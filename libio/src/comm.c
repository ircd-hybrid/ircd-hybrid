/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file comm.c
 * \brief Network functions.
 */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
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
#include "io_poll.h"
#include "log.h"
#include "memory.h"

event_manager_t comm_event_manager;

static const char *const comm_err_str[] =
{
  [COMM_OK] = "Comm OK",
  [COMM_ERR_BIND] = "Error during bind()",
  [COMM_ERR_TIMEOUT] = "connect timeout",
  [COMM_ERR_CONNECT] = "Error during connect()",
  [COMM_ERROR] = "Comm Error",
  [COMM_ERR_TIMER] = "Unable to schedule connect timeout",
  [COMM_ERR_WATCH] = "Unable to watch socket for connect completion"
};

struct comm_connect_operation
{
  fde_t *fde;
  void (*completion_handler)(fde_t *, int, void *);
  void *completion_context;
  event_handle_t timeout_event;
  uint64_t write_watch_id;
};

static void _comm_connect_cleanup(void *);

static struct io_poll *comm_poller;

bool
comm_init(event_manager_t manager)
{
  assert(manager);
  assert(comm_poller == NULL);

  comm_poller = io_poll_create(hard_fdlimit);
  if (comm_poller == NULL)
    return false;

  comm_event_manager = manager;
  if (io_poll_control_fd(comm_poller))
    ++number_fd;
  return true;
}

struct io_poll *
comm_get_poller(void)
{
  return comm_poller;
}

void
comm_shutdown(void)
{
  if (comm_poller == NULL)
    return;

  for (int fd = 0; fd <= highest_fd; ++fd)
    if (fd_table[fd].flags.open)
      comm_connect_cancel(&fd_table[fd]);

  if (io_poll_control_fd(comm_poller))
    --number_fd;
  io_poll_destroy(comm_poller);
  comm_poller = NULL;
  comm_event_manager = NULL;
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
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "setup_socket: fcntl(O_NONBLOCK) failed for FD %d: %s",
              fd, strerror(error));
    errno = error;
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

static void
_comm_connect_release(struct comm_connect_operation *operation)
{
  assert(operation);

  fde_t *const fde = operation->fde;
  assert(fde && fde->flags.open);
  assert(fde->cleanup_handler == _comm_connect_cleanup);
  assert(fde->cleanup_data == operation);

  fde->cleanup_handler = NULL;
  fde->cleanup_data = NULL;

  if (operation->timeout_event)
    event_destroy(operation->timeout_event);

  if (operation->write_watch_id)
    io_poll_unwatch_write(comm_poller, fde->fd, operation->write_watch_id);
  io_free(operation);
}

static void
comm_connect_complete(struct comm_connect_operation *operation, int status)
{
  assert(operation);

  fde_t *const fde = operation->fde;
  void (*const handler)(fde_t *, int, void *) = operation->completion_handler;
  void *const context = operation->completion_context;

  _comm_connect_release(operation);
  handler(fde, status, context);
}

static void
_comm_connect_cleanup(void *context)
{
  _comm_connect_release(context);
}

bool
comm_connect_cancel(fde_t *fde)
{
  assert(fde);
  assert(fde->flags.open);

  if (fde->cleanup_handler != _comm_connect_cleanup)
    return false;

  _comm_connect_release(fde->cleanup_data);
  return true;
}

static void
comm_connect_timeout(void *context)
{
  comm_connect_complete(context, COMM_ERR_TIMEOUT);
}

static void
comm_connect_handler(int fd, void *context)
{
  struct comm_connect_operation *const operation = context;
  assert(operation && operation->fde->fd == fd);
  (void)fd;

  int sock_err = 0;
  if (comm_socket_get_error(operation->fde, &sock_err) && sock_err == 0)
    comm_connect_complete(operation, COMM_OK);
  else
    comm_connect_complete(operation, COMM_ERR_CONNECT);
}

