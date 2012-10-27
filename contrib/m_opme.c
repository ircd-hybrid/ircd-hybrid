/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_opme.c: Regains ops on opless channels
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
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"


static int
chan_is_opless(const struct Channel *const chptr)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, chptr->members.head)
    if (((struct Membership *)ptr->data)->flags & CHFL_CHANOP)
      return 0;

  return 1;
}

/*
 * mo_opme()
 *      parv[0] = sender prefix
 *      parv[1] = channel
 */
static void
mo_opme(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;

  if (!HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[1]);
    return;
  }

  if ((member = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
               me.name, source_p->name, chptr->chname);
    return;
  }

  if (!chan_is_opless(chptr))
  {
    sendto_one(source_p, ":%s NOTICE %s :%s Channel is not opless",
               me.name, source_p->name, chptr->chname);
    return;
  }

  AddMemberFlag(member, CHFL_CHANOP);

  sendto_wallops_flags(UMODE_WALLOP, &me, "OPME called for [%s] by %s!%s@%s",
                       chptr->chname, source_p->name, source_p->username,
                       source_p->host);
  sendto_server(NULL, NOCAPS, NOCAPS,
                ":%s WALLOPS :OPME called for [%s] by %s!%s@%s",
                me.name, chptr->chname, source_p->name, source_p->username,
                source_p->host);

  ilog(LOG_TYPE_IRCD, "OPME called for [%s] by %s!%s@%s",
       chptr->chname, source_p->name, source_p->username,
       source_p->host);

  sendto_server(NULL, CAP_TS6, NOCAPS,
                ":%s PART %s", ID(source_p), chptr->chname);
  sendto_server(NULL, NOCAPS, CAP_TS6,
                ":%s PART %s", source_p->name, chptr->chname);

  sendto_server(NULL, CAP_TS6, NOCAPS,
                ":%s SJOIN %lu %s + :@%s",
                me.id, (unsigned long)chptr->channelts,
                chptr->chname, ID(source_p));
  sendto_server(NULL, NOCAPS, CAP_TS6,
                ":%s SJOIN %lu %s + :@%s",
                me.name, (unsigned long)chptr->channelts,
                chptr->chname, source_p->name);

  sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +o %s",
                       me.name, chptr->chname, source_p->name);
}

static struct Message opme_msgtab = {
  "OPME", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
