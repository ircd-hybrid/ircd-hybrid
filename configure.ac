# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_REVISION([$Id$])

AC_PREREQ(2.69)
AC_INIT([ircd-hybrid], [TRUNK], [bugs@ircd-hybrid.org])
AM_INIT_AUTOMAKE(1.13.1 subdir-objects)
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

AX_CHECK_LIB_IPV4
AX_CHECK_LIB_IPV6

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN

# Checks for library functions.
AC_CHECK_FUNCS_ONCE(strtok_r \
                    usleep   \
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

AC_ARG_ENABLE(libgeoip,
  [AS_HELP_STRING([--disable-libgeoip],[Disable GeoIP support])], [],
    [AC_CHECK_HEADER(GeoIP.h,
      [AC_SEARCH_LIBS(GeoIP_id_by_ipnum_v6_gl, GeoIP,
        [AC_DEFINE(HAVE_LIBGEOIP, 1, [Define to 1 if libGeoIP (-lGeoIP) is available.])])])], [])

AX_CHECK_OPENSSL

AC_ARG_ENABLE(assert, AS_HELP_STRING([--enable-assert], 
                                     [Enable assert() statements]),
  [assert=$enableval], [assert=no])

AS_IF([test "$assert" = "no"],
  [AC_DEFINE(NDEBUG, 1, [Define to disable assert() statements.])])

AC_DEFINE([NICKNAMEHISTORYLENGTH], 32768, [Size of the WHOWAS array.])
AC_DEFINE([MP_CHUNK_SIZE_CHANNEL], 1024*1024, [Size of the channel mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_MEMBER], 2048*1024, [Size of the channel-member mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_BAN], 1024*1024, [Size of the ban mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_CLIENT], 1024*1024, [Size of the client mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_LCLIENT], 512*1024, [Size of the local client mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_DNODE], 32*1024, [Size of the dlink_node mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_DBUF], 512*1024, [Size of the dbuf mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_AUTH], 128*1024, [Size of the auth mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_DNS], 64*1024, [Size of the dns mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_WATCH], 8*1024, [Size of the watch mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_NAMEHOST], 64*1024, [Size of the namehost mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_USERHOST], 128*1024, [Size of the userhost mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_IP_ENTRY], 128*1024, [Size of the ip_entry mempool chunk.])

# Argument processing.
AX_ARG_ENABLE_IOLOOP_MECHANISM
AX_ARG_ENABLE_HALFOPS
AX_ARG_ENABLE_DEBUGGING
AX_ARG_ENABLE_WARNINGS

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
       doc/Makefile           \
       help/Makefile          \
       tools/Makefile)

AC_OUTPUT
