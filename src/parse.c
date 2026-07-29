/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file parse.c
 * \brief The message parser.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"
#include "log.h"
#include "misc.h"

#include "channel.h"
#include "client.h"
#include "client_find.h"
#include "client_format.h"
#include "client_id.h"
#include "client_input.h"
#include "conf.h"
#include "command.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

typedef struct parse_context
{
  char *const buffer;
  const char *const buffer_end;
  char *buffer_cursor;

  struct Client *const client;
  struct Client *source;
  struct Command *command;

  unsigned int numeric;
  char *command_token;

  unsigned int parc;
  char *parv[PARSE_MAX_PARAMETERS + 2];  /* <command> + <parameters> + NULL */
} parse_context_t;

static bool
_parse_uid_is_routed_via_link(const struct Client *link, const char *uid)
{
  assert(link);
  assert(client_is_server(link));

  char sid[CLIENT_ID_SID_LENGTH + 1];
  if (!client_id_extract_sid_from_uid(uid, sid))
    return false;

  /*
   * A UID is only eligible for unknown-client cleanup if its SID resolves
   * to a server that is actually routed through the sending link.
   */
  const struct Client *const server = client_find_server_by_sid(sid);
  return server && server->nexthop == link;
}

static void
_parse_handle_unknown_prefix(struct Client *link, const char *prefix)
{
  assert(link);
  assert(client_is_server(link));
  assert(!string_is_empty(prefix));

  /*
   * Unknown prefixes are classified as follows:
   *   - valid SID or dotted server name: server prefix
   *   - valid UID from this server path: client ID
   *   - digit-starting but otherwise invalid: invalid numeric prefix
   *   - everything else: nickname
   */
  client_format_name_buffer_t link_name_buffer;
  const char *const link_name = client_format_name(link, CLIENT_FORMAT_NAME_LOG, &link_name_buffer);

  if (client_id_is_valid_sid(prefix) || strchr(prefix, '.'))
  {
    sendto_one(link, ":%s SQUIT %s :Unknown server prefix",
               me.id, prefix);
    log_write(LOG_TYPE_DEBUG, "Received message with unknown server prefix '%s' from %s",
              prefix, link_name);
    return;
  }

  if (client_id_is_valid_uid(prefix))
  {
    if (_parse_uid_is_routed_via_link(link, prefix))
    {
      sendto_one(link, ":%s KILL %s :%s (Unknown client ID)",
                 me.id, prefix, me.name);
      log_write(LOG_TYPE_DEBUG, "Received message with unknown client ID '%s' from %s",
                prefix, link_name);
    }
    else
      log_write(LOG_TYPE_DEBUG, "Received message with invalid numeric prefix '%s' from %s",
                prefix, link_name);

    return;
  }

  if (IsDigit(prefix[0]))
  {
    log_write(LOG_TYPE_DEBUG, "Received message with invalid numeric prefix '%s' from %s",
              prefix, link_name);
    return;
  }

  sendto_one(link, ":%s KILL %s :%s (Unknown nickname)",
             me.id, prefix, me.name);
  log_write(LOG_TYPE_DEBUG, "Received message with unknown nickname '%s' from %s",
            prefix, link_name);
}

/*
 *
 *      parc    number of arguments ('command name' counted as one!)
 *      parv[0] pointer to 'command name' (may point to empty string) (not used)
 *      parv[1]..parv[parc-1]
 *              pointers to additional parameters, this is a NULL
 *              terminated list (parv[parc] == NULL).
 *
 * *WARNING*
 *      Numerics are mostly error reports. If there is something
 *      wrong with the message, just *DROP* it! Don't even think of
 *      sending back a neat error message -- big danger of creating
 *      a ping pong error message...
 *
 * Rewritten by Nemesi, Jan 1999, to support numeric nicks in parv[1]
 *
 * Called when we get a numeric message from a remote _server_ and we are
 * supposed to forward it somewhere. Note that we always ignore numerics sent
 * to 'me' and simply drop the message if we can't handle with this properly:
 * the savvy approach is NEVER generate an error in response to an... error :)
 */
