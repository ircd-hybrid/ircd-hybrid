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


/* SET AUTOCONNALL */
static void
quote_autoconnall(struct Client *source_p, const char *arg, int newval)
{
  static const char *const status[] =
  {
    "OFF", "ON"
  };

  if (newval >= 0)
  {
    GlobalSetOptions.autoconn = newval != 0;
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed AUTOCONNALL to %s",
                         get_oper_name(source_p), status[GlobalSetOptions.autoconn == true]);
  }
  else
    sendto_one_notice(source_p, &me, ":AUTOCONNALL is currently %s",
                      status[GlobalSetOptions.autoconn == true]);
}

/* SET FLOODCOUNT */
static void
quote_floodcount(struct Client *source_p, const char *arg, int newval)
{
  if (newval >= 0)
  {
    GlobalSetOptions.floodcount = newval;
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed FLOODCOUNT to %u",
                         get_oper_name(source_p), GlobalSetOptions.floodcount);
  }
  else
    sendto_one_notice(source_p, &me, ":FLOODCOUNT is currently %u",
                      GlobalSetOptions.floodcount);
}

/* SET FLOODTIME */
static void
quote_floodtime(struct Client *source_p, const char *arg, int newval)
{
  if (newval >= 0)
  {
    GlobalSetOptions.floodtime = newval;
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed FLOODTIME to %u",
                         get_oper_name(source_p), GlobalSetOptions.floodtime);
  }
  else
    sendto_one_notice(source_p, &me, ":FLOODTIME is currently %u",
                      GlobalSetOptions.floodtime);
}

/* SET MAX */
static void
quote_max(struct Client *source_p, const char *arg, int newval)
{
  if (newval > 0)
  {
    if (newval > MAXCLIENTS_MAX)
    {
      sendto_one_notice(source_p, &me, ":You cannot set MAXCLIENTS to > %d, restoring to %u",
                        MAXCLIENTS_MAX, GlobalSetOptions.maxclients);
      return;
    }

    GlobalSetOptions.maxclients = newval;
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s set new MAXCLIENTS to %u (%u current)",
                         get_oper_name(source_p), GlobalSetOptions.maxclients, dlink_list_length(&local_client_list));
  }
  else
    sendto_one_notice(source_p, &me, ":Current MAXCLIENTS = %u (%u)",
                      GlobalSetOptions.maxclients, dlink_list_length(&local_client_list));
}

/* SET SPAMNUM */
static void
quote_spamnum(struct Client *source_p, const char *arg, int newval)
{
  if (newval >= 0)
  {
    if (newval == 0)
    {
      GlobalSetOptions.spam_num = newval;
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "%s has disabled ANTI_SPAMBOT", source_p->name);
      return;
    }

    GlobalSetOptions.spam_num = IRCD_MAX(newval, MIN_SPAM_NUM);
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed SPAMNUM to %u",
                         get_oper_name(source_p), GlobalSetOptions.spam_num);
  }
  else
    sendto_one_notice(source_p, &me, ":SPAMNUM is currently %u",
                      GlobalSetOptions.spam_num);
}

/* SET SPAMTIME */
static void
quote_spamtime(struct Client *source_p, const char *arg, int newval)
{
  if (newval > 0)
  {
    GlobalSetOptions.spam_time = IRCD_MAX(newval, MIN_SPAM_TIME);
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed SPAMTIME to %u",
                         get_oper_name(source_p), GlobalSetOptions.spam_time);
  }
  else
    sendto_one_notice(source_p, &me, ":SPAMTIME is currently %u",
                      GlobalSetOptions.spam_time);
}

/* SET JFLOODTIME */
static void
quote_jfloodtime(struct Client *source_p, const char *arg, int newval)
{
  if (newval >= 0)
  {
    GlobalSetOptions.joinfloodtime = newval;
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed JFLOODTIME to %u",
                         get_oper_name(source_p), GlobalSetOptions.joinfloodtime);
  }
  else
    sendto_one_notice(source_p, &me, ":JFLOODTIME is currently %u",
                      GlobalSetOptions.joinfloodtime);
}

