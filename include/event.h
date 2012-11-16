/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.h: The ircd event header.
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

#ifndef INCLUDED_event_h
#define INCLUDED_event_h
#include "client.h"

/*
 * How many event entries we need to allocate at a time in the block
 * allocator. 16 should be plenty at a time.
 */
#define	MAX_EVENTS	50


typedef void EVH(void *);

/* The list of event processes */
struct ev_entry
{
  EVH *func;
  void *arg;
  const char *name;
  time_t frequency;
  time_t when;
  int active;
};

extern void eventAdd(const char *, EVH *, void *, time_t);
extern void eventAddIsh(const char *, EVH *, void *, time_t);
extern void eventRun(void);
extern time_t eventNextTime(void);
extern void eventInit(void);
extern void eventDelete(EVH *, void *);
extern void set_back_events(time_t);
extern void show_events(struct Client *);

#endif /* INCLUDED_event_h */
