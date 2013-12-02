/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd_kqueue.c: FreeBSD kqueue compatible network routines.
 *
 *  Originally by Adrian Chadd <adrian@creative.net.au>
 *  Copyright (C) 2005 Hybrid Development Team
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

#include "stdinc.h"
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_KQUEUE
#include <sys/event.h>
#include "fdlist.h"
#include "ircd.h"
#include "memory.h"
#include "s_bsd.h"
#include "log.h"

#define KE_LENGTH 128

/* jlemon goofed up and didn't add EV_SET until fbsd 4.3 */

#ifndef EV_SET
#define EV_SET(kevp, a, b, c, d, e, f) do {     \
        (kevp)->ident = (a);                    \
        (kevp)->filter = (b);                   \
        (kevp)->flags = (c);                    \
        (kevp)->fflags = (d);                   \
        (kevp)->data = (e);                     \
        (kevp)->udata = (f);                    \
} while(0)
#endif

static fde_t kqfd;
static struct kevent kq_fdlist[KE_LENGTH];  /* kevent buffer */
static int kqoff;      /* offset into the buffer */

/*
 * init_netio
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
init_netio(void)
{
  int fd;

  if ((fd = kqueue()) < 0)
  {
    ilog(LOG_TYPE_IRCD, "init_netio: Couldn't open kqueue fd!");
    exit(115); /* Whee! */
  }

  fd_open(&kqfd, fd, 0, "kqueue() file descriptor");
}

/*
 * Write a single update to the kqueue list.
 */
static void
kq_update_events(int fd, int filter, int what)
{
  static struct timespec zero_timespec = {0, 0};
  struct kevent *kep = kq_fdlist + kqoff;

  EV_SET(kep, (uintptr_t) fd, (short) filter, what, 0, 0, NULL);

  if (++kqoff == KE_LENGTH)
  {
    int i;

    for (i = 0; i < kqoff; ++i)
      kevent(kqfd.fd, &kq_fdlist[i], 1, NULL, 0, &zero_timespec);
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
comm_setselect(fde_t *F, unsigned int type, PF *handler,
               void *client_data, time_t timeout)
{
  int new_events, diff;

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

  if (timeout != 0)
    F->timeout = CurrentTime + (timeout / 1000);

  diff = new_events ^ F->evcache;

  if ((diff & COMM_SELECT_READ))
    kq_update_events(F->fd, EVFILT_READ,
      (new_events & COMM_SELECT_READ) ? EV_ADD : EV_DELETE);
  if ((diff & COMM_SELECT_WRITE))
    kq_update_events(F->fd, EVFILT_WRITE,
      (new_events & COMM_SELECT_WRITE) ? EV_ADD : EV_DELETE);

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
  int num, i;
  static struct kevent ke[KE_LENGTH];
  struct timespec poll_time;
  PF *hdl;
  fde_t *F;

  /*
   * remember we are doing NANOseconds here, not micro/milli. God knows
   * why jlemon used a timespec, but hey, he wrote the interface, not I
   *   -- Adrian
   */
  poll_time.tv_sec = 0;
  poll_time.tv_nsec = SELECT_DELAY * 1000000;
  num = kevent(kqfd.fd, kq_fdlist, kqoff, ke, KE_LENGTH, &poll_time);
  kqoff = 0;

  set_time();

  if (num < 0)
  {
#ifdef HAVE_USLEEP
    usleep(50000);  /* avoid 99% CPU in comm_select */
#endif
    return;
  }

  for (i = 0; i < num; i++)
  {
    F = lookup_fd(ke[i].ident);
    if (F == NULL || !F->flags.open || (ke[i].flags & EV_ERROR))
      continue;

    if (ke[i].filter == EVFILT_READ)
      if ((hdl = F->read_handler) != NULL)
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);
        if (!F->flags.open)
          continue;
      }

    if (ke[i].filter == EVFILT_WRITE)
      if ((hdl = F->write_handler) != NULL)
      {
        F->write_handler = NULL;
        hdl(F, F->write_data);
        if (!F->flags.open)
          continue;
      }

    comm_setselect(F, 0, NULL, NULL, 0);
  }
}
#endif
