/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015 Attila Molnar <attilamolnar@hush.com>
 *  Copyright (c) 2015 Adam <Adam@anope.org>
 *  Copyright (c) 2005-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file tls_wolfssl.c
 * \brief Includes all wolfSSL-specific TLS functions
 */

#include "stdinc.h"
#include "tls.h"
#include "conf.h"
#include "log.h"
#include "misc.h"
#include "memory.h"

#ifdef HAVE_TLS_WOLFSSL
static bool TLS_initialized;

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

  if ((ConfigServerInfo.tls_ctx.server_ctx = wolfSSL_CTX_new(wolfTLS_server_method())) == NULL)
  {
    log_write(LOG_TYPE_IRCD, "ERROR: Could not initialize the TLS server context -- wolfSSL_CTX_new failed");
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  wolfSSL_CTX_SetMinVersion(ConfigServerInfo.tls_ctx.server_ctx, WOLFSSL_TLSV1_2);
  wolfSSL_CTX_set_session_cache_mode(ConfigServerInfo.tls_ctx.server_ctx, SSL_SESS_CACHE_OFF);
  wolfSSL_CTX_set_verify(ConfigServerInfo.tls_ctx.server_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE, always_accept_verify_cb);
  wolfSSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");

  if ((ConfigServerInfo.tls_ctx.client_ctx = wolfSSL_CTX_new(wolfTLS_client_method())) == NULL)
  {
    log_write(LOG_TYPE_IRCD, "ERROR: Could not initialize the TLS client context -- wolfSSL_CTX_new failed");
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  wolfSSL_CTX_SetMinVersion(ConfigServerInfo.tls_ctx.client_ctx, WOLFSSL_TLSV1_2);
  wolfSSL_CTX_set_session_cache_mode(ConfigServerInfo.tls_ctx.client_ctx, SSL_SESS_CACHE_OFF);
  wolfSSL_CTX_set_verify(ConfigServerInfo.tls_ctx.client_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE, always_accept_verify_cb);
}

bool
tls_new_credentials(void)
{
  TLS_initialized = false;

  if (ConfigServerInfo.tls_certificate_file == NULL || ConfigServerInfo.rsa_private_key_file == NULL)
    return true;

  if (wolfSSL_CTX_use_certificate_chain_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_certificate_file) != SSL_SUCCESS ||
      wolfSSL_CTX_use_certificate_chain_file(ConfigServerInfo.tls_ctx.client_ctx, ConfigServerInfo.tls_certificate_file) != SSL_SUCCESS)
  {
    report_crypto_errors();
    return false;
  }

  if (wolfSSL_CTX_use_PrivateKey_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) != SSL_SUCCESS ||
      wolfSSL_CTX_use_PrivateKey_file(ConfigServerInfo.tls_ctx.client_ctx, ConfigServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) != SSL_SUCCESS)
  {
    report_crypto_errors();
    return false;
  }

  if (wolfSSL_CTX_check_private_key(ConfigServerInfo.tls_ctx.server_ctx) != SSL_SUCCESS ||
      wolfSSL_CTX_check_private_key(ConfigServerInfo.tls_ctx.client_ctx) != SSL_SUCCESS)
  {
    report_crypto_errors();
    return false;
  }

  if (ConfigServerInfo.tls_dh_param_file)
    if (wolfSSL_CTX_SetTmpDH_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_dh_param_file, SSL_FILETYPE_PEM) != SSL_SUCCESS)
       log_write(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_dh_param_file -- could not open/read Diffie-Hellman parameter file");

#ifdef SSL_CTX_set1_groups_list
  if (ConfigServerInfo.tls_supported_groups == NULL)
    wolfSSL_CTX_set1_groups_list(ConfigServerInfo.tls_ctx.server_ctx, "X25519:P-256");
  else if (wolfSSL_CTX_set1_groups_list(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_supported_groups) != SSL_SUCCESS)
  {
    wolfSSL_CTX_set1_groups_list(ConfigServerInfo.tls_ctx.server_ctx, "X25519:P-256");
    log_write(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_supported_groups -- could not set supported group(s)");
  }
#else
  if (ConfigServerInfo.tls_supported_groups == NULL)
    wolfSSL_CTX_set1_curves_list(ConfigServerInfo.tls_ctx.server_ctx, "X25519:P-256");
  else if (wolfSSL_CTX_set1_curves_list(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_supported_groups) != SSL_SUCCESS)
  {
    wolfSSL_CTX_set1_curves_list(ConfigServerInfo.tls_ctx.server_ctx, "X25519:P-256");
    log_write(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_supported_groups -- could not set supported group(s)");
  }
#endif

  if (ConfigServerInfo.tls_message_digest_algorithm == NULL)
    ConfigServerInfo.message_digest_algorithm = wolfSSL_EVP_sha256();
  else if ((ConfigServerInfo.message_digest_algorithm = wolfSSL_EVP_get_digestbyname(ConfigServerInfo.tls_message_digest_algorithm)) == NULL)
  {
    ConfigServerInfo.message_digest_algorithm = wolfSSL_EVP_sha256();
    log_write(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_message_digest_algorithm -- unknown message digest algorithm");
  }

  if (ConfigServerInfo.tls_cipher_list == NULL)
    wolfSSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");
  else if (wolfSSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_cipher_list) != SSL_SUCCESS)
  {
    wolfSSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");
    log_write(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_cipher_list -- could not set supported cipher(s)");
  }

  TLS_initialized = true;
  return true;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  static char buf[128];
  WOLFSSL *ssl = *tls_data;

  snprintf(buf, sizeof(buf), "%s-%s", wolfSSL_get_version(ssl), wolfSSL_get_cipher(ssl));
  return buf;
}

const char *
tls_get_version(void)
{
  static char buf[256];

  snprintf(buf, sizeof(buf), "wolfSSL version: library: %s, header: %s",
           wolfSSL_lib_version(), LIBWOLFSSL_VERSION_STRING);
  return buf;
}

bool
tls_isusing(tls_data_t *tls_data)
{
  WOLFSSL *ssl = *tls_data;
  return ssl != NULL;
}

void
tls_free(tls_data_t *tls_data)
{
  wolfSSL_free(*tls_data);
  *tls_data = NULL;
}

ssize_t
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, bool *want_write)
{
  WOLFSSL *ssl = *tls_data;
  ssize_t ret = wolfSSL_read(ssl, buf, bufsize);

  /* Translate wolfSSL error codes, sigh */
  if (ret < 0)
  {
    switch (wolfSSL_get_error(ssl, ret))
    {
      case SSL_ERROR_WANT_WRITE:
      {
        /* wolfSSL wants to write, we signal this to the caller and do nothing about that here */
        *want_write = true;
        break;
      }
      case SSL_ERROR_WANT_READ:
        errno = EWOULDBLOCK;
      case SSL_ERROR_SYSCALL:
        break;
      case SSL_ERROR_SSL:
        if (errno == EAGAIN)
          break;
      /* Fall through */
      default:
        ret = errno = 0;
    }
  }

  return ret;
}

ssize_t
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, bool *want_read)
{
  WOLFSSL *ssl = *tls_data;
  ssize_t ret = wolfSSL_write(ssl, buf, bufsize);

  /* Translate WolfSSL error codes, sigh */
  if (ret < 0)
  {
    switch (wolfSSL_get_error(ssl, ret))
    {
      case SSL_ERROR_WANT_READ:
        *want_read = true;
        break;  /* Retry later, don't register for write events */
      case SSL_ERROR_WANT_WRITE:
        errno = EWOULDBLOCK;
        break;
      case SSL_ERROR_SYSCALL:
        break;
      case SSL_ERROR_SSL:
        if (errno == EAGAIN)
          break;
      /* Fall through */
      default:
        ret = errno = 0;  /* Either an SSL-specific error or EOF */
    }
  }

  return ret;
}

void
tls_shutdown(tls_data_t *tls_data)
{
  WOLFSSL *ssl = *tls_data;
  int ret = wolfSSL_shutdown(ssl);

  if (ret == WOLFSSL_SHUTDOWN_NOT_DONE)
     wolfSSL_shutdown(ssl);
}

bool
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  WOLFSSL *ssl;

  if (TLS_initialized == false)
    return false;

  if (role == TLS_ROLE_SERVER)
    ssl = wolfSSL_new(ConfigServerInfo.tls_ctx.server_ctx);
  else
    ssl = wolfSSL_new(ConfigServerInfo.tls_ctx.client_ctx);

  if (ssl == NULL)
  {
    log_write(LOG_TYPE_IRCD, "wolfSSL_new() ERROR! -- %s",
         wolfSSL_ERR_error_string(wolfSSL_ERR_get_error(), NULL));
    return false;
  }

  *tls_data = ssl;
  wolfSSL_set_fd(ssl, fd);
  return true;
}

