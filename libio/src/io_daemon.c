/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
