/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "list.h"
#include "rng_mt.h"
#include "io_time.h"
#include "event.h"


static list_t event_list;

const list_t *
event_get_list(void)
{
  return &event_list;
}

void
event_add(struct event *ev, void *data)
{
  event_delete(ev);

  ev->data = data;
  ev->next = io_time_get(IO_TIME_MONOTONIC_SEC) + ev->when;
  ev->active = true;

  list_node_t *node;
  LIST_FOREACH(node, event_list.head)
  {
    struct event *e = node->data;

    if (e->next > ev->next)
    {
      list_add_before(node, ev, &ev->node, &event_list);
      return;
    }
  }

  list_add_tail(ev, &ev->node, &event_list);
}

void
event_addish(struct event *ev, void *data)
{
  if (ev->when >= 3)
  {
    const uintmax_t two_third = (2 * ev->when) / 3;

    ev->when = two_third + ((genrand_int32() % 1000) * two_third) / 1000;
  }

  event_add(ev, data);
}

void
event_delete(struct event *ev)
{
  if (ev->active == false)
    return;

  list_remove(&ev->node, &event_list);
  ev->active = false;
}

void
event_run(void)
{
  static uintmax_t last = 0;

  if (last == io_time_get(IO_TIME_MONOTONIC_SEC))
    return;
  last = io_time_get(IO_TIME_MONOTONIC_SEC);

  unsigned int len = list_length(&event_list);
  while (len-- && list_length(&event_list))
  {
    struct event *ev = event_list.head->data;

    if (ev->next > io_time_get(IO_TIME_MONOTONIC_SEC))
      break;

    event_delete(ev);

    ev->handler(ev->data);

    if (ev->oneshot == false)
      event_add(ev, ev->data);
  }
}
