/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include <stddef.h>

#include "io_string.h"
#include "list.h"
#include "log.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "client_find.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static const char *
_squit_get_reason(const struct Client *source, const char *reason)
{
  if (!string_is_empty(reason))
    return reason;

  if (client_is_user(source))
    return source->name;

  return client_get_visible_server_name(source);
}

static void
_squit_report_local_request(const struct Client *source, const struct Client *target, const char *reason)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Received SQUIT %s from %s (%.*s)",
                 target->name, source_name, REASONLEN, reason);
  log_write(LOG_TYPE_IRCD, "SQUIT %s from %s (%.*s)",
            target->name, source_name, REASONLEN, reason);
}

static void
_squit_report_remote_request(const struct Client *source, const struct Client *target, const char *reason)
{
  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_GLOBAL,
                 "from %s: Remote SQUIT %s from %s (%.*s)",
                 me.name, target->name, source_name, REASONLEN, reason);
  sendto_servers(source, 0, 0, ":%s GLOBOPS :Remote SQUIT %s from %s (%.*s)",
                 me.id, target->name, source_name, REASONLEN, reason);
  log_write(LOG_TYPE_IRCD, "Remote SQUIT %s from %s (%.*s)",
            target->name, source_name, REASONLEN, reason);
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
 *      - parv[2] = reason
 */
static void
mo_squit(struct Client *source, int parc, char *parv[])
{
  const char *const target_name = parv[1];
  struct Client *target = NULL;

  /* The following allows wild cards in SQUIT. */
  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    struct Client *const tmp = node->data;
    if (client_is_server(tmp))
    {
      if (match(target_name, tmp->name) == 0)
      {
        target = tmp;
        break;
      }
    }
  }

  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHSERVER, target_name);
    return;
  }

  if (!client_is_local(target) && !client_has_oper_flag(source, OPER_FLAG_SQUIT_REMOTE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "squit:remote");
    return;
  }

  if (client_is_local(target) && !client_has_oper_flag(source, OPER_FLAG_SQUIT))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "squit");
    return;
  }

  const char *const reason = _squit_get_reason(source, parv[2]);
  if (client_is_local(target))
  {
    _squit_report_local_request(source, target, reason);

    /* To them, we are exiting */
    sendto_one(target, ":%s SQUIT %s :%.*s", source->id, me.id, REASONLEN, reason);

    /* Send to everything but target */
    sendto_servers(target, 0, 0, ":%s SQUIT %s :%.*s",
                   source->id, target->id, REASONLEN, reason);
  }
  else
    /* Send to everything */
    sendto_servers(NULL, 0, 0, ":%s SQUIT %s :%.*s",
                   source->id, target->id, REASONLEN, reason);

  client_set_flag(target, FLAGS_SQUIT);

  client_exit_fmt(target, "%.*s", REASONLEN, reason);
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
 *      - parv[2] = reason
 */
static void
ms_squit(struct Client *source, int parc, char *parv[])
{
  struct Client *target = client_find_server(source, parv[1]);
  if (target == NULL)
    return;

  if (client_is_me(target))
    target = source->nexthop;

  const char *const reason = _squit_get_reason(source, parv[2]);
  if (client_is_local(target))
  {
    _squit_report_remote_request(source, target, reason);

    /* To them, we are exiting */
    sendto_one(target, ":%s SQUIT %s :%s", source->id, me.id, reason);

    /* Send to everything but target and source */
    list_node_t *node;
    LIST_FOREACH(node, local_server_list.head)
    {
      struct Client *const client = node->data;
      if (client == target || client == source->nexthop)
        continue;

      sendto_one(client, ":%s SQUIT %s :%s",
                 source->id, target->id, reason);
    }
  }
  else
    /* Send to everything but source */
    sendto_servers(source, 0, 0, ":%s SQUIT %s :%s",
                   source->id, target->id, reason);

  client_set_flag(target, FLAGS_SQUIT);

  client_exit(target, reason);
}

static struct Command command_table =
{
  .name = "SQUIT",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_squit, .args_min = 2 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_squit, .args_min = 2 }
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
