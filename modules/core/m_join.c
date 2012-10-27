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
#include "tools.h"
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"   /* bleah */
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


struct entity
{
  struct Channel *chptr;
  char *key;
  int flags;
};

static struct entity targets[512];
static int ntargets, join_0;

static int build_target_list(struct Client *, struct Client *, char *, char *);
static int is_target(struct Channel *);

static void m_join(struct Client *, struct Client *, int, char **);
static void ms_join(struct Client *, struct Client *, int, char **);
static void do_join_0(struct Client *client_p, struct Client *source_p);

static void set_final_mode(struct Mode *, struct Mode *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, struct Client *, int, char);

static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];
static char sendbuf[MODEBUFLEN];
static char *mbuf;

struct Message join_msgtab = {
  "JOIN", 0, 0, 2, 0, MFLG_SLOW, 0,
  {m_unregistered, m_join, ms_join, m_ignore, m_join, m_ignore}
};

#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&join_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&join_msgtab);
}

const char *_version = "$Revision$";
#endif

/* m_join()
 *      parv[0] = sender prefix
 *      parv[1] = channel
 *      parv[2] = channel password (key)
 */
static void
m_join(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  char *key = NULL;
  int i, a;
  unsigned int flags = 0;
  int successful_join_count = 0; /* Number of channels successfully joined */

  if (*parv[1] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "JOIN");
    return;
  }

  build_target_list(client_p, source_p, parv[1], ((parc > 2) ? parv[2] : NULL));

  if ((a = (join_0 >= 0) ? join_0 : 0))
    do_join_0(client_p, source_p);

  for (; a < ntargets; a++)
  {
    chptr = targets[a].chptr;
    key = targets[a].key;
    flags = targets[a].flags;

    if (IsMember(source_p, chptr))
      continue;

    if (!IsOper(source_p))
      check_spambot_warning(source_p, chptr->chname);

    /*
     * can_join checks for +i key, bans.
     */
    if ((i = can_join(source_p, chptr, key)))
    {
      sendto_one(source_p, form_str(i), me.name, source_p->name, chptr->chname);
      continue;
    }

    ++successful_join_count;

    /* add the user to the channel */
    add_user_to_channel(chptr, source_p, flags, YES);

    /*
    **  Set timestamp if appropriate, and propagate
    */
    if (flags & CHFL_CHANOP)
    {
      chptr->channelts = CurrentTime;
      chptr->mode.mode |= MODE_TOPICLIMIT;
      chptr->mode.mode |= MODE_NOPRIVMSGS;

      sendto_server(client_p, source_p, chptr, CAP_TS6, NOCAPS, LL_ICLIENT,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.id, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->id);
      sendto_server(client_p, source_p, chptr, NOCAPS, CAP_TS6, LL_ICLIENT,
                    ":%s SJOIN %lu %s +nt :@%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, parv[0]);
      /*
       * notify all other users on the new channel
       */
      /* XXX just exactly who is going to be =on= this new channel
       * other than just the creator at this time? ? ?
       */
      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);

      sendto_channel_local(ALL_MEMBERS, NO, chptr,
                           ":%s MODE %s +nt",
                           me.name, chptr->chname);
    }
    else
    {
      sendto_server(client_p, source_p, chptr, CAP_TS6, NOCAPS, LL_ICLIENT,
                    ":%s JOIN %lu %s +",
                    source_p->id, (unsigned long)chptr->channelts,
                    chptr->chname);
      sendto_server(client_p, source_p, chptr, NOCAPS, CAP_TS6, LL_ICLIENT,
                    ":%s SJOIN %lu %s + :%s",
                    me.name, (unsigned long)chptr->channelts,
                    chptr->chname, source_p->name);

      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);
    }

    del_invite(chptr, source_p);

    if (chptr->topic != NULL)
    {
      sendto_one(source_p, form_str(RPL_TOPIC), me.name,
                 source_p->name, chptr->chname, chptr->topic);

      sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                 me.name, source_p->name, chptr->chname,
                 chptr->topic_info, chptr->topic_time);
    }

    channel_member_names(source_p, chptr, 1);

    if (successful_join_count != 0)
      source_p->localClient->last_join_time = CurrentTime;
  }
}

