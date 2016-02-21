/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file s_serv.c
 * \brief Server related functions.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "s_bsd.h"
#include "packet.h"
#include "conf.h"
#include "server.h"
#include "log.h"
#include "send.h"
#include "memory.h"
#include "parse.h"


dlink_list flatten_links;
static dlink_list server_capabilities_list;
static void serv_connect_callback(fde_t *, int, void *);


/*
 * write_links_file
 *
 * inputs	- void pointer which is not used
 * output	- NONE
 * side effects	- called from an event, write out list of linked servers
 *		  but in no particular order.
 */
void
write_links_file(void *unused)
{
  FILE *file = NULL;
  dlink_node *node = NULL, *node_next = NULL;
  char buff[IRCD_BUFSIZE] = "";

  if (EmptyString(ConfigServerHide.flatten_links_file))
    return;

  if ((file = fopen(ConfigServerHide.flatten_links_file, "w")) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s", ConfigServerHide.flatten_links_file,
         strerror(errno));
    return;
  }

  DLINK_FOREACH_SAFE(node, node_next, flatten_links.head)
  {
    dlinkDelete(node, &flatten_links);
    xfree(node->data);
    free_dlink_node(node);
  }

  DLINK_FOREACH(node, global_server_list.head)
  {
    const struct Client *target_p = node->data;

    /*
     * Skip hidden servers, aswell as ourselves, since we already send
     * ourselves in /links
     */
    if (IsHidden(target_p) || IsMe(target_p))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      continue;

    /*
     * Attempt to format the file in such a way it follows the usual links output
     * ie  "servername uplink :hops info"
     * Mostly for aesthetic reasons - makes it look pretty in mIRC ;)
     * - madmax
     */
    snprintf(buff, sizeof(buff), "%s %s :1 %s",   target_p->name,
             me.name, target_p->info);
    dlinkAddTail(xstrdup(buff), make_dlink_node(), &flatten_links);
    snprintf(buff, sizeof(buff), "%s %s :1 %s\n", target_p->name,
             me.name, target_p->info);

    fputs(buff, file);
  }

  fclose(file);
}

void
read_links_file(void)
{
  FILE *file = NULL;
  char *p = NULL;
  char buff[IRCD_BUFSIZE] = "";

  if (EmptyString(ConfigServerHide.flatten_links_file))
    return;

  if ((file = fopen(ConfigServerHide.flatten_links_file, "r")) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "Couldn't open \"%s\": %s", ConfigServerHide.flatten_links_file,
         strerror(errno));
    return;
  }

  while (fgets(buff, sizeof(buff), file))
  {
    if ((p = strchr(buff, '\n')))
      *p = '\0';

    dlinkAddTail(xstrdup(buff), make_dlink_node(), &flatten_links);
  }

  fclose(file);
}

/* hunt_server()
 *      Do the basic thing in delivering the message (command)
 *      across the relays to the specific server (server) for
 *      actions.
 *
 *      Note:   The command is a format string and *MUST* be
 *              of prefixed style (e.g. ":%s COMMAND %s ...").
 *              Command can have only max 8 parameters.
 *
 *      server  parv[server] is the parameter identifying the
 *              target server.
 *
 *      *WARNING*
 *              parv[server] is replaced with the pointer to the
 *              real servername from the matched client (I'm lazy
 *              now --msa).
 *
 *      returns: (see #defines)
 */
int
hunt_server(struct Client *source_p, const char *command,
            const int server, const int parc, char *parv[])
{
  struct Client *target_p = NULL;
  dlink_node *node = NULL;

  /* Assume it's me, if no server */
  if (parc <= server || EmptyString(parv[server]))
    return HUNTED_ISME;

  if ((target_p = find_person(source_p, parv[server])) == NULL)
    target_p = hash_find_server(parv[server]);

  /*
   * These are to pickup matches that would cause the following
   * message to go in the wrong direction while doing quick fast
   * non-matching lookups.
   */
  if (target_p)
    if (target_p->from == source_p->from && !MyConnect(target_p))
      target_p = NULL;

  if (!target_p && has_wildcards(parv[server]))
  {
    DLINK_FOREACH(node, global_server_list.head)
    {
      struct Client *tmp = node->data;

      assert(IsMe(tmp) || IsServer(tmp));
      if (!match(parv[server], tmp->name))
      {
        if (tmp->from == source_p->from && !MyConnect(tmp))
          continue;

        target_p = node->data;
        break;
      }
    }

    if (!target_p)
    {
      DLINK_FOREACH(node, global_client_list.head)
      {
        struct Client *tmp = node->data;

        assert(IsMe(tmp) || IsServer(tmp) || IsClient(tmp));
        if (!match(parv[server], tmp->name))
        {
          if (tmp->from == source_p->from && !MyConnect(tmp))
            continue;

          target_p = node->data;
          break;
        }
      }
    }
  }

  if (target_p)
  {
    assert(IsMe(target_p) || IsServer(target_p) || IsClient(target_p));
    if (IsMe(target_p) || MyClient(target_p))
      return HUNTED_ISME;

    parv[server] = target_p->id;
    sendto_one(target_p, command, source_p->id,
               parv[1], parv[2], parv[3], parv[4],
               parv[5], parv[6], parv[7], parv[8]);
    return HUNTED_PASS;
  }

  sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, parv[server]);
  return HUNTED_NOSUCH;
}

