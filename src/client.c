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

/*! \file client.c
 * \brief Controls clients.
 */

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "comm.h"
#include "event.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "rng_mt.h"

#include "accept.h"
#include "channel.h"
#include "channel_invite.h"
#include "client.h"
#include "client_svstag.h"
#include "conf.h"
#include "conf_connect.h"
#include "conf_gecos.h"
#include "hash.h"
#include "ipcache.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "listener.h"
#include "lookup.h"
#include "monitor.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "user_mode.h"
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
uint64_t UMODE_WALLOP;
uint64_t UMODE_CLOAK;
uint64_t UMODE_SPY;

list_t listing_client_list;
list_t unknown_list;
list_t local_client_list;
list_t local_server_list;
list_t global_client_list;
list_t global_server_list;
list_t oper_list;

static list_t dead_list, abort_list;
static list_node_t *eac_next;  /* next aborted client to exit */

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
  assert(client_is_local(client));
  assert(client->connection->activity_timeout_event);

  uintmax_t timeout_duration_ms;
  if (IsUnknown(client) || IsConnecting(client) || IsHandshake(client))
    timeout_duration_ms = ConfigGeneral.registration_timeout * 1000ULL;
  else
  {
    assert(IsClient(client) || IsServer(client));
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
  assert(client_is_local(client));

  /*
   * It is possible for this event to fire for a client that has already been
   * marked for termination (e.g., in the same main loop iteration). Do not
   * proceed if the client is already dead.
   */
  if (IsDead(client))
    return;

  /*
   * The event is a one-shot timer. It has now fired and is no longer scheduled.
   * The event handle itself remains valid for the next call to
   * client_reset_activity_timeout().
   */

  if (client_has_flag(client, FLAGS_TLS_HANDSHAKING))
  {
    /* The client failed to complete the TLS handshake within the allowed time. */
    client_exit(client, "Timeout during TLS handshake");
    return;
  }

  /* Handle timeouts for any connection that is not yet fully registered or linked. */
  if (IsUnknown(client) || IsConnecting(client) || IsHandshake(client))
  {
    const char *reason = IsUnknown(client) ? "Registration timed out" : "Timeout during server handshake";
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
  assert(client->connection);

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

static void
_client_init_base(struct Client *client)
{
  SetUnknown(client);

  client->idhnext = client;
  client->hnext = client;
  strcpy(client->username, "unknown");
  strcpy(client->account, "*");
}

struct Client *
client_create_local(void)
{
  struct Client *client = io_calloc(sizeof(*client));
  client->connection = io_calloc(sizeof(*client->connection));
  client->connection->last_receive_time = \
  client->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
  client->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);
  client->connection->registration = REG_INIT;
  client->connection->activity_timeout_event =
    event_create(ircd_event_manager, "client_activity_timeout", client_activity_timeout_handler, 1, true, client, NULL);

  /* For a local client, 'from' points to itself and 'uplink' points to &me. */
  client->from = client;
  client->uplink = &me;

  _client_init_base(client);
  return client;
}

struct Client *
client_create_remote(struct Client *uplink)
{
  assert(uplink);
  assert(IsServer(uplink));

  struct Client *client = io_calloc(sizeof(*client));
  /*
   * For a remote client, the uplink is the server introducing it, and 'from'
   * is that server's 'from' (our direct connection to that part of the net).
   */
  client->uplink = uplink;
  client->from = uplink->from;

  _client_init_base(client);
  return client;
}

static void
_client_destroy(struct Client *client)
{
  assert(client && client != &me && !IsMe(client));
  assert(client->hnext == client);
  assert(client->idhnext == client);
  assert(client->global_node.prev == NULL && client->global_node.next == NULL);
  assert(client->uplink_node.prev == NULL && client->uplink_node.next == NULL);
  assert(list_is_empty(&client->whowas_list));
  assert(list_is_empty(&client->channel));
  assert(list_is_empty(&client->svstags));

  if (client->serv)
  {
    assert(list_is_empty(&client->serv->child_server_list));
    assert(list_is_empty(&client->serv->child_client_list));

    io_free(client->serv->initiator_name);
    client->serv->initiator_name = NULL;
    io_free(client->serv);
    client->serv = NULL;
  }

  io_free(client->tls_certfp);
  client->tls_certfp = NULL;
  io_free(client->tls_cipher);
  client->tls_cipher = NULL;
  io_free(client->away);
  client->away = NULL;

  if (client_is_local(client))
  {
    assert(client->connection->node.prev == NULL && client->connection->node.next == NULL);
    assert(client->connection->list_task == NULL);
    assert(client->connection->lookup == NULL);
    assert(client->connection->fd == NULL);
    assert(client->connection->listener == NULL);
    assert(client->connection->activity_timeout_event == NULL);
    assert(client->connection->flood_recalc_event == NULL);
    assert(list_is_empty(&client->connection->acceptlist));
    assert(list_is_empty(&client->connection->monitors));
    assert(list_is_empty(&client->connection->invited));
    assert(dbuf_length(&client->connection->buf_recvq) == 0);
    assert(dbuf_length(&client->connection->buf_sendq) == 0);
    assert(client->connection->base_class == NULL);
    assert(client->connection->oper_class == NULL);
    assert(server_conf_get(client) == NULL);
    assert(client_has_flag(client, FLAGS_CLOSING) && IsDead(client));

    io_free(client->connection->password);
    client->connection->password = NULL;
    io_free(client->connection->oper_name);
    client->connection->oper_name = NULL;
    io_free(client->connection->abort_reason);
    client->connection->abort_reason = NULL;

    io_free(client->connection);
    client->connection = NULL;
  }

  io_free(client);
}

/* check_conf_klines()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - Check all connections for a pending kline against the
 * 		  client, exit the client if a kline matches.
 */
void
check_conf_klines(void)
{
  list_node_t *node, *node_next;
  const void *ptr;

  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client = node->data;

    /* If a client is already being exited */
    if (IsDead(client))
      continue;

    if ((ptr = find_conf_by_address(NULL, &client->addr, CONF_DLINE, NULL, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_DLINE, conf->reason);
      continue;  /* and go examine next Client */
    }

    if ((ptr = find_conf_by_address(client->host, &client->addr, CONF_KLINE,
                                    client->username, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_KLINE, conf->reason);
      continue;  /* and go examine next Client */
    }

    if ((ptr = gecos_find(client->info, match)))
    {
      const struct GecosItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_XLINE, conf->reason);
      continue;  /* and go examine next Client */
    }
  }

  /* Also check the unknowns list for new dlines */
  LIST_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client = node->data;

    /* If a client is already being exited */
    if (IsDead(client))
      continue;

    if ((ptr = find_conf_by_address(NULL, &client->addr, CONF_DLINE, NULL, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_DLINE, conf->reason);
      continue;  /* and go examine next Client */
    }
  }
}

/*
 * conf_try_ban
 *
 * inputs	- pointer to client to ban
 * 		- pointer to MaskItem
 * output	- NONE
 * side effects	- given client is banned
 */
void
conf_try_ban(struct Client *client, int type, const char *reason)
{
  char ban_type = '?';

  switch (type)
  {
    case CLIENT_BAN_KLINE:
      if (client_has_flag(client, FLAGS_EXEMPTKLINE))
      {
        sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                       "KLINE over-ruled for %s, client is kline_exempt",
                       client_get_name(client, HIDE_IP));
        return;
      }

      ban_type = 'K';
      break;
    case CLIENT_BAN_DLINE:
      if (find_conf_by_address(NULL, &client->addr, CONF_EXEMPT, NULL, NULL, 1))
        return;
      ban_type = 'D';
      break;
    case CLIENT_BAN_XLINE:
      if (client_has_flag(client, FLAGS_EXEMPTXLINE))
      {
        sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                       "XLINE over-ruled for %s, client is xline_exempt",
                       client_get_name(client, HIDE_IP));
        return;
      }

      ban_type = 'X';
      break;
    default:
      assert(0);
      break;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%c-line active for %s",
                 ban_type, client_get_name(client, HIDE_IP));

  if (IsClient(client))
    sendto_one_numeric(client, &me, ERR_YOUREBANNEDCREEP, reason);

  client_exit(client, reason);
}

