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

/**
 * @file io_pidfile.c
 * @brief Implements functions for handling PID files, including reading, writing, and locking.
 *
 * This file contains the implementation of functions for creating, locking, and managing PID files
 * to ensure that only one instance of a process is running at a time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include "io_pidfile.h"

/**
 * @var pidfile_fd
 * @brief Static variable to store the file descriptor of the PID file.
 */
static int pidfile_fd = -1;

/**
 * @brief Writes the current process ID to the specified PID file.
 *
 * This function writes the current process ID to the specified PID file and locks it to prevent
 * multiple instances of the process from running simultaneously.
 *
 * @param path Path to the PID file.
 * @return int Returns 0 on success, -1 on failure.
 */
int
io_pidfile_create(const char *path)
{
  pidfile_fd = open(path, O_RDWR | O_CREAT | O_CLOEXEC, 0644);
  if (pidfile_fd == -1)
  {
    fprintf(stderr, "Failed to open PID file %s: %s\n", path, strerror(errno));
    return -1;
  }

  if (lockf(pidfile_fd, F_TLOCK, 0) == -1)
  {
    if (errno == EACCES || errno == EAGAIN)
    {
      pid_t pid;

      if (io_pidfile_read(path, &pid) == 0)
        fprintf(stderr, "Process already running with PID %d\n", pid);
      else
        fprintf(stderr, "Process already running\n");

      io_pidfile_close();
      exit(EXIT_FAILURE);
    }
    else
    {
      fprintf(stderr, "Failed to lock PID file %s: %s\n", path, strerror(errno));
      io_pidfile_close();
      return -1;
    }
  }

  if (ftruncate(pidfile_fd, 0) == -1)
  {
    fprintf(stderr, "Failed to truncate PID file %s: %s\n", path, strerror(errno));
    io_pidfile_close();
    return -1;
  }

  char buf[16];
  snprintf(buf, sizeof(buf), "%d\n", getpid());

  if (write(pidfile_fd, buf, strlen(buf)) != (ssize_t)strlen(buf))
  {
    fprintf(stderr, "Failed to write to PID file %s: %s\n", path, strerror(errno));
    io_pidfile_close();
    return -1;
  }

  if (fsync(pidfile_fd) == -1)
  {
    fprintf(stderr, "Failed to sync PID file %s: %s\n", path, strerror(errno));
    io_pidfile_close();
    return -1;
  }

  return 0;
}

/**
 * @brief Reads the process ID from the specified PID file.
 *
 * This function reads the process ID from the specified PID file.
 *
 * @param path Path to the PID file.
 * @param pid Pointer to a variable where the read process ID will be stored.
 * @return int Returns 0 on success, -1 on failure.
 */
int
io_pidfile_read(const char *path, pid_t *pid)
{
  FILE *file = fopen(path, "r");
  if (file == NULL)
  {
    fprintf(stderr, "Failed to open PID file %s: %s\n", path, strerror(errno));
    return -1;
  }

  char buf[16];
  if (fgets(buf, sizeof(buf), file) == NULL)
  {
    fprintf(stderr, "Failed to read PID from file %s: %s\n", path, strerror(errno));
    fclose(file);
    return -1;
  }

  char *endptr;
  errno = 0;
  long pid_val = strtol(buf, &endptr, 10);

  /* Determine the maximum value for pid_t based on its size. */
  const long pid_max = (1UL << (sizeof(pid_t) * CHAR_BIT - 1)) - 1;

  if (errno || endptr == buf || (*endptr != '\n' && *endptr != '\0') || pid_val <= 0 || pid_val > pid_max)
  {
    fprintf(stderr, "Invalid PID format in file %s\n", path);
    fclose(file);
    return -1;
  }

  *pid = (pid_t)pid_val;

  fclose(file);
  return 0;
}

/**
 * @brief Removes the specified PID file.
 *
 * This function removes the specified PID file. It should be called when the process exits normally.
 *
 * @param path Path to the PID file.
 * @return int Returns 0 on success, -1 on failure.
 */
int
io_pidfile_remove(const char *path)
{
  if (unlink(path) == -1)
  {
    fprintf(stderr, "Failed to remove PID file %s: %s\n", path, strerror(errno));
    return -1;
  }

  return 0;
}

/**
 * @brief Closes the PID file descriptor.
 *
 * This function closes the PID file descriptor, releasing the lock on the file.
 */
void
io_pidfile_close(void)
{
  if (pidfile_fd != -1)
  {
    close(pidfile_fd);
    pidfile_fd = -1;
  }
}

