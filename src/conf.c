/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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
 */

#include "stdinc.h"
#include "address.h"
#include "fdlist.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "misc.h"
#include "module.h"
#include "res.h"
#include "reslib.h"
#include "defaults.h"
#include "ircd_defs.h"
#include "parse.h"
#include "channel.h"
#include "channel_mode.h"
#include "cloak.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_db.h"
#include "conf_gecos.h"
#include "conf_parser.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "client.h"
#include "ipcache.h"
#include "ircd.h"
#include "isupport.h"
#include "listener.h"
#include "motd.h"
#include "numeric.h"
#include "send.h"
#include "server.h"
#include "user.h"
#include "whowas.h"

/* Hashtable stuff...now external as it's used in m_stats.c */
list_t atable[ADDRESS_HASHSIZE];

/* general conf items link list root, other than k lines etc. */
list_t connect_items;
list_t operator_items;

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

/* struct MaskItem *find_conf_by_address(const char *, struct io_addr *,
 *                                         int type, int fam, const char *username)
 * Input: The hostname, the address, the type of mask to find, the address
 *        family, the username.
 * Output: The matching value with the highest precedence.
 * Side-effects: None
 * Note: Setting bit 0 of the type means that the username is ignored.
 * Warning: IsNeedPassword for everything that is not an auth{} entry
 * should always be true (i.e. conf->flags & CONF_FLAGS_NEED_PASSWORD == 0)
 */