bool
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  wolfSSL_set_cipher_list(*tls_data, cipher_list);
  return true;
}

tls_handshake_status_t
tls_handshake(tls_data_t *tls_data, tls_role_t role, const char **errstr)
{
  WOLFSSL *ssl = *tls_data;
  int ret;

  if (role == TLS_ROLE_SERVER)
    ret = wolfSSL_accept(ssl);
  else
    ret = wolfSSL_connect(ssl);

  if (ret == WOLFSSL_SUCCESS)
    return TLS_HANDSHAKE_DONE;

  switch (wolfSSL_get_error(ssl, ret))
  {
    case WOLFSSL_ERROR_WANT_WRITE:
      return TLS_HANDSHAKE_WANT_WRITE;
    case WOLFSSL_ERROR_WANT_READ:
      return TLS_HANDSHAKE_WANT_READ;
    default:
    {
      const char *error = wolfSSL_ERR_error_string(wolfSSL_ERR_get_error(), NULL);

      if (errstr)
        *errstr = error;

      return TLS_HANDSHAKE_ERROR;
    }
  }
}

bool
tls_verify_certificate(tls_data_t *tls_data, tls_md_t digest, char **fingerprint)
{
  WOLFSSL *ssl = *tls_data;
  unsigned int n;
  char buf[EVP_MAX_MD_SIZE * 2 + 1];
  unsigned char md[EVP_MAX_MD_SIZE];
  bool ret = false;

  /* Accept NULL return from SSL_get_peer_certificate */
  WOLFSSL_X509 *cert = wolfSSL_get_peer_certificate(ssl);
  if (cert == NULL)
    return true;

  switch (wolfSSL_get_verify_result(ssl))
  {
    case X509_V_OK:
    case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
    case X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE:
    case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
      ret = true;

      if (wolfSSL_X509_digest(cert, digest, md, &n))
      {
        binary_to_hex(md, buf, n);
        *fingerprint = io_strdup(buf);
      }
    default:
      break;
  }

  wolfSSL_X509_free(cert);
  return ret;
}
#endif  /* HAVE_TLS_WOLFSSL */
