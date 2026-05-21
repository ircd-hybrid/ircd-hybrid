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

/*! \file send.c
 * \brief Functions for sending messages.
 */

#include <assert.h>
#include <errno.h>

#include "address.h"
#include "comm.h"
#include "dbuf.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"

#include "cap.h"
#include "channel.h"
#include "client.h"
#include "conf.h"
#include "conf_class.h"
#include "send.h"
#include "server_capab.h"
#include "user_mode.h"

/**
 * @var broadcast_id
 * @brief A unique, incrementing ID for a single broadcast operation.
 *
 * This is used with the Connection::last_broadcast_id field to de-duplicate
 * message delivery to a single nexthop during a broadcast that may traverse
 * multiple paths (e.g., a message to a channel).
 */
static uintmax_t broadcast_id;

/* send_format()
 *
 * inputs
 *		- buffer
 *		- format format to use
 *		- var args
 * output	- number of bytes formatted output
 * side effects	- modifies sendbuf
 */
static void
send_format(struct dbuf_block *buffer, const char *format, va_list args)
{
  /*
   * from rfc1459
   *
   * IRC messages are always lines of characters terminated with a CR-LF
   * (Carriage Return - Line Feed) pair, and these messages shall not
   * exceed 512 characters in length,  counting all characters
   * including the trailing CR-LF.
   * Thus, there are 510 characters maximum allowed
   * for the command and its parameters.  There is no provision for
   * continuation message lines.  See section 7 for more details about
   * current implementations.
   */
  dbuf_put_args(buffer, format, args);

  if (buffer->size > IRCD_BUFSIZE - 2)
    buffer->size = IRCD_BUFSIZE - 2;

  buffer->data[buffer->size++] = '\r';
  buffer->data[buffer->size++] = '\n';
}

/*
 ** send_message
 **      Internal utility which appends given buffer to the sockets
 **      sendq.
 */
static void
sendto_one_buffer(struct Client *to, struct dbuf_block *buffer)
{
  assert(to && client_is_local(to));
  assert(!client_is_me(to));

  if (client_is_dead(to))
    return;

  const unsigned int max_sendq = client_get_max_sendq(to);
  const size_t new_sendq_size = dbuf_length(&to->connection->buf_sendq) + buffer->size;
  if (new_sendq_size > max_sendq)
  {
    if (!client_has_flag(to, FLAGS_SENDQEX))
    {
      client_set_flag(to, FLAGS_SENDQEX);

      if (client_is_server(to))
        sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                       "Max SendQ limit exceeded for %s: %zu > %u",
                       client_get_name(to, HIDE_IP), new_sendq_size, max_sendq);

      client_schedule_exit_fmt(to, "Max SendQ exceeded (%zu > %u)",
                               new_sendq_size, max_sendq);
    }

    return;
  }

  dbuf_add(&to->connection->buf_sendq, buffer);

  /*
   * Update statistics. The following is slightly incorrect because
   * it counts messages even if queued, but bytes only really sent.
   * Queued bytes get updated in send_queued_write().
   */
  ++to->connection->send.messages;
  ++me.connection->send.messages;

  send_queued_write(to);
}

/* send_message_remote()
 *
 * inputs	- pointer to client from message is being sent
 * 		- pointer to client to send to
 *		- pointer to buffer
 * output	- none
 * side effects	- Despite the function name, this only sends to directly
 *		  connected clients.
 *
 */
static void
sendto_one_buffer_remote(struct Client *to, const struct Client *from, struct dbuf_block *buffer)
{
  assert(to && client_is_local(to));
  assert(!client_is_me(to));
  assert(client_is_server(to));
  assert(to->nexthop == to);

  if (client_is_dead(to))
    return;

  if (to == from->nexthop)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Send message to %s dropped from %s (Fake Dir)",
                   to->name, from->name);
  else
    sendto_one_buffer(to, buffer);
}

