/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  client.c: Controls clients.
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
#include "client.h"
#include "channel_mode.h"
#include "event.h"
#include "fdlist.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "s_gline.h"
#include "numeric.h"
#include "packet.h"
#include "s_auth.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "s_misc.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "s_user.h"
#include "dbuf.h"
#include "memory.h"
#include "mempool.h"
#include "hostmask.h"
#include "listener.h"
#include "irc_res.h"
#include "userhost.h"
#include "watch.h"
#include "rng_mt.h"

dlink_list listing_client_list = { NULL, NULL, 0 };
/* Pointer to beginning of Client list */
dlink_list global_client_list = {NULL, NULL, 0};
/* unknown/client pointer lists */
dlink_list unknown_list = {NULL, NULL, 0};
dlink_list local_client_list = {NULL, NULL, 0};
dlink_list serv_list = {NULL, NULL, 0};
dlink_list global_serv_list = {NULL, NULL, 0};
dlink_list oper_list = {NULL, NULL, 0};

static EVH check_pings;

static mp_pool_t *client_pool  = NULL;
static mp_pool_t *lclient_pool = NULL;

static dlink_list dead_list  = { NULL, NULL, 0};
static dlink_list abort_list = { NULL, NULL, 0};

static dlink_node *eac_next;  /* next aborted client to exit */

static void check_pings_list(dlink_list *);
static void check_unknowns_list(void);
static void ban_them(struct Client *, struct MaskItem *);


/* client_init()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	- initialize client free memory
 */
