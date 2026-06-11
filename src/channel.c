/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/*! \file channel.c
 * \brief Responsible for managing channels, members, bans and topics
 */

#include <assert.h>

#include "address.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "misc.h"

#include "cap.h"
#include "channel.h"
#include "channel_invite.h"
#include "channel_mode.h"
#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "conf_oper.h"
#include "conf_resv.h"
#include "defaults.h"
#include "extban.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"
#include "user_mode.h"

/** Doubly linked list containing a list of all channels. */
static list_t channel_list;

/*! \brief Returns the channel_list as constant
 * \return channel_list
 */
const list_t *
channel_get_list(void)
{
  return &channel_list;
}

struct Channel *
channel_find(const char *name)
{
  if (string_is_empty(name))
    return NULL;

  return hash_find_channel(name);
}

static void
_channel_track_join_flood(struct Channel *channel, struct Client *client, bool track_join)
{
  if (!(GlobalSetOptions.joinfloodtime && GlobalSetOptions.joinfloodcount))
    return;

  if (track_join)
    channel->number_joined += 1.0f;

  channel->number_joined -=
    (float)(io_time_get(IO_TIME_MONOTONIC_SEC) - channel->last_join_time) *
    ((float)GlobalSetOptions.joinfloodcount / (float)GlobalSetOptions.joinfloodtime);

  if (channel->number_joined <= 0.0f)
  {
    channel->number_joined = 0.0f;
    channel->sent_join_flood_notice = false;
  }
  else if (channel->number_joined >= GlobalSetOptions.joinfloodcount)
  {
    channel->number_joined = GlobalSetOptions.joinfloodcount;

    if (channel->sent_join_flood_notice == false)
    {
      channel->sent_join_flood_notice = true;

      client_format_name_buffer_t client_name_buffer;
      const char *const client_name =
        client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer);

      sendto_clients(UMODE_FLOOD, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Possible Join Flooder %s on %s target: %s",
                     client_name, client->uplink->name, channel->name);
    }
  }

  channel->last_join_time = io_time_get(IO_TIME_MONOTONIC_SEC);
}

/*! \brief Adds a user to a channel by adding another link to the
 *         channels member chain.
 * \param channel    Pointer to channel to add client to
 * \param client     Pointer to client (who) to add
 * \param flags      Flags for chanops etc
 * \param track_join Whether to count this join in flood calculations
 */
void
channel_member_add(struct Channel *channel, struct Client *client, uint32_t flags, bool track_join)
{
  assert(client_is_user(client));

  _channel_track_join_flood(channel, client, track_join);

  struct ChannelMember *const member = io_calloc(sizeof(*member));
  member->client = client;
  member->channel = channel;
  member->flags = flags;
  list_add(member, &member->channode, &channel->members);

  if (client_is_local(client))
    list_add(member, &member->locchannode, &channel->members_local);

  list_add(member, &member->usernode, &client->channel_list);
}

/*! \brief Deletes an user from a channel by removing a link in the
 *         channels member chain.
 * \param member Pointer to Membership struct
 */
void
channel_member_remove(struct ChannelMember *member)
{
  struct Client *const client = member->client;
  struct Channel *const channel = member->channel;

  list_remove(&member->channode, &channel->members);

  if (client_is_local(client))
    list_remove(&member->locchannode, &channel->members_local);

  list_remove(&member->usernode, &client->channel_list);

  io_free(member);

  if (list_is_empty(&channel->members))
    channel_destroy(channel);
}

void
channel_member_remove_list(list_t *list)
{
  struct ChannelMember *member;

  while ((member = list_peek_head(list)))
    channel_member_remove(member);
}

