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
  unsigned int registered_interests;
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

int
io_poll_fd_limit(const struct io_poll *poller)
{
  return poller->fd_limit;
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
io_poll_fd_state_find(struct io_poll *poller, int fd)
{
  if (poller == NULL || poller->backend == NULL || fd < 0 || fd >= poller->fd_limit)
    return NULL;

  return &poller->fd_states[fd];
}

static int
io_poll_set_interests(struct io_poll *poller, int fd, struct io_poll_fd_state *state,
                      unsigned int interests)
{
  if (interests == state->registered_interests)
    return 0;

  if (io_poll_backend_set_interests(poller->backend, fd, state->registered_interests, interests) == -1)
    return -1;

  state->registered_interests = interests;
  return 0;
}

static void
io_poll_remove_interests(struct io_poll *poller, int fd, struct io_poll_fd_state *state,
                         unsigned int interests)
{
  if (io_poll_set_interests(poller, fd, state, state->registered_interests & ~interests) == -1)
  {
    log_write(LOG_TYPE_IRCD, "io_poll: cannot remove I/O interest for FD %d: %s",
              fd, strerror(errno));
    abort();
  }
}

static int
io_poll_watch_set(struct io_poll *poller, int fd, unsigned int interest,
                  io_poll_handler_fn handler, void *context, uint64_t *watch_id)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_find(poller, fd);
  if (state == NULL || handler == NULL)
  {
    errno = EINVAL;
    return -1;
  }

  /*
   * Leave consumed interests installed until dispatch completes. This update
   * only adds the requested direction, even when called by a ready handler.
   */
  if (io_poll_set_interests(poller, fd, state, state->registered_interests | interest) == -1)
    return -1;

  if (++poller->last_watch_id == 0)
    ++poller->last_watch_id;

  struct io_poll_watch *const watch = interest == IO_POLL_EVENT_READ ? &state->read : &state->write;
  *watch = (struct io_poll_watch){ .handler = handler, .context = context, .id = poller->last_watch_id };

  if (watch_id)
    *watch_id = watch->id;

  return 0;
}

int
io_poll_watch_read(struct io_poll *poller, int fd, io_poll_handler_fn handler, void *context)
{
  return io_poll_watch_set(poller, fd, IO_POLL_EVENT_READ, handler, context, NULL);
}

int
io_poll_watch_write(struct io_poll *poller, int fd, io_poll_handler_fn handler, void *context,
                    uint64_t *watch_id)
{
  return io_poll_watch_set(poller, fd, IO_POLL_EVENT_WRITE, handler, context, watch_id);
}

void
io_poll_unwatch_write(struct io_poll *poller, int fd, uint64_t watch_id)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_find(poller, fd);
  if (state == NULL || watch_id == 0 || state->write.id != watch_id)
    return;

  state->write = (struct io_poll_watch){ 0 };
  io_poll_remove_interests(poller, fd, state, IO_POLL_EVENT_WRITE);
}

void
io_poll_unwatch(struct io_poll *poller, int fd)
{
  struct io_poll_fd_state *const state = io_poll_fd_state_find(poller, fd);
  if (state == NULL)
    return;

  state->read = (struct io_poll_watch){ 0 };
  state->write = (struct io_poll_watch){ 0 };
  io_poll_remove_interests(poller, fd, state, state->registered_interests);
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
  const struct io_poll_fd_state *const state = io_poll_fd_state_find(poller, fd);
  if (state == NULL)
  {
    log_write(LOG_TYPE_IRCD, "io_poll: backend reported invalid descriptor %d", fd);
    abort();
  }

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

  if (poller->backend == NULL)
    return;

  const unsigned int inactive_interests = (state->read.id == 0 ? IO_POLL_EVENT_READ : 0) |
                                          (state->write.id == 0 ? IO_POLL_EVENT_WRITE : 0);
  io_poll_remove_interests(poller, event->fd, state, inactive_interests);
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
