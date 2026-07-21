/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_nick.c
 * \brief Includes required functions for processing the NICK command.
 */

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "misc.h"
#include "module.h"

#include "aline.h"
#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "client_format.h"
#include "client_id.h"
#include "conf.h"
#include "conf_resv.h"
#include "extban.h"
#include "hash.h"
#include "ipcache.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "monitor.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user.h"
#include "user_mode.h"
#include "whowas.h"

static bool
check_clean_nick(struct Client *source, const char *nick)
{
  assert(client_is_server(source) || (client_is_user(source) && !client_is_local(source)));

  /*
   * The old code did some wacky stuff here, if the nick is invalid, kill it
   * and don't bother messing at all
   */
  if (valid_nickname(nick, false))
    return true;

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Bad/long Nick: %s From: %s(via %s)",
                 nick, client_is_server(source) ? source->name : source->uplink->name, source->nexthop->name);
  sendto_one(source, ":%s KILL %s :%s (Bad Nickname)",
             me.id, nick, me.name);

  /* Bad nick change */
  if (!client_is_server(source))
  {
    sendto_servers(source, 0, 0, ":%s KILL %s :%s (Bad Nickname)",
                   me.id, source->id, me.name);

    client_set_flag(source, FLAGS_KILLED);
    client_exit(source, "Bad Nickname");
  }

  ++ServerStats.is_kill;
  return false;
}

static bool
check_clean_uid(struct Client *source, const char *nick, const char *uid)
{
  assert(client_is_server(source));

  if (client_id_is_valid_uid(uid) && strncmp(uid, source->id, CLIENT_ID_SID_LENGTH) == 0)
    return true;

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Bad UID: %s Nickname: %s From: %s(via %s)",
                 uid, nick, source->name, source->nexthop->name);
  sendto_one(source, ":%s KILL %s :%s (Bad UID)",
             me.id, uid, me.name);

  ++ServerStats.is_kill;
  return false;
}

static bool
check_clean_user(struct Client *source, const char *nick, const char *user)
{
  assert(client_is_server(source));

  if (valid_username(user, false))
    return true;

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Bad/Long Username: %s Nickname: %s From: %s(via %s)",
                 user, nick, source->name, source->nexthop->name);
  sendto_one(source, ":%s KILL %s :%s (Bad Username)",
             me.id, nick, me.name);

  ++ServerStats.is_kill;
  return false;
}

static bool
check_clean_host(struct Client *source, const char *nick, const char *host)
{
  assert(client_is_server(source));

  if (valid_hostname(host))
    return true;

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Bad/Long Hostname: %s Nickname: %s From: %s(via %s)",
                 host, nick, source->name, source->nexthop->name);
  sendto_one(source, ":%s KILL %s :%s (Bad Hostname)",
             me.id, nick, me.name);

  ++ServerStats.is_kill;
  return false;
}

static void
set_initial_nick(struct Client *source, const char *nick)
{
  bool samenick = io_strcasecmp(source->name, nick) == 0;
  if (samenick == false)
    source->tsinfo = io_time_get(IO_TIME_REALTIME_SEC);

  client_update_name(source, nick);

  source->connection->registration &= ~REG_NEED_NICK;
  if (source->connection->registration == 0)
    user_register_local(source);
}

