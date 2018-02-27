/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2018 ircd-hybrid development team
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

/*! \file auth.c
 * \brief Implementation of DNS and ident lookups.
 * \version $Id$
 */

/*
 * Changes:
 *   July 6, 1999 - Rewrote most of the code here. When a client connects
 *     to the server and passes initial socket validation checks, it
 *     is owned by this module (auth) which returns it to the rest of the
 *     server when dns and auth queries are finished. Until the client is
 *     released, the server does not know it exists and does not process
 *     any messages from it.
 *     --Bleep  Thomas Helvey <tomh@inxpress.net>
 */

#include "stdinc.h"
#include "list.h"
#include "ircd_defs.h"
#include "fdlist.h"
#include "auth.h"
#include "conf.h"
#include "client.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "packet.h"
#include "res.h"
#include "s_bsd.h"
#include "log.h"
#include "send.h"
#include "mempool.h"


enum
{
  REPORT_DO_DNS,
  REPORT_FIN_DNS,
  REPORT_FAIL_DNS,
  REPORT_DO_ID,
  REPORT_FIN_ID,
  REPORT_FAIL_ID,
  REPORT_IP_MISMATCH,
  REPORT_HOST_TOOLONG,
  REPORT_HOST_INVALID
};

static const char *const HeaderMessages[] =
{
  [REPORT_DO_DNS] = ":*** Looking up your hostname",
  [REPORT_FIN_DNS] = ":*** Found your hostname",
  [REPORT_FAIL_DNS] = ":*** Couldn't look up your hostname",
  [REPORT_DO_ID] = ":*** Checking Ident",
  [REPORT_FIN_ID] = ":*** Got Ident response",
  [REPORT_FAIL_ID] = ":*** No Ident response",
  [REPORT_IP_MISMATCH] = ":*** Your forward and reverse DNS do not match, ignoring hostname",
  [REPORT_HOST_TOOLONG] = ":*** Your hostname is too long, ignoring hostname",
  [REPORT_HOST_INVALID] = ":*** Your hostname contains illegal characters, ignoring hostname"
};

#define auth_sendheader(c, i) sendto_one_notice((c), &me, "%s", HeaderMessages[(i)])

static dlink_list auth_list;


/*
 * auth_make_request - allocate a new auth request
 */
static struct AuthRequest *
auth_make_request(struct Client *client)
{
  struct AuthRequest *const auth = &client->connection->auth;

  memset(auth, 0, sizeof(*auth));

  auth->client = client;
  auth->timeout = CurrentTime + CONNECTTIMEOUT;

  return auth;
}

/*! \brief Release auth client from auth system. This adds the client into the
 *         local client lists so it can be read by the main io processing loop.
 * \param auth Pointer to AuthRequest struct to release
 */
static void
auth_release_client(struct AuthRequest *auth)
{
  struct Client *const client = auth->client;

  if (IsDoingAuth(auth) || IsDNSPending(auth))
    return;

  if (IsInAuth(auth))
  {
    dlinkDelete(&auth->node, &auth_list);
    ClearInAuth(auth);
  }

  /*
   * When a client has auth'ed, we want to start reading what it sends
   * us. This is what read_packet() does.
   *     -- adrian
   */
  client->connection->allow_read = MAX_FLOOD;
  comm_setflush(&client->connection->fd, 1000, flood_recalc, client);

  client->connection->since     = CurrentTime;
  client->connection->lasttime  = CurrentTime;
  client->connection->firsttime = CurrentTime;
  AddFlag(client, FLAGS_FINISHED_AUTH);

  strlcpy(client->realhost, client->host, sizeof(client->realhost));

  read_packet(&client->connection->fd, client);
}

/*! Checks if a hostname is valid and doesn't contain illegal characters
 * \param hostname The string to verify
 * \return 1 if it is valid, 0 if it isn't
 */
