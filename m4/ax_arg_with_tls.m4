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

  dnl wolfSSL >= 5.6.0 with the extended/full OpenSSL compatibility layer.
  AS_IF([test "x$ax_tls_backend" = xnone], [
    AS_IF([test "x$with_tls" = xwolfssl || test "x$with_tls" = xauto], [
      AC_MSG_CHECKING([for usable wolfSSL 5.6.0 or newer with OpenSSL compatibility])

      ax_tls_wolfssl=no
      ax_tls_save_LIBS=$LIBS
      LIBS="-lwolfssl $LIBS"

      AC_LINK_IFELSE([
        AC_LANG_PROGRAM([[
#include <wolfssl/options.h>
#include <wolfssl/ssl.h>
#include <wolfssl/version.h>
#include <wolfssl/openssl/evp.h>

#if !defined(LIBWOLFSSL_VERSION_HEX)
# error Could not determine wolfSSL version
#elif LIBWOLFSSL_VERSION_HEX < 0x05006000
# error wolfSSL 5.6.0 or newer is required
#endif

#if !defined(OPENSSL_EXTRA)
# error wolfSSL must be built with OpenSSL compatibility enabled
#endif
        ]], [[
unsigned char byte = 0;
unsigned int digest_len = 0;

(void)wolfSSL_Init();

WOLFSSL_CTX *server_ctx = wolfSSL_CTX_new(wolfTLS_server_method());
WOLFSSL_CTX *client_ctx = wolfSSL_CTX_new(wolfTLS_client_method());

(void)wolfSSL_CTX_SetMinVersion(server_ctx, WOLFSSL_TLSV1_2);
(void)wolfSSL_CTX_set_session_cache_mode(server_ctx, WOLFSSL_SESS_CACHE_OFF);
wolfSSL_CTX_set_verify(server_ctx, WOLFSSL_VERIFY_PEER, NULL);

(void)wolfSSL_CTX_use_certificate_chain_file(server_ctx, "");
(void)wolfSSL_CTX_use_PrivateKey_file(server_ctx, "", WOLFSSL_FILETYPE_PEM);
(void)wolfSSL_CTX_check_private_key(server_ctx);
(void)wolfSSL_CTX_SetTmpDH_file(server_ctx, "", WOLFSSL_FILETYPE_PEM);
(void)wolfSSL_CTX_set_cipher_list(server_ctx, "");

WOLFSSL *ssl = wolfSSL_new(client_ctx);

wolfSSL_set_accept_state(ssl);
wolfSSL_set_connect_state(ssl);
wolfSSL_set_using_nonblock(ssl, 1);

(void)wolfSSL_set_fd(ssl, -1);
(void)wolfSSL_negotiate(ssl);
(void)wolfSSL_read(ssl, &byte, 1);
(void)wolfSSL_write(ssl, &byte, 1);
(void)wolfSSL_shutdown(ssl);
(void)wolfSSL_get_error(ssl, WOLFSSL_FATAL_ERROR);

(void)wolfSSL_EVP_get_digestbyname("SHA256");
(void)wolfSSL_X509_digest(NULL, wolfSSL_EVP_sha256(), NULL, &digest_len);

WOLFSSL_X509 *cert = wolfSSL_get_peer_certificate(ssl);
(void)wolfSSL_get_verify_result(ssl);
wolfSSL_X509_free(cert);

wolfSSL_free(ssl);
wolfSSL_CTX_free(client_ctx);
wolfSSL_CTX_free(server_ctx);
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
    AC_MSG_ERROR([requested TLS library '$with_tls' is unavailable, too old, or lacks required features])
  ])

  AC_MSG_NOTICE([TLS backend: $ax_tls_backend])
])
