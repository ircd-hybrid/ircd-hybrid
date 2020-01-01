/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2020 ircd-hybrid development team
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
#include "rng_mt.h"
#include "log.h"


struct event_base ebase;
struct event_base *event_base = &ebase;

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
  ev->next = event_base->time.sec_monotonic + ev->when;
  ev->active = true;

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

  dlinkDelete(&ev->node, &event_list);
  ev->active = false;
}

void
event_run(void)
{
  static uintmax_t last = 0;

  if (last == event_base->time.sec_monotonic)
    return;
  last = event_base->time.sec_monotonic;

  unsigned int len = dlink_list_length(&event_list);
  while (len-- && dlink_list_length(&event_list))
  {
    struct event *ev = event_list.head->data;

    if (ev->next > event_base->time.sec_monotonic)
      break;

    event_delete(ev);

    ev->handler(ev->data);

    if (ev->oneshot == false)
      event_add(ev, ev->data);
  }
}

void
event_time_set(void)
{
  struct timespec newtime;

  if (clock_gettime(CLOCK_REALTIME, &newtime))
    exit(EXIT_FAILURE);
  else if (event_base->time.sec_real > (uintmax_t)newtime.tv_sec)
    ilog(LOG_TYPE_IRCD, "System clock is running backwards - (%ju < %ju)",
         (uintmax_t)newtime.tv_sec, event_base->time.sec_real);
  event_base->time.sec_real = newtime.tv_sec;

#ifdef CLOCK_MONOTONIC_RAW
  if (clock_gettime(CLOCK_MONOTONIC_RAW, &newtime) == 0)
#else
  if (clock_gettime(CLOCK_MONOTONIC, &newtime) == 0)
#endif
    event_base->time.sec_monotonic = newtime.tv_sec;
  else
    exit(EXIT_FAILURE);
}
