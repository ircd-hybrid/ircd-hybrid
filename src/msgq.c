/*
 * IRC - Internet Relay Chat, ircd/msgq.c
 * Copyright (C) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 1, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
/** @file
 * @brief Outbound message queue implementation.
 * @version $Id$
 */

#include "stdinc.h"
#include "msgq.h"
#include "list.h"
#include "log.h"
#include "send.h"
#include "memory.h"
#include "restart.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "xsnprintf.h"


#include <sys/uio.h>

#define FEAT_BUFFERPOOL 27000000 /* XXX */

#define MB_BASE_SHIFT  5  /**< Log2 of smallest message body to allocate. */
#define MB_MAX_SHIFT   9  /**< Log2 of largest message body to allocate. */

/** Buffer for a single message. */
struct MsgBuf
{
  struct MsgBuf *next;      /**< next msg in global queue */
  struct MsgBuf **prev_p;   /**< what points to us in linked list */
  struct MsgBuf *real;      /**< the actual MsgBuf we're attaching */
  unsigned int ref;         /**< reference count */
  unsigned int length;      /**< length of message */
  unsigned int power;       /**< size of buffer (power of 2) */
  char msg[1];              /**< the message */
};

/** Return allocated length of the buffer of \a buf. */
#define bufsize(buf)    (1 << (buf)->power)

/** Message body for a particular destination. */
struct Msg
{
  struct Msg *next;    /**< next msg */
  unsigned int sent;   /**< bytes in msg that have already been sent */
  struct MsgBuf *msg;  /**< actual message in queue */
};

/** Statistics tracking for message sizes. */
struct MsgSizes
{
  unsigned int msgs;  /**< total number of messages */
  unsigned int sizes[IRCD_BUFSIZE];  /**< histogram of message sizes */
};

/** Global tracking data for message buffers. */
static struct
{
  struct MsgBuf *msglist;      /**< list of in-use MsgBuf's */

  struct
  {
    unsigned int alloc;        /**< number of Msg's allocated */
    unsigned int used;         /**< number of Msg's in use */
    struct Msg *free;          /**< freelist of Msg's */
  } msgs;                      /**< tracking info for Msg structs */

  size_t tot_bufsize;          /**< total amount of memory in buffers */

  /** Array of MsgBuf information, one entry for each used bucket size. */
  struct
  {
    unsigned int alloc;        /**< total MsgBuf's of this size */
    unsigned int used;         /**< number of MsgBuf's of this size in use */
    struct MsgBuf *free;       /**< list of free MsgBuf's */
  } msgBufs[MB_MAX_SHIFT - MB_BASE_SHIFT + 1];

  struct MsgSizes sizes;       /**< histogram of message sizes */
} MQData;

/*
 * This routine is used to remove a certain amount of data from a given
 * queue and release the Msg (and MsgBuf) structure if needed
 */
/** Remove some data from a list within a message queue.
 * @param[in,out] mq Message queue to remove from.
 * @param[in,out] qlist Particular list within queue to remove from.
 * @param[in,out] length_p Number of bytes left to remove.
 */
static void
msgq_delmsg(struct MsgQ *mq, struct MsgQList *qlist, unsigned int *length_p)
{
  struct Msg *m;
  unsigned int msglen;

  assert(mq);
  assert(qlist);
  assert(qlist->head);
  assert(length_p);

  m = qlist->head;  /* find the msg we're deleting from */

  msglen = m->msg->length - m->sent;  /* calculate how much is left */

  if (*length_p >= msglen)
  {
    /* deleted it all? */
    mq->length -= msglen;  /* decrement length */
    mq->count--;  /* decrement the message count */
    *length_p -= msglen;

    msgq_clean(m->msg);  /* free up the struct MsgBuf */
    m->msg = 0;  /* don't let it point anywhere nasty, please */

    if (qlist->head == qlist->tail)  /* figure out if we emptied the queue */
      qlist->head = qlist->tail = 0;
    else
      qlist->head = m->next;  /* just shift the list down some */

    MQData.msgs.used--;  /* struct Msg is not in use anymore */

    m->next = MQData.msgs.free;  /* throw it onto the free list */
    MQData.msgs.free = m;
  }
  else
  {
    mq->length -= *length_p;  /* decrement queue length */
    m->sent += *length_p;  /* this much of the message has been sent */
    *length_p = 0;  /* we've dealt with it all */
  }
}

/** Initialize \a mq.
 * @param[in] mq MsgQ to initialize.
 */
