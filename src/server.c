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

/*! \file server.c
 * \brief Server related functions.
 */

#include "stdinc.h"
#include "comm.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "io_string.h"
#include "io_time.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "packet.h"
#include "conf.h"
#include "conf_connect.h"
#include "server.h"
#include "server_capab.h"
#include "send.h"
#include "parse.h"

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
server_route_command(struct Client *client, const char *command, const int server, char *parv[])
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

  /* Attempt to find the target as a person or server. */
  route->target = find_person(client, mask);
  if (route->target == NULL)
    route->target = hash_find_server(mask);

  /*
   * Ensure the target is not from the same upstream server as the client,
   * unless the target is directly connected to this server. This prevents
   * incorrect routing of the message back upstream.
   */
  if (route->target)
    if (route->target->from == client->from && !MyConnect(route->target))
      route->target = NULL;

  /* Handle wildcard matches if no exact match was found. */
  if (route->target == NULL && has_wildcards(mask))
  {
    list_node_t *node;
    LIST_FOREACH(node, global_server_list.head)
    {
      struct Client *tmp = node->data;

      assert(IsMe(tmp) || IsServer(tmp));
      if (match(mask, tmp->name) == 0)
      {
        if (tmp->from == client->from && !MyConnect(tmp))
          continue;

        route->target = tmp;
        break;
      }
    }

    if (route->target == NULL)
    {
      LIST_FOREACH(node, global_client_list.head)
      {
        struct Client *tmp = node->data;

        assert(IsClient(tmp));
        if (match(mask, tmp->name) == 0)
        {
          if (tmp->from == client->from && !MyConnect(tmp))
            continue;

          route->target = tmp;
          break;
        }
      }
    }
  }

  /* Determine the result of the routing attempt. */
  if (route->target)
  {
    assert(IsMe(route->target) || IsServer(route->target) || IsClient(route->target));
    if (IsMe(route->target) || MyClient(route->target))
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

bool
server_valid_name(const char *name)
{
  unsigned int dots = 0;
  const char *p = name;

  for (; *p; ++p)
  {
    if (!IsServChar(*p))
      return false;

    if (*p == '.')
      ++dots;
  }

  return dots && (p - name) <= HOSTLEN;
}

/* server_make()
 *
 * inputs       - pointer to client struct
 * output       - pointer to struct Server
 * side effects - add's an Server information block to a client
 *                if it was not previously allocated.
 */
struct Server *
server_make(struct Client *client)
{
  if (client->serv == NULL)
    client->serv = io_calloc(sizeof(*client->serv));

  return client->serv;
}

static void
server_finish_tls_handshake(struct Client *client)
{
  const struct ConnectItem *const connect = server_conf_get(client);
  if (connect->active == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Error connecting to %s: connect{} block was removed",
                   client_get_name(client, SHOW_IP));
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Error connecting to %s: connect{} block was removed",
                   client_get_name(client, MASK_IP));

    client_exit(client, "Configuration removed");
    return;
  }

  client_set_class(client, connect->class, CLIENT_CLASS_BASE);
  /* Next, send the initial handshake */
  SetHandshake(client);
  AddFlag(client, FLAGS_TLS);

  sendto_one(client, "PASS %s", connect->send_password);

  sendto_one(client, "CAPAB :%s", capab_get(NULL, true));

  sendto_one(client, "SERVER %s 1 %s +%s :%s",
             me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);

  /* If we get here, we're ok, so lets start reading some data */
  read_packet(client->connection->fd, client);
}

static void
server_tls_handshake(fde_t *F, void *data_)
{
  struct Client *client = data_;
  const char *sslerr = NULL;

  assert(client);
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd == F);

  tls_handshake_status_t ret = tls_handshake(&F->tls, TLS_ROLE_CLIENT, &sslerr);
  if (ret != TLS_HANDSHAKE_DONE)
  {
    if ((io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic) > TLS_HANDSHAKE_TIMEOUT)
    {
      client_exit(client, "Timeout during TLS handshake");
      return;
    }

    switch (ret)
    {
      case TLS_HANDSHAKE_WANT_WRITE:
        comm_setselect(F, COMM_SELECT_WRITE,
                       server_tls_handshake, client, TLS_HANDSHAKE_TIMEOUT);
        return;
      case TLS_HANDSHAKE_WANT_READ:
        comm_setselect(F, COMM_SELECT_READ,
                       server_tls_handshake, client, TLS_HANDSHAKE_TIMEOUT);
        return;
      default:
      {
        sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Error connecting to %s: %s",
                       client->name, sslerr ? sslerr : "unknown TLS error");
        client_exit(client, "Error during TLS handshake");
        return;
      }
    }
  }

  comm_settimeout(F, 0, NULL, NULL);
  comm_setselect(F, COMM_SELECT_WRITE | COMM_SELECT_READ, NULL, NULL, 0);

  if (tls_verify_certificate(&F->tls, &client->tls_certfp) == false)
    log_write(LOG_TYPE_IRCD, "Server %s gave bad TLS client certificate",
              client_get_name(client, MASK_IP));

  server_finish_tls_handshake(client);
}

