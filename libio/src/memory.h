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
 * @file memory.h
 * @brief Memory utilities for allocation, deallocation, and duplication.
 *
 * The memory.h header provides functions for handling memory-related operations,
 * such as allocation, deallocation, and string duplication. These utilities help
 * manage memory resources effectively and include safeguards for out-of-memory
 * conditions to ensure robust program behavior.
 */

#ifndef INCLUDED_memory_h
#define INCLUDED_memory_h

extern void io_free(void *);
extern void io_set_oom_handler(void (*)(void));
extern void *io_calloc(size_t);
extern void *io_realloc(void *, size_t);
extern void *io_strdup(const char *);
extern void *io_strndup(const char *, size_t);
#endif  /* INCLUDED_memory_h */
