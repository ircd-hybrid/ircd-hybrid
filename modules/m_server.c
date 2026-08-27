/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_server.c
 * \brief Includes required functions for processing the SERVER/SID command.
 */

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comm.h"
#include "io_parse.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "module.h"

#include "channel.h"
#include "client.h"
#include "client_find.h"
#include "client_format.h"
#include "client_id.h"
#include "client_svstag.h"
#include "conf.h"
#include "conf_service.h"
#include "hash.h"
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
  [SERVER_REJECT_INVALID_HOPCOUNT] = "Invalid hopcount",
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
  struct Client *const exit_client;
  const char *const admin_event_source;
  const char *const oper_event_source;
  const char *const log_event_source;
  const char *const event_text;
  const char *const reason_text;
} server_rejection_context_t;

static void
_server_reject_internal(const server_rejection_context_t *ctx, const char *detail_fmt, va_list args)
{
  char detail[IRCD_BUFSIZE];

  vsnprintf(detail, sizeof(detail), detail_fmt, args);

  log_write(LOG_TYPE_IRCD, "%s from %s: %s (%s)",
            ctx->event_text, ctx->log_event_source, ctx->reason_text, detail);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                 "%s from %s: %s (%s)",
                 ctx->event_text, ctx->admin_event_source, ctx->reason_text, detail);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                 "%s from %s: %s (%s)",
                 ctx->event_text, ctx->oper_event_source, ctx->reason_text, detail);

  client_exit_fmt(ctx->exit_client, "%s: %s (%s)",
                  ctx->event_text, ctx->reason_text, detail);
}

static void
_server_reject_connection(struct Client *source, server_rejection_reason_t reason, const char *detail_fmt, ...)
{
  client_format_name_buffer_t admin_event_source_buffer;
  client_format_name_buffer_t oper_event_source_buffer;
  client_format_name_buffer_t log_event_source_buffer;

  const char *const admin_event_source =
    client_format_name(source, CLIENT_FORMAT_NAME_ADMIN, &admin_event_source_buffer);
  const char *const oper_event_source =
    client_format_name(source, CLIENT_FORMAT_NAME_OPER, &oper_event_source_buffer);
  const char *const log_event_source =
    client_format_name(source, CLIENT_FORMAT_NAME_LOG, &log_event_source_buffer);

  const server_rejection_context_t ctx =
  {
    .exit_client = source,
    .admin_event_source = admin_event_source,
    .oper_event_source = oper_event_source,
    .log_event_source = log_event_source,
    .event_text = "Server link rejected",
    .reason_text = server_rejection_reason_strings[reason]
  };

  va_list args;
  va_start(args, detail_fmt);
  _server_reject_internal(&ctx, detail_fmt, args);
  va_end(args);
}

static void
_server_reject_format_introduction_event_source(const struct Client *introducer,
                                                enum client_format_name link_name_format,
                                                char *event_source, size_t event_source_size)
{
  client_format_name_buffer_t link_name_buffer;
  const char *const link_name =
    client_format_name(introducer->nexthop, link_name_format, &link_name_buffer);

  if (introducer == introducer->nexthop)
    strlcpy(event_source, link_name, event_source_size);
  else
    snprintf(event_source, event_source_size, "%s via %s",
             introducer->name, link_name);
}

static void
_server_reject_introduction(struct Client *introducer, server_rejection_reason_t reason, const char *detail_fmt, ...)
{
  char admin_event_source[IRCD_BUFSIZE];
  char oper_event_source[IRCD_BUFSIZE];
  char log_event_source[IRCD_BUFSIZE];

  _server_reject_format_introduction_event_source(introducer, CLIENT_FORMAT_NAME_ADMIN,
                                                  admin_event_source, sizeof(admin_event_source));
  _server_reject_format_introduction_event_source(introducer, CLIENT_FORMAT_NAME_OPER,
                                                  oper_event_source, sizeof(oper_event_source));
  _server_reject_format_introduction_event_source(introducer, CLIENT_FORMAT_NAME_LOG,
                                                  log_event_source, sizeof(log_event_source));

  const server_rejection_context_t ctx =
  {
    .exit_client = introducer->nexthop,
    .admin_event_source = admin_event_source,
    .oper_event_source = oper_event_source,
    .log_event_source = log_event_source,
    .event_text = "Server introduction rejected",
    .reason_text = server_rejection_reason_strings[reason]
  };

  va_list ap;
  va_start(ap, detail_fmt);
  _server_reject_internal(&ctx, detail_fmt, ap);
  va_end(ap);
}

