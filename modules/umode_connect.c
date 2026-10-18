/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "conf_class.h"
#include "ircd_hook.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode connect_mode =
{
  .mode_char = 'c',
  .mode_flag = &UMODE_CCONN,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static hook_flow_t
user_register_hook(void *ctx_)
{
  ircd_hook_user_register_ctx *ctx = ctx_;

  const char *class_name = client_get_class_name(ctx->client);
  sendto_clients(UMODE_CCONN, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Client connecting: %s (%s@%s) [%s] {%s} [%s] <%s>",
                 ctx->client->name, ctx->client->username, ctx->client->realhost, ctx->client->sockhost,
                 class_name, ctx->client->info, ctx->client->id);

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
client_exit_hook(void *ctx_)
{
  ircd_hook_client_exit_ctx *ctx = ctx_;

  if (client_is_user(ctx->client))
    sendto_clients(UMODE_CCONN, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Client exiting: %s (%s@%s) [%s] [%s]",
                   ctx->client->name, ctx->client->username, ctx->client->realhost, ctx->client->sockhost,
                   ctx->reason);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&connect_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_user_register_local, user_register_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_client_exit_local, client_exit_hook, HOOK_PRIORITY_DEFAULT);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&connect_mode);
  hook_uninstall(ircd_hook_user_register_local, user_register_hook);
  hook_uninstall(ircd_hook_client_exit_local, client_exit_hook);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_connect",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
