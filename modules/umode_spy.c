/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "module.h"

#include "ircd_module.h"
#include "client.h"
#include "ircd_hook.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode spy_mode =
{
  .mode_char = 'y',
  .mode_flag = &UMODE_SPY,
  .policy = USER_MODE_POLICY_OPER_ONLY,
};

static void
_spy_send_request_notice(const struct Client *source, const char *command, char selector)
{
  if (selector == '\0')
  {
    sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "SPY: %s requested by %s (%s@%s) [%s]",
                   command, source->name, source->username, source->host, source->uplink->name);
    return;
  }

  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "SPY: %s %c requested by %s (%s@%s) [%s]",
                 command, selector, source->name, source->username, source->host, source->uplink->name);
}

static void
_spy_send_whois_notice(const struct Client *source, struct Client *target)
{
  sendto_one_notice(target, &me,
                    ":*** Notice -- SPY: WHOIS requested for you by %s (%s@%s) [%s]",
                    source->name, source->username, source->host, source->uplink->name);
}

static hook_flow_t
_spy_request_hook(void *ctx_)
{
  const ircd_hook_spy_request_ctx *const ctx = ctx_;
  assert(ctx);
  assert(ctx->source);
  assert(!string_is_empty(ctx->command));

  _spy_send_request_notice(ctx->source, ctx->command, ctx->selector);
  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
_spy_whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *const ctx = ctx_;
  assert(ctx);
  assert(ctx->source);
  assert(ctx->target);

  if (ctx->source == ctx->target)
    return HOOK_FLOW_CONTINUE;

  if (!user_mode_has_flag(ctx->target, UMODE_SPY))
    return HOOK_FLOW_CONTINUE;

  _spy_send_whois_notice(ctx->source, ctx->target);
  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&spy_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_spy_request, _spy_request_hook, HOOK_PRIORITY_LOWEST);
  hook_install(ircd_hook_whois_send, _spy_whois_send_hook, HOOK_PRIORITY_LOWEST);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&spy_mode);
  hook_uninstall(ircd_hook_spy_request, _spy_request_hook);
  hook_uninstall(ircd_hook_whois_send, _spy_whois_send_hook);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_spy",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
