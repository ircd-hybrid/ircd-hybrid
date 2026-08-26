/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2005-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file tls_wolfssl.c
 * \brief Includes all wolfSSL-specific TLS functions
 */

#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "conf.h"  /* XXX: decouple */
#include "io_hex.h"
#include "log.h"
#include "memory.h"
#include "tls.h"

#ifdef HAVE_TLS_WOLFSSL
static bool TLS_initialized;
static tls_context_t tls_ctx;

static void
_tls_context_free(tls_context_t context)
{
  if (context->server_ctx)
    wolfSSL_CTX_free(context->server_ctx);
  if (context->client_ctx)
    wolfSSL_CTX_free(context->client_ctx);

  io_free(context);
}

static void
_tls_context_ref(tls_context_t context)
{
  ++context->refs;
}

static void
_tls_context_unref(tls_context_t context)
{
  if (--context->refs == 0)
    _tls_context_free(context);
}

/*
 * report_crypto_errors - Dump crypto error list to log
 */
static void
report_crypto_errors(void)
{
  unsigned long e;

  while ((e = wolfSSL_ERR_get_error()))
    log_write(LOG_TYPE_IRCD, "SSL error: %s", wolfSSL_ERR_error_string(e, 0));
}

static int
always_accept_verify_cb(int preverify_ok, WOLFSSL_X509_STORE_CTX *x509_ctx)
{
  return 1;
}

bool
tls_is_initialized(void)
{
  return TLS_initialized;
}

/* tls_init()
 *
 * inputs       - nothing
 * output       - nothing
 * side effects - setups SSL context.
 */
