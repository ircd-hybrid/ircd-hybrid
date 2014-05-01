/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file s_serv.c
 * \brief Server related functions.
 * \version $Id$
 */

#include "stdinc.h"
#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include "rsa.h"
#endif
#include "list.h"
#include "client.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "ircd_defs.h"
#include "s_bsd.h"
#include "numeric.h"
#include "packet.h"
#include "conf.h"
#include "server.h"
#include "log.h"
#include "user.h"
#include "send.h"
#include "memory.h"
#include "channel.h"
#include "parse.h"

#define MIN_CONN_FREQ 300

dlink_list flatten_links;
static dlink_list cap_list = { NULL, NULL, 0 };
static CNCB serv_connect_callback;


/*
 * write_links_file
 *
 * inputs	- void pointer which is not used
 * output	- NONE
 * side effects	- called from an event, write out list of linked servers
 *		  but in no particular order.
 */
void
write_links_file(void *notused)
{
  FILE *file = NULL;
  dlink_node *ptr = NULL, *ptr_next = NULL;
  char buff[IRCD_BUFSIZE] = "";

  if ((file = fopen(LIPATH, "w")) == NULL)
    return;

  DLINK_FOREACH_SAFE(ptr, ptr_next, flatten_links.head)
  {
    dlinkDelete(ptr, &flatten_links);
    MyFree(ptr->data);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH(ptr, global_serv_list.head)
  {
    const struct Client *target_p = ptr->data;

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

  if ((file = fopen(LIPATH, "r")) == NULL)
    return;

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
  struct Client *target_tmp = NULL;
  dlink_node *ptr;

  /* Assume it's me, if no server */
  if (parc <= server || EmptyString(parv[server]))
    return HUNTED_ISME;

  if (!strcmp(parv[server], me.id) || !match(parv[server], me.name))
    return HUNTED_ISME;

  /* These are to pickup matches that would cause the following
   * message to go in the wrong direction while doing quick fast
   * non-matching lookups.
   */
  if (MyClient(source_p))
    target_p = hash_find_client(parv[server]);
  else
    target_p = find_person(source_p, parv[server]);

  if (target_p)
    if (target_p->from == source_p->from && !MyConnect(target_p))
      target_p = NULL;

  if (target_p == NULL && (target_p = hash_find_server(parv[server])))
    if (target_p->from == source_p->from && !MyConnect(target_p))
      target_p = NULL;

  /* Again, if there are no wild cards involved in the server
   * name, use the hash lookup
   */
  if (target_p == NULL)
  {
    if (!has_wildcards(parv[server]))
    {
      if (!(target_p = hash_find_server(parv[server])))
      {
        sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, parv[server]);
        return HUNTED_NOSUCH;
      }
    }
    else
    {
      DLINK_FOREACH(ptr, global_client_list.head)
      {
        target_tmp = ptr->data;

        if (!match(parv[server], target_tmp->name))
        {
          if (target_tmp->from == source_p->from && !MyConnect(target_tmp))
            continue;
          target_p = ptr->data;

          if (IsRegistered(target_p) && (target_p != source_p->from))
            break;
        }
      }
    }
  }

  if (target_p)
  {
    if (!IsRegistered(target_p))
    {
      sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, parv[server]);
      return HUNTED_NOSUCH;
    }

    if (IsMe(target_p) || MyClient(target_p))
      return HUNTED_ISME;

    if (match(target_p->name, parv[server]))
      parv[server] = target_p->name;

    /* This is a little kludgy but should work... */
    sendto_one(target_p, command, ID_or_name(source_p, target_p),
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
  dlink_node *ptr = NULL;
  int confrq = 0;

  /* TODO: change this to set active flag to 0 when added to event! --Habeeb */
  if (GlobalSetOptions.autoconn == 0)
    return;

  DLINK_FOREACH(ptr, server_items.head)
  {
    struct MaskItem *conf = ptr->data;

    assert(conf->type == CONF_SERVER);

    /* Also when already connecting! (update holdtimes) --SRB
     */
    if (!conf->port ||!IsConfAllowAutoConn(conf))
      continue;


    /* Skip this entry if the use of it is still on hold until
     * future. Otherwise handle this entry (and set it on hold
     * until next time). Will reset only hold times, if already
     * made one successfull connection... [this algorithm is
     * a bit fuzzy... -- msa >;) ]
     */
    if (conf->until > CurrentTime)
      continue;

    if (conf->class == NULL)
      confrq = DEFAULT_CONNECTFREQUENCY;
    else
    {
      confrq = conf->class->con_freq;
      if (confrq < MIN_CONN_FREQ)
        confrq = MIN_CONN_FREQ;
    }

    conf->until = CurrentTime + confrq;

    /*
     * Found a CONNECT config with port specified, scan clients
     * and see if this server is already connected?
     */
    if (hash_find_server(conf->name))
      continue;

    if (conf->class->ref_count < conf->class->max_total)
    {
      /* Go to the end of the list, if not already last */
      if (ptr->next)
      {
        dlinkDelete(ptr, &server_items);
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
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "Connection to %s activated.",
                             conf->name);
      else
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
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
  unsigned int length = 0;
  unsigned int dots   = 0;
  const char *p = name;

  for (; *p; ++p)
  {
    if (!IsServChar(*p))
      return 0;

    ++length;

    if (*p == '.')
      ++dots;
  }

  return dots && length <= HOSTLEN;
}

int
check_server(const char *name, struct Client *client_p)
{
  dlink_node *ptr;
  struct MaskItem *conf        = NULL;
  struct MaskItem *server_conf = NULL;
  int error = -1;

  assert(client_p);

  /* loop through looking for all possible connect items that might work */
  DLINK_FOREACH(ptr, server_items.head)
  {
    conf = ptr->data;

    if (match(name, conf->name))
      continue;

    error = -3;

    /* XXX: Fix me for IPv6                    */
    /* XXX sockhost is the IPv4 ip as a string */
    if (!match(conf->host, client_p->host) ||
        !match(conf->host, client_p->sockhost))
    {
      error = -2;

      if (!match_conf_password(client_p->localClient->passwd, conf))
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


  if (server_conf)
  {
    struct sockaddr_in *v4;
#ifdef IPV6
    struct sockaddr_in6 *v6;
#endif
    switch (server_conf->aftype)
    {
#ifdef IPV6
      case AF_INET6:
        v6 = (struct sockaddr_in6 *)&server_conf->addr;

        if (IN6_IS_ADDR_UNSPECIFIED(&v6->sin6_addr))
          memcpy(&server_conf->addr, &client_p->localClient->ip, sizeof(struct irc_ssaddr));
        break;
#endif
      case AF_INET:
        v4 = (struct sockaddr_in *)&server_conf->addr;

        if (v4->sin_addr.s_addr == INADDR_NONE)
          memcpy(&server_conf->addr, &client_p->localClient->ip, sizeof(struct irc_ssaddr));
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
add_capability(const char *capab_name, int cap_flag, int add_to_default)
{
  struct Capability *cap = MyMalloc(sizeof(*cap));

  cap->name = xstrdup(capab_name);
  cap->cap = cap_flag;
  dlinkAdd(cap, &cap->node, &cap_list);

  if (add_to_default)
    default_server_capabs |= cap_flag;
}

/* delete_capability()
 *
 * inputs	- string name of CAPAB
 * output	- NONE
 * side effects	- delete given capability from ones known.
 */
int
delete_capability(const char *capab_name)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, cap_list.head)
  {
    struct Capability *cap = ptr->data;

    if (cap->cap)
    {
      if (!irccmp(cap->name, capab_name))
      {
        default_server_capabs &= ~(cap->cap);
        dlinkDelete(ptr, &cap_list);
        MyFree(cap->name);
        MyFree(cap);
      }
    }
  }

  return 0;
}

/*
 * find_capability()
 *
 * inputs	- string name of capab to find
 * output	- 0 if not found CAPAB otherwise
 * side effects	- none
 */
unsigned int
find_capability(const char *capab)
{
  const dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, cap_list.head)
  {
    const struct Capability *cap = ptr->data;

    if (cap->cap && !irccmp(cap->name, capab))
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
send_capabilities(struct Client *client_p, int cap_can_send)
{
  char msgbuf[IRCD_BUFSIZE] = "";
  char *t = msgbuf;
  int tl;
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, cap_list.head)
  {
    struct Capability *cap = ptr->data;

    if (cap->cap & (cap_can_send|default_server_capabs))
    {
      tl = sprintf(t, "%s ", cap->name);
      t += tl;
    }
  }

  *(t - 1) = '\0';
  sendto_one(client_p, "CAPAB :%s", msgbuf);
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
  const dlink_node *ptr = NULL;

  strlcpy(msgbuf, "TS", sizeof(msgbuf));

  DLINK_FOREACH(ptr, cap_list.head)
  {
    const struct Capability *cap = ptr->data;

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
    client_p->serv = MyMalloc(sizeof(struct Server));

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

  getnameinfo((struct sockaddr *)&conf->addr, conf->addr.ss_len,
              buf, sizeof(buf), NULL, 0, NI_NUMERICHOST);
  ilog(LOG_TYPE_IRCD, "Connect to %s[%s] @%s", conf->name, conf->host,
       buf);

  /* Still processing a DNS lookup? -> exit */
  if (conf->dns_pending)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Error connecting to %s: DNS lookup for connect{} in progress.",
                         conf->name);
    return 0;
  }

  if (conf->dns_failed)
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Error connecting to %s: DNS lookup for connect{} failed.",
                         conf->name);
    return 0;
  }

  /* Make sure this server isn't already connected
   * Note: conf should ALWAYS be a valid C: line
   */
  if ((client_p = hash_find_server(conf->name)))
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Server %s already present from %s",
                         conf->name, get_client_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
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

  /* create a socket for the server connection */
  if (comm_open(&client_p->localClient->fd, conf->addr.ss.ss_family, SOCK_STREAM, 0, NULL) < 0)
  {
    /* Eek, failure to create the socket */
    report_error(L_ALL, "opening stream socket to %s: %s", conf->name, errno);

    SetDead(client_p);
    exit_client(client_p, "Connection failed");
    return 0;
  }

  /* servernames are always guaranteed under HOSTLEN chars */
  fd_note(&client_p->localClient->fd, "Server: %s", conf->name);

  /* Attach config entries to client here rather than in
   * serv_connect_callback(). This to avoid null pointer references.
   */
  if (!attach_connect_block(client_p, conf->name, conf->host))
  {
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Host %s is not enabled for connecting: no connect{} block",
                         conf->name);
    if (by && IsClient(by) && !MyClient(by))
      sendto_one_notice(by, &me, ":Connect to host %s failed.", client_p->name);

    SetDead(client_p);
    exit_client(client_p, "Connection failed");
    return 0;
  }

  /* at this point we have a connection in progress and C/N lines
   * attached to the client, the socket info should be saved in the
   * client and it should either be resolved or have a valid address.
   *
   * The socket has been connected or connect is in progress.
   */
  make_server(client_p);

  if (by && IsClient(by))
    strlcpy(client_p->serv->by, by->name, sizeof(client_p->serv->by));
  else
    strlcpy(client_p->serv->by, "AutoConn.", sizeof(client_p->serv->by));

  SetConnecting(client_p);
  dlinkAdd(client_p, &client_p->node, &global_client_list);

  client_p->localClient->aftype = conf->aftype;

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
        comm_connect_tcp(&client_p->localClient->fd, conf->host, conf->port,
                         (struct sockaddr *)&ipn, ipn.ss_len,
                         serv_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      }
      else if (ServerInfo.specific_ipv4_vhost)
      {
        struct irc_ssaddr ipn;
        memset(&ipn, 0, sizeof(struct irc_ssaddr));
        ipn.ss.ss_family = AF_INET;
        ipn.ss_port = 0;
        memcpy(&ipn, &ServerInfo.ip, sizeof(struct irc_ssaddr));
        comm_connect_tcp(&client_p->localClient->fd, conf->host, conf->port,
                         (struct sockaddr *)&ipn, ipn.ss_len,
                         serv_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      }
      else
        comm_connect_tcp(&client_p->localClient->fd, conf->host, conf->port,
                         NULL, 0, serv_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      break;
#ifdef IPV6
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
          comm_connect_tcp(&client_p->localClient->fd,
                           conf->host, conf->port,
                           (struct sockaddr *)&ipn, ipn.ss_len,
                           serv_connect_callback, client_p,
                           conf->aftype, CONNECTTIMEOUT);
        }
        else if (ServerInfo.specific_ipv6_vhost)
        {
          memcpy(&ipn, &ServerInfo.ip6, sizeof(struct irc_ssaddr));
          ipn.ss.ss_family = AF_INET6;
          ipn.ss_port = 0;
          comm_connect_tcp(&client_p->localClient->fd,
                           conf->host, conf->port,
                           (struct sockaddr *)&ipn, ipn.ss_len,
                           serv_connect_callback, client_p,
                           conf->aftype, CONNECTTIMEOUT);
        }
        else
          comm_connect_tcp(&client_p->localClient->fd,
                           conf->host, conf->port,
                           NULL, 0, serv_connect_callback, client_p,
                           conf->aftype, CONNECTTIMEOUT);
      }
#endif
  }
  return 1;
}

#ifdef HAVE_LIBCRYPTO
static void
finish_ssl_server_handshake(struct Client *client_p)
{
  struct MaskItem *conf = NULL;

  conf = find_conf_name(&client_p->localClient->confs,
                        client_p->name, CONF_SERVER);
  if (conf == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, HIDE_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, MASK_IP));

    exit_client(client_p, "Lost connect{} block");
    return;
  }

  sendto_one(client_p, "PASS %s TS %d %s", conf->spasswd, TS_CURRENT, me.id);

  send_capabilities(client_p, 0);

  sendto_one(client_p, "SERVER %s 1 :%s%s",
             me.name, ConfigServerHide.hidden ? "(H) " : "",
             me.info);

  /* If we've been marked dead because a send failed, just exit
   * here now and save everyone the trouble of us ever existing.
   */
  if (IsDead(client_p))
  {
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                           "%s[%s] went dead during handshake",
                           client_p->name,
                           client_p->host);
      sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                           "%s went dead during handshake", client_p->name);
      return;
  }

  /* don't move to serv_list yet -- we haven't sent a burst! */
  /* If we get here, we're ok, so lets start reading some data */
  comm_setselect(&client_p->localClient->fd, COMM_SELECT_READ, read_packet, client_p, 0);
}

