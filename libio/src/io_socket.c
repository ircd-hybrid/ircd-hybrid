/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file comm.c
 * \brief Socket lifecycle and nonblocking TCP connections.
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
#include "event.h"
#include "fdlist.h"
#include "io_poll.h"
#include "io_socket.h"
#include "log.h"
#include "memory.h"

static const char *const io_socket_connect_status_strings[IO_SOCKET_CONNECT_STATUS_COUNT] =
{
  [IO_SOCKET_CONNECT_SUCCESS] = "Success",
  [IO_SOCKET_CONNECT_BIND_FAILED] = "Error during bind()",
  [IO_SOCKET_CONNECT_TIMED_OUT] = "connect timeout",
  [IO_SOCKET_CONNECT_FAILED] = "Error during connect()",
  [IO_SOCKET_CONNECT_UNSPECIFIED_ERROR] = "Unspecified connection error",
  [IO_SOCKET_CONNECT_TIMER_FAILED] = "Unable to schedule connect timeout",
  [IO_SOCKET_CONNECT_WATCH_FAILED] = "Unable to watch socket for connect completion"
};

struct io_socket_connect_operation
{
  fde_t *socket_fde;
  io_socket_connect_callback_fn callback;
  void *callback_context;
  event_handle_t timeout_event;
  uint64_t write_watch_id;
};

static void io_socket_connect_cleanup(void *);

static event_manager_t io_socket_event_manager;
static struct io_poll *io_socket_poller;

bool
io_socket_init(event_manager_t event_manager)
{
  assert(event_manager);
  assert(io_socket_poller == NULL);

  io_socket_poller = io_poll_create(hard_fdlimit);
  if (io_socket_poller == NULL)
    return false;

  io_socket_event_manager = event_manager;
  if (io_poll_control_fd(io_socket_poller))
    ++number_fd;
  return true;
}

struct io_poll *
io_socket_get_poller(void)
{
  return io_socket_poller;
}

void
io_socket_shutdown(void)
{
  if (io_socket_poller == NULL)
    return;

  for (int fd = 0; fd <= highest_fd; ++fd)
    if (fd_table[fd].flags.open)
      io_socket_connect_cancel(&fd_table[fd]);

  if (io_poll_control_fd(io_socket_poller))
    --number_fd;
  io_poll_destroy(io_socket_poller);
  io_socket_poller = NULL;
  io_socket_event_manager = NULL;
}

static bool
io_socket_configure(int fd, int family, int socket_type)
{
  if (socket_type == SOCK_STREAM)
  {
    int option_value = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &option_value, sizeof(option_value)) == -1)
      log_write(LOG_TYPE_DEBUG, "io_socket_configure: setsockopt(TCP_NODELAY) failed for FD %d: %s",
                fd, strerror(errno));

#if defined(IPTOS_LOWDELAY)
    option_value = IPTOS_LOWDELAY;

    if (family == AF_INET)
    {
      if (setsockopt(fd, IPPROTO_IP, IP_TOS, &option_value, sizeof(option_value)) == -1)
        log_write(LOG_TYPE_DEBUG, "io_socket_configure: setsockopt(IP_TOS) failed for FD %d: %s",
                  fd, strerror(errno));
    }
#ifdef IPV6_TCLASS
    else if (family == AF_INET6)
    {
      if (setsockopt(fd, IPPROTO_IPV6, IPV6_TCLASS, &option_value, sizeof(option_value)) == -1)
        log_write(LOG_TYPE_DEBUG, "io_socket_configure: setsockopt(IPV6_TCLASS) failed for FD %d: %s",
                  fd, strerror(errno));
    }
#endif
#endif

#ifdef TCP_QUICKACK
    option_value = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_QUICKACK, &option_value, sizeof(option_value)) == -1)
      log_write(LOG_TYPE_DEBUG, "io_socket_configure: setsockopt(TCP_QUICKACK) failed for FD %d: %s",
                fd, strerror(errno));
