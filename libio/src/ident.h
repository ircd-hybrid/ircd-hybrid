/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_ident_h
#define INCLUDED_ident_h
#include <stdint.h>

#include "address.h"
#include "event.h"
#include "fdlist.h"

typedef void (*IdentCallback)(void *, const char *);

struct IdentRequest
{
  fde_t *fd;
  IdentCallback callback;
  void *user_data;
  uint16_t local_port;
  uint16_t remote_port;
  event_handle_t reply_timeout_event;
};

typedef struct IdentRequest ident_request_t;

extern void ident_delete(ident_request_t *);
extern ident_request_t *ident_start(const struct io_addr *, int, IdentCallback, void *, uintmax_t);
#endif  /* INCLUDED_ident_h */
