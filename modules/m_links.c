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

/*! \file m_links.c
 * \brief Includes required functions for processing the LINKS command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"


/*! \brief Shows a list of linked servers and notifies irc-operators
 *         about the LINKS request
 *
 * \param source_p Pointer to client to report to
 */
static void
do_links(struct Client *source_p, char *parv[])
{
  list_node_t *node;

  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE, "LINKS requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);

  if (HasUMode(source_p, UMODE_OPER) || ConfigServerHide.flatten_links == 0)
  {
    const char *mask = parv[2];
    if (EmptyString(mask))
      mask = parv[1];

    LIST_FOREACH(node, global_server_list.head)
    {
      const struct Client *target_p = node->data;

      /* Skip hidden servers */
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
       * or they're an oper.
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
     * Print our own info so at least it looks like a normal links, then
     * print out the file (which may or may not be empty).
     */
    sendto_one_numeric(source_p, &me, RPL_LINKS, me.name, me.name, 0, me.info);

    LIST_FOREACH(node, flatten_links.head)
      sendto_one_numeric(source_p, &me, RPL_LINKS | SND_EXPLICIT, "%s", node->data);
    sendto_one_numeric(source_p, &me, RPL_ENDOFLINKS, "*");
  }
}

static void
mo_links(struct Client *source_p, int parc, char *parv[])
{
  do_links(source_p, parv);
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
static void
m_links(struct Client *source_p, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "LINKS");
    return;
  }

  last_used = event_base->time.sec_monotonic;

  do_links(source_p, parv);
}

static struct Command links_msgtab =
{
  .name = "LINKS",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_links },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_links }
};

static void
module_init(void)
{
  command_add(&links_msgtab);
}

static void
module_exit(void)
{
  command_del(&links_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
