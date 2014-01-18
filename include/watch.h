/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997 Jukka Santala (Donwulff)
 *  Copyright (c) 2005-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file watch.h
 * \brief Header including structures and prototypes for WATCH support
 * \version $Id$
 */

#ifndef INCLUDED_watch_h
#define INCLUDED_watch_h


/*! \brief Watch structure */
struct Watch
{
  dlink_node node;  /**< Embedded dlink_node used to link into watchTable */
  dlink_list watched_by;  /**< List of clients that have this
                              entry on their watch list */
  time_t lasttime;  /**< Last time the client was seen */
  char nick[NICKLEN + 1];  /**< Nick name of the client to watch */
};

extern void watch_init(void);
extern void watch_add_to_hash_table(const char *, struct Client *);
extern void watch_del_from_hash_table(const char *, struct Client *);
extern void watch_check_hash(struct Client *, const unsigned int);
extern void watch_del_watch_list(struct Client *);
extern void watch_count_memory(unsigned int *const, uint64_t *const);
extern struct Watch *watch_find_hash(const char *);
#endif