struct MaskItem *
find_conf_by_address(const char *name, const struct io_addr *addr, unsigned int type,
                     const char *username, const char *password, int do_match)
{
  unsigned int hprecv = 0;
  list_node_t *node;
  struct MaskItem *hprec = NULL;
  struct AddressRec *arec = NULL;
  int (*cmpfunc)(const char *, const char *) = do_match ? match : irccmp;

  if (addr)
  {
    /* Check for IPV6 matches... */
    if (address_is_ipv6(addr))
    {
      for (int b = 128; b >= 0; b -= 16)
      {
        LIST_FOREACH(node, atable[hash_ipv6(addr, b)].head)
        {
          arec = node->data;

          if ((arec->type == type) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV6 &&
              address_match_ipv6(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (!username || !cmpfunc(arec->username, username)) &&
              (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
               conf_match_password(password, arec->conf)))
          {
            hprecv = arec->precedence;
            hprec = arec->conf;
          }
        }
      }
    }
    else if (address_is_ipv4(addr))
    {
      for (int b = 32; b >= 0; b -= 8)
      {
        LIST_FOREACH(node, atable[hash_ipv4(addr, b)].head)
        {
          arec = node->data;

          if ((arec->type == type) &&
              arec->precedence > hprecv &&
              arec->masktype == HM_IPV4 &&
              address_match_ipv4(addr, &arec->Mask.ipa.addr,
                         arec->Mask.ipa.bits) &&
              (!username || !cmpfunc(arec->username, username)) &&
              (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
               conf_match_password(password, arec->conf)))
          {
            hprecv = arec->precedence;
            hprec = arec->conf;
          }
        }
      }
    }
  }

  if (name)
  {
    const char *p = name;

    while (true)
    {
        LIST_FOREACH(node, atable[hash_text(p)].head)
        {
          arec = node->data;
          if ((arec->type == type) &&
            arec->precedence > hprecv &&
            (arec->masktype == HM_HOST) &&
            !cmpfunc(arec->Mask.hostname, name) &&
            (!username || !cmpfunc(arec->username, username)) &&
            (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
             conf_match_password(password, arec->conf)))
        {
          hprecv = arec->precedence;
          hprec = arec->conf;
        }
      }

      if ((p = strchr(p, '.')) == NULL)
        break;
      ++p;
    }

    LIST_FOREACH(node, atable[0].head)
    {
      arec = node->data;

      if (arec->type == type &&
          arec->precedence > hprecv &&
          arec->masktype == HM_HOST &&
          !cmpfunc(arec->Mask.hostname, name) &&
          (!username || !cmpfunc(arec->username, username)) &&
          (IsNeedPassword(arec->conf) || arec->conf->passwd == NULL ||
           conf_match_password(password, arec->conf)))
      {
        hprecv = arec->precedence;
        hprec = arec->conf;
      }
    }
  }

  return hprec;
}

/* struct MaskItem* find_address_conf(const char*, const char*,
 * 	                               struct io_addr*, int, char *);
 * Input: The hostname, username, address, address family.
 * Output: The applicable MaskItem.
 * Side-effects: None
 */
struct MaskItem *
find_address_conf(const char *host, const char *user, const struct io_addr *addr, const char *password)
{
  struct MaskItem *authcnf = NULL, *killcnf = NULL;

  /* Find the best auth{} block... If none, return NULL -A1kmm */
  if ((authcnf = find_conf_by_address(host, addr, CONF_CLIENT, user, password, 1)) == NULL)
    return NULL;

  /* If they are exempt from K-lines, return the best auth{} block. -A1kmm */
  if (IsConfExemptKline(authcnf))
    return authcnf;

  /* Find the best K-line... -A1kmm */
  killcnf = find_conf_by_address(host, addr, CONF_KLINE, user, NULL, 1);

  /*
   * If they are K-lined, return the K-line. Otherwise, return the
   * auth {} block. -A1kmm
   */
  if (killcnf)
    return killcnf;

  return authcnf;
}

/* struct MaskItem* find_dline_conf(struct io_addr*, int)
 *
 * Input:	An address, an address family.
 * Output:	The best matching D-line or exempt line.
 * Side effects: None.
 */
struct MaskItem *
find_dline_conf(const struct io_addr *addr)
{
  struct MaskItem *eline;

  eline = find_conf_by_address(NULL, addr, CONF_EXEMPT, NULL, NULL, 1);
  if (eline)
    return eline;

  return find_conf_by_address(NULL, addr, CONF_DLINE, NULL, NULL, 1);
}

/* void add_conf_by_address(int, struct MaskItem *aconf)
 * Input:
 * Output: None
 * Side-effects: Adds this entry to the hash table.
 */
struct AddressRec *
add_conf_by_address(const unsigned int type, struct MaskItem *conf)
{
  const char *const hostname = conf->host;
  const char *const username = conf->user;
  static unsigned int prec_value = UINT_MAX;
  int bits = 0;

  assert(type && !string_is_empty(hostname));

  struct AddressRec *arec = io_calloc(sizeof(*arec));
  arec->masktype = address_parse_netmask(hostname, &arec->Mask.ipa.addr, &bits);
  arec->Mask.ipa.bits = bits;
  arec->username = username;
  arec->conf = conf;
  arec->precedence = prec_value--;
  arec->type = type;

  switch (arec->masktype)
  {
    case HM_IPV4:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 8;
      list_add(arec, &arec->node, &atable[hash_ipv4(&arec->Mask.ipa.addr, bits)]);
      break;
    case HM_IPV6:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 16;
      list_add(arec, &arec->node, &atable[hash_ipv6(&arec->Mask.ipa.addr, bits)]);
      break;
    default: /* HM_HOST */
      arec->Mask.hostname = hostname;
      list_add(arec, &arec->node, &atable[get_mask_hash(hostname)]);
      break;
  }

  return arec;
}

/* void delete_one_address(const char*, struct MaskItem*)
 * Input: An address string, the associated MaskItem.
 * Output: None
 * Side effects: Deletes an address record. Frees the MaskItem if there
 *               is nothing referencing it, sets it as illegal otherwise.
 */
void
delete_one_address_conf(const char *address, struct MaskItem *conf)
{
  int bits = 0;
  uint32_t hv = 0;
  list_node_t *node;
  struct io_addr addr;

  switch (address_parse_netmask(address, &addr, &bits))
  {
    case HM_IPV4:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 8;
      hv = hash_ipv4(&addr, bits);
      break;
    case HM_IPV6:
      /* We have to do this, since we do not re-hash for every bit -A1kmm. */
      bits -= bits % 16;
      hv = hash_ipv6(&addr, bits);
      break;
    default: /* HM_HOST */
      hv = get_mask_hash(address);
      break;
  }

  LIST_FOREACH(node, atable[hv].head)
  {
    struct AddressRec *arec = node->data;

    if (arec->conf == conf)
    {
      list_remove(&arec->node, &atable[hv]);

      if (conf->ref_count == 0)
        conf_free(conf);

      io_free(arec);
      return;
    }
  }
}

/* void clear_out_address_conf(void)
 * Input: None
 * Output: None
 * Side effects: Clears out all address records in the hash table,
 *               frees them, and frees the MaskItems if nothing references
 *               them, otherwise sets them as illegal.
 */
static void
clear_out_address_conf(void)
{
  list_node_t *node, *node_next;

  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    LIST_FOREACH_SAFE(node, node_next, atable[i].head)
    {
      struct AddressRec *arec = node->data;

      /*
       * Destroy the ircd.conf items and keep those that are in the databases
       */
      if (IsConfDatabase(arec->conf))
        continue;

      list_remove(&arec->node, &atable[i]);
      arec->conf->active = false;

      if (arec->conf->ref_count == 0)
        conf_free(arec->conf);
      io_free(arec);
    }
  }
}

