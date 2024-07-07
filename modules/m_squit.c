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

/*! \file m_squit.c
 * \brief Includes required functions for processing the SQUIT command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/*! \brief SQUIT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = server name
 *      - parv[2] = comment
 */
static void
mo_squit(struct Client *source, int parc, char *parv[])
{
  const char *const name = parv[1];
  struct Client *target = NULL;

  /* The following allows wild cards in SQUIT. */
  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    struct Client *tmp = node->data;

    if (IsServer(tmp))
    {
      if (match(name, tmp->name) == 0)
      {
        target = tmp;
        break;
      }
    }
  }

  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, name);
    return;
  }

  if (!MyConnect(target) && !HasOFlag(source, OPER_FLAG_SQUIT_REMOTE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "squit:remote");
    return;
  }

  if (MyConnect(target) && !HasOFlag(source, OPER_FLAG_SQUIT))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "squit");
    return;
  }

  char comment[REASONLEN + 1] = CONF_NOREASON;
  if (!EmptyString(parv[2]))
    strlcpy(comment, parv[2], sizeof(comment));

  if (MyConnect(target))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Received SQUIT %s from %s (%s)",
                         target->name, get_oper_name(source), comment);
    log_write(LOG_TYPE_IRCD, "SQUIT %s from %s (%s)",
              target->name, get_oper_name(source), comment);

    /* To them, we are exiting */
    sendto_one(target, ":%s SQUIT %s :%s", source->id, me.id, comment);

    /* Send to everything but target */
    sendto_server(target, 0, 0, ":%s SQUIT %s :%s",
                  source->id, target->id, comment);
  }
  else
    /* Send to everything */
    sendto_server(NULL, 0, 0, ":%s SQUIT %s :%s",
                  source->id, target->id, comment);

  AddFlag(target, FLAGS_SQUIT);

  client_exit(target, comment);
}

/*! \brief SQUIT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = server name
 *      - parv[2] = comment
 */
static void
ms_squit(struct Client *source, int parc, char *parv[])
{
  struct Client *target = hash_find_server(parv[1]);
  if (target == NULL)
    return;

  if (!IsServer(target) && !IsMe(target))
    return;

  if (IsMe(target))
    target = source->from;

  const char *comment = source->name;
  if (parc > 2 && parv[parc - 1])
    comment = parv[parc - 1];

  if (MyConnect(target))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_GLOBAL, "from %s: Remote SQUIT %s from %s (%s)",
                         me.name, target->name, get_oper_name(source), comment);
    sendto_server(source, 0, 0, ":%s GLOBOPS :Remote SQUIT %s from %s (%s)",
                  me.id, target->name, get_oper_name(source), comment);
    log_write(LOG_TYPE_IRCD, "Remote SQUIT %s from %s (%s)",
              target->name, get_oper_name(source), comment);

    /* To them, we are exiting */
    sendto_one(target, ":%s SQUIT %s :%s", source->id, me.id, comment);

    /* Send to everything but target and source */
    list_node_t *node;
    LIST_FOREACH(node, local_server_list.head)
    {
      struct Client *client_p = node->data;

      if (client_p == target || client_p == source->from)
        continue;

      sendto_one(client_p, ":%s SQUIT %s :%s",
                 source->id, target->id, comment);
    }
  }
  else
    /* Send to everything but source */
    sendto_server(source, 0, 0, ":%s SQUIT %s :%s",
                  source->id, target->id, comment);

  AddFlag(target, FLAGS_SQUIT);

  client_exit(target, comment);
}

static struct Command command_table =
{
  .name = "SQUIT",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_squit, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_squit, .args_min = 2 }
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
  .core = true
};
