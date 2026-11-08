/*
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban_join.c
 * \brief Implements join restriction extended channel bans.
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "channel_mode.h"
#include "extban.h"
#include "ircd_module.h"

static const struct Extban extban_join =
{
  .letter = 'j',
  .kind = EXTBAN_KIND_ACTING,
  .list_types = CHFL_BAN | CHFL_EXCEPTION,
  .flag_binding = &EXTBAN_JOIN
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_extban(&extban_join, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  extban_unregister(&extban_join);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "extban_join",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
