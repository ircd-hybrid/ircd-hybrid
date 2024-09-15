/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999 Bahamut development team.
 *  Copyright (c) 2011-2024 ircd-hybrid development team
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

/*! \file m_svsnick.c
 * \brief Includes required functions for processing the SVSNICK command.
 */


#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "channel.h"
#include "channel_mode.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "irc_string.h"
#include "user.h"
#include "user_mode.h"
#include "hash.h"
#include "monitor.h"
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
 *      - parv[2] = old timestamp
 *      - parv[3] = new nickname
 *      - parv[4] = new timestamp
 */
static void
ms_svsnick(struct Client *source, int parc, char *parv[])
{
  if (!HasFlag(source, FLAGS_SERVICE) && !IsServer(source))
    return;

  const char *new_nick = parv[3];
  if (valid_nickname(new_nick, true) == false)
    return;

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target->tsinfo))
    return;

  uintmax_t new_ts = strtoumax(parv[4], NULL, 10);

  if (!MyConnect(target))
  {
    if (target->from == source->from)
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Received wrong-direction SVSNICK for %s (behind %s) from %s",
                     target->name, source->from->name, client_get_name(source, HIDE_IP));
      return;
    }

    sendto_one(target, ":%s SVSNICK %s %ju %s %ju",
               source->id, target->id, ts, new_nick, new_ts);
    return;
  }

  struct Client *exists_p = hash_find_client(new_nick);
  if (exists_p)
  {
    if (target == exists_p)
    {
      if (strcmp(target->name, new_nick) == 0)
        return;
    }
    else if (IsUnknown(exists_p))
      client_exit(exists_p, "SVSNICK Override");
    else
    {
      client_exit(target, "SVSNICK Collide");
      return;
    }
  }

  target->tsinfo = new_ts;
  clear_ban_cache_list(&target->channel);
  monitor_signoff(target);

  if (user_mode_has_flag(target, UMODE_REGISTERED))
  {
    const uint64_t oldmodes = target->umodes;
    user_mode_unset_flag(target, UMODE_REGISTERED);
    user_mode_send(source, oldmodes, USER_MODE_SEND_CLIENT);
  }

  sendto_common_channels_local(target, true, 0, 0, ":%s!%s@%s NICK :%s",
                               target->name, target->username, target->host, new_nick);

  whowas_add_history(target, true);

  sendto_servers(NULL, 0, 0, ":%s NICK %s :%ju",
                 target->id, new_nick, target->tsinfo);

  hash_del_client(target);
  strlcpy(target->name, new_nick, sizeof(target->name));
  hash_add_client(target);

  monitor_signon(target);

  fd_note(target->connection->fd, "Nick: %s", target->name);
}

static struct Command command_table =
{
  .name = "SVSNICK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svsnick, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
