/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  modules.c: A module loader.
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

#include "ltdl.h"

#include "stdinc.h"
#include "list.h"
#include "modules.h"
#include "log.h"
#include "ircd.h"
#include "client.h"
#include "send.h"
#include "conf.h"
#include "numeric.h"
#include "parse.h"
#include "ircd_defs.h"
#include "irc_string.h"
#include "memory.h"


static dlink_list modules_list = { NULL, NULL, 0 };

static const char *unknown_ver = "<unknown>";

static const char *core_module_table[] =
{
  "m_die.la",
  "m_error.la",
  "m_join.la",
  "m_kick.la",
  "m_kill.la",
  "m_message.la",
  "m_mode.la",
  "m_nick.la",
  "m_part.la",
  "m_quit.la",
  "m_server.la",
  "m_sjoin.la",
  "m_squit.la",
  NULL
};

static dlink_list mod_paths = { NULL, NULL, 0 };
static dlink_list conf_modules = { NULL, NULL, 0 };

static void mo_modload(struct Client *, struct Client *, int, char *[]);
static void mo_modlist(struct Client *, struct Client *, int, char *[]);
static void mo_modreload(struct Client *, struct Client *, int, char *[]);
static void mo_modunload(struct Client *, struct Client *, int, char *[]);
static void mo_modrestart(struct Client *, struct Client *, int, char *[]);

struct Message modload_msgtab = {
 "MODLOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modload, m_ignore}
};

struct Message modunload_msgtab = {
 "MODUNLOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modunload, m_ignore}
};

struct Message modreload_msgtab = {
  "MODRELOAD", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modreload, m_ignore}
};

struct Message modlist_msgtab = {
 "MODLIST", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modlist, m_ignore}
};

struct Message modrestart_msgtab = {
 "MODRESTART", 0, 0, 0, 0, MFLG_SLOW, 0,
 {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_modrestart, m_ignore}
};


int
modules_valid_suffix(const char *name)
{
  return ((name = strrchr(name, '.'))) && !strcmp(name, ".la");
}

/* unload_one_module()
 *
 * inputs       - name of module to unload
 *              - 1 to say modules unloaded, 0 to not
 * output       - 0 if successful, -1 if error
 * side effects - module is unloaded
 */
int
unload_one_module(const char *name, int warn)
{
  struct module *modp = NULL;

  if ((modp = findmodule_byname(name)) == NULL)
    return -1;

  if (modp->modexit)
   modp->modexit();

  assert(dlink_list_length(&modules_list) > 0);
  dlinkDelete(&modp->node, &modules_list);
  MyFree(modp->name);

  lt_dlclose(modp->handle);

  if (warn == 1)
  {
    ilog(LOG_TYPE_IRCD, "Module %s unloaded", name);
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s unloaded", name);
  }

  return 0;
}

/* load_a_module()
 *
 * inputs       - path name of module, int to notice, int of core
 * output       - -1 if error 0 if success
 * side effects - loads a module if successful
 */
int
load_a_module(const char *path, int warn)
{
  lt_dlhandle tmpptr = NULL;
  const char *mod_basename = NULL;
  struct module *modp = NULL;

  if (findmodule_byname((mod_basename = libio_basename(path))))
    return 1;

  if (!(tmpptr = lt_dlopen(path))) {
    const char *err = ((err = lt_dlerror())) ? err : "<unknown>";

    sendto_realops_flags(UMODE_ALL, L_ALL, "Error loading module %s: %s",
                         mod_basename, err);
    ilog(LOG_TYPE_IRCD, "Error loading module %s: %s", mod_basename, err);
    return -1;
  }

  if ((modp = lt_dlsym(tmpptr, "module_entry")) == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Module %s has no module_entry export",
                         mod_basename);
    ilog(LOG_TYPE_IRCD, "Module %s has no module_entry export", mod_basename);
    lt_dlclose(tmpptr);
    return -1;
  }

  modp->handle = tmpptr;

  if (EmptyString(modp->version))
    modp->version = unknown_ver;

  DupString(modp->name, mod_basename);
  dlinkAdd(modp, &modp->node, &modules_list);

  if (modp->modinit)
    modp->modinit();

  if (warn == 1)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
                         "Module %s [version: %s handle: %p] loaded.",
                         modp->name, modp->version, tmpptr);
    ilog(LOG_TYPE_IRCD, "Module %s [version: %s handle: %p] loaded.",
         modp->name, modp->version, tmpptr);
  }

  return 0;
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
    ilog(LOG_TYPE_IRCD, "Couldn't initialize the libltdl run time dynamic"
         " link library. Exiting.");
    exit(0);
  }

  mod_add_cmd(&modload_msgtab);
  mod_add_cmd(&modunload_msgtab);
  mod_add_cmd(&modreload_msgtab);
  mod_add_cmd(&modlist_msgtab);
  mod_add_cmd(&modrestart_msgtab);
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
  dlink_node *ptr;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    struct module_path *mpath = ptr->data;

    if (!strcmp(path, mpath->path))
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

  pathst = MyMalloc(sizeof(struct module_path));

  strlcpy(pathst->path, path, sizeof(pathst->path));
  dlinkAdd(pathst, &pathst->node, &mod_paths);
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

  pathst = MyMalloc(sizeof(struct module_path));

  strlcpy(pathst->path, name, sizeof(pathst->path));
  dlinkAdd(pathst, &pathst->node, &conf_modules);
}

