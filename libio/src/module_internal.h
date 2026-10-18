/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_module_internal_h
#define INCLUDED_module_internal_h
#include "io.h"
#include "module.h"

extern void _module_config_destroy_owned(module_config_t *);
extern void _module_error_clear(struct module_error_info *);
extern enum module_error_code _module_config_acquire(module_config_t *, struct module_error_info *);
extern enum module_error_code _module_error_set(struct module_error_info *, enum module_error_code, const char *, const char *, ...) IO_AFP(4, 5);
#endif  /* INCLUDED_module_internal_h */
