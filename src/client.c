/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/*! \file client.c
 * \brief Controls clients.
 */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "comm.h"
#include "io_string.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "rng_mt.h"

#include "accept.h"
#include "channel.h"
#include "channel_invite.h"
#include "client.h"
#include "client_svstag.h"
#include "conf_gecos.h"
#include "hash.h"
#include "ipcache.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "list_task.h"
#include "listener.h"
#include "monitor.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "whowas.h"

uint64_t UMODE_BOT;
uint64_t UMODE_DEAF;
uint64_t UMODE_FARCONNECT;
uint64_t UMODE_SOFTCALLERID;
uint64_t UMODE_HIDDEN;
uint64_t UMODE_EXPIRATION;
uint64_t UMODE_REGONLY;
uint64_t UMODE_SECURE;
uint64_t UMODE_WEBIRC;
uint64_t UMODE_SECUREONLY;
uint64_t UMODE_ADMIN;
uint64_t UMODE_CCONN;
uint64_t UMODE_EXTERNAL;
uint64_t UMODE_FLOOD;
uint64_t UMODE_CALLERID;
uint64_t UMODE_INVISIBLE;
uint64_t UMODE_REJ;
uint64_t UMODE_SKILL;
uint64_t UMODE_LOCOPS;
uint64_t UMODE_NCHANGE;
uint64_t UMODE_OPER;
uint64_t UMODE_HIDECHANS;
uint64_t UMODE_HIDEIDLE;
uint64_t UMODE_REGISTERED;
uint64_t UMODE_SERVNOTICE;
uint64_t UMODE_CLOAK;
uint64_t UMODE_SPY;

list_t unknown_list;
list_t local_client_list;
list_t local_server_list;
list_t global_client_list;
list_t global_server_list;
list_t oper_list;

static list_t dead_list, abort_list;

static void _client_exit_teardown_connection(struct Client *client);
static void _client_exit_log_session(const struct Client *client, const char *reason);
static void _client_exit_cleanup_client_connection(struct Client *client, const char *reason);
static void _client_exit_cleanup_server_connection(struct Client *client, const char *reason);
static void _client_exit_cleanup_unregistered_connection(struct Client *client, const char *reason);
static void _client_exit_notify_channel_members(struct Client *client, const char *reason);
static void _client_exit_unwind_tree(struct Client *client, const char *reason);
static void _client_exit_notify_network(struct Client *client, const char *reason);
static void _client_exit_detach(struct Client *client);

void
client_reset_activity_timeout(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client->connection->activity_timeout_event);

  uintmax_t timeout_duration_ms;
  if (client_is_unknown(client) || client_is_connecting(client) || client_is_handshake(client))
    timeout_duration_ms = ConfigGeneral.registration_timeout * 1000ULL;
  else
  {
    assert(client_is_user(client) || client_is_server(client));
    timeout_duration_ms = client_get_ping_freq(client) * 1000ULL;
  }

  if (timeout_duration_ms > 0)
    event_reschedule(client->connection->activity_timeout_event, timeout_duration_ms);
  else
    event_unschedule(client->connection->activity_timeout_event);
}

static void
client_activity_timeout_handler(void *data)
{
  struct Client *const client = data;
  assert(client && client_is_local(client));

  /*
   * It is possible for this event to fire for a client that has already been
   * marked for termination (e.g., in the same main loop iteration). Do not
   * proceed if the client is already dead.
   */
  if (client_is_dead(client))
    return;

  /*
   * The event is a one-shot timer. It has now fired and is no longer scheduled.
   * The event handle itself remains valid for the next call to
   * client_reset_activity_timeout().
   */

  if (client_has_flag(client, FLAGS_TLS_HANDSHAKING))
  {
    /* The client failed to complete the TLS handshake within the allowed time. */
    client_set_dead(client);  /* Prevent client_exit() from sending on a half-open TLS connection. */
    client_exit(client, "Timeout during TLS handshake");
    return;
  }

  /* Handle timeouts for any connection that is not yet fully registered or linked. */
  if (client_is_unknown(client) || client_is_connecting(client) || client_is_handshake(client))
  {
    const char *const reason =
      client_is_unknown(client) ? "Registration timed out" : "Timeout during server handshake";
    client_exit(client, reason);
    return;
  }

  /*
   * At this point, we are dealing with a fully registered client (a user or server).
   * The timeout indicates either a period of idle activity or a failure to
   * respond to a previously sent PING.
   */
  if (client->connection->ping_sent_time > 0)
  {
    /* A PING was previously sent, and the client has not responded in time. */
    const uintmax_t time_since_ping_sent = io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->ping_sent_time;
    client_exit_fmt(client, "Ping timeout: %ju seconds", time_since_ping_sent);
  }
  else
  {
    /* The client has been idle. Send a PING to verify the connection is still alive. */
    client->connection->ping_sent_time = io_time_get(IO_TIME_MONOTONIC_SEC);
    sendto_one(client, "PING :%s", client_get_id_or_name(&me, client));

    /*
     * Reschedule the activity timer. It now serves as the timeout for the
     * PING reply. If the client remains silent, this handler will be called
     * again, but the `ping_sent_time > 0` condition will then be true.
     */
    client_reset_activity_timeout(client);
  }
}

