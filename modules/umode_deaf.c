/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stddef.h>

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "isupport.h"
#include "user_mode.h"

static struct UserMode deaf_mode =
{
  .mode_char = 'D',
  .mode_flag = &UMODE_DEAF
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&deaf_mode, error_message, error_message_size))
    return false;
  isupport_add("DEAF", "%c", deaf_mode.mode_char);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&deaf_mode);
  isupport_delete("DEAF");
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_deaf",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
