#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include "ngx-queue.h"
#include "common.h"

class RingBuffer {
 public:
  RingBuffer() : roffset(0), woffset(0) {
    ngx_queue_init(&member);
  }

  static inline RingBuffer* FromMember(ngx_queue_t* member) {
    RingBuffer* result = container_of(member, RingBuffer, member);
    return result;
  }

  ngx_queue_t member;
  volatile int roffset;
  volatile int woffset;
  char data[4 * 1024];
};

class Ring {
 public:
  Ring();

  ~Ring();

  inline RingBuffer* rhead() {
    return RingBuffer::FromMember(rhead_);
  }

  inline RingBuffer* whead() {
    return RingBuffer::FromMember(whead_);
  }

  inline int Size() {
    return total_;
  }

  void Write(const char* data, int size);
  int Read(char* data, int size);
  int Peek(char* data, int size);

 private:
  ngx_queue_t queue_;
  RingBuffer head_;
  ngx_queue_t* rhead_;
  ngx_queue_t* whead_;

  int total_;
};

#endif // _SRC_RING_H_
