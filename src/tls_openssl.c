/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015 Attila Molnar <attilamolnar@hush.com>
 *  Copyright (c) 2015 Adam <Adam@anope.org>
 *  Copyright (c) 2005-2016 ircd-hybrid development team
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

/*
 * report_crypto_errors - Dump crypto error list to log
 */
static void
report_crypto_errors(void)
{
  unsigned long e = 0;

  while ((e = ERR_get_error()))
    ilog(LOG_TYPE_IRCD, "SSL error: %s", ERR_error_string(e, 0));
}

static int
always_accept_verify_cb(int preverify_ok, X509_STORE_CTX *x509_ctx)
{
  return 1;
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
  SSL_load_error_strings();
  SSLeay_add_ssl_algorithms();

  if (!(ConfigServerInfo.tls_ctx.server_ctx = SSL_CTX_new(SSLv23_server_method())))
  {
    const char *s = ERR_lib_error_string(ERR_get_error());

    fprintf(stderr, "ERROR: Could not initialize the SSL Server context -- %s\n", s);
    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the SSL Server context -- %s", s);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.server_ctx, SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3|SSL_OP_NO_TICKET);
  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.server_ctx, SSL_OP_SINGLE_DH_USE|SSL_OP_CIPHER_SERVER_PREFERENCE);
  SSL_CTX_set_verify(ConfigServerInfo.tls_ctx.server_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE,
                     always_accept_verify_cb);
  SSL_CTX_set_session_cache_mode(ConfigServerInfo.tls_ctx.server_ctx, SSL_SESS_CACHE_OFF);
  SSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");

#ifndef OPENSSL_NO_ECDH
  {
    EC_KEY *key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);

    if (key)
    {
      SSL_CTX_set_tmp_ecdh(ConfigServerInfo.tls_ctx.server_ctx, key);
      EC_KEY_free(key);
    }
  }

  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.server_ctx, SSL_OP_SINGLE_ECDH_USE);
#endif

  if (!(ConfigServerInfo.tls_ctx.client_ctx = SSL_CTX_new(SSLv23_client_method())))
  {
    const char *s = ERR_lib_error_string(ERR_get_error());

    fprintf(stderr, "ERROR: Could not initialize the SSL Client context -- %s\n", s);
    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the SSL Client context -- %s", s);
    exit(EXIT_FAILURE);
    return;  /* Not reached */
  }

  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.client_ctx, SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3|SSL_OP_NO_TICKET);
  SSL_CTX_set_options(ConfigServerInfo.tls_ctx.client_ctx, SSL_OP_SINGLE_DH_USE);
  SSL_CTX_set_verify(ConfigServerInfo.tls_ctx.client_ctx, SSL_VERIFY_PEER|SSL_VERIFY_CLIENT_ONCE,
                     always_accept_verify_cb);
  SSL_CTX_set_session_cache_mode(ConfigServerInfo.tls_ctx.client_ctx, SSL_SESS_CACHE_OFF);
}

