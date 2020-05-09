/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1998-2020 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "server_capab.h"
#include "user.h"
#include "isupport.h"


/*! \brief KNOCK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 */
static void
m_knock(struct Client *source_p, int parc, char *parv[])
{
  const char *const name = parv[1];

  struct Channel *channel = hash_find_channel(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  /* Normal channel, just be sure they aren't on it. */
  if (IsMember(source_p, channel))
  {
    sendto_one_numeric(source_p, &me, ERR_KNOCKONCHAN, channel->name);
    return;
  }

  if (!((channel->mode.mode & MODE_INVITEONLY) || channel->mode.key[0] ||
        (channel->mode.limit && dlink_list_length(&channel->members) >=
         channel->mode.limit)))
  {
    sendto_one_numeric(source_p, &me, ERR_CHANOPEN, channel->name);
    return;
  }

  if (MyClient(source_p))
  {
    /*
     * Don't allow a knock if the user is banned, or the channel is private.
     */
    if (PrivateChannel(channel) || is_banned(channel, source_p) == true)
    {
      sendto_one_numeric(source_p, &me, ERR_CANNOTSENDTOCHAN, channel->name);
      return;
    }

    if ((source_p->connection->knock.last_attempt + ConfigChannel.knock_client_time) < event_base->time.sec_monotonic)
      source_p->connection->knock.count = 0;

    if (source_p->connection->knock.count > ConfigChannel.knock_client_count)
    {
      sendto_one_numeric(source_p, &me, ERR_TOOMANYKNOCK, channel->name, "user");
      return;
    }

    if ((channel->last_knock_time + ConfigChannel.knock_delay_channel) > event_base->time.sec_monotonic)
    {
      sendto_one_numeric(source_p, &me, ERR_TOOMANYKNOCK, channel->name, "channel");
      return;
    }

    source_p->connection->knock.last_attempt = event_base->time.sec_monotonic;
    source_p->connection->knock.count++;

    sendto_one_numeric(source_p, &me, RPL_KNOCKDLVR, channel->name);
  }

  channel->last_knock_time = event_base->time.sec_monotonic;
  sendto_channel_local(NULL, channel, CHFL_CHANOP | CHFL_HALFOP, 0, 0,
                       ":%s NOTICE %%%s :KNOCK: %s (%s [%s@%s] has asked for an invite)",
                       me.name, channel->name, channel->name,
                       source_p->name,
                       source_p->username,
                       source_p->host);

  sendto_server(source_p, CAPAB_KNOCK, 0, ":%s KNOCK %s",
                source_p->id, channel->name);
}

static struct Message knock_msgtab =
{
  .cmd = "KNOCK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_knock, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_knock, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_knock, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&knock_msgtab);
  capab_add("KNOCK", CAPAB_KNOCK);
  isupport_add("KNOCK", NULL, -1);
}

static void
module_exit(void)
{
  mod_del_cmd(&knock_msgtab);
  capab_del("KNOCK");
  isupport_delete("KNOCK");
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
