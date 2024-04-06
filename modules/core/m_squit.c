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
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief SQUIT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
mo_squit(struct Client *source_p, int parc, char *parv[])
{
  const char *const name = parv[1];
  struct Client *target_p = NULL;

  /* The following allows wild cards in SQUIT. */
  dlink_node *node;
  DLINK_FOREACH(node, global_server_list.head)
  {
    struct Client *tmp = node->data;

    if (IsServer(tmp) || IsMe(tmp))
    {
      if (match(name, tmp->name) == 0)
      {
        target_p = tmp;
        break;
      }
    }
  }

  if (target_p == NULL || IsMe(target_p))
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, name);
    return;
  }

  if (!MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_SQUIT_REMOTE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "squit:remote");
    return;
  }

  if (MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_SQUIT))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "squit");
    return;
  }

  char comment[REASONLEN + 1] = CONF_NOREASON;
  if (!EmptyString(parv[2]))
    strlcpy(comment, parv[2], sizeof(comment));

  if (MyConnect(target_p))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "Received SQUIT %s from %s (%s)",
                         target_p->name, get_oper_name(source_p), comment);
    log_write(LOG_TYPE_IRCD, "SQUIT %s from %s (%s)",
              target_p->name, get_oper_name(source_p), comment);

    /* To them, we are exiting */
    sendto_one(target_p, ":%s SQUIT %s :%s", source_p->id, me.id, comment);

    /* Send to everything but target */
    sendto_server(target_p, 0, 0, ":%s SQUIT %s :%s",
                  source_p->id, target_p->id, comment);
  }
  else
    /* Send to everything */
    sendto_server(NULL, 0, 0, ":%s SQUIT %s :%s",
                  source_p->id, target_p->id, comment);

  AddFlag(target_p, FLAGS_SQUIT);

  exit_client(target_p, comment);
}

/*! \brief SQUIT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_squit(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = hash_find_server(parv[1]);
  if (target_p == NULL)
    return;

  if (!IsServer(target_p) && !IsMe(target_p))
    return;

  if (IsMe(target_p))
    target_p = source_p->from;

  const char *comment = source_p->name;
  if (parc > 2 && parv[parc - 1])
    comment = parv[parc - 1];

  if (MyConnect(target_p))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_GLOBAL, "from %s: Remote SQUIT %s from %s (%s)",
                         me.name, target_p->name, get_oper_name(source_p), comment);
    sendto_server(source_p, 0, 0, ":%s GLOBOPS :Remote SQUIT %s from %s (%s)",
                  me.id, target_p->name, get_oper_name(source_p), comment);
    log_write(LOG_TYPE_IRCD, "Remote SQUIT %s from %s (%s)",
              target_p->name, get_oper_name(source_p), comment);

    /* To them, we are exiting */
    sendto_one(target_p, ":%s SQUIT %s :%s", source_p->id, me.id, comment);

    /* Send to everything but target and source */
    dlink_node *node;
    DLINK_FOREACH(node, local_server_list.head)
    {
      struct Client *client_p = node->data;

      if (client_p == target_p || client_p == source_p->from)
        continue;

      sendto_one(client_p, ":%s SQUIT %s :%s",
                 source_p->id, target_p->id, comment);
    }
  }
  else
    /* Send to everything but source */
    sendto_server(source_p, 0, 0, ":%s SQUIT %s :%s",
                  source_p->id, target_p->id, comment);

  AddFlag(target_p, FLAGS_SQUIT);

  exit_client(target_p, comment);
}

static struct Command squit_msgtab =
{
  .name = "SQUIT",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_squit, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_squit, .args_min = 2 }
};

static void
module_init(void)
{
  command_add(&squit_msgtab);
}

static void
module_exit(void)
{
  command_del(&squit_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
