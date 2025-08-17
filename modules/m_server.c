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

#include "comm.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "module.h"

#include "stdinc.h"
#include "channel.h"
#include "client.h"
#include "client_svstag.h"
#include "conf.h"
#include "conf_service.h"
#include "hash.h"
#include "id.h"
#include "ircd.h"
#include "listener.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"
#include "user_mode.h"

typedef enum
{
  SERVER_REJECT_INVALID_NAME,
  SERVER_REJECT_INVALID_SID,
  SERVER_REJECT_INVALID_HOPCOUNT,
  SERVER_REJECT_HOPS_MISMATCH,
  SERVER_REJECT_NAME_MISMATCH,
  SERVER_REJECT_NAME_COLLISION,
  SERVER_REJECT_SID_COLLISION,
  SERVER_REJECT_CONFIG_MISMATCH,
  SERVER_REJECT_HUB_POLICY,
  SERVER_REJECT_LEAF_POLICY,
  SERVER_REJECT_LEAF_LINK_POLICY,
} server_rejection_reason_t;

static const char *const server_rejection_reason_strings[] =
{
  [SERVER_REJECT_INVALID_NAME] = "Invalid server name",
  [SERVER_REJECT_INVALID_SID] = "Invalid server ID",
  [SERVER_REJECT_INVALID_HOPCOUNT] = "Invalid hopcount on connect",
  [SERVER_REJECT_HOPS_MISMATCH] = "Hopcount mismatch in introduction",
  [SERVER_REJECT_NAME_MISMATCH] = "Name mismatch with local configuration",
  [SERVER_REJECT_NAME_COLLISION] = "Server name collision",
  [SERVER_REJECT_SID_COLLISION] = "Server ID collision",
  [SERVER_REJECT_CONFIG_MISMATCH] = "Credential or capability mismatch",
  [SERVER_REJECT_HUB_POLICY] = "Hub policy violation",
  [SERVER_REJECT_LEAF_POLICY] = "Leaf policy violation",
  [SERVER_REJECT_LEAF_LINK_POLICY] = "Leaf link policy violation",
};

typedef struct server_rejection_context
{
  struct Client *exit_client;
  const char *event_source_ip;
  const char *event_source_name;
  const char *reason_str;
  const char *log_prefix;
} server_rejection_context_t;

static void
server_reject_internal(const server_rejection_context_t *ctx, const char *detail_fmt, va_list ap)
{
  char detail_buf[IRCD_BUFSIZE];
  char oper_msg[IRCD_BUFSIZE];
  char exit_msg[IRCD_BUFSIZE];

  vsnprintf(detail_buf, sizeof(detail_buf), detail_fmt, ap);

  snprintf(oper_msg, sizeof(oper_msg), "%s from %s: %s (%s)",
           ctx->log_prefix, ctx->event_source_name, ctx->reason_str, detail_buf);

  snprintf(exit_msg, sizeof(exit_msg), "%s: %s (%s)",
           ctx->log_prefix, ctx->reason_str, detail_buf);

  log_write(LOG_TYPE_IRCD, "%s", oper_msg);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "%s", oper_msg);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE, "%s from %s: %s (%s)",
                 ctx->log_prefix, ctx->event_source_ip, ctx->reason_str, detail_buf);

  client_exit(ctx->exit_client, exit_msg);
}

static void
server_reject_connection(struct Client *source, server_rejection_reason_t reason, const char *detail_fmt, ...)
{
  server_rejection_context_t ctx =
  {
    .exit_client = source,
    .event_source_ip = client_get_name(source, MASK_IP),
    .event_source_name = client_get_name(source, SHOW_IP),
    .reason_str = server_rejection_reason_strings[reason],
    .log_prefix = "Rejecting server link"
  };

  va_list ap;
  va_start(ap, detail_fmt);
  server_reject_internal(&ctx, detail_fmt, ap);
  va_end(ap);
}

static void
server_reject_introduction(struct Client *introducer, server_rejection_reason_t reason, const char *detail_fmt, ...)
{
  server_rejection_context_t ctx =
  {
    .exit_client = introducer->from,
    .event_source_ip = introducer->from->name,
    .event_source_name = introducer->name,
    .reason_str = server_rejection_reason_strings[reason],
    .log_prefix = "Rejecting introduction"
  };

  va_list ap;
  va_start(ap, detail_fmt);
  server_reject_internal(&ctx, detail_fmt, ap);
  va_end(ap);
}

