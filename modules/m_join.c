/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "list.h"
#include "cap.h"
#include "channel.h"
#include "channel_invite.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"
#include "conf.h"
#include "parse.h"
#include "module.h"


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
  int what = MODE_NONE;

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
  {
    if (tab->mode && (tab->mode & mode->mode) && !(tab->mode & oldmode->mode))
    {
      if (what != MODE_ADD)
      {
        *mbuf++ = '+';
        what = MODE_ADD;
      }

      *mbuf++ = tab->letter;
    }
  }

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
  {
    if (tab->mode && (tab->mode & oldmode->mode) && !(tab->mode & mode->mode))
    {
      if (what != MODE_DEL)
      {
        *mbuf++ = '-';
        what = MODE_DEL;
      }

      *mbuf++ = tab->letter;
    }
  }

  if (oldmode->limit && mode->limit == 0)
  {
    if (what != MODE_DEL)
    {
      *mbuf++ = '-';
      what = MODE_DEL;
    }

    *mbuf++ = 'l';
  }

  if (oldmode->key[0] && mode->key[0] == '\0')
  {
    if (what != MODE_DEL)
    {
      *mbuf++ = '-';
      what = MODE_DEL;
    }

    *mbuf++ = 'k';
    pbuf += sprintf(pbuf, "%s ", oldmode->key);
  }

  if (mode->limit && oldmode->limit != mode->limit)
  {
    if (what != MODE_ADD)
    {
      *mbuf++ = '+';
      what = MODE_ADD;
    }

    *mbuf++ = 'l';
    pbuf += sprintf(pbuf, "%u ", mode->limit);
  }

  if (mode->key[0] && strcmp(oldmode->key, mode->key))
  {
    if (what != MODE_ADD)
    {
      *mbuf++ = '+';
      what = MODE_ADD;
    }

    *mbuf++ = 'k';
    pbuf += sprintf(pbuf, "%s ", mode->key);
  }

  *mbuf = '\0';
  *pbuf = '\0';
}

/*! \brief JOIN command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
m_join(struct Client *source, int parc, char *parv[])
{
  channel_join_list(source, parv[1], parv[2]);
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
ms_join(struct Client *source, int parc, char *parv[])
{
  bool keep_our_modes = true;

  if (!IsClient(source))
    return;

  if (channel_check_name(parv[2], false) == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "*** Too long or invalid channel name from %s(via %s): %s",
                   source->name, source->from->name, parv[2]);
    return;
  }

  uintmax_t newts = strtoumax(parv[1], NULL, 10);
  uintmax_t oldts = 0;

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
  {
    if (IsCapable(source->from, CAPAB_RESYNC))
    {
      sendto_one(source, ":%s RESYNC %s", me.id, parv[2]);
      return;
    }

    channel = channel_make(parv[2]);
    channel->creation_time = newts;
  }
  else if (newts < channel->creation_time)
  {
    keep_our_modes = false;
    oldts = channel->creation_time;
    channel->creation_time = newts;
  }

  const struct Client *origin = source->servptr;
  if (IsHidden(source->servptr) || ConfigServerHide.hide_servers)
    origin = &me;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (keep_our_modes == false)
  {
    struct Mode mode = { .mode = 0, .limit = 0, .key[0] = '\0' };
    char modebuf[MODEBUFLEN];
    char parabuf[MODEBUFLEN];

    set_final_mode(&mode, &channel->mode, modebuf, parabuf);
    channel->mode = mode;

    /* Update channel name to be the correct case */
    strlcpy(channel->name, parv[2], sizeof(channel->name));

    sendto_channel_local(NULL, channel, 0, 0, 0,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %ju to %ju",
                         me.name, channel->name, channel->name, oldts, newts);

    channel_demote_members(channel, origin);

    invite_clear_list(&channel->invites);

    channel_set_mode_lock(source->from, channel, NULL);

    if (modebuf[0])
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s %s %s",
                           origin->name, channel->name, modebuf, parabuf);

    if (channel->topic[0])
    {
      channel_set_topic(channel, "", "", 0, false);
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :",
                           origin->name, channel->name);
    }
  }

  if (member_find_link(source, channel) == NULL)
  {
    channel_add_user(channel, source, 0, true);

    sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                         source->name, source->username, source->host, channel->name,
                         source->account, source->info);
    sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                         source->name, source->username, source->host, channel->name);

    if (source->away[0])
      sendto_channel_local(source, channel, 0, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY :%s",
                           source->name, source->username, source->host, source->away);
  }

  sendto_servers(source, 0, 0, ":%s JOIN %ju %s +",
                 source->id, channel->creation_time, channel->name);
}

static struct Command command_table =
{
  .name = "JOIN",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_join, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = ms_join, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_join, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
