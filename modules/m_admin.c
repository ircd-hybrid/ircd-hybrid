/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_admin.c: Sends administrative information to a user.
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

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "hook.h"
#include "modules.h"
#include "irc_string.h"

static void m_admin(struct Client *, struct Client *, int, char **);
static void mr_admin(struct Client *, struct Client *, int, char **);
static void ms_admin(struct Client *, struct Client *, int, char **);
static void do_admin(struct Client *);

struct Message admin_msgtab = {
  "ADMIN", 0, 0, 0, 0, MFLG_SLOW | MFLG_UNREG, 0, 
  {mr_admin, m_admin, ms_admin, m_ignore, ms_admin, m_ignore}
};

#ifndef STATIC_MODULES
static struct Callback *admin_cb;
const char *_version = "$Revision$";

static void *
va_admin(va_list args)
{
  do_admin(va_arg(args, struct Client *));
  return NULL;
}

void
_modinit(void)
{
  admin_cb = register_callback("doing_admin", va_admin);
  mod_add_cmd(&admin_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&admin_msgtab);
  uninstall_hook(admin_cb, va_admin);
}
#endif

/*
 * mr_admin - ADMIN command handler
 *      parv[0] = sender prefix   
 *      parv[1] = servername   
 */
static void
mr_admin(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, EmptyString(parv[0]) ? "*" : parv[0]);
    return;
  }
  else
    last_used = CurrentTime;

#ifdef STATIC_MODULES
  do_admin(client_p);
#else
  execute_callback(admin_cb, source_p, parc, parv);
#endif
}

/*
 * m_admin - ADMIN command handler
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
m_admin(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    sendto_one(source_p,form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }
  else
    last_used = CurrentTime;

  if (!ConfigFileEntry.disable_remote)
  {
    if (hunt_server(client_p, source_p, ":%s ADMIN :%s", 1, parc, parv) != HUNTED_ISME)
      return;
  }

#ifdef STATIC_MODULES
  do_admin(client_p);
#else
  execute_callback(admin_cb, source_p, parc, parv);
#endif
}

/*
 * ms_admin - ADMIN command handler, used for OPERS as well
 *      parv[0] = sender prefix
 *      parv[1] = servername
 */
static void
ms_admin(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s ADMIN :%s", 1, parc, parv) != HUNTED_ISME)
    return;

  if (IsClient(source_p))
#ifdef STATIC_MODULES
    do_admin(source_p);
#else
    execute_callback(admin_cb, source_p, parc, parv);
#endif
}

/* do_admin()
 *
 * inputs	- pointer to client to report to
 * output	- none
 * side effects	- admin info is sent to client given
 */
static void
do_admin(struct Client *source_p)
{
  const char *me_name;
  const char *nick;

  me_name = ID_or_name(&me, source_p->from);
  nick = ID_or_name(source_p, source_p->from);

  sendto_one(source_p, form_str(RPL_ADMINME),
	     me_name, nick, me.name);
  if (AdminInfo.name != NULL)
    sendto_one(source_p, form_str(RPL_ADMINLOC1),
	       me_name, nick, AdminInfo.name);
  if (AdminInfo.description != NULL)
    sendto_one(source_p, form_str(RPL_ADMINLOC2),
	       me_name, nick, AdminInfo.description);
  if (AdminInfo.email != NULL)
    sendto_one(source_p, form_str(RPL_ADMINEMAIL),
	       me_name, nick, AdminInfo.email);
}
