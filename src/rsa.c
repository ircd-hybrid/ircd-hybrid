/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2016 ircd-hybrid development team
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

/*! \file rsa.c
 * \brief Functions for use with RSA public key cryptography.
 * \version $Id$
 */

#include "stdinc.h"
#ifdef HAVE_LIBCRYPTO
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/opensslv.h>

#include "memory.h"
#include "conf.h"
#include "log.h"
#endif

#include "rsa.h"

#ifdef HAVE_LIBCRYPTO
/*
 * report_crypto_errors - Dump crypto error list to log
 */
void
report_crypto_errors(void)
{
  unsigned long e = 0;

  while ((e = ERR_get_error()))
    ilog(LOG_TYPE_IRCD, "SSL error: %s", ERR_error_string(e, 0));
}
#endif

void
binary_to_hex(const unsigned char *bin, char *hex, unsigned int length)
{
  static const char trans[] = "0123456789ABCDEF";

  for (const unsigned char *const end = bin + length; bin < end; ++bin)
  {
    *hex++ = trans[*bin >>  4];
    *hex++ = trans[*bin & 0xf];
  }

  *hex = '\0';
}
