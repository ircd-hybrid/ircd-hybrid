/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2025 ircd-hybrid development team
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

  if (IsClient(ctx->client) && client_has_flag(ctx->client->uplink, FLAGS_EOB))
    sendto_clients(UMODE_FARCONNECT, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Client exiting at %s: %s (%s@%s) [%s] [%s]",
                   ctx->client->uplink->name, ctx->client->name, ctx->client->username, ctx->client->realhost,
                   ctx->client->sockhost, ctx->reason);

  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&farconnect_mode);
  hook_install(ircd_hook_user_register_remote, user_register_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_client_exit_remote, client_exit_hook, HOOK_PRIORITY_DEFAULT);
}

static void
exit_handler(void)
{
  user_mode_unregister(&farconnect_mode);
  hook_uninstall(ircd_hook_user_register_remote, user_register_hook);
  hook_uninstall(ircd_hook_client_exit_remote, client_exit_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
