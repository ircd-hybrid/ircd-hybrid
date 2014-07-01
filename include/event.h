/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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

/*! \file event.h
 * \brief Timer based event execution
 * \version $Id$
 */

#ifndef INCLUDED_event_h
#define INCLUDED_event_h

#include "list.h"

struct Client;
struct event;

typedef void (*event_handler)(void *);

struct event
{
  /* public */
  const char *name;
  event_handler handler;
  time_t when;
  unsigned short oneshot;

  /* private */
  time_t next;
  void *data;
  unsigned short enabled;
  dlink_node node;
};

extern void event_add(struct event *ev, void *data);
extern void event_addish(struct event *ev, void *data);
extern void event_delete(struct event *ev);
extern void event_run(void);
extern void set_back_events(time_t);
extern void show_events(struct Client *);
#endif /* INCLUDED_event_h */
