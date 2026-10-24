/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file conf.h
 * \brief A header for the configuration functions.
 */

#ifndef INCLUDED_conf_h
#define INCLUDED_conf_h
#include <stdbool.h>
#include <stdio.h>

#include "module.h"

struct Client;

enum conf_ban_type
{
  CONF_BAN_TYPE_KLINE,
  CONF_BAN_TYPE_DLINE,
  CONF_BAN_TYPE_XLINE,
};

#define CONF_NOREASON "<No reason supplied>"

struct conf_parser_context
{
  unsigned int boot;
  unsigned int pass;
  FILE *conf_file;
  module_config_t *module_config;
  bool parse_valid;          /**< No parser or input errors detected during this read. */
  bool module_config_valid;  /**< No errors detected while building the module configuration. */
};

struct config_general_entry
{
  const char *dpath;
  const char *spath;
  const char *configfile;
  const char *klinefile;
  const char *xlinefile;
  const char *dlinefile;
  const char *resvfile;
  char *cloak_secret;
  char *cloak_suffix;
  char *oper_umodes;

  unsigned int dline_min_cidr;
  unsigned int dline_min_cidr6;
  unsigned int kline_min_cidr;
  unsigned int kline_min_cidr6;
  unsigned int specials_in_ident;
  unsigned int anti_spam_exit_message_time;
  unsigned int max_accept;
  unsigned int max_monitor;
  unsigned int whowas_history_length;
  unsigned int away_time;
  unsigned int away_count;
  unsigned int max_nick_time;
  unsigned int max_nick_changes;
  unsigned int ts_max_delta;
  unsigned int ts_warn_delta;
  unsigned int anti_nick_flood;
  unsigned int warn_no_connect_block;
  unsigned int invisible_on_connect;
  unsigned int stats_e_disabled;
  unsigned int stats_u_oper_only;
  unsigned int short_motd;
  unsigned int no_oper_flood;
  unsigned int opers_bypass_callerid;
  unsigned int pace_wait;
  unsigned int pace_wait_simple;
  unsigned int max_away_length;
  unsigned int max_targets;
  unsigned int caller_id_wait;
  unsigned int min_nonwildcard;
  unsigned int min_nonwildcard_simple;
  unsigned int kill_chase_time_limit;
  unsigned int default_floodcount;
  unsigned int default_floodtime;
  unsigned int throttle_count;
  unsigned int throttle_time;
  unsigned int ping_cookie;
  unsigned int disable_ident;
  unsigned int disable_dns;
  unsigned int cycle_on_host_change;
  unsigned int cloak_enabled;
  unsigned int cloak_cidr_len_ipv4;
  unsigned int cloak_cidr_len_ipv6;
  unsigned int cloak_num_bits;
  unsigned int ident_timeout;
  unsigned int registration_timeout;
};

struct config_channel_entry
{
  unsigned int disable_fake_channels;
  unsigned int invite_client_count;
  unsigned int invite_client_time;
  unsigned int invite_delay_channel;
  unsigned int invite_expire_time;
  unsigned int knock_client_count;
  unsigned int knock_client_time;
  unsigned int knock_delay_channel;
  unsigned int max_invites;
  unsigned int max_bans;
  unsigned int max_bans_large;
  unsigned int max_channels;
  unsigned int max_kick_length;
  unsigned int max_topic_length;
  unsigned int default_join_flood_count;
  unsigned int default_join_flood_time;
};

struct config_serverhide_entry
{
  char *hidden_name;
  char *flatten_links_file;
  unsigned int flatten_links;
  unsigned int flatten_links_delay;
  unsigned int disable_remote_commands;
  unsigned int hide_servers;
  unsigned int hide_services;
  unsigned int hidden;
};

struct config_serverinfo_entry
{
  char *sid;
  char *name;
  char *description;
  char *motd_file;
  char *network_name;
  char *network_description;
  char *tls_private_key_file;
  char *tls_certificate_file;
  unsigned int hub;
  unsigned int default_max_clients;
  unsigned int max_nick_length;
};

struct config_admin_entry
{
  char *name;
  char *description;
  char *email;
};

struct config_log_entry
{
  unsigned int use_logging;
};

extern struct conf_parser_context conf_parser_ctx;
extern struct config_log_entry ConfigLog;
extern struct config_general_entry ConfigGeneral;
extern struct config_channel_entry ConfigChannel;
extern struct config_serverhide_entry ConfigServerHide;
extern struct config_serverinfo_entry ConfigServerInfo;
extern struct config_admin_entry ConfigAdminInfo;

extern void cleanup_tklines(void *);
extern void conf_ban_apply(struct Client *, enum conf_ban_type, const char *);
extern void conf_ban_check_clients(void);
extern void conf_error_report(const char *);
extern void conf_lexer_init(FILE *, const char *);
extern void conf_lexer_destroy(void);
extern bool conf_read_files(bool);
extern void conf_rehash(void);
extern void yyerror(const char *);
#endif  /* INCLUDED_conf_h */
