/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
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

event_manager_t comm_event_manager;

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

bool
comm_socket_get_error(const fde_t *fde, int *const sock_err_out)
{
  assert(fde);
  assert(fde->flags.open);
  assert(sock_err_out);

  *sock_err_out = 0;

  int sock_err = 0;
  socklen_t len = sizeof(sock_err);
  if (getsockopt(fde->fd, SOL_SOCKET, SO_ERROR, &sock_err, &len) == 0)
  {
    *sock_err_out = sock_err;
    return true;
  }
  else
  {
    log_write(LOG_TYPE_DEBUG, "comm_socket_get_error: getsockopt(SO_ERROR) failed for FD %d: %s",
              fde->fd, strerror(errno));
    return false;
  }
}

/*
 * setup_socket()
 *
 * Set the socket non-blocking, and other wonderful bits.
 */
static bool
setup_socket(int fd, int family, int sock_type)
{
  if (sock_type == SOCK_STREAM)
  {
    int opt = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt)) == -1)
      log_write(LOG_TYPE_DEBUG, "setup_socket: setsockopt(TCP_NODELAY) failed for FD %d: %s",
                fd, strerror(errno));

#if defined(IPTOS_LOWDELAY)
    opt = IPTOS_LOWDELAY;

    if (family == AF_INET)
    {
      if (setsockopt(fd, IPPROTO_IP, IP_TOS, &opt, sizeof(opt)) == -1)
        log_write(LOG_TYPE_DEBUG, "setup_socket: setsockopt(IP_TOS) failed for FD %d: %s",
                  fd, strerror(errno));
    }
#ifdef IPV6_TCLASS
    else if (family == AF_INET6)
    {
      if (setsockopt(fd, IPPROTO_IPV6, IPV6_TCLASS, &opt, sizeof(opt)) == -1)
        log_write(LOG_TYPE_DEBUG, "setup_socket: setsockopt(IPV6_TCLASS) failed for FD %d: %s",
                  fd, strerror(errno));
    }
#endif
#endif

#ifdef TCP_QUICKACK
    opt = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_QUICKACK, &opt, sizeof(opt)) == -1)
      log_write(LOG_TYPE_DEBUG, "setup_socket: setsockopt(TCP_QUICKACK) failed for FD %d: %s",
                fd, strerror(errno));
#endif
  }

  int flags = fcntl(fd, F_GETFL, 0);
  if (flags == -1 || fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
  {
    log_write(LOG_TYPE_IRCD, "setup_socket: fcntl(O_NONBLOCK) failed for FD %d: %s",
              fd, strerror(errno));
    return false;
  }

  return true;
}

/*
 * stolen from squid - its a neat (but overused! :) routine which we
 * can use to see whether we can ignore this errno or not. It is
 * generally useful for non-blocking network IO related errnos.
 *     -- adrian
 */
bool
comm_errno_is_recoverable(int error_code)
{
  switch (error_code)
  {
    case EINPROGRESS:
    case EALREADY:
    case EWOULDBLOCK:
#if EAGAIN != EWOULDBLOCK
    case EAGAIN:
#endif
    case EINTR:
#ifdef ERESTART
    case ERESTART:
#endif
      return true;
    default:
      return false;
  }
}

#define COMM_DEFAULT_SELECT_TIMEOUT_MS 100

int
comm_get_select_timeout(event_manager_t mgr)
{
  const uintmax_t next_fire_time_ms = event_manager_get_next_fire_time(mgr);
  if (next_fire_time_ms == EVENT_TIME_NEVER)
    return COMM_DEFAULT_SELECT_TIMEOUT_MS;

  const uintmax_t current_time_ms = io_time_get_monotonic_ms_total();
  if (next_fire_time_ms <= current_time_ms)
    return 0;

  const uintmax_t delta_ms = next_fire_time_ms - current_time_ms;
  if (delta_ms > COMM_DEFAULT_SELECT_TIMEOUT_MS)
    return COMM_DEFAULT_SELECT_TIMEOUT_MS;

  return (int)delta_ms;
}

