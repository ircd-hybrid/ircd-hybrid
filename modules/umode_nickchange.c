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
