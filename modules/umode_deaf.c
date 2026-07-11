/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stddef.h>

#include "module.h"

#include "client.h"
#include "isupport.h"
#include "user_mode.h"

static struct UserMode deaf_mode =
{
  .mode_char = 'D',
  .mode_flag = &UMODE_DEAF
};

static void
init_handler(void)
{
  user_mode_register(&deaf_mode);
  isupport_add("DEAF", "%c", deaf_mode.mode_char);
}

static void
exit_handler(void)
{
  user_mode_unregister(&deaf_mode);
  isupport_delete("DEAF");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
