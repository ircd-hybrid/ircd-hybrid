/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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

/*! \file m_accept.c
 * \brief Includes required functions for processing the ACCEPT command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "memory.h"
#include "accept.h"


/*! \brief Sends a list of nick!user\@host masks a Client
 *         has on its acceptlist.
 *
 * \param source The actual Client the list will be sent to.
 */
static void
accept_list(struct Client *source)
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;

  /* :me.name 281 source->name :n1!u1@h1 n2!u2@h2 ...\r\n */
  /* 1       23456            78                     9 0  */
  size_t len = strlen(me.name) + strlen(source->name) + 10;

  list_node_t *node;
  LIST_FOREACH(node, source->connection->acceptlist.head)
  {
    const struct AcceptItem *const accept = node->data;
    size_t masklen = strlen(accept->nick) +
                     strlen(accept->user) +
                     strlen(accept->host) + 3;  /* +3 for ! + @ + space */

    if ((bufptr - buf) + masklen + len > sizeof(buf))
    {
      sendto_one_numeric(source, &me, RPL_ACCEPTLIST, buf);
      bufptr = buf;
    }

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s!%s@%s" : "%s!%s@%s",
                       accept->nick, accept->user, accept->host);
  }

  if (bufptr != buf)
    sendto_one_numeric(source, &me, RPL_ACCEPTLIST, buf);

  sendto_one_numeric(source, &me, RPL_ENDOFACCEPT);
}

/*! \brief ACCEPT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = comma-separated list of masks to be accepted or removed
 */
static void
m_accept(struct Client *source, int parc, char *parv[])
{
  struct split_nuh_item nuh;
  char nick[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  char *mask = collapse(parv[1]);

  if (EmptyString(mask) || strcmp(mask, "*") == 0)
  {
    accept_list(source);
    return;
  }

  char *p = NULL;
  for (mask = strtok_r(mask, ",", &p); mask;
       mask = strtok_r(NULL, ",", &p))
  {
    if (*mask == '-' && *++mask)
    {
      nuh.nuhmask  = mask;
      nuh.nickptr  = nick;
      nuh.userptr  = user;
      nuh.hostptr  = host;

      nuh.nicksize = sizeof(nick);
      nuh.usersize = sizeof(user);
      nuh.hostsize = sizeof(host);

      split_nuh(&nuh);

      struct AcceptItem *accept =
        accept_find(nick, user, host, &source->connection->acceptlist, irccmp);
      if (accept == NULL)
      {
        sendto_one_numeric(source, &me, ERR_ACCEPTNOT, nick, user, host);
        continue;
      }

      accept_del(accept, &source->connection->acceptlist);
    }
    else if (*mask)
    {
      if (list_length(&source->connection->acceptlist) >= ConfigGeneral.max_accept)
      {
        sendto_one_numeric(source, &me, ERR_ACCEPTFULL);
        return;
      }

      nuh.nuhmask  = mask;
      nuh.nickptr  = nick;
      nuh.userptr  = user;
      nuh.hostptr  = host;

      nuh.nicksize = sizeof(nick);
      nuh.usersize = sizeof(user);
      nuh.hostsize = sizeof(host);

      split_nuh(&nuh);

      struct AcceptItem *accept =
        accept_find(nick, user, host, &source->connection->acceptlist, irccmp);
      if (accept)
      {
        sendto_one_numeric(source, &me, ERR_ACCEPTEXIST, nick, user, host);
        continue;
      }

      accept_add(nick, user, host, &source->connection->acceptlist);
      accept_list(source);
    }
  }
}

static struct Command command_table =
{
  .name = "ACCEPT",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_accept },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_accept }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
