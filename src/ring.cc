#include "ring.h"
#include "atomic.h"
#include "pa_memorybarrier.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Ring::Ring() : total_(0) {
  rhead_ = &head_;
  whead_ = &head_;
}


Ring::~Ring() {
  rhead_ = NULL;
  whead_ = NULL;
  RingBuffer* head = &head_;

  // Return all buffers into slab
  while (head->next != head) {
    RingBuffer* next = head->next;
    head->next = next->next;
    delete next;
  }
}


void Ring::Write(const char* data, int size) {
  int left = size;
  int offset = 0;
  RingBuffer* b = whead_;

  while (left > 0) {
    int available = sizeof(b->data) - b->woffset;
    int bytes = available > left ? left : available;

    assert(static_cast<size_t>(b->woffset + bytes) <= sizeof(b->data));
    memcpy(b->data + b->woffset, data + offset, bytes);
    PaUtil_FullMemoryBarrier();

    offset += bytes;
    left -= bytes;

    b->woffset += bytes;
    ATOMIC_ADD(total_, bytes);

    if (b->woffset == sizeof(b->data)) {
      RingBuffer* next = b->next;

      if (next == rhead_) {
        // Tail is full now - get a new one
        next = new RingBuffer();
        next->next = b->next;

        // Insert buffer into ring
        *const_cast<volatile RingBuffer**>(&b->next) = next;
      }
      b = next;

      // Move write head
      whead_ = next;
    }
  }
  assert(size == offset);
}


int Ring::Read(char* data, int size) {
  int left = size;
  int offset = 0;

  while (total_ > 0 && left > 0) {
    RingBuffer* b = rhead_;
    int avail = b->woffset - b->roffset;
    int bytes = avail > left ? left : avail;

    // Copy only if there's place to save data
    if (data != NULL && bytes != 0) {
      assert(avail >= bytes);
      memcpy(data + offset, b->data + b->roffset, bytes);
    }

    left -= bytes;
    offset += bytes;
    b->roffset += bytes;
    ATOMIC_SUB(total_, bytes);
    assert(b->roffset >= 0);
    assert(total_ >= 0);

    if (b->roffset == sizeof(b->data)) {
      // Reset buffer, it's empty now
      assert(b->woffset == b->roffset);
      b->roffset = 0;
      b->woffset = 0;

      // Ring can not be empty that point,
      // if it is - that means that writer hasn't created new page after filling
      // it's head. We need to wait for it in this case
      while (rhead_ == rhead_->next) {}

      // Move rhead
      rhead_ = rhead_->next;
    }
  }

  return offset;
}


int Ring::Peek(char* data, int size) {
  int left = size;
  int offset = 0;
  RingBuffer* current = rhead_;

  while (left > 0) {
    int avail = current->woffset - current->roffset;
    if (avail == 0) break;
    int bytes = avail > left ? left : avail;

    assert(current->roffset + bytes <= current->woffset);
    memcpy(data + offset, current->data + current->roffset, bytes);

    offset += bytes;
    left -= bytes;

    current = current->next;
  }

  return offset;
}
