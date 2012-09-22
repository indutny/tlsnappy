#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "ngx-queue.h"
#include "common.h"

struct RingBuffer {
  char data[4 * 1024];
  int offset;
  ngx_queue_t member;
};

class RingSlab {
 public:
  RingSlab() {
    ngx_queue_init(&head_);
  }
  ~RingSlab() {
    while (!ngx_queue_empty(&head_)) {
      delete Dequeue();
    }
  }

  inline void Enqueue(RingBuffer* buffer) {
    buffer->offset = 0;
    ngx_queue_insert_tail(&head_, &buffer->member);
  }

  inline RingBuffer* Dequeue() {
    if (ngx_queue_empty(&head_)) {
      RingBuffer* buffer = new RingBuffer();
      ngx_queue_init(&buffer->member);
      buffer->offset = 0;
      return buffer;
    }

    ngx_queue_t* member = ngx_queue_head(&head_);
    ngx_queue_remove(member);
    return container_of(member, RingBuffer, member);
  }

 private:
  ngx_queue_t head_;
};

class Ring {
 public:
  Ring(RingSlab* slab) : slab_(slab), tail_(NULL), total_(0) {
    RingBuffer* buff = slab_->Dequeue();
    ngx_queue_init(&head_);
    ngx_queue_insert_tail(&head_, &buff->member);
    tail_ = ngx_queue_head(&head_);
  }

  ~Ring() {
    while (!ngx_queue_empty(&head_)) {
      slab_->Enqueue(container_of(ngx_queue_head(&head_), RingBuffer, member));
    }
  }

  inline RingBuffer* head() {
    return container_of(ngx_queue_head(&head_), RingBuffer, member);
  }

  inline RingBuffer* tail() {
    return container_of(tail_, RingBuffer, member);
  }

  inline void Write(char* data, int size) {
    total_ += size;
    while (size > 0) {
      int left = sizeof(tail()->data) - tail()->offset;
      int bytes = left > size ? size : left;

      memcpy(tail()->data + tail()->offset, data, bytes);
      tail()->offset += bytes;

      data += bytes;
      size -= bytes;

      // tail_ is full now - create new buffer or use next one
      if (left == bytes) {
        if (ngx_queue_next(&tail()->member) != &head_) {
          tail_ = ngx_queue_next(&tail()->member);
        } else {
          RingBuffer* b = slab_->Dequeue();
          ngx_queue_insert_tail(&head_, &b->member);
          tail_ = &b->member;
        }
      }
    }
  }

  inline int Size() {
    return total_;
  }

  inline int Read(char* data, int size) {
    int left = size;

    while (left > 0 && Size() > 0) {
      int bytes = head()->offset > left ? left : head()->offset;

      // If there is output buffer
      if (data != NULL) memcpy(data, head()->data, bytes);

      // Move rest to the start of buffer
      if (bytes < head()->offset) {
        memmove(head()->data, head()->data + head()->offset - bytes, bytes);
      }

      head()->offset -= bytes;

      data += bytes;
      total_ -= bytes;
      left -= bytes;

      // If head is empty now, move it to the end of ring
      if (head()->offset == 0) {
        ngx_queue_t* head = ngx_queue_head(&head_);
        ngx_queue_remove(head);
        ngx_queue_insert_tail(&head_, head);
      }
    }

    return size - left;
  }

  inline int Peek(char* data, int size) {
    int left = size;
    RingBuffer* current = head();

    while (left > 0) {
      int bytes = current->offset > left ? left : current->offset;

      memcpy(data, current->data, bytes);

      data += bytes;
      left -= bytes;

      ngx_queue_t* next = ngx_queue_next(&current->member);
      if (next == &head_) break;

      current = container_of(next, RingBuffer, member);
    }

    return size - left;
  }

 private:
  RingSlab* slab_;
  ngx_queue_t head_;
  ngx_queue_t* tail_;
  int total_;
};

#endif // _SRC_RING_H_
