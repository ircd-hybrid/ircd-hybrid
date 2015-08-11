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

/*! \file auth.h
 * \brief A header for the ident functions.
 * \version $Id$
 */

#ifndef INCLUDED_auth_h
#define INCLUDED_auth_h

enum { RFC1413_BUFSIZ = 512 };  /**< rfc1413 says we MUST accept 512 bytes */
enum { RFC1413_PORT   = 113 };  /**< As defined per rfc1413, IDENT server listens on TCP port 113 */

enum
{
  AM_IN_AUTH     = 0x00000001U,
  AM_DOING_AUTH  = 0x00000002U,
  AM_DNS_PENDING = 0x00000004U
};

#define SetInAuth(x)         ((x)->flags |= AM_IN_AUTH)
#define ClearInAuth(x)       ((x)->flags &= ~AM_IN_AUTH)
#define IsInAuth(x)          ((x)->flags &  AM_IN_AUTH)

#define SetDNSPending(x)     ((x)->flags |= AM_DNS_PENDING)
#define ClearDNSPending(x)   ((x)->flags &= ~AM_DNS_PENDING)
#define IsDNSPending(x)      ((x)->flags &  AM_DNS_PENDING)

#define SetDoingAuth(x)      ((x)->flags |= AM_DOING_AUTH)
#define ClearAuth(x)         ((x)->flags &= ~AM_DOING_AUTH)
#define IsDoingAuth(x)       ((x)->flags &  AM_DOING_AUTH)

struct Client;

/** Stores state of the DNS and RFC 1413 ident lookups for a client. */
struct AuthRequest
{
  dlink_node node;        /**< Doubly linked list node. */
  unsigned int flags;     /**< Current state of request. */
  struct Client *client;  /**< Pointer to Client structure for request. */
  fde_t fd;               /**< File descriptor for identd queries. */
  time_t timeout;         /**< Time when query expires. */
};

extern void auth_init(void);
extern void start_auth(struct Client *);
extern void delete_auth(struct AuthRequest *);
extern void release_auth_client(struct AuthRequest *);
#endif
