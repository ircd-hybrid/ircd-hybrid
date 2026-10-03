/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf.c
 * \brief Configuration file functions.
 */

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "module.h"
#include "resolver.h"

#include "client.h"
#include "client_format.h"
#include "cloak.h"
#include "conf.h"
#include "conf_auth.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_connect.h"
#include "conf_exempt.h"
#include "conf_gecos.h"
#include "conf_deny.h"
#include "conf_kill.h"
#include "conf_oper.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "defaults.h"
#include "ipcache.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "isupport.h"
#include "links_cache.h"
#include "listener.h"
#include "motd.h"
#include "numeric.h"
#include "send.h"
#include "whowas.h"

extern int yyparse();  /* Defined in conf_parser.c */

struct config_channel_entry ConfigChannel;
struct config_serverhide_entry ConfigServerHide;
struct config_general_entry ConfigGeneral;
struct config_log_entry ConfigLog = { .use_logging = 1 };
struct config_serverinfo_entry ConfigServerInfo;
struct config_admin_entry ConfigAdminInfo;
struct conf_parser_context conf_parser_ctx;

extern unsigned int conf_line_number;
extern char conf_line_text[];
extern char conf_file_name[IRCD_BUFSIZE];

static void
_conf_kill_expire_notice(const struct conf_kill *kill, void *unused)
{
  char host[IRCD_BUFSIZE];
  const bool formatted = conf_kill_format_host(kill, host, sizeof(host));
  assert(formatted);

  if (!formatted)
    return;

  sendto_clients(UMODE_EXPIRATION, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Temporary K-line for [%s@%s] expired", kill->user, host);
}

static void
_conf_deny_expire_notice(const struct conf_deny *deny, void *unused)
{
  char prefix[IRCD_BUFSIZE];
  const bool formatted = conf_deny_format_prefix(deny, prefix, sizeof(prefix));
  assert(formatted);

  if (!formatted)
    return;

  sendto_clients(UMODE_EXPIRATION, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Temporary D-line for [%s] expired", prefix);
}

static void
conf_set_defaults(void)
{
  ConfigServerInfo.network_name = io_strdup(NETWORK_NAME_DEFAULT);
  ConfigServerInfo.network_description = io_strdup(NETWORK_DESCRIPTION_DEFAULT);
  ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  ConfigServerInfo.max_nick_length = 9;
  ConfigServerInfo.max_topic_length = TOPICLEN;
  ConfigServerInfo.hub = 0;

  ConfigLog.use_logging = 1;
  log_set_enabled(ConfigLog.use_logging);

  ConfigChannel.enable_extbans = 0;
  ConfigChannel.disable_fake_channels = 0;
  ConfigChannel.invite_client_count = 10;
  ConfigChannel.invite_client_time = 300;
  ConfigChannel.invite_delay_channel = 5;
  ConfigChannel.invite_expire_time = 1800;
  ConfigChannel.knock_client_count = 1;
  ConfigChannel.knock_client_time = 300;
  ConfigChannel.knock_delay_channel = 60;
  ConfigChannel.max_channels = 25;
  ConfigChannel.max_invites = 20;
  ConfigChannel.max_bans = 100;
  ConfigChannel.max_bans_large = 500;
  ConfigChannel.max_kick_length = KICKLEN;
  ConfigChannel.default_join_flood_count = 18;
  ConfigChannel.default_join_flood_time = 6;

  ConfigServerHide.flatten_links = 0;
  ConfigServerHide.flatten_links_delay = 300;
  links_cache_set_timer(ConfigServerHide.flatten_links_delay);
  ConfigServerHide.hidden = 0;
  ConfigServerHide.hide_servers = 0;
  ConfigServerHide.hide_services = 0;
  ConfigServerHide.hidden_name = io_strdup(NETWORK_NAME_DEFAULT);
  ConfigServerHide.disable_remote_commands = 0;

  ConfigGeneral.away_count = 2;
  ConfigGeneral.away_time = 10;
  ConfigGeneral.max_monitor = 50;
  ConfigGeneral.whowas_history_length = 15000;
  ConfigGeneral.cycle_on_host_change = 1;
  ConfigGeneral.dline_min_cidr = 16;
  ConfigGeneral.dline_min_cidr6 = 48;
  ConfigGeneral.kline_min_cidr = 16;
  ConfigGeneral.kline_min_cidr6 = 48;
  ConfigGeneral.invisible_on_connect = 1;
  ConfigGeneral.disable_ident = 0;
  ConfigGeneral.disable_dns = 0;
  ConfigGeneral.kill_chase_time_limit = 90;
  ConfigGeneral.default_floodcount = 8;
  ConfigGeneral.default_floodtime = 1;
  ConfigGeneral.failed_oper_notice = 1;
  ConfigGeneral.specials_in_ident = 0;
  ConfigGeneral.min_nonwildcard = 4;
  ConfigGeneral.min_nonwildcard_simple = 3;
  ConfigGeneral.max_accept = 50;
  ConfigGeneral.max_away_length = AWAYLEN;
  ConfigGeneral.anti_nick_flood = 0;
  ConfigGeneral.max_nick_time = 20;
  ConfigGeneral.max_nick_changes = 5;
  ConfigGeneral.anti_spam_exit_message_time = 0;
  ConfigGeneral.ts_warn_delta = 30;
  ConfigGeneral.ts_max_delta = 600;
  ConfigGeneral.warn_no_connect_block = 1;
  ConfigGeneral.stats_e_disabled = 0;
  ConfigGeneral.stats_i_oper_only = 1;  /* 1 = masked */
  ConfigGeneral.stats_k_oper_only = 1;  /* 1 = masked */
  ConfigGeneral.stats_o_oper_only = 1;
  ConfigGeneral.stats_m_oper_only = 1;
  ConfigGeneral.stats_P_oper_only = 0;
  ConfigGeneral.stats_u_oper_only = 0;
  ConfigGeneral.caller_id_wait = 60;
  ConfigGeneral.opers_bypass_callerid = 1;
  ConfigGeneral.pace_wait = 10;
  ConfigGeneral.pace_wait_simple = 1;
  ConfigGeneral.short_motd = 0;
  ConfigGeneral.ping_cookie = 0;
  ConfigGeneral.no_oper_flood = 0;
  ConfigGeneral.max_targets = 4;
  ConfigGeneral.oper_umodes = io_strdup("+flsw");
  ConfigGeneral.throttle_count = 1;
  ConfigGeneral.throttle_time = 1;
  ConfigGeneral.ident_timeout = 3;
  ConfigGeneral.registration_timeout = 30;

  ConfigGeneral.cloak_enabled = false;
  cloak_set_disabled();
  ConfigGeneral.cloak_cidr_len_ipv4 = 32;
  cloak_set_cidr_len_ipv4(ConfigGeneral.cloak_cidr_len_ipv4);
  ConfigGeneral.cloak_cidr_len_ipv6 = 64;
  cloak_set_cidr_len_ipv6(ConfigGeneral.cloak_cidr_len_ipv6);
  ConfigGeneral.cloak_num_bits = 80;
  cloak_set_num_bits(ConfigGeneral.cloak_num_bits);
  ConfigGeneral.cloak_secret = io_strdup("_WPJFgJb2M9rDC3tZmPTTzvyfcWerKebmEG84bKeTdNw");
  cloak_set_secret(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_suffix = io_strdup("irc");
  cloak_set_suffix(ConfigGeneral.cloak_suffix);
}

static void
conf_validate(void)
{
  if (string_is_empty(ConfigServerInfo.network_name))
    ConfigServerInfo.network_name = io_strdup(NETWORK_NAME_DEFAULT);

  if (string_is_empty(ConfigServerInfo.network_description))
    ConfigServerInfo.network_description = io_strdup(NETWORK_DESCRIPTION_DEFAULT);
}

static void
conf_read(FILE *file)
{
  conf_line_number = 1;

  conf_set_defaults();  /* Set default values prior to conf parsing */

  conf_parser_ctx.pass = 1;
  yyparse();  /* Pick up the classes first */

  rewind(file);

  conf_parser_ctx.pass = 2;
  yyparse();  /* Load the values from the conf */

  conf_validate();  /* Check to make sure some values are still okay. */
                    /* Some global values are also loaded here. */
  whowas_trim();  /* Attempt to trim whowas list if necessary */

  connect_sweep_inactive();

  class_sweep_inactive();  /* Delete unused classes that are marked for deletion */
}

/* conf_rehash()
 *
 * Actual REHASH service routine. Called with sig == 0 if it has been called
 * as a result of an operator issuing this command, else assume it has been
 * called as a result of the server receiving a HUP signal.
 */
void
conf_rehash(bool sig)
{
  if (sig)
  {
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Got signal SIGHUP, reloading configuration file(s)");
    log_write(LOG_TYPE_IRCD, "Got signal SIGHUP, reloading configuration file(s)");
  }

  resolver_reload();

  /* don't close listeners until we know we can go ahead with the rehash */

  conf_read_files(false);

  module_load_all(NULL);

  conf_ban_check_clients();
}

int
conf_connect_allowed(const struct io_addr *addr)
{
  if (conf_exempt_find(addr))
    return 0;

  if (conf_deny_find(addr))
    return BANNED_CLIENT;

  struct ip_entry *ip_found = ipcache_record_find_or_add(addr);
  if ((io_time_get(IO_TIME_MONOTONIC_SEC) - ip_found->last_attempt) < ConfigGeneral.throttle_time)
  {
    if (ip_found->connection_count >= ConfigGeneral.throttle_count)
      return TOO_FAST;

    ++ip_found->connection_count;
  }
  else
    ip_found->connection_count = 1;

  ip_found->last_attempt = io_time_get(IO_TIME_MONOTONIC_SEC);
  return 0;
}

void
cleanup_tklines(void *unused)
{
  const uintmax_t now = io_time_get(IO_TIME_REALTIME_SEC);

  conf_deny_expire(now, _conf_deny_expire_notice, NULL);
  conf_kill_expire(now, _conf_kill_expire_notice, NULL);

  gecos_expire();
  resv_expire();
}

static void
conf_clear(void)
{
  connect_mark_all_inactive();

  /*
   * Don't delete the class table, rather mark all entries for deletion.
   * The table is cleaned up by class_delete_marked. - avalon
   */
  class_mark_all_inactive();

  conf_deny_clear_configuration();
  conf_kill_clear_configuration();
  conf_exempt_clear();
  conf_auth_clear();

  module_config_clear();  /* Clear loadmodule items */

  motd_clear();  /* Clear motd {} items and re-cache default motd */

  cluster_clear();  /* Clear cluster {} items */

  gecos_clear();  /* Clear gecos {} items */

  resv_clear();  /* Clear resv {} items */

  service_clear();  /* Clear service {} items */

  shared_clear();  /* Clear shared {} items */

  pseudo_clear();  /* Clear pseudo {} items */

  log_clear();

  oper_free_all();

  /* Clean out ConfigServerInfo */
  io_free(ConfigServerInfo.description);
  ConfigServerInfo.description = NULL;
  io_free(ConfigServerInfo.network_name);
  ConfigServerInfo.network_name = NULL;
  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = NULL;
  io_free(ConfigServerInfo.tls_private_key_file);
  ConfigServerInfo.tls_private_key_file = NULL;
  io_free(ConfigServerInfo.tls_certificate_file);
  ConfigServerInfo.tls_certificate_file = NULL;
  io_free(ConfigServerInfo.motd_file);
  ConfigServerInfo.motd_file = NULL;

  /* Clean out ConfigAdminInfo */
  io_free(ConfigAdminInfo.name);
  ConfigAdminInfo.name = NULL;
  io_free(ConfigAdminInfo.email);
  ConfigAdminInfo.email = NULL;
  io_free(ConfigAdminInfo.description);
  ConfigAdminInfo.description = NULL;

  /* Clean out ConfigServerHide */
  io_free(ConfigServerHide.flatten_links_file);
  ConfigServerHide.flatten_links_file = NULL;
  io_free(ConfigServerHide.hidden_name);
  ConfigServerHide.hidden_name = NULL;

  /* Clean out ConfigGeneral */
  io_free(ConfigGeneral.cloak_secret);
  ConfigGeneral.cloak_secret = NULL;
  io_free(ConfigGeneral.cloak_suffix);
  ConfigGeneral.cloak_suffix = NULL;
  io_free(ConfigGeneral.oper_umodes);
  ConfigGeneral.oper_umodes = NULL;

  /* Clean out listeners */
  listener_close_marked();
}

static bool
_conf_apply_tls(void)
{
  const char *const certificate_file = ConfigServerInfo.tls_certificate_file;
  const char *const private_key_file = ConfigServerInfo.tls_private_key_file;

  if (certificate_file == NULL && private_key_file == NULL)
  {
    tls_clear_config();
    return true;
  }

  if (certificate_file == NULL || private_key_file == NULL)
  {
    log_write(LOG_TYPE_IRCD,
              "TLS configuration requires both a certificate and private key");
    return false;
  }

  const tls_config_t config =
  {
    .certificate_file = certificate_file,
    .private_key_file = private_key_file
  };

  return tls_configure(&config);
}

static void
conf_handle_tls(bool cold)
{
  if (_conf_apply_tls())
    return;

  if (cold)
  {
    log_write(LOG_TYPE_IRCD, "Error while initializing TLS");
    exit(EXIT_FAILURE);
  }

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Error reloading TLS settings, check the ircd log");
}

void
conf_read_files(bool cold)
{
  conf_parser_ctx.boot = cold;
  conf_parser_ctx.conf_file = fopen(ConfigGeneral.configfile, "r");

  if (conf_parser_ctx.conf_file == NULL)
  {
    if (cold)
    {
      log_write(LOG_TYPE_IRCD, "Unable to read configuration file '%s': %s",
           ConfigGeneral.configfile, strerror(errno));
      exit(EXIT_FAILURE);
    }
    else
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                     "Unable to read configuration file '%s': %s",
                     ConfigGeneral.configfile, strerror(errno));
      return;
    }
  }

  /*
   * We need to know the initial filename for the yyerror() to report
   *
   *  FIXME: The full path is in conffilenamebuf first time since we
   *          don't know anything else
   *
   *  - Gozem 2002-07-21
   */
  strlcpy(conf_file_name, ConfigGeneral.configfile, sizeof(conf_file_name));

  if (cold == false)
    conf_clear();

  conf_read(conf_parser_ctx.conf_file);
  fclose(conf_parser_ctx.conf_file);

  conf_handle_tls(cold);

  motd_init();

  isupport_add("CASEMAPPING", "%s", "ascii");
  isupport_add("AWAYLEN", "%d", ConfigGeneral.max_away_length);
  isupport_add("KICKLEN", "%d", ConfigChannel.max_kick_length);
  isupport_add("NICKLEN", "%d", ConfigServerInfo.max_nick_length);
  isupport_add("NETWORK", "%s", ConfigServerInfo.network_name);
  isupport_add("MAXLIST", "beI:%u", ConfigChannel.max_bans);
  isupport_add("MAXTARGETS", "%d", ConfigGeneral.max_targets);
  isupport_add("CHANTYPES", "%s", "#");
  isupport_add("CHANLIMIT", "#:%u", ConfigChannel.max_channels);
  isupport_add("CHANNELLEN", "%d", CHANNELLEN);
  isupport_add("TOPICLEN", "%d", ConfigServerInfo.max_topic_length);
}

void
yyerror(const char *msg)
{
  if (conf_parser_ctx.pass != 1)
    return;

  const char *p = stripws(conf_line_text);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "\"%s\", line %u: %s: %s",
                 conf_file_name, conf_line_number, msg, p);
  log_write(LOG_TYPE_IRCD, "\"%s\", line %u: %s: %s",
            conf_file_name, conf_line_number, msg, p);
}

