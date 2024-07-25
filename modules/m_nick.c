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

/*! \file m_nick.c
 * \brief Includes required functions for processing the NICK command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "list.h"
#include "hash.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "conf_resv.h"
#include "user.h"
#include "whowas.h"
#include "send.h"
#include "channel.h"
#include "channel_mode.h"
#include "parse.h"
#include "module.h"
#include "monitor.h"
#include "misc.h"
#include "id.h"
#include "ipcache.h"
#include "extban.h"


/* check_clean_nick()
 *
 * input        - pointer to source
 *              -
 *              - nickname
 *              - truncated nickname
 *              - origin of client
 *              - pointer to server nick is coming from
 * output       - none
 * side effects - if nickname is erroneous, or a different length to
 *                truncated nickname, return 1
 */
static bool
check_clean_nick(struct Client *source, const char *nick)
{
  assert(IsServer(source) || (IsClient(source) && !MyConnect(source)));

  /*
   * The old code did some wacky stuff here, if the nick is invalid, kill it
   * and don't bother messing at all
   */
  if (valid_nickname(nick, false))
    return true;

  ++ServerStats.is_kill;
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Bad/long Nick: %s From: %s(via %s)",
                 nick, IsServer(source) ? source->name : source->servptr->name, source->from->name);
  sendto_one(source, ":%s KILL %s :%s (Bad Nickname)",
             me.id, nick, me.name);

  /* Bad nick change */
  if (!IsServer(source))
  {
    sendto_servers(source, 0, 0, ":%s KILL %s :%s (Bad Nickname)",
                   me.id, source->id, me.name);
    AddFlag(source, FLAGS_KILLED);
    client_exit(source, "Bad Nickname");
  }

  return false;
}

static bool
check_clean_uid(struct Client *source, const char *nick, const char *uid)
{
  assert(IsServer(source));

  if (valid_uid(uid) && strncmp(uid, source->id, IRC_MAXSID) == 0)
    return true;

  ++ServerStats.is_kill;
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Bad UID: %s Nickname: %s From: %s(via %s)",
                 uid, nick, source->name, source->from->name);
  sendto_one(source, ":%s KILL %s :%s (Bad UID)",
             me.id, uid, me.name);
  return false;
}

/* check_clean_user()
 *
 * input        - pointer to client sending data
 *              - nickname
 *              - username to check
 *              - origin of NICK
 * output       - none
 * side effects - if username is erroneous, return 1
 */
static bool
check_clean_user(struct Client *source, const char *nick, const char *user)
{
  assert(IsServer(source));

  if (valid_username(user, false))
    return true;

  ++ServerStats.is_kill;
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Bad/Long Username: %s Nickname: %s From: %s(via %s)",
                 user, nick, source->name, source->from->name);
  sendto_one(source, ":%s KILL %s :%s (Bad Username)",
             me.id, nick, me.name);
  return false;
}

/* check_clean_host()
 *
 * input        - pointer to client sending us data
 *              - nickname
 *              - hostname to check
 *              - source name
 * output       - none
 * side effects - if hostname is erroneous, return 1
 */
static bool
check_clean_host(struct Client *source, const char *nick, const char *host)
{
  assert(IsServer(source));

  if (valid_hostname(host))
    return true;

  ++ServerStats.is_kill;
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Bad/Long Hostname: %s Nickname: %s From: %s(via %s)",
                 host, nick, source->name, source->from->name);
  sendto_one(source, ":%s KILL %s :%s (Bad Hostname)",
             me.id, nick, me.name);
  return false;
}

/* set_initial_nick()
 *
 * inputs
 * output
 * side effects -
 *
 * This function is only called to set up an initially registering
 * client.
 */
static void
set_initial_nick(struct Client *source, const char *nick)
{
  bool samenick = irccmp(source->name, nick) == 0;
  if (samenick == false)
    source->tsinfo = io_time_get(IO_TIME_REALTIME_SEC);

  source->connection->registration &= ~REG_NEED_NICK;

  if (source->name[0])
    hash_del_client(source);

  strlcpy(source->name, nick, sizeof(source->name));
  hash_add_client(source);

  /* fd_desc is long enough */
  fd_note(source->connection->fd, "Nick: %s", source->name);

  if (source->connection->registration == 0)
    user_register_local(source);
}

