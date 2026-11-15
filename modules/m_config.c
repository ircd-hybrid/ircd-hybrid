/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "address.h"
#include "io.h"
#include "io_hex.h"
#include "io_parse.h"
#include "io_string.h"
#include "io_time.h"
#include "module.h"

#include "client.h"
#include "command.h"
#include "conf.h"
#include "conf_deny.h"
#include "conf_exempt.h"
#include "conf_kill.h"
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
  CONFIG_ENTRY_STRING("serverinfo::sid", &ConfigServerInfo.sid),
  CONFIG_ENTRY_STRING("serverinfo::tls_certificate_file", &ConfigServerInfo.tls_certificate_file),
  CONFIG_ENTRY_STRING("serverinfo::tls_private_key_file", &ConfigServerInfo.tls_private_key_file)
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

static size_t
_config_escape_byte(unsigned char ch, char *buffer)
{
  if (ch < 0x20 || ch == 0x7f)
  {
    buffer[0] = '\\';
    buffer[1] = 'x';

    const bool converted = io_bytes_to_hex(&ch, 1, buffer + 2, sizeof("FF"));
    assert(converted);
    (void)converted;
    return sizeof("\\xFF") - 1;
  }

  if (ch == '\\' || ch == '"')
  {
    buffer[0] = '\\';
    buffer[1] = (char)ch;
    buffer[2] = '\0';
    return 2;
  }

  buffer[0] = (char)ch;
  buffer[1] = '\0';
  return 1;
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
    char escaped[sizeof("\\xFF")];
    const size_t length = _config_escape_byte(*cursor, escaped);
    _config_output_append(&output, escaped, length);
  }

  if (quoted)
    _config_output_append(&output, "\"", 1);

  _config_output_flush(&output);
}

static void
_config_cmd_list(struct Client *source, const char *pattern)
{
  const size_t count = IO_ARRAY_LENGTH(config_entries);
  size_t matched = 0;
  int name_width = sizeof("Pattern:") - 1;

  for (size_t i = 0; i < count; ++i)
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

  for (size_t i = 0; i < count; ++i)
  {
    const struct config_entry *const entry = &config_entries[i];
    if (!_config_entry_matches(entry, pattern))
      continue;

    char buffer[sizeof(unsigned int) * CHAR_BIT + sizeof(" seconds")];
    const char *const value = _config_format_value(entry, buffer, sizeof(buffer));
    const bool quoted = entry->type == CONFIG_VALUE_STRING && value != NULL;

    _config_send_value(source, entry->name, value ? value : "<unset>", quoted, name_width, limit);
  }

  const char *const entry_label = count == 1 ? "entry" : "entries";
  if (pattern)
    sendto_one_notice(source, &me, ":End of configuration list: %zu of %zu %s shown.",
                      matched, count, entry_label);
  else
    sendto_one_notice(source, &me, ":End of configuration list: %zu %s.", count, entry_label);
}

enum
{
  CONFIG_BLOCK_PAGE_SIZE = 50,
  CONFIG_ORIGIN_COLUMN_WIDTH = sizeof("database") - 1,
  CONFIG_EXPIRY_COLUMN_WIDTH = 12,
  CONFIG_SELECTOR_COLUMN_WIDTH = 24,
  CONFIG_TIME_BUFSIZE = sizeof(uintmax_t) * CHAR_BIT + 1
};

struct config_record
{
  char selector[IRCD_BUFSIZE];
  const char *origin;
  const char *reason;
  uintmax_t created_at;
  uintmax_t expires_at;
};

struct config_block
{
  const char *name;
  const char *selector_label;
  bool has_metadata;
  const list_t *(*get_list)(void);
  bool (*read_record)(const void *, struct config_record *);
  bool (*normalize_selector)(const char *, char *, size_t);
};

struct config_block_query
{
  const struct config_block *block;
  const char *selector;
  uintmax_t page;
  bool detailed;
};

static bool
_config_normalize_prefix(const char *text, char *buffer, size_t buffer_size)
{
  struct io_addr address;
  unsigned int prefix_length;

  return address_parse_prefix(text, &address, &prefix_length) &&
         address_prefix_to_string(&address, prefix_length, buffer, buffer_size);
}

static bool
_config_normalize_kill_selector(const char *text, char *buffer, size_t buffer_size)
{
  const char *const separator = strrchr(text, '@');
  if (separator == NULL || separator == text || separator[1] == '\0')
    return false;

  const size_t user_length = (size_t)(separator - text) + 1;
  if (user_length >= buffer_size)
    return false;

  char prefix[ADDRESS_PREFIX_BUFSIZE];
  const char *host = separator + 1;
  if (_config_normalize_prefix(host, prefix, sizeof(prefix)))
    host = prefix;

  const size_t host_length = strlen(host);
  if (host_length >= buffer_size - user_length)
    return false;

  memcpy(buffer, text, user_length);
  memcpy(buffer + user_length, host, host_length + 1);
  return true;
}

