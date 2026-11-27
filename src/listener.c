/*
 * SPDX-FileCopyrightText: 1999-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file listener.c
 * \brief Implementation for handling listening sockets.
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>

#include "io_socket.h"
#include "io_string.h"
#include "io_time.h"
#include "log.h"
#include "memory.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "listener.h"
#include "send.h"

static list_t listener_list;

static void _listener_close(struct Listener *);

const list_t *
listener_get_list(void)
{
  return &listener_list;
}

static struct Listener *
_listener_create(const struct io_addr *addr)
{
  struct Listener *const listener = io_calloc(sizeof(*listener));
  address_copy(&listener->addr, addr);

  list_add_tail(listener, &listener->node, &listener_list);

  return listener;
}

static void
_listener_destroy(struct Listener *listener)
{
  list_remove(&listener->node, &listener_list);
  io_free(listener->name);
  io_free(listener);
}

enum { LISTENER_ACCEPT_BUDGET = 128 };

static void
_listener_accept_connection(int fd, void *context)
{
  struct Listener *const listener = context;
  (void)fd;
  assert(listener);
  assert(listener->socket && io_socket_fd(listener->socket) == fd);

  const char *desc =
    listener_has_flag(listener, LISTENER_TLS) ? "Incoming TLS connection" : "Incoming connection";

  listener_retain(listener);
  for (unsigned int accepted_count = 0;
       accepted_count < LISTENER_ACCEPT_BUDGET && listener_is_active(listener); ++accepted_count)
  {
    struct io_addr remote_addr;

    struct io_socket *const client_socket = io_socket_accept(listener->socket, &remote_addr, desc);
    if (client_socket == NULL)
    {
      /*
       * A recoverable error indicates the listen queue is now empty. For any
       * other error (e.g., a single connection failing setup), we continue
       * trying to accept other pending connections.
       */
      if (io_socket_errno_is_transient(errno))
        break;

      continue;
    }

    char remote_addr_str[HOSTIPLEN + 1];
    if (!address_to_string(&remote_addr, remote_addr_str, sizeof(remote_addr_str)))
    {
      log_write(LOG_TYPE_IRCD, "listener_accept_connection: address_to_string() failed for new connection");
      io_socket_close(client_socket);
      continue;
    }

    client_process_accepted_connection(client_socket, listener, &remote_addr, remote_addr_str);
  }

  if (listener_is_active(listener) &&
      io_socket_watch_read(listener->socket, _listener_accept_connection, listener) == -1)
  {
    log_write(LOG_TYPE_IRCD, "Failed to rearm listener %s/%hu: %s",
              listener_get_name(listener), listener_get_port(listener), strerror(errno));
    _listener_close(listener);
  }

  listener_release(listener);
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
_listener_finalize(struct Listener *listener)
{
  char buf[HOSTIPLEN + 1];

  if (!address_to_string(&listener->addr, buf, sizeof(buf)))
  {
    log_write(LOG_TYPE_IRCD, "listener_finalize: address_to_string() failed for listener");
    return false;
  }

  if (buf[0] == ':' && buf[1] == ':')
  {
    memmove(buf + 1, buf, sizeof(buf) - 1);
    buf[0] = '0';
  }

  io_free(listener->name);
  listener->name = io_strdup(buf);

  struct io_socket *const listener_socket =
    io_socket_listen(ircd_socket_context, &listener->addr, LISTEN_BACKLOG, "Listener socket");
  if (listener_socket == NULL)
  {
    log_write(LOG_TYPE_IRCD, "Failed to initialize listener for %s/%hu",
              listener_get_name(listener), listener_get_port(listener));
    return false;
  }

#ifdef TCP_DEFER_ACCEPT
  if (listener_has_flag(listener, LISTENER_DEFER))
  {
    const int timeout = 1;

    if (setsockopt(io_socket_fd(listener_socket), IPPROTO_TCP, TCP_DEFER_ACCEPT, &timeout, sizeof(timeout)) == -1)
    {
      log_write(LOG_TYPE_IRCD, "Failed to set TCP_DEFER_ACCEPT for listener %s/%hu: %s",
                listener_get_name(listener), listener_get_port(listener), strerror(errno));
      io_socket_close(listener_socket);
      return false;
    }
  }
#endif

#ifdef SO_ACCEPTFILTER
  if (listener_has_flag(listener, LISTENER_DEFER))
  {
    struct accept_filter_arg afa;
    memset(&afa, 0, sizeof(afa));

    strlcpy(afa.af_name, "dataready", sizeof(afa.af_name));

    if (setsockopt(io_socket_fd(listener_socket), SOL_SOCKET, SO_ACCEPTFILTER, &afa, sizeof(afa)) == -1)
    {
      log_write(LOG_TYPE_IRCD, "Failed to set SO_ACCEPTFILTER for listener %s/%hu: %s",
                listener_get_name(listener), listener_get_port(listener), strerror(errno));
      io_socket_close(listener_socket);
      return false;
    }
  }
#endif

  if (io_socket_watch_read(listener_socket, _listener_accept_connection, listener) == -1)
  {
    log_write(LOG_TYPE_IRCD, "Failed to watch listener %s/%hu: %s",
              listener_get_name(listener), listener_get_port(listener), strerror(errno));
    io_socket_close(listener_socket);
    return false;
  }

  listener->socket = listener_socket;
  return true;
}

