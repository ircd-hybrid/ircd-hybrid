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
  dlink_node       node;      /* list node pointer */
  fde_t            fd;                 /* file descriptor */
  int              port;               /* listener IP port */
  int              ref_count;          /* number of connection references */
  int              active;             /* current state of listener */
  struct irc_ssaddr addr;              /* virtual address or INADDR_ANY */
  char              name[HOSTLEN + 1]; /* virtual name of listener */
  unsigned int      flags;
};

extern void add_listener(int, const char *, unsigned int);
extern void close_listeners(void);
extern const char *get_listener_name(const struct Listener *const);
extern void show_ports(struct Client *);
extern void free_listener(struct Listener *);
#endif /* INCLUDED_listener_h */
