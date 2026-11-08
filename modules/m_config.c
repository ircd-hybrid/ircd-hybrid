/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "io_string.h"
#include "module.h"

#include "client.h"
#include "command.h"
#include "conf.h"
#include "ircd_module.h"
#include "numeric.h"
#include "send.h"

enum config_value_type
{
  CONFIG_VALUE_UNSIGNED_INT,
  CONFIG_VALUE_SECONDS,
  CONFIG_VALUE_BOOLEAN,
  CONFIG_VALUE_STRING,
  CONFIG_VALUE_REDACTED
};

struct config_entry
{
  const char *name;
  enum config_value_type type;
  union
  {
    const unsigned int *unsigned_int;
    const bool *boolean;
    char *const *string;
  } value;
};

#define CONFIG_ENTRY_UNSIGNED(n, v) \
  { .name = n, .type = CONFIG_VALUE_UNSIGNED_INT, .value.unsigned_int = v }
#define CONFIG_ENTRY_SECONDS(n, v) \
  { .name = n, .type = CONFIG_VALUE_SECONDS, .value.unsigned_int = v }
#define CONFIG_ENTRY_BOOLEAN(n, v) \
  { .name = n, .type = CONFIG_VALUE_BOOLEAN, .value.boolean = v }
#define CONFIG_ENTRY_STRING(n, v) \
  { .name = n, .type = CONFIG_VALUE_STRING, .value.string = v }
#define CONFIG_ENTRY_REDACTED(n) \
  { .name = n, .type = CONFIG_VALUE_REDACTED }

