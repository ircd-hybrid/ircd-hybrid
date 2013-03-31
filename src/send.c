/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  send.c: Functions for sending messages.
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
#include "send.h"
#include "channel.h"
#include "client.h"
#include "dbuf.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "conf.h"
#include "log.h"
#include "memory.h"
#include "hook.h"
#include "packet.h"


struct Callback *iosend_cb = NULL;
static unsigned int current_serial = 0;


/* send_format()
 *
 * inputs	- buffer to format into
 *              - size of the buffer
 *		- format pattern to use
 *		- var args
 * output	- number of bytes formatted output
 * side effects	- modifies sendbuf
 */
static inline int
send_format(char *lsendbuf, int bufsize, const char *pattern, va_list args)
{
  int len;

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
  len = vsnprintf(lsendbuf, bufsize - 1, pattern, args);
  if (len > bufsize - 2)
    len = bufsize - 2;  /* required by some versions of vsnprintf */

  lsendbuf[len++] = '\r';
  lsendbuf[len++] = '\n';
  return len;
}

/*
 * iosend_default - append a packet to the client's sendq.
 */
void *
iosend_default(va_list args)
{
  struct Client *to = va_arg(args, struct Client *);
  int length = va_arg(args, int);
  char *buf = va_arg(args, char *);

  dbuf_put(&to->localClient->buf_sendq, buf, length);
  return NULL;
}

/*
 ** send_message
 **      Internal utility which appends given buffer to the sockets
 **      sendq.
 */
static void
send_message(struct Client *to, char *buf, int len)
{
  assert(!IsMe(to));
  assert(to != &me);

  if (dbuf_length(&to->localClient->buf_sendq) + len > get_sendq(&to->localClient->confs))
  {
    if (IsServer(to))
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Max SendQ limit exceeded for %s: %lu > %u",
                           get_client_name(to, HIDE_IP),
                           (unsigned long)(dbuf_length(&to->localClient->buf_sendq) + len),
                           get_sendq(&to->localClient->confs));
    if (IsClient(to))
      SetSendQExceeded(to);
    dead_link_on_write(to, 0);
    return;
  }

  execute_callback(iosend_cb, to, len, buf);

  /*
   ** Update statistics. The following is slightly incorrect
   ** because it counts messages even if queued, but bytes
   ** only really sent. Queued bytes get updated in SendQueued.
   */
  ++to->localClient->send.messages;
  ++me.localClient->send.messages;

  if (dbuf_length(&to->localClient->buf_sendq) >
      (IsServer(to) ? (unsigned int) 1024 : (unsigned int) 4096))
    send_queued_write(to);
}

/* send_message_remote()
 *
 * inputs	- pointer to client from message is being sent
 * 		- pointer to client to send to
 *		- pointer to preformatted buffer
 *		- length of input buffer
 * output	- none
 * side effects	- Despite the function name, this only sends to directly
 *		  connected clients.
 * 
 */
static void
send_message_remote(struct Client *to, struct Client *from,
                    char *buf, int len)
{
  if (!MyConnect(to))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			 "server send message to %s [%s] dropped from %s(Not local server)",
			 to->name, to->from->name, from->name);
    return;
  }

  /* Optimize by checking if (from && to) before everything */
  /* we set to->from up there.. */

  if (!MyClient(from) && IsClient(to) && (to == from->from))
  {
    if (IsServer(from))
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Send message to %s [%s] dropped from %s(Fake Dir)",
                           to->name, to->from->name, from->name);
      return;
    }

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Ghosted: %s[%s@%s] from %s[%s@%s] (%s)",
                         to->name, to->username, to->host,
                         from->name, from->username, from->host,
                         to->from->name);

    sendto_server(NULL, CAP_TS6, NOCAPS,
                  ":%s KILL %s :%s (%s[%s@%s] Ghosted %s)",
                  me.id, to->name, me.name, to->name,
                  to->username, to->host, to->from->name);
    sendto_server(NULL, NOCAPS, CAP_TS6,
                  ":%s KILL %s :%s (%s[%s@%s] Ghosted %s)",
                  me.name, to->name, me.name, to->name,
                  to->username, to->host, to->from->name);

    AddFlag(to, FLAGS_KILLED);

    if (IsClient(from))
      sendto_one(from, form_str(ERR_GHOSTEDCLIENT),
                 me.name, from->name, to->name, to->username,
                 to->host, to->from);

    exit_client(to, &me, "Ghosted client");

    return;
  } 

  send_message(to, buf, len);
}

