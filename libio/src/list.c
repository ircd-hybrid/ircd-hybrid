/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
 *  Copyright (c) 1996-2023 The Squid Software Foundation and contributors
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
 * @file list.c
 * @brief Maintains doubly-linked lists.
 *
 * This file contains functions for manipulating doubly-linked lists, including
 * creating nodes, adding, deleting, and moving nodes within the list, and finding
 * nodes by data value.
 */

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "list.h"
#include "memory.h"

/**
 * @brief Creates a new double-linked list node.
 *
 * This function allocates memory for a new double-linked list node and returns
 * a pointer to it.
 *
 * @return Pointer to the new double-linked list node.
 */
list_node_t *
list_make_node(void)
{
  list_node_t *node = io_calloc(sizeof(*node));

  return node;
}

/**
 * @brief Frees memory associated with a double-linked list node.
 *
 * This function frees memory associated with the specified double-linked list node.
 *
 * @param node Pointer to the double-linked list node to be freed.
 */
void
list_free_node(list_node_t *node)
{
  io_free(node);
}

/**
 * @brief Checks if a double-linked list is empty.
 *
 * This function checks if the specified double-linked list is empty by
 * examining its head pointer.
 *
 * @param list Pointer to the double-linked list.
 * @return true if the list is empty, false otherwise.
 */
bool
list_is_empty(const list_t *list)
{
  return list->head == NULL;
}

/**
 * @brief Adds a node to the beginning of a double-linked list.
 *
 * This function adds a node containing the specified data to the beginning of
 * the double-linked list.
 *
 * @param data Pointer to the data to be stored in the new node.
 * @param m Pointer to the node to be added.
 * @param list Pointer to the double-linked list.
 */
void
list_add(void *data, list_node_t *m, list_t *list)
{
  m->data = data;
  m->prev = NULL;
  m->next = list->head;

  /* Assumption: If list->tail != NULL, list->head != NULL */
  if (list->head)
    list->head->prev = m;
  else if (list->tail == NULL)
    list->tail = m;

  list->head = m;
  list->length++;
}

/**
 * @brief Adds a node after a specified node in a double-linked list.
 *
 * This function adds a node containing the specified data after the specified
 * node in the double-linked list.
 *
 * @param data Pointer to the data to be stored in the new node.
 * @param m Pointer to the node to be added after.
 * @param n Pointer to the node after which the new node will be added.
 * @param list Pointer to the double-linked list.
 */
void
list_add_after(void *data, list_node_t *m, list_node_t *n, list_t *list)
{
  m->data = data;
  m->prev = n;
  m->next = n->next;

  if (n->next)
    n->next->prev = m;
  else
  {
    assert(list->tail == n);
    list->tail = m;
  }

  n->next = m;
  list->length++;
}

/**
 * @brief Adds a node before a specified node in a double-linked list.
 *
 * This function adds a node containing the specified data before the specified
 * node in the double-linked list.
 *
 * @param b Pointer to the node before which the new node will be added.
 * @param data Pointer to the data to be stored in the new node.
 * @param m Pointer to the node to be added.
 * @param list Pointer to the double-linked list.
 */
void
list_add_before(list_node_t *b, void *data, list_node_t *m, list_t *list)
{
  /* Shortcut - if it's the first one, call list_add only */
  if (b == list->head)
    list_add(data, m, list);
  else
  {
    m->data = data;
    b->prev->next = m;
    m->prev = b->prev;
    b->prev = m;
    m->next = b;
    list->length++;
  }
}

/**
 * @brief Adds a node to the end of a double-linked list.
 *
 * This function adds a node containing the specified data to the end of the
 * double-linked list.
 *
 * @param data Pointer to the data to be stored in the new node.
 * @param m Pointer to the node to be added.
 * @param list Pointer to the double-linked list.
 */
void
list_add_tail(void *data, list_node_t *m, list_t *list)
{
  m->data = data;
  m->next = NULL;
  m->prev = list->tail;

  /* Assumption: If list->tail != NULL, list->head != NULL */
  if (list->tail)
    list->tail->next = m;
  else if (list->head == NULL)
    list->head = m;

  list->tail = m;
  list->length++;
}

/**
 * @brief Adds a node to the double-linked list in sorted order.
 *
 * This function adds a node containing the specified data to the double-linked list
 * in a position that maintains the list in sorted order. The comparison function `cmp`
 * determines the order.
 *
 * @param data Pointer to the data to be stored in the new node.
 * @param m Pointer to the node to be added.
 * @param list Pointer to the double-linked list.
 * @param cmp Function pointer to the comparison function.
 */
