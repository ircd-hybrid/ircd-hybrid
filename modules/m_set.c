/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_set.c: Sets a server parameter.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

/* rewritten by jdc */

#include "stdinc.h"
#include "client.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "send.h"
#include "channel.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"
#include "s_misc.h"


/* Structure used for the SET table itself */
struct SetStruct
{
  const char *name;
  void (*handler)();
  const int wants_char; /* 1 if it expects (char *, [int]) */
  const int wants_int;  /* 1 if it expects ([char *], int) */
  /* eg:  0, 1 == only an int arg
   * eg:  1, 1 == char and int args */
};

static void quote_autoconn(struct Client *, const char *, int);
static void quote_autoconnall(struct Client *, int);
static void quote_floodcount(struct Client *, int);
static void quote_identtimeout(struct Client *, int);
static void quote_max(struct Client *, int);
static void quote_msglocale(struct Client *, char *);
static void quote_spamnum(struct Client *, int);
static void quote_spamtime(struct Client *, int);
static void quote_splitmode(struct Client *, char *);
static void quote_splitnum(struct Client *, int);
static void quote_splitusers(struct Client *, int);
static void list_quote_commands(struct Client *);
static void quote_jfloodtime(struct Client *, int);
static void quote_jfloodcount(struct Client *, int);

/* 
 * If this ever needs to be expanded to more than one arg of each
 * type, want_char/want_int could be the count of the arguments,
 * instead of just a boolean flag...
 *
 * -davidt
 */

static const struct SetStruct set_cmd_table[] =
{
  /* name		function        string arg  int arg */
  /* -------------------------------------------------------- */
  { "AUTOCONN",		quote_autoconn,		1,	1 },
  { "AUTOCONNALL",	quote_autoconnall,	0,	1 },
  { "FLOODCOUNT",	quote_floodcount,	0,	1 },
  { "IDENTTIMEOUT",	quote_identtimeout,	0,	1 },
  { "MAX",		quote_max,		0,	1 },
  { "MSGLOCALE",	quote_msglocale,	1,	0 },
  { "SPAMNUM",		quote_spamnum,		0,	1 },
  { "SPAMTIME",		quote_spamtime,		0,	1 },
  { "SPLITMODE",	quote_splitmode,	1,	0 },
  { "SPLITNUM",		quote_splitnum,		0,	1 },
  { "SPLITUSERS",	quote_splitusers,	0,	1 },
  { "JFLOODTIME",	quote_jfloodtime,	0,	1 },
  { "JFLOODCOUNT",	quote_jfloodcount,	0,	1 },
  /* -------------------------------------------------------- */
  { NULL,               NULL,                   0,      0 }
};

/*
 * list_quote_commands() sends the client all the available commands.
 * Four to a line for now.
 */
static void
list_quote_commands(struct Client *source_p)
{
  int j = 0;
  const struct SetStruct *tab = set_cmd_table;
  const char *names[4] = { "", "", "", "" };

  sendto_one(source_p, ":%s NOTICE %s :Available QUOTE SET commands:",
             me.name, source_p->name);

  for (; tab->handler; ++tab)
  {
    names[j++] = tab->name;

    if (j > 3)
    {
      sendto_one(source_p, ":%s NOTICE %s :%s %s %s %s",
                 me.name, source_p->name,
                 names[0], names[1], 
                 names[2], names[3]);
      j = 0;
      names[0] = names[1] = names[2] = names[3] = "";
    }

  }

  if (j)
    sendto_one(source_p, ":%s NOTICE %s :%s %s %s %s",
               me.name, source_p->name,
               names[0], names[1], 
               names[2], names[3]);
}

/* SET AUTOCONN */
static void
quote_autoconn(struct Client *source_p, const char *arg, int newval)
{
  struct AccessItem *aconf;

  if (arg != NULL)
  {
    struct ConfItem *conf = find_exact_name_conf(SERVER_TYPE, NULL, arg, NULL, NULL);

    if (conf != NULL)
    {
      aconf = map_to_conf(conf);
      if (newval)
        SetConfAllowAutoConn(aconf);
      else
        ClearConfAllowAutoConn(aconf);

      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has changed AUTOCONN for %s to %i",
                           get_oper_name(source_p), arg, newval);
      sendto_one(source_p,
                 ":%s NOTICE %s :AUTOCONN for %s is now set to %i",
                 me.name, source_p->name, arg, newval);
    }
    else
    {
      sendto_one(source_p, ":%s NOTICE %s :Can't find %s",
                 me.name, source_p->name, arg);
    }
  }
  else
  {
    sendto_one(source_p, ":%s NOTICE %s :Please specify a server name!",
               me.name, source_p->name);
  }
}

