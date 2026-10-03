/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_auth.h
 * @brief Client authorization configuration and matching interface.
 */

#ifndef INCLUDED_conf_auth_h
#define INCLUDED_conf_auth_h
#include <stdbool.h>

#include "list.h"

struct io_addr;
struct ClassItem;
struct Client;

enum conf_auth_flags
{
  CONF_AUTH_FLAG_NO_TILDE                 = 1U << 0,
  CONF_AUTH_FLAG_REQUIRE_IDENT            = 1U << 1,
  CONF_AUTH_FLAG_EXEMPT_KLINE             = 1U << 2,
  CONF_AUTH_FLAG_EXEMPT_LIMITS            = 1U << 3,
  CONF_AUTH_FLAG_CAN_FLOOD                = 1U << 4,
  CONF_AUTH_FLAG_ENCRYPTED_PASSWORD       = 1U << 5,
  CONF_AUTH_FLAG_EXEMPT_RESV              = 1U << 6,
  CONF_AUTH_FLAG_WEBIRC                   = 1U << 7,
  CONF_AUTH_FLAG_EXEMPT_XLINE             = 1U << 8,
  CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH = 1U << 9
};

enum conf_auth_selector_type
{
  CONF_AUTH_SELECTOR_ADDRESS,
  CONF_AUTH_SELECTOR_HOSTMASK
};

enum conf_auth_lookup_result
{
  CONF_AUTH_LOOKUP_NONE,
  CONF_AUTH_LOOKUP_MATCH,
  CONF_AUTH_LOOKUP_PASSWORD_MISMATCH
};

enum conf_auth_result
{
  CONF_AUTH_SUCCESS,
  CONF_AUTH_NO_BLOCK,
  CONF_AUTH_KLINE_MATCH,
  CONF_AUTH_IDENT_REQUIRED,
  CONF_AUTH_PASSWORD_MISMATCH,
  CONF_AUTH_CLASS_TOTAL_LIMIT,
  CONF_AUTH_CLASS_LOCAL_IP_LIMIT,
  CONF_AUTH_CLASS_GLOBAL_IP_LIMIT,
  CONF_AUTH_CLASS_CIDR_LIMIT
};

struct conf_auth_rule
{
  list_node_t node;
  char *user;
  char *host;
  enum conf_auth_selector_type selector_type;
};

struct conf_auth
{
  list_node_t node;
  list_t rules;

  struct ClassItem *klass;
  char *password;
  char *spoof;
  unsigned int flags;
};

struct conf_auth_spec
{
  const char *user;
  const char *host;
  const char *password;
  const char *spoof;
  const char *class_name;
  unsigned int flags;
};

extern void conf_auth_clear(void);
extern void conf_auth_init(void);
extern bool conf_auth_add_rule(struct conf_auth *, const char *, const char *);
extern enum conf_auth_lookup_result conf_auth_find(const char *, const struct io_addr *, const char *, const char *, const struct conf_auth **);
extern const list_t *conf_auth_get_list(void);
extern const struct conf_auth *conf_auth_authorize_client(struct Client *, enum conf_auth_result *, const char **);
extern struct conf_auth *conf_auth_add(const struct conf_auth_spec *);
#endif  /* INCLUDED_conf_auth_h */
