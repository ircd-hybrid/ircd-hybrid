/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stddef.h>

#include "module.h"

#include "client.h"
#include "ircd_hook.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode nickchange_mode =
{
  .mode_char = 'n',
  .mode_flag = &UMODE_NCHANGE,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static hook_flow_t
nick_change_hook(void *ctx_)
{
  ircd_hook_nick_change_ctx *ctx = ctx_;
  sendto_clients(UMODE_NCHANGE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Nick change: From %s to %s [%s@%s]",
                 ctx->client->name, ctx->nick, ctx->client->username, ctx->client->host);
  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&nickchange_mode);
  hook_install(ircd_hook_nick_change_local, nick_change_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_nick_change_remote, nick_change_hook, HOOK_PRIORITY_DEFAULT);
}

static void
exit_handler(void)
{
  user_mode_unregister(&nickchange_mode);
  hook_uninstall(ircd_hook_nick_change_local, nick_change_hook);
  hook_uninstall(ircd_hook_nick_change_remote, nick_change_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
