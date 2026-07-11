/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "client.h"
#include "user_mode.h"

static struct UserMode hidden_mode =
{
  .mode_char = 'H',
  .mode_flag = &UMODE_HIDDEN,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static void
init_handler(void)
{
  user_mode_register(&hidden_mode);
}

static void
exit_handler(void)
{
  user_mode_unregister(&hidden_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