void
channel_member_clear_prefixes(struct Channel *channel, const char *source_name)
{
  char modebuf[MAXMODEPARAMS + 1];
  char parabuf[MAXMODEPARAMS * (NICKLEN + 1) + 1];
  char *mbuf = modebuf;
  char *pbuf = parabuf;
  unsigned int pargs = 0;

  list_node_t *node;
  LIST_FOREACH(node, channel->members.head)
  {
    struct ChannelMember *const member = node->data;

    for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    {
      if (member_has_flags(member, tab->flag))
      {
        member->flags &= ~tab->flag;
        *mbuf++ = tab->letter;
        pbuf += snprintf(pbuf, sizeof(parabuf) - (pbuf - parabuf), pbuf != parabuf ? " %s" : "%s",
                         member->client->name);

        if (++pargs >= MAXMODEPARAMS)
        {
          *mbuf = '\0';
          sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s -%s %s",
                               source_name, channel->name, modebuf, parabuf);

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
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s -%s %s",
                         source_name, channel->name, modebuf, parabuf);
  }
}

static void
_channel_send_sjoin(struct Client *client, const struct Channel *channel)
{
  size_t len;
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf + snprintf(buf, sizeof(buf), ":%s SJOIN %ju %s %s :",
                                me.id, channel->creation_time,
                                channel->name, channel_modes(channel, client, true));
  char *const bufptr_start = bufptr;

  list_node_t *node;
  LIST_FOREACH(node, channel->members.head)
  {
    const struct ChannelMember *const member = node->data;

    len = strlen(member->client->id) + 1;  /* +1 for space */
    len += channel_member_get_prefix_length(member, true);

    if ((bufptr - buf) + len > sizeof(buf) - 2)
    {
      sendto_one(client, "%s", buf);
      bufptr = bufptr_start;
    }

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != bufptr_start ? " %s%s" : "%s%s",
                       channel_member_get_prefix(member, true), member->client->id);
  }

  sendto_one(client, "%s", buf);
}

/*! \brief Sends +b/+e/+I
 * \param client   Client pointer to server
 * \param channel  Pointer to channel
 * \param list     Pointer to list of modes to send
 * \param flag     Char flag flagging type of mode. Currently this can be 'b', e' or 'I'
 */
static void
_channel_send_mask_list(struct Client *client, const struct Channel *channel, const list_t *list, const char flag)
{
  if (list_is_empty(list))
    return;

  char buf[IRCD_BUFSIZE];
  char *bufptr = buf + snprintf(buf, sizeof(buf), ":%s BMASK %ju %s %c :",
                                me.id, channel->creation_time, channel->name, flag);
  char *const bufptr_start = bufptr;

  list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    const struct Ban *const ban = node->data;
    const size_t len = ban->banstr_len + 1;  /* +1 for space */

    /*
     * Send buffer and start over if we cannot fit another ban
     */
    if ((bufptr - buf) + len > sizeof(buf) - 2)
    {
      sendto_one(client, "%s", buf);
      bufptr = bufptr_start;
    }

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != bufptr_start ? " %s" : "%s", ban->banstr);
  }

  sendto_one(client, "%s", buf);
}

static void
_channel_send_tburst(struct Client *target, const struct Channel *channel)
{
  /*
   * Send TBURST even if the topic string is empty when topic_time is set.
   * A non-zero topic_time represents topic state and is needed to synchronize
   * topic removals correctly across equal channel timestamps.
   */
  if (channel->topic_time == 0)
    return;

  sendto_one(target, ":%s TBURST %ju %s %ju %s :%s",
             me.id, channel->creation_time, channel->name, channel->topic_time,
             channel->topic_info, string_or_empty(channel->topic));
}

static void
_channel_send_mlock(struct Client *target, const struct Channel *channel)
{
  if (!capab_has_flag(target, CAPAB_MLOCK))
    return;

  sendto_one(target, ":%s MLOCK %ju %s %ju :%s",
             me.id, channel->creation_time, channel->name,
             channel->mode_lock_time, string_or_empty(channel->mode_lock));
}

/*! \brief Send "client" a full list of the modes for channel channel
 * \param client  Pointer to client client
 * \param channel Pointer to channel pointer
 */
void
channel_send_state(struct Client *client, const struct Channel *channel)
{
  _channel_send_sjoin(client, channel);

  _channel_send_mask_list(client, channel, &channel->banlist, 'b');
  _channel_send_mask_list(client, channel, &channel->exceptlist, 'e');
  _channel_send_mask_list(client, channel, &channel->invexlist, 'I');

  _channel_send_tburst(client, channel);
  _channel_send_mlock(client, channel);
}

/*! \brief Check channel name for invalid characters
 * \param name Pointer to channel name string
 * \param local Indicates whether it's a local or remote creation
 * \return false if invalid, true otherwise
 */
bool
channel_is_valid_name(const char *name, bool is_local_source)
{
  const char *p = name;

  assert(!string_is_empty(p));

  if (!IsChanPrefix(*p))
    return false;

  if (is_local_source == false || ConfigChannel.disable_fake_channels == 0)
  {
    while (*++p)
      if (!IsChanChar(*p))
        return false;
  }
  else
  {
    while (*++p)
      if (!IsVisibleChanChar(*p))
        return false;
  }

  return p - name <= CHANNELLEN;
}

