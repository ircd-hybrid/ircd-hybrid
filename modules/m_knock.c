/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_knock.c: Requests to be invited to a channel.
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
#include "s_serv.h"
#include "s_user.h"


/* m_knock
 *    parv[0] = sender prefix
 *    parv[1] = channel
 *
 *  The KNOCK command has the following syntax:
 *   :<sender> KNOCK <channel>
 *
 *  If a user is not banned from the channel they can use the KNOCK
 *  command to have the server NOTICE the channel operators notifying
 *  they would like to join.  Helpful if the channel is invite-only, the
 *  key is forgotten, or the channel is full (INVITE can bypass each one
 *  of these conditions.  Concept by Dianora <db@db.net> and written by
 *  <anonymous>
 */
static void
m_knock(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, ERR_NEEDMOREPARAMS,
               me.name, source_p->name, "KNOCK");
    return;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one(source_p, ERR_NOSUCHCHANNEL,
               me.name, source_p->name, parv[1]);
    return;
  }

  /* Normal channel, just be sure they aren't on it */
  if (IsMember(source_p, chptr))
  {
    sendto_one(source_p, ERR_KNOCKONCHAN, me.name,
               source_p->name, chptr->chname);
    return;
  }

  if (!((chptr->mode.mode & MODE_INVITEONLY) || (*chptr->mode.key) ||
        (chptr->mode.limit && dlink_list_length(&chptr->members) >=
         chptr->mode.limit)))
  {
    sendto_one(source_p, ERR_CHANOPEN, me.name,
               source_p->name, chptr->chname);
    return;
  }

  if (MyClient(source_p))
  {
    /*
     * Don't allow a knock if the user is banned, or the channel is private
     */
    if (PrivateChannel(chptr) || is_banned(chptr, source_p))
    {
      sendto_one(source_p, ERR_CANNOTSENDTOCHAN,
                 me.name, source_p->name, chptr->chname);
      return;
    }

    /*
     * flood protection:
     * allow one knock per user per knock_delay
     * allow one knock per channel per knock_delay_channel
     *
     * we only limit local requests..
     */
    if ((source_p->localClient->last_knock + ConfigChannel.knock_delay) >
        CurrentTime)
    {
      sendto_one(source_p, ERR_TOOMANYKNOCK, me.name,
                 source_p->name, chptr->chname, "user");
      return;
    }

    if ((chptr->last_knock + ConfigChannel.knock_delay_channel) > CurrentTime)
    {
      sendto_one(source_p, ERR_TOOMANYKNOCK, me.name,
                 source_p->name, chptr->chname, "channel");
      return;
    }

    source_p->localClient->last_knock = CurrentTime;

    sendto_one(source_p, RPL_KNOCKDLVR, me.name,
               source_p->name, chptr->chname);
  }

  chptr->last_knock = CurrentTime;

  sendto_channel_local(CHFL_CHANOP, 0, chptr,
                       ":%s NOTICE @%s :KNOCK: %s (%s [%s@%s] has asked for an invite)",
                       me.name, chptr->chname, chptr->chname,
                       source_p->name,
                       source_p->username,
                       source_p->host);

  sendto_server(client_p, CAP_KNOCK|CAP_TS6, NOCAPS,
                ":%s KNOCK %s", ID(source_p), chptr->chname);
  sendto_server(client_p, CAP_KNOCK, CAP_TS6,
                ":%s KNOCK %s", source_p->name, chptr->chname);
}

static struct Message knock_msgtab = {
  "KNOCK", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_knock, m_knock, m_ignore, m_knock, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&knock_msgtab);
  add_capability("KNOCK", CAP_KNOCK, 1);
  add_isupport("KNOCK", NULL, -1);
}

static void
module_exit(void)
{
  mod_del_cmd(&knock_msgtab);
  delete_capability("KNOCK");
  delete_isupport("KNOCK");
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
