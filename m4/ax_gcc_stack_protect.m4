dnl
dnl Useful macros for autoconf to check for ssp-patched gcc
dnl 1.0 - September 2003 - Tiago Sousa <mirage@kaotik.org>
dnl 1.1 - August 2006 - Ted Percival <ted@midg3t.net>
dnl     * Stricter language checking (C or C++)
dnl     * Adds AX_GCC_STACK_PROTECT_LIB to add -lssp to LDFLAGS as necessary
dnl     * Caches all results
dnl     * Uses macros to ensure correct ouput in quiet/silent mode
dnl 1.2 - April 2007 - Ted Percival <ted@midg3t.net>
dnl     * Added AX_GCC_STACK_PROTECTOR macro for simpler (one-line) invocation
dnl     * AX_GCC_STACK_PROTECT_LIB now adds -lssp to LIBS rather than LDFLAGS
dnl h.1 - June 2015 - Michael Wobst <michael@wobst.at>
dnl     * Added support for -fstack-protector-strong which is supported since gcc 4.9
dnl
dnl About ssp:
dnl GCC extension for protecting applications from stack-smashing attacks
dnl http://www.research.ibm.com/trl/projects/security/ssp/
dnl
dnl Usage:
dnl Most people will simply call AX_GCC_STACK_PROTECTOR.
dnl If you only use one of C or C++, you can save time by only calling the
dnl macro appropriate for that language. In that case you should also call
dnl AX_GCC_STACK_PROTECT_LIB first.
dnl
dnl AX_GCC_STACK_PROTECTOR
dnl Tries to turn on stack protection for C and C++ by calling the following
dnl three macros with the right languages.
dnl
dnl AX_GCC_STACK_PROTECT_CC
dnl checks -fstack-protector with the C compiler, if it exists then updates
dnl CFLAGS and defines ENABLE_SSP_CC
dnl
dnl AX_GCC_STACK_PROTECT_CXX
dnl checks -fstack-protector with the C++ compiler, if it exists then updates
dnl CXXFLAGS and defines ENABLE_SSP_CXX
dnl
dnl AX_GCC_STACK_PROTECT_LIB
dnl adds -lssp to LIBS if it is available
dnl ssp is usually provided as part of libc, but was previously a separate lib
dnl It does not hurt to add -lssp even if libc provides SSP - in that case
dnl libssp will simply be ignored.
dnl

AC_DEFUN([AX_GCC_STACK_PROTECT_LIB],[
  AC_CACHE_CHECK([whether libssp exists], ssp_cv_lib,
    [ssp_old_libs="$LIBS"
     LIBS="$LIBS -lssp"
     AC_LINK_IFELSE([AC_LANG_PROGRAM([], [])], [ssp_cv_lib=yes], [ssp_cv_lib=no])
     LIBS="$ssp_old_libs"
    ])
  if test $ssp_cv_lib = yes; then
    LIBS="$LIBS -lssp"
  fi
])

AC_DEFUN([AX_GCC_STACK_PROTECT_CC],[
  AC_LANG_ASSERT(C)
  if test "X$CC" != "X"; then
    AC_CACHE_CHECK([whether ${CC} accepts -fstack-protector-strong],
      ssp_cv_cc,
      [ssp_old_cflags="$CFLAGS"
       CFLAGS="$CFLAGS -fstack-protector-strong"
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [])], [ssp_cv_cc=yes], [ssp_cv_cc=no])
       CFLAGS="$ssp_old_cflags"
      ])
    if test $ssp_cv_cc = yes; then
      CFLAGS="$CFLAGS -fstack-protector-strong"
      AC_DEFINE([ENABLE_SSP_CC], 1, [Define if SSP C support is enabled.])
    else
      unset ssp_cv_cc
      AC_CACHE_CHECK([whether ${CC} accepts -fstack-protector],
        ssp_cv_cc,
        [ssp_old_cflags="$CFLAGS"
         CFLAGS="$CFLAGS -fstack-protector"
         AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [])], [ssp_cv_cc=yes], [ssp_cv_cc=no])
         CFLAGS="$ssp_old_cflags"
        ])
      if test $ssp_cv_cc = yes; then
        CFLAGS="$CFLAGS -fstack-protector"
        AC_DEFINE([ENABLE_SSP_CC], 1, [Define if SSP C support is enabled.])
      fi
    fi
  fi
])

AC_DEFUN([AX_GCC_STACK_PROTECT_CXX],[
  AC_LANG_ASSERT(C++)
  if test "X$CXX" != "X"; then
    AC_CACHE_CHECK([whether ${CXX} accepts -fstack-protector-strong],
      ssp_cv_cxx,
      [ssp_old_cxxflags="$CXXFLAGS"
       CXXFLAGS="$CXXFLAGS -fstack-protector-strong"
       AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [])], [ssp_cv_cxx=yes], [ssp_cv_cxx=no])
       CXXFLAGS="$ssp_old_cxxflags"
      ])
    if test $ssp_cv_cxx = yes; then
      CXXFLAGS="$CXXFLAGS -fstack-protector-strong"
      AC_DEFINE([ENABLE_SSP_CXX], 1, [Define if SSP C++ support is enabled.])
    else
      unset ssp_cv_cxx
      AC_CACHE_CHECK([whether ${CXX} accepts -fstack-protector],
        ssp_cv_cxx,
        [ssp_old_cxxflags="$CXXFLAGS"
         CXXFLAGS="$CXXFLAGS -fstack-protector"
         AC_COMPILE_IFELSE([AC_LANG_PROGRAM([], [])], [ssp_cv_cxx=yes], [ssp_cv_cxx=no])
         CXXFLAGS="$ssp_old_cxxflags"
        ])
      if test $ssp_cv_cxx = yes; then
        CXXFLAGS="$CXXFLAGS -fstack-protector"
        AC_DEFINE([ENABLE_SSP_CXX], 1, [Define if SSP C++ support is enabled.])
      fi
    fi
  fi
])

AC_DEFUN([AX_GCC_STACK_PROTECTOR],[
  AX_GCC_STACK_PROTECT_LIB

  AC_LANG_PUSH([C])
  AX_GCC_STACK_PROTECT_CC
  AC_LANG_POP([C])

  AC_LANG_PUSH([C++])
  AX_GCC_STACK_PROTECT_CXX
  AC_LANG_POP([C++])
])