void
remove_ban(struct Ban *ban, list_t *list)
{
  list_remove(&ban->node, list);
  io_free(ban);
}

static void
_channel_free_mask_list(list_t *list)
{
  while (list->head)
  {
    struct Ban *const ban = list->head->data;
    remove_ban(ban, list);
  }
}

/*! \brief Get Channel block for name (and allocate a new channel
 *         block, if it didn't exist before)
 * \param name Channel name
 * \return Channel block
 */
struct Channel *
channel_create(const char *name)
{
  assert(!string_is_empty(name));

  struct Channel *const channel = io_calloc(sizeof(*channel));
  channel->hnextch = channel;
  /* Doesn't hurt to set it here */
  channel->creation_time = io_time_get(IO_TIME_REALTIME_SEC);
  channel->last_join_time = io_time_get(IO_TIME_MONOTONIC_SEC);
  /* Cache channel name length to avoid repetitive strlen() calls. */
  channel->name_len = strlcpy(channel->name, name, sizeof(channel->name));
  if (channel->name_len >= sizeof(channel->name))
    channel->name_len = sizeof(channel->name) - 1;

  list_add(channel, &channel->node, &channel_list);
  hash_add_channel(channel);

  return channel;
}

/*! \brief Walk through this channel, and destroy it.
 * \param channel Channel pointer
 */
void
channel_destroy(struct Channel *channel)
{
  invite_clear_list(&channel->invites);

  /* Free ban/exception/invex lists */
  _channel_free_mask_list(&channel->banlist);
  _channel_free_mask_list(&channel->exceptlist);
  _channel_free_mask_list(&channel->invexlist);

  list_remove(&channel->node, &channel_list);
  hash_del_channel(channel);

  assert(channel->hnextch == channel);

  assert(channel->node.prev == NULL);
  assert(channel->node.next == NULL);

  assert(list_length(&channel->members_local) == 0);
  assert(channel->members_local.head == NULL);
  assert(channel->members_local.tail == NULL);

  assert(list_length(&channel->members) == 0);
  assert(channel->members.head == NULL);
  assert(channel->members.tail == NULL);

  assert(list_length(&channel->invites) == 0);
  assert(channel->invites.head == NULL);
  assert(channel->invites.tail == NULL);

  assert(list_length(&channel->banlist) == 0);
  assert(channel->banlist.head == NULL);
  assert(channel->banlist.tail == NULL);

  assert(list_length(&channel->exceptlist) == 0);
  assert(channel->exceptlist.head == NULL);
  assert(channel->exceptlist.tail == NULL);

  assert(list_length(&channel->invexlist) == 0);
  assert(channel->invexlist.head == NULL);
  assert(channel->invexlist.tail == NULL);

  io_free(channel->topic);
  channel->topic = NULL;
  io_free(channel->topic_info);
  channel->topic_info = NULL;
  io_free(channel->mode_lock);
  channel->mode_lock = NULL;
  io_free(channel);
}

/**
 * @brief Gets the symbolic prefix ('=', '*', '@') representing a channel's privacy level.
 *
 * Translates a channel's mode flags (+p, +s) into the corresponding prefix
 * used in protocol messages like RPL_NAMREPLY (353) to denote its public,
 * private, or secret visibility.
 *
 * @param channel The channel whose privacy prefix is to be determined.
 * @return A string literal containing the privacy prefix ("=", "*", or "@").
 */
static const char *
_channel_get_privacy_prefix(const struct Channel *channel)
{
  if (channel_is_secret(channel))
    return "@";
  if (channel_is_private(channel))
    return "*";
  return "=";
}

/*! \brief lists all names on given channel
 * \param client   Pointer to client struct requesting names
 * \param channel  Pointer to channel block
 */
