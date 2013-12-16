/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_join.c: Joins a channel.
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
#include "s_serv.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "resv.h"


static void do_join_0(struct Client *, struct Client *);

static void set_final_mode(struct Mode *, struct Mode *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, struct Client *, int, char);

static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];
static char sendbuf[MODEBUFLEN];
static char *mbuf;

/* last0() stolen from ircu */
static char *
last0(struct Client *client_p, struct Client *source_p, char *chanlist)
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
    do_join_0(client_p, source_p);

  return chanlist;
}

/* m_join()
 *      parv[0] = sender prefix
 *      parv[1] = channel
 *      parv[2] = channel password (key)
 */
static void
m_join(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char *p = NULL;
  char *key_list = NULL;
  char *chan_list = NULL;
  char *chan = NULL;
  struct Channel *chptr = NULL;
  struct MaskItem *conf = NULL;
  int i = 0;
  unsigned int flags = 0;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "JOIN");
    return;
  }

  assert(client_p == source_p);

  key_list = parv[2];
  chan_list = last0(client_p, source_p, parv[1]);

  for (chan = strtoken(&p, chan_list, ","); chan;
       chan = strtoken(&p, NULL,      ","))
  {
    char *key = NULL;

    /* If we have any more keys, take the first for this channel. */
    if (!EmptyString(key_list) && (key_list = strchr(key = key_list, ',')))
      *key_list++ = '\0';

    /* Empty keys are the same as no keys. */
    if (key && *key == '\0')
      key = NULL;

    if (!check_channel_name(chan, 1))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, chan);
      continue;
    }

    if (!IsExemptResv(source_p) &&
        !(HasUMode(source_p, UMODE_OPER) && ConfigFileEntry.oper_pass_resv) &&
        ((conf = match_find_resv(chan)) && !resv_find_exempt(source_p, conf)))
    {
      ++conf->count;
      sendto_one(source_p, form_str(ERR_CHANBANREASON), me.name, source_p->name,
                 chan, conf->reason ? conf->reason : "Reserved channel");
      sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                           "Forbidding reserved channel %s from user %s",
                           chan, get_client_name(source_p, HIDE_IP));
      continue;
    }

    if (dlink_list_length(&source_p->channel) >=
        (HasUMode(source_p, UMODE_OPER) ?
         ConfigChannel.max_chans_per_oper :
         ConfigChannel.max_chans_per_user))
    {
      sendto_one(source_p, form_str(ERR_TOOMANYCHANNELS),
                 me.name, source_p->name, chan);
      break;
    }

    if ((chptr = hash_find_channel(chan)) != NULL)
    {
      if (IsMember(source_p, chptr))
        continue;

      if (splitmode && !HasUMode(source_p, UMODE_OPER) &&
          ConfigChannel.no_join_on_split)
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }

      /*
       * can_join checks for +i key, bans.
       */
      if ((i = can_join(source_p, chptr, key)))
      {
        sendto_one(source_p, form_str(i), me.name,
                   source_p->name, chptr->chname);
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
      if (splitmode && !HasUMode(source_p, UMODE_OPER) &&
          (ConfigChannel.no_create_on_split || ConfigChannel.no_join_on_split))
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }

      flags = CHFL_CHANOP;
      chptr = make_channel(chan);
    }

    if (!HasUMode(source_p, UMODE_OPER))
      check_spambot_warning(source_p, chptr->chname);

    add_user_to_channel(chptr, source_p, flags, 1);

    /*
     *  Set timestamp if appropriate, and propagate
     */
    if (flags & CHFL_CHANOP)
    {
      chptr->channelts = CurrentTime;
      chptr->mode.mode |= MODE_TOPICLIMIT;
      chptr->mode.mode |= MODE_NOPRIVMSGS;

      sendto_server(client_p, CAP_TS6, NOCAPS,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.id, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->id);
      sendto_server(client_p, NOCAPS, CAP_TS6,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->name);
      /*
       * notify all other users on the new channel
       */
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +nt",
                           me.name, chptr->chname);
      if (source_p->away[0])
        sendto_channel_local_butone(source_p, 0, CAP_AWAY_NOTIFY, chptr,
                                    ":%s!%s@%s AWAY :%s",
                                    source_p->name, source_p->username,
                                    source_p->host, source_p->away);
    }
    else
    {
      sendto_server(client_p, CAP_TS6, NOCAPS,
                    ":%s JOIN %lu %s +",
                    source_p->id, (unsigned long)chptr->channelts,
                    chptr->chname);
      sendto_server(client_p, NOCAPS, CAP_TS6,
                    ":%s SJOIN %lu %s + :%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->name);

      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);

      if (source_p->away[0])
        sendto_channel_local_butone(source_p, 0, CAP_AWAY_NOTIFY, chptr,
                                    ":%s!%s@%s AWAY :%s",
                                    source_p->name, source_p->username,
                                    source_p->host, source_p->away);
    }

    del_invite(chptr, source_p);

    if (chptr->topic[0])
    {
      sendto_one(source_p, form_str(RPL_TOPIC), me.name,
                 source_p->name, chptr->chname, chptr->topic);

      sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                 me.name, source_p->name, chptr->chname,
                 chptr->topic_info, chptr->topic_time);
    }

    channel_member_names(source_p, chptr, 1);

    source_p->localClient->last_join_time = CurrentTime;
  }
}