static bool
_config_read_kill(const void *data, struct config_record *record)
{
  const struct conf_kill *const kill = data;
  char host[IRCD_BUFSIZE];

  const bool formatted = conf_kill_format_host(kill, host, sizeof(host));
  assert(formatted);
  if (!formatted)
    return false;

  const int length = snprintf(record->selector, sizeof(record->selector), "%s@%s", kill->user, host);
  assert(length >= 0 && (size_t)length < sizeof(record->selector));
  if (length < 0 || (size_t)length >= sizeof(record->selector))
    return false;

  switch (kill->origin)
  {
    case CONF_KILL_ORIGIN_CONFIG:   record->origin = "config"; break;
    case CONF_KILL_ORIGIN_DATABASE: record->origin = "database"; break;
    default: return false;
  }

  record->reason = kill->reason;
  record->created_at = kill->created_at;
  record->expires_at = kill->expires_at;
  return true;
}

static bool
_config_read_deny(const void *data, struct config_record *record)
{
  const struct conf_deny *const deny = data;
  if (!conf_deny_format_prefix(deny, record->selector, sizeof(record->selector)))
    return false;

  switch (deny->origin)
  {
    case CONF_DENY_ORIGIN_CONFIG:   record->origin = "config"; break;
    case CONF_DENY_ORIGIN_DATABASE: record->origin = "database"; break;
    default: return false;
  }

  record->reason = deny->reason;
  record->created_at = deny->created_at;
  record->expires_at = deny->expires_at;
  return true;
}

static bool
_config_read_exempt(const void *data, struct config_record *record)
{
  return conf_exempt_format_prefix(data, record->selector, sizeof(record->selector));
}

static const struct config_block config_blocks[] =
{
  {
    .name = "KILL",
    .selector_label = "user",
    .has_metadata = true,
    .get_list = conf_kill_get_list,
    .read_record = _config_read_kill,
    .normalize_selector = _config_normalize_kill_selector
  },
  {
    .name = "DENY",
    .selector_label = "ip",
    .has_metadata = true,
    .get_list = conf_deny_get_list,
    .read_record = _config_read_deny,
    .normalize_selector = _config_normalize_prefix
  },
  {
    .name = "EXEMPT",
    .selector_label = "ip",
    .get_list = conf_exempt_get_list,
    .read_record = _config_read_exempt,
    .normalize_selector = _config_normalize_prefix
  }
};

static const struct config_block *
_config_block_find(const char *name)
{
  for (size_t i = 0; i < IO_ARRAY_LENGTH(config_blocks); ++i)
    if (io_strcasecmp(name, config_blocks[i].name) == 0)
      return &config_blocks[i];

  return NULL;
}

static bool
_config_record_matches(const struct config_block_query *query, const struct config_record *record)
{
  if (query->selector == NULL)
    return true;

  if (query->detailed)
    return io_strcasecmp(query->selector, record->selector) == 0;

  return match(query->selector, record->selector) == 0;
}

static size_t
_config_escaped_length(const char *value, size_t limit)
{
  size_t length = 0;

  for (const unsigned char *p = (const unsigned char *)value; *p; ++p)
  {
    char escaped[sizeof("\\xFF")];
    const size_t encoded_length = _config_escape_byte(*p, escaped);
    if (encoded_length > limit - length)
      return limit;

    length += encoded_length;
  }

  return length;
}

static size_t
_config_format_preview(const char *value, bool quoted, char *buffer, size_t buffer_size)
{
  assert(buffer_size >= sizeof("\"...\""));

  size_t capacity = buffer_size - 1 - (quoted ? 2 : 0);
  const bool truncated = _config_escaped_length(value, capacity + 1) > capacity;

  if (truncated)
    capacity -= sizeof("...") - 1;

  size_t written = 0;
  if (quoted)
    buffer[written++] = '"';

  size_t content_length = 0;
  for (const unsigned char *p = (const unsigned char *)value; *p; ++p)
  {
    char escaped[sizeof("\\xFF")];
    const size_t length = _config_escape_byte(*p, escaped);
    if (length > capacity - content_length)
      break;

    memcpy(buffer + written, escaped, length);
    written += length;
    content_length += length;
  }

  if (truncated)
  {
    memcpy(buffer + written, "...", sizeof("...") - 1);
    written += sizeof("...") - 1;
  }

  if (quoted)
    buffer[written++] = '"';

  buffer[written] = '\0';
  return written;
}

