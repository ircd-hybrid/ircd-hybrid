/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file server.c
 * \brief Server related functions.
 */

#include <assert.h>
#include <errno.h>
#include <string.h>

#include "comm.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"

#include "client.h"
#include "client_find.h"
#include "client_format.h"
#include "conf.h"
#include "conf_connect.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "packet.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"

/**
 * @brief Finds the first routable client in a list matching a wildcard mask.
 *
 * This is the internal helper for `server_route_command`'s wildcard matching
 * logic. Its primary responsibility is to encapsulate the search loop and the
 * anti-looping check.
 *
 * A route is considered invalid if the target's physical link (`nexthop`) is the
 * same as the source's, as this would route the command back to its origin.
 *
 * @param list The list of clients to search.
 * @param mask The wildcard mask to match against the client's name.
 * @param source The source of the command, used as the reference for the anti-looping check.
 * @return A pointer to the first matching and routable client, or `NULL` if none is found.
 */
static struct Client *
_server_route_find_match(const list_t *list, const char *mask, const struct Client *source)
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
  {
    struct Client *const target = node->data;
    if (match(mask, target->name) == 0)
    {
      /* Anti-looping check: ensure the route is not back to the source's link. */
      if (target->nexthop == source->nexthop && !client_is_local(target))
        continue;

      return target;
    }
  }

  return NULL;
}

/**
 * @brief Routes a command to the appropriate server or client.
 *
 * This function attempts to deliver a command to the specified server or client.
 * The command is a format string that must be prefixed (e.g., ":%s COMMAND %s ...").
 * The command can have up to 8 parameters.
 *
 * @param client The client issuing the command.
 * @param command The command to be delivered.
 * @param server The index in the parv array that identifies the target server.
 * @param parv The parameter array for the command, where parv[server] is the target server identifier.
 * @return A pointer to a server_route_t structure containing the result of the routing attempt.
 */
const server_route_t *
server_route_command(struct Client *client, const char *command, size_t server, char *parv[])
{
  static server_route_t r;
  server_route_t *const route = &r;

  const char *const mask = parv[server];
  /* Assume it's this server if no target is specified. */
  if (string_is_empty(mask))
  {
    route->target = &me;
    route->result = SERVER_ROUTE_ISME;
    return route;
  }

  /* Attempt to find the target as a user or server. */
  route->target = client_find_user(client, mask);
  if (route->target == NULL)
    route->target = client_find_server(client, mask);

  /*
   * Ensure the target is not from the same upstream server as the client,
   * unless the target is directly connected to this server. This prevents
   * incorrect routing of the message back upstream.
   */
  if (route->target)
    if (route->target->nexthop == client->nexthop && !client_is_local(route->target))
      route->target = NULL;

  /* Handle wildcard matches if no exact match was found. */
  if (route->target == NULL && has_wildcards(mask))
  {
    route->target = _server_route_find_match(&global_server_list, mask, client);
    if (route->target == NULL)
      route->target = _server_route_find_match(&global_client_list, mask, client);
  }

  /* Determine the result of the routing attempt. */
  if (route->target)
  {
    assert(client_is_me(route->target) || client_is_server(route->target) || client_is_user(route->target));
    if (client_is_me(route->target) || client_is_local_user(route->target))
    {
      route->result = SERVER_ROUTE_ISME;
      return route;
    }

    parv[server] = route->target->id;
    sendto_one(route->target, command, client->id,
               parv[1], parv[2], parv[3], parv[4],
               parv[5], parv[6], parv[7], parv[8]);
    route->result = SERVER_ROUTE_PASS;
    return route;
  }

  /* Handle case where the target was not found. */
  sendto_one_numeric(client, &me, ERR_NOSUCHSERVER, mask);
  route->result = SERVER_ROUTE_NOSUCH;
  return route;
}

static bool
_server_name_is_valid_char(unsigned char ch)
{
  return (ch >= 'A' && ch <= 'Z') ||
         (ch >= 'a' && ch <= 'z') ||
         (ch >= '0' && ch <= '9') || ch == '-' || ch == '.';
}

bool
server_is_valid_name(const char *name)
{
  if (string_is_empty(name))
    return false;

  if (strlen(name) > HOSTLEN)
    return false;

  bool has_dot = false;
  bool label_start = true;
  unsigned char previous = '\0';

  for (const unsigned char *p = (const unsigned char *)name; *p; ++p)
  {
    if (!_server_name_is_valid_char(*p))
      return false;

    if (*p == '.')
    {
      if (label_start)
        return false;

      if (previous == '-')
        return false;

      has_dot = true;
      label_start = true;
    }
    else
    {
      if (label_start && *p == '-')
        return false;

      label_start = false;
    }

    previous = *p;
  }

  if (label_start)
    return false;

  if (previous == '-')
    return false;

  return has_dot;
}

struct Server *
server_get_or_create(struct Client *client)
{
  if (client->server == NULL)
    client->server = io_calloc(sizeof(*client->server));

  return client->server;
}

