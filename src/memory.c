/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file memory.c
 * \brief Memory utilities.
 * \version $Id$
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "irc_string.h"
#include "memory.h"
#include "log.h"
#include "restart.h"


/*
 * MyCalloc - allocate memory, call outofmemory on failure
 */
void *
MyCalloc(size_t size)
{
  void *ret = calloc(1, size);

  if (ret == NULL)
    outofmemory();

  return ret;
}

/*
 * MyRealloc - reallocate memory, call outofmemory on failure
 */
void *
MyRealloc(void *x, size_t y)
{
  void *ret = realloc(x, y);

  if (y && ret == NULL)
    outofmemory();

  return ret;
}

void
MyFree(void *x)
{
  free(x);
}

void *
xstrdup(const char *s)
{
  void *ret = malloc(strlen(s) + 1);

  if (ret == NULL)
    outofmemory();

  strcpy(ret, s);

  return ret;
}

void *
xstrndup(const char *s, size_t len)
{
  void *ret = malloc(len + 1);

  if (ret == NULL)
    outofmemory();

  strlcpy(ret, s, len + 1);

  return ret;
}

/* outofmemory()
 *
 * input        - NONE
 * output       - NONE
 * side effects - simply try to report there is a problem.
 *                Abort if it was called more than once
 */
void
outofmemory(void)
{
  static int was_here = 0;

  if (was_here++)
    abort();

  ilog(LOG_TYPE_IRCD, "Out of memory: restarting server...");
  server_die("Out of Memory", SERVER_RESTART);
}
