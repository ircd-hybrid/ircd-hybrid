/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2018 ircd-hybrid development team
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

/*! \file s_bsd.c
 * \brief Network functions.
 * \version $Id$
 */

#include "stdinc.h"
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include "list.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "client.h"
#include "dbuf.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "listener.h"
#include "numeric.h"
#include "packet.h"
#include "res.h"
#include "restart.h"
#include "conf.h"
#include "log.h"
#include "server.h"
#include "send.h"
#include "memory.h"
#include "user.h"


static const char *const comm_err_str[] =
{
  [COMM_OK] = "Comm OK",
  [COMM_ERR_BIND] = "Error during bind()",
  [COMM_ERR_DNS] = "Error during DNS lookup",
  [COMM_ERR_TIMEOUT] = "connect timeout",
  [COMM_ERR_CONNECT] = "Error during connect()",
  [COMM_ERROR] = "Comm Error"
};

static void comm_connect_callback(fde_t *, int);
static void comm_connect_timeout(fde_t *, void *);
static void comm_connect_dns_callback(void *, const struct irc_ssaddr *, const char *, size_t);
static void comm_connect_tryconnect(fde_t *, void *);


/* comm_get_sockerr - get the error value from the socket or the current errno
 *
 * Get the *real* error from the socket (well try to anyway..).
 * This may only work when SO_DEBUG is enabled but its worth the
 * gamble anyway.
 */
int
comm_get_sockerr(int fd)
{
  int errtmp = errno;
#ifdef SO_ERROR
  int err = 0;
  socklen_t len = sizeof(err);

  if (fd > -1 && !getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &len))
  {
    if (err)
      errtmp = err;
  }

  errno = errtmp;
#endif
  return errtmp;
}

/*
 * report_error - report an error from an errno.
 * Record error to log and also send a copy to all *LOCAL* opers online.
 *
 *        text        is a *format* string for outputing error. It must
 *                contain only two '%s', the first will be replaced
 *                by the sockhost from the client_p, and the latter will
 *                be taken from sys_errlist[errno].
 *
 *        client_p        if not NULL, is the *LOCAL* client associated with
 *                the error.
 *
 * Cannot use perror() within daemon. stderr is closed in
 * ircd and cannot be used. And, worse yet, it might have
 * been reassigned to a normal connection...
 *
 * Actually stderr is still there IFF ircd was run with -s --Rodder
 */
void
report_error(int level, const char *text, const char *who, int error)
{
  who = (who) ? who : "";

  sendto_realops_flags(UMODE_DEBUG, level, SEND_NOTICE,
                       text, who, strerror(error));
  ilog(LOG_TYPE_IRCD, text, who, strerror(error));
}

/*
 * setup_socket()
 *
 * Set the socket non-blocking, and other wonderful bits.
 */
static void
setup_socket(int fd)
{
  int opt = 1;

  setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt));

#ifdef IPTOS_LOWDELAY
  opt = IPTOS_LOWDELAY;
  setsockopt(fd, IPPROTO_IP, IP_TOS, &opt, sizeof(opt));
#endif

  fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
}

/*
 * ssl_handshake - let OpenSSL initialize the protocol. Register for
 * read/write events if necessary.
 */
static void
ssl_handshake(fde_t *F, void *data)
{
  struct Client *client_p = data;

  assert(client_p);
  assert(client_p->connection);
  assert(client_p->connection->fd);
  assert(client_p->connection->fd == F);

  tls_handshake_status_t ret = tls_handshake(&F->ssl, TLS_ROLE_SERVER, NULL);
  if (ret != TLS_HANDSHAKE_DONE)
  {
    if ((CurrentTime - client_p->connection->firsttime) > CONNECTTIMEOUT)
    {
      exit_client(client_p, "Timeout during TLS handshake");
      return;
    }

    switch (ret)
    {
      case TLS_HANDSHAKE_WANT_WRITE:
        comm_setselect(F, COMM_SELECT_WRITE, ssl_handshake, client_p, CONNECTTIMEOUT);
        return;
      case TLS_HANDSHAKE_WANT_READ:
        comm_setselect(F, COMM_SELECT_READ, ssl_handshake, client_p, CONNECTTIMEOUT);
        return;
      default:
        exit_client(client_p, "Error during TLS handshake");
        return;
    }
  }

  comm_settimeout(F, 0, NULL, NULL);

  if (!tls_verify_cert(&F->ssl, ConfigServerInfo.message_digest_algorithm, &client_p->certfp))
    ilog(LOG_TYPE_IRCD, "Client %s!%s@%s gave bad TLS client certificate",
         client_p->name, client_p->username, client_p->host);

  auth_start(client_p);
}

