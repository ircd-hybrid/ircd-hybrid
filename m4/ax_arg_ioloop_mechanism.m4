AC_DEFUN([AX_ARG_IOLOOP_MECHANISM],[
  desired_iopoll_mechanism="none"
  dnl FIXME need to handle arguments a bit better (see ac_arg_disable_block_alloc)

  AC_ARG_ENABLE([kqueue], [AS_HELP_STRING([--enable-kqueue], [Force kqueue usage.])], [desired_iopoll_mechanism="kqueue"])
  AC_ARG_ENABLE([epoll],  [AS_HELP_STRING([--enable-epoll],  [Force epoll usage.])],  [desired_iopoll_mechanism="epoll"])
  AC_ARG_ENABLE([devpoll],[AS_HELP_STRING([--enable-devpoll],[Force devpoll usage.])],[desired_iopoll_mechanism="devpoll"])
  AC_ARG_ENABLE([poll],   [AS_HELP_STRING([--enable-poll],   [Force poll usage.])],   [desired_iopoll_mechanism="poll"])

  AC_MSG_CHECKING([for optimal/desired iopoll mechanism])

  iopoll_mechanism_none=0
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_NONE],[$iopoll_mechanism_none],[no iopoll mechanism])

  iopoll_mechanism_kqueue=1
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_KQUEUE],[$iopoll_mechanism_kqueue],[kqueue mechanism])
  AC_LINK_IFELSE([AC_LANG_FUNC_LINK_TRY([kevent])],[is_kqueue_mechanism_available="yes"],[is_kqueue_mechanism_available="no"])

  iopoll_mechanism_epoll=2
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_EPOLL],[$iopoll_mechanism_epoll],[epoll mechanism])
  AC_LINK_IFELSE([AC_LANG_PROGRAM([#include <sys/epoll.h>], [epoll_create(256);])], [is_epoll_mechanism_available="yes"],[is_epoll_mechanism_available="no"])

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

  iopoll_mechanism_poll=4
  AC_DEFINE_UNQUOTED([__IOPOLL_MECHANISM_POLL],[$iopoll_mechanism_poll],[poll mechanism])
  AC_LINK_IFELSE([AC_LANG_FUNC_LINK_TRY([poll])],[is_poll_mechanism_available="yes"],[is_poll_mechanism_available="no"])

  optimal_iopoll_mechanism="none"
  for mechanism in "kqueue" "epoll" "devpoll" "poll" ; do # order is important
    eval "is_optimal_iopoll_mechanism_available=\$is_${mechanism}_mechanism_available"
    if test "$is_optimal_iopoll_mechanism_available" = "yes" ; then
      optimal_iopoll_mechanism="$mechanism"
      break
    fi
  done

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

  eval "use_iopoll_mechanism=\$iopoll_mechanism_${selected_iopoll_mechanism}"
  AC_DEFINE_UNQUOTED([USE_IOPOLL_MECHANISM],[$use_iopoll_mechanism],[use this iopoll mechanism])
])
