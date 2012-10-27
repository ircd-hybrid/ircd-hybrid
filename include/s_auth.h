/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_auth.h: A header for the ident functions.
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

#ifndef INCLUDED_s_auth_h
#define INCLUDED_s_auth_h

#include "irc_res.h"
#include "hook.h"

/* How many auth allocations to allocate in a block. I'm guessing that
 * a good number here is 64, because these are temporary and don't live
 * as long as clients do.
 *     -- adrian
 */
#define	AUTH_BLOCK_SIZE 64

struct Client;

struct AuthRequest
{
  dlink_node	      dns_node;	 /* auth_doing_dns_list */
  dlink_node	      ident_node; /* auth_doing_ident_list */
  int 		      flags;
  struct Client*      client;    /* pointer to client struct for request */
  fde_t               fd;        /* file descriptor for auth queries */
  time_t              timeout;   /* time when query expires */
  unsigned int	      ip6_int;
};

/*
 * flag values for AuthRequest
 * NAMESPACE: AM_xxx - Authentication Module
 */
#define AM_DOING_AUTH        1
#define AM_DNS_PENDING       2
#define CRIT_REGION	     4

#define SetDNSPending(x)     ((x)->flags |= AM_DNS_PENDING)
#define ClearDNSPending(x)   ((x)->flags &= ~AM_DNS_PENDING)
#define IsDNSPending(x)      ((x)->flags &  AM_DNS_PENDING)

#define SetDoingAuth(x)      ((x)->flags |= AM_DOING_AUTH)
#define ClearAuth(x)         ((x)->flags &= ~AM_DOING_AUTH)
#define IsDoingAuth(x)       ((x)->flags &  AM_DOING_AUTH)

#define IsCrit(x)	     ((x)->flags & CRIT_REGION)
#define SetCrit(x)	     ((x)->flags |= CRIT_REGION)
#define ClearCrit(x)	     ((x)->flags &= ~CRIT_REGION)

extern struct Callback *auth_cb;

extern void send_auth_query(struct AuthRequest *);
extern void remove_auth_request(struct AuthRequest *);
extern struct AuthRequest *FindAuthClient(long);
extern void init_auth(void);
extern void delete_auth(struct Client *);
extern void release_auth_client(struct Client *);

#endif /* INCLUDED_s_auth_h */