static void
server_tls_connect_init(struct Client *client, const struct ConnectItem *connect, fde_t *F)
{
  assert(client);
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd == F);

  if (tls_new(&F->tls, F->fd, TLS_ROLE_CLIENT) == false)
  {
    SetDead(client);
    client_exit(client, "TLS context initialization failed");
    return;
  }

  if (!string_is_empty(connect->cipher_list))
    tls_set_ciphers(&F->tls, connect->cipher_list);

  server_tls_handshake(F, client);
}

/* server_connect_callback() - complete a server connection.
 *
 * This routine is called after the server connection attempt has
 * completed. If unsucessful, an error is sent to ops and the client
 * is closed. If sucessful, it goes through the initialisation/check
 * procedures, the capabilities are sent, and the socket is then
 * marked for reading.
 */
static void
server_connect_callback(fde_t *F, int status, void *data_)
{
  struct Client *const client = data_;

  /* First, make sure it's a real client! */
  assert(client);
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd == F);

  /* Check the status */
  if (status != COMM_OK)
  {
    /* We have an error, so report it and quit */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Error connecting to %s: %s",
                   client_get_name(client, SHOW_IP), comm_errstr(status));
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Error connecting to %s: %s",
                   client_get_name(client, MASK_IP), comm_errstr(status));

    /*
     * If a fd goes bad, call dead_link() the socket is no
     * longer valid for reading or writing.
     */
    dead_link_on_write(client, 0);
    return;
  }

  /* COMM_OK, so continue the connection procedure */
  /* Get the connect {} block */

  const struct ConnectItem *const connect = server_conf_get(client);
  if (connect->active == false)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Error connecting to %s: connect{} block was removed",
                   client_get_name(client, SHOW_IP));
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                   "Error connecting to %s: connect{} block was removed",
                   client_get_name(client, MASK_IP));

    client_exit(client, "Configuration removed");
    return;
  }

  if (connect->flags & CONNECT_FLAG_USE_TLS)
  {
    server_tls_connect_init(client, connect, F);
    return;
  }

  client_set_class(client, connect->class, CLIENT_CLASS_BASE);
  /* Next, send the initial handshake */
  SetHandshake(client);

  sendto_one(client, "PASS %s", connect->send_password);

  sendto_one(client, "CAPAB :%s", capab_get(NULL, true));

  sendto_one(client, "SERVER %s 1 %s +%s :%s",
             me.name, me.id, ConfigServerHide.hidden ? "h" : "", me.info);

  /* If we get here, we're ok, so lets start reading some data */
  read_packet(client->connection->fd, client);
}

/* server_connect() - initiate a server connection
 *
 * inputs	- pointer to conf
 *		- pointer to client doing the connect
 * output	-
 * side effects	-
 *
 * This code initiates a connection to a server. It first checks to make
 * sure the given server exists. If this is the case, it creates a socket,
 * creates a client, saves the socket information in the client, and
 * initiates a connection to the server through comm_connect_tcp(). The
 * completion of this goes through serv_completed_connection().
 *
 * We return 1 if the connection is attempted, since we don't know whether
 * it suceeded or not, and 0 if it fails in here somewhere.
 */
