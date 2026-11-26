/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file io_poll_poll.c
 * \brief POSIX poll() compatible network routines.
 */

#include "config.h"
#if USE_IOPOLL_MECHANISM == AX_IOPOLL_MECHANISM_POLL
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <poll.h>

#include "io_poll_backend.h"
#include "memory.h"


struct io_poll_backend
{
  struct pollfd *entries;
  int *fd_indices;  /* Indexed by fd, valid while registered. */
  int entry_count;
  int entry_capacity;
};

struct io_poll_backend *
io_poll_backend_create(int fd_limit, struct io_poll_fd_info *control_fd)
{
  if ((size_t)fd_limit > SIZE_MAX / sizeof(struct pollfd))
  {
    errno = ENOMEM;
    return NULL;
  }

  struct io_poll_backend *const backend = io_calloc(sizeof(*backend));
  backend->entries = io_calloc(fd_limit * sizeof(*backend->entries));
  backend->fd_indices = io_calloc(fd_limit * sizeof(*backend->fd_indices));
  backend->entry_capacity = fd_limit;

  *control_fd = (struct io_poll_fd_info){ .fd = -1 };
  return backend;
}

void
io_poll_backend_destroy(struct io_poll_backend *backend)
{
  io_free(backend->fd_indices);
  io_free(backend->entries);
  io_free(backend);
}

int
io_poll_backend_set_interests(struct io_poll_backend *backend, int fd,
                              unsigned int previous_interests, unsigned int interests)
{
  int index = backend->fd_indices[fd];

  if (interests == 0)
  {
    assert(previous_interests && index < backend->entry_count);

    --backend->entry_count;

    if (index != backend->entry_count)
    {
      backend->entries[index] = backend->entries[backend->entry_count];
      backend->fd_indices[backend->entries[index].fd] = index;
    }

    return 0;
  }

  if (previous_interests == 0)
  {
    assert(backend->entry_count < backend->entry_capacity);

    index = backend->entry_count++;
    backend->fd_indices[fd] = index;
  }

  backend->entries[index] = (struct pollfd)
  {
    .fd = fd,
    .events = (interests & IO_POLL_EVENT_READ ? POLLIN : 0) |
              (interests & IO_POLL_EVENT_WRITE ? POLLOUT : 0)
  };

  return 0;
}

int
io_poll_backend_wait(struct io_poll_backend *backend, struct io_poll *poller, int timeout_ms)
{
  const int ready_count = poll(backend->entries, backend->entry_count, timeout_ms);

  if (ready_count < 0 || io_poll_ready_reserve(poller, ready_count) == -1)
    return -1;

  int remaining_ready = ready_count;
  for (int i = 0; remaining_ready > 0 && i < backend->entry_count; ++i)
  {
    const struct pollfd *const entry = &backend->entries[i];
    if (entry->revents == 0)
      continue;

    --remaining_ready;

    if (entry->revents & POLLNVAL)
    {
      errno = EBADF;
      return -1;
    }

    unsigned int readiness = 0;
    if (entry->revents & (POLLIN | POLLHUP | POLLERR))
      readiness |= IO_POLL_EVENT_READ;
    if (entry->revents & (POLLOUT | POLLHUP | POLLERR))
      readiness |= IO_POLL_EVENT_WRITE;

    io_poll_ready_append(poller, entry->fd, readiness);
  }

  return ready_count;
}
#endif
