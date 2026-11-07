/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_ircd_hook_h
#define INCLUDED_ircd_hook_h
#include <stdbool.h>
#include <stddef.h>

#include "hook.h"

#include "client.h"

typedef struct
{
  struct Client *client;
  const char *reason;
} ircd_hook_client_exit_ctx;

typedef struct
{
  bool notice;
  struct Client *source;
  struct Client *target;
  const char *text;
} ircd_hook_msg_client_ctx;

typedef struct
{
  struct Client *client;
  const char *nick;
} ircd_hook_nick_change_ctx;

typedef struct
{
  const struct Client *source;
  const char *command;
  char selector;
} ircd_hook_spy_request_ctx;

typedef struct
{
  struct Client *client;
} ircd_hook_user_register_ctx;

typedef struct
{
  const struct Client *source;
  const struct Client *target;
  char modes[32];
  size_t modes_len;
} ircd_hook_who_send_ctx;

typedef struct
{
  struct Client *source;
  struct Client *target;
} ircd_hook_whois_send_ctx;

extern struct HookContainer *ircd_hook_client_exit_local;
extern struct HookContainer *ircd_hook_client_exit_remote;
extern struct HookContainer *ircd_hook_msg_client_source_local;
extern struct HookContainer *ircd_hook_msg_client_target_local;
extern struct HookContainer *ircd_hook_nick_change_local;
extern struct HookContainer *ircd_hook_nick_change_remote;
extern struct HookContainer *ircd_hook_spy_request;
extern struct HookContainer *ircd_hook_user_register_local;
extern struct HookContainer *ircd_hook_user_register_remote;
extern struct HookContainer *ircd_hook_who_send;
extern struct HookContainer *ircd_hook_whois_send;

extern void ircd_hook_init(void);
#endif  /* INCLUDED_ircd_hook_h */
