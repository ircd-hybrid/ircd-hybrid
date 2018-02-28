AC_DEFUN([AX_ARG_ENABLE_EFENCE],[
  AC_ARG_ENABLE([efence],[AS_HELP_STRING([--enable-efence],[Enable linking with Electric Fence 'efence' memory debugger library.])],[efence="$enableval"],[efence="no"])

  AS_IF([test "$efence" = "yes"], [
    AC_SEARCH_LIBS(EF_Print, efence, [], [AC_MSG_FAILURE([Electric Fence 'efence' library not found])])
  ])
])
