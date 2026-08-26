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
tls_new_credentials(void)
{
  return true;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  return NULL;
}

const char *
tls_get_version(void)
{
  return NULL;
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
  return -1;
}

ssize_t
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, bool *want_read)
{
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
  return 0;
}

bool
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  return false;
}

bool
tls_get_peer_certificate_fingerprint(tls_data_t *tls_data, char **fingerprint)
{
  return false;
}
#endif  /* HAVE_TLS */
