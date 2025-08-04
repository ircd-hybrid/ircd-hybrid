/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2025 ircd-hybrid development team
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

/*! \file listener.c
 * \brief Implementation for handling listening sockets.
 */

#include "stdinc.h"
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "listener.h"
#include "client.h"
#include "fdlist.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "comm.h"
#include "conf.h"
#include "send.h"
#include "memory.h"

static list_t listener_list;

const list_t *
listener_get_list(void)
{
  return &listener_list;
}

static struct Listener *
listener_make(const struct io_addr *addr)
{
  struct Listener *listener = io_calloc(sizeof(*listener));
  address_copy(&listener->addr, addr);

  list_add(listener, &listener->node, &listener_list);

  return listener;
}

static void
listener_free(struct Listener *listener)
{
  list_remove(&listener->node, &listener_list);
  io_free(listener->name);
  io_free(listener);
}

void
listener_count_memory(unsigned int *count, size_t *bytes)
{
  *count = *bytes = 0;

  list_node_t *node;
  LIST_FOREACH(node, listener_list.head)
  {
    const struct Listener *const listener = node->data;
    ++*count;
    *bytes += sizeof(*listener);
    *bytes += strlen(listener->name) + 1;
  }
}

/*
 * ssl_handshake - let OpenSSL initialize the protocol. Register for
 * read/write events if necessary.
 */
static void
ssl_handshake(fde_t *F, void *data_)
{
  struct Client *client = data_;

  assert(client);
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd == F);

  tls_handshake_status_t ret = tls_handshake(&F->tls, TLS_ROLE_SERVER, NULL);
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
        comm_setselect(F, COMM_SELECT_WRITE, ssl_handshake, client, TLS_HANDSHAKE_TIMEOUT);
        return;
      case TLS_HANDSHAKE_WANT_READ:
        comm_setselect(F, COMM_SELECT_READ, ssl_handshake, client, TLS_HANDSHAKE_TIMEOUT);
        return;
      default:
        client_exit(client, "Error during TLS handshake");
        return;
    }
  }

  comm_settimeout(F, 0, NULL, NULL);
  comm_setselect(F, COMM_SELECT_WRITE | COMM_SELECT_READ, NULL, NULL, 0);

  if (tls_verify_certificate(&F->tls, &client->tls_certfp) == false)
    log_write(LOG_TYPE_IRCD, "Client %s gave bad TLS client certificate",
              client_get_name(client, MASK_IP));

  lookup_start(client);
}

/*
 * add_connection - creates a client which has just connected to us on
 * the given fd. The sockhost field is initialized with the ip# of the host.
 * An unique id is calculated now, in case it is needed for auth.
 * The client is sent to the auth module for verification, and not put in
 * any client list yet.
 */
static void
add_connection(fde_t *client_fde, struct Listener *listener, const struct io_addr *remote_addr, const char *remote_addr_str)
{
  struct Client *client = client_create_local();
  client->connection->fd = client_fde;

  address_copy(&client->addr, remote_addr);

  strlcpy(client->sockhost, remote_addr_str, sizeof(client->sockhost));

  if (client->sockhost[0] == ':' &&
      client->sockhost[1] == ':')
  {
    memmove(client->sockhost + 1, client->sockhost, sizeof(client->sockhost) - 1);
    client->sockhost[0] = '0';
  }

  strlcpy(client->host, client->sockhost, sizeof(client->host));

  client->connection->listener = listener;
  ++listener->ref_count;

  list_add(client, &client->connection->node, &unknown_list);

  if (listener_has_flag(listener, LISTENER_TLS))
  {
    if (tls_new(&client->connection->fd->tls, client->connection->fd->fd, TLS_ROLE_SERVER) == false)
    {
      SetDead(client);
      client_exit(client, "TLS context initialization failed");
      return;
    }

    client_set_flag(client, FLAGS_TLS);
    ssl_handshake(client->connection->fd, client);
  }
  else
    lookup_start(client);
}

enum { LISTENER_ACCEPT_BUDGET = 128 };

static void
listener_accept_connection(fde_t *F, void *data_)
{
  struct Listener *const listener = data_;
  struct io_addr remote_addr;
  unsigned int accepted_count = 0;

  assert(listener);
  assert(listener->fd == F);
  assert(listener->fd);
  assert(listener->fd->flags.open);

  /* There may be many reasons for error return, but
   * in otherwise correctly working environment the
   * probable cause is running out of file descriptors
   * (EMFILE, ENFILE or others?). The man pages for
   * accept don't seem to list these as possible,
   * although it's obvious that it may happen here.
   * Thus no specific errors are tested at this
   * point, just assume that connections cannot
   * be accepted until some old is closed first.
   */
  const char *desc = listener_has_flag(listener, LISTENER_TLS) ?
                       "Incoming TLS connection" : "Incoming connection";

  fde_t *client_fde;
  while (accepted_count < LISTENER_ACCEPT_BUDGET &&
         (client_fde = comm_accept(listener->fd, &remote_addr, desc)))
  {
    ++accepted_count;

    char remote_addr_str[HOSTIPLEN + 1];
    if (address_to_string(&remote_addr, remote_addr_str, sizeof(remote_addr_str)) == false)
    {
      log_write(LOG_TYPE_IRCD, "listener_accept_connection: address_to_string() failed for new connection");
      comm_socket_close(client_fde);
      continue;
    }

    /*
     * check for connection limit
     */
    if (number_fd > hard_fdlimit - 10)
    {
      static uintmax_t rate = 0;
      sendto_clients_ratelimited(&rate, "Refused connection from %s on listener [%s/%hu]: server full",
                                 remote_addr_str, listener_get_name(listener), listener_get_port(listener));

      ++ServerStats.is_ref;
      comm_socket_close(client_fde);
      continue;  /* drop the one and keep on clearing the queue */
    }

    /*
     * Do an initial check we aren't connecting too fast or with too many
     * from this IP...
     */
    int pe = conf_connect_allowed(&remote_addr);
    if (pe)
    {
      log_write(LOG_TYPE_DEBUG, "Refused connection from %s on listener [%s/%hu]: %s",
                remote_addr_str, listener_get_name(listener), listener_get_port(listener),
                pe == BANNED_CLIENT ? "D-lined" : "Throttled");

      ++ServerStats.is_ref;
      comm_socket_close(client_fde);
      continue;    /* drop the one and keep on clearing the queue */
    }

    ++ServerStats.is_ac;
    add_connection(client_fde, listener, &remote_addr, remote_addr_str);
  }

  /* Re-register a new IO request for the next accept .. */
  comm_setselect(listener->fd, COMM_SELECT_READ, listener_accept_connection, listener, 0);
}