static void
comm_connect_complete(comm_op_t *op, int status)
{
  assert(op);

  fde_t *fde = op->fde;
  void (*hdl)(fde_t *, int, void *) = op->completion_handler;
  void *hdl_data = op->completion_handler_data;

  if (op->timeout_event)
  {
    event_destroy(op->timeout_event);
    op->timeout_event = NULL;
  }

  if (fde == NULL || fde->flags.open == false)
  {
    hdl(fde, COMM_ERROR, hdl_data);

    io_free(op);
    return;
  }

  if (fde->cleanup_data == op)
  {
    fde->cleanup_handler = NULL;
    fde->cleanup_data = NULL;
  }

  comm_setselect(fde, COMM_SELECT_WRITE, NULL, NULL);

  hdl(fde, status, hdl_data);
  io_free(op);
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

  event_handle_t timeout_event = op->timeout_event;
  op->timeout_event = NULL;
  event_destroy(timeout_event);

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
comm_connect_handler(fde_t *fde, void *cbdata)
{
  comm_op_t *op = cbdata;
  assert(op);

  /* This check is needed or re-entrant s_bsd_* like sigio break it. */
  if (fde->cleanup_handler != comm_connect_cleanup || fde->cleanup_data != op)
    return;

  int sock_err = 0;
  if (comm_socket_get_error(fde, &sock_err) && sock_err == 0)
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
comm_connect_tcp(fde_t *fde, const struct io_addr *caddr, uint16_t port, const struct io_addr *baddr,
                 void (*handler)(fde_t *, int, void *), void *data, uintmax_t timeout_ms)
{
  assert(handler);

  comm_op_t *op = io_calloc(sizeof(*op));
  op->fde = fde;
  op->completion_handler = handler;
  op->completion_handler_data = data;
  address_copy(&op->remote_addr, caddr);
  address_set_port(&op->remote_addr, port);

  fde->cleanup_handler = comm_connect_cleanup;
  fde->cleanup_data = op;

  if (baddr && address_is_specific(baddr))
  {
    if (bind(fde->fd, (const struct sockaddr *)&baddr->ss, address_length(baddr)) == -1)
    {
      /* Failure, call the callback with COMM_ERR_BIND */
      comm_connect_complete(op, COMM_ERR_BIND);
      return;  /* ... and quit */
    }
  }

  /* Try the connect() */
  if (connect(fde->fd, (struct sockaddr *)&op->remote_addr.ss, address_length(&op->remote_addr)) == 0)
  {
    comm_connect_complete(op, COMM_OK);
    return;
  }

  if (!comm_errno_is_recoverable(errno))
  {
    comm_connect_complete(op, COMM_ERR_CONNECT);
    return;
  }

  if (timeout_ms > 0)
  {
    op->timeout_event = event_create(comm_event_manager, "comm_connect_timeout", comm_connect_timeout, timeout_ms, true, op, NULL);
    event_schedule(op->timeout_event);
  }

  comm_setselect(fde, COMM_SELECT_WRITE, comm_connect_handler, op);
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

fde_t *
comm_socket_create(int family, int sock_type, int proto, const char *desc)
{
  if (number_fd >= hard_fdlimit)
  {
    log_write(LOG_TYPE_DEBUG, "comm_socket_create: Cannot create new socket: %s", strerror(ENFILE));
    errno = ENFILE;
    return NULL;
  }

  int fd = socket(family, sock_type, proto);
  if (fd < 0)
  {
    log_write(LOG_TYPE_DEBUG, "comm_socket_create: socket() failed: %s", strerror(errno));
    return NULL;
  }

  if (!setup_socket(fd, family, sock_type))
  {
    close(fd);
    return NULL;
  }

  return fd_open(fd, true, desc);
}

fde_t *
comm_socket_listen(const struct io_addr *addr, int backlog, const char *desc)
{
  assert(backlog > 0);

  fde_t *fde = comm_socket_create(address_get_family(addr), SOCK_STREAM, 0, desc);
  if (fde == NULL)
    return NULL;

  const int opt = 1;
  if (setsockopt(fde->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
  {
    log_write(LOG_TYPE_IRCD, "comm_socket_listen: setsockopt(SO_REUSEADDR) failed for FD %d: %s",
              fde->fd, strerror(errno));
    fd_close(fde);
    return NULL;
  }

#ifdef IPV6_V6ONLY
  if (address_is_ipv6(addr) && address_is_unspecified(addr))
  {
    const int v6only_opt = 0;
    if (setsockopt(fde->fd, IPPROTO_IPV6, IPV6_V6ONLY, &v6only_opt, sizeof(v6only_opt)) == -1)
    {
      log_write(LOG_TYPE_DEBUG, "comm_socket_listen: setsockopt(IPV6_V6ONLY=0) failed for FD %d: %s",
                fde->fd, strerror(errno));
      fd_close(fde);
      return NULL;
    }
  }
#endif

  if (bind(fde->fd, (const struct sockaddr *)&addr->ss, address_length(addr)) == -1)
  {
    char addr_str[INET6_ADDRSTRLEN];
    address_to_string(addr, addr_str, sizeof(addr_str));

    log_write(LOG_TYPE_IRCD, "comm_socket_listen: bind() failed for %s: %s",
              addr_str, strerror(errno));
    fd_close(fde);
    return NULL;
  }

  if (listen(fde->fd, backlog) == -1)
  {
    log_write(LOG_TYPE_IRCD, "comm_socket_listen: listen() failed for FD %d: %s",
              fde->fd, strerror(errno));
    fd_close(fde);
    return NULL;
  }

  return fde;
}

void
comm_socket_close(fde_t *fde)
{
  assert(fde && fde->flags.open == true);

  if (tls_isusing(&fde->tls))
    tls_shutdown(&fde->tls);

  fd_close(fde);
}

fde_t *
comm_accept(fde_t *listener_fde, struct io_addr *addr, const char *desc)
{
  assert(listener_fde);
  assert(listener_fde->flags.open);

  if (number_fd >= hard_fdlimit)
  {
    log_write(LOG_TYPE_IRCD, "comm_accept: Cannot accept new connection: %s", strerror(ENFILE));
    errno = ENFILE;
    return NULL;
  }

  address_clear(addr);

  socklen_t addrlen = sizeof(addr->ss);
  int fd = accept(listener_fde->fd, (struct sockaddr *)&addr->ss, &addrlen);
  if (fd < 0)
  {
    if (comm_errno_is_recoverable(errno))
      return NULL;

    log_write(LOG_TYPE_IRCD, "comm_accept: accept() failed on FD %d: %s",
              listener_fde->fd, strerror(errno));
    return NULL;
  }

  address_strip_ipv4(addr);

  if (!setup_socket(fd, address_get_family(addr), SOCK_STREAM))
  {
    close(fd);
    return NULL;
  }

  return fd_open(fd, true, desc);
}

void
comm_socket_note(fde_t *fde, const char *format, ...)
{
  if (format)
  {
    char buf[FD_DESC_SIZE + 1];
    va_list args;

    va_start(args, format);
    vsnprintf(buf, sizeof(buf), format, args);
    va_end(args);

    fd_note(fde, "%s", buf);
  }
  else
    fd_note(fde, NULL);
}
