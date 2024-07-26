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
 * @file dbuf.c
 * @brief Implements dynamic data buffer functionality.
 *
 * This file contains the implementation of dynamic data buffers used for efficient
 * and flexible data storage and manipulation. The dynamic buffer module supports
 * the allocation, management, and formatting of buffers that can dynamically grow
 * to accommodate varying amounts of data.
 */

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "list.h"
#include "dbuf.h"
#include "memory.h"

/**
 * @brief Allocate a new dynamic buffer block.
 *
 * This function allocates memory for a new `dbuf_block` structure and initializes
 * its reference count to 1. The allocated block has a predefined size for storing data.
 *
 * @return A pointer to the newly allocated `dbuf_block` structure.
 */
struct dbuf_block *
dbuf_alloc(void)
{
  struct dbuf_block *block = io_calloc(sizeof(*block));

  ++block->ref_count;
  return block;
}

/**
 * @brief Decrease the reference count of a dynamic buffer block and free it if the count reaches zero.
 *
 * This function decrements the reference count of the given `dbuf_block`. If the reference count
 * drops to zero, the memory allocated for the block is freed.
 *
 * @param block A pointer to the `dbuf_block` structure whose reference count is to be decreased.
 */
void
dbuf_ref_free(struct dbuf_block *block)
{
  if (--block->ref_count <= 0)
    io_free(block);
}

/**
 * @brief Add a dynamic buffer block to a buffer queue.
 *
 * This function increments the reference count of the given `dbuf_block` and adds it to the end
 * of the specified `dbuf_queue`. The total size of the queue is updated to include the size of
 * the added block.
 *
 * @param queue A pointer to the `dbuf_queue` to which the block is to be added.
 * @param block A pointer to the `dbuf_block` structure to be added to the queue.
 */
void
dbuf_add(struct dbuf_queue *queue, struct dbuf_block *block)
{
  block->ref_count++;
  list_add_tail(block, list_make_node(), &queue->blocks);
  queue->total_size += block->size;
}

/**
 * @brief Remove data from a dynamic buffer queue.
 *
 * This function removes data from the specified `dbuf_queue` until the specified `count` of bytes
 * is deleted or the queue becomes empty. It adjusts the total size of the queue and handles the
 * reference counting and freeing of the blocks as needed.
 *
 * @param queue A pointer to the `dbuf_queue` from which data is to be removed.
 * @param count The number of bytes to be removed from the queue.
 */
void
dbuf_delete(struct dbuf_queue *queue, size_t count)
{
  while (count > 0 && dbuf_length(queue) > 0)
  {
    list_node_t *node = queue->blocks.head;
    struct dbuf_block *block = node->data;
    size_t avail = block->size - queue->pos;

    if (count >= avail)
    {
      count -= avail;
      queue->total_size -= avail;

      dbuf_ref_free(block);

      list_remove(node, &queue->blocks);
      list_free_node(node);

      queue->pos = 0;
    }
    else
    {
      queue->pos += count;

      queue->total_size -= count;
      count -= count;
    }
  }
}

/**
 * @brief Format a string and store it in a dynamic buffer block.
 *
 * This function formats a string using a printf-like format specifier and stores the result
 * in the given `dbuf_block`. The function ensures that the block has a reference count of 1
 * before modifying its contents.
 *
 * @param block A pointer to the `dbuf_block` where the formatted string is to be stored.
 * @param format The format string for the data.
 * @param ... Additional arguments to be formatted according to the format.
 */
void
dbuf_put_fmt(struct dbuf_block *block, const char *format, ...)
{
  va_list args;

  assert(block->ref_count == 1);

  va_start(args, format);
  dbuf_put_args(block, format, args);
  va_end(args);
}

/**
 * @brief Store formatted data in a dynamic buffer block using a variable argument list.
 *
 * This function formats data according to the provided format string and variable argument list,
 * and stores the result in the specified `dbuf_block`. The function ensures that the block has
 * a reference count of 1 before modifying its contents.
 *
 * @param block A pointer to the `dbuf_block` where the formatted data is to be stored.
 * @param data The format string for the data.
 * @param args A variable argument list containing the data to be formatted.
 */
void
dbuf_put_args(struct dbuf_block *block, const char *data, va_list args)
{
  assert(block->ref_count == 1);

  block->size += vsnprintf(block->data + block->size, sizeof(block->data) - block->size, data, args);

  /* As per C99, (v)snprintf returns the length the resulting string would be */
  if (block->size > sizeof(block->data))
    block->size = sizeof(block->data);
}

/**
 * @brief Add raw data to a dynamic buffer queue.
 *
 * This function adds raw data to the specified `dbuf_queue`. It allocates new `dbuf_block`s
 * as necessary and updates the total size of the queue to reflect the added data.
 *
 * @param queue A pointer to the `dbuf_queue` to which the data is to be added.
 * @param buf A pointer to the raw data to be added.
 * @param length The length of the raw data to be added.
 */
void
dbuf_put(struct dbuf_queue *queue, const char *buf, size_t length)
{
  while (length > 0)
  {
    struct dbuf_block *block = dbuf_length(queue) ? queue->blocks.tail->data : NULL;

    if (block == NULL || sizeof(block->data) - block->size == 0)
    {
      block = dbuf_alloc();
      list_add_tail(block, list_make_node(), &queue->blocks);
    }

    size_t avail = sizeof(block->data) - block->size;
    if (avail > length)
      avail = length;

    memcpy(&block->data[block->size], buf, avail);
    block->size += avail;

    queue->total_size += avail;

    length -= avail;
    buf += avail;
  }
}
