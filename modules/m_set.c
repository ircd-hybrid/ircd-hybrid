/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file m_set.c
 * \brief Includes required functions for processing the SET command.
 */

#include "stdinc.h"
#include "defaults.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "module.h"

enum { SET_COMMAND_LIST_SIZE = 128 };

struct SetStruct
{
  const char *const name;
  unsigned int *const ptr;
  const bool wants_bool;
  const int value_min;
  const int value_max;
};

static struct SetStruct set_cmd_table[] =
{
  { .name = "AUTOCONNECT", .ptr = &GlobalSetOptions.autoconnect, .wants_bool = true, .value_max = 1 },
  { .name = "FLOODCOUNT", .ptr = &GlobalSetOptions.floodcount, .value_max = INT_MAX },
  { .name = "FLOODTIME", .ptr = &GlobalSetOptions.floodtime, .value_max = INT_MAX },
  { .name = "MAX", .ptr = &GlobalSetOptions.maxclients, .value_min = 1, .value_max = INT_MAX },
  { .name = "SPAMNUM", .ptr = &GlobalSetOptions.spam_num, .value_min = MIN_SPAM_NUM, .value_max = INT_MAX },
  { .name = "SPAMTIME", .ptr = &GlobalSetOptions.spam_time, .value_min = MIN_SPAM_TIME, .value_max = INT_MAX },
  { .name = "JFLOODTIME", .ptr = &GlobalSetOptions.joinfloodtime, .value_max = INT_MAX },
  { .name = "JFLOODCOUNT", .ptr = &GlobalSetOptions.joinfloodcount, .value_max = INT_MAX },
  { .name = NULL }
};

static void
set_option(struct Client *source, struct SetStruct *option, int value_new)
{
  static const char *const status[] = { "OFF", "ON" };

  if (value_new >= 0)
  {
    if (value_new < option->value_min || value_new > option->value_max)
    {
      sendto_one_notice(source, &me, ":Value for %s must be between %i and %i",
                        option->name, option->value_min, option->value_max);
      return;
    }

    *option->ptr = value_new;

    if (option->wants_bool)
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s has changed %s to %s",
                     get_oper_name(source), option->name, status[*option->ptr != 0]);
    else
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s has changed %s to %i",
                     get_oper_name(source), option->name, *option->ptr);
  }
  else
  {
    if (option->wants_bool)
      sendto_one_notice(source, &me, ":%s is currently %s", option->name, status[*option->ptr != 0]);
    else
      sendto_one_notice(source, &me, ":%s is currently %i", option->name, *option->ptr);
  }
}

/*
 * list_quote_commands() sends the client all the available commands.
 */
static void
set_option_list(struct Client *source)
{
  char command_list[SET_COMMAND_LIST_SIZE] = "";

  for (const struct SetStruct *tab = set_cmd_table; tab->name; ++tab)
  {
    strlcat(command_list, tab->name, sizeof(command_list));
    if ((tab + 1)->name)
      strlcat(command_list, " ", sizeof(command_list));
  }

  sendto_one_notice(source, &me, ":Available QUOTE SET commands: %s", command_list);
}

static struct SetStruct *
set_option_find(const char *name)
{
  for (struct SetStruct *tab = set_cmd_table; tab->name; ++tab)
    if (irccmp(tab->name, name) == 0)
      return tab;

  return NULL;
}

static void
mo_set(struct Client *source, int parc, char *parv[])
{
  if (!HasOFlag(source, OPER_FLAG_SET))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "set");
    return;
  }

  if (EmptyString(parv[1]))
  {
    set_option_list(source);
    return;
  }

  if (EmptyString(parv[2]))
  {
    sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, "SET");
    return;
  }

  struct SetStruct *option = set_option_find(parv[1]);
  if (option == NULL)
  {
    sendto_one_notice(source, &me, ":Unknown setting '%s'. Use /QUOTE SET to list available options.", parv[1]);
    return;
  }

  int value_new = -1;
  const char *const arg = parv[2];
  if (irccmp(arg, "yes") == 0 || irccmp(arg, "on") == 0)
    value_new = 1;
  else if (irccmp(arg, "no") == 0 || irccmp(arg, "off") == 0)
    value_new = 0;
  else
    value_new = atoi(arg);

  if (value_new < 0)
  {
    sendto_one_notice(source, &me, ":Invalid value for '%s'. Please use a non-negative value.", option->name);
    return;
  }

  set_option(source, option, value_new);
}

static struct Command command_table =
{
  .name = "SET",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_set }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
