/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_cap_h
#define INCLUDED_cap_h
#include <stdint.h>

#include "list.h"

enum
{
  CAP_MULTI_PREFIX     = 1 << 0,  /**< multi-prefix client capability */
  CAP_AWAY_NOTIFY      = 1 << 1,  /**< away-notify client capability */
  CAP_UHNAMES          = 1 << 2,  /**< userhost-in-names client capability */
  CAP_EXTENDED_JOIN    = 1 << 3,  /**< extended-join client capability */
  CAP_ACCOUNT_NOTIFY   = 1 << 4,  /**< account-notify client capability */
  CAP_INVITE_NOTIFY    = 1 << 5,  /**< invite-notify client capability */
  CAP_CHGHOST          = 1 << 6,  /**< chghost client capability */
  CAP_CAP_NOTIFY       = 1 << 7,  /**< CAP LS 302 cap-notify client capability */
  CAP_STANDARD_REPLIES = 1 << 8,  /**< standard-replies client capability */
};

struct Cap
{
  const char *name;
  const char *value;
  uint32_t flag;
  size_t name_len;
  size_t value_len;
  list_node_t node;
};

extern void cap_register(unsigned int, const char *, const char *);
extern void cap_unregister(const char *);
extern struct Cap *cap_find(const char *);
extern const list_t *cap_get_list(void);
#endif  /* INCLUDED_cap_h */