void
channel_send_namereply(struct Client *client, struct Channel *channel)
{
  assert(client_is_user(client));

  const bool is_member = channel_member_find(client, channel) != NULL;
  const bool multi_prefix = client_has_cap(client, CAP_MULTI_PREFIX);
  const bool uhnames = client_has_cap(client, CAP_UHNAMES);

  if (channel_is_public(channel) || is_member)
  {
    char buf[IRCD_BUFSIZE];
    char *bufptr = buf;
    /* :me.name 353 client->name @ channel->name :+nick1 @nick2 %nick3 ...\r\n */
    /* 1       23456            789             01                        2 3  */
    size_t len = strlen(me.name) + strlen(client->name) + channel->name_len + 13;

    list_node_t *node;
    LIST_FOREACH(node, channel->members.head)
    {
      const struct ChannelMember *const member = node->data;
      if (user_mode_has_flag(member->client, UMODE_INVISIBLE) && is_member == false)
        continue;

      size_t masklen = 0;
      if (uhnames)
        masklen = strlen(member->client->name) + strlen(member->client->username) +
                  strlen(member->client->host) + 3;  /* +3 for ! + @ + space */
      else
        masklen = strlen(member->client->name) + 1;  /* +1 for space */

      masklen += channel_member_get_prefix_length(member, multi_prefix);

      if ((bufptr - buf) + masklen + len > sizeof(buf))
      {
        sendto_one_numeric(client, &me, RPL_NAMREPLY,
                           _channel_get_privacy_prefix(channel), channel->name, buf);
        bufptr = buf;
      }

      if (uhnames)
        bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s%s!%s@%s" : "%s%s!%s@%s",
                           channel_member_get_prefix(member, multi_prefix),
                           member->client->name, member->client->username, member->client->host);
      else
        bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s%s" : "%s%s",
                           channel_member_get_prefix(member, multi_prefix), member->client->name);
    }

    if (bufptr != buf)
      sendto_one_numeric(client, &me, RPL_NAMREPLY,
                         _channel_get_privacy_prefix(channel), channel->name, buf);
  }

  sendto_one_numeric(client, &me, RPL_ENDOFNAMES, channel->name);
}

int
channel_member_prefix_to_rank(const char prefix)
{
  for (const struct chan_mode *tab = cflag_tab; tab->prefix; ++tab)
    if (tab->prefix == prefix)
      return tab->rank;
  return CHACCESS_PEON;
}

const char *
channel_member_rank_to_prefix(const int rank)
{
  for (const struct chan_mode *tab = cflag_tab; tab->prefix; ++tab)
  {
    if (tab->rank == rank)
    {
      static char prefix[2];
      prefix[0] = tab->prefix;
      prefix[1] = '\0';  /* Just for safety */

      return prefix;
    }
  }

  return "";
}

uint32_t
channel_member_prefix_to_flag(const char prefix)
{
  for (const struct chan_mode *tab = cflag_tab; tab->prefix; ++tab)
    if (tab->prefix == prefix)
      return tab->flag;
  return 0;
}

const char *
channel_member_get_prefix(const struct ChannelMember *member, bool combine)
{
  static char buf[CMEMBER_STATUS_FLAGS_LEN + 1];  /* +1 for \0 */
  char *bufptr = buf;

  for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    if (member_has_flags(member, tab->flag))
      if (*bufptr++ = tab->prefix, combine == false)
        break;

  *bufptr = '\0';
  return buf;
}

size_t
channel_member_get_prefix_length(const struct ChannelMember *member, bool combine)
{
  size_t len = 0;

  for (const struct chan_mode *tab = cflag_tab; tab->letter; ++tab)
    if (member_has_flags(member, tab->flag))
      if (++len, combine == false)
        break;

  return len;
}

int
channel_member_get_highest_rank(const struct ChannelMember *member)
{
  if (member == NULL)
    return CHACCESS_NOTONCHAN;

  if (member_has_flags(member, CHFL_CHANOWNER))
    return CHACCESS_OWNER;

  if (member_has_flags(member, CHFL_CHANADMIN))
    return CHACCESS_ADMIN;

  if (member_has_flags(member, CHFL_CHANOP))
    return CHACCESS_OP;

  if (member_has_flags(member, CHFL_HALFOP))
    return CHACCESS_HALFOP;

  if (member_has_flags(member, CHFL_VOICE))
    return CHACCESS_VOICE;

  return CHACCESS_PEON;
}

/*!
 * \param client Pointer to Client to check
 * \param list   Pointer to ban list to search
 * \return true if ban found for given n!u\@h mask, false otherwise
 */
