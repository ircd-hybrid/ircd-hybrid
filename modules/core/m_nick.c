/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_nick.c: Sets a users nick.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "s_user.h"
#include "whowas.h"
#include "s_serv.h"
#include "send.h"
#include "channel.h"
#include "channel_mode.h"
#include "log.h"
#include "resv.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"
#include "watch.h"
#include "s_misc.h"


static void nick_from_server(struct Client *, struct Client *, int, char **,
                             time_t, const char *, char *, char *);
static void uid_from_server(struct Client *, struct Client *, int, char **,
                               time_t, const char *, char *, char *);
static int check_clean_nick(struct Client *client_p, struct Client *source_p, 
                            char *nick, struct Client *server_p);
static int check_clean_user(struct Client *client_p, char *nick, char *user,
			    struct Client *server_p);
static int check_clean_host(struct Client *client_p, char *nick, char *host,
			    struct Client *server_p);

static int clean_user_name(const char *);
static void perform_nick_collides(struct Client *, struct Client *, struct Client *,
				  int, char **, time_t, const char *, char *, char *, char *);


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
  /* Client setting NICK the first time */

  /* This had to be copied here to avoid problems.. */
  source_p->tsinfo = CurrentTime;
  source_p->localClient->registration &= ~REG_NEED_NICK;

  if (source_p->name[0])
    hash_del_client(source_p);

  strlcpy(source_p->name, nick, sizeof(source_p->name));
  hash_add_client(source_p);

  /* fd_desc is long enough */
  fd_note(&source_p->localClient->fd, "Nick: %s", nick);

  if (!source_p->localClient->registration)
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
  assert(MyConnect(source_p));

  /*
   * Client just changing his/her nick. If he/she is
   * on a channel, send note of change to all clients
   * on that channel. Propagate notice to other servers.
   */
  if ((source_p->localClient->last_nick_change +
       ConfigFileEntry.max_nick_time) < CurrentTime)
    source_p->localClient->number_of_nick_changes = 0;
  source_p->localClient->last_nick_change = CurrentTime;
  source_p->localClient->number_of_nick_changes++;

  if ((ConfigFileEntry.anti_nick_flood &&
      (source_p->localClient->number_of_nick_changes
       <= ConfigFileEntry.max_nick_changes)) ||
     !ConfigFileEntry.anti_nick_flood ||
     (HasUMode(source_p, UMODE_OPER) && ConfigFileEntry.no_oper_flood))
  {
    int samenick = !irccmp(source_p->name, nick);

    if (!samenick)
    {
      source_p->tsinfo = CurrentTime;
      clear_ban_cache_client(source_p);
      watch_check_hash(source_p, RPL_LOGOFF);

      if (HasUMode(source_p, UMODE_REGISTERED))
      {
        unsigned int oldmodes = source_p->umodes;
        char modebuf[IRCD_BUFSIZE] = { '\0' };

        DelUMode(source_p, UMODE_REGISTERED);
        send_umode(source_p, source_p, oldmodes, 0xffffffff, modebuf);
      }
    }

    /* XXX - the format of this notice should eventually be changed
     * to either %s[%s@%s], or even better would be get_client_name() -bill
     */
    sendto_realops_flags(UMODE_NCHANGE, L_ALL, SEND_NOTICE,
                         "Nick change: From %s to %s [%s@%s]",
                         source_p->name, nick, source_p->username, source_p->host);
    sendto_common_channels_local(source_p, 1, 0, ":%s!%s@%s NICK :%s",
                                 source_p->name, source_p->username,
                                 source_p->host, nick);
    add_history(source_p, 1);

    sendto_server(source_p, CAP_TS6, NOCAPS,
                  ":%s NICK %s :%lu",
                  ID(source_p), nick, (unsigned long)source_p->tsinfo);
    sendto_server(source_p, NOCAPS, CAP_TS6,
                  ":%s NICK %s :%lu",
                  source_p->name, nick, (unsigned long)source_p->tsinfo);

    hash_del_client(source_p);
    strcpy(source_p->name, nick);
    hash_add_client(source_p);

    if (!samenick)
      watch_check_hash(source_p, RPL_LOGON);

    /* fd_desc is long enough */
    fd_note(&source_p->localClient->fd, "Nick: %s", nick);
  }
  else
    sendto_one(source_p, ERR_NICKTOOFAST,
               me.name, source_p->name, source_p->name,
               nick, ConfigFileEntry.max_nick_time);
}

