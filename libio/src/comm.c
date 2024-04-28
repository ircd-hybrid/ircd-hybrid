/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include "address.h"
#include "fdlist.h"
#include "comm.h"
#include "event.h"

static const char *const comm_err_str[] =
{
  [COMM_OK] = "Comm OK",
  [COMM_ERR_BIND] = "Error during bind()",
  [COMM_ERR_TIMEOUT] = "connect timeout",
  [COMM_ERR_CONNECT] = "Error during connect()",
  [COMM_ERROR] = "Comm Error"
};

static void comm_connect_callback(fde_t *, int);
static void comm_connect_timeout(fde_t *, void *);
static void comm_connect_tryconnect(fde_t *, void *);


/* comm_get_sockerr - get the error value from the socket or the current errno
 *
 * Get the *real* error from the socket (well try to anyway..).
 * This may only work when SO_DEBUG is enabled but its worth the
 * gamble anyway.
 */
int
comm_get_sockerr(fde_t *F)
{
  int errtmp = errno;
#ifdef SO_ERROR
  int err = 0;
  socklen_t len = sizeof(err);

  assert(F);
  assert(F->flags.open == true);

  if (getsockopt(F->fd, SOL_SOCKET, SO_ERROR, &err, &len) == 0)
  {
    if (err)
      errtmp = err;
  }

  errno = errtmp;
#endif
  return errtmp;
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

#ifdef TCP_QUICKACK
  opt = 1;
  setsockopt(fd, SOL_SOCKET, TCP_QUICKACK, &opt, sizeof(opt));
#endif

  fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
}

/*
 * stolen from squid - its a neat (but overused! :) routine which we
 * can use to see whether we can ignore this errno or not. It is
 * generally useful for non-blocking network IO related errnos.
 *     -- adrian
 */
bool
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
      return true;
    default:
      return false;
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
  assert(F);
  assert(F->flags.open == true);

  F->timeout = timeout ? event_base->time.sec_monotonic + timeout : 0;
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
  assert(F);
  assert(F->flags.open == true);

  F->flush_timeout = timeout ? event_base->time.sec_monotonic + timeout : 0;
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
  for (int fd = 0; fd <= highest_fd; ++fd)
  {
    fde_t *F = &fd_table[fd];

    if (F->flags.open == false)
      continue;

    /* check flush functions */
    if (F->flush_timeout && F->flush_timeout < event_base->time.sec_monotonic)
    {
      void (*hdl)(fde_t *, void *) = F->flush_handler;
      void *data = F->flush_data;

      comm_setflush(F, 0, NULL, NULL);
      hdl(F, data);
    }

    /* check timeouts */
    if (F->timeout && F->timeout < event_base->time.sec_monotonic)
    {
      /* Call timeout handler */
      void (*hdl)(fde_t *, void *) = F->timeout_handler;
      void *data = F->timeout_data;

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
comm_connect_tcp(fde_t *F, const struct io_addr *caddr, unsigned short port, const struct io_addr *baddr,
                 void (*callback)(fde_t *, int, void *), void *data, uintmax_t timeout)
{
  assert(callback);

  F->connect.addr = *caddr;
  /* The cast is hacky, but safe - port offset is same on v4 and v6 */
  ((struct sockaddr_in *)&F->connect.addr)->sin_port = htons(port);
  F->connect.callback = callback;
  F->connect.data = data;

  /* Note that we're using a passed sockaddr here. This is because
   * generally you'll be bind()ing to a sockaddr grabbed from
   * getsockname(), so this makes things easier.
   * XXX If NULL is passed as local, we should later on bind() to the
   * virtual host IP, for completeness.
   *   -- adrian
   */
  if (baddr && bind(F->fd, (const struct sockaddr *)baddr, baddr->ss_len) < 0)
  {
    /* Failure, call the callback with COMM_ERR_BIND */
    comm_connect_callback(F, COMM_ERR_BIND);
    return;  /* ... and quit */
  }

  comm_settimeout(F, timeout, comm_connect_timeout, NULL);
  comm_connect_tryconnect(F, NULL);
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
  int retval = connect(F->fd, (struct sockaddr *)&F->connect.addr, F->connect.addr.ss_len);

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
comm_accept(fde_t *F, struct io_addr *addr)
{
  socklen_t addrlen = sizeof(*addr);

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
  int fd = accept(F->fd, (struct sockaddr *)addr, &addrlen);
  if (fd < 0)
    return -1;

  address_strip_ipv4(addr);

  setup_socket(fd);

  /* .. and return */
  return fd;
}
