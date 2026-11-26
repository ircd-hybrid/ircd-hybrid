/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file fdlist.c
 * \brief Maintains a list of file descriptors.
 */

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "defaults.h"
#include "fdlist.h"
#include "io_rlimit.h"
#include "io_string.h"
#include "memory.h"

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
  hard_fdlimit = io_rlimit_get_cur_nofile();
  hard_fdlimit = IO_MAX(hard_fdlimit, LEAKED_FDS + MAX_BUFFER + MAXCLIENTS_MIN);
  fd_table = io_calloc(sizeof(*fd_table) * hard_fdlimit);
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

fde_t *
fd_open(int fd, const char *desc)
{
  assert(fd >= 0 && fd < hard_fdlimit);
  fde_t *const F = &fd_table[fd];
  assert(F->fd == 0);
  assert(F->flags.open == false);

  F->fd = fd;
  F->flags.open = true;

  if (desc)
    F->desc = io_strndup(desc, FD_DESC_SIZE);

  fdlist_update_highest_fd(F->fd, true);
  ++number_fd;

  return F;
}

void
fd_close(fde_t *F)
{
  assert(F->fd >= 0);
  assert(F->flags.open == true);

  if (F->cleanup_handler)
    F->cleanup_handler(F->cleanup_data);

  if (tls_session_is_active(&F->tls))
    tls_session_deinit(&F->tls);

  io_free(F->desc);
  close(F->fd);
  F->flags.open = false;  /* Must set F->flags.open == false before fdlist_update_highest_fd() */

  fdlist_update_highest_fd(F->fd, false);
  --number_fd;

  memset(F, 0, sizeof(*F));
}

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

    io_free(F->desc);
    F->desc = io_strdup(buf);
  }
  else
  {
    io_free(F->desc);
    F->desc = NULL;
  }
}

void
close_fds(void)
{
  for (int fd = 0; fd <= highest_fd; ++fd)
    close(fd);
}