void
tls_init(void)
{
  wolfSSL_Init();

  tls_context_t context = io_calloc(sizeof(*context));
  _tls_context_ref(context);

  context->server_ctx = wolfSSL_CTX_new(wolfTLS_server_method());
  if (context->server_ctx == NULL)
  {
    log_write(LOG_TYPE_IRCD,
              "ERROR: Could not initialize the TLS server context -- wolfSSL_CTX_new failed");

    _tls_context_unref(context);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  wolfSSL_CTX_SetMinVersion(tls_ctx->server_ctx, WOLFSSL_TLSV1_2);
  wolfSSL_CTX_set_session_cache_mode(tls_ctx->server_ctx, WOLFSSL_SESS_CACHE_OFF);
  wolfSSL_CTX_set_verify(tls_ctx->server_ctx, WOLFSSL_VERIFY_PEER|WOLFSSL_VERIFY_CLIENT_ONCE, always_accept_verify_cb);

  context->client_ctx = wolfSSL_CTX_new(wolfTLS_client_method());
  if (context->client_ctx == NULL)
  {
    log_write(LOG_TYPE_IRCD,
              "ERROR: Could not initialize the TLS client context -- wolfSSL_CTX_new failed");

    _tls_context_unref(context);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  wolfSSL_CTX_SetMinVersion(tls_ctx->client_ctx, WOLFSSL_TLSV1_2);
  wolfSSL_CTX_set_session_cache_mode(tls_ctx->client_ctx, WOLFSSL_SESS_CACHE_OFF);
  wolfSSL_CTX_set_verify(tls_ctx->client_ctx, WOLFSSL_VERIFY_PEER|WOLFSSL_VERIFY_CLIENT_ONCE, always_accept_verify_cb);

  tls_ctx = context;
}

bool
tls_new_credentials(void)
{
  TLS_initialized = false;

  if (ConfigServerInfo.tls_certificate_file == NULL || ConfigServerInfo.rsa_private_key_file == NULL)
    return true;

  if (wolfSSL_CTX_use_certificate_chain_file(tls_ctx->server_ctx, ConfigServerInfo.tls_certificate_file) != WOLFSSL_SUCCESS ||
      wolfSSL_CTX_use_certificate_chain_file(tls_ctx->client_ctx, ConfigServerInfo.tls_certificate_file) != WOLFSSL_SUCCESS)
  {
    report_crypto_errors();
    return false;
  }

  if (wolfSSL_CTX_use_PrivateKey_file(tls_ctx->server_ctx, ConfigServerInfo.rsa_private_key_file, WOLFSSL_FILETYPE_PEM) != WOLFSSL_SUCCESS ||
      wolfSSL_CTX_use_PrivateKey_file(tls_ctx->client_ctx, ConfigServerInfo.rsa_private_key_file, WOLFSSL_FILETYPE_PEM) != WOLFSSL_SUCCESS)
  {
    report_crypto_errors();
    return false;
  }

  if (wolfSSL_CTX_check_private_key(tls_ctx->server_ctx) != WOLFSSL_SUCCESS ||
      wolfSSL_CTX_check_private_key(tls_ctx->client_ctx) != WOLFSSL_SUCCESS)
  {
    report_crypto_errors();
    return false;
  }

  TLS_initialized = true;
  return true;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  static char buf[128];
  WOLFSSL *ssl = tls_data->session;

  snprintf(buf, sizeof(buf), "%s-%s", wolfSSL_get_version(ssl), wolfSSL_get_cipher(ssl));
  return buf;
}

tls_library_info_t
tls_get_library_info(void)
{
  return (tls_library_info_t)
  {
    .name = "wolfSSL",
    .runtime_version = wolfSSL_lib_version(),
    .compile_version = LIBWOLFSSL_VERSION_STRING
  };
}

bool
tls_isusing(tls_data_t *tls_data)
{
  return tls_data->session;
}

void
tls_free(tls_data_t *tls_data)
{
  if (tls_data->session == NULL)
    return;

  WOLFSSL *session = tls_data->session;
  tls_context_t context = tls_data->context;

  tls_data->session = NULL;
  tls_data->context = NULL;

  wolfSSL_free(session);
  _tls_context_unref(context);
}

ssize_t
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, bool *want_write)
{
  *want_write = false;

  WOLFSSL *ssl = tls_data->session;
  const int size = bufsize > INT_MAX ? INT_MAX : (int)bufsize;

  errno = 0;

  const int ret = wolfSSL_read(ssl, buf, size);
  if (ret > 0)
    return ret;

  if (ret == 0)
  {
    errno = 0;
    return 0;
  }

  const int saved_errno = errno;

  switch (wolfSSL_get_error(ssl, ret))
  {
    case WOLFSSL_ERROR_WANT_READ:
      errno = EWOULDBLOCK;
      return -1;
    case WOLFSSL_ERROR_WANT_WRITE:
      *want_write = true;
      errno = EWOULDBLOCK;
      return -1;
    case WOLFSSL_ERROR_ZERO_RETURN:
      errno = 0;
      return 0;
    case WOLFSSL_ERROR_SYSCALL:
      errno = saved_errno ? saved_errno : EIO;
      return -1;
    default:
      errno = EPROTO;
      return -1;
  }
}

ssize_t
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, bool *want_read)
{
  *want_read = false;

  WOLFSSL *ssl = tls_data->session;
  const int size = bufsize > INT_MAX ? INT_MAX : (int)bufsize;

  errno = 0;

  const int ret = wolfSSL_write(ssl, buf, size);
  if (ret > 0)
    return ret;

  if (ret == 0)
  {
    errno = 0;
    return 0;
  }

  const int saved_errno = errno;

  switch (wolfSSL_get_error(ssl, ret))
  {
    case WOLFSSL_ERROR_WANT_WRITE:
      errno = EWOULDBLOCK;
      return -1;
    case WOLFSSL_ERROR_WANT_READ:
      *want_read = true;
      errno = EWOULDBLOCK;
      return -1;
    case WOLFSSL_ERROR_ZERO_RETURN:
      errno = 0;
      return 0;
    case WOLFSSL_ERROR_SYSCALL:
      errno = saved_errno ? saved_errno : EIO;
      return -1;
    default:
      errno = EPROTO;
      return -1;
  }
}