/*! \brief NICK command handler (called by unregistered,
 *         locally connected clients)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = nickname
 */
static void
mr_nick(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct MaskItem *conf = NULL;
  char nick[NICKLEN + 1];
  char *s = NULL;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, ERR_NONICKNAMEGIVEN, me.name,
               source_p->name[0] ? source_p->name : "*");
    return;
  }

  /* Terminate the nick at the first ~ */
  if ((s = strchr(parv[1], '~')) != NULL)
    *s = '\0';

  /* copy the nick and terminate it */
  strlcpy(nick, parv[1], IRCD_MIN(sizeof(nick), ServerInfo.max_nick_length + 1));

  /* check the nickname is ok */
  if (!valid_nickname(nick, 1))
  {
    sendto_one(source_p, ERR_ERRONEUSNICKNAME, me.name,
               source_p->name[0] ? source_p->name : "*", parv[1]);
    return;
  }

  /* check if the nick is resv'd */
  if ((conf = find_matching_name_conf(CONF_NRESV, nick, NULL, NULL, 0)))
  {
    ++conf->count;
    sendto_one(source_p, ERR_ERRONEUSNICKNAME, me.name,
               source_p->name[0] ? source_p->name : "*", nick);
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Forbidding reserved nick [%s] from user %s",
                         nick, get_client_name(client_p, HIDE_IP));
    return;
  }

  if ((target_p = hash_find_client(nick)) == NULL)
    set_initial_nick(source_p, nick);
  else if (source_p == target_p)
    strlcpy(source_p->name, nick, sizeof(source_p->name));
  else
    sendto_one(source_p, ERR_NICKNAMEINUSE, me.name, "*", nick);
}


/*! \brief NICK command handler (called by already registered,
 *         locally connected clients)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = nickname
 */
static void
m_nick(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char nick[NICKLEN + 1];
  struct Client *target_p = NULL;
  struct MaskItem *conf = NULL;

  assert(source_p == client_p);

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, ERR_NONICKNAMEGIVEN,
               me.name, source_p->name);
    return;
  }

  /* mark end of grace period, to prevent nickflooding */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  /* terminate nick to NICKLEN */
  strlcpy(nick, parv[1], IRCD_MIN(sizeof(nick), ServerInfo.max_nick_length + 1));

  /* check the nickname is ok */
  if (!valid_nickname(nick, 1))
  {
    sendto_one(source_p, ERR_ERRONEUSNICKNAME,
               me.name, source_p->name, nick);
    return;
  }


  if (!IsExemptResv(source_p) &&
      !(HasUMode(source_p, UMODE_OPER) && ConfigFileEntry.oper_pass_resv) &&
      (conf = find_matching_name_conf(CONF_NRESV, nick, NULL, NULL, 0)))
  {
    ++conf->count;
    sendto_one(source_p, ERR_ERRONEUSNICKNAME,
               me.name, source_p->name, nick);
    sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                         "Forbidding reserved nick [%s] from user %s",
                         nick, get_client_name(client_p, HIDE_IP));
    return;
  }

  if ((target_p = hash_find_client(nick)) == NULL)
    change_local_nick(source_p, nick);
  else if (target_p == source_p)
  {
    /*
     * If (target_p == source_p) the client is changing nicks between
     * equivalent nicknames ie: [nick] -> {nick}
     */

    /* check the nick isnt exactly the same */
    if (strcmp(target_p->name, nick))
      change_local_nick(source_p, nick);
  }
  else if (IsUnknown(target_p))
  {
    /*
     * if the client that has the nick isn't registered yet (nick but no
     * user) then drop the unregged client
     */
    exit_client(target_p, &me, "Overridden");
    change_local_nick(source_p, nick);
  }
  else
    sendto_one(source_p, ERR_NICKNAMEINUSE, me.name,
               source_p->name, nick);
}


