#include "bio.h"
#include "lring.h"
#include <assert.h>
#include <string.h>

static int mem_write(BIO*, const char*, int);
static int mem_read(BIO*, char*, int);
static int mem_puts(BIO*, const char*);
static int mem_gets(BIO*, char*, int);
static long mem_ctrl(BIO*, int, long, void*);
static int mem_new(BIO*);
static int mem_free(BIO*);

#define BIO_TYPE_NO_EX_DATA 0x0800

static BIO_METHOD mem_method = {
  BIO_TYPE_MEM | BIO_TYPE_NO_EX_DATA,
  "Super snappy buffer",
  mem_write,
  mem_read,
  mem_puts,
  mem_gets,
  mem_ctrl,
  mem_new,
  mem_free,
  NULL,
};


BIO_METHOD* BIO_snappy() {
  return &mem_method;
}


static int mem_new(BIO* bio) {
  lring_t* ring;

  ring = (lring_t*) malloc(sizeof(lring_t));
  if (ring == NULL) abort();
  lring_init(ring);

  bio->ptr = (char*) ring;

  // XXX Why am I doing it?!
  bio->shutdown = 1;
  bio->init = 1;
  bio->num = -1;

  return 1;
}


static int mem_free(BIO* bio) {
  if (bio == NULL) return 0;

  if (bio->shutdown) {
    if (bio->init && bio->ptr != NULL) {
      free(bio->ptr);
      bio->ptr = NULL;
    }
  }

  return 1;
}


static inline lring_t* mem_ring(BIO* bio) {
  return (lring_t*) bio->ptr;
}


static int mem_read(BIO* bio, char* out, int len) {
  lring_t* r;
  int bytes;
  BIO_clear_retry_flags(bio);

  r = mem_ring(bio);
  assert(r != NULL);

  bytes = (int) lring_read(r, out, len);
  if (bytes == 0) {
    bytes = bio->num;
    if (bytes != 0) {
      BIO_set_retry_read(bio);
    }
  }

  return bytes;
}


static int mem_write(BIO* bio, const char* data, int len) {
  lring_t* r;

  r = mem_ring(bio);

  BIO_clear_retry_flags(bio);

  assert(r != NULL);
  lring_write(r, data, len);

  return len;
}


static int mem_puts(BIO* bio, const char* str) {
  return mem_write(bio, str, (int) strlen(str) + 1);
}


static int mem_gets(BIO* bio, char* out, int size) {
  lring_t* r;

  r = mem_ring(bio);
  assert(r != NULL);

  int len = (int) lring_peek(r, out, size);
  if (len == 0) return 0;

  int i;
  char* tmp = out;
  for (i = 0; i < len && *tmp != '\n'; i++, tmp++) {
    // Nop
  }

  // Include newline char
  if (*tmp == '\n' && i < size) i++;

  // Flush read data
  lring_read(r, NULL, i);

  // Terminate line
  if (size == i) i--;
  out[i] = 0;

  return i;
}


static long mem_ctrl(BIO* bio, int cmd, long num, void* ptr) {
  lring_t* r;
  long ret;

  r = mem_ring(bio);
  assert(r != NULL);

  ret = 1;

  switch (cmd) {
   case BIO_CTRL_RESET:
    lring_read(r, NULL, lring_size(r));
    break;
   case BIO_CTRL_EOF:
    ret = lring_size(r) == 0;
    break;
   case BIO_C_SET_BUF_MEM_EOF_RETURN:
    bio->num = (int) num;
    break;
   case BIO_CTRL_INFO:
    ret = (long) lring_size(r);
    if (ptr != NULL)
      *((void**) ptr) = NULL;
    break;
   case BIO_C_SET_BUF_MEM:
    mem_free(bio);
    bio->shutdown = (int) num;
    bio->ptr = ptr;
    break;
   case BIO_C_GET_BUF_MEM_PTR:
    if (ptr != NULL)
      *((void**) ptr) = r;
    break;
  case BIO_CTRL_GET_CLOSE:
    ret = (long) bio->shutdown;
    break;
  case BIO_CTRL_SET_CLOSE:
    bio->shutdown = (int) num;
    break;
  case BIO_CTRL_WPENDING:
    ret = 0L;
    break;
  case BIO_CTRL_PENDING:
    ret = (long) lring_size(r);
    break;
  case BIO_CTRL_DUP:
  case BIO_CTRL_FLUSH:
    ret = 1;
    break;
  case BIO_CTRL_PUSH:
  case BIO_CTRL_POP:
  default:
    ret = 0;
    break;
  }
  return ret;
}
