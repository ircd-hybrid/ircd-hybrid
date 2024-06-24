/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */


#ifndef INCLUDED_module_h
#define INCLUDED_module_h

#include "list.h"

#define MODULE_ERROR_BUFFER_SIZE 256

enum module_error_code
{
  MODULE_SUCCESS = 0,
  MODULE_ERR_INIT_FAILED,
  MODULE_ERR_SHUTDOWN_FAILED,
  MODULE_ERR_LOAD_FAILED,
  MODULE_ERR_INVALID_PATH,
  MODULE_ERR_INVALID_SUFFIX,
  MODULE_ERR_NOT_FOUND,
  MODULE_ERR_ALREADY_LOADED,
  MODULE_ERR_NOT_CONFIGURED,
  MODULE_ERR_ILLEGAL_TRAVERSAL,
  MODULE_ERR_INVALID_FILE,
  MODULE_ERR_CLOSE_FAILED,
  MODULE_ERR_CONFIG_EXISTS,
  MODULE_ERR_CORE_UNLOAD,
  MODULE_ERR_RESIDENT_UNLOAD,
  MODULE_ERR_COUNT
};

enum module_attributes
{
  MODULE_RESIDENT = 1 << 0,
  MODULE_CORE     = 1 << 1,
};

struct Module
{
  list_node_t node;
  char *name;
  void *handle;
  void (*init_handler)(void);
  void (*exit_handler)(void);
  bool resident;
  bool core;
};

struct ModuleConfig
{
  list_node_t node;
  char *name;
  bool resident;
  bool core;
};

extern enum module_error_code module_init(void);
extern enum module_error_code module_cleanup(void);
extern enum module_error_code module_load(const char *, bool, void *);
extern enum module_error_code module_unload(const char *, bool, void *);
extern enum module_error_code module_config_add(const char *, bool, bool);
extern enum module_error_code module_unload_all(unsigned int *);
extern enum module_error_code module_load_all(unsigned int *);
extern const list_t *module_get_list(void);
extern const list_t *module_config_get_list(void);
extern const char *module_get_error(void);
extern const char *module_get_attributes(const struct Module *);
extern struct Module *module_find(const char *);
extern struct ModuleConfig *module_config_find(const char *);
extern void module_set_base_path(const char *);
extern void module_config_clear(void);
extern void module_set_load_callback(void (*)(const char *, const void *, void *));
extern void module_set_unload_callback(void (*)(const char *, const void *, void *));
#endif  /* INCLUDED_module_h */
