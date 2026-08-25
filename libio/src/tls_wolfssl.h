/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include <wolfssl/openssl/evp.h>

typedef WOLFSSL * tls_data_t;
typedef const WOLFSSL_EVP_MD * tls_md_t;

typedef struct
{
  WOLFSSL_CTX *server_ctx;
  WOLFSSL_CTX *client_ctx;
} tls_context_t;
#endif  /* HAVE_LIBWOLFSSL */
#endif  /* INCLUDED_tls_wolfssl_h */
