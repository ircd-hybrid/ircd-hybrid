/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file client.c
 * \brief Controls clients.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "auth.h"
#include "s_bsd.h"
#include "conf.h"
#include "conf_gecos.h"
#include "log.h"
#include "misc.h"
#include "server.h"
#include "send.h"
#include "whowas.h"
#include "user.h"
#include "memory.h"
#include "hostmask.h"
#include "listener.h"
#include "monitor.h"
#include "rng_mt.h"
#include "parse.h"
#include "ipcache.h"
#include "channel.h"
#include "channel_invite.h"


dlink_list listing_client_list;
dlink_list unknown_list;
dlink_list local_client_list;
dlink_list local_server_list;
dlink_list global_client_list;
dlink_list global_server_list;
dlink_list oper_list;

static dlink_list dead_list, abort_list;
static dlink_node *eac_next;  /* next aborted client to exit */

/**
 * @brief Create a new Client struct and set it to the initial state.
 *
 * If 'from' is NULL, it creates a local client (a client connected to a socket).
 * If 'from' is provided, it creates a remote client (behind a socket associated
 * with the local client defined by 'from').
 *
 * @param from The local client associated with the new remote client.
 * @return A pointer to the newly created Client struct.
 *
 * @warning If 'from' is NULL, the client is in a dangerous state with fd == -1.
 * The first thing after calling client_make(NULL) should be setting fd to a valid value.
 */
struct Client *
client_make(struct Client *from)
{
  struct Client *client = xcalloc(sizeof(*client));

  if (from)
    client->from = from;
  else
  {
    client->from = client;  /* 'from' of local client is self! */
    client->connection = xcalloc(sizeof(*client->connection));
    client->connection->last_data = event_base->time.sec_monotonic;
    client->connection->last_ping = event_base->time.sec_monotonic;
    client->connection->created_real = event_base->time.sec_real;
    client->connection->created_monotonic = event_base->time.sec_monotonic;
    client->connection->registration = REG_INIT;

    /* as good a place as any... */
    dlinkAdd(client, &client->connection->lclient_node, &unknown_list);
  }

  client->idhnext = client;
  client->hnext = client;
  SetUnknown(client);
  strcpy(client->username, "unknown");
  strcpy(client->account, "*");

  return client;
}

/*
 * client_free
 *
 * inputs	- pointer to client
 * output	- NONE
 * side effects	- client pointed to has its memory freed
 */
static void
client_free(struct Client *client)
{
  assert(!IsMe(client));
  assert(client != &me);
  assert(client->hnext == client);
  assert(client->idhnext == client);

  assert(client->node.prev == NULL);
  assert(client->node.next == NULL);

  assert(client->lnode.prev == NULL);
  assert(client->lnode.next == NULL);

  assert(dlink_list_length(&client->whowas_list) == 0);
  assert(client->whowas_list.head == NULL);
  assert(client->whowas_list.tail == NULL);

  assert(dlink_list_length(&client->channel) == 0);
  assert(client->channel.head == NULL);
  assert(client->channel.tail == NULL);

  assert(dlink_list_length(&client->svstags) == 0);
  assert(client->svstags.head == NULL);
  assert(client->svstags.tail == NULL);


  xfree(client->serv);
  xfree(client->tls_certfp);
  xfree(client->tls_cipher);

  if (MyConnect(client))
  {
    assert(client->connection->lclient_node.prev == NULL);
    assert(client->connection->lclient_node.next == NULL);

    assert(client->connection->list_task == NULL);
    assert(client->connection->auth == NULL);

    assert(dlink_list_length(&client->connection->acceptlist) == 0);
    assert(client->connection->acceptlist.head == NULL);
    assert(client->connection->acceptlist.tail == NULL);


    assert(dlink_list_length(&client->connection->monitors) == 0);
    assert(client->connection->monitors.head == NULL);
    assert(client->connection->monitors.tail == NULL);

    assert(dlink_list_length(&client->connection->confs) == 0);
    assert(client->connection->confs.head == NULL);
    assert(client->connection->confs.tail == NULL);

    assert(dlink_list_length(&client->connection->invited) == 0);
    assert(client->connection->invited.head == NULL);
    assert(client->connection->invited.tail == NULL);

    assert(client->connection->fd == NULL);

    assert(HasFlag(client, FLAGS_CLOSING) && IsDead(client));

    /*
     * Clean up extra sockets from listen {} blocks which have been discarded.
     */
    if (client->connection->listener)
    {
      listener_release(client->connection->listener);
      client->connection->listener = NULL;
    }

    dbuf_clear(&client->connection->buf_recvq);
    dbuf_clear(&client->connection->buf_sendq);

    xfree(client->connection);
    client->connection = NULL;
  }

  xfree(client);
}

