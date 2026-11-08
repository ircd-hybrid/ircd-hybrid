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

#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "ircd_module.h"
#include "user_mode.h"

static enum extban_match
_extban_usermode_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  user_mode_action_t action = USER_MODE_ACTION_ADD;
  uint64_t modes_del = 0, modes_add = 0;

  for (const char *m = ban->host; *m; ++m)
  {
    switch (*m)
    {
      case '+':
        action = USER_MODE_ACTION_ADD;
        continue;
      case '-':
        action = USER_MODE_ACTION_DEL;
        continue;
      default:
      {
        const struct UserMode *const mode = user_mode_find(*m);
        if (mode == NULL)
          continue;

        if (action == USER_MODE_ACTION_ADD)
          modes_add |= mode->mode_bit;
        else
          modes_del |= mode->mode_bit;
      }
    }
  }


  if ((client->user_mode_flags & modes_add) == modes_add &&
      (client->user_mode_flags & modes_del) == 0)
    return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

static const struct Extban extban_usermode =
{
  .character = 'u',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
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