static void
nick_change_local(struct Client *source, const char *nick)
{
  assert(source->name[0] && !string_is_empty(nick));
  assert(client_is_local_user(source));

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  if (now - source->connection->nick.last_attempt > ConfigGeneral.max_nick_time)
    source->connection->nick.count = 0;

  if (ConfigGeneral.anti_nick_flood && !client_is_oper(source) &&
      (source->connection->nick.count > ConfigGeneral.max_nick_changes))
  {
    sendto_one_numeric(source, &me, ERR_NICKTOOFAST,
                       nick, ConfigGeneral.max_nick_time);
    return;
  }

  source->connection->nick.last_attempt = now;
  source->connection->nick.count++;

  bool samenick = io_strcasecmp(source->name, nick) == 0;
  if (samenick == false)
  {
    source->tsinfo = io_time_get(IO_TIME_REALTIME_SEC);

    clear_ban_cache_list(&source->channel_member_list);

    monitor_notify_signoff(source);

    if (user_mode_has_flag(source, UMODE_REGISTERED))
    {
      const uint64_t mode_flags_old = source->user_mode_flags;
      user_mode_unset_flag(source, UMODE_REGISTERED);
      user_mode_send(source, mode_flags_old, USER_MODE_SEND_USER);
    }
  }

  ircd_hook_nick_change_ctx ctx = { .client = source, .nick = nick };
  hook_dispatch(ircd_hook_nick_change_local, &ctx);

  whowas_add_history(source, true);

  sendto_servers(source, 0, 0, ":%s NICK %s :%ju",
                 source->id, nick, source->tsinfo);
  sendto_common_channels_local(source, true, 0, 0, ":%s!%s@%s NICK :%s",
                               source->name, source->username, source->host, nick);

  client_update_name(source, nick);

  if (samenick == false)
    monitor_notify_signon(source);
}

/*!
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = timestamp
 */
static void
nick_change_remote(struct Client *source, char *parv[])
{
  const char *const new_nick = parv[1];

  assert(!string_is_empty(new_nick));
  assert(client_is_user(source));
  assert(source->name[0]);

  /* Client changing their nick */
  bool samenick = io_strcasecmp(source->name, new_nick) == 0;
  if (samenick == false)
  {
    source->tsinfo = strtoumax(parv[2], NULL, 10);
    assert(source->tsinfo);

    user_mode_unset_flag(source, UMODE_REGISTERED);

    monitor_notify_signoff(source);
  }

  ircd_hook_nick_change_ctx ctx = { .client = source, .nick = new_nick };
  hook_dispatch(ircd_hook_nick_change_remote, &ctx);

  whowas_add_history(source, true);

  sendto_servers(source, 0, 0, ":%s NICK %s :%ju",
                 source->id, new_nick, source->tsinfo);
  sendto_common_channels_local(source, true, 0, 0, ":%s!%s@%s NICK :%s",
                               source->name, source->username, source->host, new_nick);

  /* Set the new nick name */
  client_update_name(source, new_nick);

  if (samenick == false)
    monitor_notify_signon(source);
}

/*!
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 *      - parv[ 1] = nickname
 *      - parv[ 2] = hop count
 *      - parv[ 3] = TS
 *      - parv[ 4] = umode
 *      - parv[ 5] = username
 *      - parv[ 6] = hostname
 *      - parv[ 7] = real host
 *      - parv[ 8] = IP address
 *      - parv[ 9] = uid
 *      - parv[10] = services id (account name)
 *      - parv[11] = ircname (gecos)
 */
static void
uid_from_server(struct Client *source, int parc, char *parv[])
{
  struct Client *const client = client_create_remote(source);
  client->hopcount = atoi(parv[2]);
  client->tsinfo = strtoumax(parv[3], NULL, 10);

  strlcpy(client->name, parv[1], sizeof(client->name));
  strlcpy(client->username, parv[5], sizeof(client->username));
  strlcpy(client->host, parv[6], sizeof(client->host));
  strlcpy(client->realhost, parv[7], sizeof(client->realhost));
  strlcpy(client->sockhost, parv[8], sizeof(client->sockhost));
  strlcpy(client->id, parv[9], sizeof(client->id));
  strlcpy(client->account, parv[10], sizeof(client->account));
  strlcpy(client->info, parv[11], sizeof(client->info));

  if (address_from_string(client->sockhost, &client->addr))
  {
    struct ip_entry *const ipcache = ipcache_record_find_or_add(&client->addr);
    ++ipcache->count_remote;
    client_set_flag(client, FLAGS_IPHASH);
  }

  hash_add_client(client);
  hash_add_id(client);

  /* Parse user modes */
  for (const char *m = &parv[4][1]; *m; ++m)
  {
    const struct UserMode *const mode = user_mode_find(*m);
    user_mode_set_mode_exec(client, mode, USER_MODE_SOURCE_REGULAR);
  }

  user_register_remote(client);
}

