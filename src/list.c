/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  list.c: Various assorted functions for various structures.
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
#include "tools.h"
#include "client.h"
#include "list.h"
#include "memory.h"
#include "balloc.h"

static BlockHeap *dnode_heap;


/* init_dlink_nodes()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - initializes the dnode BlockHeap
 */
void
init_dlink_nodes(void)
{
  dnode_heap = BlockHeapCreate("dlink node", sizeof(dlink_node), DNODE_HEAP_SIZE);
}

/* make_dlink_node()
 *
 * inputs       - NONE
 * output       - pointer to new dlink_node
 * side effects	- NONE
 */
dlink_node *
make_dlink_node(void)
{
  dlink_node *lp = BlockHeapAlloc(dnode_heap);

  return(lp);
}

/* free_dlink_node()
 *
 * inputs       - pointer to dlink_node
 * output       - NONE
 * side effects	- free given dlink_node 
 */
void
free_dlink_node(dlink_node *ptr)
{
  BlockHeapFree(dnode_heap, ptr);
}