/*! Parses server flags to be potentially set
 * \param client Pointer to server's Client structure
 * \param flags    Pointer to the flag string to be parsed
 */
static void
server_set_flags(struct Client *client, const char *flags)
{
  const unsigned char *p = (const unsigned char *)flags;

  if (*p != '+')
    return;

  while (*++p)
  {
    switch (*p)
    {
      case 'h':
        client_set_flag(client, FLAGS_HIDDEN);
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
 * side effects - NICK message is sent towards given client
 */
static void
server_send_client(struct Client *client, const struct Client *target)
{
  assert(IsClient(target));

  sendto_one(client, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
             target->uplink->id,
             target->name, target->hopcount + 1,
             target->tsinfo, user_mode_to_str(target->umodes),
             target->username, target->host, target->realhost,
             target->sockhost, target->id,
             target->account, target->info);

  if (!string_is_empty(target->tls_certfp))
    sendto_one(client, ":%s CERTFP %s", target->id, target->tls_certfp);

  if (!string_is_empty(target->tls_cipher))
    sendto_one(client, ":%s METADATA client %s cipher :%s",
               target->uplink->id, target->id, target->tls_cipher);

  if (target->away)
    sendto_one(client, ":%s AWAY :%s", target->id, target->away);

  list_node_t *node;
  LIST_FOREACH_PREV(node, target->svstags.tail)
  {
    const struct ServicesTag *svstag = node->data;
    sendto_one(client, ":%s SVSTAG %s %ju %u +%s :%s",
               me.id, target->id, target->tsinfo, svstag->numeric,
               user_mode_to_str(svstag->umodes), svstag->tag);
  }
}

/* burst_all()
 *
 * inputs       - pointer to server to send burst to
 * output       - NONE
 * side effects - complete burst of channels/nicks is sent to client
 */
static void
server_burst(struct Client *client)
{
  list_node_t *node;

  LIST_FOREACH(node, global_client_list.head)
  {
    const struct Client *target = node->data;
    if (target->from != client)
      server_send_client(client, target);
  }

  LIST_FOREACH(node, channel_get_list()->head)
  {
    const struct Channel *channel = node->data;
    assert(list_length(&channel->members));
    if (list_length(&channel->members))
      channel_send_modes(client, channel);
  }

  /* Always send a PING after connect burst is done */
  sendto_one(client, "PING :%s", me.id);
}

/* server_estab()
 *
 * inputs       - pointer to a struct Client
 * output       -
 * side effects -
 */
static void
server_estab(struct Client *client, struct ConnectItem *connect)
{
  if (IsUnknown(client))
  {
    sendto_one(client, "PASS %s", connect->send_password);

    sendto_one(client, "CAPAB :%s", capab_get(NULL, true));

    sendto_one(client, "SERVER %s 1 %s +%s :%s",
               me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);
  }

  sendto_one(client, ":%s SVINFO %u %u 0 :%ju",
             me.id, SERVER_TS_PROTOCOL_CURRENT, SERVER_TS_PROTOCOL_MINIMUM, io_time_get(IO_TIME_REALTIME_SEC));

  if (!IsHandshake(client))
    hash_add_client(client);
  hash_add_id(client);

  SetServer(client);

  server_make(client);
  server_conf_set(client, connect);

  if (service_find(client->name, irccmp))
    client_set_flag(client, FLAGS_SERVICE);

  assert(list_find(&unknown_list, client));
  list_move_node(&client->connection->node, &local_server_list, &unknown_list);

  list_add(client, &client->global_node, &global_server_list);
  list_add(client, &client->uplink_node, &me.serv->child_server_list);

  if ((list_length(&local_client_list) + list_length(&local_server_list)) > Count.max_loc_con)
    Count.max_loc_con = list_length(&local_client_list) + list_length(&local_server_list);

  /* Show the real host/IP to admins */
  if (tls_isusing(&client->connection->fd->tls))
  {
    client->tls_cipher = io_strdup(tls_get_cipher(&client->connection->fd->tls));

    /* Show the real host/IP to admins */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link with %s established: [TLS: %s] (Capabilities: %s)",
                   client_get_name(client, SHOW_IP), client->tls_cipher,
                   capab_get(client, true));

    /* Now show the masked hostname/IP to opers */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link with %s established: [TLS: %s] (Capabilities: %s)",
                   client_get_name(client, MASK_IP), client->tls_cipher,
                   capab_get(client, true));
    log_write(LOG_TYPE_IRCD, "Link with %s established: [TLS: %s] (Capabilities: %s)",
              client_get_name(client, SHOW_IP), client->tls_cipher,
              capab_get(client, true));
  }
  else
  {
    /* Show the real host/IP to admins */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link with %s established: (Capabilities: %s)",
                   client_get_name(client, SHOW_IP), capab_get(client, true));
    /* Now show the masked hostname/IP to opers */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link with %s established: (Capabilities: %s)",
                   client_get_name(client, MASK_IP), capab_get(client, true));
    log_write(LOG_TYPE_IRCD, "Link with %s established: (Capabilities: %s)",
              client_get_name(client, SHOW_IP), capab_get(client, true));
  }

  sendto_servers(client, 0, 0, ":%s SID %s 2 %s +%s :%s",
                 me.id, client->name, client->id, IsHidden(client) ? "h" : "", client->info);

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
    const struct Client *target = node->data;
    /* target->from == target for target == client */
    if (client_is_me(target) || target->from == client)
      continue;

    sendto_one(client, ":%s SID %s %u %s +%s :%s",
               target->uplink->id, target->name, target->hopcount + 1,
               target->id, IsHidden(target) ? "h" : "", target->info);
  }

  server_burst(client);

  if (capab_has_flag(client, CAPAB_EOB))
  {
    LIST_FOREACH_PREV(node, global_server_list.tail)
    {
      const struct Client *target = node->data;
      if (target->from == client)
        continue;

      if (client_is_me(target) || client_has_flag(target, FLAGS_EOB))
        sendto_one(client, ":%s EOB", target->id);
    }
  }
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
  if (listener_has_flag(source->connection->listener, LISTENER_CLIENT))
  {
    client_exit(source, "Use a different port");
    return;
  }

  const char *const name = parv[1];
  if (server_is_valid_name(name) == false)
  {
    server_reject_connection(source, SERVER_REJECT_INVALID_NAME, "'%s'", name);
    return;
  }

  const char *const sid = parv[3];
  if (valid_sid(sid) == false)
  {
    server_reject_connection(source, SERVER_REJECT_INVALID_SID, "'%s'", sid);
    return;
  }

  const int hopcount = atoi(parv[2]);
  if (hopcount != 1)
  {
    server_reject_connection(source, SERVER_REJECT_INVALID_HOPCOUNT, "Expected 1, got %d", hopcount);
    return;
  }

  if (IsHandshake(source) && strcmp(source->name, name))
  {
    server_reject_connection(source, SERVER_REJECT_NAME_MISMATCH, "Presented as '%s', expected '%s'", name, source->name);
    return;
  }

  if (hash_find_server(name))
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
    server_reject_connection(source, SERVER_REJECT_NAME_COLLISION, "'%s'", name);
    return;
  }

  if (hash_find_id(sid))
  {
    server_reject_connection(source, SERVER_REJECT_SID_COLLISION, "'%s'", sid);
    return;
  }

  struct ConnectItem *connect = NULL;
  connect_auth_result_t result = connect_authenticate_server(name, source, &connect);
  if (result != CONNECT_AUTH_SUCCESS)
  {
    const char *reason = connect_auth_result_to_string(result);

    if (result == CONNECT_AUTH_FAIL_NAME && ConfigGeneral.warn_no_connect_block == 0)
      client_exit(source, reason);
    else
      server_reject_connection(source, SERVER_REJECT_CONFIG_MISMATCH, "%s for server '%s'", reason, name);
    return;
  }

  if (ConfigServerInfo.hub == 0 && !list_is_empty(&local_server_list))
  {
    server_reject_connection(source, SERVER_REJECT_LEAF_LINK_POLICY, "Server is configured as a non-hub leaf");
    return;
  }

  if (service_find(name, irccmp) == NULL)
  {
    if ((ConfigChannel.enable_owner == 0) != !capab_has_flag(source, CAPAB_QOP) ||
        (ConfigChannel.enable_admin == 0) != !capab_has_flag(source, CAPAB_AOP))
    {
      server_reject_connection(source, SERVER_REJECT_CONFIG_MISMATCH, "Mismatching AOP/QOP capabilities");
      return;
    }
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  struct Client *const target = hash_find_client(name);
  if (target && (target != source))
    client_exit(target, "Overridden");

  /*
   * If we are connecting (Handshake), we already have the name from the
   * connect{} block in source->name.
   */
  strlcpy(source->name, name, sizeof(source->name));
  strlcpy(source->id, sid, sizeof(source->id));
  strlcpy(source->info, parv[parc - 1], sizeof(source->info));
  source->hopcount = hopcount;

  /* Fixing eob timings.. -gnp */
  source->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
  source->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);

  io_free(source->connection->password);
  source->connection->password = NULL;

  comm_socket_note(source->connection->fd, "Server: %s", source->name);

  server_set_flags(source, parv[4]);
  client_set_class(source, connect->klass, CLIENT_CLASS_BASE);

  server_estab(source, connect);
}

