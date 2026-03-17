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

#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "comm.h"
#include "ident.h"
#include "io_string.h"
#include "io_time.h"
#include "log.h"
#include "memory.h"

/**
 * @var IDENT_BUFSIZE
 * @brief Maximum buffer size for RFC 1413 ident replies.
 *
 * The IDENT_BUFSIZE constant represents the maximum buffer size, in bytes, that is
 * allowed for RFC 1413 ident replies. According to the RFC 1413 standard, a server
 * should not send more than 512 octets of user ID and a client must accept at least
 * 512 octets of user ID.
 */
enum { IDENT_BUFSIZE = 512 };

/**
 * @var IDENT_PORTNUM
 * @brief Port number for the (Ident) server.
 *
 * The IDENT_PORTNUM constant represents the TCP port number (113) on which the
 * Ident server listens, adhering to the guidelines outlined in RFC 1413.
 */
enum { IDENT_PORTNUM = 113 };

/**
 * @brief Enumerates the fields in an Ident reply line.
 *
 * This enumeration provides human-readable names for the fields in an Ident
 * reply line. The fields represent different pieces of information extracted
 * during the parsing of an Ident reply.
 */
enum IdentReplyFields
{
  IDENT_PORT_NUMBERS,  /**< Port numbers associated with the connection. */
  IDENT_REPLY_TYPE,  /**< Type of the reply, where "USERID" is expected. */
  IDENT_OS_TYPE,  /**< Type of the operating system. */
  IDENT_INFO,  /**< User information, including the user identifier. */
  USERID_TOKEN_COUNT,  /**< Count of tokens expected in an Ident reply line. */
};

/**
 * @brief Parse an ident reply line and extract the user identifier.
 *
 * This function parses an ident reply line obtained from the ident server and
 * extracts the user identifier.
 *
 * @param reply The ident reply line received from the ident server.
 * @return The user identifier extracted from the reply, or NULL on parsing failure.
 *
 * @details The ident reply line is expected to have the following format:
 * - PortNumbers:ReplyType:OSType:UserInfo
 *   - PortNumbers: The port numbers associated with the connection.
 *   - ReplyType: The type of reply, where "USERID" is expected.
 *   - OSType: The type of the operating system.
 *   - UserInfo: The user information, including the user identifier.
 */
static const char *
ident_check_reply(char *const reply)
{
  char *vector[USERID_TOKEN_COUNT];
  const unsigned int count = token_vector(reply, ':', vector, USERID_TOKEN_COUNT);

  if (USERID_TOKEN_COUNT != count)
    return NULL;

  /*
   * Second token is the reply type
   */
  char *token = vector[IDENT_REPLY_TYPE];
  if (string_is_empty(token))
    return NULL;

  while (IsSpace(*token))
    ++token;

  if (strncmp(token, "USERID", 6))
    return NULL;

  /*
   * Third token is the os type
   */
  token = vector[IDENT_OS_TYPE];
  if (string_is_empty(token))
    return NULL;

  while (IsSpace(*token))
   ++token;

  /*
   * Unless "OTHER" is specified as the operating system type, the server
   * is expected to return the "normal" user identification of the owner
   * of this connection. "Normal" in this context may be taken to mean a
   * string of characters which uniquely identifies the connection owner
   * such as a user identifier assigned by the system administrator and
   * used by such user as a mail identifier, or as the "user" part of a
   * user/password pair used to gain access to system resources. When an
   * operating system is specified (e.g., anything but "OTHER"), the user
   * identifier is expected to be in a more or less immediately useful
   * form - e.g., something that could be used as an argument to "finger"
   * or as a mail address.
   */
  if (strncmp(token, "OTHER", 5) == 0)
    return NULL;

  /*
   * Fourth token is the username
   */
  token = vector[IDENT_INFO];
  if (string_is_empty(token))
    return NULL;

  while (IsSpace(*token))
    ++token;

  while (*token == '~' || *token == '^')
    ++token;

  /*
   * Look for the end of the username, terminators are '\0, @, <SPACE>, :'
   */
  char *end;
  for (end = token; *end; ++end)
    if (IsSpace(*end) || '@' == *end || ':' == *end)
      break;
  *end = '\0';

  return token;
}

