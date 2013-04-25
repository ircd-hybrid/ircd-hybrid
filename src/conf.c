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
#include "mempool.h"
#include "irc_res.h"
#include "userhost.h"
#include "s_user.h"
#include "channel_mode.h"
#include "parse.h"
#include "s_misc.h"
#include "conf_db.h"
#include "conf_class.h"

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
dlink_list temporary_resv = { NULL, NULL, 0 };

extern unsigned int lineno;
extern char linebuf[];
extern char conffilebuf[IRCD_BUFSIZE];
extern int yyparse(); /* defined in y.tab.c */

struct conf_parser_context conf_parser_ctx = { 0, 0, NULL };

/* internally defined functions */
static void read_conf(FILE *);
static void clear_out_old_conf(void);
static void expire_tklines(dlink_list *);
static void garbage_collect_ip_entries(void);
static int hash_ip(struct irc_ssaddr *);
static int verify_access(struct Client *);
static int attach_iline(struct Client *, struct MaskItem *);
static struct ip_entry *find_or_add_ip(struct irc_ssaddr *);
static dlink_list *map_to_list(enum maskitem_type);
static struct MaskItem *find_regexp_kline(const char *[]);
static int find_user_host(struct Client *, char *, char *, char *, unsigned int);


/* usually, with hash tables, you use a prime number...
 * but in this case I am dealing with ip addresses,
 * not ascii strings.
 */
#define IP_HASH_SIZE 0x1000

struct ip_entry
{
  struct irc_ssaddr ip;
  unsigned int count;
  time_t last_attempt;
  struct ip_entry *next;
};

static struct ip_entry *ip_hash_table[IP_HASH_SIZE];
static mp_pool_t *ip_entry_pool = NULL;
static int ip_entries_count = 0;


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
conf_dns_callback(void *vptr, const struct irc_ssaddr *addr, const char *name)
{
  struct MaskItem *conf = vptr;

  conf->dns_pending = 0;

  if (addr != NULL)
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
  if (!conf->dns_pending)
  {
    conf->dns_pending = 1;
    gethost_byname(conf_dns_callback, conf, conf->host);
  }
}

struct MaskItem *
conf_make(enum maskitem_type type)
{
  struct MaskItem *conf = MyMalloc(sizeof(*conf));
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
  dlink_node *ptr = NULL, *ptr_next = NULL;
  dlink_list *list = NULL;

  if (conf->node.next)
    if ((list = map_to_list(conf->type)))
      dlinkDelete(&conf->node, list);

  MyFree(conf->name);

  if (conf->dns_pending)
    delete_resolver_queries(conf);
  if (conf->passwd != NULL)
    memset(conf->passwd, 0, strlen(conf->passwd));
  if (conf->spasswd != NULL)
    memset(conf->spasswd, 0, strlen(conf->spasswd));

  conf->class = NULL;

  MyFree(conf->passwd);
  MyFree(conf->spasswd);
  MyFree(conf->reason);
  MyFree(conf->user);
  MyFree(conf->host);
  MyFree(conf->regexuser);
  MyFree(conf->regexhost);
#ifdef HAVE_LIBCRYPTO
  MyFree(conf->cipher_list);

  if (conf->rsa_public_key)
    RSA_free(conf->rsa_public_key);
#endif
  DLINK_FOREACH_SAFE(ptr, ptr_next, conf->hub_list.head)
  {
    MyFree(ptr->data);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, conf->leaf_list.head)
  {
    MyFree(ptr->data);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, conf->exempt_list.head)
  {
    struct exempt *exptr = ptr->data;

    MyFree(exptr->name);
    MyFree(exptr->user);
    MyFree(exptr->host);
    MyFree(exptr);
  }

  MyFree(conf);
}

