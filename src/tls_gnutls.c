/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2016 ircd-hybrid development team
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

/*! \file tls_gnutls.c
 * \brief Includes all GnuTLS-specific TLS functions
 * \version $Id$
 */

#include "stdinc.h"
#include "tls.h"
#include "conf.h"
#include "log.h"
#include "rsa.h"
#include "memory.h"

#ifdef HAVE_TLS_GNUTLS

void
tls_init(void)
{
}

static void
tls_free_cred(tls_context_t cred)
{
  gnutls_priority_deinit(cred->priorities);
  gnutls_dh_params_deinit(cred->dh_params);
  gnutls_certificate_free_credentials(cred->x509_cred);

  gnutls_global_deinit();

  xfree(cred);
}

int
tls_new_cred(void)
{
  int ret;
  struct gnutls_context *context;

  if (!ConfigServerInfo.ssl_certificate_file || !ConfigServerInfo.rsa_private_key_file)
    return 0;

  context = xcalloc(sizeof(*context));

  gnutls_global_init();

  ret = gnutls_certificate_allocate_credentials(&context->x509_cred);
  if (ret != GNUTLS_E_SUCCESS)
  {
    ilog(LOG_TYPE_IRCD, "ERROR: Could not initialize the TLS credentials -- %s", gnutls_strerror(ret));
    xfree(context);
    return 0;
  }

  gnutls_priority_init(&context->priorities, "NORMAL", NULL);

  ret = gnutls_certificate_set_x509_key_file(context->x509_cred, ConfigServerInfo.ssl_certificate_file, ConfigServerInfo.rsa_private_key_file, GNUTLS_X509_FMT_PEM);
  if (ret != GNUTLS_E_SUCCESS)
  {
    ilog(LOG_TYPE_IRCD, "Could not set TLS keys -- %s", gnutls_strerror(ret));

    gnutls_certificate_free_credentials(context->x509_cred);
    gnutls_priority_deinit(context->priorities);
    xfree(context);
    return 0;
  }

  gnutls_dh_params_init(&context->dh_params);

  if (ConfigServerInfo.ssl_dh_param_file)
  {
    gnutls_datum_t data;

    ret = gnutls_load_file(ConfigServerInfo.ssl_dh_param_file, &data);

    if (ret != GNUTLS_E_SUCCESS)
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- unable to load file -- %s", gnutls_strerror(ret));
    else
    {
      ret = gnutls_dh_params_import_pkcs3(context->dh_params, &data, GNUTLS_X509_FMT_PEM);

      if (ret != GNUTLS_E_SUCCESS)
        ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- unable to import dh params -- %s", gnutls_strerror(ret));

      gnutls_free(data.data);
    }
  }

  gnutls_certificate_set_dh_params(context->x509_cred, context->dh_params);

  if (ConfigServerInfo.ssl_message_digest_algorithm == NULL)
    ConfigServerInfo.message_digest_algorithm = GNUTLS_DIG_SHA256;
  else
  {
    ConfigServerInfo.message_digest_algorithm = gnutls_digest_get_id(ConfigServerInfo.ssl_message_digest_algorithm);

    if (ConfigServerInfo.message_digest_algorithm == GNUTLS_DIG_UNKNOWN)
    {
      ConfigServerInfo.message_digest_algorithm = GNUTLS_DIG_SHA256;
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }

  if (ConfigServerInfo.tls_ctx && --ConfigServerInfo.tls_ctx->refs == 0)
    tls_free_cred(ConfigServerInfo.tls_ctx);

  ConfigServerInfo.tls_ctx = context;
  ++context->refs;

  return 1;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  static char buffer[IRCD_BUFSIZE];

  snprintf(buffer, sizeof(buffer), "%s-%s-%s-%s",
           gnutls_protocol_get_name(gnutls_protocol_get_version(tls_data->session)),
           gnutls_kx_get_name(gnutls_kx_get(tls_data->session)),
           gnutls_cipher_get_name(gnutls_cipher_get(tls_data->session)),
           gnutls_mac_get_name(gnutls_mac_get(tls_data->session)));

  return buffer;
}

int
tls_isusing(tls_data_t *tls_data)
{
  return tls_data->session != NULL;
}

void
tls_free(tls_data_t *tls_data)
{
  gnutls_deinit(tls_data->session);
}

int
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, int *want_write)
{
  int length = gnutls_record_recv(tls_data->session, buf, bufsize);

  if (length <= 0)
  {
    switch (length)
    {
      case GNUTLS_E_AGAIN:
      case GNUTLS_E_INTERRUPTED:
        errno = EWOULDBLOCK;
      case 0:  /* Closed */
      default:  /* Other error */
        return -1;
    }
  }

  return length;
}

