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
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "s_user.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"



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
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Failed OPER attempt as %s by %s (%s@%s) - %s",
                         name, source_p->name, source_p->username,
                         source_p->host, reason);

  ilog(LOG_TYPE_OPER, "Failed OPER attempt as %s by %s (%s@%s) - %s",
       name, source_p->name, source_p->username,
       source_p->host, reason);
}

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
  struct MaskItem *conf = NULL;
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

  if ((conf = find_exact_name_conf(CONF_OPER, source_p, name, NULL, NULL)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOOPERHOST), me.name, source_p->name);
    conf = find_exact_name_conf(CONF_OPER, NULL, name, NULL, NULL);
    failed_oper_notice(source_p, name, (conf != NULL) ?
                       "host mismatch" : "no oper {} block");
    return;
  }

  if (match_conf_password(password, conf))
  {
    if (attach_conf(source_p, conf) != 0)
    {
      sendto_one(source_p, ":%s NOTICE %s :Can't attach conf!",
                 me.name, source_p->name);
      failed_oper_notice(source_p, name, "can't attach conf!");
      return;
    }

    oper_up(source_p);

    ilog(LOG_TYPE_OPER, "OPER %s by %s!%s@%s",
         name, source_p->name, source_p->username, source_p->host);
  }
  else
  {
    sendto_one(source_p, form_str(ERR_PASSWDMISMATCH), me.name, source_p->name);
    failed_oper_notice(source_p, name, "password mismatch");
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
  sendto_one(source_p, form_str(RPL_YOUREOPER),
             me.name, source_p->name);
}

static struct Message oper_msgtab = {
  "OPER", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_oper, m_ignore, m_ignore, mo_oper, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&oper_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&oper_msgtab);
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
