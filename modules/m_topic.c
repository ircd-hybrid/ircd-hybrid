/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file m_topic.c
 * \brief Includes required functions for processing the TOPIC command.
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


/*! \brief TOPIC command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = topic text, if setting topic
 */
static int
m_topic(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "TOPIC");
    return 0;
  }

  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return 0;
  }

  /* setting topic */
  if (parc > 2)
  {
    const struct Membership *member = NULL;

    if ((member = find_channel_link(source_p, chptr)) == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, chptr->name);
      return 0;
    }

    if (!(chptr->mode.mode & MODE_TOPICLIMIT) ||
        has_member_flags(member, CHFL_CHANOP|CHFL_HALFOP))
    {
      char topic_info[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */

      snprintf(topic_info, sizeof(topic_info), "%s!%s@%s", source_p->name,
               source_p->username, source_p->host);
      channel_set_topic(chptr, parv[2], topic_info, CurrentTime, 1);

      sendto_server(source_p, 0, 0, ":%s TOPIC %s :%s",
                    source_p->id, chptr->name,
                    chptr->topic);
      sendto_channel_local(NULL, chptr, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                           source_p->name,
                           source_p->username,
                           source_p->host,
                           chptr->name, chptr->topic);
    }
    else
      sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, chptr->name);
  }
  else /* only asking for topic */
  {
    if (!SecretChannel(chptr) || IsMember(source_p, chptr))
    {
      if (chptr->topic[0] == '\0')
        sendto_one_numeric(source_p, &me, RPL_NOTOPIC, chptr->name);
      else
      {
        sendto_one_numeric(source_p, &me, RPL_TOPIC,
                           chptr->name, chptr->topic);
        sendto_one_numeric(source_p, &me, RPL_TOPICWHOTIME, chptr->name,
                           chptr->topic_info,
                           chptr->topic_time);
      }
    }
    else
      sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, chptr->name);
  }

  return 0;
}


/*! \brief TOPIC command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 *      - parv[2] = topic text
 */
static int
ms_topic(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  char topic_info[NICKLEN + USERLEN + HOSTLEN + 3];  /* +3 for !, @, \0 */

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "TOPIC");
    return 0;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return 0;
  }

  if (!IsClient(source_p))
    strlcpy(topic_info, source_p->name, sizeof(topic_info));
  else
    snprintf(topic_info, sizeof(topic_info), "%s!%s@%s", source_p->name,
             source_p->username, source_p->host);
  channel_set_topic(chptr, parv[2], topic_info, CurrentTime, 0);

  sendto_server(source_p, 0, 0, ":%s TOPIC %s :%s",
                source_p->id, chptr->name,
                chptr->topic);

  if (!IsClient(source_p))
    sendto_channel_local(NULL, chptr, 0, 0, 0, ":%s TOPIC %s :%s",
                         (IsHidden(source_p) || ConfigServerHide.hide_servers) ? me.name : source_p->name,
                         chptr->name, chptr->topic);

  else
    sendto_channel_local(NULL, chptr, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                         source_p->name,
                         source_p->username,
                         source_p->host,
                         chptr->name, chptr->topic);
  return 0;
}


static struct Message topic_msgtab =
{
  .cmd = "TOPIC",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_topic,
  .handlers[SERVER_HANDLER] = ms_topic,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_topic
};

static void
module_init(void)
{
  mod_add_cmd(&topic_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&topic_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
