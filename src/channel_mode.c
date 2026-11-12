/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file channel_mode.c
 * \brief Controls modes on channels.
 */

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "address.h"
#include "io.h"
#include "io_parse.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"

#include "channel.h"
#include "channel_member.h"
#include "channel_mode.h"
#include "channel_mode_batch.h"
#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "extban.h"
#include "ircd.h"
#include "isupport.h"
#include "nuh.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "server_capab.h"
#include "user_mode.h"

/** Buffer holding a list of channel modes to be used for RPL_MYINFO */
char cmode_rpl04[2][256];
/** Buffer holding a list of channel modes to be used for RPL_ISUPPORT */
char cmode_class[4][256];

struct ChannelModeChange
{
  unsigned char letter;
  enum channel_mode_action action;
  const char *argument;
  const char *target_id;
};

struct ChannelModeContext
{
  struct Client *source;
  struct Channel *channel;
  int rank;
  unsigned int errors;
  uint32_t seen_simple_modes;
  size_t limited_mode_count;
  size_t change_count;
  struct ChannelModeChange changes[IRCD_BUFSIZE];
  size_t arguments_used;
  char arguments[PARSE_MAX_PARAMETERS * MODEBUFLEN];
};

static const char *
_channel_mode_copy_argument(struct ChannelModeContext *ctx, const char *argument)
{
  if (argument == NULL)
    return NULL;

  const size_t length = strlen(argument) + 1;
  assert(length <= MODEBUFLEN);
  assert(length <= sizeof(ctx->arguments) - ctx->arguments_used);

  char *const copy = ctx->arguments + ctx->arguments_used;
  memcpy(copy, argument, length);
  ctx->arguments_used += length;
  return copy;
}

static void
_channel_mode_record_change(struct ChannelModeContext *ctx, const struct chan_mode *mode,
                            enum channel_mode_action action, const char *argument, const char *target_id)
{
  assert(ctx->change_count < IO_ARRAY_LENGTH(ctx->changes));

  const char *const argument_copy = _channel_mode_copy_argument(ctx, argument);
  const char *const target_id_copy = _channel_mode_copy_argument(ctx, target_id);

  ctx->changes[ctx->change_count++] = (struct ChannelModeChange)
  {
    .letter = mode->letter,
    .action = action,
    .argument = argument_copy,
    .target_id = target_id_copy
  };
}

static void
_channel_mode_discard_additions(struct ChannelModeContext *ctx, const struct chan_mode *mode)
{
  for (size_t i = 0; i < ctx->change_count; ++i)
    if (ctx->changes[i].letter == mode->letter && ctx->changes[i].action == MODE_ADD)
      ctx->changes[i].letter = '\0';
}

static void
check_string(char *s)
{
  char *str = s;

  assert(s);

  for (; *s; ++s)
  {
    if (io_ascii_is_space(*s))
    {
      *s = '\0';
      break;
    }
  }

  if (string_is_empty(str))
    strcpy(str, "*");
}

static bool
_ban_format_mask(struct Ban *ban)
{
  size_t prefix_length;
  if (extban_format_prefix(ban->extban_flags, ban->banstr, sizeof(ban->banstr), &prefix_length) != EXTBAN_SUCCESS)
    return false;

  const size_t parameter_capacity = sizeof(ban->banstr) - prefix_length;
  int formatted_length;

  if (ban->extban_flags & extban_known_matching_mask())
    formatted_length = snprintf(ban->banstr + prefix_length, parameter_capacity, "%s", ban->extban_parameter);
  else
    formatted_length = snprintf(ban->banstr + prefix_length, parameter_capacity, "%s!%s@%s",
                                ban->name, ban->user, ban->host);

  if (formatted_length < 0 || (size_t)formatted_length >= parameter_capacity)
    return false;

  return true;
}

static bool
_ban_mask_equals(const struct Ban *ban, const char *mask)
{
  if (ban->extban_opaque)
    return strcmp(ban->banstr, mask) == 0;

  if (ban->extban_flags)
  {
    char prefix[EXTBAN_PREFIX_BUFFER_SIZE];
    size_t prefix_length;
    if (extban_format_prefix(ban->extban_flags, prefix, sizeof(prefix), &prefix_length) != EXTBAN_SUCCESS ||
        strncmp(mask, prefix, prefix_length) != 0)
      return false;

    return extban_parameters_equal(ban->extban_flags, ban->banstr + prefix_length, mask + prefix_length);
  }

  return io_strcasecmp(ban->banstr, mask) == 0;
}