void
client_set_class(struct Client *client, struct ClassItem *new_class, enum client_class_type type)
{
  assert(client && client_is_local(client));
  assert(type == CLIENT_CLASS_BASE || type == CLIENT_CLASS_OPER);

  struct ClassItem **class_ptr_location = NULL;
  if (type == CLIENT_CLASS_BASE)
    class_ptr_location = &client->connection->base_class;
  else
    class_ptr_location = &client->connection->oper_class;

  struct ClassItem *const old_class = *class_ptr_location;
  if (old_class == new_class)
    return;

  class_incref(new_class);
  class_decref(old_class);

  *class_ptr_location = new_class;
}

void
client_set_state(struct Client *client, enum client_state state)
{
  assert(client);

  client->state = state;

  switch (state)
  {
    case CLIENT_STATE_UNKNOWN:
    case CLIENT_STATE_CONNECTING:
    case CLIENT_STATE_HANDSHAKE:
    case CLIENT_STATE_ME:
      client->handler = UNREGISTERED_HANDLER;
      break;
    case CLIENT_STATE_SERVER:
      client->handler = SERVER_HANDLER;
      break;
    case CLIENT_STATE_USER:
      client->handler = CLIENT_HANDLER;
      break;
    default:
      assert(!"invalid client state");
      client->handler = UNREGISTERED_HANDLER;
      break;
  }
}

static void
_client_init_base(struct Client *client)
{
  client_set_state(client, CLIENT_STATE_UNKNOWN);

  client->idhnext = client;
  client->hnext = client;
  strcpy(client->username, "unknown");
  strcpy(client->account, "*");
}

struct Client *
client_create_local(void)
{
  struct Client *const client = io_calloc(sizeof(*client));
  client->connection = io_calloc(sizeof(*client->connection));
  client->connection->last_receive_time = \
  client->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
  client->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);
  client->connection->registration = REG_INIT;
  client->connection->activity_timeout_event =
    event_create(ircd_event_manager, "client_activity_timeout", client_activity_timeout_handler, 1, true, client, NULL);
  /* Local entity topology: The logical parent is this server; the entity is its own nexthop. */
  client->uplink = &me;
  client->nexthop = client;

  _client_init_base(client);
  return client;
}

struct Client *
client_create_remote(struct Client *uplink)
{
  assert(uplink);
  assert(client_is_server(uplink));
  assert(uplink->server);
  assert(uplink->nexthop);

  struct Client *const client = io_calloc(sizeof(*client));
  /* Remote entity topology: Inherit the physical route (nexthop) from the logical parent (uplink). */
  client->uplink = uplink;
  client->nexthop = uplink->nexthop;

  _client_init_base(client);
  return client;
}

static void
_client_destroy_local(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client->connection->node.prev == NULL && client->connection->node.next == NULL);
  assert(client->connection->list_task == NULL);
  assert(client->connection->lookup_request == NULL);
  assert(client->connection->fd == NULL);
  assert(client->connection->listener == NULL);
  assert(client->connection->activity_timeout_event == NULL);
  assert(client->connection->flood_recalc_event == NULL);
  assert(list_is_empty(&client->connection->accept_list));
  assert(list_is_empty(&client->connection->monitor_list));
  assert(list_is_empty(&client->connection->invite_list));
  assert(dbuf_length(&client->connection->buf_recvq) == 0);
  assert(dbuf_length(&client->connection->buf_sendq) == 0);
  assert(client->connection->base_class == NULL);
  assert(client->connection->oper_class == NULL);
  assert(server_conf_get(client) == NULL);
  assert(client_has_flag(client, FLAGS_CLOSING) && client_is_dead(client));

  io_free(client->connection->password);
  client->connection->password = NULL;
  io_free(client->connection->oper_name);
  client->connection->oper_name = NULL;
  io_free(client->connection->scheduled_exit_reason);
  client->connection->scheduled_exit_reason = NULL;

  io_free(client->connection);
  client->connection = NULL;
}

