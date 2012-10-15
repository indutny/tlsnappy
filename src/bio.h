#ifndef _SRC_BIO_H_
#define _SRC_BIO_H_

#include "openssl/bio.h"
#include "ngx-queue.h"

#ifdef __cplusplus
extern "C" {
#endif

BIO_METHOD* BIO_snappy();

#ifdef __cplusplus
}
#endif
#endif // _SRC_BIO_H_
