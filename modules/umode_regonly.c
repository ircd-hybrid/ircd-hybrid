/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>
#include <stddef.h>

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode regonly_mode =
{
  .mode_char = 'R',
  .mode_flag = &UMODE_REGONLY
};

static hook_flow_t
msg_client_source_local_hook(void *ctx_)
{
  ircd_hook_msg_client_ctx *ctx = ctx_;
  if (!user_mode_has_flag(ctx->target, UMODE_REGONLY) || ctx->target == ctx->source)
    return HOOK_FLOW_CONTINUE;

  if (user_mode_has_flag(ctx->source, UMODE_REGISTERED | UMODE_OPER))
    return HOOK_FLOW_CONTINUE;

  if (ctx->notice == false)
    sendto_one_numeric(ctx->source, &me, ERR_CANNOTSENDTOUSER,
                       ctx->target->name, "You must identify to a registered account to message this user");

  return HOOK_FLOW_STOP;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&regonly_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_msg_client_source_local, msg_client_source_local_hook, HOOK_PRIORITY_DEFAULT);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&regonly_mode);
  hook_uninstall(ircd_hook_msg_client_source_local, msg_client_source_local_hook);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_regonly",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
