/*
 * SPDX-FileCopyrightText: 1998-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_gecos.h
 * \brief Implements gecos {} block configuration management.
 */

#ifndef INCLUDED_conf_gecos_h
#define INCLUDED_conf_gecos_h
#include <stdbool.h>
#include <stdint.h>

#include "list.h"

struct GecosItem
{
  list_node_t node;
  char *mask;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  bool in_database;
};

typedef void (*gecos_expire_callback_fn)(const struct GecosItem *, void *);

extern void gecos_clear(void);
extern void gecos_delete(struct GecosItem *);
extern void gecos_expire(uintmax_t, gecos_expire_callback_fn, void *);
extern struct GecosItem *gecos_make(void);
extern struct GecosItem *gecos_find(const char *, int (*)(const char *, const char *));
extern const list_t *gecos_get_list(void);
#endif  /* INCLUDED_conf_gecos_h */