/* check_pings_list()
 *
 * inputs	- pointer to list to check
 * output	- NONE
 * side effects	-
 */
static void
check_pings_list(dlink_list *list)
{
  char buf[32];  /* 32 = sizeof("Ping timeout: 999999999 seconds") */
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, list->head)
  {
    struct Client *client = node->data;
    assert(IsClient(client) || IsServer(client));

    if (IsDead(client))
      continue;  /* Ignore it, it's been exited already */

    unsigned int ping = class_get_ping_freq(&client->connection->confs);
    if (ping < event_base->time.sec_monotonic - client->connection->last_ping)
    {
      if (!HasFlag(client, FLAGS_PINGSENT))
      {
        /*
         * If we haven't PINGed the connection and we haven't
         * heard from it in a while, PING it to make sure
         * it is still alive.
         */
        AddFlag(client, FLAGS_PINGSENT);
        client->connection->last_ping = event_base->time.sec_monotonic - ping;
        sendto_one(client, "PING :%s", ID_or_name(&me, client));
      }
      else
      {
        if (event_base->time.sec_monotonic - client->connection->last_ping >= 2 * ping)
        {
          /*
           * If the client/server hasn't talked to us in 2*ping seconds
           * and it has a ping time, then close its connection.
           */
          if (IsServer(client))
          {
            sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                                 "No response from %s, closing link",
                                 client_get_name(client, SHOW_IP));
            sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                                 "No response from %s, closing link",
                                 client_get_name(client, MASK_IP));
            ilog(LOG_TYPE_IRCD, "No response from %s, closing link",
                 client_get_name(client, SHOW_IP));
          }

          snprintf(buf, sizeof(buf), "Ping timeout: %ju seconds",
                   (event_base->time.sec_monotonic - client->connection->last_ping));
          exit_client(client, buf);
        }
      }
    }
  }
}

/* check_unknowns_list()
 *
 * inputs       - pointer to list of unknown clients
 * output       - NONE
 * side effects - unknown clients get marked for termination after n seconds
 */
static void
check_unknowns_list(void)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client = node->data;
    bool exit = false;

    /*
     * Check UNKNOWN connections - if they have been in this state
     * for > 30s, close them.
     */
    if ((event_base->time.sec_monotonic - client->connection->created_monotonic) <= 30)
      continue;

    if (IsHandshake(client))
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                           "No response from %s during handshake, closing link",
                           client_get_name(client, SHOW_IP));
      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                           "No response from %s during handshake, closing link",
                           client_get_name(client, MASK_IP));
      ilog(LOG_TYPE_IRCD, "No response from %s during handshake, closing link",
           client_get_name(client, SHOW_IP));
      exit = true;
    }
    else if (HasFlag(client, FLAGS_FINISHED_AUTH))
      exit = true;

    if (exit == true)
      exit_client(client, "Registration timed out");
  }
}

/*
 * check_pings - go through the local client list and check activity
 * kill off stuff that should die
 *
 * inputs       - NOT USED (from event)
 * side effects -
 *
 *
 * A PING can be sent to clients as necessary.
 *
 * Client/Server ping outs are handled.
 */

