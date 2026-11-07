/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2005-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file tls_openssl.c
 * \brief Includes all OpenSSL-specific TLS functions
 */

#include <errno.h>
#include <stdio.h>

#include "io_hex.h"
#include "log.h"
#include "memory.h"
#include "tls.h"

#ifdef HAVE_TLS_OPENSSL
static tls_context_t tls_ctx;

static void
_tls_context_free(tls_context_t context)
{
  if (context->server_ctx)
    SSL_CTX_free(context->server_ctx);
  if (context->client_ctx)
    SSL_CTX_free(context->client_ctx);

  io_free(context);
}

static void
_tls_context_ref(tls_context_t context)
{
  ++context->ref_count;
}

static void
_tls_context_unref(tls_context_t context)
{
  if (--context->ref_count == 0)
    _tls_context_free(context);
}

/*
 * report_crypto_errors - Dump crypto error list to log
 */
static void
report_crypto_errors(void)
{
  unsigned long e;

  while ((e = ERR_get_error()))
    log_write(LOG_TYPE_IRCD, "SSL error: %s", ERR_error_string(e, 0));
}

static int
_tls_verify_accept_all_cb(int preverify_ok, X509_STORE_CTX *x509_ctx)
{
  return 1;
}

bool
tls_is_configured(void)
{
  return tls_ctx != NULL;
}

void
tls_clear_config(void)
{
  tls_context_t context = tls_ctx;

  tls_ctx = NULL;

  if (context)
    _tls_context_unref(context);
}

static tls_context_t
_tls_context_new(void)
{
  tls_context_t context = io_calloc(sizeof(*context));
  _tls_context_ref(context);

  ERR_clear_error();

  context->server_ctx = SSL_CTX_new(TLS_server_method());
  if (context->server_ctx == NULL)
    goto fail;

  if (SSL_CTX_set_min_proto_version(context->server_ctx, TLS1_2_VERSION) != 1)
    goto fail;

  SSL_CTX_set_options(context->server_ctx, SSL_OP_CIPHER_SERVER_PREFERENCE | SSL_OP_NO_TICKET);
  SSL_CTX_set_verify(context->server_ctx, SSL_VERIFY_PEER | SSL_VERIFY_CLIENT_ONCE, _tls_verify_accept_all_cb);
  SSL_CTX_set_session_cache_mode(context->server_ctx, SSL_SESS_CACHE_OFF);

  context->client_ctx = SSL_CTX_new(TLS_client_method());
  if (context->client_ctx == NULL)
    goto fail;

  if (SSL_CTX_set_min_proto_version(context->client_ctx, TLS1_2_VERSION) != 1)
    goto fail;

  SSL_CTX_set_options(context->client_ctx, SSL_OP_NO_TICKET);
  SSL_CTX_set_verify(context->client_ctx, SSL_VERIFY_PEER | SSL_VERIFY_CLIENT_ONCE, _tls_verify_accept_all_cb);
  SSL_CTX_set_session_cache_mode(context->client_ctx, SSL_SESS_CACHE_OFF);

  return context;

fail:
  report_crypto_errors();
  _tls_context_unref(context);
  return NULL;
}

static bool
_tls_context_load_credentials(tls_context_t context, const tls_config_t *config)
{
  ERR_clear_error();

  if (SSL_CTX_use_certificate_chain_file(context->server_ctx, config->certificate_file) != 1 ||
      SSL_CTX_use_certificate_chain_file(context->client_ctx, config->certificate_file) != 1)
  {
    report_crypto_errors();
    return false;
  }

  if (SSL_CTX_use_PrivateKey_file(context->server_ctx, config->private_key_file, SSL_FILETYPE_PEM) != 1 ||
      SSL_CTX_use_PrivateKey_file(context->client_ctx, config->private_key_file, SSL_FILETYPE_PEM) != 1)
  {
    report_crypto_errors();
    return false;
  }

  if (SSL_CTX_check_private_key(context->server_ctx) != 1 ||
      SSL_CTX_check_private_key(context->client_ctx) != 1)
  {
    report_crypto_errors();
    return false;
  }

  return true;
}

bool
tls_configure(const tls_config_t *config)
{
  if (config == NULL || config->certificate_file == NULL || config->private_key_file == NULL)
    return false;

  tls_context_t context = _tls_context_new();
  if (context == NULL)
    return false;

  if (!_tls_context_load_credentials(context, config))
  {
    _tls_context_unref(context);
    return false;
  }

  tls_context_t old_context = tls_ctx;
  tls_ctx = context;

  if (old_context)
    _tls_context_unref(old_context);

  return true;
}

void
tls_library_init(void)
{
}

const char *
tls_session_get_cipher(const tls_data_t *tls_data)
{
  static char buf[128];
  SSL *ssl = tls_data->session;

  snprintf(buf, sizeof(buf), "%s-%s", SSL_get_version(ssl), SSL_get_cipher(ssl));
  return buf;
}

tls_library_info_t
tls_library_get_info(void)
{
  return (tls_library_info_t)
  {
    .name = "OpenSSL",
    .runtime_version = OpenSSL_version(OPENSSL_VERSION),
    .compile_version = OPENSSL_VERSION_TEXT
  };
}

bool
tls_session_is_active(const tls_data_t *tls_data)
{
  return tls_data->session != NULL;
}

