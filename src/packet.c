/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include "io_poll.h"
#include "io_time.h"

#include "client.h"
#include "client_input.h"
#include "packet.h"
#include "parse.h"
#include "send.h"

enum { READBUF_SIZE = 16384 };

static void
read_packet_ready(int fd, void *context)
{
  struct Client *const client = context;
  assert(client->connection->fde && client->connection->fde->fd == fd);
  (void)fd;
  read_packet(client);
}

void
read_packet(struct Client *client)
{
  ssize_t length = 0;
  char raw_receive_buffer[READBUF_SIZE];

  assert(client);
  assert(client->connection);

  if (client_is_defunct(client))
    return;

  fde_t *const fde = client->connection->fde;
  assert(fde);
  const int fd = fde->fd;

  while (true)
  {
    if (tls_session_is_active(&fde->tls))
    {
      bool want_write = false;
      length = tls_session_read(&fde->tls, raw_receive_buffer, sizeof(raw_receive_buffer), &want_write);

      if (want_write)
        io_poll_watch_write(comm_get_poller(), fd, send_write_ready, client);
    }
    else
      length = recv(fd, raw_receive_buffer, sizeof(raw_receive_buffer), 0);

    if (length <= 0)
    {
      const int error_code = length < 0 ? errno : 0;
      if (length < 0 && comm_errno_is_recoverable(error_code))
        io_poll_watch_read(comm_get_poller(), fd, read_packet_ready, client);
      else
        client_schedule_exit_on_io_failure(client, CLIENT_IO_OPERATION_READ,
                                           length == 0 ? CLIENT_IO_FAILURE_PEER_CLOSED
                                                       : CLIENT_IO_FAILURE_ERROR, error_code);
      return;
    }

    dbuf_queue_append(&client->connection->recv_queue, raw_receive_buffer, length);

    client->connection->last_receive_time = io_time_get(IO_TIME_MONOTONIC_SEC);
    client->connection->ping_sent_time = 0;
    client_update_activity_timeout(client);

    client_input_process_recvq(client);

    if (client_is_defunct(client))
      return;

    const unsigned int max_recvq = client_get_max_recvq(client);
    const size_t current_recvq = dbuf_queue_length(&client->connection->recv_queue);
    if (current_recvq > max_recvq)
    {
      client_exit_fmt(client, "Max RecvQ exceeded (%zu > %u)", current_recvq, max_recvq);
      return;
    }
  }
}
