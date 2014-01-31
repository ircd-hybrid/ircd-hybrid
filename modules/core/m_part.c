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

/*! \file m_part.c
 * \brief Includes required functions for processing the PART command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "packet.h"


/* part_one_client()
 *
 * inputs	- pointer to server
 * 		- pointer to source client to remove
 *		- char pointer of name of channel to remove from
 * output	- none
 * side effects	- remove ONE client given the channel name
 */
static void
part_one_client(struct Client *source_p, const char *name, const char *reason)
{
  struct Channel *chptr = NULL;
  struct Membership *ms = NULL;

  if ((chptr = hash_find_channel(name)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, name);
    return;
  }

  if ((ms = find_channel_link(source_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOTONCHANNEL),
               me.name, source_p->name, name);
    return;
  }

  if (MyConnect(source_p) && !HasUMode(source_p, UMODE_OPER))
    check_spambot_warning(source_p, NULL);

  /*
   * Remove user from the old channel (if any)
   * only allow /part reasons in -m chans
   */
  if (*reason && (!MyConnect(source_p) ||
      ((can_send(chptr, source_p, ms, reason) &&
       (source_p->localClient->firsttime + ConfigFileEntry.anti_spam_exit_message_time)
        < CurrentTime))))
  {
    sendto_server(source_p->from, CAP_TS6, NOCAPS, ":%s PART %s :%s",
                  ID(source_p), chptr->chname, reason);
    sendto_server(source_p->from, NOCAPS, CAP_TS6, ":%s PART %s :%s",
                  source_p->name, chptr->chname, reason);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s :%s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname, reason);
  }
  else
  {
    sendto_server(source_p->from, CAP_TS6, NOCAPS, ":%s PART %s",
                  ID(source_p), chptr->chname);
    sendto_server(source_p->from, NOCAPS, CAP_TS6, ":%s PART %s",
                  source_p->name, chptr->chname);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname);
  }

  remove_user_from_channel(ms);
}

/*
** m_part
**      parv[0] = sender prefix
**      parv[1] = channel
**      parv[2] = reason
*/
static int
m_part(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  char *p = NULL, *name = NULL;
  char reason[KICKLEN + 1] = { '\0' };

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "PART");
    return 0;
  }

  if (parc > 2 && !EmptyString(parv[2]))
    strlcpy(reason, parv[2], sizeof(reason));

  /* Finish the flood grace period... */
  if (MyClient(source_p) && !IsFloodDone(source_p))
    flood_endgrace(source_p);

  for (name = strtoken(&p, parv[1], ","); name;
       name = strtoken(&p,    NULL, ","))
    part_one_client(source_p, name, reason);
  return 0;
}

static struct Message part_msgtab =
{
  "PART", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_part, m_part, m_ignore, m_part, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&part_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&part_msgtab);
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
