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
#include "io_time.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "auth.h"
#include "comm.h"
#include "conf.h"
#include "conf_gecos.h"
#include "log.h"
#include "misc.h"
#include "server.h"
#include "send.h"
#include "whowas.h"
#include "user.h"
#include "memory.h"
#include "listener.h"
#include "monitor.h"
#include "rng_mt.h"
#include "parse.h"
#include "ipcache.h"
#include "channel.h"
#include "channel_invite.h"
#include "accept.h"

list_t listing_client_list;
list_t unknown_list;
list_t local_client_list;
list_t local_server_list;
list_t global_client_list;
list_t global_server_list;
list_t oper_list;

static list_t dead_list, abort_list;
static list_node_t *eac_next;  /* next aborted client to exit */

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
  struct Client *client = io_calloc(sizeof(*client));

  if (from)
    client->from = from;
  else
  {
    client->from = client;  /* 'from' of local client is self! */
    client->connection = io_calloc(sizeof(*client->connection));
    client->connection->last_data = \
    client->connection->last_ping = \
    client->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
    client->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);
    client->connection->registration = REG_INIT;

    /* as good a place as any... */
    list_add(client, &client->connection->node, &unknown_list);
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

  assert(list_length(&client->whowas_list) == 0);
  assert(client->whowas_list.head == NULL);
  assert(client->whowas_list.tail == NULL);

  assert(list_length(&client->channel) == 0);
  assert(client->channel.head == NULL);
  assert(client->channel.tail == NULL);

  assert(list_length(&client->svstags) == 0);
  assert(client->svstags.head == NULL);
  assert(client->svstags.tail == NULL);


  io_free(client->serv);
  io_free(client->tls_certfp);
  io_free(client->tls_cipher);

  if (MyConnect(client))
  {
    assert(client->connection->node.prev == NULL);
    assert(client->connection->node.next == NULL);

    assert(client->connection->list_task == NULL);
    assert(client->connection->auth == NULL);

    assert(list_length(&client->connection->acceptlist) == 0);
    assert(client->connection->acceptlist.head == NULL);
    assert(client->connection->acceptlist.tail == NULL);


    assert(list_length(&client->connection->monitors) == 0);
    assert(client->connection->monitors.head == NULL);
    assert(client->connection->monitors.tail == NULL);

    assert(list_length(&client->connection->confs) == 0);
    assert(client->connection->confs.head == NULL);
    assert(client->connection->confs.tail == NULL);

    assert(list_length(&client->connection->invited) == 0);
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

    io_free(client->connection);
    client->connection = NULL;
  }

  io_free(client);
}

/* check_pings_list()
 *
 * inputs	- pointer to list to check
 * output	- NONE
 * side effects	-
 */
