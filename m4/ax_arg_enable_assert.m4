AC_DEFUN([AX_ARG_ENABLE_ASSERT],[
  AC_ARG_ENABLE(assert, AS_HELP_STRING([--enable-assert],
                                       [Enable assert() statements]),
    [assert=$enableval], [assert=no])

  AS_IF([test "$assert" = "no"],
    [AC_DEFINE(NDEBUG, 1, [Define to disable assert() statements.])])
])
