/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file conf.c
 * \brief Configuration file functions.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd_defs.h"
#include "conf.h"
#include "conf_pseudo.h"
#include "server.h"
#include "resv.h"
#include "channel.h"
#include "client.h"
#include "event.h"
#include "irc_string.h"
#include "s_bsd.h"
#include "ircd.h"
#include "listener.h"
#include "hostmask.h"
#include "modules.h"
#include "numeric.h"
#include "fdlist.h"
#include "log.h"
#include "send.h"
#include "memory.h"
#include "res.h"
#include "userhost.h"
#include "user.h"
#include "channel_mode.h"
#include "parse.h"
#include "misc.h"
#include "conf_db.h"
#include "conf_class.h"
#include "motd.h"
#include "ipcache.h"


struct config_channel_entry ConfigChannel;
struct config_serverhide_entry ConfigServerHide;
struct config_general_entry ConfigGeneral;
struct config_log_entry ConfigLog = { .use_logging = 1 };
struct config_serverinfo_entry ConfigServerInfo;
struct config_admin_entry ConfigAdminInfo;
struct conf_parser_context conf_parser_ctx;

/* general conf items link list root, other than k lines etc. */
dlink_list service_items;
dlink_list server_items;
dlink_list cluster_items;
dlink_list oconf_items;
dlink_list uconf_items;
dlink_list xconf_items;
dlink_list nresv_items;
dlink_list cresv_items;

extern unsigned int lineno;
extern char linebuf[];
extern char conffilebuf[IRCD_BUFSIZE];
extern int yyparse(); /* defined in y.tab.c */


/* conf_dns_callback()
 *
 * inputs	- pointer to struct MaskItem
 *		- pointer to DNSReply reply
 * output	- none
 * side effects	- called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * if successful save hp in the conf item it was called with
 */
static void
conf_dns_callback(void *vptr, const struct irc_ssaddr *addr, const char *name, size_t namelength)
{
  struct MaskItem *const conf = vptr;

  conf->dns_pending = 0;

  if (addr)
    memcpy(&conf->addr, addr, sizeof(conf->addr));
  else
    conf->dns_failed = 1;
}

/* conf_dns_lookup()
 *
 * do a nameserver lookup of the conf host
 * if the conf entry is currently doing a ns lookup do nothing, otherwise
 * allocate a dns_query and start ns lookup.
 */
static void
conf_dns_lookup(struct MaskItem *conf)
{
  if (conf->dns_pending)
    return;

  conf->dns_pending = 1;

  if (conf->aftype == AF_INET)
    gethost_byname_type(conf_dns_callback, conf, conf->host, T_A);
  else
    gethost_byname_type(conf_dns_callback, conf, conf->host, T_AAAA);
}

/* map_to_list()
 *
 * inputs       - ConfType conf
 * output       - pointer to dlink_list to use
 * side effects - none
 */
static dlink_list *
map_to_list(enum maskitem_type type)
{
  switch (type)
  {
    case CONF_XLINE:
      return &xconf_items;
      break;
    case CONF_ULINE:
      return &uconf_items;
      break;
    case CONF_NRESV:
      return &nresv_items;
      break;
    case CONF_CRESV:
      return &cresv_items;
      break;
    case CONF_OPER:
      return &oconf_items;
      break;
    case CONF_SERVER:
      return &server_items;
      break;
    case CONF_SERVICE:
      return &service_items;
      break;
    case CONF_CLUSTER:
      return &cluster_items;
      break;
    default:
      return NULL;
  }
}

struct MaskItem *
conf_make(enum maskitem_type type)
{
  struct MaskItem *const conf = MyCalloc(sizeof(*conf));
  dlink_list *list = NULL;

  conf->type   = type;
  conf->active = 1;
  conf->aftype = AF_INET;

  if ((list = map_to_list(type)))
    dlinkAdd(conf, &conf->node, list);
  return conf;
}

void
conf_free(struct MaskItem *conf)
{
  dlink_node *node = NULL, *node_next = NULL;
  dlink_list *list = NULL;

  if ((list = map_to_list(conf->type)))
    dlinkFindDelete(list, conf);

  MyFree(conf->name);

  if (conf->dns_pending)
    delete_resolver_queries(conf);
  if (conf->passwd)
    memset(conf->passwd, 0, strlen(conf->passwd));
  if (conf->spasswd)
    memset(conf->spasswd, 0, strlen(conf->spasswd));

  conf->class = NULL;

  MyFree(conf->passwd);
  MyFree(conf->spasswd);
  MyFree(conf->reason);
  MyFree(conf->certfp);
  MyFree(conf->whois);
  MyFree(conf->user);
  MyFree(conf->host);
#ifdef HAVE_LIBCRYPTO
  MyFree(conf->cipher_list);

  if (conf->rsa_public_key)
    RSA_free(conf->rsa_public_key);
#endif
  DLINK_FOREACH_SAFE(node, node_next, conf->hub_list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &conf->hub_list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, conf->leaf_list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &conf->leaf_list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, conf->exempt_list.head)
  {
    struct exempt *exptr = node->data;

    dlinkDelete(node, &conf->exempt_list);
    MyFree(exptr->name);
    MyFree(exptr->user);
    MyFree(exptr->host);
    MyFree(exptr);
  }

  MyFree(conf);
}

/* attach_iline()
 *
 * inputs       - client pointer
 *              - conf pointer
 * output       -
 * side effects - do actual attach
 */
static int
attach_iline(struct Client *client_p, struct MaskItem *conf)
{
  const struct ClassItem *const class = conf->class;
  struct ip_entry *ip_found;
  int a_limit_reached = 0;
  unsigned int local = 0, global = 0, ident = 0;

  ip_found = ipcache_find_or_add_address(&client_p->connection->ip);
  ip_found->count++;
  AddFlag(client_p, FLAGS_IPHASH);

  count_user_host(client_p->username, client_p->host,
                  &global, &local, &ident);

  /* XXX blah. go down checking the various silly limits
   * setting a_limit_reached if any limit is reached.
   * - Dianora
   */
  if (class->max_total && class->ref_count >= class->max_total)
    a_limit_reached = 1;
  else if (class->max_perip && ip_found->count > class->max_perip)
    a_limit_reached = 1;
  else if (class->max_local && local >= class->max_local)
    a_limit_reached = 1;
  else if (class->max_global && global >= class->max_global)
    a_limit_reached = 1;
  else if (class->max_ident && ident >= class->max_ident &&
           client_p->username[0] != '~')
    a_limit_reached = 1;

  if (a_limit_reached)
  {
    if (!IsConfExemptLimits(conf))
      return TOO_MANY;   /* Already at maximum allowed */

    sendto_one_notice(client_p, &me, ":*** Your connection class is full, "
                      "but you have exceed_limit = yes;");
  }

  return attach_conf(client_p, conf);
}

