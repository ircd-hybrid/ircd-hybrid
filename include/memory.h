/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file memory.h
 * \brief A header for the memory functions.
 * \version $Id$
 */

#ifndef _I_MEMORY_H
#define _I_MEMORY_H

#include "ircd_defs.h"

extern void outofmemory(void);
extern void *MyCalloc(size_t);
extern void *MyRealloc(void *, size_t);
extern void MyFree(void *);
extern void *xstrdup(const char *);
extern void *xstrndup(const char *, size_t);
#endif /* _I_MEMORY_H */
