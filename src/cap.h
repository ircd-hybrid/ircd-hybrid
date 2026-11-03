/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_cap_h
#define INCLUDED_cap_h
#include <stdbool.h>
#include <stdint.h>

#include "list.h"

struct Client;

enum
{
  CAP_MULTI_PREFIX      = 1 << 0,   /**< multi-prefix client capability */
  CAP_AWAY_NOTIFY       = 1 << 1,   /**< away-notify client capability */
  CAP_USERHOST_IN_NAMES = 1 << 2,   /**< userhost-in-names client capability */
  CAP_EXTENDED_JOIN     = 1 << 3,   /**< extended-join client capability */
  CAP_ACCOUNT_NOTIFY    = 1 << 4,   /**< account-notify client capability */
  CAP_INVITE_NOTIFY     = 1 << 5,   /**< invite-notify client capability */
  CAP_CHGHOST           = 1 << 6,   /**< chghost client capability */
  CAP_CAP_NOTIFY        = 1 << 7,   /**< CAP LS 302 cap-notify client capability */
  CAP_STANDARD_REPLIES  = 1 << 8,   /**< standard-replies client capability */
  CAP_EXTENDED_MONITOR  = 1 << 9,   /**< extended-monitor client capability */
  CAP_NO_IMPLICIT_NAMES = 1 << 10,  /**< no-implicit-names client capability */
  CAP_ECHO_MESSAGE      = 1 << 11,  /**< echo-message client capability */
  CAP_SASL              = 1 << 12,  /**< sasl client capability */
};

typedef enum
{
  CAP_SUCCESS = 0,
  CAP_INVALID_NAME,
  CAP_INVALID_FLAG,
  CAP_INVALID_VALUE,
  CAP_ALREADY_REGISTERED,
  CAP_FLAG_CONFLICT
} cap_result_t;

struct CapConfig
{
  const char *name;
  const char *value;
  uint32_t flag;
  bool available;
};

struct Cap
{
  char *name;
  char *value;
  uint32_t flag;
  size_t name_len;
  size_t value_len;
  bool available;
  list_node_t node;
};

/* Group synchronous notifications; every begin requires an end, including on failure. */
extern void cap_notify_batch_begin(void);
extern void cap_notify_batch_end(void);
extern cap_result_t cap_register(const struct CapConfig *, struct Cap **);
extern cap_result_t cap_update(struct Cap *, const char *, bool);
extern void cap_unregister(struct Cap **);
extern void cap_client_set_flags(struct Client *, uint32_t);
extern const struct Cap *cap_find(const char *);
extern const list_t *cap_get_list(void);
#endif  /* INCLUDED_cap_h */
