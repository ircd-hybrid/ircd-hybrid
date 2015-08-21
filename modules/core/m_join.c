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

/*! \file m_join.c
 * \brief Includes required functions for processing the JOIN command.
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


static void set_final_mode(const struct Mode *, const struct Mode *);
static void remove_our_modes(struct Channel *, struct Client *);
static void remove_a_mode(struct Channel *, struct Client *, int, const char);

static char modebuf[MODEBUFLEN];
static char parabuf[MODEBUFLEN];
static char sendbuf[MODEBUFLEN];
static char *mbuf;

/*! \brief JOIN command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel
 *      - parv[2] = channel password (key)
 */
static int
m_join(struct Client *source_p, int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "JOIN");
    return 0;
  }

  channel_do_join(source_p, parv[1], parv[2]);
  return 0;
}

/* ms_join()
 *
 * inputs	- parv[0] = command
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
static int
ms_join(struct Client *source_p, int parc, char *parv[])
{
  time_t newts = 0;
  time_t oldts = 0;
  int keep_our_modes = 1;
  int keep_new_modes = 1;
  int isnew = 0;
  const char *servername = NULL;
  struct Channel *chptr = NULL;
  struct Mode mode, *oldmode;

  if (!IsClient(source_p))
    return 0;

  if (parc == 2 && !strcmp(parv[1], "0"))
  {
    channel_do_join_0(source_p);
    return 0;
  }

  if (parc < 4)
    return 0;

  if (!channel_check_name(parv[2], 0))
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "*** Too long or invalid channel name from %s(via %s): %s",
                         source_p->name, source_p->from->name, parv[2]);
    return 0;
  }

  mbuf = modebuf;
  mode.mode = mode.limit = 0;
  mode.key[0] = '\0';

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    isnew = 1;
    chptr = channel_make(parv[2]);
  }

  newts   = atol(parv[1]);
  oldts   = chptr->creationtime;
  oldmode = &chptr->mode;

  if (ConfigGeneral.ignore_bogus_ts)
  {
    if (newts < 800000000)
    {
      sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                           "*** Bogus TS %lu on %s ignored from %s(via %s)",
                           (unsigned long)newts, chptr->name,
                           source_p->name, source_p->from->name);

      newts = (oldts == 0) ? 0 : 800000000;
    }
  }
  else
  {
    if (!newts && !isnew && oldts)
    {
      sendto_channel_local(0, chptr,
                           ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to 0",
                           me.name, chptr->name, chptr->name, (unsigned long)oldts);
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "Server %s changing TS on %s from %lu to 0",
                           source_p->name, chptr->name, (unsigned long)oldts);
    }
  }

  if (isnew)
    chptr->creationtime = newts;
  else if (newts == 0 || oldts == 0)
    chptr->creationtime = 0;
  else if (newts == oldts)
    ;
  else if (newts < oldts)
  {
    keep_our_modes = 0;
    chptr->creationtime = newts;
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
      strlcpy(mode.key, oldmode->key, sizeof(mode.key));
  }

  set_final_mode(&mode, oldmode);
  chptr->mode = mode;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (!keep_our_modes)
  {
    remove_our_modes(chptr, source_p);

    if (chptr->topic[0])
    {
      channel_set_topic(chptr, "", "", 0, 0);
      sendto_channel_local(0, chptr, ":%s TOPIC %s :",
                           (IsHidden(source_p) ||
                           ConfigServerHide.hide_servers) ?
                           me.name : source_p->name, chptr->name);
    }

    sendto_channel_local(0, chptr,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %lu to %lu",
                          me.name, chptr->name, chptr->name,
                         (unsigned long)oldts, (unsigned long)newts);
  }

  if (*modebuf)
  {
    servername = (ConfigServerHide.hide_servers || IsHidden(source_p)) ?
                  me.name : source_p->name;

    /* This _SHOULD_ be to ALL_MEMBERS
     * It contains only +imnpstlk, etc */
    sendto_channel_local(0, chptr, ":%s MODE %s %s %s",
                         servername, chptr->name, modebuf, parabuf);
  }

  if (!IsMember(source_p, chptr))
  {
    add_user_to_channel(chptr, source_p, 0, 1);

    sendto_channel_local_butone(NULL, CAP_EXTENDED_JOIN, 0, chptr, ":%s!%s@%s JOIN %s %s :%s",
                                source_p->name, source_p->username,
                                source_p->host, chptr->name,
                                (!IsDigit(source_p->account[0]) && source_p->account[0] != '*') ? source_p->account : "*",
                                source_p->info);
    sendto_channel_local_butone(NULL, 0, CAP_EXTENDED_JOIN, chptr, ":%s!%s@%s JOIN :%s",
                                source_p->name, source_p->username,
                                source_p->host, chptr->name);

    if (source_p->away[0])
      sendto_channel_local_butone(source_p, CAP_AWAY_NOTIFY, 0, chptr,
                                  ":%s!%s@%s AWAY :%s",
                                  source_p->name, source_p->username,
                                  source_p->host, source_p->away);
  }

  sendto_server(source_p, 0, 0, ":%s JOIN %lu %s +",
                source_p->id, (unsigned long)chptr->creationtime, chptr->name);
  return 0;
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
set_final_mode(const struct Mode *mode, const struct Mode *oldmode)
{
  char *pbuf = parabuf;
  int what = 0, len = 0;

  for (const struct mode_letter *tab = chan_modes; tab->letter; ++tab)
  {
    if ((tab->mode & mode->mode) && !(tab->mode & oldmode->mode))
    {
      if (what != 1)
      {
        *mbuf++ = '+';
        what = 1;
      }

      *mbuf++ = tab->letter;
    }
  }

  for (const struct mode_letter *tab = chan_modes; tab->letter; ++tab)
  {
    if ((tab->mode & oldmode->mode) && !(tab->mode & mode->mode))
    {
      if (what != -1)
      {
        *mbuf++ = '-';
        what = -1;
      }

      *mbuf++ = tab->letter;
    }
  }

  if (oldmode->limit && mode->limit == 0)
  {
    if (what != -1)
    {
      *mbuf++ = '-';
      what = -1;
    }

    *mbuf++ = 'l';
  }

  if (oldmode->key[0] && mode->key[0] == '\0')
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

  if (mode->limit && oldmode->limit != mode->limit)
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
  remove_a_mode(chptr, source_p, CHFL_HALFOP, 'h');
  remove_a_mode(chptr, source_p, CHFL_VOICE, 'v');
}

