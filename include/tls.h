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

/*! \file tls.h
 * \brief A header for generic TLS functions
 * \version $Id$
 */

#ifndef INCLUDED_tls_h
#define INCLUDED_tls_h

#ifdef HAVE_LIBCRYPTO
#include "tls_openssl.h"
#elif defined(HAVE_LIBGNUTLS)
#include "tls_gnutls.h"
#else
#include "tls_none.h"
#endif

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

extern void tls_init(void);
extern int tls_new_cred(void);

extern const char *tls_get_cipher(const tls_data_t *);

extern int tls_isusing(tls_data_t *);
extern int tls_new(tls_data_t *, int, tls_role_t);
extern void tls_free(tls_data_t *);

extern tls_handshake_status_t tls_handshake(tls_data_t *, tls_role_t, const char **);
extern int tls_read(tls_data_t *, char *, size_t, int *);
extern int tls_write(tls_data_t *, const char *, size_t, int *);

extern void tls_shutdown(tls_data_t *);

extern int tls_set_ciphers(tls_data_t *, const char *);

extern int tls_verify_cert(tls_data_t *, tls_md_t, char **, int *);

#endif  /* INCLUDED_tls_h */
