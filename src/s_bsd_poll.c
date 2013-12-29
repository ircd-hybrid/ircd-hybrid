/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd_poll.c: POSIX poll() compatible network routines.
 *
 *  Originally by Adrian Chadd <adrian@creative.net.au>
 *  Copyright (C) 2002 Hybrid Development Team
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
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_POLL
#include <sys/poll.h>
#include "fdlist.h"
#include "list.h"
#include "memory.h"
#include "hook.h"
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

static struct pollfd *pollfds;
static int pollmax = -1;  /* highest FD number */


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

  pollfds = MyMalloc(sizeof(struct pollfd) * hard_fdlimit);

  for (fd = 0; fd < hard_fdlimit; fd++)
    pollfds[fd].fd = -1;
}

/*
 * find a spare slot in the fd list. We can optimise this out later!
 *   -- adrian
 */
static inline int
poll_findslot(void)
{
  int i;

  for (i = 0; i < hard_fdlimit; i++)
    if (pollfds[i].fd == -1)
    {
      /* MATCH!!#$*&$ */
      return i;
    }

  assert(1 == 0);
  /* NOTREACHED */
  return -1;
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
      pollfds[F->comm_index].fd = -1;
      pollfds[F->comm_index].revents = 0;

      if (pollmax == F->comm_index)
        while (pollmax >= 0 && pollfds[pollmax].fd == -1)
          pollmax--;
    }
    else
    {
      if (F->evcache == 0)
      {
        F->comm_index = poll_findslot();
        if (F->comm_index > pollmax)
          pollmax = F->comm_index;

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
  int num, ci, revents;
  PF *hdl;
  fde_t *F;

  /* XXX kill that +1 later ! -- adrian */
  num = poll(pollfds, pollmax + 1, SELECT_DELAY);

  set_time();

  if (num < 0)
  {
#ifdef HAVE_USLEEP
    usleep(50000);  /* avoid 99% CPU in comm_select */
#endif
    return;
  }

  for (ci = 0; ci <= pollmax && num > 0; ci++)
  {
    if ((revents = pollfds[ci].revents) == 0 || pollfds[ci].fd == -1)
      continue;
    num--;

    F = lookup_fd(pollfds[ci].fd);
    if (F == NULL || !F->flags.open)
      continue;

    if (revents & (POLLRDNORM | POLLIN | POLLHUP | POLLERR))
    {
      if ((hdl = F->read_handler) != NULL)
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);
        if (!F->flags.open)
          continue;
      }
    }

    if (revents & (POLLWRNORM | POLLOUT | POLLHUP | POLLERR))
    {
      if ((hdl = F->write_handler) != NULL)
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
