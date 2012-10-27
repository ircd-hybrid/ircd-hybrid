/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_oper.c: Makes a user an IRC Operator.
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
#include "list.h"
#include "handlers.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_log.h"
#include "s_user.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"

static struct ConfItem *find_password_conf(const char *, struct Client *);
static void failed_oper_notice(struct Client *, const char *, const char *);
static void m_oper(struct Client *, struct Client *, int, char *[]);
static void mo_oper(struct Client *, struct Client *, int, char *[]);

struct Message oper_msgtab = {
  "OPER", 0, 0, 3, 0, MFLG_SLOW, 0,
  { m_unregistered, m_oper, m_ignore, m_ignore, mo_oper, m_ignore }
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&oper_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&oper_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
** m_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
m_oper(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct ConfItem *conf;
  struct AccessItem *aconf=NULL;
  const char *name = parv[1];
  const char *password = parv[2];

  if (EmptyString(password))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
	       me.name, source_p->name, "OPER");
    return;
  }

  /* end the grace period */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((conf = find_password_conf(name, source_p)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOOPERHOST), me.name, source_p->name);
    conf = find_exact_name_conf(OPER_TYPE, name, NULL, NULL);
    failed_oper_notice(source_p, name, (conf != NULL) ?
                       "host mismatch" : "no oper {} block");
    log_oper_action(LOG_FAILED_OPER_TYPE, source_p, "%s\n", name);
    return;
  }

  aconf = (struct AccessItem *)map_to_conf(conf);

  if (match_conf_password(password, aconf))
  {
    if (attach_conf(source_p, conf) != 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Can't attach conf!",
                 me.name, source_p->name);
      failed_oper_notice(source_p, name, "can't attach conf!");
      log_oper_action(LOG_FAILED_OPER_TYPE, source_p, "%s\n", name);
      return;
    }

    oper_up(source_p);

    ilog(L_TRACE, "OPER %s by %s!%s@%s",
         name, source_p->name, source_p->username, source_p->host);
    log_oper_action(LOG_OPER_TYPE, source_p, "%s\n", name);
  }
  else
  {
    sendto_one(source_p, form_str(ERR_PASSWDMISMATCH), me.name, parv[0]);
    failed_oper_notice(source_p, name, "password mismatch");
    log_oper_action(LOG_FAILED_OPER_TYPE, source_p, "%s\n", name);
  }
}

/*
** mo_oper
**      parv[0] = sender prefix
**      parv[1] = oper name
**      parv[2] = oper password
*/
static void
mo_oper(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  sendto_one(source_p, form_str(RPL_YOUREOPER), me.name, source_p->name);
  send_message_file(source_p, &ConfigFileEntry.opermotd);
}

/* find_password_conf()
 *
 * inputs       - name
 *		- pointer to source_p
 * output       - pointer to oper conf or NULL
 * side effects	- NONE
 */
static struct ConfItem *
find_password_conf(const char *name, struct Client *source_p)
{
  struct ConfItem *conf = NULL;

  if ((conf = find_exact_name_conf(OPER_TYPE,
				   name, source_p->username, source_p->host
				   )) != NULL)
  {
    return(conf);
  }

  if ((conf = find_exact_name_conf(OPER_TYPE,
				   name, source_p->username,
				   source_p->sockhost)) != NULL)
  {
    return(conf);
  }

  return(NULL);
}

/* failed_oper_notice()
 *
 * inputs       - pointer to client doing /oper ...
 *              - pointer to nick they tried to oper as
 *              - pointer to reason they have failed
 * output       - nothing
 * side effects - notices all opers of the failed oper attempt if enabled
 */
static void
failed_oper_notice(struct Client *source_p, const char *name,
                   const char *reason)
{
  if (ConfigFileEntry.failed_oper_notice)
    sendto_realops_flags(UMODE_ALL, L_ALL, "Failed OPER attempt as %s "
                         "by %s (%s@%s) - %s", name, source_p->name,
                         source_p->username, source_p->host, reason);
}
