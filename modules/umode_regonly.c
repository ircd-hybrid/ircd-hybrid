/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2024-2024 ircd-hybrid development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "numeric.h"
#include "send.h"
#include "ircd_hook.h"
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

  if (user_mode_has_flag(ctx->target, UMODE_REGONLY) && ctx->target != ctx->source)
  {
    if (user_mode_has_flag(ctx->source, UMODE_REGISTERED | UMODE_OPER) == false)
    {
      if (ctx->notice == false)
        sendto_one_numeric(ctx->source, &me, ERR_CANNOTSENDTOUSER, ctx->target->name,
                           "You must identify to a registered account to message this user");
      return HOOK_FLOW_STOP;
    }
  }

  return HOOK_FLOW_CONTINUE;
}

static void
init_handler(void)
{
  user_mode_register(&regonly_mode);
  hook_install(ircd_hook_msg_client_source_local, msg_client_source_local_hook, HOOK_PRIORITY_DEFAULT);
}

static void
exit_handler(void)
{
  user_mode_unregister(&regonly_mode);
  hook_uninstall(ircd_hook_msg_client_source_local, msg_client_source_local_hook);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
