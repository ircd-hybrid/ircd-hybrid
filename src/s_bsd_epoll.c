/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2005-2018 ircd-hybrid development team
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
#include "memory.h"
#include <sys/epoll.h>

enum
{
  INITIAL_NEVENT =   16,
  MAXIMUM_NEVENT = 4096
};

struct epollop
{
  struct epoll_event *events;
  int nevents;
  int fd;
};

static struct epollop *epollop;


/*
 * comm_select_init
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
comm_select_init(void)
{
  int fd = epoll_create1(EPOLL_CLOEXEC);
  if (fd < 0)
  {
    ilog(LOG_TYPE_IRCD, "comm_select_init: couldn't open epoll fd: %s",
         strerror(errno));
    exit(EXIT_FAILURE); /* Whee! */
  }

  fd_open(fd, false, "epoll file descriptor");

  epollop = xcalloc(sizeof(*epollop));
  epollop->fd = fd;
  epollop->nevents = INITIAL_NEVENT;
  epollop->events = xcalloc(epollop->nevents * sizeof(*epollop->events));
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
  int new_events, op;
  struct epoll_event ep_event;

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

  new_events = (F->read_handler ? EPOLLIN : 0) |
    (F->write_handler ? EPOLLOUT : 0);

  if (timeout)
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

    memset(&ep_event, 0, sizeof(ep_event));
    ep_event.events = F->evcache = new_events;
    ep_event.data.ptr = F;

    if (epoll_ctl(epollop->fd, op, F->fd, &ep_event))
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
  int num;
  void (*hdl)(fde_t *, void *);

  num = epoll_wait(epollop->fd, epollop->events, epollop->nevents, SELECT_DELAY);
  assert(num <= epollop->nevents);

  set_time();

  if (num < 0)
  {
    const struct timespec req = { .tv_sec = 0, .tv_nsec = 50000000 };
    nanosleep(&req, NULL);  /* Avoid 99% CPU in comm_select */
    return;
  }

  for (int i = 0; i < num; ++i)
  {
    fde_t *F = epollop->events[i].data.ptr;

    if (F->flags.open == false)
      continue;

    if ((epollop->events[i].events & (EPOLLIN | EPOLLHUP | EPOLLERR)))
    {
      if ((hdl = F->read_handler))
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);

        if (F->flags.open == false)
          continue;
      }
    }

    if ((epollop->events[i].events & (EPOLLOUT | EPOLLHUP | EPOLLERR)))
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

  if (num == epollop->nevents && epollop->nevents < MAXIMUM_NEVENT)
  {
    /*
     * We used all of the event space this time. We should be
     * ready for more events next time.
     */
    int new_nevents = epollop->nevents * 2;
    struct epoll_event *new_events = xrealloc(epollop->events, new_nevents * sizeof(*epollop->events));

    epollop->events = new_events;
    epollop->nevents = new_nevents;
  }
}
#endif
