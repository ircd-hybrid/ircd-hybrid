/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file tls_openssl.h
 * \brief OpenSSL-specific TLS types
 */

#ifndef INCLUDED_tls_openssl_h
#define INCLUDED_tls_openssl_h

#ifdef HAVE_LIBCRYPTO

#define HAVE_TLS
#define HAVE_TLS_OPENSSL

#include <openssl/ssl.h>
#include <openssl/err.h>

typedef SSL * tls_data_t;
typedef EVP_MD * tls_md_t;

typedef struct
{
  SSL_CTX *server_ctx;
  SSL_CTX *client_ctx;
} tls_context_t;
#endif  /* HAVE_LIBCRYPTO */
#endif  /* INCLUDED_tls_openssl_h */
