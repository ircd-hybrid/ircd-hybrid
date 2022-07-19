/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015 Attila Molnar <attilamolnar@hush.com>
 *  Copyright (c) 2015 Adam <Adam@anope.org>
 *  Copyright (c) 2015-2022 ircd-hybrid development team
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

/*! \file tls_gnutls.h
 * \brief GnuTLS-specific TLS types
 */

#ifndef INCLUDED_tls_gnutls_h
#define INCLUDED_tls_gnutls_h

#ifdef HAVE_LIBGNUTLS

#define HAVE_TLS
#define HAVE_TLS_GNUTLS

#include <gnutls/gnutls.h>
#include <gnutls/x509.h>

enum { TLS_GNUTLS_MAX_HASH_SIZE = 64 };

typedef gnutls_digest_algorithm_t tls_md_t;
typedef struct gnutls_context * tls_context_t;

struct gnutls_context
{
  gnutls_certificate_credentials_t x509_cred;
  gnutls_priority_t priorities;
  gnutls_dh_params_t dh_params;
  unsigned int refs;
};

typedef struct
{
  gnutls_session_t session;
  tls_context_t context;
} tls_data_t;
#endif  /* HAVE_LIBGNUTLS */
#endif  /* INCLUDED_tls_gnutls_h */
