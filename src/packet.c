/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file packet.c
 * \brief Packet handlers.
 */

#include "stdinc.h"
#include "list.h"
#include "s_bsd.h"
#include "conf.h"
#include "server.h"
#include "client.h"
#include "ircd.h"
#include "parse.h"
#include "fdlist.h"
#include "packet.h"
#include "irc_string.h"
#include "memory.h"
#include "send.h"
#include "misc.h"


enum { READBUF_SIZE = 16384 };

static char readBuf[READBUF_SIZE];


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
client_dopacket(struct Client *client, char *buffer, unsigned int length)
{
  /* Update messages received */
  ++me.connection->recv.messages;
  ++client->connection->recv.messages;

  /* Update bytes received */
  client->connection->recv.bytes += length;
  me.connection->recv.bytes += length;

  parse(client, buffer, buffer + length);
}

/* extract_one_line()
 *
 * inputs       - pointer to a dbuf queue
 *              - pointer to buffer to copy data to
 * output       - length of <buffer>
 * side effects - one line is copied and removed from the dbuf
 */
static size_t
extract_one_line(struct dbuf_queue *qptr, char *buffer)
{
  size_t line_bytes = 0, eol_bytes = 0;
  dlink_node *node;

  DLINK_FOREACH(node, qptr->blocks.head)
  {
    const struct dbuf_block *block = node->data;
    unsigned int idx;

    if (node == qptr->blocks.head)
      idx = qptr->pos;
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
      else if (line_bytes++ < IRCD_BUFSIZE - 2)
        *buffer++ = c;
    }
  }

out:

  /*
   * Now, if we haven't found an EOL, ignore all line bytes
   * that we have read, since this is a partial line case.
   */
  if (eol_bytes)
    *buffer = '\0';
  else
    line_bytes = 0;

  /* Remove what is now unnecessary */
  dbuf_delete(qptr, line_bytes + eol_bytes);

  return IRCD_MIN(line_bytes, IRCD_BUFSIZE - 2);
}

/*
 * parse_client_queued - parse client queued messages
 */
static void
parse_client_queued(struct Client *client)
{
  if (IsUnknown(client))
  {
    unsigned int i = 0;

    while (true)
    {
      if (IsDefunct(client))
        return;

      /* Rate unknown clients at MAX_FLOOD per loop */
      if (i >= MAX_FLOOD)
        return;

      size_t dolen = extract_one_line(&client->connection->buf_recvq, readBuf);
      if (dolen == 0)
        return;

      client_dopacket(client, readBuf, dolen);
      ++i;

      /*
       * If they've dropped out of the unknown state, break and move
       * to the parsing for their appropriate status.  --fl
       */
      if (!IsUnknown(client))
        break;
    }
  }

  if (IsServer(client) || IsConnecting(client) || IsHandshake(client))
  {
    while (true)
    {
      if (IsDefunct(client))
        return;

      size_t dolen = extract_one_line(&client->connection->buf_recvq, readBuf);
      if (dolen == 0)
        return;

      client_dopacket(client, readBuf, dolen);
    }
  }
  else if (IsClient(client))
  {
    bool checkflood = true;

    if (ConfigGeneral.no_oper_flood && HasUMode(client, UMODE_OPER))
      checkflood = false;
    else if (HasFlag(client, FLAGS_CANFLOOD))
      checkflood = false;

    /*
     * Handle flood protection here - if we exceed our flood limit on messages
     * in this loop, we simply drop out of the loop prematurely.
     *   -- adrian
     */
    while (true)
    {
      if (IsDefunct(client))
        return;

      /*
       * This flood protection works as follows:
       *
       * A client is given allow_read lines to send to the server.  Every
       * time a line is parsed, sent_parsed is increased.  sent_parsed
       * is decreased by 1 every time flood_recalc is called.
       *
       * Thus a client can 'burst' allow_read lines to the server, any
       * excess lines will be parsed one per flood_recalc() call.
       *
       * Therefore a client will be penalised more if they keep flooding,
       * as sent_parsed will always hover around the allow_read limit
       * and no 'bursts' will be permitted.
       */
      if (checkflood)
        if (client->connection->sent_parsed >=
          (HasFlag(client, FLAGS_FLOODDONE) ? MAX_FLOOD : MAX_FLOOD_BURST))
          return;

      size_t dolen = extract_one_line(&client->connection->buf_recvq, readBuf);
      if (dolen == 0)
        return;

      client_dopacket(client, readBuf, dolen);
      ++client->connection->sent_parsed;
    }
  }
}

