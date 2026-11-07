/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_exempt.h
 * @brief D-line address-exemption configuration and lookup interface.
 */
 
#ifndef INCLUDED_conf_exempt_h
#define INCLUDED_conf_exempt_h
#include <stdbool.h>
#include <stddef.h>

#include "list.h"

struct io_addr;
struct conf_exempt;

extern void conf_exempt_clear(void);
extern void conf_exempt_init(void);
extern bool conf_exempt_format_prefix(const struct conf_exempt *, char *, size_t);
extern const list_t *conf_exempt_get_list(void);
extern const struct conf_exempt *conf_exempt_add(const char *);
extern const struct conf_exempt *conf_exempt_find(const struct io_addr *);
#endif  /* INCLUDED_conf_exempt_h */
