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
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_stats.h"
#include "s_user.h"
#include "whowas.h"
#include "s_serv.h"
#include "send.h"
#include "list.h"
#include "channel.h"
#include "s_log.h"
#include "resv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"
#include "packet.h"

static void m_nick(struct Client *, struct Client *, int, char **);
static void mr_nick(struct Client *, struct Client *, int, char **);
static void ms_nick(struct Client *, struct Client *, int, char **);
static void ms_uid(struct Client *, struct Client *, int, char **);

static void nick_from_server(struct Client *, struct Client *, int, char **,
                             time_t, char *, char *);
static void client_from_server(struct Client *, struct Client *, int, char **,
                               time_t, char *, char *);
static int check_clean_nick(struct Client *client_p, struct Client *source_p, 
                            char *nick, char *newnick,
			    struct Client *server_p);
static int check_clean_user(struct Client *client_p, char *nick, char *user,
			    struct Client *server_p);
static int check_clean_host(struct Client *client_p, char *nick, char *host,
			    struct Client *server_p);

static int clean_nick_name(char *, int);
static int clean_user_name(char *);
static int clean_host_name(char *);
static void perform_nick_collides(struct Client *, struct Client *, struct Client *,
				  int, char **, time_t, char *, char *, char *);
struct Message nick_msgtab = {
  "NICK", 0, 0, 1, 0, MFLG_SLOW, 0,
  {mr_nick, m_nick, ms_nick, m_ignore, m_nick, m_ignore}
};

struct Message uid_msgtab = {
  "UID", 0, 0, 10, 0, MFLG_SLOW, 0,
  {m_ignore, m_ignore, ms_uid, m_ignore, m_ignore, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&nick_msgtab);
  mod_add_cmd(&uid_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&nick_msgtab);
  mod_del_cmd(&uid_msgtab);
}

const char *_version = "$Revision$";
#endif

/* mr_nick()
 *
 *       parv[0] = sender prefix
 *       parv[1] = nickname
 */
static void
mr_nick(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p, *uclient_p;
  char nick[NICKLEN];
  char *s;
  dlink_node *ptr;
   
  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, EmptyString(parv[0]) ? "*" : parv[0]);
    return;
  }

  /* Terminate the nick at the first ~ */
  /* XXX - Is this still needed??      */
  if ((s = strchr(parv[1], '~')) != NULL)
    *s = '\0';

  /* copy the nick and terminate it */
  strlcpy(nick, parv[1], sizeof(nick));

  /* check the nickname is ok */
  if (!clean_nick_name(nick, 1))
  {
    sendto_one(source_p, form_str(ERR_ERRONEUSNICKNAME),
               me.name, EmptyString(parv[0]) ? "*" : parv[0], parv[1]);
    return;
  }

  /* check if the nick is resv'd */
  if (find_matching_name_conf(NRESV_TYPE, nick, NULL, NULL, 0) &&
      !IsExemptResv(source_p))
  {
    sendto_one(source_p, form_str(ERR_ERRONEUSNICKNAME),
               me.name, EmptyString(parv[0]) ? "*" : parv[0], nick);
    return;
  }

  if ((target_p = find_client(nick)) == NULL)
  {
    if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
    {
      /* We don't know anyone called nick, but our hub might */
      DLINK_FOREACH(ptr, unknown_list.head)
      {
        uclient_p = ptr->data;

	if (!strcmp(nick, uclient_p->llname))
	{
	
	  /* We're already waiting for a reply about this nick
	   * for someone else. */

	  sendto_one(source_p, form_str(ERR_NICKNAMEINUSE), me.name, "*", nick);
	  return;
	}
      }

      /* Set their llname so we can find them later */
      strcpy(source_p->llname, nick);

      /* Ask the hub about their requested name */
      sendto_one(uplink, ":%s NBURST %s %s !%s", me.name, nick,
                 nick, nick);

      /* wait for LLNICK */
      return;
    }
    else
    {
      set_initial_nick(client_p, source_p, nick);
      return;
    }
  }
  else if (source_p == target_p)
  {
    strcpy(source_p->name, nick);
    return;
  }
  else
  {
    sendto_one(source_p, form_str(ERR_NICKNAMEINUSE), me.name, "*", nick);
  }
}