static void
_parse_handle_numeric(unsigned int numeric, struct Client *source, unsigned int parc, char *parv[])
{
  assert(source);
  assert(parv);
  assert(parc > 0);
  assert(parc <= PARSE_MAX_PARAMETERS + 1);
  assert(parv[0]);
  assert(parv[parc] == NULL);

  /*
   * Avoid trash, we need it to come from a server and have a target
   */
  if (!client_is_server(source) || parc < 2 || string_is_empty(parv[1]))
    return;

  assert(source->nexthop);

  /*
   * Numerics below 100 talk about the current 'connection', you're not
   * connected to a remote server so it doesn't make sense to send them
   * remotely - but the information they contain may be useful, so we
   * remap them up. Weird, but true.  -- Isomer
   */
  if (numeric < 100)
    numeric += 100;

  const char *const name = parv[1];
  const char *const text = (parc > 2) ? string_or_empty(parv[2]) : "";

  /*
   * Who should receive this message ? Will we do something with it ?
   * Note that we use findUser functions, so the target can't be neither
   * a server, nor a channel (?) nor a list of targets (?) .. u2.10
   * should never generate numeric replies to non-users anyway
   * Ahem... it can be a channel actually, csc bots use it :\ --Nem
   */
  if (IsChanPrefix(*name))
  {
    const struct Channel *const channel = channel_find(name);
    if (channel == NULL)
      return;

    sendto_channel_butone(source, source, channel, 0, "%u %s %s", numeric, channel->name, text);
  }
  else
  {
    struct Client *const target = client_find_user(source, name);
    if (target == NULL || target->nexthop == source->nexthop)
      return;

    /* Fake it for server hiding, if it's our client */
    const bool hide_source =
      client_is_local(target) &&
      !client_is_oper(target) &&
      (ConfigServerHide.hide_servers || client_is_hidden(source));
    sendto_one_numeric(target, hide_source ? &me : source, numeric | SND_EXPLICIT, "%s", text);
  }
}

static void
_parse_handle_command(struct Command *command, struct Client *source, unsigned int parc, char *parv[])
{
  assert(command);
  assert(command->name);
  assert(source);
  assert(source->nexthop);
  assert(source->nexthop->command_handler < COMMAND_HANDLER_TYPE_COUNT);
  assert(parv);
  assert(parc > 0);
  assert(parc <= PARSE_MAX_PARAMETERS + 1);
  assert(parv[0]);
  assert(parv[parc] == NULL);

  ++command->count;
  if (client_is_server(source->nexthop))
    ++command->rcount;

  const struct CommandHandler *const handler = &command->handlers[source->nexthop->command_handler];
  assert(handler->handler);
  assert(handler->args_min <= PARSE_MAX_PARAMETERS + 1);
  assert(handler->args_max == 0 || handler->args_max <= PARSE_MAX_PARAMETERS);

  if (handler->end_grace_period && client_is_local_user(source))
    client_input_flood_endgrace(source);

  if (handler->args_min &&
      ((parc < handler->args_min) ||
       (handler->empty_last_arg != true && string_is_empty(parv[handler->args_min - 1]))))
  {
    if (client_is_server(source->nexthop))
    {
      client_format_name_buffer_t link_name_buffer;
      log_write(LOG_TYPE_DEBUG, "Invalid arguments for command from server: %s (expected at least %u, got %u) via %s",
                command->name, handler->args_min, parc,
                client_format_name(source->nexthop, CLIENT_FORMAT_NAME_LOG, &link_name_buffer));

      client_exit_fmt(source->nexthop, "Invalid arguments for command: %s (expected at least %u, got %u)",
                      command->name, handler->args_min, parc);
    }
    else
      sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, command->name);

    return;
  }

  handler->handler(source, parc, parv);
}

static bool
_parse_extract_and_validate_prefix(parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->buffer_cursor);
  assert(ctx->buffer_cursor <= ctx->buffer_end);
  assert(ctx->client);

  char *ch = ctx->buffer_cursor;
  while (*ch == ' ')
    ++ch;
  assert(ch <= ctx->buffer_end);

  if (*ch != ':')
  {
    ctx->buffer_cursor = ch;
    return true;
  }

  /*
   * Copy the prefix to 'prefix' assuming it terminates
   * with SPACE (or NULL, which is an error, though).
   */
  char *const prefix = ++ch;
  assert(prefix <= ctx->buffer_end);

  const size_t prefix_len = strcspn(prefix, " ");
  char *prefix_end = prefix + prefix_len;
  assert(prefix_end <= ctx->buffer_end);

  if (*prefix_end == ' ')
    *prefix_end++ = '\0';
  ch = prefix_end;

  /*
   * Prefixes from local clients are parsed but not trusted. Only server links
   * may identify a different logical source.
   */
  if (*prefix && client_is_server(ctx->client))
  {
    struct Client *const source = client_find_entity(ctx->client, prefix);

    /*
     * Server prefixes must resolve to a known entity. Unknown prefixes are
     * handled conservatively because they indicate stale state or bad routing.
     */
    if (source == NULL)
    {
      ++ServerStats.is_unpf;
      _parse_handle_unknown_prefix(ctx->client, prefix);
      return false;
    }

    assert(source->nexthop);

    /*
     * A prefixed source must be routed through the link that delivered the
     * message. Anything else is a fake-direction violation and is dropped.
     */
    if (source->nexthop != ctx->client)
    {
      ++ServerStats.is_wrdi;

      client_format_name_buffer_t client_name_buffer;
      log_write(LOG_TYPE_DEBUG, "Fake direction: dropped message from %s[%s] via %s",
                source->name, source->nexthop->name,
                client_format_name(ctx->client, CLIENT_FORMAT_NAME_LOG, &client_name_buffer));
      return false;
    }

    ctx->source = source;
  }

  while (*ch == ' ')
    ++ch;
  assert(ch <= ctx->buffer_end);

  ctx->buffer_cursor = ch;
  return true;
}

