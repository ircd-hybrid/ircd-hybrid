/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "io_poll.h"
#include "io_poll_backend.h"
#include "io_time.h"
#include "log.h"
#include "memory.h"

struct io_poll_watch
{
  io_poll_handler_fn handler;
  void *context;
  uint64_t id;
};

struct io_poll_fd_state
{
  struct io_poll_watch read;
  struct io_poll_watch write;
  unsigned int interests;
};

struct io_poll_ready_event
{
  int fd;
  uint64_t read_watch_id;
  uint64_t write_watch_id;
};

struct io_poll
{
  struct io_poll_backend *backend;
  struct io_poll_ready_event *ready_events;
  size_t ready_count;
  size_t ready_capacity;
  uint64_t last_watch_id;
  int fd_limit;
  struct io_poll_fd_info control_fd;
  bool dispatching;
  struct io_poll_fd_state fd_states[];
};

struct io_poll *
io_poll_create(int fd_limit)
{
  if (fd_limit <= 0)
  {
    errno = EINVAL;
    return NULL;
  }

  if ((size_t)fd_limit > (SIZE_MAX - sizeof(struct io_poll)) / sizeof(struct io_poll_fd_state))
  {
    errno = ENOMEM;
    return NULL;
  }

  struct io_poll_fd_info control_fd;
  struct io_poll_backend *const backend = io_poll_backend_create(fd_limit, &control_fd);
  if (backend == NULL)
    return NULL;

  struct io_poll *const poller = io_calloc(sizeof(*poller) + fd_limit * sizeof(*poller->fd_states));
  poller->fd_limit = fd_limit;
  poller->backend = backend;
  poller->control_fd = control_fd;

  return poller;
}

const struct io_poll_fd_info *
io_poll_control_fd(const struct io_poll *poller)
{
  return poller && poller->backend && poller->control_fd.fd >= 0 ? &poller->control_fd : NULL;
}

static void
io_poll_free_storage(struct io_poll *poller)
{
  io_free(poller->ready_events);
  io_free(poller);
}

void
io_poll_destroy(struct io_poll *poller)
{
  if (poller == NULL || poller->backend == NULL)
    return;

  io_poll_backend_destroy(poller->backend);
  poller->backend = NULL;

  if (!poller->dispatching)
    io_poll_free_storage(poller);
}

static struct io_poll_fd_state *
io_poll_fd_state_for(struct io_poll *poller, int fd)
{
  if (poller == NULL || poller->backend == NULL || fd < 0 || fd >= poller->fd_limit)
  {
    log_write(LOG_TYPE_IRCD, "io_poll: invalid watch descriptor %d", fd);
    abort();
  }

  return &poller->fd_states[fd];
}

static void
io_poll_update_interests(struct io_poll *poller, int fd, struct io_poll_fd_state *state)
{
  const unsigned int interests = (state->read.id ? IO_POLL_EVENT_READ : 0) |
                                 (state->write.id ? IO_POLL_EVENT_WRITE : 0);
  if (interests == state->interests)
    return;

  if (io_poll_backend_set_interests(poller->backend, fd, state->interests, interests) == -1)
  {
    log_write(LOG_TYPE_IRCD, "io_poll: cannot update I/O interest for FD %d: %s",
              fd, strerror(errno));
    abort();
  }

  state->interests = interests;
}

static void
io_poll_watch_set(struct io_poll *poller, struct io_poll_watch *watch,
                  io_poll_handler_fn handler, void *context)
{
  if (handler == NULL)
    abort();

  if (++poller->last_watch_id == 0)
    ++poller->last_watch_id;

  *watch = (struct io_poll_watch){ .handler = handler, .context = context, .id = poller->last_watch_id };
}

void
io_poll_watch_read(struct io_poll *poller, int fd, io_poll_handler_fn handler, void *context)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_for(poller, fd);

  io_poll_watch_set(poller, &state->read, handler, context);
  io_poll_update_interests(poller, fd, state);
}

