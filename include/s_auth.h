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


struct Client;

struct AuthRequest
{
  dlink_node	      node;	 /* auth_doing_list */
  int 		      flags;
  struct Client*      client;    /* pointer to client struct for request */
  fde_t               fd;        /* file descriptor for auth queries */
  time_t              timeout;   /* time when query expires */
};

/*
 * flag values for AuthRequest
 * NAMESPACE: AM_xxx - Authentication Module
 */
#define AM_DOING_AUTH        0x1
#define AM_DNS_PENDING       0x2

#define SetDNSPending(x)     ((x)->flags |= AM_DNS_PENDING)
#define ClearDNSPending(x)   ((x)->flags &= ~AM_DNS_PENDING)
#define IsDNSPending(x)      ((x)->flags &  AM_DNS_PENDING)

#define SetDoingAuth(x)      ((x)->flags |= AM_DOING_AUTH)
#define ClearAuth(x)         ((x)->flags &= ~AM_DOING_AUTH)
#define IsDoingAuth(x)       ((x)->flags &  AM_DOING_AUTH)

extern struct Callback *auth_cb;

extern void init_auth(void);
extern void send_auth_query(struct AuthRequest *);
extern void remove_auth_request(struct AuthRequest *);
extern void delete_auth(struct AuthRequest *);
extern void release_auth_client(struct AuthRequest *);

#endif /* INCLUDED_s_auth_h */
