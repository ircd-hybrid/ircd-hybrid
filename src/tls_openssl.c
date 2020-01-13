/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015 Attila Molnar <attilamolnar@hush.com>
 *  Copyright (c) 2015 Adam <Adam@anope.org>
 *  Copyright (c) 2005-2020 ircd-hybrid development team
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

/*! \file tls_openssl.c
 * \brief Includes all OpenSSL-specific TLS functions
 * \version $Id$
 */

#include "stdinc.h"
#include "tls.h"
#include "conf.h"
#include "log.h"
#include "misc.h"
#include "memory.h"

#ifdef HAVE_TLS_OPENSSL
#if OPENSSL_VERSION_NUMBER < 0x1010100fL
#error "OpenSSL 1.1.1 and above is required to build this module"
#endif

static bool TLS_initialized;

/*
 * report_crypto_errors - Dump crypto error list to log
 */
static void
report_crypto_errors(void)
{
  unsigned long e;

  while ((e = ERR_get_error()))
    ilog(LOG_TYPE_IRCD, "SSL error: %s", ERR_error_string(e, 0));
}

static int
always_accept_verify_cb(int preverify_ok, X509_STORE_CTX *x509_ctx)
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
  if ((ConfigServerInfo.tls_ctx.server_ctx = SSL_CTX_new(TLS_server_method())) == NULL)
  {
    const char *s = ERR_lib_error_string(ERR_get_error());

    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the TLS server context -- %s", s);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  SSL_CTX_set_min_proto_version(ConfigServerInfo.tls_ctx.server_ctx, TLS1_2_VERSION);
  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.server_ctx, SSL_OP_CIPHER_SERVER_PREFERENCE|SSL_OP_NO_TICKET);
  SSL_CTX_set_verify(ConfigServerInfo.tls_ctx.server_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE, always_accept_verify_cb);
  SSL_CTX_set_session_cache_mode(ConfigServerInfo.tls_ctx.server_ctx, SSL_SESS_CACHE_OFF);
  SSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");

  if ((ConfigServerInfo.tls_ctx.client_ctx = SSL_CTX_new(TLS_client_method())) == NULL)
  {
    const char *s = ERR_lib_error_string(ERR_get_error());

    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the TLS client context -- %s", s);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  SSL_CTX_set_min_proto_version(ConfigServerInfo.tls_ctx.client_ctx, TLS1_2_VERSION);
  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.client_ctx, SSL_OP_NO_TICKET);
  SSL_CTX_set_verify(ConfigServerInfo.tls_ctx.client_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE, always_accept_verify_cb);
  SSL_CTX_set_session_cache_mode(ConfigServerInfo.tls_ctx.client_ctx, SSL_SESS_CACHE_OFF);
}

bool
tls_new_cred(void)
{
  TLS_initialized = false;

  if (!ConfigServerInfo.tls_certificate_file || !ConfigServerInfo.rsa_private_key_file)
    return true;

  if (SSL_CTX_use_certificate_chain_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_certificate_file) <= 0 ||
      SSL_CTX_use_certificate_chain_file(ConfigServerInfo.tls_ctx.client_ctx, ConfigServerInfo.tls_certificate_file) <= 0)
  {
    report_crypto_errors();
    return false;
  }

  if (SSL_CTX_use_PrivateKey_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0 ||
      SSL_CTX_use_PrivateKey_file(ConfigServerInfo.tls_ctx.client_ctx, ConfigServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
  {
    report_crypto_errors();
    return false;
  }

  if (!SSL_CTX_check_private_key(ConfigServerInfo.tls_ctx.server_ctx) ||
      !SSL_CTX_check_private_key(ConfigServerInfo.tls_ctx.client_ctx))
  {
    report_crypto_errors();
    return false;
  }

  if (ConfigServerInfo.tls_dh_param_file)
  {
    BIO *file = BIO_new_file(ConfigServerInfo.tls_dh_param_file, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        SSL_CTX_set_tmp_dh(ConfigServerInfo.tls_ctx.server_ctx, dh);
        DH_free(dh);
      }
    }
    else
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }

  if (ConfigServerInfo.tls_supported_groups == NULL)
    SSL_CTX_set1_groups_list(ConfigServerInfo.tls_ctx.server_ctx, "X25519:P-256");
  else if (SSL_CTX_set1_groups_list(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_supported_groups) == 0)
  {
    SSL_CTX_set1_groups_list(ConfigServerInfo.tls_ctx.server_ctx, "X25519:P-256");
    ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_supported_groups -- could not set supported group(s)");
  }

  if (ConfigServerInfo.tls_message_digest_algorithm == NULL)
    ConfigServerInfo.message_digest_algorithm = EVP_sha256();
  else if ((ConfigServerInfo.message_digest_algorithm = EVP_get_digestbyname(ConfigServerInfo.tls_message_digest_algorithm)) == NULL)
  {
    ConfigServerInfo.message_digest_algorithm = EVP_sha256();
    ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_message_digest_algorithm -- unknown message digest algorithm");
  }

  if (ConfigServerInfo.tls_cipher_list)
    if (SSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_cipher_list) == 0)
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_cipher_list -- could not set supported cipher(s)");

