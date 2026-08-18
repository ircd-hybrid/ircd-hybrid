/*
 * SPDX-FileCopyrightText: 2002-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_tburst.c
 * \brief Includes required functions for processing the TBURST command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "io_parse.h"
#include "io_string.h"
#include "module.h"

#include "channel.h"
#include "client.h"
#include "conf.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static size_t
_tburst_topic_stored_length(const char *topic)
{
  assert(topic);
  assert(TOPICLEN > 0);

  size_t length = 0;
  while (topic[length] && length < TOPICLEN)
    ++length;

  return length;
}

static bool
_tburst_topic_matches_current(const struct Channel *channel, const char *topic)
{
  const char *const current_topic = string_or_empty(channel->topic);
  const size_t stored_length = _tburst_topic_stored_length(topic);

  if (strlen(current_topic) != stored_length)
    return false;

  return memcmp(current_topic, topic, stored_length) == 0;
}

static bool
_tburst_topic_is_unchanged(const struct Channel *channel, const char *topic_setter, const char *topic)
{
  if (!_tburst_topic_matches_current(channel, topic))
    return false;

  return strcmp(string_or_empty(channel->topic_setter), topic_setter) == 0;
}

static bool
_tburst_should_accept(const struct Client *source, const struct Channel *channel,
                      uintmax_t channel_ts, uintmax_t topic_ts,
                      const char *topic_setter, const char *topic)
{
  if (channel_ts > channel->creation_time)
    return false;

  if (client_is_service(source))
    return true;

  if (channel_ts < channel->creation_time)
    return true;

  if (topic_ts > channel->topic_time)
    return true;

  if (topic_ts < channel->topic_time)
    return false;

  /*
   * Equal topic timestamps have no deterministic winner. Accept only an
   * idempotent repeat of the exact effective topic state.
   */
  return _tburst_topic_is_unchanged(channel, topic_setter, topic);
}

static void
_tburst_notify_channel_members(const struct Client *source, const struct Channel *channel)
{
  if (client_is_user(source))
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s!%s@%s TOPIC %s :%s",
                         source->name, source->username, source->host,
                         channel->name, string_or_empty(channel->topic));
  else
    sendto_channel_local(NULL, channel, 0, 0, 0, ":%s TOPIC %s :%s",
                         client_get_visible_server_name(source),
                         channel->name, string_or_empty(channel->topic));
}

static void
_tburst_commit(struct Client *source, struct Channel *channel, uintmax_t channel_ts, uintmax_t topic_ts,
               const char *topic_setter, const char *topic)
{
  const bool topic_changed = !_tburst_topic_matches_current(channel, topic);

  channel_set_topic(channel, topic, topic_setter, topic_ts, false);

  sendto_servers(source, CAPAB_TBURST, 0, ":%s TBURST %ju %s %ju %s :%s",
                 source->id, channel_ts, channel->name, topic_ts, topic_setter, string_or_empty(channel->topic));

  if (topic_changed)
    _tburst_notify_channel_members(source, channel);
}

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
  if (!client_is_user(source) && !client_is_server(source))
    return;

  struct Channel *const channel = channel_find(parv[2]);
  if (channel == NULL)
    return;

  uintmax_t channel_ts;
  if (io_parse_uintmax(parv[1], &channel_ts) != IO_PARSE_OK)
    return;

  uintmax_t topic_ts;
  if (io_parse_uintmax(parv[3], &topic_ts) != IO_PARSE_OK)
    return;

  const char *const topic_setter = parv[4];
  const char *const topic = parv[5];  /* May be empty to clear the topic. */
  if (!_tburst_should_accept(source, channel, channel_ts, topic_ts, topic_setter, topic))
    return;

  _tburst_commit(source, channel, channel_ts, topic_ts, topic_setter, topic);
}

static struct Command command_table =
{
  .name = "TBURST",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_tburst, .args_min = 6, .empty_last_arg = true },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("TBURST", CAPAB_TBURST, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("TBURST");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
