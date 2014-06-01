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
#include "server.h"
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
static int
m_invite(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  struct Membership *ms = NULL;

  if (EmptyString(parv[2]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "INVITE");
    return 0;
  }

  if (IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((target_p = find_person(source_p, parv[1])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, parv[1]);
    return 0;
  }

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[2]);
    return 0;
  }

  if ((ms = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, chptr->chname);
    return 0;
  }

  if (!has_member_flags(ms, CHFL_CHANOP))
  {
    sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, chptr->chname);
    return 0;
  }

  if (IsMember(target_p, chptr))
  {
    sendto_one_numeric(source_p, &me, ERR_USERONCHANNEL, target_p->name, chptr->chname);
    return 0;
  }

  if ((source_p->localClient->last_invite + ConfigChannel.invite_delay) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, ERR_TOOMANYINVITE, chptr->chname, "user");
    return 0;
  }

  if ((chptr->last_invite + ConfigChannel.invite_delay_channel) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, ERR_TOOMANYINVITE, chptr->chname, "channel");
    return 0;
  }

  source_p->localClient->last_invite = CurrentTime;
  chptr->last_invite = CurrentTime;

  sendto_one_numeric(source_p, &me, RPL_INVITING, target_p->name, chptr->chname);

  if (target_p->away[0])
    sendto_one_numeric(source_p, &me, RPL_AWAY, target_p->name, target_p->away);

  if (MyConnect(target_p))
  {
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s",
               source_p->name, source_p->username,
               source_p->host,
               target_p->name, chptr->chname);

    if (chptr->mode.mode & MODE_INVITEONLY)
    {
      sendto_channel_butone(NULL, &me, chptr, CHFL_CHANOP,
                            "NOTICE @%s :%s is inviting %s to %s.",
                            chptr->chname, source_p->name,
                            target_p->name, chptr->chname);

      /* Add the invite if channel is +i */
      add_invite(chptr, target_p);
    }
  }
  else if (target_p->from != source_p->from)
    sendto_one(target_p, ":%s INVITE %s %s %lu",
               source_p->id, target_p->id,
               chptr->chname, (unsigned long)chptr->channelts);
  return 0;
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
static int
ms_invite(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;

  if (EmptyString(parv[2]))
    return 0;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return 0;

  if ((chptr = hash_find_channel(parv[2])) == NULL)
    return 0;

  if (IsMember(target_p, chptr))
    return 0;

  if (parc > 3 && IsDigit(*parv[3]))
    if (atoi(parv[3]) > chptr->channelts)
      return 0;

  chptr->last_invite = CurrentTime;

  if (MyConnect(target_p))
  {
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s",
               source_p->name, source_p->username,
               source_p->host,
               target_p->name, chptr->chname);

    if (chptr->mode.mode & MODE_INVITEONLY)
    {
      sendto_channel_butone(NULL, &me, chptr, CHFL_CHANOP,
                            "NOTICE @%s :%s is inviting %s to %s.",
                            chptr->chname, source_p->name,
                            target_p->name, chptr->chname);

      /* Add the invite if channel is +i */
      add_invite(chptr, target_p);
    }
  }
  else if (target_p->from != source_p->from)
    sendto_one(target_p, ":%s INVITE %s %s %lu",
               source_p->id, target_p->id,
               chptr->chname, (unsigned long)chptr->channelts);
  return 0;
}


static struct Message invite_msgtab =
{
  "INVITE", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_invite, ms_invite, m_ignore, m_invite, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
