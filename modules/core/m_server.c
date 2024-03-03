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

/*! \file m_server.c
 * \brief Includes required functions for processing the SERVER/SID command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "event.h"
#include "hash.h"
#include "id.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "conf_service.h"
#include "listener.h"
#include "log.h"
#include "misc.h"
#include "server.h"
#include "server_capab.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "memory.h"
#include "modules.h"
#include "fdlist.h"
#include "channel.h"


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

/* sendnick_TS()
 *
 * inputs       - client (server) to send nick towards
 *          - client to send nick for
 * output       - NONE
 * side effects - NICK message is sent towards given client_p
 */
static void
server_send_client(struct Client *client_p, struct Client *target_p)
{
  assert(IsClient(target_p));

  sendto_one(client_p, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
             target_p->servptr->id,
             target_p->name, target_p->hopcount + 1,
             target_p->tsinfo, user_get_mode_str(target_p->umodes),
             target_p->username, target_p->host, target_p->realhost,
             target_p->sockhost, target_p->id,
             target_p->account, target_p->info);

  if (!EmptyString(target_p->tls_certfp))
    sendto_one(client_p, ":%s CERTFP %s", target_p->id, target_p->tls_certfp);

  if (!EmptyString(target_p->tls_cipher))
    sendto_one(client_p, ":%s METADATA client %s cipher :%s",
               target_p->servptr->id, target_p->id, target_p->tls_cipher);

  if (target_p->away[0])
    sendto_one(client_p, ":%s AWAY :%s", target_p->id, target_p->away);

  dlink_node *node;
  DLINK_FOREACH_PREV(node, target_p->svstags.tail)
  {
    const struct ServicesTag *svstag = node->data;
    sendto_one(client_p, ":%s SVSTAG %s %ju %u +%s :%s", me.id,
               target_p->id, target_p->tsinfo, svstag->numeric,
               user_get_mode_str(svstag->umodes), svstag->tag);
  }
}

/* burst_all()
 *
 * inputs       - pointer to server to send burst to
 * output       - NONE
 * side effects - complete burst of channels/nicks is sent to client_p
 */