void
list_add_sorted(void *data, list_node_t *m, list_t *list, int (*cmp)(const void *, const void *))
{
  /* If the list is empty, simply add the node to the list. */
  if (list_is_empty(list))
  {
    list_add(data, m, list);
    return;
  }

  /* Iterate through the list to find the appropriate position. */
  list_node_t *current = list->head;
  while (current && cmp(current->data, data) < 0)
    current = current->next;

  /* If we've reached the end of the list, add to the tail. */
  if (current == NULL)
    list_add_tail(data, m, list);
  else if (current == list->head)
    /* If the new node should be the new head. */
    list_add(data, m, list);
  else
    /* Add the new node before the current node. */
    list_add_before(current, data, m, list);
}

/**
 * @brief Deletes a node from a double-linked list.
 *
 * This function deletes the specified node from the double-linked list.
 *
 * @param m Pointer to the node to be deleted.
 * @param list Pointer to the double-linked list.
 */
void
list_remove(list_node_t *m, list_t *list)
{
  assert(list->length > 0);

  /* Assumption: If m->next == NULL, then list->tail == m
   *      and:   If m->prev == NULL, then list->head == m
   */
  if (m->next)
    m->next->prev = m->prev;
  else
  {
    assert(list->tail == m);
    list->tail = m->prev;
  }

  if (m->prev)
    m->prev->next = m->next;
  else
  {
    assert(list->head == m);
    list->head = m->next;
  }

  /* Set this to NULL does matter */
  m->next = NULL;
  m->prev = NULL;

  list->length--;
}

/**
 * @brief Finds a node with a specific data value in a double-linked list.
 *
 * This function searches for a node with the specified data value in the
 * double-linked list and returns a pointer to it.
 *
 * @param list Pointer to the double-linked list.
 * @param data Pointer to the data value to search for.
 * @return Pointer to the node with the specified data value, or NULL if not found.
 */
list_node_t *
list_find(list_t *list, const void *data)
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
    if (node->data == data)
      return node;

  return NULL;
}

/**
 * @brief Finds a node with a specific data value using a custom comparison function.
 *
 * This function searches for a node with the specified data value in the double-linked list
 * using a custom comparison function.
 *
 * @param list Pointer to the double-linked list.
 * @param data Pointer to the data value to search for.
 * @param cmp Function pointer to the comparison function.
 * @return Pointer to the node with the specified data value, or NULL if not found.
 */
list_node_t *
list_find_cmp(const list_t *list, const void *data, int (*cmp)(const char *, const char *))
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
    if (cmp(node->data, data) == 0)
      return node;

  return NULL;
}

/**
 * @brief Moves the contents of one double-linked list to another.
 *
 * This function moves the contents of the specified source double-linked list
 * to the destination double-linked list.
 *
 * @param from Pointer to the source double-linked list.
 * @param to Pointer to the destination double-linked list.
 */
void
list_move_list(list_t *from, list_t *to)
{
  /* There are three cases */
  /* case one, nothing in from list */
  if (from->head == NULL)
    return;

  /* case two, nothing in to list */
  /* actually if to->head is NULL and to->tail isn't, that's a bug */
  if (to->head == NULL)
  {
    to->head = from->head;
    to->tail = from->tail;
    from->head = from->tail = NULL;
    to->length = from->length;
    from->length = 0;
    return;
  }

  /* third case play with the links */
  from->tail->next = to->head;
  from->head->prev = to->head->prev;
  to->head->prev = from->tail;
  to->head = from->head;
  from->head = from->tail = NULL;
  to->length += from->length;
  from->length = 0;
  /* I think I got that right */
}

/**
 * @brief Moves a node from one double-linked list to another.
 *
 * This function moves the specified node from one double-linked list to another.
 *
 * @param m Pointer to the node to be moved.
 * @param list_del Pointer to the source double-linked list.
 * @param list_add Pointer to the destination double-linked list.
 */
void
list_move_node(list_node_t *m, list_t *list_del, list_t *list_add)
{
  /* Assumption: If m->next == NULL, then list_del->tail == m
   *      and:   If m->prev == NULL, then list_del->head == m
   */
  if (m->next)
    m->next->prev = m->prev;
  else
  {
    assert(list_del->tail == m);
    list_del->tail = m->prev;
  }

  if (m->prev)
    m->prev->next = m->next;
  else
  {
    assert(list_del->head == m);
    list_del->head = m->next;
  }

  /* Set this to NULL does matter */
  m->prev = NULL;
  m->next = list_add->head;

  /* Assumption: If list_add->tail != NULL, list_add->head != NULL */
  if (list_add->head)
    list_add->head->prev = m;
  else if (list_add->tail == NULL)
    list_add->tail = m;

  list_add->head = m;
  list_add->length++;
  list_del->length--;
}

/**
 * @brief Iterates over each node in the list and calls a callback function for each node.
 *
 * This function iterates over each node in the provided list and calls the specified
 * callback function for each node, passing the data of the current node and the user-defined
 * data pointer to the callback function.
 *
 * @param list Pointer to the double-linked list to iterate over.
 * @param callback Pointer to the callback function to be called for each node.
 * @param user_ptr Pointer to user-defined data that can be passed to the callback function.
 */
