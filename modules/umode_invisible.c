/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>

#include "module.h"

#include "client.h"
#include "ircd.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (!user_mode_has_flag(client, UMODE_INVISIBLE))
    ++Count.invisi;
  return true;
}

static bool
unset_callback(struct Client *client, user_mode_source_t source)
{
  if (user_mode_has_flag(client, UMODE_INVISIBLE))
    --Count.invisi;
  return true;
}

static struct UserMode invisible_mode =
{
  .mode_char = 'i',
  .mode_flag = &UMODE_INVISIBLE,
  .set_callback = set_callback,
  .unset_callback = unset_callback
};

static void
init_handler(void)
{
  user_mode_register(&invisible_mode);
}

static void
exit_handler(void)
{
  user_mode_unregister(&invisible_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
