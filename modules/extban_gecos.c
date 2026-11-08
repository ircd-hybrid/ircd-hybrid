/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_gecos.c
 * \brief Implements gecos (real name) based extended channel bans.
 */

#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "extban.h"
#include "ircd_module.h"

static bool
_extban_gecos_matches(const struct Client *client, const struct Channel *channel, const struct Ban *ban)
{
  return match(ban->extban_parameter, client->info) == 0;
}

static const struct Extban extban_gecos =
{
  .letter = 'r',
  .kind = EXTBAN_KIND_MATCHING,
  .list_types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX,
  .matches = _extban_gecos_matches
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_extban(&extban_gecos, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  extban_unregister(&extban_gecos);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "extban_gecos",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