static void
hostmask_send_expiration(const struct AddressRec *const arec)
{
  char ban_type = '?';

  switch (arec->type)
  {
    case CONF_KLINE:
      ban_type = 'K';
      break;
    case CONF_DLINE:
      ban_type = 'D';
      break;
    default: break;
  }

  sendto_clients(UMODE_EXPIRATION, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Temporary %c-line for [%s@%s] expired", ban_type,
                 (arec->conf->user) ? arec->conf->user : "*",
                 (arec->conf->host) ? arec->conf->host : "*");
}

static void
hostmask_expire_temporary(void)
{
  list_node_t *node, *node_next;

  for (unsigned int i = 0; i < ADDRESS_HASHSIZE; ++i)
  {
    LIST_FOREACH_SAFE(node, node_next, atable[i].head)
    {
      struct AddressRec *arec = node->data;

      if (arec->conf->until == 0 || arec->conf->until > io_time_get(IO_TIME_REALTIME_SEC))
        continue;

      switch (arec->type)
      {
        case CONF_KLINE:
        case CONF_DLINE:
          hostmask_send_expiration(arec);

          list_remove(&arec->node, &atable[i]);
          conf_free(arec->conf);
          io_free(arec);
          break;
        default: break;
      }
    }
  }
}

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
conf_dns_callback(void *vptr, const struct io_addr *addr, const char *name, size_t namelength)
{
  struct MaskItem *const conf = vptr;

  conf->dns_pending = false;

  if (addr)
    address_copy(conf->addr, addr);
  else
    conf->dns_failed = true;
}

/* conf_resolve_host()
 *
 * start DNS lookups of all hostnames in the conf
 * line and convert an IP addresses in a.b.c.d number for to IP#s.
 */
void
conf_dns_lookup(struct MaskItem *conf)
{
  if (address_from_string(conf->host, conf->addr))
    return;

  /*
   * By this point conf->host possibly is not a numerical network address. Do a nameserver
   * lookup of the conf host. If the conf entry is currently doing a ns lookup do nothing.
   */
  if (conf->dns_pending)
    return;

  conf->dns_pending = true;

  if (conf->aftype == AF_INET)
    gethost_byname_type(conf_dns_callback, conf, conf->host, T_A);
  else
    gethost_byname_type(conf_dns_callback, conf, conf->host, T_AAAA);
}

/* map_to_list()
 *
 * inputs       - ConfType conf
 * output       - pointer to list_t to use
 * side effects - none
 */
