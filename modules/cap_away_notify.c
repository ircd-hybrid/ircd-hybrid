/*
 * SPDX-FileCopyrightText: 2013-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "cap.h"
#include "client.h"
#include "ircd_hook.h"
#include "ircd_module.h"
#include "monitor.h"

static struct Cap *capability;
static const struct CapConfig capability_config =
{
  .name = "away-notify",
  .flag = CAP_AWAY_NOTIFY,
  .available = true
};

static hook_flow_t
user_away_change_hook(void *context)
{
  const ircd_hook_user_away_change_ctx *const ctx = context;
  struct Client *const client = ctx->client;

  if (client->away_message)
    monitor_notify_extended(client, CAP_AWAY_NOTIFY, ":%s!%s@%s AWAY :%s",
                            client->name, client->username, client->host, client->away_message);
  else
    monitor_notify_extended(client, CAP_AWAY_NOTIFY, ":%s!%s@%s AWAY",
                            client->name, client->username, client->host);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_cap(&capability_config, &capability, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_user_away_change, user_away_change_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_user_away_change, user_away_change_hook);
  cap_unregister(&capability);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "cap_away_notify",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
