/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file io_socket.c
 * \brief Socket lifecycle and nonblocking TCP connections.
 */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "address.h"
#include "event.h"
#include "io_poll.h"
#include "io_socket.h"
#include "io_string.h"
#include "list.h"
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
  struct io_socket *socket;
  io_socket_connect_callback_fn callback;
  void *callback_context;
  event_handle_t timeout_event;
  uint64_t write_watch_id;
};

struct io_socket_context
{
  struct io_poll *poller;
  event_manager_t event_manager;
  size_t socket_limit;
  list_t sockets;
};

struct io_socket
{
  struct io_socket_context *context;
  list_node_t node;
  int fd;
  bool connect_available;
  char *description;
  tls_data_t tls;
  struct io_socket_connect_operation *connect_operation;
};

struct io_socket_context *
io_socket_context_create(struct io_poll *poller, event_manager_t event_manager, size_t socket_limit)
{
  assert(poller && event_manager);

  struct io_socket_context *const context = io_calloc(sizeof(*context));
  context->poller = poller;
  context->event_manager = event_manager;
  context->socket_limit = socket_limit;
  return context;
}

int
io_socket_context_destroy(struct io_socket_context *context)
{
  if (context && !list_is_empty(&context->sockets))
  {
    errno = EBUSY;
    return -1;
  }

  io_free(context);
  return 0;
}

size_t
io_socket_context_available_slots(const struct io_socket_context *context)
{
  return context->socket_limit - list_length(&context->sockets);
}

static int
io_socket_snapshot_compare(const void *left, const void *right)
{
  const struct io_socket_snapshot *const a = left;
  const struct io_socket_snapshot *const b = right;
  return (a->fd > b->fd) - (a->fd < b->fd);
}

int
io_socket_context_snapshot(const struct io_socket_context *context,
                           struct io_socket_snapshot **snapshot_out, size_t *count_out)
{
  const size_t count = list_length(&context->sockets);

  if (count > SIZE_MAX / sizeof(struct io_socket_snapshot))
  {
    errno = EOVERFLOW;
    return -1;
  }

  *count_out = count;
  *snapshot_out = NULL;

  if (count == 0)
    return 0;

  struct io_socket_snapshot *const snapshot = io_calloc(count * sizeof(*snapshot));
  struct io_socket_snapshot *entry = snapshot;

  const list_node_t *node;
  LIST_FOREACH(node, context->sockets.head)
  {
    const struct io_socket *const socket = node->data;
    entry->fd = socket->fd;
    strlcpy(entry->description, socket->description ? socket->description : "", sizeof(entry->description));
    ++entry;
  }

  qsort(snapshot, count, sizeof(*snapshot), io_socket_snapshot_compare);
  *snapshot_out = snapshot;
  return 0;
}

static bool
io_socket_configure(int fd, int family, int socket_type)
{
  if (fcntl(fd, F_SETFD, FD_CLOEXEC) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "io_socket_configure: fcntl(FD_CLOEXEC) failed for FD %d: %s",
              fd, strerror(error));
    errno = error;
    return false;
  }

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

  struct io_socket *const socket = operation->socket;
  assert(socket->connect_operation == operation);
  socket->connect_operation = NULL;

  if (operation->timeout_event)
    event_destroy(operation->timeout_event);

  if (operation->write_watch_id)
    io_poll_unwatch_write(socket->context->poller, socket->fd, operation->write_watch_id);

  io_free(operation);
}

static void
io_socket_connect_complete(struct io_socket_connect_operation *operation, enum io_socket_connect_status status,
                           int system_error)
{
  assert(operation);

  struct io_socket *const socket = operation->socket;
  const io_socket_connect_callback_fn callback = operation->callback;
  void *const callback_context = operation->callback_context;

  io_socket_connect_operation_destroy(operation);
  callback(socket, status, system_error, callback_context);
}

bool
io_socket_connect_cancel(struct io_socket *socket)
{
  if (socket->connect_operation == NULL)
    return false;

  io_socket_connect_operation_destroy(socket->connect_operation);
  return true;
}