/* ms_join()
 *
 * inputs	- parv[0] = uid
 *		  parv[1] = ts
 *		  parv[2] = channel name
 *		  parv[3] = modes
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
  struct Channel *chptr;
  time_t         newts;
  time_t         oldts;
  static         struct Mode mode, *oldmode;
  int            args = 0;
  int            keep_our_modes = 1;
  int            keep_new_modes = 1;
  int            isnew;
  char           *s;
  const char *servername;

  if ((parv[1][0] == '0') && (parv[1][1] == '\0') && parc == 2)
  {
    do_join_0(client_p, source_p);
    return;
  }

  if (parc < 4)
    return;

  if (*parv[2] == '&')
    return;

  if (!check_channel_name(parv[2]))
    return;

  mbuf = modebuf;
  mode.mode = mode.limit = 0;
  mode.key[0] = '\0';

  s = parv[3];
  while (*s)
  {
    switch (*(s++))
    {
      case 't':
        mode.mode |= MODE_TOPICLIMIT;
        break;
      case 'n':
        mode.mode |= MODE_NOPRIVMSGS;
        break;
      case 's':
        mode.mode |= MODE_SECRET;
        break;
      case 'm':
        mode.mode |= MODE_MODERATED;
        break;
      case 'i':
        mode.mode |= MODE_INVITEONLY;
        break;
      case 'p':
        mode.mode |= MODE_PRIVATE;
        break;
      case 'k':
        if (parc < 5+args)
          return;

        strlcpy(mode.key, parv[4 + args], sizeof(mode.key));
        args++;
        break;
      case 'l':
        if (parc < 5+args)
          return;

        mode.limit = atoi(parv[4 + args]);
        args++;
        break;
    }
  }

  if ((chptr = get_or_create_channel(source_p, parv[2], &isnew)) == NULL)
    return; /* channel name too long? */

  newts = atol(parv[1]);
  oldts   = chptr->channelts;
  oldmode = &chptr->mode;

  if (ConfigFileEntry.ignore_bogus_ts)
  {
    if (newts < 800000000)
    {
      sendto_realops_flags(UMODE_DEBUG, L_ALL,
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
      sendto_channel_local(ALL_MEMBERS, NO, chptr,
                             ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to 0",
                             me.name, chptr->chname, chptr->chname, (unsigned long)oldts);
      sendto_realops_flags(UMODE_ALL, L_ALL,
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
    keep_our_modes = NO;
    chptr->channelts = newts;
  }
  else
    keep_new_modes = NO;

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
    sendto_channel_local(ALL_MEMBERS, NO, chptr,
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
    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s MODE %s %s %s",
                         servername, chptr->chname, modebuf, parabuf);
  }

  if (!IsMember(source_p, chptr))
  {
    add_user_to_channel(chptr, source_p, 0, YES);
    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s JOIN :%s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);
  }

  sendto_server(client_p, NULL, chptr, CAP_TS6, NOCAPS, NOFLAGS,
                ":%s JOIN %lu %s +",
                ID(source_p), (unsigned long)chptr->channelts, chptr->chname);
  sendto_server(client_p, NULL, chptr, NOCAPS, CAP_TS6, NOFLAGS,
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
  dlink_node *ptr, *ptr_next;

  if (source_p->channel.head != NULL &&
      MyConnect(source_p) && !IsOper(source_p))
    check_spambot_warning(source_p, NULL);

  DLINK_FOREACH_SAFE(ptr, ptr_next, source_p->channel.head)
  {
    chptr = ((struct Membership *)ptr->data)->chptr;

    /* if the last occurance of this chan is before a 0, leave */
    if (is_target(chptr) < join_0)
    {
      sendto_server(client_p, NULL, chptr, CAP_TS6, NOCAPS, NOFLAGS,
                    ":%s PART %s", ID(source_p), chptr->chname);
      sendto_server(client_p, NULL, chptr, NOCAPS, CAP_TS6, NOFLAGS,
                    ":%s PART %s", source_p->name, chptr->chname);
      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s!%s@%s PART %s",
                           source_p->name, source_p->username,
                           source_p->host, chptr->chname);
      remove_user_from_channel(ptr->data);
    }
  }
}

/* build_target_list()
 *
 * inputs       - pointer to given client_p (server)
 *              - pointer to given source (oper/client etc.)
 *              - pointer to list of channels
 *		- pointer to list of keys
 * output       - number of valid entities
 * side effects - targets list is modified to contain a list of
 *                pointers to channels.  display whatever errors
 *		  that result from a join attempt to the user.
 *
 */
