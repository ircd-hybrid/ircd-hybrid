/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_aline_h
#define INCLUDED_aline_h
#include <stdbool.h>
#include <stdint.h>

#include "client.h"

struct aline_ctx
{
  bool add;
  bool simple_mask;
  char *mask;
  char *user;
  char *host;
  char *reason;
  char *server;
  uintmax_t duration;
};

extern bool aline_valid_mask_simple(const char *);
extern bool aline_valid_mask(int, ...);
extern bool aline_parse(const char *, struct Client *, int, char *[], struct aline_ctx *);
#endif  /* INCLUDED_aline_h */
