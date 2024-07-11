/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015 Attila Molnar <attilamolnar@hush.com>
 *  Copyright (c) 2015 Adam <Adam@anope.org>
 *  Copyright (c) 2015-2024 ircd-hybrid development team
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

/*! \file tls_none.c
 * \brief Dummy file for no TLS support
 */

#include "stdinc.h"
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
tls_handshake(tls_data_t *tls_data, tls_role_t role, const char **errstr)
{
  return 0;
}

bool
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  return false;
}

bool
tls_verify_certificate(tls_data_t *tls_data, char **fingerprint)
{
  return false;
}
#endif  /* HAVE_TLS */