/* verify_access()
 *
 * inputs       - pointer to client to verify
 * output       - 0 if success -'ve if not
 * side effect  - find the first (best) I line to attach.
 */
static int
verify_access(struct Client *client_p)
{
  struct MaskItem *conf = NULL;

  if (IsGotId(client_p))
  {
    conf = find_address_conf(client_p->host, client_p->username,
                             &client_p->connection->ip,
                             client_p->connection->aftype,
                             client_p->connection->password);
  }
  else
  {
    char non_ident[USERLEN + 1] = "~";

    strlcpy(non_ident + 1, client_p->username, sizeof(non_ident) - 1);
    conf = find_address_conf(client_p->host, non_ident,
                             &client_p->connection->ip,
                             client_p->connection->aftype,
                             client_p->connection->password);
  }

  if (!conf)
    return NOT_AUTHORIZED;

  assert(IsConfClient(conf) || IsConfKill(conf));

  if (IsConfClient(conf))
  {
    if (IsConfRedir(conf))
    {
      sendto_one_numeric(client_p, &me, RPL_REDIR,
                         conf->name ? conf->name : "",
                         conf->port);
      return NOT_AUTHORIZED;
    }

    if (IsConfDoSpoofIp(conf))
    {
      if (IsConfSpoofNotice(conf))
        sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE, "%s spoofing: %s as %s",
                             client_p->name, client_p->host, conf->name);

      strlcpy(client_p->host, conf->name, sizeof(client_p->host));
    }

    return attach_iline(client_p, conf);
  }

  sendto_one_notice(client_p, &me, ":*** Banned: %s", conf->reason);
  return BANNED_CLIENT;
}

/* check_client()
 *
 * inputs	- pointer to client
 * output	- 0 = Success
 * 		  NOT_AUTHORIZED    (-1) = Access denied (no I line match)
 * 		  IRCD_SOCKET_ERROR (-2) = Bad socket.
 * 		  I_LINE_FULL       (-3) = I-line is full
 *		  TOO_MANY          (-4) = Too many connections from hostname
 * 		  BANNED_CLIENT     (-5) = K-lined
 * side effects - Ordinary client access check.
 *		  Look for conf lines which have the same
 * 		  status as the flags passed.
 */
int
check_client(struct Client *source_p)
{
  int i;

  if ((i = verify_access(source_p)))
    ilog(LOG_TYPE_IRCD, "Access denied: %s[%s]",
         source_p->name, source_p->sockhost);

  switch (i)
  {
    case TOO_MANY:
      sendto_realops_flags(UMODE_FULL, L_ALL, SEND_NOTICE,
                           "Too many on IP for %s (%s).",
                           get_client_name(source_p, SHOW_IP),
                           source_p->sockhost);
      ilog(LOG_TYPE_IRCD, "Too many connections on IP from %s.",
           get_client_name(source_p, SHOW_IP));
      ++ServerStats.is_ref;
      exit_client(source_p, "No more connections allowed on that IP");
      break;

    case I_LINE_FULL:
      sendto_realops_flags(UMODE_FULL, L_ALL, SEND_NOTICE,
                           "auth {} block is full for %s (%s).",
                           get_client_name(source_p, SHOW_IP),
                           source_p->sockhost);
      ilog(LOG_TYPE_IRCD, "Too many connections from %s.",
           get_client_name(source_p, SHOW_IP));
      ++ServerStats.is_ref;
      exit_client(source_p, "No more connections allowed in your connection class");
      break;

    case NOT_AUTHORIZED:
      /* jdc - lists server name & port connections are on */
      /*       a purely cosmetical change */
      sendto_realops_flags(UMODE_UNAUTH, L_ALL, SEND_NOTICE,
                           "Unauthorized client connection from %s [%s] on [%s/%u].",
                           get_client_name(source_p, SHOW_IP),
                           source_p->sockhost,
                           source_p->connection->listener->name,
                           source_p->connection->listener->port);
      ilog(LOG_TYPE_IRCD, "Unauthorized client connection from %s on [%s/%u].",
           get_client_name(source_p, SHOW_IP),
           source_p->connection->listener->name,
           source_p->connection->listener->port);

      ++ServerStats.is_ref;
      exit_client(source_p, "You are not authorized to use this server");
      break;

    case BANNED_CLIENT:
      ++ServerStats.is_ref;
      exit_client(source_p, "Banned");
      break;

    case 0:
    default:
      break;
  }

  return !(i < 0);
}

/* detach_conf()
 *
 * inputs	- pointer to client to detach
 *		- type of conf to detach
 * output	- 0 for success, -1 for failure
 * side effects	- Disassociate configuration from the client.
 *		  Also removes a class from the list if marked for deleting.
 */
void
detach_conf(struct Client *client_p, enum maskitem_type type)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, client_p->connection->confs.head)
  {
    struct MaskItem *conf = node->data;

    assert(conf->type & (CONF_CLIENT | CONF_OPER | CONF_SERVER));
    assert(conf->ref_count > 0);
    assert(conf->class->ref_count > 0);

    if (!(conf->type & type))
      continue;

    dlinkDelete(node, &client_p->connection->confs);
    free_dlink_node(node);

    if (conf->type == CONF_CLIENT)
      remove_from_cidr_check(&client_p->connection->ip, conf->class);

    if (--conf->class->ref_count == 0 && conf->class->active == 0)
    {
      class_free(conf->class);
      conf->class = NULL;
    }

    if (--conf->ref_count == 0 && conf->active == 0)
      conf_free(conf);
  }
}

/* attach_conf()
 *
 * inputs	- client pointer
 * 		- conf pointer
 * output	-
 * side effects - Associate a specific configuration entry to a *local*
 *                client (this is the one which used in accepting the
 *                connection). Note, that this automatically changes the
 *                attachment if there was an old one...
 */
int
attach_conf(struct Client *client_p, struct MaskItem *conf)
{
  if (dlinkFind(&client_p->connection->confs, conf))
    return 1;

  if (conf->type == CONF_CLIENT)
    if (cidr_limit_reached(IsConfExemptLimits(conf),
                           &client_p->connection->ip, conf->class))
      return TOO_MANY;    /* Already at maximum allowed */

  conf->class->ref_count++;
  conf->ref_count++;

  dlinkAdd(conf, make_dlink_node(), &client_p->connection->confs);

  return 0;
}

