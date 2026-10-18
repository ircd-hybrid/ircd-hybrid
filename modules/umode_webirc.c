/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode webirc_mode =
{
  .mode_char = 'W',
  .mode_flag = &UMODE_WEBIRC,
  .policy = USER_MODE_POLICY_INTERNAL_ONLY,
};

static hook_flow_t
whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *ctx = ctx_;

  if (user_mode_has_flag(ctx->target, UMODE_WEBIRC))
    sendto_one_numeric(ctx->source, &me, RPL_WHOISTEXT,
                       ctx->target->name, "User connected using a webirc gateway");

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&webirc_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_whois_send, whois_send_hook, HOOK_PRIORITY_NORMAL);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&webirc_mode);
  hook_uninstall(ircd_hook_whois_send, whois_send_hook);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_webirc",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
