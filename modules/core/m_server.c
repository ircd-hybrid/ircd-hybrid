/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file m_server.c
 * \brief Includes required functions for processing the SERVER/SID command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "event.h"
#include "hash.h"
#include "id.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "conf_service.h"
#include "log.h"
#include "misc.h"
#include "server.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "memory.h"
#include "modules.h"


/*! Parses server flags to be potentially set
 * \param client_p Pointer to server's Client structure
 * \param flags    Pointer to the flag string to be parsed
 */
static void
server_set_flags(struct Client *client_p, const char *flags)
{
  const unsigned char *p = (const unsigned char *)flags;

  if (*p != '+')
    return;

  while (*++p)
  {
    switch (*p)
    {
      case 'h':
        AddFlag(client_p, FLAGS_HIDDEN);
        break;
      default:
        break;
    }
  }
}

/*
 * send_tb
 *
 * inputs       - pointer to Client
 *              - pointer to channel
 * output       - NONE
 * side effects - Called on a server burst when
 *                server is CAPAB_TBURST capable
 */
static void
send_tb(struct Client *client_p, const struct Channel *chptr)
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
  if (chptr->topic_time)
    sendto_one(client_p, ":%s TBURST %ju %s %ju %s :%s", me.id,
               chptr->creationtime, chptr->name,
               chptr->topic_time,
               chptr->topic_info,
               chptr->topic);
}

/* sendnick_TS()
 *
 * inputs       - client (server) to send nick towards
 *          - client to send nick for
 * output       - NONE
 * side effects - NICK message is sent towards given client_p
 */
