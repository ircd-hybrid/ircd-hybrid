/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014-2015 ircd-hybrid development team
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

/*! \file m_opme.c
 * \brief Includes required functions for processing the OPME command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"
#include "channel_mode.h"
#include "conf.h"


/*! \brief OPME command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 */
static int
mo_opme(struct Client *source_p, int parc, char *parv[])
{
  const char *const name = parv[1];
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;
  dlink_node *node = NULL;

  if (EmptyString(name))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "OPME");
    return 0;
  }

  if (!HasOFlag(source_p, OPER_FLAG_OPME))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "opme");
    return 0;
  }

  if ((chptr = hash_find_channel(name)) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, name);
    return 0;
  }

  if ((member = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOTONCHANNEL, chptr->name);
    return 0;
  }

  DLINK_FOREACH(node, chptr->members.head)
  {
    if (((struct Membership *)node->data)->flags & CHFL_CHANOP)
    {
      sendto_one_notice(source_p, &me, ":Cannot use OPME on %s: channel is not opless",
                        chptr->name);
      return 0;
    }
  }

  ilog(LOG_TYPE_IRCD, "%s used OPME to gain channel operator status on opless channel %s",
       get_oper_name(source_p), chptr->name);
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_GLOBAL, "from %s: %s used OPME to gain channel operator status on opless channel %s",
                       me.name, get_oper_name(source_p), chptr->name);
  sendto_server(NULL, 0, 0, ":%s GLOBOPS :%s used OPME to gain channel operator status on opless channel %s",
                me.id, get_oper_name(source_p), chptr->name);

  AddMemberFlag(member, CHFL_CHANOP);
  sendto_channel_local(0, chptr, ":%s MODE %s +o %s", me.name, chptr->name, source_p->name);
  sendto_server(NULL, 0, 0, ":%s TMODE %lu %s +o %s", me.id, (unsigned long)chptr->creationtime,
                chptr->name, source_p->id);
  return 0;
}

static struct Message opme_msgtab =
{
  "OPME", NULL, 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_opme, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&opme_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&opme_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
