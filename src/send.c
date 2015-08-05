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

/*! \file send.c
 * \brief Functions for sending messages.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "send.h"
#include "channel.h"
#include "client.h"
#include "dbuf.h"
#include "irc_string.h"
#include "ircd.h"
#include "s_bsd.h"
#include "server.h"
#include "conf_class.h"
#include "log.h"


static uint64_t current_serial;


/* send_format()
 *
 * inputs
 *		- buffer
 *		- format pattern to use
 *		- var args
 * output	- number of bytes formatted output
 * side effects	- modifies sendbuf
 */
static void
send_format(struct dbuf_block *buffer, const char *pattern, va_list args)
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
  dbuf_put_args(buffer, pattern, args);

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
send_message(struct Client *to, struct dbuf_block *buf)
{
  assert(!IsMe(to));
  assert(to != &me);
  assert(MyConnect(to));

  if (dbuf_length(&to->connection->buf_sendq) + buf->size > get_sendq(&to->connection->confs))
  {
    if (IsServer(to))
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "Max SendQ limit exceeded for %s: %lu > %u",
                           get_client_name(to, HIDE_IP),
                           (unsigned long)(dbuf_length(&to->connection->buf_sendq) + buf->size),
                           get_sendq(&to->connection->confs));

    if (IsClient(to))
      AddFlag(to, FLAGS_SENDQEX);

    dead_link_on_write(to, 0);
    return;
  }

  dbuf_add(&to->connection->buf_sendq, buf);

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
send_message_remote(struct Client *to, struct Client *from, struct dbuf_block *buf)
{
  assert(MyConnect(to));
  assert(IsServer(to));
  assert(!IsMe(to));
  assert(to->from == to);

  if (to == from->from)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Send message to %s dropped from %s (Fake Dir)",
                         to->name, from->name);
    return;
  }

  send_message(to, buf);
}

/*
 ** sendq_unblocked
 **      Called when a socket is ready for writing.
 */
void
sendq_unblocked(fde_t *fd, void *data)
{
  struct Client *const client_p = data;
  assert(fd == &client_p->connection->fd);

  DelFlag(client_p, FLAGS_BLOCKED);
  send_queued_write(client_p);
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
  int retlen = 0;

  /*
   ** Once socket is marked dead, we cannot start writing to it,
   ** even if the error is removed...
   */
  if (IsDead(to) || HasFlag(to, FLAGS_BLOCKED))
    return;  /* no use calling send() now */

  /* Next, lets try to write some data */
  if (dbuf_length(&to->connection->buf_sendq))
  {
    do
    {
      struct dbuf_block *first = to->connection->buf_sendq.blocks.head->data;

#ifdef HAVE_LIBCRYPTO
      if (to->connection->fd.ssl)
      {
        retlen = SSL_write(to->connection->fd.ssl, first->data + to->connection->buf_sendq.pos, first->size - to->connection->buf_sendq.pos);

        /* translate openssl error codes, sigh */
        if (retlen < 0)
        {
          switch (SSL_get_error(to->connection->fd.ssl, retlen))
          {
            case SSL_ERROR_WANT_READ:
              return;  /* retry later, don't register for write events */
            case SSL_ERROR_WANT_WRITE:
              errno = EWOULDBLOCK;
            case SSL_ERROR_SYSCALL:
              break;
            case SSL_ERROR_SSL:
              if (errno == EAGAIN)
                break;
            default:
              retlen = errno = 0;  /* either an SSL-specific error or EOF */
          }
        }
      }
      else
#endif
        retlen = send(to->connection->fd.fd, first->data + to->connection->buf_sendq.pos, first->size - to->connection->buf_sendq.pos, 0);

      if (retlen <= 0)
        break;

      dbuf_delete(&to->connection->buf_sendq, retlen);

      /* We have some data written .. update counters */
      to->connection->send.bytes += retlen;
      me.connection->send.bytes += retlen;
    } while (dbuf_length(&to->connection->buf_sendq));

    if (retlen < 0 && ignoreErrno(errno))
    {
      AddFlag(to, FLAGS_BLOCKED);

      /* we have a non-fatal error, reschedule a write */
      comm_setselect(&to->connection->fd, COMM_SELECT_WRITE,
                     sendq_unblocked, to, 0);
    }
    else if (retlen <= 0)
    {
      dead_link_on_write(to, errno);
      return;
    }
  }
}