static void
sendnick_TS(struct Client *client_p, struct Client *target_p)
{
  dlink_node *node = NULL;
  char ubuf[IRCD_BUFSIZE] = "";

  if (!IsClient(target_p))
    return;

  send_umode(NULL, target_p, 0, ubuf);

  if (ubuf[0] == '\0')
  {
    ubuf[0] = '+';
    ubuf[1] = '\0';
  }

  sendto_one(client_p, ":%s UID %s %u %ju %s %s %s %s %s %s :%s",
             target_p->servptr->id,
             target_p->name, target_p->hopcount + 1,
             target_p->tsinfo,
             ubuf, target_p->username, target_p->host,
             target_p->sockhost, target_p->id,
             target_p->account, target_p->info);

  if (!EmptyString(target_p->certfp))
    sendto_one(client_p, ":%s CERTFP %s", target_p->id, target_p->certfp);

  if (target_p->away[0])
    sendto_one(client_p, ":%s AWAY :%s", target_p->id, target_p->away);


  DLINK_FOREACH(node, target_p->svstags.head)
  {
    const struct ServicesTag *svstag = node->data;
    char *m = ubuf;

    for (const struct user_modes *tab = umode_tab; tab->c; ++tab)
      if (svstag->umodes & tab->flag)
        *m++ = tab->c;
    *m = '\0';

    sendto_one(client_p, ":%s SVSTAG %s %ju %u +%s :%s", me.id, target_p->id,
               target_p->tsinfo, svstag->numeric, ubuf, svstag->tag);
  }
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
  struct Membership *member;
  dlink_node *node = NULL;

  DLINK_FOREACH(node, chptr->members.head)
  {
    member   = node->data;
    target_p = member->client_p;

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
  dlink_node *node = NULL;

  DLINK_FOREACH(node, channel_list.head)
  {
    struct Channel *chptr = node->data;

    if (dlink_list_length(&chptr->members))
    {
      burst_members(client_p, chptr);
      channel_send_modes(client_p, chptr);

      if (IsCapable(client_p, CAPAB_TBURST))
        send_tb(client_p, chptr);
    }
  }

  /* also send out those that are not on any channel
   */
  DLINK_FOREACH(node, global_client_list.head)
  {
    struct Client *target_p = node->data;

    if (!HasFlag(target_p, FLAGS_BURSTED) && target_p->from != client_p)
      sendnick_TS(client_p, target_p);

    DelFlag(target_p, FLAGS_BURSTED);
  }
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
  sendto_one(client_p, "PING :%s", me.id);
}

/* server_estab()
 *
 * inputs       - pointer to a struct Client
 * output       -
 * side effects -
 */
static void
server_estab(struct Client *client_p)
{
  struct MaskItem *conf = NULL;
  dlink_node *node = NULL;

  if ((conf = find_conf_name(&client_p->connection->confs, client_p->name, CONF_SERVER)) == NULL)
  {
    /* This shouldn't happen, better tell the ops... -A1kmm */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Warning: lost connect{} block for %s",
                         get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Warning: lost connect{} block for %s",
                         get_client_name(client_p, MASK_IP));
    exit_client(client_p, "Lost connect{} block!");
    return;
  }

  xfree(client_p->connection->password);
  client_p->connection->password = NULL;

  if (!ConfigServerInfo.hub && dlink_list_length(&local_server_list))
  {
    ++ServerStats.is_ref;
    exit_client(client_p, "I'm a leaf not a hub");
    return;
  }

  if (IsUnknown(client_p))
  {
    sendto_one(client_p, "PASS %s TS %u %s", conf->spasswd, TS_CURRENT, me.id);

    send_capabilities(client_p);

    sendto_one(client_p, "SERVER %s 1 :%s%s",
               me.name, ConfigServerHide.hidden ? "(H) " : "", me.info);
  }

  sendto_one(client_p, ":%s SVINFO %u %u 0 :%ju", me.id, TS_CURRENT, TS_MIN,
             CurrentTime);

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

  if (HasFlag(client_p, FLAGS_CLOSING))
    return;

  SetServer(client_p);

  /* Some day, all these lists will be consolidated *sigh* */
  dlinkAdd(client_p, &client_p->lnode, &me.serv->server_list);

  assert(dlinkFind(&unknown_list, client_p));

  dlink_move_node(&client_p->connection->lclient_node,
                  &unknown_list, &local_server_list);

  Count.myserver++;

  dlinkAdd(client_p, &client_p->node, &global_client_list);
  dlinkAdd(client_p, make_dlink_node(), &global_server_list);
  hash_add_client(client_p);
  hash_add_id(client_p);

  /* Doesn't duplicate client_p->serv if allocated this struct already */
  make_server(client_p);

  /* Fixing eob timings.. -gnp */
  client_p->connection->firsttime = CurrentTime;

  if (service_find(client_p->name))
    AddFlag(client_p, FLAGS_SERVICE);

  /* Show the real host/IP to admins */
  if (tls_isusing(&client_p->connection->fd.ssl))
  {
    /* Show the real host/IP to admins */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link with %s established: [TLS: %s] (Capabilities: %s)",
                         get_client_name(client_p, SHOW_IP), tls_get_cipher(&client_p->connection->fd.ssl),
                         show_capabilities(client_p));

    /* Now show the masked hostname/IP to opers */
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link with %s established: [TLS: %s] (Capabilities: %s)",
                         get_client_name(client_p, MASK_IP), tls_get_cipher(&client_p->connection->fd.ssl),
                         show_capabilities(client_p));
    ilog(LOG_TYPE_IRCD, "Link with %s established: [TLS: %s] (Capabilities: %s)",
         get_client_name(client_p, SHOW_IP), tls_get_cipher(&client_p->connection->fd.ssl),
         show_capabilities(client_p));
  }
  else
  {
    /* Show the real host/IP to admins */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link with %s established: (Capabilities: %s)",
                         get_client_name(client_p, SHOW_IP), show_capabilities(client_p));
    /* Now show the masked hostname/IP to opers */
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link with %s established: (Capabilities: %s)",
                         get_client_name(client_p, MASK_IP), show_capabilities(client_p));
    ilog(LOG_TYPE_IRCD, "Link with %s established: (Capabilities: %s)",
         get_client_name(client_p, SHOW_IP), show_capabilities(client_p));
  }

  fd_note(&client_p->connection->fd, "Server: %s", client_p->name);

  sendto_server(client_p, 0, 0, ":%s SID %s 2 %s :%s%s",
                me.id, client_p->name, client_p->id,
                IsHidden(client_p) ? "(H) " : "", client_p->info);

  /*
   * Pass on my client information to the new server
   *
   * First, pass only servers (idea is that if the link gets
   * cancelled beacause the server was already there,
   * there are no NICK's to be cancelled...). Of course,
   * if cancellation occurs, all this info is sent anyway,
   * and I guess the link dies when a read is attempted...? --msa
   *
   * Note: Link cancellation to occur at this point means
   * that at least two servers from my fragment are building
   * up connection this other fragment at the same time, it's
   * a race condition, not the normal way of operation...
   */
  DLINK_FOREACH_PREV(node, global_server_list.tail)
  {
    struct Client *target_p = node->data;

    /* target_p->from == target_p for target_p == client_p */
    if (IsMe(target_p) || target_p->from == client_p)
      continue;

    sendto_one(client_p, ":%s SID %s %u %s :%s%s",
               target_p->servptr->id, target_p->name, target_p->hopcount+1,
               target_p->id, IsHidden(target_p) ? "(H) " : "",
               target_p->info);
  }

  server_burst(client_p);

  if (IsCapable(client_p, CAPAB_EOB))
  {
    DLINK_FOREACH_PREV(node, global_server_list.tail)
    {
      struct Client *target_p = node->data;

      if (target_p->from == client_p)
        continue;

      if (IsMe(target_p) || HasFlag(target_p, FLAGS_EOB))
        sendto_one(client_p, ":%s EOB", target_p->id);
    }
  }
}