const char *
add_id(struct Client *client, struct Channel *channel, const char *banid, list_t *list, uint32_t list_type)
{
  const bool local = client_is_local_user(client);
  struct Ban *ban = NULL;
  char mask[MODEBUFLEN];

  if (strlcpy(mask, banid, sizeof(mask)) >= sizeof(mask))
    goto invalid;

  if (local)
    collapse(mask);

  const extban_parse_result_t parsed = extban_parse(mask);
  if (parsed.status == EXTBAN_PARSE_INVALID_SYNTAX ||
      (local && parsed.status == EXTBAN_PARSE_UNSUPPORTED))
    goto invalid;

  char *const parameter = mask + parsed.parameter_offset;
  if (local && parsed.status == EXTBAN_PARSE_SUCCESS &&
      !extban_validate_local(parsed.flags, list_type, parameter))
    goto invalid;
  if (string_is_empty(parameter))
    return NULL;

  ban = io_calloc(sizeof(*ban));
  ban->extban_flags = parsed.flags;
  ban->extban_opaque = parsed.status == EXTBAN_PARSE_UNSUPPORTED;

  if (!ban->extban_opaque)
  {
    if (ban->extban_flags & extban_known_matching_mask())
      strlcpy(ban->extban_parameter, parameter, sizeof(ban->extban_parameter));
    else
    {
      check_string(parameter);

      struct nuh_split nuh =
      {
        .nuhmask = parameter,
        .nickptr = ban->name,
        .userptr = ban->user,
        .hostptr = ban->host,
        .nicksize = sizeof(ban->name),
        .usersize = sizeof(ban->user),
        .hostsize = sizeof(ban->host)
      };

      nuh_split(&nuh);
      address_parse_prefix(ban->host, &ban->addr, &ban->bits);
    }
  }

  if (local)
  {
    if (!_ban_format_mask(ban))
      goto invalid;
  }
  else
  {
    if (strlcpy(ban->banstr, banid, sizeof(ban->banstr)) >= sizeof(ban->banstr))
      goto invalid;
  }

  struct Ban *replaced = NULL;
  list_node_t *node;
  LIST_FOREACH(node, list->head)
  {
    struct Ban *const existing = node->data;
    const bool equal = (existing->extban_opaque || ban->extban_opaque) ?
      strcmp(existing->banstr, ban->banstr) == 0 : _ban_mask_equals(existing, ban->banstr);

    if (!equal)
      continue;

    if (existing->extban_opaque && !ban->extban_opaque)
    {
      replaced = existing;
      break;
    }

    io_free(ban);
    return NULL;
  }

  if (local && replaced == NULL)
  {
    const size_t mask_count =
      (size_t)list_length(&channel->ban_list) + list_length(&channel->exception_list) +
      list_length(&channel->invite_exception_list);
    const unsigned int limit = channel_has_mode(channel, MODE_EXTLIMIT) ?
      ConfigChannel.max_bans_large : ConfigChannel.max_bans;

    if (mask_count >= limit)
    {
      io_free(ban);
      sendto_one_numeric(client, &me, ERR_BANLISTFULL, channel->name, banid);
      return NULL;
    }
  }

  clear_ban_cache_list(&channel->local_member_list);

  ban->when = io_time_get(IO_TIME_REALTIME_SEC);
  if (client_is_user(client))
    snprintf(ban->who, sizeof(ban->who), "%s!%s@%s",
             client->name, client->username, client->host);
  else
    strlcpy(ban->who, client_get_visible_server_name(client), sizeof(ban->who));

  if (replaced)
    remove_ban(replaced, list);

  list_add_tail(ban, &ban->node, list);
  return ban->banstr;

invalid:
  io_free(ban);
  if (local)
    sendto_one_numeric(client, &me, ERR_INVALIDBAN, channel->name, banid);

  return NULL;
}

static void
_channel_mode_remove_mask(struct ChannelModeContext *ctx, const struct chan_mode *mode,
                          const char *mask, list_t *list)
{
  struct Ban *found = NULL;
  list_node_t *node;

  LIST_FOREACH(node, list->head)
  {
    struct Ban *const ban = node->data;
    if (strcmp(ban->banstr, mask) == 0)
    {
      found = ban;
      break;
    }

    if (found == NULL && _ban_mask_equals(ban, mask))
      found = ban;
  }

  if (found == NULL)
    return;

  _channel_mode_record_change(ctx, mode, MODE_DEL, found->banstr, NULL);
  clear_ban_cache_list(&ctx->channel->local_member_list);
  remove_ban(found, list);
}

struct ChannelMode
channel_mode_merge(const struct ChannelMode *left_mode, const struct ChannelMode *right_mode)
{
  struct ChannelMode merged_mode = *left_mode;
  merged_mode.flags |= right_mode->flags;

  if (right_mode->member_limit > merged_mode.member_limit)
    merged_mode.member_limit = right_mode->member_limit;

  if (strcmp(merged_mode.key, right_mode->key) < 0)
    strlcpy(merged_mode.key, right_mode->key, sizeof(merged_mode.key));

  return merged_mode;
}

