/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_kline.c
 * \brief Includes required functions for processing the KLINE command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "address.h"
#include "io_parse.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "misc.h"
#include "module.h"

#include "aline.h"
#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "conf_cluster.h"
#include "conf_kill.h"
#include "conf_oper.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static uintmax_t
_kline_expiration_time(uintmax_t created_at, uintmax_t duration_seconds)
{
  assert(duration_seconds > 0);

  if (duration_seconds > UINTMAX_MAX - created_at)
    return UINTMAX_MAX;

  return created_at + duration_seconds;
}

static bool
_kline_validate_masks(struct Client *source, const struct aline_ctx *aline)
{
  assert(source);
  assert(aline);
  assert(!string_is_empty(aline->user));
  assert(!string_is_empty(aline->host));

  if (client_is_service(source))
    return true;

  const char *const masks[] = { aline->user, aline->host };
  if (aline_valid_mask(IO_ARRAY_LENGTH(masks), masks))
    return true;

  if (client_is_user(source))
    sendto_one_notice(source, &me, ":Please include at least %u non-wildcard characters with the mask",
                      ConfigGeneral.min_nonwildcard);

  return false;
}

static bool
_kline_validate_prefix(struct Client *source, const char *host)
{
  assert(source);
  assert(!string_is_empty(host));

  struct io_addr network;
  unsigned int prefix_length;

  if (!address_parse_prefix(host, &network, &prefix_length))
    return true;

  const unsigned int minimum_prefix_length =
    address_is_ipv4(&network) ? ConfigGeneral.kline_min_cidr :
                                ConfigGeneral.kline_min_cidr6;

  if (minimum_prefix_length == 0 || client_is_service(source) ||
      prefix_length >= minimum_prefix_length)
    return true;

  if (client_is_user(source))
    sendto_one_notice(source, &me, ":For safety, bitmasks less than %u require conf access.",
                      minimum_prefix_length);

  return false;
}

static bool
_kline_matches_client(const struct conf_kill *kill, const struct Client *client)
{
  assert(kill);
  assert(client);

  return conf_kill_matches(kill, &client->addr, client->username, client->realhost) ||
         conf_kill_matches(kill, NULL, client->username, client->sockhost) ||
         conf_kill_matches(kill, NULL, client->username, client->host);
}

static void
_kline_enforce_clients(const struct conf_kill *kill)
{
  assert(kill);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *const client = node->data;
    if (client_is_dead(client) || !_kline_matches_client(kill, client))
      continue;

    conf_ban_apply(client, CONF_BAN_TYPE_KLINE, kill->reason);
  }
}

static void
_kline_notice_added(struct Client *source, const struct conf_kill *kill,
                    const char *host, const char *input_host, uintmax_t duration_seconds)
{
  assert(source);
  assert(kill);
  assert(!string_is_empty(host));
  assert(!string_is_empty(input_host));

  if (!client_is_user(source))
    return;

  const bool normalized = strcmp(input_host, host) != 0;

  if (duration_seconds)
  {
    const uintmax_t duration_minutes = duration_seconds / 60;

    if (normalized)
      sendto_one_notice(source, &me, ":Added temporary %ju min. K-Line [%s@%s] (normalized from %s)",
                        duration_minutes, kill->user, host, input_host);
    else
      sendto_one_notice(source, &me, ":Added temporary %ju min. K-Line [%s@%s]",
                        duration_minutes, kill->user, host);

    return;
  }

  if (normalized)
    sendto_one_notice(source, &me, ":Added K-Line [%s@%s] (normalized from %s)",
                      kill->user, host, input_host);
  else
    sendto_one_notice(source, &me, ":Added K-Line [%s@%s]",
                      kill->user, host);
}

static void
_kline_notice_existing(struct Client *source, const struct aline_ctx *aline,
                       const struct conf_kill *existing)
{
  assert(source);
  assert(aline);
  assert(!string_is_empty(aline->user));
  assert(!string_is_empty(aline->host));
  assert(existing);

  if (!client_is_user(source))
    return;

  char host[IRCD_BUFSIZE];
  const bool formatted = conf_kill_format_host(existing, host, sizeof(host));
  assert(formatted);

  if (!formatted)
  {
    log_write(LOG_TYPE_IRCD, "Unable to format existing K-line host for [%s@%s]",
              aline->user, aline->host);
    sendto_one_notice(source, &me, ":Unable to display the existing K-Line covering [%s@%s]",
                      aline->user, aline->host);
    return;
  }

  sendto_one_notice(source, &me, ":[%s@%s] already K-Lined by [%s@%s] - %s",
                    aline->user, aline->host, existing->user, host, existing->reason);
}