/* SET AUTOCONNALL */
static void
quote_autoconnall(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed AUTOCONNALL to %i",
                         get_oper_name(source_p), newval);

    GlobalSetOptions.autoconn = newval;
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :AUTOCONNALL is currently %i",
               me.name, source_p->name, GlobalSetOptions.autoconn);
}

/* SET FLOODCOUNT */
static void
quote_floodcount(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    GlobalSetOptions.floodcount = newval;
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed FLOODCOUNT to %i",
                         get_oper_name(source_p), GlobalSetOptions.floodcount);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :FLOODCOUNT is currently %i",
               me.name, source_p->name, GlobalSetOptions.floodcount);
}

/* SET IDENTTIMEOUT */
static void
quote_identtimeout(struct Client *source_p, int newval)
{
  if (!HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "set");
    return;
  }

  if (newval > 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed IDENTTIMEOUT to %d",
                         get_oper_name(source_p), newval);
    GlobalSetOptions.ident_timeout = newval;
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :IDENTTIMEOUT is currently %d",
               me.name, source_p->name, GlobalSetOptions.ident_timeout);
}

/* SET MAX */
static void
quote_max(struct Client *source_p, int newval)
{
  if (newval > 0)
  {
    recalc_fdlimit(NULL);

    if (newval > MAXCLIENTS_MAX)
    {
      sendto_one(source_p,
        ":%s NOTICE %s :You cannot set MAXCLIENTS to > %d, restoring to %d",
        me.name, source_p->name, MAXCLIENTS_MAX, ServerInfo.max_clients);
      return;
    }

    if (newval < MAXCLIENTS_MIN)
    {
      sendto_one(source_p,
        ":%s NOTICE %s :You cannot set MAXCLIENTS to < %d, restoring to %d",
        me.name, source_p->name, MAXCLIENTS_MIN, ServerInfo.max_clients);
      return;
    }

    ServerInfo.max_clients = newval;

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
        "%s set new MAXCLIENTS to %d (%d current)",
        get_oper_name(source_p), ServerInfo.max_clients, Count.local);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :Current MAXCLIENTS = %d (%d)",
               me.name, source_p->name, ServerInfo.max_clients, Count.local);
}

/* SET MSGLOCALE */
static void
quote_msglocale(struct Client *source_p, char *locale)
{
  if (locale != NULL)
  {
    set_locale(locale);
    rebuild_isupport_message_line();
    sendto_one(source_p, ":%s NOTICE %s :Set MSGLOCALE to '%s'",
               me.name, source_p->name, get_locale());
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :MSGLOCALE is currently '%s'",
               me.name, source_p->name, get_locale());
}

/* SET SPAMNUM */
static void
quote_spamnum(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    if (newval == 0)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s has disabled ANTI_SPAMBOT", source_p->name);
      GlobalSetOptions.spam_num = newval;
      return;
    }

    GlobalSetOptions.spam_num = IRCD_MAX(newval, MIN_SPAM_NUM);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed SPAMNUM to %i",
                         get_oper_name(source_p), GlobalSetOptions.spam_num);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :SPAMNUM is currently %i",
               me.name, source_p->name, GlobalSetOptions.spam_num);
}

/* SET SPAMTIME */
static void
quote_spamtime(struct Client *source_p, int newval)
{
  if (newval > 0)
  {
    GlobalSetOptions.spam_time = IRCD_MAX(newval, MIN_SPAM_TIME);
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed SPAMTIME to %i",
                         get_oper_name(source_p), GlobalSetOptions.spam_time);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :SPAMTIME is currently %i",
               me.name, source_p->name, GlobalSetOptions.spam_time);
}

/* this table is what splitmode may be set to */
static const char *splitmode_values[] =
{
  "OFF",
  "ON",
  "AUTO",
  NULL
};

/* this table is what splitmode may be */
static const char *splitmode_status[] =
{
  "OFF",
  "AUTO (OFF)",
  "ON",
  "AUTO (ON)",
  NULL
};

/* SET SPLITMODE */
static void
quote_splitmode(struct Client *source_p, char *charval)
{
  if (charval)
  {
    int newval;

    for (newval = 0; splitmode_values[newval]; ++newval)
      if (irccmp(splitmode_values[newval], charval) == 0)
        break;

    /* OFF */
    if (newval == 0)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s is disabling splitmode",
                           get_oper_name(source_p));

      splitmode = 0;
      splitchecking = 0;

      eventDelete(check_splitmode, NULL);
    }
    /* ON */
    else if (newval == 1)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s is enabling and activating splitmode",
                           get_oper_name(source_p));

      splitmode = 1;
      splitchecking = 0;

      /* we might be deactivating an automatic splitmode, so pull the event */
      eventDelete(check_splitmode, NULL);
    }
    /* AUTO */
    else if (newval == 2)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s is enabling automatic splitmode",
                           get_oper_name(source_p));

      splitchecking = 1;
      check_splitmode(NULL);
    }
  }
  else
    /* if we add splitchecking to splitmode*2 we get a unique table to 
     * pull values back out of, splitmode can be four states - but you can
     * only set to three, which means we cant use the same table --fl_
     */
    sendto_one(source_p, ":%s NOTICE %s :SPLITMODE is currently %s", 
               me.name, source_p->name, 
               splitmode_status[(splitchecking + (splitmode * 2))]);
}