static void
_client_destroy(struct Client *client)
{
  assert(client && !client_is_me(client));
  assert(client->hnext == client);
  assert(client->idhnext == client);
  assert(client->global_node.prev == NULL && client->global_node.next == NULL);
  assert(client->uplink_node.prev == NULL && client->uplink_node.next == NULL);
  assert(list_is_empty(&client->whowas_list));
  assert(list_is_empty(&client->channel_list));
  assert(list_is_empty(&client->svstag_list));

  if (client->server)
  {
    assert(list_is_empty(&client->server->child_user_list));
    assert(list_is_empty(&client->server->child_server_list));

    server_destroy(client->server);
    client->server = NULL;
  }

  io_free(client->tls_certfp);
  client->tls_certfp = NULL;
  io_free(client->tls_cipher);
  client->tls_cipher = NULL;
  io_free(client->away_message);
  client->away_message = NULL;

  if (client_is_local(client))
    _client_destroy_local(client);

  io_free(client);
}

void
client_update_name(struct Client *client, const char *new_name)
{
  assert(client);
  assert(!string_is_empty(new_name));

  if (client->name[0])
    hash_del_client(client);

  const size_t len = strlcpy(client->name, new_name, sizeof(client->name));
  assert(len < sizeof(client->name));

  hash_add_client(client);

  if (client_is_local(client) && client->connection->fd)
    comm_socket_note(client->connection->fd, "Name: %s", client->name);
}

/*
 * client_get_name -  Return the name of the client
 *    for various tracking and
 *      admin purposes. The main purpose of this function is to
 *      return the "socket host" name of the client, if that
 *        differs from the advertised name (other than case).
 *        But, this can be used to any client structure.
 */
const char *
client_get_name(const struct Client *client, enum addr_mask_type type)
{
  static char buf[HOSTLEN * 2 + USERLEN + 4];  /* +4 for [,@,],\0 */

  if (!client_is_local(client))
    return client->name;

  if (client_is_server(client) || client_is_connecting(client) || client_is_handshake(client))
    if (io_strcasecmp(client->name, client->host) == 0)
      return client->name;

  /* And finally, let's get the host information, ip or name */
  switch (type)
  {
    case SHOW_IP:
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client->name, client->username, client->sockhost);
      break;
    case MASK_IP:
      if (address_is_ipv4(&client->addr))
        snprintf(buf, sizeof(buf), "%s[%s@255.255.255.255]",
                 client->name, client->username);
      else
        snprintf(buf, sizeof(buf), "%s[%s@ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]",
                 client->name, client->username);
      break;
    default:  /* HIDE_IP */
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client->name, client->username, client->host);
  }

  return buf;
}

const struct Client *
client_get_visible_server(const struct Client *client)
{
  assert(client);
  assert(client_is_server(client) || client_is_me(client));

  if (client_is_hidden(client) || ConfigServerHide.hide_servers)
    return &me;

  return client;
}

const char *
client_get_visible_server_name(const struct Client *client)
{
  return client_get_visible_server(client)->name;
}

