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

/*! \file client.c
 * \brief Controls clients.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "event.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "auth.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "misc.h"
#include "server.h"
#include "send.h"
#include "whowas.h"
#include "user.h"
#include "memory.h"
#include "mempool.h"
#include "hostmask.h"
#include "listener.h"
#include "userhost.h"
#include "watch.h"
#include "rng_mt.h"
#include "parse.h"
#include "ipcache.h"


dlink_list listing_client_list;
dlink_list unknown_list;
dlink_list local_client_list;
dlink_list local_server_list;
dlink_list global_client_list;
dlink_list global_server_list;
dlink_list oper_list;

static mp_pool_t *client_pool, *connection_pool;
static dlink_list dead_list, abort_list;
static dlink_node *eac_next;  /* next aborted client to exit */


/*
 * make_client - create a new Client struct and set it to initial state.
 *
 *      from == NULL,   create local client (a client connected
 *                      to a socket).
 *                      WARNING: This leaves the client in a dangerous
 *                      state where fd == -1, dead flag is not set and
 *                      the client is on the unknown_list; therefore,
 *                      the first thing to do after calling make_client(NULL)
 *                      is setting fd to something reasonable. -adx
 *
 *      from,   create remote client (behind a socket
 *                      associated with the client defined by
 *                      'from'). ('from' is a local client!!).
 */
struct Client *
make_client(struct Client *from)
{
  struct Client *const client_p = mp_pool_get(client_pool);

  if (!from)
  {
    client_p->from = client_p;  /* 'from' of local client is self! */
    client_p->connection = mp_pool_get(connection_pool);
    client_p->connection->since = CurrentTime;
    client_p->connection->lasttime = CurrentTime;
    client_p->connection->firsttime = CurrentTime;
    client_p->connection->registration = REG_INIT;

    /* as good a place as any... */
    dlinkAdd(client_p, &client_p->connection->lclient_node, &unknown_list);
  }
  else
    client_p->from = from;

  client_p->idhnext = client_p;
  client_p->hnext = client_p;
  SetUnknown(client_p);
  strcpy(client_p->username, "unknown");
  strcpy(client_p->account, "*");

  return client_p;
}

/*
 * free_client
 *
 * inputs	- pointer to client
 * output	- NONE
 * side effects	- client pointed to has its memory freed
 */
static void
free_client(struct Client *client_p)
{
  assert(client_p != &me);
  assert(client_p->hnext == client_p);
  assert(client_p->idhnext == client_p);
  assert(client_p->channel.head == NULL);
  assert(dlink_list_length(&client_p->channel) == 0);
  assert(dlink_list_length(&client_p->whowas) == 0);
  assert(dlink_list_length(&client_p->svstags) == 0);

  MyFree(client_p->serv);
  MyFree(client_p->certfp);

  if (MyConnect(client_p))
  {
    assert(client_p->connection->invited.head == NULL);
    assert(dlink_list_length(&client_p->connection->invited) == 0);
    assert(dlink_list_length(&client_p->connection->watches) == 0);
    assert(IsClosing(client_p) && IsDead(client_p));

    MyFree(client_p->connection->challenge_response);
    client_p->connection->challenge_response = NULL;
    MyFree(client_p->connection->challenge_operator);
    client_p->connection->challenge_operator = NULL;

    /*
     * Clean up extra sockets from listen {} blocks which have been discarded.
     */
    if (client_p->connection->listener)
    {
      listener_release(client_p->connection->listener);
      client_p->connection->listener = NULL;
    }

    dbuf_clear(&client_p->connection->buf_recvq);
    dbuf_clear(&client_p->connection->buf_sendq);

    mp_pool_release(client_p->connection);
  }

  mp_pool_release(client_p);
}

