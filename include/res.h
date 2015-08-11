/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file res.h
 * \brief ircd resolver functions
 * \version $Id$
 */

#ifndef INCLUDED_res_h
#define INCLUDED_res_h

#include "config.h"

struct Client; /* XXX */


/*
 * From RFC 1035:
 *
 * Domain names in messages are expressed in terms of a sequence of labels.
 * Each label is represented as a one octet length field followed by that
 * number of octets.  Since every domain name ends with the null label of
 * the root, a domain name is terminated by a length byte of zero.  The
 * high order two bits of every length octet must be zero, and the
 * remaining six bits of the length field limit the label to 63 octets or
 * less.
 *
 * To simplify implementations, the total length of a domain name (i.e.,
 * label octets and label length octets) is restricted to 255 octets or
 * less.
 */
#define RFC1035_MAX_DOMAIN_LENGTH 255


/* Here we define some values lifted from nameser.h */
#define NS_NOTIFY_OP 4
#define NS_INT16SZ 2
#define NS_IN6ADDRSZ    16
#define NS_INADDRSZ     4
#define NS_INT32SZ 4
#define NS_CMPRSFLGS    0xc0
#define NS_MAXCDNAME 255
#define QUERY 0
#define IQUERY 1
#define NO_ERRORS 0
#define SERVFAIL 2
#define NXDOMAIN 3
#define T_A 1
#define T_AAAA 28
#define T_PTR 12
#define T_CNAME 5
#define T_NULL 10
#define C_IN 1
#define QFIXEDSZ 4
#define RRFIXEDSZ 10
#define HFIXEDSZ 12


typedef struct
{
  unsigned  id :16;     /* query identification number */
#ifdef WORDS_BIGENDIAN
  /* fields in third byte */
  unsigned  qr: 1;      /* response flag */
  unsigned  opcode: 4;  /* purpose of message */
  unsigned  aa: 1;      /* authoritive answer */
  unsigned  tc: 1;      /* truncated message */
  unsigned  rd: 1;      /* recursion desired */

  /* fields in fourth byte */
  unsigned  ra: 1;      /* recursion available */
  unsigned  unused :1;  /* unused bits (MBZ as of 4.9.3a3) */
  unsigned  ad: 1;      /* authentic data from named */
  unsigned  cd: 1;      /* checking disabled by resolver */
  unsigned  rcode :4;   /* response code */
#else
  /* fields in third byte */
  unsigned  rd :1;      /* recursion desired */
  unsigned  tc :1;      /* truncated message */
  unsigned  aa :1;      /* authoritive answer */
  unsigned  opcode :4;  /* purpose of message */
  unsigned  qr :1;      /* response flag */

  /* fields in fourth byte */
  unsigned  rcode :4;   /* response code */
  unsigned  cd: 1;      /* checking disabled by resolver */
  unsigned  ad: 1;      /* authentic data from named */
  unsigned  unused :1;  /* unused bits (MBZ as of 4.9.3a3) */
  unsigned  ra :1;      /* recursion available */
#endif
  /* remaining bytes */
  unsigned  qdcount :16; /* number of question entries */
  unsigned  ancount :16; /* number of answer entries */
  unsigned  nscount :16; /* number of authority entries */
  unsigned  arcount :16; /* number of resource entries */
} HEADER;

typedef void (*dns_callback_fnc)(void *, const struct irc_ssaddr *, const char *, size_t);

extern void init_resolver(void);
extern void restart_resolver(void);
extern void delete_resolver_queries(const void *);
extern void report_dns_servers(struct Client *);
extern void gethost_byname_type(dns_callback_fnc , void *, const char *, int);
extern void gethost_byaddr(dns_callback_fnc, void *, const struct irc_ssaddr *);
#endif
