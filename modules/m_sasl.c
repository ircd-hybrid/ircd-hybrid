/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "event.h"
#include "io.h"
#include "io_hash.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "module.h"

#include "cap.h"
#include "client.h"
#include "client_find.h"
#include "client_id.h"
#include "conf.h"
#include "hash.h"
#include "ircd.h"
#include "ircd_hook.h"
#include "ircd_module.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"
#include "user.h"

enum
{
  SASL_CHUNK_LENGTH_MAX = 400,
  SASL_MESSAGE_LENGTH_MAX = 16384,
  SASL_MECHANISM_LENGTH_MAX = 20,
  SASL_MECHANISM_LIST_LENGTH_MAX = IRCD_BUFSIZE - 2,
  SASL_ATTEMPTS_MAX = 10,
  SASL_ATTEMPT_WINDOW_SEC = 60,
  SASL_TIMEOUT_SEC = 60,
  SASL_SESSION_BUCKET_COUNT_INITIAL = 256,
  SASL_SESSION_LOAD_FACTOR_MAX = 4
};

enum sasl_state
{
  SASL_STATE_IDLE,
  SASL_STATE_WAIT_SERVER,
  SASL_STATE_WAIT_CLIENT,
  SASL_STATE_COMPLETE
};

enum sasl_chunk_result
{
  SASL_CHUNK_INVALID,
  SASL_CHUNK_INCOMPLETE,
  SASL_CHUNK_COMPLETE
};

struct SaslSession
{
  list_node_t hash_node;
  list_node_t pending_node;
  struct Client *client;
  enum sasl_state state;
  unsigned int attempt_count;
  uintmax_t attempt_window_start_time;
  uintmax_t attempt_start_time;
  size_t message_length;
  bool message_padded;
  char agent_uid[IDLEN + 1];
  char pending_account[ACCOUNTLEN + 1];
};

static list_t *session_table;
static size_t session_bucket_count;
static size_t session_count;
static list_t pending_sessions;
static struct Client *sasl_server;
static struct Cap *sasl_capability;
static const struct CapConfig sasl_capability_config =
{
  .name = "sasl",
  .flag = CAP_SASL,
  .available = false
};

static char sasl_mechanisms[SASL_MECHANISM_LIST_LENGTH_MAX + 1];
static event_handle_t session_expiry_event;

static list_t *
sasl_session_get_bucket(const struct Client *client)
{
  assert(session_bucket_count);
  return &session_table[io_hash_pointer(client) & (session_bucket_count - 1)];
}

static void
sasl_session_table_grow(void)
{
  if (session_bucket_count && session_count / SASL_SESSION_LOAD_FACTOR_MAX < session_bucket_count)
    return;
  if (session_bucket_count > SIZE_MAX / 2 / sizeof(*session_table))
    return;

  const size_t previous_bucket_count = session_bucket_count;
  list_t *const previous_table = session_table;
  session_bucket_count = previous_bucket_count ? previous_bucket_count * 2 : SASL_SESSION_BUCKET_COUNT_INITIAL;
  session_table = io_calloc(session_bucket_count * sizeof(*session_table));

  for (size_t i = 0; i < previous_bucket_count; ++i)
  {
    list_node_t *node, *next;
    LIST_FOREACH_SAFE(node, next, previous_table[i].head)
    {
      struct SaslSession *const session = node->data;
      list_remove(node, &previous_table[i]);
      list_add(session, node, sasl_session_get_bucket(session->client));
    }
  }

  io_free(previous_table);
}

static struct SaslSession *
sasl_session_find(const struct Client *client)
{
  if (session_count == 0)
    return NULL;

  list_node_t *node;
  LIST_FOREACH(node, sasl_session_get_bucket(client)->head)
  {
    struct SaslSession *const session = node->data;
    if (session->client == client)
      return session;
  }

  return NULL;
}

static struct SaslSession *
sasl_session_create(struct Client *client)
{
  assert(sasl_session_find(client) == NULL);

  sasl_session_table_grow();

  struct SaslSession *const session = io_calloc(sizeof(*session));
  session->client = client;
  list_add(session, &session->hash_node, sasl_session_get_bucket(client));

  ++session_count;
  return session;
}

static bool
sasl_session_is_pending(const struct SaslSession *session)
{
  return session->state == SASL_STATE_WAIT_SERVER || session->state == SASL_STATE_WAIT_CLIENT;
}

