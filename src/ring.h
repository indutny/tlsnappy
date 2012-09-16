#ifndef _SRC_RING_H_
#define _SRC_RING_H_

#include <assert.h>
#include <string.h>

class Ring{
 public:
  struct Buffer {
    char data[4 * 1024];
    int offset;
    Buffer* next;
  };

  Ring() : total_(0) {
    head_ = new Buffer();
    head_->offset = 0;
    head_->next = head_;

    tail_ = head_;
  }

  ~Ring() {
    while (head_ != tail_) {
      Buffer* next = head_->next;
      delete head_;
      head_ = next;
    }
    delete head_;
  }

  inline void Write(char* data, int size) {
    total_ += size;
    while (size > 0) {
      int left = sizeof(tail_->data) - tail_->offset;
      int bytes = left > size ? size : left;

      memcpy(tail_->data + tail_->offset, data, bytes);
      tail_->offset += bytes;

      data += bytes;
      size -= bytes;

      // tail_ is full now - create new buffer or use next one
      if (left == bytes) {
        if (tail_->next != head_) {
          tail_ = tail_->next;
        } else {
          Buffer* b = new Buffer();
          b->offset = 0;
          b->next = head_;

          // And replace tail_ with it
          tail_->next = b;
          tail_ = b;
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
      int bytes = head_->offset > left ? left : head_->offset;

      if (data != NULL) memcpy(data, head_->data, bytes);
      if (bytes < head_->offset) {
        memmove(head_->data, head_->data + head_->offset - bytes, bytes);
      }

      head_->offset -= bytes;

      data += bytes;
      total_ -= bytes;
      left -= bytes;

      if (head_->offset == 0) {
        head_ = head_->next;
      }
    }

    return size - left;
  }

  inline int Peek(char* data, int size) {
    int left = size;
    Buffer* current = head_;

    while (left > 0) {
      int bytes = current->offset > left ? left : current->offset;

      memcpy(data, current->data, bytes);

      data += bytes;
      left -= bytes;

      current = current->next;

      // Do not loop
      if (current == head_) break;
    }

    return size - left;
  }

 private:
  Buffer* head_;
  Buffer* tail_;
  int total_;
};

#endif // _SRC_RING_H_