void
client_attach_svstag(struct Client *client_p, unsigned int numeric,
                     const char *umodes, const char *const tag)
{
  struct ServicesTag *svstag = NULL;
  const struct user_modes *tab = NULL;

  if (numeric >= ERR_LAST_ERR_MSG || *umodes != '+')
    return;

  svstag = MyCalloc(sizeof(*svstag));
  svstag->numeric = numeric;
  svstag->tag = xstrdup(tag);

  for (const char *m = umodes + 1; *m; ++m)
    if ((tab = umode_map[(unsigned char)*m]))
      svstag->umodes |= tab->flag;

  if (numeric != RPL_WHOISOPERATOR)
    dlinkAddTail(svstag, &svstag->node, &client_p->svstags);
  else
    dlinkAdd(svstag, &svstag->node, &client_p->svstags);
}

void
client_clear_svstags(struct Client *client_p)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, client_p->svstags.head)
  {
    struct ServicesTag *svstag = node->data;

    dlinkDelete(&svstag->node, &client_p->svstags);
    MyFree(svstag->tag);
    MyFree(svstag);
  }
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
  char buf[IRCD_BUFSIZE] = "";
  int ping = 0;      /* ping time value from client */
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, list->head)
  {
    struct Client *client_p = node->data;

    if (IsDead(client_p))
      continue;  /* Ignore it, its been exited already */

    if (!IsRegistered(client_p))
      ping = CONNECTTIMEOUT;
    else
      ping = get_client_ping(&client_p->connection->confs);

    if (ping < CurrentTime - client_p->connection->lasttime)
    {
      if (!HasFlag(client_p, FLAGS_PINGSENT))
      {
        /*
         * If we haven't PINGed the connection and we haven't
         * heard from it in a while, PING it to make sure
         * it is still alive.
         */
        AddFlag(client_p, FLAGS_PINGSENT);
        client_p->connection->lasttime = CurrentTime - ping;
        sendto_one(client_p, "PING :%s", ID_or_name(&me, client_p));
      }
      else
      {
        if (CurrentTime - client_p->connection->lasttime >= 2 * ping)
        {
          /*
           * If the client/server hasn't talked to us in 2*ping seconds
           * and it has a ping time, then close its connection.
           */
          if (IsServer(client_p) || IsHandshake(client_p))
          {
            sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                                 "No response from %s, closing link",
                                 get_client_name(client_p, HIDE_IP));
            sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                                 "No response from %s, closing link",
                                 get_client_name(client_p, MASK_IP));
            ilog(LOG_TYPE_IRCD, "No response from %s, closing link",
                 get_client_name(client_p, HIDE_IP));
          }

          snprintf(buf, sizeof(buf), "Ping timeout: %d seconds",
                   (int)(CurrentTime - client_p->connection->lasttime));
          exit_client(client_p, buf);
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
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client_p = node->data;

    /*
     * Check UNKNOWN connections - if they have been in this state
     * for > 30s, close them.
     */
    if (IsAuthFinished(client_p) && (CurrentTime - client_p->connection->firsttime) > 30)
      exit_client(client_p, "Registration timed out");
  }
}

