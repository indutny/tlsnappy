#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include <assert.h>
#include <string.h>
#include <stdlib.h>
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
  int roffset;
  int woffset;
  char data[4 * 1024];
};

class Ring {
 public:
  Ring() : total_(0) {
    ngx_queue_init(&queue_);
    ngx_queue_insert_head(&queue_, &head_.member);
    rhead_ = &head_.member;
    whead_ = &head_.member;
  }

  ~Ring() {
    rhead_ = NULL;
    whead_ = NULL;

    // Return all buffers into slab
    while (!ngx_queue_empty(&queue_)) {
      RingBuffer* b = RingBuffer::FromMember(ngx_queue_head(&queue_));
      ngx_queue_remove(&b->member);
      if (b != &head_) delete b;
    }
  }

  inline RingBuffer* rhead() {
    assert(rhead_ != NULL);
    return RingBuffer::FromMember(rhead_);
  }

  inline RingBuffer* whead() {
    assert(whead_ != NULL);
    return RingBuffer::FromMember(whead_);
  }

  inline int Size() {
    return total_;
  }

  inline void Write(const char* data, int size) {
    int left = size;
    int offset = 0;
    RingBuffer* b = whead();

    while (left > 0) {
      int available = sizeof(b->data) - b->woffset;
      int bytes = available > left ? left : available;

      assert(static_cast<size_t>(b->woffset + bytes) <= sizeof(b->data));
      memcpy(b->data + b->woffset, data + offset, bytes);
      offset += bytes;
      left -= bytes;
      b->woffset += bytes;
      __sync_fetch_and_add(&total_, bytes);

      if (b->woffset == sizeof(b->data)) {
        // Tail is full now - get a new one
        b = new RingBuffer();
        ngx_queue_insert_tail(&queue_, &b->member);

        // Move write head
        whead_ = &b->member;
      }
    }
    assert(size == offset);
  }

  inline int Read(char* data, int size) {
    int left = size;
    int offset = 0;

    while (total_ > 0 && left > 0) {
      RingBuffer* b = rhead();
      int avail = b->woffset - b->roffset;
      int bytes = avail > left ? left : avail;

      // Copy only if there's place to save data
      if (data != NULL) {
        assert(avail >= bytes);
        memcpy(data + offset, b->data + b->roffset, bytes);
      }

      left -= bytes;
      offset += bytes;
      b->roffset += bytes;
      __sync_fetch_and_sub(&total_, bytes);
      assert(b->roffset >= 0);
      assert(total_ >= 0);

      if (b->roffset == sizeof(b->data)) {
        // Reset buffer, it's empty now
        assert(b->woffset == b->roffset);
        b->roffset = 0;
        b->woffset = 0;
      }

      // Move rhead
      rhead_ = ngx_queue_next(rhead_);
      if (rhead_ == &queue_) rhead_ = ngx_queue_next(rhead_);
    }

    return offset;
  }

  inline int Peek(char* data, int size) {
    int left = size;
    int offset = 0;
    RingBuffer* current = rhead();

    while (left > 0) {
      int avail = current->woffset - current->roffset;
      if (avail == 0) break;
      int bytes = avail > left ? left : avail;

      memcpy(data + offset, current->data + current->roffset, bytes);

      offset += bytes;
      left -= bytes;

      ngx_queue_t* next = ngx_queue_next(&current->member);
      if (next == &queue_) next = ngx_queue_next(next);

      current = RingBuffer::FromMember(next);
    }

    return offset;
  }

 private:
  ngx_queue_t queue_;
  RingBuffer head_;
  ngx_queue_t* rhead_;
  ngx_queue_t* whead_;

  int total_;
};

#endif // _SRC_RING_H_