/*
 * add_connection - creates a client which has just connected to us on
 * the given fd. The sockhost field is initialized with the ip# of the host.
 * An unique id is calculated now, in case it is needed for auth.
 * The client is sent to the auth module for verification, and not put in
 * any client list yet.
 */
void
add_connection(struct Listener *listener, struct irc_ssaddr *irn, int fd)
{
  struct Client *client_p = client_make(NULL);

  client_p->connection->fd = fd_open(fd, true, (listener->flags & LISTENER_SSL) ?
                                     "Incoming SSL connection" : "Incoming connection");

  /*
   * copy address to 'sockhost' as a string, copy it to host too
   * so we have something valid to put into error messages...
   */
  memcpy(&client_p->ip, irn, sizeof(client_p->ip));

  getnameinfo((const struct sockaddr *)&client_p->ip,
              client_p->ip.ss_len, client_p->sockhost,
              sizeof(client_p->sockhost), NULL, 0, NI_NUMERICHOST);

  if (client_p->sockhost[0] == ':')
  {
    client_p->sockhost[0] = '0';
    memmove(client_p->sockhost + 1, client_p->sockhost, sizeof(client_p->sockhost) - 1);
  }

  strlcpy(client_p->host, client_p->sockhost, sizeof(client_p->host));

  client_p->connection->listener = listener;
  ++listener->ref_count;

  if (listener->flags & LISTENER_SSL)
  {
    if (!tls_new(&client_p->connection->fd->ssl, fd, TLS_ROLE_SERVER))
    {
      SetDead(client_p);
      exit_client(client_p, "TLS context initialization failed");
      return;
    }

    AddFlag(client_p, FLAGS_SSL);
    ssl_handshake(client_p->connection->fd, client_p);
  }
  else
    auth_start(client_p);
}

/*
 * stolen from squid - its a neat (but overused! :) routine which we
 * can use to see whether we can ignore this errno or not. It is
 * generally useful for non-blocking network IO related errnos.
 *     -- adrian
 */
int
comm_ignore_errno(int ierrno)
{
  switch (ierrno)
  {
    case EINPROGRESS:
    case EWOULDBLOCK:
#if EAGAIN != EWOULDBLOCK
    case EAGAIN:
#endif
    case EALREADY:
    case EINTR:
#ifdef ERESTART
    case ERESTART:
#endif
        return 1;
    default:
        return 0;
  }
}

/*
 * comm_settimeout() - set the socket timeout
 *
 * Set the timeout for the fd
 */
void
comm_settimeout(fde_t *F, uintmax_t timeout, void (*callback)(fde_t *, void *), void *cbdata)
{
  assert(F->flags.open == true);

  F->timeout = CurrentTime + (timeout / 1000);
  F->timeout_handler = callback;
  F->timeout_data = cbdata;
}

/*
 * comm_setflush() - set a flush function
 *
 * A flush function is simply a function called if found during
 * comm_timeouts(). Its basically a second timeout, except in this case
 * I'm too lazy to implement multiple timeout functions! :-)
 * its kinda nice to have it separate, since this is designed for
 * flush functions, and when comm_close() is implemented correctly
 * with close functions, we _actually_ don't call comm_close() here ..
 * -- originally Adrian's notes
 * comm_close() is replaced with fd_close() in fdlist.c
 */
void
comm_setflush(fde_t *F, uintmax_t timeout, void (*callback)(fde_t *, void *), void *cbdata)
{
  assert(F->flags.open == true);

  F->flush_timeout = CurrentTime + (timeout / 1000);
  F->flush_handler = callback;
  F->flush_data = cbdata;
}

/*
 * comm_checktimeouts() - check the socket timeouts
 *
 * All this routine does is call the given callback/cbdata, without closing
 * down the file descriptor. When close handlers have been implemented,
 * this will happen.
 */
void
comm_checktimeouts(void *unused)
{
  void (*hdl)(fde_t *, void *);
  void *data;

  for (int fd = 0; fd <= highest_fd; ++fd)
  {
    fde_t *F = &fd_table[fd];

    if (F->flags.open == false)
      continue;

    /* check flush functions */
    if (F->flush_handler && F->flush_timeout > 0 &&
        F->flush_timeout < CurrentTime)
    {
      hdl = F->flush_handler;
      data = F->flush_data;

      comm_setflush(F, 0, NULL, NULL);
      hdl(F, data);
    }

    /* check timeouts */
    if (F->timeout_handler && F->timeout > 0 &&
        F->timeout < CurrentTime)
    {
      /* Call timeout handler */
      hdl = F->timeout_handler;
      data = F->timeout_data;

      comm_settimeout(F, 0, NULL, NULL);
      hdl(F, data);
    }
  }
}

