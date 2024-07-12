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

/*! \file server.h
 * \brief A header for the server functions.
 */

#ifndef INCLUDED_server_h
#define INCLUDED_server_h

struct Client;
struct MaskItem;

/*
 * ts stuff
 */
enum
{
  TS_CURRENT = 6,  /**< Current TS protocol version */
  TS_MINIMUM = 6,  /**< Minimum supported TS protocol version */
};

/** Return values for server_hunt() */
enum server_hunt_ret
{
  HUNTED_NOSUCH,  /**< If the hunted server is not found */
  HUNTED_ISME,  /**< If this server should execute the command */
  HUNTED_PASS  /**< If message passed onwards successfully */
};

struct server_hunt
{
  enum server_hunt_ret ret;
  struct Client *target;
};

extern void server_connect_auto(void *);
extern bool server_connect(struct MaskItem *, struct Client *);
extern bool server_valid_name(const char *);
extern struct Client *find_servconn_in_progress(const char *);
extern struct Server *server_make(struct Client *);
extern const struct server_hunt *server_hunt(struct Client *, const char *, const int, char *[]);
#endif  /* INCLUDED_server_h */