static struct Listener *
_listener_find(const struct io_addr *addr)
{
  struct Listener *last_closed = NULL;

  list_node_t *node;
  LIST_FOREACH(node, listener_list.head)
  {
    struct Listener *const listener = node->data;
    if (!address_equal_with_port(addr, &listener->addr))
      continue;

    /* Try to return an open listener, otherwise reuse a closed one */
    if (listener_is_active(listener))
      return listener;

    last_closed = listener;
  }

  return last_closed;
}

static void
_listener_close(struct Listener *listener)
{
  if (listener->socket)
  {
    struct io_socket *const socket = listener->socket;
    listener->socket = NULL;
    io_socket_close(socket);
  }

  if (listener->ref_count)
    return;

  _listener_destroy(listener);
}

void
listener_close_all(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, listener_list.head)
    _listener_close(node->data);
}

void
listener_release(struct Listener *listener)
{
  assert(listener->ref_count > 0);

  if (--listener->ref_count == 0 && !listener_is_active(listener))
    _listener_close(listener);
}

void
listener_retain(struct Listener *listener)
{
  assert(listener);
  ++listener->ref_count;
}

listener_result_t
listener_add(uint16_t port, const char *addr_string, listener_flag_t flags)
{
  if (port == 0)
    return LISTENER_INVALID_PORT;

#ifndef HAVE_TLS
  if (flags & LISTENER_TLS)
    return LISTENER_TLS_UNAVAILABLE;
#endif

  /* If ipv6 and no address specified we need to have two listeners; one for each protocol. */
  if (string_is_empty(addr_string))
  {
    const listener_result_t ipv4_result = listener_add(port, "0.0.0.0", flags);
    const listener_result_t ipv6_result = listener_add(port, "::", flags);

    if (ipv4_result == LISTENER_SUCCESS && ipv6_result == LISTENER_SUCCESS)
      return LISTENER_SUCCESS;

    if (ipv4_result == LISTENER_SUCCESS || ipv6_result == LISTENER_SUCCESS)
      return LISTENER_PARTIAL_SUCCESS;

    return LISTENER_INITIALIZATION_FAILED;
  }

  struct io_addr addr;
  if (!address_from_string(addr_string, &addr))
    return LISTENER_INVALID_ADDRESS;

  if (!address_set_port(&addr, port))
    return LISTENER_INVALID_ADDRESS;

  struct Listener *listener = _listener_find(&addr);
  if (listener == NULL)
    listener = _listener_create(&addr);

  listener->flags = flags;

  if (listener_is_active(listener))
    return LISTENER_SUCCESS;

  if (!_listener_finalize(listener))
  {
    _listener_close(listener);
    return LISTENER_INITIALIZATION_FAILED;
  }

  return LISTENER_SUCCESS;
}

const char *
listener_result_to_string(listener_result_t result)
{
  switch (result)
  {
    case LISTENER_SUCCESS:
      return "Success";
    case LISTENER_PARTIAL_SUCCESS:
      return "Only one wildcard listener could be initialized";
    case LISTENER_INVALID_PORT:
      return "Invalid port";
    case LISTENER_INVALID_ADDRESS:
      return "Invalid IP address";
    case LISTENER_TLS_UNAVAILABLE:
      return "TLS support is not available";
    case LISTENER_INITIALIZATION_FAILED:
      return "Listener initialization failed";
  }

  return "Unknown listener result";
}
