/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2024 ircd-hybrid development team
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
#include "list.h"
#include "listener.h"
#include "client.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "s_bsd.h"
#include "conf.h"
#include "send.h"
#include "memory.h"

#define TOOFAST_WARNING "ERROR :Your host is trying to (re)connect too fast -- throttled.\r\n"
#define DLINE_WARNING "ERROR :You have been D-lined.\r\n"
#define ALLINUSE_WARNING "ERROR :All connections in use\r\n"

static list_t listener_list;

const list_t *
listener_get_list(void)
{
  return &listener_list;
}

static struct Listener *
listener_make(const int port, const struct irc_ssaddr *addr)
{
  struct Listener *listener = xcalloc(sizeof(*listener));

  listener->port = port;
  listener->addr = *addr;
  list_add(listener, &listener->node, &listener_list);

  return listener;
}

static void
listener_free(struct Listener *listener)
{
  list_delete(&listener->node, &listener_list);
  xfree(listener->name);
  xfree(listener);
}

/*
 * listener_get_name - return displayable listener name and port
 * returns "host.foo.org/6667" for a given listener
 */
const char *
listener_get_name(const struct Listener *listener)
{
  static char buf[HOSTLEN + HOSTIPLEN + PORTNAMELEN + 4];  /* +4 for [,/,],\0 */

  snprintf(buf, sizeof(buf), "%s[%s/%u]", me.name,
           listener->name, listener->port);
  return buf;
}

bool
listener_has_flag(const struct Listener *listener, unsigned int flags)
{
  if (listener && (listener->flags & flags))
    return true;
  return false;
}

void
listener_count_memory(unsigned int *count, size_t *bytes)
{
  (*count) = list_length(&listener_list);
  (*bytes) = *count * sizeof(struct Listener);
}

static void
listener_accept_connection(fde_t *F, void *data)
{
  static uintmax_t rate = 0;
  struct irc_ssaddr addr;
  int fd;
  int pe;
  struct Listener *const listener = data;

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
  while ((fd = comm_accept(listener->fd, &addr)) != -1)
  {
    /*
     * check for connection limit
     */
    if (number_fd > hard_fdlimit - 10)
    {
      ++ServerStats.is_ref;
      sendto_realops_flags_ratelimited(&rate, "All connections in use. (%s)",
                                       listener_get_name(listener));

      if (!(listener->flags & LISTENER_TLS))
        send(fd, ALLINUSE_WARNING, sizeof(ALLINUSE_WARNING) - 1, 0);

      close(fd);
      break;    /* jump out and re-register a new io request */
    }

    /*
     * Do an initial check we aren't connecting too fast or with too many
     * from this IP...
     */
    if ((pe = conf_connect_allowed(&addr)))
    {
      ++ServerStats.is_ref;

      if (!(listener->flags & LISTENER_TLS))
      {
        switch (pe)
        {
          case BANNED_CLIENT:
            send(fd, DLINE_WARNING, sizeof(DLINE_WARNING)-1, 0);
            break;
          case TOO_FAST:
            send(fd, TOOFAST_WARNING, sizeof(TOOFAST_WARNING)-1, 0);
            break;
        }
      }

      close(fd);
      continue;    /* drop the one and keep on clearing the queue */
    }

    ++ServerStats.is_ac;
    add_connection(listener, &addr, fd);
  }

  /* Re-register a new IO request for the next accept .. */
  comm_setselect(listener->fd, COMM_SELECT_READ, listener_accept_connection,
                 listener, 0);
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
enum { LISTEN_BACKLOG = 128 };

static bool
listener_finalize(struct Listener *listener)
{
  char buf[HOSTIPLEN + 1];
  const socklen_t opt = 1;

  getnameinfo((const struct sockaddr *)&listener->addr, listener->addr.ss_len,
              buf, sizeof(buf), NULL, 0, NI_NUMERICHOST);

  if (buf[0] == ':' && buf[1] == ':')
  {
    memmove(buf + 1, buf, sizeof(buf) - 1);
    buf[0] = '0';
  }

  listener->name = xstrdup(buf);

  /*
   * At first, open a new socket
   */
  int fd = comm_socket(listener->addr.ss.ss_family, SOCK_STREAM, 0);
  if (fd == -1)
  {
    report_error(L_ALL, "opening listener socket %s:%s",
                 listener_get_name(listener), errno);
    return false;
  }

#ifdef IPV6_V6ONLY
  if (listener->addr.ss.ss_family == AF_INET6 &&
      IN6_IS_ADDR_UNSPECIFIED(&((struct sockaddr_in6 *)&listener->addr)->sin6_addr))
  {
    if (setsockopt(fd, IPPROTO_IPV6, IPV6_V6ONLY, &opt, sizeof(opt)))
    {
      report_error(L_ALL, "setting IPV6_V6ONLY for listener %s:%s",
                   listener_get_name(listener), errno);
      close(fd);
      return false;
    }
  }
#endif

  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
  {
    report_error(L_ALL, "setting SO_REUSEADDR for listener %s:%s",
                 listener_get_name(listener), errno);
    close(fd);
    return false;
  }

  /*
   * Bind a port to listen for new connections if port is non-null,
   * else assume it is already open and try get something from it.
   */
  if (bind(fd, (const struct sockaddr *)&listener->addr, listener->addr.ss_len))
  {
    report_error(L_ALL, "binding listener socket %s:%s",
                 listener_get_name(listener), errno);
    close(fd);
    return false;
  }

  if (listen(fd, LISTEN_BACKLOG))
  {
    report_error(L_ALL, "listen failed for %s:%s",
                 listener_get_name(listener), errno);
    close(fd);
    return false;
  }

#ifdef TCP_DEFER_ACCEPT
  if (listener_has_flag(listener, LISTENER_DEFER))
  {
    int timeout = 1;

    setsockopt(fd, IPPROTO_TCP, TCP_DEFER_ACCEPT, &timeout, sizeof(timeout));
  }
#endif
#ifdef SO_ACCEPTFILTER
  if (listener_has_flag(listener, LISTENER_DEFER))
  {
    struct accept_filter_arg afa;

    memset(&afa, 0, sizeof(afa));
    strlcpy(afa.af_name, "dataready", sizeof(afa.af_name));
    setsockopt(fd, SOL_SOCKET, SO_ACCEPTFILTER, &afa, sizeof(afa));
  }
#endif

  listener->fd = fd_open(fd, true, "Listener socket");

  /* Listen completion events are READ events .. */

  listener_accept_connection(listener->fd, listener);
  return true;
}

static struct Listener *
listener_find(int port, struct irc_ssaddr *addr)
{
  list_node_t *node;
  struct Listener *listener    = NULL;
  struct Listener *last_closed = NULL;

  LIST_FOREACH(node, listener_list.head)
  {
    listener = node->data;

    if ((port == listener->port) &&
        (!memcmp(addr, &listener->addr, sizeof(*addr))))
    {
      /* Try to return an open listener, otherwise reuse a closed one */
      if (listener->fd)
      {
        assert(listener->fd->flags.open);
        last_closed = listener;
      }
      else
        return (listener);
    }
  }

  return (last_closed);
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

    fd_close(listener->fd);
    listener->fd = NULL;
  }

  listener->active = false;

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

  if (--listener->ref_count == 0 && listener->active == false)
    listener_close(listener);
}

