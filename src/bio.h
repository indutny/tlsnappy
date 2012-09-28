#ifndef _SRC_BIO_H_
#define _SRC_BIO_H_

#include "openssl/bio.h"
#include "ngx-queue.h"
#include "ring.h"

namespace tlsnappy {

BIO_METHOD* BIO_snappy();

} // namespace tlsnappy

#endif // _SRC_BIO_H_
