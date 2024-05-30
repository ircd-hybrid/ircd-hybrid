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

/*! \file modules.c
 * \brief A module loader.
 */

#include "ltdl.h"
#include "stdinc.h"
#include "defaults.h"
#include "list.h"
#include "modules.h"
#include "log.h"
#include "send.h"
#include "conf.h"
#include "irc_string.h"
#include "memory.h"

static list_t modules_list;
static list_t modules_path;
static list_t modules_conf;

static const char *const core_module_table[] =
{
  "m_bmask.la",
  "m_die.la",
  "m_error.la",
  "m_join.la",
  "m_kick.la",
  "m_kill.la",
  "m_message.la",
  "m_mlock.la",
  "m_mode.la",
  "m_nick.la",
  "m_part.la",
  "m_quit.la",
  "m_server.la",
  "m_sjoin.la",
  "m_squit.la",
  "m_tmode.la",
  NULL
};

list_t *
modules_get_list(void)
{
  return &modules_list;
}

bool
modules_valid_suffix(const char *name)
{
  return ((name = strrchr(name, '.'))) && strcmp(name, ".la") == 0;
}

/* unload_one_module()
 *
 * inputs       - name of module to unload
 *              - 1 to say modules unloaded, 0 to not
 * output       - true if successful, false if error
 * side effects - module is unloaded
 */
bool
unload_one_module(const char *name, bool warn)
{
  struct module *modp = findmodule_byname(name);
  if (modp == NULL)
    return false;

  if (modp->modexit)
    modp->modexit();

  list_remove(&modp->node, &modules_list);
  io_free(modp->name);

  lt_dlclose(modp->handle);

  if (warn)
  {
    log_write(LOG_TYPE_IRCD, "Module %s unloaded", name);
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Module %s unloaded", name);
  }

  return true;
}

/* load_a_module()
 *
 * inputs       - path name of module, int to notice, int of core
 * output       - false if error true if success
 * side effects - loads a module if successful
 */
bool
load_a_module(const char *path, bool warn)
{
  const char *const name = io_basename(path);
  if (findmodule_byname(name))
    return false;

  lt_dlhandle handle = lt_dlopen(path);
  if (handle == NULL)
  {
    const char *err = ((err = lt_dlerror())) ? err : "<unknown>";

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Error loading module %s: %s",
                         name, err);
    log_write(LOG_TYPE_IRCD, "Error loading module %s: %s", name, err);
    return false;
  }

  struct module *modp = lt_dlsym(handle, "module_entry");
  if (modp == NULL)
  {
    const char *err = ((err = lt_dlerror())) ? err : "<unknown>";

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Error loading module %s: %s",
                         name, err);
    log_write(LOG_TYPE_IRCD, "Error loading module %s: %s", name, err);

    lt_dlclose(handle);
    return false;
  }

  modp->handle = handle;
  modp->name = io_strdup(name);
  list_add(modp, &modp->node, &modules_list);

  if (modp->modinit)
    modp->modinit();

  if (warn)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Module %s [handle: %p] loaded.",
                         name, handle);
    log_write(LOG_TYPE_IRCD, "Module %s [handle: %p] loaded.", name, handle);
  }

  return true;
}

/*
 * modules_init
 *
 * input	- NONE
 * output	- NONE
 * side effects	- The basic module manipulation modules are loaded
 */
void
modules_init(void)
{
  if (lt_dlinit())
  {
    log_write(LOG_TYPE_IRCD, "Couldn't initialize the libltdl run time dynamic link library: %s",
              lt_dlerror());
    exit(EXIT_FAILURE);
  }
}

/* mod_find_path()
 *
 * input	- path
 * output	- none
 * side effects - returns a module path from path
 */
static struct module_path *
mod_find_path(const char *path)
{
  list_node_t *node;

  LIST_FOREACH(node, modules_path.head)
  {
    struct module_path *mpath = node->data;

    if (strcmp(path, mpath->path) == 0)
      return mpath;
  }

  return NULL;
}

/* mod_add_path()
 *
 * input	- path
 * output	- NONE
 * side effects - adds path to list
 */
