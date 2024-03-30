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
#include "modules.h"
#include "packet.h"
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
check_clean_nick(struct Client *source_p, const char *nick)
{
  assert(IsServer(source_p) || (IsClient(source_p) && !MyConnect(source_p)));

  /*
   * The old code did some wacky stuff here, if the nick is invalid, kill it
   * and don't bother messing at all
   */
  if (valid_nickname(nick, false))
    return true;

  ++ServerStats.is_kill;
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Bad/long Nick: %s From: %s(via %s)",
                       nick, IsServer(source_p) ? source_p->name : source_p->servptr->name,
                       source_p->from->name);
  sendto_one(source_p, ":%s KILL %s :%s (Bad Nickname)",
             me.id, nick, me.name);

  /* Bad nick change */
  if (!IsServer(source_p))
  {
    sendto_server(source_p, 0, 0, ":%s KILL %s :%s (Bad Nickname)",
                  me.id, source_p->id, me.name);
    AddFlag(source_p, FLAGS_KILLED);
    exit_client(source_p, "Bad Nickname");
  }

  return false;
}

static bool
check_clean_uid(struct Client *source_p, const char *nick, const char *uid)
{
  assert(IsServer(source_p));

  if (valid_uid(uid) && strncmp(uid, source_p->id, IRC_MAXSID) == 0)
    return true;

  ++ServerStats.is_kill;
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "Bad UID: %s Nickname: %s From: %s(via %s)",
                       uid, nick, source_p->name, source_p->from->name);
  sendto_one(source_p, ":%s KILL %s :%s (Bad UID)",
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
check_clean_user(struct Client *source_p, const char *nick, const char *user)
{
  assert(IsServer(source_p));

  if (valid_username(user, false))
    return true;

  ++ServerStats.is_kill;
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "Bad/Long Username: %s Nickname: %s From: %s(via %s)",
                       user, nick, source_p->name, source_p->from->name);
  sendto_one(source_p, ":%s KILL %s :%s (Bad Username)",
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
check_clean_host(struct Client *source_p, const char *nick, const char *host)
{
  assert(IsServer(source_p));

  if (valid_hostname(host))
    return true;

  ++ServerStats.is_kill;
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "Bad/Long Hostname: %s Nickname: %s From: %s(via %s)",
                       host, nick, source_p->name, source_p->from->name);
  sendto_one(source_p, ":%s KILL %s :%s (Bad Hostname)",
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
set_initial_nick(struct Client *source_p, const char *nick)
{
  bool samenick = irccmp(source_p->name, nick) == 0;
  if (samenick == false)
    source_p->tsinfo = event_base->time.sec_real;

  source_p->connection->registration &= ~REG_NEED_NICK;

  if (source_p->name[0])
    hash_del_client(source_p);

  strlcpy(source_p->name, nick, sizeof(source_p->name));
  hash_add_client(source_p);

  /* fd_desc is long enough */
  fd_note(source_p->connection->fd, "Nick: %s", source_p->name);

  if (source_p->connection->registration == 0)
    register_local_user(source_p);
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
change_local_nick(struct Client *source_p, const char *nick)
{
  assert(source_p->name[0] && !EmptyString(nick));
  assert(MyClient(source_p));

  if ((source_p->connection->nick.last_attempt + ConfigGeneral.max_nick_time) < event_base->time.sec_monotonic)
    source_p->connection->nick.count = 0;

  if (ConfigGeneral.anti_nick_flood && !HasUMode(source_p, UMODE_OPER) &&
      (source_p->connection->nick.count > ConfigGeneral.max_nick_changes))
  {
    sendto_one_numeric(source_p, &me, ERR_NICKTOOFAST, nick,
                       ConfigGeneral.max_nick_time);
    return;
  }

  source_p->connection->nick.last_attempt = event_base->time.sec_monotonic;
  source_p->connection->nick.count++;

  bool samenick = irccmp(source_p->name, nick) == 0;
  if (samenick == false)
  {
    source_p->tsinfo = event_base->time.sec_real;
    clear_ban_cache_list(&source_p->channel);
    monitor_signoff(source_p);

    if (HasUMode(source_p, UMODE_REGISTERED))
    {
      const unsigned int oldmodes = source_p->umodes;
      DelUMode(source_p, UMODE_REGISTERED);

      send_umode(source_p, oldmodes, true, false);
    }
  }

  /*
   * Client just changing their nick. If they are on a channel, send
   * note of change to all clients on that channel. Propagate notice
   * to other servers.
   */
  sendto_realops_flags(UMODE_NCHANGE, L_ALL, SEND_NOTICE,
                       "Nick change: From %s to %s [%s@%s]",
                       source_p->name, nick, source_p->username, source_p->host);
  sendto_common_channels_local(source_p, true, 0, 0, ":%s!%s@%s NICK :%s",
                               source_p->name, source_p->username,
                               source_p->host, nick);
  whowas_add_history(source_p, true);

  sendto_server(source_p, 0, 0, ":%s NICK %s :%ju",
                source_p->id, nick, source_p->tsinfo);

  hash_del_client(source_p);
  strlcpy(source_p->name, nick, sizeof(source_p->name));
  hash_add_client(source_p);

  if (samenick == false)
    monitor_signon(source_p);

  /* fd_desc is long enough */
  fd_note(source_p->connection->fd, "Nick: %s", source_p->name);
}

/*!
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
change_remote_nick(struct Client *source_p, char *parv[])
{
  assert(!EmptyString(parv[1]));
  assert(IsClient(source_p));
  assert(source_p->name[0]);

  /* Client changing their nick */
  bool samenick = irccmp(source_p->name, parv[1]) == 0;
  if (samenick == false)
  {
    DelUMode(source_p, UMODE_REGISTERED);
    monitor_signoff(source_p);

    source_p->tsinfo = strtoumax(parv[2], NULL, 10);
    assert(source_p->tsinfo);
  }

  sendto_realops_flags(UMODE_NCHANGE, L_ALL, SEND_NOTICE,
                       "Nick change: From %s to %s [%s@%s]",
                       source_p->name, parv[1], source_p->username, source_p->host);
  sendto_common_channels_local(source_p, true, 0, 0, ":%s!%s@%s NICK :%s",
                               source_p->name, source_p->username,
                               source_p->host, parv[1]);

  whowas_add_history(source_p, true);
  sendto_server(source_p, 0, 0, ":%s NICK %s :%ju",
                source_p->id, parv[1], source_p->tsinfo);

  /* Set the new nick name */
  hash_del_client(source_p);
  strlcpy(source_p->name, parv[1], sizeof(source_p->name));
  hash_add_client(source_p);

  if (samenick == false)
    monitor_signon(source_p);
}

/*!
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
uid_from_server(struct Client *source_p, int parc, char *parv[])
{
  struct Client *client_p = client_make(source_p->from);
  client_p->servptr = source_p;
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
    memcpy(&client_p->ip, res->ai_addr, res->ai_addrlen);
    client_p->ip.ss_len = res->ai_addrlen;

    struct ip_entry *ipcache = ipcache_record_find_or_add(&client_p->ip);
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

  register_remote_user(client_p);
}

/*!
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
perform_uid_introduction_collides(struct Client *source_p, struct Client *target_p,
                                  int parc, char *parv[])
{
  const char *uid = parv[9];
  uintmax_t newts = strtoumax(parv[3], NULL, 10);

  assert(IsServer(source_p));
  assert(IsClient(target_p));

  /* Server introducing new nick */

  /* If their TS's are the same, kill both */
  if (newts == target_p->tsinfo)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Nick collision on %s(%s <- %s)(both killed)",
                         target_p->name, target_p->from->name,
                         source_p->from->name);

    sendto_one(source_p, ":%s KILL %s :%s (Nick collision (new))",
               me.id, uid, me.name);
    sendto_server(NULL, 0, 0, ":%s KILL %s :%s (Nick collision (new))",
                  me.id, target_p->id, me.name);

    ++ServerStats.is_kill;
    sendto_one_numeric(target_p, &me, ERR_NICKCOLLISION, target_p->name);

    AddFlag(target_p, FLAGS_KILLED);
    exit_client(target_p, "Nick collision (new)");
    return false;
  }

  /* The timestamps are different */
  bool sameuser = irccmp(target_p->username, parv[5]) == 0 &&
                  irccmp(target_p->sockhost, parv[8]) == 0;

  /*
   * If the users are the same (loaded a client on a different server)
   * and the new users ts is older, or the users are different and the
   * new users ts is newer, ignore the new client and let it do the kill
   */
  if ((sameuser && newts < target_p->tsinfo) || (sameuser == false && newts > target_p->tsinfo))
  {
    sendto_one(source_p, ":%s KILL %s :%s (Nick collision (new))",
               me.id, uid, me.name);
    return false;
  }

  if (sameuser)
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Nick collision on %s(%s <- %s)(older killed)",
                         target_p->name, target_p->from->name,
                         source_p->from->name);
  else
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Nick collision on %s(%s <- %s)(newer killed)",
                         target_p->name, target_p->from->name,
                         source_p->from->name);

  ++ServerStats.is_kill;
  sendto_one_numeric(target_p, &me, ERR_NICKCOLLISION, target_p->name);

  sendto_server(NULL, 0, 0, ":%s KILL %s :%s (Nick collision (new))",
                me.id, target_p->id, me.name);

  AddFlag(target_p, FLAGS_KILLED);
  exit_client(target_p, "Nick collision");

  return true;
}