void
tls_shutdown(tls_data_t *tls_data)
{
  WOLFSSL *ssl = tls_data->session;

  int ret = wolfSSL_shutdown(ssl);
  if (ret == WOLFSSL_SHUTDOWN_NOT_DONE)
    wolfSSL_shutdown(ssl);
}

bool
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  if (TLS_initialized == false)
    return false;

  tls_context_t context = tls_ctx;

  WOLFSSL_CTX *ctx;
  switch (role)
  {
    case TLS_ROLE_SERVER:
      ctx = context->server_ctx;
      break;

    case TLS_ROLE_CLIENT:
      ctx = context->client_ctx;
      break;

    default:
      return false;
  }

  _tls_context_ref(context);

  WOLFSSL *session = wolfSSL_new(ctx);
  if (session == NULL)
    goto fail;

  if (role == TLS_ROLE_SERVER)
    wolfSSL_set_accept_state(session);
  else
    wolfSSL_set_connect_state(session);

  if (wolfSSL_set_fd(session, fd) != WOLFSSL_SUCCESS)
    goto fail;

  tls_data->session = session;
  tls_data->context = context;
  return true;

fail:
  if (session)
    wolfSSL_free(session);

  _tls_context_unref(context);
  return false;
}

tls_handshake_status_t
tls_handshake(tls_data_t *tls_data, const char **errstr)
{
  if (errstr)
    *errstr = NULL;

  WOLFSSL *ssl = tls_data->session;
  const int ret = wolfSSL_negotiate(ssl);
  if (ret == WOLFSSL_SUCCESS)
    return TLS_HANDSHAKE_DONE;

  const int error = wolfSSL_get_error(ssl, ret);
  switch (error)
  {
    case WOLFSSL_ERROR_WANT_READ:
      return TLS_HANDSHAKE_WANT_READ;
    case WOLFSSL_ERROR_WANT_WRITE:
      return TLS_HANDSHAKE_WANT_WRITE;
    case WOLFSSL_ERROR_ZERO_RETURN:
      if (errstr)
        *errstr = "TLS connection closed during handshake";
      break;
    case WOLFSSL_ERROR_SYSCALL:
      if (errstr)
        *errstr = "System I/O error during TLS handshake";
      break;
    default:
      if (errstr)
      {
        const char *const reason = wolfSSL_ERR_reason_error_string((unsigned long)error);
        *errstr = reason ? reason : "TLS handshake failed";
      }

      break;
  }

  return TLS_HANDSHAKE_ERROR;
}

bool
tls_get_peer_certificate_fingerprint(tls_data_t *tls_data, char **fingerprint)
{
  WOLFSSL *ssl = tls_data->session;

  io_free(*fingerprint);
  *fingerprint = NULL;

  WOLFSSL_X509 *cert = wolfSSL_get_peer_certificate(ssl);
  if (cert == NULL)
    return false;

  int der_len;
  const unsigned char *const der = wolfSSL_X509_get_der(cert, &der_len);
  if (der == NULL || der_len <= 0)
  {
    wolfSSL_X509_free(cert);
    return false;
  }

  unsigned char digest[TLS_CERTFP_DIGEST_SIZE];
  if (wc_Sha256Hash(der, (word32)der_len, digest))
  {
    wolfSSL_X509_free(cert);
    return false;
  }

  char hex_digest[TLS_CERTFP_STRING_SIZE];
  if (!io_bytes_to_hex(digest, sizeof(digest), hex_digest, sizeof(hex_digest)))
  {
    wolfSSL_X509_free(cert);
    return false;
  }

  *fingerprint = io_strdup(hex_digest);

  wolfSSL_X509_free(cert);
  return true;
}
#endif  /* HAVE_TLS_WOLFSSL */
