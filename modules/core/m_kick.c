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

/*! \file m_kick.c
 * \brief Includes required functions for processing the KICK command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "modules.h"
#include "parse.h"
#include "hash.h"
#include "packet.h"
#include "s_serv.h"


/* m_kick()
 *  parv[0] = command
 *  parv[1] = channel
 *  parv[2] = client to kick
 *  parv[3] = kick comment
 */
static int
m_kick(struct Client *source_p, int parc, char *parv[])
{
  char reason[KICKLEN + 1] = "";
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  struct Membership *ms_source = NULL;
  struct Membership *ms_target = NULL;

  if (EmptyString(parv[2]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "KICK");
    return 0;
  }

  if (MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  if (!EmptyString(parv[3]))
    strlcpy(reason, parv[3], sizeof(reason));
  else
    strlcpy(reason, source_p->name, sizeof(reason));

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return 0;
  }

  if (!IsServer(source_p) && !HasFlag(source_p, FLAGS_SERVICE))
  {
    if ((ms_source = find_channel_link(source_p, chptr)) == NULL)
    {
      if (MyConnect(source_p))
      {
        sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, chptr->chname);
        return 0;
      }
    }

    if (!has_member_flags(ms_source, CHFL_CHANOP|CHFL_HALFOP))
    {
      /* was a user, not a server, and user isn't seen as a chanop here */
      if (MyConnect(source_p))
      {
        /* user on _my_ server, with no chanops.. so go away */
        sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, chptr->chname);
        return 0;
      }

      if (chptr->channelts == 0)
      {
        /* If its a TS 0 channel, do it the old way */
        sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, chptr->chname);
        return 0;
      }

      /* Its a user doing a kick, but is not showing as chanop locally
       * its also not a user ON -my- server, and the channel has a TS.
       * There are two cases we can get to this point then...
       *
       *     1) connect burst is happening, and for some reason a legit
       *        op has sent a KICK, but the SJOIN hasn't happened yet or
       *        been seen. (who knows.. due to lag...)
       *
       *     2) The channel is desynced. That can STILL happen with TS
       *
       *     Now, the old code roger wrote, would allow the KICK to
       *     go through. Thats quite legit, but lets weird things like
       *     KICKS by users who appear not to be chanopped happen,
       *     or even neater, they appear not to be on the channel.
       *     This fits every definition of a desync, doesn't it? ;-)
       *     So I will allow the KICK, otherwise, things are MUCH worse.
       *     But I will warn it as a possible desync.
       *
       *     -Dianora
       */
    }
  }

  if ((target_p = find_chasing(source_p, parv[2])) == NULL)
    return 0;

  if ((ms_target = find_channel_link(target_p, chptr)) != NULL)
  {
#ifdef HALFOPS
    /* half ops cannot kick other halfops on private channels */
    if (has_member_flags(ms_source, CHFL_HALFOP) && !has_member_flags(ms_source, CHFL_CHANOP))
    {
      if (((chptr->mode.mode & MODE_PRIVATE) && has_member_flags(ms_target,
        CHFL_CHANOP|CHFL_HALFOP)) || has_member_flags(ms_target, CHFL_CHANOP))
      {
        sendto_one_numeric(source_p, &me, ERR_CHANOPRIVSNEEDED, chptr->chname);
        return 0;
      }
    }
#endif

    if (IsServer(source_p))
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s KICK %s %s :%s",
                           source_p->name, chptr->chname,
                           target_p->name, reason);
    else
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s KICK %s %s :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname,
                           target_p->name, reason);

    sendto_server(source_p, NOCAPS, NOCAPS, ":%s KICK %s %s :%s",
                  source_p->id, chptr->chname,
                  target_p->id, reason);
    remove_user_from_channel(ms_target);
  }
  else
    sendto_one_numeric(source_p, &me, ERR_USERNOTINCHANNEL, target_p->name, chptr->chname);

  return 0;
}

static struct Message kick_msgtab =
{
  "KICK", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_kick, m_kick, m_ignore, m_kick, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
