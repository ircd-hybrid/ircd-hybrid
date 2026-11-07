/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_module.h
 * @brief IRCd module ownership, registration, and failure policy.
 */

#ifndef INCLUDED_ircd_module_h
#define INCLUDED_ircd_module_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "module.h"

#define IRCD_MODULE_ABI_VERSION UINT32_C(1)

struct Command;
struct InfoEntry;
struct StatsHandler;
struct UserMode;

extern void ircd_module_apply_config(void);
extern void ircd_module_check_required(void);
extern void ircd_module_format_error(const char *, const struct module_error_info *, char *, size_t);
extern void ircd_module_log_error(const char *, const struct module_error_info *);
extern void ircd_module_post_update(void);
extern void ircd_module_shutdown(void);
extern bool ircd_module_init(void);
extern bool ircd_module_register_cap(unsigned int, const char *, const char *, char *, size_t);
extern bool ircd_module_register_commands(struct Command *, size_t, char *, size_t);
extern bool ircd_module_register_info_entries(const struct InfoEntry *, size_t, char *, size_t);
extern bool ircd_module_register_stats_handlers(const struct StatsHandler *, size_t, char *, size_t);
extern bool ircd_module_register_user_mode(struct UserMode *, char *, size_t);
extern module_manager_t *ircd_module_manager_get(void);
#endif  /* INCLUDED_ircd_module_h */