void
mod_add_path(const char *path)
{
  struct module_path *pathst;

  if (mod_find_path(path))
    return;

  pathst = io_calloc(sizeof(*pathst));
  pathst->path = io_strdup(path);
  list_add(pathst, &pathst->node, &modules_path);
}

/* add_conf_module
 *
 * input	- module name
 * output	- NONE
 * side effects - adds module to conf_mod
 */
void
add_conf_module(const char *name)
{
  struct module_path *pathst;

  pathst = io_calloc(sizeof(*pathst));
  pathst->path = io_strdup(name);
  list_add(pathst, &pathst->node, &modules_conf);
}

/* mod_clear_paths()
 *
 * input	- NONE
 * output	- NONE
 * side effects - clear the lists of paths and conf modules
 */
void
modules_conf_clear(void)
{
  while (modules_path.head)
  {
    struct module_path *path = modules_path.head->data;

    list_remove(&path->node, &modules_path);
    io_free(path->path);
    io_free(path);
  }

  while (modules_conf.head)
  {
    struct module_path *path = modules_conf.head->data;

    list_remove(&path->node, &modules_conf);
    io_free(path->path);
    io_free(path);
  }
}

/* findmodule_byname
 *
 * input        - name of module
 * output       - NULL if not found or pointer to module
 * side effects - NONE
 */
struct module *
findmodule_byname(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, modules_list.head)
  {
    struct module *modp = node->data;

    if (strcmp(modp->name, name) == 0)
      return modp;
  }

  return NULL;
}

/* load_all_modules()
 *
 * input        - int flag warn
 * output       - NONE
 * side effects - load all modules found in autoload directory
 */
void
load_all_modules(bool warn)
{
  DIR *system_module_dir = opendir(AUTOMODPATH);
  if (system_module_dir == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Could not load modules from %s: %s",
              AUTOMODPATH, strerror(errno));
    return;
  }

  struct dirent *ldirent;
  while ((ldirent = readdir(system_module_dir)))
  {
    if (modules_valid_suffix(ldirent->d_name))
    {
       char path[IO_PATH_MAX + 1];
       snprintf(path, sizeof(path), "%s/%s", AUTOMODPATH, ldirent->d_name);
       load_a_module(path, warn);
    }
  }

  closedir(system_module_dir);
}

/* load_conf_modules()
 *
 * input        - NONE
 * output       - NONE
 * side effects - load modules given in ircd.conf
 */
void
load_conf_modules(void)
{
  list_node_t *node;

  LIST_FOREACH(node, modules_conf.head)
  {
    struct module_path *mpath = node->data;

    if (findmodule_byname(mpath->path) == NULL)
      load_one_module(mpath->path);
  }
}

/* load_core_modules()
 *
 * input        - int flag warn
 * output       - NONE
 * side effects - core modules are loaded, if any fail, kill ircd
 */
void
load_core_modules(bool warn)
{
  for (unsigned int i = 0; core_module_table[i]; ++i)
  {
    char path[IO_PATH_MAX + 1];
    snprintf(path, sizeof(path), "%s%s", MODPATH, core_module_table[i]);

    if (load_a_module(path, warn) == false)
    {
      log_write(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd",
                core_module_table[i]);
      exit(EXIT_FAILURE);
    }
  }
}

/* load_one_module()
 *
 * input        - pointer to path
 *		- flagged as core module or not
 * output       - -1 if error
 * side effects - module is loaded if found.
 */
bool
load_one_module(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, modules_path.head)
  {
    const struct module_path *mpath = node->data;

    if (modules_valid_suffix(name) == false)
      continue;

    char path[IO_PATH_MAX + 1];
    snprintf(path, sizeof(path), "%s/%s", mpath->path, name);

    struct stat statbuf;
    if (strstr(path, "../") == NULL &&
        strstr(path, "/..") == NULL)
      if (stat(path, &statbuf) == 0)
        if (S_ISREG(statbuf.st_mode))  /* Regular files only please */
          return load_a_module(path, true);
  }

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Cannot locate module %s", name);
  log_write(LOG_TYPE_IRCD, "Cannot locate module %s", name);
  return false;
}
