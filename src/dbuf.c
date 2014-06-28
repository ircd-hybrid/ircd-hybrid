/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file dbuf.c
 * \brief Supports dynamic data buffers.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "dbuf.h"
#include "memory.h"
#include "mempool.h"

static mp_pool_t *dbuf_pool;

void
dbuf_init(void)
{
  dbuf_pool = mp_pool_new(sizeof(struct dbuf_block), MP_CHUNK_SIZE_DBUF);
}

struct dbuf_block *
dbuf_alloc(void)
{
  struct dbuf_block *block = mp_pool_get(dbuf_pool);

  ++block->refs;
  return block;
}

void
dbuf_ref_free(struct dbuf_block *block)
{
  if (--block->refs <= 0)
    mp_pool_release(block);
}

void
dbuf_add(struct dbuf_queue *queue, struct dbuf_block *block)
{
  block->refs++;
  dlinkAddTail(block, make_dlink_node(), &queue->blocks);
  queue->total_size += block->size;
}

void
dbuf_delete(struct dbuf_queue *queue, size_t count)
{
  while (count > 0 && dbuf_length(queue) > 0)
  {
    dlink_node *node = queue->blocks.head;
    struct dbuf_block *block = node->data;
    size_t avail = block->size - queue->pos;

    if (count >= avail)
    {
      count -= avail;
      queue->total_size -= avail;

      dbuf_ref_free(block);

      dlinkDelete(node, &queue->blocks);
      free_dlink_node(node);

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
dbuf_put_fmt(struct dbuf_block *dbuf, const char *pattern, ...)
{
  va_list args;

  assert(dbuf->refs == 1);

  va_start(args, pattern);
  dbuf_put_args(dbuf, pattern, args);
  va_end(args);
}

void
dbuf_put_args(struct dbuf_block *dbuf, const char *data, va_list args)
{
  assert(dbuf->refs == 1);

  dbuf->size += vsnprintf(dbuf->data + dbuf->size, sizeof(dbuf->data) - dbuf->size, data, args);
  if (dbuf->size > sizeof(dbuf->data))
    dbuf->size = sizeof(dbuf->data); /* required by some versions of vsnprintf */
}

void
dbuf_put(struct dbuf_queue *queue, const char *buf, size_t sz)
{
  while (sz > 0)
  {
    size_t avail;
    struct dbuf_block *block = dbuf_length(queue) ? queue->blocks.tail->data : NULL;

    if (block == NULL || sizeof(block->data) - block->size == 0)
    {
      block = dbuf_alloc();
      dlinkAddTail(block, make_dlink_node(), &queue->blocks);
    }

    avail = sizeof(block->data) - block->size;
    if (avail > sz)
      avail = sz;

    memcpy(&block->data[block->size], buf, avail);
    block->size += avail;

    queue->total_size += avail;

    sz -= avail;
    buf += avail;
  }
}