static const struct shared_flags
{
  const unsigned int type;
  const unsigned char letter;
} flag_table[] = {
  { SHARED_KLINE,   'K' },
  { SHARED_UNKLINE, 'U' },
  { SHARED_XLINE,   'X' },
  { SHARED_UNXLINE, 'Y' },
  { SHARED_RESV,    'Q' },
  { SHARED_UNRESV,  'R' },
  { SHARED_LOCOPS,  'L' },
  { SHARED_DLINE,   'D' },
  { SHARED_UNDLINE, 'E' },
  { 0, '\0' }
};

/*
 * inputs	- pointer to client requesting confitem report
 *		- ConfType to report
 * output	- none
 * side effects	-
 */
void
report_confitem_types(struct Client *source_p, enum maskitem_type type)
{
  dlink_node *ptr = NULL, *dptr = NULL;
  struct MaskItem *conf = NULL;
  const struct ClassItem *class = NULL;
  const struct shared_flags *shared = NULL;
  char buf[12];
  char *p = NULL;

  switch (type)
  {
  case CONF_XLINE:
    DLINK_FOREACH(ptr, xconf_items.head)
    {
      conf = ptr->data;

      sendto_one(source_p, form_str(RPL_STATSXLINE),
		 me.name, source_p->name, 
		 conf->until ? "x": "X", conf->count,
		 conf->name, conf->reason);
    }
    break;

#ifdef HAVE_LIBPCRE
  case CONF_RXLINE:
    DLINK_FOREACH(ptr, rxconf_items.head)
    {
      conf = ptr->data;

      sendto_one(source_p, form_str(RPL_STATSXLINE),
                 me.name, source_p->name,
                 "XR", conf->count,
                 conf->name, conf->reason);
    }
    break;

  case CONF_RKLINE:
    DLINK_FOREACH(ptr, rkconf_items.head)
    {
      conf = ptr->data;

      sendto_one(source_p, form_str(RPL_STATSKLINE), me.name,
                 source_p->name, "KR", conf->host, conf->user,
                 conf->reason);
    }
    break;
#endif

  case CONF_ULINE:
    shared = flag_table;
    DLINK_FOREACH(ptr, uconf_items.head)
    {
      conf = ptr->data;

      p = buf;

      *p++ = 'c';
      for (; shared->type; ++shared)
        if (shared->type & conf->flags)
          *p++ = shared->letter;
        else
          *p++ = ToLower(shared->letter);

      sendto_one(source_p, form_str(RPL_STATSULINE),
		 me.name, source_p->name, conf->name,
                 conf->user?conf->user: "*",
		 conf->host?conf->host: "*", buf);
    }

    shared = flag_table;
    DLINK_FOREACH(ptr, cluster_items.head)
    {
      conf = ptr->data;

      p = buf;

      *p++ = 'C';
      for (; shared->type; ++shared)
        if (shared->type & conf->flags)
          *p++ = shared->letter;
        else
          *p++ = ToLower(shared->letter);

      sendto_one(source_p, form_str(RPL_STATSULINE),
                 me.name, source_p->name, conf->name,
                 "*", "*", buf);
    }

    break;

  case CONF_OPER:
    DLINK_FOREACH(ptr, oconf_items.head)
    {
      conf = ptr->data;

      /* Don't allow non opers to see oper privs */
      if (HasUMode(source_p, UMODE_OPER))
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', conf->user, conf->host,
		   conf->name, oper_privs_as_string(conf->port),
		   conf->class ? conf->class->name : "<default>");
      else
	sendto_one(source_p, form_str(RPL_STATSOLINE),
		   me.name, source_p->name, 'O', conf->user, conf->host,
                   conf->name, "0",
		   conf->class ? conf->class->name : "<default>");
    }
    break;

  case CONF_CLASS:
    DLINK_FOREACH(ptr, class_get_list()->head)
    {
      class = ptr->data;
      sendto_one(source_p, form_str(RPL_STATSYLINE),
		 me.name, source_p->name, 'Y',
		 class->name, class->ping_freq,
		 class->con_freq,
		 class->max_total, class->max_sendq,
                 class->max_recvq,
                 class->ref_count,
                 class->number_per_cidr, class->cidr_bitlen_ipv4,
                 class->number_per_cidr, class->cidr_bitlen_ipv6,
                 class->active ? "active" : "disabled");
    }
    break;

  case CONF_SERVICE:
    DLINK_FOREACH(ptr, service_items.head)
    {
      conf = ptr->data;
      sendto_one(source_p, form_str(RPL_STATSSERVICE),
                 me.name, source_p->name, 'S', "*", conf->name, 0, 0);
    }
    break;

  case CONF_SERVER:
    DLINK_FOREACH(ptr, server_items.head)
    {
      p = buf;
      conf = ptr->data;

      buf[0] = '\0';

      if (IsConfAllowAutoConn(conf))
	*p++ = 'A';
      if (IsConfSSL(conf))
        *p++ = 'S';
      if (buf[0] == '\0')
	*p++ = '*';

      *p = '\0';

      /*
       * Allow admins to see actual ips unless hide_server_ips is enabled
       */
      if (!ConfigServerHide.hide_server_ips && HasUMode(source_p, UMODE_ADMIN))
	sendto_one(source_p, form_str(RPL_STATSCLINE),
		   me.name, source_p->name, 'C', conf->host,
		   buf, conf->name, conf->port,
		   conf->class ? conf->class->name : "<default>");
        else
          sendto_one(source_p, form_str(RPL_STATSCLINE),
                     me.name, source_p->name, 'C',
		     "*@127.0.0.1", buf, conf->name, conf->port,
		     conf->class ? conf->class->name : "<default>");
    }
    break;

  case CONF_HUB:
    DLINK_FOREACH(ptr, server_items.head)
    {
      conf = ptr->data;

      DLINK_FOREACH(dptr, conf->hub_list.head)
        sendto_one(source_p, form_str(RPL_STATSHLINE), me.name,
                   source_p->name, 'H', dptr->data, conf->name, 0, "*");
    }

    DLINK_FOREACH(ptr, server_items.head)
    {
      conf = ptr->data;

      DLINK_FOREACH(dptr, conf->leaf_list.head)
        sendto_one(source_p, form_str(RPL_STATSLLINE), me.name,
                   source_p->name, 'L', dptr->data, conf->name, 0, "*");
    }

    break;

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

  return (i < 0 ? 0 : 1);
}

