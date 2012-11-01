/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  conf.c: Configuration file functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "ircd_defs.h"
#include "balloc.h"
#include "conf.h"
#include "s_serv.h"
#include "resv.h"
#include "channel.h"
#include "client.h"
#include "event.h"
#include "hook.h"
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
#include "s_gline.h"
#include "memory.h"
#include "irc_res.h"
#include "userhost.h"
#include "s_user.h"
#include "channel_mode.h"
#include "parse.h"
#include "s_misc.h"
#include "conf_db.h"

struct Callback *client_check_cb = NULL;
struct config_server_hide ConfigServerHide;

/* general conf items link list root, other than k lines etc. */
dlink_list service_items = { NULL, NULL, 0 };
dlink_list server_items  = { NULL, NULL, 0 };
dlink_list cluster_items = { NULL, NULL, 0 };
dlink_list oconf_items   = { NULL, NULL, 0 };
dlink_list uconf_items   = { NULL, NULL, 0 };
dlink_list xconf_items   = { NULL, NULL, 0 };
dlink_list rxconf_items  = { NULL, NULL, 0 };
dlink_list rkconf_items  = { NULL, NULL, 0 };
dlink_list nresv_items   = { NULL, NULL, 0 };
dlink_list class_items   = { NULL, NULL, 0 };

dlink_list temporary_resv = { NULL, NULL, 0 };

extern unsigned int lineno;
extern char linebuf[];
extern char conffilebuf[IRCD_BUFSIZE];
extern int yyparse(); /* defined in y.tab.c */

struct conf_parser_context conf_parser_ctx = { 0, 0, NULL };

/* internally defined functions */
static void read_conf(FILE *);
static void clear_out_old_conf(void);
static void flush_deleted_I_P(void);
static void expire_tklines(dlink_list *);
static void garbage_collect_ip_entries(void);
static int hash_ip(struct irc_ssaddr *);
static int verify_access(struct Client *, const char *);
static int attach_iline(struct Client *, struct ConfItem *);
static struct ip_entry *find_or_add_ip(struct irc_ssaddr *);
static dlink_list *map_to_list(ConfType);
static struct AccessItem *find_regexp_kline(const char *[]);
static int find_user_host(struct Client *, char *, char *, char *, unsigned int);

/*
 * bit_len
 */
static int cidr_limit_reached(int, struct irc_ssaddr *, struct ClassItem *);
static void remove_from_cidr_check(struct irc_ssaddr *, struct ClassItem *);
static void destroy_cidr_class(struct ClassItem *);

static void flags_to_ascii(unsigned int, const unsigned int[], char *, int);

/* address of default class conf */
static struct ConfItem *class_default;

/* usually, with hash tables, you use a prime number...
 * but in this case I am dealing with ip addresses,
 * not ascii strings.
 */
#define IP_HASH_SIZE 0x1000

struct ip_entry
{
  struct irc_ssaddr ip;
  int count;
  time_t last_attempt;
  struct ip_entry *next;
};

static struct ip_entry *ip_hash_table[IP_HASH_SIZE];
static BlockHeap *ip_entry_heap = NULL;
static int ip_entries_count = 0;


void *
map_to_conf(struct ConfItem *aconf)
{
  void *conf;
  conf = (void *)((uintptr_t)aconf +
		  (uintptr_t)sizeof(struct ConfItem));
  return(conf);
}

struct ConfItem *
unmap_conf_item(void *aconf)
{
  struct ConfItem *conf;

  conf = (struct ConfItem *)((uintptr_t)aconf -
			     (uintptr_t)sizeof(struct ConfItem));
  return(conf);
}

/* conf_dns_callback()
 *
 * inputs	- pointer to struct AccessItem
 *		- pointer to DNSReply reply
 * output	- none
 * side effects	- called when resolver query finishes
 * if the query resulted in a successful search, hp will contain
 * a non-null pointer, otherwise hp will be null.
 * if successful save hp in the conf item it was called with
 */
static void
conf_dns_callback(void *vptr, const struct irc_ssaddr *addr, const char *name)
{
  struct AccessItem *aconf = vptr;

  aconf->dns_pending = 0;

  if (addr != NULL)
    memcpy(&aconf->addr, addr, sizeof(aconf->addr));
  else
    aconf->dns_failed = 1;
}

/* conf_dns_lookup()
 *
 * do a nameserver lookup of the conf host
 * if the conf entry is currently doing a ns lookup do nothing, otherwise
 * allocate a dns_query and start ns lookup.
 */
static void
conf_dns_lookup(struct AccessItem *aconf)
{
  if (!aconf->dns_pending)
  {
    aconf->dns_pending = 1;
    gethost_byname(conf_dns_callback, aconf, aconf->host);
  }
}

/* make_conf_item()
 *
 * inputs	- type of item
 * output	- pointer to new conf entry
 * side effects	- none
 */
struct ConfItem *
make_conf_item(ConfType type)
{
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  struct ClassItem *aclass = NULL;
  int status = 0;

  switch (type)
  {
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case GLINE_TYPE:
  case KLINE_TYPE:
  case CLIENT_TYPE:
  case OPER_TYPE:
  case SERVER_TYPE:
    conf = MyMalloc(sizeof(struct ConfItem) +
                    sizeof(struct AccessItem));
    aconf = map_to_conf(conf);
    aconf->aftype = AF_INET;

    /* Yes, sigh. switch on type again */
    switch (type)
    {
    case EXEMPTDLINE_TYPE:
      status = CONF_EXEMPTDLINE;
      break;

    case DLINE_TYPE:
      status = CONF_DLINE;
      break;

    case KLINE_TYPE:
      status = CONF_KLINE;
      break;

    case GLINE_TYPE:
      status = CONF_GLINE;
      break;

    case CLIENT_TYPE:
      status = CONF_CLIENT;
      break;

    case OPER_TYPE:
      status = CONF_OPERATOR;
      dlinkAdd(conf, &conf->node, &oconf_items);
      break;

    case SERVER_TYPE:
      status = CONF_SERVER;
      dlinkAdd(conf, &conf->node, &server_items);
      break;

    default:
      break;
    }
    aconf->status = status;
    break;

  case ULINE_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &uconf_items);
    break;

  case XLINE_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &xconf_items);
    break;
#ifdef HAVE_LIBPCRE
  case RXLINE_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &rxconf_items);
    break;

  case RKLINE_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct AccessItem));
    aconf = map_to_conf(conf);
    aconf->status = CONF_KLINE;
    dlinkAdd(conf, &conf->node, &rkconf_items);
    break;
#endif
  case CLUSTER_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem));
    dlinkAdd(conf, &conf->node, &cluster_items);
    break;

  case CRESV_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct ResvChannel));
    break;

  case NRESV_TYPE:
    conf = (struct ConfItem *)MyMalloc(sizeof(struct ConfItem) +
                                       sizeof(struct MatchItem));
    dlinkAdd(conf, &conf->node, &nresv_items);
    break;

  case SERVICE_TYPE:
    status = CONF_SERVICE;
    conf = MyMalloc(sizeof(struct ConfItem));
    dlinkAdd(conf, &conf->node, &service_items);
    break;

  case CLASS_TYPE:
    conf = MyMalloc(sizeof(struct ConfItem) +
                           sizeof(struct ClassItem));
    dlinkAdd(conf, &conf->node, &class_items);

    aclass = map_to_conf(conf);
    aclass->active = 1;
    aclass->con_freq = DEFAULT_CONNECTFREQUENCY;
    aclass->ping_freq = DEFAULT_PINGFREQUENCY;
    aclass->max_total = MAXIMUM_LINKS_DEFAULT;
    aclass->max_sendq = DEFAULT_SENDQ;
    aclass->max_recvq = DEFAULT_RECVQ;

    break;

  default:
    conf = NULL;
    break;
  }

  /* XXX Yes, this will core if default is hit. I want it to for now - db */
  conf->type = type;

  return conf;
}

void
delete_conf_item(struct ConfItem *conf)
{
  dlink_node *m = NULL, *m_next = NULL;
  struct MatchItem *match_item;
  struct AccessItem *aconf;
  ConfType type = conf->type;

  MyFree(conf->name);
  conf->name = NULL;

  switch(type)
  {
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case GLINE_TYPE:
  case KLINE_TYPE:
  case CLIENT_TYPE:
  case OPER_TYPE:
  case SERVER_TYPE:
    aconf = map_to_conf(conf);

    if (aconf->dns_pending)
      delete_resolver_queries(aconf);
    if (aconf->passwd != NULL)
      memset(aconf->passwd, 0, strlen(aconf->passwd));
    if (aconf->spasswd != NULL)
      memset(aconf->spasswd, 0, strlen(aconf->spasswd));
    aconf->class_ptr = NULL;

    MyFree(aconf->passwd);
    MyFree(aconf->spasswd);
    MyFree(aconf->reason);
    MyFree(aconf->user);
    MyFree(aconf->host);
#ifdef HAVE_LIBCRYPTO
    MyFree(aconf->cipher_list);

    if (aconf->rsa_public_key)
      RSA_free(aconf->rsa_public_key);
    MyFree(aconf->rsa_public_key_file);
#endif

    /* Yes, sigh. switch on type again */
    switch(type)
    {
    case EXEMPTDLINE_TYPE:
    case DLINE_TYPE:
    case GLINE_TYPE:
    case KLINE_TYPE:
    case CLIENT_TYPE:
      MyFree(conf);
      break;

    case OPER_TYPE:
      aconf = map_to_conf(conf);
      if (!IsConfIllegal(aconf))
	dlinkDelete(&conf->node, &oconf_items);
      MyFree(conf);
      break;

    case SERVER_TYPE:
      aconf = map_to_conf(conf);

      DLINK_FOREACH_SAFE(m, m_next, aconf->hub_list.head)
      {
        MyFree(m->data);
        free_dlink_node(m);
      }

      DLINK_FOREACH_SAFE(m, m_next, aconf->leaf_list.head)
      {
        MyFree(m->data);
        free_dlink_node(m);  
      }

      if (!IsConfIllegal(aconf))
	dlinkDelete(&conf->node, &server_items);
      MyFree(conf);
      break;

    default:
      break;
    }
    break;

  case ULINE_TYPE:
    match_item = map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    dlinkDelete(&conf->node, &uconf_items);
    MyFree(conf);
    break;

  case XLINE_TYPE:
    match_item = map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    dlinkDelete(&conf->node, &xconf_items);
    MyFree(conf);
    break;
#ifdef HAVE_LIBPCRE
  case RKLINE_TYPE:
    aconf = map_to_conf(conf);
    MyFree(aconf->regexuser);
    MyFree(aconf->regexhost);
    MyFree(aconf->user);
    MyFree(aconf->host);
    MyFree(aconf->reason);
    dlinkDelete(&conf->node, &rkconf_items);
    MyFree(conf);
    break;

  case RXLINE_TYPE:
    MyFree(conf->regexpname);
    match_item = map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    dlinkDelete(&conf->node, &rxconf_items);
    MyFree(conf);
    break;
#endif
  case NRESV_TYPE:
    match_item = map_to_conf(conf);
    MyFree(match_item->user);
    MyFree(match_item->host);
    MyFree(match_item->reason);
    dlinkDelete(&conf->node, &nresv_items);

    if (conf->flags & CONF_FLAGS_TEMPORARY)
      if ((m = dlinkFindDelete(&temporary_resv, conf)) != NULL)
        free_dlink_node(m);

    MyFree(conf);
    break;

  case CLUSTER_TYPE:
    dlinkDelete(&conf->node, &cluster_items);
    MyFree(conf);
    break;

  case CRESV_TYPE:
    if (conf->flags & CONF_FLAGS_TEMPORARY)
      if ((m = dlinkFindDelete(&temporary_resv, conf)) != NULL)
        free_dlink_node(m);

    MyFree(conf);
    break;

  case CLASS_TYPE:
    dlinkDelete(&conf->node, &class_items);
    MyFree(conf);
    break;

  case SERVICE_TYPE:
    dlinkDelete(&conf->node, &service_items);
    MyFree(conf);
    break;

  default:
    break;
  }
}

