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

/*! \file s_bsd.c
 * \brief Network functions.
 */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "address.h"
#include "comm.h"
#include "event.h"
#include "fdlist.h"
#include "io_time.h"
#include "log.h"
#include "memory.h"

static event_manager_t comm_event_manager;

static const char *const comm_err_str[] =
{
  [COMM_OK] = "Comm OK",
  [COMM_ERR_BIND] = "Error during bind()",
  [COMM_ERR_TIMEOUT] = "connect timeout",
  [COMM_ERR_CONNECT] = "Error during connect()",
  [COMM_ERROR] = "Comm Error"
};

struct comm_op_st
{
  fde_t *fde;
  struct io_addr remote_addr;
  void (*completion_handler)(fde_t *, int, void *);
  void *completion_handler_data;
  event_handle_t timeout_event;
};

void
comm_init(event_manager_t mgr)
{
  assert(comm_event_manager == NULL);
  comm_event_manager = mgr;

  comm_select_init();
}

/* comm_get_sockerr - get the error value from the socket or the current errno
 *
 * Get the *real* error from the socket (well try to anyway..).
 * This may only work when SO_DEBUG is enabled but its worth the
 * gamble anyway.
 */
int
comm_get_sockerr(fde_t *F)
{
  assert(F);
  assert(F->flags.open == true);

  int sock_err = 0;
  socklen_t len = sizeof(sock_err);
  if (getsockopt(F->fd, SOL_SOCKET, SO_ERROR, &sock_err, &len))
  {
    log_write(LOG_TYPE_DEBUG, "comm_get_sockerr: getsockopt(SO_ERROR) failed for FD %d: %s",
              F->fd, strerror(errno));
    return errno;
  }

  if (sock_err)
    return sock_err;
  return errno;
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

#define COMM_DEFAULT_SELECT_TIMEOUT_MS 500

int
comm_get_select_timeout(event_manager_t mgr)
{
  if (event_manager_get_active_count(mgr) == 0)
    return COMM_DEFAULT_SELECT_TIMEOUT_MS;

  uintmax_t next_fire_time_ms = event_manager_get_next_fire_time(mgr);
  uintmax_t current_time_ms = io_time_get_monotonic_ms_total();

  if (next_fire_time_ms <= current_time_ms)
    return 0;

  uintmax_t delta_ms = next_fire_time_ms - current_time_ms;
  if (delta_ms > COMM_DEFAULT_SELECT_TIMEOUT_MS)
    return COMM_DEFAULT_SELECT_TIMEOUT_MS;

  return (int)delta_ms;
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

  F->timeout = timeout ? io_time_get(IO_TIME_MONOTONIC_SEC) + timeout : 0;
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

  F->flush_timeout = timeout ? io_time_get(IO_TIME_MONOTONIC_SEC) + timeout : 0;
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
    if (F->flush_timeout && F->flush_timeout < io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      void (*hdl)(fde_t *, void *) = F->flush_handler;
      void *data = F->flush_data;

      comm_setflush(F, 0, NULL, NULL);
      hdl(F, data);
    }

    /* check timeouts */
    if (F->timeout && F->timeout < io_time_get(IO_TIME_MONOTONIC_SEC))
    {
      /* Call timeout handler */
      void (*hdl)(fde_t *, void *) = F->timeout_handler;
      void *data = F->timeout_data;

      comm_settimeout(F, 0, NULL, NULL);
      hdl(F, data);
    }
  }
}

static void
comm_connect_complete(comm_op_t *op, int status)
{
  assert(op);

  fde_t *F = op->fde;
  assert(F && F->flags.open == true);

  void (*hdl)(fde_t *, int, void *) = op->completion_handler;
  void *hdl_data = op->completion_handler_data;

  if (F->cleanup_data == op)
  {
    F->cleanup_handler = NULL;
    F->cleanup_data = NULL;
  }

  if (op->timeout_event)
  {
    event_destroy(op->timeout_event);
    op->timeout_event = NULL;
  }

  comm_setselect(F, COMM_SELECT_WRITE, NULL, NULL, 0);

  io_free(op);

  /* Call the handler */
  hdl(F, status, hdl_data);
}

static void
comm_connect_cleanup(void *cbdata)
{
  comm_op_t *op = cbdata;
  assert(op);

  comm_connect_complete(op, COMM_ERROR);
}

static void
comm_connect_timeout(void *cbdata)
{
  comm_op_t *op = cbdata;
  assert(op);

  op->timeout_event = NULL;
  comm_connect_complete(op, COMM_ERR_TIMEOUT);
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
comm_connect_handler(fde_t *F, void *cbdata)
{
  comm_op_t *op = cbdata;
  assert(op);

  /* This check is needed or re-entrant s_bsd_* like sigio break it. */
  if (F->cleanup_handler != comm_connect_cleanup || F->cleanup_data != op)
    return;

  int sock_err = comm_get_sockerr(F);
  if (sock_err == 0)
    comm_connect_complete(op, COMM_OK);
  else
    comm_connect_complete(op, COMM_ERR_CONNECT);
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
comm_connect_tcp(fde_t *F, const struct io_addr *caddr, uint16_t port, const struct io_addr *baddr,
                 void (*handler)(fde_t *, int, void *), void *data, uintmax_t timeout)
{
  assert(handler);

  comm_op_t *op = io_calloc(sizeof(*op));
  op->fde = F;
  op->completion_handler = handler;
  op->completion_handler_data = data;
  address_copy(&op->remote_addr, caddr);
  address_set_port(&op->remote_addr, port);

  F->cleanup_handler = comm_connect_cleanup;
  F->cleanup_data = op;

  if (baddr && address_is_specific(baddr))
  {
    if (bind(F->fd, (const struct sockaddr *)baddr, address_length(baddr)) == -1)
    {
      /* Failure, call the callback with COMM_ERR_BIND */
      comm_connect_complete(op, COMM_ERR_BIND);
      return;  /* ... and quit */
    }
  }

  /* Try the connect() */
  if (connect(F->fd, (struct sockaddr *)&op->remote_addr, address_length(&op->remote_addr)) == 0)
  {
    comm_connect_complete(op, COMM_OK);
    return;
  }

  if (comm_ignore_errno(errno) == false)
  {
    comm_connect_complete(op, COMM_ERR_CONNECT);
    return;
  }

  if (timeout > 0)
  {
    op->timeout_event = event_create(comm_event_manager, "comm_connect_timeout", comm_connect_timeout, timeout * 1000, true, op, NULL);
    event_schedule(op->timeout_event);
  }

  comm_setselect(F, COMM_SELECT_WRITE, comm_connect_handler, op, 0);
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

  address_clear(addr);

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
