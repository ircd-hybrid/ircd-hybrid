/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_mode.c
 * \brief Includes required functions for processing the MODE command.
 */

#include <assert.h>
#include <stddef.h>

#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "client_find.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

/* set_user_mode()
 *
 * added 15/10/91 By Darren Reed.
 * parv[0] - command
 * parv[1] - username to change mode for
 * parv[2] - modes to change
 */
static void
set_user_mode(struct Client *source, size_t parc, char *parv[])
{
  const char *const target_name = parv[1];

  const struct Client *const target = client_find_user(source, target_name);
  if (target == NULL)
  {
    if (client_is_local(source))
      sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, target_name);
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
                       user_mode_to_str(source->user_mode_flags));
    return;
  }

  const uint64_t mode_flags_old = source->user_mode_flags;
  user_mode_action_t action = USER_MODE_ACTION_ADD;
  bool badmode = false;

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
          if (client_is_local(source))
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
  user_mode_send(source, mode_flags_old,
                 (client_is_local(source) ? USER_MODE_SEND_USER : 0) | USER_MODE_SEND_SERVER);
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
m_mode(struct Client *source, size_t parc, char *parv[])
{
  const char *const name = parv[1];
  if (!channel_is_valid_prefix_char(*name))
  {
    set_user_mode(source, parc, parv);
    return;
  }

  struct Channel *const channel = channel_find(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

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
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_mode, .args_min = 2 },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = m_mode, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = m_mode, .args_min = 2 }
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