/*!
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 *      - parv[ 0] = command
 *      - parv[ 1] = nickname
 *      - parv[ 2] = hop count
 *      - parv[ 3] = TS
 *      - parv[ 4] = umode
 *      - parv[ 5] = username
 *      - parv[ 6] = hostname
 *      - parv[ 7] = real host
 *      - parv[ 8] = IP address
 *      - parv[ 9] = uid
 *      - parv[10] = services id (account name)
 *      - parv[11] = ircname (gecos)
 */
static bool
perform_uid_introduction_collides(struct Client *source, struct Client *target,
                                  int parc, char *parv[])
{
  const char *uid = parv[9];
  uintmax_t newts = strtoumax(parv[3], NULL, 10);

  assert(client_is_server(source));
  assert(client_is_user(target));

  /* Server introducing new nick */

  /* If their TS's are the same, kill both */
  if (newts == target->tsinfo)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(both killed)",
                   target->name, target->nexthop->name, source->nexthop->name);

    sendto_one(source, ":%s KILL %s :%s (Nick collision (new))",
               me.id, uid, me.name);
    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick collision (new))",
                   me.id, target->id, me.name);

    sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

    client_set_flag(target, FLAGS_KILLED);
    client_exit(target, "Nick collision (new)");

    ++ServerStats.is_kill;
    return false;
  }

  /* The timestamps are different */
  const bool sameuser = io_strcasecmp(target->username, parv[5]) == 0 &&
                        io_strcasecmp(target->sockhost, parv[8]) == 0;

  /*
   * If the users are the same (loaded a client on a different server)
   * and the new users ts is older, or the users are different and the
   * new users ts is newer, ignore the new client and let it do the kill
   */
  if ((sameuser && newts < target->tsinfo) || (sameuser == false && newts > target->tsinfo))
  {
    sendto_one(source, ":%s KILL %s :%s (Nick collision (new))",
               me.id, uid, me.name);
    return false;
  }

  if (sameuser)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(older killed)",
                   target->name, target->nexthop->name, source->nexthop->name);
  else
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(newer killed)",
                   target->name, target->nexthop->name, source->nexthop->name);

  sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick collision (new))",
                 me.id, target->id, me.name);

  sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

  client_set_flag(target, FLAGS_KILLED);
  client_exit(target, "Nick collision");

  ++ServerStats.is_kill;
  return true;
}

/*!
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = timestamp
 */
static bool
perform_nick_change_collides(struct Client *source, struct Client *target,
                             int parc, char *parv[])
{
  uintmax_t newts = strtoumax(parv[2], NULL, 10);

  assert(client_is_user(source));
  assert(client_is_user(target));
  assert(newts);

  /* It's a client changing nick and causing a collide */
  if (newts == target->tsinfo)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick change collision from %s to %s(%s <- %s)(both killed)",
                   source->name, target->name, target->nexthop->name,
                   source->nexthop->name);

    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                   me.id, source->id, me.name);
    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                   me.id, target->id, me.name);

    sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

    client_set_flag(source, FLAGS_KILLED);
    client_set_flag(target, FLAGS_KILLED);
    client_exit(source, "Nick collision (old)");
    client_exit(target, "Nick collision (new)");

    ServerStats.is_kill += 2;
    return false;
  }

  /* The timestamps are different */
  const bool sameuser = io_strcasecmp(target->username, source->username) == 0 &&
                        io_strcasecmp(target->sockhost, source->sockhost) == 0;
  if ((sameuser && newts < target->tsinfo) || (sameuser == false && newts > target->tsinfo))
  {
    if (sameuser)
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Nick change collision from %s to %s(%s <- %s)(older killed)",
                     source->name, target->name, target->nexthop->name,
                     source->nexthop->name);
    else
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Nick change collision from %s to %s(%s <- %s)(newer killed)",
                     source->name, target->name, target->nexthop->name,
                     source->nexthop->name);

    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                   me.id, source->id, me.name);

    client_set_flag(source, FLAGS_KILLED);
    if (sameuser)
      client_exit(source, "Nick collision (old)");
    else
      client_exit(source, "Nick collision (new)");

    ++ServerStats.is_kill;
    return false;
  }

  if (sameuser)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(older killed)",
                   target->name, target->nexthop->name, source->nexthop->name);
  else
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(newer killed)",
                   target->name, target->nexthop->name, source->nexthop->name);

  sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick collision)",
                 me.id, target->id, me.name);

  sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

  client_set_flag(target, FLAGS_KILLED);
  client_exit(target, "Nick collision");

  ++ServerStats.is_kill;
  return true;
}