static bool
_ban_matches(struct Client *client, struct Channel *channel, struct Ban *ban)
{
  /* Is a matching extban, call custom match handler */
  if (ban->extban & extban_matching_mask())
  {
    const struct Extban *const extban = extban_find_flag(ban->extban & extban_matching_mask());
    if (extban == NULL)
      return false;

    if (extban->matches == NULL || extban->matches(client, channel, ban) == EXTBAN_NO_MATCH)
      return false;

    return true;
  }

  if (match(ban->name, client->name) == 0 && match(ban->user, client->username) == 0)
  {
    switch (ban->type)
    {
      case HM_HOST:
        if (match(ban->host, client->realhost) == 0 ||
            match(ban->host, client->sockhost) == 0 || match(ban->host, client->host) == 0)
          return true;
        break;
      case HM_IPV6:
      case HM_IPV4:
        if (address_match(&client->addr, &ban->addr, false, false, ban->bits))
          return true;
        break;
      default:
        assert(0);
    }
  }

  return false;
}

bool
find_bmask(struct Client *client, struct Channel *channel, const list_t *list, struct Extban *extban)
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
  {
    struct Ban *const ban = node->data;

    /* Looking for a specific type of extban? */
    if (extban)
    {
      if (!(ban->extban & extban->flag))
        continue;
    }
    else
    {
      /*
       * Acting extbans have their own time they act and are not general purpose bans,
       * so skip them unless we are hunting them.
       */
      if (ban->extban & extban_acting_mask())
        continue;
    }

    bool matches = _ban_matches(client, channel, ban);
    if (matches == false)
      continue;

    return true;
  }

  return false;
}

/*!
 * \param channel Pointer to channel block
 * \param client  Pointer to client to check access fo
 * \return false if not banned, true otherwise
 */
bool
is_banned(struct Channel *channel, struct Client *client, struct Extban *extban)
{
  if (find_bmask(client, channel, &channel->banlist, extban))
    return !find_bmask(client, channel, &channel->exceptlist, extban);
  return false;
}

/*! Tests if a client can join a certain channel
 * \param client Pointer to client attempting to join
 * \param channel  Pointer to channel
 * \param key      Key sent by client attempting to join if present
 * \return ERR_BANNEDFROMCHAN, ERR_INVITEONLYCHAN, ERR_CHANNELISFULL
 *         or 0 if allowed to join.
 */
static int
_can_join(struct Client *client, struct Channel *channel, const char *key)
{
  if (channel_has_mode(channel, MODE_SECUREONLY) && !user_mode_has_flag(client, UMODE_SECURE))
    return ERR_SECUREONLYCHAN;

  if (channel_has_mode(channel, MODE_REGONLY) && !user_mode_has_flag(client, UMODE_REGISTERED))
    return ERR_NEEDREGGEDNICK;

  if (channel_has_mode(channel, MODE_OPERONLY) && !client_is_oper(client))
    return ERR_OPERONLYCHAN;

  if (channel_has_mode(channel, MODE_INVITEONLY))
    if (invite_find(channel, client) == NULL)
      if (!find_bmask(client, channel, &channel->invexlist, NULL))
        return ERR_INVITEONLYCHAN;

  if (channel->mode.key[0] && (string_is_empty(key) || strcmp(channel->mode.key, key)))
    return ERR_BADCHANNELKEY;

  if (channel->mode.limit && list_length(&channel->members) >= channel->mode.limit)
    return ERR_CHANNELISFULL;

  if (is_banned(channel, client, NULL) || is_banned(channel, client, &extban_join))
    return ERR_BANNEDFROMCHAN;

  return 0;
}

struct ChannelMember *
channel_member_find(const struct Client *client, const struct Channel *channel)
{
  if (!client_is_user(client))
    return NULL;

  /* Take the shortest of the two lists */
  if (list_length(&channel->members) < list_length(&client->channel_list))
  {
    list_node_t *node;
    LIST_FOREACH(node, channel->members.head)
    {
      struct ChannelMember *const member = node->data;
      if (member->client == client)
        return member;
    }
  }
  else
  {
    list_node_t *node;
    LIST_FOREACH(node, client->channel_list.head)
    {
      struct ChannelMember *const member = node->data;
      if (member->channel == channel)
        return member;
    }
  }

  return NULL;
}

/*! Checks if a message contains control codes
 * \param message The actual message string the client wants to send
 * \return true if the message does contain any control codes, false otherwise
 */