static list_t *
map_to_list(enum maskitem_type type)
{
  switch (type)
  {
    case CONF_OPER:
      return &operator_items;
    case CONF_SERVER:
      return &connect_items;
    default:
      return NULL;
  }
}

struct MaskItem *
conf_make(enum maskitem_type type)
{
  struct MaskItem *const conf = io_calloc(sizeof(*conf));
  list_t *list = NULL;

  conf->type   = type;
  conf->active = true;
  conf->aftype = AF_INET;

  if ((list = map_to_list(type)))
    list_add(conf, &conf->node, list);
  return conf;
}

void
conf_free(struct MaskItem *conf)
{
  list_t *list = map_to_list(conf->type);
  if (list)
    list_find_remove(list, conf);

  if (conf->dns_pending)
    delete_resolver_queries(conf);

  if (conf->passwd)
    memset(conf->passwd, 0, strlen(conf->passwd));
  if (conf->spasswd)
    memset(conf->spasswd, 0, strlen(conf->spasswd));

  conf->class = NULL;

  io_free(conf->name);
  io_free(conf->passwd);
  io_free(conf->spasswd);
  io_free(conf->reason);
  io_free(conf->certfp);
  io_free(conf->whois);
  io_free(conf->modes);
  io_free(conf->user);
  io_free(conf->host);
  io_free(conf->addr);
  io_free(conf->bind);
  io_free(conf->cipher_list);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, conf->hub_list.head)
  {
    io_free(node->data);
    list_remove(node, &conf->hub_list);
    list_free_node(node);
  }

  LIST_FOREACH_SAFE(node, node_next, conf->leaf_list.head)
  {
    io_free(node->data);
    list_remove(node, &conf->leaf_list);
    list_free_node(node);
  }

  io_free(conf);
}

/* conf_attach_auth()
 *
 * inputs       - client pointer
 *              - conf pointer
 * output       -
 * side effects - do actual attach
 */
static int
conf_attach_auth(struct Client *client, struct MaskItem *conf)
{
  const struct ClassItem *const class = conf->class;
  bool a_limit_reached = false;

  struct ip_entry *ipcache = ipcache_record_find_or_add(&client->addr);
  ++ipcache->count_local;
  AddFlag(client, FLAGS_IPHASH);

  if (class->max_total && class->ref_count >= class->max_total)
    a_limit_reached = true;
  else if (class->max_perip_local && ipcache->count_local > class->max_perip_local)
    a_limit_reached = true;
  else if (class->max_perip_global &&
           (ipcache->count_local + ipcache->count_remote) > class->max_perip_global)
    a_limit_reached = true;
  else if (class_ip_limit_add(conf->class, &client->addr, IsConfExemptLimits(conf)))
    a_limit_reached = true;

  if (a_limit_reached)
    if (!IsConfExemptLimits(conf))
      return TOO_MANY;   /* Already at maximum allowed */

  return conf_attach(client, conf);
}

/* verify_access()
 *
 * inputs       - pointer to client to verify
 * output       - 0 if success -'ve if not
 * side effect  - find the first (best) I line to attach.
 */