void
client_init(void)
{
  /* start off the check ping event ..  -- adrian
   * Every 30 seconds is plenty -- db
   */
  client_pool = mp_pool_new(sizeof(struct Client), MP_CHUNK_SIZE_CLIENT);
  lclient_pool = mp_pool_new(sizeof(struct LocalUser), MP_CHUNK_SIZE_LCLIENT);
  eventAdd("check_pings", check_pings, NULL, 5);
}

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
  struct Client *client_p = mp_pool_get(client_pool);

  memset(client_p, 0, sizeof(*client_p));

  if (from == NULL)
  {
    client_p->from                      = client_p; /* 'from' of local client is self! */
    client_p->localClient               = mp_pool_get(lclient_pool);

    memset(client_p->localClient, 0, sizeof(*client_p->localClient));

    client_p->localClient->since        = CurrentTime;
    client_p->localClient->lasttime     = CurrentTime;
    client_p->localClient->firsttime    = CurrentTime;
    client_p->localClient->registration = REG_INIT;

    /* as good a place as any... */
    dlinkAdd(client_p, &client_p->localClient->lclient_node, &unknown_list);
  }
  else
    client_p->from = from; /* 'from' of local client is self! */

  client_p->idhnext = client_p;
  client_p->hnext  = client_p;
  client_p->status = STAT_UNKNOWN;
  strcpy(client_p->username, "unknown");
  strcpy(client_p->svid, "0");

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
  assert(client_p != NULL);
  assert(client_p != &me);
  assert(client_p->hnext == client_p);
  assert(client_p->idhnext == client_p);
  assert(client_p->channel.head == NULL);
  assert(dlink_list_length(&client_p->channel) == 0);
  assert(dlink_list_length(&client_p->whowas) == 0);
  assert(!IsServer(client_p) || (IsServer(client_p) && client_p->serv));

  MyFree(client_p->serv);
  MyFree(client_p->certfp);

  if (MyConnect(client_p))
  {
    assert(client_p->localClient->invited.head == NULL);
    assert(dlink_list_length(&client_p->localClient->invited) == 0);
    assert(dlink_list_length(&client_p->localClient->watches) == 0);
    assert(IsClosing(client_p) && IsDead(client_p));

    MyFree(client_p->localClient->response);
    MyFree(client_p->localClient->auth_oper);

    /*
     * clean up extra sockets from P-lines which have been discarded.
     */
    if (client_p->localClient->listener)
    {
      assert(0 < client_p->localClient->listener->ref_count);
      if (0 == --client_p->localClient->listener->ref_count &&
          !client_p->localClient->listener->active)
        free_listener(client_p->localClient->listener);
    }

    dbuf_clear(&client_p->localClient->buf_recvq);
    dbuf_clear(&client_p->localClient->buf_sendq);

    mp_pool_release(client_p->localClient);
  }

  mp_pool_release(client_p);
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
check_pings(void *notused)
{
  check_pings_list(&local_client_list);
  check_pings_list(&serv_list);
  check_unknowns_list();
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
  char scratch[32];        /* way too generous but... */
  int ping = 0;      /* ping time value from client */
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, list->head)
  {
    struct Client *client_p = ptr->data;

    /*
    ** Note: No need to notify opers here. It's
    ** already done when "FLAGS_DEADSOCKET" is set.
    */
    if (IsDead(client_p))
    {
      /* Ignore it, its been exited already */
      continue;
    }

    if (!IsRegistered(client_p))
      ping = CONNECTTIMEOUT;
    else
      ping = get_client_ping(&client_p->localClient->confs);

    if (ping < CurrentTime - client_p->localClient->lasttime)
    {
      if (!IsPingSent(client_p))
      {
        /*
         * if we havent PINGed the connection and we havent
         * heard from it in a while, PING it to make sure
         * it is still alive.
         */
        SetPingSent(client_p);
        client_p->localClient->lasttime = CurrentTime - ping;
        sendto_one(client_p, "PING :%s", ID_or_name(&me, client_p));
      }
      else
      {
        if (CurrentTime - client_p->localClient->lasttime >= 2 * ping)
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

          snprintf(scratch, sizeof(scratch), "Ping timeout: %d seconds",
                   (int)(CurrentTime - client_p->localClient->lasttime));
          exit_client(client_p, &me, scratch);
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
  dlink_node *ptr, *next_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, unknown_list.head)
  {
    struct Client *client_p = ptr->data;

    /*
     * Check UNKNOWN connections - if they have been in this state
     * for > 30s, close them.
     */
    if (IsAuthFinished(client_p) && (CurrentTime - client_p->localClient->firsttime) > 30)
      exit_client(client_p, &me, "Registration timed out");
  }
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
  struct Client *client_p = NULL;       /* current local client_p being examined */
  struct MaskItem *conf = NULL;
  dlink_node *ptr, *next_ptr;

  DLINK_FOREACH_SAFE(ptr, next_ptr, local_client_list.head)
  {
    client_p = ptr->data;

    /* If a client is already being exited
     */
    if (IsDead(client_p) || !IsClient(client_p))
      continue;

    if ((conf = find_dline_conf(&client_p->localClient->ip,
                                  client_p->localClient->aftype)) != NULL)
    {
      if (conf->type == CONF_EXEMPT)
        continue;

      ban_them(client_p, conf);
      continue; /* and go examine next fd/client_p */
    }

    if (ConfigFileEntry.glines && (conf = find_gline(client_p)))
    {
      if (IsExemptKline(client_p) ||
          IsExemptGline(client_p))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "GLINE over-ruled for %s, client is %sline_exempt",
                             get_client_name(client_p, HIDE_IP), IsExemptKline(client_p) ? "k" : "g");
        continue;
      }

      ban_them(client_p, conf);
      /* and go examine next fd/client_p */
      continue;
    }

    if ((conf = find_kill(client_p)) != NULL)
    {
      if (IsExemptKline(client_p))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                             "KLINE over-ruled for %s, client is kline_exempt",
                             get_client_name(client_p, HIDE_IP));
        continue;
      }

      ban_them(client_p, conf);
      continue;
    }

    if ((conf = find_matching_name_conf(CONF_XLINE,  client_p->info,
                                        NULL, NULL, 0)))
    {
      ban_them(client_p, conf);
      continue;
    }
  }

  /* also check the unknowns list for new dlines */
  DLINK_FOREACH_SAFE(ptr, next_ptr, unknown_list.head)
  {
    client_p = ptr->data;

    if ((conf = find_dline_conf(&client_p->localClient->ip,
                                 client_p->localClient->aftype)))
    {
      if (conf->type == CONF_EXEMPT)
        continue;

      exit_client(client_p, &me, "D-lined");
    }
  }
}