static bool
sasl_server_is_reachable(const struct Client *server)
{
  if (server == NULL || server == &me || !client_is_server(server) ||
      !capab_has_flag(server->nexthop, CAPAB_ENCAP))
    return false;

  for (const struct Client *route = server; route != &me; route = route->uplink)
    if (client_is_dead(route))
      return false;

  return true;
}

static bool
sasl_server_is_eligible(const struct Client *server)
{
  return !string_is_empty(ConfigGeneral.sasl_service) &&
         sasl_server_is_reachable(server) &&
         client_is_service(server) &&
         io_strcasecmp(server->name, ConfigGeneral.sasl_service) == 0;
}

static bool
sasl_mechanism_is_valid(const char *name, size_t length)
{
  if (length == 0 || length > SASL_MECHANISM_LENGTH_MAX)
    return false;

  for (size_t i = 0; i < length; ++i)
  {
    if (!io_ascii_is_upper(name[i]) &&
        !io_ascii_is_digit(name[i]) && name[i] != '-' && name[i] != '_')
      return false;
  }

  return true;
}

static bool
sasl_mechanism_list_is_valid(const char *mechanisms)
{
  if (strlen(mechanisms) > SASL_MECHANISM_LIST_LENGTH_MAX)
    return false;

  for (const char *name = mechanisms; ; )
  {
    const size_t length = strcspn(name, ",");
    if (!sasl_mechanism_is_valid(name, length))
      return false;

    if (name[length] == '\0')
      return true;

    name += length + 1;
  }
}

static bool
sasl_mechanism_list_contains(const char *mechanisms, const char *mechanism)
{
  const size_t length = strlen(mechanism);

  for (const char *name = mechanisms; ; )
  {
    const size_t token_length = strcspn(name, ",");
    if (length == token_length && memcmp(name, mechanism, length) == 0)
      return true;

    if (name[token_length] == '\0')
      return false;

    name += token_length + 1;
  }
}

static void
sasl_send_mechanisms(struct Client *client, const char *mechanisms)
{
  const char *const prefix = client_get_id_or_name(&me, client);
  const char *destination = client_get_id_or_name(client, client);

  if (string_is_empty(destination))
    destination = "*";

  const size_t overhead = 1 + strlen(prefix) + sizeof(" 908 ") - 1 + strlen(destination) + 1;
  const int length = snprintf(NULL, 0, numeric_form(RPL_SASLMECHS), mechanisms);

  /* Numeric 908 is optional; send it only when the complete list fits. */
  if (length >= 0 && overhead <= IRCD_BUFSIZE - 2 && (size_t)length <= IRCD_BUFSIZE - 2 - overhead)
    sendto_one_numeric(client, &me, RPL_SASLMECHS, mechanisms);
}

static void
sasl_send_abort(const struct SaslSession *session)
{
  if (sasl_server_is_reachable(sasl_server))
    sendto_one(sasl_server, ":%s ENCAP %s SASL %s %s D A",
               me.id, sasl_server->name, session->client->id,
               string_is_empty(session->agent_uid) ? "*" : session->agent_uid);
}

static void
sasl_session_release_uid(struct SaslSession *session)
{
  struct Client *const client = session->client;
  assert(client_is_unknown(client));
  assert(client_id_has_valid_uid(client));

  hash_del_id(client);
  client->id[0] = '\0';
}

static void
sasl_session_reset(struct SaslSession *session)
{
  if (sasl_session_is_pending(session))
    list_remove(&session->pending_node, &pending_sessions);

  session->state = SASL_STATE_IDLE;
  session->agent_uid[0] = '\0';
  session->pending_account[0] = '\0';
  session->message_length = 0;
  session->message_padded = false;
}

static void
sasl_session_fail(struct SaslSession *session, enum irc_numerics numeric)
{
  assert(sasl_session_is_pending(session));

  /* Registered clients retain their network identity across every attempt. */
  if (client_is_unknown(session->client))
    sasl_session_release_uid(session);

  sasl_session_reset(session);

  if (!client_is_dead(session->client))
    sendto_one_numeric(session->client, &me, numeric);
}

static void
sasl_session_abort(struct SaslSession *session, enum irc_numerics numeric)
{
  assert(sasl_session_is_pending(session));

  sasl_send_abort(session);
  sasl_session_fail(session, numeric);
}

