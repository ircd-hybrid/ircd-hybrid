/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file m_sjoin.c
 * \brief Includes required functions for processing the SJOIN command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_invite.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "server.h"
#include "conf.h"
#include "misc.h"


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
set_final_mode(const struct Mode *mode, const struct Mode *oldmode, char *mbuf, char *pbuf)
{
  int what = MODE_QUERY;

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
}

/* remove_ban_list()
 *
 * inputs	- channel, source, list to remove, char of mode
 * outputs	- none
 * side effects	- given ban list is removed, modes are sent to local clients
 */
static void
remove_ban_list(struct Channel *channel, const struct Client *client, dlink_list *list, char c)
{
  char modebuf[IRCD_BUFSIZE];
  char parabuf[IRCD_BUFSIZE];
  char *mbuf;
  char *pbuf;
  int count = 0;
  int cur_len, mlen;

  if (dlink_list_length(list) == 0)
    return;

  cur_len = mlen = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s -",
                            client->name, channel->name);
  mbuf = modebuf + mlen;
  pbuf = parabuf;

  while (list->head)
  {
    struct Ban *ban = list->head->data;
    int plen = ban->banstr_len + 2;  /* +2 = b and space */

    if (count >= MAXMODEPARAMS ||
        (cur_len + 1 /* space between */ + (plen - 1)) > IRCD_BUFSIZE - 2)
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
ms_sjoin(struct Client *source_p, int parc, char *parv[])
{
  struct Mode mode = { .mode = 0, .limit = 0, .key[0] = '\0' };
  int            args = 0;
  bool           isnew = false;
  bool           keep_our_modes = true;
  bool           keep_new_modes = true;
  char           uid_prefix[CMEMBER_STATUS_FLAGS_LEN + 1];
  int            len_uid = 0;
  int            buflen = 0;
  char           *s;
  char uid_buf[IRCD_BUFSIZE];  /* buffer for modes/prefixes */
  char           *uid_ptr;
  char           *p; /* pointer used making sjbuf */
  char modebuf[MODEBUFLEN] = "";
  char parabuf[MODEBUFLEN] = "";
  char parabuf2[MODEBUFLEN] = "";
  char *pbuf = parabuf2;
  unsigned int pargs = 0;

  if (!IsServer(source_p))
    return;

  if (channel_check_name(parv[2], false) == false)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "*** Too long or invalid channel name from %s(via %s): %s",
                         source_p->name, source_p->from->name, parv[2]);
    return;
  }

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
        const struct chan_mode *cmode = cmode_map[(unsigned char)*modes];

        if (cmode)
          mode.mode |= cmode->mode;
        break;
      }
    }
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
                         source_p->name, channel->name, oldts);
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

  const struct Client *origin = source_p;
  if (IsHidden(source_p) || ConfigServerHide.hide_servers)
    origin = &me;

  /* Lost the TS, other side wins, so remove modes on this side */
  if (keep_our_modes == false)
  {
    /* Update channel name to be the correct case */
    strlcpy(channel->name, parv[2], sizeof(channel->name));

    channel_demote_members(channel, origin);

    remove_ban_list(channel, origin, &channel->banlist, 'b');
    remove_ban_list(channel, origin, &channel->exceptlist, 'e');
    remove_ban_list(channel, origin, &channel->invexlist, 'I');

    clear_ban_cache_list(&channel->members_local);
    invite_clear_list(&channel->invites);

    if (channel->topic[0])
    {
      channel_set_topic(channel, "", "", 0, false);
      sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :",
                           origin->name, channel->name);
    }

    sendto_channel_local(NULL, channel, 0, 0, 0,
                         ":%s NOTICE %s :*** Notice -- TS for %s changed from %ju to %ju",
                         me.name, channel->name, channel->name,
                         oldts, newts);
  }

  if (*modebuf)
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s %s %s",
                         origin->name, channel->name, modebuf, parabuf);

  if (*parv[3] != '0' && keep_new_modes == true)
    channel_modes(channel, source_p, NULL, modebuf, parabuf);
  else
  {
    modebuf[0] = '0';
    modebuf[1] = '\0';
  }

  buflen = snprintf(uid_buf, sizeof(uid_buf), ":%s SJOIN %ju %s %s %s:",
                    source_p->id, channel->creation_time,
                    channel->name, modebuf, parabuf);
  uid_ptr = uid_buf + buflen;


  char *mbuf = modebuf;

  s = parv[args + 4];
  while (*s == ' ')
    ++s;

  if ((p = strchr(s, ' ')))
  {
    *p++ = '\0';

    while (*p == ' ')
      ++p;
  }

  while (*s)
  {
    unsigned int ret, flags = 0;
    while ((ret = channel_prefix_to_flag(*s)))
    {
      flags |= ret;
      ++s;
    }

    /*
     * If the client doesn't exist, or if it's fake direction/server, skip.
     * we cannot send ERR_NOSUCHNICK here because if it's a UID, we cannot
     * lookup the nick, and it's better to never send the numeric than only
     * sometimes.
     */
    struct Client *target_p = find_person(source_p, s);
    if (target_p == NULL || target_p->from != source_p->from)
      goto nextnick;

    len_uid = strlen(target_p->id);
    uid_prefix[0] = '\0';

    if (flags && keep_new_modes == true)
    {
      const struct ChannelMember member = { .flags = flags };
      len_uid += strlcpy(uid_prefix, member_get_prefix(&member, true), sizeof(uid_prefix));
    }
    else
      flags = 0;

    if ((uid_ptr - uid_buf + len_uid) > (IRCD_BUFSIZE - 2))
    {
      sendto_server(source_p, 0, 0, "%s", uid_buf);

      buflen = snprintf(uid_buf, sizeof(uid_buf), ":%s SJOIN %ju %s %s %s:",
                        source_p->id, channel->creation_time,
                        channel->name, modebuf, parabuf);
      uid_ptr = uid_buf + buflen;
    }

    uid_ptr += sprintf(uid_ptr, "%s%s ", uid_prefix, target_p->id);

    if (member_find_link(target_p, channel) == NULL)
    {
      bool synced = HasFlag(source_p, FLAGS_EOB) != 0;
      add_user_to_channel(channel, target_p, flags, synced);

      sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                           target_p->name, target_p->username,
                           target_p->host, channel->name, target_p->account, target_p->info);
      sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                           target_p->name, target_p->username,
                           target_p->host, channel->name);

      if (target_p->away[0])
        sendto_channel_local(target_p, channel, 0, CAP_AWAY_NOTIFY, 0,
                             ":%s!%s@%s AWAY :%s",
                             target_p->name, target_p->username,
                             target_p->host, target_p->away);
    }

    for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    {
      if (flags & tab->flag)
      {
        *mbuf++ = tab->letter;
        pbuf += snprintf(pbuf, sizeof(parabuf2) - (pbuf - parabuf2), "%s ", target_p->name);

        if (++pargs >= MAXMODEPARAMS)
        {
          *mbuf = *(pbuf - 1) = '\0';
          sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +%s %s",
                               origin->name, channel->name, modebuf, parabuf2);

          mbuf = modebuf;
          pbuf = parabuf2;
          pargs = 0;
        }
      }
    }

  nextnick:
    if ((s = p) == NULL)
      break;

    while (*s == ' ')
      ++s;

    if ((p = strchr(s, ' ')))
    {
      *p++ = '\0';

      while (*p == ' ')
        ++p;
    }
  }

  if (pargs)
  {
    *mbuf = *(pbuf - 1) = '\0';
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +%s %s",
                         origin->name, channel->name, modebuf, parabuf2);
  }

  /*
   * If this happens, it's the result of a malformed SJOIN
   * a remnant from the old persistent channel code. *sigh*
   * Or it could be the result of a client just leaving
   * and leaving us with a channel formed just as the client parts.
   * - Dianora
   */
  if (dlink_list_length(&channel->members) == 0 && isnew == true)
  {
    channel_free(channel);
    return;
  }

  if (*parv[4 + args] == '\0')
    return;

  *(uid_ptr - 1) = '\0';
  sendto_server(source_p, 0, 0, "%s", uid_buf);
}

static struct Message sjoin_msgtab =
{
  .cmd = "SJOIN",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_sjoin, .args_min = 5, .empty_last_arg = true },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&sjoin_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&sjoin_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
