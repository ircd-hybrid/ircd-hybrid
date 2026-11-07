/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file client_input.c
 * \brief Processing of queued input received from local connections.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "dbuf.h"

#include "client.h"
#include "client_input.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"

static void
_client_input_dispatch_line(struct Client *client, char *line_buffer, size_t line_length)
{
  assert(client && client_is_local(client));
  assert(!client_is_defunct(client));
  assert(line_buffer);
  assert(line_length < IRCD_BUFSIZE);
  assert(line_buffer[line_length] == '\0');

  ++me.connection->recv.messages;
  ++client->connection->recv.messages;

  client->connection->recv.bytes += line_length;
  me.connection->recv.bytes += line_length;

  parse_message(client, line_buffer, line_buffer + line_length);
}

enum client_input_line_result
{
  CLIENT_INPUT_LINE_INCOMPLETE,
  CLIENT_INPUT_LINE_COMPLETE,
  CLIENT_INPUT_LINE_MALFORMED,
  CLIENT_INPUT_LINE_TOO_LONG,
};

/**
 * @brief Extract the next LF-terminated IRC message from a receive queue.
 *
 * LF terminates a message. A directly preceding CR is consumed as part
 * of the canonical CRLF terminator; bare LF is accepted for compatibility.
 * NUL and any other CR make the input malformed.
 *
 * A valid message is copied without its terminator, NUL-terminated, and
 * removed from the queue. Empty messages are returned with a length of zero.
 *
 * Malformed or overlong input is reported as soon as it can no longer
 * become valid, even if no terminating LF has been received.
 *
 * Unless CLIENT_INPUT_LINE_COMPLETE is returned, the queue remains unchanged
 * and the output is reset to an empty string.
 *
 * @param queue       Receive queue to inspect.
 * @param line_buffer Destination buffer for the message text. It must provide
 *                    at least IRCD_BUFSIZE bytes.
 * @param line_length Receives the extracted message-text length.
 * @return Result of the extraction attempt.
 */
static enum client_input_line_result
_client_input_extract_recvq_line(struct dbuf_queue *queue, char *line_buffer, size_t *line_length)
{
  assert(queue);
  assert(line_buffer);
  assert(line_length);

  const size_t message_length_max = IRCD_BUFSIZE - 2;
  size_t message_length = 0;
  size_t consumed_length = 0;
  bool trailing_cr = false;

  line_buffer[0] = '\0';
  *line_length = 0;

  struct dbuf_queue_iterator iterator;
  dbuf_queue_iterator_init(queue, &iterator);

  struct dbuf_view view;

  while (dbuf_queue_iterator_next(&iterator, &view))
  {
    assert(view.data);
    assert(view.length > 0);

    const char *const data = view.data;

    for (size_t index = 0; index < view.length; ++index)
    {
      const char byte = data[index];
      ++consumed_length;

      if (byte == '\n')
      {
        line_buffer[message_length] = '\0';
        *line_length = message_length;

        assert(consumed_length <= dbuf_queue_length(queue));

        dbuf_queue_consume(queue, consumed_length);
        return CLIENT_INPUT_LINE_COMPLETE;
      }

      if (trailing_cr)
      {
        line_buffer[0] = '\0';
        return CLIENT_INPUT_LINE_MALFORMED;
      }

      /*
       * A CR is valid only when immediately followed by LF. This state
       * intentionally persists across queue-view boundaries.
       */
      if (byte == '\r')
      {
        trailing_cr = true;
        continue;
      }

      if (byte == '\0')
      {
        line_buffer[0] = '\0';
        return CLIENT_INPUT_LINE_MALFORMED;
      }

      if (message_length >= message_length_max)
      {
        line_buffer[0] = '\0';
        return CLIENT_INPUT_LINE_TOO_LONG;
      }

      line_buffer[message_length++] = byte;
    }
  }

  /*
   * A final CR may still become part of a subsequent CRLF terminator.
   * No queued data is consumed until a complete valid line is found.
   */
  line_buffer[0] = '\0';
  return CLIENT_INPUT_LINE_INCOMPLETE;
}