/* m_nick()
 *
 *     parv[0] = sender prefix
 *     parv[1] = nickname
 */
static void
m_nick(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char nick[NICKLEN];
  struct Client *target_p;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NONICKNAMEGIVEN),
               me.name, parv[0]);
    return;
  }

  /* mark end of grace period, to prevent nickflooding */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  /* terminate nick to NICKLEN */
  strlcpy(nick, parv[1], sizeof(nick));

  /* check the nickname is ok */
  if (!clean_nick_name(nick, 1))
  {
    sendto_one(source_p, form_str(ERR_ERRONEUSNICKNAME),
               me.name, parv[0], nick);
    return;
  }

  if (find_matching_name_conf(NRESV_TYPE, nick,
			     NULL, NULL, 0) && !IsExemptResv(source_p) &&
     !(IsOper(source_p) && ConfigFileEntry.oper_pass_resv))
  {
    sendto_one(source_p, form_str(ERR_ERRONEUSNICKNAME),
               me.name, parv[0], nick);
    return;
  }

  if ((target_p = find_client(nick)))
  {
    /* If(target_p == source_p) the client is changing nicks between
     * equivalent nicknames ie: [nick] -> {nick}
     */

    if (target_p == source_p)
    {
      /* check the nick isnt exactly the same */
      if (!strcmp(target_p->name, nick))
        return; /* client is doing :old NICK old ignore it. */

      change_local_nick(client_p, source_p, nick);
      return;
    }

    /* if the client that has the nick isn't registered yet (nick but no
     * user) then drop the unregged client
     */
    if (IsUnknown(target_p))
    {
      /* the old code had an if(MyConnect(target_p)) here.. but I cant see
       * how that can happen, m_nick() is local only --fl_
       */
      exit_client(target_p, &me, "Overridden");
      change_local_nick(client_p, source_p, nick);
      return;
    }
    else
    {
      sendto_one(source_p, form_str(ERR_NICKNAMEINUSE), me.name,
                 parv[0], nick);
      return;
    }
  }
  else
  {
    if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
    {
      /* The uplink might know someone by this name already. */
      sendto_one(uplink, ":%s NBURST %s %s %s",
                 ID_or_name(&me, uplink), nick,
                 nick, source_p->name);
      return;
    }
    else
    {
      change_local_nick(client_p,source_p,nick);
      return;
    }
  }
}

/*
 * ms_nick()
 *      
 * server -> server nick change
 *    parv[0] = sender prefix
 *    parv[1] = nickname
 *    parv[2] = TS when nick change
 *
 * server introducing new nick
 *    parv[0] = sender prefix
 *    parv[1] = nickname
 *    parv[2] = hop count
 *    parv[3] = TS
 *    parv[4] = umode
 *    parv[5] = username
 *    parv[6] = hostname
 *    parv[7] = server
 *    parv[8] = ircname
 */
static void
ms_nick(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client* target_p;
  char nick[NICKLEN];
  char ngecos[REALLEN + 1];
  time_t newts = 0;
  char *nnick = parv[1];
  char *nhop = parv[2];
  char *nts = parv[3];
  char *nusername = parv[5];
  char *nhost = parv[6];
  char *nserver = parv[7];

  if (parc < 2 || EmptyString(nnick))
    return;

  /* fix the lengths */
  strlcpy(nick, nnick, sizeof(nick));

  if (parc == 9)
  {
    struct Client *server_p = find_server(nserver);

    strlcpy(ngecos, parv[8], sizeof(ngecos));

    if (server_p == NULL)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
			   "Invalid server %s from %s for NICK %s",
			   nserver, source_p->name, nick);
      sendto_one(client_p, ":%s KILL %s :%s (Server doesn't exist!)",
                 me.name, nick, me.name);
      return;
    }

    if (check_clean_nick(client_p, source_p, nick, nnick, server_p) ||
        check_clean_user(client_p, nick, nusername, server_p) ||
	check_clean_host(client_p, nick, nhost, server_p))
      return;

    /* check the length of the clients gecos */
    if (strlen(parv[8]) > REALLEN)
      sendto_realops_flags(UMODE_ALL, L_ALL,
			   "Long realname from server %s for %s",
			   nserver, nnick);

    if (IsServer(source_p))
      newts = atol(nts);
  }
  else if (parc == 3)
  {
    if (IsServer(source_p))
      /* Server's cant change nicks.. */
      return;

    if (check_clean_nick(client_p, source_p, nick, nnick,
			 source_p->servptr))
      return;
    
    /*
     * Yes, this is right. HOP field is the TS field for parc = 3
     */ 
    newts = atol(nhop);	
  }

  /* if the nick doesnt exist, allow it and process like normal */
  if (!(target_p = find_client(nick)))
  {
    nick_from_server(client_p, source_p, parc, parv, newts, nick, ngecos);
    return;
  }

  /* we're not living in the past anymore, an unknown client is local only. */
  if (IsUnknown(target_p))
  {
    exit_client(target_p, &me, "Overridden");
    nick_from_server(client_p, source_p, parc, parv, newts, nick, ngecos);
    return;
  }

  if (target_p == source_p)
  {
    if (strcmp(target_p->name, nick))
    {
      /* client changing case of nick */
      nick_from_server(client_p, source_p, parc, parv, newts, nick, ngecos);
      return;
    }
    else
      /* client not changing nicks at all */
      return;
  }

  perform_nick_collides(source_p, client_p, target_p,
                        parc, parv, newts, nick, ngecos, NULL);
}

