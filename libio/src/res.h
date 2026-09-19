/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file res.h
 * \brief ircd resolver functions
 */

#ifndef INCLUDED_res_h
#define INCLUDED_res_h
#include <stddef.h>

#include "address.h"
#include "event.h"

typedef void (*resolver_callback_fnc)(void *, const struct io_addr *, const char *, size_t);

extern void resolver_init(event_manager_t);
extern void resolver_restart(void);
extern void resolver_cancel_by_context(const void *);
extern void resolver_lookup_name(resolver_callback_fnc , void *, const char *, int);
extern void resolver_lookup_addr(resolver_callback_fnc, void *, const struct io_addr *);
#endif  /* INCLUDED_res_h */