static void
io_socket_connect_on_timeout(void *context)
{
  io_socket_connect_complete(context, IO_SOCKET_CONNECT_TIMED_OUT, 0);
}

static void
io_socket_connect_on_write_ready(int fd, void *context)
{
  struct io_socket_connect_operation *const operation = context;
  assert(operation && operation->socket->fd == fd);

  int system_error = 0;
  socklen_t option_length = sizeof(system_error);
  if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &system_error, &option_length) == -1)
    system_error = errno;

  const enum io_socket_connect_status status =
    system_error == 0 ? IO_SOCKET_CONNECT_SUCCESS : IO_SOCKET_CONNECT_FAILED;
  io_socket_connect_complete(operation, status, system_error);
}

int
io_socket_connect_tcp(struct io_socket *socket, const struct io_addr *remote_endpoint,
                      const struct io_addr *local_endpoint, io_socket_connect_callback_fn callback,
                      void *callback_context, uintmax_t timeout_ms)
{
  assert(socket);
  assert(remote_endpoint);
  assert(callback);

  if (!socket->connect_available)
  {
    errno = socket->connect_operation ? EBUSY : EINVAL;
    return -1;
  }

  socket->connect_available = false;

  struct io_socket_connect_operation *const operation = io_calloc(sizeof(*operation));
  operation->socket = socket;
  operation->callback = callback;
  operation->callback_context = callback_context;

  socket->connect_operation = operation;

  const socklen_t remote_length = address_get_sockaddr_length(remote_endpoint);
  if (remote_length == 0)
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_FAILED, EAFNOSUPPORT);
    return 0;
  }

  if (address_get_port(remote_endpoint) == 0)
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_FAILED, EINVAL);
    return 0;
  }

  if (local_endpoint)
  {
    const socklen_t local_length = address_get_sockaddr_length(local_endpoint);
    if (local_length == 0)
    {
      io_socket_connect_complete(operation, IO_SOCKET_CONNECT_BIND_FAILED, EAFNOSUPPORT);
      return 0;
    }

    if (bind(socket->fd, address_get_sockaddr(local_endpoint), local_length) == -1)
    {
      io_socket_connect_complete(operation, IO_SOCKET_CONNECT_BIND_FAILED, errno);
      return 0;
    }
  }

  if (timeout_ms > 0)
  {
    operation->timeout_event =
      event_create(socket->context->event_manager, "io_socket_connect_timeout", io_socket_connect_on_timeout,
                   timeout_ms, true, operation, NULL);
    if (operation->timeout_event == NULL || event_schedule(operation->timeout_event) != EVENT_SUCCESS)
    {
      io_socket_connect_complete(operation, IO_SOCKET_CONNECT_TIMER_FAILED, 0);
      return 0;
    }
  }

  if (connect(socket->fd, address_get_sockaddr(remote_endpoint), remote_length) == 0)
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_SUCCESS, 0);
    return 0;
  }

  const int system_error = errno;
  if (!io_socket_errno_is_transient(system_error))
  {
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_FAILED, system_error);
    return 0;
  }

  if (io_poll_watch_write(socket->context->poller, socket->fd, io_socket_connect_on_write_ready,
                          operation, &operation->write_watch_id) == -1)
    io_socket_connect_complete(operation, IO_SOCKET_CONNECT_WATCH_FAILED, errno);

  return 0;
}

const char *
io_socket_connect_status_to_string(enum io_socket_connect_status status)
{
  if ((unsigned int)status >= IO_SOCKET_CONNECT_STATUS_COUNT)
    return "Invalid socket connect status";

  return io_socket_connect_status_strings[status];
}

static struct io_socket *
io_socket_adopt(struct io_socket_context *context, int fd, int family, int socket_type,
                const char *description, bool connect_available)
{
  if (fd >= io_poll_fd_limit(context->poller))
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

  struct io_socket *const socket = io_calloc(sizeof(*socket));
  socket->context = context;
  socket->fd = fd;
  socket->connect_available = connect_available;
  if (description)
    socket->description = io_strndup(description, IO_SOCKET_DESCRIPTION_MAX);

  list_add_tail(socket, &socket->node, &context->sockets);
  return socket;
}