/* XXX: static for now. */
static const struct config_entry config_entries[] =
{
  CONFIG_ENTRY_STRING("admin::description", &ConfigAdminInfo.description),
  CONFIG_ENTRY_STRING("admin::email", &ConfigAdminInfo.email),
  CONFIG_ENTRY_STRING("admin::name", &ConfigAdminInfo.name),
  CONFIG_ENTRY_UNSIGNED("channel::default_join_flood_count", &ConfigChannel.default_join_flood_count),
  CONFIG_ENTRY_SECONDS("channel::default_join_flood_time", &ConfigChannel.default_join_flood_time),
  CONFIG_ENTRY_BOOLEAN("channel::disable_fake_channels", &ConfigChannel.disable_fake_channels),
  CONFIG_ENTRY_UNSIGNED("channel::invite_client_count", &ConfigChannel.invite_client_count),
  CONFIG_ENTRY_SECONDS("channel::invite_client_time", &ConfigChannel.invite_client_time),
  CONFIG_ENTRY_SECONDS("channel::invite_delay_channel", &ConfigChannel.invite_delay_channel),
  CONFIG_ENTRY_SECONDS("channel::invite_expire_time", &ConfigChannel.invite_expire_time),
  CONFIG_ENTRY_UNSIGNED("channel::knock_client_count", &ConfigChannel.knock_client_count),
  CONFIG_ENTRY_SECONDS("channel::knock_client_time", &ConfigChannel.knock_client_time),
  CONFIG_ENTRY_SECONDS("channel::knock_delay_channel", &ConfigChannel.knock_delay_channel),
  CONFIG_ENTRY_UNSIGNED("channel::max_bans", &ConfigChannel.max_bans),
  CONFIG_ENTRY_UNSIGNED("channel::max_bans_large", &ConfigChannel.max_bans_large),
  CONFIG_ENTRY_UNSIGNED("channel::max_channels", &ConfigChannel.max_channels),
  CONFIG_ENTRY_UNSIGNED("channel::max_invites", &ConfigChannel.max_invites),
  CONFIG_ENTRY_UNSIGNED("channel::max_kick_length", &ConfigChannel.max_kick_length),
  CONFIG_ENTRY_UNSIGNED("channel::max_topic_length", &ConfigChannel.max_topic_length),
  CONFIG_ENTRY_UNSIGNED("cloak::cidr_len_ipv4", &ConfigCloak.cidr_len_ipv4),
  CONFIG_ENTRY_UNSIGNED("cloak::cidr_len_ipv6", &ConfigCloak.cidr_len_ipv6),
  CONFIG_ENTRY_BOOLEAN("cloak::enabled", &ConfigCloak.enabled),
  CONFIG_ENTRY_UNSIGNED("cloak::num_bits", &ConfigCloak.num_bits),
  CONFIG_ENTRY_REDACTED("cloak::secret"),
  CONFIG_ENTRY_STRING("cloak::suffix", &ConfigCloak.suffix),
  CONFIG_ENTRY_SECONDS("general::anti_spam_exit_message_time", &ConfigGeneral.anti_spam_exit_message_time),
  CONFIG_ENTRY_UNSIGNED("general::away_count", &ConfigGeneral.away_count),
  CONFIG_ENTRY_SECONDS("general::away_time", &ConfigGeneral.away_time),
  CONFIG_ENTRY_SECONDS("general::caller_id_wait", &ConfigGeneral.caller_id_wait),
  CONFIG_ENTRY_UNSIGNED("general::default_floodcount", &ConfigGeneral.default_floodcount),
  CONFIG_ENTRY_SECONDS("general::default_floodtime", &ConfigGeneral.default_floodtime),
  CONFIG_ENTRY_BOOLEAN("general::disable_dns", &ConfigGeneral.disable_dns),
  CONFIG_ENTRY_BOOLEAN("general::disable_ident", &ConfigGeneral.disable_ident),
  CONFIG_ENTRY_UNSIGNED("general::dline_min_cidr", &ConfigGeneral.dline_min_cidr),
  CONFIG_ENTRY_UNSIGNED("general::dline_min_cidr6", &ConfigGeneral.dline_min_cidr6),
  CONFIG_ENTRY_SECONDS("general::ident_timeout", &ConfigGeneral.ident_timeout),
  CONFIG_ENTRY_BOOLEAN("general::invisible_on_connect", &ConfigGeneral.invisible_on_connect),
  CONFIG_ENTRY_SECONDS("general::kill_chase_time_limit", &ConfigGeneral.kill_chase_time_limit),
  CONFIG_ENTRY_UNSIGNED("general::kline_min_cidr", &ConfigGeneral.kline_min_cidr),
  CONFIG_ENTRY_UNSIGNED("general::kline_min_cidr6", &ConfigGeneral.kline_min_cidr6),
  CONFIG_ENTRY_UNSIGNED("general::max_accept", &ConfigGeneral.max_accept),
  CONFIG_ENTRY_UNSIGNED("general::max_away_length", &ConfigGeneral.max_away_length),
  CONFIG_ENTRY_UNSIGNED("general::max_monitor", &ConfigGeneral.max_monitor),
  CONFIG_ENTRY_UNSIGNED("general::max_nick_changes", &ConfigGeneral.max_nick_changes),
  CONFIG_ENTRY_SECONDS("general::max_nick_time", &ConfigGeneral.max_nick_time),
  CONFIG_ENTRY_UNSIGNED("general::max_targets", &ConfigGeneral.max_targets),
  CONFIG_ENTRY_UNSIGNED("general::min_nonwildcard", &ConfigGeneral.min_nonwildcard),
  CONFIG_ENTRY_UNSIGNED("general::min_nonwildcard_simple", &ConfigGeneral.min_nonwildcard_simple),
  CONFIG_ENTRY_STRING("general::oper_umodes", &ConfigGeneral.oper_umodes),
  CONFIG_ENTRY_BOOLEAN("general::opers_bypass_callerid", &ConfigGeneral.opers_bypass_callerid),
  CONFIG_ENTRY_SECONDS("general::pace_wait", &ConfigGeneral.pace_wait),
  CONFIG_ENTRY_SECONDS("general::pace_wait_simple", &ConfigGeneral.pace_wait_simple),
  CONFIG_ENTRY_BOOLEAN("general::ping_cookie", &ConfigGeneral.ping_cookie),
  CONFIG_ENTRY_SECONDS("general::registration_timeout", &ConfigGeneral.registration_timeout),
  CONFIG_ENTRY_STRING("general::sasl_service", &ConfigGeneral.sasl_service),
  CONFIG_ENTRY_BOOLEAN("general::short_motd", &ConfigGeneral.short_motd),
  CONFIG_ENTRY_UNSIGNED("general::specials_in_ident", &ConfigGeneral.specials_in_ident),
  CONFIG_ENTRY_BOOLEAN("general::stats_e_disabled", &ConfigGeneral.stats_e_disabled),
  CONFIG_ENTRY_BOOLEAN("general::stats_u_oper_only", &ConfigGeneral.stats_u_oper_only),
  CONFIG_ENTRY_UNSIGNED("general::throttle_count", &ConfigGeneral.throttle_count),
  CONFIG_ENTRY_SECONDS("general::throttle_time", &ConfigGeneral.throttle_time),
  CONFIG_ENTRY_SECONDS("general::ts_max_delta", &ConfigGeneral.ts_max_delta),
  CONFIG_ENTRY_SECONDS("general::ts_warn_delta", &ConfigGeneral.ts_warn_delta),
  CONFIG_ENTRY_BOOLEAN("general::warn_no_connect_block", &ConfigGeneral.warn_no_connect_block),
  CONFIG_ENTRY_UNSIGNED("general::whowas_history_length", &ConfigGeneral.whowas_history_length),
  CONFIG_ENTRY_BOOLEAN("log::use_logging", &ConfigLog.use_logging),
  CONFIG_ENTRY_BOOLEAN("serverhide::disable_remote_commands", &ConfigServerHide.disable_remote_commands),
  CONFIG_ENTRY_BOOLEAN("serverhide::flatten_links", &ConfigServerHide.flatten_links),
  CONFIG_ENTRY_SECONDS("serverhide::flatten_links_delay", &ConfigServerHide.flatten_links_delay),
  CONFIG_ENTRY_STRING("serverhide::flatten_links_file", &ConfigServerHide.flatten_links_file),
  CONFIG_ENTRY_BOOLEAN("serverhide::hidden", &ConfigServerHide.hidden),
  CONFIG_ENTRY_STRING("serverhide::hidden_name", &ConfigServerHide.hidden_name),
  CONFIG_ENTRY_BOOLEAN("serverhide::hide_servers", &ConfigServerHide.hide_servers),
  CONFIG_ENTRY_BOOLEAN("serverhide::hide_services", &ConfigServerHide.hide_services),
  CONFIG_ENTRY_UNSIGNED("serverinfo::default_max_clients", &ConfigServerInfo.default_max_clients),
  CONFIG_ENTRY_STRING("serverinfo::description", &ConfigServerInfo.description),
  CONFIG_ENTRY_BOOLEAN("serverinfo::hub", &ConfigServerInfo.hub),
  CONFIG_ENTRY_UNSIGNED("serverinfo::max_nick_length", &ConfigServerInfo.max_nick_length),
  CONFIG_ENTRY_STRING("serverinfo::motd_file", &ConfigServerInfo.motd_file),
  CONFIG_ENTRY_STRING("serverinfo::name", &ConfigServerInfo.name),
  CONFIG_ENTRY_STRING("serverinfo::network_description", &ConfigServerInfo.network_description),
  CONFIG_ENTRY_STRING("serverinfo::network_name", &ConfigServerInfo.network_name),
  CONFIG_ENTRY_STRING("serverinfo::sid", &ConfigServerInfo.sid)
};

