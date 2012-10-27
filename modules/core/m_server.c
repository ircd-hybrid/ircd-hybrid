/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_server.c: Introduces a server.
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
#include "handlers.h"    /* m_server prototype */
#include "client.h"      /* client struct */
#include "common.h"      /* TRUE bleah */
#include "event.h"
#include "hash.h"        /* add_to_client_hash_table */
#include "irc_string.h" 
#include "ircd.h"        /* me */
#include "numeric.h"     /* ERR_xxx */
#include "s_conf.h"      /* struct AccessItem */
#include "s_log.h"       /* log level defines */
#include "s_serv.h"      /* server_estab, check_server */
#include "s_user.h"
#include "send.h"        /* sendto_one */
#include "motd.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void mr_server(struct Client *, struct Client *, int, char *[]);
static void ms_server(struct Client *, struct Client *, int, char *[]);
static void ms_sid(struct Client *, struct Client *, int, char *[]);

static void set_server_gecos(struct Client *, char *);

struct Message server_msgtab = {
  "SERVER", 0, 0, 4, 0, MFLG_SLOW | MFLG_UNREG, 0,
  {mr_server, m_registered, ms_server, m_ignore, m_registered, m_ignore}
};

struct Message sid_msgtab = {
  "SID", 0, 0, 5, 0, MFLG_SLOW, 0,
  {rfc1459_command_send_error, m_ignore, ms_sid, m_ignore, m_ignore, m_ignore}
};

void 
_modinit(void)
{
  mod_add_cmd(&server_msgtab);
  mod_add_cmd(&sid_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&server_msgtab);
  mod_del_cmd(&sid_msgtab);
}

const char *_version = "$Revision$";


/* mr_server()
 *  parv[0] = sender prefix
 *  parv[1] = servername
 *  parv[2] = serverinfo/hopcount
 *  parv[3] = serverinfo
 */