#endif
  }

  const int status_flags = fcntl(fd, F_GETFL, 0);
  if (status_flags == -1 || fcntl(fd, F_SETFL, status_flags | O_NONBLOCK) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "io_socket_configure: fcntl(O_NONBLOCK) failed for FD %d: %s",
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
io_socket_errno_is_transient(int error_code)
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
io_socket_connect_operation_destroy(struct io_socket_connect_operation *operation)
{
  assert(operation);

  fde_t *const socket_fde = operation->socket_fde;
  assert(socket_fde && socket_fde->flags.open);
  assert(socket_fde->cleanup_handler == io_socket_connect_cleanup);
  assert(socket_fde->cleanup_data == operation);

  socket_fde->cleanup_handler = NULL;
  socket_fde->cleanup_data = NULL;

  if (operation->timeout_event)
    event_destroy(operation->timeout_event);

  if (operation->write_watch_id)
    io_poll_unwatch_write(io_socket_poller, socket_fde->fd, operation->write_watch_id);
  io_free(operation);
}

static void
io_socket_connect_complete(struct io_socket_connect_operation *operation, enum io_socket_connect_status status)
{
  assert(operation);

  fde_t *const socket_fde = operation->socket_fde;
  const io_socket_connect_callback_fn callback = operation->callback;
  void *const callback_context = operation->callback_context;

  io_socket_connect_operation_destroy(operation);
  callback(socket_fde, status, callback_context);
}

static void
io_socket_connect_cleanup(void *context)
{
  io_socket_connect_operation_destroy(context);
}

bool
io_socket_connect_cancel(fde_t *socket_fde)
{
  assert(socket_fde);
  assert(socket_fde->flags.open);

  if (socket_fde->cleanup_handler != io_socket_connect_cleanup)
    return false;

  io_socket_connect_operation_destroy(socket_fde->cleanup_data);
  return true;
}

static void
io_socket_connect_on_timeout(void *context)
{
  io_socket_connect_complete(context, IO_SOCKET_CONNECT_TIMED_OUT);
}

static void
io_socket_connect_on_write_ready(int fd, void *context)
{
  struct io_socket_connect_operation *const operation = context;
  assert(operation && operation->socket_fde->fd == fd);

  int pending_error = 0;
  socklen_t option_length = sizeof(pending_error);
  const int result = getsockopt(fd, SOL_SOCKET, SO_ERROR, &pending_error, &option_length);
  if (result == -1)
    log_write(LOG_TYPE_DEBUG, "io_socket_connect_on_write_ready: getsockopt(SO_ERROR) failed for FD %d: %s",
              fd, strerror(errno));

  const enum io_socket_connect_status status =
    result == 0 && pending_error == 0 ? IO_SOCKET_CONNECT_SUCCESS : IO_SOCKET_CONNECT_FAILED;
  io_socket_connect_complete(operation, status);
}

void
io_socket_connect_tcp(fde_t *socket_fde, const struct io_addr *remote_addr, uint16_t remote_port,
                      const struct io_addr *bind_addr, io_socket_connect_callback_fn callback,
                      void *callback_context, uintmax_t timeout_ms)
{
  assert(socket_fde);
  assert(socket_fde->flags.open);
  assert(remote_addr);
  assert(address_is_ipv4(remote_addr) || address_is_ipv6(remote_addr));
  assert(callback);
  assert(socket_fde->cleanup_handler == NULL);
  assert(socket_fde->cleanup_data == NULL);

  struct io_socket_connect_operation *const operation = io_calloc(sizeof(*operation));
  operation->socket_fde = socket_fde;
  operation->callback = callback;
  operation->callback_context = callback_context;

  socket_fde->cleanup_handler = io_socket_connect_cleanup;
  socket_fde->cleanup_data = operation;

  struct io_addr remote_endpoint = *remote_addr;
  if (!address_set_port(&remote_endpoint, remote_port))
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_FAILED);
    return;
  }

  if (bind_addr)
  {
    const socklen_t bind_addr_length = address_get_sockaddr_length(bind_addr);
    if (bind_addr_length == 0 || bind(socket_fde->fd, address_get_sockaddr(bind_addr), bind_addr_length) == -1)
    {
      io_socket_connect_complete(operation, IO_SOCKET_CONNECT_BIND_FAILED);
      return;
    }
  }

  if (timeout_ms > 0)
  {
    operation->timeout_event =
      event_create(io_socket_event_manager, "io_socket_connect_timeout", io_socket_connect_on_timeout,
                   timeout_ms, true, operation, NULL);
    if (operation->timeout_event == NULL || event_schedule(operation->timeout_event) != EVENT_SUCCESS)
    {
      io_socket_connect_complete(operation, IO_SOCKET_CONNECT_TIMER_FAILED);
      return;
    }
  }

  if (connect(socket_fde->fd, address_get_sockaddr(&remote_endpoint),
              address_get_sockaddr_length(&remote_endpoint)) == 0)
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_SUCCESS);
    return;
  }

  if (!io_socket_errno_is_transient(errno))
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_FAILED);
    return;
  }

  if (io_poll_watch_write(io_socket_poller, socket_fde->fd, io_socket_connect_on_write_ready,
                          operation, &operation->write_watch_id) == -1)
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_WATCH_FAILED);
}

const char *
io_socket_connect_status_to_string(enum io_socket_connect_status status)
{
  if ((unsigned int)status >= IO_SOCKET_CONNECT_STATUS_COUNT)
    return "Invalid socket connect status";
  return io_socket_connect_status_strings[status];
}