/* free_access_item()
 *
 * inputs	- pointer to conf to free
 * output	- none
 * side effects	- crucial password fields are zeroed, conf is freed
 */
void
free_access_item(struct AccessItem *aconf)
{
  struct ConfItem *conf;

  if (aconf == NULL)
    return;
  conf = unmap_conf_item(aconf);
  delete_conf_item(conf);
}

static const unsigned int shared_bit_table[] =
  { 'K', 'k', 'U', 'X', 'x', 'Y', 'Q', 'q', 'R', 'L', 0};

/* report_confitem_types()
 *
 * inputs	- pointer to client requesting confitem report
 *		- ConfType to report
 * output	- none
 * side effects	-
 */
void
report_confitem_types(struct Client *source_p, ConfType type)
{
  dlink_node *ptr = NULL, *dptr = NULL;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf = NULL;
  struct MatchItem *matchitem = NULL;
  struct ClassItem *classitem = NULL;
  char buf[12];
  char *p = NULL;

  switch (type)
  {
  case XLINE_TYPE:
    DLINK_FOREACH(ptr, xconf_items.head)
    {
      conf = ptr->data;
      matchitem = map_to_conf(conf);

      sendto_one(source_p, form_str(RPL_STATSXLINE),
		 me.name, source_p->name, 
		 matchitem->hold ? "x": "X", matchitem->count,
		 conf->name, matchitem->reason);
    }
    break;

#ifdef HAVE_LIBPCRE
  case RXLINE_TYPE:
    DLINK_FOREACH(ptr, rxconf_items.head)
    {
      conf = ptr->data;
      matchitem = map_to_conf(conf);

      sendto_one(source_p, form_str(RPL_STATSXLINE),
                 me.name, source_p->name,
                 "XR", matchitem->count,
                 conf->name, matchitem->reason);
    }
    break;

  case RKLINE_TYPE:
    DLINK_FOREACH(ptr, rkconf_items.head)
    {
      aconf = map_to_conf((conf = ptr->data));

      sendto_one(source_p, form_str(RPL_STATSKLINE), me.name,
                 source_p->name, "KR", aconf->host, aconf->user,
                 aconf->reason);
    }
    break;
#endif

  case ULINE_TYPE:
    DLINK_FOREACH(ptr, uconf_items.head)
    {
      conf = ptr->data;
      matchitem = map_to_conf(conf);

      p = buf;

      /* some of these are redundant for the sake of 
       * consistency with cluster{} flags
       */
      *p++ = 'c';
      flags_to_ascii(matchitem->action, shared_bit_table, p, 0);

      sendto_one(source_p, form_str(RPL_STATSULINE),
		 me.name, source_p->name, conf->name,
                 matchitem->user?matchitem->user: "*",
		 matchitem->host?matchitem->host: "*", buf);
    }

    DLINK_FOREACH(ptr, cluster_items.head)
    {
      conf = ptr->data;

      p = buf;

      *p++ = 'C';
      flags_to_ascii(conf->flags, shared_bit_table, p, 0);

      sendto_one(source_p, form_str(RPL_STATSULINE),
                 me.name, source_p->name, conf->name,
                 "*", "*", buf);
    }

    break;

  case OPER_TYPE:
    DLINK_FOREACH(ptr, oconf_items.head)
    {
      conf = ptr->data;
      aconf = map_to_conf(conf);

      /* Don't allow non opers to see oper privs */
      if (HasUMode(source_p, UMODE_OPER))
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', aconf->user, aconf->host,
		   conf->name, oper_privs_as_string(aconf->port),
		   aconf->class_ptr ? aconf->class_ptr->name : "<default>");
      else
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', aconf->user, aconf->host,
                   conf->name, "0",
		   aconf->class_ptr ? aconf->class_ptr->name : "<default>");
    }
    break;

  case CLASS_TYPE:
    DLINK_FOREACH(ptr, class_items.head)
    {
      conf = ptr->data;
      classitem = map_to_conf(conf);
      sendto_one(source_p, form_str(RPL_STATSYLINE),
		 me.name, source_p->name, 'Y',
		 conf->name, classitem->ping_freq,
		 classitem->con_freq,
		 classitem->max_total, classitem->max_sendq,
                 classitem->max_recvq,
                 classitem->curr_user_count,
                 classitem->number_per_cidr, classitem->cidr_bitlen_ipv4,
                 classitem->number_per_cidr, classitem->cidr_bitlen_ipv6,
                 classitem->active ? "active" : "disabled");
    }
    break;

  case CONF_TYPE:
  case CLIENT_TYPE:
    break;

  case SERVICE_TYPE:
    DLINK_FOREACH(ptr, service_items.head)
    {
      conf = ptr->data;
      sendto_one(source_p, form_str(RPL_STATSSERVICE),
                 me.name, source_p->name, 'S', "*", conf->name, 0, 0);
    }
    break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, server_items.head)
    {
      p = buf;

      conf = ptr->data;
      aconf = map_to_conf(conf);

      buf[0] = '\0';

      if (IsConfAllowAutoConn(aconf))
	*p++ = 'A';
      if (IsConfSSL(aconf))
        *p++ = 'S';
      if (buf[0] == '\0')
	*p++ = '*';

      *p = '\0';

      /*
       * Allow admins to see actual ips unless hide_server_ips is enabled
       */
      if (!ConfigServerHide.hide_server_ips && HasUMode(source_p, UMODE_ADMIN))
	sendto_one(source_p, form_str(RPL_STATSCLINE),
		   me.name, source_p->name, 'C', aconf->host,
		   buf, conf->name, aconf->port,
		   aconf->class_ptr ? aconf->class_ptr->name : "<default>");
        else
          sendto_one(source_p, form_str(RPL_STATSCLINE),
                     me.name, source_p->name, 'C',
		     "*@127.0.0.1", buf, conf->name, aconf->port,
		     aconf->class_ptr ? aconf->class_ptr->name : "<default>");
    }
    break;

  case HUB_TYPE:
    DLINK_FOREACH(ptr, server_items.head)
    {
      conf = ptr->data;
      aconf = map_to_conf(conf);

      DLINK_FOREACH(dptr, aconf->hub_list.head)
        sendto_one(source_p, form_str(RPL_STATSHLINE), me.name,
                   source_p->name, 'H', dptr->data, conf->name, 0, "*");
    }
    break;

  case LEAF_TYPE:
    DLINK_FOREACH(ptr, server_items.head)
    {
      conf = ptr->data;
      aconf = map_to_conf(conf);

      DLINK_FOREACH(dptr, aconf->leaf_list.head)
        sendto_one(source_p, form_str(RPL_STATSLLINE), me.name,
                   source_p->name, 'L', dptr->data, conf->name, 0, "*");
    }
    break;

  case GLINE_TYPE:
  case KLINE_TYPE:
  case DLINE_TYPE:
  case EXEMPTDLINE_TYPE:
  case CRESV_TYPE:
  case NRESV_TYPE:
  case CLUSTER_TYPE:
  default:
    break;
  }
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
static void *
check_client(va_list args)
{
  struct Client *source_p = va_arg(args, struct Client *);
  const char *username = va_arg(args, const char *);
  int i;
 
  /* I'm already in big trouble if source_p->localClient is NULL -db */
  if ((i = verify_access(source_p, username)))
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
      exit_client(source_p, &me, "No more connections allowed on that IP");
      break;

    case I_LINE_FULL:
      sendto_realops_flags(UMODE_FULL, L_ALL, SEND_NOTICE,
                           "auth{} block is full for %s (%s).",
			   get_client_name(source_p, SHOW_IP),
			   source_p->sockhost);
      ilog(LOG_TYPE_IRCD, "Too many connections from %s.",
	   get_client_name(source_p, SHOW_IP));
      ++ServerStats.is_ref;
      exit_client(source_p, &me, 
		"No more connections allowed in your connection class");
      break;

    case NOT_AUTHORIZED:
      ++ServerStats.is_ref;
      /* jdc - lists server name & port connections are on */
      /*       a purely cosmetical change */
      sendto_realops_flags(UMODE_UNAUTH, L_ALL, SEND_NOTICE,
			   "Unauthorized client connection from %s [%s] on [%s/%u].",
			   get_client_name(source_p, SHOW_IP),
			   source_p->sockhost,
			   source_p->localClient->listener->name,
			   source_p->localClient->listener->port);
      ilog(LOG_TYPE_IRCD,
	  "Unauthorized client connection from %s on [%s/%u].",
	  get_client_name(source_p, SHOW_IP),
	  source_p->localClient->listener->name,
	  source_p->localClient->listener->port);

      exit_client(source_p, &me, "You are not authorized to use this server");
      break;

   case BANNED_CLIENT:
     exit_client(source_p, &me, "Banned");
     ++ServerStats.is_ref;
     break;

   case 0:
   default:
     break;
  }

  return (i < 0 ? NULL : source_p);
}

/* verify_access()
 *
 * inputs	- pointer to client to verify
 *		- pointer to proposed username
 * output	- 0 if success -'ve if not
 * side effect	- find the first (best) I line to attach.
 */
