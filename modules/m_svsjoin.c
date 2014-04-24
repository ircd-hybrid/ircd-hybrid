/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2014 ircd-hybrid development team
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

/*! \file m_svsjoin.c
 * \brief Includes required functions for processing the SVSJOIN command.
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
#include "server.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "resv.h"


/* do_join_0()
 *
 * inputs       - pointer to client doing join 0
 * output       - NONE
 * side effects - Use has decided to join 0. This is legacy
 *                from the days when channels were numbers not names. *sigh*
 *                There is a bunch of evilness necessary here due to
 *                anti spambot code.
 */
static void
do_join_0(struct Client *source_p)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, source_p->channel.head)
  {
    struct Channel *chptr = ((struct Membership *)ptr->data)->chptr;

    sendto_server(source_p, NOCAPS, NOCAPS, ":%s PART %s",
                  source_p->id, chptr->chname);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);

    remove_user_from_channel(ptr->data);
  }
}

/* last0() stolen from ircu */
static char *
last0(struct Client *target_p, char *chanlist)
{
  char *p;
  int join0 = 0;

  for (p = chanlist; *p; ++p) /* find last "JOIN 0" */
  {
    if (*p == '0' && (*(p + 1) == ',' || *(p + 1) == '\0'))
    {
      if ((*p + 1) == ',')
        ++p;

      chanlist = p + 1;
      join0 = 1;
    }
    else
    {
      while (*p != ',' && *p != '\0') /* skip past channel name */
        ++p;

      if (*p == '\0') /* hit the end */
        break;
    }
  }

  if (join0)
    do_join_0(target_p);

  return chanlist;
}

/*! \brief SVSJOIN command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = channel
 *      - parv[3] = channel password (key)
 */
