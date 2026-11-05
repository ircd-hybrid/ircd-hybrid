/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file m_module.c
 * @brief MODULE command backed by the explicit libio module manager.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "log.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "conf_oper.h"
#include "ircd.h"
#include "ircd_module.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

struct module_command_context
{
  struct Client *source;
  const char *source_name;
};

static void
_module_report_error(const struct module_command_context *command, const char *action,
                     const struct module_error_info *error)
{
  char message[IRCD_BUFSIZE];
  ircd_module_format_error(action, error, message, sizeof(message));

  sendto_one_notice(command->source, &me, ":%s", message);
  log_write(LOG_TYPE_IRCD, "%s: %s", command->source_name, message);

  if (!string_is_empty(error->cleanup_message))
  {
    sendto_one_notice(command->source, &me, ":Module cleanup failed [%s]: %s",
                      error->module_name, error->cleanup_message);
    log_write(LOG_TYPE_IRCD, "%s: Module cleanup failed [%s]: %s",
              command->source_name, error->module_name, error->cleanup_message);
  }
}

static void
_module_announce(const struct module_command_context *command, const char *name, const char *action)
{
  sendto_one_notice(command->source, &me, ":Module %s %s", name, action);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Module %s %s by %s", name, action, command->source_name);
  log_write(LOG_TYPE_IRCD, "Module %s %s by %s", name, action, command->source_name);
}

static void
_module_reload_report(const char *name, enum module_report_outcome outcome,
                      const struct module_error_info *error, void *context)
{
  const struct module_command_context *const command = context;

  if (outcome != MODULE_REPORT_SUCCESS)
    return;

  log_write(LOG_TYPE_IRCD, "Module %s reloaded by %s", name, command->source_name);
}

static void
_module_reload_summary(const struct module_command_context *command, enum module_error_code code,
                       const struct module_reload_all_result *result, const struct module_error_info *error)
{
  char message[IRCD_BUFSIZE];

  if (code != MODULE_SUCCESS && !string_is_empty(error->module_name))
    snprintf(message, sizeof(message), "Module reload aborted at %s: %zu reloaded, %zu skipped",
             error->module_name, result->reloaded, result->skipped);
  else
    snprintf(message, sizeof(message), "Module reload %s: %zu reloaded, %zu skipped",
             code == MODULE_SUCCESS ? "completed" : "aborted", result->reloaded, result->skipped);

  sendto_one_notice(command->source, &me, ":%s", message);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "%s (requested by %s)", message, command->source_name);
  log_write(LOG_TYPE_IRCD, "%s (requested by %s)", message, command->source_name);
}

static void
_module_cmd_load(struct module_command_context *command, const char *name)
{
  struct module_error_info error;

  if (ircd_module_load(name, &error) != MODULE_SUCCESS)
    _module_report_error(command, "load", &error);
  else
    _module_announce(command, name, "loaded");

  ircd_module_post_update();
}

static void
_module_cmd_unload(struct module_command_context *command, const char *name)
{
  struct module_error_info error;

  if (ircd_module_unload(name, &error) != MODULE_SUCCESS)
    _module_report_error(command, "unload", &error);
  else
    _module_announce(command, name, "unloaded");

  ircd_module_post_update();
}

static void
_module_cmd_reload(struct module_command_context *command, const char *name)
{
  struct module_error_info error;

  if (strcmp(name, "*") == 0)
  {
    struct module_reload_all_result result;
    const enum module_error_code code =
      ircd_module_reload_all(&result, _module_reload_report, command, &error);

    if (code != MODULE_SUCCESS)
      _module_report_error(command, "reload", &error);

    _module_reload_summary(command, code, &result, &error);
  }
  else if (ircd_module_reload(name, &error) != MODULE_SUCCESS)
    _module_report_error(command, "reload", &error);
  else
    _module_announce(command, name, "reloaded");

  ircd_module_post_update();
}

struct module_list_context
{
  struct Client *source;
  const char *pattern;
};

static void
_module_list_entry(const module_t *module, void *context)
{
  const struct module_list_context *const list = context;
  const char *const name = module_get_name(module);

  if (!string_is_empty(list->pattern) && match(list->pattern, name))
    return;

  sendto_one_numeric(list->source, &me, RPL_MODLIST, name,
                     module_state_to_string(module_get_state(module)),
                     module_flags_to_string(module_get_effective_flags(module)));
}

