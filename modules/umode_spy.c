/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "send.h"
#include "ircd_hook.h"
#include "user_mode.h"

static struct UserMode spy_mode =
{
  .mode_char = 'y',
  .mode_flag = &UMODE_SPY,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static hook_flow_t
whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_SPY) && ctx->source != ctx->target)
    sendto_one_notice(ctx->target, &me, ":*** Notice -- %s (%s@%s) [%s] is doing a /whois on you",
                      ctx->source->name, ctx->source->username, ctx->source->host, ctx->source->servptr->name);

  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&spy_mode);
  hook_install(ircd_hook_whois_send, whois_send_hook, HOOK_PRIORITY_LOWEST);
}

static void
exit_handler(void)
{
  user_mode_unregister(&spy_mode);
  hook_uninstall(ircd_hook_whois_send, whois_send_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
