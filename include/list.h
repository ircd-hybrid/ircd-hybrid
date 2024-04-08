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
 * @def LIST_FOREACH
 * @brief Iterates forward through the double-linked list.
 *
 * This macro is used to iterate through a double-linked list in the forward direction.
 *
 * @param pos Node variable for iteration.
 * @param head List head.
 */
#define LIST_FOREACH(pos, head) for (pos = (head); pos != NULL; pos = pos->next)

/**
 * @def LIST_FOREACH_SAFE
 * @brief Iterates forward through the double-linked list safely while removing nodes.
 *
 * This macro is used to iterate through a double-linked list in the forward direction
 * while safely removing nodes. It uses a temporary list head for safe removal.
 *
 * @param pos Node variable for iteration.
 * @param n Temporary list head for safe removal.
 * @param head List head.
 */
#define LIST_FOREACH_SAFE(pos, n, head) for (pos = (head), n = pos ? pos->next : NULL; pos != NULL; pos = n, n = pos ? pos->next : NULL)

/**
 * @def LIST_FOREACH_PREV
 * @brief Iterates backward through a double-linked list.
 *
 * This macro is used to iterate through a double-linked list in the backward direction.
 *
 * @param pos Node variable for iteration.
 * @param head List head.
 */
#define LIST_FOREACH_PREV(pos, head) for (pos = (head); pos != NULL; pos = pos->prev)

/**
 * @def list_length
 * @brief Macro to retrieve the length of the double-linked list.
 *
 * This macro returns the number of nodes in the specified double-linked list.
 *
 * @param list Pointer to the double-linked list.
 */
#define list_length(list) (list)->length

/**
 * @struct list_node_t
 * @brief Structure representing a node in a double-linked list.
 */
typedef struct _list_node
{
  void *data;  /**< Pointer to the data stored in the node. */
  struct _list_node *prev;  /**< Pointer to the previous node in the list. */
  struct _list_node *next;  /**< Pointer to the next node in the list. */
} list_node_t;

/**
 * @struct list_t
 * @brief Structure representing a double-linked list.
 */
typedef struct _list
{
  list_node_t *head;  /**< Pointer to the head (first node) of the list. */
  list_node_t *tail;  /**< Pointer to the tail (last node) of the list. */
  unsigned int length;  /**< Number of nodes in the list. */
} list_t;

extern void list_free_node(list_node_t *);
extern void list_add(void *, list_node_t *, list_t *);
extern void list_add_after(void *, list_node_t *, list_node_t *, list_t *);
extern void list_add_before(list_node_t *, void *, list_node_t *, list_t *);
extern void list_add_tail(void *, list_node_t *, list_t *);
extern void list_delete(list_node_t *, list_t *);
extern void list_move_list(list_t *, list_t *);
extern void list_move_node(list_node_t *, list_t *, list_t *);
extern list_node_t *list_find(list_t *, const void *);
extern list_node_t *list_find_cmp(const list_t *, const void *, int (*)(const char *, const char *));
extern list_node_t *list_find_delete(list_t *, void *);
extern list_node_t *list_make_node(void);
#endif  /* INCLUDED_list_h */
