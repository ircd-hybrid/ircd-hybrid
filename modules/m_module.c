/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_module.c
 * \brief Includes required functions for processing the MODULE command.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "log.h"
#include "misc.h"
#include "module.h"

#include "client.h"
#include "conf_oper.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

static void
announce_load(const char *name, const void *handle, void *user_data)
{
  struct Client *source = user_data;
  sendto_one_notice(source, &me, ":Module %s [handle: %p] loaded", name, handle);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Module %s [handle: %p] loaded", name, handle);
}

static void
announce_unload(const char *name, const void *handle, void *user_data)
{
  struct Client *source = user_data;
  sendto_one_notice(source, &me, ":Module %s [handle: %p] unloaded", name, handle);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Module %s [handle: %p] unloaded", name, handle);
}

static void
announce_reload(const char *name, const void *handle, void *user_data)
{
  struct Client *source = user_data;
  sendto_one_notice(source, &me, ":Module %s [handle: %p] reloaded", name, handle);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Module %s [handle: %p] reloaded", name, handle);
}

/**
 * @brief Command to load a module.
 *
 * This function handles the load command from a client, loading the specified module.
 *
 * @param source Client issuing the command.
 * @param arg Module name to load.
 */
static void
module_cmd_load(struct Client *source, const char *arg)
{
  module_set_load_callback(announce_load);

  if (module_load(arg, true, source) != MODULE_SUCCESS)
    sendto_one_notice(source, &me, ":%s", module_get_error());

  module_set_load_callback(NULL);
}

/**
 * @brief Command to unload a module.
 *
 * This function handles the unload command from a client, unloading the specified module.
 *
 * @param source Client issuing the command.
 * @param arg Module name to unload.
 */
static void
module_cmd_unload(struct Client *source, const char *arg)
{
  module_set_unload_callback(announce_unload);

  if (module_unload(arg, false, source) != MODULE_SUCCESS)
    sendto_one_notice(source, &me, ":%s", module_get_error());
  else
    user_mode_send_invalid();  /* XXX hook */

  module_set_unload_callback(NULL);
}

/**
 * @brief Command to reload a single module.
 *
 * This function handles the reload command from a client, reloading the specified module.
 *
 * @param source Client issuing the command.
 * @param arg Module name to reload.
 */
static void
module_cmd_reload_single(struct Client *source, const char *arg)
{
  bool core = false;

  const struct Module *module = module_find(arg);
  if (module)
    core = module->core;

  if (module_unload(arg, true, NULL) != MODULE_SUCCESS)
  {
    sendto_one_notice(source, &me, ":%s", module_get_error());
    return;
  }

  module_set_load_callback(announce_reload);

  if (module_load(arg, true, source) != MODULE_SUCCESS)
    sendto_one_notice(source, &me, ":%s", module_get_error());
  else
    user_mode_send_invalid();  /* XXX hook */

  module_set_load_callback(NULL);

  if (core)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Error reloading core module: %s: terminating ircd", arg);
    log_write(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd", arg);
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Command to reload all modules.
 *
 * This function handles the reload command from a client, reloading all modules.
 *
 * @param source Client issuing the command.
 */
static void
module_cmd_reload_all(struct Client *source)
{
  bool core = false;
  unsigned int unloaded_count = 0, loaded_count = 0;

  if (module_unload_all(&unloaded_count) != MODULE_SUCCESS)
    sendto_one_notice(source, &me, ":%s", module_get_error());

  if (module_load_all(&loaded_count) != MODULE_SUCCESS)
  {
    sendto_one_notice(source, &me, ":%s", module_get_error());
    core = true;
  }
  else
    sendto_one_notice(source, &me, ":All modules reloaded successfully");

  user_mode_send_invalid();  /* XXX hook */

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Module reload: %u modules unloaded, %u modules loaded", unloaded_count, loaded_count);
  log_write(LOG_TYPE_IRCD, "Module reload: %u modules unloaded, %u modules loaded", unloaded_count, loaded_count);

  if (core == false)
    return;

  list_node_t *node;
  LIST_FOREACH(node, module_config_get_list()->head)
  {
    const struct ModuleConfig *const config = node->data;
    if (config->core && module_find(config->name) == NULL)
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Error loading core module %s: terminating ircd", config->name);
      log_write(LOG_TYPE_IRCD, "Error loading core module %s: terminating ircd", config->name);
      exit(EXIT_FAILURE);
    }
  }
}

/**
 * @brief Command to reload modules.
 *
 * This function handles the reload command from a client, reloading the specified module or all modules if the argument is "*".
 *
 * @param source Client issuing the command.
 * @param arg Module name to reload, or "*" to reload all modules.
 */
static void
module_cmd_reload(struct Client *source, const char *arg)
{
  if (strcmp(arg, "*") == 0)
    module_cmd_reload_all(source);
  else
    module_cmd_reload_single(source, arg);
}

/**
 * @brief Command to list loaded modules.
 *
 * This function handles the list command from a client, listing all loaded modules.
 *
 * @param source Client issuing the command.
 * @param arg Optional argument to filter modules.
 */
static void
module_cmd_list(struct Client *source, const char *arg)
{
  list_node_t *node;
  LIST_FOREACH(node, module_get_list()->head)
  {
    const struct Module *const module = node->data;
    if (!string_is_empty(arg) && match(arg, module->name))
      continue;

    sendto_one_numeric(source, &me, RPL_MODLIST,
                       module->name, module->handle, "*", module_get_attributes(module));
  }

  sendto_one_numeric(source, &me, RPL_ENDOFMODLIST);
}

/**
 * @brief MODULE subcommand table entry.
 */
struct ModuleSubcommand
{
  const char *const name;
  void (*const handler)(struct Client *, const char *);
  bool argument_required;
};

/**
 * @brief MODULE subcommand table.
 */
static const struct ModuleSubcommand module_subcommands[] =
{
  { .name = "LOAD", .handler = module_cmd_load, .argument_required = true },
  { .name = "UNLOAD", .handler = module_cmd_unload, .argument_required = true },
  { .name = "RELOAD", .handler = module_cmd_reload, .argument_required = true },
  { .name = "LIST", .handler = module_cmd_list, .argument_required = false }
};

static const struct ModuleSubcommand *
_module_subcommand_find(const char *name)
{
  for (size_t i = 0; i < IO_ARRAY_LENGTH(module_subcommands); ++i)
  {
    const struct ModuleSubcommand *const subcommand = &module_subcommands[i];
    if (io_strcasecmp(name, subcommand->name) == 0)
      return subcommand;
  }

  return NULL;
}

/*! \brief MODULE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
mo_module(struct Client *source, int parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_MODULE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "module");
    return;
  }

  const char *const subcommand_name = parv[1];
  const struct ModuleSubcommand *const subcommand = _module_subcommand_find(subcommand_name);
  if (subcommand == NULL)
  {
    sendto_one_notice(source, &me, ":%s is not a valid option. Choose from LOAD, UNLOAD, RELOAD, LIST",
                      subcommand_name);
    return;
  }

  const char *const module_name = parv[2];
  if (subcommand->argument_required && string_is_empty(module_name))
  {
    sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, "MODULE");
    return;
  }

  subcommand->handler(source, module_name);
}

static struct Command command_table =
{
  .name = "MODULE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_module, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .resident = true
};