void
conf_error_report(const char *msg)
{
  const char *p = stripws(conf_line_text);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "\"%s\", line %u: %s: %s",
                 conf_file_name, conf_line_number, msg, p);
  log_write(LOG_TYPE_IRCD, "\"%s\", line %u: %s: %s",
            conf_file_name, conf_line_number, msg, p);
}

static const char *
_conf_ban_type_get_name(enum conf_ban_type type)
{
  switch (type)
  {
    case CONF_BAN_TYPE_KLINE:
      return "K-line";
    case CONF_BAN_TYPE_DLINE:
      return "D-line";
    case CONF_BAN_TYPE_XLINE:
      return "X-line";
  }

  assert(!"invalid conf ban type");
  return "ban";
}

static void
_conf_ban_report_active(struct Client *client, enum conf_ban_type type, const char *reason)
{
  client_format_name_buffer_t client_name_buffer;
  const char *const client_name =
    client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "%s active for %s (%s)",
                 _conf_ban_type_get_name(type), client_name, reason);
}

static void
_conf_ban_report_exempted(struct Client *client, enum conf_ban_type type, const char *exemption)
{
  client_format_name_buffer_t client_name_buffer;
  const char *const client_name =
    client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "%s exempted for %s (%s)",
                 _conf_ban_type_get_name(type), client_name, exemption);
}

