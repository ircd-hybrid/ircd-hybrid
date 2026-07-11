/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "cap.h"

static void
init_handler(void)
{
  cap_register(CAP_INVITE_NOTIFY, "invite-notify", NULL);
}

static void
exit_handler(void)
{
  cap_unregister("invite-notify");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
  .resident = true  /* XXX for now until caps are completely modular */
};
