/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_conf_resv_h
#define INCLUDED_conf_resv_h
#include <stdbool.h>
#include <stdint.h>

#include "address.h"
#include "list.h"

struct Client;

enum conf_resv_origin
{
  CONF_RESV_ORIGIN_INVALID,
  CONF_RESV_ORIGIN_CONFIG,
  CONF_RESV_ORIGIN_DATABASE
};

struct conf_resv
{
  list_node_t node;
  list_t exemptions;
  char *mask;
  char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_resv_origin origin;
};

struct conf_resv_exempt
{
  list_node_t node;
  char *nick;
  char *user;
  char *host;
  struct io_addr address;
  unsigned int prefix_length;
};

struct conf_resv_spec
{
  const char *mask;
  const char *reason;
  const list_t *exemptions;
  uintmax_t created_at;
  uintmax_t expires_at;
  enum conf_resv_origin origin;
};

typedef void (*conf_resv_expire_callback_fn)(const struct conf_resv *, void *);

extern void conf_resv_clear_configuration(void);
extern void conf_resv_expire(uintmax_t, conf_resv_expire_callback_fn, void *);
extern bool conf_resv_exempts_client(const struct conf_resv *, const struct Client *);
extern bool conf_resv_remove_active_exact(const char *);
extern const list_t *conf_resv_channel_get_list(void);
extern const list_t *conf_resv_nick_get_list(void);
extern const struct conf_resv *conf_resv_add(const struct conf_resv_spec *);
extern const struct conf_resv *conf_resv_find(const char *);
extern const struct conf_resv *conf_resv_find_exact(const char *);
extern const struct conf_resv *conf_resv_find_active_exact(const char *);
#endif  /* INCLUDED_conf_resv_h */