/* find_person()
 *
 * inputs	- pointer to name
 * output	- return client pointer
 * side effects - find person by (nick)name
 */
struct Client *
find_person(const struct Client *client, const char *name)
{
  struct Client *target = NULL;

  if (IsDigit(*name))
  {
    if (IsServer(client->from))
      target = hash_find_id(name);
  }
  else
    target = hash_find_client(name);

  if (target && IsClient(target))
    return target;

  return NULL;
}

/*
 * find_chasing - find the client structure for a nick name (name)
 *      using history mechanism if necessary. If the client is not found,
 *      an error message (NO SUCH NICK) is generated.
 */
struct Client *
find_chasing(struct Client *client, const char *name)
{
  struct Client *target = find_person(client, name);

  if (target)
    return target;

  if (IsDigit(*name))
    return NULL;

  target = whowas_get_history(name, ConfigGeneral.kill_chase_time_limit);
  if (target == NULL)
    sendto_one_numeric(client, &me, ERR_NOSUCHNICK, name);

  return target;
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

  if (IsServer(client) || IsConnecting(client) || IsHandshake(client))
  {
    if (irccmp(client->name, client->host) == 0)
      return client->name;
    else if (ConfigServerHide.hide_server_ips)
      type = MASK_IP;
  }

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

/*
 * Input: A client to find the active operator {} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
const char *
client_get_oper_name(const struct Client *client)
{
  if (IsServer(client))
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
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, dead_list.head)
  {
    _client_destroy(node->data);
    list_remove(node, &dead_list);
    list_free_node(node);
  }
}

static void
_client_exit_teardown_connection(struct Client *client)
{
  assert(client && client_is_local(client));

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
  if (client->connection->lookup)
  {
    lookup_delete(client->connection->lookup);
    client->connection->lookup = NULL;
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
  client_unset_flag(client, FLAGS_BLOCKED);
  send_queued_write(client);

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
  assert(client && IsClient(client));
  sendto_common_channels_local(client, false, 0, 0, ":%s!%s@%s QUIT :%s",
                               client->name, client->username, client->host, reason);
}

static void
_client_exit_unwind_tree(struct Client *split_root, const char *reason)
{
  assert(split_root && IsServer(split_root));
  assert(split_root->serv);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, split_root->serv->child_client_list.head)
  {
    struct Client *child_client = node->data;
    _client_exit_notify_channel_members(child_client, reason);
    _client_exit_detach(child_client);
  }

  LIST_FOREACH_SAFE(node, node_next, split_root->serv->child_server_list.head)
  {
    struct Client *child_server = node->data;
    _client_exit_unwind_tree(child_server, reason);
    _client_exit_detach(child_server);
  }
}

static void
_client_exit_notify_network(struct Client *client, const char *reason)
{
  if (IsServer(client))
  {
    assert(client->serv);
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
  else if (IsClient(client))
  {
    assert(client->from);

    if (!client_has_flag(client, FLAGS_KILLED))
      sendto_servers(client->from, 0, 0, ":%s QUIT :%s", client->id, reason);

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
  assert(list_find(&listing_client_list, client) == NULL);
  assert(list_find(&oper_list, client) == NULL);
  assert(list_find(&abort_list, client) == NULL);

  if (IsClient(client))
  {
    if (client_is_oper(client))
      --Count.oper;
    if (user_mode_has_flag(client, UMODE_INVISIBLE))
      --Count.invisi;

    channel_member_clear_list(&client->channel);

    svstag_clear_list(&client->svstags);

    whowas_add_history(client, false);
    whowas_off_history(client);

    monitor_signoff(client);
  }

  if (IsClient(client))
  {
    assert(client->uplink && client->uplink->serv);

    list_remove(&client->global_node, &global_client_list);
    list_remove(&client->uplink_node, &client->uplink->serv->child_client_list);
  }
  else if (IsServer(client))
  {
    assert(client->uplink && client->uplink->serv);

    list_remove(&client->global_node, &global_server_list);
    list_remove(&client->uplink_node, &client->uplink->serv->child_server_list);
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
  /* Schedule the final memory deallocation. */
  list_add(client, list_make_node(), &dead_list);
}

