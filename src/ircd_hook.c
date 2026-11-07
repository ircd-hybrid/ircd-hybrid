/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "hook.h"
#include "list.h"

#include "ircd_hook.h"

struct HookContainer *ircd_hook_client_exit_local;
struct HookContainer *ircd_hook_client_exit_remote;
struct HookContainer *ircd_hook_msg_client_source_local;
struct HookContainer *ircd_hook_msg_client_target_local;
struct HookContainer *ircd_hook_nick_change_local;
struct HookContainer *ircd_hook_nick_change_remote;
struct HookContainer *ircd_hook_spy_request;
struct HookContainer *ircd_hook_user_register_local;
struct HookContainer *ircd_hook_user_register_remote;
struct HookContainer *ircd_hook_who_send;
struct HookContainer *ircd_hook_whois_send;

void
ircd_hook_init(void)
{
  ircd_hook_client_exit_local = hook_container_register("client_exit_local");
  ircd_hook_client_exit_remote = hook_container_register("client_exit_remote");
  ircd_hook_msg_client_source_local = hook_container_register("msg_client_source_local");
  ircd_hook_msg_client_target_local = hook_container_register("msg_client_target_local");
  ircd_hook_nick_change_local = hook_container_register("nick_change_local");
  ircd_hook_nick_change_remote = hook_container_register("nick_change_remote");
  ircd_hook_spy_request = hook_container_register("spy_request");
  ircd_hook_user_register_local = hook_container_register("user_register_local");
  ircd_hook_user_register_remote = hook_container_register("user_register_remote");
  ircd_hook_who_send = hook_container_register("who_send");
  ircd_hook_whois_send = hook_container_register("whois_send");
}
