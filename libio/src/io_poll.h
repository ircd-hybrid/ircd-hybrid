/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_poll_h
#define INCLUDED_io_poll_h
#include <stdint.h>

struct io_poll;

struct io_poll_fd_info
{
  int fd;
  const char *description;
};

typedef void (*io_poll_handler_fn)(int, void *);

extern void io_poll_destroy(struct io_poll *);
extern void io_poll_unwatch(struct io_poll *, int);
extern void io_poll_unwatch_write(struct io_poll *, int, uint64_t);
extern int io_poll_dispatch(struct io_poll *, int);
extern int io_poll_watch_read(struct io_poll *, int, io_poll_handler_fn, void *);
extern int io_poll_watch_write(struct io_poll *, int, io_poll_handler_fn, void *, uint64_t *);
extern struct io_poll *io_poll_create(int fd_limit);
extern const struct io_poll_fd_info *io_poll_control_fd(const struct io_poll *);
#endif  /* INCLUDED_io_poll_h */
