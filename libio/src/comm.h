/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file comm.h
 * \brief A header for the network subsystem.
 */

#ifndef INCLUDED_comm_h
#define INCLUDED_comm_h
#include <stdbool.h>
#include <stdint.h>

#include "event.h"
#include "fdlist.h"
#include "io.h"
#include "io_poll.h"

enum
{
  COMM_OK,
  COMM_ERR_BIND,
  COMM_ERR_TIMEOUT,
  COMM_ERR_CONNECT,
  COMM_ERROR,
  COMM_ERR_TIMER,
  COMM_ERR_WATCH,
  COMM_ERR_MAX
};

extern event_manager_t comm_event_manager;

extern void comm_connect_tcp(fde_t *, const struct io_addr *, uint16_t, const struct io_addr *, void (*)(fde_t *, int, void *), void *, uintmax_t);
extern void comm_shutdown(void);
extern void comm_socket_close(fde_t *);
extern void comm_socket_note(fde_t *, const char *, ...) IO_AFP(2,3);
extern bool comm_connect_cancel(fde_t *);
extern bool comm_errno_is_recoverable(int);
extern bool comm_init(event_manager_t);
extern bool comm_socket_get_error(const fde_t *, int *const);
extern struct io_poll *comm_get_poller(void);
extern fde_t *comm_accept(fde_t *, struct io_addr *, const char *);
extern fde_t *comm_socket_create(int, int, int, const char *);
extern fde_t *comm_socket_listen(const struct io_addr *, int, const char *);
extern const char *comm_errstr(int);
#endif  /* INCLUDED_comm_h */
