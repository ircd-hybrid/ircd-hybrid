/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
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
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"


/* m_topic()
 *  parv[0] = command
 *  parv[1] = channel name
 *  parv[2] = new topic, if setting topic
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
    const struct Membership *ms = NULL;

    if ((ms = find_channel_link(source_p, chptr)) == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, parv[1]);
      return 0;
    }

    if (!(chptr->mode.mode & MODE_TOPICLIMIT) ||
        has_member_flags(ms, CHFL_CHANOP|CHFL_HALFOP))
    {
      char topic_info[USERHOST_REPLYLEN];

      snprintf(topic_info, sizeof(topic_info), "%s!%s@%s", source_p->name,
               source_p->username, source_p->host);
      set_channel_topic(chptr, parv[2], topic_info, CurrentTime, 1);

      sendto_server(source_p, NOCAPS, NOCAPS, ":%s TOPIC %s :%s",
                    ID(source_p), chptr->chname,
                    chptr->topic);
      sendto_channel_local(ALL_MEMBERS, 0,
                           chptr, ":%s!%s@%s TOPIC %s :%s",
                           source_p->name,
                           source_p->username,
                           source_p->host,
                           chptr->chname, chptr->topic);
    }
    else
      sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, chptr->chname);
  }
  else /* only asking for topic */
  {
    if (!SecretChannel(chptr) || IsMember(source_p, chptr))
    {
      if (chptr->topic[0] == '\0')
        sendto_one_numeric(source_p, &me, RPL_NOTOPIC, chptr->chname);
      else
      {
        sendto_one_numeric(source_p, &me, RPL_TOPIC,
                           chptr->chname, chptr->topic);
        sendto_one_numeric(source_p, &me, RPL_TOPICWHOTIME, chptr->chname,
                           chptr->topic_info,
                           chptr->topic_time);
      }
    }
    else
      sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, chptr->chname);
  }

  return 0;
}

static int
ms_topic(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  char topic_info[USERHOST_REPLYLEN];

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
  set_channel_topic(chptr, parv[2], topic_info, CurrentTime, 0);

  sendto_server(source_p, NOCAPS, NOCAPS, ":%s TOPIC %s :%s",
                ID(source_p), chptr->chname,
                chptr->topic);

  if (!IsClient(source_p))
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s TOPIC %s :%s",
                         source_p->name,
                         chptr->chname, chptr->topic);

  else
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s TOPIC %s :%s",
                         source_p->name,
                         source_p->username,
                         source_p->host,
                         chptr->chname, chptr->topic);
  return 0;
}


static struct Message topic_msgtab =
{
  "TOPIC", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_topic, ms_topic, m_ignore, m_topic, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
