AC_DEFUN([AX_ARG_WITH_TLS], [

AC_ARG_WITH([tls], [AS_HELP_STRING([--with-tls], [Enables TLS with specified library. Options: 'openssl', 'wolfssl', 'gnutls' or 'none'])], [with_tls=$withval], [with_tls=auto])

if test "$with_tls" = "openssl" ||
   test "$with_tls" = "auto"; then
    AC_CHECK_HEADER([openssl/opensslv.h], [
      AC_COMPUTE_INT([OPENSSL_VERSION_NUMBER],[OPENSSL_VERSION_NUMBER],[#include <openssl/opensslv.h>])
      AS_IF([test "$OPENSSL_VERSION_NUMBER" -ge $((0x1010100f))],[AC_CHECK_LIB([crypto], [RSA_free], [], [], [])])
    ])

    AS_IF([test "$ac_cv_lib_crypto_RSA_free" = "yes"], [AC_CHECK_LIB([ssl], [SSL_connect])], [])

    AC_MSG_CHECKING([for LibreSSL, or OpenSSL 1.1.1 and above])
    AS_IF([test "$ac_cv_lib_ssl_SSL_connect" = "yes"],
          [AC_MSG_RESULT([found])], [AC_MSG_RESULT([no - LibreSSL/OpenSSL support disabled])])

fi

if test "$with_tls" = "gnutls" ||
   test "$with_tls" = "auto"; then
  if test "$ac_cv_lib_ssl_SSL_connect" != "yes"; then

    AC_CHECK_HEADER([gnutls/gnutls.h], [
      AC_COMPUTE_INT([GNUTLS_VERSION_NUMBER],[GNUTLS_VERSION_NUMBER],[#include <gnutls/gnutls.h>])
      AS_IF([test "$GNUTLS_VERSION_NUMBER" -ge $((0x030605))],[AC_CHECK_LIB([gnutls], [gnutls_init], [], [], [])])
    ])

    AC_MSG_CHECKING([for GnuTLS 3.6.5 and above])
    AS_IF([test "$ac_cv_lib_gnutls_gnutls_init" = "yes"],
          [AC_MSG_RESULT([found])], [AC_MSG_RESULT([no - GnuTLS support disabled])])

  fi
fi

if test "$with_tls" = "wolfssl" ||
   test "$with_tls" = "auto"; then
  if test "$ac_cv_lib_ssl_SSL_connect" != "yes" &&
     test "$ac_cv_lib_gnutls_gnutls_init" != "yes"; then

    AC_CHECK_HEADER([wolfssl/ssl.h], [
      AC_COMPUTE_INT([LIBWOLFSSL_VERSION_HEX],[LIBWOLFSSL_VERSION_HEX],[#include <wolfssl/version.h>])
      AS_IF([test "$LIBWOLFSSL_VERSION_HEX" -ge $((0x04003000))],[AC_CHECK_LIB([wolfssl], [wolfSSL_X509_digest], [], [], [])])
    ])

    AC_MSG_CHECKING([for wolfSSL 4.3.0 and above built with extended/full OpenSSL compatibility layer])
    AS_IF([test "$ac_cv_lib_wolfssl_wolfSSL_X509_digest" = "yes"],
          [AC_MSG_RESULT([found])], [AC_MSG_RESULT([no - wolfSSL support disabled])])

  fi
fi

])
