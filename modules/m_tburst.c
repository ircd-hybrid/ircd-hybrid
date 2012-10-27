/*  modules/m_tburst.c
 *  Copyright (C) 2002, 2003, 2004, 2005 Hybrid Development Team
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  1.Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  2.Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  3.The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *  $Id$
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
 *      parv[0] = sender prefix
 *      parv[1] = channel timestamp
 *      parv[2] = channel
 *      parv[3] = topic timestamp
 *      parv[4] = topic setter
 *      parv[5] = topic
 */
static void
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
    return;

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

    set_channel_topic(chptr, topic, setby, remote_topic_ts);

    if (topic_differs)
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s TOPIC %s :%s",
                           ConfigServerHide.hide_servers ? me.name : source_p->name,
                           chptr->chname, chptr->topic);
  }

  /*
   * Always propagate what we have received, not only if we accept the topic.
   * This will keep other servers in sync.
   */
  sendto_server(source_p, CAP_TBURST|CAP_TS6, NOCAPS,
                ":%s TBURST %s %s %s %s :%s",
                ID(source_p), parv[1], parv[2], parv[3], setby, topic);
  sendto_server(source_p, CAP_TBURST, CAP_TS6,
                ":%s TBURST %s %s %s %s :%s",
                source_p->name, parv[1], parv[2], parv[3], setby, topic);
}

static struct Message tburst_msgtab = {
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

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