/*
 * ban_them
 *
 * inputs	- pointer to client to ban
 * 		- pointer to MaskItem
 * output	- NONE
 * side effects	- given client_p is banned
 */
static void
ban_them(struct Client *client_p, struct MaskItem *conf)
{
  const char *user_reason = NULL;  /* What is sent to user */
  const char *type_string = NULL;
  const char dline_string[] = "D-line";
  const char kline_string[] = "K-line";
  const char gline_string[] = "G-line";
  const char xline_string[] = "X-line";

  switch (conf->type)
  {
    case CONF_KLINE:
      type_string = kline_string;
      break;
    case CONF_DLINE:
      type_string = dline_string;
      break;
    case CONF_GLINE:
      type_string = gline_string;
      break;
    case CONF_XLINE:
      type_string = xline_string;
      ++conf->count;
      break;
    default:
      assert(0);
      break;
  }

  user_reason = conf->reason ? conf->reason : type_string;

  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE, "%s active for %s",
                       type_string, get_client_name(client_p, HIDE_IP));

  if (IsClient(client_p))
    sendto_one(client_p, form_str(ERR_YOUREBANNEDCREEP),
               me.name, client_p->name, user_reason);

  exit_client(client_p, &me, user_reason);
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
find_person(const struct Client *client_p, const char *name)
{
  struct Client *target_p = NULL;

  if (IsDigit(*name))
  {
    if ((target_p = hash_find_id(name)) != NULL)
    {
      /* invisible users shall not be found by UID guessing */
      if (HasUMode(target_p, UMODE_INVISIBLE))
        if (!IsServer(client_p) && !HasFlag(client_p, FLAGS_SERVICE))
          target_p = NULL;
    }
  }
  else
    target_p = hash_find_client(name);

  return (target_p && IsClient(target_p)) ? target_p : NULL;
}

/*
 * find_chasing - find the client structure for a nick name (name)
 *      using history mechanism if necessary. If the client is not found,
 *      an error message (NO SUCH NICK) is generated. If the client was found
 *      through the history, chasing will be 1 and otherwise 0.
 */
struct Client *
find_chasing(struct Client *source_p, const char *name, int *const chasing)
{
  struct Client *who = find_person(source_p->from, name);

  if (chasing)
    *chasing = 0;

  if (who)
    return who;

  if (IsDigit(*name))
    return NULL;

  if ((who = whowas_get_history(name,
                         (time_t)ConfigFileEntry.kill_chase_time_limit))
                         == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, name);
    return NULL;
  }

  if (chasing)
    *chasing = 1;

  return who;
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
 *        Watch out the allocation of "nbuf", if either source_p->name
 *        or source_p->sockhost gets changed into pointers instead of
 *        directly allocated within the structure...
 *
 * NOTE 2:
 *        Function return either a pointer to the structure (source_p) or
 *        to internal buffer (nbuf). *NEVER* use the returned pointer
 *        to modify what it points!!!
 */
const char *
get_client_name(const struct Client *client, enum addr_mask_type type)
{
  static char nbuf[HOSTLEN * 2 + USERLEN + 5];

  assert(client != NULL);

  if (!MyConnect(client))
    return client->name;

  if (IsServer(client) || IsConnecting(client) || IsHandshake(client))
  {
    if (!irccmp(client->name, client->host))
      return client->name;
    else if (ConfigServerHide.hide_server_ips)
      type = MASK_IP;
  }

  if (ConfigFileEntry.hide_spoof_ips)
    if (type == SHOW_IP && IsIPSpoof(client))
      type = MASK_IP;

  /* And finally, let's get the host information, ip or name */
  switch (type)
  {
    case SHOW_IP:
      snprintf(nbuf, sizeof(nbuf), "%s[%s@%s]",
               client->name,
               client->username, client->sockhost);
      break;
    case MASK_IP:
      if (client->localClient->aftype == AF_INET)
        snprintf(nbuf, sizeof(nbuf), "%s[%s@255.255.255.255]",
                 client->name, client->username);
      else
        snprintf(nbuf, sizeof(nbuf), "%s[%s@ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff]",
                 client->name, client->username);
      break;
    default:
      snprintf(nbuf, sizeof(nbuf), "%s[%s@%s]",
               client->name,
               client->username, client->host);
  }

  return nbuf;
}