/* attach_connect_block()
 *
 * inputs	- pointer to server to attach
 * 		- name of server
 *		- hostname of server
 * output	- true (1) if both are found, otherwise return false (0)
 * side effects - find connect block and attach them to connecting client
 */
int
attach_connect_block(struct Client *client_p, const char *name,
                     const char *host)
{
  dlink_node *node = NULL;

  assert(host);

  DLINK_FOREACH(node, server_items.head)
  {
    struct MaskItem *conf = node->data;

    if (match(conf->name, name) || match(conf->host, host))
      continue;

    attach_conf(client_p, conf);
    return 1;
  }

  return 0;
}

/* find_conf_name()
 *
 * inputs	- pointer to conf link list to search
 *		- pointer to name to find
 *		- int mask of type of conf to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the name
 *		  and has the given mask.
 */
struct MaskItem *
find_conf_name(dlink_list *list, const char *name, enum maskitem_type type)
{
  dlink_node *node = NULL;

  DLINK_FOREACH(node, list->head)
  {
    struct MaskItem *conf = node->data;

    if (conf->type == type)
    {
      if (conf->name && !irccmp(conf->name, name))
        return conf;
    }
  }

  return NULL;
}

/* find_matching_name_conf()
 *
 * inputs       - type of link list to look in
 *		- pointer to name string to find
 *		- pointer to user
 *		- pointer to host
 *		- optional flags to match on as well
 * output       - NULL or pointer to found struct MaskItem
 * side effects - looks for a match on name field
 */
struct MaskItem *
find_matching_name_conf(enum maskitem_type type, const char *name, const char *user,
                        const char *host, unsigned int flags)
{
  dlink_node *node = NULL;
  dlink_list *list = map_to_list(type);
  struct MaskItem *conf = NULL;

  switch (type)
  {
  case CONF_SERVICE:
    DLINK_FOREACH(node, list->head)
    {
      conf = node->data;

      if (EmptyString(conf->name))
        continue;
      if (name && !irccmp(name, conf->name))
        return conf;
    }
    break;

  case CONF_XLINE:
  case CONF_ULINE:
  case CONF_NRESV:
  case CONF_CRESV:
    DLINK_FOREACH(node, list->head)
    {
      conf = node->data;

      if (EmptyString(conf->name))
        continue;
      if (name && !match(conf->name, name))
      {
        if ((user == NULL && (host == NULL)))
          return conf;
        if ((conf->flags & flags) != flags)
          continue;
        if (EmptyString(conf->user) || EmptyString(conf->host))
          return conf;
        if (!match(conf->user, user) && !match(conf->host, host))
          return conf;
      }
    }
      break;

  case CONF_SERVER:
    DLINK_FOREACH(node, list->head)
    {
      conf = node->data;

      if (name && !match(name, conf->name))
        return conf;
      if (host && !match(host, conf->host))
        return conf;
    }
    break;

  default:
    break;
  }
  return NULL;
}

/* find_exact_name_conf()
 *
 * inputs       - type of link list to look in
 *		- pointer to name string to find
 *		- pointer to user
 *		- pointer to host
 * output       - NULL or pointer to found struct MaskItem
 * side effects - looks for an exact match on name field
 */
struct MaskItem *
find_exact_name_conf(enum maskitem_type type, const struct Client *who, const char *name,
                     const char *user, const char *host)
{
  dlink_node *node = NULL;
  dlink_list *list = map_to_list(type);
  struct MaskItem *conf = NULL;

  switch(type)
  {
  case CONF_XLINE:
  case CONF_ULINE:
  case CONF_NRESV:
  case CONF_CRESV:

    DLINK_FOREACH(node, list->head)
    {
      conf = node->data;

      if (EmptyString(conf->name))
        continue;

      if (irccmp(conf->name, name) == 0)
      {
        if ((user == NULL && (host == NULL)))
          return conf;
        if (EmptyString(conf->user) || EmptyString(conf->host))
          return conf;
        if (!match(conf->user, user) && !match(conf->host, host))
          return conf;
      }
    }
    break;

  case CONF_OPER:
    DLINK_FOREACH(node, list->head)
    {
      conf = node->data;

      if (EmptyString(conf->name))
        continue;

      if (!irccmp(conf->name, name))
      {
        if (!who)
          return conf;
        if (EmptyString(conf->user) || EmptyString(conf->host))
          return NULL;
        if (!match(conf->user, who->username))
        {
          switch (conf->htype)
          {
            case HM_HOST:
              if (!match(conf->host, who->host) || !match(conf->host, who->sockhost))
                if (!conf->class->max_total || conf->class->ref_count < conf->class->max_total)
                  return conf;
              break;
            case HM_IPV4:
              if (who->connection->aftype == AF_INET)
                if (match_ipv4(&who->connection->ip, &conf->addr, conf->bits))
                  if (!conf->class->max_total || conf->class->ref_count < conf->class->max_total)
                    return conf;
              break;
            case HM_IPV6:
              if (who->connection->aftype == AF_INET6)
                if (match_ipv6(&who->connection->ip, &conf->addr, conf->bits))
                  if (!conf->class->max_total || conf->class->ref_count < conf->class->max_total)
                    return conf;
              break;
            default:
              assert(0);
          }
        }
      }
    }

    break;

  case CONF_SERVER:
    DLINK_FOREACH(node, list->head)
    {
      conf = node->data;

      if (EmptyString(conf->name))
        continue;

      if (name == NULL)
      {
        if (EmptyString(conf->host))
          continue;
        if (irccmp(conf->host, host) == 0)
          return conf;
      }
      else if (irccmp(conf->name, name) == 0)
        return conf;
    }

    break;

  default:
    break;
  }

  return NULL;
}

/* set_default_conf()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- Set default values here.
 *		  This is called **PRIOR** to parsing the
 *		  configuration file.  If you want to do some validation
 *		  of values later, put them in validate_conf().
 */
static void
set_default_conf(void)
{
  /* verify init_class() ran, this should be an unnecessary check
   * but its not much work.
   */
  assert(class_default == class_get_list()->tail->data);

#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  {
    EC_KEY *key = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);

    if (key)
    {
      SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
      EC_KEY_free(key);
    }
  }

  SSL_CTX_set_options(ConfigServerInfo.server_ctx, SSL_OP_SINGLE_ECDH_USE);
#endif

  SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, "EECDH+HIGH:EDH+HIGH:HIGH:!aNULL");
  ConfigServerInfo.message_digest_algorithm = EVP_sha256();
  ConfigServerInfo.rsa_private_key = NULL;
  ConfigServerInfo.rsa_private_key_file = NULL;