/*!
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
perform_nick_change_collides(struct Client *source_p, struct Client *target_p,
                             int parc, char *parv[])
{
  uintmax_t newts = strtoumax(parv[2], NULL, 10);

  assert(IsClient(source_p));
  assert(IsClient(target_p));
  assert(newts);

  /* It's a client changing nick and causing a collide */
  if (newts == target_p->tsinfo)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
               "Nick change collision from %s to %s(%s <- %s)(both killed)",
               source_p->name, target_p->name, target_p->from->name,
               source_p->from->name);

    sendto_one_numeric(target_p, &me, ERR_NICKCOLLISION, target_p->name);
    ServerStats.is_kill += 2;

    sendto_server(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                  me.id, source_p->id, me.name);
    sendto_server(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                  me.id, target_p->id, me.name);

    AddFlag(source_p, FLAGS_KILLED);
    AddFlag(target_p, FLAGS_KILLED);
    exit_client(source_p, "Nick collision (old)");
    exit_client(target_p, "Nick collision (new)");
    return false;
  }

  /* The timestamps are different */
  bool sameuser = irccmp(target_p->username, source_p->username) == 0 &&
                  irccmp(target_p->sockhost, source_p->sockhost) == 0;

  if ((sameuser && newts < target_p->tsinfo) || (sameuser == false && newts > target_p->tsinfo))
  {
    if (sameuser)
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
           "Nick change collision from %s to %s(%s <- %s)(older killed)",
           source_p->name, target_p->name, target_p->from->name,
           source_p->from->name);
    else
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
           "Nick change collision from %s to %s(%s <- %s)(newer killed)",
           source_p->name, target_p->name, target_p->from->name,
           source_p->from->name);

    ++ServerStats.is_kill;

    sendto_server(NULL, 0, 0, ":%s KILL %s :%s (Nick change collision)",
                  me.id, source_p->id, me.name);
    AddFlag(source_p, FLAGS_KILLED);

    if (sameuser)
      exit_client(source_p, "Nick collision (old)");
    else
      exit_client(source_p, "Nick collision (new)");
    return false;
  }

  if (sameuser)
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Nick collision on %s(%s <- %s)(older killed)",
                         target_p->name, target_p->from->name,
                         source_p->from->name);
  else
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Nick collision on %s(%s <- %s)(newer killed)",
                         target_p->name, target_p->from->name,
                         source_p->from->name);

  sendto_server(NULL, 0, 0, ":%s KILL %s :%s (Nick collision)",
                me.id, target_p->id, me.name);

  ++ServerStats.is_kill;
  sendto_one_numeric(target_p, &me, ERR_NICKCOLLISION, target_p->name);

  AddFlag(target_p, FLAGS_KILLED);
  exit_client(target_p, "Nick collision");

  return true;
}

