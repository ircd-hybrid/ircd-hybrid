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
#include "client.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "misc.h"

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
  { .name = "AUTOCONNALL", .ptr = &GlobalSetOptions.autoconn, .wants_bool = true, .value_max = 1 },
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
set_option(struct Client *source_p, struct SetStruct *option, int newval)
{
  static const char *const status[] = { "OFF", "ON" };

  if (newval >= 0)
  {
    if (newval < option->value_min || newval > option->value_max)
    {
      sendto_one_notice(source_p, &me, ":Value for %s must be between %i and %i",
                        option->name, option->value_min, option->value_max);
      return;
    }

    *option->ptr = newval;

    if (option->wants_bool)
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%s has changed %s to %s",
                           get_oper_name(source_p), option->name, status[*option->ptr != 0]);
    else
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%s has changed %s to %i",
                           get_oper_name(source_p), option->name, *option->ptr);
  }
  else
  {
    if (option->wants_bool)
      sendto_one_notice(source_p, &me, ":%s is currently %s", option->name, status[*option->ptr != 0]);
    else
      sendto_one_notice(source_p, &me, ":%s is currently %i", option->name, *option->ptr);
  }
}

/*
 * list_quote_commands() sends the client all the available commands.
 */
static void
set_option_list(struct Client *source_p)
{
  char command_list[SET_COMMAND_LIST_SIZE] = "";

  for (const struct SetStruct *tab = set_cmd_table; tab->name; ++tab)
  {
    strlcat(command_list, tab->name, sizeof(command_list));
    if ((tab + 1)->name)
      strlcat(command_list, " ", sizeof(command_list));
  }

  sendto_one_notice(source_p, &me, ":Available QUOTE SET commands: %s", command_list);
}

static void
mo_set(struct Client *source_p, int parc, char *parv[])
{
  if (!HasOFlag(source_p, OPER_FLAG_SET))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "set");
    return;
  }

  if (parc > 1)
  {
    /*
     * Go through all the commands in set_cmd_table, until one is
     * matched.
     */
    for (struct SetStruct *tab = set_cmd_table; tab->name; ++tab)
    {
      if (irccmp(tab->name, parv[1]))
        continue;

      int newval = -1;
      const char *const arg = parv[2];
      if (arg)
      {
        if (irccmp(arg, "yes") == 0 || irccmp(arg, "on") == 0)
          newval = 1;
        else if (irccmp(arg, "no") == 0 || irccmp(arg, "off") == 0)
          newval = 0;
        else
          newval = atoi(arg);

        if (newval < 0)
        {
          sendto_one_notice(source_p, &me, ":Invalid value for %s. Please use a non-negative value.", tab->name);
          return;
        }
      }

      set_option(source_p, tab, newval);
      return;
    }

    /*
     * Code here will be executed when a /QUOTE SET command is not
     * found within set_cmd_table.
     */
    sendto_one_notice(source_p, &me, ":Variable not found.");
    return;
  }

  set_option_list(source_p);
}

static struct Message set_msgtab =
{
  .cmd = "SET",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_set }
};

static void
module_init(void)
{
  mod_add_cmd(&set_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&set_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
