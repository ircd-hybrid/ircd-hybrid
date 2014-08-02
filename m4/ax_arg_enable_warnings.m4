AC_DEFUN([AX_ARG_ENABLE_WARNINGS],[
  AC_ARG_ENABLE([warnings],[AS_HELP_STRING([--enable-warnings],[Enable compiler warnings.])],[warnings="$enableval"],[warnings="no"])

  if test "$warnings" = "yes" ; then
    AX_APPEND_COMPILE_FLAGS([-Wall])
    AX_APPEND_COMPILE_FLAGS([-Wextra])
    AX_APPEND_COMPILE_FLAGS([-Wno-unused])
    AX_APPEND_COMPILE_FLAGS([-Wcast-qual])
    AX_APPEND_COMPILE_FLAGS([-Wcast-align])
    AX_APPEND_COMPILE_FLAGS([-Wbad-function-cast])
    AX_APPEND_COMPILE_FLAGS([-Wlogical-op])
    AX_APPEND_COMPILE_FLAGS([-Wmissing-declarations])
    AX_APPEND_COMPILE_FLAGS([-Wmissing-include-dirs])
    AX_APPEND_COMPILE_FLAGS([-Wmissing-prototypes])
    AX_APPEND_COMPILE_FLAGS([-Wnested-externs])
    AX_APPEND_COMPILE_FLAGS([-Wpointer-arith])
    AX_APPEND_COMPILE_FLAGS([-Wredundant-decls])
    AX_APPEND_COMPILE_FLAGS([-Wshadow])
    AX_APPEND_COMPILE_FLAGS([-Wwrite-strings])
    AX_APPEND_COMPILE_FLAGS([-Wundef])
  fi
])
