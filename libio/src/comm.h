/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file s_bsd.h
 * \brief A header for the network subsystem.
 */

#ifndef INCLUDED_comm_h
#define INCLUDED_comm_h
#include <stdbool.h>
#include <stdint.h>

#include "event.h"
#include "fdlist.h"
#include "io.h"

typedef struct comm_op_st comm_op_t;

enum
{
  COMM_OK,
  COMM_ERR_BIND,
  COMM_ERR_TIMEOUT,
  COMM_ERR_CONNECT,
  COMM_ERROR,
  COMM_ERR_MAX
};

/* Type of IO */
enum
{
  COMM_SELECT_READ  = 1 << 0,
  COMM_SELECT_WRITE = 1 << 1
};

extern event_manager_t comm_event_manager;

extern void comm_init(event_manager_t);
extern void comm_select_init(void);
extern void comm_setselect(fde_t *, unsigned int, void (*)(fde_t *, void *), void *);
extern void comm_select(int);
extern void comm_socket_close(fde_t *);
extern void comm_socket_note(fde_t *, const char *, ...) IO_AFP(2,3);
extern void comm_connect_tcp(fde_t *, const struct io_addr *, uint16_t, const struct io_addr *, void (fde_t *, int, void *), void *, uintmax_t);
extern bool comm_errno_is_recoverable(int);
extern bool comm_socket_get_error(const fde_t *, int *const);
extern int comm_get_select_timeout(event_manager_t);
extern const char *comm_errstr(int);
extern fde_t *comm_socket_create(int, int, int, const char *);
extern fde_t *comm_socket_listen(const struct io_addr *, int, const char *);
extern fde_t *comm_accept(fde_t *, struct io_addr *, const char *);
#endif  /* INCLUDED_comm_h */
