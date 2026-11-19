/*
 * SPDX-FileCopyrightText: 2015-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "cap.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd_hook.h"
#include "ircd_module.h"
#include "send.h"

static struct Cap *capability;
static const struct CapConfig capability_config =
{
  .name = "invite-notify",
  .flag = CAP_INVITE_NOTIFY,
  .available = true
};

static hook_flow_t
channel_invite_hook(void *context)
{
  const ircd_hook_channel_invite_ctx *const ctx = context;
  const struct Client *const source = ctx->source;

  sendto_channel_local(NULL, ctx->channel, CHACCESS_HALFOP, CAP_INVITE_NOTIFY, 0,
                       ":%s!%s@%s INVITE %s %s", source->name, source->username, source->host,
                       ctx->target->name, ctx->channel->name);

  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_cap(&capability_config, &capability, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_channel_invite, channel_invite_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  hook_uninstall(ircd_hook_channel_invite, channel_invite_hook);
  cap_unregister(&capability);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "cap_invite_notify",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
