/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <stdbool.h>
#include <stddef.h>

#include "io_time.h"
#include "module.h"

#include "ircd_module.h"
#include "accept.h"
#include "client.h"
#include "conf.h"
#include "ircd_hook.h"
#include "isupport.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"

static struct UserMode softcallerid_mode =
{
  .mode_char = 'G',
  .mode_flag = &UMODE_SOFTCALLERID
};

static hook_flow_t
msg_client_target_local_hook(void *ctx_)
{
  ircd_hook_msg_client_ctx *ctx = ctx_;

  if (!user_mode_has_flag(ctx->target, UMODE_SOFTCALLERID))
    return HOOK_FLOW_CONTINUE;

  if (accept_message(ctx->source, ctx->target))
    return HOOK_FLOW_CONTINUE;

  if (ctx->notice == false)
    sendto_one_numeric(ctx->source, &me, RPL_TARGUMODEG,
                       ctx->target->name, softcallerid_mode.mode_char, "server side ignore with the exception of common channels");

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  if (now - ctx->target->connection->last_caller_id_time > ConfigGeneral.caller_id_wait)
  {
    if (ctx->notice == false)
      sendto_one_numeric(ctx->source, &me, RPL_TARGNOTIFY, ctx->target->name);

    sendto_one_numeric(ctx->target, &me, RPL_UMODEGMSG,
                       ctx->source->name, ctx->source->username, ctx->source->host, softcallerid_mode.mode_char);
    ctx->target->connection->last_caller_id_time = now;
  }

  return HOOK_FLOW_STOP;
}

static hook_flow_t
whois_send_hook(void *ctx_)
{
  ircd_hook_whois_send_ctx *ctx = ctx_;

  if (!user_mode_has_flag(ctx->target, UMODE_SOFTCALLERID))
    return HOOK_FLOW_CONTINUE;

  if (user_mode_has_flag(ctx->target, UMODE_CALLERID))
    return HOOK_FLOW_CONTINUE;

  sendto_one_numeric(ctx->source, &me, RPL_TARGUMODEG,
                     ctx->target->name, softcallerid_mode.mode_char, "server side ignore with the exception of common channels");
  return HOOK_FLOW_CONTINUE;
}

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_user_mode(&softcallerid_mode, error_message, error_message_size))
    return false;

  hook_install(ircd_hook_msg_client_target_local, msg_client_target_local_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_whois_send, whois_send_hook, HOOK_PRIORITY_NORMAL);

  return true;
}

static void
exit_handler(void *context)
{
  user_mode_unregister(&softcallerid_mode);
  hook_uninstall(ircd_hook_msg_client_target_local, msg_client_target_local_hook);
  hook_uninstall(ircd_hook_whois_send, whois_send_hook);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "umode_softcallerid",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
