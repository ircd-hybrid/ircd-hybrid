/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file tls_gnutls.c
 * \brief Includes all GnuTLS-specific TLS functions
 */

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "conf.h"  /* XXX: decouple */
#include "io_hex.h"
#include "log.h"
#include "memory.h"
#include "tls.h"

#ifdef HAVE_TLS_GNUTLS
static bool TLS_initialized;
static const char tls_default_priority_string[] =
  "NORMAL:"
  "%SERVER_PRECEDENCE:"
  "!VERS-TLS1.1:"
  "!VERS-TLS1.0:"
  "!VERS-SSL3.0";

static tls_context_t tls_ctx;

bool
tls_is_initialized(void)
{
  return TLS_initialized;
}

void
tls_init(void)
{
}

static void
_tls_context_free(tls_context_t context)
{
  gnutls_priority_deinit(context->priorities);
  gnutls_certificate_free_credentials(context->x509_cred);

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

bool
tls_new_credentials(void)
{
  TLS_initialized = false;

  if (ConfigServerInfo.tls_certificate_file == NULL || ConfigServerInfo.rsa_private_key_file == NULL)
    return true;

  struct gnutls_context *const context = io_calloc(sizeof(*context));

  int ret = gnutls_certificate_allocate_credentials(&context->x509_cred);
  if (ret != GNUTLS_E_SUCCESS)
  {
    log_write(LOG_TYPE_IRCD, "ERROR: Could not initialize the TLS credentials -- %s", gnutls_strerror(ret));
    io_free(context);
    return false;
  }

  gnutls_priority_init(&context->priorities, tls_default_priority_string, NULL);

  ret = gnutls_certificate_set_x509_key_file(context->x509_cred, ConfigServerInfo.tls_certificate_file, ConfigServerInfo.rsa_private_key_file, GNUTLS_X509_FMT_PEM);
  if (ret != GNUTLS_E_SUCCESS)
  {
    log_write(LOG_TYPE_IRCD, "Could not set TLS keys -- %s", gnutls_strerror(ret));

    gnutls_certificate_free_credentials(context->x509_cred);
    gnutls_priority_deinit(context->priorities);
    io_free(context);
    return false;
  }

  _tls_context_ref(context);

  tls_context_t old_context = tls_ctx;
  tls_ctx = context;

  if (old_context)
    _tls_context_unref(old_context);

  TLS_initialized = true;
  return true;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  static char buf[128];

  snprintf(buf, sizeof(buf), "%s-%s-%s-%s",
           gnutls_protocol_get_name(gnutls_protocol_get_version(tls_data->session)),
           gnutls_kx_get_name(gnutls_kx_get(tls_data->session)),
           gnutls_cipher_get_name(gnutls_cipher_get(tls_data->session)),
           gnutls_mac_get_name(gnutls_mac_get(tls_data->session)));
  return buf;
}

const char *
tls_get_version(void)
{
  static char buf[256];

  snprintf(buf, sizeof(buf), "GnuTLS version: library: %s, header: %s",
           gnutls_check_version(NULL), GNUTLS_VERSION);
  return buf;
}

bool
tls_isusing(tls_data_t *tls_data)
{
  return tls_data->session != NULL;
}

void
tls_free(tls_data_t *tls_data)
{
  if (tls_data->session == NULL)
    return;

  gnutls_session_t session = tls_data->session;
  tls_context_t context = tls_data->context;

  tls_data->session = NULL;
  tls_data->context = NULL;

  gnutls_deinit(session);
  _tls_context_unref(context);
}

ssize_t
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, bool *want_write)
{
  *want_write = false;

  errno = 0;

  gnutls_session_t session = tls_data->session;
  const ssize_t ret = gnutls_record_recv(session, buf, bufsize);
  if (ret > 0)
    return ret;

  if (ret == 0)
  {
    errno = 0;
    return 0;
  }

  const int saved_errno = errno;

  switch (ret)
  {
    case GNUTLS_E_AGAIN:
    case GNUTLS_E_INTERRUPTED:
      *want_write = gnutls_record_get_direction(session) != 0;
      errno = EWOULDBLOCK;
      return -1;
    case GNUTLS_E_PULL_ERROR:
    case GNUTLS_E_PUSH_ERROR:
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

  errno = 0;

  gnutls_session_t session = tls_data->session;
  const ssize_t ret = gnutls_record_send(session, buf, bufsize);
  if (ret >= 0)
    return ret;

  const int saved_errno = errno;

  switch (ret)
  {
    case GNUTLS_E_AGAIN:
    case GNUTLS_E_INTERRUPTED:
      *want_read = gnutls_record_get_direction(session) == 0;
      errno = EWOULDBLOCK;
      return -1;
    case GNUTLS_E_PULL_ERROR:
    case GNUTLS_E_PUSH_ERROR:
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
  gnutls_bye(tls_data->session, GNUTLS_SHUT_WR);
}

bool
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  if (TLS_initialized == false || tls_ctx == NULL)
    return false;

  unsigned int flags;

  switch (role)
  {
    case TLS_ROLE_SERVER:
      flags = GNUTLS_SERVER | GNUTLS_NONBLOCK;
      break;
    case TLS_ROLE_CLIENT:
      flags = GNUTLS_CLIENT | GNUTLS_NONBLOCK;
      break;
    default:
      return false;
  }

  gnutls_session_t session = NULL;
  int ret = gnutls_init(&session, flags);
  if (ret != GNUTLS_E_SUCCESS)
    return false;

  tls_context_t context = tls_ctx;
  _tls_context_ref(context);

  ret = gnutls_priority_set(session, context->priorities);
  if (ret != GNUTLS_E_SUCCESS)
    goto fail;

  ret = gnutls_credentials_set(session, GNUTLS_CRD_CERTIFICATE, context->x509_cred);
  if (ret != GNUTLS_E_SUCCESS)
    goto fail;

  gnutls_transport_set_int(session, fd);

  if (role == TLS_ROLE_SERVER)
    /* Request client certificate if any. */
    gnutls_certificate_server_set_request(session, GNUTLS_CERT_REQUEST);

  tls_data->session = session;
  tls_data->context = context;
  return true;

fail:
  gnutls_deinit(session);
  _tls_context_unref(context);
  return false;
}

tls_handshake_status_t
tls_handshake(tls_data_t *tls_data, tls_role_t role, const char **errstr)
{
  if (errstr)
    *errstr = NULL;

  gnutls_session_t session = tls_data->session;
  const int ret = gnutls_handshake(session);
  if (ret == GNUTLS_E_SUCCESS)
    return TLS_HANDSHAKE_DONE;

  if (ret == GNUTLS_E_AGAIN || ret == GNUTLS_E_INTERRUPTED)
  {
    if (gnutls_record_get_direction(session) == 0)
      return TLS_HANDSHAKE_WANT_READ;

    return TLS_HANDSHAKE_WANT_WRITE;
  }

  if (errstr)
  {
    if (ret == GNUTLS_E_WARNING_ALERT_RECEIVED || ret == GNUTLS_E_FATAL_ALERT_RECEIVED)
    {
      const gnutls_alert_description_t alert = gnutls_alert_get(session);
      const char *const reason = gnutls_alert_get_name(alert);

      *errstr = reason ? reason : gnutls_strerror(ret);
    }
    else
      *errstr = gnutls_strerror(ret);
  }

  return TLS_HANDSHAKE_ERROR;
}

bool
tls_get_peer_certificate_fingerprint(tls_data_t *tls_data, char **fingerprint)
{
  io_free(*fingerprint);
  *fingerprint = NULL;

  gnutls_session_t session = tls_data->session;
  if (gnutls_certificate_type_get2(session, GNUTLS_CTYPE_PEERS) != GNUTLS_CRT_X509)
    return false;

  unsigned int cert_list_size = 0;
  const gnutls_datum_t *cert_list = gnutls_certificate_get_peers(session, &cert_list_size);
  if (cert_list == NULL || cert_list_size == 0)
    return false;

  unsigned char digest[TLS_CERTFP_DIGEST_SIZE];
  size_t digest_len = sizeof(digest);
  if (gnutls_fingerprint(GNUTLS_DIG_SHA256, &cert_list[0], digest, &digest_len) != GNUTLS_E_SUCCESS)
    return false;

  char hex_digest[TLS_CERTFP_STRING_SIZE];
  if (!io_bytes_to_hex(digest, digest_len, hex_digest, sizeof(hex_digest)))
    return false;

  *fingerprint = io_strdup(hex_digest);
  return true;
}
#endif  /* HAVE_TLS_GNUTLS */