struct ChannelModeFormatter
{
  char *modes;
  size_t modes_capacity;
  size_t modes_length;
  char *parameters;
  size_t parameters_capacity;
  size_t parameters_length;
  enum channel_mode_action last_action;
};

static bool
_channel_mode_formatter_append(struct ChannelModeFormatter *formatter, enum channel_mode_action action,
                                unsigned char letter, const char *parameter)
{
  const size_t modes_needed = 1 + (formatter->last_action != action);
  const size_t parameter_length = parameter ? strlen(parameter) : 0;
  const size_t parameters_needed = parameter ? parameter_length + (formatter->parameters_length != 0) : 0;

  if (modes_needed >= formatter->modes_capacity - formatter->modes_length ||
      parameters_needed >= formatter->parameters_capacity - formatter->parameters_length)
    return false;

  if (formatter->last_action != action)
  {
    formatter->modes[formatter->modes_length++] = action == MODE_ADD ? '+' : '-';
    formatter->last_action = action;
  }

  formatter->modes[formatter->modes_length++] = letter;
  formatter->modes[formatter->modes_length] = '\0';

  if (parameter)
  {
    if (formatter->parameters_length)
      formatter->parameters[formatter->parameters_length++] = ' ';

    memcpy(formatter->parameters + formatter->parameters_length, parameter, parameter_length + 1);
    formatter->parameters_length += parameter_length;
  }

  return true;
}

bool
channel_mode_format(const struct ChannelMode *mode, char *modes, size_t modes_capacity,
                    char *parameters, size_t parameters_capacity)
{
  assert(mode);
  assert(modes || modes_capacity == 0);
  assert(parameters || parameters_capacity == 0);

  if (modes_capacity)
    modes[0] = '\0';
  if (parameters_capacity)
    parameters[0] = '\0';

  if (modes_capacity < 2 || parameters_capacity == 0)
    return false;

  modes[0] = '+';
  modes[1] = '\0';

  struct ChannelModeFormatter formatter =
  {
    .modes = modes,
    .modes_capacity = modes_capacity,
    .modes_length = 1,
    .parameters = parameters,
    .parameters_capacity = parameters_capacity,
    .last_action = MODE_ADD
  };

  for (const struct chan_mode *mode_entry = cmode_tab; mode_entry->letter; ++mode_entry)
    if (mode_entry->mode & mode->flags)
      if (!_channel_mode_formatter_append(&formatter, MODE_ADD, mode_entry->letter, NULL))
        goto buffer_too_small;

  if (mode->member_limit)
  {
    char limit_buffer[sizeof(mode->member_limit) * CHAR_BIT + 1];
    snprintf(limit_buffer, sizeof(limit_buffer), "%" PRIu32, mode->member_limit);

    if (!_channel_mode_formatter_append(&formatter, MODE_ADD, 'l', limit_buffer))
      goto buffer_too_small;
  }

  if (mode->key[0])
    if (!_channel_mode_formatter_append(&formatter, MODE_ADD, 'k', mode->key))
      goto buffer_too_small;

  return true;

buffer_too_small:
  modes[0] = '\0';
  parameters[0] = '\0';
  return false;
}

bool
channel_mode_format_diff(const struct ChannelMode *old_mode, const struct ChannelMode *new_mode,
                         char *modes, size_t modes_capacity,
                         char *parameters, size_t parameters_capacity)
{
  assert(old_mode);
  assert(new_mode);
  assert(modes || modes_capacity == 0);
  assert(parameters || parameters_capacity == 0);

  if (modes_capacity)
    modes[0] = '\0';
  if (parameters_capacity)
    parameters[0] = '\0';

  if (modes_capacity == 0 || parameters_capacity == 0)
    return false;

  struct ChannelModeFormatter formatter =
  {
    .modes = modes,
    .modes_capacity = modes_capacity,
    .parameters = parameters,
    .parameters_capacity = parameters_capacity,
    .last_action = MODE_NONE
  };

  for (const struct chan_mode *mode = cmode_tab; mode->letter; ++mode)
    if ((mode->mode & new_mode->flags) && !(mode->mode & old_mode->flags))
      if (!_channel_mode_formatter_append(&formatter, MODE_ADD, mode->letter, NULL))
        goto buffer_too_small;

  for (const struct chan_mode *mode = cmode_tab; mode->letter; ++mode)
    if ((mode->mode & old_mode->flags) && !(mode->mode & new_mode->flags))
      if (!_channel_mode_formatter_append(&formatter, MODE_DEL, mode->letter, NULL))
        goto buffer_too_small;

  if (old_mode->member_limit && new_mode->member_limit == 0)
    if (!_channel_mode_formatter_append(&formatter, MODE_DEL, 'l', NULL))
      goto buffer_too_small;

  if (old_mode->key[0] && new_mode->key[0] == '\0')
    if (!_channel_mode_formatter_append(&formatter, MODE_DEL, 'k', old_mode->key))
      goto buffer_too_small;

  if (new_mode->member_limit && old_mode->member_limit != new_mode->member_limit)
  {
    char limit_buffer[sizeof(new_mode->member_limit) * CHAR_BIT + 1];
    snprintf(limit_buffer, sizeof(limit_buffer), "%" PRIu32, new_mode->member_limit);

    if (!_channel_mode_formatter_append(&formatter, MODE_ADD, 'l', limit_buffer))
      goto buffer_too_small;
  }

  if (new_mode->key[0] && strcmp(old_mode->key, new_mode->key))
    if (!_channel_mode_formatter_append(&formatter, MODE_ADD, 'k', new_mode->key))
      goto buffer_too_small;

  return true;

buffer_too_small:
  modes[0] = '\0';
  parameters[0] = '\0';
  return false;
}

