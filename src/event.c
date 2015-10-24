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

/*! \file event.c
 * \brief Timer based event execution
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "event.h"
#include "client.h"
#include "send.h"
#include "numeric.h"
#include "rng_mt.h"


static dlink_list event_list;

const dlink_list *
event_get_list(void)
{
  return &event_list;
}

void
event_add(struct event *ev, void *data)
{
  dlink_node *node;

  event_delete(ev);

  ev->data = data;
  ev->next = CurrentTime + ev->when;
  ev->active = 1;

  DLINK_FOREACH(node, event_list.head)
  {
    struct event *e = node->data;

    if (e->next > ev->next)
    {
      dlinkAddBefore(node, ev, &ev->node, &event_list);
      return;
    }
  }

  dlinkAddTail(ev, &ev->node, &event_list);
}

void
event_addish(struct event *ev, void *data)
{
  if (ev->when >= 3)
  {
    const time_t two_third = (2 * ev->when) / 3;

    ev->when = two_third + ((genrand_int32() % 1000) * two_third) / 1000;
  }

  event_add(ev, data);
}

void
event_delete(struct event *ev)
{
  if (!ev->active)
    return;

  dlinkDelete(&ev->node, &event_list);
  ev->active = 0;
}

void
event_run(void)
{
  static time_t last = 0;
  unsigned int len = 0;

  if (last == CurrentTime)
    return;
  last = CurrentTime;

  len = dlink_list_length(&event_list);
  while (len-- && dlink_list_length(&event_list))
  {
    struct event *e = event_list.head->data;

    if (e->next > CurrentTime)
      break;

    event_delete(e);

    e->handler(e->data);

    if (!e->oneshot)
      event_add(e, e->data);
  }
}

/*
 * void event_set_back_events(time_t by)
 * Input: Time to set back events by.
 * Output: None.
 * Side-effects: Sets back all events by "by" seconds.
 */
void
event_set_back_events(time_t by)
{
  dlink_node *node;

  DLINK_FOREACH(node, event_list.head)
  {
    struct event *ev = node->data;
    ev->next -= by;
  }
}