/*
 * check_pings - go through the local client list and check activity
 * kill off stuff that should die
 *
 * inputs       - NOT USED (from event)
 * output       - next time_t when check_pings() should be called again
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
  struct MaskItem *conf = NULL;
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, local_client_list.head)
  {
    struct Client *client_p = node->data;

    /* If a client is already being exited */
    if (IsDead(client_p))
      continue;

    if ((conf = find_conf_by_address(NULL, &client_p->connection->ip, CONF_DLINE,
                                     client_p->connection->aftype, NULL, NULL, 1)))
    {
      conf_try_ban(client_p, conf);
      continue;  /* and go examine next Client */
    }

    if ((conf = find_conf_by_address(client_p->host, &client_p->connection->ip,
                                     CONF_KLINE, client_p->connection->aftype,
                                     client_p->username, NULL, 1)))
    {
      conf_try_ban(client_p, conf);
      continue;  /* and go examine next Client */
    }

    if ((conf = find_matching_name_conf(CONF_XLINE, client_p->info,
                                        NULL, NULL, 0)))
    {
      conf_try_ban(client_p, conf);
      continue;  /* and go examine next Client */
    }
  }

  /* Also check the unknowns list for new dlines */
  DLINK_FOREACH_SAFE(node, node_next, unknown_list.head)
  {
    struct Client *client_p = node->data;

    if ((conf = find_conf_by_address(NULL, &client_p->connection->ip, CONF_DLINE,
                                     client_p->connection->aftype, NULL, NULL, 1)))
    {
      conf_try_ban(client_p, conf);
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
 * side effects	- given client_p is banned
 */
void
conf_try_ban(struct Client *client_p, struct MaskItem *conf)
{
  char ban_type = '\0';

  switch (conf->type)
  {
    case CONF_KLINE:
      if (HasFlag(client_p, FLAGS_EXEMPTKLINE))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "KLINE over-ruled for %s, client is kline_exempt",
                             get_client_name(client_p, HIDE_IP));
        return;
      }

      ban_type = 'K';
      break;
    case CONF_DLINE:
      if (find_conf_by_address(NULL, &client_p->connection->ip, CONF_EXEMPT,
                               client_p->connection->aftype, NULL, NULL, 1))
        return;
      ban_type = 'D';
      break;
    case CONF_XLINE:
      if (HasFlag(client_p, FLAGS_EXEMPTXLINE))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "XLINE over-ruled for %s, client is xline_exempt",
                             get_client_name(client_p, HIDE_IP));
        return;
      }

      ban_type = 'X';
      ++conf->count;
      break;
    default:
      assert(0);
      break;
  }

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "%c-line active for %s",
                       ban_type, get_client_name(client_p, HIDE_IP));

  if (IsClient(client_p))
    sendto_one_numeric(client_p, &me, ERR_YOUREBANNEDCREEP, conf->reason);

  exit_client(client_p, conf->reason);
}

/* update_client_exit_stats()
 *
 * input	- pointer to client
 * output	- NONE
 * side effects	-
 */
static void
update_client_exit_stats(struct Client *client_p)
{
  if (IsClient(client_p))
  {
    assert(Count.total > 0);

    --Count.total;
    if (HasUMode(client_p, UMODE_OPER))
      --Count.oper;
    if (HasUMode(client_p, UMODE_INVISIBLE))
      --Count.invisi;
  }
  else if (IsServer(client_p))
    sendto_realops_flags(UMODE_EXTERNAL, L_ALL, SEND_NOTICE,
                         "Server %s split from %s",
                         client_p->name, client_p->servptr->name);

  if (splitchecking && !splitmode)
    check_splitmode(NULL);
}

/* find_person()
 *
 * inputs	- pointer to name
 * output	- return client pointer
 * side effects - find person by (nick)name
 */
struct Client *
find_person(const struct Client *const source_p, const char *name)
{
  struct Client *target_p = NULL;

  if (IsDigit(*name))
  {
    if (IsServer(source_p->from))
      target_p = hash_find_id(name);
  }
  else
    target_p = hash_find_client(name);

  return (target_p && IsClient(target_p)) ? target_p : NULL;
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

  target_p = whowas_get_history(name, (time_t)ConfigGeneral.kill_chase_time_limit);

  if (!target_p)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, name);
    return NULL;
  }

  return target_p;
}

/*
 * get_client_name -  Return the name of the client
 *    for various tracking and
 *      admin purposes. The main purpose of this function is to
 *      return the "socket host" name of the client, if that
 *        differs from the advertised name (other than case).
 *        But, this can be used to any client structure.
 *
 * NOTE 1:
 *        Watch out the allocation of "buf", if either source_p->name
 *        or source_p->sockhost gets changed into pointers instead of
 *        directly allocated within the structure...
 *
 * NOTE 2:
 *        Function return either a pointer to the structure (source_p) or
 *        to internal buffer (buf). *NEVER* use the returned pointer
 *        to modify what it points!!!
 */
