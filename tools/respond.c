/*
 *  Copyright (c) 2001-2014 ircd-hybrid development team
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

/*! \file respond.c
 * \brief A simple RSA authentification challenge response generator for the ircd-hybrid CHALLENGE command.
 * \version $Id: m_admin.c 3109 2014-03-06 19:25:12Z michael $
 */

#include <stdio.h>
#include <string.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/md5.h>
#include <unistd.h>

static int insecure_mode = 0;
static char *pass_param = NULL;

static int
pass_cb(char *buf, int size, int rwflag, void *u)
{
  int len = 0;
  char *tmp = NULL;

  if (insecure_mode != 0)
  {
    if (pass_param == NULL)
      return 0;
    len = strlen(pass_param);

    if (len <= 0)  /* This SHOULDN'T happen */
      return 0;
    if (len > size)
      len = size;

    memcpy(buf, pass_param, len);
    return len;
  }

  tmp = getpass("Enter passphrase for challenge: ");

  if (!tmp)
  {
    puts("Couldn't read passphrase from stdin!");
    exit(-1);
  }

  len = strlen(tmp);

  if (len <= 0) 
    return 0;
  if (len > size)
    len = size;

  memcpy(buf, tmp, len);
  return len;
}

static void
binary_to_hex(unsigned char *bin, char *hex, int length)
{
  static const char trans[] = "0123456789ABCDEF";
  int i;

  for (i = 0; i < length; ++i)
  {
    hex[(i << 1)    ] = trans[bin[i] >> 4];
    hex[(i << 1) + 1] = trans[bin[i] & 0xf];
  }

  hex[i << 1] = '\0';
}

static int
hex_to_binary(const char *from, char *to, int len)
{
  char a, b = 1;
  int p = 0;
  const char *ptr = from;

  while (-1)
  {
    a = *ptr++;

    if (!a)
      break;

    b = *ptr++;

    /* If this happens, we got bad input. */
    if (!b)
      break;
    if (p >= len)
      break;
    if (!((a >= '0' && a <= '9') || (a >= 'A' && a <= 'F')))
      break;
    if (!((b >= '0' && b <= '9') || (b >= 'A' && b <= 'F')))
      break;

    to[p++] = ((a <= '9') ? (a - '0') : (a - 'A' + 0xA)) << 4 |
              ((b <= '9') ? (b - '0') : (b - 'A' + 0xA));
  }

  return p;
}

int
main(int argc, char **argv)
{
  FILE *kfile = NULL;
  RSA *rsa = NULL;
  char ndata[257], ddata[257];

  /* respond privatefile challenge */
  if (argc < 3)
  {
    puts("Usage: respond privatefile challenge [passphrase]");
    return 0;
  }

  if (argc == 4)
  {
    /*
     * This is TOTALLY insecure and not recommended, but for
     * interfacing with irc client scripts, it's either this
     * or don't use a passphrase.
     *
     * The likelihood of a passphrase leaking isn't TOO great,
     * only ps auxww will show it, and even then, only at the
     * precise moment this is called.
     */
    insecure_mode = 1;
    pass_param = argv[3];
  }

  if (!(kfile = fopen(argv[1], "r")))
  {
    puts("Could not open the private keyfile.");
    return 0;
  }

  SSLeay_add_all_ciphers();
  rsa = PEM_read_RSAPrivateKey(kfile, NULL,pass_cb, NULL);

  if (!rsa)
  {
    puts("Unable to read your private key, is the passphrase wrong?");
    return 0;
  }

  fclose(kfile);

  if (hex_to_binary(argv[2], ndata, 128) != 128)
  {
    puts("Bad challenge.");
    return -1;
  }

  if (RSA_private_decrypt(128, (unsigned char *)ndata,
      (unsigned char *)ddata, rsa, RSA_PKCS1_PADDING) == -1)
  {
    puts("Decryption error.");
    return -1;
  }

  binary_to_hex((unsigned char *)ddata, ndata, 32);
  puts(ndata);

  return 0;
}
