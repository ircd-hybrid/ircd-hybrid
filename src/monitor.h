/*
 * SPDX-FileCopyrightText: 1997 Jukka Santala (Donwulff)
 * SPDX-FileCopyrightText: 2005-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file monitor.h
 * \brief Header including structures and prototypes for MONITOR support
 */

#ifndef INCLUDED_monitor_h
#define INCLUDED_monitor_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "list.h"

/** Monitor structure */
struct Monitor
{
  list_node_t node;  /**< List node; linked into monitor_hash */
  char *name;  /**< Name of the client to monitor */
  list_t monitored_by;  /**< List of clients that have this entry on their monitor list */
};

extern void monitor_clear_list(struct Client *);
extern void monitor_count_memory(uint32_t *const, size_t *const);
extern void monitor_notify_signoff(const struct Client *);
extern void monitor_notify_signon(const struct Client *);
extern void monitor_unsubscribe(struct Client *, const char *);
extern bool monitor_subscribe(struct Client *, const char *);
#endif  /* INCLUDED_monitor_h */