void
list_iterate(list_t *list, list_iterate_callback callback, void *user_ptr)
{
  list_node_t *node = list->head;

  while (node)
  {
    callback(node->data, user_ptr);
    node = node->next;
  }
}

/**
 * @brief Iterates over each node in the list and calls a callback function for each node safely.
 *
 * This function iterates over each node in the provided list and calls the specified
 * callback function for each node, passing the data of the current node and the user-defined
 * data pointer to the callback function. It allows the callback function to safely remove
 * entries from the list without causing issues with the iteration.
 *
 * @param list Pointer to the double-linked list to iterate over.
 * @param callback Pointer to the callback function to be called for each node.
 * @param user_ptr Pointer to user-defined data that can be passed to the callback function.
 */
void
list_iterate_safe(list_t *list, list_iterate_callback callback, void *user_ptr)
{
  list_node_t *node = list->head;

  while (node)
  {
    list_node_t *node_next = node->next;
    callback(node->data, user_ptr);

    node = node_next;
  }
}

/**
 * @brief Finds and deletes a node with a specific data value in a double-linked list.
 *
 * This function searches for a node with the specified data value in the
 * double-linked list, deletes it, and returns a pointer to it.
 *
 * @param list Pointer to the double-linked list.
 * @param data Pointer to the data value to search for and delete.
 * @return Pointer to the deleted node, or NULL if not found.
 */
list_node_t *
list_find_remove(list_t *list, void *data)
{
  list_node_t *m;

  LIST_FOREACH(m, list->head)
  {
    if (m->data == data)
    {
      list_remove(m, list);
      return m;
    }
  }

  return NULL;
}

/**
 * @brief Adds a node at a specific position in a double-linked list.
 *
 * This function adds a node containing the specified data at the specified
 * position in the double-linked list.
 *
 * @param data Pointer to the data to be stored in the new node.
 * @param pos Position at which to add the new node (0-based index).
 * @param m Pointer to the node to be added.
 * @param list Pointer to the double-linked list.
 * @return true if the node was added successfully, false if the position is invalid.
 */
bool
list_add_at(void *data, unsigned int pos, list_node_t *m, list_t *list)
{
  if (pos > list->length)
    return false;

  if (pos == 0)
    list_add(data, m, list);
  else if (pos == list->length)
    list_add_tail(data, m, list);
  else
  {
    list_node_t *current = list->head;
    for (unsigned int i = 0; i < pos; ++i)
      current = current->next;

    list_add_before(current, data, m, list);
  }

  return true;
}

/**
 * @brief Removes a node at a specific position in a double-linked list.
 *
 * This function removes a node at the specified position in the double-linked list
 * and frees the memory associated with it.
 *
 * @param pos Position of the node to be removed (0-based index).
 * @param list Pointer to the double-linked list.
 * @return Pointer to the data of the removed node, or NULL if the position is invalid.
 */
void *
list_remove_at(unsigned int pos, list_t *list)
{
  if (pos >= list->length)
    return NULL;

  list_node_t *current = list->head;
  for (unsigned int i = 0; i < pos; ++i)
    current = current->next;

  void *data = current->data;
  list_remove(current, list);
  list_free_node(current);

  return data;
}

/**
 * @brief Retrieves a node at a specific position in a double-linked list.
 *
 * This function retrieves the node at the specified position in the double-linked list.
 *
 * @param pos Position of the node to be retrieved (0-based index).
 * @param list Pointer to the double-linked list.
 * @return Pointer to the node at the specified position, or NULL if the position is invalid.
 */
list_node_t *
list_get_at(unsigned int pos, const list_t *list)
{
  if (pos >= list->length)
    return NULL;

  list_node_t *current = list->head;
  for (unsigned int i = 0; i < pos; ++i)
    current = current->next;

  return current;
}

/**
 * @brief Returns the longer of two lists.
 *
 * This function compares the lengths of two lists and returns the longer list.
 * If the lengths are equal, it returns the first list.
 *
 * @param list1 Pointer to the first list.
 * @param list2 Pointer to the second list.
 * @return Pointer to the longer list.
 */
list_t *
list_get_longer(list_t *list1, list_t *list2)
{
  if (list1->length >= list2->length)
    return list1;

  return list2;
}

/**
 * @brief Returns the shorter of two lists.
 *
 * This function compares the lengths of two lists and returns the shorter list.
 * If the lengths are equal, it returns the first list.
 *
 * @param list1 Pointer to the first list.
 * @param list2 Pointer to the second list.
 * @return Pointer to the shorter list.
 */
list_t *
list_get_shorter(list_t *list1, list_t *list2)
{
  if (list1->length <= list2->length)
    return list1;

  return list2;
}
