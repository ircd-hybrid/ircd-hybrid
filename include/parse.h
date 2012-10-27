/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  parse.h: A header for the message parser.
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

#ifndef INCLUDED_parse_h
#define INCLUDED_parse_h

struct Client;


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

/*
 * MessageHandler
 */
typedef enum HandlerType {
  UNREGISTERED_HANDLER,
  CLIENT_HANDLER,
  SERVER_HANDLER,
  ENCAP_HANDLER,
  OPER_HANDLER,
  DUMMY_HANDLER,
  LAST_HANDLER_TYPE
} HandlerType;

/*
 * MessageHandler function
 * Params:
 * struct Client* client_p   - connection message originated from
 * struct Client* source_p   - source of message, may be different from client_p
 * int            parc   - parameter count
 * char*          parv[] - parameter vector
 */
typedef void (*MessageHandler)(struct Client *, struct Client *, int, char *[]);

/* 
 * Message table structure 
 */
struct Message
{
  const char *cmd;
  unsigned int count;      /* number of times command used */
  unsigned int rcount;     /* number of times command used by server */
  unsigned int args_min; /* at least this many args must be passed
                             * or an error will be sent to the user 
                             * before the m_func is even called 
                             */
  unsigned int args_max;    /* maximum permitted parameters */
  unsigned int flags;      /* bit 0 set means that this command is allowed
                             * to be used only on the average of once per 2
                             * seconds -SRB
                             */
  uint64_t bytes;  /* bytes received for this message */

  /*
   * client_p = Connected client ptr
   * source_p = Source client ptr
   * parc = parameter count
   * parv = parameter variable array
   */
  /* handlers:
   * UNREGISTERED, CLIENT, SERVER, ENCAP, OPER, DUMMY, LAST
   */
  MessageHandler handlers[LAST_HANDLER_TYPE];
};

/*
 * Constants
 */
#define   MFLG_SLOW             0x001   /* Command can be executed roughly
                                         * once per 2 seconds.                
                                         */
#define MAXPARA    15

extern void parse(struct Client *, char *, char *);
extern void mod_add_cmd(struct Message *);
extern void mod_del_cmd(struct Message *);
extern struct Message *find_command(const char *);
extern void report_messages(struct Client *);

/* generic handlers */
extern void rfc1459_command_send_error(struct Client *, struct Client *,int, char *[]);
extern void m_ignore(struct Client *, struct Client *, int, char *[]);
extern void m_not_oper(struct Client *, struct Client *, int, char *[]);
extern void m_registered(struct Client *, struct Client *, int, char *[]);
extern void m_unregistered(struct Client *, struct Client *, int, char *[]);

#endif /* INCLUDED_parse_h */
