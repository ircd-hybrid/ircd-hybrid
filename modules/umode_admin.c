/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>

#include "module.h"

#include "client.h"
#include "conf_oper.h"
#include "user_mode.h"

static bool
set_callback(struct Client *client, user_mode_source_t source)
{
  return !client_is_local(client) || client_has_oper_flag(client, OPER_FLAG_ADMIN);
}

static struct UserMode admin_mode =
{
  .mode_char = 'a',
  .mode_flag = &UMODE_ADMIN,
  .policy = USER_MODE_POLICY_OPER_ONLY | USER_MODE_POLICY_MANUAL_ONLY,
  .set_callback = set_callback
};

static void
init_handler(void)
{
  user_mode_register(&admin_mode);
}

static void
exit_handler(void)
{
  user_mode_unregister(&admin_mode);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
