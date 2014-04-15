/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2014 ircd-hybrid development team
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

/*! \file m_svspart.c
 * \brief Includes required functions for processing the SVSPART command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
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
part_one_client(struct Client *target_p, const char *name, const char *reason)
{
  struct Channel *chptr = NULL;
  struct Membership *ms = NULL;

  if ((chptr = hash_find_channel(name)) == NULL)
  {
    sendto_one_numeric(target_p, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  if ((ms = find_channel_link(target_p, chptr)) == NULL)
  {
    sendto_one_numeric(target_p, &me, ERR_NOTONCHANNEL, chptr->chname);
    return;
  }

  /*
   * Remove user from the old channel (if any)
   * only allow /part reasons in -m chans
   */
  if (*reason && (!MyConnect(target_p) ||
      ((can_send(chptr, target_p, ms, reason) &&
       (target_p->localClient->firsttime + ConfigFileEntry.anti_spam_exit_message_time)
        < CurrentTime))))
  {
    sendto_server(target_p, NOCAPS, NOCAPS, ":%s PART %s :%s",
                  target_p->id, chptr->chname, reason);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s :%s",
                         target_p->name, target_p->username,
                         target_p->host, chptr->chname, reason);
  }
  else
  {
    sendto_server(target_p, NOCAPS, NOCAPS, ":%s PART %s",
                  target_p->id, chptr->chname);
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s",
                         target_p->name, target_p->username,
                         target_p->host, chptr->chname);
  }

  remove_user_from_channel(ms);
}

/*! \brief SVSPART command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = channel name
 *      - parv[3] = part message
 */
static int
ms_svspart(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *p = NULL, *name = NULL;
  char reason[KICKLEN + 1] = "";

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return 0;

  if (EmptyString(parv[2]))
    return 0;

  if ((target_p = find_person(source_p, parv[1])) == NULL)
    return 0;

  if (target_p->from == source_p->from)
  {
    sendto_realops_flags(UMODE_DEBUG, L_ALL, SEND_NOTICE,
                         "Received wrong-direction SVSJOIN "
                         "for %s (behind %s) from %s",
                         target_p->name, source_p->from->name,
                         get_client_name(source_p, HIDE_IP));
    return 0;
  }

  if (!MyConnect(target_p))
  {
    if (parc == 3)
      sendto_one(target_p, ":%s SVSPART %s %s", source_p->id,
                 target_p->id, parv[2]);
    else
      sendto_one(target_p, ":%s SVSPART %s %s %s", source_p->id,
                 target_p->id, parv[2], parv[3]);
    return 0;
  }

  if (parc > 3 && !EmptyString(parv[3]))
    strlcpy(reason, parv[3], sizeof(reason));

  for (name = strtoken(&p, parv[2], ","); name;
       name = strtoken(&p,    NULL, ","))
    part_one_client(target_p, name, reason);
  return 0;
}

static struct Message svspart_msgtab =
{
  "SVSPART", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_ignore, ms_svspart, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svspart_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svspart_msgtab);
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