/*
 * Input: A client to find the active operator {} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
const char *
client_get_oper_name(const struct Client *client)
{
  if (client_is_server(client))
    return client->name;

  const char *oper_name;
  if (client_is_local(client) && client->connection->oper_name)
    oper_name = client->connection->oper_name;
  else
    oper_name = client->uplink->name;

  static char buf[IRCD_BUFSIZE];
  snprintf(buf, sizeof(buf), "%s[%s@%s]{%s}",
           client->name, client->username, client->host, oper_name);
  return buf;
}

void
free_exited_clients(void)
{
  list_node_t *node;

  while ((node = dead_list.head))
  {
    struct Client *const client = node->data;

    list_remove(node, &dead_list);
    list_free_node(node);

    _client_destroy(client);
  }
}

static void
_client_exit_teardown_connection(struct Client *client)
{
  assert(client && client_is_local(client));

  if (client->connection->list_task)
  {
    list_task_destroy(client->connection->list_task);
    client->connection->list_task = NULL;
  }

  if (client->connection->activity_timeout_event)
  {
    event_destroy(client->connection->activity_timeout_event);
    client->connection->activity_timeout_event = NULL;
  }

  if (client->connection->flood_recalc_event)
  {
    event_destroy(client->connection->flood_recalc_event);
    client->connection->flood_recalc_event = NULL;
  }

  /* Clean up pending async operations to prevent their callbacks from firing. */
  if (client->connection->lookup_request)
  {
    lookup_delete(client->connection->lookup_request);
    client->connection->lookup_request = NULL;
  }

  /* Release our reference to the listener this client connected to. */
  if (client->connection->listener)
  {
    listener_release(client->connection->listener);
    client->connection->listener = NULL;
  }

  /*
   * Attempt a final, best-effort flush of any pending data in the send queue.
   * We deliberately clear the BLOCKED flag to force one last write attempt,
   * giving our final ERROR message the best possible chance of being delivered.
   * This is safe because even if this write re-blocks, the very next step
   * is to close the socket anyway.
   */
  if (!client_is_dead(client))
  {
    client_unset_flag(client, FLAGS_BLOCKED);
    send_queued_write(client);
  }

  if (client->connection->fd)
  {
    comm_socket_close(client->connection->fd);
    client->connection->fd = NULL;
  }

  /* Free transport-level buffer memory now that the socket is gone. */
  dbuf_clear(&client->connection->buf_sendq);
  dbuf_clear(&client->connection->buf_recvq);
}

static void
_client_exit_notify_channel_members(struct Client *client, const char *reason)
{
  assert(client && client_is_user(client));
  sendto_common_channels_local(client, false, 0, 0, ":%s!%s@%s QUIT :%s",
                               client->name, client->username, client->host, reason);
}

static void
_client_exit_unwind_tree(struct Client *split_root, const char *reason)
{
  assert(split_root && client_is_server(split_root));
  assert(split_root->server);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, split_root->server->child_user_list.head)
  {
    struct Client *const child_user = node->data;
    assert(!client_is_local(child_user));
    _client_exit_notify_channel_members(child_user, reason);
    _client_exit_detach(child_user);
  }

  LIST_FOREACH_SAFE(node, node_next, split_root->server->child_server_list.head)
  {
    struct Client *const child_server = node->data;
    _client_exit_unwind_tree(child_server, reason);
    _client_exit_detach(child_server);
  }
}

static void
_client_exit_notify_network(struct Client *client, const char *reason)
{
  if (client_is_server(client))
  {
    assert(client->server);
    assert(client->uplink);

    char split_reason[HOSTLEN + HOSTLEN + 2];  /* +2 for space and \0 */
    if (ConfigServerHide.hide_servers)
      /*
       * Set netsplit message to "*.net *.split" to still show that it's a split,
       * but hide the servers splitting.
       */
      strlcpy(split_reason, "*.net *.split", sizeof(split_reason));
    else
      snprintf(split_reason, sizeof(split_reason), "%s %s",
               client->uplink->name, client->name);

    sendto_clients(UMODE_EXTERNAL, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Server %s split from %s",
                   client->name, client->uplink->name);

    /* Send SQUIT for 'client' in every direction. 'client' is already off of local_server_list here. */
    if (!client_has_flag(client, FLAGS_SQUIT))
      sendto_servers(NULL, 0, 0, "SQUIT %s :%s", client->id, reason);

    /* Recursively handle the departure of all entities behind this server. */
    _client_exit_unwind_tree(client, split_reason);
  }
  else if (client_is_user(client))
  {
    assert(client->nexthop);

    if (!client_has_flag(client, FLAGS_KILLED))
      sendto_servers(client->nexthop, 0, 0, ":%s QUIT :%s", client->id, reason);

    /* Notify local clients in common channels that this user has quit. */
    _client_exit_notify_channel_members(client, reason);
  }
}