#endif

  /* ConfigServerInfo.name is not rehashable */
  /* ConfigServerInfo.name = ConfigServerInfo.name; */
  ConfigServerInfo.description = NULL;
  ConfigServerInfo.network_name = xstrdup(NETWORK_NAME_DEFAULT);
  ConfigServerInfo.network_desc = xstrdup(NETWORK_DESC_DEFAULT);

  memset(&ConfigServerInfo.ip, 0, sizeof(ConfigServerInfo.ip));
  ConfigServerInfo.specific_ipv4_vhost = 0;
  memset(&ConfigServerInfo.ip6, 0, sizeof(ConfigServerInfo.ip6));
  ConfigServerInfo.specific_ipv6_vhost = 0;

  ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  ConfigServerInfo.max_nick_length = 9;
  ConfigServerInfo.max_topic_length = 80;
  ConfigServerInfo.hub = 0;

  ConfigAdminInfo.name = NULL;
  ConfigAdminInfo.email = NULL;
  ConfigAdminInfo.description = NULL;

  log_del_all();

  ConfigLog.use_logging = 1;

  ConfigChannel.disable_fake_channels = 0;
  ConfigChannel.invite_client_count = 10;
  ConfigChannel.invite_client_time = 300;
  ConfigChannel.knock_client_count = 1;
  ConfigChannel.knock_client_time = 300;
  ConfigChannel.knock_delay_channel = 60;
  ConfigChannel.max_channels = 25;
  ConfigChannel.max_bans = 25;
  ConfigChannel.default_join_flood_count = 18;
  ConfigChannel.default_join_flood_time = 6;
  ConfigChannel.default_split_user_count = 0;
  ConfigChannel.default_split_server_count = 0;
  ConfigChannel.no_join_on_split = 0;
  ConfigChannel.no_create_on_split = 0;

  ConfigServerHide.flatten_links = 0;
  ConfigServerHide.links_delay = 300;
  ConfigServerHide.hidden = 0;
  ConfigServerHide.hide_servers = 0;
  ConfigServerHide.hide_services = 0;
  ConfigServerHide.hidden_name = xstrdup(NETWORK_NAME_DEFAULT);
  ConfigServerHide.hide_server_ips = 0;
  ConfigServerHide.disable_remote_commands = 0;

  ConfigGeneral.away_count = 2;
  ConfigGeneral.away_time = 10;
  ConfigGeneral.max_watch = WATCHSIZE_DEFAULT;
  ConfigGeneral.cycle_on_host_change = 1;
  ConfigGeneral.dline_min_cidr = 16;
  ConfigGeneral.dline_min_cidr6 = 48;
  ConfigGeneral.kline_min_cidr = 16;
  ConfigGeneral.kline_min_cidr6 = 48;
  ConfigGeneral.invisible_on_connect = 1;
  ConfigGeneral.tkline_expire_notices = 1;
  ConfigGeneral.ignore_bogus_ts = 0;
  ConfigGeneral.disable_auth = 0;
  ConfigGeneral.kill_chase_time_limit = 90;
  ConfigGeneral.default_floodcount = 8;
  ConfigGeneral.failed_oper_notice = 1;
  ConfigGeneral.dots_in_ident = 0;
  ConfigGeneral.min_nonwildcard = 4;
  ConfigGeneral.min_nonwildcard_simple = 3;
  ConfigGeneral.max_accept = 20;
  ConfigGeneral.anti_nick_flood = 0;
  ConfigGeneral.max_nick_time = 20;
  ConfigGeneral.max_nick_changes = 5;
  ConfigGeneral.anti_spam_exit_message_time = 0;
  ConfigGeneral.ts_warn_delta = TS_WARN_DELTA_DEFAULT;
  ConfigGeneral.ts_max_delta = TS_MAX_DELTA_DEFAULT;
  ConfigGeneral.warn_no_connect_block = 1;
  ConfigGeneral.stats_e_disabled = 0;
  ConfigGeneral.stats_i_oper_only = 1;  /* 1 = masked */
  ConfigGeneral.stats_k_oper_only = 1;  /* 1 = masked */
  ConfigGeneral.stats_o_oper_only = 1;
  ConfigGeneral.stats_m_oper_only = 1;
  ConfigGeneral.stats_P_oper_only = 0;
  ConfigGeneral.stats_u_oper_only = 0;
  ConfigGeneral.caller_id_wait = 60;
  ConfigGeneral.opers_bypass_callerid = 0;
  ConfigGeneral.pace_wait = 10;
  ConfigGeneral.pace_wait_simple = 1;
  ConfigGeneral.short_motd = 0;
  ConfigGeneral.ping_cookie = 0;
  ConfigGeneral.no_oper_flood = 0;
  ConfigGeneral.oper_pass_resv = 1;
  ConfigGeneral.max_targets = MAX_TARGETS_DEFAULT;
  ConfigGeneral.oper_only_umodes = UMODE_DEBUG | UMODE_LOCOPS | UMODE_HIDDEN | UMODE_FARCONNECT |
                                   UMODE_UNAUTH | UMODE_EXTERNAL | UMODE_BOTS | UMODE_NCHANGE |
                                   UMODE_SPY | UMODE_FULL | UMODE_SKILL | UMODE_REJ | UMODE_CCONN;
  ConfigGeneral.oper_umodes = UMODE_BOTS | UMODE_LOCOPS | UMODE_SERVNOTICE | UMODE_WALLOP;
  ConfigGeneral.throttle_count = 1;
  ConfigGeneral.throttle_time = 1;
}

static void
validate_conf(void)
{
  if (ConfigGeneral.ts_warn_delta < TS_WARN_DELTA_MIN)
    ConfigGeneral.ts_warn_delta = TS_WARN_DELTA_DEFAULT;

  if (ConfigGeneral.ts_max_delta < TS_MAX_DELTA_MIN)
    ConfigGeneral.ts_max_delta = TS_MAX_DELTA_DEFAULT;

  if (EmptyString(ConfigServerInfo.network_name))
    ConfigServerInfo.network_name = xstrdup(NETWORK_NAME_DEFAULT);

  if (EmptyString(ConfigServerInfo.network_desc))
    ConfigServerInfo.network_desc = xstrdup(NETWORK_DESC_DEFAULT);

  ConfigGeneral.max_watch = IRCD_MAX(ConfigGeneral.max_watch, WATCHSIZE_MIN);
}

/* read_conf()
 *
 * inputs       - file descriptor pointing to config file to use
 * output       - None
 * side effects	- Read configuration file.
 */
