/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_sjoin.c
 * \brief Includes required functions for processing the SJOIN command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "module.h"

#include "cap.h"
#include "channel.h"
#include "channel_invite.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"

/* set_final_mode
 *
 * inputs	- channel mode
 *		- old channel mode
 * output	- NONE
 * side effects	- walk through all the channel modes turning off modes
 *		  that were on in oldmode but aren't on in mode.
 *		  Then walk through turning on modes that are on in mode
 *		  but were not set in oldmode.
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

/* remove_ban_list()
 *
 * inputs	- channel, source, list to remove, char of mode
 * outputs	- none
 * side effects	- given ban list is removed, modes are sent to local clients
 */
static void
remove_ban_list(struct Channel *channel, const char *origin_name, list_t *list, char c)
{
  char modebuf[IRCD_BUFSIZE];
  char parabuf[IRCD_BUFSIZE];
  char *mbuf;
  char *pbuf;
  int count = 0;
  size_t cur_len, mlen;

  if (list_is_empty(list))
    return;

  cur_len = mlen = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s -",
                            origin_name, channel->name);
  mbuf = modebuf + mlen;
  pbuf = parabuf;

  while (list->head)
  {
    struct Ban *const ban = list->head->data;
    const int plen = ban->banstr_len + 2;  /* +2 = b and space */

    if (count >= MAXMODEPARAMS ||
        (cur_len + 1 /* space between */ + (plen - 1)) > sizeof(modebuf) - 2)
    {
      /* NUL-terminate and remove trailing space */
      *mbuf = *(pbuf - 1) = '\0';
      sendto_channel_local(NULL, channel, 0, 0, 0, "%s %s", modebuf, parabuf);

      cur_len = mlen;
      mbuf = modebuf + mlen;
      pbuf = parabuf;
      count = 0;
    }

    *mbuf++ = c;
    cur_len += plen;
    pbuf += sprintf(pbuf, "%s ", ban->banstr);
    ++count;

    remove_ban(ban, list);
  }

  *mbuf = *(pbuf - 1) = '\0';
  sendto_channel_local(NULL, channel, 0, 0, 0, "%s %s", modebuf, parabuf);
}

/* ms_sjoin()
 *
 * parv[0] - command
 * parv[1] - TS
 * parv[2] - channel
 * parv[3] - modes + n arguments (key and/or limit)
 * parv[4+n] - flags+nick list (all in one parameter)
 *
 * process a SJOIN, taking the TS's into account to either ignore the
 * incoming modes or undo the existing ones or merge them, and JOIN
 * all the specified users while sending JOIN/MODEs to local clients
 */
