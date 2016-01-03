/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2016 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
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

static dlink_list listener_list;

const dlink_list *
listener_get_list(void)
{
  return &listener_list;
}

static struct Listener *
listener_make(const int port, const struct irc_ssaddr *addr)
{
  struct Listener *listener = xcalloc(sizeof(struct Listener));

  listener->port = port;
  memcpy(&listener->addr, addr, sizeof(struct irc_ssaddr));

  return listener;
}

static void
listener_free(struct Listener *listener)
{
  dlinkDelete(&listener->node, &listener_list);
  xfree(listener);
}

/*
 * listener_get_name - return displayable listener name and port
 * returns "host.foo.org/6667" for a given listener
 */
const char *
listener_get_name(const struct Listener *const listener)
{
  static char buf[HOSTLEN + HOSTIPLEN + PORTNAMELEN + 4];  /* +4 for [,/,],\0 */

  snprintf(buf, sizeof(buf), "%s[%s/%u]", me.name,
           listener->name, listener->port);
  return buf;
}

static void
listener_accept_connection(fde_t *pfd, void *data)
{
  static time_t rate = 0;
  struct irc_ssaddr addr;
  int fd;
  int pe;
  struct Listener *const listener = data;

  assert(listener);

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
  while ((fd = comm_accept(listener, &addr)) != -1)
  {
    /*
     * check for connection limit
     */
    if (number_fd > hard_fdlimit - 10)
    {
      ++ServerStats.is_ref;
      sendto_realops_flags_ratelimited(&rate, "All connections in use. (%s)",
                                       listener_get_name(listener));

      if (!(listener->flags & LISTENER_SSL))
        send(fd, ALLINUSE_WARNING, sizeof(ALLINUSE_WARNING) - 1, 0);

      close(fd);
      break;    /* jump out and re-register a new io request */
    }

    /*
     * Do an initial check we aren't connecting too fast or with too many
     * from this IP...
     */
    if ((pe = conf_connect_allowed(&addr, addr.ss.ss_family)))
    {
      ++ServerStats.is_ref;

      if (!(listener->flags & LISTENER_SSL))
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
  comm_setselect(&listener->fd, COMM_SELECT_READ, listener_accept_connection,
                 listener, 0);
}


/*
 * inetport - create a listener socket in the AF_INET or AF_INET6 domain,
 * bind it to the port given in 'port' and listen to it
 * returns true (1) if successful false (0) on error.
 *
 * If the operating system has a define for SOMAXCONN, use it, otherwise
 * use HYBRID_SOMAXCONN
 */
#ifdef SOMAXCONN
#undef HYBRID_SOMAXCONN
#define HYBRID_SOMAXCONN SOMAXCONN
#endif

static int
inetport(struct Listener *listener)
{
  struct irc_ssaddr lsin;
  socklen_t opt = 1;

  memset(&lsin, 0, sizeof(lsin));
  memcpy(&lsin, &listener->addr, sizeof(lsin));

  getnameinfo((const struct sockaddr *)&lsin, lsin.ss_len, listener->name,
              sizeof(listener->name), NULL, 0, NI_NUMERICHOST);

  /*
   * At first, open a new socket
   */
  if (comm_open(&listener->fd, listener->addr.ss.ss_family, SOCK_STREAM, 0,
                "Listener socket") == -1)
  {
    report_error(L_ALL, "opening listener socket %s:%s",
                 listener_get_name(listener), errno);
    return 0;
  }

  if (setsockopt(listener->fd.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
  {
    report_error(L_ALL, "setting SO_REUSEADDR for listener %s:%s",
                 listener_get_name(listener), errno);
    fd_close(&listener->fd);
    return 0;
  }

  /*
   * Bind a port to listen for new connections if port is non-null,
   * else assume it is already open and try get something from it.
   */
  lsin.ss_port = htons(listener->port);

  if (bind(listener->fd.fd, (struct sockaddr *)&lsin, lsin.ss_len))
  {
    report_error(L_ALL, "binding listener socket %s:%s",
                 listener_get_name(listener), errno);
    fd_close(&listener->fd);
    return 0;
  }

  if (listen(listener->fd.fd, HYBRID_SOMAXCONN))
  {
    report_error(L_ALL, "listen failed for %s:%s",
                 listener_get_name(listener), errno);
    fd_close(&listener->fd);
    return 0;
  }

  /* Listen completion events are READ events .. */

  listener_accept_connection(&listener->fd, listener);
  return 1;
}

static struct Listener *
listener_find(int port, struct irc_ssaddr *addr)
{
  dlink_node *node;
  struct Listener *listener    = NULL;
  struct Listener *last_closed = NULL;

  DLINK_FOREACH(node, listener_list.head)
  {
    listener = node->data;

    if ((port == listener->port) &&
        (!memcmp(addr, &listener->addr, sizeof(struct irc_ssaddr))))
    {
      /* Try to return an open listener, otherwise reuse a closed one */
      if (!listener->fd.flags.open)
        last_closed = listener;
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
  if (listener->fd.flags.open)
    fd_close(&listener->fd);

  listener->active = 0;

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
  dlink_node *node = NULL, *node_next = NULL;

  /* close all 'extra' listening ports we have */
  DLINK_FOREACH_SAFE(node, node_next, listener_list.head)
    listener_close(node->data);
}

void
listener_release(struct Listener *listener)
{
  assert(listener->ref_count > 0);

  if (--listener->ref_count == 0 && !listener->active)
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
  struct Listener *listener;
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

  memset(&vaddr, 0, sizeof(vaddr));

  /* Set up the hints structure */
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  /* Get us ready for a bind() and don't bother doing dns lookup */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  /* TBD: This makes no sense here at all. Needs to be reworked */

  snprintf(portname, sizeof(portname), "%d", port);
  getaddrinfo("::", portname, &hints, &res);
  vaddr.ss.ss_family = AF_INET6;

  assert(res);

  memcpy((struct sockaddr*)&vaddr, res->ai_addr, res->ai_addrlen);
  vaddr.ss_port = port;
  vaddr.ss_len = res->ai_addrlen;
  freeaddrinfo(res);
#ifdef MAKES_NO_SENSE
  {
    struct sockaddr_in *v4 = (struct sockaddr_in*) &vaddr;
    v4->sin_addr.s_addr = INADDR_ANY;
    vaddr.ss.ss_family = AF_INET;
    vaddr.ss_len = sizeof(struct sockaddr_in);
    v4->sin_port = htons(port);
  }
#endif

  snprintf(portname, PORTNAMELEN, "%d", port);

  if (!EmptyString(vhost_ip))
  {
    if (getaddrinfo(vhost_ip, portname, &hints, &res))
      return;

    assert(res);

    memcpy((struct sockaddr*)&vaddr, res->ai_addr, res->ai_addrlen);
    vaddr.ss_port = port;
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

  if ((listener = listener_find(port, &vaddr)))
  {
    listener->flags = flags;

    if (listener->fd.flags.open)
      return;
  }
  else
  {
    listener = listener_make(port, &vaddr);
    dlinkAdd(listener, &listener->node, &listener_list);
    listener->flags = flags;
  }

  if (inetport(listener))
    listener->active = 1;
  else
    listener_close(listener);
}
