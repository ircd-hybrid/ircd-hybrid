/*
 * SPDX-FileCopyrightText: 2005-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file io_poll_epoll.c
 * \brief Linux epoll() compatible network routines.
 */

#include "config.h"
#if USE_IOPOLL_MECHANISM == AX_IOPOLL_MECHANISM_EPOLL
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/epoll.h>

#include "io_poll_backend.h"
#include "memory.h"


enum
{
  EPOLL_INITIAL_EVENT_CAPACITY =  128,
  EPOLL_MAX_EVENT_CAPACITY     = 4096
};

struct io_poll_backend
{
  int fd;
  int event_capacity;
  struct epoll_event *events;
};

struct io_poll_backend *
io_poll_backend_create(int fd_limit, struct io_poll_fd_info *control_fd)
{
  (void)fd_limit;

  const int fd = epoll_create1(EPOLL_CLOEXEC);
  if (fd == -1)
    return NULL;

  struct io_poll_backend *const backend = io_malloc(sizeof(*backend));
  backend->fd = fd;
  backend->event_capacity = EPOLL_INITIAL_EVENT_CAPACITY;
  backend->events = io_calloc(backend->event_capacity * sizeof(*backend->events));

  *control_fd = (struct io_poll_fd_info){ .fd = fd, .description = "epoll file descriptor" };
  return backend;
}

void
io_poll_backend_destroy(struct io_poll_backend *backend)
{
  close(backend->fd);
  io_free(backend->events);
  io_free(backend);
}

int
io_poll_backend_set_interests(struct io_poll_backend *backend, int fd,
                              unsigned int previous_interests, unsigned int interests)
{
  int operation;

  if (interests == 0)
    operation = EPOLL_CTL_DEL;
  else if (previous_interests == 0)
    operation = EPOLL_CTL_ADD;
  else
    operation = EPOLL_CTL_MOD;

  struct epoll_event event =
  {
    .events = (interests & IO_POLL_EVENT_READ ? EPOLLIN : 0) |
              (interests & IO_POLL_EVENT_WRITE ? EPOLLOUT : 0),
    .data.fd = fd
  };

  return epoll_ctl(backend->fd, operation, fd, &event);
}

int
io_poll_backend_wait(struct io_poll_backend *backend, struct io_poll *poller, int timeout_ms)
{
  const int event_count = epoll_wait(backend->fd, backend->events, backend->event_capacity, timeout_ms);

  if (event_count < 0 || io_poll_ready_reserve(poller, event_count) == -1)
    return -1;

  assert(event_count <= backend->event_capacity);
  for (int i = 0; i < event_count; ++i)
  {
    const struct epoll_event *const event = &backend->events[i];

    unsigned int readiness = 0;
    if (event->events & (EPOLLIN | EPOLLHUP | EPOLLERR))
      readiness |= IO_POLL_EVENT_READ;
    if (event->events & (EPOLLOUT | EPOLLHUP | EPOLLERR))
      readiness |= IO_POLL_EVENT_WRITE;

    io_poll_ready_append(poller, event->data.fd, readiness);
  }

  if (event_count == backend->event_capacity && backend->event_capacity < EPOLL_MAX_EVENT_CAPACITY)
  {
    const int event_capacity = backend->event_capacity * 2;
    backend->events = io_realloc(backend->events, event_capacity * sizeof(*backend->events));
    backend->event_capacity = event_capacity;
  }

  return event_count;
}
#endif
