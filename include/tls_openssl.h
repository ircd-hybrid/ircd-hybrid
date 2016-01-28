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

/*! \file tls_openssl.h
 * \brief OpenSSL-specific TLS types
 * \version $Id$
 */


#ifndef INCLUDED_tls_openssl_h
#define INCLUDED_tls_openssl_h

#ifdef HAVE_LIBCRYPTO

#define HAVE_TLS
#define HAVE_TLS_OPENSSL

#include <openssl/ssl.h>
#include <openssl/err.h>

typedef SSL * tls_data_t;
typedef const EVP_MD * tls_md_t;

typedef struct
{
  SSL_CTX *server_ctx;
  SSL_CTX *client_ctx;
} tls_context_t;

#endif  /* HAVE_LIBCRYPTO */
#endif  /* INCLUDED_tls_openssl_h */