static void
sasl_session_succeed(struct SaslSession *session)
{
  struct Client *const client = session->client;

  if (!string_is_empty(session->pending_account))
  {
    const bool changed = strcmp(client->account, session->pending_account) != 0;
    if (!user_set_account(client, session->pending_account))
    {
      sasl_session_abort(session, ERR_SASLFAIL);
      return;
    }

    if (changed && client_is_user(client))
      sendto_servers(NULL, 0, 0, ":%s SVSACCOUNT %s 0 %s", me.id, client->id, client->account);
  }

  sasl_session_reset(session);
  session->state = SASL_STATE_COMPLETE;
  sendto_one_numeric(client, &me, RPL_SASLSUCCESS);
}

static void
sasl_session_destroy(struct SaslSession *session)
{
  /* Services may retain a successful login until the UID is introduced. */
  if (sasl_session_is_pending(session) ||
      (session->state == SASL_STATE_COMPLETE && client_is_unknown(session->client)))
  {
    sasl_send_abort(session);
    if (client_is_unknown(session->client))
      sasl_session_release_uid(session);
  }

  sasl_session_reset(session);
  list_remove(&session->hash_node, sasl_session_get_bucket(session->client));
  --session_count;

  io_free(session);
}

static void
sasl_server_update(struct Client *server, const char *mechanisms)
{
  assert((server == NULL) == (mechanisms == NULL));
  assert(server == NULL || sasl_server_is_eligible(server));
  assert(mechanisms == NULL || sasl_mechanism_list_is_valid(mechanisms));

  /* Finish attempts against the old backend before changing availability. */
  if (sasl_server != server)
  {
    struct SaslSession *session;
    while ((session = list_peek_head(&pending_sessions)))
      sasl_session_abort(session, ERR_SASLFAIL);
  }

  sasl_server = server;
  if (mechanisms)
    strlcpy(sasl_mechanisms, mechanisms, sizeof(sasl_mechanisms));
  else
    sasl_mechanisms[0] = '\0';

  const cap_result_t result = cap_update(sasl_capability, server ? sasl_mechanisms : NULL, server != NULL);
  assert(result == CAP_SUCCESS);
  (void)result;
}

static void
sasl_server_reset(void)
{
  sasl_server_update(NULL, NULL);
}

static void
sasl_server_refresh(void)
{
  if (sasl_server && !sasl_server_is_eligible(sasl_server))
    sasl_server_reset();
}

/* Check the transport alphabet without decoding or retaining credentials. */
static bool
sasl_chunk_is_valid(const char *chunk, size_t length)
{
  if (length == 0 || length > SASL_CHUNK_LENGTH_MAX)
    return false;

  if (strcmp(chunk, "+") == 0)
    return true;

  if (length % 4)
    return false;

  size_t padding = 0;
  for (size_t i = 0; i < length; ++i)
  {
    if (chunk[i] == '=')
    {
      if (++padding > 2)
        return false;
    }
    else if (padding || (!io_ascii_is_alnum(chunk[i]) && chunk[i] != '+' && chunk[i] != '/'))
      return false;
  }

  return true;
}

static enum sasl_chunk_result
sasl_session_accept_chunk(struct SaslSession *session, const char *chunk, size_t length)
{
  const bool empty = strcmp(chunk, "+") == 0;

  if (!sasl_chunk_is_valid(chunk, length) || (session->message_padded && !empty))
    return SASL_CHUNK_INVALID;

  if (!empty)
  {
    if (length > SASL_MESSAGE_LENGTH_MAX - session->message_length)
      return SASL_CHUNK_INVALID;

    session->message_length += length;
    session->message_padded = chunk[length - 1] == '=';
  }

  if (length == SASL_CHUNK_LENGTH_MAX)
    return SASL_CHUNK_INCOMPLETE;

  session->message_length = 0;
  session->message_padded = false;
  return SASL_CHUNK_COMPLETE;
}

