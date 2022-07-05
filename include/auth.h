/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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
 * \brief Interface for DNS and ident lookups.
 * \version $Id$
 */

#ifndef INCLUDED_auth_h
#define INCLUDED_auth_h

enum { RFC1413_BUFSIZ = 512 };  /**< rfc1413 says we MUST accept 512 bytes */
enum { RFC1413_PORT   = 113 };  /**< As defined per rfc1413, IDENT server listens on TCP port 113 */

struct Client;

/** Stores state of the DNS and RFC 1413 ident lookups for a client. */
struct AuthRequest
{
  bool dns_pending;  /**< 'true' as long as dns request hasn't finished */
  bool ident_pending;  /**< 'true' as long as identd request hasn't finished */
  struct Client *client;  /**< Pointer to Client structure for request. */
  fde_t *fd;  /**< File descriptor for identd queries. */
};

extern void auth_init(void);
extern void auth_start(struct Client *);
extern void auth_delete(struct AuthRequest *);
#endif  /* INCLUDED_auth_h */
