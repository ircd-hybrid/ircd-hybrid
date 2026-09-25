/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "address.h"
#include "comm.h"
#include "event.h"
#include "ident.h"
#include "io_string.h"
#include "list.h"
#include "memory.h"

enum
{
  IDENT_SERVICE_PORT = 113,
  IDENT_QUERY_CAPACITY = 16,
  IDENT_REPLY_CAPACITY = 1000,
  IDENT_USER_ID_MAX_LENGTH = 512,
  IDENT_USER_ID_CAPACITY = IDENT_USER_ID_MAX_LENGTH + 1
};

struct ident_span
{
  const char *data;
  size_t length;
};

struct ident_user_id_reply
{
  struct ident_span opsys;
  struct ident_span user_id;
};

enum ident_request_state
{
  IDENT_REQUEST_STATE_STARTING,
  IDENT_REQUEST_STATE_ACTIVE,
  IDENT_REQUEST_STATE_START_FAILED
};

struct ident_request
{
  list_node_t node;
  fde_t *fde;
  event_handle_t timeout_event;

  ident_callback_fn callback;
  void *callback_ctx;

  enum ident_request_state state;
  uint16_t server_port;
  uint16_t client_port;

  char query[IDENT_QUERY_CAPACITY];
  size_t query_length;
  size_t query_offset;

  char reply[IDENT_REPLY_CAPACITY];
  size_t reply_length;
};

static list_t ident_request_list;

static bool
_ident_protocol_is_space(unsigned char character)
{
  return character == ' ' || character == '\t';
}

static struct ident_span
_ident_span_trim(struct ident_span span)
{
  while (span.length && _ident_protocol_is_space((unsigned char)*span.data))
  {
    ++span.data;
    --span.length;
  }

  while (span.length && _ident_protocol_is_space((unsigned char)span.data[span.length - 1]))
    --span.length;

  return span;
}

static bool
_ident_span_equal(struct ident_span span, const char *text)
{
  assert(text);

  const size_t text_length = strlen(text);
  return span.length == text_length && memcmp(span.data, text, text_length) == 0;
}

static bool
_ident_token_is_valid(struct ident_span token)
{
  if (token.length == 0)
    return false;

  for (size_t i = 0; i < token.length; ++i)
  {
    const unsigned char c = (unsigned char)token.data[i];
    if (c <= 0x20 || c >= 0x7f || c == ':' || c == ',')
      return false;
  }

  return true;
}

static bool
_ident_parse_next_field(const char *line, size_t line_length, size_t *offset, struct ident_span *field)
{
  assert(line);
  assert(offset);
  assert(field);
  assert(*offset <= line_length);

  const size_t start = *offset;
  for (size_t i = start; i < line_length; ++i)
  {
    if (line[i] != ':')
      continue;

    field->data = line + start;
    field->length = i - start;
    *offset = i + 1;
    return true;
  }

  return false;
}

static void
_ident_parse_skip_protocol_space(struct ident_span span, size_t *offset)
{
  assert(offset);
  assert(*offset <= span.length);

  while (*offset < span.length && _ident_protocol_is_space((unsigned char)span.data[*offset]))
    ++*offset;
}

static bool
_ident_parse_port(struct ident_span span, size_t *offset, uint16_t *port)
{
  assert(offset);
  assert(port);
  assert(*offset <= span.length);

  _ident_parse_skip_protocol_space(span, offset);

  unsigned int value = 0;
  size_t digit_count = 0;
  while (*offset < span.length)
  {
    const unsigned char c = (unsigned char)span.data[*offset];
    if (c < '0' || c > '9')
      break;
    if (++digit_count > 5)
      return false;

    value = value * 10U + (unsigned int)(c - '0');
    ++*offset;
  }

  if (digit_count == 0 || value == 0 || value > UINT16_MAX)
    return false;

  *port = (uint16_t)value;
  return true;
}

static bool
_ident_parse_port_pair(struct ident_span field, uint16_t *server_port, uint16_t *client_port)
{
  assert(server_port);
  assert(client_port);

  size_t offset = 0;
  if (!_ident_parse_port(field, &offset, server_port))
    return false;

  _ident_parse_skip_protocol_space(field, &offset);

  if (offset == field.length || field.data[offset] != ',')
    return false;

  ++offset;

  if (!_ident_parse_port(field, &offset, client_port))
    return false;

  _ident_parse_skip_protocol_space(field, &offset);
  return offset == field.length;
}

