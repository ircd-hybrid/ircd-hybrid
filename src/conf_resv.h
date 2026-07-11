/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_resv.h
 * \brief A header for the RESV functions.
 */

#ifndef INCLUDED_conf_resv_h
#define INCLUDED_conf_resv_h
#include <stdbool.h>
#include <stdint.h>

#include "list.h"

struct ResvItem
{
  list_node_t node;
  list_t *list;
  list_t exempt_list;
  char *mask;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  bool in_database;
};

struct ResvExemptItem
{
  list_node_t node;
  char *name;
  char *user;
  char *host;
  struct io_addr addr;
  int bits;
  int type;
};

extern void resv_delete(struct ResvItem *, bool);
extern void resv_clear(void);
extern void resv_expire(void);
extern bool resv_exempt_find(const struct Client *, const struct ResvItem *);
extern struct ResvItem *resv_make(const char *, const char *, const list_t *);
extern struct ResvItem *resv_find(const char *, int (*)(const char *, const char *));
extern const list_t *resv_chan_get_list(void);
extern const list_t *resv_nick_get_list(void);
#endif  /* INCLUDED_conf_resv_h */