static void
sasl_session_start(struct SaslSession *session, const char *mechanism)
{
  struct Client *const client = session->client;
  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);

  assert(!sasl_session_is_pending(session));

  if (session->attempt_count == 0 || now - session->attempt_window_start_time >= SASL_ATTEMPT_WINDOW_SEC)
  {
    session->attempt_window_start_time = now;
    session->attempt_count = 0;
  }

  if (session->attempt_count >= SASL_ATTEMPTS_MAX)
  {
    sendto_one_numeric(client, &me, ERR_SASLFAIL);
    client_exit(client, "Too many SASL authentication attempts");
    return;
  }

  if (client_is_unknown(client))
  {
    if (!string_is_empty(client->id))
    {
      assert(session->state == SASL_STATE_COMPLETE);
      sasl_send_abort(session);
      sasl_session_release_uid(session);
    }

    /* Unannounced clients can isolate retries with a fresh UID. */
    if (!client_id_allocate_uid(client))
    {
      sendto_one_numeric(client, &me, ERR_SASLFAIL);
      client_exit(client, "Local client ID generator exhausted");
      return;
    }

    hash_add_id(client);
  }

  assert(client_id_has_valid_uid(client));

  session->state = SASL_STATE_WAIT_SERVER;
  session->attempt_start_time = now;
  ++session->attempt_count;

  /* A fixed timeout keeps insertion order equal to deadline order. */
  list_add_tail(session, &session->pending_node, &pending_sessions);

  struct Client *const server = sasl_server;
  sendto_one(server, ":%s ENCAP %s SASL %s * H %s %s %c",
             me.id, server->name, client->id, client->host, client->sockhost,
             client_has_flag(client, FLAGS_TLS_ACTIVE) ? 'S' : 'P');

  if (strcmp(mechanism, "EXTERNAL") == 0)
    sendto_one(server, ":%s ENCAP %s SASL %s * S EXTERNAL %s",
               me.id, server->name, client->id, client->tls_certfp);
  else
    sendto_one(server, ":%s ENCAP %s SASL %s * S %s",
               me.id, server->name, client->id, mechanism);
}

static void
m_authenticate(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_cap(source, CAP_SASL) ||
      (!client_is_unknown(source) && !client_is_user(source)))
    return;

  struct SaslSession *session = sasl_session_find(source);
  if (session && session->state == SASL_STATE_COMPLETE && client_is_unknown(source) &&
      !client_has_flag(source, FLAGS_CAP302))
  {
    sendto_one_numeric(source, &me, ERR_SASLALREADY);
    return;
  }

  const char *const input = parv[1];
  const size_t length = strlen(input);

  if (strcmp(input, "*") == 0 || length > SASL_CHUNK_LENGTH_MAX)
  {
    const enum irc_numerics numeric = length > SASL_CHUNK_LENGTH_MAX ? ERR_SASLTOOLONG : ERR_SASLABORTED;
    if (session && sasl_session_is_pending(session))
      sasl_session_abort(session, numeric);
    else
      sendto_one_numeric(source, &me, numeric);
    return;
  }

  if (session && sasl_session_is_pending(session))
  {
    if (!sasl_server_is_eligible(sasl_server) || session->state != SASL_STATE_WAIT_CLIENT)
    {
      sasl_session_abort(session, ERR_SASLFAIL);
      return;
    }

    const enum sasl_chunk_result result = sasl_session_accept_chunk(session, input, length);
    if (result == SASL_CHUNK_INVALID)
    {
      sasl_session_abort(session, ERR_SASLFAIL);
      return;
    }

    if (result == SASL_CHUNK_COMPLETE)
      session->state = SASL_STATE_WAIT_SERVER;

    sendto_one(sasl_server, ":%s ENCAP %s SASL %s %s C %s",
               me.id, sasl_server->name, source->id, session->agent_uid, input);
    return;
  }

  sasl_server_refresh();

  if (sasl_server == NULL)
  {
    sendto_one_numeric(source, &me, ERR_SASLFAIL);
    return;
  }

  if (!sasl_mechanism_is_valid(input, length) ||
      !sasl_mechanism_list_contains(sasl_mechanisms, input))
  {
    sasl_send_mechanisms(source, sasl_mechanisms);
    sendto_one_numeric(source, &me, ERR_SASLFAIL);
    return;
  }

  if (strcmp(input, "EXTERNAL") == 0 && string_is_empty(source->tls_certfp))
  {
    sendto_one_numeric(source, &me, ERR_SASLFAIL);
    return;
  }

  if (session == NULL)
    session = sasl_session_create(source);

  sasl_session_start(session, input);
}

static struct SaslSession *
sasl_session_find_for_reply(const struct Client *source, const char *uid)
{
  if (source != sasl_server || !sasl_server_is_eligible(source))
    return NULL;

  struct Client *const client = client_find_entity_by_id(uid);
  if (client == NULL || !client_is_local(client) || client_is_dead(client) ||
      (!client_is_unknown(client) && !client_is_user(client)))
    return NULL;

  struct SaslSession *const session = sasl_session_find(client);
  if (session == NULL || !sasl_session_is_pending(session))
    return NULL;

  return session;
}