static void
_client_exit_log_session(const struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));

  if (IsClient(client))
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
  else if (IsServer(client))
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
  assert(IsServer(client));

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
  assert(IsClient(client));

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
    if (node)
      list_free_node(node);
  }

  free_list_task(client);
  invite_clear_list(&client->connection->invited);
  accept_clear_list(&client->connection->acceptlist);
  monitor_clear_list(client);

  client_set_class(client, NULL, CLIENT_CLASS_BASE);
  client_set_class(client, NULL, CLIENT_CLASS_OPER);
}

static void
_client_exit_cleanup_unregistered_connection(struct Client *client, const char *reason)
{
  assert(client && client_is_local(client));
  assert(IsUnknown(client) || IsConnecting(client) || IsHandshake(client));

  if (IsConnecting(client) || IsHandshake(client))
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Link Failed: %s [ip=%s] (Reason: %s)",
                   client->name, client->sockhost, reason);

  ++ServerStats.is_ni;

  assert(list_find(&unknown_list, client));
  list_remove(&client->connection->node, &unknown_list);

  if (IsConnecting(client) || IsHandshake(client))
    server_conf_set(client, NULL);

  client_set_class(client, NULL, CLIENT_CLASS_BASE);
}

void
client_exit(struct Client *client, const char *reason)
{
  assert(client && client != &me && !IsMe(client));
  assert(reason);

  if (client_has_flag(client, FLAGS_CLOSING))
    return;
  client_set_flag(client, FLAGS_CLOSING);

  /* For local clients, tear down the physical connection and its resources. */
  if (client_is_local(client))
  {
    assert(client == client->from);

    if (IsServer(client))
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

  SetDead(client);
  hook_dispatch(client_is_local(client) ? ircd_hook_client_exit_local : ircd_hook_client_exit_remote,
                &(ircd_hook_client_exit_ctx){ .client = client, .reason = reason });

  /*
   * Clean up high-level application state for local clients. This MUST be done before network
   * propagation to ensure that broadcast lists like `local_server_list` are correct before
   * they are used by sendto_servers().
   */
  if (client_is_local(client))
  {
    if (IsClient(client))
      _client_exit_cleanup_client_connection(client, reason);
    else if (IsServer(client))
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
  char buf[IRCD_BUFSIZE];
  va_list args;

  va_start(args, format);
  vsnprintf(buf, sizeof(buf), format, args);
  va_end(args);

  client_exit(client, buf);
}

static void
_client_exit_schedule(struct Client *client, const char *reason)
{
  if (IsDefunct(client))
    return;

  SetDead(client);

  io_free(client->connection->abort_reason);
  client->connection->abort_reason = io_strdup(reason);

  dbuf_clear(&client->connection->buf_recvq);
  dbuf_clear(&client->connection->buf_sendq);

  assert(list_find(&abort_list, client) == NULL);
  list_node_t *node = list_make_node();
  list_add_tail(client, node, &abort_list);

  if (eac_next == NULL)
    eac_next = node;
}

void
dead_link_on_write(struct Client *client, const char *format, ...)
{
  if (IsDefunct(client))
    return;

  char err_str[IRCD_BUFSIZE];
  va_list args;

  va_start(args, format);
  vsnprintf(err_str, sizeof(err_str), format, args);
  va_end(args);

  _client_exit_schedule(client, err_str);
}

void
dead_link_on_read(struct Client *client, int recv_return_val, int error_code)
{
  if (IsDefunct(client))
    return;

  if (recv_return_val == 0)
    _client_exit_schedule(client, "Remote host closed the connection");
  else
  {
    char reason_buf[IRCD_BUFSIZE];
    snprintf(reason_buf, sizeof(reason_buf), "Read error: %s", strerror(error_code));
    _client_exit_schedule(client, reason_buf);
  }
}

void
exit_aborted_clients(void)
{
  list_node_t *node;

  LIST_FOREACH_SAFE(node, eac_next, abort_list.head)
  {
    struct Client *client = node->data;
    eac_next = node->next;

    list_remove(node, &abort_list);
    list_free_node(node);

    const char *reason = client->connection->abort_reason;
    client_exit(client, reason);
  }
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
client_get_idle_time(const struct Client *source,
                     const struct Client *target)
{
  unsigned int idle = 0;
  const struct ClassItem *const klass = client_get_active_class(target);

  if (!(klass->flags & CLASS_FLAGS_FAKE_IDLE) || target == source)
    return io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_privmsg;

  if (client_is_oper(source) && !(klass->flags & CLASS_FLAGS_HIDE_IDLE_FROM_OPERS))
    return io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_privmsg;

  const unsigned int min_idle = klass->min_idle;
  const unsigned int max_idle = klass->max_idle;

  if (min_idle == max_idle)
    return min_idle;

  if (klass->flags & CLASS_FLAGS_RANDOM_IDLE)
    idle = genrand_int32();
  else
    idle = io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_privmsg;

  if (max_idle)
    idle %= max_idle;
  else
    idle = 0;

  if (idle < min_idle)
    idle = min_idle + (idle % (max_idle - min_idle));

  return idle;
}
