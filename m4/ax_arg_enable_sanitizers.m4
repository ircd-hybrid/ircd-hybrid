AC_DEFUN([AX_ARG_ENABLE_SANITIZERS], [
  AC_REQUIRE([AC_PROG_CC])
  AC_LANG_ASSERT([C])

  AC_ARG_ENABLE([asan],
    [AS_HELP_STRING([--enable-asan], [Enable AddressSanitizer @<:@default=no@:>@])],
    [enable_asan=$enableval],
    [enable_asan=no])

  AC_ARG_ENABLE([ubsan],
    [AS_HELP_STRING([--enable-ubsan], [Enable UndefinedBehaviorSanitizer @<:@default=no@:>@])],
    [enable_ubsan=$enableval],
    [enable_ubsan=no])

  AC_ARG_ENABLE([lsan],
    [AS_HELP_STRING([--enable-lsan], [Enable LeakSanitizer @<:@default=no@:>@])],
    [enable_lsan=$enableval],
    [enable_lsan=no])

  AS_CASE([$enable_asan],
    [yes|no], [],
    [AC_MSG_ERROR([invalid value '$enable_asan' for --enable-asan; expected yes or no])])

  AS_CASE([$enable_ubsan],
    [yes|no], [],
    [AC_MSG_ERROR([invalid value '$enable_ubsan' for --enable-ubsan; expected yes or no])])

  AS_CASE([$enable_lsan],
    [yes|no], [],
    [AC_MSG_ERROR([invalid value '$enable_lsan' for --enable-lsan; expected yes or no])])

  AS_CASE([$enable_asan:$enable_ubsan],
    [yes:no], [ax_sanitizers=address],
    [no:yes], [ax_sanitizers=undefined],
    [yes:yes], [ax_sanitizers=address,undefined],
    [ax_sanitizers=])

  ax_sanitizers_cflags=-fno-omit-frame-pointer
  AS_IF([test -n "$ax_sanitizers"], [
    ax_sanitizers_cflags="-fsanitize=$ax_sanitizers $ax_sanitizers_cflags"
  ])

  dnl Request LSan at link time; the compiler selects ASan's integrated runtime.
  AS_IF([test "x$enable_lsan" = xyes], [
    AS_IF([test -n "$ax_sanitizers"],
      [ax_sanitizers="$ax_sanitizers,leak"],
      [ax_sanitizers=leak])
  ])

  AS_IF([test -n "$ax_sanitizers"], [
    ax_sanitizers_ldflags="-fsanitize=$ax_sanitizers"

    AS_IF([test "x$enable_ubsan" = xyes], [
      ax_sanitizers_cflags="$ax_sanitizers_cflags -fno-sanitize-recover=undefined"
    ])

    ax_sanitizers_save_CFLAGS=$CFLAGS
    ax_sanitizers_save_LDFLAGS=$LDFLAGS
    CFLAGS="$CFLAGS $ax_sanitizers_cflags"
    LDFLAGS="$LDFLAGS $ax_sanitizers_ldflags"

    AC_MSG_CHECKING([whether $CC can compile and link with $ax_sanitizers sanitizers])
    AC_LINK_IFELSE([
      AC_LANG_PROGRAM([[#include <stdlib.h>]], [[
volatile int value = 1;
void *volatile allocation = malloc(1);

value = value - 1;
free(allocation);
      ]])
    ],
    [ax_sanitizers_supported=yes],
    [ax_sanitizers_supported=no])
    AC_MSG_RESULT([$ax_sanitizers_supported])

    CFLAGS=$ax_sanitizers_save_CFLAGS
    LDFLAGS=$ax_sanitizers_save_LDFLAGS

    AS_IF([test "x$ax_sanitizers_supported" != xyes], [
      AC_MSG_ERROR([requested sanitizers '$ax_sanitizers' cannot be compiled and linked; check compiler and sanitizer runtime support in config.log])
    ])

    CFLAGS="$CFLAGS $ax_sanitizers_cflags"
    LDFLAGS="$LDFLAGS $ax_sanitizers_ldflags"
  ],
  [ax_sanitizers=none])

  AC_MSG_NOTICE([Sanitizers: $ax_sanitizers])
])
