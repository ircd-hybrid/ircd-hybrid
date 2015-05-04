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

/*! \file s_bsd_poll.c
 * \brief POSIX poll() compatible network routines.
 * \version $Id$
 */

#include "stdinc.h"
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_POLL
#include <sys/poll.h>
#include "fdlist.h"
#include "list.h"
#include "memory.h"
#include "ircd.h"
#include "s_bsd.h"
#include "log.h"

/* I hate linux -- adrian */
#ifndef POLLRDNORM
#define POLLRDNORM POLLIN
#endif
#ifndef POLLWRNORM
#define POLLWRNORM POLLOUT
#endif

static int pollfds_size;
static struct pollfd *pollfds;
static int pollnum;


/*
 * init_netio
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
init_netio(void)
{
  pollfds_size = hard_fdlimit;
  pollfds = MyCalloc(sizeof(struct pollfd) * pollfds_size);
}

/*
 * comm_setselect
 *
 * This is a needed exported function which will be called to register
 * and deregister interest in a pending IO state for a given FD.
 */
void
comm_setselect(fde_t *F, unsigned int type, void (*handler)(fde_t *, void *),
               void *client_data, time_t timeout)
{
  int new_events;

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

  new_events = (F->read_handler ? POLLRDNORM : 0) |
               (F->write_handler ? POLLWRNORM : 0);

  if (timeout != 0)
  {
    F->timeout = CurrentTime + (timeout / 1000);
    F->timeout_handler = handler;
    F->timeout_data = client_data;
  }

  if (new_events != F->evcache)
  {
    if (new_events == 0)
    {
      if (F->comm_index != pollnum - 1)
      {
        fde_t *other = lookup_fd(pollfds[pollnum - 1].fd);

        pollfds[F->comm_index].fd = pollfds[pollnum - 1].fd;
        pollfds[F->comm_index].events = pollfds[pollnum - 1].events;
        pollfds[F->comm_index].revents = pollfds[pollnum - 1].revents;

        assert(other);
        other->comm_index = F->comm_index;
      }

      F->comm_index = -1;
      --pollnum;
    }
    else
    {
      if (F->evcache == 0)
      {
        if (pollnum >= pollfds_size)
        {
          pollfds_size *= 2;
          pollfds = MyRealloc(pollfds, sizeof(struct pollfd) * pollfds_size);
        }

        F->comm_index = pollnum++;
        pollfds[F->comm_index].fd = F->fd;
      }

      pollfds[F->comm_index].events = new_events;
      pollfds[F->comm_index].revents = 0;
    }

    F->evcache = new_events;
  }
}

/*
 * comm_select
 *
 * Called to do the new-style IO, courtesy of of squid (like most of this
 * new IO code). This routine handles the stuff we've hidden in
 * comm_setselect and fd_table[] and calls callbacks for IO ready
 * events.
 */
void
comm_select(void)
{
  int num, ci;
  void (*hdl)(fde_t *, void *);
  fde_t *F;

  num = poll(pollfds, pollnum, SELECT_DELAY);

  set_time();

  if (num < 0)
  {
#ifdef HAVE_USLEEP
    usleep(50000);  /* avoid 99% CPU in comm_select */
#endif
    return;
  }

  for (ci = 0; ci < pollnum && num > 0; ci++)
  {
    int revents = pollfds[ci].revents;

    if (revents == 0)
      continue;
    num--;

    F = lookup_fd(pollfds[ci].fd);
    assert(F);
    if (!F->flags.open)
      continue;

    if (revents & (POLLRDNORM | POLLIN | POLLHUP | POLLERR))
    {
      if ((hdl = F->read_handler))
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);
        if (!F->flags.open)
          continue;
      }
    }

    if (revents & (POLLWRNORM | POLLOUT | POLLHUP | POLLERR))
    {
      if ((hdl = F->write_handler))
      {
        F->write_handler = NULL;
        hdl(F, F->write_data);
        if (!F->flags.open)
          continue;
      }
    }

    comm_setselect(F, 0, NULL, NULL, 0);
  }
}
#endif