void
free_exited_clients(void)
{
  dlink_node *ptr = NULL, *next = NULL;

  DLINK_FOREACH_SAFE(ptr, next, dead_list.head)
  {
    free_client(ptr->data);
    dlinkDelete(ptr, &dead_list);
    free_dlink_node(ptr);
  }
}

/*
 * Exit one client, local or remote. Assuming all dependents have
 * been already removed, and socket closed for local client.
 *
 * The only messages generated are QUITs on channels.
 */
static void
exit_one_client(struct Client *source_p, const char *quitmsg)
{
  dlink_node *lp = NULL, *next_lp = NULL;

  assert(!IsMe(source_p));

  if (IsClient(source_p))
  {
    if (source_p->servptr->serv != NULL)
      dlinkDelete(&source_p->lnode, &source_p->servptr->serv->client_list);

    /*
     * If a person is on a channel, send a QUIT notice
     * to every client (person) on the same channel (so
     * that the client can show the "**signoff" message).
     * (Note: The notice is to the local clients *only*)
     */
    sendto_common_channels_local(source_p, 0, 0, ":%s!%s@%s QUIT :%s",
                                 source_p->name, source_p->username,
                                 source_p->host, quitmsg);
    DLINK_FOREACH_SAFE(lp, next_lp, source_p->channel.head)
      remove_user_from_channel(lp->data);

    whowas_add_history(source_p, 0);
    whowas_off_history(source_p);

    watch_check_hash(source_p, RPL_LOGOFF);

    if (MyConnect(source_p))
    {
      /* Clean up invitefield */
      DLINK_FOREACH_SAFE(lp, next_lp, source_p->localClient->invited.head)
        del_invite(lp->data, source_p);

      del_all_accepts(source_p);
    }
  }
  else if (IsServer(source_p))
  {
    dlinkDelete(&source_p->lnode, &source_p->servptr->serv->server_list);

    if ((lp = dlinkFindDelete(&global_serv_list, source_p)) != NULL)
      free_dlink_node(lp);
  }

  /* Remove source_p from the client lists */
  if (HasID(source_p))
    hash_del_id(source_p);
  if (source_p->name[0])
    hash_del_client(source_p);

  if (IsUserHostIp(source_p))
    delete_user_host(source_p->username, source_p->host, !MyConnect(source_p));

  /* remove from global client list
   * NOTE: source_p->node.next cannot be NULL if the client is added
   *       to global_client_list (there is always &me at its end)
   */
  if (source_p != NULL && source_p->node.next != NULL)
    dlinkDelete(&source_p->node, &global_client_list);

  update_client_exit_stats(source_p);

  /* Check to see if the client isn't already on the dead list */
  assert(dlinkFind(&dead_list, source_p) == NULL);

  /* add to dead client dlist */
  SetDead(source_p);
  dlinkAdd(source_p, make_dlink_node(), &dead_list);
}

/* Recursively send QUITs and SQUITs for source_p and all its dependent clients
 * and servers to those servers that need them.  A server needs the client
 * QUITs if it can't figure them out from the SQUIT (ie pre-TS4) or if it
 * isn't getting the SQUIT because of @#(*&@)# hostmasking.  With TS4, once
 * a link gets a SQUIT, it doesn't need any QUIT/SQUITs for clients depending
 * on that one -orabidoo
 *
 * This is now called on each local server -adx
 */
