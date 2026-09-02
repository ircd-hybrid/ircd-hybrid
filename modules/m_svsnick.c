/*
 * SPDX-FileCopyrightText: 1999 Bahamut development team
 * SPDX-FileCopyrightText: 2011-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_svsnick.c
 * \brief Includes required functions for processing the SVSNICK command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "io_parse.h"
#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "ircd.h"
#include "monitor.h"
#include "parse.h"
#include "send.h"
#include "user.h"
#include "user_mode.h"
#include "whowas.h"

/*! \brief SVSNICK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = old nickname
 *      - parv[2] = ignored/unused
 *      - parv[3] = new nickname
 *      - parv[4] = new timestamp
 */
static void
ms_svsnick(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  struct Client *const target = client_find_user(source, parv[1]);
  if (target == NULL)
    return;

  const char *const new_nick = parv[3];
  if (!valid_nickname(new_nick, true))
    return;

  uintmax_t new_nick_timestamp;
  if (io_parse_uintmax(parv[4], &new_nick_timestamp) != IO_PARSE_OK)
    return;

  if (!client_is_local(target))
  {
    if (target->nexthop == source->nexthop)
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Received wrong-direction SVSNICK for %s (behind %s) from %s",
                     target->name, source->nexthop->name, source->name);
      return;
    }

    sendto_one_command(target, source, "SVSNICK", "0 %s %ju", new_nick, new_nick_timestamp);
    return;
  }

  struct Client *const exists_p = client_find_entity_by_name(new_nick);
  if (exists_p)
  {
    if (target == exists_p)
    {
      if (strcmp(target->name, new_nick) == 0)
        return;
    }
    else if (client_is_unknown(exists_p))
      client_exit(exists_p, "SVSNICK Override");
    else
    {
      client_exit(target, "SVSNICK Collide");
      return;
    }
  }

  whowas_add_history(target, true);

  monitor_notify_signoff(target);

  clear_ban_cache_list(&target->channel_member_list);

  if (user_mode_has_flag(target, UMODE_REGISTERED))
  {
    const uint64_t mode_flags_old = target->user_mode_flags;
    user_mode_unset_flag(target, UMODE_REGISTERED);
    user_mode_send(target, mode_flags_old, USER_MODE_SEND_USER);
  }

  sendto_servers(NULL, 0, 0, ":%s NICK %s :%ju",
                 target->id, new_nick, new_nick_timestamp);
  sendto_common_channels_local(target, true, 0, 0, ":%s!%s@%s NICK :%s",
                               target->name, target->username, target->host, new_nick);

  client_update_name(target, new_nick);
  target->nick_timestamp = new_nick_timestamp;

  monitor_notify_signon(target);
}

static struct Command command_table =
{
  .name = "SVSNICK",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_svsnick, .args_min = 5 },
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