/* ENCAP <server> SASL <agent UID> <client UID> <C|D|M> <data> */
static void
me_sasl(struct Client *source, size_t parc, char *parv[])
{
  struct SaslSession *const session = sasl_session_find_for_reply(source, parv[2]);
  if (session == NULL)
    return;

  struct Client *const agent = client_find_user_by_uid(parv[1]);
  if (agent == NULL || agent->uplink != source || client_is_dead(agent) ||
      (!string_is_empty(session->agent_uid) && strcmp(session->agent_uid, agent->id)))
    return;

  if (parc != 5)
  {
    sasl_session_abort(session, ERR_SASLFAIL);
    return;
  }

  if (string_is_empty(session->agent_uid))
    strlcpy(session->agent_uid, agent->id, sizeof(session->agent_uid));

  if (strcmp(parv[3], "C") == 0)
  {
    if (session->state != SASL_STATE_WAIT_SERVER)
    {
      sasl_session_abort(session, ERR_SASLFAIL);
      return;
    }

    const enum sasl_chunk_result result = sasl_session_accept_chunk(session, parv[4], strlen(parv[4]));
    if (result == SASL_CHUNK_INVALID)
    {
      sasl_session_abort(session, ERR_SASLFAIL);
      return;
    }

    if (result == SASL_CHUNK_COMPLETE)
      session->state = SASL_STATE_WAIT_CLIENT;

    sendto_one(session->client, "AUTHENTICATE %s", parv[4]);
  }
  else if (strcmp(parv[3], "D") == 0)
  {
    if (strcmp(parv[4], "S") == 0)
    {
      if (session->state != SASL_STATE_WAIT_SERVER || session->message_length != 0)
        sasl_session_abort(session, ERR_SASLFAIL);
      else
        sasl_session_succeed(session);
    }
    else if (strcmp(parv[4], "F") == 0 || strcmp(parv[4], "A") == 0)
      sasl_session_fail(session, strcmp(parv[4], "A") == 0 ? ERR_SASLABORTED : ERR_SASLFAIL);
    else
      sasl_session_abort(session, ERR_SASLFAIL);
  }
  else if (strcmp(parv[3], "M") == 0 && sasl_mechanism_list_is_valid(parv[4]))
    sasl_send_mechanisms(session->client, parv[4]);
  else
    sasl_session_abort(session, ERR_SASLFAIL);
}

/* Stage the account until the corresponding SASL exchange succeeds. */
static void
me_svslogin(struct Client *source, size_t parc, char *parv[])
{
  struct SaslSession *const session = sasl_session_find_for_reply(source, parv[1]);
  if (session == NULL)
    return;

  if (parc != 6 || !user_account_is_valid(parv[5]))
  {
    sasl_session_abort(session, ERR_SASLFAIL);
    return;
  }

  strlcpy(session->pending_account, parv[5], sizeof(session->pending_account));
}

static void
me_mechlist(struct Client *source, size_t parc, char *parv[])
{
  if (parc != 2 || !sasl_server_is_eligible(source))
    return;

  if (string_is_empty(parv[1]) || strcmp(parv[1], "*") == 0)
  {
    if (source == sasl_server)
      sasl_server_reset();
  }
  else if (sasl_mechanism_list_is_valid(parv[1]))
    sasl_server_update(source, parv[1]);
}

