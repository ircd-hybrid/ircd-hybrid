/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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
 * @file list.h
 * @brief Declarations for double-linked list manipulation routines.
 *
 * This file contains declarations for functions and structures used in
 * manipulating double-linked lists. It provides functions for adding,
 * deleting, and moving nodes within the list, as well as functions for
 * finding nodes and retrieving the length of the list.
 */

#ifndef INCLUDED_list_h
#define INCLUDED_list_h

/**
 * @def DLINK_FOREACH
 * @brief Iterates forward through the double-linked list.
 *
 * This macro is used to iterate through a double-linked list in the forward direction.
 *
 * @param pos Node variable for iteration.
 * @param head List head.
 */
#define DLINK_FOREACH(pos, head) for (pos = (head); pos != NULL; pos = pos->next)

/**
 * @def DLINK_FOREACH_SAFE
 * @brief Iterates forward through the double-linked list safely while removing nodes.
 *
 * This macro is used to iterate through a double-linked list in the forward direction
 * while safely removing nodes. It uses a temporary list head for safe removal.
 *
 * @param pos Node variable for iteration.
 * @param n Temporary list head for safe removal.
 * @param head List head.
 */
#define DLINK_FOREACH_SAFE(pos, n, head) for (pos = (head), n = pos ? pos->next : NULL; pos != NULL; pos = n, n = pos ? pos->next : NULL)

/**
 * @def DLINK_FOREACH_PREV
 * @brief Iterates backward through a double-linked list.
 *
 * This macro is used to iterate through a double-linked list in the backward direction.
 *
 * @param pos Node variable for iteration.
 * @param head List head.
 */
#define DLINK_FOREACH_PREV(pos, head) for (pos = (head); pos != NULL; pos = pos->prev)

/**
 * @def dlink_list_length
 * @brief Macro to retrieve the length of the double-linked list.
 *
 * This macro returns the number of nodes in the specified double-linked list.
 *
 * @param list Pointer to the double-linked list.
 */
#define dlink_list_length(list) (list)->length

/**
 * @struct dlink_node
 * @brief Structure representing a node in a double-linked list.
 */
typedef struct _dlink_node
{
  void *data;  /**< Pointer to the data stored in the node. */
  struct _dlink_node *prev;  /**< Pointer to the previous node in the list. */
  struct _dlink_node *next;  /**< Pointer to the next node in the list. */
} dlink_node;

/**
 * @struct dlink_list
 * @brief Structure representing a double-linked list.
 */
typedef struct _dlink_list
{
  dlink_node *head;  /**< Pointer to the head (first node) of the list. */
  dlink_node *tail;  /**< Pointer to the tail (last node) of the list. */
  unsigned int length;  /**< Number of nodes in the list. */
} dlink_list;

extern void free_dlink_node(dlink_node *);
extern void dlinkAdd(void *, dlink_node *, dlink_list *);
extern void dlinkAddAfter(void *, dlink_node *, dlink_node *, dlink_list *);
extern void dlinkAddBefore(dlink_node *, void *, dlink_node *, dlink_list *);
extern void dlinkAddTail(void *, dlink_node *, dlink_list *);
extern void dlinkDelete(dlink_node *, dlink_list *);
extern void dlinkMoveList(dlink_list *, dlink_list *);
extern void dlink_move_node(dlink_node *, dlink_list *, dlink_list *);
extern dlink_node *dlinkFind(dlink_list *, const void *);
extern dlink_node *dlinkFindCmp(const dlink_list *, const void *, int (*)(const char *, const char *));
extern dlink_node *dlinkFindDelete(dlink_list *, void *);
extern dlink_node *make_dlink_node(void);
#endif  /* INCLUDED_list_h */
