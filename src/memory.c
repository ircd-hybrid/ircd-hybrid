/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  memory.c: Memory utilities.
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
#include "ircd_defs.h"
#include "irc_string.h"
#include "memory.h"
#include "s_log.h"
#include "restart.h"


/*
 * MyMalloc - allocate memory, call outofmemory on failure
 */
void *
MyMalloc(size_t size)
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

  if (ret == NULL)
    outofmemory();

  return ret;
}

void
MyFree(void *x)
{
  if (x)
    free(x);
}

void
_DupString(char **x, const char *y)
{
  (*x) = malloc(strlen(y) + 1);
  strcpy((*x), y);
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

  ilog(L_CRIT, "Out of memory: restarting server...");
  restart("Out of Memory");
}

#ifndef NDEBUG
/*
 * frob some memory. debugging time.
 * -- adrian
 */
void
mem_frob(void *data, int len)
{
  /* correct for Intel only! little endian */
  unsigned char b[4] = { 0xef, 0xbe, 0xad, 0xde };
  int i;
  char *cdata = data;

  for (i = 0; i < len; i++)
  {
    *cdata = b[i % 4];
    cdata++;
  }
}
#endif