static int
verify_access(struct Client *client_p, const char *username)
{
  struct AccessItem *aconf = NULL, *rkconf = NULL;
  struct ConfItem *conf = NULL;
  char non_ident[USERLEN + 1] = { '~', '\0' };
  const char *uhi[3];

  if (IsGotId(client_p))
  {
    aconf = find_address_conf(client_p->host, client_p->username,
			     &client_p->localClient->ip,
			     client_p->localClient->aftype,
                             client_p->localClient->passwd);
  }
  else
  {
    strlcpy(non_ident+1, username, sizeof(non_ident)-1);
    aconf = find_address_conf(client_p->host,non_ident,
			     &client_p->localClient->ip,
			     client_p->localClient->aftype,
	                     client_p->localClient->passwd);
  }

  uhi[0] = IsGotId(client_p) ? client_p->username : non_ident;
  uhi[1] = client_p->host;
  uhi[2] = client_p->sockhost;

  rkconf = find_regexp_kline(uhi);

  if (aconf != NULL)
  {
    if (IsConfClient(aconf) && !rkconf)
    {
      conf = unmap_conf_item(aconf);

      if (IsConfRedir(aconf))
      {
        sendto_one(client_p, form_str(RPL_REDIR),
                   me.name, client_p->name,
                   conf->name ? conf->name : "",
                   aconf->port);
        return(NOT_AUTHORIZED);
      }

      if (IsConfDoIdentd(aconf))
	SetNeedId(client_p);

      /* Thanks for spoof idea amm */
      if (IsConfDoSpoofIp(aconf))
      {
	conf = unmap_conf_item(aconf);

        if (!ConfigFileEntry.hide_spoof_ips && IsConfSpoofNotice(aconf))
          sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                               "%s spoofing: %s as %s",
                               client_p->name, client_p->host, conf->name);
        strlcpy(client_p->host, conf->name, sizeof(client_p->host));
        SetIPSpoof(client_p);
      }

      return(attach_iline(client_p, conf));
    }
    else if (rkconf || IsConfKill(aconf) || (ConfigFileEntry.glines && IsConfGline(aconf)))
    {
      /* XXX */
      aconf = rkconf ? rkconf : aconf;
      if (IsConfGline(aconf))
        sendto_one(client_p, ":%s NOTICE %s :*** G-lined", me.name,
                   client_p->name);
      sendto_one(client_p, ":%s NOTICE %s :*** Banned: %s", 
                 me.name, client_p->name, aconf->reason);
      return(BANNED_CLIENT);
    }
  }

  return(NOT_AUTHORIZED);
}

/* attach_iline()
 *
 * inputs	- client pointer
 *		- conf pointer
 * output	-
 * side effects	- do actual attach
 */
static int
attach_iline(struct Client *client_p, struct ConfItem *conf)
{
  struct AccessItem *aconf;
  struct ClassItem *aclass;
  struct ip_entry *ip_found;
  int a_limit_reached = 0;
  int local = 0, global = 0, ident = 0;

  ip_found = find_or_add_ip(&client_p->localClient->ip);
  ip_found->count++;
  SetIpHash(client_p);

  aconf = map_to_conf(conf);
  if (aconf->class_ptr == NULL)
    return NOT_AUTHORIZED;  /* If class is missing, this is best */

  aclass = map_to_conf(aconf->class_ptr);

  count_user_host(client_p->username, client_p->host,
                  &global, &local, &ident);

  /* XXX blah. go down checking the various silly limits
   * setting a_limit_reached if any limit is reached.
   * - Dianora
   */
  if (aclass->max_total != 0 && aclass->curr_user_count >= aclass->max_total)
    a_limit_reached = 1;
  else if (aclass->max_perip != 0 && ip_found->count > aclass->max_perip)
    a_limit_reached = 1;
  else if (aclass->max_local != 0 && local >= aclass->max_local)
    a_limit_reached = 1;
  else if (aclass->max_global != 0 && global >= aclass->max_global)
    a_limit_reached = 1;
  else if (aclass->max_ident != 0 && ident >= aclass->max_ident &&
           client_p->username[0] != '~')
    a_limit_reached = 1;

  if (a_limit_reached)
  {
    if (!IsConfExemptLimits(aconf))
      return TOO_MANY;   /* Already at maximum allowed */

    sendto_one(client_p,
               ":%s NOTICE %s :*** Your connection class is full, "
               "but you have exceed_limit = yes;", me.name, client_p->name);
  }

  return attach_conf(client_p, conf);
}

/* init_ip_hash_table()
 *
 * inputs               - NONE
 * output               - NONE
 * side effects         - allocate memory for ip_entry(s)
 *			- clear the ip hash table
 */
void
init_ip_hash_table(void)
{
  ip_entry_heap = BlockHeapCreate("ip", sizeof(struct ip_entry),
    2 * hard_fdlimit);
  memset(ip_hash_table, 0, sizeof(ip_hash_table));
}

/* find_or_add_ip()
 *
 * inputs       - pointer to struct irc_ssaddr
 * output       - pointer to a struct ip_entry
 * side effects -
 *
 * If the ip # was not found, a new struct ip_entry is created, and the ip
 * count set to 0.
 */
static struct ip_entry *
find_or_add_ip(struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr, *newptr;
  int hash_index = hash_ip(ip_in), res;
  struct sockaddr_in *v4 = (struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; ptr = ptr->next)
  {
#ifdef IPV6
    if (ptr->ip.ss.ss_family != ip_in->ss.ss_family)
      continue;
    if (ip_in->ss.ss_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&ptr->ip;
      res = memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr));
    }
    else
#endif
    {
      ptr_v4 = (struct sockaddr_in *)&ptr->ip;
      res = memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr));
    }
    if (res == 0)
    {
      /* Found entry already in hash, return it. */
      return ptr;
    }
  }

  if (ip_entries_count >= 2 * hard_fdlimit)
    garbage_collect_ip_entries();

  newptr = BlockHeapAlloc(ip_entry_heap);
  ip_entries_count++;
  memcpy(&newptr->ip, ip_in, sizeof(struct irc_ssaddr));

  newptr->next = ip_hash_table[hash_index];
  ip_hash_table[hash_index] = newptr;

  return newptr;
}

/* remove_one_ip()
 *
 * inputs        - unsigned long IP address value
 * output        - NONE
 * side effects  - The ip address given, is looked up in ip hash table
 *                 and number of ip#'s for that ip decremented.
 *                 If ip # count reaches 0 and has expired,
 *		   the struct ip_entry is returned to the ip_entry_heap
 */
void
remove_one_ip(struct irc_ssaddr *ip_in)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr = NULL;
  int hash_index = hash_ip(ip_in), res;
  struct sockaddr_in *v4 = (struct sockaddr_in *)ip_in, *ptr_v4;
#ifdef IPV6
  struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)ip_in, *ptr_v6;
#endif

  for (ptr = ip_hash_table[hash_index]; ptr; ptr = ptr->next)
  {
#ifdef IPV6
    if (ptr->ip.ss.ss_family != ip_in->ss.ss_family)
      continue;
    if (ip_in->ss.ss_family == AF_INET6)
    {
      ptr_v6 = (struct sockaddr_in6 *)&ptr->ip;
      res = memcmp(&v6->sin6_addr, &ptr_v6->sin6_addr, sizeof(struct in6_addr));
    }
    else
#endif
    {
      ptr_v4 = (struct sockaddr_in *)&ptr->ip;
      res = memcmp(&v4->sin_addr, &ptr_v4->sin_addr, sizeof(struct in_addr));
    }
    if (res)
      continue;
    if (ptr->count > 0)
      ptr->count--;
    if (ptr->count == 0 &&
	(CurrentTime-ptr->last_attempt) >= ConfigFileEntry.throttle_time)
    {
      if (last_ptr != NULL)
	last_ptr->next = ptr->next;
      else
	ip_hash_table[hash_index] = ptr->next;

      BlockHeapFree(ip_entry_heap, ptr);
      ip_entries_count--;
      return;
    }
    last_ptr = ptr;
  }
}

/* hash_ip()
 *
 * input        - pointer to an irc_inaddr
 * output       - integer value used as index into hash table
 * side effects - hopefully, none
 */
static int
hash_ip(struct irc_ssaddr *addr)
{
  if (addr->ss.ss_family == AF_INET)
  {
    struct sockaddr_in *v4 = (struct sockaddr_in *)addr;
    int hash;
    uint32_t ip;

    ip   = ntohl(v4->sin_addr.s_addr);
    hash = ((ip >> 12) + ip) & (IP_HASH_SIZE-1);
    return hash;
  }
#ifdef IPV6
  else
  {
    int hash;
    struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)addr;
    uint32_t *ip = (uint32_t *)&v6->sin6_addr.s6_addr;

    hash  = ip[0] ^ ip[3];
    hash ^= hash >> 16;  
    hash ^= hash >> 8;   
    hash  = hash & (IP_HASH_SIZE - 1);
    return hash;
  }
#else
  return 0;
#endif
}

/* count_ip_hash()
 *
 * inputs        - pointer to counter of number of ips hashed 
 *               - pointer to memory used for ip hash
 * output        - returned via pointers input
 * side effects  - NONE
 *
 * number of hashed ip #'s is counted up, plus the amount of memory
 * used in the hash.
 */
void
count_ip_hash(unsigned int *number_ips_stored, uint64_t *mem_ips_stored)
{
  struct ip_entry *ptr;
  int i;

  *number_ips_stored = 0;
  *mem_ips_stored    = 0;

  for (i = 0; i < IP_HASH_SIZE; i++)
  {
    for (ptr = ip_hash_table[i]; ptr; ptr = ptr->next)
    {
      *number_ips_stored += 1;
      *mem_ips_stored += sizeof(struct ip_entry);
    }
  }
}

/* garbage_collect_ip_entries()
 *
 * input	- NONE
 * output	- NONE
 * side effects	- free up all ip entries with no connections
 */
static void
garbage_collect_ip_entries(void)
{
  struct ip_entry *ptr;
  struct ip_entry *last_ptr;
  struct ip_entry *next_ptr;
  int i;

  for (i = 0; i < IP_HASH_SIZE; i++)
  {
    last_ptr = NULL;

    for (ptr = ip_hash_table[i]; ptr; ptr = next_ptr)
    {
      next_ptr = ptr->next;

      if (ptr->count == 0 &&
          (CurrentTime - ptr->last_attempt) >= ConfigFileEntry.throttle_time)
      {
        if (last_ptr != NULL)
          last_ptr->next = ptr->next;
        else
          ip_hash_table[i] = ptr->next;
        BlockHeapFree(ip_entry_heap, ptr);
        ip_entries_count--;
      }
      else
        last_ptr = ptr;
    }
  }
}

/* detach_conf()
 *
 * inputs	- pointer to client to detach
 *		- type of conf to detach
 * output	- 0 for success, -1 for failure
 * side effects	- Disassociate configuration from the client.
 *		  Also removes a class from the list if marked for deleting.
 */