static bool
_config_entry_matches(const struct config_entry *entry, const char *pattern)
{
  return pattern == NULL || match(pattern, entry->name) == 0;
}

static const char *
_config_format_value(const struct config_entry *entry, char *buffer, size_t buffer_size)
{
  switch (entry->type)
  {
    case CONFIG_VALUE_UNSIGNED_INT:
      snprintf(buffer, buffer_size, "%u", *entry->value.unsigned_int);
      return buffer;
    case CONFIG_VALUE_SECONDS:
      snprintf(buffer, buffer_size, "%u second%s",
               *entry->value.unsigned_int, *entry->value.unsigned_int == 1 ? "" : "s");
      return buffer;
    case CONFIG_VALUE_BOOLEAN:
      return *entry->value.boolean ? "yes" : "no";
    case CONFIG_VALUE_STRING:
      return *entry->value.string;
    case CONFIG_VALUE_REDACTED:
      return "<REDACTED>";
  }

  assert(false);
  return "<invalid>";
}

struct config_output
{
  struct Client *source;
  int name_width;
  size_t limit;
  size_t length;
  char line[IRCD_BUFSIZE];
};

static size_t
_config_notice_limit(const struct Client *source)
{
  const char *const prefix = client_get_id_or_name(&me, source);
  const char *const destination = client_get_id_or_name(source, source);
  const size_t overhead = strlen(prefix) + strlen(destination) + sizeof(": NOTICE  :\r\n") - 1;
  assert(overhead < IRCD_BUFSIZE);

  return IRCD_BUFSIZE - overhead;
}