static void
_client_exit_detach(struct Client *client)
{
  assert(list_find(&local_client_list, client) == NULL);
  assert(list_find(&local_server_list, client) == NULL);
  assert(list_find(&unknown_list, client) == NULL);
  assert(list_find(&oper_list, client) == NULL);
  assert(list_find(&abort_list, client) == NULL);

  if (client_is_user(client))
  {
    if (client_is_oper(client))
      --Count.oper;
    if (user_mode_has_flag(client, UMODE_INVISIBLE))
      --Count.invisi;

    channel_member_remove_list(&client->channel_list);

    svstag_clear_list(&client->svstag_list);

    whowas_add_history(client, false);
    whowas_off_history(client);

    monitor_notify_signoff(client);
  }

  if (client_is_user(client))
  {
    assert(client->uplink && client->uplink->server);
    assert(list_find(&client->uplink->server->child_user_list, client));

    list_remove(&client->global_node, &global_client_list);
    list_remove(&client->uplink_node, &client->uplink->server->child_user_list);
  }
  else if (client_is_server(client))
  {
    assert(client->uplink && client->uplink->server);
    assert(list_find(&client->uplink->server->child_server_list, client));

    list_remove(&client->global_node, &global_server_list);
    list_remove(&client->uplink_node, &client->uplink->server->child_server_list);
  }

  if (client->id[0])
    hash_del_id(client);
  if (client->name[0])
    hash_del_client(client);

  if (client_has_flag(client, FLAGS_IPHASH))
  {
    client_unset_flag(client, FLAGS_IPHASH);
    ipcache_record_remove(&client->addr, client_is_local(client));
  }

  assert(list_find(&dead_list, client) == NULL);
  /* Queue the client for final destruction at the tail so dead_list preserves detach order. */
  list_add_tail(client, list_make_node(), &dead_list);
}

static void
_client_exit_log_session(const struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));

  if (client_is_user(client))
  {
    log_write(LOG_TYPE_USER,
              "SESSION END: nick=\"%s\" user=\"%s\" host=\"%s\" ip=\"%s\" "
              "realhost=\"%s\" acct=\"%s\" duration=\"%s\" "
              "sent=%juKiB recv=%juKiB msgs_sent=%u msgs_recv=%u "
              "class=\"%s\" oper=\"%s\" reason=\"%s\"",
              client->name, client->username, client->host, client->sockhost, client->realhost, client->account,
              time_format_duration(client_get_session_duration(client)),
              (uintmax_t)(client->connection->send.bytes >> 10),
              (uintmax_t)(client->connection->recv.bytes >> 10),
              client->connection->send.messages,
              client->connection->recv.messages,
              client_get_class_name(client),
              client->connection->oper_name ? client->connection->oper_name : "-", reason);
  }
  else if (client_is_server(client))
  {
    log_write(LOG_TYPE_IRCD,
              "LINK END: name=\"%s\" ip=\"%s\" duration=\"%s\" "
              "sent=%juKiB recv=%juKiB msgs_sent=%u msgs_recv=%u "
              "class=\"%s\" reason=\"%s\"",
              client->name, client->sockhost,
              time_format_duration(client_get_session_duration(client)),
              (uintmax_t)(client->connection->send.bytes >> 10),
              (uintmax_t)(client->connection->recv.bytes >> 10),
              client->connection->send.messages,
              client->connection->recv.messages,
              client_get_class_name(client), reason);
  }
}

static void
_client_exit_cleanup_server_connection(struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Link Closed: %s [ip=%s class=%s uptime=\"%s\" sent=%juKiB recv=%juKiB] (Reason: %s)",
                 client->name, client->sockhost, client_get_class_name(client),
                 time_format_duration(client_get_session_duration(client)),
                 (uintmax_t)(client->connection->send.bytes >> 10),
                 (uintmax_t)(client->connection->recv.bytes >> 10), reason);

  _client_exit_log_session(client, reason);

  ++ServerStats.is_sv;
  ServerStats.is_sbs += client->connection->send.bytes;
  ServerStats.is_sbr += client->connection->recv.bytes;
  ServerStats.is_sti += client_get_session_duration(client);

  assert(list_find(&local_server_list, client));
  list_remove(&client->connection->node, &local_server_list);

  server_conf_set(client, NULL);
  client_set_class(client, NULL, CLIENT_CLASS_BASE);
}

