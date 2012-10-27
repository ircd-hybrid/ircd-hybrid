/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  packet.c: Packet handlers.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */
#include "stdinc.h"
#include "list.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_serv.h"
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "parse.h"
#include "fdlist.h"
#include "packet.h"
#include "irc_string.h"
#include "memory.h"
#include "hook.h"
#include "send.h"

#define READBUF_SIZE 16384

struct Callback *iorecv_cb = NULL;
struct Callback *iorecvctrl_cb = NULL;

static char readBuf[READBUF_SIZE];
static void client_dopacket(struct Client *, char *, size_t);

/* extract_one_line()
 *
 * inputs       - pointer to a dbuf queue
 *              - pointer to buffer to copy data to
 * output       - length of <buffer>
 * side effects - one line is copied and removed from the dbuf
 */
static int
extract_one_line(struct dbuf_queue *qptr, char *buffer)
{
  struct dbuf_block *block;
  int line_bytes = 0, empty_bytes = 0, phase = 0;
  unsigned int idx;

  char c;
  dlink_node *ptr;

  /*
   * Phase 0: "empty" characters before the line
   * Phase 1: copying the line
   * Phase 2: "empty" characters after the line
   *          (delete them as well and free some space in the dbuf)
   *
   * Empty characters are CR, LF and space (but, of course, not
   * in the middle of a line). We try to remove as much of them as we can,
   * since they simply eat server memory.
   *
   * --adx
   */
  DLINK_FOREACH(ptr, qptr->blocks.head)
  {
    block = ptr->data;

    for (idx = 0; idx < block->size; idx++)
    {
      c = block->data[idx];
      if (IsEol(c) || (c == ' ' && phase != 1))
      {
        empty_bytes++;
        if (phase == 1)
          phase = 2;
      }
      else switch (phase)
      {
        case 0: phase = 1;
        case 1: if (line_bytes++ < IRCD_BUFSIZE - 2)
                  *buffer++ = c;
                break;
        case 2: *buffer = '\0';
                dbuf_delete(qptr, line_bytes + empty_bytes);
                return IRCD_MIN(line_bytes, IRCD_BUFSIZE - 2);
      }
    }
  }

  /*
   * Now, if we haven't reached phase 2, ignore all line bytes
   * that we have read, since this is a partial line case.
   */
  if (phase != 2)
    line_bytes = 0;
  else
    *buffer = '\0';

  /* Remove what is now unnecessary */
  dbuf_delete(qptr, line_bytes + empty_bytes);
  return IRCD_MIN(line_bytes, IRCD_BUFSIZE - 2);
}

/*
 * parse_client_queued - parse client queued messages
 */
