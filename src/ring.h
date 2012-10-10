#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include "common.h"
#include <sys/types.h>

class RingPage {
 public:
  RingPage() : next(this), roffset(0), woffset(0) {
  }

  RingPage* next;
  volatile ssize_t roffset;
  volatile ssize_t woffset;
  char data[10 * 1024];
};

class Ring {
 public:
  Ring();
  ~Ring();

  void Dump();

  inline ssize_t Size() {
    return total_;
  }

  void Write(const char* data, ssize_t size);
  ssize_t Read(char* data, ssize_t size);
  ssize_t Peek(char* data, ssize_t size);

 private:
  RingPage head_;
  RingPage* rhead_;
  RingPage* whead_;

  volatile ssize_t total_;
};

#endif // _SRC_RING_H_
