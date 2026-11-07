/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file address_index.h
 * @brief Indexed matching of IPv4 and IPv6 network prefixes.
 */

#ifndef INCLUDED_address_index_h
#define INCLUDED_address_index_h
#include <stdbool.h>
#include <stddef.h>

struct io_addr;

typedef struct address_index address_index_t;
typedef struct address_index_entry address_index_entry_t;

typedef bool (*address_index_foreach_fn)(const address_index_entry_t *, void *);

extern void address_index_destroy(address_index_t *);
extern void address_index_entry_get_prefix(const address_index_entry_t *, struct io_addr *, unsigned int *);
extern bool address_index_foreach_match(address_index_t *, const struct io_addr *, address_index_foreach_fn, void *);
extern size_t address_index_count(const address_index_t *);
extern void *address_index_entry_get_data(const address_index_entry_t *);
extern void *address_index_remove(address_index_entry_t *);
extern address_index_entry_t *address_index_add(address_index_t *, const struct io_addr *, unsigned int, void *);
extern address_index_t *address_index_create(void);
#endif  /* INCLUDED_address_index_h */
