/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2021 ircd-hybrid development team
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

#include "fdlist.h"

enum
{
  LISTENER_TLS    = 1 << 0,
  LISTENER_HIDDEN = 1 << 1,
  LISTENER_SERVER = 1 << 2,
  LISTENER_CLIENT = 1 << 3,
  LISTENER_DEFER  = 1 << 4
};

struct Listener
{
  dlink_node node;  /**< Doubly linked list node */
  bool active;  /**< Current state of listener */
  fde_t *fd;  /**< File descriptor */
  int port;  /**< Listener IP port */
  int ref_count;  /**< Number of connection references */
  struct irc_ssaddr addr;  /**< Holds an IPv6 or IPv4 address */
  char *name;  /**< Holds an IPv6 or IPv4 address in string representation*/
  unsigned int flags;  /**< Listener flags (tls, hidden, server, client, defer) */
};

extern const dlink_list *listener_get_list(void);
extern void listener_add(int, const char *, unsigned int);
extern void listener_release(struct Listener *);
extern void listener_close_marked(void);
extern const char *listener_get_name(const struct Listener *);
extern bool listener_has_flag(const struct Listener *, unsigned int);
extern void listener_count_memory(unsigned int *, size_t *);
#endif  /* INCLUDED_listener_h */