static void
_module_cmd_list(struct module_command_context *command, const char *pattern)
{
  struct module_list_context context = { .source = command->source, .pattern = pattern };
  struct module_error_info error;

  if (module_manager_foreach(ircd_module_manager_get(), _module_list_entry, &context, &error) != MODULE_SUCCESS)
    _module_report_error(command, "enumeration", &error);

  sendto_one_numeric(command->source, &me, RPL_ENDOFMODLIST);
}

enum
{
  MODULE_INFO_LABEL_WIDTH = 24
};

static const char *
_module_info_flags_to_string(module_flags_t flags)
{
  switch (flags)
  {
    case 0: return "none";
    case MODULE_FLAG_NO_REMOVE: return "required";
    case MODULE_FLAG_NO_DEACTIVATE: return "resident";
    case MODULE_FLAG_NO_REMOVE | MODULE_FLAG_NO_DEACTIVATE: return "required,resident";
  }

  return "unknown";
}

static void
_module_info_field(struct Client *source, const char *label, const char *value)
{
  assert(source);
  assert(label);
  assert(strlen(label) <= MODULE_INFO_LABEL_WIDTH);
  assert(value);

  const char *const prefix = client_get_id_or_name(&me, source);
  const char *destination = client_get_id_or_name(source, source);
  if (string_is_empty(destination))
    destination = "*";

  const size_t overhead = strlen(prefix) + strlen(destination) +
    sizeof(": NOTICE  :  \r\n") - 1 + MODULE_INFO_LABEL_WIDTH;
  assert(overhead < IRCD_BUFSIZE);

  const size_t value_limit = IRCD_BUFSIZE - overhead;

  do
  {
    size_t length = 0;
    while (length < value_limit && value[length] && value[length] != '\r' && value[length] != '\n')
      ++length;

    /* Keep UTF-8 characters together; malformed byte sequences must still make progress. */
    if (length == value_limit)
    {
      size_t boundary = length;
      while (boundary && ((unsigned char)value[boundary] & 0xc0) == 0x80)
        --boundary;
      if (boundary)
        length = boundary;
    }

    sendto_one_notice(source, &me, ":  %-*s%.*s", MODULE_INFO_LABEL_WIDTH, label, (int)length, value);
    value += length;
    while (*value == '\r' || *value == '\n')
      ++value;
    label = "...";
  } while (*value);
}

static void
_module_info_count(struct Client *source, const char *label, size_t count)
{
  char value[sizeof(count) * CHAR_BIT + 1];
  snprintf(value, sizeof(value), "%zu", count);
  _module_info_field(source, label, value);
}

static void
_module_info_failure(struct Client *source, const struct module_error_info *error)
{
  const char *const failure = module_strerror(error->code);
  const char *const cause = error->cause != MODULE_SUCCESS ? module_strerror(error->cause) : NULL;

  _module_info_field(source, "Failure:", failure);

  if (cause && strcmp(cause, failure))
    _module_info_field(source, "Cause:", cause);

  if (!string_is_empty(error->message) && strcmp(error->message, failure) &&
      (cause == NULL || strcmp(error->message, cause)))
    _module_info_field(source, "Detail:", error->message);

  if (!string_is_empty(error->cleanup_message))
    _module_info_field(source, "Cleanup failure:", error->cleanup_message);
}

struct module_info_summary
{
  const module_config_t *configuration;
  size_t managed;
  size_t configured_managed;
  size_t active;
  size_t failed;
  size_t broken;
};

static void
_module_info_summary_entry(const module_t *module, void *context)
{
  struct module_info_summary *const summary = context;

  ++summary->managed;
  if (module_config_find(summary->configuration, module_get_name(module)))
    ++summary->configured_managed;

  switch (module_get_state(module))
  {
    case MODULE_STATE_ACTIVE: ++summary->active; break;
    case MODULE_STATE_FAILED: ++summary->failed; break;
    case MODULE_STATE_BROKEN: ++summary->broken; break;
    case MODULE_STATE_LOADING:
    case MODULE_STATE_RELOADING:
    case MODULE_STATE_UNLOADING:
      break;
  }
}

