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

extern void module_init(void);
extern void module_cleanup(void);
extern void module_set_base_path(const char *);
extern const char *module_get_error(void);
extern const char *module_get_attributes(const struct Module *);
extern bool module_load(const char *, bool);
extern bool module_unload(const char *);
extern struct Module *module_find(const char *);
extern struct ModuleConfig *module_config_find(const char *);
extern const list_t *module_get_list(void);
extern void module_add_config(const char *, bool, bool);
extern void module_clear_config(void);
extern bool module_reload_all(unsigned int *, unsigned int *, bool);
extern void module_load_all(bool);
#endif  /* INCLUDED_module_h */
