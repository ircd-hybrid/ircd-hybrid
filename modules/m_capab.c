/*
 * SPDX-FileCopyrightText: 1998-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_capab.c
 * \brief Includes required functions for processing the CAPAB command.
 */

#include <stddef.h>
#include <string.h>

#include "module.h"

#include "client.h"
#include "parse.h"
#include "server_capab.h"

/*! \brief CAPAB command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = space-separated list of capabilities
 */
static void
mr_capab(struct Client *source, int parc, char *parv[])
{
  char *const list = parv[1];
  char *saveptr = NULL;

  for (const char *name = strtok_r(list, " ", &saveptr); name;
                   name = strtok_r(NULL, " ", &saveptr))
  {
    unsigned int flag = capab_find(name);
    if (flag)
      capab_set_flag(source, flag);
  }
}

static struct Command command_table =
{
  .name = "CAPAB",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_capab, .args_min = 2 },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
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
