/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/**
 * @def dbuf_length(x)
 * @brief Macro to get the total length of a dbuf queue.
 * @param x Pointer to the dbuf_queue.
 * @return Total length of the dbuf queue.
 */
#define dbuf_length(x) ((x)->total_size)

/**
 * @def dbuf_clear(x)
 * @brief Macro to clear a dbuf queue.
 * @param x Pointer to the dbuf_queue.
 */
#define dbuf_clear(x) dbuf_delete(x, dbuf_length(x))

/**
 * @enum DBUF_BLOCK_SIZE
 * @brief Size of each data block within the dynamic buffer.
 */
enum { DBUF_BLOCK_SIZE = 1024 };

/**
 * @struct dbuf_block
 * @brief Structure representing a block of data within the dynamic buffer.
 */
struct dbuf_block
{
  int refs;  /**< Reference count for the data block. */
  size_t size;  /**< Size of the data block. */
  char data[DBUF_BLOCK_SIZE];  /**< Actual data stored in the block. */
};

/**
 * @struct dbuf_queue
 * @brief Structure representing a dynamic buffer queue.
 */
struct dbuf_queue
{
  dlink_list blocks;  /**< List of data blocks. */
  size_t total_size;  /**< Total size of the dynamic buffer. */
  size_t pos;  /**< Current position within the dynamic buffer. */
};

extern struct dbuf_block *dbuf_alloc(void);
extern void dbuf_ref_free(struct dbuf_block *);
extern void dbuf_add(struct dbuf_queue *, struct dbuf_block *);
extern void dbuf_delete(struct dbuf_queue *, size_t);
extern void dbuf_put_fmt(struct dbuf_block *, const char *, ...);
extern void dbuf_put_args(struct dbuf_block *, const char *, va_list);
extern void dbuf_put(struct dbuf_queue *, const char *, size_t);
#endif  /* INCLUDED_dbuf_h */