void
server_destroy(struct Server *server)
{
  assert(server);
  assert(server->conf == NULL);
  assert(list_is_empty(&server->child_server_list));
  assert(server->child_server_list.head == NULL);
  assert(server->child_server_list.tail == NULL);
  assert(list_is_empty(&server->child_user_list));
  assert(server->child_user_list.head == NULL);
  assert(server->child_user_list.tail == NULL);

  io_free(server->initiator_name);
  io_free(server);
}

static void
_server_handshake_irc_start(struct Client *client)
{
  const struct ConnectItem *const connect = server_conf_get(client);
  assert(connect);

  client_set_class(client, connect->klass, CLIENT_CLASS_BASE);
  client_set_state(client, CLIENT_STATE_HANDSHAKE);

  /* Start the activity timer now that the link is ready for IRC traffic. */
  client_update_activity_timeout(client);

  sendto_one(client, "PASS %s", connect->send_password);
  sendto_one(client, "CAPAB :%s", capab_get(NULL, true));
  sendto_one(client, "SERVER %s 1 %s +%s :%s",
             me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);

  /* If we get here, we're ok, so lets start reading some data */
  read_packet(client->connection->fde, client);
}

static void
_server_handshake_tls_finish(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client->connection->fde);
  assert(client_has_flag(client, FLAGS_TLS_HANDSHAKING));
  assert(!client_has_flag(client, FLAGS_TLS_ACTIVE));

  client_unset_flag(client, FLAGS_TLS_HANDSHAKING);
  client_set_flag(client, FLAGS_TLS_ACTIVE);

  fde_t *fde = client->connection->fde;
  comm_setselect(fde, COMM_SELECT_WRITE | COMM_SELECT_READ, NULL, NULL);

  tls_session_get_peer_certificate_fingerprint(&fde->tls, &client->tls_certfp);

  const struct ConnectItem *const connect = server_conf_get(client);
  if (connect->active == false)
  {
    client_exit(client, "Configuration removed");
    return;
  }

  _server_handshake_irc_start(client);
}

static void
_server_handshake_tls_start(fde_t *fde, void *data_)
{
  struct Client *const client = data_;
  assert(fde);
  assert(client && client_is_local(client));

  /*
   * This callback may still fire for a client that has already
   * entered the shutdown path.
   */
  if (client_is_defunct(client))
    return;

  assert(client->connection->fde);
  assert(client->connection->fde == fde);

  tls_handshake_status_t ret = tls_session_handshake(&fde->tls, NULL);
  if (ret == TLS_HANDSHAKE_DONE)
  {
    _server_handshake_tls_finish(client);
    return;
  }

  switch (ret)
  {
    case TLS_HANDSHAKE_WANT_WRITE:
      comm_setselect(fde, COMM_SELECT_WRITE, _server_handshake_tls_start, client);
      break;
    case TLS_HANDSHAKE_WANT_READ:
      comm_setselect(fde, COMM_SELECT_READ, _server_handshake_tls_start, client);
      break;
    default:
      client_set_dead(client);  /* Prevent client_exit() from sending on a failed TLS socket. */
      client_exit(client, "Error during TLS handshake");
      break;
  }
}

static void
_server_tls_init(struct Client *client, const struct ConnectItem *connect, fde_t *fde)
{
  assert(client && client_is_local(client));
  assert(client->connection->fde);
  assert(client->connection->fde == fde);

  if (!tls_session_init(&fde->tls, fde->fd, TLS_ROLE_CLIENT))
  {
    client_set_dead(client);  /* Prevent client_exit() from sending on a failed TLS socket. */
    client_exit(client, "TLS context initialization failed");
    return;
  }

  client_set_flag(client, FLAGS_TLS_HANDSHAKING);
  client_update_activity_timeout(client);

  _server_handshake_tls_start(fde, client);
}

static void
_server_connect_callback(fde_t *fde, int status, void *data_)
{
  struct Client *const client = data_;
  assert(client && client_is_local(client));
  assert(client_is_connecting(client));

  /* Check the status */
  if (status != COMM_OK)
  {
    /* We have an error, so report it and quit */
    const char *const err_str = comm_errstr(status);

    client_set_dead(client);  /* Prevent client_exit() from sending on a failed or closed connect socket. */
    client_exit_fmt(client, "Connection failed: %s", err_str);
    return;
  }

  /* COMM_OK, so continue the connection procedure */
  assert(fde);
  assert(client->connection->fde == fde);

  const struct ConnectItem *const connect = server_conf_get(client);
  if (connect->active == false)
  {
    client_exit(client, "Configuration removed");
    return;
  }

  if (connect->flags & CONNECT_FLAG_USE_TLS)
    _server_tls_init(client, connect, fde);
  else
    _server_handshake_irc_start(client);
}