int
detach_conf(struct Client *client_p, ConfType type)
{
  dlink_node *ptr, *next_ptr;
  struct ConfItem *conf;
  struct ClassItem *aclass;
  struct AccessItem *aconf;
  struct ConfItem *aclass_conf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, client_p->localClient->confs.head)
  {
    conf = ptr->data;

    if (type == CONF_TYPE || conf->type == type)
    {
      dlinkDelete(ptr, &client_p->localClient->confs);
      free_dlink_node(ptr);

      switch (conf->type)
      {
      case CLIENT_TYPE:
      case OPER_TYPE:
      case SERVER_TYPE:
        aconf = map_to_conf(conf);

        assert(aconf->clients > 0);

        if ((aclass_conf = aconf->class_ptr) != NULL)
        {
          aclass = map_to_conf(aclass_conf);

          assert(aclass->curr_user_count > 0);

          if (conf->type == CLIENT_TYPE)
            remove_from_cidr_check(&client_p->localClient->ip, aclass);
          if (--aclass->curr_user_count == 0 && aclass->active == 0)
            delete_conf_item(aclass_conf);
        }

        if (--aconf->clients == 0 && IsConfIllegal(aconf))
          delete_conf_item(conf);

        break;
      default:
        break;
      }

      if (type != CONF_TYPE)
        return 0;
    }
  }

  return -1;
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
attach_conf(struct Client *client_p, struct ConfItem *conf)
{
  struct AccessItem *aconf = map_to_conf(conf);
  struct ClassItem *aclass = map_to_conf(aconf->class_ptr);

  if (dlinkFind(&client_p->localClient->confs, conf) != NULL)
    return 1;

  if (IsConfIllegal(aconf)) /* TBV: can't happen */
    return NOT_AUTHORIZED;

  if (conf->type == CLIENT_TYPE)
    if (cidr_limit_reached(IsConfExemptLimits(aconf),
                           &client_p->localClient->ip, aclass))
      return TOO_MANY;    /* Already at maximum allowed */

  aclass->curr_user_count++;
  aconf->clients++;

  dlinkAdd(conf, make_dlink_node(), &client_p->localClient->confs);

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
  dlink_node *ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;

  assert(client_p != NULL);
  assert(host != NULL);

  if (client_p == NULL || host == NULL)
    return 0;

  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;
    aconf = map_to_conf(conf);

    if (match(conf->name, name) == 0 || match(aconf->host, host) == 0)
      continue;

    attach_conf(client_p, conf);
    return -1;
  }

  return 0;
}

/* find_conf_exact()
 *
 * inputs	- type of ConfItem
 *		- pointer to name to find
 *		- pointer to username to find
 *		- pointer to host to find
 * output	- NULL or pointer to conf found
 * side effects	- find a conf entry which matches the hostname
 *		  and has the same name.
 */
struct ConfItem *
find_conf_exact(ConfType type, const char *name, const char *user, 
                const char *host)
{
  dlink_node *ptr;
  dlink_list *list_p;
  struct ConfItem *conf = NULL;
  struct AccessItem *aconf;

  /* Only valid for OPER_TYPE and ...? */
  list_p = map_to_list(type);

  DLINK_FOREACH(ptr, (*list_p).head)
  {
    conf = ptr->data;

    if (conf->name == NULL)
      continue;
    aconf = map_to_conf(conf);
    if (aconf->host == NULL)
      continue;
    if (irccmp(conf->name, name) != 0)
      continue;

    /*
    ** Accept if the *real* hostname (usually sockethost)
    ** socket host) matches *either* host or name field
    ** of the configuration.
    */
    if (!match(aconf->host, host) || !match(aconf->user, user))
      continue;
    if (type == OPER_TYPE)
    {
      struct ClassItem *aclass = map_to_conf(aconf->class_ptr);

      if (aconf->clients >= aclass->max_total)
	continue;
    }

    return conf;
  }

  return NULL;
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
struct ConfItem *
find_conf_name(dlink_list *list, const char *name, ConfType type)
{
  dlink_node *ptr;
  struct ConfItem* conf;

  DLINK_FOREACH(ptr, list->head)
  {
    conf = ptr->data;
    
    if (conf->type == type)
    {
      if (conf->name && (irccmp(conf->name, name) == 0 ||
                         match(conf->name, name)))
      return conf;
    }
  }

  return NULL;
}

/* map_to_list()
 *
 * inputs	- ConfType conf
 * output	- pointer to dlink_list to use
 * side effects	- none
 */
static dlink_list *
map_to_list(ConfType type)
{
  switch(type)
  {
  case RXLINE_TYPE:
    return(&rxconf_items);
    break;
  case XLINE_TYPE:
    return(&xconf_items);
    break;
  case ULINE_TYPE:
    return(&uconf_items);
    break;
  case NRESV_TYPE:
    return(&nresv_items);
    break;
  case OPER_TYPE:
    return(&oconf_items);
    break;
  case CLASS_TYPE:
    return(&class_items);
    break;
  case SERVER_TYPE:
    return(&server_items);
    break;
  case SERVICE_TYPE:
    return(&service_items);
    break;
  case CLUSTER_TYPE:
    return(&cluster_items);
    break;
  case CONF_TYPE:
  case GLINE_TYPE:
  case KLINE_TYPE:
  case DLINE_TYPE:
  case CRESV_TYPE:
  default:
    return NULL;
  }
}

/* find_matching_name_conf()
 *
 * inputs       - type of link list to look in
 *		- pointer to name string to find
 *		- pointer to user
 *		- pointer to host
 *		- optional action to match on as well
 * output       - NULL or pointer to found struct MatchItem
 * side effects - looks for a match on name field
 */
struct ConfItem *
find_matching_name_conf(ConfType type, const char *name, const char *user,
                        const char *host, int action)
{
  dlink_node *ptr=NULL;
  struct ConfItem *conf=NULL;
  struct AccessItem *aconf=NULL;
  struct MatchItem *match_item=NULL;
  dlink_list *list_p = map_to_list(type);

  switch (type)
  {
#ifdef HAVE_LIBPCRE
  case RXLINE_TYPE:
      DLINK_FOREACH(ptr, list_p->head)
      {
        conf = ptr->data;
        assert(conf->regexpname);

        if (!ircd_pcre_exec(conf->regexpname, name))
          return conf;
      }
      break;
#endif
  case SERVICE_TYPE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      if (EmptyString(conf->name))
        continue;
      if ((name != NULL) && !irccmp(name, conf->name))
        return conf;
    }
    break;

  case XLINE_TYPE:
  case ULINE_TYPE:
  case NRESV_TYPE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      match_item = map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
      if ((name != NULL) && match_esc(conf->name, name))
      {
	if ((user == NULL && (host == NULL)))
	  return conf;
	if ((match_item->action & action) != action)
          continue;
	if (EmptyString(match_item->user) || EmptyString(match_item->host))
	  return conf;
	if (match(match_item->user, user) && match(match_item->host, host))
	  return conf;
      }
    }
      break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;
      aconf = map_to_conf(conf);

      if ((name != NULL) && match_esc(name, conf->name))
        return conf;
      else if ((host != NULL) && match_esc(host, aconf->host))
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
 * output       - NULL or pointer to found struct MatchItem
 * side effects - looks for an exact match on name field
 */
struct ConfItem *
find_exact_name_conf(ConfType type, const struct Client *who, const char *name,
                     const char *user, const char *host)
{
  dlink_node *ptr = NULL;
  struct AccessItem *aconf;
  struct ConfItem *conf;
  struct MatchItem *match_item;
  dlink_list *list_p;

  list_p = map_to_list(type);

  switch(type)
  {
  case RXLINE_TYPE:
  case XLINE_TYPE:
  case ULINE_TYPE:
  case NRESV_TYPE:

    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;
      match_item = (struct MatchItem *)map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
    
      if (irccmp(conf->name, name) == 0)
      {
	if ((user == NULL && (host == NULL)))
	  return (conf);
	if (EmptyString(match_item->user) || EmptyString(match_item->host))
	  return (conf);
	if (match(match_item->user, user) && match(match_item->host, host))
	  return (conf);
      }
    }
    break;

  case OPER_TYPE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;
      aconf = map_to_conf(conf);

      if (EmptyString(conf->name))
        continue;

      if (!irccmp(conf->name, name))
      {
        if (!who)
          return conf;
        if (EmptyString(aconf->user) || EmptyString(aconf->host))
          return conf;
        if (match(aconf->user, who->username))
        {
          switch (aconf->type)
          {
            case HM_HOST:
              if (match(aconf->host, who->host) || match(aconf->host, who->sockhost))
                return conf;
              break;
            case HM_IPV4:
              if (who->localClient->aftype == AF_INET)
                if (match_ipv4(&who->localClient->ip, &aconf->addr, aconf->bits))
                  return conf;
              break;
#ifdef IPV6
            case HM_IPV6:
              if (who->localClient->aftype == AF_INET6)
                if (match_ipv6(&who->localClient->ip, &aconf->addr, aconf->bits))
                  return conf;
              break;
#endif
            default:
              assert(0);
          }
        }
      }
    }

    break;

  case SERVER_TYPE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);
      if (EmptyString(conf->name))
	continue;
    
      if (name == NULL)
      {
	if (EmptyString(aconf->host))
	  continue;
	if (irccmp(aconf->host, host) == 0)
	  return(conf);
      }
      else if (irccmp(conf->name, name) == 0)
      {
	  return (conf);
      }
    }
    break;

  case CLASS_TYPE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;
      if (EmptyString(conf->name))
        continue;
    
      if (irccmp(conf->name, name) == 0)
        return (conf);
    }
    break;

  default:
    break;
  }
  return(NULL);
}

/* rehash()
 *
 * Actual REHASH service routine. Called with sig == 0 if it has been called
 * as a result of an operator issuing this command, else assume it has been
 * called as a result of the server receiving a HUP signal.
 */
