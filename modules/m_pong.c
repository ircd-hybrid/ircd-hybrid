/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_pong.c
 * \brief Includes required functions for processing the PONG command.
 */

#include <stddef.h>
#include <stdlib.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user.h"

/*! \brief PONG command handler
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
ms_pong(struct Client *source, int parc, char *parv[])
{
  const char *const origin_name = parv[1];
  const char *const destination_name = parv[2];

  struct Client *const target = client_find_entity(source, destination_name);
  if (target == NULL || client_is_me(target))
    return;  /* Target doesn't exist, or it's us. The chain ends here. */

  if (target->nexthop != source->nexthop)
    sendto_one(target, ":%s PONG %s :%s",
               client_get_id_or_name(source, target), origin_name,
               client_get_id_or_name(target, target));
}

/*! \brief PONG command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = origin/ping cookie
 */
static void
mr_pong(struct Client *source, int parc, char *parv[])
{
  assert(client_is_local(source));

  if (string_is_empty(parv[1]))
  {
    sendto_one_numeric(source, &me, ERR_NOORIGIN);
    return;
  }

  if (ConfigGeneral.ping_cookie == 0 || source->connection->ping_cookie_token == 0)
    return;

  unsigned int received_cookie = strtoul(parv[1], NULL, 10);
  if (source->connection->ping_cookie_token != received_cookie)
  {
    sendto_one_numeric(source, &me, ERR_WRONGPONG,
                       source->connection->ping_cookie_token);
    return;
  }

  client_set_flag(source, FLAGS_PING_COOKIE);

  if (source->connection->registration == 0)
    user_register_local(source);
}

static struct Command command_table =
{
  .name = "PONG",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_pong },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_pong, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
