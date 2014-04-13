/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file m_server.c
 * \brief Includes required functions for processing the SERVER/SID command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "s_misc.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "parse.h"
#include "memory.h"
#include "modules.h"
#include "channel_mode.h"


/* sendnick_TS()
 *
 * inputs       - client (server) to send nick towards
 *          - client to send nick for
 * output       - NONE
 * side effects - NICK message is sent towards given client_p
 */
void
sendnick_TS(struct Client *client_p, struct Client *target_p)
{
  char ubuf[IRCD_BUFSIZE];

  if (!IsClient(target_p))
    return;

  send_umode(NULL, target_p, 0, SEND_UMODES, ubuf);

  if (ubuf[0] == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  if (IsCapable(client_p, CAP_SVS))
  {
    if (HasID(target_p) && IsCapable(client_p, CAP_TS6))
      sendto_one(client_p, ":%s UID %s %d %lu %s %s %s %s %s %s :%s",
                 target_p->servptr->id,
                 target_p->name, target_p->hopcount + 1,
                 (unsigned long) target_p->tsinfo,
                 ubuf, target_p->username, target_p->host,
                 (MyClient(target_p) && IsIPSpoof(target_p)) ?
                 "0" : target_p->sockhost, target_p->id,
                 target_p->svid, target_p->info);
    else
      sendto_one(client_p, "NICK %s %d %lu %s %s %s %s %s :%s",
                 target_p->name, target_p->hopcount + 1,
                 (unsigned long) target_p->tsinfo,
                 ubuf, target_p->username, target_p->host,
                 target_p->servptr->name, target_p->svid,
                 target_p->info);
  }
  else
  {
    if (HasID(target_p) && IsCapable(client_p, CAP_TS6))
      sendto_one(client_p, ":%s UID %s %d %lu %s %s %s %s %s :%s",
                 target_p->servptr->id,
                 target_p->name, target_p->hopcount + 1,
                 (unsigned long) target_p->tsinfo,
                 ubuf, target_p->username, target_p->host,
                 (MyClient(target_p) && IsIPSpoof(target_p)) ?
                 "0" : target_p->sockhost, target_p->id, target_p->info);
    else
      sendto_one(client_p, "NICK %s %d %lu %s %s %s %s :%s",
                 target_p->name, target_p->hopcount + 1,
                 (unsigned long) target_p->tsinfo,
                 ubuf, target_p->username, target_p->host,
                 target_p->servptr->name, target_p->info);
  }

  if (!EmptyString(target_p->certfp))
    sendto_one(client_p, ":%s CERTFP %s",
               ID_or_name(target_p, client_p), target_p->certfp);

  if (target_p->away[0])
    sendto_one(client_p, ":%s AWAY :%s", ID_or_name(target_p, client_p),
               target_p->away);

}

/*
 * send_tb
 *
 * inputs       - pointer to Client
 *              - pointer to channel
 * output       - NONE
 * side effects - Called on a server burst when
 *                server is CAP_TBURST capable
 */
static void
send_tb(struct Client *client_p, struct Channel *chptr)
{
  /*
   * We may also send an empty topic here, but only if topic_time isn't 0,
   * i.e. if we had a topic that got unset.  This is required for syncing
   * topics properly.
   *
   * Imagine the following scenario: Our downlink introduces a channel
   * to us with a TS that is equal to ours, but the channel topic on
   * their side got unset while the servers were in splitmode, which means
   * their 'topic' is newer.  They simply wanted to unset it, so we have to
   * deal with it in a more sophisticated fashion instead of just resetting
   * it to their old topic they had before.  Read m_tburst.c:ms_tburst
   * for further information   -Michael
   */
  if (chptr->topic_time != 0)
    sendto_one(client_p, ":%s TBURST %lu %s %lu %s :%s",
               ID_or_name(&me, client_p),
               (unsigned long)chptr->channelts, chptr->chname,
               (unsigned long)chptr->topic_time,
               chptr->topic_info,
               chptr->topic);
}

/* burst_members()
 *
 * inputs       - pointer to server to send members to
 *              - dlink_list pointer to membership list to send
 * output       - NONE
 * side effects -
 */
static void
burst_members(struct Client *client_p, struct Channel *chptr)
{
  struct Client *target_p;
  struct Membership *ms;
  dlink_node *ptr;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms       = ptr->data;
    target_p = ms->client_p;

    if (!HasFlag(target_p, FLAGS_BURSTED))
    {
      AddFlag(target_p, FLAGS_BURSTED);

      if (target_p->from != client_p)
        sendnick_TS(client_p, target_p);
    }
  }
}

