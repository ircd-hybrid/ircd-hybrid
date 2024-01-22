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

/*! \file tls_wolfssl.h
 * \brief wolfSSL-specific TLS types
 */

#ifndef INCLUDED_tls_wolfssl_h
#define INCLUDED_tls_wolfssl_h

#ifdef HAVE_LIBWOLFSSL

#define HAVE_TLS
#define HAVE_TLS_WOLFSSL

#include <wolfssl/options.h>
#include <wolfssl/ssl.h>

typedef WOLFSSL * tls_data_t;
typedef const WOLFSSL_EVP_MD * tls_md_t;

typedef struct
{
  WOLFSSL_CTX *server_ctx;
  WOLFSSL_CTX *client_ctx;
} tls_context_t;
#endif  /* HAVE_LIBWOLFSSL */
#endif  /* INCLUDED_tls_wolfssl_h */
