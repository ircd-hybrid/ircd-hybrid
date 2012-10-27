/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_serv.h: A header for the server functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#ifndef INCLUDED_serv_h
#define INCLUDED_serv_h
#include "setup.h"

/* collect ziplinks compression ratios/etc every minute */
#define ZIPSTATS_TIME           60

struct ConfItem;

/*
 * number of seconds to wait after server starts up, before
 * starting try_connections()
 * TOO SOON and you can nick collide like crazy. 
 */
#define STARTUP_CONNECTIONS_TIME 60

struct Client;
struct AccessItem;
struct Channel;

/* Capabilities */
struct Capability
{
  dlink_node node;
  char *name; 	    /* name of capability */
  unsigned int cap; /* mask value         */
};

#define CAP_CAP		0x00000001 /* received a CAP to begin with        */
#define CAP_QS		0x00000002 /* Can handle quit storm removal       */
#define CAP_EX		0x00000004 /* Can do channel +e exemptions        */
#define CAP_CHW		0x00000008 /* Can do channel wall @#              */
#define CAP_LL		0x00000010 /* Can do lazy links                   */
#define CAP_IE		0x00000020 /* Can do invite exceptions            */
#define CAP_EOB		0x00000040 /* Can do EOB message                  */
#define CAP_KLN		0x00000080 /* Can do KLINE message                */
#define CAP_GLN		0x00000100 /* Can do GLINE message                */
#define CAP_HUB		0x00000200 /* This server is a HUB                */
#define CAP_TS6		0x00000400 /* Can do TS6                          */
#define CAP_ZIP		0x00000800 /* Can do ZIPlinks                     */
#define CAP_ENC		0x00001000 /* Can do ENCrypted links              */
#define CAP_KNOCK	0x00002000 /* supports KNOCK                      */
#define CAP_TB	        0x00004000 /* supports TB                         */
#define CAP_UNKLN	0x00008000 /* Can do UNKLINE message		  */
#define CAP_CLUSTER	0x00010000 /* supports server clustering	  */
#define CAP_ENCAP	0x00020000 /* supports ENCAP message		  */
#define CAP_HOPS	0x00040000 /* supports HALFOPS			  */
#define CAP_TBURST      0x00080000 /* supports TBURST                     */

#ifdef HAVE_LIBZ
#define CAP_ZIP_SUPPORTED CAP_ZIP
#else
#define CAP_ZIP_SUPPORTED 0
#endif

#ifdef HAVE_LIBCRYPTO
struct EncCapability
{
  const char *name; /* name of capability (cipher name)          */
  unsigned int cap; /* mask value                                */
  int keylen;       /* keylength (bytes)                         */
  int cipherid;     /* ID number of cipher type (BF, IDEA, etc.) */
};

/*
 * Cipher ID numbers
 *   - DO NOT CHANGE THESE!  Otherwise you break backwards compatibility
 *     If you wish to add a new cipher, append it to the list.  Do not
 *     have it's value replace another.
 */
#define CIPHER_BF       1
#define CIPHER_CAST     2
#define CIPHER_DES      3
#define CIPHER_3DES     4
#define CIPHER_IDEA     5
#define CIPHER_RC5_8    6
#define CIPHER_RC5_12   7
#define CIPHER_RC5_16   8

/* Cipher Capabilities */
#define CAP_ENC_BF_128          0x00000001
#define CAP_ENC_BF_168          0x00000002
#define CAP_ENC_CAST_128        0x00000004
#define CAP_ENC_DES_56          0x00000008
#define CAP_ENC_3DES_168        0x00000010
#define CAP_ENC_IDEA_128        0x00000020
#define CAP_ENC_RC5_8_128       0x00000040
#define CAP_ENC_RC5_12_128      0x00000080
#define CAP_ENC_RC5_16_128      0x00000100
#define CAP_ENC_ALL             0xFFFFFFFF


/* */
#ifdef HAVE_EVP_BF_CFB
#define USE_CIPHER_BF       1
/* Check for bug handling variable length blowfish keys */
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x00000000L
#define USE_CIPHER_BF_V     1
#else
#define USE_CIPHER_BF_V     0
#endif
#else
#define USE_CIPHER_BF_V     0
#define USE_CIPHER_BF       0
#endif
/* Cast */
#ifdef HAVE_EVP_CAST5_CFB
#define USE_CIPHER_CAST     1
#else
#define USE_CIPHER_CAST     0
#endif
/* DES */
#ifdef HAVE_EVP_DES_CFB
#define USE_CIPHER_DES      1
#else
#define USE_CIPHER_DES      0
#endif
/* 3DES */
#ifdef HAVE_EVP_DES_EDE3_CFB
#define USE_CIPHER_3DES     1
#else
#define USE_CIPHER_3DES     0
#endif
/* IDEA */
#ifdef HAVE_EVP_IDEA_CFB
#define USE_CIPHER_IDEA     1
#else
#define USE_CIPHER_IDEA     0
#endif
/* RC5 */
#ifdef HAVE_EVP_RC5_32_12_16_CFB
#define USE_CIPHER_RC5      1
#else
#define USE_CIPHER_RC5      0
#endif