static void
ssl_server_handshake(fde_t *fd, struct Client *client_p)
{
  X509 *cert = NULL;
  int ret = 0;

  if ((ret = SSL_connect(client_p->localClient->fd.ssl)) <= 0)
  {
    switch (SSL_get_error(client_p->localClient->fd.ssl, ret))
    {
      case SSL_ERROR_WANT_WRITE:
        comm_setselect(&client_p->localClient->fd, COMM_SELECT_WRITE,
                       (PF *)ssl_server_handshake, client_p, 0);
        return;
      case SSL_ERROR_WANT_READ:
        comm_setselect(&client_p->localClient->fd, COMM_SELECT_READ,
                       (PF *)ssl_server_handshake, client_p, 0);
        return;
      default:
      {
        const char *sslerr = ERR_error_string(ERR_get_error(), NULL);
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "Error connecting to %s: %s", client_p->name,
                             sslerr ? sslerr : "unknown SSL error");
        exit_client(client_p, "Error during SSL handshake");
        return;
      }
    }
  }

  if ((cert = SSL_get_peer_certificate(client_p->localClient->fd.ssl)))
  {
    int res = SSL_get_verify_result(client_p->localClient->fd.ssl);
    char buf[EVP_MAX_MD_SIZE * 2 + 1] = "";
    unsigned char md[EVP_MAX_MD_SIZE] = "";

    if (res == X509_V_OK || res == X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN ||
        res == X509_V_ERR_UNABLE_TO_VERIFY_LEAF_SIGNATURE ||
        res == X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT)
    {
      unsigned int n = 0;

      if (X509_digest(cert, EVP_sha256(), md, &n))
      {
        for (unsigned int i = 0; i < n; ++i)
          snprintf(buf + 2 * i, 3, "%02X", md[i]);
        client_p->certfp = xstrdup(buf);
      }
    }
    else
      ilog(LOG_TYPE_IRCD, "Server %s!%s@%s gave bad SSL client certificate: %d",
           client_p->name, client_p->username, client_p->host, res);
    X509_free(cert);
  }

  finish_ssl_server_handshake(client_p);
}

