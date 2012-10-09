#include "tlsnappy.h"
#include "bio.h"
#include "common.h"
#include "assert.h"

namespace tlsnappy {

using namespace v8;
using namespace node;

static Persistent<String> oncycle_sym;
static Persistent<String> onclose_sym;
static Persistent<String> oninit_sym;
static uv_rwlock_t* locks;

static unsigned long crypto_id_cb(void) {
#ifdef _WIN32
  return (unsigned long) GetCurrentThreadId();
#else /* !_WIN32 */
  return (unsigned long) pthread_self();
#endif /* !_WIN32 */
}


static void crypto_lock_init(void) {
  int i, n;

  n = CRYPTO_num_locks();
  locks = new uv_rwlock_t[n];

  for (i = 0; i < n; i++)
    if (uv_rwlock_init(locks + i))
      abort();
}


static void crypto_lock_cb(int mode, int n, const char* file, int line) {
  assert((mode & CRYPTO_LOCK) || (mode & CRYPTO_UNLOCK));
  assert((mode & CRYPTO_READ) || (mode & CRYPTO_WRITE));

  // No locks for SSL_CTX, users should do it themselves
  if (n == CRYPTO_LOCK_SSL_CTX) return;
  if (n == CRYPTO_LOCK_SSL) return;
  if (n == CRYPTO_LOCK_SSL_SESSION) return;

  if (mode & CRYPTO_LOCK) {
    if (mode & CRYPTO_READ)
      uv_rwlock_rdlock(locks + n);
    else
      uv_rwlock_wrlock(locks + n);
  } else {
    if (mode & CRYPTO_READ)
      uv_rwlock_rdunlock(locks + n);
    else
      uv_rwlock_wrunlock(locks + n);
  }
}


Handle<Value> Context::New(const Arguments& args) {
  HandleScope scope;

  // XXX Multi-thread pool doesn't work atm
  Context* ctx = new Context();
  ctx->Wrap(args.Holder());

  return scope.Close(args.This());
}


Context::Context() : status_(kRunning), npn_(NULL) {
  ctx_ = SSL_CTX_new(SSLv23_method());
  assert(ctx_ != NULL);

  // Mitigate BEAST attacks
  SSL_CTX_set_options(ctx_, SSL_OP_CIPHER_SERVER_PREFERENCE);
  SSL_CTX_set_options(ctx_, SSL_OP_NO_COMPRESSION);
  SSL_CTX_set_options(ctx_, SSL_OP_SINGLE_DH_USE);
  SSL_CTX_set_mode(ctx_, SSL_MODE_RELEASE_BUFFERS);
  SSL_CTX_set_session_cache_mode(ctx_, SSL_SESS_CACHE_OFF);

  // NPN
  SSL_CTX_set_next_protos_advertised_cb(ctx_, Context::Advertise, this);

  if (uv_sem_init(&event_, 0)) abort();
  if (uv_mutex_init(&queue_mtx_)) abort();
  ngx_queue_init(&queue_);

  if (uv_thread_create(&worker_, Context::Loop, this)) abort();
}


Context::~Context() {
  // Notify worker about stop event
  status_ = kStopped;
  uv_sem_post(&event_);

  // And stop it
  uv_thread_join(&worker_);

  uv_sem_destroy(&event_);
  uv_mutex_destroy(&queue_mtx_);

  SSL_CTX_free(ctx_);
  ctx_ = NULL;

  delete[] npn_;
  npn_ = NULL;
  npn_len_ = 0;
}


int Context::Advertise(SSL *s,
                       const unsigned char **data,
                       unsigned int *len,
                       void *arg) {
  Context* c = reinterpret_cast<Context*>(arg);
  if (c->npn_ != NULL) {
    *data = c->npn_;
    *len = c->npn_len_;
  } else {
    *data = reinterpret_cast<const unsigned char*>("");
    *len = 0;
  }

  return SSL_TLSEXT_ERR_OK;
}


void Context::Enqueue(Socket* s) {
  // Allow calling only once after close
  if (s->closed_) {
    if (s->closed_ == 1) {
      s->closed_ = 2;
    } else {
      return;
    }
  }

  uv_mutex_lock(&queue_mtx_);
  // Prevent double insertions
  if (ngx_queue_empty(&s->member_)) {
    ngx_queue_insert_tail(&queue_, &s->member_);
    s->queued_ = 1;
  } else {
    s->queued_++;
  }
  uv_mutex_unlock(&queue_mtx_);

  uv_sem_post(&event_);
}


inline SSL* Context::GetSSL() {
  SSL* ssl = SSL_new(ctx_);
  assert(ssl != NULL);

  return ssl;
}


void Context::Loop(void* arg) {
  Context* ctx = reinterpret_cast<Context*>(arg);

  while (ctx->RunLoop()) {
    // No op
  }
}


bool Context::RunLoop() {
  uv_sem_wait(&event_);
  if (status_ == kStopped) return false;

  Socket* socket = NULL;

  uv_mutex_lock(&queue_mtx_);

  if (!ngx_queue_empty(&queue_)) {
    ngx_queue_t* member = ngx_queue_head(&queue_);
    socket = container_of(member, Socket, member_);
    if (--socket->queued_ == 0) {
      ngx_queue_remove(member);
      ngx_queue_init(member);
    }
  }

  uv_mutex_unlock(&queue_mtx_);

  // Continue looping if there're no sockets yet
  if (socket == NULL) return true;

  // Emit final event
  if (socket->queued_ == 0 && socket->closed_) {
    socket->Close();
    return true;
  }

  socket->OnEvent();

  return true;
}


BIO* LoadBIO(Handle<Value> v) {
  HandleScope scope;

  BIO* bio = BIO_new(BIO_snappy());
  assert(bio != NULL);

  int r = -1;

  r = BIO_write(bio,
                Buffer::Data(v.As<Object>()),
                Buffer::Length(v.As<Object>()));
  assert(r > 0);

  return bio;
}


Handle<Value> Context::SetNPN(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 ||!Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  Context* ctx = ObjectWrap::Unwrap<Context>(args.This());

  if (ctx->npn_ != NULL) {
    return ThrowException(String::New("SetNPN can be called only once"));
  }

  char* data = Buffer::Data(args[0].As<Object>());
  size_t len = Buffer::Length(args[0].As<Object>());
  unsigned char* npn = new unsigned char[len];
  memcpy(npn, data, len);

  ctx->npn_len_ = len;
  ctx->npn_ = npn;

  return Null();
}


Handle<Value> Context::SetKey(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 ||!Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  BIO *bio = LoadBIO(args[0]);

  String::Utf8Value passphrase(args[1]);

  EVP_PKEY* key = PEM_read_bio_PrivateKey(bio, NULL, NULL,
                                          args.Length() == 1 ?
                                              NULL
                                              :
                                              *passphrase);

  if (!key) {
    BIO_free(bio);
    unsigned long err = ERR_get_error();
    if (!err) {
      return ThrowException(Exception::Error(
          String::New("PEM_read_bio_PrivateKey")));
    }
    char string[120];
    ERR_error_string_n(err, string, sizeof string);
    return ThrowException(Exception::Error(String::New(string)));
  }

  Context* ctx = ObjectWrap::Unwrap<Context>(args.This());

  SSL_CTX_use_PrivateKey(ctx->ctx_, key);
  EVP_PKEY_free(key);
  BIO_free(bio);

  return Null();
}

// Read a file that contains our certificate in "PEM" format,
// possibly followed by a sequence of CA certificates that should be
// sent to the peer in the Certificate message.
//
// Taken from OpenSSL - editted for style.
int SSL_CTX_use_certificate_chain(SSL_CTX *ctx, BIO *in) {
  int ret = 0;
  X509 *x = NULL;

  x = PEM_read_bio_X509_AUX(in, NULL, NULL, NULL);

  if (x == NULL) {
    SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_CHAIN_FILE, ERR_R_PEM_LIB);
    goto end;
  }

