AC_PREREQ([2.71])

dnl Project initialization.
AC_INIT([ircd-hybrid], [8.2.48], [bugs@ircd-hybrid.org])
AC_CONFIG_SRCDIR([src/ircd.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

AM_INIT_AUTOMAKE([1.16.5 subdir-objects])

dnl Toolchain.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX([noyywrap])
AC_PROG_INSTALL

dnl Libtool and libltdl.
LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen disable-static])
LTDL_INIT([recursive convenience])
LIBTOOL="$LIBTOOL --silent"

dnl Compiler flag handling.
dnl Make Clang reject unknown warning options so feature tests detect them.
AX_APPEND_COMPILE_FLAGS([-Werror=unknown-warning-option])
dnl Disable GCC's format-truncation warning when supported.
AX_APPEND_COMPILE_FLAGS([-Wno-format-truncation])

dnl Build options and feature selection.
AX_ARG_IOLOOP_MECHANISM
AX_ARG_ENABLE_ASSERT
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS
AX_ARG_ENABLE_EFENCE
AX_ARG_WITH_TLS

dnl Build hardening.
AX_ARG_ENABLE_STACK_PROTECTOR

dnl Required libraries and platform support.
AX_LIBRARY_JANSSON
AX_LIBRARY_NET
AC_SEARCH_LIBS([crypt], [crypt])

dnl Platform characteristics.
AC_C_BIGENDIAN

dnl Header availability.
AC_CHECK_HEADERS_ONCE([
  crypt.h
  socket.h
  sys/param.h
  sys/wait.h
  types.h
])

dnl Function availability.
AC_CHECK_FUNCS_ONCE([
  strlcat
  strlcpy
])

AX_CHECK_STRFTIME_MINUS_E

dnl Compile-time installation paths.
AX_DEFINE_DIR([PREFIX], [prefix], [Set to prefix.])
AX_DEFINE_DIR([SYSCONFDIR], [sysconfdir], [Set to sysconfdir.])
AX_DEFINE_DIR([LIBDIR], [libdir], [Set to libdir.])
AX_DEFINE_DIR([DATADIR], [datadir], [Set to datadir.])
AX_DEFINE_DIR([LOCALSTATEDIR], [localstatedir], [Set to localstatedir.])

dnl Reproducible build metadata.
AX_DEFINE_BUILD_DATE

dnl Generated files.
AC_CONFIG_FILES([
  Makefile
  doc/Makefile
  help/Makefile
  libio/Makefile
  libio/src/Makefile
  libltdl/Makefile
  modules/Makefile
  src/Makefile
  tools/Makefile
])

AC_OUTPUT

AC_MSG_NOTICE([Configuration complete.])
AC_MSG_NOTICE([Installation prefix: ${prefix}])
AC_MSG_NOTICE([Run 'make' (or 'gmake' on some BSD systems) to build ircd-hybrid.])
