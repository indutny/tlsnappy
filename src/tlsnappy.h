#ifndef _SRC_TLSNAPPY_H_
#define _SRC_TLSNAPPY_H_

#include "node.h"
#include "node_buffer.h"
#include "node_object_wrap.h"
#include "ngx-queue.h"
#include "lring.h"
#include "openssl/ssl.h"
#include "openssl/bio.h"
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
  static Handle<Value> ClearOut(const Arguments& args);
  static Handle<Value> EncOut(const Arguments& args);
  static Handle<Value> Close(const Arguments& args);
  static Handle<Value> ForceClose(const Arguments& args);

  inline void Cycle();
  static void EmitEvent(uv_async_t* handle, int status);
  static void OnClose(uv_async_t* handle, int status);

  // How many times socket was queued before dequeuing
  int queued_;
  ngx_queue_t member_;

  volatile int closing_;
  volatile int initializing_;
  volatile int closed_;
  bool initialized_;
  int shutdown_;

  // When SSL error happens this is filled with error code
  int err_;

  lring_t enc_in_;
  lring_t enc_out_;
  lring_t clear_in_;
  lring_t clear_out_;
  uv_async_t* event_cb_;
  uv_async_t* close_cb_;

  void OnEvent();
  void Close();
  void TryGetNPN();
  void HandleError(int err);
  void Shutdown();

  Context* ctx_;
  lring_t* ring_rbio_;
  lring_t* ring_wbio_;
  BIO* rbio_;
  BIO* wbio_;
  SSL* ssl_;

  // NPN protocol
  char* npn_;
  int npn_len_;

  friend class Context;
};

} // namespace tlsnappy

#endif // _SRC_TLSNAPPY_H_
