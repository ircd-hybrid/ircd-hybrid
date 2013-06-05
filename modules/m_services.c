/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1999 by the Bahamut Development Team.
 *  Copyright (C) 2011 by the Hybrid Development Team.
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
 */

/*! \file m_services.c
 * \brief Provides service aliases
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "channel_mode.h"
#include "numeric.h"
#include "conf.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "s_user.h"
#include "hash.h"


/*
 * XXX: Each services alias handler is currently ugly copy&paste.
 * Configureable aliases will get implemented.
 */

static void
m_nickserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG NickServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "NickServ");
}

static void
m_chanserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG ChanServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "ChanServ");
}

static void
m_memoserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG MemoServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "MemoServ");
}

static void
m_operserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG OperServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "OperServ");
}

static void
m_statserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG StatServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "StatServ");
}

static void
m_hostserv(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG HostServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "HelpServ");
}

static void
m_botserv(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  struct Client *target_p = NULL;

  assert(client_p && source_p);
  assert(client_p == source_p);

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NOTEXTTOSEND),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_server(ConfigFileEntry.service_name)))
  {
    sendto_one(target_p, ":%s PRIVMSG BotServ@%s :%s",
               source_p->name, ConfigFileEntry.service_name, parv[1]);
    return;
  }

  sendto_one(source_p, form_str(ERR_SERVICESDOWN),
             me.name, source_p->name, "BotServ");
}


static struct Message ms_msgtab = {
  "MS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore}
};

static struct Message ns_msgtab = {
  "NS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore}
};

static struct Message os_msgtab = {
  "OS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore}
};

static struct Message bs_msgtab = {
  "BS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore}
};

static struct Message cs_msgtab = {
  "CS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore}
};

static struct Message ss_msgtab = {
  "SS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_statserv, m_ignore, m_ignore, m_statserv, m_ignore}
};

static struct Message hs_msgtab = {
  "HS", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_hostserv, m_ignore, m_ignore, m_hostserv, m_ignore}
};

static struct Message botserv_msgtab = {
  "BOTSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore}
};

static struct Message chanserv_msgtab = {
  "CHANSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore}
};

static struct Message memoserv_msgtab = {
  "MEMOSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore}
};

static struct Message nickserv_msgtab = {
  "NICKSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore}
};

static struct Message operserv_msgtab = {
  "OPERSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore}
};

static struct Message statserv_msgtab = {
  "STATSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_statserv, m_ignore, m_ignore, m_statserv, m_ignore}
};

static struct Message hostserv_msgtab = {
  "HOSTSERV", 0, 0, 0, 1, MFLG_SLOW, 0,
  {m_unregistered, m_hostserv, m_ignore, m_ignore, m_hostserv, m_ignore}
};


static void
module_init(void)
{
  mod_add_cmd(&botserv_msgtab);
  mod_add_cmd(&chanserv_msgtab);
  mod_add_cmd(&memoserv_msgtab);
  mod_add_cmd(&nickserv_msgtab);
  mod_add_cmd(&operserv_msgtab);
  mod_add_cmd(&statserv_msgtab);
  mod_add_cmd(&hostserv_msgtab);
  mod_add_cmd(&bs_msgtab);
  mod_add_cmd(&ns_msgtab);
  mod_add_cmd(&cs_msgtab);
  mod_add_cmd(&ms_msgtab);
  mod_add_cmd(&os_msgtab);
  mod_add_cmd(&ss_msgtab);
  mod_add_cmd(&hs_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&botserv_msgtab);
  mod_del_cmd(&chanserv_msgtab);
  mod_del_cmd(&memoserv_msgtab);
  mod_del_cmd(&nickserv_msgtab);
  mod_del_cmd(&operserv_msgtab);
  mod_del_cmd(&statserv_msgtab);
  mod_del_cmd(&hostserv_msgtab);
  mod_del_cmd(&bs_msgtab);
  mod_del_cmd(&ns_msgtab);
  mod_del_cmd(&cs_msgtab);
  mod_del_cmd(&ms_msgtab);
  mod_del_cmd(&os_msgtab);
  mod_del_cmd(&ss_msgtab);
  mod_del_cmd(&hs_msgtab);
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