/* set_server_gecos()
 *
 * input        - pointer to client
 * output       - NONE
 * side effects - servers gecos field is set
 */
static void
server_set_gecos(struct Client *client_p, const char *info)
{
  const char *s = info;

  /* check for (H) which is a hidden server */
  if (!strncmp(s, "(H) ", 4))
  {
    AddFlag(client_p, FLAGS_HIDDEN);
    s = s + 4;
  }

  if (!EmptyString(s))
    strlcpy(client_p->info, s, sizeof(client_p->info));
  else
    strlcpy(client_p->info, "(Unknown Location)", sizeof(client_p->info));
}

/* mr_server()
 *  parv[0] = command
 *  parv[1] = servername
 *  parv[2] = hopcount
 *  parv[3] = serverinfo
 *
 * 8.3.x+:
 *  parv[0] = command
 *  parv[1] = servername
 *  parv[2] = hopcount
 *  parv[3] = sid
 *  parv[4] = string of flags starting with '+'
 *  parv[5] = serverinfo
 */
static int
mr_server(struct Client *source_p, int parc, char *parv[])
{
  const char *name = parv[1];
  const char *sid = parc == 6 ? parv[3] : source_p->id; /* TBR: compatibility 'mode' */
  struct Client *target_p = NULL;

  if (EmptyString(parv[parc - 1]))
  {
    exit_client(source_p, "No server description supplied");
    return 0;
  }

  if (!valid_servname(name))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", get_client_name(source_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", get_client_name(source_p, MASK_IP), name);
    exit_client(source_p, "Bogus server name");
    return 0;
  }

  if (!valid_sid(sid))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(source_p, SHOW_IP), sid);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(source_p, MASK_IP), sid);
    exit_client(source_p, "Bogus server ID introduced");
    return 0;
  }

  /* Now we just have to call check_server and everything should
   * be check for us... -A1kmm.
   */
  switch (check_server(name, source_p))
  {
    case -1:
      if (ConfigGeneral.warn_no_connect_block)
      {
        sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: No entry for "
           "servername %s", get_client_name(source_p, SHOW_IP), name);

        sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: No entry for "
           "servername %s", get_client_name(source_p, MASK_IP), name);
      }

      exit_client(source_p, "No connect {} block.");
      return 0;
      /* NOT REACHED */
      break;

    case -2:
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Bad password "
           "for server %s", get_client_name(source_p, SHOW_IP), name);

      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Bad password "
           "for server %s", get_client_name(source_p, MASK_IP), name);

      exit_client(source_p, "Invalid password.");
      return 0;
      /* NOT REACHED */
      break;

    case -3:
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid host "
           "for server %s", get_client_name(source_p, SHOW_IP), name);

      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid host "
           "for server %s", get_client_name(source_p, MASK_IP), name);

      exit_client(source_p, "Invalid host.");
      return 0;
    case -4:
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid certificate fingerprint "
           "for server %s", get_client_name(source_p, SHOW_IP), name);

      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
           "Unauthorized server connection attempt from %s: Invalid certificate fingerprint "
           "for server %s", get_client_name(source_p, MASK_IP), name);

      exit_client(source_p, "Invalid certificate fingerprint.");
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
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Attempt to re-introduce server %s from %s",
                         name, get_client_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Attempt to re-introduce server %s from %s",
                         name, get_client_name(source_p, MASK_IP));
    exit_client(source_p, "Server already exists");
    return 0;
  }

  if ((target_p = hash_find_id(source_p->id)))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Attempt to re-introduce server %s SID %s from %s",
                         name, source_p->id,
                         get_client_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Attempt to re-introduce server %s SID %s from %s",
                         name, source_p->id,
                         get_client_name(source_p, MASK_IP));
    exit_client(source_p, "Server ID already exists");
    return 0;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(name)))
    if (target_p != source_p)
      exit_client(target_p, "Overridden");

  /* if we are connecting (Handshake), we already have the name from the
   * connect{} block in source_p->name
   */
  strlcpy(source_p->name, name, sizeof(source_p->name));

  if (parc == 6)  /* TBR: compatibility 'mode' */
  {
    strlcpy(source_p->id, sid, sizeof(source_p->id));
    strlcpy(source_p->info, parv[parc - 1], sizeof(source_p->info));
    server_set_flags(source_p, parv[4]);
  }
  else
    server_set_gecos(source_p, parv[parc - 1]);

  source_p->hopcount = atoi(parv[2]);
  server_estab(source_p);
  return 0;
}