static void
mr_server(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char info[REALLEN + 1];
  char *name;
  struct Client *target_p;
  int hop;

  if (parc < 4 || EmptyString(parv[3]))
  {
    sendto_one(client_p, "ERROR :No servername");
    exit_client(client_p, client_p, "Wrong number of args");
    return;
  }

  name = parv[1];
  hop  = atoi(parv[2]);
  strlcpy(info, parv[3], sizeof(info));

  /*
   * Reject a direct nonTS server connection if we're TS_ONLY -orabidoo
   */
  if (!DoesTS(client_p))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
          "Unauthorized server connection attempt from %s: Non-TS server "
          "for server %s", get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER,
          "Unauthorized server connection attempt from %s: Non-TS server "
          "for server %s", get_client_name(client_p, MASK_IP), name);
    exit_client(client_p, client_p, "Non-TS server");
    return;
  }

  if (!valid_servname(name))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", get_client_name(client_p, MASK_IP), name);
    exit_client(client_p, client_p, "Bogus server name");
    return;
  }

  /* Now we just have to call check_server and everything should
   * be check for us... -A1kmm.
   */
  switch (check_server(name, client_p, CHECK_SERVER_NOCRYPTLINK))
  {
    case -1:
      if (ConfigFileEntry.warn_no_nline)
      {
        sendto_realops_flags(UMODE_ALL, L_ADMIN,
           "Unauthorized server connection attempt from %s: No entry for "
           "servername %s", get_client_name(client_p, HIDE_IP), name);

        sendto_realops_flags(UMODE_ALL, L_OPER,
           "Unauthorized server connection attempt from %s: No entry for "
           "servername %s", get_client_name(client_p, MASK_IP), name);
      }

      exit_client(client_p, client_p, "Invalid servername.");
      return;
      /* NOT REACHED */
      break;

    case -2:
      sendto_realops_flags(UMODE_ALL, L_ADMIN,
           "Unauthorized server connection attempt from %s: Bad password "
           "for server %s", get_client_name(client_p, HIDE_IP), name);

      sendto_realops_flags(UMODE_ALL, L_OPER,
           "Unauthorized server connection attempt from %s: Bad password "
           "for server %s", get_client_name(client_p, MASK_IP), name);

      exit_client(client_p, client_p, "Invalid password.");
      return;
      /* NOT REACHED */
      break;

    case -3:
      sendto_realops_flags(UMODE_ALL, L_ADMIN,
           "Unauthorized server connection attempt from %s: Invalid host "
           "for server %s", get_client_name(client_p, HIDE_IP), name);

      sendto_realops_flags(UMODE_ALL, L_OPER,
           "Unauthorized server connection attempt from %s: Invalid host "
           "for server %s", get_client_name(client_p, MASK_IP), name);

      exit_client(client_p, client_p, "Invalid host.");
      return;
      /* NOT REACHED */
      break;

    /* servername is > HOSTLEN */
    case -4:
      sendto_realops_flags(UMODE_ALL, L_ADMIN,
                           "Invalid servername %s from %s",
			   name, get_client_name(client_p, HIDE_IP));
      sendto_realops_flags(UMODE_ALL, L_OPER,
		           "Invalid servername %s from %s",
			   name, get_client_name(client_p, MASK_IP));

      exit_client(client_p, client_p, "Invalid servername.");
      return;
      /* NOT REACHED */
      break;
  }

  if ((client_p->id[0] && (target_p = hash_find_id(client_p->id)))
      || (target_p = find_server(name)))
  {
    /* This link is trying feed me a server that I already have
     * access through another path -- multiple paths not accepted
     * currently, kill this link immediately!!
     *
     * Rather than KILL the link which introduced it, KILL the
     * youngest of the two links. -avalon
     *
     * Definitely don't do that here. This is from an unregistered
     * connect - A1kmm.
     */
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
			 "Attempt to re-introduce server %s SID %s from %s",
                         name, client_p->id, 
			 get_client_name(client_p, HIDE_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER,
			 "Attempt to re-introduce server %s SID %s from %s",
                         name, client_p->id,
			 get_client_name(client_p, MASK_IP));
    sendto_one(client_p, "ERROR :Server ID already exists.");
    exit_client(client_p, client_p, "Server ID Exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(name)))
    if (target_p != client_p)
      exit_client(target_p, &me, "Overridden");

  /* if we are connecting (Handshake), we already have the name from the
   * connect{} block in client_p->name
   */
  strlcpy(client_p->name, name, sizeof(client_p->name));
  set_server_gecos(client_p, info);
  client_p->hopcount = hop;
  server_estab(client_p);
}

/* ms_server()
 *  parv[0] = sender prefix
 *  parv[1] = servername
 *  parv[2] = serverinfo/hopcount
 *  parv[3] = serverinfo
 */
static void
ms_server(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char info[REALLEN + 1];
  char *name;
  struct Client *target_p;
  struct Client *bclient_p;
  struct ConfItem *conf;
  struct MatchItem *match_item;
  int hop;
  int hlined = 0;
  int llined = 0;
  dlink_node *ptr, *ptr_next;

  /* Just to be sure -A1kmm. */
  if (!IsServer(source_p))
    return;

  if (parc < 4 || EmptyString(parv[3]))
  {
    sendto_one(client_p, "ERROR :No servername");
    return;
  }

  name = parv[1];
  hop  = atoi(parv[2]);
  strlcpy(info, parv[3], sizeof(info));

  if (!valid_servname(name))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, MASK_IP), name);
    sendto_one(client_p, "ERROR :Bogus server name introduced");
    exit_client(client_p, &me, "Bogus server name intoduced");
    return;
  }

  if ((target_p = find_server(name)))
  {
    /* This link is trying feed me a server that I already have
     * access through another path -- multiple paths not accepted
     * currently, kill this link immediately!!
     *
     * Rather than KILL the link which introduced it, KILL the
     * youngest of the two links. -avalon
     *
     * I think that we should exit the link itself, not the introducer,
     * and we should always exit the most recently received(i.e. the
     * one we are receiving this SERVER for. -A1kmm
     *
     * You *cant* do this, if you link somewhere, it bursts you a server
     * that already exists, then sends you a client burst, you squit the
     * server, but you keep getting the burst of clients on a server that
     * doesnt exist, although ircd can handle it, its not a realistic
     * solution.. --fl_ 
     */
    /* It is behind a host-masked server. Completely ignore the
     * server message(don't propagate or we will delink from whoever
     * we propagate to). -A1kmm
     */
    if (irccmp(target_p->name, name) && target_p->from == client_p)
      return;

    sendto_one(client_p, "ERROR :Server %s already exists", name);
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
			 "Link %s cancelled, server %s already exists",
                         get_client_name(client_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER,
			 "Link %s cancelled, server %s already exists",
                         client_p->name, name);
    exit_client(client_p, &me, "Server Exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(name)))
    if (target_p != client_p)
      exit_client(target_p, &me, "Overridden");

  /* See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  DLINK_FOREACH(ptr, leaf_items.head)
  {
    conf = ptr->data;

    if (match(conf->name, client_p->name))
    {
      match_item = map_to_conf(conf);

      if (match(match_item->host, name))
	llined++;
    }
  }

  DLINK_FOREACH(ptr, hub_items.head)
  {
    conf = ptr->data;

    if (match(conf->name, client_p->name))
    {
      match_item = map_to_conf(conf);

      if (match(match_item->host, name))
	hlined++;
    }
  }

  /* Ok, this way this works is
   *
   * A server can have a CONF_HUB allowing it to introduce servers
   * behind it.
   *
   * connect {
   *            name = "irc.bighub.net";
   *            hub_mask="*";
   *            ...
   * 
   * That would allow "irc.bighub.net" to introduce anything it wanted..
   *
   * However
   *
   * connect {
   *            name = "irc.somehub.fi";
   *		hub_mask="*";
   *		leaf_mask="*.edu";
   *...
   * Would allow this server in finland to hub anything but
   * .edu's
   */

  /* Ok, check client_p can hub the new server */
  if (!hlined)
  {
    /* OOOPs nope can't HUB */
    sendto_realops_flags(UMODE_ALL, L_ADMIN, "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER,  "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, MASK_IP), name);
    exit_client(source_p, &me, "No matching hub_mask.");
    return;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
			 "Link %s introduced leafed server %s.",
                         get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER,
			 "Link %s introduced leafed server %s.",
                         get_client_name(client_p, MASK_IP), name);
    /* If it is new, we are probably misconfigured, so split the
     * non-hub server introducing this. Otherwise, split the new
     * server. -A1kmm.
     */
    /* wastes too much bandwidth, generates too many errors on
     * larger networks, dont bother. --fl_
     */
    exit_client(client_p, &me, "Leafed Server.");
    return;
  }

  target_p = make_client(client_p);
  make_server(target_p);
  target_p->hopcount = hop;
  target_p->servptr = source_p;

  strlcpy(target_p->name, name, sizeof(target_p->name));

  set_server_gecos(target_p, info);
  SetServer(target_p);

  dlinkAdd(target_p, &target_p->node, &global_client_list);
  dlinkAdd(target_p, make_dlink_node(), &global_serv_list);
  dlinkAdd(target_p, &target_p->lnode, &target_p->servptr->serv->server_list);

  hash_add_client(target_p);

  /* Old sendto_serv_but_one() call removed because we now
   * need to send different names to different servers
   * (domain name matching)
   */
  DLINK_FOREACH_SAFE(ptr, ptr_next, serv_list.head)
  {
    bclient_p = ptr->data;

    if (bclient_p == client_p)
      continue;

    sendto_one(bclient_p, ":%s SERVER %s %d :%s%s",
               ID_or_name(source_p, bclient_p), target_p->name, hop + 1,
               IsHidden(target_p) ? "(H) " : "",
               target_p->info);
  }

  sendto_realops_flags(UMODE_EXTERNAL, L_ALL,
                       "Server %s being introduced by %s",
                       target_p->name, source_p->name);
}