/*
 * Addon from adrian. We used to call this after nextping seconds,
 * however I've changed it to run once a second. This is only for
 * PING timeouts, not K/etc-line checks (thanks dianora!). Having it
 * run once a second makes life a lot easier - when a new client connects
 * and they need a ping in 4 seconds, if nextping was set to 20 seconds
 * we end up waiting 20 seconds. This is stupid. :-)
 * I will optimise (hah!) check_pings() once I've finished working on
 * tidying up other network IO evilnesses.
 *     -- adrian
 */

static void
check_pings(void *unused)
{
  check_pings_list(&local_client_list);
  check_pings_list(&local_server_list);
  check_unknowns_list();
}

/* check_conf_klines()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - Check all connections for a pending kline against the
 * 		  client, exit the client if a kline matches.
 */
void
check_conf_klines(void)
{
  dlink_node *node, *node_next;
  const void *ptr;

  DLINK_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client = node->data;

    /* If a client is already being exited */
    if (IsDead(client))
      continue;

    if ((ptr = find_conf_by_address(NULL, &client->ip, CONF_DLINE, NULL, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_DLINE, conf->reason);
      continue;  /* and go examine next Client */
    }

    if ((ptr = find_conf_by_address(client->host, &client->ip, CONF_KLINE,
                                    client->username, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_KLINE, conf->reason);
      continue;  /* and go examine next Client */
    }

    if ((ptr = gecos_find(client->info, match)))
    {
      const struct GecosItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_XLINE, conf->reason);
      continue;  /* and go examine next Client */
    }
  }

  /* Also check the unknowns list for new dlines */
  DLINK_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client = node->data;

    /* If a client is already being exited */
    if (IsDead(client))
      continue;

    if ((ptr = find_conf_by_address(NULL, &client->ip, CONF_DLINE, NULL, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_DLINE, conf->reason);
      continue;  /* and go examine next Client */
    }
  }
}

/*
 * conf_try_ban
 *
 * inputs	- pointer to client to ban
 * 		- pointer to MaskItem
 * output	- NONE
 * side effects	- given client is banned
 */
void
conf_try_ban(struct Client *client, int type, const char *reason)
{
  char ban_type = '?';

  switch (type)
  {
    case CLIENT_BAN_KLINE:
      if (HasFlag(client, FLAGS_EXEMPTKLINE))
      {
        sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                             "KLINE over-ruled for %s, client is kline_exempt",
                             client_get_name(client, HIDE_IP));
        return;
      }

      ban_type = 'K';
      break;
    case CLIENT_BAN_DLINE:
      if (find_conf_by_address(NULL, &client->ip, CONF_EXEMPT, NULL, NULL, 1))
        return;
      ban_type = 'D';
      break;
    case CLIENT_BAN_XLINE:
      if (HasFlag(client, FLAGS_EXEMPTXLINE))
      {
        sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                             "XLINE over-ruled for %s, client is xline_exempt",
                             client_get_name(client, HIDE_IP));
        return;
      }

      ban_type = 'X';
      break;
    default:
      assert(0);
      break;
  }

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%c-line active for %s",
                       ban_type, client_get_name(client, HIDE_IP));

  if (IsClient(client))
    sendto_one_numeric(client, &me, ERR_YOUREBANNEDCREEP, reason);

  exit_client(client, reason);
}

/* find_person()
 *
 * inputs	- pointer to name
 * output	- return client pointer
 * side effects - find person by (nick)name
 */
struct Client *
find_person(const struct Client *source_p, const char *name)
{
  struct Client *target_p = NULL;

  if (IsDigit(*name))
  {
    if (IsServer(source_p->from))
      target_p = hash_find_id(name);
  }
  else
    target_p = hash_find_client(name);

  if (target_p && IsClient(target_p))
    return target_p;

  return NULL;
}