/* ms_join()
 *
 * inputs	- parv[0] = uid
 *		  parv[1] = ts
 *		  parv[2] = channel name
 *		  parv[3] = modes (Deprecated)
 * output	- none
 * side effects	- handles remote JOIN's sent by servers. In TSora
 *		  remote clients are joined using SJOIN, hence a 
 *		  JOIN sent by a server on behalf of a client is an error.
 *		  here, the initial code is in to take an extra parameter
 *		  and use it for the TimeStamp on a new channel.
 */
static void 
ms_join(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  time_t newts = 0;
  time_t oldts = 0;
  int keep_our_modes = 1;
  int keep_new_modes = 1;
  int isnew = 0;
  const char *servername = NULL;
  struct Channel *chptr = NULL;
  struct Mode mode, *oldmode;

  if (parc == 2 && !irccmp(parv[1], "0"))
  {
    do_join_0(client_p, source_p);
    return;
  }

  if (parc < 4)
    return;

  if (!check_channel_name(parv[2], 0))
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "*** Too long or invalid channel name from %s: %s",
                         client_p->name, parv[2]);
    return;
  }

  mbuf = modebuf;
  mode.mode = mode.limit = 0;
  mode.key[0] = '\0';

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    isnew = 1;
    chptr = make_channel(parv[2]);
  }

  newts   = atol(parv[1]);
  oldts   = chptr->channelts;
  oldmode = &chptr->mode;

  if (ConfigFileEntry.ignore_bogus_ts)
  {
    if (newts < 800000000)
    {
      sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                           "*** Bogus TS %lu on %s ignored from %s",
                           (unsigned long)newts, chptr->chname,
                           client_p->name);

      newts = (oldts == 0) ? 0 : 800000000;
    }
  }
  else
  {
    if (!newts && !isnew && oldts)
    {
      sendto_channel_local(ALL_MEMBERS, 0, chptr,
                           ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to 0",
                           me.name, chptr->chname, chptr->chname, (unsigned long)oldts);
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Server %s changing TS on %s from %lu to 0",
                           source_p->name, chptr->chname, (unsigned long)oldts);
    }
  }

  if (isnew)
    chptr->channelts = newts;
  else if (newts == 0 || oldts == 0)
    chptr->channelts = 0;
  else if (newts == oldts)
    ;
  else if (newts < oldts)
  {
    keep_our_modes = 0;
    chptr->channelts = newts;
  }
  else
    keep_new_modes = 0;

  if (!keep_new_modes)
    mode = *oldmode;
  else if (keep_our_modes)
  {
    mode.mode |= oldmode->mode;
    if (oldmode->limit > mode.limit)
      mode.limit = oldmode->limit;
    if (strcmp(mode.key, oldmode->key) < 0)
      strcpy(mode.key, oldmode->key);
  }

  set_final_mode(&mode, oldmode);
  chptr->mode = mode;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (!keep_our_modes)
  {
    remove_our_modes(chptr, source_p);

    if (chptr->topic[0])
    {
      set_channel_topic(chptr, "", "", 0, 0);
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s TOPIC %s :",
                           (IsHidden(source_p) ||
                           ConfigServerHide.hide_servers) ?
                           me.name : source_p->name, chptr->chname);
    }

    sendto_channel_local(ALL_MEMBERS, 0, chptr,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to %lu",
                          me.name, chptr->chname, chptr->chname,
                         (unsigned long)oldts, (unsigned long)newts);
  }
   
  if (*modebuf != '\0')
  {
    servername = (ConfigServerHide.hide_servers || IsHidden(source_p)) ?
                  me.name : source_p->name;

    /* This _SHOULD_ be to ALL_MEMBERS
     * It contains only +imnpstlk, etc */
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s %s",
                         servername, chptr->chname, modebuf, parabuf);
  }

  if (!IsMember(source_p, chptr))
  {
    add_user_to_channel(chptr, source_p, 0, 1);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);
    if (source_p->away[0])
      sendto_channel_local_butone(source_p, 0, CAP_AWAY_NOTIFY, chptr,
                                  ":%s!%s@%s AWAY :%s",
                                  source_p->name, source_p->username,
                                  source_p->host, source_p->away);
  }

  sendto_server(client_p, CAP_TS6, NOCAPS,
                ":%s JOIN %lu %s +",
                ID(source_p), (unsigned long)chptr->channelts, chptr->chname);
  sendto_server(client_p, NOCAPS, CAP_TS6,
                ":%s SJOIN %lu %s + :%s",
                source_p->servptr->name, (unsigned long)chptr->channelts,
                chptr->chname, source_p->name);
}

