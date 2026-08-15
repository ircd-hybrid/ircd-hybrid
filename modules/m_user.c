/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_user.c
 * \brief Includes required functions for processing the USER command.
 */

#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "listener.h"
#include "parse.h"
#include "user.h"

/*! \brief USER command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = username (login name, account)
 *      - parv[2] = client host name (ignored)
 *      - parv[3] = server host name (ignored)
 *      - parv[4] = user's real name info
 */
static void
mr_user(struct Client *source, int parc, char *parv[])
{
  const char *const username = parv[1];
  const char *const realname = parv[4];

  assert(client_is_unknown(source));

  if (listener_has_flag(source->connection->listener, LISTENER_SERVER))
  {
    client_exit(source, "Use a different port");
    return;
  }

  if (!client_has_flag(source, FLAGS_GOTID))
  {
    char *p = strchr(username, '@');
    if (p)
      *p = '\0';

    strlcpy(source->username, username, sizeof(source->username));
  }

  strlcpy(source->info, realname, sizeof(source->info));
  source->connection->registration_flags &= ~REG_NEED_USER;

  if (source->connection->registration_flags == 0)
    user_register_local(source);
}

static struct Command command_table =
{
  .name = "USER",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_user, .args_min = 5 },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_already_registered },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_reject_already_registered }
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