bool
server_connect(struct ConnectItem *connect, const struct Client *initiator)
{
  assert(connect);
  assert(connect->active);
  assert(connect->klass);
  assert(!string_is_empty(connect->name));
  assert(!string_is_empty(connect->host));
  assert(connect->port > 0);
  assert(connect->timeout > 0);
  assert(client_find_entity_by_name(connect->name) == NULL);

  /* Still processing a DNS lookup? -> exit */
  if (connect->dns_pending)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Error connecting to %s: DNS lookup for connect{} in progress.",
                   connect->name);
    return false;
  }

  if (connect->dns_failed)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Error connecting to %s: DNS lookup for connect{} failed.",
                   connect->name);
    return false;
  }

  char addr_str[HOSTIPLEN + 1];
  address_to_string(&connect->remote_addr, addr_str, sizeof(addr_str));

  log_write(LOG_TYPE_IRCD, "Connect to %s[%s] @%s", connect->name, connect->host, addr_str);

  /* Create a socket for the server connection */
  fde_t *const new_fde = comm_socket_create(address_get_family(&connect->remote_addr), SOCK_STREAM, 0, NULL);
  if (new_fde == NULL)
    return false;

  /* Create a local client */
  struct Client *const client = client_create_local();
  client->connection->fde = new_fde;

  address_copy(&client->addr, &connect->remote_addr);
  strlcpy(client->name, connect->name, sizeof(client->name));
  strlcpy(client->host, connect->host, sizeof(client->host));
  strlcpy(client->sockhost, addr_str, sizeof(client->sockhost));

  struct Server *const server = server_get_or_create(client);
  server_conf_set(client, connect);

  const char *const initiator_name = initiator ? initiator->name : "AutoConn.";
  server->initiator_name = io_strdup(initiator_name);

  client_set_state(client, CLIENT_STATE_CONNECTING);

  comm_socket_note(client->connection->fde, "Server: %s", client->name);

  list_add(client, &client->connection->node, &unknown_list);
  hash_add_client(client);

  /* Now, initiate the connection */
  comm_connect_tcp(client->connection->fde, &connect->remote_addr, connect->port, &connect->bind_addr,
                   _server_connect_callback, client, connect->timeout * 1000ULL);

  /*
   * At this point we have a connection in progress and a connect {} block
   * attached to the client, the socket info should be saved in the client
   * and it should either be resolved or have a valid address.
   *
   * The socket has been connected or connect is in progress.
   */
  return true;
}

void
server_connect_auto(void *unused)
{
  if (GlobalSetOptions.autoconnect == false)
    return;

  list_t *const list = connect_get_list();
  list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    struct ConnectItem *const connect = node->data;
    if (connect->active == false)
      continue;

    assert(connect->klass);
    assert(!string_is_empty(connect->name));
    assert(!string_is_empty(connect->host));

    if (connect->port == 0 || !(connect->flags & CONNECT_FLAG_ALLOW_AUTO_CONN))
      continue;

    /*
     * Skip this entry if the use of it is still on hold until
     * future. Otherwise handle this entry (and set it on hold
     * until next time). Will reset only hold times, if already
     * made one successfull connection... [this algorithm is
     * a bit fuzzy... -- msa >;) ]
     */
    const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
    if (connect->autoconnect_hold_until > now)
      continue;
    connect->autoconnect_hold_until = now + connect->klass->con_freq;

    if (connect->klass->ref_count >= connect->klass->max_total)
      continue;

    /* Skip if a server with this name is already connected or connecting. */
    if (client_find_entity_by_name(connect->name))
      continue;

    /*
     * Move this connect block to the end of the list so the next attempt
     * starts with a different server.
     */
    if (list->tail != node)
    {
      list_remove(node, list);
      list_add_tail(connect, node, list);
    }

    /*
     * We used to only print this if server_connect() actually
     * succeeded, but since comm_tcp_connect() can call the callback
     * immediately if there is an error, we were getting error messages
     * in the wrong order. SO, we just print out the activated line,
     * and let server_connect() / _server_connect_callback() print an
     * error afterwards if it fails.
     *   -- adrian
     */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "Connection to %s[%s] activated.",
                   connect->name, connect->host);
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE, "Connection to %s activated.",
                   connect->name);
    server_connect(connect, NULL);
    return;  /* We connect only one at time... */
  }
}

void
server_schedule_reconnect(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_server(client));

  struct ConnectItem *const connect = server_conf_get(client);
  if (connect == NULL)
    return;

  connect->autoconnect_hold_until =
    io_time_get(IO_TIME_MONOTONIC_SEC) + client_get_active_class(client)->con_freq;
}

struct ConnectItem *
server_conf_get(const struct Client *client)
{
  return client->server ? client->server->conf : NULL;
}

void
server_conf_set(struct Client *client, struct ConnectItem *new_connect)
{
  if (client->server == NULL)
    return;

  struct ConnectItem *const old_connect = server_conf_get(client);
  if (old_connect == new_connect)
    return;

  connect_incref(new_connect);
  connect_decref(old_connect);

  client->server->conf = new_connect;
}