static int
verify_access(struct Client *client)
{
  char username[USERLEN + 1] = "~";

  if (HasFlag(client, FLAGS_GOTID))
    strlcpy(username, client->username, sizeof(username));
  else
    strlcpy(username + 1, client->username, sizeof(username) - 1);

  struct MaskItem *conf = find_address_conf(client->host, username, &client->addr,
                                            client->connection->password);
  if (conf == NULL)
    return NOT_AUTHORIZED;

  assert(IsConfClient(conf) || IsConfKill(conf));

  if (IsConfKill(conf))
  {
    sendto_one_notice(client, &me, ":*** Banned: %s", conf->reason);
    return BANNED_CLIENT;
  }

  if (IsConfRedir(conf))
  {
    sendto_one_numeric(client, &me, RPL_REDIR,
                       string_or_empty(conf->name), conf->port);
    return NOT_AUTHORIZED;
  }

  if (!HasFlag(client, FLAGS_GOTID) && !IsNoTilde(conf))
    strlcpy(client->username, username, sizeof(client->username));

  /* Preserve x->host in x->realhost before it gets overwritten. */
  strlcpy(client->realhost, client->host, sizeof(client->realhost));

  if (IsConfDoSpoofIp(conf))
  {
    strlcpy(client->host, conf->name, sizeof(client->host));
    AddFlag(client, FLAGS_SPOOF);
  }

  return conf_attach_auth(client, conf);
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
bool
conf_check_client(struct Client *client)
{
  const char *error = NULL;
  bool warn = true;

  switch (verify_access(client))
  {
    case TOO_MANY:
      error = "too many connections on IP";
      break;
    case I_LINE_FULL:
      error = "connection class is full";
      break;
    case NOT_AUTHORIZED:
      error = "not authorized";
      break;
    case BANNED_CLIENT:
      error = "banned from server";
      warn = false;
      break;
  }

  if (error)
  {
    ++ServerStats.is_ref;

    if (warn)
      sendto_clients(UMODE_REJ, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Rejecting client connection from %s: %s",
                     client_get_name(client, SHOW_IP), error);

    log_write(LOG_TYPE_IRCD, "Rejecting client connection from %s: %s",
         client_get_name(client, SHOW_IP), error);
    client_exit_fmt(client, "Connection rejected - %s", error);
    return false;
  }

  return true;
}

/*! \brief Disassociate configuration from the client. Also removes a class
 *         from the list if marked for deleting.
 * \param client Client to operate on
 * \param type     Type of conf to detach
 */
void
conf_detach(struct Client *client, enum maskitem_type type)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, client->connection->confs.head)
  {
    struct MaskItem *conf = node->data;

    assert(conf->type & (CONF_CLIENT | CONF_OPER | CONF_SERVER));
    assert(conf->ref_count > 0);
    assert(conf->class->ref_count > 0);

    if (!(conf->type & type))
      continue;

    list_remove(node, &client->connection->confs);
    list_free_node(node);

    if (conf->type == CONF_CLIENT)
      class_ip_limit_remove(conf->class, &client->addr);

    if (--conf->class->ref_count == 0 && conf->class->active == false)
    {
      class_free(conf->class);
      conf->class = NULL;
    }

    if (--conf->ref_count == 0 && conf->active == false)
      conf_free(conf);
  }
}

/*! \brief Associate a specific configuration entry to a *local* client (this
 *         is the one which used in accepting the connection). Note, that this
 *         automatically changes the attachment if there was an old one.
 * \param client Client to attach the conf to
 * \param conf Configuration record to attach
 */