/* do_join_0()
 *
 * inputs	- pointer to client doing join 0
 * output	- NONE
 * side effects	- Use has decided to join 0. This is legacy
 *		  from the days when channels were numbers not names. *sigh*
 *		  There is a bunch of evilness necessary here due to
 * 		  anti spambot code.
 */
static void
do_join_0(struct Client *client_p, struct Client *source_p)
{
  struct Channel *chptr = NULL;
  dlink_node *ptr = NULL, *ptr_next = NULL;

  if (source_p->channel.head)
    if (MyConnect(source_p) && !HasUMode(source_p, UMODE_OPER))
      check_spambot_warning(source_p, NULL);

  DLINK_FOREACH_SAFE(ptr, ptr_next, source_p->channel.head)
  {
    chptr = ((struct Membership *)ptr->data)->chptr;

    sendto_server(client_p, CAP_TS6, NOCAPS,
                  ":%s PART %s", ID(source_p), chptr->chname);
    sendto_server(client_p, NOCAPS, CAP_TS6,
                  ":%s PART %s", source_p->name, chptr->chname);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);

    remove_user_from_channel(ptr->data);
  }
}

/* set_final_mode
 *
 * inputs       - channel mode
 *              - old channel mode
 * output       - NONE
 * side effects - walk through all the channel modes turning off modes
 *                that were on in oldmode but aren't on in mode.
 *                Then walk through turning on modes that are on in mode
 *                but were not set in oldmode.
 */
