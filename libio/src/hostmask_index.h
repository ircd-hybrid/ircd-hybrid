/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_hostmask_index_h
#define INCLUDED_hostmask_index_h
#include <stdbool.h>
#include <stddef.h>

typedef struct hostmask_index hostmask_index_t;
typedef struct hostmask_index_entry hostmask_index_entry_t;

typedef bool (*hostmask_index_foreach_fn)(const hostmask_index_entry_t *, void *);

extern void hostmask_index_destroy(hostmask_index_t *);
extern bool hostmask_index_foreach_match(hostmask_index_t *, const char *, hostmask_index_foreach_fn, void *);
extern size_t hostmask_index_count(const hostmask_index_t *);
extern void *hostmask_index_entry_get_data(const hostmask_index_entry_t *);
extern void *hostmask_index_remove(hostmask_index_entry_t *);
extern hostmask_index_entry_t *hostmask_index_add(hostmask_index_t *, const char *, void *);
extern hostmask_index_t *hostmask_index_create(void);
extern const char *hostmask_index_entry_get_mask(const hostmask_index_entry_t *);
#endif  /* INCLUDED_hostmask_index_h */