  ret = SSL_CTX_use_certificate(ctx, x);

  if (ERR_peek_error() != 0) {
    // Key/certificate mismatch doesn't imply ret==0 ...
    ret = 0;
  }

  if (ret) {
    // If we could set up our certificate, now proceed to
    // the CA certificates.
    X509 *ca;
    int r;
    unsigned long err;

    if (ctx->extra_certs != NULL) {
      sk_X509_pop_free(ctx->extra_certs, X509_free);
      ctx->extra_certs = NULL;
    }

    while ((ca = PEM_read_bio_X509(in, NULL, NULL, NULL))) {
      r = SSL_CTX_add_extra_chain_cert(ctx, ca);

      if (!r) {
        X509_free(ca);
        ret = 0;
        goto end;
      }
      // Note that we must not free r if it was successfully
      // added to the chain (while we must free the main
      // certificate, since its reference count is increased
      // by SSL_CTX_use_certificate).
    }

    // When the while loop ends, it's usually just EOF.
    err = ERR_peek_last_error();
    if (ERR_GET_LIB(err) == ERR_LIB_PEM &&
        ERR_GET_REASON(err) == PEM_R_NO_START_LINE) {
      ERR_clear_error();
    } else  {
      // some real error
      ret = 0;
    }
  }

end:
  if (x != NULL) X509_free(x);
  return ret;
}


