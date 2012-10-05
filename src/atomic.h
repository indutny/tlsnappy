#ifndef _SRC_ATOMIC_H_
#define _SRC_ATOMIC_H_

/* GCC >= 4.1 has built-in intrinsics. We'll use those */
#if defined(__GNUC__)
# if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)

#  define ATOMIC_ADD(arg, num) __sync_add_and_fetch(&arg, num)
#  define ATOMIC_SUB(arg, num) __sync_sub_and_fetch(&arg, num)

# elif defined( __i386__ ) || defined( __i486__ ) || defined( __i586__ ) || \
       defined( __i686__ ) || defined( __x86_64__ )

# define ATOMIC_ADD(arg, num)  asm ("lock add %1, %2\n" : \
                                    "=m" (arg) : "d" (num), "m" (arg))
# define ATOMIC_SUB(arg, num)  asm ("lock sub %1, %2\n" : \
                                    "=m" (arg) : "d" (num), "m" (arg))

# else

#  error Atomic opertations are not supported on your platform

# endif

#else

# error Atomic opertations are not supported on your platform

#endif

#endif _SRC_ATOMIC_H_
