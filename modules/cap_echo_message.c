/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "cap.h"
#include "client.h"
#include "ircd_hook.h"
#include "send.h"

static hook_flow_t
msg_sent_hook(void *ctx_)
{
  const ircd_hook_msg_sent_ctx *const ctx = ctx_;
  struct Client *const source = ctx->source;

  if (!client_is_local_user(source) || !client_has_cap(source, CAP_ECHO_MESSAGE))
    return HOOK_FLOW_CONTINUE;

  const char prefix[] = { ctx->status_prefix, '\0' };
  sendto_one(source, ":%s!%s@%s %s %s%s :%s",
             source->name, source->username, source->host,
             ctx->command, prefix, ctx->target, ctx->text);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_cap(CAP_ECHO_MESSAGE, "echo-message", NULL,
                                error_message, error_message_size))
    return false;

  hook_install(ircd_hook_msg_sent, msg_sent_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_msg_sent, msg_sent_hook);
  cap_unregister("echo-message");
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "cap_echo_message",
  .flags = MODULE_FLAG_NO_DEACTIVATE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
