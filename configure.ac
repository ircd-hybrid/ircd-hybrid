dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([ircd-hybrid], [8.2.44], [bugs@ircd-hybrid.org])
AM_INIT_AUTOMAKE([1.16.5 subdir-objects])
AM_MAINTAINER_MODE
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/ircd.c])

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX([noyywrap])
AC_PROG_INSTALL

# Initializing libtool.
LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen disable-static])
LTDL_INIT([recursive convenience])
LIBTOOL="$LIBTOOL --silent"

# Checks for libraries.
AX_GCC_STACK_PROTECT_CC
AX_GCC_STACK_PROTECT_LIB
AX_LIBRARY_NET

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN

# Checks for library functions.
AC_CHECK_FUNCS_ONCE([strlcat strlcpy])

# Checks for header files.
AC_CHECK_HEADERS_ONCE([
  crypt.h
  sys/param.h
  types.h
  socket.h
  sys/wait.h
])

AC_SEARCH_LIBS([crypt], [crypt])

# Set -Werror=unknown-warning-option for clang so subsequent
# AX_APPEND_COMPILE_FLAGS executions work properly.
AX_APPEND_COMPILE_FLAGS([-Werror=unknown-warning-option])
# Disable -Wformat-truncation specifically for gcc.
AX_APPEND_COMPILE_FLAGS([-Wno-format-truncation])

# Argument processing.
AX_ARG_IOLOOP_MECHANISM
AX_ARG_ENABLE_ASSERT
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS
AX_ARG_ENABLE_EFENCE
AX_ARG_WITH_TLS

AX_DEFINE_DIR([PREFIX], [prefix], [Set to prefix.])
AX_DEFINE_DIR([SYSCONFDIR], [sysconfdir], [Set to sysconfdir.])
AX_DEFINE_DIR([LIBDIR], [libdir], [Set to libdir.])
AX_DEFINE_DIR([DATADIR], [datadir], [Set to datadir.])
AX_DEFINE_DIR([LOCALSTATEDIR], [localstatedir], [Set to localstatedir.])

AX_DEFINE_BUILD_DATE

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  libltdl/Makefile
  modules/Makefile
  modules/core/Makefile
  modules/extra/Makefile
  doc/Makefile
  help/Makefile
  tools/Makefile
])

AC_OUTPUT

echo "###############################################################################"
echo "Configuration complete.  Type make (or gmake on some *BSD machines) to compile."
echo
echo "ircd-hybrid will be installed in ${prefix}.  To change this, run:"
echo "   ./configure --prefix=DIRECTORY"
echo "###############################################################################"
