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
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include "address.h"
#include "event.h"
#include "io.h"
#include "io_poll.h"
#include "tls.h"

struct io_socket;
struct io_socket_context;

enum { IO_SOCKET_DESCRIPTION_MAX = 80 };

struct io_socket_snapshot
{
  int fd;
  char description[IO_SOCKET_DESCRIPTION_MAX + 1];
};

enum io_socket_connect_status
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

typedef void (*io_socket_connect_callback_fn)(struct io_socket *, enum io_socket_connect_status, int, void *);

extern void io_socket_close(struct io_socket *);
extern void io_socket_set_description_fmt(struct io_socket *, const char *, ...) IO_AFP(2,3);
extern bool io_socket_connect_cancel(struct io_socket *);
extern bool io_socket_errno_is_transient(int);
extern bool io_socket_tls_get_peer_certificate_fingerprint(struct io_socket *, char **);
extern bool io_socket_tls_is_active(const struct io_socket *);
extern bool io_socket_tls_start(struct io_socket *, tls_role_t);
extern int io_socket_connect_tcp(struct io_socket *, const struct io_addr *, const struct io_addr *, io_socket_connect_callback_fn, void *, uintmax_t);
extern int io_socket_context_destroy(struct io_socket_context *);
extern int io_socket_context_snapshot(const struct io_socket_context *, struct io_socket_snapshot **, size_t *);
extern int io_socket_fd(const struct io_socket *);
extern int io_socket_watch_read(struct io_socket *, io_poll_handler_fn, void *);
extern int io_socket_watch_write(struct io_socket *, io_poll_handler_fn, void *);
extern size_t io_socket_context_available_slots(const struct io_socket_context *);
extern ssize_t io_socket_tls_read(struct io_socket *, char *, size_t, bool *);
extern ssize_t io_socket_tls_write(struct io_socket *, const char *, size_t, bool *);
extern tls_handshake_status_t io_socket_tls_handshake(struct io_socket *, const char **);
extern struct io_socket *io_socket_accept(struct io_socket *, struct io_addr *, const char *);
extern struct io_socket *io_socket_create(struct io_socket_context *, int, int, int, const char *);
extern struct io_socket *io_socket_listen(struct io_socket_context *, const struct io_addr *, int, const char *);
extern struct io_socket_context *io_socket_context_create(struct io_poll *, event_manager_t, size_t);
extern const char *io_socket_connect_status_to_string(enum io_socket_connect_status);
extern const char *io_socket_tls_get_cipher(const struct io_socket *);
#endif  /* INCLUDED_io_socket_h */
