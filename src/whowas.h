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
 * @struct WhowasGroup
 * @brief Structure representing a nickname and its associated WHOWAS records.
 *
 * This structure manages the list of Whowas structs associated with a specific nickname.
 */
struct WhowasGroup
{
  list_node_t hash_node;  /**< List node; linked into whowas_hash. */
  char *name;  /**< Nickname string. */
  unsigned int hash_value;  /**< Hash value derived from WhowasGroup::name. */
  list_t whowas_records;  /**< List of Whowas structs for this nickname. */
};

/**
 * @struct Whowas
 * @brief Structure representing a historical record of an IRC user.
 *
 * This structure contains information about a user's historical presence on the network,
 * including details such as nickname, user name, host, logoff time, and more.
 */
struct Whowas
{
  list_node_t whowas_list_node;  /**< List node; linked into whowas_list. */
  list_node_t client_list_node;  /**< List node; linked into client->whowas_list. */
  list_node_t group_list_node;  /**< List node; linked into WhowasGroup::whowas_records. */
  struct Client *client;  /**< Pointer to the current client or NULL if offline. */
  struct WhowasGroup *group;  /**< Pointer to the WhowasGroup this record belongs to. */
  uintmax_t logoff;  /**< Time when the client logged off; real time. */
  bool server_hidden;  /**< Indicates if the client's server is hidden. */
  char *name;  /**< Client's nickname. */
  char *username;  /**< Client's username. */
  char *hostname;  /**< Client's host name. */
  char *realhost;  /**< Client's real host name. */
  char *sockhost;  /**< Client's IP address as a string. */
  char *realname;  /**< Client's real name or GECOS information. */
  char *account;  /**< Services account associated with the client. */
  char *servername;  /**< Name of the server the client is using. */
};

extern void whowas_trim(void);
extern void whowas_add_history(struct Client *, bool);
extern void whowas_off_history(struct Client *);
extern void whowas_count_memory(unsigned int *const, size_t *const, unsigned int *const, size_t *const);
extern struct Client *whowas_get_history(const char *, uintmax_t);
extern struct WhowasGroup *whowas_group_find(const char *);
#endif  /* INCLUDED_whowas_h */
