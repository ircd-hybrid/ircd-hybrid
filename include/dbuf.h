/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file dbuf.h
 * \brief A header for the dynamic buffers functions.
 */

#ifndef INCLUDED_dbuf_h
#define INCLUDED_dbuf_h

#define dbuf_length(x) ((x)->total_size)
#define dbuf_clear(x) dbuf_delete(x, dbuf_length(x))

enum { DBUF_BLOCK_SIZE = 1024 };

struct dbuf_block
{
  int refs;
  size_t size;
  char data[DBUF_BLOCK_SIZE];
};

struct dbuf_queue
{
  dlink_list blocks;
  size_t total_size;
  size_t pos;
};

extern struct dbuf_block *dbuf_alloc(void);
extern void dbuf_ref_free(struct dbuf_block *);
extern void dbuf_add(struct dbuf_queue *, struct dbuf_block *);
extern void dbuf_delete(struct dbuf_queue *, size_t);
extern void dbuf_put_fmt(struct dbuf_block *, const char *, ...);
extern void dbuf_put_args(struct dbuf_block *, const char *, va_list);
extern void dbuf_put(struct dbuf_queue *, const char *, size_t);
#endif  /* INCLUDED_dbuf_h */
