/************************************************************************
 *   IRC - Internet Relay Chat, servlink/servlink.h
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

#ifndef INCLUDED_servlink_servlink_h
#define INCLUDED_servlink_servlink_h

#include "config.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/evp.h>
#endif
#ifdef HAVE_LIBZ
#include <zlib.h>
#endif

/* do not use stdin/out/err, as it seems to break on solaris */
#define CONTROL_R               fds[0]
#define CONTROL_W               fds[1]
#define LOCAL_R                 fds[2]
#define LOCAL_W                 fds[3]
#define REMOTE_R                fds[4]
#define REMOTE_W                REMOTE_R

#undef  SERVLINK_DEBUG

#define READLEN                  16384

#ifdef HAVE_LIBZ
#define BUFLEN                   READLEN * 6 /* allow for decompression */
#else
#define BUFLEN                   READLEN
#endif


#ifdef HAVE_LIBCRYPTO
#define CIPHER_BF       1
#define CIPHER_CAST     2
#define CIPHER_DES      3
#define CIPHER_3DES     4
#define CIPHER_IDEA     5
#define CIPHER_RC5_8    6
#define CIPHER_RC5_12   7
#define CIPHER_RC5_16   8

struct crypt_state
{
  EVP_CIPHER_CTX       ctx;
  const EVP_CIPHER     *cipher;
  unsigned int          keylen;         /* bytes */
  unsigned char        *key;
  unsigned int          ivlen;          /* bytes */
  unsigned char        *iv;
  unsigned int          rounds;         /* rc5 only */
};
#endif

#ifdef HAVE_LIBZ
struct zip_state
{
  z_stream             stream;
  int                  level;           /* compression level */
};
#endif

struct slink_state
{
  unsigned int          crypt:1;
  unsigned int          zip:1;
  unsigned int          active:1;

  unsigned char         buf[BUFLEN*2];
  unsigned int          ofs;
  unsigned int          len;

#ifdef HAVE_LIBCRYPTO
  struct crypt_state    crypt_state;
#endif
#ifdef HAVE_LIBZ
  struct zip_state      zip_state;
#endif
};


typedef void (io_callback)(void);

struct fd_table
{
  int           fd;
  io_callback   *read_cb;
  io_callback   *write_cb;
};

extern struct slink_state       in_state;
extern struct slink_state       out_state;
extern struct fd_table          fds[5];

#endif /* INCLUDED_servlink_servlink_h */