static void
read_conf(FILE *file)
{
  lineno = 0;

  set_default_conf();  /* Set default values prior to conf parsing */
  conf_parser_ctx.pass = 1;
  yyparse();  /* Pick up the classes first */

  rewind(file);

  conf_parser_ctx.pass = 2;
  yyparse();  /* Load the values from the conf */
  validate_conf();  /* Check to make sure some values are still okay. */
                    /* Some global values are also loaded here. */
  class_delete_marked();  /* Delete unused classes that are marked for deletion */
}

/* conf_rehash()
 *
 * Actual REHASH service routine. Called with sig == 0 if it has been called
 * as a result of an operator issuing this command, else assume it has been
 * called as a result of the server receiving a HUP signal.
 */
void
conf_rehash(int sig)
{
  if (sig)
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Got signal SIGHUP, reloading configuration file(s)");

  restart_resolver();

  /* don't close listeners until we know we can go ahead with the rehash */

  read_conf_files(0);

  load_conf_modules();
  check_conf_klines();
}

/* lookup_confhost()
 *
 * start DNS lookups of all hostnames in the conf
 * line and convert an IP addresses in a.b.c.d number for to IP#s.
 */
void
lookup_confhost(struct MaskItem *conf)
{
  struct addrinfo hints, *res;

  /*
   * Do name lookup now on hostnames given and store the
   * ip numbers in conf structure.
   */
  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* Get us ready for a bind() and don't bother doing dns lookup */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(conf->host, NULL, &hints, &res))
  {
    conf_dns_lookup(conf);
    return;
  }

  assert(res);

  memcpy(&conf->addr, res->ai_addr, res->ai_addrlen);
  conf->addr.ss_len = res->ai_addrlen;
  conf->addr.ss.ss_family = res->ai_family;

  freeaddrinfo(res);
}

/* conf_connect_allowed()
 *
 * inputs	- pointer to inaddr
 *		- int type ipv4 or ipv6
 * output	- BANNED or accepted
 * side effects	- none
 */
int
conf_connect_allowed(struct irc_ssaddr *addr, int aftype)
{
  struct ip_entry *ip_found = NULL;
  struct MaskItem *const conf = find_dline_conf(addr, aftype);

  /* DLINE exempt also gets you out of static limits/pacing... */
  if (conf && (conf->type == CONF_EXEMPT))
    return 0;

  if (conf)
    return BANNED_CLIENT;

  ip_found = ipcache_find_or_add_address(addr);

  if ((CurrentTime - ip_found->last_attempt) < ConfigGeneral.throttle_time)
  {
    if (ip_found->connection_count >= ConfigGeneral.throttle_count)
      return TOO_FAST;

    ++ip_found->connection_count;
  }
  else
    ip_found->connection_count = 1;

  ip_found->last_attempt = CurrentTime;
  return 0;
}

/* expire_tklines()
 *
 * inputs       - tkline list pointer
 * output       - NONE
 * side effects - expire tklines
 */
static void
expire_tklines(dlink_list *list)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, list->head)
  {
    struct MaskItem *conf = node->data;

    if (!conf->until || conf->until > CurrentTime)
      continue;

    if (conf->type == CONF_XLINE)
    {
      if (ConfigGeneral.tkline_expire_notices)
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "Temporary X-line for [%s] expired", conf->name);
      conf_free(conf);
    }
    else if (conf->type == CONF_NRESV || conf->type == CONF_CRESV)
    {
      if (ConfigGeneral.tkline_expire_notices)
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "Temporary RESV for [%s] expired", conf->name);
      conf_free(conf);
    }
  }
}

/* cleanup_tklines()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - call function to expire temporary k/d lines
 *                This is an event started off in ircd.c
 */
void
cleanup_tklines(void *unused)
{
  hostmask_expire_temporary();
  expire_tklines(&xconf_items);
  expire_tklines(&nresv_items);
  expire_tklines(&cresv_items);
}

/* oper_privs_as_string()
 *
 * inputs        - pointer to client_p
 * output        - pointer to static string showing oper privs
 * side effects  - return as string, the oper privs as derived from port
 */
static const struct oper_privs
{
  const unsigned int flag;
  const unsigned char c;
} flag_list[] = {
  { OPER_FLAG_ADMIN,          'A' },
  { OPER_FLAG_REMOTEBAN,      'B' },
  { OPER_FLAG_DIE,            'D' },
  { OPER_FLAG_REHASH,         'H' },
  { OPER_FLAG_KLINE,          'K' },
  { OPER_FLAG_KILL,           'N' },
  { OPER_FLAG_KILL_REMOTE,    'O' },
  { OPER_FLAG_CONNECT,        'P' },
  { OPER_FLAG_CONNECT_REMOTE, 'Q' },
  { OPER_FLAG_SQUIT,          'R' },
  { OPER_FLAG_SQUIT_REMOTE,   'S' },
  { OPER_FLAG_UNKLINE,        'U' },
  { OPER_FLAG_XLINE,          'X' },
  { 0, '\0' }
};

const char *
oper_privs_as_string(const unsigned int port)
{
  static char privs_out[IRCD_BUFSIZE];
  char *privs_ptr = privs_out;

  for (const struct oper_privs *opriv = flag_list; opriv->flag; ++opriv)
  {
    if (port & opriv->flag)
      *privs_ptr++ = opriv->c;
    else
      *privs_ptr++ = ToLower(opriv->c);
  }

  *privs_ptr = '\0';

  return privs_out;
}

/*
 * Input: A client to find the active operator {} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
const char *
get_oper_name(const struct Client *client_p)
{
  static char buffer[IRCD_BUFSIZE];

  if (IsServer(client_p))
    return client_p->name;

  if (MyConnect(client_p))
  {
    const dlink_node *const node = client_p->connection->confs.head;

    if (node)
    {
      const struct MaskItem *const conf = node->data;

      if (conf->type == CONF_OPER)
      {
        snprintf(buffer, sizeof(buffer), "%s!%s@%s{%s}", client_p->name,
                 client_p->username, client_p->host, conf->name);
        return buffer;
      }
    }

    /*
     * Probably should assert here for now. If there is an oper out there
     * with no operator {} conf attached, it would be good for us to know...
     */
    assert(0);  /* Oper without oper conf! */
  }

  snprintf(buffer, sizeof(buffer), "%s!%s@%s{%s}", client_p->name,
           client_p->username, client_p->host, client_p->servptr->name);
  return buffer;
}

/* clear_out_old_conf()
 *
 * inputs       - none
 * output       - none
 * side effects - Clear out the old configuration
 */