/* mod_clear_paths()
 *
 * input	- NONE
 * output	- NONE
 * side effects - clear the lists of paths and conf modules
 */
void
mod_clear_paths(void)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, mod_paths.head)
  {
    dlinkDelete(ptr, &mod_paths);
    MyFree(ptr->data);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, conf_modules.head)
  {
    dlinkDelete(ptr, &conf_modules);
    MyFree(ptr->data);
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
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, modules_list.head)
  {
    struct module *modp = ptr->data;

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
load_all_modules(int warn)
{
  DIR *system_module_dir = NULL;
  struct dirent *ldirent = NULL;
  char module_fq_name[PATH_MAX + 1];

  if ((system_module_dir = opendir(AUTOMODPATH)) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "Could not load modules from %s: %s",
         AUTOMODPATH, strerror(errno));
    return;
  }

  while ((ldirent = readdir(system_module_dir)) != NULL)
  {
    if (modules_valid_suffix(ldirent->d_name))
    {
       snprintf(module_fq_name, sizeof(module_fq_name), "%s/%s",
                AUTOMODPATH, ldirent->d_name);
       load_a_module(module_fq_name, warn);
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
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, conf_modules.head)
  {
    struct module_path *mpath = ptr->data;

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
load_core_modules(int warn)
{
  char module_name[PATH_MAX + 1];
  int i = 0;

  for (; core_module_table[i]; ++i)
  {
    snprintf(module_name, sizeof(module_name), "%s%s",
             MODPATH, core_module_table[i]);

    if (load_a_module(module_name, warn) == -1)
    {
      ilog(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd",
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
int
load_one_module(const char *path)
{
  dlink_node *ptr = NULL;
  char modpath[PATH_MAX + 1];
  struct stat statbuf;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    const struct module_path *mpath = ptr->data;

    snprintf(modpath, sizeof(modpath), "%s/%s", mpath->path, path);

    if (!modules_valid_suffix(path))
      continue;

    if (strstr(modpath, "../") == NULL &&
        strstr(modpath, "/..") == NULL) 
      if (!stat(modpath, &statbuf))
        if (S_ISREG(statbuf.st_mode))  /* Regular files only please */
          return load_a_module(modpath, 1);
  }

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "Cannot locate module %s", path);
  ilog(LOG_TYPE_IRCD, "Cannot locate module %s", path);
  return -1;
}

/* load a module .. */
static void
mo_modload(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  const char *m_bn = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = libio_basename(parv[1]);

  if (findmodule_byname(m_bn) != NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is already loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  load_one_module(parv[1]);
}

/* unload a module .. */
static void
mo_modunload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  const char *m_bn = NULL;
  struct module *modp = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = libio_basename(parv[1]);

  if ((modp = findmodule_byname(m_bn)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  if (modp->flags & MODULE_FLAG_CORE)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Module %s is a core module and may not be unloaded",
	       me.name, source_p->name, m_bn);
    return;
  }

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
  }
}

/* unload and load in one! */
static void
mo_modreload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  const char *m_bn = NULL;
  struct module *modp = NULL;
  int check_core;

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = libio_basename(parv[1]);

  if ((modp = findmodule_byname(m_bn)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  check_core = (modp->flags & MODULE_FLAG_CORE) != 0;

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  if ((load_one_module(parv[1]) == -1) && check_core)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Error reloading core "
                         "module: %s: terminating ircd", parv[1]);
    ilog(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd", parv[1]);
    exit(0);
  }
}

/* list modules .. */
static void
mo_modlist(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{
  const dlink_node *ptr = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  DLINK_FOREACH(ptr, modules_list.head)
  {
    const struct module *modp = ptr->data;

    if (parc > 1 && !match(parv[1], modp->name))
      continue;

    sendto_one(source_p, form_str(RPL_MODLIST), me.name, source_p->name,
               modp->name, modp->handle,
               modp->version, (modp->flags & MODULE_FLAG_CORE) ?"(core)":"");
  }

  sendto_one(source_p, form_str(RPL_ENDOFMODLIST),
             me.name, source_p->name);
}

/* unload and reload all modules */
static void
mo_modrestart(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  unsigned int modnum = 0;
  dlink_node *ptr = NULL, *ptr_next = NULL;

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
             me.name, source_p->name);

  modnum = dlink_list_length(&modules_list);

  DLINK_FOREACH_SAFE(ptr, ptr_next, modules_list.head)
  {
    struct module *modp = ptr->data;
    unload_one_module(modp->name, 0);
  }

  load_all_modules(0);
  load_conf_modules();
  load_core_modules(0);

  sendto_realops_flags(UMODE_ALL, L_ALL,
                      "Module Restart: %u modules unloaded, %u modules loaded",
			modnum, dlink_list_length(&modules_list));
  ilog(LOG_TYPE_IRCD, "Module Restart: %u modules unloaded, %u modules loaded",
       modnum, dlink_list_length(&modules_list));
}