/* ms_sid()
 *  parv[0] = command
 *  parv[1] = servername
 *  parv[2] = hopcount
 *  parv[3] = sid of new server
 *  parv[4] = serverinfo
 *
 * 8.3.x+:
 *  parv[0] = command
 *  parv[1] = servername
 *  parv[2] = hopcount
 *  parv[3] = sid of new server
 *  parv[4] = string of flags starting with '+'
 *  parv[5] = serverinfo
 */
static int
ms_sid(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *node = NULL;
  struct Client *target_p = NULL;
  struct Client *client_p = source_p->from; /* XXX */
  const struct MaskItem *conf = NULL;
  int hlined = 0;
  int llined = 0;

  /* Just to be sure -A1kmm. */
  if (!IsServer(source_p))
    return 0;

  if (EmptyString(parv[parc - 1]))
  {
    exit_client(client_p, "No server description supplied");
    return 0;
  }

  if (!valid_servname(parv[1]))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(client_p, "Bogus server name introduced");
    return 0;
  }

  if (!valid_sid(parv[3]))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(client_p, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         get_client_name(client_p, MASK_IP), parv[3]);
    exit_client(client_p, "Bogus server ID introduced");
    return 0;
  }

  /* collision on SID? */
  if ((target_p = hash_find_id(parv[3])))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, server ID %s already exists",
                         get_client_name(client_p, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, server ID %s already exists",
                         get_client_name(client_p, MASK_IP), parv[3]);
    exit_client(client_p, "Link cancelled, server ID already exists");
    return 0;
  }

  /* collision on name? */
  if ((target_p = hash_find_server(parv[1])))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(client_p, "Server exists");
    return 0;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  if ((target_p = find_servconn_in_progress(parv[1])))
    if (target_p != client_p)
      exit_client(target_p, "Overridden");

  conf = client_p->connection->confs.head->data;

  /* See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  DLINK_FOREACH(node, conf->leaf_list.head)
  {
    if (!match(node->data, parv[1]))
    {
      llined = 1;
      break;
    }
  }

  DLINK_FOREACH(node, conf->hub_list.head)
  {
    if (!match(node->data, parv[1]))
    {
      hlined = 1;
      break;
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
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(source_p, "No matching hub_mask.");
    return 0;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         get_client_name(client_p, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         get_client_name(client_p, MASK_IP), parv[1]);
    exit_client(client_p, "Leafed server.");
    return 0;
  }

  target_p = make_client(client_p);
  make_server(target_p);
  target_p->hopcount = atoi(parv[2]);
  target_p->servptr = source_p;

  strlcpy(target_p->name, parv[1], sizeof(target_p->name));
  strlcpy(target_p->id, parv[3], sizeof(target_p->id));

  if (parc == 6)  /* TBR: compatibility 'mode' */
  {
    strlcpy(target_p->info, parv[parc - 1], sizeof(target_p->info));
    server_set_flags(target_p, parv[4]);
  }
  else
    server_set_gecos(target_p, parv[parc - 1]);

  SetServer(target_p);

  if (service_find(target_p->name))
    AddFlag(target_p, FLAGS_SERVICE);

  dlinkAdd(target_p, &target_p->node, &global_client_list);
  dlinkAdd(target_p, make_dlink_node(), &global_server_list);
  dlinkAdd(target_p, &target_p->lnode, &target_p->servptr->serv->server_list);

  hash_add_client(target_p);
  hash_add_id(target_p);

  sendto_server(client_p, 0, 0, ":%s SID %s %u %s :%s%s",
                source_p->id, target_p->name, target_p->hopcount + 1,
                target_p->id, IsHidden(target_p) ? "(H) " : "", target_p->info);
  sendto_realops_flags(UMODE_EXTERNAL, L_ALL, SEND_NOTICE,
                       "Server %s being introduced by %s",
                       target_p->name, source_p->name);
  return 0;
}

static struct Message server_msgtab =
{
  .cmd = "SERVER",
  .args_min = 4,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = mr_server,
  .handlers[CLIENT_HANDLER] = m_registered,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_registered
};

static struct Message sid_msgtab =
{
  .cmd = "SID",
  .args_min = 5,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_ignore,
  .handlers[CLIENT_HANDLER] = m_ignore,
  .handlers[SERVER_HANDLER] = ms_sid,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = m_ignore
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
