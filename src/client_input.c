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
  assert(line_length < IRCD_BUFSIZE);

  ++me.connection->recv.messages;
  ++client->connection->recv.messages;

  client->connection->recv.bytes += line_length;
  me.connection->recv.bytes += line_length;

  parse_message(client, line_buffer, line_buffer + line_length);
}

/* extract_one_line()
 *
 * inputs       - pointer to a dbuf queue
 *              - pointer to buffer to copy data to
 * output       - length of <buffer>
 * side effects - one line is copied and removed from the dbuf
 */
static size_t
_client_input_extract_recvq_line(struct dbuf_queue *queue, char *line_buffer)
{
  size_t line_bytes = 0, eol_bytes = 0;
  list_node_t *node;

  LIST_FOREACH(node, queue->blocks.head)
  {
    const struct dbuf_block *block = node->data;
    size_t idx;

    if (node == queue->blocks.head)
      idx = queue->pos;
    else
      idx = 0;

    for (; idx < block->size; ++idx)
    {
      char c = block->data[idx];

      if (IsEol(c))
      {
        ++eol_bytes;

        /* Allow 2 eol bytes per message */
        if (eol_bytes == 2)
          goto out;
      }
      else if (eol_bytes)
        goto out;
      else if (line_bytes < IRCD_BUFSIZE - 2)
      {
        ++line_bytes;
        *line_buffer++ = c;
      }
    }
  }

out:

  assert(line_bytes <= IRCD_BUFSIZE - 2);

  /*
   * Now, if we haven't found an EOL, ignore all line bytes
   * that we have read, since this is a partial line case.
   */
  if (eol_bytes)
    *line_buffer = '\0';
  else
    line_bytes = 0;

  /* Remove what is now unnecessary */
  dbuf_delete(queue, line_bytes + eol_bytes);

  return IO_MIN(line_bytes, IRCD_BUFSIZE - 2);
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

    const size_t line_length = _client_input_extract_recvq_line(&client->connection->buf_recvq, line_buffer);
    if (line_length == 0)
      return;

    _client_input_dispatch_line(client, line_buffer, line_length);
    ++line_count;

    /* Registration commands may transition the connection out of the unknown state. */
    if (!client_is_unknown(client))
      return;
  }
}

static void
_client_input_process_recvq_server(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client_is_connecting(client) || client_is_handshake(client) || IsServer(client));

  char line_buffer[IRCD_BUFSIZE];

  while (true)
  {
    if (client_is_defunct(client))
      return;

    const size_t line_length = _client_input_extract_recvq_line(&client->connection->buf_recvq, line_buffer);
    if (line_length == 0)
      return;

    _client_input_dispatch_line(client, line_buffer, line_length);
  }
}

static void
_client_input_process_recvq_client(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(IsClient(client));

  char line_buffer[IRCD_BUFSIZE];
  bool enforce_limits = true;

  if (ConfigGeneral.no_oper_flood && client_is_oper(client))
    enforce_limits = false;
  else if (client_has_flag(client, FLAGS_CANFLOOD))
    enforce_limits = false;

  while (true)
  {
    if (client_is_defunct(client))
      return;

    /*
     * The parsed-line budget is replenished by client_input_flood_recalc().
     * Once exhausted, stop processing until additional budget becomes
     * available.
     */
    if (enforce_limits && client->connection->input_parse_debt >=
        (client_has_flag(client, FLAGS_FLOODDONE) ?
         CLIENT_INPUT_USER_LINE_BUDGET :
         CLIENT_INPUT_USER_BURST_LINE_BUDGET))
      return;

    const size_t line_length = _client_input_extract_recvq_line(&client->connection->buf_recvq, line_buffer);
    if (line_length == 0)
      return;

    _client_input_dispatch_line(client, line_buffer, line_length);
    ++client->connection->input_parse_debt;
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

  if (IsClient(client))
  {
    _client_input_process_recvq_client(client);
    return;
  }

  assert(client_is_connecting(client) || client_is_handshake(client) || IsServer(client));
  _client_input_process_recvq_server(client);
}

void
client_input_flood_endgrace(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(IsClient(client));

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
  assert(IsClient(client));

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