/* flood_endgrace()
 *
 * marks the end of the clients grace period
 */
void
flood_endgrace(struct Client *client)
{
  if (HasFlag(client, FLAGS_FLOODDONE))
    return;  /* Grace period has already ended */

  AddFlag(client, FLAGS_FLOODDONE);

  /*
   * sent_parsed could be way over MAX_FLOOD but under MAX_FLOOD_BURST,
   * so reset it.
   */
  client->connection->sent_parsed = 0;
}

/*
 * flood_recalc
 *
 * recalculate the number of allowed flood lines. this should be called
 * once a second on any given client. We then attempt to flush some data.
 */
void
flood_recalc(fde_t *F, void *data)
{
  struct Client *const client = data;

  /*
   * Allow a bursting client their allocation per second, allow
   * a client who is flooding an extra 2 per second
   */
  if (HasFlag(client, FLAGS_FLOODDONE))
    client->connection->sent_parsed -= 2;
  else
    client->connection->sent_parsed = 0;

  if (client->connection->sent_parsed < 0)
    client->connection->sent_parsed = 0;

  parse_client_queued(client);

  /* And now, try flushing .. */
  if (!IsDead(client))
  {
    /* and finally, reset the flood check */
    comm_setflush(F, 1, flood_recalc, client);
  }
}

/*
 * read_packet - Read a 'packet' of data from a connection and process it.
 */
void
read_packet(fde_t *F, void *data)
{
  struct Client *const client = data;
  ssize_t length = 0;

  assert(client);
  assert(client->connection);
  assert(client->connection->fd);
  assert(client->connection->fd == F);

  if (IsDefunct(client))
    return;

  /*
   * Read some data. We *used to* do anti-flood protection here, but
   * I personally think it makes the code too hairy to make sane.
   *     -- adrian
   */
  while (true)
  {
    if (tls_isusing(&F->tls))
    {
      bool want_write = false;
      length = tls_read(&F->tls, readBuf, sizeof(readBuf), &want_write);

      if (want_write)
        comm_setselect(F, COMM_SELECT_WRITE, sendq_unblocked, client, 0);
    }
    else
      length = recv(F->fd, readBuf, sizeof(readBuf), 0);

    if (length <= 0)
    {
      /*
       * If true, then we can recover from this error. Stop here and register for
       * another COMM_SELECT_READ io-request.
       */
      if (length < 0 && comm_ignore_errno(errno))
        comm_setselect(F, COMM_SELECT_READ, read_packet, client, 0);
      else
        dead_link_on_read(client, length);
      return;
    }

    dbuf_put(&client->connection->buf_recvq, readBuf, length);

    client->connection->last_ping = event_base->time.sec_monotonic;
    client->connection->last_data = event_base->time.sec_monotonic;

    DelFlag(client, FLAGS_PINGSENT);

    /* Attempt to parse what we have */
    parse_client_queued(client);

    if (IsDefunct(client))
      return;

    /* Check to make sure we're not flooding */
    if (!(IsServer(client) || IsHandshake(client) || IsConnecting(client)) &&
        (dbuf_length(&client->connection->buf_recvq) >
         class_get_recvq(&client->connection->confs)))
    {
      exit_client(client, "Excess Flood");
      return;
    }
  }
}
