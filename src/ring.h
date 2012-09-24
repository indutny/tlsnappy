#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "ngx-queue.h"
#include "common.h"

class RingBuffer {
 public:
  RingBuffer() : offset(0) {
    ngx_queue_init(&member);
  }

  static inline RingBuffer* FromMember(ngx_queue_t* member) {
    RingBuffer* result = container_of(member, RingBuffer, member);
    return result;
  }

  ngx_queue_t member;
  int offset;
  char data[4 * 1024];
};

class RingSlab {
 public:
  RingSlab() {
    uv_mutex_init(&mtx_);
    ngx_queue_init(&queue_);
  }

  ~RingSlab() {
    while (!ngx_queue_empty(&queue_)) {
      delete Dequeue();
    }
    uv_mutex_destroy(&mtx_);
  }

  inline void Enqueue(RingBuffer* buffer) {
    // Remove buffer from it's previous queue
    ngx_queue_remove(&buffer->member);

    // Insert buffer into current FIFO
    uv_mutex_lock(&mtx_);
    ngx_queue_insert_head(&queue_, &buffer->member);
    uv_mutex_unlock(&mtx_);
  }

  inline RingBuffer* Dequeue() {
    RingBuffer* r;

    if (uv_mutex_trylock(&mtx_)) {
      return new RingBuffer();
    }

    if (ngx_queue_empty(&queue_)) {
      uv_mutex_unlock(&mtx_);
      r = new RingBuffer();
    } else {
      ngx_queue_t* member = ngx_queue_head(&queue_);
      ngx_queue_remove(member);
      uv_mutex_unlock(&mtx_);

      r = RingBuffer::FromMember(member);
      r->offset = 0;
    }

    return r;
  }

 private:
  uv_mutex_t mtx_;
  ngx_queue_t queue_;
};

class Ring {
 public:
  Ring(RingSlab* slab) : slab_(slab), total_(0) {
    ngx_queue_init(&queue_);
    RingBuffer* buffer = slab_->Dequeue();
    ngx_queue_insert_head(&queue_, &buffer->member);
  }

  ~Ring() {
    // Return all buffers into slab
    while (!ngx_queue_empty(&queue_)) {
      slab_->Enqueue(head());
    }
  }

  inline RingBuffer* head() {
    assert(!ngx_queue_empty(&queue_));
    return RingBuffer::FromMember(ngx_queue_head(&queue_));
  }

  inline RingBuffer* tail() {
    assert(!ngx_queue_empty(&queue_));
    return RingBuffer::FromMember(ngx_queue_last(&queue_));
  }

  inline int Size() {
    return total_;
  }

  inline void Write(char* data, int size) {
    int left = size;
    int offset = 0;
    RingBuffer* b = tail();

    while (left > 0) {
      int available = sizeof(b->data) - b->offset;
      int bytes = available > left ? left : available;

      assert(static_cast<size_t>(b->offset + bytes) <= sizeof(b->data));
      memcpy(b->data + b->offset, data + offset, bytes);
      b->offset += bytes;
      offset += bytes;
      total_ += bytes;
      left -= bytes;

      if (b->offset == sizeof(b->data)) {
        // Tail is full now - get a new one
        b = slab_->Dequeue();
        ngx_queue_insert_tail(&queue_, &b->member);
      }
    }
    assert(size == offset);
  }

  inline int Read(char* data, int size) {
    int left = size;
    int offset = 0;

    while (total_ > 0 && left > 0) {
      RingBuffer* b = head();
      int bytes = b->offset > left ? left : b->offset;

      // Copy only if there's place to save data
      if (data != NULL) {
        assert(b->offset >= bytes);
        memcpy(data + offset, b->data, bytes);
      }

      b->offset -= bytes;
      left -= bytes;
      offset += bytes;
      total_ -= bytes;
      assert(b->offset >= 0);
      assert(total_ >= 0);

      if (b->offset != 0) {
        // Move remaining bytes left
        memmove(b->data, b->data + bytes, b->offset);
      } else {
        // Enqueue buffer into slab if it's empty
        // (but do not remove head)
        if (total_ != 0) {
          slab_->Enqueue(b);
          assert(!ngx_queue_empty(&queue_));
        }
      }
    }

    return offset;
  }

  inline int Peek(char* data, int size) {
    int left = size;
    int offset = 0;
    RingBuffer* current = head();

    while (left > 0) {
      int bytes = current->offset > left ? left : current->offset;

      memcpy(data + offset, current->data, bytes);

      offset += bytes;
      left -= bytes;

      ngx_queue_t* next = ngx_queue_next(&current->member);
      if (next == &queue_) break;

      current = RingBuffer::FromMember(next);
    }

    return offset;
  }

 private:
  RingSlab* slab_;
  ngx_queue_t queue_;
  int total_;
};

#endif // _SRC_RING_H_
