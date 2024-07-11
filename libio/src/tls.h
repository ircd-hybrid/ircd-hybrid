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

/*! \file tls.h
 * \brief A header for generic TLS functions
 */

#ifndef INCLUDED_tls_h
#define INCLUDED_tls_h

#ifdef HAVE_LIBCRYPTO
#include "tls_openssl.h"
#elif defined(HAVE_LIBGNUTLS)
#include "tls_gnutls.h"
#elif defined(HAVE_LIBWOLFSSL)
#include "tls_wolfssl.h"
#else
#include "tls_none.h"
#endif

/**< Time in seconds for the TLS handshake to time out. */
enum { TLS_HANDSHAKE_TIMEOUT = 5 };

typedef enum _tls_role
{
  TLS_ROLE_SERVER,
  TLS_ROLE_CLIENT
} tls_role_t;

typedef enum _tls_handshake_status
{
  TLS_HANDSHAKE_DONE,
  TLS_HANDSHAKE_WANT_READ,
  TLS_HANDSHAKE_WANT_WRITE,
  TLS_HANDSHAKE_ERROR
} tls_handshake_status_t;

extern bool tls_is_initialized(void);
extern void tls_init(void);
extern bool tls_new_credentials(void);

extern const char *tls_get_cipher(const tls_data_t *);
extern const char *tls_get_version(void);

extern bool tls_isusing(tls_data_t *);
extern bool tls_new(tls_data_t *, int, tls_role_t);
extern void tls_free(tls_data_t *);

extern tls_handshake_status_t tls_handshake(tls_data_t *, tls_role_t, const char **);
extern ssize_t tls_read(tls_data_t *, char *, size_t, bool *);
extern ssize_t tls_write(tls_data_t *, const char *, size_t, bool *);

extern void tls_shutdown(tls_data_t *);

extern bool tls_set_ciphers(tls_data_t *, const char *);

extern bool tls_verify_certificate(tls_data_t *, char **);

#endif  /* INCLUDED_tls_h */