/* burst_all()
 *
 * inputs       - pointer to server to send burst to
 * output       - NONE
 * side effects - complete burst of channels/nicks is sent to client_p
 */
static void
burst_all(struct Client *client_p)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, global_channel_list.head)
  {
    struct Channel *chptr = ptr->data;

    if (dlink_list_length(&chptr->members) != 0)
    {
      burst_members(client_p, chptr);
      send_channel_modes(client_p, chptr);

      if (IsCapable(client_p, CAP_TBURST))
        send_tb(client_p, chptr);
    }
  }

  /* also send out those that are not on any channel
   */
  DLINK_FOREACH(ptr, global_client_list.head)
  {
    struct Client *target_p = ptr->data;

    if (!HasFlag(target_p, FLAGS_BURSTED) && target_p->from != client_p)
      sendnick_TS(client_p, target_p);

    DelFlag(target_p, FLAGS_BURSTED);
  }

  if (IsCapable(client_p, CAP_EOB))
    sendto_one(client_p, ":%s EOB", ID_or_name(&me, client_p));
}

/* server_burst()
 *
 * inputs       - struct Client pointer server
 *              -
 * output       - none
 * side effects - send a server burst
 * bugs         - still too long
 */
static void
server_burst(struct Client *client_p)
{
  /* Send it in the shortened format with the TS, if
  ** it's a TS server; walk the list of channels, sending
  ** all the nicks that haven't been sent yet for each
  ** channel, then send the channel itself -- it's less
  ** obvious than sending all nicks first, but on the
  ** receiving side memory will be allocated more nicely
  ** saving a few seconds in the handling of a split
  ** -orabidoo
  */

  burst_all(client_p);

  /* EOB stuff is now in burst_all */
  /* Always send a PING after connect burst is done */
  sendto_one(client_p, "PING :%s", ID_or_name(&me, client_p));
}

/* server_estab()
 *
 * inputs       - pointer to a struct Client
 * output       -
 * side effects -
 */
void
server_estab(struct Client *client_p)
{
  struct Client *target_p;
  struct MaskItem *conf = NULL;
  char *host;
  const char *inpath;
  static char inpath_ip[HOSTLEN * 2 + USERLEN + 6];
  dlink_node *ptr;
#ifdef HAVE_LIBCRYPTO
  const COMP_METHOD *compression = NULL, *expansion = NULL;
#endif

  assert(client_p != NULL);

  strlcpy(inpath_ip, get_client_name(client_p, SHOW_IP), sizeof(inpath_ip));

  inpath = get_client_name(client_p, MASK_IP); /* "refresh" inpath with host */
  host   = client_p->name;

  if ((conf = find_conf_name(&client_p->localClient->confs, host, CONF_SERVER))
      == NULL)
  {
    /* This shouldn't happen, better tell the ops... -A1kmm */
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Warning: Lost connect{} block "
                         "for server %s(this shouldn't happen)!", host);
    exit_client(client_p, &me, "Lost connect{} block!");
    return;
  }

  MyFree(client_p->localClient->passwd);
  client_p->localClient->passwd = NULL;

  /* Its got identd, since its a server */
  SetGotId(client_p);

  /* If there is something in the serv_list, it might be this
   * connecting server..
   */
  if (!ServerInfo.hub && serv_list.head)
  {
    if (client_p != serv_list.head->data || serv_list.head->next)
    {
      ++ServerStats.is_ref;
      sendto_one(client_p, "ERROR :I'm a leaf not a hub");
      exit_client(client_p, &me, "I'm a leaf");
      return;
    }
  }

  if (IsUnknown(client_p))
  {
    sendto_one(client_p, "PASS %s TS %d %s", conf->spasswd, TS_CURRENT, me.id);

    send_capabilities(client_p, 0);

    sendto_one(client_p, "SERVER %s 1 :%s%s",
               me.name, ConfigServerHide.hidden ? "(H) " : "", me.info);
  }

  sendto_one(client_p, "SVINFO %d %d 0 :%lu", TS_CURRENT, TS_MIN,
             (unsigned long)CurrentTime);

  /* assumption here is if they passed the correct TS version, they also passed an SID */
  if (IsCapable(client_p, CAP_TS6))
    hash_add_id(client_p);

  /* XXX Does this ever happen? I don't think so -db */
  detach_conf(client_p, CONF_OPER);

  /* *WARNING*
  **    In the following code in place of plain server's
  **    name we send what is returned by get_client_name
  **    which may add the "sockhost" after the name. It's
  **    *very* *important* that there is a SPACE between
  **    the name and sockhost (if present). The receiving
  **    server will start the information field from this
  **    first blank and thus puts the sockhost into info.
  **    ...a bit tricky, but you have been warned, besides
  **    code is more neat this way...  --msa
  */
  client_p->servptr = &me;

  if (IsClosing(client_p))
    return;

  SetServer(client_p);

  /* Update the capability combination usage counts. -A1kmm */
  set_chcap_usage_counts(client_p);

  /* Some day, all these lists will be consolidated *sigh* */
  dlinkAdd(client_p, &client_p->lnode, &me.serv->server_list);

  assert(dlinkFind(&unknown_list, client_p));

  dlink_move_node(&client_p->localClient->lclient_node,
                  &unknown_list, &serv_list);

  Count.myserver++;

  dlinkAdd(client_p, make_dlink_node(), &global_serv_list);
  hash_add_client(client_p);

  /* doesnt duplicate client_p->serv if allocated this struct already */
  make_server(client_p);

  /* fixing eob timings.. -gnp */
  client_p->localClient->firsttime = CurrentTime;

  if (find_matching_name_conf(CONF_SERVICE, client_p->name, NULL, NULL, 0))
    AddFlag(client_p, FLAGS_SERVICE);

  /* Show the real host/IP to admins */