/*! Parses server flags to be potentially set
 * \param client Pointer to server's Client structure
 * \param flags    Pointer to the flag string to be parsed
 */
static void
_server_set_flags(struct Client *client, const char *flags)
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

static void
_server_burst_send_client(struct Client *client, const struct Client *target)
{
  assert(client_is_user(target));

  sendto_one(client, ":%s UID %s %u %ju %s %s %s %s %s %s %s :%s",
             target->uplink->id,
             target->name, target->hopcount + 1,
             target->nick_timestamp, user_mode_to_str(target->user_mode_flags),
             target->username, target->host, target->realhost,
             target->sockhost, target->id,
             target->account, target->info);

  if (!string_is_empty(target->tls_certfp))
    sendto_one(client, ":%s CERTFP %s", target->id, target->tls_certfp);

  if (!string_is_empty(target->tls_cipher))
    sendto_one(client, ":%s METADATA client %s cipher :%s",
               target->uplink->id, target->id, target->tls_cipher);

  if (target->away_message)
    sendto_one(client, ":%s AWAY :%s", target->id, target->away_message);

  list_node_t *node;
  LIST_FOREACH(node, target->svstag_list.head)
  {
    const struct ServicesTag *const svstag = node->data;
    sendto_one(client, ":%s SVSTAG %s 0 %u + :%s",
               me.id, target->id, RPL_WHOISOPERATOR, svstag->text);
  }
}

static void
_server_establish_send_handshake(struct Client *client, const struct ConnectItem *connect)
{
  assert(client && client_is_local(client));
  assert(client_is_unknown(client) || client_is_handshake(client));
  assert(connect);

  if (client_is_unknown(client))
  {
    sendto_one(client, "PASS %s", connect->send_password);
    sendto_one(client, "CAPAB :%s", capab_get(NULL, true));
    sendto_one(client, "SERVER %s 1 %s +%s :%s",
               me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);
  }

  sendto_one(client, ":%s SVINFO %u %u 0 :%ju",
             me.id, SERVER_TS_PROTOCOL_CURRENT, SERVER_TS_PROTOCOL_MINIMUM, io_time_get(IO_TIME_REALTIME_SEC));
}

static void
_server_establish_finalize_local(struct Client *client, struct ConnectItem *connect)
{
  assert(client && client_is_local(client));
  assert(client_is_unknown(client) || client_is_handshake(client));
  assert(connect);

  /* Fixing eob timings.. -gnp */
  client->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
  client->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);

  io_free(client->connection->password);
  client->connection->password = NULL;

  comm_socket_note(client->connection->fde, "Server: %s", client->name);

  client_set_class(client, connect->klass, CLIENT_CLASS_BASE);

  server_get_or_create(client);
  server_conf_set(client, connect);

  if (service_find(client->name))
    client_set_flag(client, FLAGS_SERVICE);

  if (tls_session_is_active(&client->connection->fde->tls))
    client->tls_cipher = io_strdup(tls_session_get_cipher(&client->connection->fde->tls));

  client_set_state(client, CLIENT_STATE_SERVER);
  client_update_activity_timeout(client);
}

static void
_server_establish_publish_local(struct Client *client, bool add_namehash)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));
  assert(client->server);

  if (add_namehash)
    hash_add_client(client);
  hash_add_id(client);

  assert(list_find(&unknown_list, client));
  list_move_node(&client->connection->node, &local_server_list, &unknown_list);

  list_add(client, &client->global_node, &global_server_list);
  list_add(client, &client->uplink_node, &me.server->child_server_list);

  const size_t local_connection_count =
    list_length(&local_client_list) + list_length(&local_server_list);
  if (local_connection_count > Count.max_loc_con)
    Count.max_loc_con = local_connection_count;
}