void
comm_connect_tcp(fde_t *fde, const struct io_addr *remote_addr, uint16_t remote_port, const struct io_addr *local_addr,
                 void (*handler)(fde_t *, int, void *), void *context, uintmax_t timeout_ms)
{
  assert(fde);
  assert(fde->flags.open);
  assert(remote_addr);
  assert(address_is_ipv4(remote_addr) || address_is_ipv6(remote_addr));
  assert(handler);
  assert(fde->cleanup_handler == NULL);
  assert(fde->cleanup_data == NULL);

  struct comm_connect_operation *const operation = io_calloc(sizeof(*operation));
  operation->fde = fde;
  operation->completion_handler = handler;
  operation->completion_context = context;

  fde->cleanup_handler = _comm_connect_cleanup;
  fde->cleanup_data = operation;

  struct io_addr endpoint = *remote_addr;
  if (!address_set_port(&endpoint, remote_port))
  {
    comm_connect_complete(operation, COMM_ERR_CONNECT);
    return;
  }

  if (local_addr)
  {
    const socklen_t local_length = address_get_sockaddr_length(local_addr);
    if (local_length == 0 || bind(fde->fd, address_get_sockaddr(local_addr), local_length) == -1)
    {
      comm_connect_complete(operation, COMM_ERR_BIND);
      return;
    }
  }

  if (timeout_ms > 0)
  {
    operation->timeout_event =
      event_create(comm_event_manager, "comm_connect_timeout", comm_connect_timeout, timeout_ms, true, operation, NULL);
    if (operation->timeout_event == NULL || event_schedule(operation->timeout_event) != EVENT_SUCCESS)
    {
      comm_connect_complete(operation, COMM_ERR_TIMER);
      return;
    }
  }

  if (connect(fde->fd, address_get_sockaddr(&endpoint), address_get_sockaddr_length(&endpoint)) == 0)
  {
    comm_connect_complete(operation, COMM_OK);
    return;
  }

  if (!comm_errno_is_recoverable(errno))
  {
    comm_connect_complete(operation, COMM_ERR_CONNECT);
    return;
  }

  if (io_poll_watch_write(comm_poller, fde->fd, comm_connect_handler, operation, &operation->write_watch_id) == -1)
    comm_connect_complete(operation, COMM_ERR_WATCH);
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

static fde_t *
comm_socket_adopt(int fd, int family, int sock_type, const char *desc)
{
  if (fd >= hard_fdlimit)
  {
    close(fd);
    errno = EMFILE;
    return NULL;
  }

  if (!setup_socket(fd, family, sock_type))
  {
    const int error = errno;
    close(fd);
    errno = error;
    return NULL;
  }

  return fd_open(fd, desc);
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
    const int error = errno;
    log_write(LOG_TYPE_DEBUG, "comm_socket_create: socket() failed: %s", strerror(error));
    errno = error;
    return NULL;
  }

  return comm_socket_adopt(fd, family, sock_type, desc);
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
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "comm_socket_listen: setsockopt(SO_REUSEADDR) failed for FD %d: %s",
              fde->fd, strerror(error));
    comm_socket_close(fde);
    errno = error;
    return NULL;
  }

#ifdef IPV6_V6ONLY
  if (address_is_ipv6(addr))
  {
    const int v6only_opt = 1;
    if (setsockopt(fde->fd, IPPROTO_IPV6, IPV6_V6ONLY, &v6only_opt, sizeof(v6only_opt)) == -1)
    {
      const int error = errno;
      log_write(LOG_TYPE_DEBUG, "comm_socket_listen: setsockopt(IPV6_V6ONLY=1) failed for FD %d: %s",
                fde->fd, strerror(error));
      comm_socket_close(fde);
      errno = error;
      return NULL;
    }
  }
#endif

  if (bind(fde->fd, address_get_sockaddr(addr), address_get_sockaddr_length(addr)) == -1)
  {
    const int error = errno;
    char addr_str[ADDRESS_STRING_BUFSIZE];
    address_to_string(addr, addr_str, sizeof(addr_str));

    log_write(LOG_TYPE_IRCD, "comm_socket_listen: bind() failed for %s: %s",
              addr_str, strerror(error));
    comm_socket_close(fde);
    errno = error;
    return NULL;
  }

  if (listen(fde->fd, backlog) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "comm_socket_listen: listen() failed for FD %d: %s",
              fde->fd, strerror(error));
    comm_socket_close(fde);
    errno = error;
    return NULL;
  }

  return fde;
}

void
comm_socket_close(fde_t *fde)
{
  assert(fde && fde->flags.open == true);

  if (comm_poller)
    io_poll_unwatch(comm_poller, fde->fd);

  if (tls_session_is_active(&fde->tls))
    tls_session_close_notify(&fde->tls);

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
    const int error = errno;
    if (!comm_errno_is_recoverable(error))
      log_write(LOG_TYPE_IRCD, "comm_accept: accept() failed on FD %d: %s",
                listener_fde->fd, strerror(error));
    errno = error;
    return NULL;
  }

  address_unmap_ipv4(addr);

  return comm_socket_adopt(fd, address_get_family(addr), SOCK_STREAM, desc);
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