#ifdef HAVE_LIBCRYPTO
  if (client_p->localClient->fd.ssl)
  {
    compression = SSL_get_current_compression(client_p->localClient->fd.ssl);
    expansion   = SSL_get_current_expansion(client_p->localClient->fd.ssl);

    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link with %s established: [SSL: %s, Compression/Expansion method: %s/%s] (Capabilities: %s)",
                         inpath_ip, ssl_get_cipher(client_p->localClient->fd.ssl),
                         compression ? SSL_COMP_get_name(compression) : "NONE",
                         expansion ? SSL_COMP_get_name(expansion) : "NONE",
                         show_capabilities(client_p));
    /* Now show the masked hostname/IP to opers */
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link with %s established: [SSL: %s, Compression/Expansion method: %s/%s] (Capabilities: %s)",
                         inpath, ssl_get_cipher(client_p->localClient->fd.ssl),
                         compression ? SSL_COMP_get_name(compression) : "NONE",
                         expansion ? SSL_COMP_get_name(expansion) : "NONE",
                         show_capabilities(client_p));
    ilog(LOG_TYPE_IRCD, "Link with %s established: [SSL: %s, Compression/Expansion method: %s/%s] (Capabilities: %s)",
         inpath_ip, ssl_get_cipher(client_p->localClient->fd.ssl),
         compression ? SSL_COMP_get_name(compression) : "NONE",
         expansion ? SSL_COMP_get_name(expansion) : "NONE",
         show_capabilities(client_p));
  }
  else