static int
auth_verify_hostname(const char *hostname)
{
  const char *p = hostname;

  assert(p);

  if (EmptyString(p) || *p == '.' || *p == ':')
    return 0;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return 0;

  return 1;
}

/*! \brief Handle a complete DNS lookup. Send the client on its way to a connection
 *         completion, regardless of success or failure.
 * \param vptr The pending struct AuthRequest.
 * \param addr IP address being resolved.
 * \param name Resolved name, or NULL if lookup failed.
 * \param namelength String length of the resolved hostname pointed by 'name'
 */
static void
auth_dns_callback(void *vptr, const struct irc_ssaddr *addr, const char *name, size_t namelength)
{
  struct AuthRequest *const auth = vptr;

  ClearDNSPending(auth);

  if (!EmptyString(name))
  {
    if (auth->client->connection->ip.ss.ss_family == AF_INET6)
    {
      const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)&auth->client->connection->ip;
      const struct sockaddr_in6 *const v6dns = (const struct sockaddr_in6 *)addr;

      if (memcmp(&v6->sin6_addr, &v6dns->sin6_addr, sizeof(struct in6_addr)))
      {
        auth_sendheader(auth->client, REPORT_IP_MISMATCH);
        auth_release_client(auth);
        return;
      }
    }
    else
    {
      const struct sockaddr_in *const v4 = (const struct sockaddr_in *)&auth->client->connection->ip;
      const struct sockaddr_in *const v4dns = (const struct sockaddr_in *)addr;

      if (v4->sin_addr.s_addr != v4dns->sin_addr.s_addr)
      {
        auth_sendheader(auth->client, REPORT_IP_MISMATCH);
        auth_release_client(auth);
        return;
      }
    }

    if (namelength > HOSTLEN)
      auth_sendheader(auth->client, REPORT_HOST_TOOLONG);
    else if (!auth_verify_hostname(name))
      auth_sendheader(auth->client, REPORT_HOST_INVALID);
    else
    {
      strlcpy(auth->client->host, name, sizeof(auth->client->host));
      auth_sendheader(auth->client, REPORT_FIN_DNS);
    }
  }
  else
    auth_sendheader(auth->client, REPORT_FAIL_DNS);

  auth_release_client(auth);
}

/*
 * auth_error - handle auth send errors
 */
static void
auth_error(struct AuthRequest *auth)
{
  ++ServerStats.is_abad;

  fd_close(&auth->fd);
  ClearAuth(auth);

  auth_sendheader(auth->client, REPORT_FAIL_ID);

  auth_release_client(auth);
}

/** Enum used to index ident reply fields in a human-readable way. */
enum IdentReplyFields
{
  IDENT_PORT_NUMBERS,
  IDENT_REPLY_TYPE,
  IDENT_OS_TYPE,
  IDENT_INFO,
  USERID_TOKEN_COUNT
};

/** Parse an ident reply line and extract the userid from it.
 * \param reply The ident reply line.
 * \return The userid, or NULL on parse failure.
 */
static const char *
auth_check_ident_reply(char *const reply)
{
  char *token = NULL, *end = NULL;
  char *vector[USERID_TOKEN_COUNT];
  const unsigned int count = token_vector(reply, ':', vector, USERID_TOKEN_COUNT);

  if (USERID_TOKEN_COUNT != count)
    return NULL;

  /*
   * Second token is the reply type
   */
  token = vector[IDENT_REPLY_TYPE];

  if (EmptyString(token))
    return NULL;

  while (IsSpace(*token))
    ++token;

  if (strncmp(token, "USERID", 6))
    return NULL;

  /*
   * Third token is the os type
   */
  token = vector[IDENT_OS_TYPE];

  if (EmptyString(token))
    return NULL;

  while (IsSpace(*token))
   ++token;

  /*
   * Unless "OTHER" is specified as the operating system type, the server
   * is expected to return the "normal" user identification of the owner
   * of this connection. "Normal" in this context may be taken to mean a
   * string of characters which uniquely identifies the connection owner
   * such as a user identifier assigned by the system administrator and
   * used by such user as a mail identifier, or as the "user" part of a
   * user/password pair used to gain access to system resources. When an
   * operating system is specified (e.g., anything but "OTHER"), the user
   * identifier is expected to be in a more or less immediately useful
   * form - e.g., something that could be used as an argument to "finger"
   * or as a mail address.
   */
  if (!strncmp(token, "OTHER", 5))
    return NULL;

  /*
   * Fourth token is the username
   */
  token = vector[IDENT_INFO];

  if (EmptyString(token))
    return NULL;

  while (IsSpace(*token))
    ++token;

  while (*token == '~' || *token == '^')
    ++token;

  /*
   * Look for the end of the username, terminators are '\0, @, <SPACE>, :'
   */
  for (end = token; *end; ++end)
    if (IsSpace(*end) || '@' == *end || ':' == *end)
      break;
  *end = '\0';

  return token;
}

