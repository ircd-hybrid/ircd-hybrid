/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file fdlist.h
 * \brief The file descriptor list header.
 * \version $Id$
 */

#ifndef INCLUDED_fdlist_h
#define INCLUDED_fdlist_h

#include "ircd_defs.h"
#include "tls.h"


enum { FD_DESC_SIZE = 128 };  /* hostlen + comment */
enum { FD_HASH_SIZE = 1024 };

enum
{
  COMM_OK,
  COMM_ERR_BIND,
  COMM_ERR_DNS,
  COMM_ERR_TIMEOUT,
  COMM_ERR_CONNECT,
  COMM_ERROR,
  COMM_ERR_MAX
};

struct _fde;
struct Client;

typedef struct _fde
{
  /* New-school stuff, again pretty much ripped from squid */
  /*
   * Yes, this gives us only one pending read and one pending write per
   * filedescriptor. Think though: when do you think we'll need more?
   */
  int fd;  /* So we can use the fde_t as a callback ptr */
  int comm_index;  /* where in the poll list we live */
  int evcache;          /* current fd events as set up by the underlying I/O */
  char desc[FD_DESC_SIZE];
  void (*read_handler)(struct _fde *, void *);
  void *read_data;
  void (*write_handler)(struct _fde *, void *);
  void *write_data;
  void (*timeout_handler)(struct _fde *, void *);
  void *timeout_data;
  time_t timeout;
  void (*flush_handler)(struct _fde *, void *);
  void *flush_data;
  time_t flush_timeout;

  struct
  {
    unsigned int open:1;
    unsigned int is_socket:1;
  } flags;

  struct
  {
    /* We don't need the host here ? */
    struct irc_ssaddr S;
    struct irc_ssaddr hostaddr;
    void (*callback)(struct _fde *, int, void *);
    void *data;
    /* We'd also add the retry count here when we get to that -- adrian */
  } connect;

  tls_data_t ssl;
  struct _fde *hnext;
} fde_t;

extern int number_fd;
extern int hard_fdlimit;
extern fde_t *fd_hash[];
extern fde_t *fd_next_in_loop;

extern void fdlist_init(void);
extern fde_t *lookup_fd(int);
extern void fd_open(fde_t *, int, int, const char *);
extern void fd_close(fde_t *);
extern void fd_dump(struct Client *, int, char *[]);
extern void fd_note(fde_t *, const char *, ...);
extern void close_standard_fds(void);
extern void close_fds(fde_t *);
#endif /* INCLUDED_fdlist_h */
