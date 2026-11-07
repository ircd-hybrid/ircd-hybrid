/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_accept_h
#define INCLUDED_accept_h
#include <stdbool.h>

#include "list.h"
#include "client.h"


struct AcceptItem
{
  list_node_t node;
  char *nick;
  char *user;
  char *host;
};

extern void accept_add(const char *, const char *, const char *, list_t *);
extern void accept_del(struct AcceptItem *, list_t *);
extern void accept_clear_list(list_t *);
extern bool accept_message(struct Client *, struct Client *);
extern struct AcceptItem *accept_find(const char *, const char *, const char *, list_t *, int (*)(const char *, const char *));
#endif  /* INCLUDED_accept_h */
