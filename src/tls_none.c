/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015 Attila Molnar <attilamolnar@hush.com>
 *  Copyright (c) 2015 Adam <Adam@anope.org>
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

/*! \file tls_none.c
 * \brief Dummy file for no TLS support
 * \version $Id$
 */

#include "stdinc.h"
#include "tls.h"

#ifndef HAVE_TLS

void
tls_init(void)
{
}

int
tls_new_cred(void)
{
  return 0;
}

const char *
tls_get_cipher(const tls_data_t *tls_data)
{
  return NULL;
}

int
tls_isusing(tls_data_t *tls_data)
{
  return 0;
}

void
tls_free(tls_data_t *tls_data)
{
}

int
tls_read(tls_data_t *tls_data, char *buf, size_t bufsize, int *want_write)
{
  return -1;
}

int
tls_write(tls_data_t *tls_data, const char *buf, size_t bufsize, int *want_read)
{
  return -1;
}

void
tls_shutdown(tls_data_t *tls_data)
{
}

int
tls_new(tls_data_t *tls_data, int fd, tls_role_t role)
{
  return 0;
}

int
tls_set_ciphers(tls_data_t *tls_data, const char *cipher_list)
{
  return 0;
}

int
tls_verify_cert(tls_data_t *tls_data, tls_md_t digest, char **fingerprint)
{
  return 0;
}
#endif  /* HAVE_TLS */
