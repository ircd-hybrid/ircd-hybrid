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

/*! \file dbuf.c
 * \brief Supports dynamic data buffers.
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


struct dbuf_block *
dbuf_alloc(void)
{
  struct dbuf_block *block = io_calloc(sizeof(*block));

  ++block->ref_count;
  return block;
}

void
dbuf_ref_free(struct dbuf_block *block)
{
  if (--block->ref_count <= 0)
    io_free(block);
}

void
dbuf_add(struct dbuf_queue *queue, struct dbuf_block *block)
{
  block->ref_count++;
  list_add_tail(block, list_make_node(), &queue->blocks);
  queue->total_size += block->size;
}

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

void
dbuf_put_fmt(struct dbuf_block *block, const char *pattern, ...)
{
  va_list args;

  assert(block->ref_count == 1);

  va_start(args, pattern);
  dbuf_put_args(block, pattern, args);
  va_end(args);
}

void
dbuf_put_args(struct dbuf_block *block, const char *data, va_list args)
{
  assert(block->ref_count == 1);

  block->size += vsnprintf(block->data + block->size, sizeof(block->data) - block->size, data, args);

  /* As per C99, (v)snprintf returns the length the resulting string would be */
  if (block->size > sizeof(block->data))
    block->size = sizeof(block->data);
}

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