static void
clear_out_old_conf(void)
{
  dlink_node *node = NULL, *node_next = NULL;
  dlink_list *free_items [] = {
    &server_items,   &oconf_items,
     &uconf_items,   &xconf_items,
     &nresv_items, &cluster_items,  &service_items, &cresv_items, NULL
  };

  dlink_list ** iterator = free_items; /* C is dumb */

  /* We only need to free anything allocated by yyparse() here.
   * Resetting structs, etc, is taken care of by set_default_conf().
   */

  for (; *iterator; iterator++)
  {
    DLINK_FOREACH_SAFE(node, node_next, (*iterator)->head)
    {
      struct MaskItem *conf = node->data;

      conf->active = 0;

      if (!IsConfDatabase(conf))
      {
        dlinkDelete(&conf->node, *iterator);

        if (!conf->ref_count)
          conf_free(conf);
      }
    }
  }

  motd_clear();

  /*
   * Don't delete the class table, rather mark all entries for deletion.
   * The table is cleaned up by class_delete_marked. - avalon
   */
  class_mark_for_deletion();

  clear_out_address_conf();

  /* Clean out module paths */
  mod_clear_paths();

  pseudo_clear();

  /* Clean out ConfigServerInfo */
  MyFree(ConfigServerInfo.description);
  ConfigServerInfo.description = NULL;
  MyFree(ConfigServerInfo.network_name);
  ConfigServerInfo.network_name = NULL;
  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = NULL;
#ifdef HAVE_LIBCRYPTO
  if (ConfigServerInfo.rsa_private_key)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;
  }

  MyFree(ConfigServerInfo.rsa_private_key_file);
  ConfigServerInfo.rsa_private_key_file = NULL;
#endif

  /* Clean out ConfigAdminInfo */
  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = NULL;
  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = NULL;
  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = NULL;

  /* Clean out listeners */
  close_listeners();
}

/* read_conf_files()
 *
 * inputs       - cold start YES or NO
 * output       - none
 * side effects - read all conf files needed, ircd.conf kline.conf etc.
 */
void
read_conf_files(int cold)
{
  const char *filename = NULL;
  char chanmodes[IRCD_BUFSIZE] = "";
  char chanlimit[IRCD_BUFSIZE] = "";

  conf_parser_ctx.boot = cold;
  filename = ConfigGeneral.configfile;

  /* We need to know the initial filename for the yyerror() to report
     FIXME: The full path is in conffilenamebuf first time since we
             don't know anything else

     - Gozem 2002-07-21
  */
  strlcpy(conffilebuf, filename, sizeof(conffilebuf));

  if ((conf_parser_ctx.conf_file = fopen(filename, "r")) == NULL)
  {
    if (cold)
    {
      ilog(LOG_TYPE_IRCD, "Unable to read configuration file '%s': %s",
           filename, strerror(errno));
      exit(-1);
    }
    else
    {
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                           "Unable to read configuration file '%s': %s",
                           filename, strerror(errno));
      return;
    }
  }

  if (!cold)
    clear_out_old_conf();

  read_conf(conf_parser_ctx.conf_file);
  fclose(conf_parser_ctx.conf_file);

  log_reopen_all();

  add_isupport("NICKLEN", NULL, ConfigServerInfo.max_nick_length);
  add_isupport("NETWORK", ConfigServerInfo.network_name, -1);

  snprintf(chanmodes, sizeof(chanmodes), "beI:%d", ConfigChannel.max_bans);
  add_isupport("MAXLIST", chanmodes, -1);
  add_isupport("MAXTARGETS", NULL, ConfigGeneral.max_targets);
  add_isupport("CHANTYPES", "#", -1);

  snprintf(chanlimit, sizeof(chanlimit), "#:%d",
           ConfigChannel.max_channels);
  add_isupport("CHANLIMIT", chanlimit, -1);
  snprintf(chanmodes, sizeof(chanmodes), "%s", "beI,k,l,cimnprstCMORS");
  add_isupport("CHANNELLEN", NULL, CHANNELLEN);
  add_isupport("TOPICLEN", NULL, ConfigServerInfo.max_topic_length);
  add_isupport("CHANMODES", chanmodes, -1);

  /*
   * message_locale may have changed.  rebuild isupport since it relies
   * on strlen(form_str(RPL_ISUPPORT))
   */
  rebuild_isupport_message_line();
}

/* conf_add_class_to_conf()
 *
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a class pointer to a conf
 */
void
conf_add_class_to_conf(struct MaskItem *conf, const char *name)
{
  if (EmptyString(name) || (conf->class = class_find(name, 1)) == NULL)
  {
    conf->class = class_default;

    if (conf->type == CONF_CLIENT || conf->type == CONF_OPER)
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                           "Warning *** Defaulting to default class for %s@%s",
                           conf->user, conf->host);
    else
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                           "Warning *** Defaulting to default class for %s",
                           conf->name);
  }
}

/* yyerror()
 *
 * inputs	- message from parser
 * output	- NONE
 * side effects	- message to opers and log file entry is made
 */
void
yyerror(const char *msg)
{
  char newlinebuf[IRCD_BUFSIZE];

  if (conf_parser_ctx.pass != 1)
    return;

  strip_tabs(newlinebuf, linebuf, sizeof(newlinebuf));
  sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                       "\"%s\", line %u: %s: %s",
                       conffilebuf, lineno + 1, msg, newlinebuf);
  ilog(LOG_TYPE_IRCD, "\"%s\", line %u: %s: %s",
       conffilebuf, lineno + 1, msg, newlinebuf);
}

void
conf_error_report(const char *msg)
{
  char newlinebuf[IRCD_BUFSIZE];

  strip_tabs(newlinebuf, linebuf, sizeof(newlinebuf));
  sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                       "\"%s\", line %u: %s: %s",
                       conffilebuf, lineno + 1, msg, newlinebuf);
  ilog(LOG_TYPE_IRCD, "\"%s\", line %u: %s: %s",
       conffilebuf, lineno + 1, msg, newlinebuf);
}

/*
 * valid_tkline()
 *
 * inputs       - pointer to ascii string to check
 *              - whether the specified time is in seconds or minutes
 * output       - -1 not enough parameters
 *              - 0 if not an integer number, else the number
 * side effects - none
 * Originally written by Dianora (Diane, db@db.net)
 */
