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

#include "stdinc.h"
#include "tools.h"
#include "modules.h"
#include "s_log.h"
#include "ircd.h"
#include "client.h"
#include "send.h"
#include "s_conf.h"
#include "handlers.h"
#include "numeric.h"
#include "parse.h"
#include "ircd_defs.h"
#include "irc_string.h"
#include "memory.h"
#include "list.h"

/* -TimeMr14C:
 * I have moved the dl* function definitions and
 * the two functions (load_a_module / unload_a_module) to the
 * file dynlink.c 
 * And also made the necessary changes to those functions
 * to comply with shl_load and friends.
 * In this file, to keep consistency with the makefile, 
 * I added the ability to load *.sl files, too.
 * 27/02/2002
 */

#ifndef STATIC_MODULES

dlink_list mod_list = { NULL, NULL, 0 };

static const char *core_module_table[] =
{
  "m_die",
  "m_join",
  "m_kick",
  "m_kill",
  "m_message",
  "m_mode",
  "m_nick",
  "m_part",
  "m_quit",
  "m_server",
  "m_sjoin",
  "m_squit",
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


extern struct Message error_msgtab;

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
  mod_add_cmd(&modload_msgtab);
  mod_add_cmd(&modunload_msgtab);
  mod_add_cmd(&modreload_msgtab);
  mod_add_cmd(&modlist_msgtab);
  mod_add_cmd(&modrestart_msgtab);
  mod_add_cmd(&error_msgtab);
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
  struct module_path *mpath;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    mpath = ptr->data;

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
  struct module_path *pathst;
  dlink_node *ptr;
  dlink_node *next_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, mod_paths.head)
  {
    pathst = ptr->data;

    dlinkDelete(&pathst->node, &mod_paths);
    MyFree(pathst);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, conf_modules.head)
  {
    pathst = ptr->data;

    dlinkDelete(&pathst->node, &conf_modules);
    MyFree(pathst);
  }
}

/* findmodule_byname
 *
 * input        - name of module
 * output       - NULL if not found or pointer to module
 * side effects - NONE
 */
