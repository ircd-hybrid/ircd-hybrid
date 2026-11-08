/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_usermode.c
 * \brief Implements usermode based extended channel bans.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "ircd_module.h"
#include "user_mode.h"

struct extban_usermode_constraints
{
  uint64_t required_modes;
  uint64_t forbidden_modes;
};

static bool
_extban_usermode_parse_parameter(const char *parameter, struct extban_usermode_constraints *constraints_out)
{
  if (string_is_empty(parameter))
    return false;

  struct extban_usermode_constraints constraints = { 0 };
  const char *cursor = parameter;
  bool require_modes = true;

  while (*cursor)
  {
    if (*cursor == '+' || *cursor == '-')
      require_modes = *cursor++ == '+';

    const char *const group_start = cursor;
    for (; *cursor && *cursor != '+' && *cursor != '-'; ++cursor)
    {
      const struct UserMode *const mode = user_mode_find(*cursor);
      if (mode == NULL)
        return false;

      if (require_modes)
        constraints.required_modes |= mode->mode_bit;
      else
        constraints.forbidden_modes |= mode->mode_bit;
    }

    if (cursor == group_start)
      return false;
  }

  if (constraints.required_modes & constraints.forbidden_modes)
    return false;

  if (constraints_out)
    *constraints_out = constraints;

  return true;
}

static bool
_extban_usermode_validate_parameter(const char *parameter)
{
  return _extban_usermode_parse_parameter(parameter, NULL);
}

static bool
_extban_usermode_matches(const struct Client *client, const struct Channel *channel, const struct Ban *ban)
{
  struct extban_usermode_constraints constraints;
  if (!_extban_usermode_parse_parameter(ban->extban_parameter, &constraints))
    return false;

  return (client->user_mode_flags & constraints.required_modes) == constraints.required_modes &&
         (client->user_mode_flags & constraints.forbidden_modes) == 0;
}

static const struct Extban extban_usermode =
{
  .letter = 'u',
  .kind = EXTBAN_KIND_MATCHING,
  .parameter_case_sensitive = true,
  .list_types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .validate_parameter = _extban_usermode_validate_parameter,
  .matches = _extban_usermode_matches
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_extban(&extban_usermode, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  extban_unregister(&extban_usermode);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "extban_usermode",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