void
tls_session_deinit(tls_data_t *tls_data)
{
  if (tls_data->session == NULL)
    return;

  SSL *session = tls_data->session;
  tls_context_t context = tls_data->context;

  tls_data->session = NULL;
  tls_data->context = NULL;

  SSL_free(session);
  _tls_context_unref(context);
}

ssize_t
tls_session_read(tls_data_t *tls_data, char *buf, size_t bufsize, bool *want_write)
{
  *want_write = false;

  ERR_clear_error();
  errno = 0;

  SSL *ssl = tls_data->session;
  size_t nread = 0;
  const int ret = SSL_read_ex(ssl, buf, bufsize, &nread);
  if (ret == 1)
    return (ssize_t)nread;

  const int saved_errno = errno;

  switch (SSL_get_error(ssl, ret))
  {
    case SSL_ERROR_WANT_READ:
      errno = EWOULDBLOCK;
      return -1;
    case SSL_ERROR_WANT_WRITE:
      *want_write = true;
      errno = EWOULDBLOCK;
      return -1;
    case SSL_ERROR_ZERO_RETURN:
      errno = 0;
      return 0;
    case SSL_ERROR_SYSCALL:
      errno = saved_errno ? saved_errno : EIO;
      return -1;
    case SSL_ERROR_SSL:
    default:
      errno = EPROTO;
      return -1;
  }
}

ssize_t
tls_session_write(tls_data_t *tls_data, const char *buf, size_t bufsize, bool *want_read)
{
  *want_read = false;

  ERR_clear_error();
  errno = 0;

  SSL *ssl = tls_data->session;
  size_t nwritten = 0;
  const int ret = SSL_write_ex(ssl, buf, bufsize, &nwritten);
  if (ret == 1)
    return (ssize_t)nwritten;

  const int saved_errno = errno;

  switch (SSL_get_error(ssl, ret))
  {
    case SSL_ERROR_WANT_WRITE:
      errno = EWOULDBLOCK;
      return -1;
    case SSL_ERROR_WANT_READ:
      *want_read = true;
      errno = EWOULDBLOCK;
      return -1;
    case SSL_ERROR_ZERO_RETURN:
      errno = 0;
      return 0;
    case SSL_ERROR_SYSCALL:
      errno = saved_errno ? saved_errno : EIO;
      return -1;
    case SSL_ERROR_SSL:
    default:
      errno = EPROTO;
      return -1;
  }
}

void
tls_session_close_notify(tls_data_t *tls_data)
{
  SSL *ssl = tls_data->session;
  SSL_set_shutdown(ssl, SSL_RECEIVED_SHUTDOWN);

  if (SSL_shutdown(ssl) == 0)
    SSL_shutdown(ssl);
}

bool
tls_session_init(tls_data_t *tls_data, int fd, tls_role_t role)
{
  if (tls_ctx == NULL)
    return false;

  tls_context_t context = tls_ctx;

  SSL_CTX *ctx;
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

  SSL *session = SSL_new(ctx);
  if (session == NULL)
    goto fail;

  if (role == TLS_ROLE_SERVER)
    SSL_set_accept_state(session);
  else
    SSL_set_connect_state(session);

  if (SSL_set_fd(session, fd) != 1)
    goto fail;

  tls_data->session = session;
  tls_data->context = context;
  return true;

fail:
  if (session)
    SSL_free(session);

  _tls_context_unref(context);
  return false;
}

tls_handshake_status_t
tls_session_handshake(tls_data_t *tls_data, const char **errstr)
{
  if (errstr)
    *errstr = NULL;

  ERR_clear_error();

  SSL *ssl = tls_data->session;
  const int ret = SSL_do_handshake(ssl);
  if (ret == 1)
    return TLS_HANDSHAKE_DONE;

  switch (SSL_get_error(ssl, ret))
  {
    case SSL_ERROR_WANT_READ:
      return TLS_HANDSHAKE_WANT_READ;
    case SSL_ERROR_WANT_WRITE:
      return TLS_HANDSHAKE_WANT_WRITE;
    case SSL_ERROR_ZERO_RETURN:
      if (errstr)
        *errstr = "TLS connection closed during handshake";
      break;
    case SSL_ERROR_SYSCALL:
      if (errstr)
        *errstr = "System I/O error during TLS handshake";
      break;
    case SSL_ERROR_SSL:
      if (errstr)
      {
        const unsigned long code = ERR_peek_last_error();
        const char *const reason = code ? ERR_reason_error_string(code) : NULL;

        *errstr = reason ? reason : "TLS protocol error during handshake";
      }
      break;
    default:
      if (errstr)
        *errstr = "TLS handshake failed";
      break;
  }

  return TLS_HANDSHAKE_ERROR;
}

bool
tls_session_get_peer_certificate_fingerprint(tls_data_t *tls_data, char **fingerprint)
{
  SSL *ssl = tls_data->session;

  io_free(*fingerprint);
  *fingerprint = NULL;

  const X509 *cert = SSL_get0_peer_certificate(ssl);
  if (cert == NULL)
    return false;

  unsigned char digest[TLS_CERTFP_DIGEST_SIZE];
  unsigned int digest_len;
  if (X509_digest(cert, EVP_sha256(), digest, &digest_len) != 1)
  {
    ERR_clear_error();
    return false;
  }

  char hex_digest[TLS_CERTFP_STRING_SIZE];
  if (!io_bytes_to_hex(digest, digest_len, hex_digest, sizeof(hex_digest)))
    return false;

  *fingerprint = io_strdup(hex_digest);
  return true;
}
#endif  /* HAVE_TLS_OPENSSL */
