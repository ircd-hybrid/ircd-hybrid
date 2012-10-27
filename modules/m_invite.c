/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_invite.c: Invites the user to join a channel.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "s_serv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"

static void m_invite(struct Client *, struct Client *, int, char *[]);

struct Message invite_msgtab = {
  "INVITE", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_unregistered, m_invite, m_invite, m_ignore, m_invite, m_ignore }
};

void
_modinit(void)
{
  mod_add_cmd(&invite_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&invite_msgtab);
}

const char *_version = "$Revision$";

/*
** m_invite
**      parv[0] - sender prefix
**      parv[1] - user to invite
**      parv[2] - channel name
**      parv[3] - invite timestamp
*/
static void
m_invite(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  struct Membership *ms = NULL;

  if (IsServer(source_p))
    return;

  if (EmptyString(parv[2]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "INVITE");
    return;
  }

  if (MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((target_p = find_person(client_p, parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, parv[1]);
    return;
  }

  /* Do not send local channel invites to users if they are not on the
   * same server as the person sending the INVITE message. 
   */
  /* Possibly should be an error sent to source_p */
  /* done .. there should be no problem because MyConnect(source_p) should
   * always be true if parse() and such is working correctly --is
   */
  if (!MyConnect(target_p) && (*parv[2] == '&'))
  {
    if (ConfigServerHide.hide_servers == 0)
      sendto_one(source_p, form_str(ERR_USERNOTONSERV),
                 me.name, source_p->name, target_p->name);
    return;
  }

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[2]);
    return;
  }

  if (MyConnect(source_p) && (ms = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
               me.name, source_p->name, chptr->chname);
    return;
  }

  if ((chptr->mode.mode & (MODE_INVITEONLY | MODE_PRIVATE)))
  {
    if (MyConnect(source_p) && !has_member_flags(ms, CHFL_CHANOP|CHFL_HALFOP))
    {
      sendto_one(source_p, form_str(ERR_CHANOPRIVSNEEDED),
                 me.name, source_p->name, chptr->chname);
      return;
    }
  }

  if (IsMember(target_p, chptr))
  {
    sendto_one(source_p, form_str(ERR_USERONCHANNEL),
               me.name, source_p->name, target_p->name, chptr->chname);
    return;
  }

  if (MyConnect(source_p))
  {
    sendto_one(source_p, form_str(RPL_INVITING), me.name,
               source_p->name, target_p->name, chptr->chname);

    if (target_p->away)
      sendto_one(source_p, form_str(RPL_AWAY),
                 me.name, source_p->name, target_p->name,
                 target_p->away);
  }
  else if (parc > 3 && IsDigit(*parv[3]))
    if (atoi(parv[3]) > chptr->channelts)
      return;

  if (MyConnect(target_p))
  {
    sendto_one(target_p, ":%s!%s@%s INVITE %s :%s",
               source_p->name, source_p->username,
               source_p->host,
               target_p->name, chptr->chname);

    if (chptr->mode.mode & MODE_INVITEONLY)
    {
      if (chptr->mode.mode & MODE_PRIVATE)
      {
        /* Only do this if channel is set +i AND +p */
        sendto_channel_local(CHFL_CHANOP|CHFL_HALFOP, 0, chptr,
                             ":%s NOTICE %s :%s is inviting %s to %s.",
                             me.name, chptr->chname, source_p->name,
                             target_p->name, chptr->chname);
        sendto_channel_remote(source_p, client_p, CHFL_CHANOP|CHFL_HALFOP,
                              NOCAPS, NOCAPS, chptr,
                              ":%s NOTICE %s :%s is inviting %s to %s.",
                              source_p->name, chptr->chname, source_p->name,
                              target_p->name, chptr->chname);
      }

      /* Add the invite if channel is +i */
      add_invite(chptr, target_p);
    }
  }
  else if (target_p->from != client_p)
    sendto_one(target_p, ":%s INVITE %s %s %lu",
               ID_or_name(source_p, target_p->from),
               ID_or_name(target_p, target_p->from),
               chptr->chname, (unsigned long)chptr->channelts);
}
