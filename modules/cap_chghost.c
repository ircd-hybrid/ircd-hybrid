/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "cap.h"

static struct Cap *capability;
static const struct CapConfig capability_config =
{
  .name = "chghost",
  .flag = CAP_CHGHOST,
  .available = true
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_cap(&capability_config, &capability, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  cap_unregister(&capability);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "cap_chghost",
  .flags = MODULE_FLAG_NO_DEACTIVATE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