const char *
get_client_name(const struct Client *client_p, enum addr_mask_type type)
{
  static char buf[HOSTLEN * 2 + USERLEN + 5];

  if (!MyConnect(client_p))
    return client_p->name;

  if (IsServer(client_p) || IsConnecting(client_p) || IsHandshake(client_p))
  {
    if (!irccmp(client_p->name, client_p->host))
      return client_p->name;
    else if (ConfigServerHide.hide_server_ips)
      type = MASK_IP;
  }

  /* And finally, let's get the host information, ip or name */
  switch (type)
  {
    case SHOW_IP:
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client_p->name,
               client_p->username, client_p->sockhost);
      break;
    case MASK_IP:
      if (client_p->connection->aftype == AF_INET)
        snprintf(buf, sizeof(buf), "%s[%s@255.255.255.255]",
                 client_p->name, client_p->username);
      else
        snprintf(buf, sizeof(buf), "%s[%s@ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]",
                 client_p->name, client_p->username);
      break;
    default:  /* HIDE_IP */
      snprintf(buf, sizeof(buf), "%s[%s@%s]",
               client_p->name,
               client_p->username, client_p->host);
  }

  return buf;
}

void
free_exited_clients(void)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, dead_list.head)
  {
    free_client(node->data);
    dlinkDelete(node, &dead_list);
    free_dlink_node(node);
  }
}

/*
 * Exit one client, local or remote. Assuming all dependents have
 * been already removed, and socket closed for local client.
 *
 * The only messages generated are QUITs on channels.
 */
static void
exit_one_client(struct Client *source_p, const char *comment)
{
  dlink_node *node = NULL, *node_next = NULL;

  assert(!IsMe(source_p));
  assert(source_p != &me);

  if (IsClient(source_p))
  {
    dlinkDelete(&source_p->lnode, &source_p->servptr->serv->client_list);
    dlinkDelete(&source_p->node, &global_client_list);

    /*
     * If a person is on a channel, send a QUIT notice
     * to every client (person) on the same channel (so
     * that the client can show the "**signoff" message).
     * (Note: The notice is to the local clients *only*)
     */
    sendto_common_channels_local(source_p, 0, 0, ":%s!%s@%s QUIT :%s",
                                 source_p->name, source_p->username,
                                 source_p->host, comment);

    DLINK_FOREACH_SAFE(node, node_next, source_p->channel.head)
      remove_user_from_channel(node->data);

    whowas_add_history(source_p, 0);
    whowas_off_history(source_p);

    watch_check_hash(source_p, RPL_LOGOFF);

    if (MyConnect(source_p))
    {
      clear_invites_client(source_p);
      del_all_accepts(source_p);
    }
  }
  else if (IsServer(source_p))
  {
    dlinkDelete(&source_p->lnode, &source_p->servptr->serv->server_list);
    dlinkDelete(&source_p->node, &global_client_list);

    if ((node = dlinkFindDelete(&global_server_list, source_p)))
      free_dlink_node(node);
  }

  /* Remove source_p from the client lists */
  if (source_p->id[0])
    hash_del_id(source_p);

  if (source_p->name[0])
    hash_del_client(source_p);

  if (HasFlag(source_p, FLAGS_USERHOST))
    delete_user_host(source_p->username, source_p->host, !MyConnect(source_p));

  update_client_exit_stats(source_p);

  /* Check to see if the client isn't already on the dead list */
  assert(dlinkFind(&dead_list, source_p) == NULL);

  /* add to dead client dlist */
  SetDead(source_p);
  dlinkAdd(source_p, make_dlink_node(), &dead_list);
}

/*
 * Remove all clients that depend on source_p; assumes all (S)QUITs have
 * already been sent.  we make sure to exit a server's dependent clients
 * and servers before the server itself; exit_one_client takes care of
 * actually removing things off llists.   tweaked from +CSr31  -orabidoo
 */