static void
recurse_send_quits(struct Client *original_source_p, struct Client *source_p,
                   struct Client *from, struct Client *to, const char *comment,
                   const char *splitstr)
{
  dlink_node *ptr, *next;
  struct Client *target_p;

  assert(to != source_p);  /* should be already removed from serv_list */

  /* If this server can handle quit storm (QS) removal
   * of dependents, just send the SQUIT
   */
  if (!IsCapable(to, CAP_QS))
    DLINK_FOREACH_SAFE(ptr, next, source_p->serv->client_list.head)
    {
      target_p = ptr->data;
      sendto_one(to, ":%s QUIT :%s", target_p->name, splitstr);
    }

  DLINK_FOREACH_SAFE(ptr, next, source_p->serv->server_list.head)
    recurse_send_quits(original_source_p, ptr->data, from, to,
                       comment, splitstr);

  if ((source_p == original_source_p && to != from) ||
                  !IsCapable(to, CAP_QS))
  {
    /* don't use a prefix here - we have to be 100% sure the message
     * will be accepted without Unknown prefix etc.. */
    sendto_one(to, "SQUIT %s :%s", ID_or_name(source_p, to), comment);
  }
}

/*
 * Remove all clients that depend on source_p; assumes all (S)QUITs have
 * already been sent.  we make sure to exit a server's dependent clients
 * and servers before the server itself; exit_one_client takes care of
 * actually removing things off llists.   tweaked from +CSr31  -orabidoo
 */
static void
recurse_remove_clients(struct Client *source_p, const char *quitmsg)
{
  dlink_node *ptr, *next;

  DLINK_FOREACH_SAFE(ptr, next, source_p->serv->client_list.head)
    exit_one_client(ptr->data, quitmsg);

  DLINK_FOREACH_SAFE(ptr, next, source_p->serv->server_list.head)
  {
    recurse_remove_clients(ptr->data, quitmsg);
    exit_one_client(ptr->data, quitmsg);
  }
}

/*
** Remove *everything* that depends on source_p, from all lists, and sending
** all necessary QUITs and SQUITs.  source_p itself is still on the lists,
** and its SQUITs have been sent except for the upstream one  -orabidoo
*/
static void
remove_dependents(struct Client *source_p, struct Client *from,
                  const char *comment, const char *splitstr)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, serv_list.head)
    recurse_send_quits(source_p, source_p, from, ptr->data,
                       comment, splitstr);

  recurse_remove_clients(source_p, splitstr);
}

/*
 * exit_client - exit a client of any type. Generally, you can use
 * this on any struct Client, regardless of its state.
 *
 * Note, you shouldn't exit remote _users_ without first doing
 * AddFlag(x, FLAGS_KILLED) and propagating a kill or similar message.
 * However, it is perfectly correct to call exit_client to force a _server_
 * quit (either local or remote one).
 *
 * inputs:       - a client pointer that is going to be exited
 *               - for servers, the second argument is a pointer to who
 *                 is firing the server. This side won't get any generated
 *                 messages. NEVER NULL!
 * output:       none
 * side effects: the client is delinked from all lists, disconnected,
 *               and the rest of IRC network is notified of the exit.
 *               Client memory is scheduled to be freed
 */