/*! \brief NICK command handler (called by servers and remotely
 *         connected clients)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 * server -> server nick change
 *  - parv[0] = sender prefix
 *  - parv[1] = nickname
 *  - parv[2] = TS when nick change
 *
 * server introducing new nick (without services support)
 *  - parv[0] = sender prefix
 *  - parv[1] = nickname
 *  - parv[2] = hop count
 *  - parv[3] = TS
 *  - parv[4] = umode
 *  - parv[5] = username
 *  - parv[6] = hostname
 *  - parv[7] = server
 *  - parv[8] = ircname
 *
 * server introducing new nick (with services support)
 *  - parv[0] = sender prefix
 *  - parv[1] = nickname
 *  - parv[2] = hop count
 *  - parv[3] = TS
 *  - parv[4] = umode
 *  - parv[5] = username
 *  - parv[6] = hostname
 *  - parv[7] = server
 *  - parv[8] = services id (timestamp)
 *  - parv[9] = ircname
 */
static void
ms_nick(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p = NULL;
  time_t newts = 0;
  const char *svsid = "0";

  if (parc < 3 || EmptyString(parv[parc - 1]))
    return;

  if (parc >= 9)
  {
    struct Client *server_p = hash_find_server(parv[7]);

    if (server_p == NULL)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Invalid server %s from %s for NICK %s",
			   parv[7], source_p->name, parv[1]);
      sendto_one(client_p, ":%s KILL %s :%s (Server doesn't exist!)",
                 me.name, parv[1], me.name);
      return;
    }

    if (check_clean_nick(client_p, source_p, parv[1], server_p) ||
        check_clean_user(client_p, parv[1], parv[5], server_p) ||
	check_clean_host(client_p, parv[1], parv[6], server_p))
      return;

    if (IsServer(source_p))
      newts = atol(parv[3]);
    if (IsServer(source_p) && parc == 10)
      svsid = parv[8];
  }
  else if (parc == 3)
  {
    if (IsServer(source_p))
      /* Servers can't change nicks.. */
      return;

    if (check_clean_nick(client_p, source_p, parv[1],
			 source_p->servptr))
      return;

    newts = atol(parv[2]);	
  }

  /* if the nick doesnt exist, allow it and process like normal */
  if ((target_p = hash_find_client(parv[1])) == NULL)
    nick_from_server(client_p, source_p, parc, parv, newts, svsid, parv[1], parv[parc-1]);
  else if (IsUnknown(target_p))
  {
    /* we're not living in the past anymore, an unknown client is local only. */
    exit_client(target_p, &me, "Overridden");
    nick_from_server(client_p, source_p, parc, parv, newts, svsid, parv[1], parv[parc-1]);
  }
  else if (target_p == source_p)
  {
    if (strcmp(target_p->name, parv[1]))
      nick_from_server(client_p, source_p, parc, parv, newts, svsid, parv[1], parv[parc-1]);
  }
  else
    perform_nick_collides(source_p, client_p, target_p, parc, parv,
                          newts, svsid, parv[1], parv[parc-1], NULL);
}


