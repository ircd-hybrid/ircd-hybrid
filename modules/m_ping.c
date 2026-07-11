/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_ping.c
 * \brief Includes required functions for processing the PING command.
 */

#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

/*! \brief PING command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin
 *      - parv[2] = destination
 */
static void
m_ping(struct Client *source, int parc, char *parv[])
{
  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NOORIGIN);
    return;
  }

  const char *const destination = parv[2];  /* Will get NULL or pointer (parc >= 2!!) */
  if (ConfigServerHide.disable_remote_commands && !client_is_oper(source))
  {
    sendto_one(source, ":%s PONG %s :%s",
               me.name, (destination) ? destination : me.name, parv[1]);
    return;
  }

  struct Client *target = NULL;
  if (string_is_empty(destination) || ((target = client_find_server(source, destination)) && client_is_me(target)))
    sendto_one(source, ":%s PONG %s :%s", me.name, me.name, parv[1]);
  else if (target)
    sendto_one(target, ":%s PING %s :%s",
               client_get_id_or_name(source, target), source->name, client_get_id_or_name(target, target));
  else
    sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, destination);
}

/*! \brief PING command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin
 *      - parv[2] = destination
 */
static void
ms_ping(struct Client *source, int parc, char *parv[])
{
  struct Client *target = NULL;

  const char *const destination = parv[2];
  if (string_is_empty(destination) || ((target = client_find_server(source, destination)) && client_is_me(target)))
    sendto_one(source, ":%s PONG %s :%s",
               client_get_id_or_name(&me, source), me.name, client_get_id_or_name(source, source));
  else if (target)
  {
    if (target->nexthop != source->nexthop)
      sendto_one(target, ":%s PING %s :%s",
                 client_get_id_or_name(source, target), source->name, client_get_id_or_name(target, target));
  }
}

static struct Command command_table =
{
  .name = "PING",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_ping },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_ping, .args_min = 2 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_ping }
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
