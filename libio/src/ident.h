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

#ifndef INCLUDED_ident_h
#define INCLUDED_ident_h
#include <stdint.h>

#include "address.h"
#include "fdlist.h"

typedef void (*IdentCallback)(void *, const char *);

struct IdentRequest
{
  fde_t *fd;
  IdentCallback callback;
  void *user_data;
  uint16_t local_port;
  uint16_t remote_port;
};

typedef struct IdentRequest ident_request_t;

extern void ident_delete(ident_request_t *);
extern ident_request_t *ident_start(const struct io_addr *, int, IdentCallback, void *, uintmax_t);
#endif  /* INCLUDED_ident_h */