static void
recurse_remove_clients(struct Client *source_p, const char *comment)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, source_p->serv->client_list.head)
    exit_one_client(node->data, comment);

  DLINK_FOREACH_SAFE(node, node_next, source_p->serv->server_list.head)
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
exit_client(struct Client *source_p, const char *comment)
{
  dlink_node *node = NULL;

  assert(!IsMe(source_p));
  assert(source_p != &me);

  if (MyConnect(source_p))
  {
    /* DO NOT REMOVE. exit_client can be called twice after a failed
     * read/write.
     */
    if (IsClosing(source_p))
      return;

    SetClosing(source_p);

    if (HasFlag(source_p, FLAGS_IPHASH))
    {
      DelFlag(source_p, FLAGS_IPHASH);
      ipcache_remove_address(&source_p->connection->ip);
    }

    delete_auth(&source_p->connection->auth);

    /*
     * This source_p could have status of one of STAT_UNKNOWN, STAT_CONNECTING
     * STAT_HANDSHAKE or STAT_UNKNOWN
     * all of which are lumped together into unknown_list
     *
     * In all above cases IsRegistered() will not be true.
     */
    if (!IsRegistered(source_p))
    {
      assert(dlinkFind(&unknown_list, source_p));

      dlinkDelete(&source_p->connection->lclient_node, &unknown_list);
    }
    else if (IsClient(source_p))
    {
      time_t on_for = CurrentTime - source_p->connection->firsttime;

      assert(Count.local > 0);

      --Count.local;

      if (HasUMode(source_p, UMODE_OPER))
        if ((node = dlinkFindDelete(&oper_list, source_p)))
          free_dlink_node(node);

      assert(dlinkFind(&local_client_list, source_p));
      dlinkDelete(&source_p->connection->lclient_node, &local_client_list);

      if (source_p->connection->list_task)
        free_list_task(source_p);

      watch_del_watch_list(source_p);
      client_clear_svstags(source_p);

      sendto_realops_flags(UMODE_CCONN, L_ALL, SEND_NOTICE,
                           "Client exiting: %s (%s@%s) [%s] [%s]",
                           source_p->name, source_p->username, source_p->host, comment,
                           source_p->sockhost);

      ilog(LOG_TYPE_USER, "%s (%3u:%02u:%02u): %s!%s@%s %llu/%llu",
           myctime(source_p->connection->firsttime), (unsigned int)(on_for / 3600),
           (unsigned int)((on_for % 3600)/60), (unsigned int)(on_for % 60),
           source_p->name, source_p->username, source_p->host,
           source_p->connection->send.bytes>>10,
           source_p->connection->recv.bytes>>10);
    }
    else if (IsServer(source_p))
    {
      assert(Count.myserver > 0);

      --Count.myserver;

      assert(dlinkFind(&local_server_list, source_p));
      dlinkDelete(&source_p->connection->lclient_node, &local_server_list);
    }

    if (!IsDead(source_p))
    {
      if (IsServer(source_p))
      {
        if (!HasFlag(source_p, FLAGS_SQUIT))
        {
          /* for them, we are exiting the network */
          sendto_one(source_p, ":%s SQUIT %s :%s",
                     me.id, me.id, comment);
        }
      }

      sendto_one(source_p, "ERROR :Closing Link: %s (%s)",
                 source_p->host, comment);
    }

    close_connection(source_p);
  }
  else if (IsClient(source_p) && HasFlag(source_p->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client exiting at %s: %s (%s@%s) [%s]",
                         source_p->servptr->name, source_p->name,
                         source_p->username, source_p->host, comment);

  if (IsServer(source_p))
  {
    char splitstr[HOSTLEN + HOSTLEN + 2] = "";

    assert(source_p->serv);
    assert(source_p->servptr);

    if (ConfigServerHide.hide_servers)
      /*
       * Set netsplit message to "*.net *.split" to still show
       * that its a split, but hide the servers splitting
       */
      strlcpy(splitstr, "*.net *.split", sizeof(splitstr));
    else
      snprintf(splitstr, sizeof(splitstr), "%s %s",
               source_p->servptr->name, source_p->name);

    /* Send SQUIT for source_p in every direction. source_p is already off of local_server_list here */
    if (!HasFlag(source_p, FLAGS_SQUIT))
      sendto_server(NULL, 0, 0, "SQUIT %s :%s", source_p->id, comment);

    /* Now exit the clients internally */
    recurse_remove_clients(source_p, splitstr);

    if (MyConnect(source_p))
    {
      int connected = CurrentTime - source_p->connection->firsttime;
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s was connected for %d day%s, %2d:%02d:%02d. %llu/%llu sendK/recvK.",
                           source_p->name, connected/86400, (connected/86400 == 1) ? "" : "s",
                           (connected % 86400) / 3600, (connected % 3600) / 60, connected % 60,
                           source_p->connection->send.bytes >> 10,
                           source_p->connection->recv.bytes >> 10);
      ilog(LOG_TYPE_IRCD, "%s was connected for %d day%s, %2d:%02d:%02d. %llu/%llu sendK/recvK.",
           source_p->name, connected/86400, (connected/86400 == 1) ? "" : "s",
           (connected % 86400) / 3600, (connected % 3600) / 60, connected % 60,
           source_p->connection->send.bytes >> 10,
           source_p->connection->recv.bytes >> 10);
    }
  }
  else if (IsClient(source_p) && !HasFlag(source_p, FLAGS_KILLED))
    sendto_server(source_p->from, 0, 0, ":%s QUIT :%s",
                  source_p->id, comment);

  /* The client *better* be off all of the lists */
  assert(dlinkFind(&unknown_list, source_p) == NULL);
  assert(dlinkFind(&local_client_list, source_p) == NULL);
  assert(dlinkFind(&local_server_list, source_p) == NULL);
  assert(dlinkFind(&oper_list, source_p) == NULL);

  exit_one_client(source_p, comment);
}