/* ms_sid()
 *  parv[0] = sender prefix
 *  parv[1] = servername
 *  parv[2] = serverinfo/hopcount
 *  parv[3] = sid of new server
 *  parv[4] = serverinfo
 */
static void
ms_sid(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char info[REALLEN + 1];
  struct Client *target_p;
  struct Client *bclient_p;
  struct ConfItem *conf;
  struct MatchItem *match_item;
  int hlined = 0;
  int llined = 0;
  dlink_node *ptr, *ptr_next;
  int hop;

  /* Just to be sure -A1kmm. */
  if (!IsServer(source_p))
    return;

  if (parc < 5 || EmptyString(parv[4]))
  {
    sendto_one(client_p, "ERROR :No servername");
    return;
  }

  hop = atoi(parv[2]);
  strlcpy(info, parv[4], sizeof(info));

  if (!valid_servname(parv[1]))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, MASK_IP), parv[1]);
    sendto_one(client_p, "ERROR :Bogus server name introduced");
    exit_client(client_p, &me, "Bogus server name intoduced");
    return;
  }

  if (!valid_sid(parv[3]))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(client_p, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_ALL, L_OPER,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(client_p, MASK_IP), parv[3]);
    sendto_one(client_p, "ERROR :Bogus server ID introduced");
    exit_client(client_p, &me, "Bogus server ID intoduced");
    return;
  }

  /* collision on SID? */
  if ((target_p = hash_find_id(parv[3])))
  {
    sendto_one(client_p, "ERROR :SID %s already exists", parv[3]);
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
			 "Link %s cancelled, SID %s already exists",
                         get_client_name(client_p, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_ALL, L_OPER,
			 "Link %s cancelled, SID %s already exists",
                         client_p->name, parv[3]);
    exit_client(client_p, &me, "Server Exists");
    return;
  }

  /* collision on name? */
  if ((target_p = find_server(parv[1])))
  {
    sendto_one(client_p, "ERROR :Server %s already exists", parv[1]);
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
                         "Link %s cancelled, server %s already exists",   
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER,
                         "Link %s cancelled, server %s already exists",   
                         client_p->name, parv[1]);
    exit_client(client_p, &me, "Server Exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(parv[1])))
    if (target_p != client_p)
      exit_client(target_p, &me, "Overridden");

  /* See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  DLINK_FOREACH(ptr, leaf_items.head)
  {
    conf = ptr->data;

    if (match(conf->name, client_p->name))
    {
      match_item = map_to_conf(conf);

      if (match(match_item->host, parv[1]))
	llined++;
    }
  }

  DLINK_FOREACH(ptr, hub_items.head)
  {
    conf = ptr->data;

    if (match(conf->name, client_p->name))
    {
      match_item = map_to_conf(conf);

      if (match(match_item->host, parv[1]))
	hlined++;
    }
  }

  /* Ok, this way this works is
   *
   * A server can have a CONF_HUB allowing it to introduce servers
   * behind it.
   *
   * connect {
   *            name = "irc.bighub.net";
   *            hub_mask="*";
   *            ...
   * 
   * That would allow "irc.bighub.net" to introduce anything it wanted..
   *
   * However
   *
   * connect {
   *            name = "irc.somehub.fi";
   *		hub_mask="*";
   *		leaf_mask="*.edu";
   *...
   * Would allow this server in finland to hub anything but
   * .edu's
   */

  /* Ok, check client_p can hub the new server, and make sure it's not a LL */
  if (!hlined)
  {
    /* OOOPs nope can't HUB */
    sendto_realops_flags(UMODE_ALL, L_ADMIN, "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER,  "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(source_p, &me, "No matching hub_mask.");
    return;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_realops_flags(UMODE_ALL, L_ADMIN,
			 "Link %s introduced leafed server %s.",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER,  
			 "Link %s introduced leafed server %s.",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(client_p, &me, "Leafed Server.");
    return;
  }

  target_p = make_client(client_p);
  make_server(target_p);
  target_p->hopcount = hop;
  target_p->servptr = source_p;

  strlcpy(target_p->name, parv[1], sizeof(target_p->name));
  strlcpy(target_p->id, parv[3], sizeof(target_p->id));

  set_server_gecos(target_p, info);
  SetServer(target_p);

  dlinkAdd(target_p, &target_p->node, &global_client_list);
  dlinkAdd(target_p, make_dlink_node(), &global_serv_list);
  dlinkAdd(target_p, &target_p->lnode, &target_p->servptr->serv->server_list);

  hash_add_client(target_p);
  hash_add_id(target_p);

  DLINK_FOREACH_SAFE(ptr, ptr_next, serv_list.head)
  {
    bclient_p = ptr->data;
    
    if (bclient_p == client_p)
      continue;

    if (IsCapable(bclient_p, CAP_TS6))
      sendto_one(bclient_p, ":%s SID %s %d %s :%s%s",
                 ID_or_name(source_p, client_p), target_p->name, hop + 1,
                 parv[3], IsHidden(target_p) ? "(H) " : "",
                 target_p->info);
    else
      sendto_one(bclient_p, ":%s SERVER %s %d :%s%s",
                 source_p->name, target_p->name, hop + 1,
                 IsHidden(target_p) ? "(H) " : "",
                 target_p->info);
  }

  sendto_realops_flags(UMODE_EXTERNAL, L_ALL, 
                       "Server %s being introduced by %s",
                       target_p->name, source_p->name);
}

/* set_server_gecos()
 *
 * input	- pointer to client
 * output	- NONE
 * side effects - servers gecos field is set
 */
static void
set_server_gecos(struct Client *client_p, char *info)
{
  /* check the info for [IP] */
  if (info[0])
  {
    char *p;
    char *s;
    char *t;
    
    s = info;
    
    /* we should only check the first word for an ip */
    if ((p = strchr(s, ' ')) != NULL)
      *p = '\0';
      
    /* check for a ] which would symbolise an [IP] */
    if ((t = strchr(s, ']')) != NULL)
    {
      /* set s to after the first space */
      if (p)
        s = ++p;
      else
        s = NULL;
    }
    /* no ], put the space back */
    else if (p)
      *p = ' ';

    /* p may have been set to a trailing space, so check s exists and that
     * it isnt \0 */
    if (s && (*s != '\0'))
    {
      /* a space? if not (H) could be the last part of info.. */
      if ((p = strchr(s, ' ')))
        *p = '\0';
      
      /* check for (H) which is a hidden server */
      if (!strcmp(s, "(H)"))
      {
        SetHidden(client_p);

        /* if there was no space.. theres nothing to set info to */
        if (p)
	  s = ++p;
	else
	  s = NULL;
      }
      else if (p)
        *p = ' ';

      /* if there was a trailing space, s could point to \0, so check */
      if (s && (*s != '\0'))
        strlcpy(client_p->info, s, sizeof(client_p->info));
      else
        strlcpy(client_p->info, "(Unknown Location)", sizeof(client_p->info));
    }
    else
      strlcpy(client_p->info, "(Unknown Location)", sizeof(client_p->info));
  }
  else
    strlcpy(client_p->info, "(Unknown Location)", sizeof(client_p->info));
}