static bool
_parse_token_is_numeric(const char *token, size_t token_len)
{
  assert(token);
  return token_len == 3 && IsDigit(token[0]) && IsDigit(token[1]) && IsDigit(token[2]);
}

static void
_parse_handle_unknown_command_token(parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->command_token);
  assert(ctx->source);

  /*
   * Report unknown commands only to user sources. Server traffic and
   * incomplete registration states must not receive protocol replies here;
   * doing so could create noisy feedback loops.
   */
  if (client_is_local_user(ctx->source))
  {
    /*
     * Bound the reflected token so an oversized unknown command cannot bloat
     * the ERR_UNKNOWNCOMMAND reply.
     */
    char reply_token[COMMAND_NAME_BUFFER_SIZE];
    strlcpy(reply_token, ctx->command_token, sizeof(reply_token));

    sendto_one_numeric(ctx->source, &me, ERR_UNKNOWNCOMMAND, reply_token);
  }
  else if (client_is_server(ctx->source))
  {
    client_format_name_buffer_t client_name_buffer;
    log_write(LOG_TYPE_DEBUG, "Unknown command from server: %s via %s",
              ctx->command_token, client_format_name(ctx->client, CLIENT_FORMAT_NAME_LOG, &client_name_buffer));
  }

  ++ServerStats.is_unco;
}

static bool
_parse_identify_numeric(parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->command_token);

  const char *const token = ctx->command_token;
  ctx->numeric = (token[0] - '0') * 100 +
                 (token[1] - '0') * 10 +
                 (token[2] - '0');

  if (ctx->numeric < 1 || ctx->numeric > 999)
  {
    client_format_name_buffer_t client_name_buffer;
    log_write(LOG_TYPE_DEBUG, "Unknown numeric from server: %u via %s",
              ctx->numeric, client_format_name(ctx->client, CLIENT_FORMAT_NAME_LOG, &client_name_buffer));
    return false;
  }

  ++ServerStats.is_num;
  return true;
}

static bool
_parse_identify_command(parse_context_t *ctx, size_t token_len)
{
  assert(ctx);
  assert(ctx->command_token);
  assert(ctx->command_token[0]);
  assert(token_len > 0);

  ctx->command = command_find(ctx->command_token);
  if (ctx->command == NULL)
  {
    _parse_handle_unknown_command_token(ctx);
    return false;
  }

  if (ctx->buffer_cursor < ctx->buffer_end)
  {
    /*
     * buffer_cursor points after the first command/parameter separator. That
     * separator was replaced with NUL while extracting the command token, so
     * add it back to account for the full command payload.
     */
    ctx->command->bytes += token_len + 1 + (size_t)(ctx->buffer_end - ctx->buffer_cursor);
  }
  else
    ctx->command->bytes += token_len;

  return true;
}

static bool
_parse_identify_command_token(parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->buffer_cursor);
  assert(ctx->buffer_cursor <= ctx->buffer_end);

  if (*ctx->buffer_cursor == '\0')
  {
    ++ServerStats.is_empt;
    return false;
  }

  char *const token = ctx->buffer_cursor;
  const size_t token_len = strcspn(token, " ");
  char *token_end = token + token_len;

  assert(token_end <= ctx->buffer_end);

  if (token_len == 0)
  {
    ++ServerStats.is_empt;
    return false;
  }

  if (*token_end == ' ')
    *token_end++ = '\0';

  ctx->command_token = token;
  ctx->buffer_cursor = token_end;

  if (_parse_token_is_numeric(ctx->command_token, token_len))
    return _parse_identify_numeric(ctx);

  return _parse_identify_command(ctx, token_len);
}