/* SET SPLITNUM */
static void
quote_splitnum(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed SPLITNUM to %i", 
                         get_oper_name(source_p), newval);
    split_servers = newval;

    if (splitchecking)
      check_splitmode(NULL);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :SPLITNUM is currently %i", 
               me.name, source_p->name, split_servers);
}

/* SET SPLITUSERS */
static void
quote_splitusers(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed SPLITUSERS to %i", 
                         get_oper_name(source_p), newval);
    split_users = newval;

    if (splitchecking)
      check_splitmode(NULL);
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :SPLITUSERS is currently %i", 
               me.name, source_p->name, split_users);
}

/* SET JFLOODTIME */
static void
quote_jfloodtime(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed JFLOODTIME to %i", 
                         get_oper_name(source_p), newval);
    GlobalSetOptions.joinfloodtime = newval;
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :JFLOODTIME is currently %i", 
               me.name, source_p->name, GlobalSetOptions.joinfloodtime);
}

/* SET JFLOODCOUNT */
static void
quote_jfloodcount(struct Client *source_p, int newval)
{
  if (newval >= 0)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s has changed JFLOODCOUNT to %i", 
                         get_oper_name(source_p), newval);
    GlobalSetOptions.joinfloodcount = newval;
  }
  else
    sendto_one(source_p, ":%s NOTICE %s :JFLOODCOUNT is currently %i", 
               me.name, source_p->name, GlobalSetOptions.joinfloodcount);
}

/*
 * mo_set - SET command handler
 * set options while running
 */
static void
mo_set(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  int n;
  int newval;
  const char *arg    = NULL;
  const char *intarg = NULL;
  const struct SetStruct *tab = set_cmd_table;

  if (!HasOFlag(source_p, OPER_FLAG_SET))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, source_p->name, "set");
    return;
  }

  if (parc > 1)
  {
    /*
     * Go through all the commands in set_cmd_table, until one is
     * matched.
     */
    for (; tab->handler; ++tab)
    {
      if (!irccmp(tab->name, parv[1]))
      {
        /*
         * Command found; now execute the code
         */
        n = 2;

        if (tab->wants_char)
          arg = parv[n++];

        if (tab->wants_int)
          intarg = parv[n++];

        if ((n - 1) > parc)
        {
          if (parc > 2)
            sendto_one(source_p,
                       ":%s NOTICE %s :SET %s expects (\"%s%s\") args",
                       me.name, source_p->name, tab->name,
                       (tab->wants_char ? "string, " : ""),
                       (tab->wants_char ? "int" : ""));
        }

        if (parc <= 2)
        {
          arg = NULL;
          intarg = NULL;
        }

        if (!strcmp(tab->name, "AUTOCONN") && (parc < 4))
        {
          sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
                     me.name, source_p->name, "SET");
          return;
        }

        if (tab->wants_int && (parc > 2))
        {
          if (intarg)
          {
            if (irccmp(intarg, "yes") == 0 || irccmp(intarg, "on") == 0)
              newval = 1;
            else if (irccmp(intarg, "no") == 0|| irccmp(intarg, "off") == 0)
              newval = 0;
            else
              newval = atoi(intarg);
          }
          else
            newval = -1;

          if (newval < 0)
          {
            sendto_one(source_p,
                       ":%s NOTICE %s :Value less than 0 illegal for %s",
                       me.name, source_p->name,
                       tab->name);

            return;
          }
        }
        else
          newval = -1;

        if (tab->wants_char)
        {
          if (tab->wants_int)
            tab->handler(source_p, arg, newval);
          else
            tab->handler(source_p, arg);
          return;
        }
        else
        {
          if (tab->wants_int)
            tab->handler(source_p, newval);
          else
            /* Just in case someone actually wants a
             * set function that takes no args.. *shrug* */
            tab->handler(source_p);
          return;
        }
      }
    }

    /*
     * Code here will be executed when a /QUOTE SET command is not
     * found within set_cmd_table.
     */
    sendto_one(source_p, ":%s NOTICE %s :Variable not found.",
               me.name, source_p->name);
    return;
  }

  list_quote_commands(source_p);
}

static struct Message set_msgtab = {
  "SET", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, rfc1459_command_send_error, m_ignore, mo_set, m_ignore}
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
