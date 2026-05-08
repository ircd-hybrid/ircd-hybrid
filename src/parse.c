/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

/*! \file parse.c
 * \brief The message parser.
 */

#include <assert.h>

#include "io_string.h"
#include "log.h"
#include "misc.h"

#include "channel.h"
#include "client.h"
#include "client_id.h"
#include "client_input.h"
#include "conf.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "packet.h"
#include "parse.h"
#include "send.h"
#include "user_mode.h"

typedef struct parser_context
{
  char *const buffer;
  const char *const buffer_end;
  char *buffer_cursor;
  struct Client *const client;
  struct Client *source;
  struct Command *command;
  unsigned int numeric;
  char *command_numeric_str;
  unsigned int parc_max;
  unsigned int parc;
  char *parv[PARSE_MAX_PARAMETERS + 2];  /* <command> + <parameters> + NULL */
} parse_context_t;

static bool
_parse_uid_belongs_to_source(const struct Client *source_server, const char *uid)
{
  assert(source_server);
  assert(IsServer(source_server));
  assert(client_id_is_valid_uid(uid));

  char sid[CLIENT_ID_SID_LENGTH + 1];
  strlcpy(sid, uid, sizeof(sid));

  /*
   * A UID is only eligible for unknown-client cleanup if its server SID
   * resolves to a server that is actually routed through the sending link.
   */
  const struct Client *server = hash_find_id(sid);
  return server && server->nexthop == source_server;
}

