/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file s_bsd.h
 * \brief A header for the network subsystem.
 */

#ifndef INCLUDED_comm_h
#define INCLUDED_comm_h

#include <stdint.h>
#include <stdbool.h>

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
