/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file ircd_module.c
 * @brief IRCd module ownership, registration, and failure policy.
 */

#include "config.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "log.h"

#include "cap.h"
#include "client.h"
#include "command.h"
#include "info.h"
#include "ircd_exit.h"
#include "ircd_module.h"
#include "stats.h"
#include "user_mode.h"

static module_manager_t *module_manager;

void
ircd_module_format_error(const char *action, const struct module_error_info *error,
                         char *buffer, size_t buffer_size)
{
  assert(action);
  assert(error);
  assert(error->code != MODULE_SUCCESS);
  assert(buffer);
  assert(buffer_size > 0);

  char module_label[MODULE_NAME_CAPACITY + sizeof(" []") - 1] = "";
  if (!string_is_empty(error->module_name))
    snprintf(module_label, sizeof(module_label), " [%s]", error->module_name);

  const char *const description = module_strerror(error->code);
  if (error->cause != MODULE_SUCCESS)
    snprintf(buffer, buffer_size, "Module %s failed%s: %s (cause: %s)",
             action, module_label, description, module_strerror(error->cause));
  else
    snprintf(buffer, buffer_size, "Module %s failed%s: %s", action, module_label, description);

  if (!string_is_empty(error->message) && strcmp(error->message, description))
  {
    strlcat(buffer, ": ", buffer_size);
    strlcat(buffer, error->message, buffer_size);
  }
}

void
ircd_module_log_error(const char *action, const struct module_error_info *error)
{
  char message[IRCD_BUFSIZE];
  ircd_module_format_error(action, error, message, sizeof(message));

  log_write(LOG_TYPE_IRCD, "%s", message);

  if (!string_is_empty(error->cleanup_message))
    log_write(LOG_TYPE_IRCD, "Module cleanup failed [%s]: %s",
              error->module_name, error->cleanup_message);
}

bool
ircd_module_init(void)
{
  assert(module_manager == NULL);

  const struct module_manager_options options =
  {
    .application_abi_version = IRCD_MODULE_ABI_VERSION
  };
  struct module_error_info error;

  module_manager = module_manager_create(&options, &error);
  if (module_manager == NULL)
    ircd_module_log_error("manager initialization", &error);

  return module_manager != NULL;
}

module_manager_t *
ircd_module_manager_get(void)
{
  assert(module_manager);
  return module_manager;
}

static void
_ircd_module_shutdown_report(const char *name, enum module_report_outcome outcome,
                             const struct module_error_info *error, void *context)
{
  if (outcome == MODULE_REPORT_FAILED)
    ircd_module_log_error("shutdown", error);
  else
    log_write(LOG_TYPE_IRCD, "Module %s shut down", name);
}

void
ircd_module_shutdown(void)
{
  if (module_manager == NULL)
    return;

  struct module_error_info error;
  const enum module_error_code code =
    module_manager_shutdown(module_manager, _ircd_module_shutdown_report, NULL, &error);
  if (code == MODULE_ERR_BUSY)
    ircd_module_log_error("shutdown", &error);

  if (module_manager_count(module_manager) == 0 && module_manager_destroy(&module_manager, &error) != MODULE_SUCCESS)
    ircd_module_log_error("manager destruction", &error);
}

static void
_ircd_module_fail_required(const char *name)
{
  assert(!string_is_empty(name));
  ircd_exit_fmt(IRCD_EXIT_FAILURE, "Required module %s is not active", name);
}

static void
_ircd_module_find_failed_required(const module_t *module, void *context)
{
  char *const name = context;

  if (*name == '\0' && (module_get_effective_flags(module) & MODULE_FLAG_NO_REMOVE) &&
      module_get_state(module) != MODULE_STATE_ACTIVE)
    strlcpy(name, module_get_name(module), MODULE_NAME_CAPACITY);
}

void
ircd_module_check_required(void)
{
  assert(module_manager);

  const module_config_t *const configuration = module_manager_get_config(module_manager);
  for (size_t i = 0; i < module_config_count(configuration); ++i)
  {
    const struct module_config_entry *const config = module_config_get(configuration, i);
    if (!(config->policy_flags & MODULE_FLAG_NO_REMOVE))
      continue;

    const module_t *const module = module_manager_find(module_manager, config->name);
    if (module == NULL || module_get_state(module) != MODULE_STATE_ACTIVE)
      _ircd_module_fail_required(config->name);
  }

  char name[MODULE_NAME_CAPACITY] = "";
  struct module_error_info error;

  if (module_manager_foreach(module_manager, _ircd_module_find_failed_required, name, &error) != MODULE_SUCCESS)
  {
    ircd_module_log_error("required-module enumeration", &error);
    return;
  }

  if (*name)
    _ircd_module_fail_required(name);
}

