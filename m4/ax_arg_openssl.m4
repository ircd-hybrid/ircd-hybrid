AC_DEFUN([AX_ARG_OPENSSL], [
AC_ARG_ENABLE(openssl,
[  --enable-openssl[=DIR]       Enable LibreSSL/OpenSSL support (DIR optional).
  --disable-openssl            Disable LibreSSL/OpenSSL support. ],
[ cf_enable_openssl=$enableval ],
[ cf_enable_openssl="auto" ])
AC_MSG_CHECKING([for LibreSSL/OpenSSL])
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
 [AC_MSG_CHECKING(for LibreSSL or OpenSSL 1.0.1f and above)
  AC_RUN_IFELSE([
    AC_LANG_PROGRAM([
    #include <openssl/opensslv.h>
    #include <stdlib.h>],
    [[ exit(!(OPENSSL_VERSION_NUMBER >= 0x1000106fL)); ]])],
  [cf_openssl_version_ok=yes],
  [cf_openssl_version_ok=no],
  [cf_openssl_version_ok=no])

  AS_IF([test "$cf_openssl_version_ok" = "yes"],
    [AC_MSG_RESULT(found)

    AC_CHECK_LIB(crypto, RSA_free)
    AS_IF([test "$ac_cv_lib_crypto_RSA_free" = "yes"],
      [AC_CHECK_LIB(ssl, SSL_connect)])
    ],[AC_MSG_RESULT(no - LibreSSL/OpenSSL support disabled)
    cf_enable_openssl="no"])])
])