void
msgq_init(struct MsgQ *mq)
{
  assert(mq);

  mq->length = 0;
  mq->count = 0;
  mq->queue.head = 0;
  mq->queue.tail = 0;
  mq->prio.head = 0;
  mq->prio.tail = 0;
}

/** Delete bytes from the front of a message queue.
 * @param[in] mq Queue to drop data from.
 * @param[in] length Number of bytes to drop.
 */
void
msgq_delete(struct MsgQ *mq, unsigned int length)
{
  assert(0 != mq);

  while (length > 0)
  {
    if (mq->queue.head && mq->queue.head->sent > 0)  /* partial msg on norm q */
      msgq_delmsg(mq, &mq->queue, &length);
    else if (mq->prio.head)  /* message (partial or complete) on prio queue */
      msgq_delmsg(mq, &mq->prio, &length);
    else if (mq->queue.head)  /* message on normal queue */
      msgq_delmsg(mq, &mq->queue, &length);
    else
      break;
  }
}

/** Map data from a message queue to an I/O vector.
 * @param[in] mq Message queue to send from.
 * @param[out] iov Output vector.
 * @param[in] count Number of elements in \a iov.
 * @param[out] len Number of bytes mapped from \a mq to \a iov.
 * @return Number of elements filled in \a iov.
 */
int
msgq_mapiov(const struct MsgQ *mq, struct iovec *iov, int count,
            unsigned int *len)
{
  struct Msg *queue;
  struct Msg *prio;
  int i = 0;

  assert(mq);
  assert(iov);
  assert(count);
  assert(len);

  if (mq->length <= 0)  /* no data to map */
    return 0;

  if (mq->queue.head && mq->queue.head->sent > 0)
  {
    /* partial msg on norm q */
    iov[i].iov_base = mq->queue.head->msg->msg + mq->queue.head->sent;
    iov[i].iov_len = mq->queue.head->msg->length - mq->queue.head->sent;
    *len += iov[i].iov_len;

    queue = mq->queue.head->next;  /* where we start later... */

    i++;  /* filled an iovec... */

    if (!--count)  /* check for space */
      return i;
  }
  else
    queue = mq->queue.head;  /* start at head of queue */

  if (mq->prio.head && mq->prio.head->sent > 0)
  {
    /* partial msg on prio q */
    iov[i].iov_base = mq->prio.head->msg->msg + mq->prio.head->sent;
    iov[i].iov_len = mq->prio.head->msg->length - mq->prio.head->sent;
    *len += iov[i].iov_len;

    prio = mq->prio.head->next;  /* where we start later... */

    i++;  /* filled an iovec... */

    if (!--count)  /* check for space */
      return i;
  }
  else
    prio = mq->prio.head;  /* start at head of prio */

  for (; prio; prio = prio->next)
  {
    /* go through prio queue */
    iov[i].iov_base = prio->msg->msg;  /* store message */
    iov[i].iov_len = prio->msg->length;
    *len += iov[i].iov_len;

    i++;  /* filled an iovec... */

    if (!--count)  /* check for space */
      return i;
  }

  for (; queue; queue = queue->next)
  {
    /* go through normal queue */
    iov[i].iov_base = queue->msg->msg;
    iov[i].iov_len = queue->msg->length;
    *len += iov[i].iov_len;

    i++;  /* filled an iovec... */

    if (!--count)  /* check for space */
      return i;
  }

  return i;
}

/** Allocate a message buffer large enough to hold \a length bytes.
 * TODO: \a in_mb needs better documentation.
 * @param[in] in_mb Some other message buffer(?).
 * @param[in] length Number of bytes of space to reserve in output.
 * @return Pointer to some usable message buffer.
 */
