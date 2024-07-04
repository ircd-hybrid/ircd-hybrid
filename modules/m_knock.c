/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1998-2024 ircd-hybrid development team
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

/*! \file m_knock.c
 * \brief Includes required functions for processing the KNOCK command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "module.h"
#include "server_capab.h"
#include "isupport.h"


/*! \brief KNOCK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 */
static void
m_knock(struct Client *source, int parc, char *parv[])
{
  const char *const name = parv[1];

  struct Channel *channel = hash_find_channel(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  /* Normal channel, just be sure they aren't on it. */
  if (member_find_link(source, channel))
  {
    sendto_one_numeric(source, &me, ERR_KNOCKONCHAN, channel->name);
    return;
  }

  if (!HasCMode(channel, MODE_INVITEONLY))
  {
    sendto_one_numeric(source, &me, ERR_CHANOPEN, channel->name);
    return;
  }

  if (MyClient(source))
  {
    if (HasCMode(channel, MODE_NOKNOCK))
    {
      sendto_one_numeric(source, &me, ERR_CANNOTKNOCK, channel->name, "knocks are not allowed (+K)");
      return;
    }

    /* Don't allow a knock if the user is banned. */
    if (is_banned(channel, source, NULL) || is_banned(channel, source, &extban_knock))
    {
      sendto_one_numeric(source, &me, ERR_CANNOTKNOCK, channel->name, "you are banned (+b)");
      return;
    }

    if ((source->connection->knock.last_attempt + ConfigChannel.knock_client_time) < io_time_get(IO_TIME_MONOTONIC_SEC))
      source->connection->knock.count = 0;

    if (source->connection->knock.count > ConfigChannel.knock_client_count)
    {
      sendto_one_numeric(source, &me, ERR_TOOMANYKNOCK, channel->name, "user");
      return;
    }

    if ((channel->last_knock_time + ConfigChannel.knock_delay_channel) > io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      sendto_one_numeric(source, &me, ERR_TOOMANYKNOCK, channel->name, "channel");
      return;
    }

    source->connection->knock.last_attempt = io_time_get(IO_TIME_MONOTONIC_SEC);
    source->connection->knock.count++;

    sendto_one_numeric(source, &me, RPL_KNOCKDLVR, channel->name);
  }

  channel->last_knock_time = io_time_get(IO_TIME_MONOTONIC_SEC);

  sendto_channel_local(NULL, channel, CHACCESS_HALFOP, 0, 0,
                       ":%s NOTICE %%%s :KNOCK: %s (%s [%s@%s] has asked for an invite)",
                       me.name, channel->name, channel->name, source->name, source->username, source->host);
  sendto_server(source, CAPAB_KNOCK, 0, ":%s KNOCK %s",
                source->id, channel->name);
}

static struct Command command_table =
{
  .name = "KNOCK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_knock, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_knock, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_knock, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("KNOCK", CAPAB_KNOCK, true);
  isupport_add("KNOCK", NULL, -1);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("KNOCK");
  isupport_delete("KNOCK");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
