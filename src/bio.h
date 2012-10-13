#ifndef _SRC_BIO_H_
#define _SRC_BIO_H_

#include "openssl/bio.h"
#include "ngx-queue.h"

BIO_METHOD* BIO_snappy();

#endif // _SRC_BIO_H_
