/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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
 */

#ifndef INCLUDED_listener_h
#define INCLUDED_listener_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "address.h"
#include "fdlist.h"
#include "list.h"

/** Listener flags */
typedef enum
{
  LISTENER_TLS    = 1 << 0,  /**< Listener accepts only TLS connections */
  LISTENER_HIDDEN = 1 << 1,  /**< Listener doesn't show up in '/stats P', except for server administrators */
  LISTENER_SERVER = 1 << 2,  /**< Listener accepts only server connections */
  LISTENER_CLIENT = 1 << 3,  /**< Listener accepts only client connections */
  LISTENER_DEFER  = 1 << 4,  /**< Listener has the TCP_DEFER_ACCEPT/SO_ACCEPTFILTER socket option enabled */
} listener_flag_t;

/** Entry for a single listener/port */
struct Listener
{
  list_node_t node;  /**< List node; linked into listener_list */
  struct io_addr addr;  /**< Holds an IPv6 or IPv4 address */
  char *name;  /**< Holds an IPv6 or IPv4 address in string representation */
  listener_flag_t flags;  /**< Listener flags (tls, hidden, server, client, defer) */
  fde_t *fd;  /**< File descriptor (NULL if inactive) */
  unsigned int ref_count;  /**< Number of connection references */
};

extern void listener_add(uint16_t, const char *, listener_flag_t);
extern void listener_release(struct Listener *);
extern void listener_close_marked(void);
extern void listener_count_memory(unsigned int *, size_t *);
extern const list_t *listener_get_list(void);

static inline const char *
listener_get_name(const struct Listener *listener)
{
  return listener->name;
}

static inline uint16_t
listener_get_port(const struct Listener *listener)
{
  return address_get_port(&listener->addr);
}

static inline bool
listener_has_flag(const struct Listener *listener, listener_flag_t flags)
{
  return listener && (listener->flags & flags);
}

static inline bool
listener_is_active(const struct Listener *listener)
{
  return listener->fd && listener->fd->flags.open;
}
#endif  /* INCLUDED_listener_h */
