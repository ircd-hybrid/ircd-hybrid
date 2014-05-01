/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
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
#include "rsa.h"
#include "conf.h"
#include "log.h"


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

static void
binary_to_hex(unsigned char *bin, char *hex, unsigned int length)
{
  static const char trans[] = "0123456789ABCDEF";
  unsigned int i = 0;

  for (; i < length; ++i)
  {
    hex[(i << 1)    ] = trans[bin[i] >> 4];
    hex[(i << 1) + 1] = trans[bin[i] & 0xf];
  }

  hex[i << 1] = '\0';
}

int
get_randomness(unsigned char *buf, int length)
{
  /* Seed OpenSSL PRNG with EGD enthropy pool -kre */
  if (ConfigFileEntry.use_egd && ConfigFileEntry.egdpool_path)
    if (RAND_egd(ConfigFileEntry.egdpool_path) == -1)
      return -1;

  if (RAND_status())
    return RAND_bytes(buf, length);
  /* XXX - abort? */
  return RAND_pseudo_bytes(buf, length);
}

int
generate_challenge(char **r_challenge, char **r_response, RSA *rsa)
{
  unsigned char secret[32], *tmp = NULL;
  unsigned long length = 0;
  int ret = -1;

  if (!rsa)
    return -1;

  get_randomness(secret, 32);
  *r_response = MyMalloc(65);
  binary_to_hex(secret, *r_response, 32);

  length = RSA_size(rsa);
  tmp = MyMalloc(length);
  ret = RSA_public_encrypt(32, secret, tmp, rsa, RSA_PKCS1_PADDING);

  *r_challenge = MyMalloc((length << 1) + 1);
  binary_to_hex( tmp, *r_challenge, length);
  (*r_challenge)[length << 1] = 0;
  MyFree(tmp);

  if (ret < 0)
  {
    report_crypto_errors();
    return -1;
  }

  return 0;
}
#endif