/*! \brief NICK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 */
static void
mr_nick(struct Client *source_p, int parc, char *parv[])
{
  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  /* Copy the nick and terminate it */
  char nick[NICKLEN + 1];
  strlcpy(nick, parv[1], IRCD_MIN(sizeof(nick), ConfigServerInfo.max_nick_length + 1));

  /* Check the nickname is ok */
  if (valid_nickname(nick, true) == false)
  {
    sendto_one_numeric(source_p, &me, ERR_ERRONEUSNICKNAME, parv[1], "Erroneous Nickname");
    return;
  }

  /* Check if the nick is resv'd */
  const struct ResvItem *resv = resv_find(nick, match);
  if (resv)
  {
    sendto_one_numeric(source_p, &me, ERR_ERRONEUSNICKNAME, nick, resv->reason);
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Forbidding reserved nick %s from user %s",
                         nick, client_get_name(source_p, HIDE_IP));
    return;
  }

  struct Client *target_p = hash_find_client(nick);
  if (target_p == NULL || target_p == source_p)
    set_initial_nick(source_p, nick);
  else
    sendto_one_numeric(source_p, &me, ERR_NICKNAMEINUSE, target_p->name);
}

/*! \brief NICK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 */
static void
m_nick(struct Client *source_p, int parc, char *parv[])
{
  const struct ResvItem *resv = NULL;

  assert(MyClient(source_p));

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NONICKNAMEGIVEN);
    return;
  }

  /* Terminate nick to NICKLEN */
  char nick[NICKLEN + 1];
  strlcpy(nick, parv[1], IRCD_MIN(sizeof(nick), ConfigServerInfo.max_nick_length + 1));

  /* Check the nickname is ok */
  if (valid_nickname(nick, true) == false)
  {
    sendto_one_numeric(source_p, &me, ERR_ERRONEUSNICKNAME, nick, "Erroneous Nickname");
    return;
  }

  if (!HasFlag(source_p, FLAGS_EXEMPTRESV) &&
      !(HasUMode(source_p, UMODE_OPER) && HasOFlag(source_p, OPER_FLAG_NICK_RESV)) &&
      (resv = resv_find(nick, match)))
  {
    sendto_one_numeric(source_p, &me, ERR_ERRONEUSNICKNAME, nick, resv->reason);
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Forbidding reserved nick %s from user %s",
                         nick, client_get_name(source_p, HIDE_IP));
    return;
  }

  dlink_node *node;
  DLINK_FOREACH(node, source_p->channel.head)
  {
    struct ChannelMember *member = node->data;

    if (member_highest_rank(member) < CHACCESS_VOICE)
    {
      if (HasCMode(member->channel, MODE_NONICKCHANGE))
      {
        sendto_one_numeric(source_p, &me, ERR_NONICKCHANGE, member->channel->name);
        return;
      }

      if (is_banned(member->channel, source_p, &extban_nick))
      {
        sendto_one_numeric(source_p, &me, ERR_BANNICKCHANGE, member->channel->name);
        return;
      }
    }
  }

  struct Client *target_p = hash_find_client(nick);
  if (target_p == NULL)
    change_local_nick(source_p, nick);
  else if (target_p == source_p)
  {
    /*
     * If (target_p == source_p) the client is changing nicks between
     * equivalent nicknames ie: nick -> nIcK
     */

    /* Check the nick isn't exactly the same */
    if (strcmp(target_p->name, nick))
      change_local_nick(source_p, nick);
  }
  else if (IsUnknown(target_p))
  {
    /*
     * If the client that has the nick isn't registered yet (NICK but no
     * USER) then drop the unregistered client
     */
    exit_client(target_p, "Overridden by other sign on");
    change_local_nick(source_p, nick);
  }
  else
    sendto_one_numeric(source_p, &me, ERR_NICKNAMEINUSE, target_p->name);
}

