/*
 * SPDX-FileCopyrightText: 2015 Attila Molnar <attilamolnar@hush.com>
 * SPDX-FileCopyrightText: 2015 Adam <Adam@anope.org>
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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

typedef struct tls_context *tls_context_t;

struct tls_context
{
  gnutls_certificate_credentials_t x509_cred;
  gnutls_priority_t priorities;
  unsigned int ref_count;
};

typedef struct
{
  gnutls_session_t session;
  tls_context_t context;
} tls_data_t;
#endif  /* HAVE_LIBGNUTLS */
#endif  /* INCLUDED_tls_gnutls_h */