static void
check_pings_list(list_t *list)
{
  char buf[32];  /* 32 = sizeof("Ping timeout: 999999999 seconds") */
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, list->head)
  {
    struct Client *client = node->data;
    assert(IsClient(client) || IsServer(client));

    if (IsDead(client))
      continue;  /* Ignore it, it's been exited already */

    unsigned int ping = class_get_ping_freq(&client->connection->confs);
    if (ping < io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->last_ping)
    {
      if (!HasFlag(client, FLAGS_PINGSENT))
      {
        /*
         * If we haven't PINGed the connection and we haven't
         * heard from it in a while, PING it to make sure
         * it is still alive.
         */
        AddFlag(client, FLAGS_PINGSENT);
        client->connection->last_ping = io_time_get(IO_TIME_MONOTONIC_SEC) - ping;
        sendto_one(client, "PING :%s", ID_or_name(&me, client));
      }
      else
      {
        if (io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->last_ping >= 2 * ping)
        {
          /*
           * If the client/server hasn't talked to us in 2*ping seconds
           * and it has a ping time, then close its connection.
           */
          if (IsServer(client))
          {
            sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                                 "No response from %s, closing link",
                                 client_get_name(client, SHOW_IP));
            sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                                 "No response from %s, closing link",
                                 client_get_name(client, MASK_IP));
            log_write(LOG_TYPE_IRCD, "No response from %s, closing link",
                      client_get_name(client, SHOW_IP));
          }

          snprintf(buf, sizeof(buf), "Ping timeout: %ju seconds",
                   (io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->last_ping));
          client_exit(client, buf);
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
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client = node->data;
    bool exit = false;

    /*
     * Check UNKNOWN connections - if they have been in this state
     * for > 30s, close them.
     */
    if ((io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic) <= 30)
      continue;

    if (IsHandshake(client))
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                           "No response from %s during handshake, closing link",
                           client_get_name(client, SHOW_IP));
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                           "No response from %s during handshake, closing link",
                           client_get_name(client, MASK_IP));
      log_write(LOG_TYPE_IRCD, "No response from %s during handshake, closing link",
                client_get_name(client, SHOW_IP));
      exit = true;
    }
    else if (HasFlag(client, FLAGS_FINISHED_AUTH))
      exit = true;

    if (exit)
      client_exit(client, "Registration timed out");
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
  list_node_t *node, *node_next;
  const void *ptr;

  LIST_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client = node->data;

    /* If a client is already being exited */
    if (IsDead(client))
      continue;

    if ((ptr = find_conf_by_address(NULL, &client->addr, CONF_DLINE, NULL, NULL, 1)))
    {
      const struct MaskItem *conf = ptr;
      conf_try_ban(client, CLIENT_BAN_DLINE, conf->reason);
      continue;  /* and go examine next Client */
    }

    if ((ptr = find_conf_by_address(client->host, &client->addr, CONF_KLINE,
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
  LIST_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client = node->data;

    /* If a client is already being exited */
    if (IsDead(client))
      continue;

    if ((ptr = find_conf_by_address(NULL, &client->addr, CONF_DLINE, NULL, NULL, 1)))
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
        sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                             "KLINE over-ruled for %s, client is kline_exempt",
                             client_get_name(client, HIDE_IP));
        return;
      }

      ban_type = 'K';
      break;
    case CLIENT_BAN_DLINE:
      if (find_conf_by_address(NULL, &client->addr, CONF_EXEMPT, NULL, NULL, 1))
        return;
      ban_type = 'D';
      break;
    case CLIENT_BAN_XLINE:
      if (HasFlag(client, FLAGS_EXEMPTXLINE))
      {
        sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
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

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%c-line active for %s",
                       ban_type, client_get_name(client, HIDE_IP));

  if (IsClient(client))
    sendto_one_numeric(client, &me, ERR_YOUREBANNEDCREEP, reason);

  client_exit(client, reason);
}

/* find_person()
 *
 * inputs	- pointer to name
 * output	- return client pointer
 * side effects - find person by (nick)name
 */
struct Client *
find_person(const struct Client *client, const char *name)
{
  struct Client *target = NULL;

  if (IsDigit(*name))
  {
    if (IsServer(client->from))
      target = hash_find_id(name);
  }
  else
    target = hash_find_client(name);

  if (target && IsClient(target))
    return target;

  return NULL;
}

/*
 * find_chasing - find the client structure for a nick name (name)
 *      using history mechanism if necessary. If the client is not found,
 *      an error message (NO SUCH NICK) is generated.
 */
struct Client *
find_chasing(struct Client *client, const char *name)
{
  struct Client *target = find_person(client, name);

  if (target)
    return target;

  if (IsDigit(*name))
    return NULL;

  target = whowas_get_history(name, ConfigGeneral.kill_chase_time_limit);
  if (target == NULL)
    sendto_one_numeric(client, &me, ERR_NOSUCHNICK, name);

  return target;
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
               client->name, client->username, client->sockhost);
      break;
    case MASK_IP:
      if (client->addr.ss.ss_family == AF_INET)
        snprintf(buf, sizeof(buf), "%s[%s@255.255.255.255]",
                 client->name, client->username);
      else
        snprintf(buf, sizeof(buf), "%s[%s@ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]",
                 client->name, client->username);
      break;
    default:  /* HIDE_IP */
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client->name, client->username, client->host);
  }

  return buf;
}

