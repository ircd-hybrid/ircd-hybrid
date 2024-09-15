/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file m_mode.c
 * \brief Includes required functions for processing the MODE command.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "client_svstag.h"
#include "cloak.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "user_mode.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/* set_user_mode()
 *
 * added 15/10/91 By Darren Reed.
 * parv[0] - command
 * parv[1] - username to change mode for
 * parv[2] - modes to change
 */
static void
set_user_mode(struct Client *source, const int parc, char *parv[])
{
  const struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
  {
    if (MyConnect(source))
      sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  if (source != target)
  {
     sendto_one_numeric(source, &me, ERR_USERSDONTMATCH);
     return;
  }

  if (parc < 3)
  {
    sendto_one_numeric(source, &me, RPL_UMODEIS,
                       user_mode_to_str(source->umodes));
    return;
  }

  const uint64_t oldmodes = source->umodes;
  user_mode_action_t action = USER_MODE_ACTION_ADD;
  bool badmode = false;

  /* Parse user mode change string */
  for (const char *m = parv[2]; *m; ++m)
  {
    switch (*m)
    {
      case '+':
        action = USER_MODE_ACTION_ADD;
        break;
      case '-':
        action = USER_MODE_ACTION_DEL;
        break;
      default:
        if (user_mode_change(source, *m, USER_MODE_SOURCE_REGULAR, action) == USER_MODE_RESULT_MODE_NOT_FOUND)
          if (MyConnect(source))
            badmode = true;
        break;
    }
  }

  if (badmode)
    sendto_one_numeric(source, &me, ERR_UMODEUNKNOWNFLAG);

  /*
   * Compare new modes with old modes and send string which will cause
   * servers to update correctly.
   */
  user_mode_send(source, oldmodes, MyConnect(source), true);
}

/*! \brief MODE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel or nick name
 *      - parv[2] = modes to be added or removed
 */
static void
m_mode(struct Client *source, int parc, char *parv[])
{
  const char *const name = parv[1];

  /* Now, try to find the channel in question */
  if (!IsChanPrefix(*name))
  {
    /* If here, it has to be a non-channel name */
    set_user_mode(source, parc, parv);
    return;
  }

  struct Channel *channel = hash_find_channel(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  /* Now known the channel exists */
  if (parc < 3)
  {
    sendto_one_numeric(source, &me, RPL_CHANNELMODEIS,
                       channel->name, channel_modes(channel, source, true));
    sendto_one_numeric(source, &me, RPL_CREATIONTIME,
                       channel->name, channel->creation_time);
    return;
  }

  channel_mode_set(source, channel, parc - 2, parv + 2);
}

static struct Command command_table =
{
  .name = "MODE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_mode, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_mode, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_mode, .args_min = 2 }
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