static struct MsgBuf *
msgq_alloc(struct MsgBuf *in_mb, unsigned int length)
{
  struct MsgBuf *mb;
  unsigned int power;

  /* Find the power of two size that will accommodate the message */
  for (power = MB_BASE_SHIFT; power < MB_MAX_SHIFT + 1; power++)
    if ((length - 1) >> power == 0)
      break;

  assert((1 << power) >= length);
  assert((1 << power) <= 512);
  length = 1 << power;  /* reset the length */

  /* If the message needs a buffer of exactly the existing size, just use it */
  if (in_mb && in_mb->power == power)
  {
    in_mb->real = in_mb;  /* real buffer is this buffer */
    return in_mb;
  }

  /* Try popping one off the freelist first */
  if ((mb = MQData.msgBufs[power - MB_BASE_SHIFT].free))
    MQData.msgBufs[power - MB_BASE_SHIFT].free = mb->next;
  else if (MQData.tot_bufsize < FEAT_BUFFERPOOL)
  {
    /* Allocate another if we won't bust the BUFFERPOOL */
    ilog(LOG_TYPE_DEBUG, "Allocating MsgBuf of length %d (total size %zu)",
         length, sizeof(struct MsgBuf) + length);

    mb = MyMalloc(sizeof(struct MsgBuf) + length);
    MQData.msgBufs[power - MB_BASE_SHIFT].alloc++;
    mb->power = power;  /* remember size */
    MQData.tot_bufsize += length;
  }

  if (mb)
  {
    MQData.msgBufs[power - MB_BASE_SHIFT].used++;  /* how many are we using? */

    mb->real = 0;  /* essential initializations */
    mb->ref = 1;

    if (in_mb)  /* remember who's the *real* buffer */
      in_mb->real = mb;
  }
  else if (in_mb)  /* just use the input buffer */
    mb = in_mb->real = in_mb;

  return mb;  /* return the buffer */
}

/** Deallocate unused message buffers.
 */
static void
msgq_clear_freembs(void)
{
  struct MsgBuf *mb;
  int i;

  /* Walk through the various size classes */
  for (i = MB_BASE_SHIFT; i < MB_MAX_SHIFT + 1; i++)
  {
    /* walk down the free list */
    while ((mb = MQData.msgBufs[i - MB_BASE_SHIFT].free))
    {
      MQData.msgBufs[i - MB_BASE_SHIFT].free = mb->next;  /* shift free list */
      MQData.msgBufs[i - MB_BASE_SHIFT].alloc--;  /* reduce allocation count */
      MQData.tot_bufsize -= 1 << i;  /* reduce total buffer allocation count */
      MyFree(mb);  /* and free the buffer */
    }
  }
}

/** Format a message buffer for a client from a format string.
 * @param[in] dest %Client that receives the data (may be NULL).
 * @param[in] format Format string for message.
 * @param[in] vl Argument list for \a format.
 * @return Allocated MsgBuf.
 */
struct MsgBuf *
msgq_vmake(struct Client *dest, const char *format, va_list vl)
{
  struct MsgBuf *mb;

  assert(format);

  if (!(mb = msgq_alloc(0, IRCD_BUFSIZE)))
  {
    /*
     * from "Married With Children" episode were Al bought a REAL toilet
     * on the black market because he was tired of the wimpy water
     * conserving toilets they make these days --Bleep
     */
    /*
     * Apparently this doesn't work, the server _has_ to
     * dump a few clients to handle the load. A fully loaded
     * server cannot handle a net break without dumping some
     * clients. If we flush the connections here under a full
     * load we may end up starving the kernel for mbufs and
     * crash the machine
     */
    /*
     * attempt to recover from buffer starvation before
     * bailing this may help servers running out of memory
     */
    send_queued_all();
    mb = msgq_alloc(0, IRCD_BUFSIZE);

    if (!mb)
    { /* OK, try clearing the buffer free list */
      msgq_clear_freembs();
      mb = msgq_alloc(0, IRCD_BUFSIZE);
    }
#if 0
    if (!mb)
    {
      /* OK, try killing a client */
      kill_highest_sendq(0);  /* Don't kill any server connections */
      msgq_clear_freembs();  /* Release whatever was just freelisted */
      mb = msgq_alloc(0, IRCD_BUFSIZE);
    }

    if (!mb)
    {
      kill_highest_sendq(1);  /* Try killing a server connection now */
      msgq_clear_freembs();  /* Clear freelist again */
      mb = msgq_alloc(0, IRCD_BUFSIZE);
    }
#endif
    if (!mb)  /* AIEEEE! */
      restart("Unable to allocate buffers!");
  }

  mb->next = MQData.msglist;  /* initialize the msgbuf */
  mb->prev_p = &MQData.msglist;

  /* fill the buffer */
  mb->length = xvsnprintf(dest, mb->msg, bufsize(mb) - 1, format, vl);

  if (mb->length > bufsize(mb) - 2)
    mb->length = bufsize(mb) - 2;

  mb->msg[mb->length++] = '\r';  /* add \r\n to buffer */
  mb->msg[mb->length++] = '\n';
  mb->msg[mb->length] = '\0';  /* not strictly necessary */

  assert(mb->length <= bufsize(mb));

  if (MQData.msglist)  /* link it into the list */
    MQData.msglist->prev_p = &mb->next;
  MQData.msglist = mb;

  return mb;
}