static unsigned int
_parse_get_parameter_count(const parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->parc > 0);
  return ctx->parc - 1;
}

static unsigned int
_parse_get_parameter_limit(const parse_context_t *ctx)
{
  assert(ctx);

  if (ctx->numeric)
    return 2;  /* Target, and the rest of it. */

  assert(ctx->command);
  assert(ctx->source);
  assert(ctx->source->nexthop);
  assert(ctx->source->nexthop->command_handler < COMMAND_HANDLER_TYPE_COUNT);

  const struct CommandHandler *const handler = &ctx->command->handlers[ctx->source->nexthop->command_handler];
  if (handler->args_max == 0)
    return PARSE_MAX_PARAMETERS;

  assert(handler->args_max <= PARSE_MAX_PARAMETERS);

  if (handler->args_max > PARSE_MAX_PARAMETERS)
    return PARSE_MAX_PARAMETERS;

  return handler->args_max;
}

static void
_parse_assert_parameters_valid(const parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->parc > 0);
  assert(ctx->parc < IO_ARRAY_LENGTH(ctx->parv));

  for (unsigned int i = 0; i < ctx->parc; ++i)
    assert(ctx->parv[i]);

  for (unsigned int i = ctx->parc; i < IO_ARRAY_LENGTH(ctx->parv); ++i)
    assert(ctx->parv[i] == NULL);
}

static void
_parse_split_parameters(parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->command_token);
  assert(ctx->buffer_cursor);
  assert(ctx->buffer_cursor <= ctx->buffer_end);

  const unsigned int parameter_limit = _parse_get_parameter_limit(ctx);
  assert(parameter_limit <= PARSE_MAX_PARAMETERS);

  ctx->parv[ctx->parc++] = ctx->command_token;

  if (ctx->command && ctx->command->extra)
  {
    assert(_parse_get_parameter_count(ctx) < parameter_limit);

    ctx->parv[ctx->parc++] = ctx->command->extra;
  }

  char *s = ctx->buffer_cursor;
  while (*s == ' ')
    *s++ = '\0';
  assert(s <= ctx->buffer_end);

  while (*s && _parse_get_parameter_count(ctx) < parameter_limit)
  {
    assert(s <= ctx->buffer_end);
    assert(ctx->parc < IO_ARRAY_LENGTH(ctx->parv) - 1);

    if (*s == ':')
    {
      /* The rest is single parameter--can include blanks also. */
      ctx->parv[ctx->parc++] = s + (ctx->numeric == 0);  /* Keep the colon if it's a numeric */
      break;
    }

    ctx->parv[ctx->parc++] = s;

    /*
     * If this is the final permitted parameter slot, leave the rest of
     * the message attached to this argument.
     */
    if (_parse_get_parameter_count(ctx) >= parameter_limit)
      break;

    while (*s && *s != ' ')
      ++s;
    assert(s <= ctx->buffer_end);

    while (*s == ' ')
      *s++ = '\0';
    assert(s <= ctx->buffer_end);
  }

  _parse_assert_parameters_valid(ctx);
}

static void
_parse_dispatch_handler(parse_context_t *ctx)
{
  assert(ctx);
  assert(ctx->source);
  assert(ctx->source->nexthop);
  assert(ctx->command || ctx->numeric);

  _parse_assert_parameters_valid(ctx);

  if (ctx->command)
    _parse_handle_command(ctx->command, ctx->source, ctx->parc, ctx->parv);
  else
    _parse_handle_numeric(ctx->numeric, ctx->source, ctx->parc, ctx->parv);
}

void
parse_message(struct Client *client, char *buffer, const char *buffer_end)
{
  assert(buffer && buffer_end);
  assert(buffer_end >= buffer);
  assert((buffer_end - buffer) < IRCD_BUFSIZE);
  assert(*buffer_end == '\0');
  assert(client && client_is_local(client));
  assert(client->nexthop);
  assert(client->command_handler < COMMAND_HANDLER_TYPE_COUNT);
  assert(client->connection->fde);
  assert(client->connection->fde->flags.open);
  assert(!client_is_dead(client));

  parse_context_t ctx =
  {
    .client = client,
    .source = client,
    .buffer = buffer,
    .buffer_end = buffer_end,
    .buffer_cursor = buffer
  };

  if (!_parse_extract_and_validate_prefix(&ctx))
    return;

  if (!_parse_identify_command_token(&ctx))
    return;

  _parse_split_parameters(&ctx);

  _parse_dispatch_handler(&ctx);
}
