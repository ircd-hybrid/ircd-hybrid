/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_lookup_h
#define INCLUDED_lookup_h
#include <stdbool.h>

#include "ident.h"
#include "client.h"

struct LookupRequest
{
  ident_request_t *ident_request;
  struct Client *client;
  bool dns_pending;
  bool ident_pending;
};

extern void lookup_delete(struct LookupRequest *);
extern void lookup_start(struct Client *);
#endif  /* INCLUDED_lookup_h */
