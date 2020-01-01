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
  char reason[KICKLEN + 1] = "";
  struct Client *target_p = NULL;
  struct Channel *channel = NULL;
  struct ChannelMember *member_source = NULL;
  struct ChannelMember *member_target = NULL;

  if (EmptyString(parv[2]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "KICK");
    return;
  }

  if ((channel = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  if ((member_source = find_channel_link(source_p, channel)) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (!has_member_flags(member_source, CHFL_CHANOP | CHFL_HALFOP))
  {
    sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, channel->name);
    return;
  }

  if ((target_p = find_chasing(source_p, parv[2])) == NULL)
    return;  /* find_chasing sends ERR_NOSUCHNICK */

  if ((member_target = find_channel_link(target_p, channel)) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_USERNOTINCHANNEL, target_p->name, channel->name);
    return;
  }

  if (has_member_flags(member_source, CHFL_HALFOP) && !has_member_flags(member_source, CHFL_CHANOP))
  {
    if (has_member_flags(member_target, CHFL_CHANOP | CHFL_HALFOP))
    {
      sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, channel->name);
      return;
    }
  }

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
  char reason[KICKLEN + 1] = "";
  struct Client *target_p = NULL;
  struct Channel *channel = NULL;
  struct ChannelMember *member_target = NULL;

  if (EmptyString(parv[2]))
    return;

  if ((channel = hash_find_channel(parv[1])) == NULL)
    return;

  if ((target_p = find_person(source_p, parv[2])) == NULL)
    return;

  if ((member_target = find_channel_link(target_p, channel)) == NULL)
    return;

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
  .args_min = 3,
  .args_max = MAXPARA,
  .flags = MFLG_ENDGRACE,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_kick,
  .handlers[SERVER_HANDLER] = ms_kick,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_kick
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