dlink_node *
findmodule_byname(const char *name)
{
  dlink_node *ptr;
  struct module *modp;

  DLINK_FOREACH(ptr, mod_list.head)
  {
    modp = ptr->data;

    if (strcmp(modp->name, name) == 0)
      return ptr;
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

  modules_init();

  if ((system_module_dir = opendir(AUTOMODPATH)) == NULL)
  {
    ilog(L_WARN, "Could not load modules from %s: %s",
         AUTOMODPATH, strerror(errno));
    return;
  }

  while ((ldirent = readdir(system_module_dir)) != NULL)
  {
    const char *offset = strrchr(ldirent->d_name, '.');

    if (offset && !strcmp(offset, SHARED_SUFFIX))
    {
       snprintf(module_fq_name, sizeof(module_fq_name), "%s/%s",
                AUTOMODPATH, ldirent->d_name);
       load_a_module(module_fq_name, warn, 0);
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
  struct module_path *mpath = NULL;

  DLINK_FOREACH(ptr, conf_modules.head)
  {
    mpath = ptr->data;

    if (findmodule_byname(mpath->path) == NULL)
      load_one_module(mpath->path, 0);
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
    snprintf(module_name, sizeof(module_name), "%s%s%s", MODPATH,
             core_module_table[i], SHARED_SUFFIX);

    if (load_a_module(module_name, warn, 1) == -1)
    {
      ilog(L_CRIT, "Error loading core module %s%s: terminating ircd",
           core_module_table[i], SHARED_SUFFIX);
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
load_one_module(char *path, int coremodule)
{
  dlink_node *ptr = NULL;
  char modpath[PATH_MAX + 1];
  struct stat statbuf;

  DLINK_FOREACH(ptr, mod_paths.head)
  {
    const struct module_path *mpath = ptr->data;

    snprintf(modpath, sizeof(modpath), "%s/%s", mpath->path, path);

    if (strstr(modpath, "../") == NULL &&
        strstr(modpath, "/..") == NULL) 
    {
      if (!stat(modpath, &statbuf))
      {
        if (S_ISREG(statbuf.st_mode))
        {
          /* Regular files only please */
          return load_a_module(modpath, 1, coremodule);
        }
      }
    }
  }

  sendto_realops_flags(UMODE_ALL, L_ALL,
                       "Cannot locate module %s", path);
  ilog(L_WARN, "Cannot locate module %s", path);
  return -1;
}

/* load a module .. */
static void
mo_modload(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char *m_bn;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if (findmodule_byname(m_bn) != NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is already loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  load_one_module(parv[1], 0);
}

/* unload a module .. */
static void
mo_modunload(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  char *m_bn;
  dlink_node *ptr;
  struct module *modp;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((ptr = findmodule_byname(m_bn)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  modp = ptr->data;

  if (modp->core == 1)
  {
    sendto_one(source_p,
               ":%s NOTICE %s :Module %s is a core module and may not be unloaded",
	       me.name, source_p->name, m_bn);
    return;
  }

  /* XXX might want to simply un dlink it here */

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
  char *m_bn;
  dlink_node *ptr;
  struct module *modp;
  int check_core;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  m_bn = basename(parv[1]);

  if ((ptr = findmodule_byname(m_bn)) == NULL)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  modp = ptr->data;
  check_core = modp->core;

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one(source_p, ":%s NOTICE %s :Module %s is not loaded",
               me.name, source_p->name, m_bn);
    return;
  }

  if ((load_one_module(parv[1], check_core) == -1) && check_core)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, "Error reloading core "
                         "module: %s: terminating ircd", parv[1]);
    ilog(L_CRIT, "Error loading core module %s: terminating ircd", parv[1]);
    exit(0);
  }
}

/* list modules .. */
static void
mo_modlist(struct Client *client_p, struct Client *source_p,
	   int parc, char *parv[])
{
  dlink_node *ptr;
  struct module *modp;

  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  DLINK_FOREACH(ptr, mod_list.head)
  {
    modp = ptr->data;

    if (parc > 1)
    {
      if (match(parv[1], modp->name))
      {
        sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                   modp->name, modp->address,
                   modp->version, modp->core?"(core)":"");
      }
    }
    else
    {
      sendto_one(source_p, form_str(RPL_MODLIST), me.name, parv[0],
                 modp->name, modp->address,
                 modp->version, modp->core?"(core)":"");
    }
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
  dlink_node *ptr;
  dlink_node *tptr;
  struct module *modp;
  
  if (!IsAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  sendto_one(source_p, ":%s NOTICE %s :Reloading all modules",
             me.name, source_p->name);

  modnum = dlink_list_length(&mod_list);

  DLINK_FOREACH_SAFE(ptr, tptr, mod_list.head)
  {
    modp = ptr->data;
    unload_one_module(modp->name, 0);
  }

  load_all_modules(0);
  load_conf_modules();
  load_core_modules(0);

  sendto_realops_flags(UMODE_ALL, L_ALL,
              "Module Restart: %u modules unloaded, %lu modules loaded",
			modnum, dlink_list_length(&mod_list));
  ilog(L_WARN, "Module Restart: %u modules unloaded, %lu modules loaded",
       modnum, dlink_list_length(&mod_list));
}

#else /* STATIC_MODULES */
#include "s_serv.h"

/* load_all_modules()
 *
 * input        - warn flag
 * output       - NONE
 * side effects - all the msgtabs are added for static modules
 */
void
load_all_modules(int warn)
{
  mod_add_cmd(&error_msgtab);
  mod_add_cmd(&accept_msgtab);
  mod_add_cmd(&admin_msgtab);
  mod_add_cmd(&away_msgtab);
  mod_add_cmd(&bmask_msgtab);
  mod_add_cmd(&cap_msgtab);
  mod_add_cmd(&capab_msgtab);
  mod_add_cmd(&cburst_msgtab);
  mod_add_cmd(&close_msgtab);
  mod_add_cmd(&connect_msgtab);
#ifdef HAVE_LIBCRYPTO
  mod_add_cmd(&challenge_msgtab);
  mod_add_cmd(&cryptlink_msgtab);
#endif
  mod_add_cmd(&die_msgtab);
  mod_add_cmd(&drop_msgtab);
  mod_add_cmd(&eob_msgtab);
  mod_add_cmd(&etrace_msgtab);
  mod_add_cmd(&gline_msgtab);
  add_capability("GLN", CAP_GLN, 1);
  mod_add_cmd(&hash_msgtab);
  mod_add_cmd(&ungline_msgtab);
  mod_add_cmd(&info_msgtab);
  mod_add_cmd(&invite_msgtab);
  mod_add_cmd(&ison_msgtab);
  mod_add_cmd(&join_msgtab);
  mod_add_cmd(&kick_msgtab);
  mod_add_cmd(&kill_msgtab);
  mod_add_cmd(&kline_msgtab);
  add_capability("KLN", CAP_KLN, 1);
  mod_add_cmd(&dline_msgtab);
  mod_add_cmd(&unkline_msgtab);
  mod_add_cmd(&undline_msgtab);
  mod_add_cmd(&knock_msgtab);
  add_capability("KNOCK", CAP_KNOCK, 1);
  mod_add_cmd(&knockll_msgtab);
  mod_add_cmd(&links_msgtab);
  mod_add_cmd(&list_msgtab);
  mod_add_cmd(&lljoin_msgtab);
  mod_add_cmd(&llnick_msgtab);
  mod_add_cmd(&locops_msgtab);
  mod_add_cmd(&lusers_msgtab);
  mod_add_cmd(&privmsg_msgtab);
  mod_add_cmd(&notice_msgtab);
  mod_add_cmd(&map_msgtab);
  mod_add_cmd(&mode_msgtab);
  mod_add_cmd(&motd_msgtab);
  mod_add_cmd(&names_msgtab);
  mod_add_cmd(&nburst_msgtab);
  mod_add_cmd(&nick_msgtab);
  mod_add_cmd(&omotd_msgtab);
  mod_add_cmd(&oper_msgtab);
  mod_add_cmd(&operwall_msgtab);
  mod_add_cmd(&part_msgtab);
  mod_add_cmd(&pass_msgtab);
  mod_add_cmd(&ping_msgtab);
  mod_add_cmd(&pong_msgtab);
  mod_add_cmd(&post_msgtab);
  mod_add_cmd(&get_msgtab);
  mod_add_cmd(&put_msgtab);
  mod_add_cmd(&quit_msgtab);
  mod_add_cmd(&rehash_msgtab);
  mod_add_cmd(&restart_msgtab);
  mod_add_cmd(&resv_msgtab);
  mod_add_cmd(&rkline_msgtab);
  mod_add_cmd(&rxline_msgtab);
  mod_add_cmd(&server_msgtab);
  mod_add_cmd(&set_msgtab);
  mod_add_cmd(&sid_msgtab);
  mod_add_cmd(&sjoin_msgtab);
  mod_add_cmd(&squit_msgtab);
  mod_add_cmd(&stats_msgtab);
  mod_add_cmd(&svinfo_msgtab);
  mod_add_cmd(&tb_msgtab);
  add_capability("TB", CAP_TB, 1);
  mod_add_cmd(&tburst_msgtab);
  add_capability("TBURST", CAP_TBURST, 1);
  mod_add_cmd(&testline_msgtab);
  mod_add_cmd(&testgecos_msgtab);
  mod_add_cmd(&testmask_msgtab);
  mod_add_cmd(&time_msgtab);
  mod_add_cmd(&tmode_msgtab);
  mod_add_cmd(&topic_msgtab);
  mod_add_cmd(&trace_msgtab);
  add_capability("UNKLN", CAP_UNKLN, 1);
  mod_add_cmd(&uid_msgtab);
  mod_add_cmd(&unresv_msgtab);
  mod_add_cmd(&unxline_msgtab);
  mod_add_cmd(&user_msgtab);
  mod_add_cmd(&userhost_msgtab);
  mod_add_cmd(&users_msgtab);
  mod_add_cmd(&version_msgtab);
  mod_add_cmd(&wallops_msgtab);
  mod_add_cmd(&who_msgtab);
  mod_add_cmd(&whois_msgtab);
  mod_add_cmd(&whowas_msgtab);
  mod_add_cmd(&xline_msgtab);
  mod_add_cmd(&help_msgtab);
  mod_add_cmd(&uhelp_msgtab);
#ifdef BUILD_CONTRIB
  mod_add_cmd(&bs_msgtab);
  mod_add_cmd(&botserv_msgtab);
  mod_add_cmd(&capture_msgtab);
  mod_add_cmd(&chanserv_msgtab);
  mod_add_cmd(&chghost_msgtab);
  mod_add_cmd(&chgident_msgtab);
  mod_add_cmd(&chgname_msgtab);
  mod_add_cmd(&classlist_msgtab);
  mod_add_cmd(&clearchan_msgtab);
  mod_add_cmd(&cs_msgtab);
  mod_add_cmd(&ctrace_msgtab);
  mod_add_cmd(&delspoof_msgtab);
  mod_add_cmd(&flags_msgtab);
  mod_add_cmd(&forcejoin_msgtab);
  mod_add_cmd(&forcepart_msgtab);
  mod_add_cmd(&global_msgtab);
  mod_add_cmd(&help_msgtab);
  mod_add_cmd(&uhelp_msgtab);
  mod_add_cmd(&helpserv_msgtab);
  mod_add_cmd(&hostserv_msgtab);
  mod_add_cmd(&identify_msgtab);
  mod_add_cmd(&jupe_msgtab);
  mod_add_cmd(&killhost_msgtab);
  mod_add_cmd(&ltrace_msgtab);
  mod_add_cmd(&memoserv_msgtab);
  mod_add_cmd(&mkpasswd_msgtab);
  mod_add_cmd(&ms_msgtab);
  mod_add_cmd(&nickserv_msgtab);
  mod_add_cmd(&ns_msgtab);
  mod_add_cmd(&ojoin_msgtab);
  mod_add_cmd(&operserv_msgtab);
  mod_add_cmd(&operspy_msgtab);
  mod_add_cmd(&opme_msgtab);
  mod_add_cmd(&os_msgtab);
  mod_add_cmd(&seenserv_msgtab);
  mod_add_cmd(&spoof_msgtab);
  mod_add_cmd(&statserv_msgtab);
  mod_add_cmd(&svsnick_msgtab);
  mod_add_cmd(&uncapture_msgtab);
  /* FIXME: what about spy*? */
#endif
}
#endif /* STATIC_MODULES */