static void
_config_send_record_row(struct Client *source, const struct config_record *record, size_t limit, uintmax_t now)
{
  char line[IRCD_BUFSIZE];
  size_t length;

  if (record->origin)
  {
    char expires[CONFIG_TIME_BUFSIZE + sizeof("s")];

    if (record->expires_at == 0)
      strcpy(expires, "never");
    else if (record->expires_at <= now)
      strcpy(expires, "expired");
    else
      snprintf(expires, sizeof(expires), "%jus", record->expires_at - now);

    const int prefix_length = snprintf(line, sizeof(line), "  %-*s %-*s ",
                                       CONFIG_ORIGIN_COLUMN_WIDTH, record->origin, CONFIG_EXPIRY_COLUMN_WIDTH, expires);
    assert(prefix_length > 0 && (size_t)prefix_length < sizeof(line));
    length = (size_t)prefix_length;
  }
  else
  {
    memcpy(line, "  ", 2);
    length = 2;
  }

  const size_t minimum_preview_length = sizeof("\"...\"") - 1;
  assert(length + 2 + 2 * minimum_preview_length <= limit);
  size_t reserved = 0;

  if (record->reason)
  {
    size_t reason_length = 2 + _config_escaped_length(record->reason, (limit - length) / 2 - 2);
    if (reason_length < minimum_preview_length)
      reason_length = minimum_preview_length;

    reserved = 2 + reason_length;
  }

  const size_t selector_length =
    _config_format_preview(record->selector, false, line + length, limit - length - reserved + 1);
  length += selector_length;

  if (record->reason)
  {
    size_t padding = selector_length < CONFIG_SELECTOR_COLUMN_WIDTH ?
      CONFIG_SELECTOR_COLUMN_WIDTH - selector_length + 2 : 2;
    const size_t padding_limit = limit - length - minimum_preview_length;
    if (padding > padding_limit)
      padding = padding_limit;

    memset(line + length, ' ', padding);
    length += padding;
    length += _config_format_preview(record->reason, true, line + length, limit - length + 1);
  }

  line[length] = '\0';
  sendto_one_notice(source, &me, ":%s", line);
}

static const char *
_config_format_timestamp(uintmax_t timestamp, char *buffer, size_t buffer_size)
{
  if (timestamp == 0)
    return "<unknown>";

  if (timestamp <= INTMAX_MAX)
  {
    const time_t time = (time_t)timestamp;
    struct tm utc;
    if ((uintmax_t)time == timestamp && gmtime_r(&time, &utc) && utc.tm_year <= 9999 - 1900 &&
        strftime(buffer, buffer_size, "%Y-%m-%dT%H:%M:%SZ", &utc))
      return buffer;
  }

  snprintf(buffer, buffer_size, "%ju", timestamp);
  return buffer;
}

static void
_config_send_record_details(struct Client *source, const struct config_block *block,
                            const struct config_record *record, size_t limit, uintmax_t now)
{
  const int width = sizeof("expires_at") - 1;
  _config_send_value(source, block->selector_label, record->selector, true, width, limit);

  if (record->origin == NULL)
    return;

  char buffer[CONFIG_TIME_BUFSIZE + sizeof(" seconds")];
  _config_send_value(source, "origin", record->origin, false, width, limit);
  _config_send_value(source, "created_at",
                      _config_format_timestamp(record->created_at, buffer, sizeof(buffer)), false, width, limit);
  _config_send_value(source, "expires_at", record->expires_at ?
                      _config_format_timestamp(record->expires_at, buffer, sizeof(buffer)) : "never", false, width, limit);

  if (record->expires_at)
  {
    const char *remaining = "expired";

    if (record->expires_at > now)
    {
      snprintf(buffer, sizeof(buffer), "%ju seconds", record->expires_at - now);
      remaining = buffer;
    }

    _config_send_value(source, "remaining", remaining, false, width, limit);
  }

  _config_send_value(source, "reason", record->reason, true, width, limit);
}

