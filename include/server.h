/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2018 ircd-hybrid development team
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
 * \version $Id$
 */

#ifndef INCLUDED_server_h
#define INCLUDED_server_h

struct Client;
struct MaskItem;

/*
 * Number of seconds to wait after server starts up, before
 * starting try_connections()
 * TOO SOON and you can nick collide like crazy.
 */
enum { STARTUP_CONNECTIONS_TIME = 60 };

/*
 * Return values for server_hunt()
 */
enum server_hunt_ret
{
  HUNTED_NOSUCH  = -1,  /**< If the hunted server is not found */
  HUNTED_ISME    =  0,  /**< If this server should execute the command */
  HUNTED_PASS    =  1   /**< If message passed onwards successfully */
};

struct server_hunt
{
  enum server_hunt_ret ret;
  struct Client *target_p;
};

extern int valid_servname(const char *);
extern const struct server_hunt *server_hunt(struct Client *, const char *, const int, const int, char *[]);
extern void write_links_file(void *);
extern void read_links_file(void);
extern void try_connections(void *);
extern int server_connect(struct MaskItem *, struct Client *);
extern struct Client *find_servconn_in_progress(const char *);
extern struct Server *server_make(struct Client *);
#endif  /* INCLUDED_server_h */
