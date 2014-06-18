/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2005-2014 ircd-hybrid development team
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

/*! \file s_bsd_epoll.c
 * \brief Linux epoll() compatible network routines.
 * \version $Id$
 */

#include "stdinc.h"
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_EPOLL
#include "fdlist.h"
#include "ircd.h"
#include "s_bsd.h"
#include "log.h"
#include <sys/epoll.h>
#include <sys/syscall.h>

static fde_t efd;


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

  if ((fd = epoll_create(hard_fdlimit)) < 0)
  {
    ilog(LOG_TYPE_IRCD, "init_netio: Couldn't open epoll fd - %d: %s",
         errno, strerror(errno));
    exit(115); /* Whee! */
  }

  fd_open(&efd, fd, 0, "epoll file descriptor");
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
  int new_events, op;
  struct epoll_event ep_event = { 0, { 0 } };

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

  new_events = (F->read_handler ? EPOLLIN : 0) |
    (F->write_handler ? EPOLLOUT : 0);

  if (timeout != 0)
  {
    F->timeout = CurrentTime + (timeout / 1000);
    F->timeout_handler = handler;
    F->timeout_data = client_data;
  }

  if (new_events != F->evcache)
  {
    if (new_events == 0)
      op = EPOLL_CTL_DEL;
    else if (F->evcache == 0)
      op = EPOLL_CTL_ADD;
    else
      op = EPOLL_CTL_MOD;

    ep_event.events = F->evcache = new_events;
    ep_event.data.fd = F->fd;

    if (epoll_ctl(efd.fd, op, F->fd, &ep_event) != 0)
    {
      ilog(LOG_TYPE_IRCD, "comm_setselect: epoll_ctl() failed: %s", strerror(errno));
      abort();
    }
  }
}

/*
 * comm_select()
 *
 * Called to do the new-style IO, courtesy of of squid (like most of this
 * new IO code). This routine handles the stuff we've hidden in
 * comm_setselect and fd_table[] and calls callbacks for IO ready
 * events.
 */
void
comm_select(void)
{
  struct epoll_event ep_fdlist[128];
  int num, i;
  PF *hdl;
  fde_t *F;

  num = epoll_wait(efd.fd, ep_fdlist, 128, SELECT_DELAY);

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
    F = lookup_fd(ep_fdlist[i].data.fd);
    if (F == NULL || !F->flags.open)
      continue;

    if ((ep_fdlist[i].events & (EPOLLIN | EPOLLHUP | EPOLLERR)))
    {
      if ((hdl = F->read_handler) != NULL)
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);
        if (!F->flags.open)
          continue;
      }
    }

    if ((ep_fdlist[i].events & (EPOLLOUT | EPOLLHUP | EPOLLERR)))
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