/*! \brief UID command handler (called by servers)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *
 * server introducing new nick (without services support)
 *  - parv[0] = sender prefix
 *  - parv[1] = nickname
 *  - parv[2] = hop count
 *  - parv[3] = TS
 *  - parv[4] = umode
 *  - parv[5] = username
 *  - parv[6] = hostname
 *  - parv[7] = ip
 *  - parv[8] = uid
 *  - parv[9] = ircname (gecos)
 *
 * server introducing new nick (with services support)
 *  - parv[ 0] = sender prefix
 *  - parv[ 1] = nickname
 *  - parv[ 2] = hop count
 *  - parv[ 3] = TS
 *  - parv[ 4] = umode
 *  - parv[ 5] = username
 *  - parv[ 6] = hostname
 *  - parv[ 7] = ip
 *  - parv[ 8] = uid
 *  - parv[ 9] = services id (timestamp)
 *  - parv[10] = ircname (gecos)
 */
static void
ms_uid(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct Client *target_p = NULL;
  time_t newts = 0;
  const char *svsid = "0";

  if (parc < 10 || EmptyString(parv[parc-1]))
    return;

  if (check_clean_nick(client_p, source_p, parv[1], source_p) ||
      check_clean_user(client_p,  parv[1], parv[5], source_p) ||
      check_clean_host(client_p,  parv[1], parv[6], source_p))
    return;

  newts = atol(parv[3]);
  svsid = parc == 11 ? parv[9] : "0";

  /*
   * if there is an ID collision, kill our client, and kill theirs.
   * this may generate 401's, but it ensures that both clients always
   * go, even if the other server refuses to do the right thing.
   */
  if ((target_p = hash_find_id(parv[8])) != NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
		         "ID collision on %s(%s <- %s)(both killed)",
			 target_p->name, target_p->from->name,
			 client_p->name);
    kill_client_ll_serv_butone(NULL, target_p, "%s (ID collision)",
		               me.name);

    ++ServerStats.is_kill;
    AddFlag(target_p, FLAGS_KILLED);
    exit_client(target_p, &me, "ID Collision");
    return;
  }
    
  if ((target_p = hash_find_client(parv[1])) == NULL)
    uid_from_server(client_p, source_p, parc, parv, newts, svsid, parv[1], parv[parc-1]);
  else if (IsUnknown(target_p))
  {
    exit_client(target_p, &me, "Overridden");
    uid_from_server(client_p, source_p, parc, parv, newts, svsid, parv[1], parv[parc-1]);
  }
  else
    perform_nick_collides(source_p, client_p, target_p, parc, parv, newts, svsid, parv[1],
                          parv[parc-1], parv[8]);
}			  

/* check_clean_nick()
 *
 * input	- pointer to source
 *		- 
 *		- nickname
 *		- truncated nickname
 *		- origin of client
 *		- pointer to server nick is coming from
 * output	- none
 * side effects - if nickname is erroneous, or a different length to
 *                truncated nickname, return 1
 */
static int
check_clean_nick(struct Client *client_p, struct Client *source_p, 
                 char *nick, struct Client *server_p)
{
  /* the old code did some wacky stuff here, if the nick is invalid, kill it
   * and dont bother messing at all
   */
  if (!valid_nickname(nick, 0))
  {
    ++ServerStats.is_kill;
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Bad/long Nick: %s From: %s(via %s)",
                         nick, server_p->name, client_p->name);

    sendto_one(client_p, ":%s KILL %s :%s (Bad Nickname)",
               me.name, nick, me.name);

    /* bad nick change */
    if (source_p != client_p)
    {
      kill_client_ll_serv_butone(client_p, source_p,
                                 "%s (Bad Nickname)",
				 me.name);
      AddFlag(source_p, FLAGS_KILLED);
      exit_client(source_p, &me, "Bad Nickname");
    }

    return 1;
  }

  return 0;
}

/* check_clean_user()
 * 
 * input	- pointer to client sending data
 *              - nickname
 *              - username to check
 *		- origin of NICK
 * output	- none
 * side effects - if username is erroneous, return 1
 */
static int
check_clean_user(struct Client *client_p, char *nick, 
                 char *user, struct Client *server_p)
{
  if (!clean_user_name(user))
  {
    ++ServerStats.is_kill;
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Bad/Long Username: %s Nickname: %s From: %s(via %s)",
                         user, nick, server_p->name, client_p->name);
    sendto_one(client_p, ":%s KILL %s :%s (Bad Username)",
               me.name, nick, me.name);
    return 1;
  }

  return 0;
}

