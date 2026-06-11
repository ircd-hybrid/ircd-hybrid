/*!
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

/*! \file client_input.c
 * \brief Processing of queued input received from local connections.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "list.h"
#include "misc.h"

#include "client.h"
#include "client_input.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"

/*
 * client_dopacket - copy packet to client buf and parse it
 *      client - pointer to client structure for which the buffer data
 *             applies.
 *      buffer - pointer to the buffer containing the newly read data
 *      length - number of valid bytes of data in the buffer
 *
 * Note:
 *      It is implicitly assumed that client_dopacket() is called only
 *      with client of "local" variation, which contains all the
 *      necessary fields (buffer etc..)
 */
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

/**
 * @brief Extracts one complete protocol message from a receive queue.
 *
 * Copies the message text without its line terminator into line_buffer,
 * NUL-terminates it, stores the copied length in line_length, and removes
 * the full physical message including its terminator from the queue.
 *
 * Overlong messages are truncated in line_buffer, but still consumed completely.
 * Empty messages are returned as complete messages with line_length set to 0.
 *
 * @param queue       The receive queue to extract from.
 * @param line_buffer The destination buffer for the extracted message text.
 * @param line_length Receives the number of copied message-text bytes.
 * @return true if a complete message was consumed, false if no complete message is available.
 */
static bool
_client_input_extract_recvq_line(struct dbuf_queue *queue, char *line_buffer, size_t *line_length)
{
  const size_t message_text_max = IRCD_BUFSIZE - 2;

  size_t copied_bytes = 0;
  size_t consumed_bytes = 0;
  size_t eol_bytes = 0;

  assert(queue);
  assert(line_buffer);
  assert(line_length);

  *line_length = 0;
  line_buffer[0] = '\0';

  list_node_t *node;
  LIST_FOREACH(node, queue->blocks.head)
  {
    const struct dbuf_block *const block = node->data;
    size_t idx = (node == queue->blocks.head) ? queue->pos : 0;

    for (; idx < block->size; ++idx)
    {
      const char c = block->data[idx];
      if (c == '\r' || c == '\n')
      {
        ++consumed_bytes;
        ++eol_bytes;

        /*
         * Consume at most two consecutive CR/LF bytes as the message terminator.
         * Additional CR/LF bytes remain queued and are processed as subsequent
         * empty messages.
         */
        if (eol_bytes == 2)
          goto complete;

        continue;
      }

      if (eol_bytes)
        goto complete;

      ++consumed_bytes;

      if (copied_bytes < message_text_max)
        line_buffer[copied_bytes++] = c;
    }
  }

  if (eol_bytes == 0)
    return false;

complete:
  assert(consumed_bytes > 0);
  assert(copied_bytes <= message_text_max);

  line_buffer[copied_bytes] = '\0';
  *line_length = copied_bytes;

  dbuf_delete(queue, consumed_bytes);
  return true;
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
    if (!_client_input_extract_recvq_line(&client->connection->buf_recvq, line_buffer, &line_length))
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
    if (!_client_input_extract_recvq_line(&client->connection->buf_recvq, line_buffer, &line_length))
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
    if (!_client_input_extract_recvq_line(&client->connection->buf_recvq, line_buffer, &line_length))
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
