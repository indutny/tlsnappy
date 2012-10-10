#ifndef _SRC_COMMON_H_
#define _SRC_COMMON_H_

#include <stdint.h>
#include <stdlib.h>

#if defined(_WIN32) && !defined(_SSIZE_T_) && !defined(_SSIZE_T_DEFINED)
  typedef intptr_t ssize_t;
# define _SSIZE_T_
# define _SSIZE_T_DEFINED
#endif

#ifndef offset_of
// g++ in strict mode complains loudly about the system offsetof() macro
// because it uses NULL as the base address.
# define offset_of(type, member) \
  ((intptr_t) ((char *) &(((type *) 8)->member) - 8))
#endif

#ifndef container_of
# define container_of(ptr, type, member) \
  ((type *) ((char *) (ptr) - offset_of(type, member)))
#endif

#endif // _SRC_COMMON_H_