static bool
_ident_parse_opsys_field(struct ident_span field, struct ident_span *opsys)
{
  assert(opsys);

  field = _ident_span_trim(field);
  if (field.length == 0)
    return false;

  size_t comma = field.length;
  for (size_t i = 0; i < field.length; ++i)
  {
    if (field.data[i] == ',')
    {
      comma = i;
      break;
    }
  }

  struct ident_span parsed_opsys = { .data = field.data, .length = comma };
  parsed_opsys = _ident_span_trim(parsed_opsys);

  if (!_ident_token_is_valid(parsed_opsys))
    return false;

  if (comma != field.length)
  {
    struct ident_span charset =
    {
      .data = field.data + comma + 1,
      .length = field.length - comma - 1
    };

    charset = _ident_span_trim(charset);
    if (!_ident_token_is_valid(charset))
      return false;
  }

  *opsys = parsed_opsys;
  return true;
}

static bool
_ident_parse_user_id_reply(const struct ident_request *request, const char *line,
                           size_t line_length, struct ident_user_id_reply *parsed_reply)
{
  assert(request);
  assert(line);
  assert(parsed_reply);

  for (size_t i = 0; i < line_length; ++i)
  {
    if (line[i] == '\0' || line[i] == '\r' || line[i] == '\n')
      return false;
  }

  size_t offset = 0;
  struct ident_span port_pair;
  struct ident_span reply_type;
  struct ident_span opsys_field;

  if (!_ident_parse_next_field(line, line_length, &offset, &port_pair) ||
      !_ident_parse_next_field(line, line_length, &offset, &reply_type) ||
      !_ident_parse_next_field(line, line_length, &offset, &opsys_field))
    return false;

  uint16_t server_port;
  uint16_t client_port;
  if (!_ident_parse_port_pair(port_pair, &server_port, &client_port) ||
      server_port != request->server_port || client_port != request->client_port)
    return false;

  reply_type = _ident_span_trim(reply_type);
  if (!_ident_span_equal(reply_type, "USERID"))
    return false;

  struct ident_span opsys;
  if (!_ident_parse_opsys_field(opsys_field, &opsys))
    return false;

  *parsed_reply = (struct ident_user_id_reply)
  {
    .opsys = opsys,
    .user_id =
    {
      .data = line + offset,
      .length = line_length - offset
    }
  };

  return true;
}

static bool
_ident_user_id_extract(const struct ident_user_id_reply *reply, char *username, size_t username_capacity)
{
  assert(reply);
  assert(username);
  assert(username_capacity > 0);

  if (_ident_span_equal(reply->opsys, "OTHER"))
    return false;

  const struct ident_span user_id = reply->user_id;

  size_t start = 0;
  while (start < user_id.length && io_ascii_is_space(user_id.data[start]))
    ++start;

  while (start < user_id.length && (user_id.data[start] == '~' || user_id.data[start] == '^'))
    ++start;

  size_t end = start;
  while (end < user_id.length)
  {
    const unsigned char c = (unsigned char)user_id.data[end];
    if (io_ascii_is_space(user_id.data[end]) || c == '@' || c == ':')
      break;

    if (c < 0x20 || c == 0x7f)
      return false;

    ++end;
  }

  if (end == start)
    return false;

  size_t username_length = end - start;
  if (username_length >= username_capacity)
    username_length = username_capacity - 1;

  memcpy(username, user_id.data + start, username_length);
  username[username_length] = '\0';
  return true;
}

static void
_ident_timeout_cancel(struct ident_request *request)
{
  assert(request);

  if (request->timeout_event == NULL)
    return;

  event_handle_t timeout_event = request->timeout_event;
  request->timeout_event = NULL;
  event_destroy(timeout_event);
}

static void
_ident_request_destroy(struct ident_request *request)
{
  assert(request);

  if (request->state == IDENT_REQUEST_STATE_ACTIVE)
    list_remove(&request->node, &ident_request_list);

  _ident_timeout_cancel(request);

  fde_t *const fde = request->fde;
  request->fde = NULL;

  if (fde)
  {
    assert(fde->flags.open);
    comm_socket_close(fde);
  }

  io_free(request);
}

static void
_ident_request_complete(struct ident_request *request, const char *username)
{
  assert(request);
  assert(request->state == IDENT_REQUEST_STATE_ACTIVE);
  assert(request->callback);

  ident_callback_fn callback = request->callback;
  void *const callback_ctx = request->callback_ctx;

  _ident_request_destroy(request);
  callback(callback_ctx, username);
}

static void
_ident_request_fail(struct ident_request *request)
{
  assert(request);

  switch (request->state)
  {
    case IDENT_REQUEST_STATE_STARTING:
      request->state = IDENT_REQUEST_STATE_START_FAILED;
      break;
    case IDENT_REQUEST_STATE_ACTIVE:
      _ident_request_complete(request, NULL);
      break;
    case IDENT_REQUEST_STATE_START_FAILED:
      break;
  }
}