/*! \brief NICK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 */
static void
mr_nick(struct Client *source, int parc, char *parv[])
{
  assert(client_is_local(source));

  const char *const new_nick = parv[1];
  if (string_is_empty(new_nick))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  char nick[NICKLEN + 1];
  strlcpy(nick, new_nick, IO_MIN(sizeof(nick), ConfigServerInfo.max_nick_length + 1));

  if (!valid_nickname(nick, true))
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, new_nick, "Erroneous Nickname");
    return;
  }

  const struct ResvItem *const resv = resv_find(nick, match);
  if (resv)
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, nick, resv->reason);

    client_format_name_buffer_t source_name_buffer;
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Forbidding reserved nick %s from user %s",
                   nick, client_format_name(source, CLIENT_FORMAT_NAME_PUBLIC, &source_name_buffer));
    return;
  }

  struct Client *const target = client_find_entity_by_name(nick);
  if (target == NULL || target == source)
    set_initial_nick(source, nick);
  else
    sendto_one_numeric(source, &me, ERR_NICKNAMEINUSE, target->name);
}

/*! \brief NICK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 */
static void
m_nick(struct Client *source, int parc, char *parv[])
{
  assert(client_is_local_user(source));

  const char *const new_nick = parv[1];
  if (string_is_empty(new_nick))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  char nick[NICKLEN + 1];
  strlcpy(nick, new_nick, IO_MIN(sizeof(nick), ConfigServerInfo.max_nick_length + 1));

  if (!valid_nickname(nick, true))
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, nick, "Erroneous Nickname");
    return;
  }

  const struct ResvItem *resv;
  if (!client_has_flag(source, FLAGS_EXEMPTRESV) &&
      !(client_is_oper(source) && client_has_oper_flag(source, OPER_FLAG_NICK_RESV)) &&
      (resv = resv_find(nick, match)))
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, nick, resv->reason);

    client_format_name_buffer_t source_name_buffer;
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Forbidding reserved nick %s from user %s",
                   nick, client_format_name(source, CLIENT_FORMAT_NAME_PUBLIC, &source_name_buffer));
    return;
  }

  list_node_t *node;
  LIST_FOREACH(node, source->channel_member_list.head)
  {
    struct ChannelMember *const member = node->data;
    if (channel_member_get_highest_rank(member) < CHACCESS_VOICE)
    {
      if (channel_has_mode(member->channel, MODE_NONICKCHANGE))
      {
        sendto_one_numeric(source, &me, ERR_NONICKCHANGE, member->channel->name);
        return;
      }

      if (is_banned(member->channel, source, &extban_nick))
      {
        sendto_one_numeric(source, &me, ERR_BANNICKCHANGE, member->channel->name);
        return;
      }
    }
  }

  struct Client *const target = client_find_entity_by_name(nick);
  if (target == NULL)
    nick_change_local(source, nick);
  else if (target == source)
  {
    /*
     * If (target == source) the client is changing nicks between
     * equivalent nicknames ie: nick -> nIcK.
     */

    /* Check the nick isn't exactly the same. */
    if (strcmp(target->name, nick))
      nick_change_local(source, nick);
  }
  else if (client_is_unknown(target))
  {
    /*
     * If the client that has the nick isn't registered yet (NICK but no
     * USER) then drop the unregistered client.
     */
    client_exit(target, "Overridden by other sign on");

    nick_change_local(source, nick);
  }
  else
    sendto_one_numeric(source, &me, ERR_NICKNAMEINUSE, target->name);
}