#endif
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link with %s established: (Capabilities: %s)",
                         inpath_ip, show_capabilities(client_p));
    /* Now show the masked hostname/IP to opers */
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link with %s established: (Capabilities: %s)",
                         inpath, show_capabilities(client_p));
    ilog(LOG_TYPE_IRCD, "Link with %s established: (Capabilities: %s)",
         inpath_ip, show_capabilities(client_p));
  }

  fd_note(&client_p->localClient->fd, "Server: %s", client_p->name);

  /* Old sendto_serv_but_one() call removed because we now
  ** need to send different names to different servers
  ** (domain name matching) Send new server to other servers.
  */
  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    if (target_p == client_p)
      continue;

    if (IsCapable(target_p, CAP_TS6) && HasID(client_p))
      sendto_one(target_p, ":%s SID %s 2 %s :%s%s",
                 me.id, client_p->name, client_p->id,
                 IsHidden(client_p) ? "(H) " : "",
                 client_p->info);
    else
      sendto_one(target_p,":%s SERVER %s 2 :%s%s",
                 me.name, client_p->name,
                 IsHidden(client_p) ? "(H) " : "",
                 client_p->info);
  }

  DLINK_FOREACH_PREV(ptr, global_serv_list.tail)
  {
    target_p = ptr->data;

    /* target_p->from == target_p for target_p == client_p */
    if (IsMe(target_p) || target_p->from == client_p)
      continue;

    if (IsCapable(client_p, CAP_TS6))
    {
      if (HasID(target_p))
        sendto_one(client_p, ":%s SID %s %d %s :%s%s",
                   ID(target_p->servptr), target_p->name, target_p->hopcount+1,
                   target_p->id, IsHidden(target_p) ? "(H) " : "",
                   target_p->info);
      else  /* introducing non-ts6 server */
        sendto_one(client_p, ":%s SERVER %s %d :%s%s",
                   ID(target_p->servptr), target_p->name, target_p->hopcount+1,
                   IsHidden(target_p) ? "(H) " : "", target_p->info);
    }
    else
      sendto_one(client_p, ":%s SERVER %s %d :%s%s",
                 target_p->servptr->name, target_p->name, target_p->hopcount+1,
                 IsHidden(target_p) ? "(H) " : "", target_p->info);

    if (HasFlag(target_p, FLAGS_EOB))
      sendto_one(client_p, ":%s EOB", ID_or_name(target_p, client_p));
  }

  server_burst(client_p);
}

/* set_server_gecos()
 *
 * input        - pointer to client
 * output       - NONE
 * side effects - servers gecos field is set
 */
static void
set_server_gecos(struct Client *client_p, const char *info)
{
  const char *s = info;

  /* check for (H) which is a hidden server */
  if (!strncmp(s, "(H) ", 4))
  {
    SetHidden(client_p);
    s = s + 4;
  }

  if (!EmptyString(s))
    strlcpy(client_p->info, s, sizeof(client_p->info));
  else
    strlcpy(client_p->info, "(Unknown Location)", sizeof(client_p->info));
}

/* mr_server()
 *  parv[0] = sender prefix
 *  parv[1] = servername
 *  parv[2] = serverinfo/hopcount
 *  parv[3] = serverinfo
 */
static int
mr_server(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char *name;
  struct Client *target_p;
  int hop;

  if (EmptyString(parv[3]))
  {
    sendto_one(client_p, "ERROR :No servername");
    exit_client(client_p, client_p, "Wrong number of args");
    return 0;
  }

  name = parv[1];
  hop  = atoi(parv[2]);

  /*
   * Reject a direct nonTS server connection if we're TS_ONLY -orabidoo
   */
  if (!DoesTS(client_p))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Non-TS server "
          "for server %s", get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Non-TS server "
          "for server %s", get_client_name(client_p, MASK_IP), name);
    exit_client(client_p, client_p, "Non-TS server");
    return 0;
  }

  if (!valid_servname(name))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", get_client_name(client_p, MASK_IP), name);
    exit_client(client_p, client_p, "Bogus server name");
    return 0;
  }

  /* Now we just have to call check_server and everything should
   * be check for us... -A1kmm.
   */
  switch (check_server(name, client_p))
  {
    case -1:
      if (ConfigFileEntry.warn_no_nline)
      {
        sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: No entry for "
           "servername %s", get_client_name(client_p, HIDE_IP), name);

        sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: No entry for "
           "servername %s", get_client_name(client_p, MASK_IP), name);
      }

      exit_client(client_p, client_p, "No connect{} block.");
      return 0;
      /* NOT REACHED */
      break;

    case -2:
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Bad password "
           "for server %s", get_client_name(client_p, HIDE_IP), name);

      sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Bad password "
           "for server %s", get_client_name(client_p, MASK_IP), name);

      exit_client(client_p, client_p, "Invalid password.");
      return 0;
      /* NOT REACHED */
      break;

    case -3:
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid host "
           "for server %s", get_client_name(client_p, HIDE_IP), name);

      sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid host "
           "for server %s", get_client_name(client_p, MASK_IP), name);

      exit_client(client_p, client_p, "Invalid host.");
      return 0;
    case -4:
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid certificate fingerprint "
           "for server %s", get_client_name(client_p, HIDE_IP), name);

      sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid certificate fingerprint "
           "for server %s", get_client_name(client_p, MASK_IP), name);

      exit_client(client_p, client_p, "Invalid certificate fingerprint.");
      return 0;
      /* NOT REACHED */
      break;
  }

  if ((target_p = hash_find_server(name)))
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
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Attempt to re-introduce server %s from %s",
                         name, get_client_name(client_p, HIDE_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Attempt to re-introduce server %s from %s",
                         name, get_client_name(client_p, MASK_IP));
    sendto_one(client_p, "ERROR :Server already exists.");
    exit_client(client_p, client_p, "Server already exists");
    return 0;
  }

  if ((client_p->id[0] && (target_p = hash_find_id(client_p->id))))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Attempt to re-introduce server %s SID %s from %s",
                         name, client_p->id,
                         get_client_name(client_p, HIDE_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Attempt to re-introduce server %s SID %s from %s",
                         name, client_p->id,
                         get_client_name(client_p, MASK_IP));
    sendto_one(client_p, "ERROR :Server ID already exists.");
    exit_client(client_p, client_p, "Server ID already exists");
    return 0;
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
  set_server_gecos(client_p, parv[3]);
  client_p->hopcount = hop;
  server_estab(client_p);
  return 0;
}