/* send_queued_all()
 *
 * input        - NONE
 * output       - NONE
 * side effects - try to flush sendq of each client
 */
void
send_queued_all(void)
{
  dlink_node *node = NULL;

  /* Servers are processed first, mainly because this can generate
   * a notice to opers, which is to be delivered by this function.
   */
  DLINK_FOREACH(node, local_server_list.head)
    send_queued_write(node->data);

  DLINK_FOREACH(node, unknown_list.head)
    send_queued_write(node->data);

  DLINK_FOREACH(node, local_client_list.head)
    send_queued_write(node->data);

  /* NOTE: This can still put clients on aborted_list; unfortunately,
   * exit_aborted_clients takes precedence over send_queued_all,
   * because exiting clients can generate server/oper traffic.
   * The easiest approach is dealing with aborted clients in the next I/O lap.
   * -adx
   */
}

/* sendto_one()
 *
 * inputs	- pointer to destination client
 *		- var args message
 * output	- NONE
 * side effects	- send message to single client
 */
void
sendto_one(struct Client *to, const char *pattern, ...)
{
  va_list args;
  struct dbuf_block *buffer = NULL;

  if (IsDead(to->from))
    return;  /* This socket has already been marked as dead */

  buffer = dbuf_alloc();

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  send_message(to->from, buffer);

  dbuf_ref_free(buffer);
}

void
sendto_one_numeric(struct Client *to, struct Client *from, enum irc_numerics numeric, ...)
{
  struct dbuf_block *buffer = NULL;
  const char *dest = NULL, *numstr = NULL;
  va_list args;

  if (IsDead(to->from))
    return;

  dest = ID_or_name(to, to);

  if (EmptyString(dest))
    dest = "*";

  buffer = dbuf_alloc();

  dbuf_put_fmt(buffer, ":%s %03d %s ", ID_or_name(from, to), numeric & ~SND_EXPLICIT, dest);

  va_start(args, numeric);

  if (numeric & SND_EXPLICIT)
    numstr = va_arg(args, const char *);
  else
    numstr = numeric_form(numeric);

  send_format(buffer, numstr, args);
  va_end(args);

  send_message(to->from, buffer);

  dbuf_ref_free(buffer);
}

