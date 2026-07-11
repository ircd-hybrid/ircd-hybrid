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

typedef void (*dns_callback_fnc)(void *, const struct io_addr *, const char *, size_t);

extern void resolver_init(event_manager_t);
extern void restart_resolver(void);
extern void delete_resolver_queries(const void *);
extern void gethost_byname_type(dns_callback_fnc , void *, const char *, int);
extern void gethost_byaddr(dns_callback_fnc, void *, const struct io_addr *);
#endif  /* INCLUDED_res_h */