Handle<Value> Context::SetCert(const Arguments& args) {
  HandleScope scope;
  Context* ctx = ObjectWrap::Unwrap<Context>(args.This());

  if (args.Length() < 1 ||!Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  BIO *bio = LoadBIO(args[0]);

  int rv = SSL_CTX_use_certificate_chain(ctx->ctx_, bio);

  BIO_free(bio);

  if (!rv) {
    unsigned long err = ERR_get_error();
    if (!err) {
      return ThrowException(Exception::Error(
          String::New("SSL_CTX_use_certificate_chain")));
    }
    char string[120];
    ERR_error_string_n(err, string, sizeof string);
    return ThrowException(Exception::Error(String::New(string)));
  }

  return Null();
}


Handle<Value> Socket::New(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1) {
    return ThrowException(String::New("First argument should be Context"));
  }

  Context* ctx = ObjectWrap::Unwrap<Context>(args[0].As<Object>());

  Socket* s = new Socket(ctx);
  s->Wrap(args.Holder());
  s->Ref();

  return scope.Close(args.This());
}


Socket::Socket(Context* ctx) : queued_(0),
                               closing_(0),
                               initializing_(0),
                               closed_(0),
                               initialized_(false),
                               shutdown_tries_(0),
                               err_(0),
                               ctx_(ctx),
                               ssl_(NULL),
                               npn_(NULL),
                               npn_len_(-1) {
  ctx_->Ref();

  rbio_ = BIO_new(BIO_snappy());
  wbio_ = BIO_new(BIO_snappy());
  assert(rbio_ != NULL);
  assert(wbio_ != NULL);
  ring_rbio_ = reinterpret_cast<Ring*>(rbio_->ptr);
  ring_wbio_ = reinterpret_cast<Ring*>(wbio_->ptr);

  event_cb_ = new uv_async_t();
  event_cb_->data = this;

  if (uv_async_init(uv_default_loop(), event_cb_, EmitEvent)) abort();

  close_cb_ = new uv_async_t();
  close_cb_->data = this;
  if (uv_async_init(uv_default_loop(), close_cb_, OnClose)) abort();

  ngx_queue_init(&member_);
}


void OnAsyncClose(uv_handle_t* handle) {
  delete handle;
}


Socket::~Socket() {
  assert(closed_ == 3);
  assert(ngx_queue_empty(&member_));
  ctx_->Unref();

  uv_close(reinterpret_cast<uv_handle_t*>(event_cb_), OnAsyncClose);
  uv_close(reinterpret_cast<uv_handle_t*>(close_cb_), OnAsyncClose);

  delete[] npn_;
  npn_ = NULL;
}