static void
_client_exit_cleanup_client_connection(struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));
  assert(client_is_user(client));

  _client_exit_log_session(client, reason);

  ++ServerStats.is_cl;
  ServerStats.is_cbs += client->connection->send.bytes;
  ServerStats.is_cbr += client->connection->recv.bytes;
  ServerStats.is_cti += client_get_session_duration(client);

  assert(list_find(&local_client_list, client));
  list_remove(&client->connection->node, &local_client_list);

  if (client_is_oper(client))
  {
    list_node_t *node = list_find_remove(&oper_list, client);
    assert(node);

    if (node)
      list_free_node(node);
  }

  invite_clear_list(&client->connection->invite_list);
  accept_clear_list(&client->connection->accept_list);
  monitor_clear_list(client);

  client_set_class(client, NULL, CLIENT_CLASS_BASE);
  client_set_class(client, NULL, CLIENT_CLASS_OPER);
}

static void
_client_exit_cleanup_unregistered_connection(struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));
  assert(client_is_unknown(client) || client_is_connecting(client) || client_is_handshake(client));

  if (client_is_connecting(client) || client_is_handshake(client))
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Link Failed: %s [ip=%s] (Reason: %s)",
                   client->name, client->sockhost, reason);

  ++ServerStats.is_ni;

  assert(list_find(&unknown_list, client));
  list_remove(&client->connection->node, &unknown_list);

  if (client_is_connecting(client) || client_is_handshake(client))
    server_conf_set(client, NULL);

  client_set_class(client, NULL, CLIENT_CLASS_BASE);
}

void
client_exit(struct Client *client, const char *reason)
{
  assert(client && !client_is_me(client));
  assert(reason);

  if (client_has_flag(client, FLAGS_CLOSING))
    return;
  client_set_flag(client, FLAGS_CLOSING);

  /* For local clients, tear down the physical connection and its resources. */
  if (client_is_local(client))
  {
    assert(client == client->nexthop);

    if (client_is_server(client))
    {
      server_schedule_reconnect(client);

      /*
       * Queue a final "dying gasp" SQUIT message to inform the remote server that we
       * are the ones initiating the split. This is not sent if the exit was triggered
       * by a remote SQUIT for this link.
       */
      if (!client_has_flag(client, FLAGS_SQUIT))
        sendto_one(client, ":%s SQUIT %s :%s", me.id, me.id, reason);
    }

    sendto_one(client, "ERROR :Closing Link: %s (%s)", client->host, reason);
    _client_exit_teardown_connection(client);
  }

  client_set_dead(client);
  hook_dispatch(client_is_local(client) ? ircd_hook_client_exit_local : ircd_hook_client_exit_remote,
                &(ircd_hook_client_exit_ctx){ .client = client, .reason = reason });

  /*
   * Clean up high-level application state for local clients. This MUST be done before network
   * propagation to ensure that broadcast lists like `local_server_list` are correct before
   * they are used by sendto_servers().
   */
  if (client_is_local(client))
  {
    if (client_is_user(client))
      _client_exit_cleanup_client_connection(client, reason);
    else if (client_is_server(client))
      _client_exit_cleanup_server_connection(client, reason);
    else
      _client_exit_cleanup_unregistered_connection(client, reason);
  }

  /* Propagate the departure news across the IRC network. */
  _client_exit_notify_network(client, reason);

  /* Perform the final, irreversible detachment from all data structures and schedule the memory for deallocation. */
  _client_exit_detach(client);
}

void
client_exit_fmt(struct Client *client, const char *format, ...)
{
  char reason[IRCD_BUFSIZE];
  va_list args;

  va_start(args, format);
  vsnprintf(reason, sizeof(reason), format, args);
  va_end(args);

  client_exit(client, reason);
}

void
client_schedule_exit(struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));
  assert(reason);

  if (client_is_defunct(client))
    return;

  client_set_dead(client);

  io_free(client->connection->scheduled_exit_reason);
  client->connection->scheduled_exit_reason = io_strdup(reason);

  dbuf_clear(&client->connection->buf_recvq);
  dbuf_clear(&client->connection->buf_sendq);

  assert(list_find(&abort_list, client) == NULL);
  list_add_tail(client, list_make_node(), &abort_list);
}

void
client_schedule_exit_fmt(struct Client *client, const char *format, ...)
{
  assert(client && client_is_local(client));
  assert(format);

  if (client_is_defunct(client))
    return;

  char reason[IRCD_BUFSIZE];
  va_list args;

  va_start(args, format);
  vsnprintf(reason, sizeof(reason), format, args);
  va_end(args);

  client_schedule_exit(client, reason);
}

