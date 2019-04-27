/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2019 ircd-hybrid development team
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

/*! \file s_bsd_kqueue.c
 * \brief kqueue() compatible network routines.
 * \version $Id$
 */

#include "stdinc.h"
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_KQUEUE
#include <sys/event.h>
#include "fdlist.h"
#include "ircd.h"
#include "s_bsd.h"
#include "log.h"

enum { KE_LENGTH = 128 };

static int kqueue_fd;
static struct kevent kq_fdlist[KE_LENGTH];  /* kevent buffer */
static int kqoff;      /* offset into the buffer */


/*
 * comm_select_init
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
comm_select_init(void)
{
  if ((kqueue_fd = kqueue()) < 0)
  {
    ilog(LOG_TYPE_IRCD, "comm_select_init: couldn't open kqueue fd: %s",
         strerror(errno));
    exit(EXIT_FAILURE); /* Whee! */
  }

  fd_open(kqueue_fd, false, "kqueue() file descriptor");
}

/*
 * Write a single update to the kqueue list.
 */
static void
kq_update_events(fde_t *F, int filter, int what)
{
  const struct timespec zero_timespec = { .tv_sec = 0, .tv_nsec = 0 };
  struct kevent *kep = kq_fdlist + kqoff;

  EV_SET(kep, (uintptr_t) F->fd, (short) filter, what, 0, 0, F);

  if (++kqoff == KE_LENGTH)
  {
    int i;

    for (i = 0; i < kqoff; ++i)
      kevent(kqueue_fd, &kq_fdlist[i], 1, NULL, 0, &zero_timespec);
    kqoff = 0;
  }
}

/*
 * comm_setselect
 *
 * This is a needed exported function which will be called to register
 * and deregister interest in a pending IO state for a given FD.
 */
void
comm_setselect(fde_t *F, unsigned int type, void (*handler)(fde_t *, void *),
               void *client_data, uintmax_t timeout)
{
  int new_events, diff;

  assert(F);
  assert(F->flags.open == true);

  if ((type & COMM_SELECT_READ))
  {
    F->read_handler = handler;
    F->read_data = client_data;
  }

  if ((type & COMM_SELECT_WRITE))
  {
    F->write_handler = handler;
    F->write_data = client_data;
  }

  new_events = (F->read_handler ? COMM_SELECT_READ : 0) |
               (F->write_handler ? COMM_SELECT_WRITE : 0);

  if (timeout)
  {
    F->timeout = event_base->time.sec_monotonic + timeout;
    F->timeout_handler = handler;
    F->timeout_data = client_data;
  }

  diff = new_events ^ F->evcache;

  if ((diff & COMM_SELECT_READ))
    kq_update_events(F, EVFILT_READ, (new_events & COMM_SELECT_READ) ? EV_ADD : EV_DELETE);
  if ((diff & COMM_SELECT_WRITE))
    kq_update_events(F, EVFILT_WRITE, (new_events & COMM_SELECT_WRITE) ? EV_ADD : EV_DELETE);

  F->evcache = new_events;
}

/*
 * comm_select
 *
 * Called to do the new-style IO, courtesy of squid (like most of this
 * new IO code). This routine handles the stuff we've hidden in
 * comm_setselect and fd_table[] and calls callbacks for IO ready
 * events.
 */
void
comm_select(void)
{
  int num;
  static struct kevent ke[KE_LENGTH];
  struct timespec poll_time;
  void (*hdl)(fde_t *, void *);

  /*
   * remember we are doing NANOseconds here, not micro/milli. God knows
   * why jlemon used a timespec, but hey, he wrote the interface, not I
   *   -- Adrian
   */
  poll_time.tv_sec = 0;
  poll_time.tv_nsec = SELECT_DELAY * 1000000;
  num = kevent(kqueue_fd, kq_fdlist, kqoff, ke, KE_LENGTH, &poll_time);
  kqoff = 0;

  event_time_set();

  if (num < 0)
  {
    const struct timespec req = { .tv_sec = 0, .tv_nsec = 50000000 };
    nanosleep(&req, NULL);  /* Avoid 99% CPU in comm_select */
    return;
  }

  for (int i = 0; i < num; ++i)
  {
    fde_t *F = ke[i].udata;

    if (F->flags.open == false || (ke[i].flags & EV_ERROR))
      continue;

    if (ke[i].filter == EVFILT_READ)
    {
      if ((hdl = F->read_handler))
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);

        if (F->flags.open == false)
          continue;
      }
    }

    if (ke[i].filter == EVFILT_WRITE)
    {
      if ((hdl = F->write_handler))
      {
        F->write_handler = NULL;
        hdl(F, F->write_data);

        if (F->flags.open == false)
          continue;
      }
    }

    comm_setselect(F, 0, NULL, NULL, 0);
  }
}
#endif