static void
_module_info_summary(struct module_command_context *command, module_manager_t *manager)
{
  struct module_info_summary summary = { .configuration = module_manager_get_config(manager) };
  struct module_error_info error;

  if (module_manager_foreach(manager, _module_info_summary_entry, &summary, &error) != MODULE_SUCCESS)
  {
    _module_report_error(command, "enumeration", &error);
    return;
  }

  const size_t configured = module_config_count(summary.configuration);
  const char *const path = module_config_get_base_path(summary.configuration);
  struct Client *const source = command->source;

  sendto_one_notice(source, &me, ":Module manager:");
  _module_info_field(source, "Configured path:", path ? path : "not set");
  _module_info_count(source, "Configured modules:", configured);
  _module_info_count(source, "Managed modules:", summary.managed);
  _module_info_count(source, "Active modules:", summary.active);
  _module_info_count(source, "Failed modules:", summary.failed);
  _module_info_count(source, "Broken modules:", summary.broken);
  _module_info_count(source, "Configured, unmanaged:", configured - summary.configured_managed);
  _module_info_count(source, "Managed, unconfigured:", summary.managed - summary.configured_managed);
}

static void
_module_cmd_info(struct module_command_context *command, const char *name)
{
  module_manager_t *const manager = ircd_module_manager_get();

  if (string_is_empty(name))
  {
    _module_info_summary(command, manager);
    return;
  }

  struct Client *const source = command->source;
  if (!module_name_is_valid(name))
  {
    sendto_one_notice(source, &me, ":Invalid module name");
    return;
  }

  const module_config_t *const configuration = module_manager_get_config(manager);
  const struct module_config_entry *const entry = module_config_find(configuration, name);
  const module_t *const module = module_manager_find(manager, name);

  if (entry == NULL && module == NULL)
  {
    sendto_one_notice(source, &me, ":Module %s is neither configured nor managed", name);
    return;
  }

  sendto_one_notice(source, &me, ":Module: %s", name);
  _module_info_field(source, "Configured:", entry ? "yes" : "no");
  _module_info_field(source, "State:", module ? module_state_to_string(module_get_state(module)) : "not loaded");
  _module_info_field(source, "Intrinsic flags:", module ?
                     _module_info_flags_to_string(module_get_intrinsic_flags(module)) : "unavailable");
  _module_info_field(source, "Configured flags:", entry ?
                     _module_info_flags_to_string(entry->policy_flags) : "n/a");
  _module_info_field(source, "Effective flags:", module ?
                     _module_info_flags_to_string(module_get_effective_flags(module)) : "unavailable");

  struct module_error_info error;
  if (module && module_get_failure(module, &error))
    _module_info_failure(source, &error);
}

struct module_subcommand
{
  const char *name;
  void (*handler)(struct module_command_context *, const char *);
  bool argument_required;
};

static const struct module_subcommand module_subcommands[] =
{
  { .name = "INFO", .handler = _module_cmd_info },
  { .name = "LIST", .handler = _module_cmd_list },
  { .name = "LOAD", .handler = _module_cmd_load, .argument_required = true },
  { .name = "RELOAD", .handler = _module_cmd_reload, .argument_required = true },
  { .name = "UNLOAD", .handler = _module_cmd_unload, .argument_required = true }
};

static const struct module_subcommand *
_module_subcommand_find(const char *name)
{
  for (size_t i = 0; i < IO_ARRAY_LENGTH(module_subcommands); ++i)
  {
    const struct module_subcommand *const subcommand = &module_subcommands[i];
    if (io_strcasecmp(name, subcommand->name) == 0)
      return subcommand;
  }

  return NULL;
}

static void
mo_module(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_MODULE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "module");
    return;
  }

  const char *const subcommand_name = parv[1];
  const struct module_subcommand *const subcommand = _module_subcommand_find(subcommand_name);
  if (subcommand == NULL)
  {
    sendto_one_notice(source, &me, ":Invalid MODULE option: %s", subcommand_name);
    return;
  }

  const char *const module_name = parv[2];
  if (subcommand->argument_required && string_is_empty(module_name))
  {
    sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, "MODULE");
    return;
  }

  /* Preserve attribution before native callbacks can change user-mode state. */
  client_format_oper_name_buffer_t source_name_buffer;
  struct module_command_context context =
  {
    .source = source,
    .source_name = client_format_oper_name(source, &source_name_buffer)
  };

  subcommand->handler(&context, module_name);
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

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_commands(&command_table, 1, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  command_del(&command_table);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "m_module",
  .flags = MODULE_FLAG_NO_DEACTIVATE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
