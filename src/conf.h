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
#include <stdint.h>
#include <stdio.h>

#include "address.h"
#include "conf_class.h"

struct Client;

enum conf_authorize_result
{
  CONF_AUTHORIZE_SUCCESS,
  CONF_AUTHORIZE_NO_AUTH_BLOCK,
  CONF_AUTHORIZE_KLINE_MATCH,
  CONF_AUTHORIZE_IDENT_REQUIRED,
  CONF_AUTHORIZE_PASSWORD_MISMATCH,
  CONF_AUTHORIZE_CLASS_TOTAL_LIMIT,
  CONF_AUTHORIZE_CLASS_LOCAL_IP_LIMIT,
  CONF_AUTHORIZE_CLASS_GLOBAL_IP_LIMIT,
  CONF_AUTHORIZE_CLASS_CIDR_LIMIT,
};

enum conf_ban_type
{
  CONF_BAN_TYPE_KLINE,
  CONF_BAN_TYPE_DLINE,
  CONF_BAN_TYPE_XLINE,
};

enum maskitem_type
{
  CONF_CLIENT = 1,
  CONF_KLINE,
  CONF_DLINE,
  CONF_EXEMPT,
};

/* MaskItem->flags */
enum
{
  CONF_FLAGS_NO_TILDE        = 1 <<  0,
  CONF_FLAGS_NEED_IDENTD     = 1 <<  1,
  CONF_FLAGS_EXEMPTKLINE     = 1 <<  2,
  CONF_FLAGS_NOLIMIT         = 1 <<  3,
  CONF_FLAGS_SPOOF_IP        = 1 <<  4,
  CONF_FLAGS_CAN_FLOOD       = 1 <<  6,
  CONF_FLAGS_NEED_PASSWORD   = 1 <<  7,
  CONF_FLAGS_ENCRYPTED       = 1 <<  9,
  CONF_FLAGS_IN_DATABASE     = 1 << 10,
  CONF_FLAGS_EXEMPTRESV      = 1 << 11,
  CONF_FLAGS_WEBIRC          = 1 << 13,
  CONF_FLAGS_EXEMPTXLINE     = 1 << 14
};

enum
{
  BANNED_CLIENT  = -4,
  TOO_FAST       = -5
};

#define CONF_NOREASON "<No reason supplied>"

/* Macros for struct MaskItem */
#define IsConfWebIRC(x)           ((x)->flags & CONF_FLAGS_WEBIRC)
#define IsNoTilde(x)              ((x)->flags & CONF_FLAGS_NO_TILDE)
#define IsConfCanFlood(x)         ((x)->flags & CONF_FLAGS_CAN_FLOOD)
#define IsNeedPassword(x)         ((x)->flags & CONF_FLAGS_NEED_PASSWORD)
#define IsNeedIdentd(x)           ((x)->flags & CONF_FLAGS_NEED_IDENTD)
#define IsConfExemptKline(x)      ((x)->flags & CONF_FLAGS_EXEMPTKLINE)
#define IsConfExemptXline(x)      ((x)->flags & CONF_FLAGS_EXEMPTXLINE)
#define IsConfExemptLimits(x)     ((x)->flags & CONF_FLAGS_NOLIMIT)
#define IsConfExemptResv(x)       ((x)->flags & CONF_FLAGS_EXEMPTRESV)
#define IsConfDoSpoofIp(x)        ((x)->flags & CONF_FLAGS_SPOOF_IP)
#define IsConfDatabase(x)         ((x)->flags & CONF_FLAGS_IN_DATABASE)
#define SetConfDatabase(x)        ((x)->flags |= CONF_FLAGS_IN_DATABASE)


#define IsConfKill(x)           ((x)->type == CONF_KLINE)
#define IsConfClient(x)         ((x)->type == CONF_CLIENT)

struct MaskItem
{
  list_node_t         node;
  enum maskitem_type type;
  unsigned int       flags;
  unsigned int       port;
  uintmax_t          until;     /* Hold action until this time (calendar time) */
  uintmax_t          setat;
  struct ClassItem  *klass;  /* Class of connection */
  char              *name;
  char              *user;     /* user part of user@host */
  char              *host;     /* host part of user@host */
  char              *passwd;
  char              *reason;
};

struct conf_parser_context
{
  unsigned int boot;
  unsigned int pass;
  FILE *conf_file;
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
  unsigned int failed_oper_notice;
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
  unsigned int stats_i_oper_only;
  unsigned int stats_k_oper_only;
  unsigned int stats_m_oper_only;
  unsigned int stats_o_oper_only;
  unsigned int stats_P_oper_only;
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
  unsigned int enable_extbans;
  unsigned int enable_owner;
  unsigned int enable_admin;
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
  char *rsa_private_key_file;
  char *tls_certificate_file;
  char *tls_dh_param_file;
  char *tls_supported_groups;
  char *tls_cipher_list;
  char *tls_cipher_suites;
  char *tls_message_digest_algorithm;
  unsigned int hub;
  unsigned int default_max_clients;
  unsigned int max_nick_length;
  unsigned int max_topic_length;
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

struct AddressRec
{
  list_node_t node;

  /* masktype: HM_HOST, HM_IPV4, HM_IPV6 -A1kmm */
  enum hostmask_type masktype;
  /* type: CONF_CLIENT, CONF_DLINE, CONF_KLINE etc... -A1kmm */
  enum maskitem_type type;

  union
  {
    struct
    {
      /* Pointer into MaskItem... -A1kmm */
      struct io_addr addr;
      int bits;
    } ipa;

    /* Pointer into MaskItem... -A1kmm */
    const char *hostname;
  } Mask;

  /* Higher precedences overrule lower ones... */
  unsigned int precedence;

  /* Only checked if !(type & 1)... */
  const char *username;
  struct MaskItem *conf;
};

extern list_t atable[ADDRESS_HASHSIZE];
extern struct conf_parser_context conf_parser_ctx;
extern struct config_log_entry ConfigLog;
extern struct config_general_entry ConfigGeneral;
extern struct config_channel_entry ConfigChannel;
extern struct config_serverhide_entry ConfigServerHide;
extern struct config_serverinfo_entry ConfigServerInfo;
extern struct config_admin_entry ConfigAdminInfo;

extern void cleanup_tklines(void *);
extern void conf_assign_class(struct MaskItem *, const char *);
extern void conf_ban_apply(struct Client *, enum conf_ban_type, const char *);
extern void conf_ban_check_clients(void);
extern void conf_error_report(const char *);
extern void conf_free(struct MaskItem *);
extern void conf_read_files(bool);
extern void conf_rehash(bool);
extern void delete_one_address_conf(const char *, struct MaskItem *);
extern void yyerror(const char *);
extern bool conf_match_password(const char *, const struct MaskItem *);
extern int conf_connect_allowed(const struct io_addr *);
extern struct AddressRec *add_conf_by_address(const unsigned int, struct MaskItem *);
extern struct MaskItem *conf_authorize_client(struct Client *, enum conf_authorize_result *, const char **);
extern struct MaskItem *conf_make(enum maskitem_type);
extern struct MaskItem *find_address_conf(const char *, const char *, const struct io_addr *, const char *);
extern struct MaskItem *find_conf_by_address(const char *, const struct io_addr *, unsigned int, const char *, const char *, int);
extern struct MaskItem *find_dline_conf(const struct io_addr *);
#endif  /* INCLUDED_conf_h */
