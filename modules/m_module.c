/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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
 */

/*! \file m_module.c
 * \brief Includes required functions for processing the MODULE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief LOAD subcommand handler
 *         Attempts to load a module, throwing an error if
 *         the module has already been loaded
 * \param source_p Pointer to client issuing the command
 * \param parv     Argument vector 
 */
static void
module_load(struct Client *source_p, char *parv[])
{
  const char *m_bn = NULL;

  if (findmodule_byname((m_bn = libio_basename(parv[2]))))
  {
    sendto_one_notice(source_p, &me, ":Module %s is already loaded", m_bn);
    return;
  }

  load_one_module(parv[2]);
}

/*! \brief UNLOAD subcommand handler
 *         Attempts to unload a module, throwing an error if
 *         the module could not be found
 * \param source_p Pointer to client issuing the command
 * \param parv     Argument vector
 */
static void
module_unload(struct Client *source_p, char *parv[])
{
  const char *m_bn = NULL;
  const struct module *modp = NULL;

  if ((modp = findmodule_byname((m_bn = libio_basename(parv[2])))) == NULL)
  {
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
    return;
  }

  if (modp->flags & MODULE_FLAG_CORE)
  {
    sendto_one_notice(source_p, &me, ":Module %s is a core module and may not be unloaded",
                      m_bn);
    return;
  }

  if (modp->flags & MODULE_FLAG_NOUNLOAD)
  {
    sendto_one_notice(source_p, &me, ":Module %s is a resident module and may not be unloaded",
                      m_bn);
    return;
  }

  if (unload_one_module(m_bn, 1) == -1)
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
}

/*! \brief RELOAD subcommand handler
 *         Attempts to reload a module, throwing an error if
 *         the module could not be found or loaded
 * \param source_p Pointer to client issuing the command
 * \param parv     Argument vector
 */
static void
module_reload(struct Client *source_p, char *parv[])
{
  const char *m_bn = NULL;
  struct module *modp = NULL;
  int check_core = 0;

  if (!strcmp(parv[2], "*"))
  {
    unsigned int modnum = 0;
    dlink_node *ptr = NULL, *ptr_next = NULL;

    sendto_one_notice(source_p, &me, ":Reloading all modules");

    modnum = dlink_list_length(modules_get_list());

    DLINK_FOREACH_SAFE(ptr, ptr_next, modules_get_list()->head)
    {
      modp = ptr->data;

      if (!(modp->flags & MODULE_FLAG_NOUNLOAD))
        unload_one_module(modp->name, 0);
    }

    load_all_modules(0);
    load_conf_modules();
    load_core_modules(0);

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Module Restart: %u modules unloaded, %u modules loaded",
                         modnum, dlink_list_length(modules_get_list()));
    ilog(LOG_TYPE_IRCD, "Module Restart: %u modules unloaded, %u modules loaded",
         modnum, dlink_list_length(modules_get_list()));
    return;
  }

  if ((modp = findmodule_byname((m_bn = libio_basename(parv[2])))) == NULL)
  {
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
    return;
  }

  if (modp->flags & MODULE_FLAG_NOUNLOAD)
  {
    sendto_one_notice(source_p, &me, ":Module %s is a resident module and may not be unloaded",
                      m_bn);
    return;
  }

  check_core = (modp->flags & MODULE_FLAG_CORE) != 0;

  if (unload_one_module(m_bn, 1) == -1)
  {
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
    return;
  }

  if ((load_one_module(parv[2]) == -1) && check_core)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Error reloading core "
                         "module: %s: terminating ircd", parv[2]);
    ilog(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd", parv[2]);
    exit(0);
  }
}

/*! \brief LIST subcommand handler
 *         Shows a list of loaded modules
 * \param source_p Pointer to client issuing the command
 * \param parv     Argument vector
 */
static void
module_list(struct Client *source_p, char *parv[])
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, modules_get_list()->head)
  {
    const struct module *modp = ptr->data;

    if (!EmptyString(parv[2]) && match(parv[2], modp->name))
      continue;

    sendto_one_numeric(source_p, &me, RPL_MODLIST,
                       modp->name, modp->handle,
                       modp->version, (modp->flags & MODULE_FLAG_CORE) ? "(core)" : "");
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFMODLIST);
}

struct ModuleStruct
{
  const char *cmd;
  void (*handler)(struct Client *, char *[]);
  const int arg_required;
};

static const struct ModuleStruct module_cmd_table[] =
{
  { "LOAD",   module_load,   1 },
  { "UNLOAD", module_unload, 1 },
  { "RELOAD", module_reload, 1 },
  { "LIST",   module_list,   0 },
  { NULL,     NULL,          0 }
};

/*! \brief MODULE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = MODULE subcommand [LOAD, UNLOAD, RELOAD, LIST]
 *      - parv[2] = module name
 */
static int
mo_module(struct Client *source_p, int parc, char *parv[])
{
  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "module");
    return 0;
  }

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "MODULE");
    return 0;
  }

  for (const struct ModuleStruct *tab = module_cmd_table; tab->handler; ++tab)
  {
    if (irccmp(tab->cmd, parv[1]))
      continue;

    if (tab->arg_required && EmptyString(parv[2]))
    {
      sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "MODULE");
      return 0;
    }

    tab->handler(source_p, parv);
    return 0;
  }

  sendto_one_notice(source_p, &me, ":%s is not a valid option. "
                    "Choose from LOAD, UNLOAD, RELOAD, LIST",
                    parv[1]);
  return 0;
}

static struct Message module_msgtab =
{
  "MODULE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_module, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&module_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&module_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_NOUNLOAD
};