void
free_exited_clients(void)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, dead_list.head)
  {
    client_free(node->data);
    list_remove(node, &dead_list);
    list_free_node(node);
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
    ServerStats.is_cti += io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic;
  }
  else if (IsServer(client))
  {
    ++ServerStats.is_sv;
    ServerStats.is_sbs += client->connection->send.bytes;
    ServerStats.is_sbr += client->connection->recv.bytes;
    ServerStats.is_sti += io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic;

    list_node_t *node;
    LIST_FOREACH(node, connect_items.head)
    {
      struct MaskItem *conf = node->data;

      /*
       * Reset next-connect cycle of all connect{} blocks that match
       * this servername.
       */
      if (irccmp(conf->name, client->name) == 0)
        conf->until = io_time_get(IO_TIME_MONOTONIC_SEC) + conf->class->con_freq;
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

  io_free(client->connection->password);
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
  assert(!IsMe(client));
  assert(client != &me);

  if (IsClient(client))
  {
    if (HasUMode(client, UMODE_OPER))
      --Count.oper;
    if (HasUMode(client, UMODE_INVISIBLE))
      --Count.invisi;

    list_remove(&client->lnode, &client->servptr->serv->client_list);
    list_remove(&client->node, &global_client_list);

    /*
     * If a person is on a channel, send a QUIT notice
     * to every client (person) on the same channel (so
     * that the client can show the "**signoff" message).
     * (Note: The notice is to the local clients *only*)
     */
    sendto_common_channels_local(client, false, 0, 0, ":%s!%s@%s QUIT :%s",
                                 client->name, client->username, client->host, comment);

    list_node_t *node, *node_next;
    LIST_FOREACH_SAFE(node, node_next, client->channel.head)
      channel_remove_user(node->data);

    svstag_clear_list(&client->svstags);

    whowas_add_history(client, false);
    whowas_off_history(client);

    monitor_signoff(client);
  }
  else if (IsServer(client))
  {
    sendto_clients(UMODE_EXTERNAL, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Server %s split from %s",
                         client->name, client->servptr->name);

    list_remove(&client->lnode, &client->servptr->serv->server_list);
    list_remove(&client->node, &global_server_list);
  }

  if (client->id[0])
    hash_del_id(client);

  if (client->name[0])
    hash_del_client(client);

  if (HasFlag(client, FLAGS_IPHASH))
  {
    DelFlag(client, FLAGS_IPHASH);
    ipcache_record_remove(&client->addr, MyConnect(client));
  }

  /* Check to see if the client isn't already on the dead list */
  assert(list_find(&dead_list, client) == NULL);

  /* Add to dead client dlist */
  SetDead(client);
  list_add(client, list_make_node(), &dead_list);
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
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, client->serv->client_list.head)
    exit_one_client(node->data, comment);

  LIST_FOREACH_SAFE(node, node_next, client->serv->server_list.head)
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
client_exit(struct Client *client, const char *comment)
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
        list_node_t *node = list_find_remove(&oper_list, client);
        if (node)
          list_free_node(node);
      }

      assert(list_find(&local_client_list, client));
      list_remove(&client->connection->node, &local_client_list);

      if (client->connection->list_task)
        free_list_task(client);

      invite_clear_list(&client->connection->invited);

      accept_clear_list(&client->connection->acceptlist);

      monitor_clear_list(client);

      sendto_clients(UMODE_CCONN, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "Client exiting: %s (%s@%s) [%s] [%s]",
                           client->name, client->username, client->realhost,
                           client->sockhost, comment);

      log_write(LOG_TYPE_USER, "%s (%ju): %s!%s@%s %s %s %ju/%ju :%s",
                date_ctime(client->connection->created_real),
                io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic,
                client->name, client->username, client->host,
                client->sockhost, client->account,
                client->connection->send.bytes >> 10,
                client->connection->recv.bytes >> 10, client->info);
    }
    else if (IsServer(client))
    {
      assert(list_find(&local_server_list, client));
      list_remove(&client->connection->node, &local_server_list);

      if (!HasFlag(client, FLAGS_SQUIT))
        /* For them, we are exiting the network */
        sendto_one(client, ":%s SQUIT %s :%s", me.id, me.id, comment);
    }
    else
    {
      assert(list_find(&unknown_list, client));
      list_remove(&client->connection->node, &unknown_list);
    }

    sendto_one(client, "ERROR :Closing Link: %s (%s)", client->host, comment);

    client_close_connection(client);
  }
  else if (IsClient(client) && HasFlag(client->servptr, FLAGS_EOB))
    sendto_clients(UMODE_FARCONNECT, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
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
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                           "%s was connected for %s. %ju/%ju sendK/recvK.",
                           client->name, time_format_duration(io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic),
                           client->connection->send.bytes >> 10,
                           client->connection->recv.bytes >> 10);
      log_write(LOG_TYPE_IRCD, "%s was connected for %s. %ju/%ju sendK/recvK.",
                client->name, time_format_duration(io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic),
                client->connection->send.bytes >> 10,
                client->connection->recv.bytes >> 10);
    }
  }
  else if (IsClient(client) && !HasFlag(client, FLAGS_KILLED))
    sendto_server(client->from, 0, 0, ":%s QUIT :%s", client->id, comment);

  /* The client *better* be off all of the lists */
  assert(list_find(&unknown_list, client) == NULL);
  assert(list_find(&local_client_list, client) == NULL);
  assert(list_find(&local_server_list, client) == NULL);
  assert(list_find(&oper_list, client) == NULL);
  assert(list_find(&listing_client_list, client) == NULL);
  assert(list_find(&abort_list, client) == NULL);

  exit_one_client(client, comment);
}

