#ifndef INCLUDED_msgq_h
#define INCLUDED_msgq_h
/*
 * IRC - Internet Relay Chat, include/msgq.h
 * Copyright (C) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
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
 * @brief Outbound message queue interface and declarations.
 * @version $Id$
 */
#ifndef INCLUDED_ircd_defs_h
#include "ircd_defs.h" /* BUFSIZE */
#endif
#ifndef INCLUDED_sys_types_h
#include <sys/types.h>
#define INCLUDED_sys_types_h
#endif
#ifndef INCLUDED_stdarg_h
#include <stdarg.h>
#define INCLUDED_stdarg_h
#endif

struct iovec;
struct Client;
struct Msg;
struct MsgBuf;

/** Queue of individual messages. */
struct MsgQList
{
  struct Msg *head;             /**< First Msg in queue list */
  struct Msg *tail;             /**< Last Msg in queue list */
};

/** Entire two-priority message queue for a destination. */
struct MsgQ
{
  unsigned int length;          /**< Current number of bytes stored */
  unsigned int count;           /**< Current number of messages stored */
  struct MsgQList queue;        /**< Normal Msg queue */
  struct MsgQList prio;         /**< Priority Msg queue */
};

/** Returns the current number of bytes stored in \a mq. */
#define MsgQLength(mq) ((mq)->length)

/** Returns the current number of messages stored in \a mq. */
#define MsgQCount(mq) ((mq)->count)

/** Scratch the current content of the buffer.
 * Release all allocated buffers and make it empty.
 */
#define MsgQClear(mq) msgq_delete((mq), MsgQLength(mq))

/*
 * Prototypes
 */
extern void msgq_init(struct MsgQ *);
extern void msgq_delete(struct MsgQ *, unsigned int);
extern int msgq_mapiov(const struct MsgQ *, struct iovec *, int, unsigned int *);
extern struct MsgBuf *msgq_make(struct Client *, const char *, ...);
extern struct MsgBuf *msgq_vmake(struct Client *, const char *, va_list);
extern void msgq_append(struct Client *, struct MsgBuf *, const char *, ...);
extern void msgq_clean(struct MsgBuf *);
extern void msgq_add(struct MsgQ *, struct MsgBuf *, int);
extern void msgq_count_memory(struct Client *, size_t *, size_t *);
extern void msgq_histogram(struct Client *);
extern unsigned int msgq_bufleft(struct MsgBuf *);
#endif /* INCLUDED_msgq_h */
