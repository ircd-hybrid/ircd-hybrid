/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2022-2026 ircd-hybrid development team
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

/*! \file m_mlock.c
 * \brief Includes required functions for processing the MLOCK command.
 */

#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

#include "io_string.h"
#include "list.h"
#include "module.h"

#include "channel.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static bool
_mlock_should_accept(const struct Client *source, const struct Channel *channel,
                     uintmax_t channel_ts, uintmax_t mode_lock_ts)
{
  if (channel_ts > channel->creation_time)
    return false;

  if (client_is_service(source))
    return true;

  if (channel_ts < channel->creation_time)
    return true;

  return mode_lock_ts >= channel->mode_lock_time;
}

static void
_mlock_commit(struct Client *source, struct Channel *channel, const char *mode_lock, uintmax_t mode_lock_ts)
{
  channel_set_mode_lock(source, channel, mode_lock);
  channel->mode_lock_time = mode_lock_ts;

  sendto_servers(source, 0, 0, ":%s MLOCK %ju %s %ju :%s",
                 source->id, channel->creation_time, channel->name, channel->mode_lock_time,
                 string_or_empty(channel->mode_lock));
}

/*! \brief MLOCK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = timestamp
 *      - parv[2] = channel name
 *      - parv[3] = timestamp of the mode lock
 *      - parv[4] = modes to be locked
 */
static void
ms_mlock(struct Client *source, int parc, char *parv[])
{
  assert(!client_is_local_user(source));

  struct Channel *const channel = hash_find_channel(parv[2]);
  if (channel == NULL)
    return;

  const uintmax_t channel_ts = strtoumax(parv[1], NULL, 10);
  const uintmax_t mode_lock_ts = strtoumax(parv[3], NULL, 10);
  if (!_mlock_should_accept(source, channel, channel_ts, mode_lock_ts))
    return;

  _mlock_commit(source, channel, parv[4], mode_lock_ts);
}

static struct Command command_table =
{
  .name = "MLOCK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_mlock, .args_min = 5, .empty_last_arg = true },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("MLOCK", CAPAB_MLOCK, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("MLOCK");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
