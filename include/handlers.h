/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  handlers.h: A header for some built in command handlers.
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

#ifndef INCLUDED_handlers_h
#define INCLUDED_handlers_h

/*
 * m_functions execute protocol messages on this server:
 * int m_func(struct Client* client_p, struct Client* source_p, int parc, char* parv[]);
 *
 *    client_p    is always NON-NULL, pointing to a *LOCAL* client
 *            structure (with an open socket connected!). This
 *            identifies the physical socket where the message
 *            originated (or which caused the m_function to be
 *            executed--some m_functions may call others...).
 *
 *    source_p    is the source of the message, defined by the
 *            prefix part of the message if present. If not
 *            or prefix not found, then source_p==client_p.
 *
 *            (!IsServer(client_p)) => (client_p == source_p), because
 *            prefixes are taken *only* from servers...
 *
 *            (IsServer(client_p))
 *                    (source_p == client_p) => the message didn't
 *                    have the prefix.
 *
 *                    (source_p != client_p && IsServer(source_p) means
 *                    the prefix specified servername. (?)
 *
 *                    (source_p != client_p && !IsServer(source_p) means
 *                    that message originated from a remote
 *                    user (not local).
 *
 *
 *            combining
 *
 *            (!IsServer(source_p)) means that, source_p can safely
 *            taken as defining the target structure of the
 *            message in this server.
 *
 *    *Always* true (if 'parse' and others are working correct):
 *
 *    1)      source_p->from == client_p  (note: client_p->from == client_p)
 *
 *    2)      MyConnect(source_p) <=> source_p == client_p (e.g. source_p
 *            *cannot* be a local connection, unless it's
 *            actually client_p!). [MyConnect(x) should probably
 *            be defined as (x == x->from) --msa ]
 *
 *    parc    number of variable parameter strings (if zero,
 *            parv is allowed to be NULL)
 *
 *    parv    a NULL terminated list of parameter pointers,
 *
 *                    parv[0], sender (prefix string), if not present
 *                            this points to an empty string.
 *                    parv[1]...parv[parc-1]
 *                            pointers to additional parameters
 *                    parv[parc] == NULL, *always*
 *
 *            note:   it is guaranteed that parv[0]..parv[parc-1] are all
 *                    non-NULL pointers.
 */

struct Client;

/* generic handlers */
extern void rfc1459_command_send_error(struct Client *, struct Client *,int, char *[]);
extern void m_ignore(struct Client *, struct Client *, int, char *[]);
extern void m_not_oper(struct Client *, struct Client *, int, char *[]);
extern void m_registered(struct Client *, struct Client *, int, char *[]);
extern void m_unregistered(struct Client *, struct Client *, int, char *[]);

#endif /* INCLUDED_handlers_h */