void
ircd_module_post_update(void)
{
  assert(module_manager);

  user_mode_send_invalid();
  ircd_module_check_required();
}

static void
_ircd_module_activation_report(const char *name, enum module_report_outcome outcome,
                               const struct module_error_info *error, void *context)
{
  if (outcome == MODULE_REPORT_FAILED)
    ircd_module_log_error("configured activation", error);
  else if (outcome == MODULE_REPORT_SUCCESS)
    log_write(LOG_TYPE_IRCD, "Module %s activated", name);
}

void
ircd_module_apply_config(void)
{
  assert(module_manager);

  struct module_error_info error;
  struct module_activation_result result;
  const enum module_error_code code =
    module_manager_activate_configured(module_manager, &result, _ircd_module_activation_report, NULL, &error);
  if (code != MODULE_SUCCESS && result.failed == 0)
  {
    ircd_module_log_error("configured activation", &error);
    return;
  }

  ircd_module_post_update();
}

bool
ircd_module_register_commands(struct Command *commands, size_t count,
                              char *error_message, size_t error_message_size)
{
  assert(commands || count == 0);
  assert(error_message);
  assert(error_message_size > 0);

  size_t failed_index;
  const command_result_t result = command_add_array(commands, count, &failed_index);
  switch (result)
  {
    case COMMAND_SUCCESS:
      return true;

    case COMMAND_INVALID_NAME:
      snprintf(error_message, error_message_size, "Command %zu has an invalid name: %s",
               failed_index, string_or_default(commands[failed_index].name, "(empty)"));
      return false;

    case COMMAND_ALREADY_REGISTERED:
      snprintf(error_message, error_message_size, "Command %s is already registered",
               commands[failed_index].name);
      return false;
  }

  return false;
}

bool
ircd_module_register_info_entries(const struct InfoEntry *entries, size_t count,
                                  char *error_message, size_t error_message_size)
{
  assert(entries || count == 0);
  assert(error_message);
  assert(error_message_size > 0);

  size_t failed_index;
  const info_result_t result = info_register_array(entries, count, &failed_index);
  if (result == INFO_SUCCESS)
    return true;

  const struct InfoEntry *const entry = &entries[failed_index];
  snprintf(error_message, error_message_size, "Cannot register info %s/%s (result %u)",
           entry->namespace ? entry->namespace : "(global)", entry->name, (unsigned int)result);
  return false;
}

bool
ircd_module_register_stats_handlers(const struct StatsHandler *handlers, size_t count,
                                    char *error_message, size_t error_message_size)
{
  assert(handlers || count == 0);
  assert(error_message);
  assert(error_message_size > 0);

  for (size_t i = 0; i < count; ++i)
  {
    const struct StatsHandler *const handler = &handlers[i];
    const stats_result_t result = stats_register(handler->letter, handler->handler, handler->required_modes);
    if (result != STATS_SUCCESS)
    {
      snprintf(error_message, error_message_size, "Cannot register stats %c (result %u)",
               handler->letter, (unsigned int)result);

      while (i)
        stats_unregister(handlers[--i].letter);
      return false;
    }
  }

  return true;
}

bool
ircd_module_register_user_mode(struct UserMode *mode, char *error_message, size_t error_message_size)
{
  assert(mode);
  assert(error_message);
  assert(error_message_size > 0);

  const user_mode_result_t result = user_mode_register(mode);
  if (result == USER_MODE_SUCCESS)
    return true;

  snprintf(error_message, error_message_size, "Cannot register user mode %c (result %u)",
           mode->mode_char, (unsigned int)result);
  return false;
}

bool
ircd_module_register_cap(unsigned int flag, const char *name, const char *value,
                         char *error_message, size_t error_message_size)
{
  assert(!string_is_empty(name));
  assert(error_message);
  assert(error_message_size > 0);

  if (cap_find(name))
  {
    snprintf(error_message, error_message_size, "Capability %s is already registered", name);
    return false;
  }

  cap_register(flag, name, value);
  return true;
}
