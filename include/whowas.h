/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  whowas.h: Header for the whowas functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#ifndef INCLUDED_whowas_h
#define INCLUDED_whowas_h

#include "ircd_defs.h"
#include "client.h"
#include "config.h"


struct Whowas
{
  int hashv;
  time_t logoff;
  char name[NICKLEN + 1];
  char username[USERLEN + 1];
  char hostname[HOSTLEN + 1];
  char realname[REALLEN + 1];
  char servername[HOSTLEN + 1];
  struct Client *online; /* Pointer to new nickname for chasing or NULL */
  dlink_node tnode;      /* for hash table...                           */
  dlink_node cnode;      /* for client struct linked list               */
};

/*
** initwhowas
*/
extern void whowas_init(void);

/*
** add_history
**      Add the currently defined name of the client to history.
**      usually called before changing to a new name (nick).
**      Client must be a fully registered user.
*/
extern void add_history(struct Client *, const int);

/*
** off_history
**      This must be called when the client structure is about to
**      be released. History mechanism keeps pointers to client
**      structures and it must know when they cease to exist. This
**      also implicitly calls AddHistory.
*/
extern void off_history(struct Client *);

/*
** get_history
**      Return the current client that was using the given
**      nickname within the timelimit. Returns NULL, if no
**      one found...
*/
extern struct Client *get_history(const char *, time_t);

/*
** for debugging...counts related structures stored in whowas array.
*/
extern void whowas_count_memory(unsigned int *const, uint64_t *const);
extern dlink_list WHOWASHASH[];
#endif /* INCLUDED_whowas_h */
