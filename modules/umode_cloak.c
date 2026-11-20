/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "client.h"
#include "cloak.h"
#include "ircd_hook.h"
#include "ircd_module.h"
#include "user.h"
#include "user_mode.h"

static bool set_callback(struct Client *, user_mode_source_t);
static bool unset_callback(struct Client *, user_mode_source_t);

static struct UserMode cloak_mode =
{
  .mode_char = 'x',
  .set_callback = set_callback,
  .unset_callback = unset_callback
};

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (source != USER_MODE_SOURCE_REGULAR)
    return false;

  if (user_mode_has_mode(client, &cloak_mode))
    return false;

  if (client_is_local(client))
  {
    if (client_has_flag(client, FLAGS_SPOOF))
      return false;

    const char *const cloak = cloak_compute(&client->addr);
    if (cloak == NULL)
      return false;

    bool svshost = client_has_flag(client, FLAGS_INTRODUCED);
    user_set_hostmask(client, cloak, svshost);
  }

  return true;
}

static bool
unset_callback(struct Client *client, user_mode_source_t source)
{
  if (source != USER_MODE_SOURCE_REGULAR)
    return false;

  if (!user_mode_has_mode(client, &cloak_mode))
    return false;

  if (client_is_local(client))
    user_set_hostmask(client, client->realhost, true);
  return true;
}

static hook_flow_t
user_register_local_welcome_hook(void *context)
{
  const ircd_hook_user_register_ctx *const ctx = context;
  user_mode_set_mode_exec(ctx->client, &cloak_mode, USER_MODE_SOURCE_REGULAR);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&cloak_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_user_register_local_welcome, user_register_local_welcome_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_user_register_local_welcome, user_register_local_welcome_hook);
  user_mode_unregister(&cloak_mode);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_cloak",
  .flags = MODULE_FLAG_NO_REMOVE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
