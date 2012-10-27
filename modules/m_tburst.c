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
#include "handlers.h"
#include "client.h"
#include "common.h"
#include "ircd.h"
#include "send.h"
#include "msg.h"
#include "modules.h"
#include "hash.h"
#include "s_serv.h"
#include "s_conf.h"

static void ms_tb(struct Client *, struct Client *, int, char *[]);
static void ms_tburst(struct Client *, struct Client *, int, char *[]);
static void set_topic(struct Client *, struct Channel *, time_t,
                      const char *, const char *);

struct Message tburst_msgtab = {
  "TBURST", 0, 0, 5, 0, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_tburst, m_ignore, m_ignore, m_ignore }
};

struct Message tb_msgtab = {
  "TB", 0, 0, 4, 0, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_tb, m_ignore, m_ignore, m_ignore }
};

#ifndef STATIC_MODULES

void
_modinit(void)
{
  mod_add_cmd(&tb_msgtab);
  add_capability("TB", CAP_TB, 1);

  mod_add_cmd(&tburst_msgtab);
  add_capability("TBURST", CAP_TBURST, 1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&tb_msgtab);
  delete_capability("TB");

  mod_del_cmd(&tburst_msgtab);
  delete_capability("TBURST");
}

const char *_version = "$Revision$";

#endif /* !STATIC_MODULES */

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
  const char *topic = "";
  const char *setby = "";

  /*
   * Do NOT test parv[5] for an empty string and return if true!
   * parv[5] CAN be an empty string, i.e. if the other side wants
   * to unset our topic.  Don't forget: an empty topic is also a
   * valid topic.
   */


  if ((chptr = hash_find_channel(parv[2])) == NULL)
    return;

  if (parc == 6)
  {
    topic = parv[5];
    setby = parv[4];
  }

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
  if (remote_channel_ts < chptr->channelts)
    accept_remote = 1;
  else if (remote_channel_ts == chptr->channelts)
    if (remote_topic_ts > chptr->topic_time)
      accept_remote = 1;

  if (accept_remote)
  {
    int topic_differs = strcmp(chptr->topic ? chptr->topic : "", topic);

    set_channel_topic(chptr, topic, setby, remote_topic_ts);

    if (topic_differs)
      sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s TOPIC %s :%s",
                           ConfigServerHide.hide_servers ? me.name : source_p->name,
                           chptr->chname, chptr->topic == NULL ? "" : chptr->topic);
  }

  /*
   * Always propagate what we have received, not only if we accept the topic.
   * This will keep other servers in sync.
   */
  sendto_server(source_p, chptr, CAP_TBURST, NOCAPS,
                ":%s TBURST %s %s %s %s :%s",
                source_p->name, parv[1], parv[2], parv[3], setby, topic);
  if (parc > 5 && *topic != '\0') /* unsetting a topic is not supported by TB */
    sendto_server(source_p, chptr, CAP_TB, CAP_TBURST,
                  ":%s TB %s %s %s :%s",
                  source_p->name, parv[1], parv[2], setby, topic);
}

/* ms_tb()
 * 
 *      parv[0] = sender prefix
 *      parv[1] = channel name
 *      parv[2] = topic timestamp
 *      parv[3] = topic setter OR topic itself if parc == 4
 *      parv[4] = topic itself if parc == 5
 */
#define tb_channel      parv[1]
#define tb_topicts_str  parv[2]

static void
ms_tb(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr;
  time_t tb_topicts = atol(tb_topicts_str);
  char *tb_whoset = NULL;
  char *tb_topic = NULL;

  if ((chptr = hash_find_channel(tb_channel)) == NULL)
    return;

  if (parc == 5)
  {
    tb_whoset = parv[3];
    tb_topic = parv[4];
  }
  else
  {
    tb_whoset = source_p->name;
    tb_topic = parv[3];
  }

  set_topic(source_p, chptr, tb_topicts, tb_whoset, tb_topic);
}

/*
 * set_topic
 *
 * inputs	- source_p pointer
 *		- channel pointer
 *		- topicts to set
 *		- who to set as who doing the topic
 *		- topic
 * output	- none
 * Side effects	- simply propagates topic as needed
 * little helper function, could be removed
 */
static void
set_topic(struct Client *source_p, struct Channel *chptr, time_t topicts,
          const char *topicwho, const char *topic)
{
  int new_topic = strcmp(chptr->topic ? chptr->topic : "", topic);

  set_channel_topic(chptr, topic, topicwho, topicts);

  /* Only send TOPIC to channel if it's different */
  if (new_topic)
    sendto_channel_local(ALL_MEMBERS, NO, chptr, ":%s TOPIC %s :%s",
                         ConfigServerHide.hide_servers ? me.name : source_p->name,
                         chptr->chname, chptr->topic == NULL ? "" : chptr->topic);

  sendto_server(source_p, chptr, CAP_TBURST, NOCAPS,
                ":%s TBURST %lu %s %lu %s :%s",
                me.name, (unsigned long)chptr->channelts, chptr->chname,
                (unsigned long)chptr->topic_time,
                chptr->topic_info == NULL ? "" : chptr->topic_info,
                chptr->topic == NULL ? "" : chptr->topic);
  sendto_server(source_p, chptr, CAP_TB, CAP_TBURST,
                ":%s TB %s %lu %s :%s",
                me.name, chptr->chname,
                (unsigned long)chptr->topic_time, 
                chptr->topic_info == NULL ? "" : chptr->topic_info,
                chptr->topic == NULL ? "" : chptr->topic);
}
