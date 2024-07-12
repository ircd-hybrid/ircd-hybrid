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
 * @file whowas.h
 * @brief Declarations for the WHOWAS user cache.
 *
 * This header file defines the structure for storing historical information about IRC users.
 */

#ifndef INCLUDED_whowas_h
#define INCLUDED_whowas_h

#include "ircd_defs.h"
#include "client.h"

/**
 * @struct Whowas
 * @brief Structure representing a historical record of an IRC user.
 *
 * This structure contains information about a user's historical presence on the network,
 * including details such as nickname, user name, host, logoff time, and more.
 */
struct Whowas
{
  list_node_t hash_node;  /**< List node; linked into whowas_hash. */
  list_node_t list_node;  /**< List node; linked into whowas_list. */
  list_node_t client_list_node;  /**< List node; linked into client->whowas_list. */
  unsigned int hash_value;  /**< Hash value derived from Whowas::name. */
  uintmax_t logoff;  /**< Time when the client logged off; real time. */
  bool server_hidden;  /**< Indicates if the client's server is hidden. */
  char account[ACCOUNTLEN + 1];  /**< Services account associated with the client. */
  char name[NICKLEN + 1];  /**< Client's nickname. */
  char username[USERLEN + 1];  /**< Client's username. */
  char hostname[HOSTLEN + 1];  /**< Client's host name. */
  char realhost[HOSTLEN + 1];  /**< Client's real host name. */
  char sockhost[HOSTIPLEN + 1];  /**< Client's IP address as a string. */
  char realname[REALLEN + 1];  /**< Client's real name or GECOS information. */
  char servername[HOSTLEN + 1];  /**< Name of the server the client is using. */
  struct Client *client;  /**< Pointer to the current client or NULL if offline. */
};

extern void whowas_trim(void);
extern void whowas_add_history(struct Client *, bool);
extern void whowas_off_history(struct Client *);
extern void whowas_count_memory(unsigned int *const, size_t *const);
extern struct Client *whowas_get_history(const char *, uintmax_t);
extern const list_t *whowas_get_hash(unsigned int);
#endif  /* INCLUDED_whowas_h */
