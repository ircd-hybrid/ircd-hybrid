/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_kill.h
 * @brief K-line configuration and lookup interface.
 */

#ifndef INCLUDED_conf_kill_h
#define INCLUDED_conf_kill_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "list.h"

struct io_addr;
struct address_index_entry;
struct hostmask_index_entry;

enum conf_kill_origin
{
  CONF_KILL_ORIGIN_INVALID,
  CONF_KILL_ORIGIN_CONFIG,
  CONF_KILL_ORIGIN_DATABASE
};

enum conf_kill_selector_type
{
  CONF_KILL_SELECTOR_ADDRESS,
  CONF_KILL_SELECTOR_HOSTMASK
};

union conf_kill_index_entry
{
  struct address_index_entry *address;
  struct hostmask_index_entry *hostmask;
};

struct conf_kill
{
  list_node_t node;
  char *user;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_kill_origin origin;

  enum conf_kill_selector_type selector_type;
  union conf_kill_index_entry index_entry;
};

struct conf_kill_spec
{
  const char *user;
  const char *host;
  const char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_kill_origin origin;
};

typedef void (*conf_kill_expire_callback_fn)(const struct conf_kill *, void *);

extern void conf_kill_clear_configuration(void);
extern void conf_kill_delete(struct conf_kill *);
extern void conf_kill_expire(uintmax_t, conf_kill_expire_callback_fn, void *);
extern void conf_kill_init(void);
extern bool conf_kill_format_host(const struct conf_kill *, char *, size_t);
extern bool conf_kill_matches(const struct conf_kill *, const struct io_addr *, const char *, const char *);
extern const list_t *conf_kill_get_list(void);
extern const struct conf_kill *conf_kill_find(const struct io_addr *, const char *, const char *);
extern const struct conf_kill *conf_kill_find_covering(const char *, const char *);
extern struct conf_kill *conf_kill_add(const struct conf_kill_spec *);
extern struct conf_kill *conf_kill_find_exact(const char *, const char *);
#endif  /* INCLUDED_conf_kill_h */

