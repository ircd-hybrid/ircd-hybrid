/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file s_bsd_poll.c
 * \brief POSIX poll() compatible network routines.
 */

#include "config.h"  /**< Autotools-generated USE_IOPOLL_MECHANISM & AX_IOPOLL_MECHANISM_POLL. */
#if USE_IOPOLL_MECHANISM == AX_IOPOLL_MECHANISM_POLL
#include <assert.h>
#include <poll.h>
#include <time.h>

#include "comm.h"
#include "fdlist.h"
#include "io_time.h"
#include "log.h"
#include "memory.h"

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
 * comm_select_init
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
comm_select_init(void)
{
  pollfds_size = hard_fdlimit;
  pollfds = io_calloc(sizeof(struct pollfd) * pollfds_size);
}

/*
 * comm_setselect
 *
 * This is a needed exported function which will be called to register
 * and deregister interest in a pending IO state for a given FD.
 */
void
comm_setselect(fde_t *F, unsigned int type, void (*handler)(fde_t *, void *), void *client_data)
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

  new_events = (F->read_handler ? POLLRDNORM : 0) | (F->write_handler ? POLLWRNORM : 0);
  if (new_events != F->evcache)
  {
    if (new_events == 0)
    {
      if (F->comm_index != pollnum - 1)
      {
        fde_t *other = &fd_table[pollfds[pollnum - 1].fd];

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
          pollfds = io_realloc(pollfds, sizeof(struct pollfd) * pollfds_size);
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
comm_select(int timeout_ms)
{
  int num;
  void (*hdl)(fde_t *, void *);

  num = poll(pollfds, pollnum, timeout_ms);

  io_time_update_cache();

  if (num < 0)
  {
    const struct timespec req = { .tv_sec = 0, .tv_nsec = 50000000 };
    nanosleep(&req, NULL);  /* Avoid 99% CPU in comm_select */
    return;
  }

  for (int ci = 0; ci < pollnum && num > 0; ++ci)
  {
    int revents = pollfds[ci].revents;
    if (revents == 0)
      continue;

    --num;

    fde_t *F = &fd_table[pollfds[ci].fd];

    if (F->flags.open == false)
      continue;

    if (revents & (POLLRDNORM | POLLIN | POLLHUP | POLLERR))
    {
      if ((hdl = F->read_handler))
      {
        F->read_handler = NULL;
        hdl(F, F->read_data);

        if (F->flags.open == false)
          continue;
      }
    }

    if (revents & (POLLWRNORM | POLLOUT | POLLHUP | POLLERR))
    {
      if ((hdl = F->write_handler))
      {
        F->write_handler = NULL;
        hdl(F, F->write_data);

        if (F->flags.open == false)
          continue;
      }
    }

    comm_setselect(F, 0, NULL, NULL);
  }
}
#endif