/*
 * find_chasing - find the client structure for a nick name (name)
 *      using history mechanism if necessary. If the client is not found,
 *      an error message (NO SUCH NICK) is generated.
 */
struct Client *
find_chasing(struct Client *source_p, const char *name)
{
  struct Client *target_p = find_person(source_p, name);

  if (target_p)
    return target_p;

  if (IsDigit(*name))
    return NULL;

  target_p = whowas_get_history(name, ConfigGeneral.kill_chase_time_limit);
  if (target_p == NULL)
    sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, name);

  return target_p;
}

/*
 * client_get_name -  Return the name of the client
 *    for various tracking and
 *      admin purposes. The main purpose of this function is to
 *      return the "socket host" name of the client, if that
 *        differs from the advertised name (other than case).
 *        But, this can be used to any client structure.
 */
const char *
client_get_name(const struct Client *client, enum addr_mask_type type)
{
  static char buf[HOSTLEN * 2 + USERLEN + 4];  /* +4 for [,@,],\0 */

  if (!MyConnect(client))
    return client->name;

  if (IsServer(client) || IsConnecting(client) || IsHandshake(client))
  {
    if (irccmp(client->name, client->host) == 0)
      return client->name;
    else if (ConfigServerHide.hide_server_ips)
      type = MASK_IP;
  }

  /* And finally, let's get the host information, ip or name */
  switch (type)
  {
    case SHOW_IP:
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client->name,
               client->username, client->sockhost);
      break;
    case MASK_IP:
      if (client->ip.ss.ss_family == AF_INET)
        snprintf(buf, sizeof(buf), "%s[%s@255.255.255.255]",
                 client->name, client->username);
      else
        snprintf(buf, sizeof(buf), "%s[%s@ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]",
                 client->name, client->username);
      break;
    default:  /* HIDE_IP */
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client->name,
               client->username, client->host);
  }

  return buf;
}

void
free_exited_clients(void)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, dead_list.head)
  {
    client_free(node->data);
    dlinkDelete(node, &dead_list);
    free_dlink_node(node);
  }
}

/*
 * client_close_connection
 *        Close the physical connection. This function must make
 *        MyConnect(client) == FALSE, and set client->from == NULL.
 */
static void
client_close_connection(struct Client *client)
{
  assert(client);

  if (!IsDead(client))
  {
    /* Attempt to flush any pending dbufs. Evil, but .. -- adrian */
    /*
     * There is still a chance that we might send data to this socket
     * even if it is marked as blocked (COMM_SELECT_READ handler is called
     * before COMM_SELECT_WRITE). Let's try, nothing to lose.. -adx
     */
    DelFlag(client, FLAGS_BLOCKED);
    send_queued_write(client);
  }

  if (IsClient(client))
  {
    ++ServerStats.is_cl;
    ServerStats.is_cbs += client->connection->send.bytes;
    ServerStats.is_cbr += client->connection->recv.bytes;
    ServerStats.is_cti += event_base->time.sec_monotonic - client->connection->created_monotonic;
  }
  else if (IsServer(client))
  {
    dlink_node *node;

    ++ServerStats.is_sv;
    ServerStats.is_sbs += client->connection->send.bytes;
    ServerStats.is_sbr += client->connection->recv.bytes;
    ServerStats.is_sti += event_base->time.sec_monotonic - client->connection->created_monotonic;

    DLINK_FOREACH(node, connect_items.head)
    {
      struct MaskItem *conf = node->data;

      /*
       * Reset next-connect cycle of all connect{} blocks that match
       * this servername.
       */
      if (irccmp(conf->name, client->name) == 0)
        conf->until = event_base->time.sec_monotonic + conf->class->con_freq;
    }
  }
  else
    ++ServerStats.is_ni;

  if (tls_isusing(&client->connection->fd->tls))
    tls_shutdown(&client->connection->fd->tls);

  if (client->connection->fd)
  {
    fd_close(client->connection->fd);
    client->connection->fd = NULL;
  }

  dbuf_clear(&client->connection->buf_sendq);
  dbuf_clear(&client->connection->buf_recvq);

  xfree(client->connection->password);
  client->connection->password = NULL;

  conf_detach(client, CONF_CLIENT | CONF_OPER | CONF_SERVER);
}

