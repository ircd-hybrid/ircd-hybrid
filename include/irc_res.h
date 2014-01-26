/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file irc_res.h
 * \brief ircd resolver functions
 * \version $Id$
 */

#ifndef INCLUDED_irc_res_h
#define INCLUDED_irc_res_h

#include "config.h"

struct Client; /* XXX */

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

typedef void (*dns_callback_fnc)(void *, const struct irc_ssaddr *, const char *);

extern void init_resolver(void);
extern void restart_resolver(void);
extern void delete_resolver_queries(const void *);
extern void report_dns_servers(struct Client *);
extern void gethost_byname_type(dns_callback_fnc , void *, const char *, int);
extern void gethost_byname(dns_callback_fnc, void *, const char *);
extern void gethost_byaddr(dns_callback_fnc, void *, const struct irc_ssaddr *);
#endif
