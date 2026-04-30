/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2026 ircd-hybrid development team
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

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "list.h"
#include "memory.h"

/**
 * @brief Initializes a list structure to a safe, empty state.
 *
 * This function prepares a `list_t` structure for use by setting its head and
 * tail pointers to NULL and its length to 0.
 *
 * @param list Pointer to the list to initialize.
 */
void
list_init(list_t *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
}

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
  assert(node->prev == NULL);
  assert(node->next == NULL);

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
 * @param node Pointer to the node to be added.
 * @param list Pointer to the double-linked list.
 */
void
list_add(void *data, list_node_t *node, list_t *list)
{
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert((list->head == NULL) == (list->tail == NULL));

  node->data = data;
  node->next = list->head;

  if (list->head)
    list->head->prev = node;
  else
    list->tail = node;

  list->head = node;
  list->length++;
}

/**
 * @brief Adds a node to the end (tail) of a list.
 *
 * This function links the given node at the end of the list and associates
 * it with the provided data pointer. The list's tail and length are
 * correctly updated. This is an O(1) operation.
 *
 * @param data The application-specific data pointer to store in the node.
 * @param node The node to add. Must be a fresh, unlinked node.
 * @param list The list to which the node will be added.
 */
void
list_add_tail(void *data, list_node_t *node, list_t *list)
{
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert((list->head == NULL) == (list->tail == NULL));

  node->data = data;
  node->prev = list->tail;

  if (list->tail)
    list->tail->next = node;
  else
    list->head = node;

  list->tail = node;
  list->length++;
}

/**
 * @brief Adds a node after a specified reference node in a list.
 *
 * This function links the given `node` immediately after the `ref_node` and
 * associates it with the provided `data` pointer. The list's tail and length
 * are correctly updated if necessary. This is an O(1) operation.
 *
 * @param data The application-specific data pointer to store in the node.
 * @param node The node to add. Must be unlinked.
 * @param ref_node The node already in the list after which to insert.
 * @param list The list being operated on.
 */
void
list_add_after(void *data, list_node_t *node, list_node_t *ref_node, list_t *list)
{
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert(ref_node->prev || ref_node->next || list->head == ref_node);
  assert((list->head == NULL) == (list->tail == NULL));

  node->data = data;
  node->next = ref_node->next;
  node->prev = ref_node;

  if (ref_node->next)
    ref_node->next->prev = node;
  else
  {
    assert(list->tail == ref_node);
    list->tail = node;
  }

  ref_node->next = node;

  list->length++;
}

/**
 * @brief Adds a node before a specified reference node in a list.
 *
 * This function links the given `node` immediately before the `ref_node` and
 * associates it with the provided `data` pointer. The list's head and length
 * are correctly updated if necessary. This is an O(1) operation.
 *
 * @param data The application-specific data pointer to store in the node.
 * @param node The node to add. Must be unlinked.
 * @param ref_node The node already in the list before which to insert.
 * @param list The list being operated on.
 */
void
list_add_before(void *data, list_node_t *node, list_node_t *ref_node, list_t *list)
{
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert(ref_node->prev || ref_node->next || list->head == ref_node);
  assert((list->head == NULL) == (list->tail == NULL));

  node->data = data;
  node->next = ref_node;
  node->prev = ref_node->prev;

  if (ref_node->prev)
    ref_node->prev->next = node;
  else
  {
    assert(list->head == ref_node);
    list->head = node;
  }

  ref_node->prev = node;

  list->length++;
}

/**
 * @brief Adds a node to a list while maintaining sorted order.
 *
 * This function finds the correct position for the new node in the list
 * based on the provided comparison function `cmp`, and inserts it there. The
 * list is assumed to be already sorted according to the same comparison logic.
 * This is an O(n) operation due to the linear scan required to find the
 * insertion point.
 *
 * @param data The application-specific data pointer to store in the node.
 * @param node The node to add. Must be a fresh, unlinked node.
 * @param list The sorted list to which the node will be added.
 * @param cmp The comparison function. It should return < 0 if a < b, 0 if a == b,
 *            and > 0 if a > b.
 */
