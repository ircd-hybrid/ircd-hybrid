/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_accept.c
 * \brief Includes required functions for processing the ACCEPT command.
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"
#include "module.h"

#include "accept.h"
#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "nuh.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

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
  LIST_FOREACH(node, source->connection->accept_list.head)
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
m_accept(struct Client *source, size_t parc, char *parv[])
{
  char *mask = collapse(parv[1]);

  if (string_is_empty(mask) || strcmp(mask, "*") == 0)
  {
    accept_list(source);
    return;
  }

  char nick[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  struct nuh_split nuh =
  {
    .nickptr  = nick,
    .userptr  = user,
    .hostptr  = host,
    .nicksize = sizeof(nick),
    .usersize = sizeof(user),
    .hostsize = sizeof(host)
  };

  char *saveptr = NULL;
  for (mask = strtok_r(mask, ",", &saveptr); mask;
       mask = strtok_r(NULL, ",", &saveptr))
  {
    if (*mask == '-' && *++mask)
    {
      nuh.nuhmask = mask;
      nuh_split(&nuh);

      struct AcceptItem *accept =
        accept_find(nick, user, host, &source->connection->accept_list, io_strcasecmp);
      if (accept == NULL)
      {
        sendto_one_numeric(source, &me, ERR_ACCEPTNOT, nick, user, host);
        continue;
      }

      accept_del(accept, &source->connection->accept_list);
    }
    else if (*mask)
    {
      if (list_length(&source->connection->accept_list) >= ConfigGeneral.max_accept)
      {
        sendto_one_numeric(source, &me, ERR_ACCEPTFULL);
        return;
      }

      nuh.nuhmask = mask;
      nuh_split(&nuh);

      struct AcceptItem *accept =
        accept_find(nick, user, host, &source->connection->accept_list, io_strcasecmp);
      if (accept)
      {
        sendto_one_numeric(source, &me, ERR_ACCEPTEXIST, nick, user, host);
        continue;
      }

      accept_add(nick, user, host, &source->connection->accept_list);
      accept_list(source);
    }
  }
}

static struct Command command_table =
{
  .name = "ACCEPT",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_accept },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_accept }
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
