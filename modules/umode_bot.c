/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stddef.h>

#include "module.h"

#include "client.h"
#include "ircd_hook.h"
#include "isupport.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode bot_mode =
{
  .mode_char = 'B',
  .mode_flag = &UMODE_BOT
};

static hook_flow_t
who_send_hook(void *ctx_)
{
  ircd_hook_who_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_BOT))
    if (ctx->modes_len < sizeof(ctx->modes) - 1)
      ctx->modes[ctx->modes_len++] = bot_mode.mode_char;

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_BOT))
    sendto_one_numeric(ctx->source, &me, RPL_WHOISBOT, ctx->target->name);

  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&bot_mode);
  hook_install(ircd_hook_who_send, who_send_hook, HOOK_PRIORITY_NORMAL);
  hook_install(ircd_hook_whois_send, whois_send_hook, HOOK_PRIORITY_NORMAL);
  isupport_add("BOT", "%c", bot_mode.mode_char);
}

static void
exit_handler(void)
{
  user_mode_unregister(&bot_mode);
  hook_uninstall(ircd_hook_who_send, who_send_hook);
  hook_uninstall(ircd_hook_whois_send, whois_send_hook);
  isupport_delete("BOT");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
