/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stddef.h>

#include "module.h"

#include "client.h"
#include "ircd_hook.h"
#include "ircd_module.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode registered_mode =
{
  .mode_char = 'r',
  .mode_flag = &UMODE_REGISTERED,
  .policy = USER_MODE_POLICY_SERVICE_ONLY,
};

static hook_flow_t
nick_change_prepare_hook(void *context)
{
  const ircd_hook_nick_change_ctx *const ctx = context;
  struct Client *const client = ctx->client;

  /* Registration follows IRC nickname identity, regardless of spelling or origin. */
  if (!ctx->identity_changed || !user_mode_has_mode(client, &registered_mode))
    return HOOK_FLOW_CONTINUE;

  const uint64_t mode_flags_old = client->user_mode_flags;
  user_mode_unset_mode(client, &registered_mode);
  if (client_is_local(client))
    user_mode_send(client, mode_flags_old, USER_MODE_SEND_USER);

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
who_send_hook(void *ctx_)
{
  ircd_hook_who_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_REGISTERED))
    if (ctx->modes_len < sizeof(ctx->modes) - 1)
      ctx->modes[ctx->modes_len++] = registered_mode.mode_char;

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_REGISTERED))
    sendto_one_numeric(ctx->source, &me, RPL_WHOISREGNICK, ctx->target->name);

  if (client_has_account(ctx->target))
    sendto_one_numeric(ctx->source, &me, RPL_WHOISACCOUNT, ctx->target->name, ctx->target->account, "is");

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&registered_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_nick_change_prepare, nick_change_prepare_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_who_send, who_send_hook, HOOK_PRIORITY_NORMAL);
  hook_install(ircd_hook_whois_send, whois_send_hook, HOOK_PRIORITY_ABOVE_NORMAL);

  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_nick_change_prepare, nick_change_prepare_hook);
  hook_uninstall(ircd_hook_who_send, who_send_hook);
  hook_uninstall(ircd_hook_whois_send, whois_send_hook);
  user_mode_unregister(&registered_mode);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_registered",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
