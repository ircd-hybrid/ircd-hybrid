/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module_loader.h
 * @brief Native dynamic module loader interface.
 */

#ifndef INCLUDED_module_loader_h
#define INCLUDED_module_loader_h
#include <stdbool.h>
#include <stddef.h>

typedef void *module_loader_handle_t;

extern bool module_loader_build_path(char *, size_t, const char *, const char *);
extern bool module_loader_close(module_loader_handle_t);
extern bool module_loader_symbol(module_loader_handle_t, const char *, void **);
extern const char *module_loader_get_error(void);
extern module_loader_handle_t module_loader_open(const char *);
#endif  /* INCLUDED_module_loader_h */