static void
_ident_timeout_expire(void *context)
{
  struct ident_request *const request = context;
  assert(request);
  assert(request->state == IDENT_REQUEST_STATE_ACTIVE);
  assert(request->fde);

  event_handle_t timeout_event = request->timeout_event;
  assert(timeout_event);
  request->timeout_event = NULL;
  event_destroy(timeout_event);

  _ident_request_complete(request, NULL);
}

static bool
_ident_errno_is_would_block(int error_code)
{
  switch (error_code)
  {
    case EWOULDBLOCK:
#if EAGAIN != EWOULDBLOCK
    case EAGAIN:
#endif
      return true;
    default:
      return false;
  }
}

static bool
_ident_reply_find_line_end(const char *reply, size_t reply_length, size_t *line_length)
{
  assert(reply);
  assert(line_length);

  for (size_t i = 0; i + 1 < reply_length; ++i)
  {
    if (reply[i] == '\r' && reply[i + 1] == '\n')
    {
      *line_length = i;
      return true;
    }
  }

  return false;
}

static void
_ident_reply_read(fde_t *fde, void *context)
{
  struct ident_request *const request = context;
  assert(request);

  if (request->fde != fde)
    return;

  assert(fde->flags.open);
  assert(request->state == IDENT_REQUEST_STATE_ACTIVE);
  assert(request->reply_length <= sizeof(request->reply));

  while (request->reply_length < sizeof(request->reply))
  {
    const size_t reply_capacity_remaining = sizeof(request->reply) - request->reply_length;
    const ssize_t recv_result = recv(fde->fd, request->reply + request->reply_length,
                                     reply_capacity_remaining, 0);

    if (recv_result > 0)
    {
      request->reply_length += (size_t)recv_result;

      size_t line_length;
      if (_ident_reply_find_line_end(request->reply, request->reply_length, &line_length))
      {
        struct ident_user_id_reply parsed_reply;
        char username[IDENT_USER_ID_CAPACITY];
        const bool user_id_extracted =
          _ident_parse_user_id_reply(request, request->reply, line_length, &parsed_reply) &&
          _ident_user_id_extract(&parsed_reply, username, sizeof(username));

        _ident_request_complete(request, user_id_extracted ? username : NULL);
        return;
      }

      continue;
    }

    if (recv_result == 0)
    {
      _ident_request_complete(request, NULL);
      return;
    }

    if (errno == EINTR)
      continue;

    if (_ident_errno_is_would_block(errno))
    {
      comm_setselect(fde, COMM_SELECT_READ, _ident_reply_read, request);
      return;
    }

    _ident_request_complete(request, NULL);
    return;
  }

  _ident_request_complete(request, NULL);
}

static void
_ident_query_write(fde_t *fde, void *context)
{
  struct ident_request *const request = context;
  assert(request);

  if (request->fde != fde)
    return;

  assert(fde->flags.open);
  assert(request->state == IDENT_REQUEST_STATE_STARTING ||
         request->state == IDENT_REQUEST_STATE_ACTIVE);
  assert(request->query_offset <= request->query_length);

  while (request->query_offset < request->query_length)
  {
    const char *const query_data = request->query + request->query_offset;
    const size_t query_remaining = request->query_length - request->query_offset;
    const ssize_t send_result = send(fde->fd, query_data, query_remaining, 0);

    if (send_result > 0)
    {
      request->query_offset += (size_t)send_result;
      continue;
    }

    if (send_result == -1 && errno == EINTR)
      continue;

    if (send_result == -1 && _ident_errno_is_would_block(errno))
    {
      comm_setselect(fde, COMM_SELECT_WRITE, _ident_query_write, request);
      return;
    }

    _ident_request_fail(request);
    return;
  }

  comm_setselect(fde, COMM_SELECT_READ, _ident_reply_read, request);
}

static void
_ident_connect_complete(fde_t *fde, int error, void *context)
{
  struct ident_request *const request = context;
  assert(request);

  /*
   * Closing a socket with a pending comm_connect_tcp() synchronously invokes
   * its cleanup callback. A request being cancelled detaches its fde before
   * closing it, so this callback becomes a no-op in that re-entrant path.
   */
  if (request->fde != fde)
    return;

  assert(request->state == IDENT_REQUEST_STATE_STARTING ||
         request->state == IDENT_REQUEST_STATE_ACTIVE);
  assert(request->timeout_event);

  if (error != COMM_OK)
  {
    _ident_request_fail(request);
    return;
  }

  _ident_query_write(fde, request);
}