/*
 ** sendq_unblocked
 **      Called when a socket is ready for writing.
 */
void
sendq_unblocked(fde_t *F, void *data)
{
  struct Client *const client = data;

  assert(F);
  assert(client);
  assert(client->connection);

  if (client_is_dead(client))
    return;

  assert(client->connection->fd);
  assert(client->connection->fd == F);
  assert(client_has_flag(client, FLAGS_BLOCKED));

  client_unset_flag(client, FLAGS_BLOCKED);
  send_queued_write(client);
}

/*
 ** send_queued_write
 **      This is called when there is a chance that some output would
 **      be possible. This attempts to empty the send queue as far as
 **      possible, and then if any data is left, a write is rescheduled.
 */
void
send_queued_write(struct Client *to)
{
  assert(to && client_is_local(to));

  /*
   * Once socket is marked dead, we cannot start writing to it,
   * even if the error is removed...
   */
  if (client_is_dead(to) || client_has_flag(to, FLAGS_BLOCKED))
    return;  /* no use calling send() now */

  /* Next, lets try to write some data */
  while (dbuf_length(&to->connection->buf_sendq))
  {
    ssize_t retlen;
    bool want_read = false;
    const struct dbuf_block *first = to->connection->buf_sendq.blocks.head->data;

    if (tls_isusing(&to->connection->fd->tls))
    {
      retlen = tls_write(&to->connection->fd->tls, first->data + to->connection->buf_sendq.pos,
                                                   first->size - to->connection->buf_sendq.pos, &want_read);

      if (want_read)
        return;  /* Retry later, don't register for write events */
    }
    else
      retlen = send(to->connection->fd->fd, first->data + to->connection->buf_sendq.pos,
                                            first->size - to->connection->buf_sendq.pos, 0);

    if (retlen <= 0)
    {
      const int error_code = retlen < 0 ? errno : 0;
      if (retlen < 0 && comm_errno_is_recoverable(error_code))
      {
        client_set_flag(to, FLAGS_BLOCKED);
        /* We have a non-fatal error, reschedule a write */
        comm_setselect(to->connection->fd, COMM_SELECT_WRITE, sendq_unblocked, to);
      }
      else
      {
        client_schedule_exit_on_io_failure(to, CLIENT_IO_OPERATION_WRITE,
                                           retlen == 0 ? CLIENT_IO_FAILURE_PEER_CLOSED
                                                       : CLIENT_IO_FAILURE_ERROR, error_code);
      }

      return;
    }

    dbuf_delete(&to->connection->buf_sendq, retlen);

    /* We have some data written .. update counters */
    to->connection->send.bytes += retlen;
    me.connection->send.bytes += retlen;
  }
}

static void
_sendto_one_stdreply(struct Client *to, const struct Client *from, const char *type,
                     const char *command, const char *code,
                     const char *context[], size_t context_len,
                     const char *format, va_list args)
{
  assert(to);
  assert(from);
  assert(type);
  assert(command);
  assert(code);
  assert(format);
  assert((context_len > 0) == (context != NULL));

  if (client_is_dead(to->nexthop))
    return;

  if (!client_has_cap(to, CAP_STANDARD_REPLIES))
    return;

  struct dbuf_block *buffer = dbuf_alloc();
  dbuf_put_fmt(buffer, ":%s %s %s %s",
               client_get_id_or_name(from, to), type, command, code);

  for (size_t i = 0; i < context_len; ++i)
  {
    assert(context[i] != NULL && strchr(context[i], ' ') == NULL);
    dbuf_put_fmt(buffer, " %s", context[i]);
  }

  dbuf_put_fmt(buffer, " :");
  send_format(buffer, format, args);

  sendto_one_buffer(to->nexthop, buffer);
  dbuf_ref_free(buffer);
}

