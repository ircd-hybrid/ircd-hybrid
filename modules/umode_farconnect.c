/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "ircd_hook.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode farconnect_mode =
{
  .mode_char = 'F',
  .mode_flag = &UMODE_FARCONNECT,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static hook_flow_t
user_register_hook(void *ctx_)
{
  ircd_hook_user_register_ctx *ctx = ctx_;
  if (client_has_flag(ctx->client->uplink, FLAGS_EOB))
    sendto_clients(UMODE_FARCONNECT, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Client connecting at %s: %s (%s@%s) [%s] [%s] <%s>",
                   ctx->client->uplink->name, ctx->client->name, ctx->client->username, ctx->client->realhost,
                   ctx->client->sockhost, ctx->client->info, ctx->client->id);

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
client_exit_hook(void *ctx_)
{
  ircd_hook_client_exit_ctx *ctx = ctx_;
  if (client_is_user(ctx->client) && client_has_flag(ctx->client->uplink, FLAGS_EOB))
    sendto_clients(UMODE_FARCONNECT, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Client exiting at %s: %s (%s@%s) [%s] [%s]",
                   ctx->client->uplink->name, ctx->client->name, ctx->client->username, ctx->client->realhost,
                   ctx->client->sockhost, ctx->reason);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&farconnect_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_user_register_remote, user_register_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_client_exit_remote, client_exit_hook, HOOK_PRIORITY_DEFAULT);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&farconnect_mode);
  hook_uninstall(ircd_hook_user_register_remote, user_register_hook);
  hook_uninstall(ircd_hook_client_exit_remote, client_exit_hook);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_farconnect",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
