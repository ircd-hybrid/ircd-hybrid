/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_dline.c
 * \brief Includes required functions for processing the DLINE command.
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
#include "conf_deny.h"
#include "conf_oper.h"
#include "conf_shared.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server_capab.h"

static uintmax_t
_dline_expiration_time(uintmax_t created_at, uintmax_t duration_seconds)
{
  assert(duration_seconds > 0);

  if (duration_seconds > UINTMAX_MAX - created_at)
    return UINTMAX_MAX;

  return created_at + duration_seconds;
}

static bool
_dline_validate_prefix(struct Client *source, const char *prefix)
{
  assert(source);
  assert(!string_is_empty(prefix));

  struct io_addr network;
  unsigned int prefix_length;

  if (!address_parse_prefix(prefix, &network, &prefix_length))
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Invalid D-Line");

    return false;
  }

  const unsigned int minimum_prefix_length =
    address_is_ipv4(&network) ? ConfigGeneral.dline_min_cidr :
                                ConfigGeneral.dline_min_cidr6;

  if (minimum_prefix_length == 0 || client_is_service(source) ||
      prefix_length >= minimum_prefix_length)
    return true;

  if (client_is_user(source))
    sendto_one_notice(source, &me, ":For safety, bitmasks less than %u require conf access.",
                      minimum_prefix_length);

  return false;
}

static void
_dline_enforce_clients(const struct conf_deny *deny)
{
  assert(deny);

  list_t *const lists[] = { &local_client_list, &unknown_list };

  for (size_t i = 0; i < IO_ARRAY_LENGTH(lists); ++i)
  {
    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, lists[i]->head)
    {
      struct Client *const client = node->data;
      if (client_is_dead(client) || !conf_deny_matches(deny, &client->addr))
        continue;

      conf_ban_apply(client, CONF_BAN_TYPE_DLINE, deny->reason);
    }
  }
}

static void
_dline_notice_added(struct Client *source, const char *prefix,
                    const char *input_prefix, uintmax_t duration_seconds)
{
  assert(source);
  assert(!string_is_empty(prefix));
  assert(!string_is_empty(input_prefix));

  if (!client_is_user(source))
    return;

  const bool normalized = strcmp(input_prefix, prefix) != 0;

  if (duration_seconds)
  {
    const uintmax_t duration_minutes = duration_seconds / 60;

    if (normalized)
      sendto_one_notice(source, &me, ":Added temporary %ju min. D-Line [%s] (normalized from %s)",
                        duration_minutes, prefix, input_prefix);
    else
      sendto_one_notice(source, &me, ":Added temporary %ju min. D-Line [%s]",
                        duration_minutes, prefix);

    return;
  }

  if (normalized)
    sendto_one_notice(source, &me,
                      ":Added D-Line [%s] (normalized from %s)",
                      prefix, input_prefix);
  else
    sendto_one_notice(source, &me, ":Added D-Line [%s]", prefix);
}

static void
_dline_notice_existing(struct Client *source, const struct aline_ctx *aline,
                       const struct conf_deny *existing)
{
  assert(source);
  assert(aline);
  assert(!string_is_empty(aline->mask));
  assert(existing);

  if (!client_is_user(source))
    return;

  char prefix[IRCD_BUFSIZE];
  const bool formatted = conf_deny_format_prefix(existing, prefix, sizeof(prefix));
  assert(formatted);

  if (!formatted)
  {
    log_write(LOG_TYPE_IRCD, "Unable to format existing D-line prefix for [%s]",
              aline->mask);
    sendto_one_notice(source, &me, ":[%s] is already covered by an existing D-Line",
                      aline->mask);
    return;
  }

  sendto_one_notice(source, &me, ":[%s] already D-Lined by [%s] - %s",
                    aline->mask, prefix, existing->reason);
}

static void
_dline_report_added(struct Client *source, const struct conf_deny *deny,
                    const char *prefix, uintmax_t duration_seconds)
{
  assert(source);
  assert(deny);
  assert(!string_is_empty(prefix));

  client_format_oper_name_buffer_t source_name_buffer;
  const char *const source_name = client_format_oper_name(source, &source_name_buffer);

  if (duration_seconds)
  {
    const uintmax_t duration_minutes = duration_seconds / 60;

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Temporary D-line added by %s for [%s] (%ju min) [%s]",
                   source_name, prefix, duration_minutes, deny->reason);
    log_write(LOG_TYPE_DLINE,
              "Temporary D-line added by %s for [%s] (%ju min) [%s]",
              source_name, prefix, duration_minutes, deny->reason);
    return;
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "D-line added by %s for [%s] [%s]",
                 source_name, prefix, deny->reason);
  log_write(LOG_TYPE_DLINE, "D-line added by %s for [%s] [%s]",
            source_name, prefix, deny->reason);
}