/* try_connections()
 *
 * inputs	- void pointer which is not used
 * output	- NONE
 * side effects	-
 * scan through configuration and try new connections.
 * Returns the calendar time when the next call to this
 * function should be made latest. (No harm done if this
 * is called earlier or later...)
 */
void
try_connections(void *unused)
{
  dlink_node *node = NULL;

  if (GlobalSetOptions.autoconn == 0)
    return;

  DLINK_FOREACH(node, server_items.head)
  {
    struct MaskItem *conf = node->data;

    assert(conf->type == CONF_SERVER);

    /* Also when already connecting! (update holdtimes) --SRB */
    if (!conf->port || !IsConfAllowAutoConn(conf))
      continue;

    /*
     * Skip this entry if the use of it is still on hold until
     * future. Otherwise handle this entry (and set it on hold
     * until next time). Will reset only hold times, if already
     * made one successfull connection... [this algorithm is
     * a bit fuzzy... -- msa >;) ]
     */
    if (conf->until > CurrentTime)
      continue;

    assert(conf->class);

    conf->until = CurrentTime + conf->class->con_freq;

    /*
     * Found a CONNECT config with port specified, scan clients
     * and see if this server is already connected?
     */
    if (hash_find_server(conf->name))
      continue;

    if (conf->class->ref_count < conf->class->max_total)
    {
      /* Move this entry to the end of the list, if not already last */
      if (node->next)
      {
        dlinkDelete(node, &server_items);
        dlinkAddTail(conf, &conf->node, &server_items);
      }

      if (find_servconn_in_progress(conf->name))
        return;

      /*
       * We used to only print this if serv_connect() actually
       * succeeded, but since comm_tcp_connect() can call the callback
       * immediately if there is an error, we were getting error messages
       * in the wrong order. SO, we just print out the activated line,
       * and let serv_connect() / serv_connect_callback() print an
       * error afterwards if it fails.
       *   -- adrian
       */
      if (ConfigServerHide.hide_server_ips)
        sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                             "Connection to %s activated.",
                             conf->name);
      else
        sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                             "Connection to %s[%s] activated.",
                             conf->name, conf->host);

      serv_connect(conf, NULL);
      /* We connect only one at time... */
      return;
    }
  }
}

int
valid_servname(const char *name)
{
  unsigned int dots = 0;
  const char *p = name;

  for (; *p; ++p)
  {
    if (!IsServChar(*p))
      return 0;

    if (*p == '.')
      ++dots;
  }

  return dots && (p - name) <= HOSTLEN;
}

int
check_server(const char *name, struct Client *client_p)
{
  dlink_node *node = NULL;
  struct MaskItem *conf        = NULL;
  struct MaskItem *server_conf = NULL;
  int error = -1;

  assert(client_p);

  /* Loop through looking for all possible connect items that might work */
  DLINK_FOREACH(node, server_items.head)
  {
    conf = node->data;

    if (match(name, conf->name))
      continue;

    error = -3;

    if (!match(conf->host, client_p->host) ||
        !match(conf->host, client_p->sockhost))
    {
      error = -2;

      if (!match_conf_password(client_p->connection->password, conf))
        return -2;

      if (!EmptyString(conf->certfp))
        if (EmptyString(client_p->certfp) || strcasecmp(client_p->certfp, conf->certfp))
          return -4;

      server_conf = conf;
    }
  }

  if (server_conf == NULL)
    return error;

  attach_conf(client_p, server_conf);

  switch (server_conf->aftype)
  {
    case AF_INET6:
    {
      const struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)&server_conf->addr;

      if (IN6_IS_ADDR_UNSPECIFIED(&v6->sin6_addr))
        memcpy(&server_conf->addr, &client_p->connection->ip, sizeof(struct irc_ssaddr));
      break;
    }
    case AF_INET:
    {
      const struct sockaddr_in *v4 = (struct sockaddr_in *)&server_conf->addr;

      if (v4->sin_addr.s_addr == INADDR_NONE)
        memcpy(&server_conf->addr, &client_p->connection->ip, sizeof(struct irc_ssaddr));
      break;
    }
  }

  return 0;
}