/* ms_sid()
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

  const char *const name = parv[1];
  if (server_is_valid_name(name) == false)
  {
    server_reject_introduction(source, SERVER_REJECT_INVALID_NAME, "'%s'", name);
    return;
  }

  const char *const sid = parv[3];
  if (valid_sid(sid) == false)
  {
    server_reject_introduction(source, SERVER_REJECT_INVALID_SID, "'%s'", sid);
    return;
  }

  const int hopcount = atoi(parv[2]);
  if (hopcount != (int)source->hopcount + 1)
  {
    server_reject_introduction(source, SERVER_REJECT_HOPS_MISMATCH, "Introducer hopcount: %d, New server hopcount: %d",
                               source->hopcount, hopcount);
    return;
  }

  if (hash_find_id(sid))
  {
    server_reject_introduction(source, SERVER_REJECT_SID_COLLISION, "'%s'", sid);
    return;
  }

  if (hash_find_server(name))
  {
    server_reject_introduction(source, SERVER_REJECT_NAME_COLLISION, "'%s'", name);
    return;
  }

  /* XXX If somehow there is a connect in progress and
   * a connect comes in with same name toss the pending one,
   * but only if it's not the same client! - Dianora
   */
  struct Client *target = hash_find_client(name);
  if (target && (target != source->from))
    client_exit(target, "Overridden");

  /*
   * See if the newly found server is behind a guaranteed
   * leaf. If so, close the link.
   */
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

  const struct ConnectItem *const connect = server_conf_get(source->from);
  /* Ok, check source->from can hub the new server */
  if (list_find_cmp(&connect->hub_masks, name, match) == NULL)
  {
    /* OOOPs nope can't HUB */
    server_reject_introduction(source, SERVER_REJECT_HUB_POLICY,
                               "Introducer '%s' is not an authorized hub for '%s'", source->name, name);
    return;
  }

  /* Check for the new server being leafed behind this HUB */
  if (list_find_cmp(&connect->leaf_masks, name, match))
  {
    /* OOOPs nope can't HUB this leaf */
    server_reject_introduction(source, SERVER_REJECT_LEAF_POLICY,
                               "Introduction of '%s' by '%s' denied (server is designated as a leaf)", name, source->name);
    return;
  }

  target = client_create_remote(source);
  server_make(target);
  strlcpy(target->name, name, sizeof(target->name));
  strlcpy(target->id, sid, sizeof(target->id));
  strlcpy(target->info, parv[parc - 1], sizeof(target->info));
  target->hopcount = hopcount;

  SetServer(target);
  server_set_flags(target, parv[4]);

  if (service_find(target->name, irccmp))
    client_set_flag(target, FLAGS_SERVICE);

  list_add(target, &target->global_node, &global_server_list);
  list_add(target, &target->uplink_node, &target->uplink->serv->child_server_list);

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