int
rehash(int sig)
{
  if (sig != 0)
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Got signal SIGHUP, reloading ircd.conf file");

  restart_resolver();

  /* don't close listeners until we know we can go ahead with the rehash */

  /* Check to see if we magically got(or lost) IPv6 support */
  check_can_use_v6();

  read_conf_files(0);

  if (ServerInfo.description != NULL)
    strlcpy(me.info, ServerInfo.description, sizeof(me.info));

  load_conf_modules();

  flush_deleted_I_P();

  rehashed_klines = 1;
/* XXX */
  if (ConfigLoggingEntry.use_logging)
    log_close_all();

  return(0);
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
  assert(class_default == (struct ConfItem *) class_items.tail->data);

#ifdef HAVE_LIBCRYPTO
  ServerInfo.rsa_private_key = NULL;
  ServerInfo.rsa_private_key_file = NULL;
#endif

  /* ServerInfo.name is not rehashable */
  /* ServerInfo.name = ServerInfo.name; */
  ServerInfo.description = NULL;
  DupString(ServerInfo.network_name, NETWORK_NAME_DEFAULT);
  DupString(ServerInfo.network_desc, NETWORK_DESC_DEFAULT);

  memset(&ServerInfo.ip, 0, sizeof(ServerInfo.ip));
  ServerInfo.specific_ipv4_vhost = 0;
  memset(&ServerInfo.ip6, 0, sizeof(ServerInfo.ip6));
  ServerInfo.specific_ipv6_vhost = 0;

  ServerInfo.max_clients = MAXCLIENTS_MAX;

  ServerInfo.hub = 0;
  ServerInfo.dns_host.sin_addr.s_addr = 0;
  ServerInfo.dns_host.sin_port = 0;
  AdminInfo.name = NULL;
  AdminInfo.email = NULL;
  AdminInfo.description = NULL;

  log_close_all();

  ConfigLoggingEntry.use_logging = 1;

  ConfigChannel.disable_fake_channels = 0;
  ConfigChannel.restrict_channels = 0;
  ConfigChannel.knock_delay = 300;
  ConfigChannel.knock_delay_channel = 60;
  ConfigChannel.max_chans_per_user = 25;
  ConfigChannel.max_chans_per_oper = 50;
  ConfigChannel.quiet_on_ban = 1;
  ConfigChannel.max_bans = 25;
  ConfigChannel.default_split_user_count = 0;
  ConfigChannel.default_split_server_count = 0;
  ConfigChannel.no_join_on_split = 0;
  ConfigChannel.no_create_on_split = 0;

  ConfigServerHide.flatten_links = 0;
  ConfigServerHide.links_delay = 300;
  ConfigServerHide.hidden = 0;
  ConfigServerHide.hide_servers = 0;
  DupString(ConfigServerHide.hidden_name, NETWORK_NAME_DEFAULT);
  ConfigServerHide.hide_server_ips = 0;

  
  DupString(ConfigFileEntry.service_name, SERVICE_NAME_DEFAULT);
  ConfigFileEntry.max_watch = WATCHSIZE_DEFAULT;
  ConfigFileEntry.glines = 0;
  ConfigFileEntry.gline_time = 12 * 3600;
  ConfigFileEntry.gline_request_time = GLINE_REQUEST_EXPIRE_DEFAULT;
  ConfigFileEntry.gline_min_cidr = 16;
  ConfigFileEntry.gline_min_cidr6 = 48;
  ConfigFileEntry.invisible_on_connect = 1;
  ConfigFileEntry.tkline_expire_notices = 1;
  ConfigFileEntry.hide_spoof_ips = 1;
  ConfigFileEntry.ignore_bogus_ts = 0;
  ConfigFileEntry.disable_auth = 0;
  ConfigFileEntry.disable_remote = 0;
  ConfigFileEntry.kill_chase_time_limit = 90;
  ConfigFileEntry.default_floodcount = 8;
  ConfigFileEntry.failed_oper_notice = 1;
  ConfigFileEntry.dots_in_ident = 0;
  ConfigFileEntry.min_nonwildcard = 4;
  ConfigFileEntry.min_nonwildcard_simple = 3;
  ConfigFileEntry.max_accept = 20;
  ConfigFileEntry.anti_nick_flood = 0;
  ConfigFileEntry.max_nick_time = 20;
  ConfigFileEntry.max_nick_changes = 5;
  ConfigFileEntry.anti_spam_exit_message_time = 0;
  ConfigFileEntry.ts_warn_delta = TS_WARN_DELTA_DEFAULT;
  ConfigFileEntry.ts_max_delta = TS_MAX_DELTA_DEFAULT;
  ConfigFileEntry.warn_no_nline = 1;
  ConfigFileEntry.stats_o_oper_only = 0;
  ConfigFileEntry.stats_k_oper_only = 1;  /* masked */
  ConfigFileEntry.stats_i_oper_only = 1;  /* masked */
  ConfigFileEntry.stats_P_oper_only = 0;
  ConfigFileEntry.caller_id_wait = 60;
  ConfigFileEntry.opers_bypass_callerid = 0;
  ConfigFileEntry.pace_wait = 10;
  ConfigFileEntry.pace_wait_simple = 1;
  ConfigFileEntry.short_motd = 0;
  ConfigFileEntry.ping_cookie = 0;
  ConfigFileEntry.no_oper_flood = 0;
  ConfigFileEntry.true_no_oper_flood = 0;
  ConfigFileEntry.oper_pass_resv = 1;
  ConfigFileEntry.max_targets = MAX_TARGETS_DEFAULT;
  ConfigFileEntry.oper_only_umodes = UMODE_DEBUG;
  ConfigFileEntry.oper_umodes = UMODE_BOTS | UMODE_LOCOPS | UMODE_SERVNOTICE |
    UMODE_OPERWALL | UMODE_WALLOP;
  ConfigFileEntry.use_egd = 0;
  ConfigFileEntry.egdpool_path = NULL;
  ConfigFileEntry.throttle_time = 10;
}

static void
validate_conf(void)
{
  if (ConfigFileEntry.ts_warn_delta < TS_WARN_DELTA_MIN)
    ConfigFileEntry.ts_warn_delta = TS_WARN_DELTA_DEFAULT;

  if (ConfigFileEntry.ts_max_delta < TS_MAX_DELTA_MIN)
    ConfigFileEntry.ts_max_delta = TS_MAX_DELTA_DEFAULT;

  if (ServerInfo.network_name == NULL)
    DupString(ServerInfo.network_name,NETWORK_NAME_DEFAULT);

  if (ServerInfo.network_desc == NULL)
    DupString(ServerInfo.network_desc,NETWORK_DESC_DEFAULT);

  if (ConfigFileEntry.service_name == NULL)
    DupString(ConfigFileEntry.service_name, SERVICE_NAME_DEFAULT);

  ConfigFileEntry.max_watch = IRCD_MAX(ConfigFileEntry.max_watch, WATCHSIZE_MIN);
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

  set_default_conf(); /* Set default values prior to conf parsing */
  conf_parser_ctx.pass = 1;
  yyparse();	      /* pick up the classes first */

  rewind(file);

  conf_parser_ctx.pass = 2;
  yyparse();          /* Load the values from the conf */
  validate_conf();    /* Check to make sure some values are still okay. */
                      /* Some global values are also loaded here. */
  check_class();      /* Make sure classes are valid */
}

/* lookup_confhost()
 *
 * start DNS lookups of all hostnames in the conf
 * line and convert an IP addresses in a.b.c.d number for to IP#s.
 */
static void
lookup_confhost(struct ConfItem *conf)
{
  struct AccessItem *aconf;
  struct addrinfo hints, *res;

  aconf = map_to_conf(conf);

  if (has_wildcards(aconf->host))
  {
    ilog(LOG_TYPE_IRCD, "Host/server name error: (%s) (%s)",
         aconf->host, conf->name);
    return;
  }

  /* Do name lookup now on hostnames given and store the
   * ip numbers in conf structure.
   */
  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* Get us ready for a bind() and don't bother doing dns lookup */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(aconf->host, NULL, &hints, &res))
  {
    conf_dns_lookup(aconf);
    return;
  }

  assert(res != NULL);

  memcpy(&aconf->addr, res->ai_addr, res->ai_addrlen);
  aconf->addr.ss_len = res->ai_addrlen;
  aconf->addr.ss.ss_family = res->ai_family;
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
  struct ip_entry *ip_found;
  struct AccessItem *aconf = find_dline_conf(addr, aftype);

  /* DLINE exempt also gets you out of static limits/pacing... */
  if (aconf && (aconf->status & CONF_EXEMPTDLINE))
    return 0;

  if (aconf != NULL)
    return BANNED_CLIENT;

  ip_found = find_or_add_ip(addr);

  if ((CurrentTime - ip_found->last_attempt) <
      ConfigFileEntry.throttle_time)
  {
    ip_found->last_attempt = CurrentTime;
    return TOO_FAST;
  }

  ip_found->last_attempt = CurrentTime;
  return 0;
}

static struct AccessItem *
find_regexp_kline(const char *uhi[])
{
#ifdef HAVE_LIBPCRE
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, rkconf_items.head)
  {
    struct AccessItem *aptr = map_to_conf(ptr->data);

    assert(aptr->regexuser);
    assert(aptr->regexhost);

    if (!ircd_pcre_exec(aptr->regexuser, uhi[0]) &&
        (!ircd_pcre_exec(aptr->regexhost, uhi[1]) ||
         !ircd_pcre_exec(aptr->regexhost, uhi[2])))
      return aptr;
  }
#endif
  return NULL;
}

/* find_kill()
 *
 * inputs	- pointer to client structure
 * output	- pointer to struct AccessItem if found
 * side effects	- See if this user is klined already,
 *		  and if so, return struct AccessItem pointer
 */
struct AccessItem *
find_kill(struct Client *client_p)
{
  struct AccessItem *aconf = NULL;
  const char *uhi[3];

  uhi[0] = client_p->username;
  uhi[1] = client_p->host;
  uhi[2] = client_p->sockhost;

  assert(client_p != NULL);

  aconf = find_conf_by_address(client_p->host, &client_p->localClient->ip,
                               CONF_KLINE, client_p->localClient->aftype,
                               client_p->username, NULL, 1);
  if (aconf == NULL)
    aconf = find_regexp_kline(uhi);

  return aconf;
}

struct AccessItem *
find_gline(struct Client *client_p)
{
  struct AccessItem *aconf;

  assert(client_p != NULL);

  aconf = find_conf_by_address(client_p->host, &client_p->localClient->ip,
                               CONF_GLINE, client_p->localClient->aftype,
                               client_p->username, NULL, 1);
  return aconf;
}

/* add_temp_line()
 *
 * inputs        - pointer to struct ConfItem
 * output        - none
 * Side effects  - links in given struct ConfItem into 
 *                 temporary *line link list
 */
void
add_temp_line(struct ConfItem *conf)
{
  if ((conf->type == NRESV_TYPE) || (conf->type == CRESV_TYPE))
  {
    conf->flags |= CONF_FLAGS_TEMPORARY;
    dlinkAdd(conf, make_dlink_node(), &temporary_resv);
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
cleanup_tklines(void *notused)
{
  hostmask_expire_temporary();
  expire_tklines(&xconf_items); 
  expire_tklines(&temporary_resv);
}

/* expire_tklines()
 *
 * inputs       - tkline list pointer
 * output       - NONE
 * side effects - expire tklines
 */
static void
expire_tklines(dlink_list *tklist)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct MatchItem *xconf;
  struct MatchItem *nconf;
  struct ResvChannel *cconf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, tklist->head)
  {
    conf = ptr->data;

    if (conf->type == XLINE_TYPE)
    {
      if (!IsConfTemporary(conf))
        continue;

      xconf = (struct MatchItem *)map_to_conf(conf);
      if (xconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                               "Temporary X-line for [%s] expired", conf->name);
	delete_conf_item(conf);
      }
    }
    else if (conf->type == NRESV_TYPE)
    {
      nconf = (struct MatchItem *)map_to_conf(conf);
      if (nconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                               "Temporary RESV for [%s] expired", conf->name);
	dlinkDelete(ptr, tklist);
        free_dlink_node(ptr);
	delete_conf_item(conf);
      }
    }
    else if (conf->type == CRESV_TYPE)
    {
      cconf = (struct ResvChannel *)map_to_conf(conf);
      if (cconf->hold <= CurrentTime)
      {
        if (ConfigFileEntry.tkline_expire_notices)
	  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                               "Temporary RESV for [%s] expired", cconf->name);
	delete_channel_resv(cconf);
      }
    }
  }
}