/* add_capability()
 *
 * inputs	- string name of CAPAB
 *		- int flag of capability
 * output	- NONE
 * side effects	- Adds given capability name and bit mask to
 *		  current supported capabilities. This allows
 *		  modules to dynamically add or subtract their capability.
 */
void
add_capability(const char *name, unsigned int flag)
{
  struct Capability *cap = xcalloc(sizeof(*cap));

  cap->name = xstrdup(name);
  cap->cap = flag;
  dlinkAdd(cap, &cap->node, &server_capabilities_list);
}

/* delete_capability()
 *
 * inputs	- string name of CAPAB
 * output	- NONE
 * side effects	- delete given capability from ones known.
 */
void
delete_capability(const char *name)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, server_capabilities_list.head)
  {
    struct Capability *cap = node->data;

    if (!irccmp(cap->name, name))
    {
      dlinkDelete(node, &server_capabilities_list);
      xfree(cap->name);
      xfree(cap);
    }
  }
}

/*
 * find_capability()
 *
 * inputs	- string name of capab to find
 * output	- 0 if not found CAPAB otherwise
 * side effects	- none
 */
unsigned int
find_capability(const char *name)
{
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, server_capabilities_list.head)
  {
    const struct Capability *cap = node->data;

    if (!irccmp(cap->name, name))
      return cap->cap;
  }

  return 0;
}

/* send_capabilities()
 *
 * inputs	- Client pointer to send to
 *		- int flag of capabilities that this server can send
 * output	- NONE
 * side effects	- send the CAPAB line to a server  -orabidoo
 *
 */
void
send_capabilities(struct Client *client_p)
{
  char buf[IRCD_BUFSIZE] = "";
  const dlink_node *node = NULL;

  DLINK_FOREACH(node, server_capabilities_list.head)
  {
    const struct Capability *cap = node->data;

    strlcat(buf, cap->name, sizeof(buf));

    if (node->next)
      strlcat(buf, " ", sizeof(buf));
  }

  sendto_one(client_p, "CAPAB :%s", buf);
}

/*
 * show_capabilities - show current server capabilities
 *
 * inputs       - pointer to a struct Client
 * output       - pointer to static string
 * side effects - build up string representing capabilities of server listed
 */
const char *
show_capabilities(const struct Client *target_p)
{
  static char msgbuf[IRCD_BUFSIZE] = "";
  const dlink_node *node = NULL;

  strlcpy(msgbuf, "TS", sizeof(msgbuf));

  DLINK_FOREACH(node, server_capabilities_list.head)
  {
    const struct Capability *cap = node->data;

    if (!IsCapable(target_p, cap->cap))
      continue;

    strlcat(msgbuf,       " ", sizeof(msgbuf));
    strlcat(msgbuf, cap->name, sizeof(msgbuf));
  }

  return msgbuf;
}

/* make_server()
 *
 * inputs       - pointer to client struct
 * output       - pointer to struct Server
 * side effects - add's an Server information block to a client
 *                if it was not previously allocated.
 */
struct Server *
make_server(struct Client *client_p)
{
  if (client_p->serv == NULL)
    client_p->serv = xcalloc(sizeof(struct Server));

  return client_p->serv;
}

/* New server connection code
 * Based upon the stuff floating about in s_bsd.c
 *   -- adrian
 */

/* serv_connect() - initiate a server connection
 *
 * inputs	- pointer to conf
 *		- pointer to client doing the connect
 * output	-
 * side effects	-
 *
 * This code initiates a connection to a server. It first checks to make
 * sure the given server exists. If this is the case, it creates a socket,
 * creates a client, saves the socket information in the client, and
 * initiates a connection to the server through comm_connect_tcp(). The
 * completion of this goes through serv_completed_connection().
 *
 * We return 1 if the connection is attempted, since we don't know whether
 * it suceeded or not, and 0 if it fails in here somewhere.
 */