/* check_clean_host()
 * 
 * input	- pointer to client sending us data
 *              - nickname
 *              - hostname to check
 *		- source name
 * output	- none
 * side effects - if hostname is erroneous, return 1
 */
static int
check_clean_host(struct Client *client_p, char *nick,
                 char *host, struct Client *server_p)
{
  if (!valid_hostname(host))
  {
    ++ServerStats.is_kill;
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Bad/Long Hostname: %s Nickname: %s From: %s(via %s)",
                         host, nick, server_p->name, client_p->name);
    sendto_one(client_p, ":%s KILL %s :%s (Bad Hostname)",
               me.name, nick, me.name);
    return 1;
  }

  return 0;
}

/* clean_user_name()
 *
 * input	- username
 * output	- none
 * side effects - walks through the username, returning 0 if erroneous
 */
static int
clean_user_name(const char *user)
{
  const char *p = user;

  assert(user && *user);

  for (; *p; ++p)
    if (!IsUserChar(*p))
      return 0;

  return p - user <= USERLEN;
}

/*
 * nick_from_server()
 */
static void
nick_from_server(struct Client *client_p, struct Client *source_p, int parc,
                 char *parv[], time_t newts, const char *svsid, char *nick, char *ngecos)
{
  int samenick = 0;

  if (IsServer(source_p))
  {
    /* A server introducing a new client, change source */
    source_p = make_client(client_p);
    dlinkAdd(source_p, &source_p->node, &global_client_list);

    if (parc > 2)
      source_p->hopcount = atoi(parv[2]);
    if (newts)
      source_p->tsinfo = newts;
    else
    {
      newts = source_p->tsinfo = CurrentTime;
      ts_warn("Remote nick %s (%s) introduced without a TS", nick, parv[0]);
    }

    strlcpy(source_p->svid, svsid, sizeof(source_p->svid));
    strlcpy(source_p->info, ngecos, sizeof(source_p->info));
    /* copy the nick in place */
    strlcpy(source_p->name, nick, sizeof(source_p->name));
    hash_add_client(source_p);

    if (parc > 8)
    {
      const char *m;

      /* parse usermodes */
      for (m = &parv[4][1]; *m; ++m)
      {
        unsigned int flag = user_modes[(unsigned char)*m];

        if ((flag & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
          ++Count.invisi;
        if ((flag & UMODE_OPER) && !HasUMode(source_p, UMODE_OPER))
          ++Count.oper;

        source_p->umodes |= flag & SEND_UMODES;
      }

      register_remote_user(source_p, parv[5], parv[6],
                           parv[7], ngecos);
      return;
    }
  }
  else if (source_p->name[0])
  {
    samenick = !irccmp(source_p->name, nick);

    /* client changing their nick */
    if (!samenick)
    {
      DelUMode(source_p, UMODE_REGISTERED);
      watch_check_hash(source_p, RPL_LOGOFF);
      source_p->tsinfo = newts ? newts : CurrentTime;
    }

    sendto_common_channels_local(source_p, 1, 0, ":%s!%s@%s NICK :%s",
                                 source_p->name,source_p->username,
                                 source_p->host, nick);

    add_history(source_p, 1);
    sendto_server(client_p, CAP_TS6, NOCAPS,
                  ":%s NICK %s :%lu",
                  ID(source_p), nick, (unsigned long)source_p->tsinfo);
    sendto_server(client_p, NOCAPS, CAP_TS6,
                  ":%s NICK %s :%lu",
                  source_p->name, nick, (unsigned long)source_p->tsinfo);
  }

  /* set the new nick name */
  if (source_p->name[0])
    hash_del_client(source_p);

  strlcpy(source_p->name, nick, sizeof(source_p->name));
  hash_add_client(source_p);

  if (!samenick)
    watch_check_hash(source_p, RPL_LOGON);
}

/*
 * client_from_server()
 */
static void
uid_from_server(struct Client *client_p, struct Client *source_p, int parc,
                char *parv[], time_t newts, const char *svsid, char *nick, char *ugecos)
{
  const char *m = NULL;
  const char *servername = source_p->name;

  source_p = make_client(client_p);
  dlinkAdd(source_p, &source_p->node, &global_client_list);

  source_p->hopcount = atoi(parv[2]);
  source_p->tsinfo = newts;
  strlcpy(source_p->svid, svsid, sizeof(source_p->svid));

  /* copy the nick in place */
  strcpy(source_p->name, nick);
  strlcpy(source_p->id, parv[8], sizeof(source_p->id));
  strlcpy(source_p->sockhost, parv[7], sizeof(source_p->sockhost));
  strlcpy(source_p->info, ugecos, sizeof(source_p->info));

  hash_add_client(source_p);
  hash_add_id(source_p);

  /* parse usermodes */
  for (m = &parv[4][1]; *m; ++m)
  {
    unsigned int flag = user_modes[(unsigned char)*m];

    if ((flag & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
      ++Count.invisi;
    if ((flag & UMODE_OPER) && !HasUMode(source_p, UMODE_OPER))
      ++Count.oper;

    source_p->umodes |= flag & SEND_UMODES;
  }

  register_remote_user(source_p, parv[5], parv[6],
                       servername, ugecos);
}

static void
perform_nick_collides(struct Client *source_p, struct Client *client_p, 
                      struct Client *target_p, int parc, char *parv[], 
                      time_t newts, const char *svsid, char *nick, char *gecos, char *uid)
{
  int sameuser;
  
  /* server introducing new nick */
  if (IsServer(source_p))
  {
    /* if we dont have a ts, or their TS's are the same, kill both */
    if (!newts || !target_p->tsinfo || (newts == target_p->tsinfo))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Nick collision on %s(%s <- %s)(both killed)",
			   target_p->name, target_p->from->name,
			   client_p->name);
      
      /* if we have a UID, issue a kill for it */
      if (uid)
        sendto_one(client_p, ":%s KILL %s :%s (Nick collision (new))",
                   me.id, uid, me.name);

      kill_client_ll_serv_butone(NULL, target_p,
                                 "%s (Nick collision (new))",
				 me.name);
      ++ServerStats.is_kill;
      sendto_one(target_p, ERR_NICKCOLLISION,
                 me.name, target_p->name, target_p->name);

      AddFlag(target_p, FLAGS_KILLED);
      exit_client(target_p, &me, "Nick collision (new)");
      return;
    }
    /* the timestamps are different */
    else
    {
      sameuser = !irccmp(target_p->username, parv[5]) &&
                 !irccmp(target_p->host, parv[6]);
   
      /* if the users are the same (loaded a client on a different server)
       * and the new users ts is older, or the users are different and the
       * new users ts is newer, ignore the new client and let it do the kill
       */
      if ((sameuser && newts < target_p->tsinfo) ||
         (!sameuser && newts > target_p->tsinfo))
      {
        if (uid)
          sendto_one(client_p, ":%s KILL %s :%s (Nick collision (new))",
                     me.id, uid, me.name);
	return;
      }
      else
      {
        if (sameuser)
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
	                  "Nick collision on %s(%s <- %s)(older killed)",
			  target_p->name, target_p->from->name,
			  client_p->name);
        else
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
	                  "Nick collision on %s(%s <- %s)(newer killed)",
			  target_p->name, target_p->from->name,
			  client_p->name);

        ++ServerStats.is_kill;
	sendto_one(target_p, ERR_NICKCOLLISION,
	           me.name, target_p->name, target_p->name);

        /* if it came from a LL server, itd have been source_p,
	 * so we dont need to mark target_p as known
	 */
	kill_client_ll_serv_butone(source_p, target_p,
	                           "%s (Nick collision (new))",
				   me.name);

        AddFlag(target_p, FLAGS_KILLED);
	exit_client(target_p, &me, "Nick collision");
	
	if (!uid && (parc == 9 || parc == 10))
	  nick_from_server(client_p, source_p, parc, parv, newts, svsid, nick, gecos);
	else if (uid && (parc == 10 || parc == 11))
	  uid_from_server(client_p, source_p, parc, parv, newts, svsid, nick, gecos);
	  
	return;
      }
    }
  }

  /* its a client changing nick and causing a collide */
  if (!newts || !target_p->tsinfo || (newts == target_p->tsinfo))
  {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                 "Nick change collision from %s to %s(%s <- %s)(both killed)",
		 source_p->name, target_p->name, target_p->from->name,
		 client_p->name);
    
      sendto_one(target_p, ERR_NICKCOLLISION, me.name,
                 target_p->name, target_p->name);

      ++ServerStats.is_kill;
      kill_client_ll_serv_butone(NULL, source_p, "%s (Nick change collision)",
                                 me.name);

      ++ServerStats.is_kill;
      kill_client_ll_serv_butone(NULL, target_p, "%s (Nick change collision)",
                                 me.name);

      AddFlag(target_p, FLAGS_KILLED);
      exit_client(target_p, &me, "Nick collision (new)");

      AddFlag(source_p, FLAGS_KILLED);
      exit_client(source_p, &me, "Nick collision (old)");
      return;
    }
    else
    {
      sameuser = !irccmp(target_p->username, source_p->username) &&
                 !irccmp(target_p->host, source_p->host);

      if ((sameuser && newts < target_p->tsinfo) ||
          (!sameuser && newts > target_p->tsinfo))
      {
        if (sameuser)
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
 	       "Nick change collision from %s to %s(%s <- %s)(older killed)",
	       source_p->name, target_p->name, target_p->from->name,
	       client_p->name);
        else
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
	       "Nick change collision from %s to %s(%s <- %s)(newer killed)",
	       source_p->name, target_p->name, target_p->from->name,
	       client_p->name);

        ++ServerStats.is_kill;
        kill_client_ll_serv_butone(client_p, source_p,
	                           "%s (Nick change collision)",
				   me.name);

        AddFlag(source_p, FLAGS_KILLED);
	
	if (sameuser)
	  exit_client(source_p, &me, "Nick collision (old)");
	else
	  exit_client(source_p, &me, "Nick collision (new)");
	return;
     }
     else
     {
       if (sameuser)
         sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
	                      "Nick collision on %s(%s <- %s)(older killed)",
			      target_p->name, target_p->from->name,
			      client_p->name);
       else
         sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
	                      "Nick collision on %s(%s <- %s)(newer killed)",
			      target_p->name, target_p->from->name,
			      client_p->name);
  			      
       kill_client_ll_serv_butone(source_p, target_p,
                                 "%s (Nick collision)",
				 me.name);

       ++ServerStats.is_kill;
       sendto_one(target_p, ERR_NICKCOLLISION,
                  me.name, target_p->name, target_p->name);

       AddFlag(target_p, FLAGS_KILLED);
       exit_client(target_p, &me, "Nick collision");
     }
   }

  /* we should only ever call nick_from_server() here, as
   * this is a client changing nick, not a new client
   */
  nick_from_server(client_p, source_p, parc, parv, newts, svsid, nick, gecos);
}

static struct Message nick_msgtab = {
  "NICK", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {mr_nick, m_nick, ms_nick, m_ignore, m_nick, m_ignore}
};

static struct Message uid_msgtab = {
  "UID", 0, 0, 10, MAXPARA, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_uid, m_ignore, m_ignore, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&uid_msgtab);
  mod_add_cmd(&nick_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&uid_msgtab);
  mod_del_cmd(&nick_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