/* verify_access()
 *
 * inputs	- pointer to client to verify
 * output	- 0 if success -'ve if not
 * side effect	- find the first (best) I line to attach.
 */
static int
verify_access(struct Client *client_p)
{
  struct MaskItem *conf = NULL, *rkconf = NULL;
  char non_ident[USERLEN + 1] = { '~', '\0' };
  const char *uhi[3];

  if (IsGotId(client_p))
  {
    conf = find_address_conf(client_p->host, client_p->username,
			     &client_p->localClient->ip,
			     client_p->localClient->aftype,
                             client_p->localClient->passwd);
  }
  else
  {
    strlcpy(non_ident+1, client_p->username, sizeof(non_ident)-1);
    conf = find_address_conf(client_p->host,non_ident,
			     &client_p->localClient->ip,
			     client_p->localClient->aftype,
	                     client_p->localClient->passwd);
  }

  uhi[0] = IsGotId(client_p) ? client_p->username : non_ident;
  uhi[1] = client_p->host;
  uhi[2] = client_p->sockhost;

  rkconf = find_regexp_kline(uhi);

  if (conf != NULL)
  {
    if (IsConfClient(conf) && !rkconf)
    {
      if (IsConfRedir(conf))
      {
        sendto_one(client_p, form_str(RPL_REDIR),
                   me.name, client_p->name,
                   conf->name ? conf->name : "",
                   conf->port);
        return(NOT_AUTHORIZED);
      }

      if (IsConfDoIdentd(conf))
	SetNeedId(client_p);

      /* Thanks for spoof idea amm */
      if (IsConfDoSpoofIp(conf))
      {
        if (!ConfigFileEntry.hide_spoof_ips && IsConfSpoofNotice(conf))
          sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                               "%s spoofing: %s as %s",
                               client_p->name, client_p->host, conf->name);
        strlcpy(client_p->host, conf->name, sizeof(client_p->host));
        SetIPSpoof(client_p);
      }

      return(attach_iline(client_p, conf));
    }
    else if (rkconf || IsConfKill(conf) || (ConfigFileEntry.glines && IsConfGline(conf)))
    {
      /* XXX */
      conf = rkconf ? rkconf : conf;
      if (IsConfGline(conf))
        sendto_one(client_p, ":%s NOTICE %s :*** G-lined", me.name,
                   client_p->name);
      sendto_one(client_p, ":%s NOTICE %s :*** Banned: %s", 
                 me.name, client_p->name, conf->reason);
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
attach_iline(struct Client *client_p, struct MaskItem *conf)
{
  struct ClassItem *class = NULL;
  struct ip_entry *ip_found;
  int a_limit_reached = 0;
  unsigned int local = 0, global = 0, ident = 0;

  ip_found = find_or_add_ip(&client_p->localClient->ip);
  ip_found->count++;
  SetIpHash(client_p);

  if (conf->class == NULL)
    return NOT_AUTHORIZED;  /* If class is missing, this is best */

  class = conf->class;

  count_user_host(client_p->username, client_p->host,
                  &global, &local, &ident);

  /* XXX blah. go down checking the various silly limits
   * setting a_limit_reached if any limit is reached.
   * - Dianora
   */
  if (class->max_total != 0 && class->ref_count >= class->max_total)
    a_limit_reached = 1;
  else if (class->max_perip != 0 && ip_found->count > class->max_perip)
    a_limit_reached = 1;
  else if (class->max_local != 0 && local >= class->max_local)
    a_limit_reached = 1;
  else if (class->max_global != 0 && global >= class->max_global)
    a_limit_reached = 1;
  else if (class->max_ident != 0 && ident >= class->max_ident &&
           client_p->username[0] != '~')
    a_limit_reached = 1;

  if (a_limit_reached)
  {
    if (!IsConfExemptLimits(conf))
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
  ip_entry_pool = mp_pool_new(sizeof(struct ip_entry),
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

  newptr = mp_pool_get(ip_entry_pool);
  memset(newptr, 0, sizeof(*newptr));
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

      mp_pool_release(ptr);
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
        mp_pool_release(ptr);
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
void
detach_conf(struct Client *client_p, enum maskitem_type type)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, client_p->localClient->confs.head)
  {
    struct MaskItem *conf = ptr->data;

    assert(conf->type & (CONF_CLIENT | CONF_OPER | CONF_SERVER));
    assert(conf->ref_count > 0);
    assert(conf->class->ref_count > 0);

    if (!(conf->type & type))
      continue;

    dlinkDelete(ptr, &client_p->localClient->confs);
    free_dlink_node(ptr);

    if (conf->type == CONF_CLIENT)
      remove_from_cidr_check(&client_p->localClient->ip, conf->class);

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
  if (dlinkFind(&client_p->localClient->confs, conf) != NULL)
    return 1;

  if (conf->type == CONF_CLIENT)
    if (cidr_limit_reached(IsConfExemptLimits(conf),
                           &client_p->localClient->ip, conf->class))
      return TOO_MANY;    /* Already at maximum allowed */

  conf->class->ref_count++;
  conf->ref_count++;

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
  struct MaskItem *conf = NULL;

  assert(client_p != NULL);
  assert(host != NULL);

  if (client_p == NULL || host == NULL)
    return 0;

  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;

    if (match(conf->name, name) || match(conf->host, host))
      continue;

    attach_conf(client_p, conf);
    return -1;
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
  dlink_node *ptr;
  struct MaskItem* conf;

  DLINK_FOREACH(ptr, list->head)
  {
    conf = ptr->data;
    
    if (conf->type == type)
    {
      if (conf->name && (irccmp(conf->name, name) == 0 ||
                         !match(conf->name, name)))
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
map_to_list(enum maskitem_type type)
{
  switch(type)
  {
  case CONF_RKLINE:
    return(&rkconf_items);
    break;
  case CONF_RXLINE:
    return(&rxconf_items);
    break;
  case CONF_XLINE:
    return(&xconf_items);
    break;
  case CONF_ULINE:
    return(&uconf_items);
    break;
  case CONF_NRESV:
    return(&nresv_items);
    break;
  case CONF_CRESV:
    return(&resv_channel_list);
  case CONF_OPER:
    return(&oconf_items);
    break;
  case CONF_SERVER:
    return(&server_items);
    break;
  case CONF_SERVICE:
    return(&service_items);
    break;
  case CONF_CLUSTER:
    return(&cluster_items);
    break;
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
 *		- optional flags to match on as well
 * output       - NULL or pointer to found struct MaskItem
 * side effects - looks for a match on name field
 */
struct MaskItem *
find_matching_name_conf(enum maskitem_type type, const char *name, const char *user,
                        const char *host, unsigned int flags)
{
  dlink_node *ptr=NULL;
  struct MaskItem *conf=NULL;
  dlink_list *list_p = map_to_list(type);

  switch (type)
  {
#ifdef HAVE_LIBPCRE
  case CONF_RXLINE:
      DLINK_FOREACH(ptr, list_p->head)
      {
        conf = ptr->data;
        assert(conf->regexuser);

        if (!ircd_pcre_exec(conf->regexuser, name))
          return conf;
      }
      break;
#endif
  case CONF_SERVICE:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      if (EmptyString(conf->name))
        continue;
      if ((name != NULL) && !irccmp(name, conf->name))
        return conf;
    }
    break;

  case CONF_XLINE:
  case CONF_ULINE:
  case CONF_NRESV:
  case CONF_CRESV:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      if (EmptyString(conf->name))
	continue;
      if ((name != NULL) && !match(conf->name, name))
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
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      if ((name != NULL) && !match(name, conf->name))
        return conf;
      else if ((host != NULL) && !match(host, conf->host))
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
  dlink_node *ptr = NULL;
  struct MaskItem *conf;
  dlink_list *list_p = map_to_list(type);

  switch(type)
  {
  case CONF_RXLINE:
  case CONF_XLINE:
  case CONF_ULINE:
  case CONF_NRESV:
  case CONF_CRESV:

    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      if (EmptyString(conf->name))
	continue;
    
      if (irccmp(conf->name, name) == 0)
      {
	if ((user == NULL && (host == NULL)))
	  return (conf);
	if (EmptyString(conf->user) || EmptyString(conf->host))
	  return (conf);
	if (!match(conf->user, user) && !match(conf->host, host))
	  return (conf);
      }
    }
    break;

  case CONF_OPER:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

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
              if (who->localClient->aftype == AF_INET)
                if (match_ipv4(&who->localClient->ip, &conf->addr, conf->bits))
                  if (!conf->class->max_total || conf->class->ref_count < conf->class->max_total)
                    return conf;
              break;
#ifdef IPV6
            case HM_IPV6:
              if (who->localClient->aftype == AF_INET6)
                if (match_ipv6(&who->localClient->ip, &conf->addr, conf->bits))
                  if (!conf->class->max_total || conf->class->ref_count < conf->class->max_total)
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

  case CONF_SERVER:
    DLINK_FOREACH(ptr, list_p->head)
    {
      conf = ptr->data;

      if (EmptyString(conf->name))
	continue;
    
      if (name == NULL)
      {
	if (EmptyString(conf->host))
	  continue;
	if (irccmp(conf->host, host) == 0)
	  return(conf);
      }
      else if (irccmp(conf->name, name) == 0)
      {
	  return (conf);
      }
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

  rehashed_klines = 1;

  return 0;
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
  ServerInfo.rsa_private_key = NULL;
  ServerInfo.rsa_private_key_file = NULL;
#endif

  /* ServerInfo.name is not rehashable */
  /* ServerInfo.name = ServerInfo.name; */
  ServerInfo.description = NULL;
  ServerInfo.network_name = xstrdup(NETWORK_NAME_DEFAULT);
  ServerInfo.network_desc = xstrdup(NETWORK_DESC_DEFAULT);

  memset(&ServerInfo.ip, 0, sizeof(ServerInfo.ip));
  ServerInfo.specific_ipv4_vhost = 0;
  memset(&ServerInfo.ip6, 0, sizeof(ServerInfo.ip6));
  ServerInfo.specific_ipv6_vhost = 0;

  ServerInfo.max_clients = MAXCLIENTS_MAX;
  ServerInfo.max_nick_length = 9;
  ServerInfo.max_topic_length = 80;

  ServerInfo.hub = 0;
  ServerInfo.dns_host.sin_addr.s_addr = 0;
  ServerInfo.dns_host.sin_port = 0;
  AdminInfo.name = NULL;
  AdminInfo.email = NULL;
  AdminInfo.description = NULL;

  log_del_all();

  ConfigLoggingEntry.use_logging = 1;

  ConfigChannel.disable_fake_channels = 0;
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
  ConfigServerHide.hide_services = 0;
  ConfigServerHide.hidden_name = xstrdup(NETWORK_NAME_DEFAULT);
  ConfigServerHide.hide_server_ips = 0;

  
  ConfigFileEntry.service_name = xstrdup(SERVICE_NAME_DEFAULT);
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
    ServerInfo.network_name = xstrdup(NETWORK_NAME_DEFAULT);

  if (ServerInfo.network_desc == NULL)
    ServerInfo.network_desc = xstrdup(NETWORK_DESC_DEFAULT);

  if (ConfigFileEntry.service_name == NULL)
    ConfigFileEntry.service_name = xstrdup(SERVICE_NAME_DEFAULT);

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
  class_delete_marked();      /* Make sure classes are valid */
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

  /* Do name lookup now on hostnames given and store the
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

  assert(res != NULL);

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
  struct ip_entry *ip_found;
  struct MaskItem *conf = find_dline_conf(addr, aftype);

  /* DLINE exempt also gets you out of static limits/pacing... */
  if (conf && (conf->type == CONF_EXEMPT))
    return 0;

  if (conf != NULL)
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

static struct MaskItem *
find_regexp_kline(const char *uhi[])
{
#ifdef HAVE_LIBPCRE
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, rkconf_items.head)
  {
    struct MaskItem *aptr = ptr->data;

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
 * output	- pointer to struct MaskItem if found
 * side effects	- See if this user is klined already,
 *		  and if so, return struct MaskItem pointer
 */
struct MaskItem *
find_kill(struct Client *client_p)
{
  struct MaskItem *conf = NULL;
  const char *uhi[3];

  uhi[0] = client_p->username;
  uhi[1] = client_p->host;
  uhi[2] = client_p->sockhost;

  assert(client_p != NULL);

  conf = find_conf_by_address(client_p->host, &client_p->localClient->ip,
                              CONF_KLINE, client_p->localClient->aftype,
                              client_p->username, NULL, 1);
  if (conf == NULL)
    conf = find_regexp_kline(uhi);

  return conf;
}

struct MaskItem *
find_gline(struct Client *client_p)
{
  struct MaskItem *conf;

  assert(client_p != NULL);

  conf = find_conf_by_address(client_p->host, &client_p->localClient->ip,
                              CONF_GLINE, client_p->localClient->aftype,
                              client_p->username, NULL, 1);
  return conf;
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
  expire_tklines(&nresv_items);
  expire_tklines(&resv_channel_list);
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
  struct MaskItem *conf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, tklist->head)
  {
    conf = ptr->data;

    if (!conf->until || conf->until > CurrentTime)
      continue;

    if (conf->type == CONF_XLINE)
    {
      if (ConfigFileEntry.tkline_expire_notices)
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                               "Temporary X-line for [%s] expired", conf->name);
      conf_free(conf);
    }
    else if (conf->type == CONF_NRESV || conf->type == CONF_CRESV)
    {
      if (ConfigFileEntry.tkline_expire_notices)
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                               "Temporary RESV for [%s] expired", conf->name);
      conf_free(conf);
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
  const unsigned int flag;
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
  const struct oper_privs *opriv = flag_list;

  for (; opriv->flag; ++opriv)
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
      struct MaskItem *conf = cnode->data;

      if (IsConfOperator(conf))
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

  log_reopen_all();

  add_isupport("NICKLEN", NULL, ServerInfo.max_nick_length);
  add_isupport("NETWORK", ServerInfo.network_name, -1);

  snprintf(chanmodes, sizeof(chanmodes), "beI:%d", ConfigChannel.max_bans);
  add_isupport("MAXLIST", chanmodes, -1);
  add_isupport("MAXTARGETS", NULL, ConfigFileEntry.max_targets);
  add_isupport("CHANTYPES", "#", -1);

  snprintf(chanlimit, sizeof(chanlimit), "#:%d",
           ConfigChannel.max_chans_per_user);
  add_isupport("CHANLIMIT", chanlimit, -1);
  snprintf(chanmodes, sizeof(chanmodes), "%s", "beI,k,l,imnprstORS");
  add_isupport("CHANNELLEN", NULL, LOCAL_CHANNELLEN);
  add_isupport("TOPICLEN", NULL, ServerInfo.max_topic_length);
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
  struct MaskItem *conf;
  dlink_list *free_items [] = {
    &server_items,   &oconf_items,
     &uconf_items,   &xconf_items, &rxconf_items, &rkconf_items,
     &nresv_items, &cluster_items,  &service_items, &resv_channel_list, NULL
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

      dlinkDelete(&conf->node, map_to_list(conf->type));

      /* XXX This is less than pretty */
      if (conf->type == CONF_SERVER || conf->type == CONF_OPER)
      {
        if (!conf->ref_count)
	  conf_free(conf);
      }
      else if (conf->type == CONF_XLINE  ||
               conf->type == CONF_RXLINE ||
               conf->type == CONF_RKLINE)
      {
        if (!conf->until)
          conf_free(conf);
      }
      else
        conf_free(conf);
    }
  }

  /*
   * don't delete the class table, rather mark all entries
   * for deletion. The table is cleaned up by class_delete_marked. - avalon
   */
  class_mark_for_deletion();

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

  /* clean out AdminInfo */
  MyFree(AdminInfo.name);
  AdminInfo.name = NULL;
  MyFree(AdminInfo.email);
  AdminInfo.email = NULL;
  MyFree(AdminInfo.description);
  AdminInfo.description = NULL;

  /* clean out listeners */
  close_listeners();

  /* clean out general */
  MyFree(ConfigFileEntry.service_name);
  ConfigFileEntry.service_name = NULL;

  delete_isupport("INVEX");
  delete_isupport("EXCEPTS");
}

/* conf_add_class_to_conf()
 *
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a class pointer to a conf 
 */
void
conf_add_class_to_conf(struct MaskItem *conf, const char *class_name)
{
  if (class_name == NULL) 
  {
    conf->class = class_default;

    if (conf->type == CONF_CLIENT)
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s@%s",
			   conf->user, conf->host);
    else
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s",
			   conf->name);
  }
  else
    conf->class = class_find(class_name, 1);

  if (conf->class == NULL)
  {
    if (conf->type == CONF_CLIENT)
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s@%s",
			   conf->user, conf->host);
    else
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
			   "Warning *** Defaulting to default class for %s",
			   conf->name);
    conf->class = class_default;
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
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
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
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
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
match_conf_password(const char *password, const struct MaskItem *conf)
{
  const char *encr = NULL;

  if (EmptyString(password) || EmptyString(conf->passwd))
    return 0;

  if (conf->flags & CONF_FLAGS_ENCRYPTED)
    encr = crypt(password, conf->passwd);
  else
    encr = password;

  return !strcmp(encr, conf->passwd);
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
    const struct MaskItem *conf = ptr->data;

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