void
exit_client(struct Client *source_p, struct Client *from, const char *comment)
{
  dlink_node *m = NULL;

  if (MyConnect(source_p))
  {
    /* DO NOT REMOVE. exit_client can be called twice after a failed
     * read/write.
     */
    if (IsClosing(source_p))
      return;

    SetClosing(source_p);

    if (IsIpHash(source_p))
      remove_one_ip(&source_p->localClient->ip);

    delete_auth(&source_p->localClient->auth);

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

      dlinkDelete(&source_p->localClient->lclient_node, &unknown_list);
    }
    else if (IsClient(source_p))
    {
      time_t on_for = CurrentTime - source_p->localClient->firsttime;
      assert(Count.local > 0);
      Count.local--;

      if (HasUMode(source_p, UMODE_OPER))
        if ((m = dlinkFindDelete(&oper_list, source_p)) != NULL)
          free_dlink_node(m);

      assert(dlinkFind(&local_client_list, source_p));
      dlinkDelete(&source_p->localClient->lclient_node, &local_client_list);

      if (source_p->localClient->list_task != NULL)
        free_list_task(source_p->localClient->list_task, source_p);

      watch_del_watch_list(source_p);
      sendto_realops_flags(UMODE_CCONN, L_ALL, SEND_NOTICE,
                           "Client exiting: %s (%s@%s) [%s] [%s]",
                           source_p->name, source_p->username, source_p->host, comment,
                           ConfigFileEntry.hide_spoof_ips && IsIPSpoof(source_p) ?
                           "255.255.255.255" : source_p->sockhost);
      ilog(LOG_TYPE_USER, "%s (%3u:%02u:%02u): %s!%s@%s %llu/%llu",
           myctime(source_p->localClient->firsttime), (unsigned int)(on_for / 3600),
           (unsigned int)((on_for % 3600)/60), (unsigned int)(on_for % 60),
           source_p->name, source_p->username, source_p->host,
           source_p->localClient->send.bytes>>10,
           source_p->localClient->recv.bytes>>10);
    }
    else if (IsServer(source_p))
    {
      assert(Count.myserver > 0);
      --Count.myserver;

      assert(dlinkFind(&serv_list, source_p));
      dlinkDelete(&source_p->localClient->lclient_node, &serv_list);
      unset_chcap_usage_counts(source_p);
    }

    if (!IsDead(source_p))
    {
      if (IsServer(source_p))
      {
        /* for them, we are exiting the network */
        sendto_one(source_p, ":%s SQUIT %s :%s",
                   ID_or_name(from, source_p), me.name, comment);
      }

      sendto_one(source_p, "ERROR :Closing Link: %s (%s)",
                 source_p->host, comment);
    }

    /*
    ** Currently only server connections can have
    ** depending remote clients here, but it does no
    ** harm to check for all local clients. In
    ** future some other clients than servers might
    ** have remotes too...
    **
    ** Close the Client connection first and mark it
    ** so that no messages are attempted to send to it.
    ** Remember it makes source_p->from == NULL.
    */
    close_connection(source_p);
  }
  else if (IsClient(source_p) && HasFlag(source_p->servptr, FLAGS_EOB))
    sendto_realops_flags(UMODE_FARCONNECT, L_ALL, SEND_NOTICE,
                         "Client exiting at %s: %s (%s@%s) [%s]",
                         source_p->servptr->name, source_p->name,
                         source_p->username, source_p->host, comment);

  if (IsServer(source_p))
  {
    char splitstr[HOSTLEN + HOSTLEN + 2];

    /* This shouldn't ever happen */
    assert(source_p->serv != NULL && source_p->servptr != NULL);

    if (ConfigServerHide.hide_servers)
      /*
       * Set netsplit message to "*.net *.split" to still show
       * that its a split, but hide the servers splitting
       */
      strcpy(splitstr, "*.net *.split");
    else
      snprintf(splitstr, sizeof(splitstr), "%s %s",
               source_p->servptr->name, source_p->name);

    remove_dependents(source_p, from->from, comment, splitstr);

    if (source_p->servptr == &me)
    {
      sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                           "%s was connected for %d seconds.  %llu/%llu sendK/recvK.",
                           source_p->name, (int)(CurrentTime - source_p->localClient->firsttime),
                           source_p->localClient->send.bytes >> 10,
                           source_p->localClient->recv.bytes >> 10);
      ilog(LOG_TYPE_IRCD, "%s was connected for %d seconds.  %llu/%llu sendK/recvK.",
           source_p->name, (int)(CurrentTime - source_p->localClient->firsttime),
           source_p->localClient->send.bytes >> 10,
           source_p->localClient->recv.bytes >> 10);
    }
  }
  else if (IsClient(source_p) && !HasFlag(source_p, FLAGS_KILLED))
  {
    sendto_server(from->from, CAP_TS6, NOCAPS,
                  ":%s QUIT :%s", ID(source_p), comment);
    sendto_server(from->from, NOCAPS, CAP_TS6,
                  ":%s QUIT :%s", source_p->name, comment);
  }

  /* The client *better* be off all of the lists */
  assert(dlinkFind(&unknown_list, source_p) == NULL);
  assert(dlinkFind(&local_client_list, source_p) == NULL);
  assert(dlinkFind(&serv_list, source_p) == NULL);
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
  dlink_node *ptr;

  if (IsDefunct(client_p))
    return;

  dbuf_clear(&client_p->localClient->buf_recvq);
  dbuf_clear(&client_p->localClient->buf_sendq);

  assert(dlinkFind(&abort_list, client_p) == NULL);
  ptr = make_dlink_node();
  /* don't let exit_aborted_clients() finish yet */
  dlinkAddTail(client_p, ptr, &abort_list);

  if (eac_next == NULL)
    eac_next = ptr;

  SetDead(client_p); /* You are dead my friend */
}

