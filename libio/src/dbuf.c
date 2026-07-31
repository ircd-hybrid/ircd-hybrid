/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "dbuf.h"

/**
 * @brief Allocate a new dynamic buffer block.
 *
 * This function allocates memory for a new `dbuf_block` structure and initializes
 * its reference count to 1. The allocated block has a predefined size for storing data.
 *
 * @return A pointer to the newly allocated `dbuf_block` structure.
 */
struct dbuf_block *
dbuf_block_create(void)
{
  struct dbuf_block *const block = io_malloc(sizeof(*block));
  block->ref_count = 1;
  block->length = 0;

  return block;
}

void
dbuf_block_ref(struct dbuf_block *block)
{
  assert(block);
  assert(block->ref_count > 0);

  ++block->ref_count;
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
dbuf_block_unref(struct dbuf_block *block)
{
  assert(block);
  assert(block->ref_count > 0);

  if (--block->ref_count == 0)
    io_free(block);
}


void
dbuf_queue_clear(struct dbuf_queue *queue)
{
  assert(queue);

  list_node_t *node;
  while ((node = list_pop_head(&queue->block_list)))
  {
    struct dbuf_block *const block = node->data;
    assert(block);
    assert(block->ref_count > 0);

    dbuf_block_unref(block);
    list_free_node(node);
  }

  queue->length = 0;
  queue->head_offset = 0;
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
dbuf_queue_append_block(struct dbuf_queue *queue, struct dbuf_block *block)
{
  assert(queue);
  assert(block);
  assert(block->ref_count > 0);
  assert(block->length > 0);
  assert(block->length <= DBUF_BLOCK_CAPACITY);

  dbuf_block_ref(block);

  list_add_tail(block, list_make_node(), &queue->block_list);
  queue->length += block->length;
}

/**
 * @brief Consume data from the head of a dynamic buffer queue.
 *
 * This function removes exactly `length` bytes from the front of the specified
 * `dbuf_queue`. It updates the queue length and head offset, removes fully
 * consumed blocks, and releases their references as needed.
 *
 * @param queue A pointer to the `dbuf_queue` from which data is to be consumed.
 * @param length The number of bytes to consume from the queue.
 */
void
dbuf_queue_consume(struct dbuf_queue *queue, size_t length)
{
  assert(queue);
  assert(length <= queue->length);

  size_t remaining_length = length;
  while (remaining_length > 0)
  {
    list_node_t *const node = queue->block_list.head;
    assert(node);

    struct dbuf_block *const block = node->data;

    assert(block);
    assert(block->ref_count > 0);
    assert(block->length > 0);
    assert(block->length <= DBUF_BLOCK_CAPACITY);
    assert(queue->head_offset < block->length);

    const size_t available_length = block->length - queue->head_offset;
    if (remaining_length < available_length)
    {
      queue->head_offset += remaining_length;
      queue->length -= remaining_length;
      return;
    }

    remaining_length -= available_length;
    queue->length -= available_length;
    queue->head_offset = 0;

    list_node_t *const removed_node = list_pop_head(&queue->block_list);
    assert(removed_node == node);
    assert(removed_node->data == block);

    dbuf_block_unref(block);
    list_free_node(node);
  }
}

bool
dbuf_block_append(struct dbuf_block *block, const void *data, size_t length)
{
  assert(block);
  assert(data || length == 0);
  assert(block->ref_count == 1);
  assert(block->length <= DBUF_BLOCK_CAPACITY);

  if (length == 0)
    return true;

  const size_t available_capacity = DBUF_BLOCK_CAPACITY - block->length;
  if (length > available_capacity)
    return false;

  memcpy(block->data + block->length, data, length);
  block->length += length;

  return true;
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
dbuf_block_append_fmt(struct dbuf_block *block, const char *format, ...)
{
  assert(block->ref_count == 1);

  va_list args;
  va_start(args, format);
  dbuf_block_append_vfmt(block, format, args);
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
 * @param format The format string for the data.
 * @param args A variable argument list containing the data to be formatted.
 */
void
dbuf_block_append_vfmt(struct dbuf_block *block, const char *format, va_list args)
{
  assert(block->ref_count == 1);

  block->length += vsnprintf(block->data + block->length, sizeof(block->data) - block->length, format, args);

  /* As per C99, (v)snprintf returns the length the resulting string would be */
  if (block->length > sizeof(block->data))
    block->length = sizeof(block->data);
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
dbuf_queue_append(struct dbuf_queue *queue, const char *buf, size_t length)
{
  while (length > 0)
  {
    struct dbuf_block *block = dbuf_queue_length(queue) ? queue->block_list.tail->data : NULL;
    if (block == NULL || sizeof(block->data) - block->length == 0)
    {
      block = dbuf_block_create();
      list_add_tail(block, list_make_node(), &queue->block_list);
    }

    size_t avail = sizeof(block->data) - block->length;
    if (avail > length)
      avail = length;

    memcpy(&block->data[block->length], buf, avail);
    block->length += avail;

    queue->length += avail;

    length -= avail;
    buf += avail;
  }
}