/* oper_privs_as_string()
 *
 * inputs        - pointer to client_p
 * output        - pointer to static string showing oper privs
 * side effects  - return as string, the oper privs as derived from port
 */
static const struct oper_privs
{
  const unsigned int oprivs;
  const unsigned char c;
} flag_list[] = {
  { OPER_FLAG_ADMIN,       'A' },
  { OPER_FLAG_REMOTEBAN,   'B' },
  { OPER_FLAG_DIE,         'D' },
  { OPER_FLAG_GLINE,       'G' },
  { OPER_FLAG_REHASH,      'H' },
  { OPER_FLAG_K,           'K' },
  { OPER_FLAG_OPERWALL,    'L' },
  { OPER_FLAG_N,           'N' },
  { OPER_FLAG_GLOBAL_KILL, 'O' },
  { OPER_FLAG_REMOTE,      'R' },
  { OPER_FLAG_OPER_SPY,    'S' },
  { OPER_FLAG_UNKLINE,     'U' },
  { OPER_FLAG_X,           'X' },
  { 0, '\0' }
};

char *
oper_privs_as_string(const unsigned int port)
{
  static char privs_out[16];
  char *privs_ptr = privs_out;
  unsigned int i = 0;

  for (; flag_list[i].oprivs; ++i)
  {
    if (port & flag_list[i].oprivs)
      *privs_ptr++ = flag_list[i].c;
    else
      *privs_ptr++ = ToLowerTab[flag_list[i].c];
  }

  *privs_ptr = '\0';

  return privs_out;
}

/*
 * Input: A client to find the active oper{} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
const char *
get_oper_name(const struct Client *client_p)
{
  dlink_node *cnode = NULL;
  /* +5 for !,@,{,} and null */
  static char buffer[NICKLEN + USERLEN + HOSTLEN + HOSTLEN + 5];

  if (MyConnect(client_p))
  {
    if ((cnode = client_p->localClient->confs.head))
    {
      struct ConfItem *conf = cnode->data;
      const struct AccessItem *aconf = map_to_conf(conf);

      if (IsConfOperator(aconf))
      {
	snprintf(buffer, sizeof(buffer), "%s!%s@%s{%s}", client_p->name,
                 client_p->username, client_p->host, conf->name);
	return buffer;
      }
    }

    /* Probably should assert here for now. If there is an oper out there 
     * with no oper{} conf attached, it would be good for us to know...
     */
    assert(0); /* Oper without oper conf! */
  }

  snprintf(buffer, sizeof(buffer), "%s!%s@%s{%s}", client_p->name,
	   client_p->username, client_p->host, client_p->servptr->name);
  return buffer;
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
  const char *filename;
  char chanmodes[32];
  char chanlimit[32];

  conf_parser_ctx.boot = cold;
  filename = ConfigFileEntry.configfile;

  /* We need to know the initial filename for the yyerror() to report
     FIXME: The full path is in conffilenamebuf first time since we
             dont know anything else

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
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Unable to read configuration file '%s': %s",
			   filename, strerror(errno));
      return;
    }
  }

  if (!cold)
    clear_out_old_conf();

  read_conf(conf_parser_ctx.conf_file);
  fclose(conf_parser_ctx.conf_file);

  add_isupport("NETWORK", ServerInfo.network_name, -1);
  snprintf(chanmodes, sizeof(chanmodes), "beI:%d",
           ConfigChannel.max_bans);
  add_isupport("MAXLIST", chanmodes, -1);
  add_isupport("MAXTARGETS", NULL, ConfigFileEntry.max_targets);

  add_isupport("CHANTYPES", "#", -1);

  snprintf(chanlimit, sizeof(chanlimit), "#:%d",
	   ConfigChannel.max_chans_per_user);
  add_isupport("CHANLIMIT", chanlimit, -1);
  snprintf(chanmodes, sizeof(chanmodes), "%s",
           "beI,k,l,imnprstORS");
  add_isupport("CHANNELLEN", NULL, LOCAL_CHANNELLEN);

  add_isupport("EXCEPTS", "e", -1);
  add_isupport("INVEX", "I", -1);
  add_isupport("CHANMODES", chanmodes, -1);

  /*
   * message_locale may have changed.  rebuild isupport since it relies
   * on strlen(form_str(RPL_ISUPPORT))
   */
  rebuild_isupport_message_line();
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
  dlink_node *ptr = NULL, *next_ptr = NULL;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  struct ClassItem *cltmp;
  dlink_list *free_items [] = {
    &server_items,   &oconf_items,
     &uconf_items,   &xconf_items, &rxconf_items, &rkconf_items,
     &nresv_items, &cluster_items,  &service_items, NULL
  };

  dlink_list ** iterator = free_items; /* C is dumb */

  /* We only need to free anything allocated by yyparse() here.
   * Resetting structs, etc, is taken care of by set_default_conf().
   */
  
  for (; *iterator != NULL; iterator++)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, (*iterator)->head)
    {
      conf = ptr->data;
      /* XXX This is less than pretty */
      if (conf->type == SERVER_TYPE)
      {
	aconf = map_to_conf(conf);

	if (aconf->clients != 0)
        {
	  SetConfIllegal(aconf);
	  dlinkDelete(&conf->node, &server_items);
	}
	else
	{
	  delete_conf_item(conf);
	}
      }
      else if (conf->type == OPER_TYPE)
      {
	aconf = map_to_conf(conf);

	if (aconf->clients != 0)
        {
	  SetConfIllegal(aconf);
	  dlinkDelete(&conf->node, &oconf_items);
	}
	else
	{
	  delete_conf_item(conf);
	}
      }
      else if (conf->type == XLINE_TYPE  ||
               conf->type == RXLINE_TYPE ||
               conf->type == RKLINE_TYPE)
      {
        /* temporary (r)xlines are also on
         * the (r)xconf items list */
        if (conf->flags & CONF_FLAGS_TEMPORARY)
          continue;

        delete_conf_item(conf);
      }
      else
      {
	  delete_conf_item(conf);
      }
    }
  }

  /*
   * don't delete the class table, rather mark all entries
   * for deletion. The table is cleaned up by check_class. - avalon
   */
  DLINK_FOREACH(ptr, class_items.head)
  {
    cltmp = map_to_conf(ptr->data);

    if (ptr != class_items.tail)  /* never mark the "default" class */
      cltmp->active = 0;
  }

  clear_out_address_conf();

  /* clean out module paths */
  mod_clear_paths();

  /* clean out ServerInfo */
  MyFree(ServerInfo.description);
  ServerInfo.description = NULL;
  MyFree(ServerInfo.network_name);
  ServerInfo.network_name = NULL;
  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = NULL;
  MyFree(ConfigFileEntry.egdpool_path);
  ConfigFileEntry.egdpool_path = NULL;
#ifdef HAVE_LIBCRYPTO
  if (ServerInfo.rsa_private_key != NULL)
  {
    RSA_free(ServerInfo.rsa_private_key);
    ServerInfo.rsa_private_key = NULL;
  }

  MyFree(ServerInfo.rsa_private_key_file);
  ServerInfo.rsa_private_key_file = NULL;

  if (ServerInfo.server_ctx)
    SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv2|
                                               SSL_OP_NO_SSLv3|
                                               SSL_OP_NO_TLSv1);
  if (ServerInfo.client_ctx)
    SSL_CTX_set_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv2|
                                               SSL_OP_NO_SSLv3|
                                               SSL_OP_NO_TLSv1);
#endif

  /* clean out old resvs from the conf */
  clear_conf_resv();

  /* clean out AdminInfo */
  MyFree(AdminInfo.name);
  AdminInfo.name = NULL;
  MyFree(AdminInfo.email);
  AdminInfo.email = NULL;
  MyFree(AdminInfo.description);
  AdminInfo.description = NULL;

  /* operator{} and class{} blocks are freed above */
  /* clean out listeners */
  close_listeners();

  /* auth{}, quarantine{}, shared{}, connect{}, kill{}, deny{},
   * exempt{} and gecos{} blocks are freed above too
   */

  /* clean out general */
  MyFree(ConfigFileEntry.service_name);
  ConfigFileEntry.service_name = NULL;

  delete_isupport("INVEX");
  delete_isupport("EXCEPTS");
}

/* flush_deleted_I_P()
 *
 * inputs       - none
 * output       - none
 * side effects - This function removes I/P conf items
 */
static void
flush_deleted_I_P(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct ConfItem *conf;
  struct AccessItem *aconf;
  dlink_list * free_items [] = {
    &server_items, &oconf_items, NULL
  };
  dlink_list ** iterator = free_items; /* C is dumb */

  /* flush out deleted I and P lines
   * although still in use.
   */
  for (; *iterator != NULL; iterator++)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, (*iterator)->head)
    {
      conf = ptr->data;
      aconf = (struct AccessItem *)map_to_conf(conf);

      if (IsConfIllegal(aconf))
      {
	dlinkDelete(ptr, *iterator);

	if (aconf->clients == 0)
	  delete_conf_item(conf);
      }
    }
  }
}

#define BAD_PING (-1)

/* get_conf_ping()
 *
 * inputs       - pointer to struct AccessItem
 *              - pointer to a variable that receives ping warning time
 * output       - ping frequency
 * side effects - NONE
 */
static int
get_conf_ping(struct ConfItem *conf, int *pingwarn)
{
  struct ClassItem *aclass;
  struct AccessItem *aconf;

  if (conf != NULL)
  {
    aconf = (struct AccessItem *)map_to_conf(conf);
    if (aconf->class_ptr != NULL)
    {
      aclass = (struct ClassItem *)map_to_conf(aconf->class_ptr);
      *pingwarn = aclass->ping_warning;
      return aclass->ping_freq;
    }
  }

  return BAD_PING;
}

/* get_client_class()
 *
 * inputs	- pointer to client struct
 * output	- pointer to name of class
 * side effects - NONE
 */
