/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2019 ircd-hybrid development team
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

/*! \file server.c
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
#include "server_capab.h"
#include "log.h"
#include "send.h"
#include "memory.h"
#include "parse.h"


dlink_list flatten_links;
static void server_connect_callback(fde_t *, int, void *);


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
  dlink_node *node, *node_next;
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

/* server_hunt()
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
const struct server_hunt *
server_hunt(struct Client *source_p, const char *command,
            const int server, const int parc, char *parv[])
{
  static struct server_hunt hunt;
  struct server_hunt *const h = &hunt;
  dlink_node *node;

  /* Assume it's me, if no server */
  if (parc <= server || EmptyString(parv[server]))
  {
    h->target_p = &me;
    h->ret = HUNTED_ISME;
    return h;
  }

  if ((h->target_p = find_person(source_p, parv[server])) == NULL)
    h->target_p = hash_find_server(parv[server]);

  /*
   * These are to pickup matches that would cause the following
   * message to go in the wrong direction while doing quick fast
   * non-matching lookups.
   */
  if (h->target_p)
    if (h->target_p->from == source_p->from && !MyConnect(h->target_p))
      h->target_p = NULL;

  if (h->target_p == NULL && has_wildcards(parv[server]))
  {
    DLINK_FOREACH(node, global_server_list.head)
    {
      struct Client *tmp = node->data;

      assert(IsMe(tmp) || IsServer(tmp));
      if (match(parv[server], tmp->name) == 0)
      {
        if (tmp->from == source_p->from && !MyConnect(tmp))
          continue;

        h->target_p = tmp;
        break;
      }
    }

    if (h->target_p == NULL)
    {
      DLINK_FOREACH(node, global_client_list.head)
      {
        struct Client *tmp = node->data;

        assert(IsClient(tmp));
        if (match(parv[server], tmp->name) == 0)
        {
          if (tmp->from == source_p->from && !MyConnect(tmp))
            continue;

          h->target_p = tmp;
          break;
        }
      }
    }
  }

  if (h->target_p)
  {
    assert(IsMe(h->target_p) || IsServer(h->target_p) || IsClient(h->target_p));
    if (IsMe(h->target_p) || MyClient(h->target_p))
    {
      h->ret = HUNTED_ISME;
      return h;
    }

    parv[server] = h->target_p->id;
    sendto_one(h->target_p, command, source_p->id,
               parv[1], parv[2], parv[3], parv[4],
               parv[5], parv[6], parv[7], parv[8]);
    h->ret = HUNTED_PASS;
    return h;
  }

  sendto_one_numeric(source_p, &me, ERR_NOSUCHSERVER, parv[server]);
  h->ret = HUNTED_NOSUCH;
  return h;
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
  dlink_node *node;

  if (GlobalSetOptions.autoconn == false)
    return;

  DLINK_FOREACH(node, connect_items.head)
  {
    struct MaskItem *conf = node->data;

    assert(conf->type == CONF_SERVER);
    assert(conf->class);

    /* Also when already connecting! (update holdtimes) --SRB */
    if (conf->port == 0 || !IsConfAllowAutoConn(conf))
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
        dlinkDelete(node, &connect_items);
        dlinkAddTail(conf, &conf->node, &connect_items);
      }

      if (find_servconn_in_progress(conf->name))
        return;

      /*
       * We used to only print this if server_connect() actually
       * succeeded, but since comm_tcp_connect() can call the callback
       * immediately if there is an error, we were getting error messages
       * in the wrong order. SO, we just print out the activated line,
       * and let server_connect() / server_connect_callback() print an
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

      server_connect(conf, NULL);
      /* We connect only one at time... */
      return;
    }
  }
}

bool
server_valid_name(const char *name)
{
  unsigned int dots = 0;
  const char *p = name;

  for (; *p; ++p)
  {
    if (!IsServChar(*p))
      return false;

    if (*p == '.')
      ++dots;
  }

  return dots && (p - name) <= HOSTLEN;
}

/* server_make()
 *
 * inputs       - pointer to client struct
 * output       - pointer to struct Server
 * side effects - add's an Server information block to a client
 *                if it was not previously allocated.
 */
struct Server *
server_make(struct Client *client_p)
{
  if (client_p->serv == NULL)
    client_p->serv = xcalloc(sizeof(*client_p->serv));

  return client_p->serv;
}