uint64_t
io_poll_watch_write(struct io_poll *poller, int fd, io_poll_handler_fn handler, void *context)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_for(poller, fd);

  io_poll_watch_set(poller, &state->write, handler, context);
  io_poll_update_interests(poller, fd, state);
  return state->write.id;
}

void
io_poll_unwatch_write(struct io_poll *poller, int fd, uint64_t watch_id)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_for(poller, fd);

  if (state->write.id == watch_id)
    state->write = (struct io_poll_watch){ 0 };

  io_poll_update_interests(poller, fd, state);
}

void
io_poll_unwatch(struct io_poll *poller, int fd)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_for(poller, fd);

  state->read = (struct io_poll_watch){ 0 };
  state->write = (struct io_poll_watch){ 0 };
  io_poll_update_interests(poller, fd, state);
}

int
io_poll_ready_reserve(struct io_poll *poller, size_t count)
{
  if (count <= poller->ready_capacity)
    return 0;

  const size_t maximum = SIZE_MAX / sizeof(*poller->ready_events);
  if (count > maximum)
  {
    errno = ENOMEM;
    return -1;
  }

  size_t capacity = count;
  if (poller->ready_capacity <= maximum / 2 && poller->ready_capacity * 2 > capacity)
    capacity = poller->ready_capacity * 2;

  poller->ready_events = io_realloc(poller->ready_events, capacity * sizeof(*poller->ready_events));
  poller->ready_capacity = capacity;
  return 0;
}

void
io_poll_ready_append(struct io_poll *poller, int fd, unsigned int events)
{
  const struct io_poll_fd_state *const state = io_poll_fd_state_for(poller, fd);
  const struct io_poll_ready_event event =
  {
    .fd = fd,
    .read_watch_id = (events & IO_POLL_EVENT_READ) ? state->read.id : 0,
    .write_watch_id = (events & IO_POLL_EVENT_WRITE) ? state->write.id : 0
  };

  if (event.read_watch_id == 0 && event.write_watch_id == 0)
    return;

  assert(poller->ready_count < poller->ready_capacity);
  poller->ready_events[poller->ready_count++] = event;
}

static void
io_poll_watch_dispatch(int fd, struct io_poll_watch *watch, uint64_t watch_id)
{
  /* The fd can outlive a watch or be reused for a different descriptor. */
  if (watch_id == 0 || watch->id != watch_id)
    return;

  const struct io_poll_watch ready_watch = *watch;
  *watch = (struct io_poll_watch){ 0 };
  ready_watch.handler(fd, ready_watch.context);
}

static void
io_poll_ready_dispatch(struct io_poll *poller, const struct io_poll_ready_event *event)
{
  struct io_poll_fd_state *const state = &poller->fd_states[event->fd];

  io_poll_watch_dispatch(event->fd, &state->read, event->read_watch_id);
  if (poller->backend == NULL)
    return;

  io_poll_watch_dispatch(event->fd, &state->write, event->write_watch_id);

  if (poller->backend)
    io_poll_update_interests(poller, event->fd, state);
}

int
io_poll_dispatch(struct io_poll *poller, int timeout_ms)
{
  if (poller == NULL)
  {
    errno = EINVAL;
    return -1;
  }

  if (poller->dispatching)
  {
    errno = EBUSY;
    return -1;
  }

  poller->dispatching = true;

  const int result = io_poll_backend_wait(poller->backend, poller, timeout_ms);
  const int saved_errno = errno;
  const bool clock_ok = io_time_update_cache() != NULL;

  if (result >= 0 && clock_ok)
  {
    for (size_t i = 0; poller->backend && i < poller->ready_count; ++i)
      io_poll_ready_dispatch(poller, &poller->ready_events[i]);
  }

  poller->ready_count = 0;
  poller->dispatching = false;

  if (poller->backend == NULL)
    io_poll_free_storage(poller);

  if (result < 0 || !clock_ok)
  {
    errno = result < 0 ? saved_errno : EIO;
    return -1;
  }

  return 0;
}