const char *
get_client_class(struct Client *target_p)
{
  dlink_node *cnode = NULL;
  struct AccessItem *aconf = NULL;

  assert(!IsMe(target_p));

  if ((cnode = target_p->localClient->confs.head))
  {
    struct ConfItem *conf = cnode->data;

    assert((conf->type == CLIENT_TYPE) || (conf->type == SERVER_TYPE) ||
          (conf->type == OPER_TYPE));

    aconf = map_to_conf(conf);
    if (aconf->class_ptr != NULL)
      return aconf->class_ptr->name;
  }

  return "default";
}

/* get_client_ping()
 *
 * inputs	- pointer to client struct
 *              - pointer to a variable that receives ping warning time
 * output	- ping frequency
 * side effects - NONE
 */
int
get_client_ping(struct Client *target_p, int *pingwarn)
{
  int ping = 0;
  dlink_node *cnode = NULL;

  if ((cnode = target_p->localClient->confs.head))
  {
    struct ConfItem *conf = cnode->data;

    assert((conf->type == CLIENT_TYPE) || (conf->type == SERVER_TYPE) ||
          (conf->type == OPER_TYPE));

    ping = get_conf_ping(conf, pingwarn);
    if (ping > 0)
      return ping;
  }

  *pingwarn = 0;
  return DEFAULT_PINGFREQUENCY;
}

/* find_class()
 *
 * inputs	- string name of class
 * output	- corresponding Class pointer
 * side effects	- NONE
 */
struct ConfItem *
find_class(const char *classname)
{
  struct ConfItem *conf;

  if ((conf = find_exact_name_conf(CLASS_TYPE, NULL, classname, NULL, NULL)) != NULL)
    return conf;

  return class_default;
}

/* check_class()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects	- 
 */
void
check_class(void)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, class_items.head)
  {
    struct ClassItem *aclass = map_to_conf(ptr->data);

    if (!aclass->active && !aclass->curr_user_count)
    {
      destroy_cidr_class(aclass);
      delete_conf_item(ptr->data);
    }
  }
}

/* init_class()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects	- 
 */
void
init_class(void)
{
  struct ClassItem *aclass;

  class_default = make_conf_item(CLASS_TYPE);

  aclass = map_to_conf(class_default);
  aclass->active = 1;
  DupString(class_default->name, "default");
  aclass->con_freq  = DEFAULT_CONNECTFREQUENCY;
  aclass->ping_freq = DEFAULT_PINGFREQUENCY;
  aclass->max_total = MAXIMUM_LINKS_DEFAULT;
  aclass->max_sendq = DEFAULT_SENDQ;
  aclass->max_recvq = DEFAULT_RECVQ;

  client_check_cb = register_callback("check_client", check_client);
}

/* get_sendq()
 *
 * inputs       - pointer to client
 * output       - sendq for this client as found from its class
 * side effects	- NONE
 */
unsigned int
get_sendq(struct Client *client_p)
{
  unsigned int sendq = DEFAULT_SENDQ;
  dlink_node *cnode;
  struct ConfItem *class_conf;
  struct ClassItem *aclass;
  struct AccessItem *aconf;

  assert(!IsMe(client_p));

  if ((cnode = client_p->localClient->confs.head))
  {
    struct ConfItem *conf = cnode->data;

    assert((conf->type == CLIENT_TYPE) || (conf->type == SERVER_TYPE) ||
          (conf->type == OPER_TYPE));

    aconf = map_to_conf(conf);

    if ((class_conf = aconf->class_ptr) == NULL)
      return DEFAULT_SENDQ; /* TBV: shouldn't be possible at all */

    aclass = map_to_conf(class_conf);
    sendq = aclass->max_sendq;
    return sendq;
  }

  /* XXX return a default?
   * if here, then there wasn't an attached conf with a sendq
   * that is very bad -Dianora
   */
  return DEFAULT_SENDQ;
}

unsigned int
get_recvq(struct Client *client_p)
{
  unsigned int recvq = DEFAULT_RECVQ;
  dlink_node *cnode;
  struct ConfItem *class_conf;
  struct ClassItem *aclass;
  struct AccessItem *aconf;

  assert(!IsMe(client_p));

  if ((cnode = client_p->localClient->confs.head))
  {
    struct ConfItem *conf = cnode->data;

    assert((conf->type == CLIENT_TYPE) || (conf->type == SERVER_TYPE) ||
          (conf->type == OPER_TYPE));

    aconf = map_to_conf(conf);

    if ((class_conf = aconf->class_ptr) == NULL)
      return DEFAULT_RECVQ; /* TBV: shouldn't be possible at all */

    aclass = map_to_conf(class_conf);
    recvq = aclass->max_recvq;
    return recvq;
  }

  /* XXX return a default?
   * if here, then there wasn't an attached conf with a recvq
   * that is very bad -Dianora
   */
  return DEFAULT_RECVQ;
}

/* conf_add_class_to_conf()
 *
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a class pointer to a conf 
 */
void
conf_add_class_to_conf(struct ConfItem *conf, const char *class_name)
{
  struct AccessItem *aconf = map_to_conf(conf);
  struct ClassItem *class = NULL;

  if (class_name == NULL) 
  {
    aconf->class_ptr = class_default;

    if (conf->type == CLIENT_TYPE)
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s@%s",
			   aconf->user, aconf->host);
    else
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s",
			   conf->name);
  }
  else
    aconf->class_ptr = find_class(class_name);

  if (aconf->class_ptr)
    class = map_to_conf(aconf->class_ptr);

  if (aconf->class_ptr == NULL || !class->active)
  {
    if (conf->type == CLIENT_TYPE)
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s@%s",
			   aconf->user, aconf->host);
    else
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s",
			   conf->name);
    aconf->class_ptr = class_default;
  }
}

/* conf_add_server()
 *
 * inputs       - pointer to config item
 *		- pointer to link count already on this conf
 * output       - NONE
 * side effects - Add a connect block
 */
int
conf_add_server(struct ConfItem *conf, const char *class_name)
{
  struct AccessItem *aconf = map_to_conf(conf);

  conf_add_class_to_conf(conf, class_name);

  if (!aconf->host || !conf->name)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL,  SEND_NOTICE,
                         "Bad connect block");
    ilog(LOG_TYPE_IRCD, "Bad connect block");
    return -1;
  }

  if (EmptyString(aconf->passwd))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Bad connect block, name %s",
                         conf->name);
    ilog(LOG_TYPE_IRCD, "Bad connect block, host %s", conf->name);
    return -1;
  }

  lookup_confhost(conf);

  return 0;
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
  sendto_realops_flags(UMODE_ALL, L_ALL,  SEND_NOTICE,
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
valid_tkline(const char *p, int minutes)
{
  time_t result = 0;

  for (; *p; ++p)
  {
    if (!IsDigit(*p))
      return 0;

    result *= 10;
    result += ((*p) & 0xF);
  }

  /*
   * In the degenerate case where oper does a /quote kline 0 user@host :reason 
   * i.e. they specifically use 0, I am going to return 1 instead
   * as a return value of non-zero is used to flag it as a temporary kline
   */
  if (result == 0)
    result = 1;

  /* 
   * If the incoming time is in seconds convert it to minutes for the purpose
   * of this calculation
   */
  if (!minutes)
    result = result / (time_t)60; 

  if (result > MAX_TDKLINE_TIME)
    result = MAX_TDKLINE_TIME;

  result = result * (time_t)60;  /* turn it into seconds */

  return result;
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
valid_wild_card(struct Client *source_p, int warn, int count, ...)
{
  char *p;
  char tmpch;
  int nonwild = 0;
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
    p = va_arg(args, char *);
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
        if (++nonwild >= ConfigFileEntry.min_nonwildcard)
          return 1;
      }
    }
  }

  if (warn)
    sendto_one(source_p, ":%s NOTICE %s :Please include at least %d non-wildcard characters with the mask",
               me.name, source_p->name, ConfigFileEntry.min_nonwildcard);
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
 * output       - 1 if valid, -1 if not valid
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
  static char def_reason[] = "No Reason";
  static char user[USERLEN*4+1];
  static char host[HOSTLEN*4+1];

  parv++;
  parc--;

  found_tkline_time = valid_tkline(*parv, TK_MINUTES);

  if (found_tkline_time != 0)
  {
    parv++;
    parc--;

    if (tkline_time != NULL)
      *tkline_time = found_tkline_time;
    else
    {
      sendto_one(source_p, ":%s NOTICE %s :temp_line not supported by %s",
		 me.name, source_p->name, cmd);
      return -1;
    }
  }

  if (parc == 0)
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, cmd);
    return -1;
  }

  if (h_p == NULL)
    *up_p = *parv;
  else
  {
    if (find_user_host(source_p, *parv, user, host, parse_flags) == 0)
      return -1;

    *up_p = user;
    *h_p = host;
  }
 
  parc--;
  parv++;

  if (parc != 0)
  {
    if (irccmp(*parv, "ON") == 0)
    {
      parc--;
      parv++;

      if (target_server == NULL)
      {
	sendto_one(source_p, ":%s NOTICE %s :ON server not supported by %s",
		   me.name, source_p->name, cmd);
	return -1;
      }

      if (!HasOFlag(source_p, OPER_FLAG_REMOTEBAN))
      {
        sendto_one(source_p, form_str(ERR_NOPRIVS),
                   me.name, source_p->name, "remoteban");
        return -1;
      }

      if (parc == 0 || EmptyString(*parv))
      {
	sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
		   me.name, source_p->name, cmd);
	return -1;
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
      if (target_server != NULL)
	*target_server = NULL;
    }
  }

  if (h_p != NULL)
  {
    if (strchr(user, '!') != NULL)
    {
      sendto_one(source_p, ":%s NOTICE %s :Invalid character '!' in kline",
                 me.name, source_p->name);
      return -1;
    }

    if ((parse_flags & AWILD) && !valid_wild_card(source_p, 1, 2, *up_p, *h_p))
      return -1;
  }
  else
    if ((parse_flags & AWILD) && !valid_wild_card(source_p, 1, 1, *up_p))
      return -1;

  if (reason != NULL)
  {
    if (parc != 0 && !EmptyString(*parv))
    {
      *reason = *parv;
      if (!valid_comment(source_p, *reason, 1))
	return -1;
    }
    else
      *reason = def_reason;
  }

  return 1;
}

/* find_user_host()
 *
 * inputs	- pointer to client placing kline
 *              - pointer to user_host_or_nick
 *              - pointer to user buffer
 *              - pointer to host buffer
 * output	- 0 if not ok to kline, 1 to kline i.e. if valid user host
 * side effects -
 */
