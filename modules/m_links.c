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

/*! \file m_links.c
 * \brief Includes required functions for processing the LINKS command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "conf.h"
#include "motd.h"
#include "parse.h"
#include "modules.h"


/*! \brief Shows a list of linked servers and notifies irc-operators
 *         about the LINKS request
 *
 * \param source_p Pointer to client to report to
 */
static void
do_links(struct Client *source_p, int parc, char *parv[])
{
  dlink_node *ptr = NULL;

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "LINKS requested by %s (%s@%s) [%s]",
                       source_p->name,
                       source_p->username, source_p->host,
                       source_p->servptr->name);

  if (HasUMode(source_p, UMODE_OPER) || !ConfigServerHide.flatten_links)
  {
    const char *mask = (parc > 2 ? parv[2] : parv[1]);

    DLINK_FOREACH(ptr, global_serv_list.head)
    {
      struct Client *target_p = ptr->data;

      /* skip hidden servers */
      if (IsHidden(target_p))
        if (!HasUMode(source_p, UMODE_OPER))
          continue;

      if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
        if (!HasUMode(source_p, UMODE_OPER))
          continue;

      if (!EmptyString(mask) && match(mask, target_p->name))
        continue;

      /*
       * We just send the reply, as if they are here there's either no SHIDE,
       * or they're an oper..
       */
      sendto_one_numeric(source_p, &me, RPL_LINKS,
                         target_p->name, target_p->servptr->name,
                         target_p->hopcount, target_p->info);
    }

    sendto_one_numeric(source_p, &me, RPL_ENDOFLINKS,
                       EmptyString(mask) ? "*" : mask);
  }
  else
  {
    /*
     * Print our own info so at least it looks like a normal links
     * then print out the file (which may or may not be empty)
     */
    sendto_one_numeric(source_p, &me, RPL_LINKS, me.name, me.name, 0, me.info);

    DLINK_FOREACH(ptr, flatten_links.head)
      sendto_one_numeric(source_p, &me, RPL_LINKS|SND_EXPLICIT, "%s", ptr->data);
    sendto_one_numeric(source_p, &me, RPL_ENDOFLINKS, "*");
  }
}

static int
mo_links(struct Client *source_p, int parc, char *parv[])
{
  if (parc > 2)
    if (!ConfigServerHide.disable_remote_commands || HasUMode(source_p, UMODE_OPER))
      if (hunt_server(source_p, ":%s LINKS %s :%s", 1,
                      parc, parv) != HUNTED_ISME)
        return 0;

  do_links(source_p, parc, parv);
  return 0;
}

/*! \brief LINKS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = servername mask
 * or
 *      - parv[0] = command
 *      - parv[1] = server to query
 *      - parv[2] = servername mask
 */
static int
m_links(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI);
    return 0;
  }

  last_used = CurrentTime;

  if (!ConfigServerHide.flatten_links)
    return mo_links(source_p, parc, parv);

  do_links(source_p, parc, parv);
  return 0;
}

/*! \brief LINKS command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = servername mask
 * or
 *      - parv[0] = command
 *      - parv[1] = server to query
 *      - parv[2] = servername mask
 */
static int
ms_links(struct Client *source_p, int parc, char *parv[])
{
  if (hunt_server(source_p, ":%s LINKS %s :%s", 1,
                  parc, parv) != HUNTED_ISME)
    return 0;

  return m_links(source_p, parc, parv);
}

static struct Message links_msgtab =
{
  "LINKS", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_links, ms_links, m_ignore, mo_links, m_ignore }
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
