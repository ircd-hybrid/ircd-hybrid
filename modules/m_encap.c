/*
 * SPDX-FileCopyrightText: 2003-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_encap.c
 * \brief Includes required functions for processing the ENCAP command.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

/*
 * ms_encap()
 *
 * inputs	- destination server, subcommand, parameters
 * output	- none
 * side effects	- propagates subcommand to locally connected servers
 */
static void
ms_encap(struct Client *source, int parc, char *parv[])
{
  char buf[IRCD_BUFSIZE];
  char *bufptr = buf;
  size_t cur_len = 0, len;

  for (unsigned int i = 1; i < (unsigned int)parc - 1; ++i)
  {
    len = strlen(parv[i]) + 1;  /* +1 for the space */

    /* Drop the whole command if this parameter would be truncated */
    if ((cur_len + len) >= sizeof(buf))
      return;

    snprintf(bufptr, sizeof(buf) - cur_len, "%s ", parv[i]);
    cur_len += len;
    bufptr += len;
  }

  /* If it's a command without parameters, don't prepend a ':' */
  if (parc == 3)
    snprintf(bufptr, sizeof(buf) - cur_len, "%s", parv[2]);
  else
    snprintf(bufptr, sizeof(buf) - cur_len, ":%s", parv[parc - 1]);

  sendto_match_servs(source, parv[1], CAPAB_ENCAP, "ENCAP %s", buf);

  if (match(parv[1], me.name))
    return;

  struct Command *const command = command_find(parv[2]);
  if (command == NULL)
    return;

  const struct CommandHandler *const handler = &command->handlers[COMMAND_HANDLER_ENCAP];
  command->bytes += strlen(buf);
  command->ecount++;

  parv += 2;
  parc -= 2;

  if (handler->args_min &&
      (((unsigned int)parc < handler->args_min) ||
       (handler->empty_last_arg != true && string_is_empty(parv[handler->args_min - 1]))))
    return;

  handler->handler(source, parc, parv);
}

static struct Command command_table =
{
  .name = "ENCAP",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_encap, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("ENCAP", CAPAB_ENCAP, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("ENCAP");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