static int
find_user_host(struct Client *source_p, char *user_host_or_nick,
               char *luser, char *lhost, unsigned int flags)
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

    if (hostp != NULL)                            /* I'm a little user@host */
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
        find_chasing(source_p, source_p, user_host_or_nick, NULL)) == NULL)
      return 0;

    if (IsExemptKline(target_p))
    {
      if (!IsServer(source_p))
	sendto_one(source_p,
		   ":%s NOTICE %s :%s is E-lined",
		   me.name, source_p->name, target_p->name);
      return 0;
    }

    /*
     * turn the "user" bit into "*user", blow away '~'
     * if found in original user name (non-idented)
     */
    strlcpy(luser, target_p->username, USERLEN*4 + 1);

    if (target_p->username[0] == '~')
      luser[0] = '*';

    if (target_p->sockhost[0] == '\0' ||
        (target_p->sockhost[0] == '0' && target_p->sockhost[1] == '\0'))
      strlcpy(lhost, target_p->host, HOSTLEN*4 + 1);
    else
      strlcpy(lhost, target_p->sockhost, HOSTLEN*4 + 1);
    return 1;
  }

  return 0;
}

/* valid_comment()
 *
 * inputs	- pointer to client
 *              - pointer to comment
 * output       - 0 if no valid comment,
 *              - 1 if valid
 * side effects - truncates reason where necessary
 */
int
valid_comment(struct Client *source_p, char *comment, int warn)
{
  if (strchr(comment, '"'))
  {
    if (warn)
      sendto_one(source_p, ":%s NOTICE %s :Invalid character '\"' in comment",
                 me.name, source_p->name);
    return 0;
  }

  if (strlen(comment) > REASONLEN)
    comment[REASONLEN-1] = '\0';

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
match_conf_password(const char *password, const struct AccessItem *aconf)
{
  const char *encr = NULL;

  if (EmptyString(password) || EmptyString(aconf->passwd))
    return 0;

  if (aconf->flags & CONF_FLAGS_ENCRYPTED)
    encr = crypt(password, aconf->passwd);
  else
    encr = password;

  return !strcmp(encr, aconf->passwd);
}

/*
 * cluster_a_line
 *
 * inputs	- client sending the cluster
 *		- command name "KLINE" "XLINE" etc.
 *		- capab -- CAP_KLN etc. from s_serv.h
 *		- cluster type -- CLUSTER_KLINE etc. from conf.h
 *		- pattern and args to send along
 * output	- none
 * side effects	- Take source_p send the pattern with args given
 *		  along to all servers that match capab and cluster type
*/
void
cluster_a_line(struct Client *source_p, const char *command,
               int capab, int cluster_type, const char *pattern, ...)
{
  va_list args;
  char buffer[IRCD_BUFSIZE];
  const dlink_node *ptr = NULL;

  va_start(args, pattern);
  vsnprintf(buffer, sizeof(buffer), pattern, args);
  va_end(args);

  DLINK_FOREACH(ptr, cluster_items.head)
  {
    const struct ConfItem *conf = ptr->data;

    if (conf->flags & cluster_type)
      sendto_match_servs(source_p, conf->name, CAP_CLUSTER|capab,
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

    if (iptr->nickptr && *iptr->nuhmask != '\0')
      strlcpy(iptr->nickptr, iptr->nuhmask, iptr->nicksize);

    if ((q = strchr(++p, '@'))) {
      *q++ = '\0';

      if (*p != '\0')
        strlcpy(iptr->userptr, p, iptr->usersize);

      if (*q != '\0')
        strlcpy(iptr->hostptr, q, iptr->hostsize);
    }
    else
    {
      if (*p != '\0')
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

      if (*iptr->nuhmask != '\0')
        strlcpy(iptr->userptr, iptr->nuhmask, iptr->usersize);

      if (*p != '\0')
        strlcpy(iptr->hostptr, p, iptr->hostsize);
    }
    else
    {
      /* no @ found */
      if (!iptr->nickptr || strpbrk(iptr->nuhmask, ".:"))
        strlcpy(iptr->hostptr, iptr->nuhmask, iptr->hostsize);
      else
        strlcpy(iptr->nickptr, iptr->nuhmask, iptr->nicksize);
    }
  }
}

/*
 * flags_to_ascii
 *
 * inputs	- flags is a bitmask
 *		- pointer to table of ascii letters corresponding
 *		  to each bit
 *		- flag 1 for convert ToLower if bit missing 
 *		  0 if ignore.
 * output	- none
 * side effects	- string pointed to by p has bitmap chars written to it
 */
static void
flags_to_ascii(unsigned int flags, const unsigned int bit_table[], char *p,
	       int lowerit)
{
  unsigned int mask = 1;
  int i = 0;

  for (mask = 1; (mask != 0) && (bit_table[i] != 0); mask <<= 1, i++)
  {
    if (flags & mask)
      *p++ = bit_table[i];
    else if (lowerit)
      *p++ = ToLower(bit_table[i]);
  }
  *p = '\0';
}

/*
 * cidr_limit_reached
 *
 * inputs	- int flag allowing over_rule of limits
 *		- pointer to the ip to be added
 *		- pointer to the class
 * output	- non zero if limit reached
 *		  0 if limit not reached
 * side effects	-
 */
static int
cidr_limit_reached(int over_rule,
		   struct irc_ssaddr *ip, struct ClassItem *aclass)
{
  dlink_node *ptr = NULL;
  struct CidrItem *cidr;

  if (aclass->number_per_cidr <= 0)
    return 0;

  if (ip->ss.ss_family == AF_INET)
  {
    if (aclass->cidr_bitlen_ipv4 <= 0)
      return 0;

    DLINK_FOREACH(ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;
      if (match_ipv4(ip, &cidr->mask, aclass->cidr_bitlen_ipv4))
      {
        if (!over_rule && (cidr->number_on_this_cidr >= aclass->number_per_cidr))
          return -1;
        cidr->number_on_this_cidr++;
        return 0;
      }
    }
    cidr = MyMalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, aclass->cidr_bitlen_ipv4);
    dlinkAdd(cidr, &cidr->node, &aclass->list_ipv4);
  }
#ifdef IPV6
  else if (aclass->cidr_bitlen_ipv6 > 0)
  {
    DLINK_FOREACH(ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;
      if (match_ipv6(ip, &cidr->mask, aclass->cidr_bitlen_ipv6))
      {
        if (!over_rule && (cidr->number_on_this_cidr >= aclass->number_per_cidr))
          return -1;
        cidr->number_on_this_cidr++;
        return 0;
      }
    }
    cidr = MyMalloc(sizeof(struct CidrItem));
    cidr->number_on_this_cidr = 1;
    cidr->mask = *ip;
    mask_addr(&cidr->mask, aclass->cidr_bitlen_ipv6);
    dlinkAdd(cidr, &cidr->node, &aclass->list_ipv6);
  }
#endif
  return 0;
}

/*
 * remove_from_cidr_check
 *
 * inputs	- pointer to the ip to be removed
 *		- pointer to the class
 * output	- NONE
 * side effects	-
 */
static void
remove_from_cidr_check(struct irc_ssaddr *ip, struct ClassItem *aclass)
{
  dlink_node *ptr = NULL;
  dlink_node *next_ptr = NULL;
  struct CidrItem *cidr;

  if (aclass->number_per_cidr == 0)
    return;

  if (ip->ss.ss_family == AF_INET)
  {
    if (aclass->cidr_bitlen_ipv4 <= 0)
      return;

    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv4.head)
    {
      cidr = ptr->data;
      if (match_ipv4(ip, &cidr->mask, aclass->cidr_bitlen_ipv4))
      {
	cidr->number_on_this_cidr--;
	if (cidr->number_on_this_cidr == 0)
	{
	  dlinkDelete(ptr, &aclass->list_ipv4);
	  MyFree(cidr);
	  return;
	}
      }
    }
  }
#ifdef IPV6
  else if (aclass->cidr_bitlen_ipv6 > 0)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, aclass->list_ipv6.head)
    {
      cidr = ptr->data;
      if (match_ipv6(ip, &cidr->mask, aclass->cidr_bitlen_ipv6))
      {
	cidr->number_on_this_cidr--;
	if (cidr->number_on_this_cidr == 0)
	{
	  dlinkDelete(ptr, &aclass->list_ipv6);
	  MyFree(cidr);
	  return;
	}
      }
    }
  }
#endif
}

static void
rebuild_cidr_list(int aftype, struct ConfItem *oldcl, struct ClassItem *newcl,
                  dlink_list *old_list, dlink_list *new_list, int changed)
{
  dlink_node *ptr;
  struct Client *client_p;
  struct ConfItem *conf;
  struct AccessItem *aconf;

  if (!changed)
  {
    *new_list = *old_list;
    old_list->head = old_list->tail = NULL;
    old_list->length = 0;
    return;
  }

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    client_p = ptr->data;
    if (client_p->localClient->aftype != aftype)
      continue;
    if (dlink_list_length(&client_p->localClient->confs) == 0)
      continue;

    conf = client_p->localClient->confs.tail->data;
    if (conf->type == CLIENT_TYPE)
    {
      aconf = map_to_conf(conf);
      if (aconf->class_ptr == oldcl)
        cidr_limit_reached(1, &client_p->localClient->ip, newcl);
    }
  }
}

/*
 * rebuild_cidr_class
 *
 * inputs	- pointer to old conf
 *		- pointer to new_class
 * output	- none
 * side effects	- rebuilds the class link list of cidr blocks
 */
void
rebuild_cidr_class(struct ConfItem *conf, struct ClassItem *new_class)
{
  struct ClassItem *old_class = map_to_conf(conf);

  if (old_class->number_per_cidr > 0 && new_class->number_per_cidr > 0)
  {
    if (old_class->cidr_bitlen_ipv4 > 0 && new_class->cidr_bitlen_ipv4 > 0)
      rebuild_cidr_list(AF_INET, conf, new_class,
                        &old_class->list_ipv4, &new_class->list_ipv4,
                        old_class->cidr_bitlen_ipv4 != new_class->cidr_bitlen_ipv4);

#ifdef IPV6
    if (old_class->cidr_bitlen_ipv6 > 0 && new_class->cidr_bitlen_ipv6 > 0)
      rebuild_cidr_list(AF_INET6, conf, new_class,
                        &old_class->list_ipv6, &new_class->list_ipv6,
                        old_class->cidr_bitlen_ipv6 != new_class->cidr_bitlen_ipv6);
#endif
  }

  destroy_cidr_class(old_class);
}

/*
 * destroy_cidr_list
 *
 * inputs	- pointer to class dlink list of cidr blocks
 * output	- none
 * side effects	- completely destroys the class link list of cidr blocks
 */
static void
destroy_cidr_list(dlink_list *list)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    dlinkDelete(ptr, list);
    MyFree(ptr->data);
  }
}

/*
 * destroy_cidr_class
 *
 * inputs	- pointer to class
 * output	- none
 * side effects	- completely destroys the class link list of cidr blocks
 */
static void
destroy_cidr_class(struct ClassItem *aclass)
{
  destroy_cidr_list(&aclass->list_ipv4);
  destroy_cidr_list(&aclass->list_ipv6);
}
