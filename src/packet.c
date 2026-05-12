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

/*! \file packet.c
 * \brief Packet handlers.
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "comm.h"
#include "fdlist.h"
#include "io_time.h"

#include "client.h"
#include "client_input.h"
#include "packet.h"
#include "parse.h"
#include "send.h"

enum { READBUF_SIZE = 16384 };

/*
 * read_packet - Read a 'packet' of data from a connection and process it.
 */
void
read_packet(fde_t *F, void *data_)
{
  struct Client *const client = data_;
  ssize_t length = 0;
  char raw_receive_buffer[READBUF_SIZE];

  assert(client);
  assert(client->connection);

  if (client_is_defunct(client))
    return;

  assert(client->connection->fd);
  assert(client->connection->fd == F);

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
      length = tls_read(&F->tls, raw_receive_buffer, sizeof(raw_receive_buffer), &want_write);

      if (want_write)
        comm_setselect(F, COMM_SELECT_WRITE, sendq_unblocked, client);
    }
    else
      length = recv(F->fd, raw_receive_buffer, sizeof(raw_receive_buffer), 0);

    if (length <= 0)
    {
      /*
       * If true, then we can recover from this error. Stop here and register for
       * another COMM_SELECT_READ io-request.
       */
      const int error_code = length < 0 ? errno : 0;
      if (length < 0 && comm_errno_is_recoverable(error_code))
        comm_setselect(F, COMM_SELECT_READ, read_packet, client);
      else
        client_schedule_exit_on_io_failure(client, CLIENT_IO_OPERATION_READ,
                                           length == 0 ? CLIENT_IO_FAILURE_PEER_CLOSED
                                                       : CLIENT_IO_FAILURE_ERROR, error_code);
      return;
    }

    dbuf_put(&client->connection->buf_recvq, raw_receive_buffer, length);

    client->connection->last_receive_time = io_time_get(IO_TIME_MONOTONIC_SEC);
    client->connection->ping_sent_time = 0;
    client_reset_activity_timeout(client);

    /* Attempt to parse what we have */
    client_input_process_recvq(client);

    if (client_is_defunct(client))
      return;

    /* Check to make sure we're not flooding */
    const unsigned int max_recvq = client_get_max_recvq(client);
    const size_t current_recvq = dbuf_length(&client->connection->buf_recvq);
    if (current_recvq > max_recvq)
    {
      client_exit_fmt(client, "Max RecvQ exceeded (%zu > %u)", current_recvq, max_recvq);
      return;
    }
  }
}