/* server_connect() - initiate a server connection
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
bool
server_connect(struct MaskItem *conf, struct Client *by)
{
  char buf[HOSTIPLEN + 1] = "";

  /* Make sure conf is useful */
  assert(conf);
  assert(conf->type == CONF_SERVER);
  assert(hash_find_server(conf->name) == NULL);  /* This should have been checked by the caller */

  getnameinfo((const struct sockaddr *)&conf->addr, conf->addr.ss_len,
              buf, sizeof(buf), NULL, 0, NI_NUMERICHOST);
  ilog(LOG_TYPE_IRCD, "Connect to %s[%s] @%s", conf->name, conf->host, buf);

  /* Still processing a DNS lookup? -> exit */
  if (conf->dns_pending == true)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Error connecting to %s: DNS lookup for connect{} in progress.",
                         conf->name);
    return false;
  }

  if (conf->dns_failed == true)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Error connecting to %s: DNS lookup for connect{} failed.",
                         conf->name);
    return false;
  }

  /* Create a socket for the server connection */
  int fd = comm_socket(conf->addr.ss.ss_family, SOCK_STREAM, 0);
  if (fd == -1)
  {
    /* Eek, failure to create the socket */
    report_error(L_ALL, "opening stream socket to %s: %s", conf->name, errno);
    return false;
  }

  /* Create a local client */
  struct Client *client_p = client_make(NULL);

  /* Copy in the server, hostname, fd */
  strlcpy(client_p->name, conf->name, sizeof(client_p->name));
  strlcpy(client_p->host, conf->host, sizeof(client_p->host));

  /* We already converted the ip once, so lets use it - stu */
  strlcpy(client_p->sockhost, buf, sizeof(client_p->sockhost));

  client_p->connection->fd = fd_open(fd, true, NULL);

  /* Server names are always guaranteed under HOSTLEN chars */
  fd_note(client_p->connection->fd, "Server: %s", client_p->name);

  /*
   * Attach config entries to client here rather than in server_connect_callback().
   * This to avoid null pointer references.
   */
  conf_attach(client_p, conf);

  server_make(client_p);

  if (by && IsClient(by))
    strlcpy(client_p->serv->by, by->name, sizeof(client_p->serv->by));
  else
    strlcpy(client_p->serv->by, "AutoConn.", sizeof(client_p->serv->by));

  SetConnecting(client_p);
  client_p->ip.ss.ss_family = conf->aftype;

  /* Now, initiate the connection */
  /* XXX assume that a non 0 type means a specific bind address
   * for this connect.
   */
  switch (conf->aftype)
  {
    case AF_INET:
      if (((struct sockaddr_in*)&conf->bind)->sin_addr.s_addr)
        comm_connect_tcp(client_p->connection->fd, conf->host, conf->port,
                         (struct sockaddr *)&conf->bind, conf->bind.ss_len,
                         server_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      else
        comm_connect_tcp(client_p->connection->fd, conf->host, conf->port, NULL, 0,
                         server_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      break;
    case AF_INET6:
      if (IN6_IS_ADDR_UNSPECIFIED(&((struct sockaddr_in6 *)&conf->bind)->sin6_addr) == 0)
        comm_connect_tcp(client_p->connection->fd, conf->host, conf->port,
                         (struct sockaddr *)&conf->bind, conf->bind.ss_len,
                         server_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
      else
        comm_connect_tcp(client_p->connection->fd, conf->host, conf->port, NULL, 0,
                         server_connect_callback, client_p, conf->aftype,
                         CONNECTTIMEOUT);
  }

  /*
   * At this point we have a connection in progress and a connect {} block
   * attached to the client, the socket info should be saved in the client
   * and it should either be resolved or have a valid address.
   *
   * The socket has been connected or connect is in progress.
   */
  return true;
}

static void
server_finish_tls_handshake(struct Client *client_p)
{
  const struct MaskItem *conf = find_conf_name(&client_p->connection->confs,
                                                client_p->name, CONF_SERVER);
  if (!conf)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Lost connect{} block for %s", client_get_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Lost connect{} block for %s", client_get_name(client_p, MASK_IP));

    exit_client(client_p, "Lost connect{} block");
    return;
  }

  /* Next, send the initial handshake */
  SetHandshake(client_p);

  sendto_one(client_p, "PASS %s TS %u %s", conf->spasswd, TS_CURRENT, me.id);

  sendto_one(client_p, "CAPAB :%s", capab_get(NULL));

  sendto_one(client_p, "SERVER %s 1 :%s%s",
             me.name, ConfigServerHide.hidden ? "(H) " : "",
             me.info);

  /* If we get here, we're ok, so lets start reading some data */
  read_packet(client_p->connection->fd, client_p); 
}

