/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_quit.c
 * \brief Includes required functions for processing the QUIT command.
 */

#include "io_string.h"
#include "io_time.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "parse.h"

/*! \brief QUIT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = quit message
 */
static void
m_quit(struct Client *source, size_t parc, char *parv[])
{
  const char *reason = "";

  if (!string_is_empty(parv[1]))
    if (client_is_oper(source) ||
        (client_get_session_duration(source) > ConfigGeneral.anti_spam_exit_message_time))
      reason = parv[1];

  client_exit_fmt(source, "Quit: %.*s", KICKLEN, reason);
}

/*! \brief QUIT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = quit message
 */
static void
ms_quit(struct Client *source, size_t parc, char *parv[])
{
  const char *const reason = string_or_default(parv[1], "");
  client_exit_fmt(source, "%.*s", KICKLEN, reason);
}

static struct Command command_table =
{
  .name = "QUIT",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = m_quit },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_quit },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_quit },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_quit }
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