static void
ms_sjoin(struct Client *source, int parc, char *parv[])
{
  if (!client_is_server(source))
    return;

  const char *const channel_name = parv[2];
  if (!channel_is_valid_name(channel_name, false))
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "*** Too long or invalid channel name from %s(via %s): %s",
                   source->name, source->nexthop->name, channel_name);
    return;
  }

  struct ChannelMode mode = { .flags = 0, .limit = 0, .key[0] = '\0' };
  int args = 0;
  for (const char *modes = parv[3]; *modes; ++modes)
  {
    switch (*modes)
    {
      case 'k':
        strlcpy(mode.key, parv[4 + args], sizeof(mode.key));
        ++args;

        if (parc < 5 + args)
          return;
        break;

      case 'l':
        mode.limit = atoi(parv[4 + args]);
        ++args;

        if (parc < 5 + args)
          return;
        break;

      default:
      {
        const struct chan_mode *const cmode = cmode_map[(unsigned char)*modes];
        if (cmode)
          mode.flags |= cmode->mode;
        break;
      }
    }
  }

  uintmax_t newts = strtoumax(parv[1], NULL, 10);
  uintmax_t oldts = 0;
  bool keep_our_modes = true;
  bool keep_new_modes = true;

  bool isnew = false;
  struct Channel *channel = channel_find(channel_name);
  if (channel == NULL)
  {
    isnew = true;
    channel = channel_create(channel_name);
    channel->creation_time = newts;
  }
  else if (newts < channel->creation_time)
  {
    keep_our_modes = false;
    oldts = channel->creation_time;
    channel->creation_time = newts;
  }
  else if (newts > channel->creation_time)
    keep_new_modes = false;

  struct ChannelMode *oldmode = &channel->mode;

  if (keep_new_modes == false)
    mode = *oldmode;
  else if (keep_our_modes)
  {
    mode.flags |= oldmode->flags;

    if (oldmode->limit > mode.limit)
      mode.limit = oldmode->limit;
    if (strcmp(mode.key, oldmode->key) < 0)
      strlcpy(mode.key, oldmode->key, sizeof(mode.key));
  }

  char modebuf[MODEBUFLEN] = "";
  char parabuf[MODEBUFLEN] = "";
  set_final_mode(&mode, oldmode, modebuf, parabuf);
  channel->mode = mode;

  const char *const origin_name = client_get_visible_server_name(source);

  /* Lost the TS, other side wins, so remove modes on this side */
  if (keep_our_modes == false)
  {
    /* Update channel name to be the correct case */
    strlcpy(channel->name, channel_name, sizeof(channel->name));

    sendto_channel_local(NULL, channel, 0, 0, 0,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %ju to %ju",
                         me.name, channel->name, channel->name, oldts, newts);

    channel_member_clear_prefixes(channel, origin_name);

    remove_ban_list(channel, origin_name, &channel->ban_list, 'b');
    remove_ban_list(channel, origin_name, &channel->exception_list, 'e');
    remove_ban_list(channel, origin_name, &channel->invite_exception_list, 'I');

    clear_ban_cache_list(&channel->local_member_list);
    channel_invite_remove_all(&channel->invite_list);

    channel_set_mode_lock(source, channel, NULL);

    if (!string_is_empty(channel->topic))
    {
      channel_set_topic(channel, NULL, NULL, 0, false);
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :",
                           origin_name, channel->name);
    }
  }

  if (modebuf[0])
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s %s %s",
                         origin_name, channel->name, modebuf, parabuf);

  char *mbuf = modebuf;
  char *pbuf = parabuf;
  unsigned int pargs = 0;

  char uid_buf[IRCD_BUFSIZE];  /* Buffer for modes/prefixes */
  const size_t buflen = snprintf(uid_buf, sizeof(uid_buf), ":%s SJOIN %ju %s %s :",
                                 source->id, channel->creation_time, channel->name,
                                 channel_modes(channel, source, true));
  char *uid_ptr = uid_buf + buflen;
  char *const uid_buf_start = uid_ptr;

  char *list = parv[args + 4], *saveptr = NULL;
  for (const char *s = strtok_r(list, " ", &saveptr); s;
                   s = strtok_r(NULL, " ", &saveptr))
  {
    unsigned int ret, flags = 0;
    while ((ret = channel_member_prefix_to_flag(*s)))
    {
      flags |= ret;
      ++s;
    }

    /*
     * If the client doesn't exist, or if it's fake direction/server, skip.
     */
    struct Client *const target = client_find_user(source, s);
    if (target == NULL || target->nexthop != source->nexthop)
      continue;

    size_t len_uid = strlen(target->id);
    char uid_prefix[CMEMBER_STATUS_FLAGS_LEN + 1] = "";

    if (flags && keep_new_modes)
    {
      const struct ChannelMember member = { .flags = flags };
      len_uid += strlcpy(uid_prefix, channel_member_get_prefix(&member, true), sizeof(uid_prefix));
    }
    else
      flags = 0;

    if ((uid_ptr - uid_buf + len_uid) > (sizeof(uid_buf) - 2))
    {
      sendto_servers(source, 0, 0, "%s", uid_buf);
      uid_ptr = uid_buf_start;
    }

    uid_ptr += snprintf(uid_ptr, sizeof(uid_buf) - (uid_ptr - uid_buf), uid_ptr != uid_buf_start ? " %s%s" : "%s%s", uid_prefix, target->id);

    if (channel_member_find(target, channel) == NULL)
    {
      bool synced = client_has_flag(source, FLAGS_EOB);
      channel_member_add(channel, target, flags, synced);

      sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                           target->name, target->username, target->host, channel->name,
                           target->account, target->info);
      sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                           target->name, target->username, target->host, channel->name);

      if (target->away_message)
        sendto_channel_local(target, channel, 0, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY :%s",
                             target->name, target->username, target->host, target->away_message);
    }

    for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    {
      if (flags & tab->flag)
      {
        *mbuf++ = tab->letter;
        pbuf += snprintf(pbuf, sizeof(parabuf) - (pbuf - parabuf), pbuf != parabuf ? " %s" : "%s", target->name);

        if (++pargs >= MAXMODEPARAMS)
        {
          *mbuf = '\0';
          sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +%s %s",
                               origin_name, channel->name, modebuf, parabuf);

          mbuf = modebuf;
          pbuf = parabuf;
          pargs = 0;
        }
      }
    }
  }

  if (pargs)
  {
    *mbuf = '\0';
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +%s %s",
                         origin_name, channel->name, modebuf, parabuf);
  }

  sendto_servers(source, 0, 0, "%s", uid_buf);

  if (list_is_empty(&channel->member_list) && isnew)
    channel_destroy(channel);
}

static struct Command command_table =
{
  .name = "SJOIN",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_sjoin, .args_min = 5, .empty_last_arg = true },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
