/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.h: A header for the modules functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#ifndef INCLUDED_modules_h
#define INCLUDED_modules_h

#include "config.h"
#include "parse.h"

#include "ircd_handler.h"
#include "msg.h"
#include "memory.h"

struct module
{
  dlink_node node;
  char *name;
  const char *version;
  void *handle;
  void (*modremove)(void);
  int core;
};

struct module_path
{
  dlink_node node;
  char path[PATH_MAX + 1];
};

/* add a path */
extern void mod_add_path(const char *);
extern void mod_clear_paths(void);

/* load all modules */
extern void load_all_modules(int);

/* load core modules */
extern void load_core_modules(int);

/* Add this module to list of modules to be loaded from conf */
extern void add_conf_module(const char *);
/* load all modules listed in conf */
extern void load_conf_modules(void);

extern void _modinit(void);
extern void _moddeinit(void);

extern void dynlink_init(void);
extern int unload_one_module(const char *, int);
extern int modules_valid_suffix(const char *);
extern int load_one_module(const char *, int);
extern int load_a_module(const char *, int, int);
extern dlink_node *findmodule_byname(const char *);
extern void modules_init(void);
#endif /* INCLUDED_modules_h */