/*
 * dead_link_on_write - report a write error if not already dead,
 *			mark it as dead then exit it
 */
void
dead_link_on_write(struct Client *client, int ierrno)
{
  if (IsDefunct(client))
    return;

  dbuf_clear(&client->connection->buf_recvq);
  dbuf_clear(&client->connection->buf_sendq);

  assert(list_find(&abort_list, client) == NULL);
  list_node_t *node = list_make_node();
  /* don't let exit_aborted_clients() finish yet */
  list_add_tail(client, node, &abort_list);

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
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                           "Server %s closed the connection",
                           client_get_name(client, SHOW_IP));
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                           "Server %s closed the connection",
                           client_get_name(client, MASK_IP));
      log_write(LOG_TYPE_IRCD, "Server %s closed the connection",
                client_get_name(client, SHOW_IP));
    }
    else
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                           "Lost connection to %s: %s",
                           client_get_name(client, SHOW_IP), strerror(current_error));
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE,
                           "Lost connection to %s: %s",
                           client_get_name(client, MASK_IP), strerror(current_error));
      log_write(LOG_TYPE_IRCD, "Lost connection to %s: %s",
                client_get_name(client, SHOW_IP), strerror(current_error));
    }

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s was connected for %s",
                         client->name, time_format_duration(io_time_get(IO_TIME_MONOTONIC_SEC) - client->connection->created_monotonic));
  }

  if (error == 0)
    strlcpy(errmsg, "Remote host closed the connection", sizeof(errmsg));
  else
    snprintf(errmsg, sizeof(errmsg), "Read error: %s", strerror(current_error));

  client_exit(client, errmsg);
}

void
exit_aborted_clients(void)
{
  list_node_t *ptr;
  const char *notice;

  LIST_FOREACH_SAFE(ptr, eac_next, abort_list.head)
  {
    struct Client *client = ptr->data;
    eac_next = ptr->next;

    list_remove(ptr, &abort_list);
    list_free_node(ptr);

    if (client == NULL)
    {
      sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                           "Warning: null client on abort_list!");
      continue;
    }

    if (HasFlag(client, FLAGS_SENDQEX))
      notice = "Max SendQ exceeded";
    else
      notice = "Write error: connection closed";

    client_exit(client, notice);
  }
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
 * @param source Pointer to the source client.
 * @param target Pointer to the target client.
 * @return The calculated (fake) idle time for the target client.
 */
unsigned int
client_get_idle_time(const struct Client *source,
                     const struct Client *target)
{
  unsigned int idle = 0;
  const struct ClassItem *const class = class_get_ptr(&target->connection->confs);

  if (!(class->flags & CLASS_FLAGS_FAKE_IDLE) || target == source)
    return io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_privmsg;

  if (HasUMode(source, UMODE_OPER) &&
      !(class->flags & CLASS_FLAGS_HIDE_IDLE_FROM_OPERS))
    return io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_privmsg;

  const unsigned int min_idle = class->min_idle;
  const unsigned int max_idle = class->max_idle;

  if (min_idle == max_idle)
    return min_idle;

  if (class->flags & CLASS_FLAGS_RANDOM_IDLE)
    idle = genrand_int32();
  else
    idle = io_time_get(IO_TIME_MONOTONIC_SEC) - target->connection->last_privmsg;

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
