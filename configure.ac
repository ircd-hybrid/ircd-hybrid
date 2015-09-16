dnl Process this file with autoconf to produce a configure script.

AC_REVISION([$Id$])

AC_PREREQ(2.69)
AC_INIT([ircd-hybrid], [TRUNK], [bugs@ircd-hybrid.org])
AM_INIT_AUTOMAKE(1.15 subdir-objects)
AM_MAINTAINER_MODE
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER(config.h)
AC_CONFIG_SRCDIR(src/ircd.c)

# Checks for programs.
AC_PROG_CC_C99
AS_IF([test "$ac_cv_prog_cc_c99" = "no"],
    [AC_MSG_ERROR([no suitable C99 compiler found. Aborting.])])
AC_PROG_YACC
AM_PROG_LEX
AC_PROG_INSTALL

# Initializing libtool.
LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen disable-static])
LTDL_INIT([recursive convenience])
LIBTOOL="$LIBTOOL --silent"

# Checks for libraries.
GCC_STACK_PROTECT_CC
GCC_STACK_PROTECT_LIB

AX_APPEND_COMPILE_FLAGS([-fno-strict-aliasing])
AX_LIBRARY_NET

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN

# Checks for library functions.
AC_CHECK_FUNCS_ONCE(strtok_r \
                    strlcat  \
                    strlcpy)

# Checks for header files.
AC_CHECK_HEADERS_ONCE(crypt.h        \
                      sys/resource.h \
                      sys/param.h    \
                      types.h        \
                      socket.h       \
                      sys/wait.h     \
                      wait.h)

AC_SEARCH_LIBS(crypt, crypt)

# Define various chunk sizes for the pooling allocator
AX_MEMPOOL_CHUNKSIZES

# Argument processing.
AX_ARG_IOLOOP_MECHANISM
AX_ARG_ENABLE_ASSERT
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS
AX_ARG_OPENSSL
AX_ARG_LIBGEOIP

AC_DEFINE_DIR([PREFIX],[prefix],[Set to prefix.])
AC_DEFINE_DIR([SYSCONFDIR],[sysconfdir],[Set to sysconfdir.])
AC_DEFINE_DIR([LIBDIR],[libdir],[Set to libdir.])
AC_DEFINE_DIR([DATADIR],[datadir],[Set to datadir.])
AC_DEFINE_DIR([LOCALSTATEDIR],[localstatedir],[Set to localstatedir.])

AC_CONFIG_FILES(              \
       Makefile               \
       src/Makefile           \
       libltdl/Makefile       \
       modules/Makefile       \
       modules/core/Makefile  \
       modules/extra/Makefile \
       doc/Makefile           \
       help/Makefile          \
       tools/Makefile)

AC_OUTPUT

echo "###############################################################################"
echo "Configuration complete.  Type make (or gmake on some *BSD machines) to compile."
echo
echo "ircd-hybrid will be installed in ${prefix}.  To change this, run:"
echo "   ./configure --prefix=DIRECTORY"
echo "###############################################################################"
