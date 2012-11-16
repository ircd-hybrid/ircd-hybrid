/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  dbuf.c: Supports dynamic data buffers.
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
#include "dbuf.h"
#include "memory.h"
#include "mempool.h"

static mp_pool_t *dbuf_pool;

void
dbuf_init(void)
{
  dbuf_pool = mp_pool_new(sizeof(struct dbuf_block), MP_CHUNK_SIZE_DBUF);
}

static struct dbuf_block *
dbuf_alloc(struct dbuf_queue *qptr)
{
  struct dbuf_block *block = mp_pool_get(dbuf_pool);

  memset(block, 0, sizeof(*block));
  dlinkAddTail(block, make_dlink_node(), &qptr->blocks);
  return block;
}

void
dbuf_put(struct dbuf_queue *qptr, char *data, size_t count)
{
  struct dbuf_block *last;
  size_t amount;

  assert(count > 0);
  if (qptr->blocks.tail == NULL)
    dbuf_alloc(qptr);

  do {
    last = qptr->blocks.tail->data;

    amount = DBUF_BLOCK_SIZE - last->size;
    if (!amount)
    {
      last = dbuf_alloc(qptr);
      amount = DBUF_BLOCK_SIZE;
    }
    if (amount > count)
      amount = count;

    memcpy((void *) &last->data[last->size], data, amount);
    count -= amount;
    last->size += amount;
    qptr->total_size += amount;

    data += amount;

  } while (count > 0);
}

void
dbuf_delete(struct dbuf_queue *qptr, size_t count)
{
  dlink_node *ptr;
  struct dbuf_block *first;

  assert(qptr->total_size >= count);
  if (count == 0)
    return;

  /* free whole blocks first.. */
  while (1)
  {
    if (!count)
      return;
    ptr = qptr->blocks.head;
    first = ptr->data;
    if (count < first->size)
      break;

    qptr->total_size -= first->size;
    count -= first->size;
    dlinkDelete(ptr, &qptr->blocks);
    free_dlink_node(ptr);
    mp_pool_release(first);
  }

  /* ..then remove data from the beginning of the queue */
  first->size -= count;
  qptr->total_size -= count;
  memmove((void *) &first->data, (void *) &first->data[count], first->size);
}

