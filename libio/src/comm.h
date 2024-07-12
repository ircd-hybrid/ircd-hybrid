/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

#include "fdlist.h"

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

/** How long can comm_select() wait for network events [milliseconds] */
enum { SELECT_DELAY = 500 };

extern void comm_select_init(void);
extern void comm_setselect(fde_t *, unsigned int, void (*)(fde_t *, void *), void *, uintmax_t);
extern void comm_select(void);
extern void comm_settimeout(fde_t *, uintmax_t, void (*)(fde_t *, void *), void *);
extern void comm_setflush(fde_t *, uintmax_t, void (*)(fde_t *, void *), void *);
extern void comm_checktimeouts(void *);
extern void comm_connect_tcp(fde_t *, const struct io_addr *, unsigned short, const struct io_addr *, void (fde_t *, int, void *), void *, uintmax_t);
extern bool comm_ignore_errno(int);
extern int comm_get_sockerr(fde_t *);
extern int comm_socket(int, int, int);
extern int comm_accept(fde_t *, struct io_addr *);
extern const char *comm_errstr(int);
#endif  /* INCLUDED_comm_h */
