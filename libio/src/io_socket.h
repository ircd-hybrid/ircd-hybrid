/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file io_socket.h
 * \brief Socket lifecycle and nonblocking TCP connections.
 */

#ifndef INCLUDED_io_socket_h
#define INCLUDED_io_socket_h
#include <stdbool.h>
#include <stdint.h>

#include "event.h"
#include "fdlist.h"
#include "io.h"
#include "io_poll.h"

enum
{
  IO_SOCKET_CONNECT_SUCCESS,
  IO_SOCKET_CONNECT_BIND_FAILED,
  IO_SOCKET_CONNECT_TIMED_OUT,
  IO_SOCKET_CONNECT_FAILED,
  IO_SOCKET_CONNECT_UNSPECIFIED_ERROR,
  IO_SOCKET_CONNECT_TIMER_FAILED,
  IO_SOCKET_CONNECT_WATCH_FAILED,
  IO_SOCKET_CONNECT_STATUS_COUNT
};

typedef void (*io_socket_connect_callback_fn)(fde_t *, int, void *);

extern event_manager_t io_socket_event_manager;

extern void io_socket_close(fde_t *);
extern void io_socket_connect_tcp(fde_t *, const struct io_addr *, uint16_t, const struct io_addr *,
                                  io_socket_connect_callback_fn, void *, uintmax_t);
extern void io_socket_set_description_fmt(fde_t *, const char *, ...) IO_AFP(2,3);
extern void io_socket_shutdown(void);
extern bool io_socket_connect_cancel(fde_t *);
extern bool io_socket_errno_is_transient(int);
extern bool io_socket_get_pending_error(const fde_t *, int *const);
extern bool io_socket_init(event_manager_t);
extern fde_t *io_socket_accept(fde_t *, struct io_addr *, const char *);
extern fde_t *io_socket_create(int, int, int, const char *);
extern fde_t *io_socket_listen(const struct io_addr *, int, const char *);
extern const char *io_socket_connect_status_to_string(int);
extern struct io_poll *io_socket_get_poller(void);
#endif  /* INCLUDED_io_socket_h */