/* remove_a_mode()
 *
 * inputs       -
 * output       - NONE
 * side effects - remove ONE mode from a channel
 */
static void
remove_a_mode(struct Channel *chptr, struct Client *source_p, int mask, const char flag)
{
  dlink_node *node = NULL;
  char lmodebuf[MODEBUFLEN];
  const char *lpara[MAXMODEPARAMS];
  int count = 0, lcount = 0;

  mbuf = lmodebuf;
  *mbuf++ = '-';

  for (lcount = 0; lcount < MAXMODEPARAMS; ++lcount)
    lpara[lcount] = "";

  sendbuf[0] = '\0';

  DLINK_FOREACH(node, chptr->members.head)
  {
    struct Membership *member = node->data;

    if ((member->flags & mask) == 0)
      continue;

    member->flags &= ~mask;

    lpara[count++] = member->client_p->name;

    *mbuf++ = flag;

    if (count >= MAXMODEPARAMS)
    {
      for (lcount = 0; lcount < MAXMODEPARAMS; ++lcount)
      {
        if (*lpara[lcount] == '\0')
          break;

        strlcat(sendbuf, " ", sizeof(sendbuf));
        strlcat(sendbuf, lpara[lcount], sizeof(sendbuf));
        lpara[lcount] = "";
      }

      *mbuf = '\0';
      sendto_channel_local(0, chptr, ":%s MODE %s %s%s",
                           (IsHidden(source_p) ||
                           ConfigServerHide.hide_servers) ?
                           me.name : source_p->name,
                           chptr->name, lmodebuf, sendbuf);
      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      sendbuf[0] = '\0';
    }
  }

  if (count)
  {
    *mbuf = '\0';

    for (lcount = 0; lcount < MAXMODEPARAMS; ++lcount)
    {
      if (*lpara[lcount] == '\0')
        break;

      strlcat(sendbuf, " ", sizeof(sendbuf));
      strlcat(sendbuf, lpara[lcount], sizeof(sendbuf));
    }

    sendto_channel_local(0, chptr, ":%s MODE %s %s%s",
                         (IsHidden(source_p) || ConfigServerHide.hide_servers) ?
                         me.name : source_p->name, chptr->name, lmodebuf, sendbuf);
  }
}

static struct Message join_msgtab =
{
  .cmd = "JOIN",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_join,
  .handlers[SERVER_HANDLER] = ms_join,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_join
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

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
