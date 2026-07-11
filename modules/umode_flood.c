/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "client.h"
#include "user_mode.h"

static struct UserMode flood_mode =
{
  .mode_char = 'f',
  .mode_flag = &UMODE_FLOOD,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static void
init_handler(void)
{
  user_mode_register(&flood_mode);
}

static void
exit_handler(void)
{
  user_mode_unregister(&flood_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