int
tls_new_cred(void)
{
  if (!ConfigServerInfo.ssl_certificate_file || !ConfigServerInfo.rsa_private_key_file)
    return 1;

  if (SSL_CTX_use_certificate_chain_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.ssl_certificate_file) <= 0 ||
      SSL_CTX_use_certificate_chain_file(ConfigServerInfo.tls_ctx.client_ctx, ConfigServerInfo.ssl_certificate_file) <= 0)
  {
    report_crypto_errors();
    return 0;
  }

  if (SSL_CTX_use_PrivateKey_file(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0 ||
      SSL_CTX_use_PrivateKey_file(ConfigServerInfo.tls_ctx.client_ctx, ConfigServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
  {
    report_crypto_errors();
    return 0;
  }

  if (!SSL_CTX_check_private_key(ConfigServerInfo.tls_ctx.server_ctx) ||
      !SSL_CTX_check_private_key(ConfigServerInfo.tls_ctx.client_ctx))
  {
    report_crypto_errors();
    return 0;
  }

  if (ConfigServerInfo.ssl_dh_param_file)
  {
    BIO *file = BIO_new_file(ConfigServerInfo.ssl_dh_param_file, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        if (DH_size(dh) >= 256)
          SSL_CTX_set_tmp_dh(ConfigServerInfo.tls_ctx.server_ctx, dh);
        else
          ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- need at least a 2048 bit DH prime size");

        DH_free(dh);
      }
    }
    else
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }

#ifndef OPENSSL_NO_ECDH
  if (ConfigServerInfo.ssl_dh_elliptic_curve)
  {
    int nid = 0;
    EC_KEY *key = NULL;

    if ((nid = OBJ_sn2nid(ConfigServerInfo.ssl_dh_elliptic_curve)) == 0)
      goto set_default_curve;

    if ((key = EC_KEY_new_by_curve_name(nid)) == NULL)
      goto set_default_curve;

    SSL_CTX_set_tmp_ecdh(ConfigServerInfo.tls_ctx.server_ctx, key);
    EC_KEY_free(key);
  }
  else
  {
    EC_KEY *key;

set_default_curve:

    key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);

    if (key)
    {
      SSL_CTX_set_tmp_ecdh(ConfigServerInfo.tls_ctx.server_ctx, key);
      EC_KEY_free(key);
    }
  }
#endif

  if (ConfigServerInfo.ssl_message_digest_algorithm == NULL)
    ConfigServerInfo.message_digest_algorithm = EVP_sha256();
  else
  {
    ConfigServerInfo.message_digest_algorithm = EVP_get_digestbyname(ConfigServerInfo.ssl_message_digest_algorithm);

    if (ConfigServerInfo.message_digest_algorithm == NULL)
    {
      ConfigServerInfo.message_digest_algorithm = EVP_sha256();
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }

  if (ConfigServerInfo.ssl_cipher_list)
    SSL_CTX_set_cipher_list(ConfigServerInfo.tls_ctx.server_ctx, ConfigServerInfo.ssl_cipher_list);

  return 1;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  static char buffer[IRCD_BUFSIZE];
  int bits = 0;
  SSL *ssl = *tls_data;

  SSL_CIPHER_get_bits(SSL_get_current_cipher(ssl), &bits);

  snprintf(buffer, sizeof(buffer), "%s-%s-%d", SSL_get_version(ssl),
           SSL_get_cipher(ssl), bits);
  return buffer;
}

int
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

int
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, int *want_write)
{
  SSL *ssl = *tls_data;
  int length = SSL_read(ssl, buf, bufsize);

  /* Translate openssl error codes, sigh */
  if (length < 0)
  {
    switch (SSL_get_error(ssl, length))
    {
      case SSL_ERROR_WANT_WRITE:
      {
        /* OpenSSL wants to write, we signal this to the caller and do nothing about that here */
        *want_write = 1;
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

int
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, int *want_read)
{
  SSL *ssl = *tls_data;
  int retlen = SSL_write(ssl, buf, bufsize);

  /* Translate openssl error codes, sigh */
  if (retlen < 0)
  {
    switch (SSL_get_error(ssl, retlen))
    {
      case SSL_ERROR_WANT_READ:
        *want_read = 1;
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

  if (!SSL_shutdown(ssl))
    SSL_shutdown(ssl);
}

int
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  SSL *ssl;

  if (role == TLS_ROLE_SERVER)
    ssl = SSL_new(ConfigServerInfo.tls_ctx.server_ctx);
  else
    ssl = SSL_new(ConfigServerInfo.tls_ctx.client_ctx);

  if (!ssl)
  {
    ilog(LOG_TYPE_IRCD, "SSL_new() ERROR! -- %s",
         ERR_error_string(ERR_get_error(), NULL));
    return 0;
  }

  *tls_data = ssl;
  SSL_set_fd(ssl, fd);
  return 1;
}

int
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  SSL_set_cipher_list(*tls_data, cipher_list);
  return 1;
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

int
tls_verify_cert(tls_data_t *tls_data, tls_md_t digest, char **fingerprint)
{
  SSL *ssl = *tls_data;
  X509 *cert = SSL_get_peer_certificate(ssl);
  unsigned int n;
  char buf[EVP_MAX_MD_SIZE * 2 + 1];
  unsigned char md[EVP_MAX_MD_SIZE];
  int ret = 0;

  /* Accept NULL return from SSL_get_peer_certificate */
  if (!cert)
    return 1;

  int res = SSL_get_verify_result(ssl);
  if (res == X509_V_OK || res == X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN ||
      res == X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE ||
      res == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT)
  {
    ret = 1;

    if (X509_digest(cert, digest, md, &n))
    {
      binary_to_hex(md, buf, n);
      *fingerprint = xstrdup(buf);
    }
  }

  X509_free(cert);
  return ret;
}
#endif  /* HAVE_TLS_OPENSSL */