/* ms_uid()
 *
 *  parv[0] = sender prefix
 *  parv[1] = nickname
 *  parv[2] = hop count
 *  parv[3] = TS
 *  parv[4] = umode
 *  parv[5] = username
 *  parv[6] = hostname
 *  parv[7] = ip
 *  parv[8] = uid
 *  parv[9] = ircname (gecos)
 */
static void
ms_uid(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct Client *target_p;
  char nick[NICKLEN];
  char ugecos[REALLEN + 1];
  time_t newts = 0;
  char *unick = parv[1];
  char *uts = parv[3];
  char *uname = parv[5];
  char *uhost = parv[6];
  char *uid = parv[8];

  if (EmptyString(unick))
    return;

  /* Fix the lengths */
  strlcpy(nick, parv[1], sizeof(nick));
  strlcpy(ugecos, parv[9], sizeof(ugecos));

  if (check_clean_nick(client_p, source_p, nick, unick, source_p) ||
      check_clean_user(client_p, nick, uname, source_p) ||
      check_clean_host(client_p, nick, uhost, source_p))
    return;

  if (strlen(parv[9]) > REALLEN)
    sendto_realops_flags(UMODE_ALL, L_ALL, "Long realname from server %s for %s",
                         parv[0], parv[1]);

  newts = atol(uts);

  /* if there is an ID collision, kill our client, and kill theirs.
   * this may generate 401's, but it ensures that both clients always
   * go, even if the other server refuses to do the right thing.
   */
  if ((target_p = hash_find_id(uid)) != NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,
		         "ID collision on %s(%s <- %s)(both killed)",
			 target_p->name, target_p->from->name,
			 client_p->name);

    if (ServerInfo.hub && IsCapable(client_p, CAP_LL))
      add_lazylinkclient(client_p, source_p);

    kill_client_ll_serv_butone(NULL, target_p, "%s (ID collision)",
		               me.name);

    ServerStats->is_kill++;
	    
    SetKilled(target_p);
    exit_client(target_p, &me, "ID Collision");
    return;
  }
    
  if ((target_p = find_client(unick)) == NULL)
    client_from_server(client_p, source_p, parc, parv, newts, nick, ugecos);
  else if (IsUnknown(target_p))
  {
    exit_client(target_p, &me, "Overridden");
    client_from_server(client_p, source_p, parc, parv, newts, nick, ugecos);
  }
  else
    perform_nick_collides(source_p, client_p, target_p,
                          parc, parv, newts, nick, ugecos, uid);
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
                 char *nick, char *newnick, struct Client *server_p)
{
  /* the old code did some wacky stuff here, if the nick is invalid, kill it
   * and dont bother messing at all
   */
  if (!clean_nick_name(nick, 0) || strcmp(nick, newnick))
  {
    ServerStats->is_kill++;
    sendto_realops_flags(UMODE_DEBUG, L_ALL,
                         "Bad Nick: %s From: %s(via %s)",
                         nick, server_p->name, client_p->name);

    sendto_one(client_p, ":%s KILL %s :%s (Bad Nickname)",
               me.name, newnick, me.name);

    /* bad nick change */
    if (source_p != client_p)
    {
      kill_client_ll_serv_butone(client_p, source_p,
                                 "%s (Bad Nickname)",
				 me.name);
      SetKilled(source_p);
      exit_client(source_p, &me, "Bad Nickname");
    }

    return (1);
  }

  return (0);
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
  if (strlen(user) > USERLEN)
  {
    ServerStats->is_kill++;
    sendto_realops_flags(UMODE_DEBUG, L_ALL,
                         "Long Username: %s Nickname: %s From: %s(via %s)",
			 user, nick, server_p->name, client_p->name);

    sendto_one(client_p, ":%s KILL %s :%s (Bad Username)",
               me.name, nick, me.name);
  
    return (1);
  }

  if (!clean_user_name(user))
    sendto_realops_flags(UMODE_DEBUG, L_ALL,
                         "Bad Username: %s Nickname: %s From: %s(via %s)",
			 user, nick, server_p->name, client_p->name);
			 
  return (0);
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
  if (strlen(host) > HOSTLEN)
  {
    ServerStats->is_kill++;
    sendto_realops_flags(UMODE_DEBUG, L_ALL,
                         "Long Hostname: %s Nickname: %s From: %s(via %s)",
			 host, nick, server_p->name, client_p->name);

    sendto_one(client_p, ":%s KILL %s :%s (Bad Hostname)",
               me.name, nick, me.name);

    return (1);
  }

  if (!clean_host_name(host))
    sendto_realops_flags(UMODE_DEBUG, L_ALL,
                         "Bad Hostname: %s Nickname: %s From: %s(via %s)",
			 host, nick, server_p->name, client_p->name);

  return (0);
}