/*
 ** sendq_unblocked
 **      Called when a socket is ready for writing.
 */
void
sendq_unblocked(fde_t *fd, struct Client *client_p)
{
  ClearSendqBlocked(client_p);
  /* let send_queued_write be executed by send_queued_all */

#ifdef HAVE_LIBCRYPTO
  if (fd->flags.pending_read)
  {
    fd->flags.pending_read = 0;
    read_packet(fd, client_p);
  }
#endif
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
  int retlen;
  struct dbuf_block *first;

  /*
   ** Once socket is marked dead, we cannot start writing to it,
   ** even if the error is removed...
   */
  if (IsDead(to) || IsSendqBlocked(to))
    return;  /* no use calling send() now */

  /* Next, lets try to write some data */

  if (dbuf_length(&to->localClient->buf_sendq))
  {
    do {
      first = to->localClient->buf_sendq.blocks.head->data;

#ifdef HAVE_LIBCRYPTO
      if (to->localClient->fd.ssl)
      {
        retlen = SSL_write(to->localClient->fd.ssl, first->data, first->size);

        /* translate openssl error codes, sigh */
	if (retlen < 0)
	  switch (SSL_get_error(to->localClient->fd.ssl, retlen))
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
      else
#endif
        retlen = send(to->localClient->fd.fd, first->data, first->size, 0);

      if (retlen <= 0)
        break;

      dbuf_delete(&to->localClient->buf_sendq, retlen);

      /* We have some data written .. update counters */
      to->localClient->send.bytes += retlen;
      me.localClient->send.bytes += retlen;
    } while (dbuf_length(&to->localClient->buf_sendq));

    if ((retlen < 0) && (ignoreErrno(errno)))
    {
      /* we have a non-fatal error, reschedule a write */
      SetSendqBlocked(to);
      comm_setselect(&to->localClient->fd, COMM_SELECT_WRITE,
                     (PF *)sendq_unblocked, (void *)to, 0);
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
  dlink_node *ptr;

  /* Servers are processed first, mainly because this can generate
   * a notice to opers, which is to be delivered by this function.
   */
  DLINK_FOREACH(ptr, serv_list.head)
    send_queued_write((struct Client *) ptr->data);

  DLINK_FOREACH(ptr, unknown_list.head)
    send_queued_write((struct Client *) ptr->data);

  DLINK_FOREACH(ptr, local_client_list.head)
    send_queued_write((struct Client *) ptr->data);

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
  char buffer[IRCD_BUFSIZE];
  int len;

  if (to->from != NULL)
    to = to->from;
  if (IsDead(to))
    return; /* This socket has already been marked as dead */

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  send_message(to, buffer, len);
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
  va_list alocal, aremote, auid;
  char local_buf[IRCD_BUFSIZE];
  char remote_buf[IRCD_BUFSIZE];
  char uid_buf[IRCD_BUFSIZE];
  int local_len, remote_len, uid_len;
  dlink_node *ptr = NULL, *ptr_next = NULL;

  if (IsServer(from))
    local_len = sprintf(local_buf, ":%s ",
                        from->name);
  else
    local_len = sprintf(local_buf, ":%s!%s@%s ",
                        from->name, from->username, from->host);
  remote_len = sprintf(remote_buf, ":%s ",
                          from->name);
  uid_len = sprintf(uid_buf, ":%s ",
                    ID(from));

  va_start(alocal, pattern);
  va_start(aremote, pattern);
  va_start(auid, pattern);
  local_len += send_format(&local_buf[local_len], IRCD_BUFSIZE - local_len,
                           pattern, alocal);
  remote_len += send_format(&remote_buf[remote_len], IRCD_BUFSIZE - remote_len,
                            pattern, aremote);
  uid_len += send_format(&uid_buf[uid_len], IRCD_BUFSIZE - uid_len, pattern,
                         auid);
  va_end(auid);
  va_end(aremote);
  va_end(alocal);

  ++current_serial;

  DLINK_FOREACH_SAFE(ptr, ptr_next, chptr->members.head)
  {
    struct Membership *ms = ptr->data;
    struct Client *target_p = ms->client_p;

    assert(IsClient(target_p));

    if (IsDefunct(target_p) || HasUMode(target_p, UMODE_DEAF) || target_p->from == one)
      continue;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (MyConnect(target_p))
    {
      if (target_p->localClient->serial != current_serial)
      {
        send_message(target_p, local_buf, local_len);
        target_p->localClient->serial = current_serial;
      }
    }
    else
    {
      /* Now check whether a message has been sent to this
       * remote link already
       */
      if (target_p->from->localClient->serial != current_serial)
      {
        if (IsCapable(target_p->from, CAP_TS6))
          send_message_remote(target_p->from, from, uid_buf, uid_len);
        else
          send_message_remote(target_p->from, from, remote_buf, remote_len);
        target_p->from->localClient->serial = current_serial;
      }
    }
  }
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
  dlink_node *ptr = NULL;
  char buffer[IRCD_BUFSIZE];
  int len = 0;

  va_start(args, format);
  len = send_format(buffer, IRCD_BUFSIZE, format, args);
  va_end(args);

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *client_p = ptr->data;

    /* If dead already skip */
    if (IsDead(client_p))
      continue;
    /* check against 'one' */
    if (one != NULL && (client_p == one->from))
      continue;
    /* check we have required capabs */
    if ((client_p->localClient->caps & caps) != caps)
      continue;
    /* check we don't have any forbidden capabs */
    if ((client_p->localClient->caps & nocaps) != 0)
      continue;

    send_message(client_p, buffer, len);
  }
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
  struct Membership *ms;
  struct Client *target_p;
  char buffer[IRCD_BUFSIZE];
  int len;

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  ++current_serial;

  DLINK_FOREACH(cptr, user->channel.head)
  {
    chptr = ((struct Membership *) cptr->data)->chptr;
    assert(chptr != NULL);

    DLINK_FOREACH(uptr, chptr->members.head)
    {
      ms = uptr->data;
      target_p = ms->client_p;
      assert(target_p != NULL);

      if (!MyConnect(target_p) || target_p == user || IsDefunct(target_p) ||
          target_p->localClient->serial == current_serial)
        continue;

      if (HasCap(target_p, cap) != cap)
        continue;

      target_p->localClient->serial = current_serial;
      send_message(target_p, buffer, len);
    }
  }

  if (touser && MyConnect(user) && !IsDead(user) &&
      user->localClient->serial != current_serial)
    if (HasCap(target_p, cap) == cap)
      send_message(user, buffer, len);
}

/* sendto_channel_local()
 *
 * inputs	- member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - whether to ignore +D clients (YES/NO)
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  locally connected to this server.
 */
void
sendto_channel_local(int type, int nodeaf, struct Channel *chptr,
                     const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  dlink_node *ptr;
  struct Membership *ms;
  struct Client *target_p;

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    target_p = ms->client_p;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (!MyConnect(target_p) || IsDefunct(target_p) ||
        (nodeaf && HasUMode(target_p, UMODE_DEAF)))
      continue;

    send_message(target_p, buffer, len);
  }
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
sendto_channel_local_butone(struct Client *one, int type, unsigned int cap,
			    struct Channel *chptr, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  struct Client *target_p;
  struct Membership *ms;
  dlink_node *ptr;

  va_start(args, pattern); 
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, chptr->members.head)       
  {   
    ms = ptr->data;
    target_p = ms->client_p;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (!MyConnect(target_p) || target_p == one ||
        IsDefunct(target_p) || HasUMode(target_p, UMODE_DEAF))
      continue;

    if (HasCap(target_p, cap) != cap)
        continue;
    send_message(target_p, buffer, len);
  }
}


/* sendto_channel_remote()
 *
 * inputs	- Client not to send towards
 *		- Client from whom message is from
 *		- member status mask, e.g. CHFL_CHANOP | CHFL_VOICE
 *              - pointer to channel to send to
 *              - var args pattern
 * output	- NONE
 * side effects - Send a message to all members of a channel that are
 *		  remote to this server.
 */
void
sendto_channel_remote(struct Client *one, struct Client *from, int type,
                      const unsigned int caps, const unsigned int nocaps,
                      struct Channel *chptr, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  dlink_node *ptr;
  struct Client *target_p;
  struct Membership *ms;

  va_start(args, pattern);
  len = send_format(buffer, IRCD_BUFSIZE, pattern, args);
  va_end(args);

  ++current_serial;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    target_p = ms->client_p;

    if (type != 0 && (ms->flags & type) == 0)
      continue;

    if (MyConnect(target_p))
      continue;
    target_p = target_p->from;

    if (target_p == one->from ||
        ((target_p->from->localClient->caps & caps) != caps) ||
        ((target_p->from->localClient->caps & nocaps) != 0))
      continue;
    if (target_p->from->localClient->serial != current_serial)
    {
      send_message(target_p, buffer, len);
      target_p->from->localClient->serial = current_serial;
    }
  } 
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
match_it(const struct Client *one, const char *mask, int what)
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
sendto_match_butone(struct Client *one, struct Client *from, char *mask,
                    int what, const char *pattern, ...)
{
  va_list alocal, aremote;
  struct Client *client_p;
  dlink_node *ptr, *ptr_next;
  char local_buf[IRCD_BUFSIZE], remote_buf[IRCD_BUFSIZE];
  int local_len = sprintf(local_buf, ":%s!%s@%s ", from->name,
                          from->username, from->host);
  int remote_len = sprintf(remote_buf, ":%s ", from->name);

  va_start(alocal, pattern);
  va_start(aremote, pattern);
  local_len += send_format(&local_buf[local_len], IRCD_BUFSIZE - local_len,
                           pattern, alocal);
  remote_len += send_format(&remote_buf[remote_len], IRCD_BUFSIZE - remote_len,
                            pattern, aremote);
  va_end(aremote);
  va_end(alocal);

  /* scan the local clients */
  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;

    if (client_p != one && !IsDefunct(client_p) &&
        match_it(client_p, mask, what))
      send_message(client_p, local_buf, local_len);
  }

  /* Now scan servers */
  DLINK_FOREACH_SAFE(ptr, ptr_next, serv_list.head)
  {
    client_p = ptr->data;

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
    if (client_p != one && !IsDefunct(client_p))
      send_message_remote(client_p, from, remote_buf, remote_len);
  }
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
sendto_match_servs(struct Client *source_p, const char *mask, int cap,
                   const char *pattern, ...)
{
  va_list args;
  struct Client *target_p;
  dlink_node *ptr;
  char buffer[IRCD_BUFSIZE];
  int found = 0;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  ++current_serial;

  DLINK_FOREACH(ptr, global_serv_list.head)
  {
    target_p = ptr->data;

    /* Do not attempt to send to ourselves, or the source */
    if (IsMe(target_p) || target_p->from == source_p->from)
      continue;

    if (target_p->from->localClient->serial == current_serial)
      continue;

    if (!match(mask, target_p->name))
    {
      /*
       * if we set the serial here, then we'll never do a
       * match() again, if !IsCapable()
       */
      target_p->from->localClient->serial = current_serial;
      found++;

      if (!IsCapable(target_p->from, cap))
        continue;

      sendto_anywhere(target_p, source_p, "%s", buffer);
    }
  }
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
                const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;
  struct Client *send_to = (to->from != NULL ? to->from : to);

  if (IsDead(send_to))
    return;

  if (MyClient(to))
  {
    if (IsServer(from))
    {
      if (IsCapable(to, CAP_TS6) && HasID(from))
        len = sprintf(buffer, ":%s ", from->id);
      else
        len = sprintf(buffer, ":%s ", from->name);
    }
    else
      len = sprintf(buffer, ":%s!%s@%s ",
                       from->name, from->username, from->host);
  }
  else len = sprintf(buffer, ":%s ", ID_or_name(from, send_to));

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  if(MyClient(to))
    send_message(send_to, buffer, len);
  else
    send_message_remote(send_to, from, buffer, len);
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
  dlink_node *ptr = NULL;
  char nbuf[IRCD_BUFSIZE];
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

  DLINK_FOREACH(ptr, oper_list.head)
  {
    struct Client *client_p = ptr->data;
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
  dlink_node *ptr = NULL;
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;

  if (IsClient(source_p))
    len = sprintf(buffer, ":%s!%s@%s WALLOPS :",
                  source_p->name, source_p->username, source_p->host);
  else
    len = sprintf(buffer, ":%s WALLOPS :", source_p->name);

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, oper_list.head)
  {
    struct Client *client_p = ptr->data;
    assert(client_p->umodes & UMODE_OPER);

    if (HasUMode(client_p, flags) && !IsDefunct(client_p))
      send_message(client_p, buffer, len);
  }
}

/* ts_warn()
 *
 * inputs	- var args message
 * output	- NONE
 * side effects	- Call sendto_realops_flags, with some flood checking
 *		  (at most 5 warnings every 5 seconds)
 */
void
ts_warn(const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  static time_t last = 0;
  static int warnings = 0;

  /*
   ** if we're running with TS_WARNINGS enabled and someone does
   ** something silly like (remotely) connecting a nonTS server,
   ** we'll get a ton of warnings, so we make sure we don't send
   ** more than 5 every 5 seconds.  -orabidoo
   */

  if (CurrentTime - last < 5)
  {
    if (++warnings > 5)
      return;
  }
  else
  {
    last = CurrentTime;
    warnings = 0;
  }

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "%s", buffer);
  ilog(LOG_TYPE_IRCD, "%s", buffer);
}