static void
_server_establish_report_link(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  client_format_name_buffer_t admin_client_name_buffer;
  client_format_name_buffer_t oper_client_name_buffer;
  const char *const admin_client_name =
    client_format_name(client, CLIENT_FORMAT_NAME_ADMIN, &admin_client_name_buffer);
  const char *const oper_client_name =
    client_format_name(client, CLIENT_FORMAT_NAME_OPER, &oper_client_name_buffer);
  const char *const capabilities = capab_get(client, true);

  if (tls_session_is_active(&client->connection->fde->tls))
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link with %s established: [TLS: %s] (Capabilities: %s)",
                   admin_client_name, client->tls_cipher, capabilities);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link with %s established: [TLS: %s] (Capabilities: %s)",
                   oper_client_name, client->tls_cipher, capabilities);

    log_write(LOG_TYPE_IRCD, "Link with %s established: [TLS: %s] (Capabilities: %s)",
              admin_client_name, client->tls_cipher, capabilities);
  }
  else
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Link with %s established: (Capabilities: %s)",
                   admin_client_name, capabilities);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Link with %s established: (Capabilities: %s)",
                   oper_client_name, capabilities);

    log_write(LOG_TYPE_IRCD, "Link with %s established: (Capabilities: %s)",
              admin_client_name, capabilities);
  }
}

static void
_server_establish_introduce_server(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  sendto_servers(client, 0, 0, ":%s SID %s 2 %s +%s :%s",
                 me.id, client->name, client->id, client_is_hidden(client) ? "h" : "", client->info);
}

static void
_server_establish_send_servers(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  list_node_t *node;
  LIST_FOREACH_PREV(node, global_server_list.tail)
  {
    const struct Client *const target = node->data;
    /* Skip our own server and servers behind the newly established link. */
    if (client_is_me(target) || target->nexthop == client)
      continue;

    sendto_one(client, ":%s SID %s %u %s +%s :%s",
               target->uplink->id, target->name, target->hopcount + 1,
               target->id, client_is_hidden(target) ? "h" : "", target->info);
  }
}

static void
_server_establish_burst(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  list_node_t *node;
  LIST_FOREACH(node, global_client_list.head)
  {
    const struct Client *const target = node->data;
    if (target->nexthop == client)
      continue;

    _server_burst_send_client(client, target);
  }

  LIST_FOREACH(node, channel_get_list()->head)
  {
    const struct Channel *const channel = node->data;
    assert(!channel_is_empty(channel));
    if (channel_is_empty(channel))
      continue;

    channel_send_state(client, channel);
  }

  /* Always send a PING after connect burst is done. */
  sendto_one(client, "PING :%s", me.id);
}

static void
_server_establish_send_eobs(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  list_node_t *node;
  LIST_FOREACH_PREV(node, global_server_list.tail)
  {
    const struct Client *const target = node->data;
    if (target->nexthop == client)
      continue;

    sendto_one(client, ":%s EOB", target->id);
  }
}

