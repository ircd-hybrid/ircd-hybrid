/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "user_mode.h"

static struct UserMode flood_mode =
{
  .mode_char = 'f',
  .mode_flag = &UMODE_FLOOD,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_user_mode(&flood_mode, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&flood_mode);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_flood",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
