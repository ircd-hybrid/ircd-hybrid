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
#include "modules.h"
#include "irc_string.h"
#include "user.h"
#include "hash.h"
#include "monitor.h"
#include "whowas.h"


/*! \brief SVSNICK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_svsnick(struct Client *source_p, int parc, char *parv[])
{
  const char *new_nick = parv[3];

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return;

  if (valid_nickname(new_nick, true) == false)
    return;

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target_p->tsinfo))
    return;

  uintmax_t new_ts = strtoumax(parv[4], NULL, 10);

  if (!MyConnect(target_p))
  {
    if (target_p->from == source_p->from)
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "Received wrong-direction SVSNICK "
                           "for %s (behind %s) from %s",
                           target_p->name, source_p->from->name,
                           client_get_name(source_p, HIDE_IP));
      return;
    }

    sendto_one(target_p, ":%s SVSNICK %s %ju %s %ju", source_p->id,
               target_p->id, ts, new_nick, new_ts);
    return;
  }

  struct Client *exists_p = hash_find_client(new_nick);
  if (exists_p)
  {
    if (target_p == exists_p)
    {
      if (strcmp(target_p->name, new_nick) == 0)
        return;
    }
    else if (IsUnknown(exists_p))
      exit_client(exists_p, "SVSNICK Override");
    else
    {
      exit_client(target_p, "SVSNICK Collide");
      return;
    }
  }

  target_p->tsinfo = new_ts;
  clear_ban_cache_list(&target_p->channel);
  monitor_signoff(target_p);

  if (HasUMode(target_p, UMODE_REGISTERED))
  {
    const unsigned int oldmodes = target_p->umodes;
    char buf[UMODE_MAX_STR] = "";

    DelUMode(target_p, UMODE_REGISTERED);
    send_umode(target_p, true, oldmodes, buf);
  }

  sendto_common_channels_local(target_p, true, 0, 0, ":%s!%s@%s NICK :%s",
                               target_p->name, target_p->username,
                               target_p->host, new_nick);

  whowas_add_history(target_p, true);

  sendto_server(NULL, 0, 0, ":%s NICK %s :%ju",
                target_p->id, new_nick, target_p->tsinfo);

  hash_del_client(target_p);
  strlcpy(target_p->name, new_nick, sizeof(target_p->name));
  hash_add_client(target_p);

  monitor_signon(target_p);

  fd_note(target_p->connection->fd, "Nick: %s", target_p->name);
}

static struct Message svsnick_msgtab =
{
  .cmd = "SVSNICK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svsnick, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svsnick_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svsnick_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
