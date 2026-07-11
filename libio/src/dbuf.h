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
#include <stddef.h>

#include "list.h"

/**
 * @var DBUF_BLOCK_SIZE
 * @brief Size of each data block within the dynamic buffer.
 */
enum { DBUF_BLOCK_SIZE = 1024 };

/**
 * @struct dbuf_block
 * @brief Structure representing a block of data within the dynamic buffer.
 */
struct dbuf_block
{
  int ref_count;  /**< Reference count for the data block. */
  size_t size;  /**< Size of the data block. */
  char data[DBUF_BLOCK_SIZE];  /**< Actual data stored in the block. */
};

/**
 * @struct dbuf_queue
 * @brief Structure representing a dynamic buffer queue.
 */
struct dbuf_queue
{
  list_t blocks;  /**< List of data blocks. */
  size_t total_size;  /**< Total size of the dynamic buffer. */
  size_t pos;  /**< Current position within the dynamic buffer. */
};

extern void dbuf_add(struct dbuf_queue *, struct dbuf_block *);
extern void dbuf_delete(struct dbuf_queue *, size_t);
extern void dbuf_put(struct dbuf_queue *, const char *, size_t);
extern void dbuf_put_args(struct dbuf_block *, const char *, va_list);
extern void dbuf_put_fmt(struct dbuf_block *, const char *, ...);
extern void dbuf_ref_free(struct dbuf_block *);
extern struct dbuf_block *dbuf_alloc(void);

/**
 * @brief Get the total length of data available in the dbuf queue.
 * @param queue Pointer to the dbuf_queue.
 * @return Total number of bytes available for reading.
 */
static inline size_t
dbuf_length(const struct dbuf_queue *queue)
{
  return queue->total_size;
}

/**
 * @brief Remove all data from a dbuf queue.
 * @param queue Pointer to the dbuf_queue.
 */
static inline void
dbuf_clear(struct dbuf_queue *queue)
{
  dbuf_delete(queue, dbuf_length(queue));
}
#endif  /* INCLUDED_dbuf_h */
