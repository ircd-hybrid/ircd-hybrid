/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2004-2014 ircd-hybrid development team
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

/*! \file m_etrace.c
 * \brief Includes required functions for processing the ETRACE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"


/* report_this_status()
 *
 * inputs       - pointer to client to report to
 *              - pointer to client to report about
 *              - flag full etrace or not
 * output       - NONE
 * side effects - NONE
 */
static void
report_this_status(struct Client *source_p, const struct Client *target_p)
{
  if (target_p->status != STAT_CLIENT)
    return;

  if (ConfigFileEntry.hide_spoof_ips)
    sendto_one_numeric(source_p, &me, RPL_ETRACE,
                       HasUMode(target_p, UMODE_OPER) ? "Oper" : "User",
                       get_client_class(&target_p->localClient->confs),
                       target_p->name,
                       target_p->username,
                       target_p->host,
                       IsIPSpoof(target_p) ? "255.255.255.255" : target_p->sockhost,
                       target_p->info);
  else
    sendto_one_numeric(source_p, &me, RPL_ETRACE,
                       HasUMode(target_p, UMODE_OPER) ? "Oper" : "User",
                       get_client_class(&target_p->localClient->confs),
                       target_p->name,
                       target_p->username,
                       target_p->host,
                       target_p->sockhost,
                       target_p->info);
}

/*
 * do_etrace()
 */
static void
do_etrace(struct Client *source_p, const char *arg)
{
  const char *tname = NULL;
  unsigned int wilds = 0, do_all = 0;
  const dlink_node *ptr = NULL;

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "ETRACE requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  if (!EmptyString(arg))
  {
    tname = arg;
    wilds = has_wildcards(tname);
  }
  else
  {
    do_all = 1;
    tname = "*";
  }

  if (!wilds && !do_all)
  {
    const struct Client *target_p = hash_find_client(tname);

    if (target_p && MyClient(target_p))
      report_this_status(source_p, target_p);

    sendto_one_numeric(source_p, &me, RPL_ENDOFTRACE, tname);
    return;
  }

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    const struct Client *target_p = ptr->data;

    if (wilds)
    {
      if (!match(tname, target_p->name))
        report_this_status(source_p, target_p);
    }
    else
      report_this_status(source_p, target_p);
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFTRACE, tname);
}

/* mo_etrace()
 *      parv[0] = command
 *      parv[1] = servername
 */
static int
mo_etrace(struct Client *source_p, int parc, char *parv[])
{
  do_etrace(source_p, parv[1]);
  return 0;
}

static struct Message etrace_msgtab =
{
  "ETRACE", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_etrace, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&etrace_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&etrace_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