/*
 * Exit one client, local or remote. Assuming all dependents have
 * been already removed, and socket closed for local client.
 *
 * The only messages generated are QUITs on channels.
 */
static void
exit_one_client(struct Client *client, const char *comment)
{
  dlink_node *node, *node_next;

  assert(!IsMe(client));
  assert(client != &me);

  if (IsClient(client))
  {
    if (HasUMode(client, UMODE_OPER))
      --Count.oper;
    if (HasUMode(client, UMODE_INVISIBLE))
      --Count.invisi;

    dlinkDelete(&client->lnode, &client->servptr->serv->client_list);
    dlinkDelete(&client->node, &global_client_list);

    /*
     * If a person is on a channel, send a QUIT notice
     * to every client (person) on the same channel (so
     * that the client can show the "**signoff" message).
     * (Note: The notice is to the local clients *only*)
     */
    sendto_common_channels_local(client, false, 0, 0, ":%s!%s@%s QUIT :%s",
                                 client->name, client->username,
                                 client->host, comment);

    DLINK_FOREACH_SAFE(node, node_next, client->channel.head)
      channel_remove_user(node->data);

    svstag_clear_list(&client->svstags);

    whowas_add_history(client, false);
    whowas_off_history(client);

    monitor_signoff(client);
  }
  else if (IsServer(client))
  {
    sendto_realops_flags(UMODE_EXTERNAL, L_ALL, SEND_NOTICE,
                         "Server %s split from %s",
                         client->name, client->servptr->name);

    dlinkDelete(&client->lnode, &client->servptr->serv->server_list);
    dlinkDelete(&client->node, &global_server_list);
  }

  if (client->id[0])
    hash_del_id(client);

  if (client->name[0])
    hash_del_client(client);

  if (HasFlag(client, FLAGS_IPHASH))
  {
    DelFlag(client, FLAGS_IPHASH);
    ipcache_record_remove(&client->ip, MyConnect(client));
  }

  /* Check to see if the client isn't already on the dead list */
  assert(dlinkFind(&dead_list, client) == NULL);

  /* Add to dead client dlist */
  SetDead(client);
  dlinkAdd(client, make_dlink_node(), &dead_list);
}

/*
 * Remove all clients that depend on 'client'; assumes all (S)QUITs have
 * already been sent.  we make sure to exit a server's dependent clients
 * and servers before the server itself; exit_one_client takes care of
 * actually removing things off llists.   tweaked from +CSr31  -orabidoo
 */
static void
recurse_remove_clients(struct Client *client, const char *comment)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, client->serv->client_list.head)
    exit_one_client(node->data, comment);

  DLINK_FOREACH_SAFE(node, node_next, client->serv->server_list.head)
  {
    recurse_remove_clients(node->data, comment);
    exit_one_client(node->data, comment);
  }
}

/*
 * exit_client - exit a client of any type. Generally, you can use
 * this on any struct Client, regardless of its state.
 *
 * Note, you shouldn't exit remote _users_ without first doing
 * AddFlag(x, FLAGS_KILLED) and propagating a kill or similar message.
 *
 * However, it is perfectly correct to call exit_client to force a _server_
 * quit (either local or remote one).
 *
 *
 * inputs:       - a client pointer that is going to be exited
 * output:       none
 * side effects: the client is delinked from all lists, disconnected,
 *               and the rest of IRC network is notified of the exit.
 *               Client memory is scheduled to be freed
 */
