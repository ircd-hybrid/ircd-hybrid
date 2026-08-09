/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file dbuf.h
 * @brief Header file for dynamic buffers.
 *
 * The dbuf.h file provides structures and functions for managing dynamic buffers.
 * Dynamic buffers are used for efficient handling and manipulation of
 * variable-length data.
 */

#ifndef INCLUDED_dbuf_h
#define INCLUDED_dbuf_h
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#include "list.h"

struct dbuf_block;

/**
 * @struct dbuf_queue
 * @brief Structure representing a dynamic buffer queue.
 */
struct dbuf_queue
{
  list_t block_list;  /**< List of data blocks. */
  size_t length;  /**< Total size of the dynamic buffer. */
  size_t head_offset;  /**< Current position within the dynamic buffer. */
};

struct dbuf_view
{
  const void *data;
  size_t length;
};

struct dbuf_queue_iterator
{
  const struct dbuf_queue *queue;
  const void *cursor;
};

extern void dbuf_block_append_fmt(struct dbuf_block *, const char *, ...);
extern void dbuf_block_append_vfmt(struct dbuf_block *, const char *, va_list);
extern void dbuf_block_ref(struct dbuf_block *);
extern void dbuf_block_truncate(struct dbuf_block *, size_t);
extern void dbuf_block_unref(struct dbuf_block *);
extern void dbuf_queue_append(struct dbuf_queue *, const void *, size_t);
extern void dbuf_queue_append_block(struct dbuf_queue *, struct dbuf_block *);
extern void dbuf_queue_clear(struct dbuf_queue *);
extern void dbuf_queue_consume(struct dbuf_queue *, size_t);
extern void dbuf_queue_iterator_init(const struct dbuf_queue *, struct dbuf_queue_iterator *);
extern bool dbuf_block_append(struct dbuf_block *, const void *, size_t);
extern bool dbuf_queue_iterator_next(struct dbuf_queue_iterator *, struct dbuf_view *);
extern bool dbuf_queue_peek_head(const struct dbuf_queue *, struct dbuf_view *);
extern size_t dbuf_block_length(const struct dbuf_block *);
extern struct dbuf_block *dbuf_block_create(void);

/**
 * @brief Get the total length of data available in the dbuf queue.
 * @param queue Pointer to the dbuf_queue.
 * @return Total number of bytes available for reading.
 */
static inline size_t
dbuf_queue_length(const struct dbuf_queue *queue)
{
  return queue->length;
}

static inline bool
dbuf_queue_is_empty(const struct dbuf_queue *queue)
{
  return dbuf_queue_length(queue) == 0;
}
#endif  /* INCLUDED_dbuf_h */