static int
build_target_list(struct Client *client_p, struct Client *source_p,
                  char *channels, char *keys)
{
  int error_reported, flags = 0;
  char *p, *p2, *chan, *key = keys;
  struct Channel *chptr = NULL;

  ntargets = error_reported = 0;
  join_0 = -1;

  for (chan = strtoken(&p, channels, ","); chan;
       key  = (key) ? strtoken(&p2, keys, ",") : NULL,
       chan = strtoken(&p, NULL, ","))
  {
    if (!check_channel_name(chan))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, chan);
      continue;
    }

    if (*chan == '0' && !atoi(chan))
    {
      targets[ntargets].chptr = NULL;
      targets[ntargets].key = NULL;
      targets[ntargets++].flags = 0;

      join_0 = ntargets;
      continue;
    }
    else if (!IsChanPrefix(*chan))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, chan);
      continue;
    }

    if (ConfigChannel.disable_local_channels && (*chan == '&'))
    {
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, chan);
      continue;
    }

    if (strlen(chan) > LOCAL_CHANNELLEN)
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, chan);
      continue;
    }

    if (!IsExemptResv(source_p) &&
        !(IsOper(source_p) && ConfigFileEntry.oper_pass_resv) &&
        (!hash_find_resv(chan) == ConfigChannel.restrict_channels))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, chan);
      sendto_realops_flags(UMODE_SPY, L_ALL,
                           "User %s (%s@%s) is attempting to join locally juped channel %s",
                           source_p->name, source_p->username, source_p->host, chan);
      continue;
    }

    if ((dlink_list_length(&source_p->channel) >= ConfigChannel.max_chans_per_user) &&
        (!IsOper(source_p) || (dlink_list_length(&source_p->channel) >=
                               ConfigChannel.max_chans_per_user * 3)))
    {
      if (!error_reported++)
        sendto_one(source_p, form_str(ERR_TOOMANYCHANNELS),
                   me.name, source_p->name, chan);
      continue;
    }

    if ((chptr = hash_find_channel(chan)) != NULL)
    {
      if (splitmode && !IsOper(source_p) && (*chan != '&') &&
          ConfigChannel.no_join_on_split)
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }

      if (dlink_list_length(&chptr->members) == 0)
        flags = CHFL_CHANOP;
      else
        flags = 0;
    }
    else
    {
      if (splitmode && !IsOper(source_p) && (*chan != '&') &&
          (ConfigChannel.no_create_on_split || ConfigChannel.no_join_on_split))
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }

      flags = CHFL_CHANOP;
      if (!ServerInfo.hub)
      {
        if ((*chan != '&') && uplink && IsCapable(uplink, CAP_LL))
        {
          sendto_one(uplink, ":%s CBURST %s %s %s",
                     me.name, chan, source_p->name, key ? key : "");
          continue;
        }
      }

      if ((chptr = get_or_create_channel(source_p, chan, NULL)) == NULL)
      {
        sendto_one(source_p, form_str(ERR_UNAVAILRESOURCE),
                   me.name, source_p->name, chan);
        continue;
      }
    }

    if (is_target(chptr))
      continue;

    targets[ntargets].chptr = chptr;
    targets[ntargets].key = key;
    targets[ntargets++].flags = flags;
  }

  return ((ntargets) ? 1 : 0);
}

/* is_target()
 *
 * inputs	- channel to check
 * output       - YES if duplicate pointer in table, NO if not.
 *                note, this does the canonize using pointers
 * side effects - NONE
 */
static int
is_target(struct Channel *chptr)
{
  int i;

  /*
   * we step through this backwards for do_join_0()s sake.
   * if the returned value is > join_0 (the highest 0 in the targets)
   * we know they are supposed to stay in that channel.
   */
  for (i = ntargets-1; i >=0; i--)
  {
    if (targets[i].chptr == chptr)
      return i;
  }

  return 0;
}

/* set_final_mode()
 *
 * inputs       - pointer to mode to setup
 *              - pointer to old mode
 * output       - NONE
 * side effects -
 */
static const struct mode_letter
{
  unsigned int mode;
  unsigned char letter;
} flags[] = {
  { MODE_NOPRIVMSGS, 'n' },
  { MODE_TOPICLIMIT, 't' },
  { MODE_SECRET,     's' },
  { MODE_MODERATED,  'm' },
  { MODE_INVITEONLY, 'i' },
  { MODE_PRIVATE,    'p' },
  { 0, '\0' }
};

static void
set_final_mode(struct Mode *mode, struct Mode *oldmode)
{
  char *pbuf = parabuf;
  int what   = 0;
  int len;
  int i;

  for (i = 0; flags[i].letter; i++)
  {
    if ((flags[i].mode & mode->mode) &&
        !(flags[i].mode & oldmode->mode))
    {
      if (what != 1)
      {
        *mbuf++ = '+';
        what = 1;
      }
      *mbuf++ = flags[i].letter;
    }
  }

  for (i = 0; flags[i].letter; i++)
  {
    if ((flags[i].mode & oldmode->mode) &&
        !(flags[i].mode & mode->mode))
    {
      if (what != -1)
      {
        *mbuf++ = '-';
        what = -1;
      }
      *mbuf++ = flags[i].letter;
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
    len = ircsprintf(pbuf, "%s ", oldmode->key);
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
    len = ircsprintf(pbuf, "%d ", mode->limit);
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
    len = ircsprintf(pbuf, "%s ", mode->key);
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
      sendto_channel_local(ALL_MEMBERS, NO, chptr,
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
    sendto_channel_local(ALL_MEMBERS, NO, chptr,
                         ":%s MODE %s %s%s",
                         (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                         me.name : source_p->name,
                         chptr->chname, lmodebuf, sendbuf);
  }
}

