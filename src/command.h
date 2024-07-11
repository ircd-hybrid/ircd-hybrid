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

#ifndef INCLUDED_command_h
#define INCLUDED_command_h


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

/** Enumerated type for client command handlers. */
typedef enum HandlerType
{
  UNREGISTERED_HANDLER,  /**< Used for unregistered clients. */
  CLIENT_HANDLER,  /**< Used for local users. */
  SERVER_HANDLER,  /**< Used for server connections. */
  ENCAP_HANDLER,  /**< Used for encapsulated commands (ENCAP). */
  OPER_HANDLER,  /**< Used for IRC operators. */
  LAST_HANDLER_TYPE,  /**< Number of handler types. */
} HandlerType;

struct CommandHandler
{
  bool end_grace_period;  /**< Handler ends the flood grace period */
  bool empty_last_arg;  /**< Last argument is allowed to be empty / NUL */
  unsigned int args_min;  /**< At least this many args must be passed or an error will
                               be sent to the user before the m_func is even called */
  unsigned int args_max;  /**< Maximum permitted parameters. If reached, the rest
                               of the message will be put into this last parameter */
  void (*handler)(struct Client *, int, char *[]);  /**< Command handler function. */
};

/*
 * Command table structure
 */
struct Command
{
  const char *name;  /**< The actual command string */
  void *extra;  /**< Extra pointer to be passed in parv[1] */
  unsigned int count;  /**< Number of times command used */
  unsigned int rcount;  /**< Number of times command used by server */
  unsigned int ecount;  /**< Number of times command has been issued via ENCAP */
  size_t bytes;  /**< Bytes received for this command */

  /* handlers:
   * UNREGISTERED, CLIENT, SERVER, ENCAP, OPER, LAST
   */
  struct CommandHandler handlers[LAST_HANDLER_TYPE];
};

extern void command_add(struct Command *);
extern void command_del(struct Command *);
extern void command_add_array(struct Command *, size_t);
extern void command_del_array(struct Command *, size_t);
extern void command_report(struct Client *);
extern struct Command *command_find(const char *);
#endif  /* INCLUDED_command_h */
