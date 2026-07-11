/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file whowas.h
 * @brief Declarations for the WHOWAS user cache.
 *
 * This header file defines the structure for storing historical information about IRC users.
 */

#ifndef INCLUDED_whowas_h
#define INCLUDED_whowas_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "list.h"

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

typedef void (*whowas_callback_t)(const struct Whowas *, void *);

extern void whowas_trim(void);
extern void whowas_add_history(struct Client *, bool);
extern void whowas_off_history(struct Client *);
extern void whowas_count_memory(uint32_t *const, size_t *const, uint32_t *const, size_t *const);
extern int whowas_query(const char *, int, whowas_callback_t, void *);
extern struct Client *whowas_get_history(const char *, uintmax_t);
extern struct WhowasGroup *whowas_group_find(const char *);
#endif  /* INCLUDED_whowas_h */