/* Only enable ciphers supported by available version of OpenSSL */
#define CAP_ENC_MASK \
             (((USE_CIPHER_BF   * CAP_ENC_ALL) & CAP_ENC_BF_128)         | \
              ((USE_CIPHER_BF_V * CAP_ENC_ALL) & CAP_ENC_BF_168)         | \
              ((USE_CIPHER_CAST * CAP_ENC_ALL) & CAP_ENC_CAST_128)       | \
              ((USE_CIPHER_DES  * CAP_ENC_ALL) & CAP_ENC_DES_56)         | \
              ((USE_CIPHER_3DES * CAP_ENC_ALL) & CAP_ENC_3DES_168)       | \
              ((USE_CIPHER_IDEA * CAP_ENC_ALL) & CAP_ENC_IDEA_128)       | \
              ((USE_CIPHER_RC5  * CAP_ENC_ALL) & CAP_ENC_RC5_8_128)      | \
              ((USE_CIPHER_RC5  * CAP_ENC_ALL) & CAP_ENC_RC5_12_128)     | \
              ((USE_CIPHER_RC5  * CAP_ENC_ALL) & CAP_ENC_RC5_16_128))

#define IsCapableEnc(x, cap)    ((x)->localClient->enc_caps &   (cap))
#define SetCapableEnc(x, cap)   ((x)->localClient->enc_caps |=  (cap))
#define ClearCapEnc(x, cap)     ((x)->localClient->enc_caps &= ~(cap))
#endif /* HAVE_LIBCRYPTO */

#define CHECK_SERVER_CRYPTLINK    1
#define CHECK_SERVER_NOCRYPTLINK  0

/*
 * Capability macros.
 */
#define IsCapable(x, cap)       ((x)->localClient->caps &   (cap))
#define SetCapable(x, cap)      ((x)->localClient->caps |=  (cap))
#define ClearCap(x, cap)        ((x)->localClient->caps &= ~(cap))

#define SLINKCMD_SET_ZIP_OUT_LEVEL           1       /* data */
#define SLINKCMD_START_ZIP_OUT               2
#define SLINKCMD_START_ZIP_IN                3
#define SLINKCMD_SET_CRYPT_IN_CIPHER         4       /* data */
#define SLINKCMD_SET_CRYPT_IN_KEY            5       /* data */
#define SLINKCMD_START_CRYPT_IN              6
#define SLINKCMD_SET_CRYPT_OUT_CIPHER        7       /* data */
#define SLINKCMD_SET_CRYPT_OUT_KEY           8       /* data */
#define SLINKCMD_START_CRYPT_OUT             9
#define SLINKCMD_INJECT_RECVQ                10      /* data */
#define SLINKCMD_INJECT_SENDQ                11      /* data */
#define SLINKCMD_INIT                        12
#define SLINKCMD_ZIPSTATS                    13

#define SLINKRPL_FLAG_DATA      0x0001  /* reply has data following */
#define SLINKRPL_ERROR          1
#define SLINKRPL_ZIPSTATS       2

typedef void SlinkRplHnd(unsigned int replyid, unsigned int datalen,
                         unsigned char *data, struct Client *client_p);
struct SlinkRplDef
{
  unsigned int replyid;
  SlinkRplHnd *handler;
  unsigned int flags;
};

extern struct SlinkRplDef slinkrpltab[];

/*
 * Globals
 *
 *
 * list of recognized server capabilities.  "TS" is not on the list
 * because all servers that we talk to already do TS, and the kludged
 * extra argument to "PASS" takes care of checking that.  -orabidoo
 */
extern struct Capability captab[];
#ifdef HAVE_LIBCRYPTO
extern struct EncCapability CipherTable[];
#endif

extern struct Client *uplink; /* NON NULL if leaf and is this servers uplink */

/*
 * return values for hunt_server() 
 */
#define HUNTED_NOSUCH   (-1)    /* if the hunted server is not found */
#define HUNTED_ISME     0       /* if this server should execute the command */
#define HUNTED_PASS     1       /* if message passed onwards successfully */

extern int check_server(const char *, struct Client *, int);
extern int hunt_server(struct Client *, struct Client *,
                       const char *, int, int, char **);
extern const char *my_name_for_link(struct ConfItem *);
extern void add_capability(const char *, int, int);
extern int delete_capability(const char *);
extern int find_capability(const char *);
extern void send_capabilities(struct Client *, struct AccessItem *, int, int);
extern void write_links_file(void *);
extern void server_estab(struct Client *);
extern void set_autoconn(struct Client *, const char *, int);
extern const char *show_capabilities(struct Client *);
extern void try_connections(void *);
extern void collect_zipstats(void *);
extern void initServerMask(void);
extern void burst_channel(struct Client *client_p, struct Channel *);
extern void sendnick_TS(struct Client *, struct Client *);
extern int serv_connect(struct AccessItem *, struct Client *);
extern struct Client *find_servconn_in_progress(const char *);
extern unsigned long nextFreeMask(void);
extern void cryptlink_init(struct Client *, struct ConfItem *, fde_t *);
extern void cryptlink_regen_key(void *);
extern void cryptlink_error(struct Client *, const char *,
                            const char *, const char *);
extern void remove_lazylink_flags(unsigned long);
extern void client_burst_if_needed(struct Client *, struct Client *);
extern struct EncCapability *check_cipher(struct Client *, struct AccessItem *);
extern void add_lazylinkclient(struct Client *, struct Client *);

extern struct Server *make_server(struct Client *);

/* XXX don't belong in the now gone md5, but do these belong in s_serv.c ? */
extern int base64_block(unsigned char **, char *, int);
extern int unbase64_block(unsigned char **, char *, int);
#endif /* INCLUDED_s_serv_h */

