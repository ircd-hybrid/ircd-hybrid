/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2022 ircd-hybrid development team
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

/*! \file modules.h
 * \brief A header for the modules functions.
 * \version $Id$
 */

#ifndef INCLUDED_modules_h
#define INCLUDED_modules_h

struct module
{
  dlink_node node;
  char *name;
  const char *version;
  void *handle;
  void (*modinit)(void);
  void (*modexit)(void);
  bool is_resident;
  bool is_core;
};

struct module_path
{
  dlink_node node;
  char *path;
};

extern dlink_list *modules_get_list(void);
/* add a path */
extern void mod_add_path(const char *);
extern void modules_conf_clear(void);

/* load all modules */
extern void load_all_modules(bool);

/* load core modules */
extern void load_core_modules(bool);

/* Add this module to list of modules to be loaded from conf */
extern void add_conf_module(const char *);
/* load all modules listed in conf */
extern void load_conf_modules(void);
extern void modules_init(void);

extern bool unload_one_module(const char *, bool);
extern bool modules_valid_suffix(const char *);
extern bool load_one_module(const char *);
extern bool load_a_module(const char *, bool);
extern struct module *findmodule_byname(const char *);
#endif  /* INCLUDED_modules_h */