/*
 * listener_add- create a new listener
 * port - the port number to listen on
 * vhost_ip - if non-null must contain a valid IP address string in
 * the format "255.255.255.255"
 */
void
listener_add(int port, const char *vhost_ip, unsigned int flags)
{
  struct irc_ssaddr vaddr;
  struct addrinfo hints, *res;
  char portname[PORTNAMELEN + 1];
  static short int pass = 0; /* if ipv6 and no address specified we need to
				have two listeners; one for each protocol. */

  /*
   * if no or invalid port in conf line, don't bother
   */
  if (!(port > 0 && port <= 0xFFFF))
    return;

  /* Set up the hints structure */
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  /* Get us ready for a bind() and don't bother doing dns lookup */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  snprintf(portname, sizeof(portname), "%d", port);

  getaddrinfo("::", portname, &hints, &res);
  assert(res);

  memcpy((struct sockaddr *)&vaddr, res->ai_addr, res->ai_addrlen);
  vaddr.ss_len = res->ai_addrlen;
  freeaddrinfo(res);

  if (!EmptyString(vhost_ip))
  {
    if (getaddrinfo(vhost_ip, portname, &hints, &res))
      return;

    assert(res);

    memcpy((struct sockaddr *)&vaddr, res->ai_addr, res->ai_addrlen);
    vaddr.ss_len = res->ai_addrlen;
    freeaddrinfo(res);
  }
  else if (pass == 0)
  {
    /* add the ipv4 listener if we havent already */
    pass = 1;
    listener_add(port, "0.0.0.0", flags);
  }

  pass = 0;

  struct Listener *listener = listener_find(port, &vaddr);
  if (listener)
  {
    listener->flags = flags;

    if (listener->fd)
    {
      assert(listener->fd->flags.open);
      return;
    }
  }
  else
  {
    listener = listener_make(port, &vaddr);
    listener->flags = flags;
  }

  if (listener_finalize(listener))
    listener->active = true;
  else
    listener_close(listener);
}
