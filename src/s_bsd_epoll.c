/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd_epoll.c: Linux epoll() compatible network routines.
 *
 *  Copyright (C) 2002-2005 Hybrid Development Team
 *  Based also on work of Adrian Chadd, Aaron Sethman and others.
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
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_EPOLL
#include "fdlist.h"
#include "ircd.h"
#include "memory.h"
#include "s_bsd.h"
#include "log.h"
#include <sys/epoll.h>
#include <sys/syscall.h>

static fde_t efd;

/* Thanks to ircu for the following ifdefs. */

/* The GNU C library may have a valid header but stub implementations
 * of the epoll system calls.  If so, provide our own. */
#if defined(__stub_epoll_create) || defined(__stub___epoll_create) || defined(EPOLL_NEED_BODY)

/* Oh, did we mention that some glibc releases do not even define the
 * syscall numbers? */
#if !defined(__NR_epoll_create)
#if defined(__ia64__)
#define __NR_epoll_create 1243
#define __NR_epoll_ctl 1244
#define __NR_epoll_wait 1245
#elif defined(__x86_64__)
#define __NR_epoll_create 214
#define __NR_epoll_ctl 233
#define __NR_epoll_wait 232
#elif defined(__sparc64__) || defined(__sparc__)
#define __NR_epoll_create 193
#define __NR_epoll_ctl 194
#define __NR_epoll_wait 195
#elif defined(__s390__) || defined(__m68k__)
#define __NR_epoll_create 249
#define __NR_epoll_ctl 250
#define __NR_epoll_wait 251
#elif defined(__ppc64__) || defined(__ppc__)
#define __NR_epoll_create 236
#define __NR_epoll_ctl 237
#define __NR_epoll_wait 238
#elif defined(__parisc__) || defined(__arm26__) || defined(__arm__)
#define __NR_epoll_create 224
#define __NR_epoll_ctl 225
#define __NR_epoll_wait 226
#elif defined(__alpha__)
#define __NR_epoll_create 407
#define __NR_epoll_ctl 408
#define __NR_epoll_wait 409
#elif defined(__sh64__)
#define __NR_epoll_create 282
#define __NR_epoll_ctl 283
#define __NR_epoll_wait 284
#elif defined(__i386__) || defined(__sh__) || defined(__m32r__) || defined(__h8300__) || defined(__frv__)
#define __NR_epoll_create 254
#define __NR_epoll_ctl 255
#define __NR_epoll_wait 256
#else /* cpu types */
#error No system call numbers defined for epoll family.
#endif /* cpu types */
#endif /* !defined(__NR_epoll_create) */

_syscall1(int, epoll_create, int, size)
_syscall4(int, epoll_ctl, int, epfd, int, op, int, fd, struct epoll_event *, event)
_syscall4(int, epoll_wait, int, epfd, struct epoll_event *, pevents, int, maxevents, int, timeout)

#endif /* epoll_create defined as stub */

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