static void
set_final_mode(struct Mode *mode, struct Mode *oldmode)
{
  const struct mode_letter *tab;
  char *pbuf = parabuf;
  int what   = 0;
  int len;

  for (tab = chan_modes; tab->letter; ++tab)
  {
    if ((tab->mode & mode->mode) &&
        !(tab->mode & oldmode->mode))
    {
      if (what != 1)
      {
        *mbuf++ = '+';
        what = 1;
      }
      *mbuf++ = tab->letter;
    }
  }

  for (tab = chan_modes; tab->letter; ++tab)
  {
    if ((tab->mode & oldmode->mode) &&
        !(tab->mode & mode->mode))
    {
      if (what != -1)
      {
        *mbuf++ = '-';
        what = -1;
      }
      *mbuf++ = tab->letter;
    }
  }

  if (oldmode->limit != 0 && mode->limit == 0)
  {
    if (what != -1)
    {
      *mbuf++ = '-';
      what = -1;
    }
    *mbuf++ = 'l';
  }

  if (oldmode->key[0] && !mode->key[0])
  {
    if (what != -1)
    {
      *mbuf++ = '-';
      what = -1;
    }
    *mbuf++ = 'k';
    len = sprintf(pbuf, "%s ", oldmode->key);
    pbuf += len;
  }

  if (mode->limit != 0 && oldmode->limit != mode->limit)
  {
    if (what != 1)
    {
      *mbuf++ = '+';
      what = 1;
    }
    *mbuf++ = 'l';
    len = sprintf(pbuf, "%d ", mode->limit);
    pbuf += len;
  }

  if (mode->key[0] && strcmp(oldmode->key, mode->key))
  {
    if (what != 1)
    {
      *mbuf++ = '+';
      what = 1;
    }
    *mbuf++ = 'k';
    len = sprintf(pbuf, "%s ", mode->key);
    pbuf += len;
  }
  *mbuf = '\0';
}

/* remove_our_modes()
 *
 * inputs       - pointer to channel to remove modes from
 *              - client pointer
 * output       - NONE
 * side effects - Go through the local members, remove all their
 *                chanop modes etc., this side lost the TS.
 */
static void
remove_our_modes(struct Channel *chptr, struct Client *source_p)
{
  remove_a_mode(chptr, source_p, CHFL_CHANOP, 'o');
#ifdef HALFOPS
  remove_a_mode(chptr, source_p, CHFL_HALFOP, 'h');
#endif
  remove_a_mode(chptr, source_p, CHFL_VOICE, 'v');
}

/* remove_a_mode()
 *
 * inputs       -
 * output       - NONE
 * side effects - remove ONE mode from a channel
 */
static void
remove_a_mode(struct Channel *chptr, struct Client *source_p,
              int mask, char flag)
{
  dlink_node *ptr;
  struct Membership *ms;
  char lmodebuf[MODEBUFLEN];
  const char *lpara[MAXMODEPARAMS];
  int count = 0;
  int lcount;

  mbuf = lmodebuf;
  *mbuf++ = '-';

  for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
    lpara[lcount] = "";
  sendbuf[0] = '\0';

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;

    if ((ms->flags & mask) == 0)
      continue;

    ms->flags &= ~mask;

    lpara[count++] = ms->client_p->name;

    *mbuf++ = flag;

    if (count >= MAXMODEPARAMS)
    {
      for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
      {
        if (*lpara[lcount] == '\0')
          break;

        strlcat(sendbuf, " ", sizeof(sendbuf));
        strlcat(sendbuf, lpara[lcount], sizeof(sendbuf));
        lpara[lcount] = "";
      }

      *mbuf = '\0';
      sendto_channel_local(ALL_MEMBERS, 0, chptr,
                           ":%s MODE %s %s%s",
                           (IsHidden(source_p) ||
                           ConfigServerHide.hide_servers) ?
                           me.name : source_p->name,
                           chptr->chname, lmodebuf, sendbuf);
      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      sendbuf[0] = '\0';
    }
  }

  if (count != 0)
  {
    *mbuf = '\0';
    for (lcount = 0; lcount < MAXMODEPARAMS; lcount++)
    {
      if (*lpara[lcount] == '\0')
        break;

      strlcat(sendbuf, " ", sizeof(sendbuf));
      strlcat(sendbuf, lpara[lcount], sizeof(sendbuf));
    }
    sendto_channel_local(ALL_MEMBERS, 0, chptr,
                         ":%s MODE %s %s%s",
                         (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                         me.name : source_p->name,
                         chptr->chname, lmodebuf, sendbuf);
  }
}

static struct Message join_msgtab = {
  "JOIN", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_join, ms_join, m_ignore, m_join, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&join_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&join_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
