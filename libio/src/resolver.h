/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file resolver.h
 * @brief Asynchronous DNS resolver interface.
 */

#ifndef INCLUDED_resolver_h
#define INCLUDED_resolver_h
#include <stdbool.h>
#include <stddef.h>

#include "address.h"
#include "event.h"

typedef void (*resolver_lookup_addr_callback_fn)(void *, const char *, size_t);
typedef void (*resolver_lookup_name_callback_fn)(void *, const struct io_addr *, size_t);

extern void resolver_cancel_by_context(const void *);
extern bool resolver_init(event_manager_t);
extern bool resolver_lookup_addr(resolver_lookup_addr_callback_fn, void *, const struct io_addr *);
extern bool resolver_lookup_name(resolver_lookup_name_callback_fn, void *, const char *, int);
extern bool resolver_nameserver_get(size_t, struct io_addr *);
extern bool resolver_reload(void);
extern size_t resolver_nameserver_count(void);
#endif  /* INCLUDED_resolver_h */
