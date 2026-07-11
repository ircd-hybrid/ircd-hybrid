/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_svstag.c
 * \brief Includes required functions for processing the SVSTAG command.
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "module.h"

#include "client.h"
#include "client_find.h"
#include "client_svstag.h"
#include "parse.h"
#include "send.h"

/*! \brief SVSTAG command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = ignored/unused
 *      - parv[3] = [-][raw]
 *      - parv[4] = required user mode(s) to see the tag
 *      - parv[5] = tag line
 */
static void
ms_svstag(struct Client *source, int parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  struct Client *const target = client_find_user(source, parv[1]);
  if (target == NULL)
    return;

  if (strcmp(parv[3], "-") == 0)
  {
    svstag_clear_list(&target->svstag_list);
    sendto_servers(source, 0, 0, ":%s SVSTAG %s 0 -",
                   source->id, target->id);
    return;
  }

  if (string_is_empty(parv[5]))
    return;

  svstag_attach(&target->svstag_list, strtoul(parv[3], NULL, 10), parv[4], parv[5]);

  sendto_servers(source, 0, 0, ":%s SVSTAG %s 0 %s %s :%s",
                 source->id, target->id, parv[3], parv[4], parv[5]);
}

static struct Command command_table =
{
  .name = "SVSTAG",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_svstag, .args_min = 4 },
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