static void
_server_establish(struct Client *client, struct ConnectItem *connect)
{
  assert(client && client_is_local(client));
  assert(client_is_unknown(client) || client_is_handshake(client));

  /* Outgoing links already occupy the name hash during handshake. */
  const bool add_namehash = !client_is_handshake(client);

  _server_establish_send_handshake(client, connect);
  _server_establish_finalize_local(client, connect);
  _server_establish_publish_local(client, add_namehash);
  _server_establish_report_link(client);
  _server_establish_introduce_server(client);
  _server_establish_send_servers(client);
  _server_establish_burst(client);
  _server_establish_send_eobs(client);
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
  assert(source && client_is_local(source));
  assert(!client_is_server(source));

  if (listener_has_flag(source->connection->listener, LISTENER_CLIENT))
  {
    client_exit(source, "Use a different port");
    return;
  }

  const char *const name = parv[1];
  if (!server_is_valid_name(name))
  {
    _server_reject_connection(source, SERVER_REJECT_INVALID_NAME, "'%s'", name);
    return;
  }

  /* While completing an outgoing handshake, reject peers that present an unexpected server name. */
  if (client_is_handshake(source) && strcmp(source->name, name))
  {
    _server_reject_connection(source, SERVER_REJECT_NAME_MISMATCH, "Presented as '%s', expected '%s'", name, source->name);
    return;
  }

  const char *const sid = parv[3];
  if (!client_id_is_valid_sid(sid))
  {
    _server_reject_connection(source, SERVER_REJECT_INVALID_SID, "'%s'", sid);
    return;
  }

  uint32_t hopcount;
  if (io_parse_uint32(parv[2], &hopcount) != IO_PARSE_OK)
  {
    _server_reject_connection(source, SERVER_REJECT_INVALID_HOPCOUNT, "'%s'", parv[2]);
    return;
  }

  if (hopcount != 1)
  {
    _server_reject_connection(source, SERVER_REJECT_INVALID_HOPCOUNT, "Expected 1, got %u", hopcount);
    return;
  }

  struct ConnectItem *connect = NULL;
  connect_auth_result_t result = connect_authenticate_server(name, source, &connect);
  if (result != CONNECT_AUTH_SUCCESS)
  {
    const char *const reason = connect_auth_result_to_string(result);

    if (result == CONNECT_AUTH_FAIL_NAME && ConfigGeneral.warn_no_connect_block == 0)
      client_exit(source, reason);
    else
      _server_reject_connection(source, SERVER_REJECT_CONFIG_MISMATCH, "%s for server '%s'", reason, name);
    return;
  }

  if (ConfigServerInfo.hub == 0 && !list_is_empty(&local_server_list))
  {
    _server_reject_connection(source, SERVER_REJECT_LEAF_LINK_POLICY, "Server is configured as a non-hub leaf");
    return;
  }

  if (service_find(name) == NULL)
  {
    if ((ConfigChannel.enable_owner == 0) != !capab_has_flag(source, CAPAB_QOP) ||
        (ConfigChannel.enable_admin == 0) != !capab_has_flag(source, CAPAB_AOP))
    {
      _server_reject_connection(source, SERVER_REJECT_CONFIG_MISMATCH, "Mismatching AOP/QOP capabilities");
      return;
    }
  }

  /*
   * A fully established server with the same SID or name already exists in the
   * network view. This is a hard collision and the introduction must be rejected.
   */
  if (client_find_server_by_sid(sid))
  {
    _server_reject_connection(source, SERVER_REJECT_SID_COLLISION, "'%s'", sid);
    return;
  }

  if (client_find_server_by_name(name))
  {
    _server_reject_connection(source, SERVER_REJECT_NAME_COLLISION, "'%s'", name);
    return;
  }

  /*
   * A matching entry in the client hash may only be replaced if it is another
   * local connection that has not yet completed server registration.
   */
  struct Client *const target = client_find_entity_by_name(name);
  if (target && target != source)
  {
    /*
     * Any non-local entry, or any local entry that is already fully established,
     * is treated as a genuine name collision and must not be replaced.
     */
    if (!client_is_local(target) ||
        (!client_is_unknown(target) && !client_is_connecting(target) && !client_is_handshake(target)))
    {
      _server_reject_connection(source, SERVER_REJECT_NAME_COLLISION, "'%s'", name);
      return;
    }

    /*
     * At this point, the match refers to a different local pending link for the
     * same server name. Replace it in favor of the current connection.
     */
    client_exit(target, "Replaced by incoming server introduction");
  }

  /*
   * If we are connecting (Handshake), we already have the name from the
   * connect{} block in source->name.
   */
  strlcpy(source->name, name, sizeof(source->name));
  strlcpy(source->id, sid, sizeof(source->id));
  strlcpy(source->info, parv[parc - 1], sizeof(source->info));
  source->hopcount = hopcount;
  _server_set_flags(source, parv[4]);

  _server_establish(source, connect);
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
  assert(client_is_server(source));
  assert(source->server);
  assert(source->nexthop);

  /* This handler should only ever be called for a fully established server. */
  if (!client_is_server(source))
    return;

  const char *const name = parv[1];
  if (!server_is_valid_name(name))
  {
    _server_reject_introduction(source, SERVER_REJECT_INVALID_NAME, "'%s'", name);
    return;
  }

  const char *const sid = parv[3];
  if (!client_id_is_valid_sid(sid))
  {
    _server_reject_introduction(source, SERVER_REJECT_INVALID_SID, "'%s'", sid);
    return;
  }

  uint32_t hopcount;
  if (io_parse_uint32(parv[2], &hopcount) != IO_PARSE_OK)
  {
    _server_reject_introduction(source, SERVER_REJECT_INVALID_HOPCOUNT, "'%s'", parv[2]);
    return;
  }

  const uint32_t expected_hopcount = source->hopcount + 1U;
  if (hopcount != expected_hopcount)
  {
    _server_reject_introduction(source, SERVER_REJECT_HOPS_MISMATCH, "Introducer hopcount: %u, New server hopcount: %u",
                                source->hopcount, hopcount);
    return;
  }

  const struct ConnectItem *const connect = server_conf_get(source->nexthop);
  /* An established server link must have a connect block associated with it. */
  assert(connect);

  /*
   * The introducing uplink must be permitted to introduce this server name.
   * If no matching hub mask exists, the introduction violates link policy.
   */
  if (list_find_cmp(&connect->hub_masks, name, match) == NULL)
  {
    _server_reject_introduction(source, SERVER_REJECT_HUB_POLICY,
                                "Introducer '%s' is not an authorized hub for '%s'", source->name, name);
    return;
  }

  /*
   * Reject the introduction if the target server name matches a configured
   * leaf mask behind this uplink.
   */
  if (list_find_cmp(&connect->leaf_masks, name, match))
  {
    _server_reject_introduction(source, SERVER_REJECT_LEAF_POLICY,
                                "Introduction of '%s' by '%s' denied (server is designated as a leaf)", name, source->name);
    return;
  }

  /*
   * A fully established server with the same SID or name already exists in the
   * network view. This is a hard collision and the introduction must be rejected.
   */
  if (client_find_server_by_sid(sid))
  {
    _server_reject_introduction(source, SERVER_REJECT_SID_COLLISION, "'%s'", sid);
    return;
  }

  if (client_find_server_by_name(name))
  {
    _server_reject_introduction(source, SERVER_REJECT_NAME_COLLISION, "'%s'", name);
    return;
  }

  /*
   * A matching entry in the client hash may only be replaced if it is a
   * local connection that has not yet completed server registration.
   */
  struct Client *target = client_find_entity_by_name(name);
  if (target)
  {
    /*
     * Any non-local entry, or any local entry that is already fully established,
     * is treated as a genuine name collision and must not be replaced.
     */
    if (!client_is_local(target) ||
        (!client_is_unknown(target) && !client_is_connecting(target) && !client_is_handshake(target)))
    {
      _server_reject_introduction(source, SERVER_REJECT_NAME_COLLISION, "'%s'", name);
      return;
    }

    /*
     * At this point, the match refers to a local pending link for the same
     * server name. Replace it in favor of the incoming introduction.
     */
    client_exit(target, "Replaced by incoming server introduction");
  }

  target = client_create_remote(source);
  server_get_or_create(target);
  strlcpy(target->name, name, sizeof(target->name));
  strlcpy(target->id, sid, sizeof(target->id));
  strlcpy(target->info, parv[parc - 1], sizeof(target->info));
  target->hopcount = hopcount;

  client_set_state(target, CLIENT_STATE_SERVER);
  _server_set_flags(target, parv[4]);

  if (service_find(target->name))
    client_set_flag(target, FLAGS_SERVICE);

  list_add(target, &target->global_node, &global_server_list);
  list_add(target, &target->uplink_node, &target->uplink->server->child_server_list);

  hash_add_client(target);
  hash_add_id(target);

  sendto_servers(source->nexthop, 0, 0, ":%s SID %s %u %s +%s :%s",
                 source->id, target->name, target->hopcount + 1, target->id, client_is_hidden(target) ? "h" : "", target->info);
  sendto_clients(UMODE_EXTERNAL, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Server %s being introduced by %s",
                 target->name, source->name);
}

static struct Command command_table[] =
{
  [0] = {
    .name = "SERVER",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_server, .args_min = 6 },
    .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_already_registered },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_reject_already_registered }
  },
  [1] = {
    .name = "SID",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_sid, .args_min = 6 },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