/*! \brief NICK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_nick(struct Client *source_p, int parc, char *parv[])
{
  if (!IsClient(source_p))
    return;  /* Servers and unknown clients can't change nicks.. */

  if (check_clean_nick(source_p, parv[1]) == false)
    return;

  /* If the nick doesn't exist, allow it and process like normal */
  struct Client *target_p = hash_find_client(parv[1]);
  if (target_p == NULL)
    change_remote_nick(source_p, parv);
  else if (IsUnknown(target_p))
  {
    /* We're not living in the past anymore, an unknown client is local only. */
    exit_client(target_p, "Overridden by other sign on");
    change_remote_nick(source_p, parv);
  }
  else if (target_p == source_p)
  {
    if (strcmp(target_p->name, parv[1]))
      change_remote_nick(source_p, parv);
  }
  else if (perform_nick_change_collides(source_p, target_p, parc, parv))
    change_remote_nick(source_p, parv);
}

/*! \brief UID command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_uid(struct Client *source_p, int parc, char *parv[])
{
  if (check_clean_nick(source_p, parv[1]) == false ||
      check_clean_user(source_p, parv[1], parv[5]) == false ||
      check_clean_host(source_p, parv[1], parv[6]) == false ||
      check_clean_host(source_p, parv[1], parv[7]) == false ||
      check_clean_uid(source_p, parv[1], parv[9]) == false)
    return;

  /*
   * If there is an ID collision, kill our client, and kill theirs.
   * This may generate 401's, but it ensures that both clients always
   * go, even if the other server refuses to do the right thing.
   */
  struct Client *target_p = hash_find_id(parv[9]);
  if (target_p)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "ID collision on %s(%s <- %s)(both killed)",
                         target_p->name, target_p->from->name,
                         source_p->from->name);

    sendto_server(NULL, 0, 0, ":%s KILL %s :%s (ID collision)",
                  me.id, target_p->id, me.name);

    ++ServerStats.is_kill;
    AddFlag(target_p, FLAGS_KILLED);
    exit_client(target_p, "ID Collision");
    return;
  }

  target_p = hash_find_client(parv[1]);
  if (target_p == NULL)
    uid_from_server(source_p, parc, parv);
  else if (IsUnknown(target_p))
  {
    exit_client(target_p, "Overridden by other sign on");
    uid_from_server(source_p, parc, parv);
  }
  else if (perform_uid_introduction_collides(source_p, target_p, parc, parv))
    uid_from_server(source_p, parc, parv);
}

static struct Command nick_msgtab =
{
  .name = "NICK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = mr_nick },
  .handlers[CLIENT_HANDLER] = { .handler = m_nick, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = ms_nick, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_nick }
};

static struct Command uid_msgtab =
{
  .name = "UID",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_uid, .args_min = 12 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  command_add(&uid_msgtab);
  command_add(&nick_msgtab);
}

static void
module_exit(void)
{
  command_del(&uid_msgtab);
  command_del(&nick_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