static hook_flow_t
sasl_conf_read_hook(void *unused)
{
  sasl_server_refresh();
  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
sasl_cap_change_hook(void *ctx_)
{
  const ircd_hook_cap_change_ctx *const ctx = ctx_;

  if (ctx->removed & CAP_SASL)
  {
    struct SaslSession *const session = sasl_session_find(ctx->client);
    if (session && sasl_session_is_pending(session))
      sasl_session_abort(session, ERR_SASLABORTED);
  }

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
sasl_user_register_local_prepare_hook(void *ctx_)
{
  const ircd_hook_user_register_ctx *const ctx = ctx_;
  struct SaslSession *const session = sasl_session_find(ctx->client);

  /* Keep attempt accounting across the transition to registered state. */
  if (session && sasl_session_is_pending(session))
    sasl_session_abort(session, ERR_SASLABORTED);

  return HOOK_FLOW_CONTINUE;
}

static hook_flow_t
sasl_client_exit_hook(void *ctx_)
{
  const ircd_hook_client_exit_ctx *const ctx = ctx_;
  struct SaslSession *const session = sasl_session_find(ctx->client);

  if (session)
    sasl_session_destroy(session);

  if (client_is_server(ctx->client))
    sasl_server_refresh();

  if (sasl_server && client_is_user(ctx->client) && ctx->client->uplink == sasl_server)
  {
    list_node_t *node, *next;
    LIST_FOREACH_SAFE(node, next, pending_sessions.head)
    {
      struct SaslSession *const pending = node->data;
      if (strcmp(pending->agent_uid, ctx->client->id) == 0)
        sasl_session_abort(pending, ERR_SASLFAIL);
    }
  }

  return HOOK_FLOW_CONTINUE;
}

static void
sasl_expire_sessions(void *unused)
{
  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  struct SaslSession *session;

  while ((session = list_peek_head(&pending_sessions)))
  {
    if (now - session->attempt_start_time < SASL_TIMEOUT_SEC)
      break;
    sasl_session_abort(session, ERR_SASLFAIL);
  }
}

static struct Command command_table[] =
{
  {
    .name = "AUTHENTICATE",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = m_authenticate, .args_min = 2, .args_max = 1 },
    .handlers[COMMAND_HANDLER_USER] = { .handler = m_authenticate, .args_min = 2, .args_max = 1 },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = m_authenticate, .args_min = 2, .args_max = 1 }
  },
  {
    .name = "SASL",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = me_sasl, .args_min = 5 },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
  },
  {
    .name = "SVSLOGIN",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = me_svslogin, .args_min = 6 },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
  },
  {
    .name = "MECHLIST",
    .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
    .handlers[COMMAND_HANDLER_ENCAP] = { .handler = me_mechlist, .args_min = 2, .empty_last_arg = true },
    .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
  }
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  if (!ircd_module_register_cap(&sasl_capability_config, &sasl_capability, error_message, error_message_size))
    return false;

  if (!ircd_module_register_commands(command_table, IO_ARRAY_LENGTH(command_table), error_message, error_message_size))
  {
    cap_unregister(&sasl_capability);
    return false;
  }

  session_expiry_event =
    event_create(ircd_event_manager, "sasl_expire_sessions", sasl_expire_sessions, 1000, false, NULL, NULL);
  if (event_schedule(session_expiry_event) != EVENT_SUCCESS)
  {
    event_destroy(session_expiry_event);
    session_expiry_event = NULL;
    command_del_array(command_table, IO_ARRAY_LENGTH(command_table));
    cap_unregister(&sasl_capability);

    snprintf(error_message, error_message_size, "could not schedule SASL session expiry");
    return false;
  }

  hook_install(ircd_hook_cap_change, sasl_cap_change_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_conf_read, sasl_conf_read_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_user_register_local_prepare, sasl_user_register_local_prepare_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_client_exit_local, sasl_client_exit_hook, HOOK_PRIORITY_DEFAULT);
  hook_install(ircd_hook_client_exit_remote, sasl_client_exit_hook, HOOK_PRIORITY_DEFAULT);
  return true;
}

static void
exit_handler(void *context)
{
  event_destroy(session_expiry_event);

  hook_uninstall(ircd_hook_cap_change, sasl_cap_change_hook);
  hook_uninstall(ircd_hook_conf_read, sasl_conf_read_hook);
  hook_uninstall(ircd_hook_user_register_local_prepare, sasl_user_register_local_prepare_hook);
  hook_uninstall(ircd_hook_client_exit_local, sasl_client_exit_hook);
  hook_uninstall(ircd_hook_client_exit_remote, sasl_client_exit_hook);

  for (size_t i = 0; i < session_bucket_count; ++i)
  {
    list_node_t *node, *next;
    LIST_FOREACH_SAFE(node, next, session_table[i].head)
    {
      struct SaslSession *const session = node->data;
      if (sasl_session_is_pending(session))
        sasl_session_abort(session, ERR_SASLABORTED);
      sasl_session_destroy(session);
    }
  }

  io_free(session_table);
  session_table = NULL;
  session_bucket_count = 0;
  assert(session_count == 0 && list_is_empty(&pending_sessions));

  sasl_server_reset();

  cap_unregister(&sasl_capability);
  command_del_array(command_table, IO_ARRAY_LENGTH(command_table));
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "m_sasl",
  .flags = MODULE_FLAG_NO_DEACTIVATE,
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