static void
fix_key(char *arg)
{
  unsigned char *s = (unsigned char *)arg;
  unsigned char *t = (unsigned char *)arg;

  for (unsigned char c; (c = *s) && s - (unsigned char *)arg < KEYLEN; ++s)
  {
    c &= 0x7f;

    if (c != ':' && c > ' ' && c != ',')
      *t++ = c;
  }

  *t = '\0';
}

void
clear_ban_cache_list(list_t *list)
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
  {
    struct ChannelMember *const member = node->data;
    member->flags &= ~(CHFL_BAN_SILENCED | CHFL_BAN_CHECKED);
  }
}

/*
 * Bitmasks for various error returns that channel_mode_set should only return
 * once per call  -orabidoo
 */
enum
{
  SM_ERR_NOOPS        = 1 << 0,  /* No chan ops */
  SM_ERR_UNKNOWN      = 1 << 1,
  SM_ERR_RPL_B        = 1 << 2,
  SM_ERR_RPL_E        = 1 << 3,
  SM_ERR_RPL_I        = 1 << 4,
  SM_ERR_NOTONCHANNEL = 1 << 5,  /* Client is not on channel */
  SM_ERR_NOTOPER      = 1 << 6,  /* Only irc-operators can change that mode */
  SM_ERR_ONLYSERVER   = 1 << 7,  /* Only servers or services can change that mode */
  SM_ERR_MLOCK        = 1 << 8,
  SM_ERR_NOSUCHNICK   = 1 << 9,
};

static bool
channel_mode_can_change(struct ChannelModeContext *ctx, const struct chan_mode *mode)
{
  struct Client *const client = ctx->source;
  struct Channel *const channel = ctx->channel;

  if (!client_is_local_user(client))
    return true;

  if (mode->only_opers)
  {
    if (!client_is_oper(client))
    {
      if (!(ctx->errors & SM_ERR_NOTOPER))
        sendto_one_numeric(client, &me, ERR_NOPRIVILEGES);

      ctx->errors |= SM_ERR_NOTOPER;
      return false;
    }
  }

  if (mode->only_servers)
  {
    if (!client_is_server(client) && !client_is_service(client))
    {
      if (!(ctx->errors & SM_ERR_ONLYSERVER))
        sendto_one_numeric(client, &me,
                           ctx->rank == CHACCESS_NOTONCHAN ? ERR_NOTONCHANNEL : ERR_ONLYSERVERSCANCHANGE, channel->name);

      ctx->errors |= SM_ERR_ONLYSERVER;
      return false;
    }
  }

  if (ctx->rank < mode->required_rank)
  {
    if (!(ctx->errors & SM_ERR_NOOPS))
      sendto_one_numeric(client, &me,
                         ctx->rank == CHACCESS_NOTONCHAN ? ERR_NOTONCHANNEL : ERR_CHANOPRIVSNEEDED, channel->name);

    ctx->errors |= SM_ERR_NOOPS;
    return false;
  }

  if (channel->mode_lock && strchr(channel->mode_lock, mode->letter))
  {
    if (!(ctx->errors & SM_ERR_MLOCK))
      sendto_one_numeric(client, &me, ERR_MLOCKRESTRICTED, channel->name, mode->letter, channel->mode_lock);

    ctx->errors |= SM_ERR_MLOCK;
    return false;
  }

  return true;
}

static void
chm_nosuch(struct ChannelModeContext *ctx, unsigned char letter)
{
  if (ctx->errors & SM_ERR_UNKNOWN)
    return;

  ctx->errors |= SM_ERR_UNKNOWN;

  if (client_is_local_user(ctx->source))
    sendto_one_numeric(ctx->source, &me, ERR_UNKNOWNMODE, letter);
}