Handle<Value> Socket::ClearIn(const Arguments& args) {
  if (args.Length() < 1 || !Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  Socket* s = ObjectWrap::Unwrap<Socket>(args.This());

  if (s->closed_) return Null();
  s->clear_in_.Write(Buffer::Data(args[0].As<Object>()),
                     Buffer::Length(args[0].As<Object>()));

  s->ctx_->Enqueue(s);

  return Null();
}


Handle<Value> Socket::EncIn(const Arguments& args) {
  if (args.Length() < 1 || !Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  Socket* s = ObjectWrap::Unwrap<Socket>(args.This());

  if (s->closed_) return Null();
  BIO_clear_retry_flags(s->rbio_);
  s->ring_rbio_->Write(Buffer::Data(args[0].As<Object>()),
                       Buffer::Length(args[0].As<Object>()));

  s->ctx_->Enqueue(s);

  return Null();
}


Handle<Value> Socket::ClearOut(const Arguments& args) {
  HandleScope scope;
  Socket* s = ObjectWrap::Unwrap<Socket>(args.This());

  if (args.Length() < 1 ||!Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  if (args.Length() < 3) {
    return ThrowException(String::New("Three arguments are required"));
  }

  char* data = Buffer::Data(args[0].As<Object>());
  size_t size = Buffer::Length(args[0].As<Object>());

  size_t off = args[1]->Int32Value();
  size_t len = args[2]->Int32Value();

  assert(size >= off + len);

  int res = s->clear_out_.Read(data + off, len);

  return scope.Close(Number::New(res));
}


Handle<Value> Socket::EncOut(const Arguments& args) {
  HandleScope scope;
  Socket* s = ObjectWrap::Unwrap<Socket>(args.This());

  if (args.Length() < 1 ||!Buffer::HasInstance(args[0])) {
    return ThrowException(String::New("First argument should be Buffer"));
  }

  if (args.Length() < 3) {
    return ThrowException(String::New("Three arguments are required"));
  }

  char* data = Buffer::Data(args[0].As<Object>());
  size_t size = Buffer::Length(args[0].As<Object>());

  size_t off = args[1]->Int32Value();
  size_t len = args[2]->Int32Value();

  assert(size >= off + len);

  int res = s->ring_wbio_->Read(data + off, len);

  return scope.Close(Number::New(res));
}


Handle<Value> Socket::Close(const Arguments& args) {
  HandleScope scope;
  Socket* s = ObjectWrap::Unwrap<Socket>(args.This());

  s->closing_ = 1;
  s->ctx_->Enqueue(s);

  return Null();
}


void Socket::Cycle() {
  HandleScope scope;

  MakeCallback(handle_, oncycle_sym, 0, NULL);
}


void Socket::EmitEvent(uv_async_t* handle, int status) {
  HandleScope scope;
  Socket* s = reinterpret_cast<Socket*>(handle->data);

  // Do not emit events after close
  if (s->closed_) return;

  if (s->initializing_ == 2 && !s->initialized_) {
    s->initialized_ = true;

    Handle<Value> argv[1] = { String::New(const_cast<char*>(s->npn_),
                                          s->npn_len_) };
    MakeCallback(s->handle_, oninit_sym, 1, argv);
  }

  if (s->err_ == 0 && (s->clear_in_.Size() != 0 || s->enc_in_.Size() != 0)) {
    s->Cycle();
    s->ctx_->Enqueue(s);
    return;
  }

  if (s->closing_ == 2) {
    s->Cycle();
    s->closed_ = 1;

    // And finally emit close event
    MakeCallback(s->handle_, onclose_sym, 0, NULL);

    // Enqueue socket for finalizing all OnEvent invokations
    s->ctx_->Enqueue(s);
    return;
  } else {
    s->Cycle();
  }
}


void Socket::OnClose(uv_async_t* handle, int status) {
  HandleScope scope;
  Socket* s = reinterpret_cast<Socket*>(handle->data);

  // Final call - let GC collect socket
  assert(s->closed_ == 3);
  s->Unref();
}


void Socket::HandleError(int err) {
  err_ = err;

  // Flush all incoming data
  clear_in_.Read(NULL, clear_in_.Size());
  enc_in_.Read(NULL, enc_in_.Size());

  // Pretend we're closing
  Shutdown();
}


void Socket::TryGetNPN() {
  if (initializing_ == 2) return;
  if (!SSL_is_init_finished(ssl_)) return;

  // Read NPN info if we didn't before
  if (npn_len_ == -1) {
    const unsigned char* npn;
    unsigned int len;
    SSL_get0_next_proto_negotiated(ssl_, &npn, &len);
    if (npn == NULL) {
      npn_len_ = 0;
      npn_ = NULL;
    } else {
      npn_len_ = len;
      npn_ = new char[len];
      memcpy(npn_, npn, len);
    }
  }

  initializing_ = 2;
  uv_async_send(event_cb_);
}


void Socket::Shutdown() {
  if (closing_ == 2) return;
  int bytes = 0;
  int r;
  bytes = clear_in_.Size();

  // Do not send shutdown if data wasn't transferred to the client
  if (bytes != 0) return;
  r = SSL_shutdown(ssl_);

  // Try only four times (copy pasted from Apache Httpd)
  if (r == 0 && ++shutdown_tries_ < 4) return;

  // Wait for all iterations to execute before this
  if (r == -1 || queued_ == 0) closing_ = 2;
}


void Socket::OnEvent() {
  int r;
  int err;
  int bytes;
  char data[10240];

  // Lazy init ssl
  if (ssl_ == NULL) {
    ssl_ = ctx_->GetSSL();
    SSL_set_bio(ssl_, rbio_, wbio_);
    SSL_set_accept_state(ssl_);
  }

  do {
    // Write clear data
    bytes = clear_in_.Peek(data, sizeof(data));

    if (bytes > 0) {
      r = SSL_write(ssl_, data, bytes);
      if (r > 0) {
        // Flush read data
        clear_in_.Read(NULL, r);

        // Loop until all data will be written
        if (r < bytes) continue;
      } else {
        err = SSL_get_error(ssl_, r);
        if (closing_ == 2) break;

        if (err == SSL_ERROR_ZERO_RETURN) {
          // Ignore
        } else if (err == SSL_ERROR_WANT_READ) {
          // Ignore
          break;
        } else if (err == SSL_ERROR_WANT_WRITE) {
          // Ignore
          break;
        } else {
          HandleError(err);
          break;
        }
      }
    }
  } while (clear_in_.Size() > 0);

  TryGetNPN();

  do {
    // Read clear data
    bytes = SSL_read(ssl_, data, sizeof(data));
    if (bytes > 0) {
      TryGetNPN();

      clear_out_.Write(data, bytes);

      uv_async_send(event_cb_);
    } else if (closing_ != 2) {
      err = SSL_get_error(ssl_, bytes);
      if (err == SSL_ERROR_ZERO_RETURN) {
        // Ignore
      } else if (err == SSL_ERROR_WANT_READ) {
        // Ignore
        break;
      } else if (err == SSL_ERROR_WANT_WRITE) {
        // Ignore
      } else {
        HandleError(err);
        break;
      }
    }
  } while (bytes > 0);

  if (closing_) {
    Shutdown();
  }

  uv_async_send(event_cb_);
}


void Socket::Close() {
  if (closed_ != 2) return;
  closed_ = 3;

  if (ssl_ != NULL) {
    SSL_free(ssl_);
    ssl_ = NULL;
  }

  uv_async_send(close_cb_);
}


void Context::Init(Handle<Object> target) {
  Local<FunctionTemplate> t = FunctionTemplate::New(Context::New);

  t->InstanceTemplate()->SetInternalFieldCount(1);
  t->SetClassName(String::NewSymbol("Context"));

  NODE_SET_PROTOTYPE_METHOD(t, "setKey", Context::SetKey);
  NODE_SET_PROTOTYPE_METHOD(t, "setCert", Context::SetCert);
  NODE_SET_PROTOTYPE_METHOD(t, "setNPN", Context::SetNPN);

  target->Set(String::NewSymbol("Context"), t->GetFunction());
}


void Socket::Init(Handle<Object> target) {
  Local<FunctionTemplate> t = FunctionTemplate::New(Socket::New);

  t->InstanceTemplate()->SetInternalFieldCount(1);
  t->SetClassName(String::NewSymbol("Socket"));

  NODE_SET_PROTOTYPE_METHOD(t, "clearIn", Socket::ClearIn);
  NODE_SET_PROTOTYPE_METHOD(t, "encIn", Socket::EncIn);
  NODE_SET_PROTOTYPE_METHOD(t, "clearOut", Socket::ClearOut);
  NODE_SET_PROTOTYPE_METHOD(t, "encOut", Socket::EncOut);
  NODE_SET_PROTOTYPE_METHOD(t, "close", Socket::Close);

  target->Set(String::NewSymbol("Socket"), t->GetFunction());
}


void Init(Handle<Object> target) {
  HandleScope scope;

  // Shamelessly copy-pasted from node.js
  crypto_lock_init();
  CRYPTO_set_locking_callback(crypto_lock_cb);
  CRYPTO_set_id_callback(crypto_id_cb);

  oncycle_sym = Persistent<String>::New(String::NewSymbol("oncycle"));
  onclose_sym = Persistent<String>::New(String::NewSymbol("onclose"));
  oninit_sym = Persistent<String>::New(String::NewSymbol("oninit"));

  Context::Init(target);
  Socket::Init(target);
}

} // namespace tlsnappy

NODE_MODULE(tlsnappy, tlsnappy::Init)