static bool
_ident_sockaddr_result_is_valid(const struct io_addr *addr, socklen_t length)
{
  assert(addr);

  const socklen_t expected_length = address_get_sockaddr_length(addr);
  return expected_length != 0 && length >= expected_length && (size_t)length <= sizeof(addr->ss);
}

static bool
_ident_connection_endpoints_get(int connection_fd, struct io_addr *local_addr_out, struct io_addr *peer_addr_out)
{
  assert(connection_fd >= 0);
  assert(local_addr_out);
  assert(peer_addr_out);
  assert(local_addr_out != peer_addr_out);

  struct io_addr local_addr = { 0 };
  socklen_t local_addr_length = sizeof(local_addr.ss);
  if (getsockname(connection_fd, (struct sockaddr *)&local_addr.ss, &local_addr_length) == -1)
    return false;

  struct io_addr peer_addr = { 0 };
  socklen_t peer_addr_length = sizeof(peer_addr.ss);
  if (getpeername(connection_fd, (struct sockaddr *)&peer_addr.ss, &peer_addr_length) == -1)
    return false;

  if (!_ident_sockaddr_result_is_valid(&local_addr, local_addr_length) ||
      !_ident_sockaddr_result_is_valid(&peer_addr, peer_addr_length))
    return false;

  /*
   * Dual-stack IPv6 sockets may report IPv4 endpoints as IPv4-mapped IPv6.
   * Normalize both ends before comparing families or reusing the addresses.
   */
  address_unmap_ipv4(&local_addr);
  address_unmap_ipv4(&peer_addr);

  if (!address_is_specified(&local_addr) || !address_is_specified(&peer_addr) ||
      address_get_family(&local_addr) != address_get_family(&peer_addr))
    return false;

  *local_addr_out = local_addr;
  *peer_addr_out = peer_addr;
  return true;
}

bool
ident_start(ident_callback_fn callback, void *callback_ctx, int connection_fd, uintmax_t timeout_ms)
{
  assert(callback);

  if (connection_fd < 0 || timeout_ms == 0)
    return false;

  struct io_addr connection_local_addr;
  struct io_addr connection_peer_addr;
  if (!_ident_connection_endpoints_get(connection_fd, &connection_local_addr, &connection_peer_addr))
    return false;

  const uint16_t server_port = address_get_port(&connection_peer_addr);
  const uint16_t client_port = address_get_port(&connection_local_addr);
  if (server_port == 0 || client_port == 0)
    return false;

  struct ident_request *const request = io_calloc(sizeof(*request));
  request->callback = callback;
  request->callback_ctx = callback_ctx;
  request->server_port = server_port;
  request->client_port = client_port;
  request->state = IDENT_REQUEST_STATE_STARTING;

  const int formatted_length = snprintf(request->query, sizeof(request->query), "%u,%u\r\n",
                                        (unsigned int)request->server_port,
                                        (unsigned int)request->client_port);
  if (formatted_length < 0 || (size_t)formatted_length >= sizeof(request->query))
  {
    io_free(request);
    return false;
  }

  request->query_length = (size_t)formatted_length;

  request->fde =
    comm_socket_create(address_get_family(&connection_peer_addr), SOCK_STREAM, 0, "ident");
  if (request->fde == NULL)
  {
    _ident_request_destroy(request);
    return false;
  }

  struct io_addr bind_addr;
  address_copy(&bind_addr, &connection_local_addr);

  if (!address_set_port(&bind_addr, 0))
  {
    _ident_request_destroy(request);
    return false;
  }

  request->timeout_event =
    event_create(comm_event_manager, "ident_timeout", _ident_timeout_expire, timeout_ms, true, request, NULL);
  if (request->timeout_event == NULL || event_schedule(request->timeout_event) != EVENT_SUCCESS)
  {
    _ident_request_destroy(request);
    return false;
  }

  comm_connect_tcp(request->fde, &connection_peer_addr, IDENT_SERVICE_PORT, &bind_addr,
                   _ident_connect_complete, request, 0);

  if (request->state == IDENT_REQUEST_STATE_START_FAILED)
  {
    _ident_request_destroy(request);
    return false;
  }

  assert(request->state == IDENT_REQUEST_STATE_STARTING);
  request->state = IDENT_REQUEST_STATE_ACTIVE;
  list_add(request, &request->node, &ident_request_list);
  return true;
}

void
ident_cancel_by_context(const void *callback_ctx)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, ident_request_list.head)
  {
    struct ident_request *const request = node->data;
    if (request->callback_ctx == callback_ctx)
      _ident_request_destroy(request);
  }
}