static void
chm_simple(struct ChannelModeContext *ctx, const struct chan_mode *mode,
           enum channel_mode_action action, const char *parameter)
{
  if (!channel_mode_can_change(ctx, mode))
    return;

  if (ctx->seen_simple_modes & mode->mode)
    return;

  ctx->seen_simple_modes |= mode->mode;

  if (action == MODE_ADD)
  {
    if (client_is_local_user(ctx->source) && channel_has_mode(ctx->channel, mode->mode))
      return;

    channel_set_mode(ctx->channel, mode->mode);
  }
  else if (action == MODE_DEL)
  {
    if (client_is_local_user(ctx->source) && !channel_has_mode(ctx->channel, mode->mode))
      return;

    channel_unset_mode(ctx->channel, mode->mode);
  }

  _channel_mode_record_change(ctx, mode, action, NULL, NULL);
}

static void
chm_mask(struct ChannelModeContext *ctx, const struct chan_mode *mode,
         enum channel_mode_action action, const char *parameter)
{
  struct Client *const client = ctx->source;
  struct Channel *const channel = ctx->channel;
  list_t *list;
  enum irc_numerics rpl_list, rpl_endlist;
  unsigned int errtype;

  switch (mode->flag)
  {
    case CHFL_BAN:
      errtype = SM_ERR_RPL_B;
      list = &channel->ban_list;
      rpl_list = RPL_BANLIST;
      rpl_endlist = RPL_ENDOFBANLIST;
      break;
    case CHFL_EXCEPTION:
      errtype = SM_ERR_RPL_E;
      list = &channel->exception_list;
      rpl_list = RPL_EXCEPTLIST;
      rpl_endlist = RPL_ENDOFEXCEPTLIST;
      break;
    case CHFL_INVEX:
      errtype = SM_ERR_RPL_I;
      list = &channel->invite_exception_list;
      rpl_list = RPL_INVEXLIST;
      rpl_endlist = RPL_ENDOFINVEXLIST;
      break;
    default:
      assert(false);
      return;
  }

  if (parameter == NULL)
  {
    if (ctx->errors & errtype)
      return;

    ctx->errors |= errtype;

    list_node_t *node;
    LIST_FOREACH(node, list->head)
    {
      const struct Ban *const ban = node->data;
      sendto_one_numeric(client, &me, rpl_list, channel->name, ban->banstr, ban->who, ban->when);
    }

    sendto_one_numeric(client, &me, rpl_endlist, channel->name);
    return;
  }

  if (!channel_mode_can_change(ctx, mode))
    return;

  if (client_is_local_user(client) && (++ctx->limited_mode_count > MAXMODEPARAMS))
    return;

  if (*parameter == ':' || (!client_is_local(client) && strchr(parameter, ' ')))
    return;

  if (action == MODE_DEL)
  {
    _channel_mode_remove_mask(ctx, mode, parameter, list);
    return;
  }

  const char *const mask = add_id(client, channel, parameter, list, mode->flag);
  if (mask)
    _channel_mode_record_change(ctx, mode, action, mask, NULL);
}

static void
chm_flag(struct ChannelModeContext *ctx, const struct chan_mode *mode,
         enum channel_mode_action action, const char *parameter)
{
  struct Client *const client = ctx->source;
  struct Channel *const channel = ctx->channel;

  if (!channel_mode_can_change(ctx, mode))
    return;

  if (parameter == NULL)
    return;

  struct Client *const target = client_find_user_with_history(client, parameter, NULL);
  if (target == NULL)
  {
    if (client_is_local_user(client) &&
        !(ctx->errors & SM_ERR_NOSUCHNICK))
      sendto_one_numeric(client, &me, ERR_NOSUCHNICK, parameter);

    ctx->errors |= SM_ERR_NOSUCHNICK;
    return;
  }

  struct ChannelMember *const member = channel_member_find(channel, target);
  if (member == NULL)
  {
    if (client_is_local_user(client) &&
        !(ctx->errors & SM_ERR_NOTONCHANNEL))
      sendto_one_numeric(client, &me, ERR_USERNOTINCHANNEL, target->name, channel->name);

    ctx->errors |= SM_ERR_NOTONCHANNEL;
    return;
  }

  if (client_is_local_user(client) && (++ctx->limited_mode_count > MAXMODEPARAMS))
    return;

  if (action == MODE_ADD)
  {
    if (channel_member_has_flags(member, mode->flag))
      return;

    channel_member_set_flags(member, mode->flag);
  }
  else if (action == MODE_DEL)
  {
    if (!channel_member_has_flags(member, mode->flag))
      return;

    channel_member_unset_flags(member, mode->flag);
  }

  _channel_mode_record_change(ctx, mode, action, target->name, target->id);
}