/*
 * dead_link_on_write - report a write error if not already dead,
 *			mark it as dead then exit it
 */
void
dead_link_on_write(struct Client *client_p, int ierrno)
{
  dlink_node *node;

  if (IsDefunct(client_p))
    return;

  dbuf_clear(&client_p->connection->buf_recvq);
  dbuf_clear(&client_p->connection->buf_sendq);

  assert(dlinkFind(&abort_list, client_p) == NULL);
  node = make_dlink_node();
  /* don't let exit_aborted_clients() finish yet */
  dlinkAddTail(client_p, node, &abort_list);

  if (eac_next == NULL)
    eac_next = node;

  SetDead(client_p); /* You are dead my friend */
}

/*
 * dead_link_on_read -  report a read error if not already dead,
 *			mark it as dead then exit it
 */
void
dead_link_on_read(struct Client *client_p, int error)
{
  char errmsg[IRCD_BUFSIZE];
  int current_error;

  if (IsDefunct(client_p))
    return;

  dbuf_clear(&client_p->connection->buf_recvq);
  dbuf_clear(&client_p->connection->buf_sendq);

  current_error = get_sockerr(client_p->connection->fd.fd);

  if (IsServer(client_p) || IsHandshake(client_p))
  {
    int connected = CurrentTime - client_p->connection->firsttime;

    if (error == 0)
    {
      /* Admins get the real IP */
      sendto_realops_flags(UMODE_ALL, L_ADMIN, SEND_NOTICE,
                           "Server %s closed the connection",
                           get_client_name(client_p, SHOW_IP));

      /* Opers get a masked IP */
      sendto_realops_flags(UMODE_ALL, L_OPER, SEND_NOTICE,
                           "Server %s closed the connection",
                           get_client_name(client_p, MASK_IP));

      ilog(LOG_TYPE_IRCD, "Server %s closed the connection",
           get_client_name(client_p, SHOW_IP));
    }
    else
    {
      report_error(L_ADMIN, "Lost connection to %s: %s",
                   get_client_name(client_p, SHOW_IP), current_error);
      report_error(L_OPER, "Lost connection to %s: %s",
                   get_client_name(client_p, MASK_IP), current_error);
    }

    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "%s was connected for %d day%s, %2d:%02d:%02d",
                         client_p->name, connected/86400,
                         (connected/86400 == 1) ? "" : "s",
                         (connected % 86400) / 3600, (connected % 3600) / 60,
                         connected % 60);
  }

  if (error == 0)
    strlcpy(errmsg, "Remote host closed the connection",
            sizeof(errmsg));
  else
    snprintf(errmsg, sizeof(errmsg), "Read error: %s",
             strerror(current_error));

  exit_client(client_p, errmsg);
}