struct io_socket *
io_socket_create(struct io_socket_context *context, int family, int socket_type, int protocol, const char *description)
{
  if (io_socket_context_available_slots(context) == 0)
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

  const bool tcp = (family == AF_INET || family == AF_INET6) && socket_type == SOCK_STREAM &&
                   (protocol == 0 || protocol == IPPROTO_TCP);
  return io_socket_adopt(context, fd, family, socket_type, description, tcp);
}

struct io_socket *
io_socket_listen(struct io_socket_context *context, const struct io_addr *bind_addr, int backlog, const char *description)
{
  assert(backlog > 0);

  struct io_socket *const listener =
    io_socket_create(context, address_get_family(bind_addr), SOCK_STREAM, 0, description);
  if (listener == NULL)
    return NULL;

  const int reuse_addr = 1;
  if (setsockopt(listener->fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "io_socket_listen: setsockopt(SO_REUSEADDR) failed for FD %d: %s",
              listener->fd, strerror(error));
    io_socket_close(listener);
    errno = error;
    return NULL;
  }

#ifdef IPV6_V6ONLY
  if (address_is_ipv6(bind_addr))
  {
    const int ipv6_only = 1;
    if (setsockopt(listener->fd, IPPROTO_IPV6, IPV6_V6ONLY, &ipv6_only, sizeof(ipv6_only)) == -1)
    {
      const int error = errno;
      log_write(LOG_TYPE_DEBUG, "io_socket_listen: setsockopt(IPV6_V6ONLY=1) failed for FD %d: %s",
                listener->fd, strerror(error));
      io_socket_close(listener);
      errno = error;
      return NULL;
    }
  }
#endif

  if (bind(listener->fd, address_get_sockaddr(bind_addr), address_get_sockaddr_length(bind_addr)) == -1)
  {
    const int error = errno;
    char address_text[ADDRESS_STRING_BUFSIZE];
    address_to_string(bind_addr, address_text, sizeof(address_text));

    log_write(LOG_TYPE_IRCD, "io_socket_listen: bind() failed for %s: %s",
              address_text, strerror(error));
    io_socket_close(listener);
    errno = error;
    return NULL;
  }

  if (listen(listener->fd, backlog) == -1)
  {
    const int error = errno;
    log_write(LOG_TYPE_IRCD, "io_socket_listen: listen() failed for FD %d: %s",
              listener->fd, strerror(error));
    io_socket_close(listener);
    errno = error;
    return NULL;
  }

  listener->connect_available = false;
  return listener;
}

void
io_socket_close(struct io_socket *socket)
{
  struct io_socket_context *const context = socket->context;

  io_poll_unwatch(context->poller, socket->fd);
  io_socket_connect_cancel(socket);

  if (tls_session_is_active(&socket->tls))
  {
    tls_session_close_notify(&socket->tls);
    tls_session_deinit(&socket->tls);
  }

  close(socket->fd);
  list_remove(&socket->node, &context->sockets);
  io_free(socket->description);
  io_free(socket);
}

struct io_socket *
io_socket_accept(struct io_socket *listener, struct io_addr *peer_addr, const char *description)
{
  struct io_socket_context *const context = listener->context;

  if (io_socket_context_available_slots(context) == 0)
  {
    log_write(LOG_TYPE_IRCD, "io_socket_accept: Cannot accept new connection: %s", strerror(ENFILE));
    errno = ENFILE;
    return NULL;
  }

  address_clear(peer_addr);

  socklen_t peer_addr_length = sizeof(peer_addr->ss);
  const int fd = accept(listener->fd, (struct sockaddr *)&peer_addr->ss, &peer_addr_length);
  if (fd < 0)
  {
    const int error = errno;
    if (!io_socket_errno_is_transient(error))
      log_write(LOG_TYPE_IRCD, "io_socket_accept: accept() failed on FD %d: %s",
                listener->fd, strerror(error));
    errno = error;
    return NULL;
  }

  address_unmap_ipv4(peer_addr);

  return io_socket_adopt(context, fd, address_get_family(peer_addr), SOCK_STREAM, description, false);
}