static void
chm_limit(struct ChannelModeContext *ctx, const struct chan_mode *mode,
          enum channel_mode_action action, const char *parameter)
{
  if (!channel_mode_can_change(ctx, mode))
    return;

  if (action == MODE_ADD && parameter)
  {
    unsigned int parsed_limit;
    const io_parse_status_t status = io_parse_uint(parameter, &parsed_limit);

    if (status != IO_PARSE_OK && status != IO_PARSE_RANGE)
      return;

    if (status == IO_PARSE_OK && parsed_limit == 0)
      return;

    const unsigned int limit =
      status == IO_PARSE_RANGE || parsed_limit > INT_MAX ? INT_MAX : parsed_limit;
    char limit_buffer[sizeof(limit) * CHAR_BIT + 1];
    snprintf(limit_buffer, sizeof(limit_buffer), "%u", limit);

    _channel_mode_discard_additions(ctx, mode);
    _channel_mode_record_change(ctx, mode, action, limit_buffer, NULL);
    ctx->channel->mode.member_limit = limit;
  }
  else if (action == MODE_DEL)
  {
    if (!channel_has_member_limit(ctx->channel))
      return;

    ctx->channel->mode.member_limit = 0;
    _channel_mode_record_change(ctx, mode, action, NULL, NULL);
  }
}

static void
chm_key(struct ChannelModeContext *ctx, const struct chan_mode *mode,
        enum channel_mode_action action, const char *parameter)
{
  if (!channel_mode_can_change(ctx, mode))
    return;

  if (action == MODE_ADD && parameter)
  {
    char key[KEYLEN + 1];
    strlcpy(key, parameter, sizeof(key));
    fix_key(key);

    if (string_is_empty(key))
      return;

    assert(*key != ' ');
    strlcpy(ctx->channel->mode.key, key, sizeof(ctx->channel->mode.key));

    _channel_mode_discard_additions(ctx, mode);
    _channel_mode_record_change(ctx, mode, action, key, NULL);
  }
  else if (action == MODE_DEL)
  {
    if (!channel_has_key(ctx->channel))
      return;

    ctx->channel->mode.key[0] = '\0';
    _channel_mode_record_change(ctx, mode, action, "*", NULL);
  }
}

static void
_channel_mode_flush_local_batch(const struct Channel *channel, const char *header, struct ChannelModeBatch *batch)
{
  if (batch->modes_length)
    sendto_channel_local(NULL, channel, 0, 0, 0, "%s%s%s%s",
                         header, batch->modes, batch->parameter_count ? " " : "", batch->parameters);

  channel_mode_batch_reset(batch);
}

static void
_channel_mode_flush_server_batch(const struct Client *source, const char *header, struct ChannelModeBatch *batch)
{
  if (batch->modes_length)
    sendto_servers(source, 0, 0, "%s%s%s%s",
                   header, batch->modes, batch->parameter_count ? " " : "", batch->parameters);

  channel_mode_batch_reset(batch);
}

static void
send_mode_changes_server(const struct ChannelModeContext *ctx)
{
  char header[IRCD_BUFSIZE];
  const int header_length = snprintf(header, sizeof(header), ":%s TMODE %ju %s ",
                                     ctx->source->id, ctx->channel->creation_time, ctx->channel->name);
  assert(header_length >= 0 && (size_t)header_length < sizeof(header));

  struct ChannelModeBatch batch;
  channel_mode_batch_init(&batch, (size_t)header_length);

  for (size_t i = 0; i < ctx->change_count; ++i)
  {
    const struct ChannelModeChange *const change = &ctx->changes[i];
    if (change->letter == '\0')
      continue;

    const char *const argument = change->target_id ? change->target_id : change->argument;
    channel_mode_batch_result_t result = channel_mode_batch_append(&batch, change->action, change->letter, argument);
    if (result == CHANNEL_MODE_BATCH_FULL)
    {
      _channel_mode_flush_server_batch(ctx->source, header, &batch);
      result = channel_mode_batch_append(&batch, change->action, change->letter, argument);
    }

    assert(result == CHANNEL_MODE_BATCH_SUCCESS);
    (void)result;
  }

  _channel_mode_flush_server_batch(ctx->source, header, &batch);
}

