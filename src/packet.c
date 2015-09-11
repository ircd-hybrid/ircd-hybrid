/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
 * \version $Id$
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
 *      client_p - pointer to client structure for which the buffer data
 *             applies.
 *      buffer - pointer to the buffer containing the newly read data
 *      length - number of valid bytes of data in the buffer
 *
 * Note:
 *      It is implicitly assumed that client_dopacket() is called only
 *      with client_p of "local" variation, which contains all the
 *      necessary fields (buffer etc..)
 */
static void
client_dopacket(struct Client *client_p, char *buffer, unsigned int length)
{
  /* Update messages received */
  ++me.connection->recv.messages;
  ++client_p->connection->recv.messages;

  /* Update bytes received */
  client_p->connection->recv.bytes += length;
  me.connection->recv.bytes += length;

  parse(client_p, buffer, buffer + length);
}

/* extract_one_line()
 *
 * inputs       - pointer to a dbuf queue
 *              - pointer to buffer to copy data to
 * output       - length of <buffer>
 * side effects - one line is copied and removed from the dbuf
 */
static unsigned int
extract_one_line(struct dbuf_queue *qptr, char *buffer)
{
  unsigned int line_bytes = 0, eol_bytes = 0;
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
parse_client_queued(struct Client *client_p)
{
  unsigned int dolen = 0;

  if (IsUnknown(client_p))
  {
    unsigned int i = 0;

    while (1)
    {
      if (IsDefunct(client_p))
        return;

      /* Rate unknown clients at MAX_FLOOD per loop */
      if (i >= MAX_FLOOD)
        break;

      dolen = extract_one_line(&client_p->connection->buf_recvq, readBuf);

      if (dolen == 0)
        break;

      client_dopacket(client_p, readBuf, dolen);
      ++i;

      /*
       * If they've dropped out of the unknown state, break and move
       * to the parsing for their appropriate status.  --fl
       */
      if (!IsUnknown(client_p))
        break;
    }
  }

  if (IsServer(client_p) || IsConnecting(client_p) || IsHandshake(client_p))
  {
    while (1)
    {
      if (IsDefunct(client_p))
        return;

      if ((dolen = extract_one_line(&client_p->connection->buf_recvq, readBuf)) == 0)
        break;

      client_dopacket(client_p, readBuf, dolen);
    }
  }
  else if (IsClient(client_p))
  {
    unsigned int checkflood = 1;

    if (ConfigGeneral.no_oper_flood && HasUMode(client_p, UMODE_OPER))
      checkflood = 0;
    else if (HasFlag(client_p, FLAGS_CANFLOOD))
      checkflood = 0;

    /*
     * Handle flood protection here - if we exceed our flood limit on messages
     * in this loop, we simply drop out of the loop prematurely.
     *   -- adrian
     */
    while (1)
    {
      if (IsDefunct(client_p))
        break;

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
        if (client_p->connection->sent_parsed >= client_p->connection->allow_read)
          break;

      dolen = extract_one_line(&client_p->connection->buf_recvq, readBuf);

      if (dolen == 0)
        break;

      client_dopacket(client_p, readBuf, dolen);
      ++client_p->connection->sent_parsed;
    }
  }
}

/* flood_endgrace()
 *
 * marks the end of the clients grace period
 */
void
flood_endgrace(struct Client *client_p)
{
  AddFlag(client_p, FLAGS_FLOODDONE);

  /* Drop their flood limit back down */
  client_p->connection->allow_read = MAX_FLOOD;

  /*
   * sent_parsed could be way over MAX_FLOOD but under MAX_FLOOD_BURST,
   * so reset it.
   */
  client_p->connection->sent_parsed = 0;
}

/*
 * flood_recalc
 *
 * recalculate the number of allowed flood lines. this should be called
 * once a second on any given client. We then attempt to flush some data.
 */
void
flood_recalc(fde_t *fd, void *data)
{
  struct Client *const client_p = data;

  /*
   * Allow a bursting client their allocation per second, allow
   * a client who is flooding an extra 2 per second
   */
  if (IsFloodDone(client_p))
    client_p->connection->sent_parsed -= 2;
  else
    client_p->connection->sent_parsed = 0;

  if (client_p->connection->sent_parsed < 0)
    client_p->connection->sent_parsed = 0;

  parse_client_queued(client_p);

  /* And now, try flushing .. */
  if (!IsDead(client_p))
  {
    /* and finally, reset the flood check */
    comm_setflush(fd, 1000, flood_recalc, client_p);
  }
}

/*
 * read_packet - Read a 'packet' of data from a connection and process it.
 */
void
read_packet(fde_t *fd, void *data)
{
  struct Client *const client_p = data;
  int length = 0;

  if (IsDefunct(client_p))
    return;

  /*
   * Read some data. We *used to* do anti-flood protection here, but
   * I personally think it makes the code too hairy to make sane.
   *     -- adrian
   */
  do
  {
#ifdef HAVE_LIBCRYPTO
    if (fd->ssl)
    {
      length = SSL_read(fd->ssl, readBuf, sizeof(readBuf));

      /* translate openssl error codes, sigh */
      if (length < 0)
        switch (SSL_get_error(fd->ssl, length))
        {
          case SSL_ERROR_WANT_WRITE:
            comm_setselect(fd, COMM_SELECT_WRITE, sendq_unblocked, client_p, 0);
            return;
          case SSL_ERROR_WANT_READ:
              errno = EWOULDBLOCK;
          case SSL_ERROR_SYSCALL:
              break;
          case SSL_ERROR_SSL:
            if (errno == EAGAIN)
              break;
          default:
            length = errno = 0;
        }
    }
    else
#endif
    {
      length = recv(fd->fd, readBuf, sizeof(readBuf), 0);
    }

    if (length <= 0)
    {
      /*
       * If true, then we can recover from this error. Just jump out of
       * the loop and re-register a new io-request.
       */
      if (length < 0 && ignoreErrno(errno))
        break;

      dead_link_on_read(client_p, length);
      return;
    }

    dbuf_put(&client_p->connection->buf_recvq, readBuf, length);

    if (client_p->connection->lasttime < CurrentTime)
      client_p->connection->lasttime = CurrentTime;

    if (client_p->connection->lasttime > client_p->connection->since)
      client_p->connection->since = CurrentTime;

    DelFlag(client_p, FLAGS_PINGSENT);

    /* Attempt to parse what we have */
    parse_client_queued(client_p);

    if (IsDefunct(client_p))
      return;

    /* Check to make sure we're not flooding */
    if (!(IsServer(client_p) || IsHandshake(client_p) || IsConnecting(client_p)) &&
        (dbuf_length(&client_p->connection->buf_recvq) >
         get_recvq(&client_p->connection->confs)))
    {
      exit_client(client_p, "Excess Flood");
      return;
    }
  }
#ifdef HAVE_LIBCRYPTO
  while (length == sizeof(readBuf) || fd->ssl);
#else
  while (length == sizeof(readBuf));
#endif

  /* If we get here, we need to register for another COMM_SELECT_READ */
  comm_setselect(fd, COMM_SELECT_READ, read_packet, client_p, 0);
}