/*! \brief Read the reply (if any) from the ident server we connected to. We
 *         only give it one shot, if the reply isn't good the first time fail
 *         the authentication entirely. --Bleep
 * \param fd The socket/fd to read from.
 * \param data The request to read.
 */
static void
auth_read_reply(fde_t *fd, void *data)
{
  struct AuthRequest *const auth = data;
  const char *username = NULL;
  ssize_t len = 0;
  char buf[RFC1413_BUFSIZ + 1];

  if ((len = recv(fd->fd, buf, RFC1413_BUFSIZ, 0)) > 0)
  {
    buf[len] = '\0';
    username = auth_check_ident_reply(buf);
  }

  fd_close(fd);
  ClearAuth(auth);

  if (EmptyString(username))
  {
    auth_sendheader(auth->client, REPORT_FAIL_ID);
    ++ServerStats.is_abad;
  }
  else
  {
    strlcpy(auth->client->username, username, sizeof(auth->client->username));
    auth_sendheader(auth->client, REPORT_FIN_ID);
    ++ServerStats.is_asuc;
    AddFlag(auth->client, FLAGS_GOTID);
  }

  auth_release_client(auth);
}

/*
 * auth_connect_callback() - deal with the result of comm_connect_tcp()
 *
 * If the connection failed, we simply close the auth fd and report
 * a failure. If the connection suceeded send the ident server a query
 * giving "theirport , ourport". The write is only attempted *once* so
 * it is deemed to be a fail if the entire write doesn't write all the
 * data given.  This shouldnt be a problem since the socket should have
 * a write buffer far greater than this message to store it in should
 * problems arise. -avalon
 */
static void
auth_connect_callback(fde_t *fd, int error, void *data)
{
  struct AuthRequest *const auth = data;
  struct irc_ssaddr us;
  struct irc_ssaddr them;
  char authbuf[16];
  ssize_t len = 0;
  socklen_t ulen = sizeof(struct irc_ssaddr);
  socklen_t tlen = sizeof(struct irc_ssaddr);
  uint16_t uport, tport;
  struct sockaddr_in6 *v6;

  if (error != COMM_OK)
  {
    auth_error(auth);
    return;
  }

  if (getsockname(auth->client->connection->fd.fd, (struct sockaddr *)&us, &ulen) ||
      getpeername(auth->client->connection->fd.fd, (struct sockaddr *)&them, &tlen))
  {
    report_error(L_ALL, "auth get{sock,peer}name error %s:%s",
                 client_get_name(auth->client, SHOW_IP), errno);
    auth_error(auth);
    return;
  }

  v6 = (struct sockaddr_in6 *)&us;
  uport = ntohs(v6->sin6_port);
  v6 = (struct sockaddr_in6 *)&them;
  tport = ntohs(v6->sin6_port);

  len = snprintf(authbuf, sizeof(authbuf), "%u, %u\r\n", tport, uport);

  if (send(fd->fd, authbuf, len, 0) != len)
  {
    auth_error(auth);
    return;
  }

  comm_setselect(fd, COMM_SELECT_READ, auth_read_reply, auth, 0);
}

