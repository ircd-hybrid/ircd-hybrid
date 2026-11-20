/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>

#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "ircd_module.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (!user_mode_has_flag(client, UMODE_INVISIBLE))
    ++Count.invisi;
  return true;
}

static bool
unset_callback(struct Client *client, user_mode_source_t source)
{
  if (user_mode_has_flag(client, UMODE_INVISIBLE))
    --Count.invisi;
  return true;
}

static struct UserMode invisible_mode =
{
  .mode_char = 'i',
  .mode_flag = &UMODE_INVISIBLE,
  .set_callback = set_callback,
  .unset_callback = unset_callback
};

static hook_flow_t
user_register_local_defaults_hook(void *context)
{
  const ircd_hook_user_register_ctx *const ctx = context;
  if (ConfigGeneral.invisible_on_connect)
    user_mode_set_mode_exec(ctx->client, &invisible_mode, USER_MODE_SOURCE_REGULAR);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&invisible_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_user_register_local_defaults, user_register_local_defaults_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_user_register_local_defaults, user_register_local_defaults_hook);
  user_mode_unregister(&invisible_mode);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_invisible",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