void
sendto_one_fail(struct Client *to, const struct Client *from, const char *command, const char *code,
                const char *context[], size_t context_len, const char *format, ...)
{
  va_list args;
  va_start(args, format);
  _sendto_one_stdreply(to, from, "FAIL", command, code, context, context_len, format, args);
  va_end(args);
}

void
sendto_one_warn(struct Client *to, const struct Client *from, const char *command, const char *code,
                const char *context[], size_t context_len, const char *format, ...)
{
  va_list args;
  va_start(args, format);
  _sendto_one_stdreply(to, from, "WARN", command, code, context, context_len, format, args);
  va_end(args);
}

void
sendto_one_note(struct Client *to, const struct Client *from, const char *command, const char *code,
                const char *context[], size_t context_len, const char *format, ...)
{
  va_list args;
  va_start(args, format);
  _sendto_one_stdreply(to, from, "NOTE", command, code, context, context_len, format, args);
  va_end(args);
}

/* sendto_one()
 *
 * inputs	- pointer to destination client
 *		- var args message
 * output	- NONE
 * side effects	- send message to single client
 */
void
sendto_one(struct Client *to, const char *format, ...)
{
  if (client_is_dead(to->nexthop))
    return;  /* This socket has already been marked as dead */

  struct dbuf_block *buffer = dbuf_alloc();

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  sendto_one_buffer(to->nexthop, buffer);

  dbuf_ref_free(buffer);
}

void
sendto_one_numeric(struct Client *to, const struct Client *from, enum irc_numerics numeric, ...)
{
  if (client_is_dead(to->nexthop))
    return;  /* This socket has already been marked as dead */

  const char *dest = client_get_id_or_name(to, to);
  if (string_is_empty(dest))
    dest = "*";

  struct dbuf_block *buffer = dbuf_alloc();
  dbuf_put_fmt(buffer, ":%s %03d %s ", client_get_id_or_name(from, to), numeric & ~SND_EXPLICIT, dest);

  va_list args;
  va_start(args, numeric);

  const char *numstr;
  if (numeric & SND_EXPLICIT)
    numstr = va_arg(args, const char *);
  else
    numstr = numeric_form(numeric);

  send_format(buffer, numstr, args);
  va_end(args);

  sendto_one_buffer(to->nexthop, buffer);

  dbuf_ref_free(buffer);
}

void
sendto_one_notice(struct Client *to, const struct Client *from, const char *format, ...)
{
  if (client_is_dead(to->nexthop))
    return;  /* This socket has already been marked as dead */

  const char *dest = client_get_id_or_name(to, to);
  if (string_is_empty(dest))
    dest = "*";

  struct dbuf_block *buffer = dbuf_alloc();
  dbuf_put_fmt(buffer, ":%s NOTICE %s ", client_get_id_or_name(from, to), dest);

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  sendto_one_buffer(to->nexthop, buffer);

  dbuf_ref_free(buffer);
}

/* sendto_anywhere()
 *
 * inputs	- pointer to dest client
 * 		- pointer to from client
 * 		- varags
 * output	- NONE
 * side effects	- less efficient than sendto_remote and sendto_one
 * 		  but useful when one does not know where target "lives"
 */
void
sendto_one_anywhere(struct Client *to, const struct Client *from, const char *command, const char *format, ...)
{
  if (client_is_dead(to->nexthop))
    return;

  struct dbuf_block *buffer = dbuf_alloc();
  if (client_is_local_user(to) && client_is_user(from))
    dbuf_put_fmt(buffer, ":%s!%s@%s %s %s ",
                 from->name, from->username, from->host, command, to->name);
  else
    dbuf_put_fmt(buffer, ":%s %s %s ",
                 client_get_id_or_name(from, to), command, client_get_id_or_name(to, to));

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  if (client_is_local(to))
    sendto_one_buffer(to, buffer);
  else
    sendto_one_buffer_remote(to->nexthop, from, buffer);

  dbuf_ref_free(buffer);
}

