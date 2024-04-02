/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file fdlist.c
 * \brief Maintains a list of file descriptors.
 */

#include "stdinc.h"
#include "defaults.h"
#include "fdlist.h"
#include "irc_string.h"
#include "s_bsd.h"   /* comm_setselect */
#include "memory.h"
#include "misc.h"


fde_t *fd_table;
int number_fd = LEAKED_FDS;
int hard_fdlimit = 0;
int highest_fd = -1;


void
fdlist_init(void)
{
  /*
   * Allow MAXCLIENTS_MIN clients even at the cost of MAX_BUFFER and
   * some not really LEAKED_FDS
   */
  hard_fdlimit = IRCD_MAX(hard_fdlimit, LEAKED_FDS + MAX_BUFFER + MAXCLIENTS_MIN);
  fd_table = xcalloc(sizeof(*fd_table) * hard_fdlimit);
}

static void
fdlist_update_highest_fd(int fd, bool opening)
{
  if (fd < highest_fd)
    return;

  assert(fd < hard_fdlimit);

  if (fd > highest_fd)
  {
    /*
     * assert() that we are not closing a FD bigger than our known highest FD.
     */
    assert(opening == true);
    highest_fd = fd;
    return;
  }

  /* If we are here, then fd == highest_fd */
  /*
   * assert() that we are closing the highest FD; we can't be re-opening it.
   */
  assert(opening == false);

  while (highest_fd >= 0 && fd_table[highest_fd].flags.open == false)
    --highest_fd;
}

/* Called to open a given filedescriptor */
fde_t *
fd_open(int fd, bool is_socket, const char *desc)
{
  fde_t *F = &fd_table[fd];

  assert(fd >= 0);
  assert(F->fd == 0);
  assert(F->flags.open == false);

  /*
   * Note: normally we'd have to clear the other flags, but currently F
   * is always cleared before calling us.
   */
  F->fd = fd;
  F->comm_index = -1;
  F->flags.open = true;
  F->flags.is_socket = is_socket;

  if (desc)
    F->desc = xstrndup(desc, FD_DESC_SIZE);

  fdlist_update_highest_fd(F->fd, true);
  ++number_fd;

  return F;
}

/* Called to close a given filedescriptor */
fde_t *
fd_close(fde_t *F)
{
  assert(F->fd >= 0);
  assert(F->flags.open == true);

  if (F->flags.is_socket)
    comm_setselect(F, COMM_SELECT_WRITE | COMM_SELECT_READ, NULL, NULL, 0);

  if (tls_isusing(&F->tls))
    tls_free(&F->tls);

  xfree(F->desc);
  /* Unlike squid, we're actually closing the FD here! -- adrian */
  close(F->fd);
  F->flags.open = false;  /* Must set F->flags.open == false before fdlist_update_highest_fd() */

  fdlist_update_highest_fd(F->fd, false);
  --number_fd;

  memset(F, 0, sizeof(*F));

  return F;
}

/*
 * fd_note() - set the fd note
 *
 * Note: must be careful not to overflow fd_table[fd].desc when
 *       calling.
 */
void
fd_note(fde_t *F, const char *format, ...)
{
  if (format)
  {
    char buf[FD_DESC_SIZE + 1];
    va_list args;

    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);

    xfree(F->desc);
    F->desc = xstrdup(buf);
  }
  else
  {
    xfree(F->desc);
    F->desc = NULL;
  }
}

void
close_fds(void)
{
  for (int fd = 0; fd <= highest_fd; ++fd)
    close(fd);
}