/** Format a message buffer for a client from a format string.
 * @param[in] dest %Client that receives the data (may be NULL).
 * @param[in] format Format string for message.
 * @return Allocated MsgBuf.
 */
struct MsgBuf *
msgq_make(struct Client *dest, const char *format, ...)
{
  va_list vl;
  struct MsgBuf *mb;

  va_start(vl, format);
  mb = msgq_vmake(dest, format, vl);
  va_end(vl);

  return mb;
}

/** Append text to an existing message buffer.
 * @param[in] dest %Client for whom to format the message.
 * @param[in] mb Message buffer to append to.
 * @param[in] format Format string of what to append.
 */
void
msgq_append(struct Client *dest, struct MsgBuf *mb, const char *format, ...)
{
  va_list vl;

  assert(mb);
  assert(format);
  assert(0 == mb->real);

  assert(2 < mb->length);
  assert(bufsize(mb) >= mb->length);

  mb->length -= 2;  /* back up to before \r\n */

  va_start(vl, format);  /* append to the buffer */

  mb->length += xvsnprintf(dest, mb->msg + mb->length,
                           bufsize(mb) - mb->length - 1, format, vl);

  va_end(vl);

  if (mb->length > bufsize(mb) - 2)
    mb->length = bufsize(mb) - 2;

  mb->msg[mb->length++] = '\r';  /* add \r\n to buffer */
  mb->msg[mb->length++] = '\n';
  mb->msg[mb->length] = '\0';  /* not strictly necessary */

  assert(mb->length <= bufsize(mb));
}

/** Decrement the reference count on \a mb, freeing it if needed.
 * @param[in] mb MsgBuf to release.
 */
void
msgq_clean(struct MsgBuf *mb)
{
  assert(mb);
  assert(0 < mb->ref);

  if (!--mb->ref)
  {
    /* deallocate the message */
    if (mb->prev_p)
    {
      *mb->prev_p = mb->next;  /* clip it out of active MsgBuf's list */

      if (mb->next)
        mb->next->prev_p = mb->prev_p;
    }

    if (mb->real && mb->real != mb)  /* clean up the real buffer */
      msgq_clean(mb->real);

    mb->next = MQData.msgBufs[mb->power - MB_BASE_SHIFT].free;
    MQData.msgBufs[mb->power - MB_BASE_SHIFT].free = mb;
    MQData.msgBufs[mb->power - MB_BASE_SHIFT].used--;

    mb->prev_p = 0;
  }
}

/** Append a message to a peer's message queue.
 * @param[in] mq Message queue to append to.
 * @param[in] mb Message to append.
 * @param[in] prio If non-zero, use the high-priority (lag-busting) message list; else use the normal list.
 */
void
msgq_add(struct MsgQ *mq, struct MsgBuf *mb, int prio)
{
  struct MsgQList *qlist;
  struct Msg *msg;

  assert(mq);
  assert(mb);
  assert(0 < mb->ref);
  assert(0 < mb->length);

  ilog(LOG_TYPE_DEBUG, "Adding buffer %p [%.*s] length %u to %s queue", mb,
       mb->length - 2, mb->msg, mb->length, prio ? "priority" : "normal");

  qlist = prio ? &mq->prio : &mq->queue;

  if (!(msg = MQData.msgs.free))
  {
    /* do I need to allocate one? */
    msg = MyMalloc(sizeof(struct Msg));
    MQData.msgs.alloc++;  /* we allocated another */
  }
  else  /* shift the free list */
    MQData.msgs.free = MQData.msgs.free->next;

  MQData.msgs.used++;  /* we're using another */

  msg->next = 0; /* initialize the msg */
  msg->sent = 0;

  /* Get the real buffer, allocating one if necessary */
  if (!mb->real)
  {
    struct MsgBuf *tmp;

    MQData.sizes.msgs++; /* update histogram counts */
    MQData.sizes.sizes[mb->length - 1]++;

    tmp = msgq_alloc(mb, mb->length); /* allocate a close-fitting buffer */

    if (tmp != mb)
    {
      /* OK, prepare the new "real" buffer */
      ilog(LOG_TYPE_DEBUG, "Copying old buffer %p [%.*s] length %u into new "
           "buffer %p size %u", mb, mb->length - 2, mb->msg, mb->length,
           tmp, bufsize(tmp));
      memcpy(tmp->msg, mb->msg, mb->length + 1);  /* copy string over */
      tmp->length = mb->length;

      tmp->next = mb->next;  /* replace it in the list, now */

      if (tmp->next)
        tmp->next->prev_p = &tmp->next;
      tmp->prev_p = mb->prev_p;
      *tmp->prev_p = tmp;

      mb->next = 0;  /* this one's no longer in the list */
      mb->prev_p = 0;
    }
  }

  mb = mb->real;  /* work with the real buffer */
  mb->ref++;  /* increment the ref count on the buffer */

  msg->msg = mb;  /* point at the real message buffer now */

  if (!qlist->head)  /* queue list was empty; head and tail point to msg */
    qlist->head = qlist->tail = msg;
  else
  {
    assert(qlist->tail);

    qlist->tail->next = msg;  /* queue had something in it; add to end */
    qlist->tail = msg;
  }

  mq->length += mb->length;  /* update the queue length */
  mq->count++;  /* and the queue count */
}

