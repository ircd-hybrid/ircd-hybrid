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
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "io_socket.h"
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
  assert(client->connection->socket && io_socket_fd(client->connection->socket) == fd);
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

  struct io_socket *const socket = client->connection->socket;
  assert(socket);
  const int fd = io_socket_fd(socket);

  while (true)
  {
    bool want_write = false;
    if (io_socket_tls_is_active(socket))
      length = io_socket_tls_read(socket, raw_receive_buffer, sizeof(raw_receive_buffer), &want_write);
    else
      length = recv(fd, raw_receive_buffer, sizeof(raw_receive_buffer), 0);

    const int error_code = length < 0 ? errno : 0;
    if (want_write && io_socket_watch_write(socket, send_write_ready, client) == -1)
    {
      client_schedule_exit_fmt(client, "Write watch registration failed: %s", strerror(errno));
      return;
    }

    if (length <= 0)
    {
      if (length < 0 && io_socket_errno_is_transient(error_code))
      {
        if (io_socket_watch_read(socket, read_packet_ready, client) == -1)
          client_schedule_exit_fmt(client, "Read watch registration failed: %s", strerror(errno));
      }
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