/*
 * void comm_connect_tcp(int fd, const char *host, unsigned short port,
 *                       struct sockaddr *clocal, int socklen,
 *                       CNCB *callback, void *data, int aftype, int timeout)
 * Input: An fd to connect with, a host and port to connect to,
 *        a local sockaddr to connect from + length(or NULL to use the
 *        default), a callback, the data to pass into the callback, the
 *        address family.
 * Output: None.
 * Side-effects: A non-blocking connection to the host is started, and
 *               if necessary, set up for selection. The callback given
 *               may be called now, or it may be called later.
 */
void
comm_connect_tcp(fde_t *F, const char *host, unsigned short port, struct sockaddr *clocal,
                 int socklen, void (*callback)(fde_t *, int, void *), void *data,
                 int aftype, uintmax_t timeout)
{
  struct addrinfo hints, *res;
  char portname[PORTNAMELEN + 1];

  assert(callback);
  F->connect.callback = callback;
  F->connect.data = data;

  F->connect.hostaddr.ss.ss_family = aftype;
  F->connect.hostaddr.ss_port = htons(port);

  /* Note that we're using a passed sockaddr here. This is because
   * generally you'll be bind()ing to a sockaddr grabbed from
   * getsockname(), so this makes things easier.
   * XXX If NULL is passed as local, we should later on bind() to the
   * virtual host IP, for completeness.
   *   -- adrian
   */
  if (clocal && bind(F->fd, clocal, socklen) < 0)
  {
    /* Failure, call the callback with COMM_ERR_BIND */
    comm_connect_callback(F, COMM_ERR_BIND);
    return;  /* ... and quit */
  }

  memset(&hints, 0, sizeof(hints));

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  snprintf(portname, sizeof(portname), "%d", port);

  /*
   * Next, if we have been given an IP address, get the address and skip the
   * DNS check (and head direct to comm_connect_tryconnect()).
   */
  if (getaddrinfo(host, portname, &hints, &res))
  {
    /* Send the DNS request, for the next level */
    if (aftype == AF_INET6)
      gethost_byname_type(comm_connect_dns_callback, F, host, T_AAAA);
    else
      gethost_byname_type(comm_connect_dns_callback, F, host, T_A);
  }
  else
  {
    /* We have a valid IP, so we just call tryconnect */
    /* Make sure we actually set the timeout here .. */
    assert(res);

    memcpy(&F->connect.hostaddr, res->ai_addr, res->ai_addrlen);
    F->connect.hostaddr.ss_len = res->ai_addrlen;
    F->connect.hostaddr.ss.ss_family = res->ai_family;

    freeaddrinfo(res);

    comm_settimeout(F, timeout * 1000, comm_connect_timeout, NULL);
    comm_connect_tryconnect(F, NULL);
  }
}

/*
 * comm_connect_callback() - call the callback, and continue with life
 */
static void
comm_connect_callback(fde_t *F, int status)
{
  void (*hdl)(fde_t *, int, void *);

  /* This check is gross..but probably necessary */
  if (F->connect.callback == NULL)
    return;

  /* Clear the connect flag + handler */
  hdl = F->connect.callback;
  F->connect.callback = NULL;

  /* Clear the timeout handler */
  comm_settimeout(F, 0, NULL, NULL);

  /* Call the handler */
  hdl(F, status, F->connect.data);
}

/*
 * comm_connect_timeout() - this gets called when the socket connection
 * times out. This *only* can be called once connect() is initially
 * called ..
 */
static void
comm_connect_timeout(fde_t *F, void *unused)
{
  /* error! */
  comm_connect_callback(F, COMM_ERR_TIMEOUT);
}

/*
 * comm_connect_dns_callback() - called at the completion of the DNS request
 *
 * The DNS request has completed, so if we've got an error, return it,
 * otherwise we initiate the connect()
 */
static void
comm_connect_dns_callback(void *vptr, const struct irc_ssaddr *addr, const char *name, size_t namelength)
{
  fde_t *const F = vptr;

  if (addr == NULL)
  {
    comm_connect_callback(F, COMM_ERR_DNS);
    return;
  }

  /* No error, set a 30 second timeout */
  comm_settimeout(F, 30 * 1000, comm_connect_timeout, NULL);

  /* Copy over the DNS reply info so we can use it in the connect() */
  /*
   * Note we don't fudge the refcount here, because we aren't keeping
   * the DNS record around, and the DNS cache is gone anyway..
   *     -- adrian
   */
  memcpy(&F->connect.hostaddr, addr, addr->ss_len);

  /* The cast is hacky, but safe - port offset is same on v4 and v6 */
  ((struct sockaddr_in *)&F->connect.hostaddr)->sin_port = F->connect.hostaddr.ss_port;
  F->connect.hostaddr.ss_len = addr->ss_len;

  /* Now, call the tryconnect() routine to try a connect() */
  comm_connect_tryconnect(F, NULL);
}

