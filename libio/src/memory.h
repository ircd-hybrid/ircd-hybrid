/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
#include <stddef.h>

extern void io_free(void *);
extern void io_set_oom_handler(void (*)(void));
extern void *io_calloc(size_t);
extern void *io_realloc(void *, size_t);
extern char *io_strdup(const char *);
extern char *io_strndup(const char *, size_t);
#endif  /* INCLUDED_memory_h */
