/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file m_squit.c
 * \brief Includes required functions for processing the SQUIT command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/* mo_squit - SQUIT message handler
 *  parv[0] = command
 *  parv[1] = server name
 *  parv[2] = comment
 */
static int
mo_squit(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Client *p;
  dlink_node *ptr;
  char *comment;
  const char *server;
  char def_reason[] = CONF_NOREASON;

  if (parc < 2 || EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "SQUIT");
    return 0;
  }

  server = parv[1];

  /* The following allows wild cards in SQUIT. Only
   * useful when the command is issued by an oper.
   */
  DLINK_FOREACH(ptr, global_serv_list.head)
  {
    p = ptr->data;

    if (IsServer(p) || IsMe(p))
    {
      if (!match(server, p->name))
      {
        target_p = p;
        break;
      }
    }
  }

  if ((target_p == NULL) || IsMe(target_p))
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, server);
    return 0;
  }

  if (!MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_SQUIT_REMOTE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "squit:remote");
    return 0;
  }

  if (MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_SQUIT))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "squit");
    return 0;
  }

  comment = (parc > 2 && parv[2]) ? parv[2] : def_reason;

  if (strlen(comment) > (size_t)REASONLEN)
    comment[REASONLEN] = '\0';

  if (MyConnect(target_p))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Received SQUIT %s from %s (%s)",
                         target_p->name, get_client_name(source_p, HIDE_IP), comment);
    ilog(LOG_TYPE_IRCD, "Received SQUIT %s from %s (%s)",
         target_p->name, get_client_name(source_p, HIDE_IP), comment);
  }

  exit_client(target_p, source_p, comment);
  return 0;
}

/** NOTE: I removed wildcard lookups here, because a wildcarded
 **       SQUIT should/can never happen in ms_squit. -Michael
 **/

/* ms_squit - SQUIT message handler
 *  parv[0] = command
 *  parv[1] = server name
 *  parv[2] = comment
 */
static int
ms_squit(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Client *target_p = NULL;
  const char *comment = NULL;

  if (parc < 2 || EmptyString(parv[parc - 1]))
    return 0;

  if ((target_p = hash_find_server(parv[1])) == NULL)
    return 0;

  if (!IsServer(target_p) && !IsMe(target_p))
    return 0;

  if (IsMe(target_p))
    target_p = client_p;

  comment = (parc > 2 && parv[parc - 1]) ? parv[parc - 1] : client_p->name;

  if (MyConnect(target_p))
  {
    sendto_wallops_flags(UMODE_WALLOP, &me, "Remote SQUIT %s from %s (%s)",
                         target_p->name, source_p->name, comment);
    sendto_server(NULL, NOCAPS, NOCAPS,
                  ":%s WALLOPS :Remote SQUIT %s from %s (%s)",
                  me.id, target_p->name, source_p->name, comment);
    ilog(LOG_TYPE_IRCD, "SQUIT From %s : %s (%s)", source_p->name,
         target_p->name, comment);
  }

  exit_client(target_p, source_p, comment);
  return 0;
}

static struct Message squit_msgtab =
{
  "SQUIT", 0, 0, 1, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_squit, m_ignore, mo_squit, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&squit_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&squit_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
