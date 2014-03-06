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

void
dbuf_add(struct dbuf_queue *qptr, struct dbuf_block *bptr)
{
  assert(bptr->size > 0);

  bptr->refs++;
  dlinkAddTail(bptr, make_dlink_node(), &qptr->blocks);

  qptr->total_size += bptr->size;
}

void
dbuf_delete(struct dbuf_queue *qptr, size_t count)
{
  assert(qptr->total_size >= count);

  qptr->total_size -= count;

  while (count > 0 && dlink_list_length(&qptr->blocks) > 0)
  {
    dlink_node *node = qptr->blocks.head;
    struct dbuf_block *buffer = node->data;
    size_t avail;

    assert(buffer->size > qptr->pos);
    avail = buffer->size - qptr->pos;

    if (count >= avail)
    {
      count -= avail;

      dbuf_ref_free(buffer);

      dlinkDelete(node, &qptr->blocks);
      free_dlink_node(node);

      qptr->pos = 0;

    }
    else
    {
      qptr->pos += count;
      count = 0;
    }
  }
}

struct dbuf_block *
dbuf_alloc(void)
{
  struct dbuf_block *block = mp_pool_get(dbuf_pool);

  memset(block, 0, sizeof(*block));

  ++block->refs;
  return block;
}

void
dbuf_ref_free(struct dbuf_block *bptr)
{
  if (--bptr->refs <= 0)
    mp_pool_release(bptr);
}

void
dbuf_put(struct dbuf_block *dbuf, const char *pattern, ...)
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
    dbuf->size = sizeof(dbuf->data);  /* Required by some versions of vsnprintf */
}

void
dbuf_put_raw(struct dbuf_queue *qptr, const char *buf, size_t sz)
{
  struct dbuf_block *buffer;

  assert(sz > 0);

  if (dlink_list_length(&qptr->blocks) == 0)
  {
    buffer = dbuf_alloc();
    dlinkAddTail(buffer, make_dlink_node(), &qptr->blocks);
    assert(qptr->pos == 0);
  }

  do
  {
    size_t amount;

    buffer = qptr->blocks.tail->data;
    amount = sizeof(buffer->data) - buffer->size;

    if (!amount)
    {
      buffer = dbuf_alloc();
      dlinkAddTail(buffer, make_dlink_node(), &qptr->blocks);
    }

    if (amount > sz)
      amount = sz;

    memcpy(&buffer->data[buffer->size], buf, amount);
    buffer->size += amount;

    qptr->total_size += amount;
    sz -= amount;
    buf += amount;
  } while (sz > 0);
}

