/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/**
 * @file auth.h
 * @brief This file contains the interface for handling DNS and ident lookups in the server.
 *
 * The functions and structures defined in this file are responsible for managing the authentication
 * process, including DNS hostname resolution and RFC 1413 Identd queries for connecting clients.
 */

#ifndef INCLUDED_auth_h
#define INCLUDED_auth_h

/**
 * @enum RFC1413_BUFSIZE
 * @brief Maximum buffer size for RFC 1413 ident replies.
 *
 * The RFC1413_BUFSIZE constant represents the maximum buffer size, in bytes, that is
 * allowed for RFC 1413 ident replies. According to the RFC 1413 standard, a server
 * should not send more than 512 octets of user ID and a client must accept at least
 * 512 octets of user ID.
 */
enum { RFC1413_BUFSIZE = 512 };

/**
 * @enum RFC1413_PORTNUM
 * @brief Port number for the (Ident) server.
 *
 * The RFC1413_PORTNUM constant represents the TCP port number (113) on which the
 * Ident server listens, adhering to the guidelines outlined in RFC 1413.
 */
enum { RFC1413_PORTNUM = 113 };

struct Client;

/**
 * @struct AuthRequest
 * @brief Structure to maintain the state of DNS and ident lookups for a client.
 *
 * The AuthRequest structure holds information about ongoing DNS and ident lookup
 * processes for a specific client. It is used to track the progress of these
 * lookups and manage associated resources.
 */
struct AuthRequest
{
  bool dns_pending;  /**< Flag indicating whether a DNS request is pending for the client. */
  bool ident_pending;  /**< Flag indicating whether an identd request is pending for the client. */
  struct Client *client;  /**< Pointer to the Client structure associated with the request. */
  fde_t *fd;  /**< File descriptor for identd queries. */
};

extern void auth_init(void);
extern void auth_start(struct Client *);
extern void auth_delete(struct AuthRequest *);
#endif  /* INCLUDED_auth_h */