static void
parse_client_queued(struct Client *client_p)
{ 
  int dolen = 0;
  int checkflood = 1;
  struct LocalUser *lclient_p = client_p->localClient;

  if (IsUnknown(client_p))
  {
    int i = 0;

    for(;;)
    {
      if (IsDefunct(client_p))
	return;

      /* rate unknown clients at MAX_FLOOD per loop */
      if (i >= MAX_FLOOD)
        break;

      dolen = extract_one_line(&lclient_p->buf_recvq, readBuf);
      if (dolen == 0)
	break;

      client_dopacket(client_p, readBuf, dolen);
      i++;

      /* if they've dropped out of the unknown state, break and move
       * to the parsing for their appropriate status.  --fl
       */
      if(!IsUnknown(client_p))
        break;
    }
  }

  if (IsServer(client_p) || IsConnecting(client_p) || IsHandshake(client_p))
  {
    while (1)
    {
      if (IsDefunct(client_p))
        return;
      if ((dolen = extract_one_line(&lclient_p->buf_recvq,
                                    readBuf)) == 0)
        break;
      client_dopacket(client_p, readBuf, dolen);
    }
  }
  else if (IsClient(client_p))
  {
    if (ConfigFileEntry.no_oper_flood && (IsOper(client_p) || IsCanFlood(client_p)))
    {
      if (ConfigFileEntry.true_no_oper_flood)
        checkflood = -1;
      else
        checkflood = 0;
    }

    /*
     * Handle flood protection here - if we exceed our flood limit on
     * messages in this loop, we simply drop out of the loop prematurely.
     *   -- adrian
     */
    for (;;)
    {
      if (IsDefunct(client_p))
	break;

      /* This flood protection works as follows:
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
      if (checkflood > 0)
      {
        if(lclient_p->sent_parsed >= lclient_p->allow_read)
          break;
      }
      
      /* allow opers 4 times the amount of messages as users. why 4?
       * why not. :) --fl_
       */
      else if (lclient_p->sent_parsed >= (4 * lclient_p->allow_read) &&
               checkflood != -1)
        break;

      dolen = extract_one_line(&lclient_p->buf_recvq, readBuf);
      if (dolen == 0)
        break;

      client_dopacket(client_p, readBuf, dolen);
      lclient_p->sent_parsed++;
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
  SetFloodDone(client_p);

  /* Drop their flood limit back down */
  client_p->localClient->allow_read = MAX_FLOOD;

  /* sent_parsed could be way over MAX_FLOOD but under MAX_FLOOD_BURST,
   * so reset it.
   */
  client_p->localClient->sent_parsed = 0;
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
  struct Client *client_p = data;
  struct LocalUser *lclient_p = client_p->localClient;
 
  /* allow a bursting client their allocation per second, allow
   * a client whos flooding an extra 2 per second
   */
  if (IsFloodDone(client_p))
    lclient_p->sent_parsed -= 2;
  else
    lclient_p->sent_parsed = 0;
  
  if (lclient_p->sent_parsed < 0)
    lclient_p->sent_parsed = 0;
  
  parse_client_queued(client_p);
  
  /* And now, try flushing .. */
  if (!IsDead(client_p))
  {
    /* and finally, reset the flood check */
    comm_setflush(fd, 1000, flood_recalc, client_p);
  }
}

/*
 * read_ctrl_packet - Read a 'packet' of data from a servlink control
 *                    link and process it.
 */
void
read_ctrl_packet(fde_t *fd, void *data)
{
  struct Client *server = data;
  struct LocalUser *lserver = server->localClient;
  struct SlinkRpl *reply;
  int length = 0;
  unsigned char tmp[2];
  unsigned char *len = tmp;
  struct SlinkRplDef *replydef;

  assert(lserver != NULL);
    
  reply = &lserver->slinkrpl;

  if (IsDefunct(server))
    return;

  if (!reply->command)
  {
    reply->gotdatalen = 0;
    reply->readdata = 0;
    reply->data = NULL;

    length = recv(fd->fd, tmp, 1, 0);

    if (length <= 0)
    {
      if ((length == -1) && ignoreErrno(errno))
        goto nodata;
      dead_link_on_read(server, length);
      return;
    }
    reply->command = tmp[0];
  }

  for (replydef = slinkrpltab; replydef->handler; replydef++)
  {
    if (replydef->replyid == (unsigned int)reply->command)
      break;
  }

  /* we should be able to trust a local slink process...
   * and if it sends an invalid command, that's a bug.. */
  assert(replydef->handler);

  if ((replydef->flags & SLINKRPL_FLAG_DATA) && (reply->gotdatalen < 2))
  {
    /* we need a datalen u16 which we don't have yet... */
    length = recv(fd->fd, len, (2 - reply->gotdatalen), 0);
    if (length <= 0)
    {
      if ((length == -1) && ignoreErrno(errno))
        goto nodata;
      dead_link_on_read(server, length);
      return;
    }

    if (reply->gotdatalen == 0)
    {
      reply->datalen = *len << 8;
      reply->gotdatalen++;
      length--;
      len++;
    }
    if (length && (reply->gotdatalen == 1))
    {
      reply->datalen |= *len;
      reply->gotdatalen++;
      if (reply->datalen > 0)
        reply->data = MyMalloc(reply->datalen);
    }

    if (reply->gotdatalen < 2)
      return; /* wait for more data */
  }

  if (reply->readdata < reply->datalen) /* try to get any remaining data */
  {
    length = recv(fd->fd, (reply->data + reply->readdata),
                  (reply->datalen - reply->readdata), 0);
    if (length <= 0)
    {
      if ((length == -1) && ignoreErrno(errno))
        goto nodata;
      dead_link_on_read(server, length);
      return;
    }

    reply->readdata += length;
    if (reply->readdata < reply->datalen)
      return; /* wait for more data */
  }

  execute_callback(iorecvctrl_cb, server, reply->command);

  /* we now have the command and any data, pass it off to the handler */
  (*replydef->handler)(reply->command, reply->datalen, reply->data, server);

  /* reset SlinkRpl */                      
  if (reply->datalen > 0)
    MyFree(reply->data);
  reply->command = 0;

  if (IsDead(server))
    return;

nodata:
  /* If we get here, we need to register for another COMM_SELECT_READ */
  comm_setselect(fd, COMM_SELECT_READ, read_ctrl_packet, server, 0);
}

/*
 * iorecv_default - append a packet to the recvq dbuf
 */
void *
iorecv_default(va_list args)
{
  struct Client *client_p = va_arg(args, struct Client *);
  int length = va_arg(args, int);
  char *buf = va_arg(args, char *);

  dbuf_put(&client_p->localClient->buf_recvq, buf, length);
  return NULL;
}

/*
 * read_packet - Read a 'packet' of data from a connection and process it.
 */
void
read_packet(fde_t *fd, void *data)
{
  struct Client *client_p = data;
  int length = 0;

  if (IsDefunct(client_p))
    return;

  /*
   * Read some data. We *used to* do anti-flood protection here, but
   * I personally think it makes the code too hairy to make sane.
   *     -- adrian
   */
  do {
#ifdef HAVE_LIBCRYPTO
    if (fd->ssl)
    {
      length = SSL_read(fd->ssl, readBuf, READBUF_SIZE);

      /* translate openssl error codes, sigh */
      if (length < 0)
        switch (SSL_get_error(fd->ssl, length))
	{
          case SSL_ERROR_WANT_WRITE:
            fd->flags.pending_read = 1;
	    SetSendqBlocked(client_p);
	    comm_setselect(fd, COMM_SELECT_WRITE, (PF *) sendq_unblocked,
	                   client_p, 0);
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
      length = recv(fd->fd, readBuf, READBUF_SIZE, 0);
    }

    if (length <= 0)
    {
      /*
       * If true, then we can recover from this error.  Just jump out of
       * the loop and re-register a new io-request.
       */
      if (length < 0 && ignoreErrno(errno))
        break;

      dead_link_on_read(client_p, length);
      return;
    }

    execute_callback(iorecv_cb, client_p, length, readBuf);

    if (client_p->lasttime < CurrentTime)
      client_p->lasttime = CurrentTime;
    if (client_p->lasttime > client_p->since)
      client_p->since = CurrentTime;
    ClearPingSent(client_p);

    /* Attempt to parse what we have */
    parse_client_queued(client_p);

    if (IsDefunct(client_p))
      return;

    /* Check to make sure we're not flooding */
    /* TBD - ConfigFileEntry.client_flood should be a size_t */
    if (!(IsServer(client_p) || IsHandshake(client_p) || IsConnecting(client_p))
        && (dbuf_length(&client_p->localClient->buf_recvq) >
            (unsigned int)ConfigFileEntry.client_flood))
    {
      if (!(ConfigFileEntry.no_oper_flood && IsOper(client_p)))
      {
        exit_client(client_p, client_p, "Excess Flood");
        return;
      }
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

/*
 * client_dopacket - copy packet to client buf and parse it
 *      client_p - pointer to client structure for which the buffer data
 *             applies.
 *      buffer - pointr to the buffer containing the newly read data
 *      length - number of valid bytes of data in the buffer
 *
 * Note:
 *      It is implicitly assumed that dopacket is called only
 *      with client_p of "local" variation, which contains all the
 *      necessary fields (buffer etc..)
 */
static void
client_dopacket(struct Client *client_p, char *buffer, size_t length)
{
  /* 
   * Update messages received
   */
  ++me.localClient->recv.messages;
  ++client_p->localClient->recv.messages;

  /* 
   * Update bytes received
   */
  client_p->localClient->recv.bytes += length;
  me.localClient->recv.bytes += length;

  parse(client_p, buffer, buffer + length);
}