void
ident_delete(ident_request_t *request)
{
  if (request->reply_timeout_event)
  {
    event_destroy(request->reply_timeout_event);
    request->reply_timeout_event = NULL;
  }

  if (request->fd)
  {
    comm_socket_close(request->fd);
    request->fd = NULL;
  }

  io_free(request);
}

static void
ident_read_reply(fde_t *F, void *data)
{
  ident_request_t *request = data;

  /* If callback is NULL, the owner is tearing down the request. Abort. */
  if (request->callback == NULL)
    return;

  assert(F->read_handler);

  /* The event is no longer needed as we have received a reply. */
  if (request->reply_timeout_event)
  {
    event_destroy(request->reply_timeout_event);
    request->reply_timeout_event = NULL;
  }

  char buf[IDENT_BUFSIZE + 1];
  ssize_t len = recv(F->fd, buf, sizeof(buf) - 1, 0);
  if (len > 0)
  {
    buf[len] = '\0';
    const char *username = ident_check_reply(buf);
    request->callback(request->user_data, username);
  }
  else
    request->callback(request->user_data, NULL);
}

static void
ident_connect_callback(fde_t *F, int error, void *data)
{
  ident_request_t *request = data;

  /* If callback is NULL, the owner is tearing down the request. Abort. */
  if (request->callback == NULL)
    return;

  if (error != COMM_OK)
  {
    request->callback(request->user_data, NULL);
    return;
  }

  char buf[16];
  ssize_t len = snprintf(buf, sizeof(buf), "%hu,%hu\r\n", request->remote_port, request->local_port);

  if (send(F->fd, buf, len, 0) != len)
  {
    log_write(LOG_TYPE_IRCD, "Failed to send Ident query: %s",
              strerror(errno));
    request->callback(request->user_data, NULL);
    return;
  }

  /*
   * The query has been sent. Now, schedule the reply timeout and set the
   * read handler to wait for the response.
   */
  event_schedule(request->reply_timeout_event);
  comm_setselect(F, COMM_SELECT_READ, ident_read_reply, request);
}

static void
_ident_reply_timeout_handler(void *data)
{
  ident_request_t *request = data;
  assert(request);

  /* The event has fired, so clear the handle. */
  request->reply_timeout_event = NULL;

  /* If callback is NULL, the owner is tearing down the request. Abort. */
  if (request->callback == NULL)
    return;

  request->callback(request->user_data, NULL);
}

ident_request_t *
ident_start(const struct io_addr *addr, int socket_fd, IdentCallback callback, void *user_data, uintmax_t timeout_ms)
{
  ident_request_t *request = io_calloc(sizeof(*request));
  request->callback = callback;
  request->user_data = user_data;

  /*
   * Create the persistent timeout event for this request's lifetime.
   * It is created here but remains unscheduled until the TCP connection succeeds.
   */
  request->reply_timeout_event = event_create(comm_event_manager, "ident_reply_timeout", _ident_reply_timeout_handler,
                                              timeout_ms, true, request, NULL);

  fde_t *new_fde = comm_socket_create(address_get_family(addr), SOCK_STREAM, 0, "ident");
  if (new_fde == NULL)
  {
    ident_delete(request);
    return NULL;
  }

  request->fd = new_fde;

  struct io_addr local_addr;
  struct io_addr remote_addr;
  socklen_t local_len = sizeof(local_addr);
  socklen_t remote_len = sizeof(remote_addr);

  if (getsockname(socket_fd, (struct sockaddr *)&local_addr, &local_len) ||
      getpeername(socket_fd, (struct sockaddr *)&remote_addr, &remote_len))
  {
    log_write(LOG_TYPE_IRCD, "getsockname/getpeername failed: %s",
              strerror(errno));
    ident_delete(request);
    return NULL;
  }

  request->local_port = address_get_port(&local_addr);
  request->remote_port = address_get_port(&remote_addr);

  struct io_addr bind_addr;
  address_copy(&bind_addr, &local_addr);
  address_strip_ipv4(&bind_addr);
  address_set_port(&bind_addr, 0);

  comm_connect_tcp(request->fd, addr, IDENT_PORTNUM, &bind_addr, ident_connect_callback, request, timeout_ms);
  return request;
}
