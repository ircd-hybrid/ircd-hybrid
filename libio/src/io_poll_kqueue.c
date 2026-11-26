/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file io_poll_kqueue.c
 * \brief kqueue() compatible network routines.
 */

#include "config.h"
#if USE_IOPOLL_MECHANISM == AX_IOPOLL_MECHANISM_KQUEUE
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/event.h>
#include <time.h>

#include "io_poll_backend.h"
#include "memory.h"


enum { KQUEUE_EVENT_CAPACITY = 128 };

struct io_poll_backend
{
  int fd;
};

struct io_poll_backend *
io_poll_backend_create(int fd_limit, struct io_poll_fd_info *control_fd)
{
  (void)fd_limit;

  const int fd = kqueue();
  if (fd == -1)
    return NULL;

  if (fcntl(fd, F_SETFD, FD_CLOEXEC) == -1)
  {
    const int error = errno;

    close(fd);
    errno = error;
    return NULL;
  }

  struct io_poll_backend *const backend = io_malloc(sizeof(*backend));
  backend->fd = fd;

  *control_fd = (struct io_poll_fd_info){ .fd = fd, .description = "kqueue() file descriptor" };
  return backend;
}

void
io_poll_backend_destroy(struct io_poll_backend *backend)
{
  close(backend->fd);
  io_free(backend);
}

int
io_poll_backend_set_interests(struct io_poll_backend *backend, int fd,
                              unsigned int previous_interests, unsigned int interests)
{
  const unsigned int changed_interests = previous_interests ^ interests;
  struct kevent changes[2];
  int change_count = 0;

  /*
   * Apply changes while this descriptor is still owned by the caller.
   * With no output events, kevent reports change errors via errno.
   */
  if (changed_interests & IO_POLL_EVENT_READ)
  {
    EV_SET(&changes[change_count], (uintptr_t)fd, EVFILT_READ,
           interests & IO_POLL_EVENT_READ ? EV_ADD : EV_DELETE, 0, 0, 0);
    ++change_count;
  }

  if (changed_interests & IO_POLL_EVENT_WRITE)
  {
    EV_SET(&changes[change_count], (uintptr_t)fd, EVFILT_WRITE,
           interests & IO_POLL_EVENT_WRITE ? EV_ADD : EV_DELETE, 0, 0, 0);
    ++change_count;
  }

  return kevent(backend->fd, changes, change_count, NULL, 0, NULL);
}

int
io_poll_backend_wait(struct io_poll_backend *backend, struct io_poll *poller, int timeout_ms)
{
  struct kevent events[KQUEUE_EVENT_CAPACITY];
  const struct timespec timeout =
  {
    .tv_sec = timeout_ms / 1000,
    .tv_nsec = (timeout_ms % 1000) * 1000000L
  };

  const int event_count =
    kevent(backend->fd, NULL, 0, events, KQUEUE_EVENT_CAPACITY, timeout_ms < 0 ? NULL : &timeout);
  if (event_count < 0 || io_poll_ready_reserve(poller, event_count) == -1)
    return -1;

  for (int i = 0; i < event_count; ++i)
  {
    const struct kevent *const event = &events[i];
    if (event->flags & EV_ERROR)
      continue;

    if (event->filter == EVFILT_READ)
      io_poll_ready_append(poller, (int)event->ident, IO_POLL_EVENT_READ);
    else if (event->filter == EVFILT_WRITE)
      io_poll_ready_append(poller, (int)event->ident, IO_POLL_EVENT_WRITE);
  }

  return event_count;
}
#endif