/* kill_client()
 *
 * inputs	- client to send kill towards
 * 		- pointer to client to kill
 * 		- reason for kill
 * output	- NONE
 * side effects	- NONE
 */
void
kill_client(struct Client *client_p, struct Client *diedie,
            const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  int len;

  if (client_p->from != NULL)
    client_p = client_p->from;
  if (IsDead(client_p))
    return;

  len = sprintf(buffer, ":%s KILL %s :", ID_or_name(&me, client_p->from),
                ID_or_name(diedie, client_p));

  va_start(args, pattern);
  len += send_format(&buffer[len], IRCD_BUFSIZE - len, pattern, args);
  va_end(args);

  send_message(client_p, buffer, len);
}

/* kill_client_ll_serv_butone()
 *
 * inputs	- pointer to client to not send to
 *		- pointer to client to kill
 * output	- NONE
 * side effects	- Send a KILL for the given client
 *		  message to all connected servers
 *                except the client 'one'. Also deal with
 *		  client being unknown to leaf, as in lazylink...
 */
void
kill_client_ll_serv_butone(struct Client *one, struct Client *source_p,
                           const char *pattern, ...)
{
  va_list args;
  int have_uid = 0;
  dlink_node *ptr = NULL;
  char buf_uid[IRCD_BUFSIZE], buf_nick[IRCD_BUFSIZE];
  int len_uid = 0, len_nick = 0;

  if (HasID(source_p))
  {
    have_uid = 1;
    va_start(args, pattern);
    len_uid = sprintf(buf_uid, ":%s KILL %s :", me.id, ID(source_p));
    len_uid += send_format(&buf_uid[len_uid], IRCD_BUFSIZE - len_uid, pattern,
                           args);
    va_end(args);
  }

  va_start(args, pattern);
  len_nick = sprintf(buf_nick, ":%s KILL %s :", me.name, source_p->name);
  len_nick += send_format(&buf_nick[len_nick], IRCD_BUFSIZE - len_nick, pattern,
                          args);
  va_end(args);

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *client_p = ptr->data;

    if (one != NULL && (client_p == one->from))
      continue;
    if (IsDefunct(client_p))
      continue;

    if (have_uid && IsCapable(client_p, CAP_TS6))
      send_message(client_p, buf_uid, len_uid);
    else
      send_message(client_p, buf_nick, len_nick);
  }
} 
