#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include "common.h"

class RingBuffer {
 public:
  RingBuffer() : next(this), roffset(0), woffset(0) {
  }

  RingBuffer* next;
  volatile int roffset;
  volatile int woffset;
  char data[4 * 1024];
};

class Ring {
 public:
  Ring();

  ~Ring();

  inline int Size() {
    return total_;
  }

  void Write(const char* data, int size);
  int Read(char* data, int size);
  int Peek(char* data, int size);

 private:
  RingBuffer head_;
  RingBuffer* rhead_;
  RingBuffer* whead_;

  int total_;
};

#endif // _SRC_RING_H_