/* clean_nick_name()
 *
 * input	- nickname
 *              - whether it's a local nick (1) or remote (0)
 * output	- none
 * side effects - walks through the nickname, returning 0 if erroneous
 */
static int
clean_nick_name(char *nick, int local)
{
  assert(nick);
  if (nick == NULL)
    return (0);

  /* nicks cant start with a digit or - or be 0 length */
  /* This closer duplicates behaviour of hybrid-6 */

  if (*nick == '-' || (IsDigit(*nick) && local) || *nick == '\0')
    return (0);

  for(; *nick; nick++)
  {
    if (!IsNickChar(*nick))
      return (0);
  }

  return (1);
}

/* clean_user_name()
 *
 * input	- username
 * output	- none
 * side effects - walks through the username, returning 0 if erroneous
 */
static int
clean_user_name(char *user)
{
  assert(user);
  if (user == NULL)
    return 0;
    
  for(; *user; user++)
  {
    if (!IsUserChar(*user))
      return 0;
  }

  return 1;
}

/* clean_host_name()
 * input	- hostname
 * output	- none
 * side effects - walks through the hostname, returning 0 if erroneous
 */
static int
clean_host_name(char *host)
{
  assert(host);
  if (host == NULL)
    return 0;
  for(; *host; host++)
  {
    if (!IsHostChar(*host))
      return 0;
  }

  return 1;
}

/*
 * nick_from_server()
 */