time_t
valid_tkline(const char *data, const int minutes)
{
  const unsigned char *p = (const unsigned char *)data;
  unsigned char tmpch = '\0';
  time_t result = 0;

  while ((tmpch = *p++))
  {
    if (!IsDigit(tmpch))
      return 0;

    result *= 10;
    result += (tmpch & 0xF);
  }

  /*
   * In the degenerate case where oper does a /quote kline 0 user@host :reason
   * i.e. they specifically use 0, I am going to return 1 instead as a return
   * value of non-zero is used to flag it as a temporary kline
   */
  if (result == 0)
    result = 1;

  /*
   * If the incoming time is in seconds convert it to minutes for the purpose
   * of this calculation
   */
  if (!minutes)
    result = result / 60;

  if (result > MAX_TDKLINE_TIME)
    result = MAX_TDKLINE_TIME;

  result = result * 60;  /* Turn it into seconds */

  return result;
}

/* valid_wild_card_simple()
 *
 * inputs       - data to check for sufficient non-wildcard characters
 * outputs      - 1 if valid, else 0
 * side effects - none
 */
int
valid_wild_card_simple(const char *data)
{
  const unsigned char *p = (const unsigned char *)data;
  unsigned char tmpch = '\0';
  unsigned int nonwild = 0;

  while ((tmpch = *p++))
  {
    if (tmpch == '\\' && *p)
    {
      ++p;
      if (++nonwild >= ConfigGeneral.min_nonwildcard_simple)
        return 1;
    }
    else if (!IsMWildChar(tmpch))
    {
      if (++nonwild >= ConfigGeneral.min_nonwildcard_simple)
        return 1;
    }
  }

  return 0;
}

/* valid_wild_card()
 *
 * input        - pointer to client
 *		- int flag, 0 for no warning oper 1 for warning oper
 *		- count of following varargs to check
 * output       - 0 if not valid, 1 if valid
 * side effects - NOTICE is given to source_p if warn is 1
 */
int
valid_wild_card(struct Client *source_p, int count, ...)
{
  unsigned char tmpch = '\0';
  unsigned int nonwild = 0;
  va_list args;

  /*
   * Now we must check the user and host to make sure there
   * are at least NONWILDCHARS non-wildcard characters in
   * them, otherwise assume they are attempting to kline
   * *@* or some variant of that. This code will also catch
   * people attempting to kline *@*.tld, as long as NONWILDCHARS
   * is greater than 3. In that case, there are only 3 non-wild
   * characters (tld), so if NONWILDCHARS is 4, the kline will
   * be disallowed.
   * -wnder
   */

  va_start(args, count);

  while (count--)
  {
    const unsigned char *p = va_arg(args, const unsigned char *);
    if (p == NULL)
      continue;

    while ((tmpch = *p++))
    {
      if (!IsKWildChar(tmpch))
      {
        /*
         * If we find enough non-wild characters, we can
         * break - no point in searching further.
         */
        if (++nonwild >= ConfigGeneral.min_nonwildcard)
        {
          va_end(args);
          return 1;
        }
      }
    }
  }

  if (IsClient(source_p))
    sendto_one_notice(source_p, &me,
                      ":Please include at least %u non-wildcard characters with the mask",
                      ConfigGeneral.min_nonwildcard);
  va_end(args);
  return 0;
}

/* find_user_host()
 *
 * inputs       - pointer to client placing kline
 *              - pointer to user_host_or_nick
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output       - 0 if not ok to kline, 1 to kline i.e. if valid user host
 * side effects -
 */
static int
find_user_host(struct Client *source_p, char *user_host_or_nick,
               char *luser, char *lhost)
{
  struct Client *target_p = NULL;
  char *hostp = NULL;

  if (lhost == NULL)
  {
    strlcpy(luser, user_host_or_nick, USERLEN*4 + 1);
    return 1;
  }

  if ((hostp = strchr(user_host_or_nick, '@')) || *user_host_or_nick == '*')
  {
    /* Explicit user@host mask given */
    if (hostp)                            /* I'm a little user@host */
    {
      *(hostp++) = '\0';                       /* short and squat */

      if (*user_host_or_nick)
        strlcpy(luser, user_host_or_nick, USERLEN*4 + 1); /* here is my user */
      else
        strcpy(luser, "*");

      if (*hostp)
        strlcpy(lhost, hostp, HOSTLEN + 1);    /* here is my host */
      else
        strcpy(lhost, "*");
    }
    else
    {
      luser[0] = '*';             /* no @ found, assume its *@somehost */
      luser[1] = '\0';
      strlcpy(lhost, user_host_or_nick, HOSTLEN*4 + 1);
    }

    return 1;
  }
  else
  {
    /* Try to find user@host mask from nick */
    /* Okay to use source_p as the first param, because source_p == client_p */
    if ((target_p =
        find_chasing(source_p, user_host_or_nick)) == NULL)
      return 0;  /* find_chasing sends ERR_NOSUCHNICK */

    if (IsExemptKline(target_p))
    {
      if (IsClient(source_p))
        sendto_one_notice(source_p, &me, ":%s is E-lined", target_p->name);
      return 0;
    }

    /*
     * Turn the "user" bit into "*user", blow away '~'
     * if found in original user name (non-idented)
     */
    strlcpy(luser, target_p->username, USERLEN*4 + 1);

    if (target_p->username[0] == '~')
      luser[0] = '*';

    if (!strcmp(target_p->sockhost, "0"))
      strlcpy(lhost, target_p->host, HOSTLEN*4 + 1);
    else
      strlcpy(lhost, target_p->sockhost, HOSTLEN*4 + 1);
    return 1;
  }

  return 0;
}

/* XXX should this go into a separate file ? -Dianora */
/* parse_aline
 *
 * input        - pointer to cmd name being used
 *              - pointer to client using cmd
 *              - parc parameter count
 *              - parv[] list of parameters to parse
 *		- parse_flags bit map of things to test
 *		- pointer to user or string to parse into
 *              - pointer to host or NULL to parse into if non NULL
 *              - pointer to optional tkline time or NULL
 *              - pointer to target_server to parse into if non NULL
 *              - pointer to reason to parse into
 *
 * output       - 1 if valid, 0 if not valid
 * side effects - A generalised k/d/x etc. line parser,
 *               "ALINE [time] user@host|string [ON] target :reason"
 *                will parse returning a parsed user, host if
 *                h_p pointer is non NULL, string otherwise.
 *                if tkline_time pointer is non NULL a tk line will be set
 *                to non zero if found.
 *                if tkline_time pointer is NULL and tk line is found,
 *                error is reported.
 *                if target_server is NULL and an "ON" is found error
 *                is reported.
 *                if reason pointer is NULL ignore pointer,
 *                this allows use of parse_a_line in unkline etc.
 *
 * - Dianora
 */
