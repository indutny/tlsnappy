#ifndef _SRC_TLSNAPPY_H_
#define _SRC_TLSNAPPY_H_

#include "node.h"
#include "node_buffer.h"
#include "node_object_wrap.h"
#include "ngx-queue.h"
#include "ring.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

namespace tlsnappy {

using namespace v8;
using namespace node;

// Forward declaration
class Socket;

class Context : public ObjectWrap {
 public:
  enum Status {
    kRunning,
    kStopped
  };

  Context();
  ~Context();

  static void Init(Handle<Object> target);

  void Enqueue(Socket* s);
  inline SSL* GetSSL();

 protected:
  static Handle<Value> New(const Arguments& args);
  static Handle<Value> SetKey(const Arguments& args);
  static Handle<Value> SetCert(const Arguments& args);
  static Handle<Value> SetNPN(const Arguments& args);

  static int Advertise(SSL *s,
                       const unsigned char **data,
                       unsigned int *len,
                       void *arg);
  static void Loop(void* arg);
  bool RunLoop();

  // Worker data
  volatile Status status_;
  unsigned char* npn_;
  int npn_len_;
  uv_sem_t event_;
  uv_mutex_t queue_mtx_;
  uv_mutex_t mtx_;
  ngx_queue_t queue_;
  uv_thread_t worker_;

  SSL_CTX* ctx_;

  friend class Socket;
};

class Socket : public ObjectWrap {
 public:
  Socket(Context* context);
  ~Socket();

  static void Init(Handle<Object> target);

 protected:
  static Handle<Value> New(const Arguments& args);

  static Handle<Value> ClearIn(const Arguments& args);
  static Handle<Value> EncIn(const Arguments& args);
  static Handle<Value> Close(const Arguments& args);

  static void ClearOut(uv_async_t* handle, int status);
  static void EncOut(uv_async_t* handle, int status);
  static void OnClose(uv_async_t* handle, int status);
  static void OnInit(uv_async_t* handle, int status);

  uv_mutex_t event_mtx_;
  int queued_;
  volatile int closing_;
  bool closed_;
  int err_;
  bool sent_shutdown_;

  Ring enc_in_;
  Ring enc_out_;
  Ring clear_in_;
  Ring clear_out_;
  uv_async_t* clear_out_cb_;
  uv_async_t* enc_out_cb_;
  uv_async_t* close_cb_;
  uv_async_t* init_cb_;

  void OnEvent();
  void TryGetNPN();
  void HandleError(int err);
  void Shutdown();

  bool want_write_;

  Context* ctx_;
  BIO* rbio_;
  BIO* wbio_;
  SSL* ssl_;

  char* npn_;
  int npn_len_;
  ngx_queue_t member_;

  friend class Context;
};

} // namespace tlsnappy

#endif // _SRC_TLSNAPPY_H_
