/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file tls.h
 * \brief A header for generic TLS functions
 */

#ifndef INCLUDED_tls_h
#define INCLUDED_tls_h
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#include "config.h"  /**< Autotools-generated HAVE_LIBCRYPTO & HAVE_LIBGNUTLS & HAVE_LIBWOLFSSL. */
#ifdef HAVE_LIBCRYPTO
#include "tls_openssl.h"
#elif defined(HAVE_LIBGNUTLS)
#include "tls_gnutls.h"
#elif defined(HAVE_LIBWOLFSSL)
#include "tls_wolfssl.h"
#else
#include "tls_none.h"
#endif

enum
{
  TLS_CERTFP_DIGEST_SIZE = 32,
  TLS_CERTFP_STRING_SIZE = (TLS_CERTFP_DIGEST_SIZE * 2) + 1
};

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

extern void tls_free(tls_data_t *);
extern void tls_init(void);
extern void tls_shutdown(tls_data_t *);
extern bool tls_is_initialized(void);
extern bool tls_isusing(tls_data_t *);
extern bool tls_new(tls_data_t *, int, tls_role_t);
extern bool tls_new_credentials(void);
extern bool tls_get_peer_certificate_fingerprint(tls_data_t *, char **);
extern ssize_t tls_read(tls_data_t *, char *, size_t, bool *);
extern ssize_t tls_write(tls_data_t *, const char *, size_t, bool *);
extern tls_handshake_status_t tls_handshake(tls_data_t *, const char **);
extern const char *tls_get_cipher(const tls_data_t *);
extern const char *tls_get_version(void);
#endif  /* INCLUDED_tls_h */