int
parse_aline(const char *cmd, struct Client *source_p,
            int parc, char **parv,
            int parse_flags, char **up_p, char **h_p, time_t *tkline_time,
            char **target_server, char **reason)
{
  int found_tkline_time=0;
  static char default_reason[] = CONF_NOREASON;
  static char user[USERLEN*4+1];
  static char host[HOSTLEN*4+1];

  parv++;
  parc--;

  found_tkline_time = valid_tkline(*parv, TK_MINUTES);

  if (found_tkline_time)
  {
    parv++;
    parc--;

    if (tkline_time)
      *tkline_time = found_tkline_time;
    else
    {
      sendto_one_notice(source_p, &me, ":temp_line not supported by %s", cmd);
      return 0;
    }
  }

  if (parc == 0)
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, cmd);
    return 0;
  }

  if (h_p == NULL)
    *up_p = *parv;
  else
  {
    if (find_user_host(source_p, *parv, user, host) == 0)
      return 0;

    *up_p = user;
    *h_p = host;
  }

  parc--;
  parv++;

  if (parc)
  {
    if (irccmp(*parv, "ON") == 0)
    {
      parc--;
      parv++;

      if (target_server == NULL)
      {
        sendto_one_notice(source_p, &me, ":ON server not supported by %s", cmd);
        return 0;
      }

      if (!HasOFlag(source_p, OPER_FLAG_REMOTEBAN))
      {
        sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "remoteban");
        return 0;
      }

      if (parc == 0 || EmptyString(*parv))
      {
        sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, cmd);
        return 0;
      }

      *target_server = *parv;
      parc--;
      parv++;
    }
    else
    {
      /* Make sure target_server *is* NULL if no ON server found
       * caller probably NULL'd it first, but no harm to do it again -db
       */
      if (target_server)
        *target_server = NULL;
    }
  }

  if (h_p)
  {
    if (strchr(user, '!'))
    {
      sendto_one_notice(source_p, &me, ":Invalid character '!' in kline");
      return 0;
    }

    if ((parse_flags & AWILD) && !valid_wild_card(source_p, 2, *up_p, *h_p))
      return 0;
  }
  else
    if ((parse_flags & AWILD) && !valid_wild_card(source_p, 1, *up_p))
      return 0;

  if (reason)
  {
    if (parc && !EmptyString(*parv))
      *reason = *parv;
    else
      *reason = default_reason;
  }

  return 1;
}

/* match_conf_password()
 *
 * inputs       - pointer to given password
 *              - pointer to Conf
 * output       - 1 or 0 if match
 * side effects - none
 */
int
match_conf_password(const char *password, const struct MaskItem *conf)
{
  const char *encr = NULL;

  if (EmptyString(password) || EmptyString(conf->passwd))
    return 0;

  if (conf->flags & CONF_FLAGS_ENCRYPTED)
    encr = crypt(password, conf->passwd);
  else
    encr = password;

  return encr && !strcmp(encr, conf->passwd);
}

/*
 * cluster_a_line
 *
 * inputs	- client sending the cluster
 *		- command name "KLINE" "XLINE" etc.
 *		- capab -- CAP_KLN etc. from server.h
 *		- cluster type -- CLUSTER_KLINE etc. from conf.h
 *		- pattern and args to send along
 * output	- none
 * side effects	- Take source_p send the pattern with args given
 *		  along to all servers that match capab and cluster type
*/
void
cluster_a_line(struct Client *source_p, const char *command, unsigned int capab,
               unsigned int cluster_type, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE] = "";
  const dlink_node *node = NULL;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  DLINK_FOREACH(node, cluster_items.head)
  {
    const struct MaskItem *conf = node->data;

    if (conf->flags & cluster_type)
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER | capab,
                         "%s %s %s", command, conf->name, buffer);
  }
}

/*
 * split_nuh
 *
 * inputs	- pointer to original mask (modified in place)
 *		- pointer to pointer where nick should go
 *		- pointer to pointer where user should go
 *		- pointer to pointer where host should go
 * output	- NONE
 * side effects	- mask is modified in place
 *		  If nick pointer is NULL, ignore writing to it
 *		  this allows us to use this function elsewhere.
 *
 * mask				nick	user	host
 * ----------------------	------- ------- ------
 * Dianora!db@db.net		Dianora	db	db.net
 * Dianora			Dianora	*	*
 * db.net                       *       *       db.net
 * OR if nick pointer is NULL
 * Dianora			-	*	Dianora
 * Dianora!			Dianora	*	*
 * Dianora!@			Dianora	*	*
 * Dianora!db			Dianora	db	*
 * Dianora!@db.net		Dianora	*	db.net
 * db@db.net			*	db	db.net
 * !@				*	*	*
 * @				*	*	*
 * !				*	*	*
 */
void
split_nuh(struct split_nuh_item *const iptr)
{
  char *p = NULL, *q = NULL;

  if (iptr->nickptr)
    strlcpy(iptr->nickptr, "*", iptr->nicksize);

  if (iptr->userptr)
    strlcpy(iptr->userptr, "*", iptr->usersize);

  if (iptr->hostptr)
    strlcpy(iptr->hostptr, "*", iptr->hostsize);

  if ((p = strchr(iptr->nuhmask, '!')))
  {
    *p = '\0';

    if (iptr->nickptr && *iptr->nuhmask)
      strlcpy(iptr->nickptr, iptr->nuhmask, iptr->nicksize);

    if ((q = strchr(++p, '@')))
    {
      *q++ = '\0';

      if (*p)
        strlcpy(iptr->userptr, p, iptr->usersize);

      if (*q)
        strlcpy(iptr->hostptr, q, iptr->hostsize);
    }
    else
    {
      if (*p)
        strlcpy(iptr->userptr, p, iptr->usersize);
    }
  }
  else
  {
    /* No ! found so lets look for a user@host */
    if ((p = strchr(iptr->nuhmask, '@')))
    {
      /* if found a @ */
      *p++ = '\0';

      if (*iptr->nuhmask)
        strlcpy(iptr->userptr, iptr->nuhmask, iptr->usersize);

      if (*p)
        strlcpy(iptr->hostptr, p, iptr->hostsize);
    }
    else
    {
      /* No @ found */
      if (!iptr->nickptr || strpbrk(iptr->nuhmask, ".:"))
        strlcpy(iptr->hostptr, iptr->nuhmask, iptr->hostsize);
      else
        strlcpy(iptr->nickptr, iptr->nuhmask, iptr->nicksize);
    }
  }
}