void
exit_aborted_clients(void)
{
  dlink_node *ptr;
  struct Client *target_p;
  const char *notice;

  DLINK_FOREACH_SAFE(ptr, eac_next, abort_list.head)
  {
    target_p = ptr->data;
    eac_next = ptr->next;

    if (target_p == NULL)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "Warning: null client on abort_list!");
      dlinkDelete(ptr, &abort_list);
      free_dlink_node(ptr);
      continue;
    }

    dlinkDelete(ptr, &abort_list);

    if (HasFlag(target_p, FLAGS_SENDQEX))
      notice = "Max SendQ exceeded";
    else
      notice = "Write error: connection closed";

    exit_client(target_p, notice);
    free_dlink_node(ptr);
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
del_accept(struct split_nuh_item *accept_p, struct Client *client_p)
{
  dlinkDelete(&accept_p->node, &client_p->connection->acceptlist);

  MyFree(accept_p->nickptr);
  MyFree(accept_p->userptr);
  MyFree(accept_p->hostptr);
  MyFree(accept_p);
}

struct split_nuh_item *
find_accept(const char *nick, const char *user,
            const char *host, struct Client *client_p,
            int (*cmpfunc)(const char *, const char *))
{
  dlink_node *node = NULL;

  DLINK_FOREACH(node, client_p->connection->acceptlist.head)
  {
    struct split_nuh_item *accept_p = node->data;

    if (!cmpfunc(accept_p->nickptr, nick) &&
        !cmpfunc(accept_p->userptr, user) &&
        !cmpfunc(accept_p->hostptr, host))
      return accept_p;
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
int
accept_message(struct Client *source,
               struct Client *target)
{
  dlink_node *node = NULL;

  if (HasFlag(source, FLAGS_SERVICE) ||
      (HasUMode(source, UMODE_OPER) && ConfigGeneral.opers_bypass_callerid))
    return 1;

  if (source == target || find_accept(source->name, source->username,
                                      source->host, target, match))
    return 1;

  if (!HasUMode(target, UMODE_CALLERID) && HasUMode(target, UMODE_SOFTCALLERID))
    DLINK_FOREACH(node, target->channel.head)
      if (IsMember(source, ((struct Membership *)node->data)->chptr))
        return 1;

  return 0;
}

/* del_all_accepts()
 *
 * inputs       - pointer to exiting client
 * output       - NONE
 * side effects - Walk through given clients acceptlist and remove all entries
 */
void
del_all_accepts(struct Client *client_p)
{
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, client_p->connection->acceptlist.head)
    del_accept(node->data, client_p);
}

unsigned int
client_get_idle_time(const struct Client *source_p,
                     const struct Client *target_p)
{
  unsigned int idle = 0;
  unsigned int min_idle = 0;
  unsigned int max_idle = 0;
  const struct ClassItem *const class = get_class_ptr(&target_p->connection->confs);

  if (!(class->flags & CLASS_FLAGS_FAKE_IDLE) || target_p == source_p)
    return CurrentTime - target_p->connection->last_privmsg;

  if (HasUMode(source_p, UMODE_OPER) &&
      !(class->flags & CLASS_FLAGS_HIDE_IDLE_FROM_OPERS))
    return CurrentTime - target_p->connection->last_privmsg;

  min_idle = class->min_idle;
  max_idle = class->max_idle;

  if (min_idle == max_idle)
    return min_idle;

  if (class->flags & CLASS_FLAGS_RANDOM_IDLE)
    idle = genrand_int32();
  else
    idle = CurrentTime - target_p->connection->last_privmsg;

  if (!max_idle)
    idle = 0;
  else
    idle %= max_idle;

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

  client_pool = mp_pool_new(sizeof(struct Client), MP_CHUNK_SIZE_CLIENT);
  connection_pool = mp_pool_new(sizeof(struct Connection), MP_CHUNK_SIZE_CONNECTION);
  event_add(&event_ping, NULL);
}
