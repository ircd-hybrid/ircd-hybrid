/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2017 ircd-hybrid development team
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

/*! \file whowas.h
 * \brief A header for the whowas functions.
 * \version $Id$
 */

#ifndef INCLUDED_whowas_h
#define INCLUDED_whowas_h

#include "ircd_defs.h"
#include "client.h"


struct Whowas
{
  dlink_node hnode;  /**< List node; linked into whowas_hash */
  dlink_node cnode;  /**< List node; linked into client->whowas_list */
  dlink_node lnode;  /**< List node; linked into whowas_list */
  unsigned int hashv;  /**< Hash value derived from Whowas::name */
  unsigned int shide;  /**< Client's server is hidden */
  uintmax_t logoff;  /**< When the client logged off */
  char account[ACCOUNTLEN + 1];  /**< Services account */
  char name[NICKLEN + 1];  /**< Client's nick name */
  char username[USERLEN + 1];  /**< Client's user name */
  char hostname[HOSTLEN + 1];  /**< Client's host name */
  char sockhost[HOSTIPLEN + 1];  /**< Client's IP address as string */
  char realname[REALLEN + 1];  /**< Client's real name/gecos */
  char servername[HOSTLEN + 1];  /**< Name of the server the client is using */
  struct Client *online;  /**< Pointer to new nick name for chasing or NULL */
};

extern const dlink_list *whowas_get_hash(unsigned int);
extern void whowas_init(void);
extern void whowas_trim(void);
extern void whowas_add_history(struct Client *, const int);
extern void whowas_off_history(struct Client *);
extern struct Client *whowas_get_history(const char *, uintmax_t);
extern void whowas_count_memory(unsigned int *const, size_t *const);
#endif /* INCLUDED_whowas_h */