void
client_schedule_exit_on_io_failure(struct Client *client, enum client_io_operation operation,
                                   enum client_io_failure failure, int error_code)
{
  assert(client && client_is_local(client));

  if (client_is_defunct(client))
    return;

  const char *operation_name = NULL;
  switch (operation)
  {
    case CLIENT_IO_OPERATION_READ:
      operation_name = "Read";
      break;
    case CLIENT_IO_OPERATION_WRITE:
      operation_name = "Write";
      break;
    default:
      operation_name = "IO";
      break;
  }

  const char *failure_reason = NULL;
  switch (failure)
  {
    case CLIENT_IO_FAILURE_PEER_CLOSED:
      failure_reason = "Connection closed by peer";
      break;
    case CLIENT_IO_FAILURE_ERROR:
      failure_reason = error_code ? strerror(error_code) : "Unknown error";
      break;
    default:
      failure_reason = "Unknown error";
      break;
  }

  char reason[IRCD_BUFSIZE];
  snprintf(reason, sizeof(reason), "%s failed: %s", operation_name, failure_reason);
  client_schedule_exit(client, reason);
}

void
exit_aborted_clients(void)
{
  list_node_t *node;

  while ((node = abort_list.head))
  {
    struct Client *const client = node->data;
    assert(client && client_is_local(client));
    assert(client_is_dead(client));

    list_remove(node, &abort_list);
    list_free_node(node);

    const char *reason = client->connection->scheduled_exit_reason;
    client_exit(client, reason);
  }
}

static void
_client_normalize_ipv6_address_string(char *addr_string, size_t addr_string_size)
{
  assert(addr_string);
  assert(addr_string_size > 0);

  if (addr_string[0] == ':' && addr_string[1] == ':')
  {
    const size_t len = strlen(addr_string);
    if (len + 2 <= addr_string_size)
    {
      memmove(addr_string + 1, addr_string, len + 1);
      addr_string[0] = '0';
    }
  }
}

static void
_client_reject_connection_server_full(fde_t *client_fde, const struct Listener *listener, const char *remote_addr_str)
{
  assert(client_fde);
  assert(listener);
  assert(remote_addr_str);

  static uintmax_t rate = 0;
  sendto_clients_ratelimited(&rate, "Refused connection from %s on listener [%s/%hu]: server full",
                             remote_addr_str, listener_get_name(listener), listener_get_port(listener));

  ++ServerStats.is_ref;
  comm_socket_close(client_fde);
}

static void
_client_reject_connection_by_policy(fde_t *client_fde, const struct Listener *listener,
                                    const char *remote_addr_str, int policy_result)
{
  assert(client_fde);
  assert(listener);
  assert(remote_addr_str);
  assert(policy_result);

  log_write(LOG_TYPE_DEBUG, "Refused connection from %s on listener [%s/%hu]: %s",
            remote_addr_str, listener_get_name(listener), listener_get_port(listener),
            policy_result == BANNED_CLIENT ? "D-lined" : "Throttled");

  ++ServerStats.is_ref;
  comm_socket_close(client_fde);
}

static void
_client_tls_handshake_handler(fde_t *fd, void *data)
{
  struct Client *const client = data;
  assert(client && client_is_local(client));
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd == fd);

  /*
   * This callback may still fire for a client that has already
   * entered the shutdown path.
   */
  if (client_is_defunct(client))
    return;

  const char *tls_error = NULL;
  const tls_handshake_status_t status = tls_handshake(&fd->tls, TLS_ROLE_SERVER, &tls_error);

  switch (status)
  {
    case TLS_HANDSHAKE_DONE:
      client_unset_flag(client, FLAGS_TLS_HANDSHAKING);
      client_set_flag(client, FLAGS_TLS_ACTIVE);
      comm_setselect(fd, 0, NULL, NULL);

      if (!tls_verify_certificate(&fd->tls, &client->tls_certfp))
        log_write(LOG_TYPE_IRCD, "Client %s gave bad TLS client certificate",
                  client_get_name(client, MASK_IP));

      lookup_start(client);
      return;
    case TLS_HANDSHAKE_WANT_WRITE:
      comm_setselect(fd, COMM_SELECT_WRITE, _client_tls_handshake_handler, client);
      return;
    case TLS_HANDSHAKE_WANT_READ:
      comm_setselect(fd, COMM_SELECT_READ, _client_tls_handshake_handler, client);
      return;
    default:
      client_set_dead(client);  /* Prevent client_exit() from sending on a failed TLS socket. */
      client_exit(client, tls_error ? tls_error : "Error during TLS handshake");
      return;
  }
}