/* ms_server()
 *  parv[0] = sender prefix
 *  parv[1] = servername
 *  parv[2] = serverinfo/hopcount
 *  parv[3] = serverinfo
 */
static int
ms_server(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  char *name;
  struct Client *target_p;
  struct MaskItem *conf = NULL;
  int hop;
  int hlined = 0;
  int llined = 0;
  dlink_node *ptr = NULL;

  /* Just to be sure -A1kmm. */
  if (!IsServer(source_p))
    return 0;

  if (EmptyString(parv[3]))
  {
    sendto_one(client_p, "ERROR :No servername");
    return 0;
  }

  name = parv[1];
  hop  = atoi(parv[2]);

  if (!valid_servname(name))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, MASK_IP), name);
    sendto_one(client_p, "ERROR :Bogus server name introduced");
    exit_client(client_p, &me, "Bogus server name intoduced");
    return 0;
  }

  if ((target_p = hash_find_server(name)))
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
    sendto_one(client_p, "ERROR :Server %s already exists", name);
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         get_client_name(client_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         client_p->name, name);
    exit_client(client_p, &me, "Server Exists");
    return 0;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(name)))
    if (target_p != client_p)
      exit_client(target_p, &me, "Overridden");

  conf = client_p->localClient->confs.head->data;

  /* See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  DLINK_FOREACH(ptr, conf->leaf_list.head)
    if (!match(ptr->data, name))
    {
      llined = 1;
      break;
    }

  DLINK_FOREACH(ptr, conf->hub_list.head)
    if (!match(ptr->data, name))
    {
      hlined = 1;
      break;
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
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, MASK_IP), name);
    exit_client(source_p, &me, "No matching hub_mask.");
    return 0;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         get_client_name(client_p, HIDE_IP), name);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
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
    return 0;
  }

  target_p = make_client(client_p);
  make_server(target_p);
  target_p->hopcount = hop;
  target_p->servptr = source_p;

  strlcpy(target_p->name, name, sizeof(target_p->name));

  set_server_gecos(target_p, parv[3]);
  SetServer(target_p);

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_SERVICE, target_p->name, NULL, NULL, 0))
    AddFlag(target_p, FLAGS_SERVICE);

  dlinkAdd(target_p, &target_p->node, &global_client_list);
  dlinkAdd(target_p, make_dlink_node(), &global_serv_list);
  dlinkAdd(target_p, &target_p->lnode, &target_p->servptr->serv->server_list);

  hash_add_client(target_p);

  sendto_server(client_p, NOCAPS, NOCAPS, ":%s SERVER %s %d :%s%s",
                source_p->name, target_p->name, hop + 1,
                IsHidden(target_p) ? "(H) " : "", target_p->info);

  sendto_realops_flags(UMODE_EXTERNAL, L_ALL, SEND_NOTICE,
                       "Server %s being introduced by %s",
                       target_p->name, source_p->name);
  return 0;
}

/* ms_sid()
 *  parv[0] = sender prefix
 *  parv[1] = servername
 *  parv[2] = serverinfo/hopcount
 *  parv[3] = sid of new server
 *  parv[4] = serverinfo
 */
