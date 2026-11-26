/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file fdlist.h
 * @brief Header file for managing file descriptors.
 *
 * The fdlist.h file provides data structures and functions for managing
 * file descriptors. It includes features for handling event callbacks,
 * timeouts, and connection information associated with file descriptors.
 */

#ifndef INCLUDED_fdlist_h
#define INCLUDED_fdlist_h
#include <stdbool.h>
#include <stdint.h>

#include "address.h"
#include "io.h"
#include "tls.h"

/**
 * @var FD_DESC_SIZE
 * @brief Size of the file descriptor description buffer.
 */
enum { FD_DESC_SIZE = 80 };  /* HOSTLEN + comment */

typedef struct _fde
{
  int fd;  /**< File descriptor. */
  char *desc;  /**< File descriptor description. */

  void (*cleanup_handler)(void *data);
  void *cleanup_data;

  /** @name Flags */
  /**@{*/
  struct
  {
    bool open;  /**< Flag indicating if the file descriptor is open. */
  } flags;
  /**@}*/

  tls_data_t tls;  /**< TLS-related data. */
} fde_t;

extern int number_fd;  /**< Number of file descriptors. */
extern int hard_fdlimit;  /**< Hard file descriptor limit. */
extern int highest_fd;  /**< Highest file descriptor in use. */
extern fde_t *fd_table;  /**< File descriptor table. */

extern void fdlist_init(void);
extern void fd_note(fde_t *, const char *, ...) IO_AFP(2,3);
extern void close_fds(void);
extern fde_t *fd_open(int, const char *);
extern void fd_close(fde_t *);
#endif  /* INCLUDED_fdlist_h */