/*! \brief NICK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 * server -> server nick change
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = timestamp
 */
static void
ms_nick(struct Client *source, int parc, char *parv[])
{
  if (!client_is_user(source))
    return;  /* Servers and unknown clients can't change nicks. */

  const char *const new_nick = parv[1];
  if (!check_clean_nick(source, new_nick))
    return;

  /* If the nick doesn't exist, allow it and process like normal. */
  struct Client *const target = client_find_entity_by_name(new_nick);
  if (target == NULL)
    nick_change_remote(source, parv);
  else if (client_is_unknown(target))
  {
    /* We're not living in the past anymore, an unknown client is local only. */
    client_exit(target, "Overridden by other sign on");

    nick_change_remote(source, parv);
  }
  else if (target == source)
  {
    if (strcmp(target->name, new_nick))
      nick_change_remote(source, parv);
  }
  else if (perform_nick_change_collides(source, target, parc, parv))
    nick_change_remote(source, parv);
}

/*! \brief UID command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 *      - parv[ 0] = command
 *      - parv[ 1] = nickname
 *      - parv[ 2] = hop count
 *      - parv[ 3] = TS
 *      - parv[ 4] = umode
 *      - parv[ 5] = username
 *      - parv[ 6] = hostname
 *      - parv[ 7] = real host
 *      - parv[ 8] = IP address
 *      - parv[ 9] = uid
 *      - parv[10] = services id (account name)
 *      - parv[11] = ircname (gecos)
 */
static void
ms_uid(struct Client *source, int parc, char *parv[])
{
  if (check_clean_nick(source, parv[1]) == false ||
      check_clean_user(source, parv[1], parv[5]) == false ||
      check_clean_host(source, parv[1], parv[6]) == false ||
      check_clean_host(source, parv[1], parv[7]) == false ||
      check_clean_uid(source, parv[1], parv[9]) == false)
    return;

  /*
   * If there is an ID collision, kill our client, and kill theirs.
   * This may generate 401's, but it ensures that both clients always
   * go, even if the other server refuses to do the right thing.
   */
  struct Client *target = client_find_entity_by_id(parv[9]);
  if (target)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "ID collision for UID %s on %s (%s <- %s) (both killed)",
                   target->id, target->name, target->nexthop->name, source->nexthop->name);

    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (ID collision)",
                   me.id, target->id, me.name);

    client_set_flag(target, FLAGS_KILLED);
    client_exit(target, "ID Collision");

    ++ServerStats.is_kill;
    return;
  }

  target = client_find_entity_by_name(parv[1]);
  if (target == NULL)
    uid_from_server(source, parc, parv);
  else if (client_is_unknown(target))
  {
    client_exit(target, "Overridden by other sign on");

    uid_from_server(source, parc, parv);
  }
  else if (perform_uid_introduction_collides(source, target, parc, parv))
    uid_from_server(source, parc, parv);
}

static struct Command command_table[] =
{
  [0] = {
    .name = "NICK",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_nick },
    .handlers[COMMAND_HANDLER_USER] = { .handler = m_nick, .end_grace_period = true },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_nick, .args_min = 3 },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = m_nick }
  },
  [1] = {
    .name = "UID",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_uid, .args_min = 12 },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
  }
};

static void
init_handler(void)
{
  command_add_array(command_table, IO_ARRAY_LENGTH(command_table));
}

static void
exit_handler(void)
{
  command_del_array(command_table, IO_ARRAY_LENGTH(command_table));
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
