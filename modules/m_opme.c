/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2024 ircd-hybrid development team
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

/*! \file m_opme.c
 * \brief Includes required functions for processing the OPME command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "module.h"
#include "channel.h"
#include "channel_mode.h"
#include "conf.h"


/*! \brief OPME command handler
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
mo_opme(struct Client *source, int parc, char *parv[])
{
  const char *const name = parv[1];
  list_node_t *node;

  if (!HasOFlag(source, OPER_FLAG_OPME))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "opme");
    return;
  }

  struct Channel *channel = hash_find_channel(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  struct ChannelMember *member = member_find_link(source, channel);
  if (member == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  LIST_FOREACH(node, channel->members.head)
  {
    const struct ChannelMember *tmp = node->data;

    if (member_highest_rank(tmp) > CHACCESS_HALFOP)
    {
      sendto_one_notice(source, &me, ":Cannot use OPME on %s: channel is not opless",
                        channel->name);
      return;
    }
  }

  log_write(LOG_TYPE_IRCD, "%s used OPME on channel %s",
            get_oper_name(source), channel->name);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_GLOBAL, "from %s: %s used OPME on channel %s",
                 me.name, get_oper_name(source), channel->name);
  sendto_servers(NULL, 0, 0, ":%s GLOBOPS :%s used OPME on channel %s",
                 me.id, get_oper_name(source), channel->name);

  AddMemberFlag(member, CHFL_CHANOP);
  sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +o %s",
                       me.name, channel->name, source->name);
  sendto_servers(NULL, 0, 0, ":%s TMODE %ju %s +o %s", me.id, channel->creation_time,
                 channel->name, source->id);
}

static struct Command command_table =
{
  .name = "OPME",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_opme, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