static bool
sendto_clients_qualifies(const struct Client *client, uint64_t flags, send_recipient_t recipient)
{
  if (flags && !user_mode_has_flag(client, flags))
    return false;

  switch (recipient)
  {
    case SEND_RECIPIENT_ADMIN:
      return client_is_admin(client);
    case SEND_RECIPIENT_OPER:
      return client_is_oper(client) && !client_is_admin(client);
    case SEND_RECIPIENT_OPER_ALL:
      return client_is_oper(client);
    case SEND_RECIPIENT_CLIENT:
      return true;
    default:
      return false;
  }
}

/* sendto_clients()
 *
 * inputs	- flag types of messages to show to real opers
 *		- flag indicating opers/admins
 *		- var args input message
 * output	- NONE
 * side effects	- Send to *local* ops only but NOT +s nonopers.
 */
void
sendto_clients(uint64_t flags, send_recipient_t recipient, send_type_t type, const char *format, ...)
{
  const char *ntype = "???";

  switch (type)
  {
    case SEND_TYPE_NOTICE:
      ntype = "Notice";
      break;
    case SEND_TYPE_GLOBAL:
      ntype = "Global";
      break;
    case SEND_TYPE_LOCOPS:
      ntype = "LocOps";
      break;
    default:
      assert(0);
  }

  struct dbuf_block *buffer = dbuf_alloc();
  dbuf_put_fmt(buffer, ":%s NOTICE * :*** %s -- ", me.name, ntype);

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  list_t *list = (recipient == SEND_RECIPIENT_CLIENT) ? &local_client_list : &oper_list;
  list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    struct Client *client = node->data;
    if (client_is_dead(client))
      continue;

    if (!sendto_clients_qualifies(client, flags, recipient))
      continue;

    sendto_one_buffer(client, buffer);
  }

  dbuf_ref_free(buffer);
}

/* ts_warn()
 *
 * inputs       - var args message
 * output       - NONE
 * side effects - Call sendto_clients, with some flood checking
 *                (at most 5 warnings every 5 seconds)
 */
void
sendto_clients_ratelimited(uintmax_t *rate, const char *format, ...)
{
  if ((io_time_get(IO_TIME_MONOTONIC_SEC) - *rate) < 20)
    return;

  *rate = io_time_get(IO_TIME_MONOTONIC_SEC);

  char buffer[IRCD_BUFSIZE];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s", buffer);
  log_write(LOG_TYPE_IRCD, "%s", buffer);
}

void
sendto_filtered_butone(const struct Client *exclude_client, const struct Client *source,
                       send_filter_fn filter_fn, void *filter_ctx, const char *format, ...)
{
  assert(source);
  assert(filter_fn);

  struct dbuf_block *buffer_local = dbuf_alloc();
  struct dbuf_block *buffer_remote = dbuf_alloc();

  if (client_is_user(source))
    dbuf_put_fmt(buffer_local, ":%s!%s@%s ", source->name, source->username, source->host);
  else
    dbuf_put_fmt(buffer_local, ":%s ", source->name);

  dbuf_put_fmt(buffer_remote, ":%s ", source->id);

  va_list args;
  va_start(args, format);
  va_list args_copy;
  va_copy(args_copy, args);

  send_format(buffer_local, format, args);
  send_format(buffer_remote, format, args_copy);

  va_end(args_copy);
  va_end(args);

  list_node_t *node;
  LIST_FOREACH(node, local_client_list.head)
  {
    struct Client *target = node->data;
    if (client_is_dead(target))
      continue;

    if (filter_fn(target, filter_ctx))
      sendto_one_buffer(target, buffer_local);
  }

  LIST_FOREACH(node, local_server_list.head)
  {
    struct Client *target = node->data;
    if (client_is_dead(target))
      continue;

    if (target == exclude_client)
      continue;

    sendto_one_buffer_remote(target, source, buffer_remote);
  }

  dbuf_ref_free(buffer_local);
  dbuf_ref_free(buffer_remote);
}

