/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_ident_h
#define INCLUDED_ident_h
#include <stdbool.h>
#include <stdint.h>

typedef void (*ident_callback_fn)(void *, const char *);

extern void ident_cancel_by_context(const void *);
extern bool ident_start(ident_callback_fn, void *, int, uintmax_t);
#endif  /* INCLUDED_ident_h */
