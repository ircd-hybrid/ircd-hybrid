/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file parse.h
 * \brief A header for the message parser.
 * \version $Id$
 */

#ifndef INCLUDED_parse_h
#define INCLUDED_parse_h

struct Client;


/*
 * m_functions execute protocol messages on this server:
 * int m_func(struct Client *source_p, int parc, char *parv[]);
 *
 * source_p is the source of the message, defined by the
 * prefix part of the message if present. If not
 * then it is the client of the physical connection.
 * Note that prefixes are only taken from servers.
 *
 * parc   number of variable parameter strings (if zero,
 *        parv is allowed to be NULL)
 *
 * parv   a NULL terminated list of parameter pointers,
 *
 *          parv[0] command
 *          parv[1]...parv[parc - 1] pointers to additional parameters
 *          parv[parc] == NULL, *always*
 *
 * note: it is guaranteed that parv[0]..parv[parc - 1] are all
 * non-NULL pointers.
 */

/*
 * MessageHandler
 */
typedef enum HandlerType
{
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
 * struct Client* source_p   - source of message, may be different from client_p
 * int            parc   - parameter count
 * char*          parv[] - parameter vector
 */
typedef int (*MessageHandler)(struct Client *, int, char *[]);

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
extern int m_ignore(struct Client *, int, char *[]);
extern int m_not_oper(struct Client *, int, char *[]);
extern int m_registered(struct Client *, int, char *[]);
extern int m_unregistered(struct Client *, int, char *[]);
#endif /* INCLUDED_parse_h */
