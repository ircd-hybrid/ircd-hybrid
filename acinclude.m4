dnl Inspired by work Copyright (C) 2006 Luca Filipozzi
dnl vim: set fdm=marker sw=2 ts=2 et si:
dnl {{{ ax_check_lib_ipv4
AC_DEFUN([AX_CHECK_LIB_IPV4],[
  AC_CHECK_FUNC(getaddrinfo, [], AC_SEARCH_LIBS(getaddrinfo, nsl))
  AC_CHECK_FUNC(getnameinfo, [], AC_SEARCH_LIBS(getnameinfo, nsl))
  AC_SEARCH_LIBS([socket],[socket],,[AC_MSG_ERROR([socket library not found])])
  AC_CHECK_TYPES([struct sockaddr_in, struct sockaddr_storage, struct addrinfo],,,[#include <sys/types.h>
   #include <sys/socket.h>
   #include <netdb.h>
  ])
  AC_CHECK_MEMBERS([struct sockaddr_in.sin_len],,,[#include <sys/types.h>
  <sys/socket.h>])
])dnl }}}
dnl {{{ ax_check_lib_ipv6
AC_DEFUN([AX_CHECK_LIB_IPV6],[
  AC_CHECK_TYPE([struct sockaddr_in6],[AC_DEFINE([IPV6],[1],[Define to 1 if you have IPv6 support.])],,[#include <netinet/in.h>])
])dnl }}}
dnl {{{ ax_arg_enable_ioloop_mechanism (FIXME)
AC_DEFUN([AX_ARG_ENABLE_IOLOOP_MECHANISM],[
  dnl {{{ allow the user to specify desired mechanism
  desired_iopoll_mechanism="none"
  dnl FIXME need to handle arguments a bit better (see ac_arg_disable_block_alloc)
  AC_ARG_ENABLE([kqueue], [AS_HELP_STRING([--enable-kqueue], [Force kqueue usage.])], [desired_iopoll_mechanism="kqueue"])
  AC_ARG_ENABLE([epoll],  [AS_HELP_STRING([--enable-epoll],  [Force epoll usage.])],  [desired_iopoll_mechanism="epoll"])
  AC_ARG_ENABLE([devpoll],[AS_HELP_STRING([--enable-devpoll],[Force devpoll usage.])],[desired_iopoll_mechanism="devpoll"])
  AC_ARG_ENABLE([poll],   [AS_HELP_STRING([--enable-poll],   [Force poll usage.])],   [desired_iopoll_mechanism="poll"]) 
  AC_ARG_ENABLE([select], [AS_HELP_STRING([--enable-select], [Force select usage.])], [desired_iopoll_mechanism="select"])
  dnl }}}
  dnl {{{ preamble
  AC_MSG_CHECKING([for optimal/desired iopoll mechanism])
  iopoll_mechanism_none=0
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_NONE],[$iopoll_mechanism_none],[no iopoll mechanism])
  dnl }}}
  dnl {{{ check for kqueue mechanism support
  iopoll_mechanism_kqueue=1
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_KQUEUE],[$iopoll_mechanism_kqueue],[kqueue mechanism])
  AC_LINK_IFELSE([AC_LANG_FUNC_LINK_TRY([kevent])],[is_kqueue_mechanism_available="yes"],[is_kqueue_mechanism_available="no"])
  dnl }}}
  dnl {{{ check for epoll oechanism support
  iopoll_mechanism_epoll=2
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_EPOLL],[$iopoll_mechanism_epoll],[epoll mechanism])
  AC_RUN_IFELSE([AC_LANG_PROGRAM([[
#include <sys/epoll.h>
#include <sys/syscall.h>
#if defined(__stub_epoll_create) || defined(__stub___epoll_create) || defined(EPOLL_NEED_BODY)
#if !defined(__NR_epoll_create)
#if defined(__ia64__)
#define __NR_epoll_create 1243
#elif defined(__x86_64__)
#define __NR_epoll_create 214
#elif defined(__sparc64__) || defined(__sparc__)
#define __NR_epoll_create 193
#elif defined(__s390__) || defined(__m68k__)
#define __NR_epoll_create 249
#elif defined(__ppc64__) || defined(__ppc__)
#define __NR_epoll_create 236
#elif defined(__parisc__) || defined(__arm26__) || defined(__arm__)
#define __NR_epoll_create 224
#elif defined(__alpha__)
#define __NR_epoll_create 407
#elif defined(__sh64__)
#define __NR_epoll_create 282
#elif defined(__i386__) || defined(__sh__) || defined(__m32r__) || defined(__h8300__) || defined(__frv__)
#define __NR_epoll_create 254
#else
#error No system call numbers defined for epoll family.
#endif
#endif
_syscall1(int, epoll_create, int, size)
#endif
]], [[ return epoll_create(256) == -1 ? 1 : 0 ]])],
  [is_epoll_mechanism_available="yes"],[is_epoll_mechanism_available="no"])
  dnl }}}
  dnl {{{ check for devpoll mechanism support
  iopoll_mechanism_devpoll=3
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_DEVPOLL],[$iopoll_mechanism_devpoll],[devpoll mechanism])
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([#include <devpoll.h>])],[is_devpoll_mechanism_available="yes"],[is_devpoll_mechanism_available="no"])
  if test "$is_devpoll_mechanism_available" = "yes" ; then
    AC_DEFINE([HAVE_DEVPOLL_H],[1],[Define to 1 if you have the <devpoll.h> header file.])
  fi
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([#include <sys/devpoll.h>])],[is_devpoll_mechanism_available="yes"],[is_devpoll_mechanism_available="no"])
  if test "$is_devpoll_mechanism_available" = "yes" ; then
    AC_DEFINE([HAVE_SYS_DEVPOLL_H],[1],[Define to 1 if you have the <sys/devpoll.h> header file.])
  fi
  dnl }}}
  dnl {{{ check for poll mechanism support
  iopoll_mechanism_poll=4
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_POLL],[$iopoll_mechanism_poll],[poll mechanism])
  AC_LINK_IFELSE([AC_LANG_FUNC_LINK_TRY([poll])],[is_poll_mechanism_available="yes"],[is_poll_mechanism_available="no"])
  dnl }}}
  dnl {{{ check for select mechanism support
  iopoll_mechanism_select=5
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_SELECT],[$iopoll_mechanism_select],[select mechanism])
  AC_LINK_IFELSE([AC_LANG_FUNC_LINK_TRY([select])],[is_select_mechanism_available="yes"],[is_select_mechanism_available="no"])
  dnl }}}
  dnl {{{ determine the optimal mechanism
  optimal_iopoll_mechanism="none"
  for mechanism in "kqueue" "epoll" "devpoll" "poll" "select" ; do # order is important
    eval "is_optimal_iopoll_mechanism_available=\$is_${mechanism}_mechanism_available"
    if test "$is_optimal_iopoll_mechanism_available" = "yes" ; then
      optimal_iopoll_mechanism="$mechanism"
      break
    fi
  done
  dnl }}}
  dnl {{{ select between optimal mechanism and desired mechanism (if specified)
  if test "$desired_iopoll_mechanism" = "none" ; then
    if test "$optimal_iopoll_mechanism" = "none" ; then
      AC_MSG_RESULT([none])
      AC_MSG_ERROR([no iopoll mechanism found!])
    else
      selected_iopoll_mechanism=$optimal_iopoll_mechanism
      AC_MSG_RESULT([$selected_iopoll_mechanism])
    fi
  else
    eval "is_desired_iopoll_mechanism_available=\$is_${desired_iopoll_mechanism}_mechanism_available"
    if test "$is_desired_iopoll_mechanism_available" = "yes" ; then
      selected_iopoll_mechanism=$desired_iopoll_mechanism
      AC_MSG_RESULT([$selected_iopoll_mechanism])
    else
      AC_MSG_RESULT([none])
      AC_MSG_ERROR([desired iopoll mechanism, $desired_iopoll_mechanism, is not available])
    fi
  fi
  dnl }}}
  dnl {{{ postamble
  eval "use_iopoll_mechanism=\$iopoll_mechanism_${selected_iopoll_mechanism}"
  AC_DEFINE_UNQUOTED([USE_IOPOLL_MECHANISM],[$use_iopoll_mechanism],[use this iopoll mechanism])
  dnl }}}
])dnl }}}
dnl {{{ ax_arg_enable_halfops
AC_DEFUN([AX_ARG_ENABLE_HALFOPS],[
  AC_ARG_ENABLE([halfops],[AS_HELP_STRING([--enable-halfops],[Enable halfops support.])],[halfops="$enableval"],[halfops="no"])
  if test "$halfops" = "yes" ; then
    AC_DEFINE([HALFOPS],[1],[Define to 1 if you want halfops support.])
  fi
])dnl }}}
dnl {{{ ax_arg_enable_debugging
AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],[AS_HELP_STRING([--enable-debugging],[Enable debugging.])],[debugging="$enableval"],[debugging="no"])
  if test "$debugging" = "yes" ; then
    CFLAGS="-Wall -g -O0"
  fi
])dnl }}}
dnl {{{ ax_arg_enable_warnings
AC_DEFUN([AX_ARG_ENABLE_WARNINGS],[
  AC_ARG_ENABLE([warnings],[AS_HELP_STRING([--enable-warnings],[Enable compiler warnings.])],[warnings="$enableval"],[warnings="no"])
  if test "$warnings" = "yes" ; then
    AX_APPEND_COMPILE_FLAGS([-Wall])
    AX_APPEND_COMPILE_FLAGS([-Wextra])
    AX_APPEND_COMPILE_FLAGS([-Wno-unused])
    AX_APPEND_COMPILE_FLAGS([-Wcast-qual])
    AX_APPEND_COMPILE_FLAGS([-Wcast-align])
    AX_APPEND_COMPILE_FLAGS([-Wbad-function-cast])
    AX_APPEND_COMPILE_FLAGS([-Wmissing-declarations])
    AX_APPEND_COMPILE_FLAGS([-Wmissing-prototypes])
    AX_APPEND_COMPILE_FLAGS([-Wnested-externs])
    AX_APPEND_COMPILE_FLAGS([-Wredundant-decls])
    AX_APPEND_COMPILE_FLAGS([-Wshadow])
    AX_APPEND_COMPILE_FLAGS([-Wwrite-strings])
    AX_APPEND_COMPILE_FLAGS([-Wundef])
  fi
])dnl }}}
]) dnl }}}