/*! \brief Flag the client to show an attempt to contact the ident server on
 *         the client's host. Should the connect or any later phase of the
 *         identifying process fail, it is aborted and the user is given a
 *         username of "unknown".
 * \param auth The request for which to start the ident lookup.
 */
static void
auth_start_query(struct AuthRequest *auth)
{
  struct irc_ssaddr localaddr;
  socklen_t locallen = sizeof(struct irc_ssaddr);
  struct sockaddr_in6 *v6;

  /* Open a socket of the same type as the client socket */
  if (comm_open(&auth->fd, auth->client->connection->ip.ss.ss_family, SOCK_STREAM, 0, "ident") == -1)
  {
    report_error(L_ALL, "creating auth stream socket %s:%s",
                 client_get_name(auth->client, SHOW_IP), errno);
    ++ServerStats.is_abad;
    return;
  }

  SetDoingAuth(auth);
  auth_sendheader(auth->client, REPORT_DO_ID);

  /*
   * Get the local address of the client and bind to that to
   * make the auth request.
   */
  memset(&localaddr, 0, locallen);
  getsockname(auth->client->connection->fd.fd, (struct sockaddr *)&localaddr, &locallen);

  remove_ipv6_mapping(&localaddr);
  v6 = (struct sockaddr_in6 *)&localaddr;
  v6->sin6_port = htons(0);
  localaddr.ss_port = htons(0);

  comm_connect_tcp(&auth->fd, auth->client->sockhost, RFC1413_PORT,
      (struct sockaddr *)&localaddr, localaddr.ss_len, auth_connect_callback,
      auth, auth->client->connection->ip.ss.ss_family,
      GlobalSetOptions.ident_timeout);
}

/*
 * auth_start
 *
 * inputs       - pointer to client to auth
 * output       - NONE
 * side effects - starts auth (identd) and dns queries for a client
 */
void
auth_start(struct Client *client_p)
{
  struct AuthRequest *const auth = auth_make_request(client_p);

  SetInAuth(auth);
  dlinkAddTail(auth, &auth->node, &auth_list);

  auth_sendheader(client_p, REPORT_DO_DNS);

  SetDNSPending(auth);

  if (ConfigGeneral.disable_auth == 0)
    auth_start_query(auth);

  gethost_byaddr(auth_dns_callback, auth, &client_p->connection->ip);
}

/*
 * auth_delete()
 */
void
auth_delete(struct AuthRequest *auth)
{
  if (IsDoingAuth(auth))
  {
    fd_close(&auth->fd);
    ClearAuth(auth);
  }

  if (IsDNSPending(auth))
  {
    delete_resolver_queries(auth);
    ClearDNSPending(auth);
  }

  if (IsInAuth(auth))
  {
    dlinkDelete(&auth->node, &auth_list);
    ClearInAuth(auth);
  }
}

/*
 * auth_timeout_queries - timeout resolver and identd requests
 * allow clients through if requests failed
 */
static void
auth_timeout_queries(void *notused)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, auth_list.head)
  {
    struct AuthRequest *auth = node->data;

    if (auth->timeout > CurrentTime)
      break;

    if (IsDoingAuth(auth))
    {
      ++ServerStats.is_abad;
      fd_close(&auth->fd);
      ClearAuth(auth);

      auth_sendheader(auth->client, REPORT_FAIL_ID);
    }

    if (IsDNSPending(auth))
    {
      delete_resolver_queries(auth);
      ClearDNSPending(auth);

      auth_sendheader(auth->client, REPORT_FAIL_DNS);
    }

    auth_release_client(auth);
  }
}

/* auth_init
 *
 * Initialise the auth code
 */
void
auth_init(void)
{
  static struct event timeout_auth_queries =
  {
    .name = "auth_timeout_queries",
    .handler = auth_timeout_queries,
    .when = 1
  };

  event_add(&timeout_auth_queries, NULL);
}
