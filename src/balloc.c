/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *  Original credit lines follow:
 *
 *  File:   balloc.c
 *  Owner:  Wohali (Joan Touzet)
 *  
 *  Modified 2001/11/29 for mmap() support by Aaron Sethman <androsyn@ratbox.org>
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

/*! \file balloc.c
 * \brief A block allocator
 * \version $Id$
 * 
 * About the block allocator
 *
 * Basically we have three ways of getting memory off of the operating
 * system. Below are this list of methods and the order of preference.
 *
 * 1. mmap() anonymous pages with the MMAP_ANON flag.\n
 * 2. mmap() via the /dev/zero trick.\n
 * 3. malloc()\n
 *
 * The advantages of 1 and 2 are this.  We can munmap() the pages which will
 * return the pages back to the operating system, thus reducing the size 
 * of the process as the memory is unused.  malloc() on many systems just keeps
 * a heap of memory to itself, which never gets given back to the OS, except on
 * exit.  This of course is bad, if say we have an event that causes us to allocate
 * say, 200MB of memory, while our normal memory consumption would be 15MB.  In the
 * malloc() case, the amount of memory allocated to our process never goes down, as
 * malloc() has it locked up in its heap.  With the mmap() method, we can munmap()
 * the block and return it back to the OS, thus causing our memory consumption to go
 * down after we no longer need it.
 */


#include "stdinc.h"
#ifdef HAVE_MMAP /* We've got mmap() that is good */
#include <sys/mman.h>

/* HP-UX sucks */
#ifdef MAP_ANONYMOUS
#ifndef MAP_ANON
#define MAP_ANON MAP_ANONYMOUS
#endif
#endif /* MAP_ANONYMOUS */
#endif

#include "list.h"
#include "balloc.h"
#include "memory.h"
#include "irc_string.h"
#include "client.h"
#include "send.h"
#include "numeric.h"
#include "fdlist.h"
#include "event.h"


static BlockHeap *heap_list = NULL;

static int BlockHeapGarbageCollect(BlockHeap *);
static void heap_garbage_collection(void *);

/*! \brief Returns memory for the block back to either the malloc heap
 *         in case of !HAVE_MMAP, or back to the OS otherwise.
 * \param ptr  Pointer to memory to be freed
 * \param size The size of the memory space
 */
static void
free_block(void *ptr, size_t size)
{
#ifdef HAVE_MMAP
  munmap(ptr, size);
#else
  free(ptr);
#endif
}

#ifdef HAVE_MMAP
#ifndef MAP_ANON /* But we cannot mmap() anonymous pages */
		 /* So we mmap() /dev/zero, which is just as good */
static fde_t dpfd;
#endif
#endif

/*! \brief Opens /dev/zero and saves the file handle for
 * future allocations.
 */
void
initBlockHeap(void)
{
#ifdef HAVE_MMAP
#ifndef MAP_ANON
  int zero_fd = open("/dev/zero", O_RDWR);

  if (zero_fd < 0)
    outofmemory();
  fd_open(&dpfd, zero_fd, 0, "Anonymous mmap()");
#endif
  eventAdd("heap_garbage_collection", &heap_garbage_collection, NULL, 119);
#endif
}

/*!
 * \param size Size of block to allocate
 * \return Address pointer to allocated data space
 */
static void *
get_block(size_t size)
{
#ifdef HAVE_MMAP
  void *ptr = NULL;

#ifndef MAP_ANON
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, dpfd.fd, 0);
#else
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
#endif
  return ptr == MAP_FAILED ? NULL : ptr;
#else
  return malloc(size);
#endif
}

static void
heap_garbage_collection(void *arg)
{
  BlockHeap *bh;

  for (bh = heap_list; bh != NULL; bh = bh->next)
    BlockHeapGarbageCollect(bh);
}

/*! \brief Allocates a new block for addition to a blockheap
 * \param bh Pointer to parent blockheap
 * \return 0 if successful, 1 if not
 */
static int
newblock(BlockHeap *bh)
{
  MemBlock *newblk = NULL;
  Block *b = NULL;
  int i = 0;
  void *offset = NULL;

  /* Setup the initial data structure. */
  if ((b = calloc(1, sizeof(Block))) == NULL)
    return 1;

  b->freeElems = bh->elemsPerBlock;
  b->next = bh->base;
  b->alloc_size = bh->elemsPerBlock * (bh->elemSize + sizeof(MemBlock));
  b->elems = get_block(b->alloc_size);

  if (b->elems == NULL)
    return 1;

  offset = b->elems;

  /* Setup our blocks now */
  for (; i < bh->elemsPerBlock; ++i)
  {
    void *data;

    newblk = offset;
    newblk->block = b;
    data = (void *)((size_t)offset + sizeof(MemBlock));

    dlinkAdd(data, &newblk->self, &b->free_list);
    offset = (void *)((size_t)offset + bh->elemSize + sizeof(MemBlock));
  }

  ++bh->blocksAllocated;
  bh->freeElems += bh->elemsPerBlock;
  bh->base = b;

  return 0;
}