static void
server_burst(struct Client *client_p)
{
  dlink_node *node;

  DLINK_FOREACH(node, global_client_list.head)
  {
    struct Client *target_p = node->data;

    if (target_p->from != client_p)
      server_send_client(client_p, target_p);
  }

  DLINK_FOREACH(node, channel_get_list()->head)
  {
    const struct Channel *channel = node->data;

    assert(dlink_list_length(&channel->members) != 0);
    if (dlink_list_length(&channel->members))
      channel_send_modes(client_p, channel);
  }

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
  xfree(client_p->connection->password);
  client_p->connection->password = NULL;

  if (ConfigServerInfo.hub == 0 && dlink_list_length(&local_server_list))
  {
    ++ServerStats.is_ref;
    exit_client(client_p, "I'm a leaf not a hub");
    return;
  }

  if (IsUnknown(client_p))
  {
    const struct MaskItem *const conf = client_p->connection->confs.head->data;

    sendto_one(client_p, "PASS %s", conf->spasswd);

    sendto_one(client_p, "CAPAB :%s", capab_get(NULL, true));

    sendto_one(client_p, "SERVER %s 1 %s +%s :%s",
               me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);
  }

  sendto_one(client_p, ":%s SVINFO %u %u 0 :%ju", me.id, TS_CURRENT, TS_MINIMUM,
             event_base->time.sec_real);

  SetServer(client_p);
  client_p->servptr = &me;

  dlinkAdd(client_p, &client_p->lnode, &me.serv->server_list);

  assert(dlinkFind(&unknown_list, client_p));
  dlink_move_node(&client_p->connection->node, &unknown_list, &local_server_list);

  dlinkAdd(client_p, &client_p->node, &global_server_list);

  if ((dlink_list_length(&local_client_list) +
       dlink_list_length(&local_server_list)) > Count.max_loc_con)
    Count.max_loc_con = dlink_list_length(&local_client_list) +
                        dlink_list_length(&local_server_list);

  hash_add_client(client_p);
  hash_add_id(client_p);

  /* Doesn't duplicate client_p->serv if allocated this struct already */
  server_make(client_p);

  /* Fixing eob timings.. -gnp */
  client_p->connection->created_monotonic = event_base->time.sec_monotonic;
  client_p->connection->created_real = event_base->time.sec_real;

  if (service_find(client_p->name, irccmp))
    AddFlag(client_p, FLAGS_SERVICE);

  /* Show the real host/IP to admins */
  if (tls_isusing(&client_p->connection->fd->tls))
  {
    client_p->tls_cipher = xstrdup(tls_get_cipher(&client_p->connection->fd->tls));

    /* Show the real host/IP to admins */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link with %s established: [TLS: %s] (Capabilities: %s)",
                         client_get_name(client_p, SHOW_IP), client_p->tls_cipher,
                         capab_get(client_p, true));

    /* Now show the masked hostname/IP to opers */
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link with %s established: [TLS: %s] (Capabilities: %s)",
                         client_get_name(client_p, MASK_IP), client_p->tls_cipher,
                         capab_get(client_p, true));
    log_write(LOG_TYPE_IRCD, "Link with %s established: [TLS: %s] (Capabilities: %s)",
         client_get_name(client_p, SHOW_IP), client_p->tls_cipher,
         capab_get(client_p, true));
  }
  else
  {
    /* Show the real host/IP to admins */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link with %s established: (Capabilities: %s)",
                         client_get_name(client_p, SHOW_IP), capab_get(client_p, true));
    /* Now show the masked hostname/IP to opers */
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link with %s established: (Capabilities: %s)",
                         client_get_name(client_p, MASK_IP), capab_get(client_p, true));
    log_write(LOG_TYPE_IRCD, "Link with %s established: (Capabilities: %s)",
         client_get_name(client_p, SHOW_IP), capab_get(client_p, true));
  }

  fd_note(client_p->connection->fd, "Server: %s", client_p->name);

  sendto_server(client_p, 0, 0, ":%s SID %s 2 %s +%s :%s",
                me.id, client_p->name, client_p->id,
                IsHidden(client_p) ? "h" : "", client_p->info);

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
  dlink_node *node;
  DLINK_FOREACH_PREV(node, global_server_list.tail)
  {
    struct Client *target_p = node->data;

    /* target_p->from == target_p for target_p == client_p */
    if (IsMe(target_p) || target_p->from == client_p)
      continue;

    sendto_one(client_p, ":%s SID %s %u %s +%s :%s",
               target_p->servptr->id, target_p->name, target_p->hopcount+1,
               target_p->id, IsHidden(target_p) ? "h" : "",
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

enum
{
  SERVER_CHECK_OK                  =  0,
  SERVER_CHECK_CONNECT_NOT_FOUND   = -1,
  SERVER_CHECK_INVALID_PASSWORD    = -2,
  SERVER_CHECK_INVALID_HOST        = -3,
  SERVER_CHECK_INVALID_CERTIFICATE = -4,
};

static int
server_check(const char *name, struct Client *client_p)
{
  dlink_node *node;
  int error = SERVER_CHECK_CONNECT_NOT_FOUND;

  assert(client_p);

  /* Loop through looking for all possible connect items that might work */
  DLINK_FOREACH(node, connect_items.head)
  {
    struct MaskItem *conf = node->data;

    if (irccmp(name, conf->name))
      continue;

    error = SERVER_CHECK_INVALID_HOST;

    if (!irccmp(conf->host, client_p->host) ||
        !irccmp(conf->host, client_p->sockhost))
    {
      if (match_conf_password(client_p->connection->password, conf) == false)
        return SERVER_CHECK_INVALID_PASSWORD;

      if (!EmptyString(conf->certfp))
        if (EmptyString(client_p->tls_certfp) || strcasecmp(client_p->tls_certfp, conf->certfp))
          return SERVER_CHECK_INVALID_CERTIFICATE;

      conf_attach(client_p, conf);
      return SERVER_CHECK_OK;
    }
  }

  return error;
}

/* mr_server()
 *  parv[0] = command
 *  parv[1] = servername
 *  parv[2] = hopcount
 *  parv[3] = sid
 *  parv[4] = string of flags starting with '+'
 *  parv[5] = serverinfo
 */
static void
mr_server(struct Client *source_p, int parc, char *parv[])
{
  const char *name = parv[1];
  const char *sid = parv[3];
  const char *error = NULL;
  bool warn = true;

  if (listener_has_flag(source_p->connection->listener, LISTENER_CLIENT))
  {
    exit_client(source_p, "Use a different port");
    return;
  }

  if (server_valid_name(name) == false)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", client_get_name(source_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
          "Unauthorized server connection attempt from %s: Bogus server name "
          "for server %s", client_get_name(source_p, MASK_IP), name);
    exit_client(source_p, "Bogus server name");
    return;
  }

  if (valid_sid(sid) == false)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         client_get_name(source_p, SHOW_IP), sid);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         client_get_name(source_p, MASK_IP), sid);
    exit_client(source_p, "Bogus server ID introduced");
    return;
  }

  if (IsHandshake(source_p) && irccmp(source_p->name, name))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with mismatching server name %s",
                         client_get_name(source_p, SHOW_IP), name);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with mismatching server name %s",
                         client_get_name(source_p, MASK_IP), name);
    exit_client(source_p, "Mismatching server name introduced");
    return;
  }

  /*
   * Now we just have to call server_check() and everything should
   * be checked for us... -A1kmm.
   */
  switch (server_check(name, source_p))
  {
    case SERVER_CHECK_CONNECT_NOT_FOUND:
      error = "No connect {} block";
      warn = ConfigGeneral.warn_no_connect_block != 0;
      break;
    case SERVER_CHECK_INVALID_PASSWORD:
      error = "Invalid password";
      break;
    case SERVER_CHECK_INVALID_HOST:
      error = "Invalid host";
      break;
    case SERVER_CHECK_INVALID_CERTIFICATE:
      error = "Invalid certificate fingerprint";
      break;
  }

  if (error)
  {
    if (warn)
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
         "Unauthorized server connection attempt from %s: %s for server %s",
         client_get_name(source_p, SHOW_IP), error, name);
      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
         "Unauthorized server connection attempt from %s: %s for server %s",
         client_get_name(source_p, MASK_IP), error, name);
    }

    exit_client(source_p, error);
    return;
  }

  if (service_find(name, irccmp) == NULL)
  {
    if ((ConfigChannel.enable_owner == 0) != !IsCapable(source_p, CAPAB_QOP) ||
        (ConfigChannel.enable_admin == 0) != !IsCapable(source_p, CAPAB_AOP))
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                           "Link %s introduced server with mismatching AOP/QOP capabilities",
                           client_get_name(source_p, SHOW_IP));
      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                           "Link %s introduced server with mismatching AOP/QOP capabilities",
                           client_get_name(source_p, MASK_IP));
      exit_client(source_p, "Mismatching AOP/QOP capabilities");
      return;
    }
  }

  struct Client *target_p = hash_find_server(name);
  if (target_p)
  {
    /*
     * This link is trying feed me a server that I already have
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
                         name, client_get_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Attempt to re-introduce server %s from %s",
                         name, client_get_name(source_p, MASK_IP));
    exit_client(source_p, "Server already exists");
    return;
  }

  target_p = hash_find_id(sid);
  if (target_p)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Attempt to re-introduce server %s SID %s from %s",
                         name, sid, client_get_name(source_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Attempt to re-introduce server %s SID %s from %s",
                         name, sid, client_get_name(source_p, MASK_IP));
    exit_client(source_p, "Server ID already exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  target_p = find_servconn_in_progress(name);
  if (target_p && (target_p != source_p))
    exit_client(target_p, "Overridden");

  /*
   * If we are connecting (Handshake), we already have the name from the
   * connect{} block in source_p->name.
   */
  strlcpy(source_p->name, name, sizeof(source_p->name));
  strlcpy(source_p->id, sid, sizeof(source_p->id));
  strlcpy(source_p->info, parv[parc - 1], sizeof(source_p->info));

  server_set_flags(source_p, parv[4]);

  source_p->hopcount = atoi(parv[2]);
  server_estab(source_p);
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
static void
ms_sid(struct Client *source_p, int parc, char *parv[])
{
  /* Just to be sure -A1kmm. */
  if (!IsServer(source_p))
    return;

  if (server_valid_name(parv[1]) == false)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         client_get_name(source_p->from, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server name %s",
                         client_get_name(source_p->from, MASK_IP), parv[1]);
    exit_client(source_p->from, "Bogus server name introduced");
    return;
  }

  if (valid_sid(parv[3]) == false)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         client_get_name(source_p->from, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced server with bogus server ID %s",
                         client_get_name(source_p->from, MASK_IP), parv[3]);
    exit_client(source_p->from, "Bogus server ID introduced");
    return;
  }

  /* Collision on SID? */
  struct Client *target_p = hash_find_id(parv[3]);
  if (target_p)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, server ID %s already exists",
                         client_get_name(source_p->from, SHOW_IP), parv[3]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, server ID %s already exists",
                         client_get_name(source_p->from, MASK_IP), parv[3]);
    exit_client(source_p->from, "Link cancelled, server ID already exists");
    return;
  }

  /* Collision on name? */
  target_p = hash_find_server(parv[1]);
  if (target_p)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         client_get_name(source_p->from, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s cancelled, server %s already exists",
                         client_get_name(source_p->from, MASK_IP), parv[1]);
    exit_client(source_p->from, "Server exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  target_p = find_servconn_in_progress(parv[1]);
  if (target_p && (target_p != source_p->from))
    exit_client(target_p, "Overridden");

  /*
   * See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  const struct MaskItem *conf = source_p->from->connection->confs.head->data;
  bool hlined = dlinkFindCmp(&conf->hub_list , parv[1], match) != NULL;
  bool llined = dlinkFindCmp(&conf->leaf_list, parv[1], match) != NULL;


  /*
   * Ok, this way this works is
   *
   * A server can have a CONF_HUB allowing it to introduce servers
   * behind it.
   *
   * connect {
   *            name = "irc.bighub.net";
   *            hub_mask = "*";
   *            ...
   *
   * That would allow "irc.bighub.net" to introduce anything it wanted..
   *
   * However
   *
   * connect {
   *            name = "irc.somehub.fi";
   *            hub_mask = "*";
   *            leaf_mask = "*.edu";
   *            ...
   *
   * Would allow this server in finland to hub anything but .edu's
   */

  /* Ok, check source_p->from can hub the new server */
  if (hlined == false)
  {
    /* OOOPs nope can't HUB */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         client_get_name(source_p->from, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Non-Hub link %s introduced %s.",
                         client_get_name(source_p->from, MASK_IP), parv[1]);
    exit_client(source_p, "No matching hub_mask.");
    return;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         client_get_name(source_p->from, SHOW_IP), parv[1]);
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Link %s introduced leafed server %s.",
                         client_get_name(source_p->from, MASK_IP), parv[1]);
    exit_client(source_p->from, "Leafed server.");
    return;
  }

  target_p = client_make(source_p->from);
  server_make(target_p);
  target_p->hopcount = atoi(parv[2]);
  target_p->servptr = source_p;

  strlcpy(target_p->name, parv[1], sizeof(target_p->name));
  strlcpy(target_p->id, parv[3], sizeof(target_p->id));
  strlcpy(target_p->info, parv[parc - 1], sizeof(target_p->info));

  server_set_flags(target_p, parv[4]);

  SetServer(target_p);

  if (service_find(target_p->name, irccmp))
    AddFlag(target_p, FLAGS_SERVICE);

  dlinkAdd(target_p, &target_p->node, &global_server_list);
  dlinkAdd(target_p, &target_p->lnode, &target_p->servptr->serv->server_list);

  hash_add_client(target_p);
  hash_add_id(target_p);

  sendto_server(source_p->from, 0, 0, ":%s SID %s %u %s +%s :%s",
                source_p->id, target_p->name, target_p->hopcount + 1,
                target_p->id, IsHidden(target_p) ? "h" : "", target_p->info);
  sendto_realops_flags(UMODE_EXTERNAL, L_ALL, SEND_NOTICE,
                       "Server %s being introduced by %s",
                       target_p->name, source_p->name);
}

static struct Message server_msgtab =
{
  .cmd = "SERVER",
  .handlers[UNREGISTERED_HANDLER] = { .handler = mr_server, .args_min = 6 },
  .handlers[CLIENT_HANDLER] = { .handler = m_registered },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_registered }
};

static struct Message sid_msgtab =
{
  .cmd = "SID",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_sid, .args_min = 6 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
