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

#include "stdinc.h"
#include "list.h"
#include "hook.h"
#include "ircd_hook.h"

struct HookContainer *ircd_hook_msg_client_source_local;
struct HookContainer *ircd_hook_msg_client_target_local;
struct HookContainer *ircd_hook_nick_change_local;
struct HookContainer *ircd_hook_nick_change_remote;
struct HookContainer *ircd_hook_whois_send;

void
ircd_hook_init(void)
{
  ircd_hook_msg_client_source_local = hook_container_register("msg_client_source_local");
  ircd_hook_msg_client_target_local = hook_container_register("msg_client_target_local");
  ircd_hook_nick_change_local = hook_container_register("nick_change_local");
  ircd_hook_nick_change_remote = hook_container_register("nick_change_remote");
  ircd_hook_whois_send = hook_container_register("whois_send");
}
