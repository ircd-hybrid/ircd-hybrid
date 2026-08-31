/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "list.h"
#include "memory.h"
#include "module.h"

#include "client.h"
#include "client_svstag.h"
#include "command.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (client_is_oper(client))
    return false;

  ++Count.oper;

  if (client_is_local(client))
  {
    client->command_handler = COMMAND_HANDLER_OPER;
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

  svstag_clear_list(&client->svstag_list);

  if (client_is_local(client))
  {
    client->command_handler = COMMAND_HANDLER_USER;
    client_set_class(client, NULL, CLIENT_CLASS_OPER);

    io_free(client->connection->oper_auth_name);
    client->connection->oper_auth_name = NULL;

    client_clear_oper_flags(client);

    list_node_t *node = list_find_remove(&oper_list, client);
    assert(node);

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
    if (client_is_oper(ctx->source) || !user_mode_has_flag(ctx->target, UMODE_HIDDEN))
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
