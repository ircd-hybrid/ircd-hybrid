/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2015 ircd-hybrid development team
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

/*! \file event.h
 * \brief Timer based event execution
 * \version $Id$
 */

#ifndef INCLUDED_event_h
#define INCLUDED_event_h

#include "list.h"

struct event
{
  /* public */
  const char *name;
  void (*handler)(void *);
  time_t when;
  unsigned int oneshot;

  /* private */
  time_t next;
  void *data;
  unsigned int enabled;
  dlink_node node;
};

extern const dlink_list *event_get_list(void);
extern void event_add(struct event *, void *);
extern void event_addish(struct event *, void *);
extern void event_delete(struct event *);
extern void event_run(void);
extern void set_back_events(time_t);
#endif /* INCLUDED_event_h */
