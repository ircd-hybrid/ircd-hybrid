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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file listener.h
 * \brief A header for the listener code.
 * \version $Id$
 */

#ifndef INCLUDED_listener_h
#define INCLUDED_listener_h

#include "ircd_defs.h"
#include "fdlist.h"

struct Client;

enum
{
  LISTENER_SSL    = 1 << 0,
  LISTENER_HIDDEN = 1 << 1,
  LISTENER_SERVER = 1 << 2
};

struct Listener
{
  dlink_node node;           /**< Doubly linked list node */
  fde_t fd;                  /**< Describe socket to event system */
  int port;                  /**< Listener IP port */
  int ref_count;             /**< Number of connection references */
  int active;                /**< Current state of listener */
  struct irc_ssaddr addr;    /**< Holds an IPv6 or IPv4 address */
  char name[HOSTIPLEN + 1];  /**< Holds an IPv6 or IPv4 address in string representation*/
  unsigned int flags;        /**< Listener flags (ssl, hidden, server) */
};

extern void add_listener(int, const char *, unsigned int);
extern void listener_release(struct Listener *);
extern void close_listeners(void);
extern const char *get_listener_name(const struct Listener *const);
extern void show_ports(struct Client *);
extern void free_listener(struct Listener *);
#endif