/*
 * dead_link_on_read -  report a read error if not already dead,
 *			mark it as dead then exit it
 */
void
dead_link_on_read(struct Client *client_p, int error)
{
  char errmsg[255];
  int current_error;

  if (IsDefunct(client_p))
    return;

  dbuf_clear(&client_p->localClient->buf_recvq);
  dbuf_clear(&client_p->localClient->buf_sendq);

  current_error = get_sockerr(client_p->localClient->fd.fd);

  if (IsServer(client_p) || IsHandshake(client_p))
  {
    int connected = CurrentTime - client_p->localClient->firsttime;

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
                         "%s had been connected for %d day%s, %2d:%02d:%02d",
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

  exit_client(client_p, &me, errmsg);
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

    if (IsSendQExceeded(target_p))
      notice = "Max SendQ exceeded";
    else
      notice = "Write error: connection closed";

    exit_client(target_p, &me, notice);
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
  dlinkDelete(&accept_p->node, &client_p->localClient->acceptlist);

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
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, client_p->localClient->acceptlist.head)
  {
    struct split_nuh_item *accept_p = ptr->data;

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
  dlink_node *ptr = NULL;

  if (source == target || find_accept(source->name, source->username,
                                      source->host, target, match))
    return 1;

  if (HasUMode(target, UMODE_SOFTCALLERID))
    DLINK_FOREACH(ptr, target->channel.head)
      if (IsMember(source, ((struct Membership *)ptr->data)->chptr))
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
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, client_p->localClient->acceptlist.head)
    del_accept(ptr->data, client_p);
}

unsigned int
idle_time_get(const struct Client *source_p, const struct Client *target_p)
{
  unsigned int idle = 0;
  unsigned int min_idle = 0;
  unsigned int max_idle = 0;
  const struct ClassItem *class = get_class_ptr(&target_p->localClient->confs);

  if (!(class->flags & CLASS_FLAGS_FAKE_IDLE) || target_p == source_p)
    return CurrentTime - target_p->localClient->last_privmsg;
  if (HasUMode(source_p, UMODE_OPER) &&
      !(class->flags & CLASS_FLAGS_HIDE_IDLE_FROM_OPERS))
    return CurrentTime - target_p->localClient->last_privmsg;

  min_idle = class->min_idle;
  max_idle = class->max_idle;

  if (min_idle == max_idle)
    return min_idle;

  if (class->flags & CLASS_FLAGS_RANDOM_IDLE)
    idle = genrand_int32();
  else
    idle = CurrentTime - target_p->localClient->last_privmsg;

  if (max_idle == 0)
    idle = 0;
  else
    idle %= max_idle;

  if (idle < min_idle)
    idle = min_idle + (idle % (max_idle - min_idle));

  return idle;
}