void
conf_ban_apply(struct Client *client, enum conf_ban_type type, const char *reason)
{
  const char *const ban_reason = string_or_default(reason, "Banned");

  switch (type)
  {
    case CONF_BAN_TYPE_KLINE:
      if (client_has_flag(client, FLAGS_EXEMPTKLINE))
      {
        _conf_ban_report_exempted(client, type, "kline_exempt");
        return;
      }

      break;
    case CONF_BAN_TYPE_DLINE:
      if (conf_exempt_find(&client->addr))
        return;
      break;
    case CONF_BAN_TYPE_XLINE:
      if (client_has_flag(client, FLAGS_EXEMPTXLINE))
      {
        _conf_ban_report_exempted(client, type, "xline_exempt");
        return;
      }

      break;
    default:
      assert(!"invalid conf ban type");
      return;
  }

  _conf_ban_report_active(client, type, ban_reason);

  if (client_is_user(client))
    sendto_one_numeric(client, &me, ERR_YOUREBANNEDCREEP, ban_reason);

  client_exit(client, ban_reason);
}

static bool
_conf_ban_check_dline(struct Client *client)
{
  const struct conf_deny *const deny = conf_deny_find(&client->addr);
  if (deny == NULL)
    return false;

  conf_ban_apply(client, CONF_BAN_TYPE_DLINE, deny->reason);
  return true;
}

static bool
_conf_ban_check_kline(struct Client *client)
{
  const struct conf_kill *const kill =
    conf_kill_find(&client->addr, client->username, client->host);
  if (kill == NULL)
    return false;

  conf_ban_apply(client, CONF_BAN_TYPE_KLINE, kill->reason);
  return true;
}

static bool
_conf_ban_check_xline(struct Client *client)
{
  const struct GecosItem *const conf = gecos_find(client->info, match);
  if (conf == NULL)
    return false;

  conf_ban_apply(client, CONF_BAN_TYPE_XLINE, conf->reason);
  return true;
}

static void
_conf_ban_check_registered_client(struct Client *client)
{
  if (client_is_dead(client))
    return;

  if (_conf_ban_check_dline(client))
    return;

  if (_conf_ban_check_kline(client))
    return;

  _conf_ban_check_xline(client);
}

static void
_conf_ban_check_unknown_client(struct Client *client)
{
  if (client_is_dead(client))
    return;

  _conf_ban_check_dline(client);
}

void
conf_ban_check_clients(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *const client = node->data;
    _conf_ban_check_registered_client(client);
  }

  LIST_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *const client = node->data;
    _conf_ban_check_unknown_client(client);
  }
}