static void
server_tls_handshake(fde_t *F, void *data)
{
  struct Client *client_p = data;
  const char *sslerr = NULL;

  assert(client_p);
  assert(client_p->connection);
  assert(client_p->connection->fd);
  assert(client_p->connection->fd == F);

  tls_handshake_status_t ret = tls_handshake(&F->ssl, TLS_ROLE_CLIENT, &sslerr);
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
        comm_setselect(F, COMM_SELECT_WRITE,
                       server_tls_handshake, client_p, CONNECTTIMEOUT);
        return;
      case TLS_HANDSHAKE_WANT_READ:
        comm_setselect(F, COMM_SELECT_READ,
                       server_tls_handshake, client_p, CONNECTTIMEOUT);
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

  comm_settimeout(F, 0, NULL, NULL);

  if (tls_verify_cert(&F->ssl, ConfigServerInfo.message_digest_algorithm, &client_p->certfp) == false)
    ilog(LOG_TYPE_IRCD, "Server %s!%s@%s gave bad TLS client certificate",
         client_p->name, client_p->username, client_p->host);

  server_finish_tls_handshake(client_p);
}

static void
server_tls_connect_init(struct Client *client_p, const struct MaskItem *conf, fde_t *F)
{
  assert(client_p);
  assert(client_p->connection);
  assert(client_p->connection->fd);
  assert(client_p->connection->fd == F);

  if (tls_new(&F->ssl, F->fd, TLS_ROLE_CLIENT) == false)
  {
    SetDead(client_p);
    exit_client(client_p, "TLS context initialization failed");
    return;
  }

  if (!EmptyString(conf->cipher_list))
    tls_set_ciphers(&F->ssl, conf->cipher_list);

  server_tls_handshake(F, client_p);
}

/* server_connect_callback() - complete a server connection.
 *
 * This routine is called after the server connection attempt has
 * completed. If unsucessful, an error is sent to ops and the client
 * is closed. If sucessful, it goes through the initialisation/check
 * procedures, the capabilities are sent, and the socket is then
 * marked for reading.
 */
static void
server_connect_callback(fde_t *F, int status, void *data)
{
  struct Client *const client_p = data;

  /* First, make sure it's a real client! */
  assert(client_p);
  assert(client_p->connection);
  assert(client_p->connection->fd);
  assert(client_p->connection->fd == F);

  /* Next, for backward purposes, record the ip of the server */
  memcpy(&client_p->ip, &F->connect.hostaddr, sizeof(client_p->ip));

  /* Check the status */
  if (status != COMM_OK)
  {
    /* We have an error, so report it and quit */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Error connecting to %s: %s",
                         client_get_name(client_p, SHOW_IP), comm_errstr(status));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Error connecting to %s: %s",
                         client_get_name(client_p, MASK_IP), comm_errstr(status));

    /*
     * If a fd goes bad, call dead_link() the socket is no
     * longer valid for reading or writing.
     */
    dead_link_on_write(client_p, 0);
    return;
  }

  /* COMM_OK, so continue the connection procedure */
  /* Get the connect {} block */
  const struct MaskItem *conf = find_conf_name(&client_p->connection->confs,
                                                client_p->name, CONF_SERVER);
  if (!conf)
  {
    sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                         "Lost connect{} block for %s", client_get_name(client_p, SHOW_IP));
    sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                         "Lost connect{} block for %s", client_get_name(client_p, MASK_IP));

    exit_client(client_p, "Lost connect{} block");
    return;
  }

  if (IsConfSSL(conf))
  {
    server_tls_connect_init(client_p, conf, F);
    return;
  }

  /* Next, send the initial handshake */
  SetHandshake(client_p);

  sendto_one(client_p, "PASS %s TS %u %s", conf->spasswd, TS_CURRENT, me.id);

  sendto_one(client_p, "CAPAB :%s", capab_get(NULL));

  sendto_one(client_p, "SERVER %s 1 :%s%s", me.name,
             ConfigServerHide.hidden ? "(H) " : "", me.info);

  /* If we get here, we're ok, so lets start reading some data */
  read_packet(client_p->connection->fd, client_p);
}

struct Client *
find_servconn_in_progress(const char *name)
{
  dlink_node *ptr;

  DLINK_FOREACH(ptr, unknown_list.head)
  {
    struct Client *cptr = ptr->data;

    if (cptr->name[0])
      if (!irccmp(name, cptr->name))
        return cptr;
  }

  return NULL;
}
