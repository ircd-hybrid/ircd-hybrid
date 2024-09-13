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

#include "list.h"
#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "client_svstag.h"
#include "conf.h"
#include "command.h"
#include "ircd.h"
#include "numeric.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (source != USER_MODE_SOURCE_REGULAR)
    return false;

  if (!MyConnect(client) && user_mode_has_flag(client, UMODE_OPER) == false)
  {
    ++Count.oper;
    return true;
  }

  return false;
}

static bool
unset_callback(struct Client *client, user_mode_source_t source)
{
  if (user_mode_has_flag(client, UMODE_OPER) == false)
    return false;

  --Count.oper;
  user_mode_unset_flag(client, user_mode_get_oper_only());

  if (MyConnect(client))
  {
    client->handler = CLIENT_HANDLER;
    svstag_detach(&client->svstags, RPL_WHOISOPERATOR);
    conf_detach(client, CONF_OPER);

    ClrOFlag(client);

    list_node_t *node = list_find_remove(&oper_list, client);
    if (node)
      list_free_node(node);
  }

  return true;
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
}

static void
exit_handler(void)
{
  user_mode_unregister(&oper_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .resident = true
};