static void
_parse_handle_unknown_prefix(struct Client *client, const char *prefix, const char *buffer)
{
  assert(client);
  assert(IsServer(client));
  assert(!string_is_empty(prefix));
  assert(buffer);

  /*
   * Unknown prefixes are classified as follows:
   *   - valid SID or dotted server name: server prefix
   *   - valid UID from this server path:  client ID
   *   - digit-starting but otherwise invalid: invalid numeric prefix
   *   - everything else: nickname
   */
  const char *const source_name = client_get_name(client, SHOW_IP);

  if (client_id_is_valid_sid(prefix) || strchr(prefix, '.'))
  {
    sendto_one(client, ":%s SQUIT %s :Unknown server prefix",
               me.id, prefix);
    log_write(LOG_TYPE_DEBUG, "Received message with unknown server prefix '%s' from %s",
              prefix, source_name);
    return;
  }

  if (client_id_is_valid_uid(prefix))
  {
    if (_parse_uid_belongs_to_source(client, prefix))
    {
      sendto_one(client, ":%s KILL %s :%s (Unknown client ID)",
                 me.id, prefix, me.name);
      log_write(LOG_TYPE_DEBUG, "Received message with unknown client ID '%s' from %s",
                prefix, source_name);
    }
    else
      log_write(LOG_TYPE_DEBUG, "Received message with invalid numeric prefix '%s' from %s",
                prefix, source_name);

    return;
  }

  if (IsDigit(prefix[0]))
  {
    log_write(LOG_TYPE_DEBUG, "Received message with invalid numeric prefix '%s' from %s",
              prefix, source_name);
    return;
  }

  sendto_one(client, ":%s KILL %s :%s (Unknown nickname)",
             me.id, prefix, me.name);
  log_write(LOG_TYPE_DEBUG, "Received message with unknown nickname '%s' from %s",
            prefix, source_name);
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
  assert(parc <= PARSE_MAX_PARAMETERS + 2);
  assert(parv);
  assert(parv[0]);
  assert(parv[1]);
  assert(parv[2]);

  /*
   * Avoid trash, we need it to come from a server and have a target
   */
  if (parc < 2 || !IsServer(source))
    return;

  /*
   * Remap low number numerics, not that I understand WHY.. --Nemesi
   */
  /*
   * Numerics below 100 talk about the current 'connection', you're not
   * connected to a remote server so it doesn't make sense to send them
   * remotely - but the information they contain may be useful, so we
   * remap them up. Weird, but true.  -- Isomer
   */
  if (numeric < 100)
    numeric += 100;

  const char *name = parv[1];
  const char *text = string_or_empty(parv[2]);

  /*
   * Who should receive this message ? Will we do something with it ?
   * Note that we use findUser functions, so the target can't be neither
   * a server, nor a channel (?) nor a list of targets (?) .. u2.10
   * should never generate numeric replies to non-users anyway
   * Ahem... it can be a channel actually, csc bots use it :\ --Nem
   */
  if (IsChanPrefix(*name))
  {
    const struct Channel *channel = hash_find_channel(name);
    if (channel == NULL)
      return;

    sendto_channel_butone(source, source, channel, 0, "%u %s %s", numeric, channel->name, text);
  }
  else
  {
    struct Client *target = find_person(source, name);
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
  assert(parc <= PARSE_MAX_PARAMETERS + 2);

  ++command->count;
  if (IsServer(source->nexthop))
    ++command->rcount;

  const struct CommandHandler *const handler = &command->handlers[source->nexthop->handler];
  if (handler->end_grace_period && MyClient(source))
    client_input_flood_endgrace(source);

  if (handler->args_min &&
      ((parc < handler->args_min) ||
       (handler->empty_last_arg != true && string_is_empty(parv[handler->args_min - 1]))))
  {
    if (IsServer(source->nexthop))
    {
      log_write(LOG_TYPE_DEBUG, "Invalid arguments for command from server: %s (expected at least %u, got %u) via %s",
                command->name, handler->args_min, parc, client_get_name(source->nexthop, SHOW_IP));
      client_exit_fmt(source->nexthop, "Invalid arguments for command: %s (expected at least %u, got %u)",
                      command->name, handler->args_min, parc);
    }
    else
      sendto_one_numeric(source, &me, ERR_NEEDMOREPARAMS, command->name);
  }
  else
    handler->handler(source, parc, parv);
}

static bool
_parse_extract_and_validate_prefix(parse_context_t *ctx)
{
  char *ch = ctx->buffer_cursor;

  /* Skip leading spaces. */
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

  size_t prefix_len = strcspn(prefix, " ");
  char *prefix_end = prefix + prefix_len;
  assert(prefix_end <= ctx->buffer_end);

  if (*prefix_end == ' ')
    *prefix_end++ = '\0';
  ch = prefix_end;

  if (*prefix && IsServer(ctx->client))
  {
    struct Client *from = hash_find_id(prefix);
    if (from == NULL)
      from = hash_find_client(prefix);

    /*
     * Hmm! If the client corresponding to the prefix is not found--what is
     * the correct action??? Now, I will ignore the message (old IRC just
     * let it through as if the prefix just wasn't there...) --msa
     */
    if (from == NULL)
    {
      ++ServerStats.is_unpf;
      _parse_handle_unknown_prefix(ctx->client, prefix, ctx->buffer);
      return false;
    }

    if (from->nexthop != ctx->client)
    {
      ++ServerStats.is_wrdi;
      log_write(LOG_TYPE_DEBUG, "Fake direction: dropped message from %s[%s] via %s",
                from->name, from->nexthop->name, client_get_name(ctx->client, SHOW_IP));
      return false;
    }

    ctx->source = from;
  }

  while (*ch == ' ')
    ++ch;
  assert(ch <= ctx->buffer_end);

  ctx->buffer_cursor = ch;
  return true;
}

static bool
_parse_is_numeric(const char *token)
{
  return IsDigit(token[0]) && IsDigit(token[1]) && IsDigit(token[2]) && token[3] == ' ';
}

static bool
_parse_identify_command(parse_context_t *ctx)
{
  char *const token = ctx->buffer_cursor;
  ctx->command_numeric_str = token;

  size_t token_len = strcspn(token, " ");
  char *token_end = token + token_len;

  if (*token_end == ' ')
    *token_end++ = '\0';
  ctx->buffer_cursor = token_end;

  ctx->command = command_find(ctx->command_numeric_str);
  if (ctx->command == NULL)
  {
    /*
     * Note: Give error message *only* to recognized
     * persons. It's a nightmare situation to have
     * two programs sending "Unknown command"'s or
     * equivalent to each other at full blast....
     * If it has got to person state, it at least
     * seems to be well behaving. Perhaps this message
     * should never be generated, though...  --msa
     */
    if (IsClient(ctx->source))
      sendto_one_numeric(ctx->source, &me, ERR_UNKNOWNCOMMAND, ctx->command_numeric_str);
    else if (IsServer(ctx->source))
      log_write(LOG_TYPE_DEBUG, "Unknown command from server: %s via %s",
                ctx->command_numeric_str, client_get_name(ctx->client, SHOW_IP));

    ++ServerStats.is_unco;
    return false;
  }

  size_t bytes = (ctx->buffer_cursor < ctx->buffer_end) ? (ctx->buffer_end - ctx->buffer_cursor) : 0;
  ctx->command->bytes += bytes;
  ctx->parc_max = ctx->command->handlers[ctx->source->nexthop->handler].args_max;

  return true;
}

static bool
_parse_identify_numeric(parse_context_t *ctx)
{
  char *const token = ctx->buffer_cursor;
  ctx->command_numeric_str = token;

  ctx->numeric = (token[0] - '0') * 100 +
                 (token[1] - '0') * 10 +
                 (token[2] - '0');
  if (ctx->numeric < 1 || ctx->numeric > 999)
  {
    log_write(LOG_TYPE_DEBUG, "Unknown numeric from server: %u via %s",
              ctx->numeric, client_get_name(ctx->client, SHOW_IP));
    return false;
  }

  ctx->parc_max = 2;  /* Destination, and the rest of it */

  char *token_end = token + 3;  /* I know this is ' ' from parse_is_numeric() */
  *token_end++ = '\0';  /* Blow away the ' '. */
  ctx->buffer_cursor = token_end;

  ++ServerStats.is_num;
  return true;
}

static bool
_parse_identify_command_or_numeric(parse_context_t *ctx)
{
  if (*ctx->buffer_cursor == '\0')
  {
    ++ServerStats.is_empt;
    return false;
  }

  if (_parse_is_numeric(ctx->buffer_cursor))
    return _parse_identify_numeric(ctx);

  return _parse_identify_command(ctx);
}

static void
_parse_split_parameters(parse_context_t *ctx)
{
  char *s = ctx->buffer_cursor;
  if (*s == '\0')
    return;

  ctx->parv[ctx->parc] = ctx->command_numeric_str;

  if (ctx->command && ctx->command->extra)
    ctx->parv[++ctx->parc] = ctx->command->extra;

  unsigned int parc_max = ctx->parc_max;
  if (parc_max == 0 || parc_max > IO_ARRAY_LENGTH(ctx->parv))
    parc_max = IO_ARRAY_LENGTH(ctx->parv);

  /*
   * Must the following loop really be so devious? On surface it
   * splits the message to parameters from blank spaces. But, if
   * paramcount has been reached, the rest of the message goes into
   * this last parameter (about same effect as ":" has...) --msa
   */
  while (ctx->parc < IO_ARRAY_LENGTH(ctx->parv))
  {
    while (*s == ' ')
      *s++ = '\0';
    assert(s <= ctx->buffer_end);

    if (*s == '\0')
      break;

    assert(ctx->parc + 1 < IO_ARRAY_LENGTH(ctx->parv));
    if (*s == ':')
    {
      /* The rest is single parameter--can include blanks also. */
      ctx->parv[++ctx->parc] = s + (ctx->numeric == 0);  /* Keep the colon if it's a numeric */
      break;
    }

    ctx->parv[++ctx->parc] = s;

    if (ctx->parc >= parc_max)
      break;

    while (*s && *s != ' ')
      ++s;
    assert(s <= ctx->buffer_end);
  }

  assert(ctx->parc < IO_ARRAY_LENGTH(ctx->parv));
  ctx->parv[++ctx->parc] = NULL;
}

static void
_parse_dispatch_handler(parse_context_t *ctx)
{
  assert(ctx->command || ctx->numeric);

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
  assert(client->connection->fd);
  assert(client->connection->fd->flags.open);
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

  if (!_parse_identify_command_or_numeric(&ctx))
    return;

  _parse_split_parameters(&ctx);

  _parse_dispatch_handler(&ctx);
}

/* m_not_oper()
 * inputs	-
 * output	-
 * side effects	- just returns a nastyogram to given user
 */
void
m_not_oper(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, ERR_NOPRIVILEGES);
}

void
m_unregistered(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, ERR_NOTREGISTERED);
}

void
m_registered(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, ERR_ALREADYREGISTRED);
}

void
m_ignore(struct Client *source, int parc, char *parv[])
{
  return;
}