/* sendto_servers()
 *
 * inputs       - pointer to client to NOT send to
 *              - pointer to channel
 *              - capabs or'd together which must ALL be present
 *              - capabs or'd together which must ALL NOT be present
 *              - printf style format string
 *              - args to format string
 * output       - NONE
 * side effects - Send a message to all connected servers, except the
 *                client 'one' (if non-NULL), as long as the servers
 *                support ALL capabs in 'capab', and NO capabs in 'nocapab'.
 *
 * This function was written in an attempt to merge together the other
 * billion sendto_*serv*() functions, which sprung up with capabs,
 * lazylinks, uids, etc.
 * -davidt
 */
void
sendto_servers(const struct Client *exclude_client, uint32_t required_capab,
               uint32_t excluded_capab, const char *format, ...)
{
  struct dbuf_block *buffer = dbuf_alloc();

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  list_node_t *node;
  LIST_FOREACH(node, local_server_list.head)
  {
    struct Client *client = node->data;

    /* If dead already skip */
    if (client_is_dead(client))
      continue;

    /* check against 'one' */
    if (exclude_client && (client == exclude_client->nexthop))
      continue;

    /* check we have required capabs */
    if (capab_has_flag(client, required_capab) != required_capab)
      continue;

    /* check we don't have any forbidden capabs */
    if (capab_has_flag(client, excluded_capab))
      continue;

    sendto_one_buffer(client, buffer);
  }

  dbuf_ref_free(buffer);
}

/* sendto_match_servs()
 *
 * inputs       - source client
 *              - mask to send to
 *              - capab needed
 *              - data
 * outputs	- none
 * side effects	- data sent to servers matching with capab
 */
void
sendto_match_servs(const struct Client *source, const char *mask, uint32_t required_capab, const char *format, ...)
{
  struct dbuf_block *buffer = dbuf_alloc();

  dbuf_put_fmt(buffer, ":%s ", source->id);

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  ++broadcast_id;

  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    struct Client *target = node->data;

    if (client_is_dead(target->nexthop))
      continue;

    /* Do not attempt to send to ourselves ... */
    if (client_is_me(target))
      continue;

    /* ... or the source */
    if (target->nexthop == source->nexthop)
      continue;

    if (target->nexthop->connection->last_broadcast_id == broadcast_id)
      continue;

    if (capab_has_flag(target->nexthop, required_capab) != required_capab)
      continue;

    if (match(mask, target->name))
      continue;

    target->nexthop->connection->last_broadcast_id = broadcast_id;
    sendto_one_buffer_remote(target->nexthop, source, buffer);
  }

  dbuf_ref_free(buffer);
}

/* sendto_common_channels_local()
 *
 * inputs	- pointer to client
 *		- format to send
 * output	- NONE
 * side effects	- Sends a message to all people on local server who are
 * 		  in same channel with user.
 *		  used by m_nick.c and exit_one_client.
 */
void
sendto_common_channels_local(struct Client *user, bool touser, uint32_t required_cap,
                             uint32_t excluded_cap, const char *format, ...)
{
  struct dbuf_block *buffer = dbuf_alloc();

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  ++broadcast_id;

  list_node_t *node, *node2;
  LIST_FOREACH(node, user->channel_list.head)
  {
    const struct ChannelMember *member = node->data;
    const struct Channel *channel = member->channel;

    LIST_FOREACH(node2, channel->members_local.head)
    {
      const struct ChannelMember *member2 = node2->data;
      struct Client *target = member2->client;

      if (client_is_dead(target))
        continue;

      if (target == user)
        continue;

      if (target->connection->last_broadcast_id == broadcast_id)
        continue;

      if (required_cap && (target->connection->cap & required_cap) != required_cap)
        continue;

      if (excluded_cap && (target->connection->cap & excluded_cap))
        continue;

      target->connection->last_broadcast_id = broadcast_id;
      sendto_one_buffer(target, buffer);
    }
  }

  if (touser && client_is_local(user) && !client_is_dead(user))
  {
    if ((required_cap == 0 || (user->connection->cap & required_cap) == required_cap) &&
        (excluded_cap == 0 || (user->connection->cap & excluded_cap) == 0))
      sendto_one_buffer(user, buffer);
  }

  dbuf_ref_free(buffer);
}