static void
nick_from_server(struct Client *client_p, struct Client *source_p, int parc,
                 char *parv[], time_t newts, char *nick, char *ngecos)
{
  if (IsServer(source_p))
  {
    /* A server introducing a new client, change source */
    source_p = make_client(client_p);
    dlinkAdd(source_p, &source_p->node, &global_client_list);

    /* We don't need to introduce leafs clients back to them! */
    if (ServerInfo.hub && IsCapable(client_p, CAP_LL))
      add_lazylinkclient(client_p, source_p);

    if (parc > 2)
      source_p->hopcount = atoi(parv[2]);
    if (newts)
      source_p->tsinfo = newts;
    else
    {
      newts = source_p->tsinfo = CurrentTime;
      ts_warn("Remote nick %s (%s) introduced without a TS", nick, parv[0]);
    }

    /* copy the nick in place */
    strcpy(source_p->name, nick);
    hash_add_client(source_p);

    if (parc > 8)
    {
      unsigned int flag;
      char *m;

      /* parse usermodes */
      m = &parv[4][1];

      while (*m)
      {
        flag = user_modes[(unsigned char)*m];
        if (!(source_p->umodes & UMODE_INVISIBLE) && (flag & UMODE_INVISIBLE))
	  Count.invisi++;
        if (!(source_p->umodes & UMODE_OPER) && (flag & UMODE_OPER))
	  Count.oper++;

        source_p->umodes |= flag & SEND_UMODES;
        m++;
      }

      register_remote_user(client_p, source_p, parv[5], parv[6],
                           parv[7], ngecos);
      return;
    }
  }
  else if (source_p->name[0])
  {
    /* client changing their nick */
    if (irccmp(parv[0], nick))
    {
      del_all_accepts(source_p);
      source_p->tsinfo = newts ? newts : CurrentTime;
    }

    sendto_common_channels_local(source_p, 1, ":%s!%s@%s NICK :%s",
                                 source_p->name,source_p->username,
                                 source_p->host, nick);

    add_history(source_p, 1);
    sendto_server(client_p, source_p, NULL, CAP_TS6, NOCAPS, NOFLAGS,
                  ":%s NICK %s :%lu",
                  ID(source_p), nick, (unsigned long)source_p->tsinfo);
    sendto_server(client_p, source_p, NULL, NOCAPS, CAP_TS6, NOFLAGS,
                  ":%s NICK %s :%lu",
                  parv[0], nick, (unsigned long)source_p->tsinfo);
  }

  /* set the new nick name */
  if (source_p->name[0])
    hash_del_client(source_p);

  strcpy(source_p->name, nick);
  hash_add_client(source_p);
}

/*
 * client_from_server()
 */
static void
client_from_server(struct Client *client_p, struct Client *source_p, int parc,
                   char *parv[], time_t newts, char *nick, char *ugecos)
{
  char *m;
  unsigned int flag;
  const char *servername = source_p->name;

  source_p = make_client(client_p);
  dlinkAdd(source_p, &source_p->node, &global_client_list);

  /* We don't need to introduce leafs clients back to them! */
  if (ServerInfo.hub && IsCapable(client_p, CAP_LL))
    add_lazylinkclient(client_p, source_p);

  source_p->hopcount = atoi(parv[2]);
  source_p->tsinfo = newts;

  /* copy the nick in place */
  strcpy(source_p->name, nick);
  strlcpy(source_p->id, parv[8], sizeof(source_p->id));
  strlcpy(source_p->sockhost, parv[7], sizeof(source_p->sockhost));

  hash_add_client(source_p);
  hash_add_id(source_p);

  /* parse usermodes */
  m = &parv[4][1];
  while (*m)
  {
    flag = user_modes[(unsigned char)*m];
    if (flag & UMODE_INVISIBLE)
      Count.invisi++;
    if (flag & UMODE_OPER)
      Count.oper++;

    source_p->umodes |= flag & SEND_UMODES;
    m++;
  }

  register_remote_user(client_p, source_p, parv[5], parv[6],
                       servername, ugecos);
}