static fde_t *
io_socket_adopt(int fd, int family, int socket_type, const char *description)
{
  if (fd >= hard_fdlimit)
  {
    close(fd);
    errno = EMFILE;
    return NULL;
  }

  if (!io_socket_configure(fd, family, socket_type))
  {
    const int error = errno;
    close(fd);
    errno = error;
    return NULL;
  }

  return fd_open(fd, description);
}

fde_t *
io_socket_create(int family, int socket_type, int protocol, const char *description)
{
  if (number_fd >= hard_fdlimit)
  {
    log_write(LOG_TYPE_DEBUG, "io_socket_create: Cannot create new socket: %s", strerror(ENFILE));
    errno = ENFILE;
    return NULL;
  }

  const int fd = socket(family, socket_type, protocol);
  if (fd < 0)
  {
    const int error = errno;
    log_write(LOG_TYPE_DEBUG, "io_socket_create: socket() failed: %s", strerror(error));
    errno = error;
    return NULL;
  }

  return io_socket_adopt(fd, family, socket_type, description);
}

fde_t *
io_socket_listen(const struct io_addr *bind_addr, int backlog, const char *description)
{
  assert(backlog > 0);

  fde_t *const listener_fde = io_socket_create(address_get_family(bind_addr), SOCK_STREAM, 0, description);
  if (listener_fde == NULL)
    return NULL;

  const int reuse_addr = 1;
  if (setsockopt(listener_fde->fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "io_socket_listen: setsockopt(SO_REUSEADDR) failed for FD %d: %s",
              listener_fde->fd, strerror(error));
    io_socket_close(listener_fde);
    errno = error;
    return NULL;
  }

#ifdef IPV6_V6ONLY
  if (address_is_ipv6(bind_addr))
  {
    const int ipv6_only = 1;
    if (setsockopt(listener_fde->fd, IPPROTO_IPV6, IPV6_V6ONLY, &ipv6_only, sizeof(ipv6_only)) == -1)
    {
      const int error = errno;
      log_write(LOG_TYPE_DEBUG, "io_socket_listen: setsockopt(IPV6_V6ONLY=1) failed for FD %d: %s",
                listener_fde->fd, strerror(error));
      io_socket_close(listener_fde);
      errno = error;
      return NULL;
    }
  }
#endif

  if (bind(listener_fde->fd, address_get_sockaddr(bind_addr), address_get_sockaddr_length(bind_addr)) == -1)
  {
    const int error = errno;
    char address_text[ADDRESS_STRING_BUFSIZE];
    address_to_string(bind_addr, address_text, sizeof(address_text));

    log_write(LOG_TYPE_IRCD, "io_socket_listen: bind() failed for %s: %s",
              address_text, strerror(error));
    io_socket_close(listener_fde);
    errno = error;
    return NULL;
  }

  if (listen(listener_fde->fd, backlog) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "io_socket_listen: listen() failed for FD %d: %s",
              listener_fde->fd, strerror(error));
    io_socket_close(listener_fde);
    errno = error;
    return NULL;
  }

  return listener_fde;
}

void
io_socket_close(fde_t *socket_fde)
{
  assert(socket_fde && socket_fde->flags.open == true);

  if (io_socket_poller)
    io_poll_unwatch(io_socket_poller, socket_fde->fd);

  if (tls_session_is_active(&socket_fde->tls))
    tls_session_close_notify(&socket_fde->tls);

  fd_close(socket_fde);
}

fde_t *
io_socket_accept(fde_t *listener_fde, struct io_addr *peer_addr, const char *description)
{
  assert(listener_fde);
  assert(listener_fde->flags.open);

  if (number_fd >= hard_fdlimit)
  {
    log_write(LOG_TYPE_IRCD, "io_socket_accept: Cannot accept new connection: %s", strerror(ENFILE));
    errno = ENFILE;
    return NULL;
  }

  address_clear(peer_addr);

  socklen_t peer_addr_length = sizeof(peer_addr->ss);
  const int fd = accept(listener_fde->fd, (struct sockaddr *)&peer_addr->ss, &peer_addr_length);
  if (fd < 0)
  {
    const int error = errno;
    if (!io_socket_errno_is_transient(error))
      log_write(LOG_TYPE_IRCD, "io_socket_accept: accept() failed on FD %d: %s",
                listener_fde->fd, strerror(error));
    errno = error;
    return NULL;
  }

  address_unmap_ipv4(peer_addr);

  return io_socket_adopt(fd, address_get_family(peer_addr), SOCK_STREAM, description);
}

void
io_socket_set_description_fmt(fde_t *socket_fde, const char *format, ...)
{
  if (format)
  {
    char description[FD_DESC_SIZE + 1];
    va_list args;

    va_start(args, format);
    vsnprintf(description, sizeof(description), format, args);
    va_end(args);

    fd_note(socket_fde, "%s", description);
  }
  else
    fd_note(socket_fde, NULL);
}
