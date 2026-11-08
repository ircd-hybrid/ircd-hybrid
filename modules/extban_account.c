/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_account.c
 * \brief Implements services account based extended channel bans.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "ircd_module.h"
#include "isupport.h"

static enum extban_match
_extban_account_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  assert(client->account[0]);

  if (client_has_account(client) && match(ban->host, client->account) == 0)
    return EXTBAN_MATCH;

  return EXTBAN_NO_MATCH;
}

static const struct Extban extban_account =
{
  .character = 'a',
  .type = EXTBAN_MATCHING,
  .types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = _extban_account_matches
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_extban(&extban_account, error_message, error_message_size))
    return false;

  const isupport_result_t result = isupport_add("ACCOUNTEXTBAN", "%c", extban_account.character);
  assert(result == ISUPPORT_SUCCESS);
  (void)result;
  return true;
}

static void
exit_handler(void *context)
{
  isupport_delete("ACCOUNTEXTBAN");
  extban_unregister(&extban_account);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "extban_account",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