static bool
_msg_has_ctrls(const char *message)
{
  const unsigned char *p = (const unsigned char *)message;

  for (; *p; ++p)
  {
    if (*p > 31 || *p == 1)
      continue;  /* No control code or CTCP */

    if (*p == 27)  /* Escape */
    {
      /* ISO 2022 charset shift sequence */
      if (*(p + 1) == '$' ||
          *(p + 1) == '(')
      {
        ++p;
        continue;
      }
    }

    return true;  /* Control code */
  }

  return false;  /* No control code found */
}

/*! Tests if a client can send to a channel
 * \param channel Pointer to Channel struct
 * \param client  Pointer to Client struct
 * \param member  Pointer to Membership struct (can be NULL)
 * \param message The actual message string the client wants to send
 * \return CAN_SEND_OPV if op, halfop, or voiced on channel\n
 *         CAN_SEND_NONOP if can send to channel but is not an op\n
 *         CAN_SEND_NO if they cannot send to channel\n
 */
channel_send_perm_t
channel_send_qualifies(struct Channel *channel, struct Client *client, struct ChannelMember *member,
                       unsigned int statusmsg, const char *message, bool notice, const char **error)
{
  if (client_is_server(client) || client_is_service(client))
    return CHANNEL_SEND_PERM_ELEVATED;

  if (client_is_local(client) && !client_has_flag(client, FLAGS_EXEMPTRESV))
  {
    if (!(client_is_oper(client) && client_has_oper_flag(client, OPER_FLAG_JOIN_RESV)))
    {
      const struct ResvItem *const resv = resv_find(channel->name, match);
      if (resv && !resv_exempt_find(client, resv))
      {
        *error = "channel is reserved";
        return CHANNEL_SEND_PERM_FORBIDDEN;
      }
    }
  }

  if (channel_has_mode(channel, MODE_NOCTRL) && _msg_has_ctrls(message))
  {
    *error = "control codes are not permitted";
    return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  if (channel_has_mode(channel, MODE_NOCTCP))
  {
    if (*message == '\001' && strncmp(message + 1, "ACTION ", 7))
    {
      *error = "CTCPs are not permitted";
      return CHANNEL_SEND_PERM_FORBIDDEN;
    }
  }

  if (member || (member = channel_member_find(client, channel)))
    if (channel_member_get_highest_rank(member) > CHACCESS_PEON)
      return CHANNEL_SEND_PERM_ELEVATED;

  if (statusmsg)
  {
    *error = "STATUSMSG requires elevated privileges";
    return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  if (member == NULL && channel_has_mode(channel, MODE_NOPRIVMSGS))
  {
    *error = "external messages are not permitted";
    return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  if (channel_has_mode(channel, MODE_MODERATED))
  {
    *error = "channel is moderated (+m)";
    return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  if (channel_has_mode(channel, MODE_MODREG) && !user_mode_has_flag(client, UMODE_REGISTERED))
  {
    *error = "you need to identify to a registered nick";
    return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  if (channel_has_mode(channel, MODE_NONOTICE) && notice)
  {
    *error = "NOTICEs are not permitted";
    return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  *error = "you are banned (+b)";
  /* Cache can send if banned */
  if (client_is_local(client))
  {
    if (member)
    {
      if (member->flags & CHFL_BAN_SILENCED)
        return CHANNEL_SEND_PERM_FORBIDDEN;

      if (!(member->flags & CHFL_BAN_CHECKED))
      {
        if (is_banned(channel, client, NULL) || is_banned(channel, client, &extban_mute))
        {
          member->flags |= (CHFL_BAN_CHECKED | CHFL_BAN_SILENCED);
          return CHANNEL_SEND_PERM_FORBIDDEN;
        }

        member->flags |= CHFL_BAN_CHECKED;
      }
    }
    else if (is_banned(channel, client, NULL) || is_banned(channel, client, &extban_mute))
      return CHANNEL_SEND_PERM_FORBIDDEN;
  }

  return CHANNEL_SEND_PERM_STANDARD;
}

/*! \brief Updates the client's oper_warn_count_down, warns the
 *         IRC operators if necessary, and updates
 *         join_part_countdown as needed.
 * \param client Pointer to struct Client to check
 * \param name   Channel name or NULL if this is a part.
 */
static void
_channel_check_spambot_warning(struct Client *client, const char *name)
{
  if (GlobalSetOptions.spam_num &&
      (client->connection->join_part_count >= GlobalSetOptions.spam_num))
  {
    if (client->connection->oper_warn_count_down)
      --client->connection->oper_warn_count_down;

    if (client->connection->oper_warn_count_down == 0 && name)
    {
      client->connection->oper_warn_count_down = OPER_SPAM_COUNTDOWN;

      /* It's already known as a possible spambot */
      sendto_clients(UMODE_FLOOD, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "User %s (%s@%s) trying to join %s is a possible spambot",
                     client->name, client->username, client->host, name);
    }
  }
  else
  {
    const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
    const uintmax_t part_delta = now - client->connection->last_part_time;

    if (part_delta > JOIN_LEAVE_COUNT_EXPIRE_TIME)
    {
      const unsigned int decrement_count = part_delta / JOIN_LEAVE_COUNT_EXPIRE_TIME;
      if (decrement_count > client->connection->join_part_count)
        client->connection->join_part_count = 0;
      else
        client->connection->join_part_count -= decrement_count;
    }
    else if (now - client->connection->last_join_time < GlobalSetOptions.spam_time)
      ++client->connection->join_part_count;  /* It's a possible spambot */

    if (name)
      client->connection->last_join_time = now;
    else
      client->connection->last_part_time = now;
  }
}

/*! \brief Sets the channel topic for a certain channel
 * \param channel    Pointer to struct Channel
 * \param topic      The topic string
 * \param topic_info n!u\@h formatted string of the topic setter
 * \param topicts    Timestamp on the topic
 * \param local      Whether the topic is set by a local client
 */
void
channel_set_topic(struct Channel *channel, const char *topic, const char *topic_info, uintmax_t topicts, bool local)
{
  io_free(channel->topic);
  channel->topic = NULL;
  io_free(channel->topic_info);
  channel->topic_info = NULL;

  if (!string_is_empty(topic))
  {
    const size_t max_length = local ? ConfigServerInfo.max_topic_length : TOPICLEN;
    channel->topic = io_strndup(topic, max_length);
  }

  if (!string_is_empty(topic_info))
    channel->topic_info = io_strdup(topic_info);

  channel->topic_time = topicts;
}

/*! \brief Sets the mode lock for a certain channel
 * \param client     Pointer to struct Client
 * \param channel    Pointer to struct Channel
 * \param mode_lock  The modes to lock as a string. Can be NULL.
 */
void
channel_set_mode_lock(struct Client *client, struct Channel *channel, const char *mode_lock)
{
  io_free(channel->mode_lock);
  channel->mode_lock = NULL;

  if (!string_is_empty(mode_lock))
    channel->mode_lock = io_strdup(mode_lock);
}

void
channel_join_list(struct Client *client, char *chan_list, char *key_list)
{
  assert(client_is_local_user(client));

  char *p = NULL;
  for (const char *name = strtok_r(chan_list, ",", &p); name;
                   name = strtok_r(NULL,      ",", &p))
  {
    const char *key = NULL;
    /* If we have any more keys, take the first for this channel. */
    if (!string_is_empty(key_list) && (key_list = strchr(key = key_list, ',')))
      *key_list++ = '\0';

    channel_join(client, name, key);
  }
}

void
channel_join(struct Client *client, const char *name, const char *key)
{
  if (!channel_is_valid_name(name, true))
  {
    sendto_one_numeric(client, &me, ERR_BADCHANNAME, name);
    return;
  }

  const bool can_join_reserved_channel =
    client_has_flag(client, FLAGS_EXEMPTRESV) ||
    (client_is_oper(client) && client_has_oper_flag(client, OPER_FLAG_JOIN_RESV));
  const struct ResvItem *const resv = can_join_reserved_channel ? NULL : resv_find(name, match);

  if (resv && !resv_exempt_find(client, resv))
  {
    sendto_one_numeric(client, &me, ERR_CHANBANREASON, name, resv->reason);

    client_format_name_buffer_t client_name_buffer;
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Forbidding reserved channel %s from user %s",
                   name, client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer));
    return;
  }

  unsigned int max_channels = client_get_max_channels(client);
  if (list_length(&client->channel_list) >= max_channels)
  {
    sendto_one_numeric(client, &me, ERR_TOOMANYCHANNELS, name);
    return;
  }

  uint32_t flags = 0;
  struct Channel *channel = channel_find(name);
  if (channel == NULL)
  {
    flags = CHFL_CHANOP;
    channel = channel_create(name);
  }
  else
  {
    if (channel_member_find(client, channel))
      return;

    /* can_join() checks for +i, +l, key, bans, etc. */
    int ret = _can_join(client, channel, key);
    if (ret)
    {
      sendto_one_numeric(client, &me, ret, channel->name);
      return;
    }
  }

  if (!client_is_oper(client))
    _channel_check_spambot_warning(client, channel->name);

  channel_member_add(channel, client, flags, true);
  client->connection->last_join_time = io_time_get(IO_TIME_MONOTONIC_SEC);

  /*
   * Set channel modes if appropriate, and propagate
   */
  if (flags == CHFL_CHANOP)
  {
    channel_set_mode(channel, MODE_TOPICLIMIT | MODE_NOPRIVMSGS);

    sendto_servers(NULL, 0, 0, ":%s SJOIN %ju %s +nt :@%s",
                   me.id, channel->creation_time, channel->name, client->id);

    /*
     * Notify all other users on the new channel
     */
    sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                         client->name, client->username, client->host, channel->name, client->account, client->info);
    sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                         client->name, client->username, client->host, channel->name);
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +nt",
                         me.name, channel->name);
  }
  else
  {
    sendto_servers(NULL, 0, 0, ":%s JOIN %ju %s +",
                   client->id, channel->creation_time, channel->name);

    sendto_channel_local(NULL, channel, 0, CAP_EXTENDED_JOIN, 0, ":%s!%s@%s JOIN %s %s :%s",
                         client->name, client->username, client->host, channel->name, client->account, client->info);
    sendto_channel_local(NULL, channel, 0, 0, CAP_EXTENDED_JOIN, ":%s!%s@%s JOIN :%s",
                         client->name, client->username, client->host, channel->name);
  }

  if (client->away_message)
    sendto_channel_local(client, channel, 0, CAP_AWAY_NOTIFY, 0, ":%s!%s@%s AWAY :%s",
                         client->name, client->username, client->host, client->away_message);

  struct Invite *const invite = invite_find(channel, client);
  if (invite)
    invite_del(invite);

  if (!string_is_empty(channel->topic))
  {
    sendto_one_numeric(client, &me, RPL_TOPIC, channel->name, channel->topic);
    sendto_one_numeric(client, &me, RPL_TOPICWHOTIME,
                       channel->name, channel->topic_info, channel->topic_time);
  }

  channel_send_namereply(client, channel);
}

/*! \brief Removes a client from a specific channel
 * \param client Pointer to client to remove
 * \param name   Name of channel to remove from
 * \param reason Part reason to show
 */
void
channel_part(struct Client *client, const char *name, const char *reason)
{
  struct Channel *const channel = channel_find(name);
  if (channel == NULL)
  {
    sendto_one_numeric(client, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  struct ChannelMember *const member = channel_member_find(client, channel);
  if (member == NULL)
  {
    sendto_one_numeric(client, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  if (client_is_local(client) && !client_is_oper(client))
    _channel_check_spambot_warning(client, NULL);

  /*
   * Remove user from the old channel (if any). Only allow /part reasons in -m chans.
   */
  bool show_reason = true;
  if (string_is_empty(reason))
    show_reason = false;
  else if (client_is_local(client))
  {
    const char *error;
    if (client_get_session_duration(client) <= ConfigGeneral.anti_spam_exit_message_time)
      show_reason = false;
    else if (channel_send_qualifies(channel, client, member, 0, reason, false, &error) == CHANNEL_SEND_PERM_FORBIDDEN)
      show_reason = false;
  }

  if (show_reason)
  {
    sendto_servers(client, 0, 0, ":%s PART %s :%.*s",
                   client->id, channel->name, KICKLEN, reason);
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s PART %s :%.*s",
                         client->name, client->username, client->host, channel->name, KICKLEN, reason);
  }
  else
  {
    sendto_servers(client, 0, 0, ":%s PART %s",
                   client->id, channel->name);
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s PART %s",
                         client->name, client->username, client->host, channel->name);
  }

  channel_member_remove(member);
}

void
channel_part_list(struct Client *client, char *list, const char *reason)
{
  assert(client_is_user(client));

  char *p = NULL;
  for (const char *name = strtok_r(list, ",", &p); name;
                   name = strtok_r(NULL, ",", &p))
    channel_part(client, name, reason);
}
