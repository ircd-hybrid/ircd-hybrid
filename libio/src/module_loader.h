/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module_loader.h
 * @brief Native POSIX dynamic module loader interface.
 */

#ifndef INCLUDED_module_loader_h
#define INCLUDED_module_loader_h

#define MODULE_LOADER_ERROR_CAPACITY 512

typedef void *module_loader_handle_t;

typedef enum
{
  MODULE_LOADER_OK = 0,
  MODULE_LOADER_INVALID_ARGUMENT,
  MODULE_LOADER_OPEN_FAILED,
  MODULE_LOADER_SYMBOL_FAILED,
  MODULE_LOADER_CLOSE_FAILED
} module_loader_result_t;

struct module_loader_error
{
  char message[MODULE_LOADER_ERROR_CAPACITY];
};

extern module_loader_result_t module_loader_close(module_loader_handle_t *, struct module_loader_error *);
extern module_loader_result_t module_loader_open(const char *, module_loader_handle_t *, struct module_loader_error *);
extern module_loader_result_t module_loader_symbol(module_loader_handle_t, const char *, void **, struct module_loader_error *);
#endif  /* INCLUDED_module_loader_h */
