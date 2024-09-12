/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
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

#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "user_mode.h"


static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  if (user_mode_has_flag(client, UMODE_INVISIBLE) == false)
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
