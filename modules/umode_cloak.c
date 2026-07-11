/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "client.h"
#include "cloak.h"
#include "user.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (source != USER_MODE_SOURCE_REGULAR)
    return false;

  if (user_mode_has_flag(client, UMODE_CLOAK))
    return false;

  if (client_is_local(client))
  {
    if (client_has_flag(client, FLAGS_SPOOF))
      return false;

    const char *const cloak = cloak_compute(&client->addr);
    if (cloak == NULL)
      return false;

    bool svshost = client_has_flag(client, FLAGS_INTRODUCED);
    user_set_hostmask(client, cloak, svshost);
  }

  return true;
}

static bool
unset_callback(struct Client *client, user_mode_source_t source)
{
  if (source != USER_MODE_SOURCE_REGULAR)
    return false;

  if (!user_mode_has_flag(client, UMODE_CLOAK))
    return false;

  if (client_is_local(client))
    user_set_hostmask(client, client->realhost, true);
  return true;
}

static struct UserMode cloak_mode =
{
  .mode_char = 'x',
  .mode_flag = &UMODE_CLOAK,
  .set_callback = set_callback,
  .unset_callback = unset_callback
};

static void
init_handler(void)
{
  user_mode_register(&cloak_mode);
}

static void
exit_handler(void)
{
  user_mode_unregister(&cloak_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .core = true
};
