/*
 * SPDX-FileCopyrightText: 1998-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_conf_gecos_h
#define INCLUDED_conf_gecos_h
#include <stdbool.h>
#include <stdint.h>

#include "list.h"

enum conf_gecos_origin
{
  CONF_GECOS_ORIGIN_INVALID,
  CONF_GECOS_ORIGIN_CONFIG,
  CONF_GECOS_ORIGIN_DATABASE
};

struct conf_gecos
{
  list_node_t node;
  char *mask;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_gecos_origin origin;
};

struct conf_gecos_spec
{
  const char *mask;
  const char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_gecos_origin origin;
};

typedef void (*conf_gecos_expire_callback_fn)(const struct conf_gecos *, void *);

extern void conf_gecos_clear_configuration(void);
extern void conf_gecos_expire(uintmax_t, conf_gecos_expire_callback_fn, void *);
extern bool conf_gecos_remove_active_exact(const char *);
extern const list_t *conf_gecos_get_list(void);
extern const struct conf_gecos *conf_gecos_add(const struct conf_gecos_spec *);
extern const struct conf_gecos *conf_gecos_find(const char *);
extern const struct conf_gecos *conf_gecos_find_exact(const char *);
extern const struct conf_gecos *conf_gecos_find_active_exact(const char *);
#endif  /* INCLUDED_conf_gecos_h */