/** Report memory statistics for message buffers.
 * @param[in] cptr Client requesting information.
 * @param[out] msg_alloc Receives number of bytes allocated in Msg structs.
 * @param[out] msgbuf_alloc Receives number of bytes allocated in MsgBuf structs.
 */
void
msgq_count_memory(struct Client *source_p, size_t *msg_alloc, size_t *msgbuf_alloc)
{
  int i;
  size_t total = 0, size;

  assert(client_p);
  assert(msg_alloc);
  assert(msgbuf_alloc);

  /* Data for Msg's is simple, so just send it */
  sendto_one(source_p, ":%s %d %s :Msgs allocated %d(%zu) used %d(%zu) text %zu",
             me.name, RPL_STATSDEBUG, source_p->name,
             MQData.msgs.alloc, MQData.msgs.alloc * sizeof(struct Msg),
             MQData.msgs.used,  MQData.msgs.used * sizeof(struct Msg),
             MQData.tot_bufsize);
  /* count_memory() wants to know the total */
  *msg_alloc = MQData.msgs.alloc * sizeof(struct Msg);

  /* Ok, now walk through each size class */
  for (i = MB_BASE_SHIFT; i < MB_MAX_SHIFT + 1; i++)
  {
    size = sizeof(struct MsgBuf) + (1 << i);  /* total size of a buffer */

    /* Send information for this buffer size class */
    sendto_one(source_p, ":%s %d %s :MsgBufs of size %zu allocated %d(%zu) used %d(%zu)",
               me.name, RPL_STATSDEBUG, source_p->name, 1 << i,
               MQData.msgBufs[i - MB_BASE_SHIFT].alloc,
               MQData.msgBufs[i - MB_BASE_SHIFT].alloc * size,
               MQData.msgBufs[i - MB_BASE_SHIFT].used,
               MQData.msgBufs[i - MB_BASE_SHIFT].used * size);

    /* count_memory() wants to know the total */
    total += MQData.msgBufs[i - MB_BASE_SHIFT].alloc * size;
  }

  *msgbuf_alloc = total;
}

/** Report remaining space in a MsgBuf.
 * @param[in] mb Message buffer to check.
 * @return Number of additional bytes that can be appended to the message.
 */
unsigned int
msgq_bufleft(struct MsgBuf *mb)
{
  assert(mb);

  return bufsize(mb) - mb->length;  /* \r\n counted in mb->length */
}

/** Send histogram of message lengths to a client.
 * @param[in] cptr Client requesting statistics.
 * @param[in] sd Stats descriptor for request (ignored).
 * @param[in] param Extra parameter from user (ignored).
 */
void
msgq_histogram(struct Client *source_p)
{
  struct MsgSizes tmp = MQData.sizes;  /* All hail structure copy! */
  int i;

  sendto_one(source_p, ":%s %d %s :Histogram of message lengths (%lu messages)",
             me.name, RPL_STATSDEBUG, source_p->name, tmp.msgs);

  for (i = 0; i + 16 <= IRCD_BUFSIZE; i += 16)
    sendto_one(source_p, ":%s %d %s :% 4d: %u %u %u %u "
               "%u %u %u %u %u %u %u %u %u %u %u %u",
               me.name, RPL_STATSDEBUG, source_p->name, i + 1,
               tmp.sizes[i +  0], tmp.sizes[i +  1], tmp.sizes[i +  2],
               tmp.sizes[i +  3], tmp.sizes[i +  4], tmp.sizes[i +  5],
               tmp.sizes[i +  6], tmp.sizes[i +  7], tmp.sizes[i +  8],
               tmp.sizes[i +  9], tmp.sizes[i + 10], tmp.sizes[i + 11],
               tmp.sizes[i + 12], tmp.sizes[i + 13], tmp.sizes[i + 14],
               tmp.sizes[i + 15]);
}