static void
perform_nick_collides(struct Client *source_p, struct Client *client_p, 
                      struct Client *target_p, int parc, char *parv[], 
                      time_t newts, char *nick, char *gecos, char *uid)
{
  int sameuser;
  
  /* server introducing new nick */
  if (IsServer(source_p))
  {
    /* if we dont have a ts, or their TS's are the same, kill both */
    if (!newts || !target_p->tsinfo || (newts == target_p->tsinfo))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
                           "Nick collision on %s(%s <- %s)(both killed)",
			   target_p->name, target_p->from->name,
			   client_p->name);
      
      if (ServerInfo.hub && IsCapable(client_p,CAP_LL))
        add_lazylinkclient(client_p, target_p);

      /* if we have a UID, issue a kill for it */
      if (uid)
        sendto_one(client_p, ":%s KILL %s :%s (Nick collision (new))",
                   me.id, uid, me.name);

      kill_client_ll_serv_butone(NULL, target_p,
                                 "%s (Nick collision (new))",
				 me.name);
      ServerStats->is_kill++;
      sendto_one(target_p, form_str(ERR_NICKCOLLISION),
                 me.name, target_p->name, target_p->name);

      SetKilled(target_p);
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

        client_burst_if_needed(client_p, target_p);
	return;
      }
      else
      {
        if (sameuser)
	  sendto_realops_flags(UMODE_ALL, L_ALL,
	                  "Nick collision on %s(%s <- %s)(older killed)",
			  target_p->name, target_p->from->name,
			  client_p->name);
        else
	  sendto_realops_flags(UMODE_ALL, L_ALL,
	                  "Nick collision on %s(%s <- %s)(newer killed)",
			  target_p->name, target_p->from->name,
			  client_p->name);

        ServerStats->is_kill++;
	sendto_one(target_p, form_str(ERR_NICKCOLLISION),
	           me.name, target_p->name, target_p->name);

        /* if it came from a LL server, itd have been source_p,
	 * so we dont need to mark target_p as known
	 */
	kill_client_ll_serv_butone(source_p, target_p,
	                           "%s (Nick collision (new))",
				   me.name);

        SetKilled(target_p);
	exit_client(target_p, &me, "Nick collision");
	
	if (parc == 9)
	  nick_from_server(client_p, source_p, parc, parv, newts, nick, gecos);
	else if (parc == 10)
	  client_from_server(client_p, source_p, parc, parv, newts, nick, gecos);
	  
	return;
      }
    }
  }

  /* its a client changing nick and causing a collide */
  if (!newts || !target_p->tsinfo || (newts == target_p->tsinfo))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL,
                 "Nick change collision from %s to %s(%s <- %s)(both killed)",
		 source_p->name, target_p->name, target_p->from->name,
		 client_p->name);
    
      ServerStats->is_kill++;
      sendto_one(target_p, form_str(ERR_NICKCOLLISION),
                 me.name, target_p->name, target_p->name);

      /* if we got the message from a LL, it knows about source_p */
      kill_client_ll_serv_butone(NULL, source_p,
                                  "%s (Nick change collision)",
				  me.name);

      ServerStats->is_kill++;
      /* If we got the message from a LL, ensure it gets the kill */
      if (ServerInfo.hub && IsCapable(client_p,CAP_LL))
        add_lazylinkclient(client_p, target_p);

      kill_client_ll_serv_butone(NULL, target_p,
                                 "%s (Nick change collision)",
				 me.name);

      SetKilled(target_p);
      exit_client(target_p, &me, "Nick collision (new)");
      SetKilled(source_p);
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
	  sendto_realops_flags(UMODE_ALL, L_ALL,
 	       "Nick change collision from %s to %s(%s <- %s)(older killed)",
	       source_p->name, target_p->name, target_p->from->name,
	       client_p->name);
        else
	  sendto_realops_flags(UMODE_ALL, L_ALL,
	       "Nick change collision from %s to %s(%s <- %s)(newer killed)",
	       source_p->name, target_p->name, target_p->from->name,
	       client_p->name);

        ServerStats->is_kill++;

	/* this won't go back to the incoming link, so LL doesnt matter */
        kill_client_ll_serv_butone(client_p, source_p,
	                           "%s (Nick change collision)",
				   me.name);

        SetKilled(source_p);
	
	if (sameuser)
	  exit_client(source_p, &me, "Nick collision (old)");
	else
	  exit_client(source_p, &me, "Nick collision (new)");
	return;
     }
     else
     {
       if (sameuser)
         sendto_realops_flags(UMODE_ALL, L_ALL,
	                      "Nick collision on %s(%s <- %s)(older killed)",
			      target_p->name, target_p->from->name,
			      client_p->name);
       else
         sendto_realops_flags(UMODE_ALL, L_ALL,
	                      "Nick collision on %s(%s <- %s)(newer killed)",
			      target_p->name, target_p->from->name,
			      client_p->name);
  			      
       kill_client_ll_serv_butone(source_p, target_p,
                                 "%s (Nick collision)",
				 me.name);

       ServerStats->is_kill++;
       sendto_one(target_p, form_str(ERR_NICKCOLLISION),
                  me.name, target_p->name, target_p->name);

       SetKilled(target_p);
       exit_client(target_p, &me, "Nick collision");
     }
   }

  /* we should only ever call nick_from_server() here, as
   * this is a client changing nick, not a new client
   */
  nick_from_server(client_p, source_p, parc, parv, newts, nick, gecos);
}