void
exit_client(struct Client *client, const char *comment)
{
  assert(!IsMe(client));
  assert(client != &me);

  if (MyConnect(client))
  {
    assert(client == client->from);

    /*
     * DO NOT REMOVE. exit_client can be called twice after a failed read/write.
     */
    if (HasFlag(client, FLAGS_CLOSING))
      return;

    AddFlag(client, FLAGS_CLOSING);

    if (client->connection->auth)
    {
      auth_delete(client->connection->auth);
      client->connection->auth = NULL;
    }

    if (IsClient(client))
    {
      if (HasUMode(client, UMODE_OPER))
      {
        dlink_node *node = dlinkFindDelete(&oper_list, client);
        if (node)
          free_dlink_node(node);
      }

      assert(dlinkFind(&local_client_list, client));
      dlinkDelete(&client->connection->lclient_node, &local_client_list);

      if (client->connection->list_task)
        free_list_task(client);

      invite_clear_list(&client->connection->invited);

      accept_clear_list(&client->connection->acceptlist);

      monitor_clear_list(client);

      sendto_realops_flags(UMODE_CCONN, L_ALL, SEND_NOTICE,
                           "Client exiting: %s (%s@%s) [%s] [%s]",
                           client->name, client->username, client->realhost,
                           client->sockhost, comment);

      ilog(LOG_TYPE_USER, "%s (%ju): %s!%s@%s %s %s %ju/%ju :%s",
           date_ctime(client->connection->created_real),
           event_base->time.sec_monotonic - client->connection->created_monotonic,
           client->name, client->username, client->host,
           client->sockhost, client->account,
           client->connection->send.bytes >> 10,
           client->connection->recv.bytes >> 10, client->info);
    }
    else if (IsServer(client))
    {
      assert(dlinkFind(&local_server_list, client));
      dlinkDelete(&client->connection->lclient_node, &local_server_list);

      if (!HasFlag(client, FLAGS_SQUIT))
        /* For them, we are exiting the network */
        sendto_one(client, ":%s SQUIT %s :%s", me.id, me.id, comment);
    }
    else
    {
      assert(dlinkFind(&unknown_list, client));
      dlinkDelete(&client->connection->lclient_node, &unknown_list);
    }

    sendto_one(client, "ERROR :Closing Link: %s (%s)", client->host, comment);

    client_close_connection(client);
  }
  else if (IsClient(client) && HasFlag(client->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client exiting at %s: %s (%s@%s) [%s] [%s]",
                         client->servptr->name, client->name,
                         client->username, client->realhost, client->sockhost, comment);

  if (IsServer(client))
  {
    char splitstr[HOSTLEN + HOSTLEN + 2];  /* +2 for space and \0 */

    assert(client->serv);
    assert(client->servptr);

    if (ConfigServerHide.hide_servers)
      /*
       * Set netsplit message to "*.net *.split" to still show that it's a split,
       * but hide the servers splitting.
       */
      strlcpy(splitstr, "*.net *.split", sizeof(splitstr));
    else
      snprintf(splitstr, sizeof(splitstr), "%s %s",
               client->servptr->name, client->name);

    /* Send SQUIT for 'client' in every direction. 'client' is already off of local_server_list here */
    if (!HasFlag(client, FLAGS_SQUIT))
      sendto_server(NULL, 0, 0, "SQUIT %s :%s", client->id, comment);

    /* Now exit the clients internally */
    recurse_remove_clients(client, splitstr);

    if (MyConnect(client))
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "%s was connected for %s. %ju/%ju sendK/recvK.",
                           client->name, time_dissect(event_base->time.sec_monotonic - client->connection->created_monotonic),
                           client->connection->send.bytes >> 10,
                           client->connection->recv.bytes >> 10);
      ilog(LOG_TYPE_IRCD, "%s was connected for %s. %ju/%ju sendK/recvK.",
           client->name, time_dissect(event_base->time.sec_monotonic - client->connection->created_monotonic),
           client->connection->send.bytes >> 10,
           client->connection->recv.bytes >> 10);
    }
  }
  else if (IsClient(client) && !HasFlag(client, FLAGS_KILLED))
    sendto_server(client->from, 0, 0, ":%s QUIT :%s", client->id, comment);

  /* The client *better* be off all of the lists */
  assert(dlinkFind(&unknown_list, client) == NULL);
  assert(dlinkFind(&local_client_list, client) == NULL);
  assert(dlinkFind(&local_server_list, client) == NULL);
  assert(dlinkFind(&oper_list, client) == NULL);
  assert(dlinkFind(&listing_client_list, client) == NULL);
  assert(dlinkFind(&abort_list, client) == NULL);

  exit_one_client(client, comment);
}

