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

/*! \file hash.h
 * \brief A header for the ircd hashtable code.
 */

#ifndef INCLUDED_hash_h
#define INCLUDED_hash_h

#define FNV1_32_INIT 0x811c9dc5
#define FNV1_32_BITS 16
#define FNV1_32_SIZE (1 << FNV1_32_BITS)  /* 2^16 = 65536 */
#define HASHSIZE FNV1_32_SIZE

struct Client;
struct Channel;

enum
{
  HASH_TYPE_ID,
  HASH_TYPE_CLIENT,
  HASH_TYPE_CHANNEL
};

extern void hash_add_client(struct Client *);
extern void hash_del_client(struct Client *);
extern void hash_add_channel(struct Channel *);
extern void hash_del_channel(struct Channel *);
extern void hash_add_id(struct Client *);
extern void hash_del_id(struct Client *);

extern struct Client *hash_find_id(const char *);
extern struct Client *hash_find_client(const char *);
extern struct Client *hash_find_server(const char *);
extern struct Channel *hash_find_channel(const char *);
extern void *hash_get_bucket(int, unsigned int);

extern void free_list_task(struct Client *);
extern void safe_list_channels(struct Client *, bool);

extern unsigned int strhash(const char *);
#endif  /* INCLUDED_hash_h */