static void
_client_begin_local_connection_ingress(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->listener);

  client_reset_activity_timeout(client);

  if (!listener_has_flag(client->connection->listener, LISTENER_TLS))
  {
    lookup_start(client);
    return;
  }

  if (!tls_new(&client->connection->fd->tls, client->connection->fd->fd, TLS_ROLE_SERVER))
  {
    client_set_dead(client);  /* Prevent client_exit() from sending on a failed TLS socket. */
    client_exit(client, "TLS context initialization failed");
    return;
  }

  client_set_flag(client, FLAGS_TLS_HANDSHAKING);
  _client_tls_handshake_handler(client->connection->fd, client);
}

static struct Client *
_client_create_accepted_local_connection(fde_t *client_fde, struct Listener *listener,
                                         const struct io_addr *remote_addr, const char *remote_addr_str)
{
  assert(client_fde);
  assert(listener);
  assert(remote_addr);
  assert(remote_addr_str);

  struct Client *const client = client_create_local();
  client->connection->fd = client_fde;

  address_copy(&client->addr, remote_addr);

  strlcpy(client->sockhost, remote_addr_str, sizeof(client->sockhost));
  _client_normalize_ipv6_address_string(client->sockhost, sizeof(client->sockhost));

  strlcpy(client->host, client->sockhost, sizeof(client->host));

  client->connection->listener = listener;
  listener_retain(listener);

  list_add(client, &client->connection->node, &unknown_list);

  return client;
}

void
client_process_accepted_connection(fde_t *client_fde, struct Listener *listener,
                                   const struct io_addr *remote_addr, const char *remote_addr_str)
{
  assert(client_fde);
  assert(listener);
  assert(remote_addr);
  assert(remote_addr_str);

  if (number_fd > hard_fdlimit - 10)
  {
    _client_reject_connection_server_full(client_fde, listener, remote_addr_str);
    return;
  }

  int policy_result = conf_connect_allowed(remote_addr);
  if (policy_result)
  {
    _client_reject_connection_by_policy(client_fde, listener, remote_addr_str, policy_result);
    return;
  }

  ++ServerStats.is_ac;

  struct Client *client =
    _client_create_accepted_local_connection(client_fde, listener, remote_addr, remote_addr_str);
  _client_begin_local_connection_ingress(client);
}

/**
 * @brief Retrieves the (fake) idle time for a target client.
 *
 * This function calculates the (fake) idle time for a target client based on the
 * configuration of the class it belongs to. If fake idle is not enabled or the
 * target client is the same as the source client, the actual idle time is returned.
 * If the source client has oper mode and hiding idle from opers is not enabled, the
 * actual idle time is also returned. Otherwise, the (fake) idle time is calculated
 * based on the class configuration.
 *
 * @param source Pointer to the source client.
 * @param target Pointer to the target client.
 * @return The calculated (fake) idle time for the target client.
 */
unsigned int
client_get_idle_time(const struct Client *source, const struct Client *target)
{
  const struct ClassItem *const klass = client_get_active_class(target);
  if (!(klass->flags & CLASS_FLAGS_FAKE_IDLE) || target == source)
    return client_get_idle_duration(target);

  if (client_is_oper(source) && !(klass->flags & CLASS_FLAGS_HIDE_IDLE_FROM_OPERS))
    return client_get_idle_duration(target);

  const unsigned int min_idle = klass->min_idle;
  const unsigned int max_idle = klass->max_idle;
  if (min_idle == max_idle)
    return min_idle;

  unsigned int idle = 0;
  if (klass->flags & CLASS_FLAGS_RANDOM_IDLE)
    idle = genrand_int32();
  else
    idle = client_get_idle_duration(target);

  if (max_idle)
    idle %= max_idle;
  else
    idle = 0;

  if (idle < min_idle)
    idle = min_idle + (idle % (max_idle - min_idle));

  return idle;
}