/*
 * dead_link_on_write - report a write error if not already dead,
 *			mark it as dead then exit it
 */
void
dead_link_on_write(struct Client *client, int ierrno)
{
  dlink_node *node;

  if (IsDefunct(client))
    return;

  dbuf_clear(&client->connection->buf_recvq);
  dbuf_clear(&client->connection->buf_sendq);

  assert(dlinkFind(&abort_list, client) == NULL);
  node = make_dlink_node();
  /* don't let exit_aborted_clients() finish yet */
  dlinkAddTail(client, node, &abort_list);

  if (eac_next == NULL)
    eac_next = node;

  SetDead(client); /* You are dead my friend */
}

/*
 * dead_link_on_read -  report a read error if not already dead,
 *			mark it as dead then exit it
 */
void
dead_link_on_read(struct Client *client, int error)
{
  char errmsg[IRCD_BUFSIZE];
  int current_error;

  if (IsDefunct(client))
    return;

  dbuf_clear(&client->connection->buf_recvq);
  dbuf_clear(&client->connection->buf_sendq);

  current_error = comm_get_sockerr(client->connection->fd);

  if (IsServer(client) || IsHandshake(client))
  {
    if (error == 0)
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                           "Server %s closed the connection",
                           client_get_name(client, SHOW_IP));
      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                           "Server %s closed the connection",
                           client_get_name(client, MASK_IP));
      ilog(LOG_TYPE_IRCD, "Server %s closed the connection",
           client_get_name(client, SHOW_IP));
    }
    else
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ADMIN, SEND_NOTICE,
                           "Lost connection to %s: %s",
                           client_get_name(client, SHOW_IP), strerror(current_error));
      sendto_realops_flags(UMODE_SERVNOTICE, L_OPER, SEND_NOTICE,
                           "Lost connection to %s: %s",
                           client_get_name(client, MASK_IP), strerror(current_error));
      ilog(LOG_TYPE_IRCD, "Lost connection to %s: %s",
           client_get_name(client, SHOW_IP), strerror(current_error));
    }

    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "%s was connected for %s",
                         client->name, time_dissect(event_base->time.sec_monotonic - client->connection->created_monotonic));
  }

  if (error == 0)
    strlcpy(errmsg, "Remote host closed the connection",
            sizeof(errmsg));
  else
    snprintf(errmsg, sizeof(errmsg), "Read error: %s",
             strerror(current_error));

  exit_client(client, errmsg);
}

void
exit_aborted_clients(void)
{
  dlink_node *ptr;
  const char *notice;

  DLINK_FOREACH_SAFE(ptr, eac_next, abort_list.head)
  {
    struct Client *client = ptr->data;
    eac_next = ptr->next;

    dlinkDelete(ptr, &abort_list);
    free_dlink_node(ptr);

    if (client == NULL)
    {
      sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                           "Warning: null client on abort_list!");
      continue;
    }

    if (HasFlag(client, FLAGS_SENDQEX))
      notice = "Max SendQ exceeded";
    else
      notice = "Write error: connection closed";

    exit_client(client, notice);
  }
}

/*
 * accept processing, this adds a form of "caller ID" to ircd
 *
 * If a client puts themselves into "caller ID only" mode,
 * only clients that match a client pointer they have put on
 * the accept list will be allowed to message them.
 *
 * Diane Bruce, "Dianora" db@db.net
 */