static void
ssl_connect_init(struct Client *client_p, struct MaskItem *conf, fde_t *fd)
{
  if ((client_p->localClient->fd.ssl = SSL_new(ServerInfo.client_ctx)) == NULL)
  {
    ilog(LOG_TYPE_IRCD, "SSL_new() ERROR! -- %s",
         ERR_error_string(ERR_get_error(), NULL));
    SetDead(client_p);
    exit_client(client_p, "SSL_new failed");
    return;
  }

  SSL_set_fd(fd->ssl, fd->fd);

  if (!EmptyString(conf->cipher_list))
    SSL_set_cipher_list(client_p->localClient->fd.ssl, conf->cipher_list);

  ssl_server_handshake(NULL, client_p);
}
#endif

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
  struct Client *client_p = data;
  struct MaskItem *conf = NULL;

  /* First, make sure its a real client! */
  assert(client_p);
  assert(&client_p->localClient->fd == fd);

  /* Next, for backward purposes, record the ip of the server */
  memcpy(&client_p->localClient->ip, &fd->connect.hostaddr,
         sizeof(struct irc_ssaddr));

  /* Check the status */
  if (status != COMM_OK)
  {
    /* We have an error, so report it and quit
     * Admins get to see any IP, mere opers don't *sigh*
     */
     if (ConfigServerHide.hide_server_ips)
       sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                            "Error connecting to %s: %s",
                            client_p->name, comm_errstr(status));
     else
       sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                            "Error connecting to %s[%s]: %s", client_p->name,
                            client_p->host, comm_errstr(status));

     sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                          "Error connecting to %s: %s",
                          client_p->name, comm_errstr(status));

     /* If a fd goes bad, call dead_link() the socket is no
      * longer valid for reading or writing.
      */
     dead_link_on_write(client_p, 0);
     return;
  }

  /* COMM_OK, so continue the connection procedure */
  /* Get the C/N lines */
  conf = find_conf_name(&client_p->localClient->confs,
                        client_p->name, CONF_SERVER);
  if (conf == NULL)
  {
    sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, HIDE_IP));
    sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                         "Lost connect{} block for %s", get_client_name(client_p, MASK_IP));

    exit_client(client_p, "Lost connect{} block");
    return;
  }

  /* Next, send the initial handshake */
  SetHandshake(client_p);

#ifdef HAVE_LIBCRYPTO
  if (IsConfSSL(conf))
  {
    ssl_connect_init(client_p, conf, fd);
    return;
  }
#endif

  sendto_one(client_p, "PASS %s TS %d %s", conf->spasswd, TS_CURRENT, me.id);

  send_capabilities(client_p, 0);

  sendto_one(client_p, "SERVER %s 1 :%s%s", me.name,
             ConfigServerHide.hidden ? "(H) " : "", me.info);

  /* If we've been marked dead because a send failed, just exit
   * here now and save everyone the trouble of us ever existing.
   */
  if (IsDead(client_p))
  {
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                           "%s[%s] went dead during handshake",
                           client_p->name,
                           client_p->host);
      sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                           "%s went dead during handshake", client_p->name);
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