static int
ms_sid(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct Client *target_p;
  struct MaskItem *conf = NULL;
  int hlined = 0;
  int llined = 0;
  dlink_node *ptr = NULL;
  int hop;

  /* Just to be sure -A1kmm. */
  if (!IsServer(source_p))
    return 0;

  if (EmptyString(parv[4]))
  {
    sendto_one(client_p, "ERROR :No servername");
    return 0;
  }

  hop = atoi(parv[2]);

  if (!valid_servname(parv[1]))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, MASK_IP), parv[1]);
    sendto_one(client_p, "ERROR :Bogus server name introduced");
    exit_client(client_p, &me, "Bogus server name intoduced");
    return 0;
  }

  if (!valid_sid(parv[3]))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(client_p, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(client_p, MASK_IP), parv[3]);
    sendto_one(client_p, "ERROR :Bogus server ID introduced");
    exit_client(client_p, &me, "Bogus server ID intoduced");
    return 0;
  }

  /* collision on SID? */
  if ((target_p = hash_find_id(parv[3])))
  {
    sendto_one(client_p, "ERROR :SID %s already exists", parv[3]);
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, SID %s already exists",
                         get_client_name(client_p, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, SID %s already exists",
                         client_p->name, parv[3]);
    exit_client(client_p, &me, "SID Exists");
    return 0;
  }

  /* collision on name? */
  if ((target_p = hash_find_server(parv[1])))
  {
    sendto_one(client_p, "ERROR :Server %s already exists", parv[1]);
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         client_p->name, parv[1]);
    exit_client(client_p, &me, "Server Exists");
    return 0;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(parv[1])))
    if (target_p != client_p)
      exit_client(target_p, &me, "Overridden");

  conf = client_p->localClient->confs.head->data;

  /* See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  DLINK_FOREACH(ptr, conf->leaf_list.head)
    if (!match(ptr->data, parv[1]))
    {
      llined = 1;
      break;
    }

  DLINK_FOREACH(ptr, conf->hub_list.head)
    if (!match(ptr->data, parv[1]))
    {
      hlined = 1;
      break;
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
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(source_p, &me, "No matching hub_mask.");
    return 0;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(client_p, &me, "Leafed Server.");
    return 0;
  }

  target_p = make_client(client_p);
  make_server(target_p);
  target_p->hopcount = hop;
  target_p->servptr = source_p;

  strlcpy(target_p->name, parv[1], sizeof(target_p->name));
  strlcpy(target_p->id, parv[3], sizeof(target_p->id));

  set_server_gecos(target_p, parv[4]);
  SetServer(target_p);

  if (HasFlag(source_p, FLAGS_SERVICE) || find_matching_name_conf(CONF_SERVICE, target_p->name, NULL, NULL, 0))
    AddFlag(target_p, FLAGS_SERVICE);

  dlinkAdd(target_p, &target_p->node, &global_client_list);
  dlinkAdd(target_p, make_dlink_node(), &global_serv_list);
  dlinkAdd(target_p, &target_p->lnode, &target_p->servptr->serv->server_list);

  hash_add_client(target_p);
  hash_add_id(target_p);

  sendto_server(client_p, CAP_TS6, NOCAPS, ":%s SID %s %d %s :%s%s",
                ID_or_name(source_p, client_p), target_p->name, hop + 1,
                target_p->id, IsHidden(target_p) ? "(H) " : "", target_p->info);
  sendto_server(client_p, NOCAPS, CAP_TS6, ":%s SERVER %s %d :%s%s",
                source_p->name, target_p->name, hop + 1,
                IsHidden(target_p) ? "(H) " : "", target_p->info);

  sendto_realops_flags(UMODE_EXTERNAL, L_ALL, SEND_NOTICE,
                       "Server %s being introduced by %s",
                       target_p->name, source_p->name);
  return 0;
}

static struct Message server_msgtab =
{
  "SERVER", 0, 0, 4, MAXPARA, MFLG_SLOW, 0,
  { mr_server, m_registered, ms_server, m_ignore, m_registered, m_ignore }
};

static struct Message sid_msgtab =
{
  "SID", 0, 0, 5, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_sid, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&sid_msgtab);
  mod_add_cmd(&server_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&sid_msgtab);
  mod_del_cmd(&server_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
