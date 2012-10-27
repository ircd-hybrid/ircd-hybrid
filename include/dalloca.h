/* dalloca.h - alloca function for tinycc which doesn't have one natively
 * $Id$
 */

/*
 *    Copyright (C) 2003 Damian M Gryski <dgryski@uwaterloo.ca> 
 *    Released under LGPL 2.1
 */

#ifdef __TINYC__

#ifdef NO_ALLOCA_CHECK
#define alloca_assert(expr)
#else 
#include <assert.h>
#define alloca_assert(expr) assert(expr)
#endif

/*
 * `size' is known at compile time, but tccasm doesn't like the math expr.
 * Blindly accept input, but at least assert() that it's good.
 * Since the assert() check is substantially more expensive than the alloca
 * itself, the check can be turned off by compiling with -DNO_ALLOCA_CHECK
 */

#define alloca_const(size) \
   ({ void * __sp; \
    alloca_assert(size % 4 == 0); \
   asm("subl $" #size ", %%esp\n"  \
       "movl %%esp, %0" \
       : "=m" (__sp) ) ; \
      __sp; })

#define alloca_var(size) \
   ({ void * __sp; unsigned int __arg = size; \
   asm("movl %1, %%eax\n"        /* get the size */ \
       "addl $3, %%eax\n"        /* eax := (eax + 3) & -4 */ \
       "andl $-4, %%eax\n"       /* rounds to next multiple of 4 */ \
       "subl %%eax, %%esp\n"     /* adjust stack pointer */ \
       "movl %%esp, %0\n"        /* return result */  \
       : "=m" (__sp) : "m" (__arg) : "eax") ; \
   __sp ; }) 


#define alloca(size) alloca_var(size)

#endif
