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

/*! \file s_bsd.h
 * \brief A header for the network subsystem.
 * \version $Id$
 */

#ifndef INCLUDED_s_bsd_h
#define INCLUDED_s_bsd_h

#include "config.h"
#include "fdlist.h"

/* Type of IO */
#define COMM_SELECT_READ  1
#define COMM_SELECT_WRITE 2

/* How long can comm_select() wait for network events [milliseconds] */
#define SELECT_DELAY    500

struct Client;
struct MaskItem;
struct Listener;

extern void add_connection(struct Listener *, struct irc_ssaddr *, int);
extern void close_connection(struct Client *);
extern void report_error(int, const char *, const char *, int);

extern int get_sockerr(int);
extern int ignoreErrno(int);

extern void comm_settimeout(fde_t *, time_t, PF *, void *);
extern void comm_setflush(fde_t *, time_t, PF *, void *);
extern void comm_checktimeouts(void *);
extern void comm_connect_tcp(fde_t *, const char *, unsigned short,
                             struct sockaddr *, int, CNCB *, void *, int, int);
extern const char *comm_errstr(int status);
extern int comm_open(fde_t *F, int family, int sock_type, int proto,
                     const char *note);
extern int comm_accept(struct Listener *, struct irc_ssaddr *pn);

/* These must be defined in the network IO loop code of your choice */
extern void init_netio(void);
extern void comm_setselect(fde_t *, unsigned int, PF *, void *, time_t);
extern int read_message (time_t, unsigned char);
extern void comm_select(void);
extern void check_can_use_v6(void);
#ifdef IPV6
extern void remove_ipv6_mapping(struct irc_ssaddr *);
#endif
#endif /* INCLUDED_s_bsd_h */
