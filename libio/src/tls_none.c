/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file tls_none.c
 * \brief Dummy file for no TLS support
 */

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#include "tls.h"

#ifndef HAVE_TLS
bool
tls_is_initialized(void)
{
  return false;
}

void
tls_init(void)
{
}

bool
tls_configure(const tls_config_t *config)
{
  return false;
}

void
tls_clear_credentials(void)
{
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  return NULL;
}

tls_library_info_t
tls_get_library_info(void)
{
  return (tls_library_info_t){ 0 };
}

bool
tls_isusing(tls_data_t *tls_data)
{
  return false;
}

void
tls_free(tls_data_t *tls_data)
{
}

ssize_t
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, bool *want_write)
{
  *want_write = false;
  return -1;
}

ssize_t
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, bool *want_read)
{
  *want_read = false;
  return -1;
}

void
tls_shutdown(tls_data_t *tls_data)
{
}

bool
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  return false;
}

tls_handshake_status_t
tls_handshake(tls_data_t *tls_data, const char **errstr)
{
  if (errstr)
    *errstr = NULL;

  return TLS_HANDSHAKE_ERROR;
}

bool
tls_get_peer_certificate_fingerprint(tls_data_t *tls_data, char **fingerprint)
{
  return false;
}
#endif  /* HAVE_TLS */