static void
_kline_report_added(struct Client *source, const struct conf_kill *kill,
                    const char *host, uintmax_t duration_seconds)
{
  assert(source);
  assert(kill);
  assert(!string_is_empty(host));

  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  if (duration_seconds)
  {
    const uintmax_t duration_minutes = duration_seconds / 60;

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Temporary K-line added by %s for [%s@%s] (%ju min) [%s]",
                   source_name, kill->user, host, duration_minutes, kill->reason);
    log_write(LOG_TYPE_KLINE,
              "Temporary K-line added by %s for [%s@%s] (%ju min) [%s]",
              source_name, kill->user, host, duration_minutes, kill->reason);
    return;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "K-line added by %s for [%s@%s] [%s]",
                 source_name, kill->user, host, kill->reason);
  log_write(LOG_TYPE_KLINE, "K-line added by %s for [%s@%s] [%s]",
            source_name, kill->user, host, kill->reason);
}

static void
_kline_add(struct Client *source, const struct aline_ctx *aline)
{
  assert(source);
  assert(aline);
  assert(!string_is_empty(aline->user));
  assert(!string_is_empty(aline->host));
  assert(aline->reason);

  if (!_kline_validate_masks(source, aline) ||
      !_kline_validate_prefix(source, aline->host))
    return;

  const struct conf_kill *const existing = conf_kill_find_covering(aline->user, aline->host);
  if (existing)
  {
    _kline_notice_existing(source, aline, existing);
    return;
  }

  const uintmax_t created_at = io_time_get(IO_TIME_REALTIME_SEC);
  const uintmax_t expires_at =
    aline->duration ? _kline_expiration_time(created_at, aline->duration) : 0;
  const char *const created_date = date_iso8601(0);

  char reason[IRCD_BUFSIZE];
  if (aline->duration)
  {
    const uintmax_t duration_minutes = aline->duration / 60;
    snprintf(reason, sizeof(reason), "Temporary K-line %ju min. - %.*s (%s)",
             duration_minutes, REASONLEN, aline->reason, created_date);
  }
  else
    snprintf(reason, sizeof(reason), "%.*s (%s)",
             REASONLEN, aline->reason, created_date);

  const struct conf_kill_spec spec =
  {
    .user = aline->user,
    .host = aline->host,
    .reason = reason,
    .created_at = created_at,
    .expires_at = expires_at,
    .origin = CONF_KILL_ORIGIN_DATABASE
  };

  struct conf_kill *const kill = conf_kill_add(&spec);
  if (kill == NULL)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Unable to add K-Line [%s@%s]",
                        aline->user, aline->host);

    log_write(LOG_TYPE_IRCD, "Unable to add K-line for [%s@%s]",
              aline->user, aline->host);
    return;
  }

  char host[IRCD_BUFSIZE];
  const bool formatted = conf_kill_format_host(kill, host, sizeof(host));
  assert(formatted);

  if (!formatted)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Unable to add K-Line [%s@%s]",
                        aline->user, aline->host);

    log_write(LOG_TYPE_IRCD, "Unable to format newly added K-line host for [%s@%s]",
              aline->user, aline->host);
    conf_kill_delete(kill);
    return;
  }

  _kline_notice_added(source, kill, host, aline->host, aline->duration);
  _kline_report_added(source, kill, host, aline->duration);
  _kline_enforce_clients(kill);
}

static void
mo_kline(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_KLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kline");
    return;
  }

  struct aline_ctx aline = { .add = true, .simple_mask = false };
  if (!aline_parse("KLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_KLN, "KLINE %s %ju %s %s :%s",
                       aline.server, aline.duration, aline.user, aline.host, aline.reason);

    /* Apply the K-line locally as well when the ON mask matches this server. */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "KLINE", CAPAB_KLN, CLUSTER_KLINE, "%ju %s %s :%s",
                       aline.duration, aline.user, aline.host, aline.reason);

  _kline_add(source, &aline);
}

/*! \brief KLINE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = duration in seconds
 *      - parv[3] = user mask
 *      - parv[4] = host mask
 *      - parv[5] = reason
 */
static void
ms_kline(struct Client *source, size_t parc, char *parv[])
{
  uintmax_t duration_seconds;
  if (io_parse_uintmax(parv[2], &duration_seconds) != IO_PARSE_OK)
    return;

  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = false,
    .user = parv[3],
    .host = parv[4],
    .reason = parv[5],
    .server = parv[1],
    .duration = duration_seconds
  };

  sendto_match_servs(source, aline.server, CAPAB_KLN, "KLINE %s %ju %s %s :%s",
                     aline.server, aline.duration, aline.user, aline.host, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_KLINE, source->uplink->name, source->username, source->host))
    _kline_add(source, &aline);
}

static struct Command command_table =
{
  .name = "KLINE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_kline, .args_min = 6 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_kline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("KLN", CAPAB_KLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("KLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
