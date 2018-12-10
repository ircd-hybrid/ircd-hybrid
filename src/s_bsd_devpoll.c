/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2018 ircd-hybrid development team
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

/*! \file s_bsd_devpoll.c
 * \brief /dev/poll compatible network routines.
 * \version $Id$
 */

#include "stdinc.h"
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_DEVPOLL
#include <sys/ioctl.h>
/* HPUX uses devpoll.h and not sys/devpoll.h */
#ifdef HAVE_DEVPOLL_H
# include <devpoll.h>
#else
# ifdef HAVE_SYS_DEVPOLL_H
#  include <sys/devpoll.h>
# else
#  error "No devpoll.h found! Try ./configuring and letting the script choose for you."
# endif
#endif
#include "fdlist.h"
#include "ircd.h"
#include "s_bsd.h"
#include "log.h"

static int devpoll_fd;

/*
 * comm_select_init
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
comm_select_init(void)
{
  if ((devpoll_fd = open("/dev/poll", O_RDWR)) < 0)
  {
    ilog(LOG_TYPE_IRCD, "comm_select_init: couldn't open /dev/poll: %s",
         strerror(errno));
    exit(EXIT_FAILURE); /* Whee! */
  }

  fd_open(devpoll_fd, false, "/dev/poll file descriptor");
}

/*
 * Write an update to the devpoll filter.
 * See, we end up having to do a seperate (?) remove before we do an
 * add of a new polltype, so we have to have this function seperate from
 * the others.
 */
static void
devpoll_write_update(int fd, int events)
{
  struct pollfd pfd;

  /* Build the pollfd entry */
  pfd.revents = 0;
  pfd.fd = fd;
  pfd.events = events;

  /* Write the thing to our poll fd */
  if (write(devpoll_fd, &pfd, sizeof(pfd)) != sizeof(pfd))
    ilog(LOG_TYPE_IRCD, "devpoll_write_update: dpfd write failed %d: %s",
         errno, strerror(errno));
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
  int new_events;

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

  new_events = (F->read_handler ? POLLIN : 0) |
    (F->write_handler ? POLLOUT : 0);

  if (timeout)
  {
    F->timeout = CurrentTime + (timeout / 1000);
    F->timeout_handler = handler;
    F->timeout_data = client_data;
  }

  if (new_events != F->evcache)
  {
    devpoll_write_update(F->fd, POLLREMOVE);
    if ((F->evcache = new_events))
      devpoll_write_update(F->fd, new_events);
  }
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
  struct pollfd pollfds[128];
  struct dvpoll dopoll;
  void (*hdl)(fde_t *, void *);

  dopoll.dp_timeout = SELECT_DELAY;
  dopoll.dp_nfds = 128;
  dopoll.dp_fds = &pollfds[0];
  num = ioctl(devpoll_fd, DP_POLL, &dopoll);

  set_time();

  if (num < 0)
  {
    const struct timespec req = { .tv_sec = 0, .tv_nsec = 50000000 };
    nanosleep(&req, NULL);  /* Avoid 99% CPU in comm_select */
    return;
  }

  for (int i = 0; i < num; ++i)
  {
    fde_t *F = &fd_table[dopoll.dp_fds[i].fd];

    if (F->flags.open == false)
      continue;

    if ((dopoll.dp_fds[i].revents & POLLIN))
    {
      if ((hdl = F->read_handler))
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);

        if (F->flags.open == false)
          continue;
      }
    }

    if ((dopoll.dp_fds[i].revents & POLLOUT))
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
