/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

#include "io_daemon.h"

static bool
_io_daemon_redirect_standard_fds(void)
{
  const int null_fd = open("/dev/null", O_RDWR | O_CLOEXEC);
  if (null_fd == -1)
    return false;

  if (dup2(null_fd, STDIN_FILENO) == -1 ||
      dup2(null_fd, STDOUT_FILENO) == -1 ||
      dup2(null_fd, STDERR_FILENO) == -1)
  {
    const int saved_errno = errno;

    if (null_fd > STDERR_FILENO)
      close(null_fd);

    errno = saved_errno;
    return false;
  }

  if (null_fd > STDERR_FILENO)
    close(null_fd);

  return true;
}

io_daemon_result_t
io_daemonize(pid_t *child_pid)
{
  assert(child_pid);

  *child_pid = -1;

  const pid_t pid = fork();
  if (pid == -1)
    return IO_DAEMON_ERROR;

  if (pid > 0)
  {
    *child_pid = pid;
    return IO_DAEMON_PARENT;
  }

  if (setsid() == -1)
    return IO_DAEMON_ERROR;

  if (!_io_daemon_redirect_standard_fds())
    return IO_DAEMON_ERROR;

  *child_pid = 0;
  return IO_DAEMON_CHILD;
}