int
serv_connect(struct MaskItem *conf, struct Client *by)
{
  struct Client *client_p = NULL;
  char buf[HOSTIPLEN + 1] = "";

  /* conversion structs */
  struct sockaddr_in *v4;

  /* Make sure conf is useful */
  assert(conf);

  getnameinfo((const struct sockaddr *)&conf->addr, conf->addr.ss_len,
              buf, sizeof(buf), NULL, 0, NI_NUMERICHOST);
  ilog(LOG_TYPE_IRCD, "Connect to %s[%s] @%s", conf->name, conf->host,
       buf);

  /* Still processing a DNS lookup? -> exit */
  if (conf->dns_pending)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Error connecting to %s: DNS lookup for connect{} in progress.",
                         conf->name);
    return 0;
  }

  if (conf->dns_failed)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Error connecting to %s: DNS lookup for connect{} failed.",
                         conf->name);
    return 0;
  }

  /*
   * Make sure this server isn't already connected.
   * Note: conf should ALWAYS be a valid connect {} block
   */
  if ((client_p = hash_find_server(conf->name)))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Server %s already present from %s",
                         conf->name, get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Server %s already present from %s",
                         conf->name, get_client_name(client_p, MASK_IP));
    if (by && IsClient(by) && !MyClient(by))
      sendto_one_notice(by, &me, ":Server %s already present from %s",
                        conf->name, get_client_name(client_p, MASK_IP));
    return 0;
  }

  /* Create a local client */
  client_p = make_client(NULL);

  /* Copy in the server, hostname, fd */
  strlcpy(client_p->name, conf->name, sizeof(client_p->name));
  strlcpy(client_p->host, conf->host, sizeof(client_p->host));

  /* We already converted the ip once, so lets use it - stu */
  strlcpy(client_p->sockhost, buf, sizeof(client_p->sockhost));

  /* Create a socket for the server connection */
  if (comm_open(&client_p->connection->fd, conf->addr.ss.ss_family, SOCK_STREAM, 0, NULL) < 0)
  {
    /* Eek, failure to create the socket */
    report_error(L_ALL, "opening stream socket to %s: %s", conf->name, errno);

    SetDead(client_p);
    exit_client(client_p, "Connection failed");
    return 0;
  }

  /* Server names are always guaranteed under HOSTLEN chars */
  fd_note(&client_p->connection->fd, "Server: %s", client_p->name);

  /*
   * Attach config entries to client here rather than in serv_connect_callback().
   * This to avoid null pointer references.
   */
  if (!attach_connect_block(client_p, conf->name, conf->host))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Host %s is not enabled for connecting: no connect {} block",
                         conf->name);
    if (by && IsClient(by) && !MyClient(by))
      sendto_one_notice(by, &me, ":Connect to host %s failed: no connect {} block", client_p->name);

    SetDead(client_p);
    exit_client(client_p, "Connection failed");
    return 0;
  }

  /*
   * At this point we have a connection in progress and a connect {} block
   * attached to the client, the socket info should be saved in the client
   * and it should either be resolved or have a valid address.
   *
   * The socket has been connected or connect is in progress.
   */
  make_server(client_p);

  if (by && IsClient(by))
    strlcpy(client_p->serv->by, by->name, sizeof(client_p->serv->by));
  else
    strlcpy(client_p->serv->by, "AutoConn.", sizeof(client_p->serv->by));

  SetConnecting(client_p);
  client_p->connection->aftype = conf->aftype;

  /* Now, initiate the connection */
  /* XXX assume that a non 0 type means a specific bind address
   * for this connect.
   */
  switch (conf->aftype)
  {
    case AF_INET:
      v4 = (struct sockaddr_in*)&conf->bind;
      if (v4->sin_addr.s_addr)
      {
        struct irc_ssaddr ipn;
        memset(&ipn, 0, sizeof(struct irc_ssaddr));
        ipn.ss.ss_family = AF_INET;
        ipn.ss_port = 0;
        memcpy(&ipn, &conf->bind, sizeof(struct irc_ssaddr));
        comm_connect_tcp(&client_p->connection->fd, conf->host, conf->port,
                         (struct sockaddr *)&ipn, ipn.ss_len,
                         serv_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      }
      else if (ConfigServerInfo.specific_ipv4_vhost)
      {
        struct irc_ssaddr ipn;
        memset(&ipn, 0, sizeof(struct irc_ssaddr));
        ipn.ss.ss_family = AF_INET;
        ipn.ss_port = 0;
        memcpy(&ipn, &ConfigServerInfo.ip, sizeof(struct irc_ssaddr));
        comm_connect_tcp(&client_p->connection->fd, conf->host, conf->port,
                         (struct sockaddr *)&ipn, ipn.ss_len,
                         serv_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      }
      else
        comm_connect_tcp(&client_p->connection->fd, conf->host, conf->port,
                         NULL, 0, serv_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      break;
    case AF_INET6:
      {
        struct irc_ssaddr ipn;
        struct sockaddr_in6 *v6;
        struct sockaddr_in6 *v6conf;

        memset(&ipn, 0, sizeof(struct irc_ssaddr));
        v6conf = (struct sockaddr_in6 *)&conf->bind;
        v6 = (struct sockaddr_in6 *)&ipn;

        if (memcmp(&v6conf->sin6_addr, &v6->sin6_addr, sizeof(struct in6_addr)))
        {
          memcpy(&ipn, &conf->bind, sizeof(struct irc_ssaddr));
          ipn.ss.ss_family = AF_INET6;
          ipn.ss_port = 0;
          comm_connect_tcp(&client_p->connection->fd,
                           conf->host, conf->port,
                           (struct sockaddr *)&ipn, ipn.ss_len,
                           serv_connect_callback, client_p,
                           conf->aftype, CONNECTTIMEOUT);
        }
        else if (ConfigServerInfo.specific_ipv6_vhost)
        {
          memcpy(&ipn, &ConfigServerInfo.ip6, sizeof(struct irc_ssaddr));
          ipn.ss.ss_family = AF_INET6;
          ipn.ss_port = 0;
          comm_connect_tcp(&client_p->connection->fd,
                           conf->host, conf->port,
                           (struct sockaddr *)&ipn, ipn.ss_len,
                           serv_connect_callback, client_p,
                           conf->aftype, CONNECTTIMEOUT);
        }
        else
          comm_connect_tcp(&client_p->connection->fd,
                           conf->host, conf->port,
                           NULL, 0, serv_connect_callback, client_p,
                           conf->aftype, CONNECTTIMEOUT);
      }
  }

  return 1;
}

static void
finish_ssl_server_handshake(struct Client *client_p)
{
  struct MaskItem *conf = NULL;

  conf = find_conf_name(&client_p->connection->confs,
                        client_p->name, CONF_SERVER);
  if (conf == NULL)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, MASK_IP));

    exit_client(client_p, "Lost connect{} block");
    return;
  }

  sendto_one(client_p, "PASS %s TS %d %s", conf->spasswd, TS_CURRENT, me.id);

  send_capabilities(client_p);

  sendto_one(client_p, "SERVER %s 1 :%s%s",
             me.name, ConfigServerHide.hidden ? "(H) " : "",
             me.info);

  /*
   * If we've been marked dead because a send failed, just exit
   * here now and save everyone the trouble of us ever existing.
   */
  if (IsDead(client_p))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "%s went dead during handshake", get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "%s went dead during handshake", get_client_name(client_p, MASK_IP));
    return;
  }

  /* don't move to serv_list yet -- we haven't sent a burst! */
  /* If we get here, we're ok, so lets start reading some data */
  comm_setselect(&client_p->connection->fd, COMM_SELECT_READ, read_packet, client_p, 0);
}

