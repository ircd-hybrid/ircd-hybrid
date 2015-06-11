AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],[AS_HELP_STRING([--enable-debugging],[Enable debugging.])],[debugging="$enableval"],[debugging="no"])

  AS_IF([test "$debugging" = "yes"], [
    CFLAGS="-Wall -g -O0"
  ])
])
