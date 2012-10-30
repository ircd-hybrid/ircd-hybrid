/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_links.c: Shows what servers are currently connected.
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
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_serv.h"
#include "send.h"
#include "conf.h"
#include "motd.h"
#include "parse.h"
#include "modules.h"


static void
do_links(struct Client *source_p, int parc, char *parv[])
{
  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "LINKS requested by %s (%s@%s) [%s]",
                       source_p->name,
                       source_p->username, source_p->host,
                       source_p->servptr->name);

  if (HasUMode(source_p, UMODE_OPER) || !ConfigServerHide.flatten_links)
  {
    const char *mask = (parc > 2 ? parv[2] : parv[1]);
    const char *me_name, *nick;
    dlink_node *ptr;

    me_name = ID_or_name(&me, source_p->from);
    nick = ID_or_name(source_p, source_p->from);

    DLINK_FOREACH(ptr, global_serv_list.head)
    {
      struct Client *target_p = ptr->data;

      /* skip hidden servers */
      if (IsHidden(target_p))
        if (!HasUMode(source_p, UMODE_OPER))
          continue;

      if (!EmptyString(mask) && !match(mask, target_p->name))
        continue;

      /*
       * We just send the reply, as if they are here there's either no SHIDE,
       * or they're an oper..  
       */
      sendto_one(source_p, form_str(RPL_LINKS),
                 me_name, nick,
                 target_p->name, target_p->servptr->name,
                 target_p->hopcount, target_p->info);
    }
  
    sendto_one(source_p, form_str(RPL_ENDOFLINKS),
               me_name, nick,
               EmptyString(mask) ? "*" : mask);
  }
  else
  {
    /*
     * Print our own info so at least it looks like a normal links
     * then print out the file (which may or may not be empty)
     */
    sendto_one(source_p, form_str(RPL_LINKS),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from),
               me.name, me.name, 0, me.info);
    send_message_file(source_p, &ConfigFileEntry.linksfile);
    sendto_one(source_p, form_str(RPL_ENDOFLINKS),
               ID_or_name(&me, source_p->from),
               ID_or_name(source_p, source_p->from), "*");
  }
}

static void
mo_links(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (parc > 2)
    if (!ConfigFileEntry.disable_remote || HasUMode(source_p, UMODE_OPER))
      if (hunt_server(client_p, source_p, ":%s LINKS %s :%s", 1,
                      parc, parv) != HUNTED_ISME)
        return;

  do_links(source_p, parc, parv);
}

/*
 * m_links - LINKS message handler
 *      parv[0] = sender prefix
 *      parv[1] = servername mask
 * or
 *      parv[0] = sender prefix
 *      parv[1] = server to query 
 *      parv[2] = servername mask
 */
static void
m_links(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (!ConfigServerHide.flatten_links)
  {
    mo_links(client_p, source_p, parc, parv);
    return;
  }

  do_links(source_p, parc, parv);
}

/*
 * ms_links - LINKS message handler
 *      parv[0] = sender prefix
 *      parv[1] = servername mask
 * or
 *      parv[0] = sender prefix
 *      parv[1] = server to query 
 *      parv[2] = servername mask
 */
static void
ms_links(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s LINKS %s :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return;

  if (IsClient(source_p))
    m_links(client_p, source_p, parc, parv);
}

static struct Message links_msgtab = {
  "LINKS", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_links, ms_links, m_ignore, mo_links, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&links_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&links_msgtab);
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
