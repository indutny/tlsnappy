#include "ring.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Ring::Ring() : total_(0) {
  ngx_queue_init(&queue_);
  ngx_queue_insert_head(&queue_, &head_.member);
  rhead_ = &head_.member;
  whead_ = &head_.member;
}


Ring::~Ring() {
  rhead_ = NULL;
  whead_ = NULL;

  // Return all buffers into slab
  while (!ngx_queue_empty(&queue_)) {
    RingBuffer* b = RingBuffer::FromMember(ngx_queue_head(&queue_));
    ngx_queue_remove(&b->member);
    if (b != &head_) delete b;
  }
}


void Ring::Write(const char* data, int size) {
  int left = size;
  int offset = 0;
  RingBuffer* b = whead();

  while (left > 0) {
    int available = sizeof(b->data) - b->woffset;
    int bytes = available > left ? left : available;

    assert(static_cast<size_t>(b->woffset + bytes) <= sizeof(b->data));
    memcpy(b->data + b->woffset, data + offset, bytes);
    fprintf(stdout, "write: (%d) %p %d %d\n", (unsigned char) data[offset], b->data, b->woffset, b->woffset + bytes);
    offset += bytes;
    left -= bytes;

    __sync_fetch_and_add(&b->woffset, bytes);
    __sync_fetch_and_add(&total_, bytes);

    if (b->woffset == sizeof(b->data)) {
      ngx_queue_t* next = ngx_queue_next(&b->member);
      if (next == &queue_) next = ngx_queue_next(next);

      if (next == rhead_) {
        fprintf(stdout, "new\n");
        // Tail is full now - get a new one
        b = new RingBuffer();
        ngx_queue_insert_tail(&queue_, &b->member);

        // Move write head
        whead_ = &b->member;
      } else {
        fprintf(stdout, "reuse\n");
        whead_ = next;
        b = RingBuffer::FromMember(next);
      }
    }
  }
  assert(size == offset);
}


int Ring::Read(char* data, int size) {
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
      fprintf(stdout, "read: %p %d %d\n", b->data, b->roffset, b->roffset + bytes);
    }

    left -= bytes;
    offset += bytes;
    __sync_fetch_and_add(&b->roffset, bytes);
    __sync_fetch_and_sub(&total_, bytes);
    assert(b->roffset >= 0);
    assert(total_ >= 0);

    if (b->roffset == sizeof(b->data)) {
      // Reset buffer, it's empty now
      assert(b->woffset == b->roffset);
      b->roffset = 0;
      b->woffset = 0;
      fprintf(stdout, "!!!!!!! nullify: %p\n", b);
    }

    // Move rhead
    rhead_ = ngx_queue_next(rhead_);
    if (rhead_ == &queue_) rhead_ = ngx_queue_next(rhead_);
  }

  return offset;
}


int Ring::Peek(char* data, int size) {
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
