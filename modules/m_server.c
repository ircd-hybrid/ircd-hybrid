/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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
#include "io_time.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "hash.h"
#include "id.h"
#include "io_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "conf_service.h"
#include "listener.h"
#include "log.h"
#include "misc.h"
#include "server.h"
#include "server_capab.h"
#include "user_mode.h"
#include "send.h"
#include "parse.h"
#include "memory.h"
#include "module.h"
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
server_send_client(struct Client *client_p, struct Client *target)
{
  assert(IsClient(target));

  sendto_one(client_p, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
             target->servptr->id,
             target->name, target->hopcount + 1,
             target->tsinfo, user_mode_to_str(target->umodes),
             target->username, target->host, target->realhost,
             target->sockhost, target->id,
             target->account, target->info);

  if (!string_is_empty(target->tls_certfp))
    sendto_one(client_p, ":%s CERTFP %s", target->id, target->tls_certfp);

  if (!string_is_empty(target->tls_cipher))
    sendto_one(client_p, ":%s METADATA client %s cipher :%s",
               target->servptr->id, target->id, target->tls_cipher);

  if (target->away)
    sendto_one(client_p, ":%s AWAY :%s", target->id, target->away);

  list_node_t *node;
  LIST_FOREACH_PREV(node, target->svstags.tail)
  {
    const struct ServicesTag *svstag = node->data;
    sendto_one(client_p, ":%s SVSTAG %s %ju %u +%s :%s", me.id,
               target->id, target->tsinfo, svstag->numeric,
               user_mode_to_str(svstag->umodes), svstag->tag);
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
  list_node_t *node;

  LIST_FOREACH(node, global_client_list.head)
  {
    struct Client *target = node->data;

    if (target->from != client_p)
      server_send_client(client_p, target);
  }

  LIST_FOREACH(node, channel_get_list()->head)
  {
    const struct Channel *channel = node->data;

    assert(list_length(&channel->members) != 0);
    if (list_length(&channel->members))
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
server_estab(struct Client *client_p, struct MaskItem *conf)
{
  io_free(client_p->connection->password);
  client_p->connection->password = NULL;

  if (ConfigServerInfo.hub == 0 && list_length(&local_server_list))
  {
    ++ServerStats.is_ref;
    client_exit(client_p, "I'm a leaf not a hub");
    return;
  }

  if (IsUnknown(client_p))
  {
    sendto_one(client_p, "PASS %s", conf->spasswd);

    sendto_one(client_p, "CAPAB :%s", capab_get(NULL, true));

    sendto_one(client_p, "SERVER %s 1 %s +%s :%s",
               me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);
  }

  sendto_one(client_p, ":%s SVINFO %u %u 0 :%ju",
             me.id, SERVER_TS_PROTOCOL_CURRENT, SERVER_TS_PROTOCOL_MINIMUM, io_time_get(IO_TIME_REALTIME_SEC));

  SetServer(client_p);
  client_p->servptr = &me;

  list_add(client_p, &client_p->lnode, &me.serv->server_list);

  assert(list_find(&unknown_list, client_p));
  list_move_node(&client_p->connection->node, &unknown_list, &local_server_list);

  list_add(client_p, &client_p->node, &global_server_list);

  if ((list_length(&local_client_list) +
       list_length(&local_server_list)) > Count.max_loc_con)
    Count.max_loc_con = list_length(&local_client_list) +
                        list_length(&local_server_list);

  hash_add_client(client_p);
  hash_add_id(client_p);

  /* Doesn't duplicate client_p->serv if allocated this struct already */
  server_make(client_p);

  server_attach_conf(client_p, conf);

  /* Fixing eob timings.. -gnp */
  client_p->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
  client_p->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);

  if (service_find(client_p->name, irccmp))
    AddFlag(client_p, FLAGS_SERVICE);

  /* Show the real host/IP to admins */
  if (tls_isusing(&client_p->connection->fd->tls))
  {
    client_p->tls_cipher = io_strdup(tls_get_cipher(&client_p->connection->fd->tls));

    /* Show the real host/IP to admins */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link with %s established: [TLS: %s] (Capabilities: %s)",
                   client_get_name(client_p, SHOW_IP), client_p->tls_cipher,
                   capab_get(client_p, true));

    /* Now show the masked hostname/IP to opers */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
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
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link with %s established: (Capabilities: %s)",
                   client_get_name(client_p, SHOW_IP), capab_get(client_p, true));
    /* Now show the masked hostname/IP to opers */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link with %s established: (Capabilities: %s)",
                   client_get_name(client_p, MASK_IP), capab_get(client_p, true));
    log_write(LOG_TYPE_IRCD, "Link with %s established: (Capabilities: %s)",
              client_get_name(client_p, SHOW_IP), capab_get(client_p, true));
  }

  fd_note(client_p->connection->fd, "Server: %s", client_p->name);

  sendto_servers(client_p, 0, 0, ":%s SID %s 2 %s +%s :%s",
                 me.id, client_p->name, client_p->id, IsHidden(client_p) ? "h" : "", client_p->info);

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
  list_node_t *node;
  LIST_FOREACH_PREV(node, global_server_list.tail)
  {
    struct Client *target = node->data;

    /* target->from == target for target == client_p */
    if (IsMe(target) || target->from == client_p)
      continue;

    sendto_one(client_p, ":%s SID %s %u %s +%s :%s",
               target->servptr->id, target->name, target->hopcount + 1,
               target->id, IsHidden(target) ? "h" : "", target->info);
  }

  server_burst(client_p);

  if (capab_has_flag(client_p, CAPAB_EOB))
  {
    LIST_FOREACH_PREV(node, global_server_list.tail)
    {
      struct Client *target = node->data;

      if (target->from == client_p)
        continue;

      if (IsMe(target) || HasFlag(target, FLAGS_EOB))
        sendto_one(client_p, ":%s EOB", target->id);
    }
  }
}

