/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2002-2024 ircd-hybrid development team
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

/*! \file m_tburst.c
 * \brief Includes required functions for processing the TBURST command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "module.h"
#include "hash.h"
#include "server_capab.h"
#include "conf.h"
#include "parse.h"
#include "channel.h"


/*! \brief TBURST command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel timestamp
 *      - parv[2] = channel name
 *      - parv[3] = topic timestamp
 *      - parv[4] = topic setter
 *      - parv[5] = topic (can be an empty string)
 */
static void
ms_tburst(struct Client *source, int parc, char *parv[])
{
  uintmax_t remote_channel_ts = strtoumax(parv[1], NULL, 10);
  uintmax_t remote_topic_ts = strtoumax(parv[3], NULL, 10);
  const char *topic = parv[5];
  const char *setby = parv[4];

  /*
   * Do NOT test parv[5] for an empty string and return if true!
   * parv[5] CAN be an empty string, i.e. if the other side wants
   * to unset our topic.  Don't forget: an empty topic is also a
   * valid topic.
   */


  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
    return;

  /*
   * The logic for accepting and rejecting channel topics was
   * always a bit hairy, so now we got exactly 3 cases where
   * we would accept a topic
   *
   * Case 1:
   *        A services client/server wants to set a topic
   * Case 2:
   *        The TS of the remote channel is older than ours
   * Case 3:
   *        The TS of the remote channel is equal to ours AND
   *        the TS of the remote topic is newer than ours
   */
  bool accept_remote = false;
  if (HasFlag(source, FLAGS_SERVICE))
    accept_remote = true;
  else if (remote_channel_ts < channel->creation_time)
    accept_remote = true;
  else if (remote_channel_ts == channel->creation_time)
    if (remote_topic_ts > channel->topic_time)
      accept_remote = true;

  if (accept_remote)
  {
    bool topic_differs = strncmp(channel->topic, topic, sizeof(channel->topic) - 1);
    bool hidden_server = (ConfigServerHide.hide_servers || IsHidden(source));

    channel_set_topic(channel, topic, setby, remote_topic_ts, false);

    sendto_server(source, CAPAB_TBURST, 0, ":%s TBURST %s %s %s %s :%s",
                  source->id, parv[1], parv[2], parv[3], setby, topic);

    /* If it's a new topic, send it to clients, otherwise drop it to save bandwith. */
    if (topic_differs)
    {
      if (IsClient(source))
        sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                             source->name, source->username, source->host, channel->name, channel->topic);
      else
        sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :%s",
                             hidden_server ? me.name : source->name, channel->name, channel->topic);
    }
  }
}

static struct Command tburst_msgtab =
{
  .name = "TBURST",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_tburst, .args_min = 6, .empty_last_arg = true },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
init_handler(void)
{
  command_add(&tburst_msgtab);
  capab_add("TBURST", CAPAB_TBURST, true);
}

static void
exit_handler(void)
{
  command_del(&tburst_msgtab);
  capab_del("TBURST");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
