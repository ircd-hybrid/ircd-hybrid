/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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
 * @file memory.c
 * @brief Memory utilities.
 *
 * This file contains utility functions for memory management, including allocation,
 * reallocation, and deallocation, as well as string duplication functions.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "memory.h"
#include "irc_string.h"

/**
 * @brief Custom handler for out-of-memory conditions.
 *
 * This function pointer allows users to specify a custom handler to be called in case
 * of memory allocation failure within the memory utility functions. By default, it
 * is set to abort(), terminating the program.
 */
static void (*outofmemory)(void) = abort;

/**
 * @brief Sets a custom out-of-memory handler.
 *
 * This function allows users to specify a custom handler to be called
 * in case of memory allocation failure within the memory utility functions.
 *
 * @param handler A function pointer to the custom out-of-memory handler.
 */
void
io_set_oom_handler(void (*handler)(void))
{
  if (handler)
    outofmemory = handler;
  else
    outofmemory = abort;
}

/**
 * @brief Allocates memory using calloc.
 *
 * This function allocates memory of the specified size using calloc.
 * The use of calloc ensures that the allocated memory is initialized to zero.
 * If memory allocation fails, it calls the outofmemory() function.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block.
 */
void *
io_calloc(size_t size)
{
  void *ret = calloc(1, size);

  if (ret == NULL)
    outofmemory();

  return ret;
}

/**
 * @brief Reallocates memory using realloc.
 *
 * This function reallocates memory for the specified block to the new size using realloc.
 * If memory allocation fails and the new size is non-zero, it calls the outofmemory() function.
 *
 * @param x Pointer to the memory block to reallocate.
 * @param y The new size of the memory block.
 * @return A pointer to the reallocated memory block.
 */
void *
io_realloc(void *x, size_t y)
{
  void *ret = realloc(x, y);

  if (y && ret == NULL)
    outofmemory();

  return ret;
}

/**
 * @brief Deallocates memory.
 *
 * This function deallocates the memory block pointed to by x using free.
 *
 * @param x Pointer to the memory block to deallocate.
 */
void
io_free(void *x)
{
  free(x);
}

/**
 * @brief Duplicates a string and handles out-of-memory conditions.
 *
 * This function duplicates the specified string using malloc and strcpy.
 * If memory allocation fails, it calls the outofmemory() function.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string.
 */
void *
io_strdup(const char *s)
{
  void *ret = malloc(strlen(s) + 1);

  if (ret == NULL)
    outofmemory();

  strcpy(ret, s);

  return ret;
}

/**
 * @brief Duplicates a string up to a specified length using malloc and strlcpy.
 *
 * This function duplicates the specified string up to the specified length using malloc and strlcpy.
 * If memory allocation fails, it calls the outofmemory() function.
 *
 * @param s The string to duplicate.
 * @param len The maximum length of the duplicated string.
 * @return A pointer to the duplicated string.
 */
void *
io_strndup(const char *s, size_t len)
{
  void *ret = malloc(len + 1);

  if (ret == NULL)
    outofmemory();

  strlcpy(ret, s, len + 1);

  return ret;
}