/* static void comm_connect_tryconnect(fde_t *fd, void *unused)
 * Input: The fd, the handler data(unused).
 * Output: None.
 * Side-effects: Try and connect with pending connect data for the FD. If
 *               we succeed or get a fatal error, call the callback.
 *               Otherwise, it is still blocking or something, so register
 *               to select for a write event on this FD.
 */
static void
comm_connect_tryconnect(fde_t *F, void *unused)
{
  /* This check is needed or re-entrant s_bsd_* like sigio break it. */
  if (F->connect.callback == NULL)
    return;

  /* Try the connect() */
  int retval = connect(F->fd, (struct sockaddr *)&F->connect.hostaddr, F->connect.hostaddr.ss_len);

  /* Error? */
  if (retval < 0)
  {
    /*
     * If we get EISCONN, then we've already connect()ed the socket,
     * which is a good thing.
     *   -- adrian
     */
    if (errno == EISCONN)
      comm_connect_callback(F, COMM_OK);
    else if (comm_ignore_errno(errno))
      /* Ignore error? Reschedule */
      comm_setselect(F, COMM_SELECT_WRITE, comm_connect_tryconnect, NULL, 0);
    else
      /* Error? Fail with COMM_ERR_CONNECT */
      comm_connect_callback(F, COMM_ERR_CONNECT);
    return;
  }

  /* If we get here, we've suceeded, so call with COMM_OK */
  comm_connect_callback(F, COMM_OK);
}

/*
 * comm_errorstr() - return an error string for the given error condition
 */
const char *
comm_errstr(int error)
{
  if (error < 0 || error >= COMM_ERR_MAX)
    return "Invalid error number!";
  return comm_err_str[error];
}

/*
 * comm_open() - open a socket
 *
 * This is a highly highly cut down version of squid's comm_open() which
 * for the most part emulates socket(), *EXCEPT* it fails if we're about
 * to run out of file descriptors.
 */
int
comm_socket(int family, int sock_type, int proto)
{
  /* First, make sure we aren't going to run out of file descriptors */
  if (number_fd >= hard_fdlimit)
  {
    errno = ENFILE;
    return -1;
  }

  /*
   * Next, we try to open the socket. We *should* drop the reserved FD
   * limit if/when we get an error, but we can deal with that later.
   * XXX !!! -- adrian
   */
  int fd = socket(family, sock_type, proto);
  if (fd < 0)
    return -1; /* errno will be passed through, yay.. */

  setup_socket(fd);

  return fd;
}

/*
 * comm_accept() - accept an incoming connection
 *
 * This is a simple wrapper for accept() which enforces FD limits like
 * comm_open() does. Returned fd must be either closed or tagged with
 * fd_open (this function no longer does it).
 */
int
comm_accept(int fd, struct irc_ssaddr *addr)
{
  socklen_t addrlen = sizeof(struct irc_ssaddr);

  if (number_fd >= hard_fdlimit)
  {
    errno = ENFILE;
    return -1;
  }

  memset(addr, 0, sizeof(*addr));

  /*
   * Next, do the accept(). if we get an error, we should drop the
   * reserved fd limit, but we can deal with that when comm_open()
   * also does it. XXX -- adrian
   */
  int new_fd = accept(fd, (struct sockaddr *)addr, &addrlen);
  if (new_fd < 0)
    return -1;

  remove_ipv6_mapping(addr);

  setup_socket(new_fd);

  /* .. and return */
  return new_fd;
}

/*
 * remove_ipv6_mapping() - Removes IPv4-In-IPv6 mapping from an address
 * OSes with IPv6 mapping listening on both
 * AF_INET and AF_INET6 map AF_INET connections inside AF_INET6 structures
 *
 */
void
remove_ipv6_mapping(struct irc_ssaddr *addr)
{
  if (addr->ss.ss_family == AF_INET6)
  {
    if (IN6_IS_ADDR_V4MAPPED(&((struct sockaddr_in6 *)addr)->sin6_addr))
    {
      struct sockaddr_in6 v6;
      struct sockaddr_in *v4 = (struct sockaddr_in *)addr;

      memcpy(&v6, addr, sizeof(v6));
      memset(v4, 0, sizeof(struct sockaddr_in));
      memcpy(&v4->sin_addr, &v6.sin6_addr.s6_addr[12], sizeof(v4->sin_addr));

      addr->ss.ss_family = AF_INET;
      addr->ss_len = sizeof(struct sockaddr_in);
    }
    else
      addr->ss_len = sizeof(struct sockaddr_in6);
  }
  else
    addr->ss_len = sizeof(struct sockaddr_in);
}