void
sendto_one_notice(struct Client *to, struct Client *from, const char *pattern, ...)
{
  struct dbuf_block *buffer = NULL;
  const char *dest = NULL;
  va_list args;

  if (IsDead(to->from))
    return;

  dest = ID_or_name(to, to);

  if (EmptyString(dest))
    dest = "*";

  buffer = dbuf_alloc();

  dbuf_put_fmt(buffer, ":%s NOTICE %s ", ID_or_name(from, to), dest);

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  send_message(to->from, buffer);

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
sendto_channel_butone(struct Client *one, struct Client *from,
                      struct Channel *chptr, unsigned int type,
                      const char *pattern, ...)
{
  va_list alocal, aremote;
  struct dbuf_block *local_buf, *remote_buf;
  dlink_node *node = NULL;

  local_buf = dbuf_alloc(), remote_buf = dbuf_alloc();

  if (IsClient(from))
    dbuf_put_fmt(local_buf, ":%s!%s@%s ", from->name, from->username, from->host);
  else
    dbuf_put_fmt(local_buf, ":%s ", from->name);

  dbuf_put_fmt(remote_buf, ":%s ", from->id);

  va_start(alocal, pattern);
  va_start(aremote, pattern);
  send_format(local_buf, pattern, alocal);
  send_format(remote_buf, pattern, aremote);

  va_end(aremote);
  va_end(alocal);

  ++current_serial;

  DLINK_FOREACH(node, chptr->members.head)
  {
    struct Membership *member = node->data;
    struct Client *target_p = member->client_p;

    assert(IsClient(target_p));

    if (IsDefunct(target_p) || HasUMode(target_p, UMODE_DEAF) ||
        (one && target_p->from == one->from))
      continue;

    if (type && (member->flags & type) == 0)
      continue;

    if (MyConnect(target_p))
      send_message(target_p, local_buf);
    else if (target_p->from->connection->serial != current_serial)
      send_message_remote(target_p->from, from, remote_buf);

    target_p->from->connection->serial = current_serial;
  }

  dbuf_ref_free(local_buf);
  dbuf_ref_free(remote_buf);
}

/* sendto_server()
 *
 * inputs       - pointer to client to NOT send to
 *              - pointer to channel
 *              - caps or'd together which must ALL be present
 *              - caps or'd together which must ALL NOT be present
 *              - printf style format string
 *              - args to format string
 * output       - NONE
 * side effects - Send a message to all connected servers, except the
 *                client 'one' (if non-NULL), as long as the servers
 *                support ALL capabs in 'caps', and NO capabs in 'nocaps'.
 *
 * This function was written in an attempt to merge together the other
 * billion sendto_*serv*() functions, which sprung up with capabs,
 * lazylinks, uids, etc.
 * -davidt
 */
void
sendto_server(struct Client *one,
              const unsigned int caps,
              const unsigned int nocaps,
              const char *format, ...)
{
  va_list args;
  dlink_node *node = NULL;
  struct dbuf_block *buffer = dbuf_alloc();

  va_start(args, format);
  send_format(buffer, format, args);
  va_end(args);

  DLINK_FOREACH(node, local_server_list.head)
  {
    struct Client *client_p = node->data;

    /* If dead already skip */
    if (IsDead(client_p))
      continue;

    /* check against 'one' */
    if (one && (client_p == one->from))
      continue;

    /* check we have required capabs */
    if ((client_p->connection->caps & caps) != caps)
      continue;

    /* check we don't have any forbidden capabs */
    if ((client_p->connection->caps & nocaps))
      continue;

    send_message(client_p, buffer);
  }

  dbuf_ref_free(buffer);
}

/* sendto_common_channels_local()
 *
 * inputs	- pointer to client
 *		- pattern to send
 * output	- NONE
 * side effects	- Sends a message to all people on local server who are
 * 		  in same channel with user.
 *		  used by m_nick.c and exit_one_client.
 */
void
sendto_common_channels_local(struct Client *user, int touser, unsigned int cap,
                             const char *pattern, ...)
{
  va_list args;
  dlink_node *uptr;
  dlink_node *cptr;
  struct Channel *chptr;
  struct Membership *member;
  struct Client *target_p;
  struct dbuf_block *buffer = dbuf_alloc();

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  ++current_serial;

  DLINK_FOREACH(cptr, user->channel.head)
  {
    chptr = ((struct Membership *)cptr->data)->chptr;

    DLINK_FOREACH(uptr, chptr->locmembers.head)
    {
      member = uptr->data;
      target_p = member->client_p;

      if (target_p == user || IsDefunct(target_p) ||
          target_p->connection->serial == current_serial)
        continue;

      if (HasCap(target_p, cap) != cap)
        continue;

      target_p->connection->serial = current_serial;
      send_message(target_p, buffer);
    }
  }

  if (touser && MyConnect(user) && !IsDead(user) &&
      user->connection->serial != current_serial)
    if (HasCap(user, cap) == cap)
      send_message(user, buffer);

  dbuf_ref_free(buffer);
}

/* sendto_channel_local()
 *
 * inputs	- member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  locally connected to this server.
 */
void
sendto_channel_local(unsigned int type, struct Channel *chptr,
                     const char *pattern, ...)
{
  va_list args;
  dlink_node *node = NULL;
  struct dbuf_block *buffer = dbuf_alloc();

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  DLINK_FOREACH(node, chptr->locmembers.head)
  {
    struct Membership *member = node->data;
    struct Client *target_p = member->client_p;

    if (type && (member->flags & type) == 0)
      continue;

    if (IsDefunct(target_p))
      continue;

    send_message(target_p, buffer);
  }

  dbuf_ref_free(buffer);
}

/* sendto_channel_local_butone()
 *
 * inputs       - pointer to client to NOT send message to
 *              - member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - pointer to channel to send to
 *              - var args pattern
 * output       - NONE
 * side effects - Send a message to all members of a channel that are
 *                locally connected to this server except one.
 *
 * WARNING - +D clients are omitted
 */
void
sendto_channel_local_butone(struct Client *one, unsigned int poscap, unsigned int negcap,
                            struct Channel *chptr, const char *pattern, ...)
{
  va_list args;
  dlink_node *node = NULL;
  struct dbuf_block *buffer = dbuf_alloc();

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  DLINK_FOREACH(node, chptr->locmembers.head)
  {
    struct Membership *member = node->data;
    struct Client *target_p = member->client_p;

    if (one && target_p == one->from)
      continue;

    if (IsDefunct(target_p))
      continue;

    if (poscap && HasCap(target_p, poscap) != poscap)
      continue;

    if (negcap && HasCap(target_p, negcap))
      continue;

    send_message(target_p, buffer);
  }

  dbuf_ref_free(buffer);
}

/*
 ** match_it() and sendto_match_butone() ARE only used
 ** to send a msg to all ppl on servers/hosts that match a specified mask
 ** (used for enhanced PRIVMSGs) for opers
 **
 ** addition -- Armin, 8jun90 (gruner@informatik.tu-muenchen.de)
 **
 */

/* match_it()
 *
 * inputs	- client pointer to match on
 *		- actual mask to match
 *		- what to match on, HOST or SERVER
 * output	- 1 or 0 if match or not
 * side effects	- NONE
 */
static int
match_it(const struct Client *one, const char *mask, unsigned int what)
{
  if (what == MATCH_HOST)
    return !match(mask, one->host);

  return !match(mask, one->servptr->name);
}

/* sendto_match_butone()
 *
 * Send to all clients which match the mask in a way defined on 'what';
 * either by user hostname or user servername.
 *
 * ugh. ONLY used by m_message.c to send an "oper magic" message. ugh.
 */
void
sendto_match_butone(struct Client *one, struct Client *from, const char *mask,
                    int what, const char *pattern, ...)
{
  va_list alocal, aremote;
  dlink_node *node = NULL;
  struct dbuf_block *local_buf, *remote_buf;

  local_buf = dbuf_alloc(), remote_buf = dbuf_alloc();

  dbuf_put_fmt(local_buf, ":%s!%s@%s ", from->name, from->username, from->host);
  dbuf_put_fmt(remote_buf, ":%s ", from->id);

  va_start(alocal, pattern);
  va_start(aremote, pattern);
  send_format(local_buf, pattern, alocal);
  send_format(remote_buf, pattern, aremote);
  va_end(aremote);
  va_end(alocal);

  /* scan the local clients */
  DLINK_FOREACH(node, local_client_list.head)
  {
    struct Client *client_p = node->data;

    if ((!one || client_p != one->from) && !IsDefunct(client_p) &&
        match_it(client_p, mask, what))
      send_message(client_p, local_buf);
  }

  /* Now scan servers */
  DLINK_FOREACH(node, local_server_list.head)
  {
    struct Client *client_p = node->data;

    /*
     * The old code looped through every client on the
     * network for each server to check if the
     * server (client_p) has at least 1 client matching
     * the mask, using something like:
     *
     * for (target_p = GlobalClientList; target_p; target_p = target_p->next)
     *        if (IsRegisteredUser(target_p) &&
     *                        match_it(target_p, mask, what) &&
     *                        (target_p->from == client_p))
     *   vsendto_prefix_one(client_p, from, pattern, args);
     *
     * That way, we wouldn't send the message to
     * a server who didn't have a matching client.
     * However, on a network such as EFNet, that
     * code would have looped through about 50
     * servers, and in each loop, loop through
     * about 50k clients as well, calling match()
     * in each nested loop. That is a very bad
     * thing cpu wise - just send the message
     * to every connected server and let that
     * server deal with it.
     * -wnder
     */
    if ((!one || client_p != one->from) && !IsDefunct(client_p))
      send_message_remote(client_p, from, remote_buf);
  }

  dbuf_ref_free(local_buf);
  dbuf_ref_free(remote_buf);
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
sendto_match_servs(struct Client *source_p, const char *mask, unsigned int cap,
                   const char *pattern, ...)
{
  va_list args;
  dlink_node *node = NULL;
  struct dbuf_block *buffer = dbuf_alloc();

  dbuf_put_fmt(buffer, ":%s ", source_p->id);
  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  ++current_serial;

  DLINK_FOREACH(node, global_server_list.head)
  {
    struct Client *target_p = node->data;

    /* Do not attempt to send to ourselves, or the source */
    if (IsMe(target_p) || target_p->from == source_p->from)
      continue;

    if (target_p->from->connection->serial == current_serial)
      continue;

    if (match(mask, target_p->name))
      continue;

    /*
     * If we set the serial here, then we'll never do a
     * match() again, if !IsCapable()
     */
    target_p->from->connection->serial = current_serial;

    if (!IsCapable(target_p->from, cap))
      continue;

    send_message_remote(target_p->from, source_p, buffer);
  }

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
sendto_anywhere(struct Client *to, struct Client *from,
                const char *command,
                const char *pattern, ...)
{
  va_list args;
  struct dbuf_block *buffer = NULL;

  if (IsDead(to->from))
    return;

  buffer = dbuf_alloc();

  if (MyClient(to) && IsClient(from))
    dbuf_put_fmt(buffer, ":%s!%s@%s %s %s ", from->name, from->username,
                 from->host, command, to->name);
  else
    dbuf_put_fmt(buffer, ":%s %s %s ", ID_or_name(from, to),
                 command, ID_or_name(to, to));

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  if (MyConnect(to))
    send_message(to, buffer);
  else
    send_message_remote(to->from, from, buffer);

  dbuf_ref_free(buffer);
}

/* sendto_realops_flags()
 *
 * inputs	- flag types of messages to show to real opers
 *		- flag indicating opers/admins
 *		- var args input message
 * output	- NONE
 * side effects	- Send to *local* ops only but NOT +s nonopers.
 */
void
sendto_realops_flags(unsigned int flags, int level, int type, const char *pattern, ...)
{
  const char *ntype = NULL;
  dlink_node *node = NULL;
  char nbuf[IRCD_BUFSIZE] = "";
  va_list args;

  va_start(args, pattern);
  vsnprintf(nbuf, sizeof(nbuf), pattern, args);
  va_end(args);

  switch (type)
  {
    case SEND_NOTICE:
      ntype = "Notice";
      break;
    case SEND_GLOBAL:
      ntype = "Global";
      break;
    case SEND_LOCOPS:
      ntype = "LocOps";
      break;
    default:
      assert(0);
  }

  DLINK_FOREACH(node, oper_list.head)
  {
    struct Client *client_p = node->data;
    assert(HasUMode(client_p, UMODE_OPER));

    /*
     * If we're sending it to opers and they're an admin, skip.
     * If we're sending it to admins, and they're not, skip.
     */
    if (((level == L_ADMIN) && !HasUMode(client_p, UMODE_ADMIN)) ||
        ((level == L_OPER) && HasUMode(client_p, UMODE_ADMIN)))
      continue;

    if (HasUMode(client_p, flags))
      sendto_one(client_p, ":%s NOTICE %s :*** %s -- %s",
                 me.name, client_p->name, ntype, nbuf);
  }
}

/* ts_warn()
 *
 * inputs       - var args message
 * output       - NONE
 * side effects - Call sendto_realops_flags, with some flood checking
 *                (at most 5 warnings every 5 seconds)
 */
void
sendto_realops_flags_ratelimited(time_t *rate, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE] = "";

  if ((CurrentTime - *rate) < 20)
    return;

  *rate = CurrentTime;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%s", buffer);
  ilog(LOG_TYPE_IRCD, "%s", buffer);
}

/* sendto_wallops_flags()
 *
 * inputs       - flag types of messages to show to real opers
 *              - client sending request
 *              - var args input message
 * output       - NONE
 * side effects - Send a wallops to local opers
 */
void
sendto_wallops_flags(unsigned int flags, struct Client *source_p,
                     const char *pattern, ...)
{
  dlink_node *node = NULL;
  va_list args;
  struct dbuf_block *buffer = dbuf_alloc();

  if (IsClient(source_p))
    dbuf_put_fmt(buffer, ":%s!%s@%s WALLOPS :", source_p->name, source_p->username, source_p->host);
  else
    dbuf_put_fmt(buffer, ":%s WALLOPS :", source_p->name);

  va_start(args, pattern);
  send_format(buffer, pattern, args);
  va_end(args);

  DLINK_FOREACH(node, oper_list.head)
  {
    struct Client *client_p = node->data;
    assert(client_p->umodes & UMODE_OPER);

    if (HasUMode(client_p, flags) && !IsDefunct(client_p))
      send_message(client_p, buffer);
  }

  dbuf_ref_free(buffer);
}
