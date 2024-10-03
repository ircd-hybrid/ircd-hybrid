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
#include "conf_class.h"
#include "send.h"
#include "ircd_hook.h"
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

  sendto_clients(UMODE_CCONN, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Client connecting: %s (%s@%s) [%s] {%s} [%s] <%s>",
                 ctx->client->name, ctx->client->username, ctx->client->realhost, ctx->client->sockhost,
                 class_get_name(&ctx->client->connection->confs), ctx->client->info, ctx->client->id);

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
client_exit_hook(void *ctx_)
{
  ircd_hook_client_exit_ctx *ctx = ctx_;

  if (IsClient(ctx->client))
    sendto_clients(UMODE_CCONN, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Client exiting: %s (%s@%s) [%s] [%s]",
                   ctx->client->name, ctx->client->username, ctx->client->realhost, ctx->client->sockhost,
                   ctx->comment);

  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&connect_mode);
  hook_install(ircd_hook_user_register_local, user_register_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_client_exit_local, client_exit_hook, HOOK_PRIORITY_DEFAULT);
}

static void
exit_handler(void)
{
  user_mode_unregister(&connect_mode);
  hook_uninstall(ircd_hook_user_register_local, user_register_hook);
  hook_uninstall(ircd_hook_client_exit_local, client_exit_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