/* change_local_nick()
 *
 * inputs       - pointer to server
 *              - pointer to client
 *              - nick
 * output       -
 * side effects - changes nick of a LOCAL user
 */
static void
change_local_nick(struct Client *source, const char *nick)
{
  assert(source->name[0] && !EmptyString(nick));
  assert(MyClient(source));

  if ((source->connection->nick.last_attempt + ConfigGeneral.max_nick_time) < io_time_get(IO_TIME_MONOTONIC_SEC))
    source->connection->nick.count = 0;

  if (ConfigGeneral.anti_nick_flood && !HasUMode(source, UMODE_OPER) &&
      (source->connection->nick.count > ConfigGeneral.max_nick_changes))
  {
    sendto_one_numeric(source, &me, ERR_NICKTOOFAST,
                       nick, ConfigGeneral.max_nick_time);
    return;
  }

  source->connection->nick.last_attempt = io_time_get(IO_TIME_MONOTONIC_SEC);
  source->connection->nick.count++;

  bool samenick = irccmp(source->name, nick) == 0;
  if (samenick == false)
  {
    source->tsinfo = io_time_get(IO_TIME_REALTIME_SEC);
    clear_ban_cache_list(&source->channel);
    monitor_signoff(source);

    if (HasUMode(source, UMODE_REGISTERED))
    {
      const unsigned int oldmodes = source->umodes;
      DelUMode(source, UMODE_REGISTERED);

      send_umode(source, oldmodes, true, false);
    }
  }

  /*
   * Client just changing their nick. If they are on a channel, send
   * note of change to all clients on that channel. Propagate notice
   * to other servers.
   */
  sendto_clients(UMODE_NCHANGE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Nick change: From %s to %s [%s@%s]",
                 source->name, nick, source->username, source->host);
  sendto_common_channels_local(source, true, 0, 0, ":%s!%s@%s NICK :%s",
                               source->name, source->username, source->host, nick);
  whowas_add_history(source, true);

  sendto_servers(source, 0, 0, ":%s NICK %s :%ju",
                 source->id, nick, source->tsinfo);

  hash_del_client(source);
  strlcpy(source->name, nick, sizeof(source->name));
  hash_add_client(source);

  if (samenick == false)
    monitor_signon(source);

  /* fd_desc is long enough */
  fd_note(source->connection->fd, "Nick: %s", source->name);
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
change_remote_nick(struct Client *source, char *parv[])
{
  assert(!EmptyString(parv[1]));
  assert(IsClient(source));
  assert(source->name[0]);

  /* Client changing their nick */
  bool samenick = irccmp(source->name, parv[1]) == 0;
  if (samenick == false)
  {
    DelUMode(source, UMODE_REGISTERED);
    monitor_signoff(source);

    source->tsinfo = strtoumax(parv[2], NULL, 10);
    assert(source->tsinfo);
  }

  sendto_clients(UMODE_NCHANGE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Nick change: From %s to %s [%s@%s]",
                 source->name, parv[1], source->username, source->host);
  sendto_common_channels_local(source, true, 0, 0, ":%s!%s@%s NICK :%s",
                               source->name, source->username, source->host, parv[1]);

  whowas_add_history(source, true);
  sendto_servers(source, 0, 0, ":%s NICK %s :%ju",
                 source->id, parv[1], source->tsinfo);

  /* Set the new nick name */
  hash_del_client(source);
  strlcpy(source->name, parv[1], sizeof(source->name));
  hash_add_client(source);

  if (samenick == false)
    monitor_signon(source);
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
  struct Client *client_p = client_make(source->from);
  client_p->servptr = source;
  client_p->hopcount = atoi(parv[2]);
  client_p->tsinfo = strtoumax(parv[3], NULL, 10);

  strlcpy(client_p->name, parv[1], sizeof(client_p->name));
  strlcpy(client_p->username, parv[5], sizeof(client_p->username));
  strlcpy(client_p->host, parv[6], sizeof(client_p->host));
  strlcpy(client_p->realhost, parv[7], sizeof(client_p->realhost));
  strlcpy(client_p->sockhost, parv[8], sizeof(client_p->sockhost));
  strlcpy(client_p->id, parv[9], sizeof(client_p->id));
  strlcpy(client_p->account, parv[10], sizeof(client_p->account));
  strlcpy(client_p->info, parv[11], sizeof(client_p->info));

  struct addrinfo hints, *res = NULL;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(client_p->sockhost, NULL, &hints, &res) == 0)
  {
    memcpy(&client_p->addr, res->ai_addr, res->ai_addrlen);
    client_p->addr.ss_len = res->ai_addrlen;

    struct ip_entry *ipcache = ipcache_record_find_or_add(&client_p->addr);
    ++ipcache->count_remote;
    AddFlag(client_p, FLAGS_IPHASH);
  }

  if (res)
    freeaddrinfo(res);

  hash_add_client(client_p);
  hash_add_id(client_p);

  /* Parse user modes */
  for (const char *m = &parv[4][1]; *m; ++m)
  {
    const struct user_modes *tab = umode_map[(unsigned char)*m];
    if (tab == NULL)
      continue;

    if ((tab->flag & UMODE_INVISIBLE) && !HasUMode(client_p, UMODE_INVISIBLE))
      ++Count.invisi;
    else if ((tab->flag & UMODE_OPER) && !HasUMode(client_p, UMODE_OPER))
      ++Count.oper;

    AddUMode(client_p, tab->flag);
  }

  user_register_remote(client_p);
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

  assert(IsServer(source));
  assert(IsClient(target));

  /* Server introducing new nick */

  /* If their TS's are the same, kill both */
  if (newts == target->tsinfo)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(both killed)",
                   target->name, target->from->name, source->from->name);

    sendto_one(source, ":%s KILL %s :%s (Nick collision (new))",
               me.id, uid, me.name);
    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick collision (new))",
                   me.id, target->id, me.name);

    ++ServerStats.is_kill;
    sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

    AddFlag(target, FLAGS_KILLED);
    client_exit(target, "Nick collision (new)");
    return false;
  }

  /* The timestamps are different */
  bool sameuser = irccmp(target->username, parv[5]) == 0 &&
                  irccmp(target->sockhost, parv[8]) == 0;

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
                   target->name, target->from->name, source->from->name);
  else
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(newer killed)",
                   target->name, target->from->name, source->from->name);

  ++ServerStats.is_kill;
  sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

  sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick collision (new))",
                 me.id, target->id, me.name);

  AddFlag(target, FLAGS_KILLED);
  client_exit(target, "Nick collision");

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

  assert(IsClient(source));
  assert(IsClient(target));
  assert(newts);

  /* It's a client changing nick and causing a collide */
  if (newts == target->tsinfo)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick change collision from %s to %s(%s <- %s)(both killed)",
                   source->name, target->name, target->from->name,
                   source->from->name);

    sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);
    ServerStats.is_kill += 2;

    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                   me.id, source->id, me.name);
    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                   me.id, target->id, me.name);

    AddFlag(source, FLAGS_KILLED);
    AddFlag(target, FLAGS_KILLED);
    client_exit(source, "Nick collision (old)");
    client_exit(target, "Nick collision (new)");
    return false;
  }

  /* The timestamps are different */
  bool sameuser = irccmp(target->username, source->username) == 0 &&
                  irccmp(target->sockhost, source->sockhost) == 0;

  if ((sameuser && newts < target->tsinfo) || (sameuser == false && newts > target->tsinfo))
  {
    if (sameuser)
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Nick change collision from %s to %s(%s <- %s)(older killed)",
                     source->name, target->name, target->from->name,
                     source->from->name);
    else
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Nick change collision from %s to %s(%s <- %s)(newer killed)",
                     source->name, target->name, target->from->name,
                     source->from->name);

    ++ServerStats.is_kill;

    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                   me.id, source->id, me.name);
    AddFlag(source, FLAGS_KILLED);

    if (sameuser)
      client_exit(source, "Nick collision (old)");
    else
      client_exit(source, "Nick collision (new)");
    return false;
  }

  if (sameuser)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(older killed)",
                   target->name, target->from->name, source->from->name);
  else
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Nick collision on %s(%s <- %s)(newer killed)",
                   target->name, target->from->name, source->from->name);

  sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (Nick collision)",
                 me.id, target->id, me.name);

  ++ServerStats.is_kill;
  sendto_one_numeric(target, &me, ERR_NICKCOLLISION, target->name);

  AddFlag(target, FLAGS_KILLED);
  client_exit(target, "Nick collision");

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
  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  /* Copy the nick and terminate it */
  char nick[NICKLEN + 1];
  strlcpy(nick, parv[1], IO_MIN(sizeof(nick), ConfigServerInfo.max_nick_length + 1));

  /* Check the nickname is ok */
  if (valid_nickname(nick, true) == false)
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, parv[1], "Erroneous Nickname");
    return;
  }

  /* Check if the nick is resv'd */
  const struct ResvItem *resv = resv_find(nick, match);
  if (resv)
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, nick, resv->reason);
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Forbidding reserved nick %s from user %s",
                   nick, client_get_name(source, HIDE_IP));
    return;
  }

  struct Client *target = hash_find_client(nick);
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
  const struct ResvItem *resv = NULL;

  assert(MyClient(source));

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  /* Terminate nick to NICKLEN */
  char nick[NICKLEN + 1];
  strlcpy(nick, parv[1], IO_MIN(sizeof(nick), ConfigServerInfo.max_nick_length + 1));

  /* Check the nickname is ok */
  if (valid_nickname(nick, true) == false)
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, nick, "Erroneous Nickname");
    return;
  }

  if (!HasFlag(source, FLAGS_EXEMPTRESV) &&
      !(HasUMode(source, UMODE_OPER) && HasOFlag(source, OPER_FLAG_NICK_RESV)) &&
      (resv = resv_find(nick, match)))
  {
    sendto_one_numeric(source, &me, ERR_ERRONEUSNICKNAME, nick, resv->reason);
    sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Forbidding reserved nick %s from user %s",
                   nick, client_get_name(source, HIDE_IP));
    return;
  }

  list_node_t *node;
  LIST_FOREACH(node, source->channel.head)
  {
    struct ChannelMember *member = node->data;

    if (member_highest_rank(member) < CHACCESS_VOICE)
    {
      if (HasCMode(member->channel, MODE_NONICKCHANGE))
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

  struct Client *target = hash_find_client(nick);
  if (target == NULL)
    change_local_nick(source, nick);
  else if (target == source)
  {
    /*
     * If (target == source) the client is changing nicks between
     * equivalent nicknames ie: nick -> nIcK
     */

    /* Check the nick isn't exactly the same */
    if (strcmp(target->name, nick))
      change_local_nick(source, nick);
  }
  else if (IsUnknown(target))
  {
    /*
     * If the client that has the nick isn't registered yet (NICK but no
     * USER) then drop the unregistered client
     */
    client_exit(target, "Overridden by other sign on");
    change_local_nick(source, nick);
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
  if (!IsClient(source))
    return;  /* Servers and unknown clients can't change nicks.. */

  if (check_clean_nick(source, parv[1]) == false)
    return;

  /* If the nick doesn't exist, allow it and process like normal */
  struct Client *target = hash_find_client(parv[1]);
  if (target == NULL)
    change_remote_nick(source, parv);
  else if (IsUnknown(target))
  {
    /* We're not living in the past anymore, an unknown client is local only. */
    client_exit(target, "Overridden by other sign on");
    change_remote_nick(source, parv);
  }
  else if (target == source)
  {
    if (strcmp(target->name, parv[1]))
      change_remote_nick(source, parv);
  }
  else if (perform_nick_change_collides(source, target, parc, parv))
    change_remote_nick(source, parv);
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
  struct Client *target = hash_find_id(parv[9]);
  if (target)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "ID collision on %s(%s <- %s)(both killed)",
                   target->name, target->from->name, source->from->name);

    sendto_servers(NULL, 0, 0, ":%s KILL %s :%s (ID collision)",
                   me.id, target->id, me.name);

    ++ServerStats.is_kill;
    AddFlag(target, FLAGS_KILLED);
    client_exit(target, "ID Collision");
    return;
  }

  target = hash_find_client(parv[1]);
  if (target == NULL)
    uid_from_server(source, parc, parv);
  else if (IsUnknown(target))
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
    .handlers[UNREGISTERED_HANDLER] = { .handler = mr_nick },
    .handlers[CLIENT_HANDLER] = { .handler = m_nick, .end_grace_period = true },
    .handlers[SERVER_HANDLER] = { .handler = ms_nick, .args_min = 3 },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_nick }
  },
  [1] = {
    .name = "UID",
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
    .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
    .handlers[SERVER_HANDLER] = { .handler = ms_uid, .args_min = 12 },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
