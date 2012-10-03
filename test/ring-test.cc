#include "ring.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

static const int kBufsize = 237;

void* producer(void* arg) {
  Ring* r = reinterpret_cast<Ring*>(arg);
  char out[kBufsize];
  int current = 0;

  while (true) {
    if (r->Size() > 10 * sizeof(out)) {
      usleep(30000);
      continue;
    }

    for (int i = 0; i < kBufsize; i++) {
      out[i] = current;
      current = (current + 1) & 0xff;
    }
    r->Write(out, sizeof(out));
  }

  return NULL;
}


void* consumer(void* arg) {
  Ring* r = reinterpret_cast<Ring*>(arg);
  char in[1024];
  int last = 0;

  while (true) {
    int bytes = r->Read(in, sizeof(in));
    for (int i = 0; i < bytes; i++) {
      unsigned char uin = static_cast<unsigned char>(in[i]);
      if (uin != last) {
        fprintf(stdout, "err: %d (expected: %d found: %d)\n", i, last, uin);
        abort();
      }
      last = (last + 1) & 0xff;
    }
  }

  return NULL;
}

int main() {
  pthread_t p;
  pthread_t c;
  Ring* r = new Ring();

  pthread_create(&p, NULL, producer, r);
  pthread_create(&c, NULL, consumer, r);
  pthread_join(p, NULL);
  pthread_join(c, NULL);

  delete r;

  return 0;
}
