/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

#ifndef INCLUDED_cap_h
#define INCLUDED_cap_h
#include "list.h"

enum
{
  CAP_MULTI_PREFIX   = 1 << 0,  /**< multi-prefix client capability */
  CAP_AWAY_NOTIFY    = 1 << 1,  /**< away-notify client capability */
  CAP_UHNAMES        = 1 << 2,  /**< userhost-in-names client capability */
  CAP_EXTENDED_JOIN  = 1 << 3,  /**< extended-join client capability */
  CAP_ACCOUNT_NOTIFY = 1 << 4,  /**< account-notify client capability */
  CAP_INVITE_NOTIFY  = 1 << 5,  /**< invite-notify client capability */
  CAP_CHGHOST        = 1 << 6,  /**< chghost client capability */
  CAP_CAP_NOTIFY     = 1 << 7,  /**< CAP LS 302 cap-notify client capability */
};

#define HasCap(x, y) ((x)->connection->cap & (y))

struct Cap
{
  const char *name;
  const char *value;
  unsigned int flag;
  size_t name_len;
  size_t value_len;
  list_node_t node;
};

extern void cap_register(unsigned int, const char *, const char *);
extern void cap_unregister(const char *);
extern struct Cap *cap_find(const char *);
extern const list_t *cap_get_list(void);
#endif  /* INCLUDED_cap_h */