bool
server_connect(struct ConnectItem *connect, struct Client *initiator)
{
  assert(connect);
  assert(hash_find_server(connect->name) == NULL);  /* This should have been checked by the caller */

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

  char buf[HOSTIPLEN + 1];
  address_to_string(&connect->remote_addr, buf, sizeof(buf));
  log_write(LOG_TYPE_IRCD, "Connect to %s[%s] @%s", connect->name, connect->host, buf);

  /* Create a socket for the server connection */
  int fd = comm_socket(address_get_family(&connect->remote_addr), SOCK_STREAM, 0);
  if (fd == -1)
  {
    /* Eek, failure to create the socket */
    log_write(LOG_TYPE_IRCD, "opening stream socket to %s: %s",
              connect->name, strerror(errno));
    return false;
  }

  /* Create a local client */
  struct Client *client = client_make(NULL);

  /* Copy in the server, hostname, fd */
  strlcpy(client->name, connect->name, sizeof(client->name));
  strlcpy(client->host, connect->host, sizeof(client->host));

  /* We already converted the ip once, so lets use it - stu */
  strlcpy(client->sockhost, buf, sizeof(client->sockhost));

  address_copy(&client->addr, &connect->remote_addr);
  client->connection->fd = fd_open(fd, true, NULL);

  /* Server names are always guaranteed under HOSTLEN chars */
  fd_note(client->connection->fd, "Server: %s", client->name);

  server_make(client);
  server_conf_set(client, connect);

  const char *initiator_name = initiator ? initiator->name : "AutoConn.";
  client->serv->initiator_name = io_strdup(initiator_name);

  SetConnecting(client);

  /* Now, initiate the connection */
  comm_connect_tcp(client->connection->fd, &connect->remote_addr, connect->port, &connect->bind_addr,
                   server_connect_callback, client, connect->timeout);

  /*
   * At this point we have a connection in progress and a connect {} block
   * attached to the client, the socket info should be saved in the client
   * and it should either be resolved or have a valid address.
   *
   * The socket has been connected or connect is in progress.
   */
  return true;
}

/* server_connect_auto()
 *
 * inputs	- void pointer which is not used
 * output	- NONE
 * side effects	-
 * scan through configuration and try new connections.
 * Returns the calendar time when the next call to this
 * function should be made latest. (No harm done if this
 * is called earlier or later...)
 */
void
server_connect_auto(void *unused)
{
  if (GlobalSetOptions.autoconnect == false)
    return;

  list_node_t *node;
  list_t *list = connect_get_list();
  LIST_FOREACH(node, list->head)
  {
    struct ConnectItem *connect = node->data;
    assert(connect->class);

    /* Also when already connecting! (update holdtimes) --SRB */
    if (connect->port == 0 || !(connect->flags & CONNECT_FLAG_ALLOW_AUTO_CONN))
      continue;

    /*
     * Skip this entry if the use of it is still on hold until
     * future. Otherwise handle this entry (and set it on hold
     * until next time). Will reset only hold times, if already
     * made one successfull connection... [this algorithm is
     * a bit fuzzy... -- msa >;) ]
     */
    if (connect->autoconnect_hold_until > io_time_get(IO_TIME_MONOTONIC_SEC))
      continue;

    connect->autoconnect_hold_until = io_time_get(IO_TIME_MONOTONIC_SEC) + connect->class->con_freq;

    if (connect->class->ref_count >= connect->class->max_total)
      continue;

    /*
     * Found a CONNECT config with port specified, scan clients
     * and see if this server is already connected?
     */
    if (hash_find_server(connect->name))
      continue;

    if (find_servconn_in_progress(connect->name))
      continue;

    /* Move this entry to the end of the list, if not already last */
    if (node->next)
    {
      list_remove(node, list);
      list_add_tail(connect, &connect->node, list);
    }

    /*
     * We used to only print this if server_connect() actually
     * succeeded, but since comm_tcp_connect() can call the callback
     * immediately if there is an error, we were getting error messages
     * in the wrong order. SO, we just print out the activated line,
     * and let server_connect() / server_connect_callback() print an
     * error afterwards if it fails.
     *   -- adrian
     */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   ConfigServerHide.hide_server_ips ? "Connection to %s activated." : "Connection to %s[%s] activated.",
                   connect->name, connect->host);

    server_connect(connect, NULL);
    return;  /* We connect only one at time... */
  }
}

struct ConnectItem *
server_conf_get(const struct Client *client)
{
  if (client->serv)
    return client->serv->conf;

  return NULL;
}

void
server_conf_clear(struct Client *client)
{
  if (client->serv && client->serv->conf)
  {
    connect_decref(client->serv->conf);
    client->serv->conf = NULL;
  }
}

void
server_conf_set(struct Client *client, struct ConnectItem *new_connect)
{
  assert(client->serv);
  assert(new_connect);

  struct ConnectItem *old_connect = server_conf_get(client);
  if (old_connect == new_connect)
    return;

  if (old_connect)
    server_conf_clear(client);

  client->serv->conf = new_connect;
  connect_incref(new_connect);
}

struct Client *
find_servconn_in_progress(const char *name)
{
  list_node_t *ptr;

  LIST_FOREACH(ptr, unknown_list.head)
  {
    struct Client *cptr = ptr->data;

    if (cptr->name[0])
      if (!irccmp(name, cptr->name))
        return cptr;
  }

  return NULL;
}
