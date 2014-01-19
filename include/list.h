/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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

/*! \file list.h
 * \brief A header for the list manipulation routines.
 * \version $Id$
 */

#ifndef INCLUDED_list_h
#define INCLUDED_list_h

/* These macros are basically swiped from the linux kernel
 * they are simple yet effective
 */

/*
 * Walks forward of a list.
 * pos is your node
 * head is your list head
 */
#define DLINK_FOREACH(pos, head) for (pos = (head); pos != NULL; pos = pos->next)

/*
 * Walks forward of a list safely while removing nodes
 * pos is your node
 * n is another list head for temporary storage
 * head is your list head
 */
#define DLINK_FOREACH_SAFE(pos, n, head) for (pos = (head), n = pos ? pos->next : NULL; pos != NULL; pos = n, n = pos ? pos->next : NULL)
#define DLINK_FOREACH_PREV(pos, head) for (pos = (head); pos != NULL; pos = pos->prev)

/* Returns the list length */
#define dlink_list_length(list) (list)->length

/*
 * double-linked-list stuff
 */
typedef struct _dlink_node dlink_node;
typedef struct _dlink_list dlink_list;

struct _dlink_node
{
  void *data;
  dlink_node *prev;
  dlink_node *next;
};

struct _dlink_list
{
  dlink_node *head;
  dlink_node *tail;
  unsigned int length;
};

extern void init_dlink_nodes(void);
extern void free_dlink_node(dlink_node *);
extern void dlinkAdd(void *, dlink_node *, dlink_list *);
extern void dlinkAddBefore(dlink_node *, void *, dlink_node *, dlink_list *);
extern void dlinkAddTail(void *, dlink_node *, dlink_list *);
extern void dlinkDelete(dlink_node *, dlink_list *);
extern void dlinkMoveList(dlink_list *, dlink_list *);
extern void dlink_move_node(dlink_node *, dlink_list *, dlink_list *);
extern dlink_node *dlinkFind(dlink_list *, void *);
extern dlink_node *dlinkFindDelete(dlink_list *, void *);
extern dlink_node *make_dlink_node(void);
#endif
