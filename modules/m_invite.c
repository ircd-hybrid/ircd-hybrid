/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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

/*! \file m_invite.c
 * \brief Includes required functions for processing the INVITE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"


/*! \brief INVITE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user to invite
 *      - parv[2] = channel name
 */
static void
m_invite(struct Client *source_p, int parc, char *parv[])
{
  if (parc < 2)
  {
    dlink_node *node;

    DLINK_FOREACH(node, source_p->connection->invited.head)
      sendto_one_numeric(source_p, &me, RPL_INVITELIST,
                         ((const struct Invite *)node->data)->channel->name);

    sendto_one_numeric(source_p, &me, RPL_ENDOFINVITELIST);
    return;
  }

  if (parc < 3 || EmptyString(parv[2]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "INVITE");
    return;
  }

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, parv[1]);
    return;
  }

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[2]);
    return;
  }

  struct ChannelMember *member = find_channel_link(source_p, channel);
  if (member == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (!has_member_flags(member, CHFL_CHANOP | CHFL_HALFOP))
  {
    sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  if (IsMember(target_p, channel))
  {
    sendto_one_numeric(source_p, &me, ERR_USERONCHANNEL, target_p->name, channel->name);
    return;
  }

  if ((source_p->connection->invite.last_attempt + ConfigChannel.invite_client_time) < event_base->time.sec_monotonic)
    source_p->connection->invite.count = 0;

  if (source_p->connection->invite.count > ConfigChannel.invite_client_count)
  {
    sendto_one_numeric(source_p, &me, ERR_TOOMANYINVITE, channel->name, "user");
    return;
  }

  if ((channel->last_invite_time + ConfigChannel.invite_delay_channel) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source_p, &me, ERR_TOOMANYINVITE, channel->name, "channel");
    return;
  }

  source_p->connection->invite.last_attempt = event_base->time.sec_monotonic;
  source_p->connection->invite.count++;

  sendto_one_numeric(source_p, &me, RPL_INVITING, target_p->name, channel->name);

  if (target_p->away[0])
    sendto_one_numeric(source_p, &me, RPL_AWAY, target_p->name, target_p->away);

  channel->last_invite_time = event_base->time.sec_monotonic;

  if (MyConnect(target_p))
  {
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s",
               source_p->name, source_p->username,
               source_p->host,
               target_p->name, channel->name);

    if (HasCMode(channel, MODE_INVITEONLY))
      add_invite(channel, target_p);  /* Add the invite if channel is +i */
  }

  if (HasCMode(channel, MODE_INVITEONLY))
  {
    sendto_channel_local(NULL, channel, CHFL_CHANOP | CHFL_HALFOP, 0, CAP_INVITE_NOTIFY,
                         ":%s NOTICE %%%s :%s is inviting %s to %s.",
                         me.name, channel->name, source_p->name, target_p->name, channel->name);
    sendto_channel_local(NULL, channel, CHFL_CHANOP | CHFL_HALFOP, CAP_INVITE_NOTIFY, 0,
                         ":%s!%s@%s INVITE %s %s", source_p->name, source_p->username,
                         source_p->host, target_p->name, channel->name);
  }

  sendto_server(source_p, 0, 0, ":%s INVITE %s %s %ju",
                source_p->id, target_p->id,
                channel->name, channel->creation_time);
}

/*! \brief INVITE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = user to invite
 *      - parv[2] = channel name
 *      - parv[3] = channel timestamp
 */
static void
ms_invite(struct Client *source_p, int parc, char *parv[])
{
  if (parc < 3 || EmptyString(parv[2]))
    return;

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
    return;

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
    return;

  if (IsMember(target_p, channel))
    return;

  if (parc > 3 && IsDigit(*parv[3]))
    if (strtoumax(parv[3], NULL, 10) > channel->creation_time)
      return;

  channel->last_invite_time = event_base->time.sec_monotonic;

  if (MyConnect(target_p))
  {
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s",
               source_p->name, source_p->username,
               source_p->host,
               target_p->name, channel->name);

    if (HasCMode(channel, MODE_INVITEONLY))
      add_invite(channel, target_p);  /* Add the invite if channel is +i */
  }

  if (HasCMode(channel, MODE_INVITEONLY))
  {
    sendto_channel_local(NULL, channel, CHFL_CHANOP | CHFL_HALFOP, 0, CAP_INVITE_NOTIFY,
                         ":%s NOTICE %%%s :%s is inviting %s to %s.",
                         me.name, channel->name, source_p->name, target_p->name, channel->name);
    sendto_channel_local(NULL, channel, CHFL_CHANOP | CHFL_HALFOP, CAP_INVITE_NOTIFY, 0,
                         ":%s!%s@%s INVITE %s %s", source_p->name, source_p->username,
                         source_p->host, target_p->name, channel->name);
  }

  sendto_server(source_p, 0, 0, ":%s INVITE %s %s %ju",
                source_p->id, target_p->id,
                channel->name, channel->creation_time);
}


static struct Message invite_msgtab =
{
  .cmd = "INVITE",
  .args_max = MAXPARA,
  .flags = MFLG_ENDGRACE,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_invite,
  .handlers[SERVER_HANDLER] = ms_invite,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_invite
};

static void
module_init(void)
{
  mod_add_cmd(&invite_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&invite_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
