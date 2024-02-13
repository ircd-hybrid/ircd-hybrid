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

#include "stdinc.h"
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
dlink_node *
make_dlink_node(void)
{
  dlink_node *node = xcalloc(sizeof(*node));

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
free_dlink_node(dlink_node *node)
{
  xfree(node);
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
dlinkAdd(void *data, dlink_node *m, dlink_list *list)
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
dlinkAddBefore(dlink_node *b, void *data, dlink_node *m, dlink_list *list)
{
  /* Shortcut - if it's the first one, call dlinkAdd only */
  if (b == list->head)
    dlinkAdd(data, m, list);
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
dlinkAddTail(void *data, dlink_node *m, dlink_list *list)
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
 * @brief Deletes a node from a double-linked list.
 *
 * This function deletes the specified node from the double-linked list.
 *
 * @param m Pointer to the node to be deleted.
 * @param list Pointer to the double-linked list.
 */
void
dlinkDelete(dlink_node *m, dlink_list *list)
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
dlink_node *
dlinkFind(dlink_list *list, const void *data)
{
  dlink_node *node;

  DLINK_FOREACH(node, list->head)
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
dlink_node *
dlinkFindCmp(const dlink_list *list, const void *data, int (*cmp)(const char *, const char *))
{
  dlink_node *node;

  DLINK_FOREACH(node, list->head)
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
dlinkMoveList(dlink_list *from, dlink_list *to)
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
dlink_move_node(dlink_node *m, dlink_list *list_del, dlink_list *list_add)
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
 * @brief Finds and deletes a node with a specific data value in a double-linked list.
 *
 * This function searches for a node with the specified data value in the
 * double-linked list, deletes it, and returns a pointer to it.
 *
 * @param list Pointer to the double-linked list.
 * @param data Pointer to the data value to search for and delete.
 * @return Pointer to the deleted node, or NULL if not found.
 */
dlink_node *
dlinkFindDelete(dlink_list *list, void *data)
{
  dlink_node *m;

  DLINK_FOREACH(m, list->head)
  {
    if (m->data == data)
    {
      dlinkDelete(m, list);
      return m;
    }
  }

  return NULL;
}
