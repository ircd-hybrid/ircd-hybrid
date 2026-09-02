/*
 * SPDX-FileCopyrightText: 2014-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_opme.c
 * \brief Includes required functions for processing the OPME command.
 */

#include <stddef.h>
#include <stdint.h>

#include "list.h"
#include "log.h"
#include "module.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "client.h"
#include "client_format.h"
#include "conf_oper.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

/*! \brief OPME command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel name
 */
static void
mo_opme(struct Client *source, size_t parc, char *parv[])
{
  const char *const name = parv[1];
  list_node_t *node;

  if (!client_has_oper_flag(source, OPER_FLAG_OPME))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "opme");
    return;
  }

  struct Channel *channel = channel_find(name);
  if (channel == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHCHANNEL, name);
    return;
  }

  struct ChannelMember *member = channel_member_find(channel, source);
  if (member == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOTONCHANNEL, channel->name);
    return;
  }

  LIST_FOREACH(node, channel->member_list.head)
  {
    const struct ChannelMember *tmp = node->data;

    if (channel_member_get_highest_rank(tmp) > CHACCESS_HALFOP)
    {
      sendto_one_notice(source, &me, ":Cannot use OPME on %s: channel is not opless",
                        channel->name);
      return;
    }
  }

  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  log_write(LOG_TYPE_IRCD, "%s used OPME on channel %s",
            source_name, channel->name);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_GLOBAL, "from %s: %s used OPME on channel %s",
                 me.name, source_name, channel->name);
  sendto_servers(NULL, 0, 0, ":%s GLOBOPS :%s used OPME on channel %s",
                 me.id, source_name, channel->name);

  channel_member_set_flags(member, CHFL_CHANOP);
  sendto_channel_local(NULL, channel, 0, 0, 0, ":%s MODE %s +o %s",
                       me.name, channel->name, source->name);
  sendto_servers(NULL, 0, 0, ":%s TMODE %ju %s +o %s", me.id, channel->creation_time,
                 channel->name, source->id);
}

static struct Command command_table =
{
  .name = "OPME",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_opme, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