/*! \brief Creates a new blockheap
 *
 * Creates a new blockheap from which smaller blocks can be allocated.
 * Intended to be used instead of multiple calls to malloc() when
 * performance is an issue.
 *
 * \param name          Name of the blockheap
 * \param elemsize      Size of the basic element to be stored
 * \param elemsperblock Number of elements to be stored in a single block of
 *                      memory.  When the blockheap runs out of free memory,
 *                      it will allocate elemsize * elemsperblock more.
 * \return Pointer to new BlockHeap, or NULL if unsuccessful
 */
BlockHeap *
BlockHeapCreate(const char *const name, size_t elemsize, int elemsperblock)
{
  BlockHeap *bh = NULL;
  assert(elemsize > 0 && elemsperblock > 0);

  /* Catch idiotic requests up front */
  if ((elemsize <= 0) || (elemsperblock <= 0))
    outofmemory();    /* die.. out of memory */

  /* Allocate our new BlockHeap */
  if ((bh = calloc(1, sizeof(BlockHeap))) == NULL)
    outofmemory();    /* die.. out of memory */

  if ((elemsize % sizeof(void *)) != 0)
  {
    /* Pad to even pointer boundary */
    elemsize += sizeof(void *);
    elemsize &= ~(sizeof(void *) - 1);
  }

  bh->name = name;
  bh->elemSize = elemsize;
  bh->elemsPerBlock = elemsperblock;

  /* Be sure our malloc was successful */
  if (newblock(bh))
  {
    if (bh != NULL)
      free(bh);

     outofmemory();    /* die.. out of memory */
  }

  bh->next = heap_list;
  heap_list = bh;

  return bh;
}

/*! \brief Returns a pointer to a struct within our BlockHeap that's free for
 *         the taking.
 * \param bh Pointer to the Blockheap
 * \return Address pointer to allocated data space, or NULL if unsuccessful
 */
void *
BlockHeapAlloc(BlockHeap *bh)
{
  Block *walker = NULL;
  dlink_node *new_node = NULL;

  assert(bh != NULL);

  if (bh->freeElems == 0)
  {   
    /* Allocate new block and assign */
    /* newblock returns 1 if unsuccessful, 0 if not */
    if (newblock(bh))
    {
      /* That didn't work..try to garbage collect */
      BlockHeapGarbageCollect(bh);  

      if (newblock(bh))
        outofmemory(); /* Well that didn't work either...bail */
    }
  }
      
  for (walker = bh->base; walker != NULL; walker = walker->next)
  {
    if (walker->freeElems > 0)
    {
      --bh->freeElems;
      --walker->freeElems;
      new_node = walker->free_list.head;

      dlinkDelete(new_node, &walker->free_list);
      assert(new_node->data != NULL);

      memset(new_node->data, 0, bh->elemSize);
      return new_node->data;
    }
  }

  assert(0 == 1);
  outofmemory();
  return NULL;
}

/*! \brief Returns an element to the free pool, does not free()
 * \param bh  Pointer to BlockHeap containing element
 * \param ptr Pointer to element to be "freed"
 * \return 0 if successful, 1 if element not contained within BlockHeap
 */
int
BlockHeapFree(BlockHeap *bh, void *ptr)
{
  Block *block = NULL;
  struct MemBlock *memblock = NULL;
    
  assert(bh != NULL);
  assert(ptr != NULL);

  memblock = (void *)((size_t)ptr - sizeof(MemBlock));
  assert(memblock->block != NULL);

  if (memblock->block == NULL)
    outofmemory();

  block = memblock->block;
  ++bh->freeElems;
  ++block->freeElems;
  mem_frob(ptr, bh->elemSize);

  dlinkAdd(ptr, &memblock->self, &block->free_list);
  return 0;
}

/*! \brief Performs garbage collection on the block heap.
 *
 * Performs garbage collection on the block heap.  Any blocks that are
 * completely unallocated are removed from the heap.  Garbage collection
 * will \b never remove the root node of the heap.
 *
 * \param bh Pointer to the BlockHeap to be cleaned up
 * \return 0 if successful, 1 if bh == NULL
 */