int
conf_attach(struct Client *client, struct MaskItem *conf)
{
  if (list_find(&client->connection->confs, conf))
    return 1;

  conf->class->ref_count++;
  conf->ref_count++;

  list_add(conf, list_make_node(), &client->connection->confs);

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
find_conf_name(list_t *list, const char *name, enum maskitem_type type)
{
  list_node_t *node;

  LIST_FOREACH(node, list->head)
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

/*! \brief Find a connect {} conf that has a name that matches \a name.
 * \param name Name to match
 * \param compare Pointer to function to be used for string matching
 */
struct MaskItem *
connect_find(const char *name, int (*compare)(const char *, const char *))
{
  list_node_t *node;

  LIST_FOREACH(node, connect_items.head)
  {
    struct MaskItem *conf = node->data;

    if (compare(name, conf->name) == 0)
      return conf;
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
operator_find(const struct Client *client, const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, operator_items.head)
  {
    struct MaskItem *conf = node->data;

    if (irccmp(conf->name, name) == 0)
    {
      if (client == NULL)
        return conf;

      if (conf->class->max_total &&
          conf->class->max_total <= conf->class->ref_count)
        continue;

      if (match(conf->user, client->username) == 0)
      {
        switch (conf->htype)
        {
          case HM_HOST:
            if (match(conf->host, client->realhost) == 0 ||
                match(conf->host, client->sockhost) == 0 || match(conf->host, client->host) == 0)
              return conf;
            break;
          case HM_IPV6:
          case HM_IPV4:
            if (address_match(&client->addr, conf->addr, false, false, conf->bits))
              return conf;
            break;
          default:
            assert(0);
        }
      }
    }
  }

  return NULL;
}

/* conf_set_defaults()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- Set default values here.
 *		  This is called **PRIOR** to parsing the
 *		  configuration file.  If you want to do some validation
 *		  of values later, put them in validate_conf().
 */
static void
conf_set_defaults(void)
{
  /* Verify class_init() ran. */
  assert(class_default == list_peek_tail(class_get_list()));

  ConfigServerInfo.network_name = io_strdup(NETWORK_NAME_DEFAULT);
  ConfigServerInfo.network_description = io_strdup(NETWORK_DESCRIPTION_DEFAULT);
  ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  ConfigServerInfo.max_nick_length = 9;
  ConfigServerInfo.max_topic_length = TOPICLEN;
  ConfigServerInfo.hub = 0;

  ConfigLog.use_logging = 1;

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
  ConfigServerHide.hidden = 0;
  ConfigServerHide.hide_servers = 0;
  ConfigServerHide.hide_services = 0;
  ConfigServerHide.hidden_name = io_strdup(NETWORK_NAME_DEFAULT);
  ConfigServerHide.hide_server_ips = 0;
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
  ConfigGeneral.disable_auth = 0;
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
  ConfigGeneral.ident_timeout = 4;

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

/* conf_read()
 *
 * inputs       - file descriptor pointing to config file to use
 * output       - None
 * side effects	- Read configuration file.
 */
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
  class_delete_marked();  /* Delete unused classes that are marked for deletion */
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

  restart_resolver();

  /* don't close listeners until we know we can go ahead with the rehash */

  conf_read_files(false);

  module_load_all(NULL);

  check_conf_klines();
}

/* conf_connect_allowed()
 *
 * inputs	- pointer to inaddr
 *		- int type ipv4 or ipv6
 * output	- BANNED or accepted
 * side effects	- none
 */
int
conf_connect_allowed(struct io_addr *addr)
{
  const struct MaskItem *conf = find_dline_conf(addr);

  if (conf)
  {
    /* DLINE exempt also gets you out of static limits/pacing... */
    if (conf->type == CONF_EXEMPT)
      return 0;
    return BANNED_CLIENT;
  }

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
  gecos_expire();
  resv_expire();
}

/*
 * Input: A client to find the active operator {} name for.
 * Output: The nick!user@host{oper} of the oper.
 *         "oper" is server name for remote opers
 * Side effects: None.
 */
const char *
get_oper_name(const struct Client *client)
{
  static char buf[IRCD_BUFSIZE];

  if (IsServer(client))
    return client->name;

  if (MyConnect(client))
  {
    const struct MaskItem *conf = list_peek_head(&client->connection->confs);
    if (conf && (conf->type == CONF_OPER))
    {
      snprintf(buf, sizeof(buf), "%s!%s@%s{%s}",
               client->name, client->username, client->host, conf->name);
      return buf;
    }

    /*
     * Probably should assert here for now. If there is an oper out there
     * with no operator {} conf attached, it would be good for us to know...
     */
    assert(0);  /* Oper without oper conf! */
  }

  snprintf(buf, sizeof(buf), "%s!%s@%s{%s}", client->name,
           client->username, client->host, client->servptr->name);
  return buf;
}

/* conf_clear()
 *
 * inputs       - none
 * output       - none
 * side effects - Clear out the old configuration
 */
static void
conf_clear(void)
{
  list_t *free_items [] = { &connect_items, &operator_items, NULL };

  /* We only need to free anything allocated by yyparse() here.
   * Resetting structs, etc, is taken care of by conf_set_defaults().
   */

  for (list_t ** iterator = free_items; *iterator; iterator++)
  {
    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, (*iterator)->head)
    {
      struct MaskItem *conf = node->data;

      conf->active = false;
      list_remove(&conf->node, *iterator);

      if (!conf->ref_count)
        conf_free(conf);
    }
  }

  /*
   * Don't delete the class table, rather mark all entries for deletion.
   * The table is cleaned up by class_delete_marked. - avalon
   */
  class_mark_for_deletion();

  clear_out_address_conf();

  module_config_clear();  /* Clear loadmodule items */

  motd_clear();  /* Clear motd {} items and re-cache default motd */

  cluster_clear();  /* Clear cluster {} items */

  gecos_clear();  /* Clear gecos {} items */

  resv_clear();  /* Clear resv {} items */

  service_clear();  /* Clear service {} items */

  shared_clear();  /* Clear shared {} items */

  pseudo_clear();  /* Clear pseudo {} items */

  log_clear();

  /* Clean out ConfigServerInfo */
  io_free(ConfigServerInfo.description);
  ConfigServerInfo.description = NULL;
  io_free(ConfigServerInfo.network_name);
  ConfigServerInfo.network_name = NULL;
  io_free(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = NULL;
  io_free(ConfigServerInfo.rsa_private_key_file);
  ConfigServerInfo.rsa_private_key_file = NULL;
  io_free(ConfigServerInfo.tls_certificate_file);
  ConfigServerInfo.tls_certificate_file = NULL;
  io_free(ConfigServerInfo.tls_dh_param_file);
  ConfigServerInfo.tls_dh_param_file = NULL;
  io_free(ConfigServerInfo.tls_supported_groups);
  ConfigServerInfo.tls_supported_groups = NULL;
  io_free(ConfigServerInfo.tls_cipher_list);
  ConfigServerInfo.tls_cipher_list = NULL;
  io_free(ConfigServerInfo.tls_cipher_suites);
  ConfigServerInfo.tls_cipher_suites = NULL;
  io_free(ConfigServerInfo.tls_message_digest_algorithm);
  ConfigServerInfo.tls_message_digest_algorithm = NULL;
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

static void
conf_handle_tls(bool cold)
{
  if (tls_new_credentials() == false)
  {
    if (cold)
    {
      log_write(LOG_TYPE_IRCD, "Error while initializing TLS");
      exit(EXIT_FAILURE);
    }
    else
    {
      /* Failed to load new settings/certs, old ones remain active */
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                     "Error reloading TLS settings, check the ircd log"); // report_crypto_errors logs this
    }
  }
}

/* read_conf_files()
 *
 * inputs       - cold start YES or NO
 * output       - none
 * side effects - read all conf files needed, ircd.conf kline.conf etc.
 */
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

/* conf_assign_class()
 *
 * inputs       - pointer to config item
 * output       - NONE
 * side effects - Add a class pointer to a conf
 */
void
conf_assign_class(struct MaskItem *conf, const char *name)
{
  if (string_is_empty(name) || (conf->class = class_find(name, true)) == NULL)
  {
    conf->class = class_default;

    if (conf->type == CONF_CLIENT || conf->type == CONF_OPER)
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                     "Warning *** Defaulting to default class for %s@%s",
                     conf->user, conf->host);
    else
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
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

/* conf_match_password()
 *
 * inputs       - pointer to given password
 *              - pointer to Conf
 * output       - 1 or 0 if match
 * side effects - none
 */
bool
conf_match_password(const char *password, const struct MaskItem *conf)
{
  if (string_is_empty(password) || string_is_empty(conf->passwd))
    return false;

  const char *encr;
  if (conf->flags & CONF_FLAGS_ENCRYPTED)
    encr = crypt(password, conf->passwd);
  else
    encr = password;

  return encr && strcmp(encr, conf->passwd) == 0;
}
