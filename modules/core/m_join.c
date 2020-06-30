/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2020 ircd-hybrid development team
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


static void set_final_mode(const struct Mode *, const struct Mode *, char *, char *);
static void remove_a_mode(struct Channel *, const struct Client *, unsigned int, const char);


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
static void
m_join(struct Client *source_p, int parc, char *parv[])
{
  channel_do_join(source_p, parv[1], parv[2]);
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
static void
ms_join(struct Client *source_p, int parc, char *parv[])
{
  bool keep_our_modes = true;
  bool keep_new_modes = true;
  bool isnew = false;
  struct Mode mode = { .mode = 0, .limit = 0, .key[0] = '\0' };
  char modebuf[MODEBUFLEN];
  char parabuf[MODEBUFLEN];

  if (!IsClient(source_p))
    return;

  if (channel_check_name(parv[2], false) == false)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "*** Too long or invalid channel name from %s(via %s): %s",
                         source_p->name, source_p->from->name, parv[2]);
    return;
  }

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
  {
    isnew = true;
    channel = channel_make(parv[2]);
  }

  uintmax_t newts = strtoumax(parv[1], NULL, 10);
  uintmax_t oldts = channel->creation_time;

  if (newts == 0 && isnew == false && oldts)
  {
    sendto_channel_local(NULL, channel, 0, 0, 0,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %ju to 0",
                         me.name, channel->name, channel->name, oldts);
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Server %s changing TS on %s from %ju to 0",
                         source_p->servptr->name, channel->name, oldts);
  }

  if (isnew == true)
    channel->creation_time = newts;
  else if (newts == 0 || oldts == 0)
    channel->creation_time = 0;
  else if (newts == oldts)
    ;
  else if (newts < oldts)
  {
    keep_our_modes = false;
    channel->creation_time = newts;
  }
  else
    keep_new_modes = false;

  struct Mode *oldmode = &channel->mode;

  if (keep_new_modes == false)
    mode = *oldmode;
  else if (keep_our_modes == true)
  {
    mode.mode |= oldmode->mode;

    if (oldmode->limit > mode.limit)
      mode.limit = oldmode->limit;
    if (strcmp(mode.key, oldmode->key) < 0)
      strlcpy(mode.key, oldmode->key, sizeof(mode.key));
  }

  set_final_mode(&mode, oldmode, modebuf, parabuf);
  channel->mode = mode;

  const struct Client *origin = source_p->servptr;
  if (IsHidden(source_p->servptr) || ConfigServerHide.hide_servers)
    origin = &me;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (keep_our_modes == false)
  {
    remove_a_mode(channel, origin, CHFL_CHANOP, 'o');
    remove_a_mode(channel, origin, CHFL_HALFOP, 'h');
    remove_a_mode(channel, origin, CHFL_VOICE, 'v');

    if (channel->topic[0])
    {
      channel_set_topic(channel, "", "", 0, false);
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :",
                           origin->name, channel->name);
    }

    sendto_channel_local(NULL, channel, 0, 0, 0,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %ju to %ju",
                         me.name, channel->name, channel->name, oldts, newts);
  }

  if (*modebuf)
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s %s %s",
                         origin->name, channel->name, modebuf, parabuf);

  if (find_channel_link(source_p, channel) == NULL)
  {
    add_user_to_channel(channel, source_p, 0, true);

    sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                         source_p->name, source_p->username,
                         source_p->host, channel->name, source_p->account, source_p->info);
    sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                         source_p->name, source_p->username,
                         source_p->host, channel->name);

    if (source_p->away[0])
      sendto_channel_local(source_p, channel, 0, CAP_AWAY_NOTIFY, 0,
                           ":%s!%s@%s AWAY :%s",
                           source_p->name, source_p->username,
                           source_p->host, source_p->away);
  }

  sendto_server(source_p, 0, 0, ":%s JOIN %ju %s +",
                source_p->id, channel->creation_time, channel->name);
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
set_final_mode(const struct Mode *mode, const struct Mode *oldmode, char *mbuf, char *pbuf)
{
  int what = 0, len = 0;

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
  {
    if (tab->mode && (tab->mode & mode->mode) && !(tab->mode & oldmode->mode))
    {
      if (what != 1)
      {
        *mbuf++ = '+';
        what = 1;
      }

      *mbuf++ = tab->letter;
    }
  }

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
  {
    if (tab->mode && (tab->mode & oldmode->mode) && !(tab->mode & mode->mode))
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
    len = sprintf(pbuf, "%u ", mode->limit);
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

/* remove_a_mode()
 *
 * inputs       -
 * output       - NONE
 * side effects - remove ONE mode from a channel
 */
static void
remove_a_mode(struct Channel *channel, const struct Client *client, unsigned int mask, const char flag)
{
  dlink_node *node;
  char modebuf[MODEBUFLEN];
  char parabuf[MODEBUFLEN];
  char *mbuf = modebuf;
  char *pbuf = modebuf;
  const char *names[MAXMODEPARAMS];
  static const unsigned int names_size = sizeof(names) / sizeof(names[0]);
  unsigned int count = 0;

  DLINK_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *member = node->data;

    if ((member->flags & mask) == 0)
      continue;

    member->flags &= ~mask;

    names[count++] = member->client->name;

    *mbuf++ = flag;

    if (count >= names_size)
    {
      *mbuf = '\0';

      for (unsigned int i = 0; i < names_size; ++i)
        pbuf += snprintf(pbuf, sizeof(parabuf) - (pbuf - parabuf), " %s", names[i]);

      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s -%s%s",
                           client->name, channel->name, modebuf, parabuf);
      mbuf = modebuf;
      pbuf = parabuf;
      count = 0;
    }
  }

  if (count)
  {
    *mbuf = '\0';

    for (unsigned int i = 0; i < names_size; ++i)
      pbuf += snprintf(pbuf, sizeof(parabuf) - (pbuf - parabuf), " %s", names[i]);

    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s -%s%s",
                         client->name, channel->name, modebuf, parabuf);
  }
}

static struct Message join_msgtab =
{
  .cmd = "JOIN",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_join, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = ms_join, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_join, .args_min = 2 }
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
  .is_core = true
};
