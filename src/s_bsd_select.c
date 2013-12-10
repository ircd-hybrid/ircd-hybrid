/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_bsd_select.c: select() compatible network routines.
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
#if USE_IOPOLL_MECHANISM == __IOPOLL_MECHANISM_SELECT
#include "list.h"
#include "fdlist.h"
#include "hook.h"
#include "ircd.h"
#include "s_bsd.h"
#include "log.h"

/*
 * Note that this is only a single list - multiple lists is kinda pointless
 * under select because the list size is a function of the highest FD :-)
 *   -- adrian
 */

static fd_set select_readfds, tmpreadfds;
static fd_set select_writefds, tmpwritefds;
static int highest_fd = -1;


/*
 * init_netio
 *
 * This is a needed exported function which will be called to initialise
 * the network loop code.
 */
void
init_netio(void)
{
  FD_ZERO(&select_readfds);
  FD_ZERO(&select_writefds);
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

  new_events = (F->read_handler ? COMM_SELECT_READ : 0) |
               (F->write_handler ? COMM_SELECT_WRITE : 0);

  if (timeout != 0)
    F->timeout = CurrentTime + (timeout / 1000);

  if (new_events != F->evcache)
  {
    if ((new_events & COMM_SELECT_READ))
      FD_SET(F->fd, &select_readfds);
    else
    {
      FD_CLR(F->fd, &select_readfds);
      FD_CLR(F->fd, &tmpreadfds);
    }

    if ((new_events & COMM_SELECT_WRITE))
      FD_SET(F->fd, &select_writefds);
    else
    {
      FD_CLR(F->fd, &select_writefds);
      FD_CLR(F->fd, &tmpwritefds);
    }

    if (new_events == 0)
    {
      if (highest_fd == F->fd)
        while (highest_fd >= 0 && (FD_ISSET(highest_fd, &select_readfds) ||
                                   FD_ISSET(highest_fd, &select_writefds)))
          highest_fd--;
    }
    else if (F->evcache == 0)
      if (F->fd > highest_fd)
        highest_fd = F->fd;

    F->evcache = new_events;
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
  struct timeval to;
  int num, fd;
  fde_t *F;
  PF *hdl;

  /* Copy over the read/write sets so we don't have to rebuild em */
  memcpy(&tmpreadfds, &select_readfds, sizeof(fd_set));
  memcpy(&tmpwritefds, &select_writefds, sizeof(fd_set));

  to.tv_sec = 0;
  to.tv_usec = SELECT_DELAY * 1000;
  num = select(highest_fd + 1, &tmpreadfds, &tmpwritefds, NULL, &to);

  set_time();

  if (num < 0)
  {
#ifdef HAVE_USLEEP
    usleep(50000);
#endif
    return;
  }

  for (fd = 0; fd <= highest_fd && num > 0; fd++)
  {
    if (FD_ISSET(fd, &tmpreadfds) || FD_ISSET(fd, &tmpwritefds))
    {
      num--;

      F = lookup_fd(fd);
      if (F == NULL || !F->flags.open)
        continue;

      if (FD_ISSET(fd, &tmpreadfds))
      {
        if ((hdl = F->read_handler) != NULL)
        {
          F->read_handler = NULL;
          hdl(F, F->read_data);
          if (!F->flags.open)
            continue;
        }
      }

      if (FD_ISSET(fd, &tmpwritefds))
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
}
#endif
