/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2002-2014 ircd-hybrid development team
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

/*! \file m_tburst.c
 * \brief Includes required functions for processing the TBURST command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "modules.h"
#include "hash.h"
#include "s_serv.h"
#include "conf.h"
#include "parse.h"


/* ms_tburst()
 *
 *      parv[0] = command
 *      parv[1] = channel timestamp
 *      parv[2] = channel
 *      parv[3] = topic timestamp
 *      parv[4] = topic setter
 *      parv[5] = topic
 */
static int
ms_tburst(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  int accept_remote = 0;
  time_t remote_channel_ts = atol(parv[1]);
  time_t remote_topic_ts = atol(parv[3]);
  const char *topic = parv[5];
  const char *setby = parv[4];

  /*
   * Do NOT test parv[5] for an empty string and return if true!
   * parv[5] CAN be an empty string, i.e. if the other side wants
   * to unset our topic.  Don't forget: an empty topic is also a
   * valid topic.
   */


  if ((chptr = hash_find_channel(parv[2])) == NULL)
    return 0;

  /*
   * The logic for accepting and rejecting channel topics was
   * always a bit hairy, so now we got exactly 2 cases where
   * we would accept a bursted topic
   *
   * Case 1:
   *        The TS of the remote channel is older than ours
   * Case 2:
   *        The TS of the remote channel is equal to ours AND
   *        the TS of the remote topic is newer than ours
   */
  if (HasFlag(source_p, FLAGS_SERVICE))
    accept_remote = 1;
  else if (remote_channel_ts < chptr->channelts)
    accept_remote = 1;
  else if (remote_channel_ts == chptr->channelts)
    if (remote_topic_ts > chptr->topic_time)
      accept_remote = 1;

  if (accept_remote)
  {
    int topic_differs = strncmp(chptr->topic, topic, sizeof(chptr->topic) - 1);
    int hidden_server = (ConfigServerHide.hide_servers || IsHidden(source_p));

    set_channel_topic(chptr, topic, setby, remote_topic_ts, !!MyClient(source_p));

    sendto_server(source_p, CAP_TBURST, NOCAPS,
                  ":%s TBURST %s %s %s %s :%s",
                  ID(source_p), parv[1], parv[2], parv[3], setby, topic);

    if (topic_differs)
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s TOPIC %s :%s",
                           hidden_server ? me.name : source_p->name,
                           chptr->chname, chptr->topic);
  }

  return 0;
}

static struct Message tburst_msgtab =
{
  "TBURST", 0, 0, 6, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_tburst, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&tburst_msgtab);
  add_capability("TBURST", CAP_TBURST, 1);
}

static void
module_exit(void)
{
  mod_del_cmd(&tburst_msgtab);
  delete_capability("TBURST");
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
