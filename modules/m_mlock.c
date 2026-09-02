/*
 * SPDX-FileCopyrightText: 2022-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_mlock.c
 * \brief Includes required functions for processing the MLOCK command.
 */

#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

#include "io_parse.h"
#include "io_string.h"
#include "list.h"
#include "module.h"

#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static bool
_mlock_should_accept(const struct Client *source, const struct Channel *channel,
                     uintmax_t channel_ts, uintmax_t mode_lock_ts,
                     const char *mode_lock)
{
  if (channel_ts > channel->creation_time)
    return false;

  if (client_is_service(source))
    return true;

  if (channel_ts < channel->creation_time)
    return true;

  if (mode_lock_ts > channel->mode_lock_time)
    return true;

  if (mode_lock_ts < channel->mode_lock_time)
    return false;

  return strcmp(string_or_empty(channel->mode_lock), mode_lock) == 0;
}

static void
_mlock_commit(struct Client *source, struct Channel *channel, uintmax_t channel_ts, uintmax_t mode_lock_ts,
              const char *mode_lock)
{
  channel_set_mode_lock(source, channel, mode_lock);
  channel->mode_lock_time = mode_lock_ts;

  sendto_servers(source, 0, 0, ":%s MLOCK %ju %s %ju :%s",
                 source->id, channel_ts, channel->name, mode_lock_ts, string_or_empty(channel->mode_lock));
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
ms_mlock(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_service(source) && !client_is_server(source))
    return;

  struct Channel *const channel = channel_find(parv[2]);
  if (channel == NULL)
    return;

  uintmax_t channel_ts;
  if (io_parse_uintmax(parv[1], &channel_ts) != IO_PARSE_OK)
    return;

  uintmax_t mode_lock_ts;
  if (io_parse_uintmax(parv[3], &mode_lock_ts) != IO_PARSE_OK)
    return;

  const char *const mode_lock = parv[4];
  if (!_mlock_should_accept(source, channel, channel_ts, mode_lock_ts, mode_lock))
    return;

  _mlock_commit(source, channel, channel_ts, mode_lock_ts, mode_lock);
}

static struct Command command_table =
{
  .name = "MLOCK",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_mlock, .args_min = 5, .empty_last_arg = true },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