static int
BlockHeapGarbageCollect(BlockHeap *bh)
{
  Block *walker = NULL, *last = NULL;

  assert(bh != NULL);

  if (bh->freeElems < bh->elemsPerBlock || bh->blocksAllocated == 1)
  {
    /* There couldn't possibly be an entire free block.  Return. */
    return 0;
  }

  walker = bh->base;

  while (walker != NULL)
  {
    if (walker->freeElems == bh->elemsPerBlock)
    {
      free_block(walker->elems, walker->alloc_size);

      if (last != NULL)
      {
        last->next = walker->next;

        if (walker != NULL)
          free(walker);
        walker = last->next;
      }
      else
      {
        bh->base = walker->next;

        if (walker != NULL)
          free(walker);
        walker = bh->base;
      }

      --bh->blocksAllocated;
      bh->freeElems -= bh->elemsPerBlock;
    }
    else
    {
      last = walker;
      walker = walker->next;
    }
  }

  return 0;
}

/*! \brief Completely free()s a BlockHeap.  Use for cleanup.
 * \param bh Pointer to the BlockHeap to be destroyed
 * \return 0 if successful, 1 if bh == NULL
 */
int
BlockHeapDestroy(BlockHeap *bh)
{
  Block *walker = NULL, *next = NULL;

  if (bh == NULL)
    return 1;

  for (walker = bh->base; walker != NULL; walker = next)
  {
    next = walker->next;
    free_block(walker->elems, walker->alloc_size);

    if (walker != NULL)
      free(walker);
  }

  if (heap_list == bh)
    heap_list = bh->next;
  else {
    BlockHeap *prev;

    for (prev = heap_list; prev->next != bh; prev = prev->next)
      /* nothing */ ;
    prev->next = bh->next;
  }

  free(bh);
  return 0;
}

/*! \brief Returns the number of bytes being used
 * \param bh Pointer to a BlockHeap
 * \return Number of bytes being used
 */
static size_t
block_heap_get_used_mem(const BlockHeap *const bh)
{
  return(((bh->blocksAllocated *
           bh->elemsPerBlock)-bh->freeElems) *
          (bh->elemSize + sizeof(MemBlock)));
}

/*! \brief Returns the number of bytes being free for further allocations
 * \param bh Pointer to a BlockHeap
 * \return Number of bytes being free for further allocations
 */
static size_t
block_heap_get_free_mem(const BlockHeap *const bh)
{
  return(bh->freeElems * (bh->elemSize + sizeof(MemBlock)));
}

/*! \brief Returns the total number of bytes of memory belonging to a heap
 * \param bh Pointer to a BlockHeap
 * \return Total number of bytes of memory belonging to a heap
 */
static size_t
block_heap_get_size_mem(const BlockHeap *const bh)
{
  return(((bh->blocksAllocated *
           bh->elemsPerBlock)) *
          (bh->elemSize + sizeof(MemBlock)));
}

/*! \brief Returns the number of elements being used.
 * \param bh Pointer to a BlockHeap
 * \return Number of elements being free for further allocations
 */
static unsigned int
block_heap_get_used_elm(const BlockHeap *const bh)
{
  return((bh->blocksAllocated *
          bh->elemsPerBlock)-bh->freeElems);
}

/*! \brief Returns the number of elements being free for further allocations.
 * \param bh Pointer to a BlockHeap
 * \return Number of elements being free for further allocations
 */
static unsigned int
block_heap_get_free_elm(const BlockHeap *const bh)
{
  return(bh->freeElems);
}

/*! \brief Returns the number of total elements belonging to a heap.
 *         Includes \b free and \b used elements.
 * \param bh Pointer to a BlockHeap
 * \return Number of total elements belonging to a heap
 */
static unsigned int
block_heap_get_size_elm(const BlockHeap *const bh)
{
  return(bh->blocksAllocated * bh->elemsPerBlock);
}

void
block_heap_report_stats(struct Client *client_p)
{
  const BlockHeap *bh = NULL;

  for (bh = heap_list; bh != NULL; bh = bh->next)
    sendto_one(client_p, ":%s %d %s z :%s mempool: used %u/%u free %u/%u (size %u/%u)",
               me.name, RPL_STATSDEBUG, client_p->name, bh->name,
               block_heap_get_used_elm(bh),
               block_heap_get_used_mem(bh),
               block_heap_get_free_elm(bh),
               block_heap_get_free_mem(bh),
               block_heap_get_size_elm(bh),
               block_heap_get_size_mem(bh));
}