/*! \brief Send a message to members of a channel that are locally connected to this server.
 * \param one      Client to skip; can be NULL
 * \param channel    Destination channel
 * \param rank     Minimum channel member rank clients must have
 * \param poscap   Positive client capabilities flags (CAP)
 * \param negcap   Negative client capabilities flags (CAP)
 * \param format  Format string for command arguments
 */
void
sendto_channel_local(const struct Client *exclude_client, const struct Channel *channel, int required_rank,
                     uint32_t required_cap, uint32_t excluded_cap, const char *format, ...)
{
  struct dbuf_block *buffer = dbuf_alloc();

  va_list args;
  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  list_node_t *node;
  LIST_FOREACH(node, channel->members_local.head)
  {
    const struct ChannelMember *member = node->data;
    struct Client *target = member->client;

    if (client_is_dead(target))
      continue;

    if (exclude_client && (target == exclude_client->nexthop))
      continue;

    if (required_rank && member_highest_rank(member) < required_rank)
      continue;

    if (required_cap && (target->connection->cap & required_cap) != required_cap)
      continue;

    if (excluded_cap && (target->connection->cap & excluded_cap))
      continue;

    sendto_one_buffer(target, buffer);
  }

  dbuf_ref_free(buffer);
}

/* sendto_channel_butone()
 *
 * inputs	- pointer to client(server) to NOT send message to
 *		- pointer to client that is sending this message
 *		- pointer to channel being sent to
 *		- vargs message
 * output	- NONE
 * side effects	- message as given is sent to given channel members.
 *
 * WARNING - +D clients are ignored
 */
void
sendto_channel_butone(const struct Client *exclude_client, const struct Client *from, const struct Channel *channel,
                      int required_rank, const char *format, ...)
{
  struct dbuf_block *buffer_local = dbuf_alloc();
  struct dbuf_block *buffer_remote = dbuf_alloc();

  if (client_is_user(from))
    dbuf_put_fmt(buffer_local, ":%s!%s@%s ", from->name, from->username, from->host);
  else
    dbuf_put_fmt(buffer_local, ":%s ", from->name);

  dbuf_put_fmt(buffer_remote, ":%s ", from->id);

  va_list args;
  va_start(args, format);
  va_list args_copy;
  va_copy(args_copy, args);

  send_format(buffer_local, format, args);
  send_format(buffer_remote, format, args_copy);

  va_end(args_copy);
  va_end(args);

  ++broadcast_id;

  list_node_t *node;
  LIST_FOREACH(node, channel->members.head)
  {
    const struct ChannelMember *member = node->data;
    struct Client *target = member->client;

    assert(client_is_user(target));

    if (client_is_dead(target->nexthop))
      continue;

    if (exclude_client && (target->nexthop == exclude_client->nexthop))
      continue;

    if (required_rank && member_highest_rank(member) < required_rank)
      continue;

    if (user_mode_has_flag(target, UMODE_DEAF))
      continue;

    if (client_is_local(target))
      sendto_one_buffer(target, buffer_local);
    else if (target->nexthop->connection->last_broadcast_id != broadcast_id)
      sendto_one_buffer_remote(target->nexthop, from, buffer_remote);

    target->nexthop->connection->last_broadcast_id = broadcast_id;
  }

  dbuf_ref_free(buffer_local);
  dbuf_ref_free(buffer_remote);
}
