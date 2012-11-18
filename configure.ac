# Inspired by work Copyright (C) 2006 Luca Filipozzi
# vim: set fdm=marker ts=2 sw=2 et:

AC_REVISION([$Id$])

AC_PREREQ(2.69)
AC_INIT([ircd-hybrid], [8.0.0], [bugs@ircd-hybrid.org])
AM_INIT_AUTOMAKE(1.12.5)
AM_MAINTAINER_MODE
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

AC_ARG_ENABLE(libpcre,
  [AS_HELP_STRING([--disable-libpcre],[Disable PCRE support])], [],
    [AC_CHECK_HEADER(pcre.h,
      [AC_SEARCH_LIBS(pcre_study, pcre,
        [AC_DEFINE(HAVE_LIBPCRE, 1, [Define to 1 if libpcre (-lpcre) is available.])])])], [])

dnl Openssl checks
AC_ARG_ENABLE(openssl,
[  --enable-openssl[=DIR]       Enable OpenSSL support (DIR optional).
  --disable-openssl            Disable OpenSSL support. ],
[ cf_enable_openssl=$enableval ],
[ cf_enable_openssl="auto" ])
AC_MSG_CHECKING([for OpenSSL])
if test "$cf_enable_openssl" != "no"; then
  cf_openssl_basedir=""
  if test "$cf_enable_openssl" != "auto" &&
     test "$cf_enable_openssl" != "yes"; then
     dnl Support for --enable-openssl=/some/place
     cf_openssl_basedir="${cf_enable_openssl}"
  else
    dnl Do the auto-probe here.  Check some common directory paths.
    for dirs in /usr/local/ssl /usr/pkg /usr/local /usr/lib /usr/lib/ssl\
                /opt /opt/openssl /usr/local/openssl; do
      if test -f "${dirs}/include/openssl/opensslv.h"; then
        cf_openssl_basedir="${dirs}"
        break
      fi
    done
    unset dirs
  fi

  dnl Now check cf_openssl_found to see if we found anything.
  if test ! -z "$cf_openssl_basedir"; then
    if test -f "${cf_openssl_basedir}/include/openssl/opensslv.h"; then
      CPPFLAGS="-I${cf_openssl_basedir}/include $CPPFLAGS"
      LDFLAGS="-L${cf_openssl_basedir}/lib $LDFLAGS"
    else
      dnl OpenSSL wasn't found in the directory specified.  Naughty
      dnl administrator...
      cf_openssl_basedir=""
    fi
  else
    dnl Check for stock FreeBSD 4.x and 5.x systems, since their files
    dnl are in /usr/include and /usr/lib.  In this case, we don't want to
    dnl change INCLUDES or LIBS, but still want to enable OpenSSL.
    dnl We can't do this check above, because some people want two versions
    dnl of OpenSSL installed (stock FreeBSD 4.x/5.x and /usr/local/ssl)
    dnl and they want /usr/local/ssl to have preference.
    if test -f "/usr/include/openssl/opensslv.h"; then
      cf_openssl_basedir="/usr"
    fi
  fi

  dnl If we have a basedir defined, then everything is okay.  Otherwise,
  dnl we have a problem.
  if test ! -z "$cf_openssl_basedir"; then
    AC_MSG_RESULT([$cf_openssl_basedir])
    cf_enable_openssl="yes"
  else
    AC_MSG_RESULT([not found. Please check your path.])
    cf_enable_openssl="no"
  fi
  unset cf_openssl_basedir
else
  dnl If --disable-openssl was specified
  AC_MSG_RESULT([disabled])
fi

AS_IF([test "$cf_enable_openssl" != "no"],
 [AC_MSG_CHECKING(for OpenSSL 0.9.8 or above)
  AC_RUN_IFELSE([
    AC_LANG_PROGRAM([
    #include <openssl/opensslv.h>
    #include <stdlib.h>],
    [[ exit(!(OPENSSL_VERSION_NUMBER >= 0x00908000)); ]])],
  [cf_openssl_version_ok=yes],
  [cf_openssl_version_ok=no],
  [cf_openssl_version_ok=no])

  AS_IF([test "$cf_openssl_version_ok" = "yes"],
    [AC_MSG_RESULT(found)

    AC_CHECK_LIB(crypto, RSA_free)
    AS_IF([test "$ac_cv_lib_crypto_RSA_free" = "yes"],
      [AC_CHECK_LIB(ssl, SSL_connect)])
    ],[AC_MSG_RESULT(no - OpenSSL support disabled)
    cf_enable_openssl="no"])])

AM_CONDITIONAL(ENABLE_SSL, [test "$ac_cv_lib_ssl_SSL_connect" = yes])


AC_ARG_ENABLE(assert, AS_HELP_STRING([--enable-assert], 
                                     [Enable assert() statements]),
  [assert=$enableval], [assert=no])

AS_IF([test "$assert" = "no"],
  [AC_DEFINE(NDEBUG, 1, [Define to disable assert() statements.])])


AC_DEFINE([NICKNAMEHISTORYLENGTH], 16384, [Size of the WHOWAS array.])
AC_DEFINE([MP_CHUNK_SIZE_CHANNEL], 64*1024, [Size of the channel mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_MEMBER], 32*1024, [Size of the channel mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_BAN], 16*1024, [Size of the ban mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_CLIENT], 256*1024, [Size of the client mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_LCLIENT], 128*1024, [Size of the local client mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_DNODE], 8*1024, [Size of the dlink_node mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_DBUF], 512*1024, [Size of the dbuf mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_AUTH], 32*1024, [Size of the auth mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_DNS], 16*1024, [Size of the dns mempool chunk.])
AC_DEFINE([MP_CHUNK_SIZE_WATCH], 4*1024, [Size of the watch mempool chunk.])

# Argument processing.
AX_ARG_ENABLE_IOLOOP_MECHANISM
AX_ARG_WITH_NICKLEN
AX_ARG_WITH_TOPICLEN
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
       messages/Makefile      \
       modules/Makefile       \
       modules/core/Makefile  \
       doc/Makefile           \
       help/Makefile          \
       help/opers/Makefile    \
       help/users/Makefile    \
       tools/Makefile)

AC_OUTPUT