static void
ssl_server_handshake(fde_t *fd, void *data)
{
  struct Client *client_p = data;
  const char *sslerr = NULL;

  tls_handshake_status_t ret = tls_handshake(&client_p->connection->fd.ssl, TLS_ROLE_CLIENT, &sslerr);
  if (ret != TLS_HANDSHAKE_DONE)
  {
    if ((CurrentTime - client_p->connection->firsttime) > CONNECTTIMEOUT)
    {
      exit_client(client_p, "Timeout during TLS handshake");
      return;
    }

    switch (ret)
    {
      case TLS_HANDSHAKE_WANT_WRITE:
        comm_setselect(&client_p->connection->fd, COMM_SELECT_WRITE,
                       ssl_server_handshake, client_p, CONNECTTIMEOUT);
        return;
      case TLS_HANDSHAKE_WANT_READ:
        comm_setselect(&client_p->connection->fd, COMM_SELECT_READ,
                       ssl_server_handshake, client_p, CONNECTTIMEOUT);
        return;
      default:
      {
        sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                             "Error connecting to %s: %s", client_p->name,
                             sslerr ? sslerr : "unknown TLS error");
        exit_client(client_p, "Error during TLS handshake");
        return;
      }
    }
  }

  comm_settimeout(&client_p->connection->fd, 0, NULL, NULL);

  if (!tls_verify_cert(&client_p->connection->fd.ssl, ConfigServerInfo.message_digest_algorithm, &client_p->certfp))
    ilog(LOG_TYPE_IRCD, "Server %s!%s@%s gave bad TLS client certificate",
         client_p->name, client_p->username, client_p->host);

  finish_ssl_server_handshake(client_p);
}