int
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, int *want_read)
{
  int length = gnutls_record_send(tls_data->session, buf, bufsize);

  if (length <= 0)
  {
    switch (length)
    {
      case GNUTLS_E_AGAIN:
      case GNUTLS_E_INTERRUPTED:
      case 0:
        errno = EWOULDBLOCK;
      default:
        return -1;
    }
  }

  return length;
}

void
tls_shutdown(tls_data_t *tls_data)
{
  gnutls_bye(tls_data->session, GNUTLS_SHUT_WR);

  if (--tls_data->context->refs == 0)
    tls_free_cred(tls_data->context);
}

int
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  gnutls_init(&tls_data->session, role == TLS_ROLE_SERVER ? GNUTLS_SERVER : GNUTLS_CLIENT);

  tls_data->context = ConfigServerInfo.tls_ctx;
  ++tls_data->context->refs;

  gnutls_priority_set(tls_data->session, tls_data->context->priorities);
  gnutls_credentials_set(tls_data->session, GNUTLS_CRD_CERTIFICATE, tls_data->context->x509_cred);
  gnutls_dh_set_prime_bits(tls_data->session, 1024);
  gnutls_transport_set_int(tls_data->session, fd);

  if (role == TLS_ROLE_SERVER)
    /* Request client certificate if any. */
    gnutls_certificate_server_set_request(tls_data->session, GNUTLS_CERT_REQUEST);

  return 1;
}

int
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  int ret;
  const char *prioerror;

  gnutls_priority_deinit(tls_data->context->priorities);

  ret = gnutls_priority_init(&tls_data->context->priorities, cipher_list, &prioerror);
  if (ret != GNUTLS_E_SUCCESS)
  {
    /* GnuTLS did not understand the user supplied string, log and fall back to the default priorities */
    ilog(LOG_TYPE_IRCD, "Failed to set GnuTLS priorities to \"%s\": %s Syntax error at position %u, falling back to default (NORMAL)",
         cipher_list, gnutls_strerror(ret), (unsigned int)(prioerror - cipher_list));
    gnutls_priority_init(&tls_data->context->priorities, "NORMAL", NULL);
    return 0;
  }

  return 1;
}

tls_handshake_status_t
tls_handshake(tls_data_t *tls_data, tls_role_t role, const char **errstr)
{
  int ret = gnutls_handshake(tls_data->session);

  if (ret >= 0)
    return TLS_HANDSHAKE_DONE;

  if (ret == GNUTLS_E_AGAIN || ret == GNUTLS_E_INTERRUPTED)
  {
    /* Handshake needs resuming later, read() or write() would have blocked. */

    if (gnutls_record_get_direction(tls_data->session) == 0)
    {
      /* gnutls_handshake() wants to read() again. */
      return TLS_HANDSHAKE_WANT_READ;
    }
    else
    {
      /* gnutls_handshake() wants to write() again. */
      return TLS_HANDSHAKE_WANT_WRITE;
    }
  }
  else
  {
    const char *error = gnutls_strerror(ret);

    if (errstr)
      *errstr = error;

    return TLS_HANDSHAKE_ERROR;
  }
}

int
tls_verify_cert(tls_data_t *tls_data, tls_md_t digest, char **fingerprint, int *raw_result)
{
  int ret;
  gnutls_x509_crt_t cert;
  const gnutls_datum_t *cert_list;
  unsigned int cert_list_size = 0;
  unsigned char digestbuf[TLS_GNUTLS_MAX_HASH_SIZE];
  size_t digest_size = sizeof(digestbuf);
  char buf[TLS_GNUTLS_MAX_HASH_SIZE * 2 + 1];

  cert_list = gnutls_certificate_get_peers(tls_data->session, &cert_list_size);
  if (!cert_list)
    return 1;  /* No certificate */

  ret = gnutls_x509_crt_init(&cert);
  if (ret != GNUTLS_E_SUCCESS)
    return 1;

  ret = gnutls_x509_crt_import(cert, &cert_list[0], GNUTLS_X509_FMT_DER);
  if (ret != GNUTLS_E_SUCCESS)
    goto info_done_dealloc;

  ret = gnutls_x509_crt_get_fingerprint(cert, digest, digestbuf, &digest_size);
  if (ret != GNUTLS_E_SUCCESS)
    goto info_done_dealloc;

  binary_to_hex(digestbuf, buf, digest_size);
  *fingerprint = xstrdup(buf);

  return 1;

info_done_dealloc:
  gnutls_x509_crt_deinit(cert);
  *raw_result = 0;
  return 0;
}
#endif  /* HAVE_TLS_GNUTLS */
