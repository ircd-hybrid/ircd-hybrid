/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf_shared.h
 * \brief Implements shared {} block configuration management.
 */

#ifndef INCLUDED_conf_shared_h
#define INCLUDED_conf_shared_h
#include <stdint.h>

enum
{
  SHARED_KLINE   = 1 << 0,
  SHARED_UNKLINE = 1 << 1,
  SHARED_XLINE   = 1 << 2,
  SHARED_UNXLINE = 1 << 3,
  SHARED_RESV    = 1 << 4,
  SHARED_UNRESV  = 1 << 5,
  SHARED_LOCOPS  = 1 << 6,
  SHARED_DLINE   = 1 << 7,
  SHARED_UNDLINE = 1 << 8,
  SHARED_REHASH  = 1 << 9,
  SHARED_ALL     = UINT32_MAX
};

struct SharedItem
{
  list_node_t node;
  char *server;
  char *user;
  char *host;
  uint32_t type;
};

extern void shared_clear(void);
extern struct SharedItem *shared_make(void);
extern const list_t *shared_get_list(void);
extern const struct SharedItem *shared_find(uint32_t, const char *, const char *, const char *);
#endif  /* INCLUDED_conf_shared_h */