static void
_config_cmd_block(struct Client *source, const struct config_block_query *query)
{
  assert(query->page > 0);

  const list_t *const items = query->block->get_list();
  const size_t total = list_length(items);
  const size_t page_size = query->detailed ? 1 : CONFIG_BLOCK_PAGE_SIZE;
  const uintmax_t page_index = query->page - 1;
  const void *page_items[CONFIG_BLOCK_PAGE_SIZE];
  struct config_record record = { 0 };
  size_t matched = 0;
  size_t selected = 0;

  const list_node_t *node;
  LIST_FOREACH(node, items->head)
  {
    if (query->selector)
    {
      if (!query->block->read_record(node->data, &record))
        goto format_error;
      if (!_config_record_matches(query, &record))
        continue;
    }

    if (matched / page_size == page_index)
    {
      assert(selected < IO_ARRAY_LENGTH(page_items));
      page_items[selected++] = node->data;
    }
    ++matched;

    if (query->selector == NULL && selected == page_size)
    {
      matched = total;
      break;
    }
  }

  const size_t pages = matched ? (matched - 1) / page_size + 1 : 1;
  if (query->page > pages)
  {
    sendto_one_notice(source, &me, ":Page %ju is out of range for %s (1-%zu).",
                      query->page, query->block->name, pages);
    return;
  }

  const size_t limit = _config_notice_limit(source);
  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);
  sendto_one_notice(source, &me, ":%s configuration:", query->block->name);

  if (query->selector && (!query->detailed || matched == 0))
    _config_send_value(source, query->detailed ? "Selector:" : "Pattern:", query->selector, true, 10, limit);

  if (pages > 1)
    sendto_one_notice(source, &me, ":  Page: %ju of %zu", query->page, pages);

  if (!query->detailed && query->block->has_metadata)
    sendto_one_notice(source, &me, ":  %-*s %-*s %-*s  Reason",
                      CONFIG_ORIGIN_COLUMN_WIDTH, "Origin", CONFIG_EXPIRY_COLUMN_WIDTH, "Expires",
                      CONFIG_SELECTOR_COLUMN_WIDTH, query->block->selector_label);

  for (size_t i = 0; i < selected; ++i)
  {
    if (!query->block->read_record(page_items[i], &record))
      goto format_error;

    if (query->detailed)
      _config_send_record_details(source, query->block, &record, limit, now);
    else
      _config_send_record_row(source, &record, limit, now);
  }

  sendto_one_notice(source, &me, ":End of %s configuration%s: %zu of %zu %s shown.",
                    query->block->name, query->detailed ? "" : " list", selected, total, total == 1 ? "entry" : "entries");

  if (query->selector && matched > selected)
    sendto_one_notice(source, &me, ":%zu entries match the selector.", matched);
  if (query->page < pages)
    sendto_one_notice(source, &me, ":Next page: PAGE %ju.", query->page + 1);
  return;

format_error:
  sendto_one_notice(source, &me, ":Unable to format %s configuration entry.", query->block->name);
}

static void
_config_send_syntax(struct Client *source)
{
  sendto_one_notice(source, &me, ":Syntax: CONFIG [LIST [selector]]");
  sendto_one_notice(source, &me, ":Syntax: CONFIG LIST <KILL|DENY|EXEMPT> [pattern] [PAGE <number>]");
  sendto_one_notice(source, &me, ":Syntax: CONFIG SHOW <KILL|DENY|EXEMPT> <selector> [PAGE <number>]");
}

static void
mo_config(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_admin(source))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "admin");
    return;
  }

  if (parc == 1 || (parc == 2 && io_strcasecmp(parv[1], "LIST") == 0))
  {
    _config_cmd_list(source, NULL);
    return;
  }

  const bool detailed = io_strcasecmp(parv[1], "SHOW") == 0;
  if (parc < 3 || (!detailed && io_strcasecmp(parv[1], "LIST")))
  {
    _config_send_syntax(source);
    return;
  }

  const struct config_block *const block = _config_block_find(parv[2]);
  if (block == NULL)
  {
    if (!detailed && parc == 3 && !string_is_empty(parv[2]))
      _config_cmd_list(source, parv[2]);
    else
      _config_send_syntax(source);
    return;
  }

  struct config_block_query query = { .block = block, .page = 1, .detailed = detailed };
  size_t argument_count = parc - 3;
  char *const *const arguments = parv + 3;
  if (argument_count >= 2 && io_strcasecmp(arguments[argument_count - 2], "PAGE") == 0)
  {
    if (io_parse_uintmax(arguments[argument_count - 1], &query.page) != IO_PARSE_OK || query.page == 0)
    {
      _config_send_syntax(source);
      return;
    }

    argument_count -= 2;
  }

  if (argument_count > 1 || (detailed && argument_count != 1) ||
      (argument_count == 1 && string_is_empty(arguments[0])))
  {
    _config_send_syntax(source);
    return;
  }

  char selector[IRCD_BUFSIZE];
  if (argument_count)
  {
    if (detailed)
    {
      if (!block->normalize_selector(arguments[0], selector, sizeof(selector)))
      {
        sendto_one_notice(source, &me, ":Invalid %s selector.", block->name);
        return;
      }

      query.selector = selector;
    }
    else
      query.selector = arguments[0];
  }

  _config_cmd_block(source, &query);
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
