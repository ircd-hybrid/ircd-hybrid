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

#include "list.h"
#include "memory.h"
#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "client_svstag.h"
#include "conf.h"
#include "command.h"
#include "ircd.h"
#include "numeric.h"
#include "ircd_hook.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (client_is_oper(client))
    return false;

  ++Count.oper;

  if (MyConnect(client))
  {
    client->handler = OPER_HANDLER;
    assert(list_find(&oper_list, client) == NULL);
    list_add(client, list_make_node(), &oper_list);
  }

  return true;
}

static bool
unset_callback(struct Client *client, user_mode_source_t source)
{
  if (!client_is_oper(client))
    return false;

  --Count.oper;
  user_mode_unset_flag(client, user_mode_get_oper_only());

  if (MyConnect(client))
  {
    client->handler = CLIENT_HANDLER;
    client_set_class(client, NULL, CLIENT_CLASS_OPER);

    io_free(client->connection->oper_name);
    client->connection->oper_name = NULL;

    svstag_detach(&client->svstags, RPL_WHOISOPERATOR);
    ClrOFlag(client);

    list_node_t *node = list_find_remove(&oper_list, client);
    if (node)
      list_free_node(node);
  }

  return true;
}

static hook_flow_t
who_send_hook(void *ctx_)
{
  ircd_hook_who_send_ctx *ctx = ctx_;

  if (client_is_oper(ctx->target))
    if (client_is_oper(ctx->source) || user_mode_has_flag(ctx->target, UMODE_HIDDEN) == false)
      if (ctx->modes_len < sizeof(ctx->modes) - 1)
        ctx->modes[ctx->modes_len++] = '*';

  return HOOK_FLOW_CONTINUE;
}

static struct UserMode oper_mode =
{
  .mode_char = 'o',
  .mode_flag = &UMODE_OPER,
  .policy = USER_MODE_POLICY_OPER_ONLY,
  .set_callback = set_callback,
  .unset_callback = unset_callback
};

static void
init_handler(void)
{
  user_mode_register(&oper_mode);
  hook_install(ircd_hook_who_send, who_send_hook, HOOK_PRIORITY_NORMAL);
}

static void
exit_handler(void)
{
  user_mode_unregister(&oper_mode);
  hook_uninstall(ircd_hook_who_send, who_send_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