static struct MaskItem *
server_check(const char *name, struct Client *client_p, const char **error_reason, bool *warn_opers)
{
  bool name_match_found = false;

  *warn_opers = true;
  *error_reason = "No connect{} block found for server";

  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct MaskItem *const conf = node->data;
    assert(conf->type == CONF_SERVER);

    if (irccmp(name, conf->name))
      continue;

    name_match_found = true;

    if (irccmp(conf->host, client_p->host) && irccmp(conf->host, client_p->sockhost))
    {
      *error_reason = "Invalid host";
      continue;
    }

    if (conf_match_password(client_p->connection->password, conf) == false)
    {
      *error_reason = "Invalid password";
      continue;
    }

    if (!string_is_empty(conf->certfp))
    {
      if (string_is_empty(client_p->tls_certfp) || strcasecmp(client_p->tls_certfp, conf->certfp))
      {
        *error_reason = "Invalid certificate fingerprint";
        continue;
      }
    }

    *error_reason = NULL;
    return conf;
  }

  if (name_match_found == false)
    *warn_opers = ConfigGeneral.warn_no_connect_block != 0;

  return NULL;
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
mr_server(struct Client *source, int parc, char *parv[])
{
  const char *name = parv[1];
  const char *sid = parv[3];

  if (listener_has_flag(source->connection->listener, LISTENER_CLIENT))
  {
    client_exit(source, "Use a different port");
    return;
  }

  if (server_valid_name(name) == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Unauthorized server connection attempt from %s: Bogus server name for server %s",
                   client_get_name(source, SHOW_IP), name);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Unauthorized server connection attempt from %s: Bogus server name for server %s",
                   client_get_name(source, MASK_IP), name);
    client_exit(source, "Bogus server name");
    return;
  }

  if (valid_sid(sid) == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s introduced server with bogus server ID %s",
                   client_get_name(source, SHOW_IP), sid);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s introduced server with bogus server ID %s",
                   client_get_name(source, MASK_IP), sid);
    client_exit(source, "Bogus server ID introduced");
    return;
  }

  if (IsHandshake(source) && irccmp(source->name, name))
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s introduced server with mismatching server name %s",
                   client_get_name(source, SHOW_IP), name);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s introduced server with mismatching server name %s",
                   client_get_name(source, MASK_IP), name);
    client_exit(source, "Mismatching server name introduced");
    return;
  }

  const char *error;
  bool warn_opers;
  struct MaskItem *const conf = server_check(name, source, &error, &warn_opers);
  if (conf == NULL)
  {
    if (warn_opers)
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                     "Unauthorized server connection attempt from %s: %s for server %s",
                     client_get_name(source, SHOW_IP), error, name);
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                     "Unauthorized server connection attempt from %s: %s for server %s",
                     client_get_name(source, MASK_IP), error, name);
    }

    client_exit(source, error);
    return;
  }

  if (service_find(name, irccmp) == NULL)
  {
    if ((ConfigChannel.enable_owner == 0) != !capab_has_flag(source, CAPAB_QOP) ||
        (ConfigChannel.enable_admin == 0) != !capab_has_flag(source, CAPAB_AOP))
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                     "Link %s introduced server with mismatching AOP/QOP capabilities",
                     client_get_name(source, SHOW_IP));
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                     "Link %s introduced server with mismatching AOP/QOP capabilities",
                     client_get_name(source, MASK_IP));
      client_exit(source, "Mismatching AOP/QOP capabilities");
      return;
    }
  }

  struct Client *target = hash_find_server(name);
  if (target)
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
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Attempt to re-introduce server %s from %s",
                   name, client_get_name(source, SHOW_IP));
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Attempt to re-introduce server %s from %s",
                   name, client_get_name(source, MASK_IP));
    client_exit(source, "Server already exists");
    return;
  }

  target = hash_find_id(sid);
  if (target)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Attempt to re-introduce server %s SID %s from %s",
                   name, sid, client_get_name(source, SHOW_IP));
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Attempt to re-introduce server %s SID %s from %s",
                   name, sid, client_get_name(source, MASK_IP));
    client_exit(source, "Server ID already exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  target = find_servconn_in_progress(name);
  if (target && (target != source))
    client_exit(target, "Overridden");

  /*
   * If we are connecting (Handshake), we already have the name from the
   * connect{} block in source->name.
   */
  strlcpy(source->name, name, sizeof(source->name));
  strlcpy(source->id, sid, sizeof(source->id));
  strlcpy(source->info, parv[parc - 1], sizeof(source->info));

  server_set_flags(source, parv[4]);

  source->hopcount = atoi(parv[2]);

  client_set_class(source, conf->class, CLIENT_CLASS_BASE);

  server_estab(source, conf);
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
ms_sid(struct Client *source, int parc, char *parv[])
{
  /* Just to be sure -A1kmm. */
  if (!IsServer(source))
    return;

  if (server_valid_name(parv[1]) == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s introduced server with bogus server name %s",
                   client_get_name(source->from, SHOW_IP), parv[1]);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s introduced server with bogus server name %s",
                   client_get_name(source->from, MASK_IP), parv[1]);
    client_exit(source->from, "Bogus server name introduced");
    return;
  }

  if (valid_sid(parv[3]) == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s introduced server with bogus server ID %s",
                   client_get_name(source->from, SHOW_IP), parv[3]);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s introduced server with bogus server ID %s",
                   client_get_name(source->from, MASK_IP), parv[3]);
    client_exit(source->from, "Bogus server ID introduced");
    return;
  }

  /* Collision on SID? */
  struct Client *target = hash_find_id(parv[3]);
  if (target)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s cancelled, server ID %s already exists",
                   client_get_name(source->from, SHOW_IP), parv[3]);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s cancelled, server ID %s already exists",
                   client_get_name(source->from, MASK_IP), parv[3]);
    client_exit(source->from, "Link cancelled, server ID already exists");
    return;
  }

  /* Collision on name? */
  target = hash_find_server(parv[1]);
  if (target)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s cancelled, server %s already exists",
                   client_get_name(source->from, SHOW_IP), parv[1]);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s cancelled, server %s already exists",
                   client_get_name(source->from, MASK_IP), parv[1]);
    client_exit(source->from, "Server exists");
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  target = find_servconn_in_progress(parv[1]);
  if (target && (target != source->from))
    client_exit(target, "Overridden");

  /*
   * See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
  const struct MaskItem *const conf = source->serv->conf;
  bool hlined = list_find_cmp(&conf->hub_list , parv[1], match) != NULL;
  bool llined = list_find_cmp(&conf->leaf_list, parv[1], match) != NULL;


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

  /* Ok, check source->from can hub the new server */
  if (hlined == false)
  {
    /* OOOPs nope can't HUB */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Non-Hub link %s introduced %s.",
                   client_get_name(source->from, SHOW_IP), parv[1]);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Non-Hub link %s introduced %s.",
                   client_get_name(source->from, MASK_IP), parv[1]);
    client_exit(source, "No matching hub_mask.");
    return;
  }

  /* Check for the new server being leafed behind this HUB */
  if (llined)
  {
    /* OOOPs nope can't HUB this leaf */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link %s introduced leafed server %s.",
                   client_get_name(source->from, SHOW_IP), parv[1]);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link %s introduced leafed server %s.",
                   client_get_name(source->from, MASK_IP), parv[1]);
    client_exit(source->from, "Leafed server.");
    return;
  }

  target = client_make(source->from);
  server_make(target);
  target->hopcount = atoi(parv[2]);
  target->servptr = source;

  strlcpy(target->name, parv[1], sizeof(target->name));
  strlcpy(target->id, parv[3], sizeof(target->id));
  strlcpy(target->info, parv[parc - 1], sizeof(target->info));

  server_set_flags(target, parv[4]);

  SetServer(target);

  if (service_find(target->name, irccmp))
    AddFlag(target, FLAGS_SERVICE);

  list_add(target, &target->node, &global_server_list);
  list_add(target, &target->lnode, &target->servptr->serv->server_list);

  hash_add_client(target);
  hash_add_id(target);

  sendto_servers(source->from, 0, 0, ":%s SID %s %u %s +%s :%s",
                 source->id, target->name, target->hopcount + 1, target->id, IsHidden(target) ? "h" : "", target->info);
  sendto_clients(UMODE_EXTERNAL, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Server %s being introduced by %s",
                 target->name, source->name);
}

static struct Command command_table[] =
{
  [0] = {
    .name = "SERVER",
    .handlers[UNREGISTERED_HANDLER] = { .handler = mr_server, .args_min = 6 },
    .handlers[CLIENT_HANDLER] = { .handler = m_registered },
    .handlers[SERVER_HANDLER] = { .handler = m_ignore },
    .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
    .handlers[OPER_HANDLER] = { .handler = m_registered }
  },
  [1] = {
    .name = "SID",
    .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
    .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
    .handlers[SERVER_HANDLER] = { .handler = ms_sid, .args_min = 6 },
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