static bool
_client_input_read_next_line(struct Client *client, char *line_buffer, size_t *line_length)
{
  assert(client && client_is_local(client));
  assert(!client_is_defunct(client));
  assert(line_buffer);
  assert(line_length);

  const enum client_input_line_result result =
    _client_input_extract_recvq_line(&client->connection->recv_queue, line_buffer, line_length);

  switch (result)
  {
    case CLIENT_INPUT_LINE_INCOMPLETE:
      return false;
    case CLIENT_INPUT_LINE_COMPLETE:
      return true;
    case CLIENT_INPUT_LINE_MALFORMED:
      client_exit(client, "Malformed IRC message");
      return false;
    case CLIENT_INPUT_LINE_TOO_LONG:
      client_exit(client, "IRC message too long");
      return false;
  }

  assert(0);
  return false;
}

static void
_client_input_process_recvq_unknown(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_unknown(client));

  char line_buffer[IRCD_BUFSIZE];
  unsigned int line_count = 0;

  while (true)
  {
    if (client_is_defunct(client))
      return;

    if (line_count >= CLIENT_INPUT_HANDSHAKE_LINE_LIMIT)
      return;

    size_t line_length = 0;
    if (!_client_input_read_next_line(client, line_buffer, &line_length))
      return;

    ++line_count;

    if (line_length == 0)
      continue;

    _client_input_dispatch_line(client, line_buffer, line_length);

    /* Registration commands may transition the connection out of the unknown state. */
    if (!client_is_unknown(client))
      return;
  }
}

static void
_client_input_process_recvq_server(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_connecting(client) || client_is_handshake(client) || client_is_server(client));

  char line_buffer[IRCD_BUFSIZE];

  while (true)
  {
    if (client_is_defunct(client))
      return;

    size_t line_length = 0;
    if (!_client_input_read_next_line(client, line_buffer, &line_length))
      return;

    if (line_length == 0)
      continue;

    _client_input_dispatch_line(client, line_buffer, line_length);
  }
}

static bool
_client_input_should_enforce_user_limits(const struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_user(client));

  if (ConfigGeneral.no_oper_flood && client_is_oper(client))
    return false;

  if (client_has_flag(client, FLAGS_CANFLOOD))
    return false;

  return true;
}

static void
_client_input_process_recvq_user(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_user(client));

  char line_buffer[IRCD_BUFSIZE];

  while (true)
  {
    if (client_is_defunct(client))
      return;

    /*
     * The parsed-line budget is replenished by client_input_flood_recalc().
     * Once exhausted, stop processing until additional budget becomes
     * available.
     */
    const bool enforce_limits = _client_input_should_enforce_user_limits(client);
    if (enforce_limits && client->connection->input_parse_debt >=
        (client_has_flag(client, FLAGS_FLOODDONE) ?
         CLIENT_INPUT_USER_LINE_BUDGET :
         CLIENT_INPUT_USER_BURST_LINE_BUDGET))
      return;

    size_t line_length = 0;
    if (!_client_input_read_next_line(client, line_buffer, &line_length))
      return;

    ++client->connection->input_parse_debt;

    if (line_length == 0)
      continue;

    _client_input_dispatch_line(client, line_buffer, line_length);
  }
}

void
client_input_process_recvq(struct Client *client)
{
  assert(client && client_is_local(client));

  if (client_is_unknown(client))
  {
    _client_input_process_recvq_unknown(client);

    /*
     * Registration parsing may have changed the client state. Re-evaluate the
     * current state before attempting to process any remaining queued input.
     */
    if (client_is_defunct(client) || client_is_unknown(client))
      return;
  }

  if (client_is_user(client))
  {
    _client_input_process_recvq_user(client);
    return;
  }

  assert(client_is_connecting(client) || client_is_handshake(client) || client_is_server(client));
  _client_input_process_recvq_server(client);
}

void
client_input_flood_endgrace(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_user(client));

  if (client_has_flag(client, FLAGS_FLOODDONE))
    return;

  /*
   * Grace period has ended. Reset the parsed-line budget so normal
   * flood limits apply immediately.
   */
  client_set_flag(client, FLAGS_FLOODDONE);
  client->connection->input_parse_debt = 0;
}

void
client_input_flood_recalc(void *data_)
{
  struct Client *const client = data_;
  assert(client && client_is_local(client));
  assert(client_is_user(client));

  /*
   * This callback may still fire for a client that has already
   * entered the shutdown path.
   */
  if (client_is_defunct(client))
    return;

  if (client_has_flag(client, FLAGS_FLOODDONE))
    client->connection->input_parse_debt -= 2;
  else
    client->connection->input_parse_debt = 0;

  if (client->connection->input_parse_debt < 0)
    client->connection->input_parse_debt = 0;

  client_input_process_recvq(client);
}
