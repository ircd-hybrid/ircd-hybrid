/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_poll_backend_h
#define INCLUDED_io_poll_backend_h

#include <stddef.h>

#include "io_poll.h"

struct io_poll_backend;

enum
{
  IO_POLL_EVENT_READ  = 1 << 0,
  IO_POLL_EVENT_WRITE = 1 << 1
};

extern struct io_poll_backend *io_poll_backend_create(int fd_limit, struct io_poll_fd_info *control_fd);
extern void io_poll_backend_destroy(struct io_poll_backend *backend);

/* Apply the interest mask synchronously. Each update either adds one interest
 * or removes interests. Return -1 with errno on failure. A failed addition
 * leaves the previous mask installed. */
extern int io_poll_backend_set_interests(struct io_poll_backend *backend, int fd,
                                         unsigned int previous_interests, unsigned int interests);

/* Reserve space for the whole result before recording readiness.
 * Return -1 with errno on a wait or result size error. */
extern int io_poll_backend_wait(struct io_poll_backend *backend, struct io_poll *poller, int timeout_ms);
extern int io_poll_ready_reserve(struct io_poll *poller, size_t count);
extern void io_poll_ready_append(struct io_poll *poller, int fd, unsigned int events);

#endif  /* INCLUDED_io_poll_backend_h */
