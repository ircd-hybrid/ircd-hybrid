/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_ison.c
 * \brief Includes required functions for processing the ISON command.
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "module.h"

#include "client.h"
#include "client_find.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

/*! \brief ISON command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = space-separated list of nicknames
 */
static void
m_ison(struct Client *source, size_t parc, char *parv[])
{
  char buf[IRCD_BUFSIZE] = "";  /* Essential that buf[0] = '\0' */
  char *bufptr = buf;

  /* :me.name 303 source->name :nick1 nick2 ...      \r\n */
  /* 1       23456            78                     9 0  */
  const size_t len = strlen(me.name) + strlen(source->name) + 10;

  char *saveptr = NULL;
  for (const char *name = strtok_r(parv[1], " ", &saveptr); name;
                   name = strtok_r(NULL,    " ", &saveptr))
  {
    const struct Client *const target = client_find_user_by_name(name);
    if (target == NULL)
      continue;

    if ((bufptr - buf) + strlen(target->name) + len + 1 /* +1 for space */ > sizeof(buf))
      break;

    bufptr += snprintf(bufptr, sizeof(buf) - (bufptr - buf), bufptr != buf ? " %s" : "%s", target->name);
  }

  sendto_one_numeric(source, &me, RPL_ISON, buf);
}

static struct Command command_table =
{
  .name = "ISON",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_ison, .args_min = 2, .args_max = 1 },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_ison, .args_min = 2, .args_max = 1 }
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
