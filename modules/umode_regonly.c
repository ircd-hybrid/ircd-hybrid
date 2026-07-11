/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "client.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode regonly_mode =
{
  .mode_char = 'R',
  .mode_flag = &UMODE_REGONLY
};

static hook_flow_t
msg_client_source_local_hook(void *ctx_)
{
  ircd_hook_msg_client_ctx *ctx = ctx_;
  if (!user_mode_has_flag(ctx->target, UMODE_REGONLY) || ctx->target == ctx->source)
    return HOOK_FLOW_CONTINUE;

  if (user_mode_has_flag(ctx->source, UMODE_REGISTERED | UMODE_OPER))
    return HOOK_FLOW_CONTINUE;

  if (ctx->notice == false)
    sendto_one_numeric(ctx->source, &me, ERR_CANNOTSENDTOUSER,
                       ctx->target->name, "You must identify to a registered account to message this user");

  return HOOK_FLOW_STOP;
}

static void
init_handler(void)
{
  user_mode_register(&regonly_mode);
  hook_install(ircd_hook_msg_client_source_local, msg_client_source_local_hook, HOOK_PRIORITY_DEFAULT);
}

static void
exit_handler(void)
{
  user_mode_unregister(&regonly_mode);
  hook_uninstall(ircd_hook_msg_client_source_local, msg_client_source_local_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
