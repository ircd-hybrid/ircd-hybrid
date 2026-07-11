/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "client.h"
#include "user_mode.h"

static struct UserMode hideidle_mode =
{
  .mode_char = 'q',
  .mode_flag = &UMODE_HIDEIDLE
};

static void
init_handler(void)
{
  user_mode_register(&hideidle_mode);
}

static void
exit_handler(void)
{
  user_mode_unregister(&hideidle_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