void
list_add_sorted(void *data, list_node_t *node, list_t *list, int (*cmp)(const void *, const void *))
{
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert((list->head == NULL) == (list->tail == NULL));

  /* If the list is empty, simply add the node to the list. */
  if (list_is_empty(list))
  {
    list_add(data, node, list);
    return;
  }

  /*
   * Find the insertion point. We are looking for the first node in the list
   * that is "greater than or equal to" the new node's data.
   */
  list_node_t *insertion_point = list->head;
  while (insertion_point && cmp(insertion_point->data, data) < 0)
    insertion_point = insertion_point->next;

  /* Perform the insertion based on the found insertion point. */
  if (insertion_point == NULL)
    /* We traversed the entire list, so the new node is the largest. */
    list_add_tail(data, node, list);
  else
    /*
     * We found the correct spot. The list_add_before function correctly
     * handles all cases, including insertion at the head of the list.
     */
    list_add_before(data, node, insertion_point, list);
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
list_remove(list_node_t *node, list_t *list)
{
  assert(node->prev || list->head == node);
  assert(node->next || list->tail == node);

  if (node->prev)
    node->prev->next = node->next;
  else
  {
    assert(list->head == node);
    list->head = node->next;
  }

  if (node->next)
    node->next->prev = node->prev;
  else
  {
    assert(list->tail == node);
    list->tail = node->prev;
  }

  assert(list->length > 0);
  list->length--;

  node->prev = NULL;
  node->next = NULL;
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
  list_node_t *node = list_find(list, data);
  if (node)
    list_remove(node, list);

  return node;
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
 * @brief Appends all nodes from a source list to the end of a destination list.
 *
 * This function moves all nodes from the `src_list` list to the end of the `dest_list`
 * list in a single, efficient O(1) operation. The pointers of the lists are
 * relinked, and the `src_list` list is re-initialized to an empty state, as its
 * nodes are now owned by the `dest_list` list.
 *
 * @param dest_list The list to which nodes will be appended.
 * @param src_list The list from which nodes will be moved.
 */
void
list_concat(list_t *dest_list, list_t *src_list)
{
  assert(dest_list != src_list);

  /* If the lists are the same, or the source is empty, there is nothing to do. */
  if (dest_list == src_list || list_is_empty(src_list))
    return;

  if (list_is_empty(dest_list))
  {
    /* If destination is empty, it simply becomes the source list. */
    dest_list->head = src_list->head;
    dest_list->tail = src_list->tail;
    dest_list->length = src_list->length;
  }
  else
  {
    /* Append the source list to the tail of the destination list. */
    dest_list->tail->next = src_list->head;
    src_list->head->prev = dest_list->tail;
    dest_list->tail = src_list->tail;
    dest_list->length += src_list->length;
  }

  /* The source list is now conceptually empty. Re-initialize it. */
  list_init(src_list);
}

/**
 * @brief Moves a node from one double-linked list to another.
 *
 * This function moves the specified node from one double-linked list to another.
 *
 * @param node The node to move.
 * @param dest_list The list to add the node to.
 * @param src_list The list to remove the node from.
 */
void
list_move_node(list_node_t *node, list_t *dest_list, list_t *src_list)
{
  assert(src_list->length > 0);

  if (src_list == dest_list)
    return;

  list_remove(node, src_list);
  list_add(node->data, node, dest_list);
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
 * @brief Adds a node at a specific position (index) in a list.
 *
 * This function inserts the given node at the zero-based `pos`. To be
 * efficient, it traverses from the head or the tail, whichever is closer.
 * This is an O(n) operation due to the linear scan required to find the
 * insertion point in the worst case.
 *
 * @param list The list to which the node will be added.
 * @param pos The zero-based index at which to insert the node. Must be <= list->length.
 * @param data The application-specific data pointer to store in the node.
 * @param node The node to add. Must be a fresh, unlinked node.
 * @return true on success, false if `pos` is out of bounds.
 */
bool
list_add_at(list_t *list, unsigned int pos, void *data, list_node_t *node)
{
  assert(node->prev == NULL);
  assert(node->next == NULL);
  assert((list->head == NULL) == (list->tail == NULL));
  assert(pos <= list->length);

  /* Check for out-of-bounds position. */
  if (pos > list->length)
    return false;

  /* Handle simple, O(1) edge cases first. */
  if (pos == 0)
    list_add(data, node, list);
  else if (pos == list->length)
    list_add_tail(data, node, list);
  else
  {
    /*
     * For insertion in the middle, find the reference node to insert before.
     * This is optimized by traversing from the closest end of the list.
     */
    list_node_t *ref_node;
    if (pos < (list->length / 2))
    {
      /* Position is in the first half, traverse from the head. */
      ref_node = list->head;
      for (unsigned int i = 0; i < pos; ++i)
        ref_node = ref_node->next;
    }
    else
    {
      /* Position is in the second half, traverse backwards from the tail. */
      ref_node = list->tail;
      for (unsigned int i = list->length - 1; i > pos; --i)
        ref_node = ref_node->prev;
    }

    list_add_before(data, node, ref_node, list);
  }

  return true;
}

/**
 * @brief Removes and returns the node from a specific position (index) in a list.
 *
 * This function finds and unlinks the node at the zero-based `pos`. To be
 * efficient, it traverses from the head or the tail, whichever is closer.
 * This is an O(n) operation due to the linear scan required to find the
 * node in the worst case.
 *
 * @param list The list from which to remove the node.
 * @param pos The zero--based index of the node to remove. Must be < list->length.
 * @return A pointer to the unlinked node, or NULL if `pos` is out of bounds.
 */
list_node_t *
list_remove_at(list_t *list, unsigned int pos)
{
  assert(pos < list->length);

  /* Check for out-of-bounds position. */
  if (pos >= list->length)
    return NULL;

  list_node_t *node_to_remove;

  /* Handle O(1) edge cases first for direct access. */
  if (pos == 0)
    node_to_remove = list->head;
  else if (pos == list->length - 1)
    node_to_remove = list->tail;
  else
  {
    /*
     * For removal from the middle, find the target node.
     * This is optimized by traversing from the closest end of the list.
     */
    if (pos < (list->length / 2))
    {
      /* Position is in the first half, traverse from the head. */
      node_to_remove = list->head;
      for (unsigned int i = 0; i < pos; ++i)
        node_to_remove = node_to_remove->next;
    }
    else
    {
      /* Position is in the second half, traverse backwards from the tail. */
      node_to_remove = list->tail;
      for (unsigned int i = list->length - 1; i > pos; --i)
        node_to_remove = node_to_remove->prev;
    }
  }

  assert(node_to_remove);
  list_remove(node_to_remove, list);

  return node_to_remove;
}

/**
 * @brief Retrieves the node at a specific position (index) in a list.
 *
 * This function finds and returns the node at the zero-based `pos`. To be
 * efficient, it traverses from the head or the tail, whichever is closer.
 * This is an O(n) operation due to the linear scan required to find the
 * node in the worst case.
 *
 * @param list The list to search within.
 * @param pos The zero-based index of the node to retrieve. Must be < list->length.
 * @return A pointer to the node at the specified position, or NULL if `pos` is out of bounds.
 */
list_node_t *
list_get_at(const list_t *list, unsigned int pos)
{
  assert(pos < list->length);

  /* Check for out-of-bounds position. */
  if (pos >= list->length)
    return NULL;

  list_node_t *found_node;

  /* Optimize by traversing from the closest end of the list. */
  if (pos < (list->length / 2))
  {
    /* Position is in the first half, traverse from the head. */
    found_node = list->head;
    for (unsigned int i = 0; i < pos; ++i)
      found_node = found_node->next;
  }
  else
  {
    /* Position is in the second half, traverse backwards from the tail. */
    found_node = list->tail;
    for (unsigned int i = list->length - 1; i > pos; --i)
      found_node = found_node->prev;
  }

  assert(found_node);
  return found_node;
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
  return (list1->length >= list2->length) ? list1 : list2;
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
  return (list1->length <= list2->length) ? list1 : list2;
}

/**
 * @brief Converts a double-linked list to an array.
 *
 * This function converts all the nodes of a double-linked list into an array of void pointers.
 * The array will contain pointers to the data of each node, in the order they appear in the list.
 * The caller is responsible for freeing the allocated array.
 *
 * @param list Pointer to the double-linked list.
 * @return Pointer to the newly allocated array, or NULL if the list is empty.
 */
void **
list_to_array(const list_t *list)
{
  if (list_is_empty(list))
    return NULL;

  void **array = io_calloc(list->length * sizeof(void *));

  unsigned int index = 0;
  list_node_t *node = list->head;
  while (node)
  {
    array[index++] = node->data;
    node = node->next;
  }

  assert(index == list->length);
  return array;
}

/**
 * @brief Peeks at the data of the head node of a double-linked list without removing the node.
 *
 * This function returns a pointer to the data stored in the head node (the first node)
 * of the specified double-linked list. If the list is empty, it returns NULL.
 *
 * @param list Pointer to the double-linked list to peek at.
 * @return Pointer to the data of the head node, or NULL if the list is empty.
 */
void *
list_peek_head(const list_t *list)
{
  return list_is_empty(list) ? NULL : list->head->data;
}

/**
 * @brief Peeks at the data of the tail node of a double-linked list without removing the node.
 *
 * This function returns a pointer to the data stored in the tail node (the last node)
 * of the specified double-linked list. If the list is empty, it returns NULL.
 *
 * @param list Pointer to the double-linked list to peek at.
 * @return Pointer to the data of the tail node, or NULL if the list is empty.
 */
void *
list_peek_tail(const list_t *list)
{
  return list_is_empty(list) ? NULL : list->tail->data;
}
