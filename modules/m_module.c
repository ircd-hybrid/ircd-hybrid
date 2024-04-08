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

/*! \file m_module.c
 * \brief Includes required functions for processing the MODULE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief LOAD subcommand handler
 *         Attempts to load a module, throwing an error if
 *         the module has already been loaded
 * \param source_p Pointer to client issuing the command
 * \param arg      Additional argument which might be needed by this handler
 */
static void
module_load(struct Client *source_p, const char *arg)
{
  const char *m_bn = NULL;

  if (findmodule_byname((m_bn = libio_basename(arg))))
  {
    sendto_one_notice(source_p, &me, ":Module %s is already loaded", m_bn);
    return;
  }

  load_one_module(arg);
}

/*! \brief UNLOAD subcommand handler
 *         Attempts to unload a module, throwing an error if
 *         the module could not be found
 * \param source_p Pointer to client issuing the command
 * \param arg      Additional argument which might be needed by this handler
 */
static void
module_unload(struct Client *source_p, const char *arg)
{
  const char *m_bn = NULL;
  const struct module *modp = NULL;

  if ((modp = findmodule_byname((m_bn = libio_basename(arg)))) == NULL)
  {
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
    return;
  }

  if (modp->is_core)
  {
    sendto_one_notice(source_p, &me, ":Module %s is a core module and may not be unloaded",
                      m_bn);
    return;
  }

  if (modp->is_resident)
  {
    sendto_one_notice(source_p, &me, ":Module %s is a resident module and may not be unloaded",
                      m_bn);
    return;
  }

  if (unload_one_module(m_bn, true) == false)
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
}

/*! \brief RELOAD subcommand handler
 *         Attempts to reload a module, throwing an error if
 *         the module could not be found or loaded
 * \param source_p Pointer to client issuing the command
 * \param arg      Additional argument which might be needed by this handler
 */
static void
module_reload(struct Client *source_p, const char *arg)
{
  const char *m_bn = NULL;
  struct module *modp = NULL;

  if (strcmp(arg, "*") == 0)
  {
    unsigned int modnum = list_length(modules_get_list());

    sendto_one_notice(source_p, &me, ":Reloading all modules");

    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, modules_get_list()->head)
    {
      modp = node->data;

      if (modp->is_resident == false)
        unload_one_module(modp->name, false);
    }

    load_all_modules(0);
    load_conf_modules();
    load_core_modules(0);

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Module Restart: %u modules unloaded, %u modules loaded",
                         modnum, list_length(modules_get_list()));
    log_write(LOG_TYPE_IRCD, "Module Restart: %u modules unloaded, %u modules loaded",
              modnum, list_length(modules_get_list()));
    return;
  }

  if ((modp = findmodule_byname((m_bn = libio_basename(arg)))) == NULL)
  {
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
    return;
  }

  if (modp->is_resident)
  {
    sendto_one_notice(source_p, &me, ":Module %s is a resident module and may not be unloaded",
                      m_bn);
    return;
  }

  /* Cache modp->is_core for later use after the module is unloaded */
  bool is_core = modp->is_core;

  if (unload_one_module(m_bn, true) == false)
  {
    sendto_one_notice(source_p, &me, ":Module %s is not loaded", m_bn);
    return;
  }

  if (load_one_module(arg) == false && is_core)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Error reloading core module: %s: terminating ircd", arg);
    log_write(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd", arg);
    exit(EXIT_FAILURE);
  }
}

/*! \brief LIST subcommand handler
 *         Shows a list of loaded modules
 * \param source_p Pointer to client issuing the command
 * \param arg      Additional argument which might be needed by this handler
 */
static void
module_list(struct Client *source_p, const char *arg)
{
  list_node_t *node;

  LIST_FOREACH(node, modules_get_list()->head)
  {
    const struct module *modp = node->data;

    if (!EmptyString(arg) && match(arg, modp->name))
      continue;

    sendto_one_numeric(source_p, &me, RPL_MODLIST,
                       modp->name, modp->handle, "*", modp->is_core == true ? "(core)" : "");
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFMODLIST);
}

struct ModuleStruct
{
  const char *const cmd;
  void (*const handler)(struct Client *, const char *);
  bool arg_required;
};

static const struct ModuleStruct module_cmd_table[] =
{
  { .cmd = "LOAD", .handler = module_load, .arg_required = true },
  { .cmd = "UNLOAD", .handler = module_unload, .arg_required = true },
  { .cmd = "RELOAD", .handler = module_reload, .arg_required = true },
  { .cmd = "LIST", .handler = module_list },
  { .cmd = NULL }
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
static void
mo_module(struct Client *source_p, int parc, char *parv[])
{
  const char *const subcmd = parv[1];
  const char *const module = parv[2];

  if (!HasOFlag(source_p, OPER_FLAG_MODULE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "module");
    return;
  }

  for (const struct ModuleStruct *tab = module_cmd_table; tab->handler; ++tab)
  {
    if (irccmp(tab->cmd, subcmd))
      continue;

    if (tab->arg_required && EmptyString(module))
    {
      sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "MODULE");
      return;
    }

    tab->handler(source_p, module);
    return;
  }

  sendto_one_notice(source_p, &me, ":%s is not a valid option. "
                    "Choose from LOAD, UNLOAD, RELOAD, LIST",
                    subcmd);
}

static struct Command module_msgtab =
{
  .name = "MODULE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_module, .args_min = 2 }
};

static void
module_init(void)
{
  command_add(&module_msgtab);
}

static void
module_exit(void)
{
  command_del(&module_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
  .is_resident = true
};