/**
 * @var LISTEN_BACKLOG
 * @brief Enumeration for the backlog argument in the listen() function.
 *
 * This enum specifies the maximum length of the queue of pending connections
 * that the listen() function can handle. When a connection request arrives
 * and the queue is full, the request may be refused, depending on the system's
 * behavior.
 */
enum { LISTEN_BACKLOG = 511 };

static bool
listener_finalize(struct Listener *listener)
{
  char buf[HOSTIPLEN + 1];
  address_to_string(&listener->addr, buf, sizeof(buf));

  if (buf[0] == ':' && buf[1] == ':')
  {
    memmove(buf + 1, buf, sizeof(buf) - 1);
    buf[0] = '0';
  }

  listener->name = io_strdup(buf);

  fde_t *new_fde = comm_socket_listen(&listener->addr, LISTEN_BACKLOG, "Listener socket");
  if (new_fde == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Failed to initialize listener for %s/%hu",
              listener_get_name(listener), listener_get_port(listener));
    return false;
  }

#ifdef TCP_DEFER_ACCEPT
  if (listener_has_flag(listener, LISTENER_DEFER))
  {
    int timeout = 1;
    setsockopt(new_fde->fd, IPPROTO_TCP, TCP_DEFER_ACCEPT, &timeout, sizeof(timeout));
  }
#endif

#ifdef SO_ACCEPTFILTER
  if (listener_has_flag(listener, LISTENER_DEFER))
  {
    struct accept_filter_arg afa;
    memset(&afa, 0, sizeof(afa));

    strlcpy(afa.af_name, "dataready", sizeof(afa.af_name));
    setsockopt(new_fde->fd, SOL_SOCKET, SO_ACCEPTFILTER, &afa, sizeof(afa));
  }
#endif

  listener->fd = new_fde;
  /* Listen completion events are READ events .. */
  listener_accept_connection(listener->fd, listener);
  return true;
}

static struct Listener *
listener_find(const struct io_addr *addr)
{
  struct Listener *last_closed = NULL;

  list_node_t *node;
  LIST_FOREACH(node, listener_list.head)
  {
    struct Listener *listener = node->data;
    if (memcmp(addr, &listener->addr, sizeof(*addr)) == 0)
    {
      /* Try to return an open listener, otherwise reuse a closed one */
      if (listener_is_active(listener))
        return listener;

      last_closed = listener;
    }
  }

  return last_closed;
}

/*
 * close_listener - close a single listener
 */
static void
listener_close(struct Listener *listener)
{
  if (listener->fd)
  {
    assert(listener->fd->flags.open);

    comm_socket_close(listener->fd);
    listener->fd = NULL;
  }

  if (listener->ref_count)
    return;

  listener_free(listener);
}

/*
 * listener_close_marked - close and free all listeners that are not being used
 */
void
listener_close_marked(void)
{
  list_node_t *node, *node_next;

  /* close all 'extra' listening ports we have */
  LIST_FOREACH_SAFE(node, node_next, listener_list.head)
    listener_close(node->data);
}

void
listener_release(struct Listener *listener)
{
  assert(listener->ref_count > 0);

  if (--listener->ref_count == 0 && listener_is_active(listener) == false)
    listener_close(listener);
}

/*
 * listener_add- create a new listener
 * port - the port number to listen on
 * vhost_ip - if non-null must contain a valid IP address string in
 * the format "255.255.255.255"
 */
void
listener_add(uint16_t port, const char *addr_string, listener_flag_t flags)
{
  /* If no or invalid port in conf line, don't bother. */
  if (port == 0)
    return;

  /* If ipv6 and no address specified we need to have two listeners; one for each protocol. */
  if (string_is_empty(addr_string))
  {
    listener_add(port, "0.0.0.0", flags);
    listener_add(port, "::", flags);
    return;
  }

  struct io_addr addr;
  if (address_from_string(addr_string, &addr) == false)
    return;

  address_set_port(&addr, port);

  struct Listener *listener = listener_find(&addr);
  if (listener == NULL)
    listener = listener_make(&addr);

  listener->flags = flags;

  if (listener_is_active(listener))
    return;

  if (listener_finalize(listener) == false)
    listener_close(listener);
}
