/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
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
  .name = "account-notify",
  .flag = CAP_ACCOUNT_NOTIFY,
  .available = true
};

static hook_flow_t
user_account_change_hook(void *context)
{
  const ircd_hook_user_account_change_ctx *const ctx = context;
  struct Client *const client = ctx->client;

  if (client_is_user(client))
    monitor_notify_extended(client, CAP_ACCOUNT_NOTIFY, ":%s!%s@%s ACCOUNT %s",
                            client->name, client->username, client->host, client->account);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_cap(&capability_config, &capability, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_user_account_change, user_account_change_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_user_account_change, user_account_change_hook);
  cap_unregister(&capability);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "cap_account_notify",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
