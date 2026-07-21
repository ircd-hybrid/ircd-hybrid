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

#include "comm.h"
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

enum { LISTENER_ACCEPT_BUDGET = 128 };

static void
_listener_accept_connection(fde_t *F, void *data_)
{
  struct Listener *const listener = data_;
  assert(listener);
  assert(listener->fde == F);
  assert(listener->fde);
  assert(listener->fde->flags.open);

  const char *desc =
    listener_has_flag(listener, LISTENER_TLS) ? "Incoming TLS connection" : "Incoming connection";

  for (unsigned int accepted_count = 0; accepted_count < LISTENER_ACCEPT_BUDGET; ++accepted_count)
  {
    struct io_addr remote_addr;

    fde_t *const client_fde = comm_accept(listener->fde, &remote_addr, desc);
    if (client_fde == NULL)
    {
      /*
       * A recoverable error indicates the listen queue is now empty. For any
       * other error (e.g., a single connection failing setup), we continue
       * trying to accept other pending connections.
       */
      if (comm_errno_is_recoverable(errno))
        break;

      continue;
    }

    char remote_addr_str[HOSTIPLEN + 1];
    if (!address_to_string(&remote_addr, remote_addr_str, sizeof(remote_addr_str)))
    {
      log_write(LOG_TYPE_IRCD, "listener_accept_connection: address_to_string() failed for new connection");
      ++ServerStats.is_ref;
      comm_socket_close(client_fde);
      continue;
    }

    client_process_accepted_connection(client_fde, listener, &remote_addr, remote_addr_str);
  }

  /* Re-register a new IO request for the next accept .. */
  comm_setselect(listener->fde, COMM_SELECT_READ, _listener_accept_connection, listener);
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

  listener->fde = new_fde;
  /* Listen completion events are READ events .. */
  _listener_accept_connection(listener->fde, listener);
  return true;
}

static struct Listener *
_listener_find(const struct io_addr *addr)
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
_listener_close(struct Listener *listener)
{
  if (listener->fde)
  {
    assert(listener->fde->flags.open);

    comm_socket_close(listener->fde);
    listener->fde = NULL;
  }

  if (listener->ref_count)
    return;

  _listener_destroy(listener);
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
  if (!address_from_string(addr_string, &addr))
    return;

  if (!address_set_port(&addr, port))
    return;

  struct Listener *listener = _listener_find(&addr);
  if (listener == NULL)
    listener = _listener_create(&addr);

  listener->flags = flags;

  if (listener_is_active(listener))
    return;

  if (!_listener_finalize(listener))
    _listener_close(listener);
}
