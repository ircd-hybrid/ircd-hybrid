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
 * @file fdlist.h
 * @brief Header file for managing file descriptors.
 *
 * The fdlist.h file provides data structures and functions for managing
 * file descriptors. It includes features for handling event callbacks,
 * timeouts, and connection information associated with file descriptors.
 */

#ifndef INCLUDED_fdlist_h
#define INCLUDED_fdlist_h

#include "io.h"
#include "address.h"
#include "tls.h"

/**
 * @var FD_DESC_SIZE
 * @brief Size of the file descriptor description buffer.
 */
enum { FD_DESC_SIZE = 80 };  /* HOSTLEN + comment */

/**
 * @struct _fde
 * @brief Structure representing a file descriptor entry.
 */
typedef struct _fde
{
  /*
   * Yes, this gives us only one pending read and one pending write per
   * filedescriptor. Think though: when do you think we'll need more?
   */
  int fd;  /**< File descriptor. */
  int comm_index;  /**< Index in the poll list. */
  int evcache;  /**< Current fd events as set up by the underlying I/O. */
  char *desc;  /**< File descriptor description. */

  /** @name Event Handlers */
  /**@{*/
  void (*read_handler)(struct _fde *, void *);  /**< Read event handler. */
  void *read_data;  /**< Data for the read event handler. */

  void (*write_handler)(struct _fde *, void *);  /**< Write event handler. */
  void *write_data;  /**< Data for the write event handler. */

  void (*timeout_handler)(struct _fde *, void *);  /**< Timeout event handler. */
  void *timeout_data;  /**< Data for the timeout event handler. */
  uintmax_t timeout;  /**< Timeout duration. */

  void (*flush_handler)(struct _fde *, void *);  /**< Flush event handler. */
  void *flush_data;  /**< Data for the flush event handler. */
  uintmax_t flush_timeout;  /**< Flush timeout duration. */
  /**@}*/

  /** @name Flags */
  /**@{*/
  struct
  {
    bool open;  /**< Flag indicating if the file descriptor is open. */
    bool is_socket;  /**< Flag indicating if the file descriptor is a socket. */
  } flags;
  /**@}*/

  /** @name Connection Information */
  /**@{*/
  struct
  {
    struct io_addr addr;  /**< Host address information. */
    void (*callback)(struct _fde *, int, void *);  /**< Callback function for connection events. */
    void *data;  /**< Data for the connection callback. */
    /* Retry count could be added here in the future -- adrian */
  } connect;
  /**@}*/

  tls_data_t tls;  /**< TLS-related data. */
} fde_t;

extern int number_fd;  /**< Number of file descriptors. */
extern int hard_fdlimit;  /**< Hard file descriptor limit. */
extern int highest_fd;  /**< Highest file descriptor in use. */
extern fde_t *fd_table;  /**< File descriptor table. */

extern void fdlist_init(void);
extern fde_t *fd_open(int, bool, const char *);
extern fde_t *fd_close(fde_t *);
extern void fd_note(fde_t *, const char *, ...) IO_AFP(2,3);
extern void close_fds(void);
#endif  /* INCLUDED_fdlist_h */
