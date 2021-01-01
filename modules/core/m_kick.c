/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2021 ircd-hybrid development team
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

/*! \file m_kick.c
 * \brief Includes required functions for processing the KICK command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "modules.h"
#include "parse.h"
#include "hash.h"
#include "packet.h"
#include "server.h"


/*! \brief KICK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = client to kick
 *      - parv[3] = reason
 */
static void
m_kick(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  struct ChannelMember *member_source = member_find_link(source_p, channel);
  if (member_source == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (member_has_flags(member_source, CHFL_CHANOP | CHFL_HALFOP) == false)
  {
    sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  struct Client *target_p = find_chasing(source_p, parv[2]);
  if (target_p == NULL)
    return;  /* find_chasing sends ERR_NOSUCHNICK */

  struct ChannelMember *member_target = member_find_link(target_p, channel);
  if (member_target == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_USERNOTINCHANNEL, target_p->name, channel->name);
    return;
  }

  if (member_has_flags(member_source, CHFL_CHANOP) == false)
  {
    if (member_has_flags(member_target, CHFL_CHANOP | CHFL_HALFOP) == true)
    {
      sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, channel->name);
      return;
    }
  }

  char reason[KICKLEN + 1];
  if (!EmptyString(parv[3]))
    strlcpy(reason, parv[3], sizeof(reason));
  else
    strlcpy(reason, source_p->name, sizeof(reason));

  sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s KICK %s %s :%s",
                       source_p->name, source_p->username,
                       source_p->host, channel->name,
                       target_p->name, reason);
  sendto_server(source_p, 0, 0, ":%s KICK %s %s :%s",
                source_p->id, channel->name,
                target_p->id, reason);
  remove_user_from_channel(member_target);
}

/*! \brief KICK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = client to kick
 *      - parv[3] = reason
 */
static void
ms_kick(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
    return;

  struct Client *target_p = find_person(source_p, parv[2]);
  if (target_p == NULL)
    return;

  struct ChannelMember *member_target = member_find_link(target_p, channel);
  if (member_target == NULL)
    return;

  char reason[KICKLEN + 1];
  if (!EmptyString(parv[3]))
    strlcpy(reason, parv[3], sizeof(reason));
  else
    strlcpy(reason, source_p->name, sizeof(reason));

  if (IsClient(source_p))
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s KICK %s %s :%s",
                         source_p->name, source_p->username,
                         source_p->host, channel->name,
                         target_p->name, reason);
  else
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s KICK %s %s :%s",
                         IsHidden(source_p) || ConfigServerHide.hide_servers ? me.name : source_p->name,
                         channel->name, target_p->name, reason);

  sendto_server(source_p, 0, 0, ":%s KICK %s %s :%s",
                source_p->id, channel->name,
                target_p->id, reason);
  remove_user_from_channel(member_target);
}

static struct Message kick_msgtab =
{
  .cmd = "KICK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_kick, .args_min = 3, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = ms_kick, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_kick, .args_min = 3, .end_grace_period = true }
};

static void
module_init(void)
{
  mod_add_cmd(&kick_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&kick_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