static void
_dline_add(struct Client *source, const struct aline_ctx *aline)
{
  assert(source);
  assert(aline);
  assert(!string_is_empty(aline->mask));
  assert(aline->reason);

  if (!_dline_validate_prefix(source, aline->mask))
    return;

  const struct conf_deny *const existing = conf_deny_find_covering(aline->mask);
  if (existing)
  {
    _dline_notice_existing(source, aline, existing);
    return;
  }

  const uintmax_t created_at = io_time_get(IO_TIME_REALTIME_SEC);
  const uintmax_t expires_at =
    aline->duration ? _dline_expiration_time(created_at, aline->duration) : 0;
  const char *const created_date = date_iso8601(0);

  char reason[IRCD_BUFSIZE];
  if (aline->duration)
  {
    const uintmax_t duration_minutes = aline->duration / 60;
    snprintf(reason, sizeof(reason), "Temporary D-line %ju min. - %.*s (%s)",
             duration_minutes, REASONLEN, aline->reason, created_date);
  }
  else
    snprintf(reason, sizeof(reason), "%.*s (%s)",
             REASONLEN, aline->reason, created_date);

  const struct conf_deny_spec spec =
  {
    .prefix = aline->mask,
    .reason = reason,
    .created_at = created_at,
    .expires_at = expires_at,
    .origin = CONF_DENY_ORIGIN_DATABASE
  };

  struct conf_deny *const deny = conf_deny_add(&spec);
  if (deny == NULL)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Unable to add D-Line [%s]",
                        aline->mask);

    log_write(LOG_TYPE_IRCD, "Unable to add D-line for [%s]", aline->mask);
    return;
  }

  char prefix[IRCD_BUFSIZE];
  const bool formatted = conf_deny_format_prefix(deny, prefix, sizeof(prefix));
  assert(formatted);

  if (!formatted)
  {
    if (client_is_user(source))
      sendto_one_notice(source, &me, ":Unable to add D-Line [%s]",
                        aline->mask);

    log_write(LOG_TYPE_IRCD, "Unable to format newly added D-line prefix for [%s]",
              aline->mask);
    conf_deny_delete(deny);
    return;
  }

  _dline_notice_added(source, prefix, aline->mask, aline->duration);
  _dline_report_added(source, deny, prefix, aline->duration);
  _dline_enforce_clients(deny);
}

static void
mo_dline(struct Client *source, size_t parc, char *parv[])
{
  if (!client_has_oper_flag(source, OPER_FLAG_DLINE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "dline");
    return;
  }

  struct aline_ctx aline = { .add = true, .simple_mask = true };
  if (!aline_parse("DLINE", source, parc, parv, &aline))
    return;

  if (aline.server)
  {
    sendto_match_servs(source, aline.server, CAPAB_DLN, "DLINE %s %ju %s :%s",
                       aline.server, aline.duration, aline.mask, aline.reason);

    /* Apply the D-line locally as well when the ON mask matches this server. */
    if (match(aline.server, me.name))
      return;
  }
  else
    cluster_distribute(source, "DLINE", CAPAB_DLN, CLUSTER_DLINE, "%ju %s :%s",
                       aline.duration, aline.mask, aline.reason);

  _dline_add(source, &aline);
}

/*! \brief DLINE command handler
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
 *      - parv[3] = IP address
 *      - parv[4] = reason
 */
static void
ms_dline(struct Client *source, size_t parc, char *parv[])
{
  uintmax_t duration_seconds;
  if (io_parse_uintmax(parv[2], &duration_seconds) != IO_PARSE_OK)
    return;

  struct aline_ctx aline =
  {
    .add = true,
    .simple_mask = true,
    .mask = parv[3],
    .reason = parv[4],
    .server = parv[1],
    .duration = duration_seconds
  };

  sendto_match_servs(source, aline.server, CAPAB_DLN, "DLINE %s %ju %s :%s",
                     aline.server, aline.duration, aline.mask, aline.reason);

  if (match(aline.server, me.name))
    return;

  if (client_is_service(source) ||
      shared_find(SHARED_DLINE, source->uplink->name, source->username, source->host))
    _dline_add(source, &aline);
}

static struct Command command_table =
{
  .name = "DLINE",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_dline, .args_min = 5 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_dline, .args_min = 2 }
};

static void
init_handler(void)
{
  command_add(&command_table);
  capab_add("DLN", CAPAB_DLN, true);
}

static void
exit_handler(void)
{
  command_del(&command_table);
  capab_del("DLN");
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