static int
ms_svsjoin(struct Client *source_p, int parc, char *parv[])
{
  char *p = NULL;
  char *key_list = NULL;
  char *chan_list = NULL;
  char *chan = NULL;
  struct Channel *chptr = NULL;
  struct MaskItem *conf = NULL;
  struct Client *target_p = NULL;
  int i = 0;
  unsigned int flags = 0;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return 0;

  if (EmptyString(parv[2]))
    return 0;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return 0;

  if (target_p->from == source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Received wrong-direction SVSJOIN "
                         "for %s (behind %s) from %s",
                         target_p->name, source_p->from->name,
                         get_client_name(source_p, HIDE_IP));
    return 0;
  }

  if (!MyConnect(target_p))
  {
    if (parc == 3)
      sendto_one(target_p, ":%s SVSJOIN %s %s", source_p->id,
                 target_p->id, parv[2]);
    else
      sendto_one(target_p, ":%s SVSJOIN %s %s %s", source_p->id,
                 target_p->id, parv[2], parv[3]);
    return 0;
  }

  key_list = parv[3];
  chan_list = last0(target_p, parv[2]);

  for (chan = strtoken(&p, chan_list, ","); chan;
       chan = strtoken(&p,      NULL, ","))
  {
    const char *key = NULL;

    /* If we have any more keys, take the first for this channel. */
    if (!EmptyString(key_list) && (key_list = strchr(key = key_list, ',')))
      *key_list++ = '\0';

    /* Empty keys are the same as no keys. */
    if (key && *key == '\0')
      key = NULL;

    if (!check_channel_name(chan, 1))
    {
      sendto_one_numeric(target_p, &me, ERR_BADCHANNAME, chan);
      continue;
    }

    if (!IsExemptResv(target_p) &&
        !(HasUMode(target_p, UMODE_OPER) && ConfigFileEntry.oper_pass_resv) &&
        ((conf = match_find_resv(chan)) && !resv_find_exempt(target_p, conf)))
    {
      ++conf->count;
      sendto_one_numeric(target_p, &me, ERR_CHANBANREASON,
                         chan, conf->reason ? conf->reason : "Reserved channel");
      sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                           "Forbidding reserved channel %s from user %s",
                           chan, get_client_name(target_p, HIDE_IP));
      continue;
    }

    if (dlink_list_length(&target_p->channel) >=
        (HasUMode(target_p, UMODE_OPER) ?
         ConfigChannel.max_chans_per_oper :
         ConfigChannel.max_chans_per_user))
    {
      sendto_one_numeric(target_p, &me, ERR_TOOMANYCHANNELS, chan);
      break;
    }

    if ((chptr = hash_find_channel(chan)))
    {
      if (IsMember(target_p, chptr))
        continue;

      if (splitmode && !HasUMode(target_p, UMODE_OPER) &&
          ConfigChannel.no_join_on_split)
      {
        sendto_one_numeric(target_p, &me, ERR_UNAVAILRESOURCE, chan);
        continue;
      }

      /*
       * can_join checks for +i key, bans.
       */
      if ((i = can_join(target_p, chptr, key)))
      {
        sendto_one_numeric(target_p, &me, i, chptr->chname);
        continue;
      }

      /*
       * This should never be the case unless there is some sort of
       * persistant channels.
       */
      if (dlink_list_length(&chptr->members) == 0)
        flags = CHFL_CHANOP;
      else
        flags = 0;
    }
    else
    {
      if (splitmode && !HasUMode(target_p, UMODE_OPER) &&
          (ConfigChannel.no_create_on_split || ConfigChannel.no_join_on_split))
      {
        sendto_one_numeric(target_p, &me, ERR_UNAVAILRESOURCE, chan);
        continue;
      }

      flags = CHFL_CHANOP;
      chptr = make_channel(chan);
    }

    add_user_to_channel(chptr, target_p, flags, 1);

    /*
     *  Set timestamp if appropriate, and propagate
     */
    if (flags == CHFL_CHANOP)
    {
      chptr->channelts = CurrentTime;
      chptr->mode.mode |= MODE_TOPICLIMIT;
      chptr->mode.mode |= MODE_NOPRIVMSGS;

      sendto_server(target_p, NOCAPS, NOCAPS, ":%s SJOIN %lu %s +nt :@%s",
                    me.id, (unsigned long)chptr->channelts,
                    chptr->chname, target_p->id);
      /*
       * Notify all other users on the new channel
       */
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                           target_p->name, target_p->username,
                           target_p->host, chptr->chname);
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +nt",
                           me.name, chptr->chname);

      if (target_p->away[0])
        sendto_channel_local_butone(target_p, 0, CAP_AWAY_NOTIFY, chptr,
                                    ":%s!%s@%s AWAY :%s",
                                    target_p->name, target_p->username,
                                    target_p->host, target_p->away);
    }
    else
    {
      sendto_server(target_p, NOCAPS, NOCAPS, ":%s JOIN %lu %s +",
                    target_p->id, (unsigned long)chptr->channelts,
                    chptr->chname);
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                           target_p->name, target_p->username,
                           target_p->host, chptr->chname);

      if (target_p->away[0])
        sendto_channel_local_butone(target_p, 0, CAP_AWAY_NOTIFY, chptr,
                                    ":%s!%s@%s AWAY :%s",
                                    target_p->name, target_p->username,
                                    target_p->host, target_p->away);
    }

    del_invite(chptr, target_p);

    if (chptr->topic[0])
    {
      sendto_one_numeric(target_p, &me, RPL_TOPIC, chptr->chname, chptr->topic);
      sendto_one_numeric(target_p, &me, RPL_TOPICWHOTIME, chptr->chname,
                         chptr->topic_info, chptr->topic_time);
    }

    channel_member_names(target_p, chptr, 1);
  }

  return 0;
}

static struct Message svsjoin_msgtab =
{
  "SVSJOIN", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_ignore, ms_svsjoin, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svsjoin_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svsjoin_msgtab);
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