static void
send_mode_changes_client(const struct ChannelModeContext *ctx)
{
  const struct Client *const client = ctx->source;
  char header[IRCD_BUFSIZE];
  const int header_length = client_is_user(client) ?
    snprintf(header, sizeof(header), ":%s!%s@%s MODE %s ",
             client->name, client->username, client->host, ctx->channel->name) :
    snprintf(header, sizeof(header), ":%s MODE %s ",
             client_get_visible_server_name(client), ctx->channel->name);
  assert(header_length >= 0 && (size_t)header_length < sizeof(header));

  struct ChannelModeBatch batch;
  channel_mode_batch_init(&batch, (size_t)header_length);

  for (size_t i = 0; i < ctx->change_count; ++i)
  {
    const struct ChannelModeChange *const change = &ctx->changes[i];
    if (change->letter == '\0')
      continue;

    channel_mode_batch_result_t result =
      channel_mode_batch_append(&batch, change->action, change->letter, change->argument);
    if (result == CHANNEL_MODE_BATCH_FULL)
    {
      _channel_mode_flush_local_batch(ctx->channel, header, &batch);
      result = channel_mode_batch_append(&batch, change->action, change->letter, change->argument);
    }

    assert(result == CHANNEL_MODE_BATCH_SUCCESS);
    (void)result;
  }

  _channel_mode_flush_local_batch(ctx->channel, header, &batch);
}

const struct chan_mode *cmode_map[256];
const struct chan_mode cmode_tab[] =
{
  { .letter = 'b', .flag = CHFL_BAN, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'c', .mode = MODE_NOCTRL, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'e', .flag = CHFL_EXCEPTION, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'i', .mode = MODE_INVITEONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'k', .func = chm_key, .required_rank = CHACCESS_HALFOP, .class = MODE_CLASS_B },
  { .letter = 'l', .func = chm_limit, .required_rank = CHACCESS_HALFOP, .class = MODE_CLASS_C },
  { .letter = 'm', .mode = MODE_MODERATED, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'n', .mode = MODE_NOPRIVMSGS, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'p', .mode = MODE_PRIVATE, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'r', .mode = MODE_REGISTERED, .required_rank = CHACCESS_REMOTE, .only_servers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 's', .mode = MODE_SECRET, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 't', .mode = MODE_TOPICLIMIT, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'z', .mode = MODE_SECUREONLY, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'C', .mode = MODE_NOCTCP, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'I', .flag = CHFL_INVEX, .required_rank = CHACCESS_HALFOP, .func = chm_mask, .class = MODE_CLASS_A },
  { .letter = 'K', .mode = MODE_NOKNOCK, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'L', .mode = MODE_EXTLIMIT, .required_rank = CHACCESS_OP, .only_opers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'M', .mode = MODE_MODREG, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'N', .mode = MODE_NONICKCHANGE, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'O', .mode = MODE_OPERONLY, .required_rank = CHACCESS_OP, .only_opers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'Q', .mode = MODE_NOKICK, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'R', .mode = MODE_REGONLY, .required_rank = CHACCESS_HALFOP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'T', .mode = MODE_NONOTICE, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'V', .mode = MODE_NOINVITE, .required_rank = CHACCESS_OP, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = 'Z', .mode = MODE_ISSECURE, .required_rank = CHACCESS_REMOTE, .only_servers = true, .func = chm_simple, .class = MODE_CLASS_D },
  { .letter = '\0' }
};

/*
 * XXX: Currently this needs to be sorted from highest to lowest rank.
 */
const struct chan_mode cflag_tab[] =
{
  { .letter = 'q', .prefix = '~', .flag = CHFL_CHANOWNER, .rank = CHACCESS_OWNER, .required_rank = CHACCESS_OWNER, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'a', .prefix = '&', .flag = CHFL_CHANADMIN, .rank = CHACCESS_ADMIN, .required_rank = CHACCESS_OWNER, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'o', .prefix = '@', .flag = CHFL_CHANOP, .rank = CHACCESS_OP, .required_rank = CHACCESS_OP, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'h', .prefix = '%', .flag = CHFL_HALFOP, .rank = CHACCESS_HALFOP, .required_rank = CHACCESS_OP, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = 'v', .prefix = '+', .flag = CHFL_VOICE, .rank = CHACCESS_VOICE, .required_rank = CHACCESS_HALFOP, .func = chm_flag, .class = MODE_CLASS_B },
  { .letter = '\0' }
};