void
accept_del(struct AcceptItem *accept, dlink_list *list)
{
  dlinkDelete(&accept->node, list);

  xfree(accept->nick);
  xfree(accept->user);
  xfree(accept->host);
  xfree(accept);
}

struct AcceptItem *
accept_find(const char *nick,
            const char *user,
            const char *host, dlink_list *list,
            int (*compare)(const char *, const char *))
{
  dlink_node *node;

  DLINK_FOREACH(node, list->head)
  {
    struct AcceptItem *accept = node->data;

    if (compare(accept->nick, nick) == 0 &&
        compare(accept->user, user) == 0 &&
        compare(accept->host, host) == 0)
      return accept;
  }

  return NULL;
}

/* accept_message()
 *
 * inputs       - pointer to source client
 *              - pointer to target client
 * output       - 1 if accept this message 0 if not
 * side effects - See if source is on target's allow list
 */
bool
accept_message(struct Client *source,
               struct Client *target)
{
  dlink_node *node;

  if (HasFlag(source, FLAGS_SERVICE) ||
      (HasUMode(source, UMODE_OPER) && ConfigGeneral.opers_bypass_callerid))
    return true;

  if (source == target || accept_find(source->name, source->username, source->host,
                                      &target->connection->acceptlist, match))
    return true;

  if (!HasUMode(target, UMODE_CALLERID) && HasUMode(target, UMODE_SOFTCALLERID))
    DLINK_FOREACH(node, target->channel.head)
      if (member_find_link(source, ((struct ChannelMember *)node->data)->channel))
        return true;

  return false;
}

/* del_all_accepts()
 *
 * inputs       - pointer to exiting client
 * output       - NONE
 * side effects - Walk through given clients acceptlist and remove all entries
 */
void
accept_clear_list(dlink_list *list)
{
  while (list->head)
    accept_del(list->head->data, list);
}

/** 
 * @brief Retrieves the (fake) idle time for a target client.
 *
 * This function calculates the (fake) idle time for a target client based on the
 * configuration of the class it belongs to. If fake idle is not enabled or the
 * target client is the same as the source client, the actual idle time is returned.
 * If the source client has oper mode and hiding idle from opers is not enabled, the
 * actual idle time is also returned. Otherwise, the (fake) idle time is calculated
 * based on the class configuration.
 *
 * @param source_p Pointer to the source client.
 * @param target_p Pointer to the target client.
 * @return The calculated (fake) idle time for the target client.
 */
unsigned int
client_get_idle_time(const struct Client *source_p,
                     const struct Client *target_p)
{
  unsigned int idle = 0;
  const struct ClassItem *const class = class_get_ptr(&target_p->connection->confs);

  if (!(class->flags & CLASS_FLAGS_FAKE_IDLE) || target_p == source_p)
    return event_base->time.sec_monotonic - target_p->connection->last_privmsg;

  if (HasUMode(source_p, UMODE_OPER) &&
      !(class->flags & CLASS_FLAGS_HIDE_IDLE_FROM_OPERS))
    return event_base->time.sec_monotonic - target_p->connection->last_privmsg;

  const unsigned int min_idle = class->min_idle;
  const unsigned int max_idle = class->max_idle;

  if (min_idle == max_idle)
    return min_idle;

  if (class->flags & CLASS_FLAGS_RANDOM_IDLE)
    idle = genrand_int32();
  else
    idle = event_base->time.sec_monotonic - target_p->connection->last_privmsg;

  if (max_idle)
    idle %= max_idle;
  else
    idle = 0;

  if (idle < min_idle)
    idle = min_idle + (idle % (max_idle - min_idle));

  return idle;
}

/* client_init()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects - initialize client free memory
 */
void
client_init(void)
{
  static struct event event_ping =
  {
    .name = "check_pings",
    .handler = check_pings,
    .when = 5
  };

  event_add(&event_ping, NULL);
}
