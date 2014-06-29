/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  event.c: Event functions.
 *
 *  Copyright (c) 1998-2000 Regents of the University of California
 *  Copyright (c) 2000-2014 ircd-hybrid development team
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd.h"
#include "event.h"
#include "client.h"
#include "send.h"
#include "memory.h"
#include "log.h"
#include "numeric.h"
#include "rng_mt.h"

static dlink_list events;

void
event_add(struct event *ev, void *data)
{
  dlink_node *node;

  event_delete(ev);

  ev->data = data;
  ev->next = CurrentTime + ev->when;
  ev->enabled = 1;

  DLINK_FOREACH(node, events.head)
  {
    struct event *e = node->data;

    if (e->next > ev->next)
    {
      dlinkAddBefore(node, ev, &ev->node, &events);
      return;
    }
  }

  dlinkAddTail(ev, &ev->node, &events);
}

void
event_addish(struct event *ev, void *data)
{
  if (ev->when >= 3)
  {
    const time_t two_third = (2 * ev->when) / 3;
    ev->when = two_third + ((genrand_int32() % 1000) * two_third) / 1000;
      /*
       * XXX I hate the above magic, I don't even know if its right.
       * Grr. -- adrian
       */
  }

  event_add(ev, data);
}

void
event_delete(struct event *ev)
{
  if (!ev->enabled)
    return;

  dlinkDelete(&ev->node, &events);
  ev->enabled = 0;
}

void
event_run(void)
{
  static time_t last = 0;
  dlink_node *node = NULL;
  size_t len = 0;

  if (last == CurrentTime)
    return;
  last = CurrentTime;

  len = dlink_list_length(&events);
  while (len-- && dlink_list_length(&events))
  {
    struct event *e = events.head->data;

    if (e->when > CurrentTime)
      break;

    event_delete(e);

    e->handler(e->data);

    if (!e->oneshot)
      event_add(e, e->data);
  }
}

/*
 * void set_back_events(time_t by)
 * Input: Time to set back events by.
 * Output: None.
 * Side-effects: Sets back all events by "by" seconds.
 */
void
set_back_events(time_t by)
{
  dlink_node *node;

  DLINK_FOREACH(node, events.head)
  {
    struct event *ev = node->data;
    ev->next -= by;
  }
}

/*
 * void show_events(struct Client *source_p)
 *
 * Input: Client requesting the event
 * Output: List of events
 * Side Effects: None
 */
void
show_events(struct Client *source_p)
{
  const dlink_node *node;

  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "E :Operation                    Next Execution");
  sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                     "E :-------------------------------------------");

  DLINK_FOREACH(node, events.head)
  {
    const struct event *ev = node->data;

    sendto_one_numeric(source_p, &me, RPL_STATSDEBUG|SND_EXPLICIT,
                       "E :%-28s %-4d seconds",
                       ev->name,
                       (int)(ev->next - CurrentTime));
  }
}