void
channel_mode_init(void)
{
  char status_letters[IO_ARRAY_LENGTH(cflag_tab)];
  char status_prefixes[IO_ARRAY_LENGTH(cflag_tab)];
  size_t status_count = 0;

  for (const struct chan_mode *tab = cmode_tab; tab->letter; ++tab)
    cmode_map[tab->letter] = tab;

  for (const struct chan_mode *status_mode = cflag_tab; status_mode->letter; ++status_mode)
  {
    cmode_map[status_mode->letter] = status_mode;

    status_letters[status_count] = status_mode->letter;
    status_prefixes[status_count] = status_mode->prefix;
    ++status_count;
  }

  status_letters[status_count] = '\0';
  status_prefixes[status_count] = '\0';

  for (unsigned int i = 0; i < 256; ++i)
  {
    const struct chan_mode *cmode = cmode_map[i];
    if (cmode == NULL)
      continue;

    const char str[] = { cmode->letter, '\0' };
    strlcat(cmode_rpl04[0], str, sizeof(cmode_rpl04[0]));

    if (cmode->class != MODE_CLASS_D)
      strlcat(cmode_rpl04[1], str, sizeof(cmode_rpl04[1]));

   /*
    * from draft-brocklesby-irc-isupport-03:
    * The IRC server MUST NOT list modes in CHANMODES which are also
    * present in the PREFIX parameter; however, for completeness, modes
    * described in PREFIX may be treated as type B modes.
    */
    if (cmode->prefix == '\0')
      strlcat(cmode_class[cmode->class], str, sizeof(cmode_class[cmode->class]));
  }

  isupport_add("CHANMODES", "%s,%s,%s,%s",
               cmode_class[MODE_CLASS_A], cmode_class[MODE_CLASS_B],
               cmode_class[MODE_CLASS_C], cmode_class[MODE_CLASS_D]);

  isupport_add("PREFIX", "(%s)%s", status_letters, status_prefixes);
  isupport_add("STATUSMSG", "%s", status_prefixes);
  isupport_add("MODES", "%u", (unsigned int)MAXMODEPARAMS);
  isupport_add("EXCEPTS", NULL);
  isupport_add("INVEX", NULL);

  capab_add("QOP", CAPAB_QOP, true);
  capab_add("AOP", CAPAB_AOP, true);
  capab_add("HOP", CAPAB_HOP, true);
}

static const char *
_channel_mode_next_parameter(const struct chan_mode *mode, enum channel_mode_action action,
                             size_t parc, char *parv[], size_t *index)
{
  if (mode->class == MODE_CLASS_D || (mode->class == MODE_CLASS_C && action == MODE_DEL))
    return NULL;

  if (*index >= parc)
    return NULL;

  return parv[(*index)++];
}

void
channel_mode_set(struct Client *client, struct Channel *channel, size_t parc, char *parv[])
{
  assert(parc > 0 && parc <= PARSE_MAX_PARAMETERS);
  assert(strlen(parv[0]) < IRCD_BUFSIZE);

  struct ChannelModeContext ctx =
  {
    .source = client,
    .channel = channel,
    .rank = client_is_local_user(client) ?
      channel_member_get_highest_rank(channel_member_find(channel, client)) : CHACCESS_REMOTE
  };
  enum channel_mode_action action = MODE_ADD;
  size_t parameter_index = 1;

  for (const char *ml = parv[0]; *ml; ++ml)
  {
    switch (*ml)
    {
      case '+':
        action = MODE_ADD;
        break;
      case '-':
        action = MODE_DEL;
        break;
      default:
      {
        const struct chan_mode *const mode = cmode_map[(unsigned char)*ml];
        if (mode)
        {
          const char *const parameter = _channel_mode_next_parameter(mode, action, parc, parv, &parameter_index);
          mode->func(&ctx, mode, action, parameter);
        }
        else
          chm_nosuch(&ctx, (unsigned char)*ml);
        break;
      }
    }
  }

  if (ctx.change_count == 0)
    return;

  send_mode_changes_client(&ctx);
  send_mode_changes_server(&ctx);
}

void
channel_mode_clear_member_statuses(struct Channel *channel, const char *source_name)
{
  char header[IRCD_BUFSIZE];
  const int header_length = snprintf(header, sizeof(header), ":%s MODE %s ", source_name, channel->name);
  assert(header_length >= 0 && (size_t)header_length < sizeof(header));

  struct ChannelModeBatch batch;
  channel_mode_batch_init(&batch, (size_t)header_length);

  list_node_t *node;
  LIST_FOREACH(node, channel->member_list.head)
  {
    struct ChannelMember *const member = node->data;

    char status_modes[CHANNEL_MEMBER_STATUS_MODES_BUFFER_SIZE];
    const bool formatted = channel_member_format_status_modes(member, status_modes, sizeof(status_modes));
    assert(formatted);

    if (!formatted || string_is_empty(status_modes))
      continue;

    channel_member_clear_statuses(member);

    for (const char *mode_letter = status_modes; *mode_letter; ++mode_letter)
    {
      channel_mode_batch_result_t result =
        channel_mode_batch_append(&batch, MODE_DEL, (unsigned char)*mode_letter, member->client->name);
      if (result == CHANNEL_MODE_BATCH_FULL)
      {
        _channel_mode_flush_local_batch(channel, header, &batch);
        result = channel_mode_batch_append(&batch, MODE_DEL, (unsigned char)*mode_letter, member->client->name);
      }

      assert(result == CHANNEL_MODE_BATCH_SUCCESS);
      (void)result;

      if (batch.parameter_count == MAXMODEPARAMS)
        _channel_mode_flush_local_batch(channel, header, &batch);
    }
  }

  _channel_mode_flush_local_batch(channel, header, &batch);
}