static void
_config_output_reset(struct config_output *output, const char *name)
{
  const int length = snprintf(output->line, sizeof(output->line), "  %-*s  ", output->name_width, name);
  assert(length > 0 && (size_t)length + 4 <= output->limit);

  output->length = (size_t)length;
}

static void
_config_output_flush(struct config_output *output)
{
  output->line[output->length] = '\0';
  sendto_one_notice(output->source, &me, ":%s", output->line);
}

static void
_config_output_append(struct config_output *output, const char *text, size_t length)
{
  assert(length <= 4);

  if (length > output->limit - output->length)
  {
    _config_output_flush(output);
    _config_output_reset(output, "...");
  }

  memcpy(output->line + output->length, text, length);
  output->length += length;
}

static void
_config_send_value(struct Client *source, const char *name, const char *value,
                   bool quoted, int name_width, size_t limit)
{
  struct config_output output = { .source = source, .name_width = name_width, .limit = limit };
  _config_output_reset(&output, name);

  if (quoted)
    _config_output_append(&output, "\"", 1);

  for (const unsigned char *cursor = (const unsigned char *)value; *cursor; ++cursor)
  {
    const char *text = (const char *)cursor;
    size_t length = 1;
    char escaped[4];

    if (*cursor < 0x20 || *cursor == 0x7f)
    {
      static const char hex[] = "0123456789ABCDEF";

      escaped[0] = '\\';
      escaped[1] = 'x';
      escaped[2] = hex[*cursor >> 4];
      escaped[3] = hex[*cursor & 0xf];
      text = escaped;
      length = sizeof(escaped);
    }
    else if (*cursor == '\\' || *cursor == '"')
    {
      escaped[0] = '\\';
      escaped[1] = (char)*cursor;
      text = escaped;
      length = 2;
    }

    _config_output_append(&output, text, length);
  }

  if (quoted)
    _config_output_append(&output, "\"", 1);

  _config_output_flush(&output);
}

static void
_config_cmd_list(struct Client *source, const char *pattern)
{
  size_t matched = 0;
  int name_width = sizeof("Pattern:") - 1;

  for (size_t i = 0; i < IO_ARRAY_LENGTH(config_entries); ++i)
  {
    const struct config_entry *const entry = &config_entries[i];
    if (!_config_entry_matches(entry, pattern))
      continue;

    ++matched;

    const int length = (int)strlen(entry->name);
    if (length > name_width)
      name_width = length;
  }

  const size_t limit = _config_notice_limit(source);
  sendto_one_notice(source, &me, ":Configuration:");

  if (pattern)
    _config_send_value(source, "Pattern:", pattern, true, name_width, limit);

  if (matched == 0)
  {
    sendto_one_notice(source, &me, ":No matching configuration entries.");
    return;
  }

  for (size_t i = 0; i < IO_ARRAY_LENGTH(config_entries); ++i)
  {
    const struct config_entry *const entry = &config_entries[i];
    if (!_config_entry_matches(entry, pattern))
      continue;

    char buffer[sizeof(unsigned int) * CHAR_BIT + sizeof(" seconds")];
    const char *const value = _config_format_value(entry, buffer, sizeof(buffer));
    const bool quoted = entry->type == CONFIG_VALUE_STRING && value != NULL;

    _config_send_value(source, entry->name, value ? value : "<unset>", quoted, name_width, limit);
  }

  sendto_one_notice(source, &me, ":End of configuration list: %zu %s.",
                    matched, matched == 1 ? "entry" : "entries");
}

static void
mo_config(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_admin(source))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "admin");
    return;
  }

  if (parc > 3 || (parc > 1 && io_strcasecmp(parv[1], "LIST")) ||
      (parc == 3 && string_is_empty(parv[2])))
  {
    sendto_one_notice(source, &me, ":Syntax: CONFIG [LIST [selector]]");
    return;
  }

  _config_cmd_list(source, parc == 3 ? parv[2] : NULL);
}

static struct Command command_table =
{
  .name = "CONFIG",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_config }
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_commands(&command_table, 1, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  command_del(&command_table);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "m_config",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
