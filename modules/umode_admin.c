/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "conf_oper.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  return !client_is_local(client) || client_has_oper_flag(client, OPER_FLAG_ADMIN);
}

static struct UserMode admin_mode =
{
  .mode_char = 'a',
  .mode_flag = &UMODE_ADMIN,
  .policy = USER_MODE_POLICY_OPER_ONLY | USER_MODE_POLICY_MANUAL_ONLY,
  .set_callback = set_callback
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_user_mode(&admin_mode, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&admin_mode);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_admin",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
