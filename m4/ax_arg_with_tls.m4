AC_DEFUN([AX_ARG_WITH_TLS], [
  AC_REQUIRE([AC_PROG_CC])
  AC_LANG_ASSERT([C])

  AC_ARG_WITH([tls],
    [AS_HELP_STRING([--with-tls=LIB],
      [use TLS library LIB: openssl, gnutls, wolfssl, none, or auto @<:@default=auto@:>@])],
    [with_tls=$withval],
    [with_tls=auto])

  AS_CASE([$with_tls],
    [yes], [with_tls=auto],
    [no], [with_tls=none],
    [auto|openssl|gnutls|wolfssl|none], [],
    [AC_MSG_ERROR([invalid value '$with_tls' for --with-tls; expected openssl, gnutls, wolfssl, none, or auto])])

  ax_tls_backend=none

  dnl OpenSSL >= 3.0.0. LibreSSL is intentionally not accepted here.
  AS_IF([test "x$with_tls" = xopenssl || test "x$with_tls" = xauto], [
    AC_MSG_CHECKING([for usable OpenSSL 3.0.0 or newer])

    ax_tls_openssl=no
    ax_tls_save_LIBS=$LIBS
    LIBS="-lssl -lcrypto $LIBS"

    AC_LINK_IFELSE([
      AC_LANG_PROGRAM([[
#include <openssl/opensslv.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>

#if defined(LIBRESSL_VERSION_NUMBER)
# error LibreSSL is not supported by the OpenSSL backend
#endif

#if !defined(OPENSSL_VERSION_MAJOR)
# error OpenSSL 3.0.0 or newer is required
#elif OPENSSL_VERSION_MAJOR < 3
# error OpenSSL 3.0.0 or newer is required
#endif
      ]], [[
volatile unsigned int version = OPENSSL_version_major();
SSL_CTX *ctx = SSL_CTX_new(TLS_method());

(void)version;
SSL_CTX_free(ctx);
      ]])
    ],
    [ax_tls_openssl=yes],
    [ax_tls_openssl=no])

    LIBS=$ax_tls_save_LIBS
    AC_MSG_RESULT([$ax_tls_openssl])

    AS_IF([test "x$ax_tls_openssl" = xyes], [
      LIBS="-lssl -lcrypto $LIBS"
      ax_tls_backend=openssl

      AC_DEFINE([HAVE_LIBCRYPTO], [1],
        [Define to 1 if OpenSSL libcrypto is available.])
      AC_DEFINE([HAVE_LIBSSL], [1],
        [Define to 1 if OpenSSL libssl is available.])
    ])
  ])

  dnl GnuTLS >= 3.6.5.
  AS_IF([test "x$ax_tls_backend" = xnone], [
    AS_IF([test "x$with_tls" = xgnutls || test "x$with_tls" = xauto], [
      AC_MSG_CHECKING([for usable GnuTLS 3.6.5 or newer])

      ax_tls_gnutls=no
      ax_tls_save_LIBS=$LIBS
      LIBS="-lgnutls $LIBS"

      AC_LINK_IFELSE([
        AC_LANG_PROGRAM([[
#include <gnutls/gnutls.h>

#if GNUTLS_VERSION_NUMBER < 0x030605
# error GnuTLS 3.6.5 or newer is required
#endif
        ]], [[
gnutls_session_t session;

if (gnutls_init(&session, GNUTLS_CLIENT) != GNUTLS_E_SUCCESS)
  return 1;

gnutls_deinit(session);
        ]])
      ],
      [ax_tls_gnutls=yes],
      [ax_tls_gnutls=no])

      LIBS=$ax_tls_save_LIBS
      AC_MSG_RESULT([$ax_tls_gnutls])

      AS_IF([test "x$ax_tls_gnutls" = xyes], [
        LIBS="-lgnutls $LIBS"
        ax_tls_backend=gnutls

        AC_DEFINE([HAVE_LIBGNUTLS], [1],
          [Define to 1 if GnuTLS is available.])
      ])
    ])
  ])

  dnl wolfSSL >= 4.3.0 with the extended/full OpenSSL compatibility layer.
  AS_IF([test "x$ax_tls_backend" = xnone], [
    AS_IF([test "x$with_tls" = xwolfssl || test "x$with_tls" = xauto], [
      AC_MSG_CHECKING([for usable wolfSSL 4.3.0 or newer with OpenSSL compatibility])

      ax_tls_wolfssl=no
      ax_tls_save_LIBS=$LIBS
      LIBS="-lwolfssl $LIBS"

      AC_LINK_IFELSE([
        AC_LANG_PROGRAM([[
#include <wolfssl/ssl.h>
#include <wolfssl/version.h>

#if LIBWOLFSSL_VERSION_HEX < 0x04003000
# error wolfSSL 4.3.0 or newer is required
#endif
        ]], [[
(void)wolfSSL_X509_digest(NULL, NULL, NULL, NULL);
        ]])
      ],
      [ax_tls_wolfssl=yes],
      [ax_tls_wolfssl=no])

      LIBS=$ax_tls_save_LIBS
      AC_MSG_RESULT([$ax_tls_wolfssl])

      AS_IF([test "x$ax_tls_wolfssl" = xyes], [
        LIBS="-lwolfssl $LIBS"
        ax_tls_backend=wolfssl

        AC_DEFINE([HAVE_LIBWOLFSSL], [1],
          [Define to 1 if wolfSSL is available.])
      ])
    ])
  ])

  AS_IF([test "x$with_tls" != xauto &&
         test "x$with_tls" != xnone &&
         test "x$ax_tls_backend" = xnone], [
    AC_MSG_ERROR([requested TLS library '$with_tls' is unavailable or does not meet the minimum version requirements])
  ])

  AC_MSG_NOTICE([TLS backend: $ax_tls_backend])
])
