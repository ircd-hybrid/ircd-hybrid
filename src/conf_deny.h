/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_deny.h
 * @brief D-line configuration and lookup interface.
 */

#ifndef INCLUDED_conf_deny_h
#define INCLUDED_conf_deny_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "list.h"

struct io_addr;
struct address_index_entry;

enum conf_deny_origin
{
  CONF_DENY_ORIGIN_INVALID,
  CONF_DENY_ORIGIN_CONFIG,
  CONF_DENY_ORIGIN_DATABASE
};

struct conf_deny
{
  list_node_t node;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_deny_origin origin;

  struct address_index_entry *index_entry;
};

struct conf_deny_spec
{
  const char *prefix;
  const char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_deny_origin origin;
};

typedef void (*conf_deny_expire_callback_fn)(const struct conf_deny *, void *);


extern void conf_deny_clear_configuration(void);
extern void conf_deny_delete(struct conf_deny *);
extern void conf_deny_expire(uintmax_t, conf_deny_expire_callback_fn, void *);
extern void conf_deny_init(void);
extern bool conf_deny_format_prefix(const struct conf_deny *, char *, size_t);
extern bool conf_deny_matches(const struct conf_deny *, const struct io_addr *);
extern const list_t *conf_deny_get_list(void);
extern const struct conf_deny *conf_deny_find(const struct io_addr *);
extern const struct conf_deny *conf_deny_find_covering(const char *);
extern struct conf_deny *conf_deny_add(const struct conf_deny_spec *);
extern struct conf_deny *conf_deny_find_exact(const char *);
#endif  /* INCLUDED_conf_deny_h */