static void
ssl_connect_init(struct Client *client_p, const struct MaskItem *conf, fde_t *fd)
{
  if (!tls_new(&client_p->connection->fd.ssl, fd->fd, TLS_ROLE_CLIENT))
  {
    SetDead(client_p);
    exit_client(client_p, "TLS context initialization failed");
    return;
  }

  if (!EmptyString(conf->cipher_list))
    tls_set_ciphers(&client_p->connection->fd.ssl, conf->cipher_list);

  ssl_server_handshake(NULL, client_p);
}

/* serv_connect_callback() - complete a server connection.
 *
 * This routine is called after the server connection attempt has
 * completed. If unsucessful, an error is sent to ops and the client
 * is closed. If sucessful, it goes through the initialisation/check
 * procedures, the capabilities are sent, and the socket is then
 * marked for reading.
 */
static void
serv_connect_callback(fde_t *fd, int status, void *data)
{
  struct Client *const client_p = data;
  const struct MaskItem *conf = NULL;

  /* First, make sure it's a real client! */
  assert(client_p);
  assert(&client_p->connection->fd == fd);

  /* Next, for backward purposes, record the ip of the server */
  memcpy(&client_p->connection->ip, &fd->connect.hostaddr,
         sizeof(struct irc_ssaddr));

  /* Check the status */
  if (status != COMM_OK)
  {
    /* We have an error, so report it and quit */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Error connecting to %s: %s",
                         get_client_name(client_p, SHOW_IP), comm_errstr(status));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Error connecting to %s: %s",
                         get_client_name(client_p, MASK_IP), comm_errstr(status));

    /*
     * If a fd goes bad, call dead_link() the socket is no
     * longer valid for reading or writing.
     */
    dead_link_on_write(client_p, 0);
    return;
  }

  /* COMM_OK, so continue the connection procedure */
  /* Get the C/N lines */
  conf = find_conf_name(&client_p->connection->confs,
                        client_p->name, CONF_SERVER);
  if (conf == NULL)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, MASK_IP));

    exit_client(client_p, "Lost connect{} block");
    return;
  }

  /* Next, send the initial handshake */
  SetHandshake(client_p);

  if (IsConfSSL(conf))
  {
    ssl_connect_init(client_p, conf, fd);
    return;
  }

  sendto_one(client_p, "PASS %s TS %d %s", conf->spasswd, TS_CURRENT, me.id);

  send_capabilities(client_p);

  sendto_one(client_p, "SERVER %s 1 :%s%s", me.name,
             ConfigServerHide.hidden ? "(H) " : "", me.info);

  /*
   * If we've been marked dead because a send failed, just exit
   * here now and save everyone the trouble of us ever existing.
   */
  if (IsDead(client_p))
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "%s went dead during handshake", get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "%s went dead during handshake", get_client_name(client_p, MASK_IP));
    return;
  }

  /* don't move to serv_list yet -- we haven't sent a burst! */
  /* If we get here, we're ok, so lets start reading some data */
  comm_setselect(fd, COMM_SELECT_READ, read_packet, client_p, 0);
}

struct Client *
find_servconn_in_progress(const char *name)
{
  dlink_node *ptr;
  struct Client *cptr;

  DLINK_FOREACH(ptr, unknown_list.head)
  {
    cptr = ptr->data;

    if (cptr && cptr->name[0])
      if (!match(name, cptr->name))
        return cptr;
  }

  return NULL;
}
