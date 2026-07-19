/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_join.c
 * \brief Includes required functions for processing the JOIN command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "module.h"

#include "cap.h"
#include "channel.h"
#include "channel_invite.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"

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
set_final_mode(const struct ChannelMode *mode, const struct ChannelMode *oldmode, char *mbuf, char *pbuf)
{
  int what = MODE_NONE;

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
  {
    if (tab->mode && (tab->mode & mode->flags) && !(tab->mode & oldmode->flags))
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
    if (tab->mode && (tab->mode & oldmode->flags) && !(tab->mode & mode->flags))
    {
      if (what != MODE_DEL)
      {
        *mbuf++ = '-';
        what = MODE_DEL;
      }

      *mbuf++ = tab->letter;
    }
  }

  if (oldmode->member_limit && mode->member_limit == 0)
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

  if (mode->member_limit && oldmode->member_limit != mode->member_limit)
  {
    if (what != MODE_ADD)
    {
      *mbuf++ = '+';
      what = MODE_ADD;
    }

    *mbuf++ = 'l';
    pbuf += sprintf(pbuf, "%u ", mode->member_limit);
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
  if (!client_is_user(source))
    return;

  const char *const channel_name = parv[2];
  if (!channel_is_valid_name(channel_name, false))
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "*** Too long or invalid channel name from %s(via %s): %s",
                   source->name, source->nexthop->name, channel_name);
    return;
  }

  uintmax_t newts = strtoumax(parv[1], NULL, 10);
  uintmax_t oldts = 0;
  bool keep_our_modes = true;

  struct Channel *channel = channel_find(channel_name);
  if (channel == NULL)
  {
    if (capab_has_flag(source->nexthop, CAPAB_RESYNC))
    {
      sendto_one(source, ":%s RESYNC %s", me.id, channel_name);
      return;
    }

    channel = channel_create(channel_name);
    channel->creation_time = newts;
  }
  else if (newts < channel->creation_time)
  {
    keep_our_modes = false;
    oldts = channel->creation_time;
    channel->creation_time = newts;
  }

  /* Lost the TS, other side wins, so remove modes on this side */
  if (keep_our_modes == false)
  {
    struct ChannelMode mode = { .flags = 0, .member_limit = 0, .key[0] = '\0' };
    char modebuf[MODEBUFLEN];
    char parabuf[MODEBUFLEN];

    set_final_mode(&mode, &channel->mode, modebuf, parabuf);
    channel->mode = mode;

    /* Update channel name to be the correct case */
    strlcpy(channel->name, channel_name, sizeof(channel->name));

    sendto_channel_local(NULL, channel, 0, 0, 0,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %ju to %ju",
                         me.name, channel->name, channel->name, oldts, newts);

    const char *const origin_name = client_get_visible_server_name(source->uplink);
    channel_mode_clear_member_statuses(channel, origin_name);

    channel_invite_remove_all(&channel->invite_list);

    channel_set_mode_lock(source->nexthop, channel, NULL);

    if (modebuf[0])
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s %s %s",
                           origin_name, channel->name, modebuf, parabuf);

    if (!string_is_empty(channel->topic))
    {
      channel_set_topic(channel, NULL, NULL, 0, false);
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :",
                           origin_name, channel->name);
    }
  }

  if (channel_member_find(channel, source) == NULL)
  {
    channel_member_add(channel, source, 0);

    if (client_has_flag(source->nexthop, FLAGS_EOB))
      channel_flood_record_join(channel, source);

    sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                         source->name, source->username, source->host, channel->name,
                         source->account, source->info);
    sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                         source->name, source->username, source->host, channel->name);

    if (source->away_message)
      sendto_channel_local(source, channel, 0, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY :%s",
                           source->name, source->username, source->host, source->away_message);
  }

  sendto_servers(source, 0, 0, ":%s JOIN %ju %s +",
                 source->id, channel->creation_time, channel->name);
}

static struct Command command_table =
{
  .name = "JOIN",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_join, .args_min = 2 },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_join, .args_min = 4 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_join, .args_min = 2 }
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