void
io_socket_set_description_fmt(struct io_socket *socket, const char *format, ...)
{
  char *description = NULL;

  if (format)
  {
    char buffer[IO_SOCKET_DESCRIPTION_MAX + 1];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    description = io_strdup(buffer);
  }

  io_free(socket->description);
  socket->description = description;
}

int
io_socket_fd(const struct io_socket *socket)
{
  return socket->fd;
}

static int
_io_socket_get_endpoint(const struct io_socket *socket, bool peer, struct io_addr *endpoint)
{
  assert(socket);
  assert(endpoint);

  struct io_addr address = { 0 };
  socklen_t length = sizeof(address.ss);
  struct sockaddr *const storage = (struct sockaddr *)&address.ss;
  const int result = peer ? getpeername(socket->fd, storage, &length) :
                            getsockname(socket->fd, storage, &length);
  if (result == -1)
    return -1;

  const size_t family_end = offsetof(struct sockaddr_storage, ss_family) + sizeof(address.ss.ss_family);
  if ((size_t)length < family_end || (size_t)length > sizeof(address.ss))
  {
    errno = EINVAL;
    return -1;
  }

  const socklen_t expected_length = address_get_sockaddr_length(&address);
  if (expected_length == 0)
  {
    errno = EAFNOSUPPORT;
    return -1;
  }

  if (length < expected_length)
  {
    errno = EINVAL;
    return -1;
  }

  address_unmap_ipv4(&address);
  *endpoint = address;
  return 0;
}

int
io_socket_get_local_endpoint(const struct io_socket *socket, struct io_addr *endpoint)
{
  return _io_socket_get_endpoint(socket, false, endpoint);
}

int
io_socket_get_peer_endpoint(const struct io_socket *socket, struct io_addr *endpoint)
{
  return _io_socket_get_endpoint(socket, true, endpoint);
}

int
io_socket_watch_read(struct io_socket *socket, io_poll_handler_fn handler, void *context)
{
  if (socket->connect_operation)
  {
    errno = EBUSY;
    return -1;
  }

  const int result = io_poll_watch_read(socket->context->poller, socket->fd, handler, context);
  if (result == 0)
    socket->connect_available = false;

  return result;
}

int
io_socket_watch_write(struct io_socket *socket, io_poll_handler_fn handler, void *context)
{
  if (socket->connect_operation)
  {
    errno = EBUSY;
    return -1;
  }

  const int result = io_poll_watch_write(socket->context->poller, socket->fd, handler, context, NULL);
  if (result == 0)
    socket->connect_available = false;

  return result;
}

bool
io_socket_tls_start(struct io_socket *socket, tls_role_t role)
{
  assert(!tls_session_is_active(&socket->tls));

  if (socket->connect_operation)
  {
    errno = EBUSY;
    return false;
  }

  if (!tls_session_init(&socket->tls, socket->fd, role))
    return false;

  socket->connect_available = false;
  return true;
}

bool
io_socket_tls_is_active(const struct io_socket *socket)
{
  return tls_session_is_active(&socket->tls);
}

tls_handshake_status_t
io_socket_tls_handshake(struct io_socket *socket, const char **error)
{
  return tls_session_handshake(&socket->tls, error);
}

ssize_t
io_socket_tls_read(struct io_socket *socket, char *buffer, size_t length, bool *want_write)
{
  return tls_session_read(&socket->tls, buffer, length, want_write);
}

ssize_t
io_socket_tls_write(struct io_socket *socket, const char *buffer, size_t length, bool *want_read)
{
  return tls_session_write(&socket->tls, buffer, length, want_read);
}

bool
io_socket_tls_get_peer_certificate_fingerprint(struct io_socket *socket, char **fingerprint)
{
  return tls_session_get_peer_certificate_fingerprint(&socket->tls, fingerprint);
}

const char *
io_socket_tls_get_cipher(const struct io_socket *socket)
{
  return tls_session_get_cipher(&socket->tls);
}