/* SET JFLOODCOUNT */
static void
quote_jfloodcount(struct Client *source_p, const char *arg, int newval)
{
  if (newval >= 0)
  {
    GlobalSetOptions.joinfloodcount = newval;
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s has changed JFLOODCOUNT to %u",
                         get_oper_name(source_p), GlobalSetOptions.joinfloodcount);
  }
  else
    sendto_one_notice(source_p, &me, ":JFLOODCOUNT is currently %u",
                      GlobalSetOptions.joinfloodcount);
}

/* Structure used for the SET table itself */
struct SetStruct
{
  const char *const name;
  void (*const handler)(struct Client *, const char *, int);
  bool wants_char;  /* 1 if it expects (char *, [int]) */
  bool wants_int;  /* 1 if it expects ([char *], int) */
  /* eg:  0, 1 == only an int arg
   * eg:  1, 1 == char and int args */
};

/*
 * If this ever needs to be expanded to more than one arg of each
 * type, want_char/want_int could be the count of the arguments,
 * instead of just a boolean flag...
 *
 * -davidt
 */
static const struct SetStruct set_cmd_table[] =
{
  /* name               function        string arg  int arg */
  /* ------------------------------------------------------ */
  { "AUTOCONNALL",      quote_autoconnall,  false,  true  },
  { "FLOODCOUNT",       quote_floodcount,   false,  true  },
  { "FLOODTIME",        quote_floodtime,    false,  true  },
  { "MAX",              quote_max,          false,  true  },
  { "SPAMNUM",          quote_spamnum,      false,  true  },
  { "SPAMTIME",         quote_spamtime,     false,  true  },
  { "JFLOODTIME",       quote_jfloodtime,   false,  true  },
  { "JFLOODCOUNT",      quote_jfloodcount,  false,  true  },
  /* ------------------------------------------------------ */
  { NULL,               NULL,               false,  false }
};

/*
 * list_quote_commands() sends the client all the available commands.
 * Four to a line for now.
 */
static void
list_quote_commands(struct Client *source_p)
{
  unsigned int j = 0;
  const char *names[4] = { "", "", "", "" };

  sendto_one_notice(source_p, &me, ":Available QUOTE SET commands:");

  for (const struct SetStruct *tab = set_cmd_table; tab->handler; ++tab)
  {
    names[j++] = tab->name;

    if (j > 3)
    {
      sendto_one_notice(source_p, &me, ":%s %s %s %s",
                        names[0], names[1],
                        names[2], names[3]);
      j = 0;
      names[0] = names[1] = names[2] = names[3] = "";
    }
  }

  if (j)
    sendto_one_notice(source_p, &me, ":%s %s %s %s",
                      names[0], names[1],
                      names[2], names[3]);
}

/*
 * mo_set - SET command handler
 * set options while running
 */
static void
mo_set(struct Client *source_p, int parc, char *parv[])
{
  int newval;
  const char *strarg = NULL;
  const char *intarg = NULL;

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
    for (const struct SetStruct *tab = set_cmd_table; tab->handler; ++tab)
    {
      if (irccmp(tab->name, parv[1]))
        continue;

      /*
       * Command found; now execute the code
       */
      int n = 2;

      if (tab->wants_char)
        strarg = parv[n++];

      if (tab->wants_int)
        intarg = parv[n++];

      if ((n - 1) > parc)
        sendto_one_notice(source_p, &me, ":SET %s expects (\"%s%s\") args", tab->name,
                          (tab->wants_char ? "string, " : ""),
                          (tab->wants_int ? "int" : ""));

      if (parc <= 2)
      {
        strarg = NULL;
        intarg = NULL;
      }

      if (tab->wants_int && parc > 2)
      {
        if (intarg)
        {
          if (irccmp(intarg, "yes") == 0 || irccmp(intarg, "on") == 0)
            newval = 1;
          else if (irccmp(intarg, "no") == 0 || irccmp(intarg, "off") == 0)
            newval = 0;
          else
            newval = atoi(intarg);
        }
        else
          newval = -1;

        if (newval < 0)
        {
          sendto_one_notice(source_p, &me, ":Value less than 0 illegal for %s", tab->name);
          return;
        }
      }
      else
        newval = -1;

      tab->handler(source_p, strarg, newval);
      return;
    }

    /*
     * Code here will be executed when a /QUOTE SET command is not
     * found within set_cmd_table.
     */
    sendto_one_notice(source_p, &me, ":Variable not found.");
    return;
  }

  list_quote_commands(source_p);
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
