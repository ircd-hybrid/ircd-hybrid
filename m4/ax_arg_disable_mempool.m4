AC_DEFUN([AX_ARG_DISABLE_MEMPOOL],[
  AC_ARG_ENABLE([mempool],[AS_HELP_STRING([--disable-mempool],[Disables the memory pooling allocator.])],[mempool=$enableval],[mempool="yes"])

  AS_IF([test "$mempool" = "no"], [
    AC_DEFINE([MEMPOOL_DISABLED], 1, [Define to disable the memory pooling allocator.])
  ])
])
