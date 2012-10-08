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


void Ring::Dump() {
  fprintf(stdout, "-- ring %p dump start --\n", this);
  RingBuffer* current = &head_;
  do {
    char flags[4];
    flags[0] = current == rhead_ ? 'r' : ' ';
    flags[1] = current == whead_ ? 'w' : ' ';
    flags[2] = current == &head_ ? 's' : ' ';
    flags[3] = 0;

    fprintf(stdout, "# %d %d (%d %d) %s\n",
            current->roffset,
            current->woffset,
            0,
            0,
            flags);
    current = current->next;
  } while (current != &head_);
  fprintf(stdout, "-- ring %p dump end --\n", this);
}


void Ring::Write(const char* data, int size) {
  int left = size;
  int offset = 0;
  int woffset;
  RingBuffer* b = whead_;

  while (left > 0) {
    int available = sizeof(b->data) - b->woffset;
    int bytes = available > left ? left : available;

    assert(static_cast<size_t>(b->woffset + bytes) <= sizeof(b->data));
    memcpy(b->data + b->woffset, data + offset, bytes);

    offset += bytes;
    left -= bytes;

    woffset = b->woffset + bytes;
    b->woffset = woffset;

    if (woffset == sizeof(b->data)) {
      RingBuffer* next = b->next;

      if (rhead_ != next &&
          next->roffset == sizeof(next->data) &&
          next->woffset == sizeof(next->data)) {
        // Fully written and read buffer is the same thing as empty
        next->roffset = 0;
        next->woffset = 0;
      } else if (next->woffset != 0) {
        // Tail is full now - get a new one
        next = new RingBuffer();
        next->next = b->next;

        // Insert buffer into ring
        *const_cast<volatile RingBuffer**>(&b->next) = next;
      }
      b = next;

      // Move write head
      whead_ = b;

      assert(whead_->woffset == 0);
      assert(whead_->roffset == 0);
    }

    PaUtil_WriteMemoryBarrier();
    ATOMIC_ADD(total_, bytes);
  }
  assert(size == offset);
}


int Ring::Read(char* data, int size) {
  RingBuffer* b = rhead_;
  int left = size;
  int offset = 0;
  int roffset;

  while (total_ > 0 && left > 0) {
    PaUtil_ReadMemoryBarrier();

    int avail = b->woffset - b->roffset;
    int bytes = avail > left ? left : avail;

    // Copy only if there's place to save data
    if (data != NULL && bytes != 0) {
      assert(avail >= bytes);
      memcpy(data + offset, b->data + b->roffset, bytes);
    }

    left -= bytes;
    offset += bytes;

    roffset = b->roffset + bytes;
    b->roffset = roffset;
    ATOMIC_SUB(total_, bytes);

    assert(roffset >= 0);

    if (roffset == sizeof(b->data)) {
      // Move rhead if we can't read there anymore
      b = b->next;
      rhead_ = b;
    }
  }

  return offset;
}


int Ring::Peek(char* data, int size) {
  int left = size;
  int offset = 0;
  RingBuffer* current = rhead_;

  if (left > total_) left = total_;

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