#ifndef LIBRESSL_VERSION_NUMBER
  if (ConfigServerInfo.tls_cipher_suites == NULL)
    SSL_CTX_set_ciphersuites(ConfigServerInfo.tls_ctx.server_ctx, "TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_GCM_SHA256");
  else if (SSL_CTX_set_ciphersuites(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.tls_cipher_suites) == 0)
  {
    SSL_CTX_set_ciphersuites(ConfigServerInfo.tls_ctx.server_ctx, "TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_GCM_SHA256");
    ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::tls_cipher_suites -- could not set supported cipher suite(s)");
  }
#endif

  TLS_initialized = true;
  return true;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  static char buffer[IRCD_BUFSIZE];
  SSL *ssl = *tls_data;

  snprintf(buffer, sizeof(buffer), "%s-%s", SSL_get_version(ssl), SSL_get_cipher(ssl));
  return buffer;
}

const char *
tls_get_version(void)
{
  static char buf[IRCD_BUFSIZE];

  snprintf(buf, sizeof(buf), "OpenSSL version: library: %s, header: %s",
           OpenSSL_version(OPENSSL_VERSION), OPENSSL_VERSION_TEXT);
  return buf;
}

bool
tls_isusing(tls_data_t *tls_data)
{
  SSL *ssl = *tls_data;
  return ssl != NULL;
}

void
tls_free(tls_data_t *tls_data)
{
  SSL_free(*tls_data);
  *tls_data = NULL;
}

ssize_t
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, bool *want_write)
{
  SSL *ssl = *tls_data;
  ssize_t length = SSL_read(ssl, buf, bufsize);

  /* Translate openssl error codes, sigh */
  if (length < 0)
  {
    switch (SSL_get_error(ssl, length))
    {
      case SSL_ERROR_WANT_WRITE:
      {
        /* OpenSSL wants to write, we signal this to the caller and do nothing about that here */
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
        length = errno = 0;
    }
  }

  return length;
}

ssize_t
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, bool *want_read)
{
  SSL *ssl = *tls_data;
  ssize_t retlen = SSL_write(ssl, buf, bufsize);

  /* Translate openssl error codes, sigh */
  if (retlen < 0)
  {
    switch (SSL_get_error(ssl, retlen))
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
        retlen = errno = 0;  /* Either an SSL-specific error or EOF */
    }
  }

  return retlen;
}

void
tls_shutdown(tls_data_t *tls_data)
{
  SSL *ssl = *tls_data;

  SSL_set_shutdown(ssl, SSL_RECEIVED_SHUTDOWN);

  if (SSL_shutdown(ssl) == 0)
    SSL_shutdown(ssl);
}

bool
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  SSL *ssl;

  if (TLS_initialized == false)
    return false;

  if (role == TLS_ROLE_SERVER)
    ssl = SSL_new(ConfigServerInfo.tls_ctx.server_ctx);
  else
    ssl = SSL_new(ConfigServerInfo.tls_ctx.client_ctx);

  if (ssl == NULL)
  {
    ilog(LOG_TYPE_IRCD, "SSL_new() ERROR! -- %s",
         ERR_error_string(ERR_get_error(), NULL));
    return false;
  }

  *tls_data = ssl;
  SSL_set_fd(ssl, fd);
  return true;
}

bool
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  SSL_set_cipher_list(*tls_data, cipher_list);
  return true;
}

tls_handshake_status_t
tls_handshake(tls_data_t *tls_data, tls_role_t role, const char **errstr)
{
  SSL *ssl = *tls_data;
  int ret;

  if (role == TLS_ROLE_SERVER)
    ret = SSL_accept(ssl);
  else
    ret = SSL_connect(ssl);

  if (ret > 0)
    return TLS_HANDSHAKE_DONE;

  switch (SSL_get_error(ssl, ret))
  {
    case SSL_ERROR_WANT_WRITE:
      return TLS_HANDSHAKE_WANT_WRITE;
    case SSL_ERROR_WANT_READ:
      return TLS_HANDSHAKE_WANT_READ;
    default:
    {
      const char *error = ERR_error_string(ERR_get_error(), NULL);

      if (errstr)
        *errstr = error;

      return TLS_HANDSHAKE_ERROR;
    }
  }
}

bool
tls_verify_cert(tls_data_t *tls_data, tls_md_t digest, char **fingerprint)
{
  SSL *ssl = *tls_data;
  unsigned int n;
  char buf[EVP_MAX_MD_SIZE * 2 + 1];
  unsigned char md[EVP_MAX_MD_SIZE];
  bool ret = false;

  /* Accept NULL return from SSL_get_peer_certificate */
  X509 *cert = SSL_get_peer_certificate(ssl);
  if (cert == NULL)
    return true;

  switch (SSL_get_verify_result(ssl))
  {
    case X509_V_OK:
    case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
    case X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE:
    case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
      ret = true;

      if (X509_digest(cert, digest, md, &n))
      {
        binary_to_hex(md, buf, n);
        *fingerprint = xstrdup(buf);
      }
    default:
      break;
  }

  X509_free(cert);
  return ret;
}
#endif  /* HAVE_TLS_OPENSSL */
