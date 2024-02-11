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

/**
 * @file auth.c
 * @brief Implementation of DNS and ident lookups for client authentication.
 *
 * This file contains the implementation of DNS and ident lookups used in
 * the process of authenticating clients connecting to the server.
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
#include "memory.h"
#include "misc.h"
#include "hostmask.h"

/**
 * @brief Enumerates the different types of reports generated during the authentication process.
 *
 * This enumeration defines constants representing various reports that may occur during
 * the authentication process. Each constant is associated with a specific informational
 * message to be conveyed to the user or server, indicating the progress or outcome of
 * DNS and ident lookups.
 */
enum
{
  REPORT_DO_DNS,  /**< Indicates the initiation of hostname lookup. */
  REPORT_FIN_DNS,  /**< Indicates the successful completion of hostname lookup. */
  REPORT_FAIL_DNS,  /**< Indicates the failure of hostname lookup. */
  REPORT_DO_ID,  /**< Indicates the initiation of Ident check. */
  REPORT_FIN_ID,  /**< Indicates a successful Ident response. */
  REPORT_FAIL_ID,  /**< Indicates the absence of Ident response. */
  REPORT_IP_MISMATCH,  /**< Indicates a mismatch between forward and reverse DNS. */
  REPORT_HOST_TOOLONG,  /**< Indicates that the hostname is too long. */
  REPORT_HOST_INVALID,  /**< Indicates that the hostname contains illegal characters. */
};

/**
 * @brief Array of header messages for different authentication reports.
 *
 * This array contains header messages corresponding to different authentication report types.
 */
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

/**
 * @def auth_sendheader(c, i)
 * @brief Send authentication header message to the client.
 *
 * This macro sends an authentication header message to the specified client based on the given report type.
 *
 * @param c Pointer to the client.
 * @param i Report type index.
 */
#define auth_sendheader(c, i) sendto_one_notice((c), &me, "%s", HeaderMessages[(i)])

/**
 * @brief Allocate a new authentication request.
 *
 * This function allocates memory for a new authentication request, associating it with the given client.
 *
 * @param client The client being looked up.
 * @return Pointer to the newly allocated authentication request.
 */
static struct AuthRequest *
auth_make(struct Client *client)
{
  struct AuthRequest *auth = xcalloc(sizeof(*auth));

  auth->client = client;
  auth->client->connection->auth = auth;

  return auth;
}

/**
 * @brief Free memory associated with an authentication request.
 *
 * This function frees the memory associated with an authentication request.
 *
 * @param auth The authentication request to cleanup.
 */
static void
auth_free(struct AuthRequest *auth)
{
  auth->client = NULL;
  xfree(auth);
}

/**
 * @brief Release client from authentication system.
 *
 * This function releases a client from the authentication system, allowing it
 * to be processed by the main IO loop.
 *
 * @param auth Pointer to the authentication request.
 */
static void
auth_release_client(struct AuthRequest *auth)
{
  struct Client *client = auth->client;

  assert(client);
  assert(client->connection);

  /* Check if DNS or ident queries are still pending; if yes, do not release the client yet. */
  if (auth->ident_pending == true || auth->dns_pending == true)
    return;

  auth_free(auth);
  client->connection->auth = NULL;

  /*
   * When a client has auth'ed, we want to start reading what it sends
   * us. This is what read_packet() does.
   *     -- adrian
   */
  comm_setflush(client->connection->fd, 1, flood_recalc, client);

  client->connection->last_ping = event_base->time.sec_monotonic;
  client->connection->last_data = event_base->time.sec_monotonic;
  client->connection->created_real = event_base->time.sec_real;
  client->connection->created_monotonic = event_base->time.sec_monotonic;

  AddFlag(client, FLAGS_FINISHED_AUTH);

  read_packet(client->connection->fd, client);
}

/**
 * @brief Verify if a hostname is valid and does not contain illegal characters.
 *
 * This function checks if the given hostname is valid and does not contain illegal characters.
 *
 * @param hostname The string to verify.
 * @return True if the hostname is valid, false otherwise.
 */
static bool
auth_verify_hostname(const char *hostname)
{
  const char *p = hostname;

  assert(p);

  if (EmptyString(p) || *p == '.' || *p == ':')
    return false;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return false;

  return true;
}

/**
 * @brief Handles the completion of a DNS lookup for authentication.
 *
 * This function is called when a DNS lookup for authentication is completed.
 * It processes the result of the DNS lookup and sends the client on its way
 * to complete the connection, regardless of whether the lookup was successful
 * or not. If the lookup fails or if the resolved hostname is invalid, it sends
 * an appropriate failure notice to the client. If the hostname matches the
 * client's IP address and passes validation checks, it updates the client's
 * hostname and sends a success notice to the client.
 *
 * @param vptr A pointer to the pending AuthRequest struct.
 * @param addr The IP address being resolved.
 * @param name The resolved hostname, or NULL if the lookup failed.
 * @param namelength The length of the resolved hostname string.
 */
static void
auth_dns_callback(void *vptr, const struct irc_ssaddr *addr, const char *name, size_t namelength)
{
  struct AuthRequest *const auth = vptr;

  assert(auth->client);
  assert(auth->client->connection);

  auth->dns_pending = false;

  if (namelength == 0)
    auth_sendheader(auth->client, REPORT_FAIL_DNS);
  else if (address_compare(addr, &auth->client->ip, true, false, 0) == false)
    auth_sendheader(auth->client, REPORT_IP_MISMATCH);
  else if (namelength > HOSTLEN)
    auth_sendheader(auth->client, REPORT_HOST_TOOLONG);
  else if (auth_verify_hostname(name) == false)
    auth_sendheader(auth->client, REPORT_HOST_INVALID);
  else
  {
    strlcpy(auth->client->host, name, sizeof(auth->client->host));
    auth_sendheader(auth->client, REPORT_FIN_DNS);
  }

  auth_release_client(auth);
}

/**
 * @brief Handles errors that occur during the authentication process.
 *
 * This function is responsible for managing errors that may occur during
 * the authentication process. It is called when there is an issue with the
 * authentication flow, such as a failed connection or an incomplete write.
 * In case of an error, it increments the server statistics for failed
 * authentication attempts and releases the resources associated with the
 * authentication request, sending an appropriate failure notice to the client.
 *
 * @param auth A pointer to the AuthRequest struct representing the authentication request.
 */
static void
auth_error(struct AuthRequest *auth)
{
  assert(auth);
  assert(auth->fd);
  assert(auth->client);
  assert(auth->client->connection);

  ++ServerStats.is_abad;

  fd_close(auth->fd);
  auth->fd = NULL;
  auth->ident_pending = false;

  auth_sendheader(auth->client, REPORT_FAIL_ID);

  auth_release_client(auth);
}

/**
 * @brief Enumerates the fields in an Ident reply line.
 *
 * This enumeration provides human-readable names for the fields in an Ident
 * reply line. The fields represent different pieces of information extracted
 * during the parsing of an Ident reply.
 */
enum IdentReplyFields
{
  IDENT_PORT_NUMBERS,  /**< Port numbers associated with the connection. */
  IDENT_REPLY_TYPE,  /**< Type of the reply, where "USERID" is expected. */
  IDENT_OS_TYPE,  /**< Type of the operating system. */
  IDENT_INFO,  /**< User information, including the user identifier. */
  USERID_TOKEN_COUNT,  /**< Count of tokens expected in an Ident reply line. */
};

/**
 * @brief Parse an ident reply line and extract the user identifier.
 *
 * This function parses an ident reply line obtained from the ident server and
 * extracts the user identifier.
 *
 * @param reply The ident reply line received from the ident server.
 * @return The user identifier extracted from the reply, or NULL on parsing failure.
 *
 * @details The ident reply line is expected to have the following format:
 * - PortNumbers:ReplyType:OSType:UserInfo
 *   - PortNumbers: The port numbers associated with the connection.
 *   - ReplyType: The type of reply, where "USERID" is expected.
 *   - OSType: The type of the operating system.
 *   - UserInfo: The user information, including the user identifier.
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
  if (strncmp(token, "OTHER", 5) == 0)
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

/**
 * @brief Reads the reply from the ident server and processes it.
 *
 * This callback function is called by the I/O multiplexer when there is data
 * to be read from the socket connected to the ident server. It reads the
 * reply from the server and attempts to parse the userid from it. This
 * function is a one-shot operation, meaning it only attempts to read the
 * reply once. If the parsing is successful, it updates the client's username
 * and sends a success notice to the client. If the parsing fails or there is
 * an error in reading the reply, it sends a failure notice to the client and
 * marks the authentication attempt as unsuccessful.
 *
 * @param F The socket/fd to read from.
 * @param data The AuthRequest struct representing the authentication request.
 */
static void
auth_read_reply(fde_t *F, void *data)
{
  struct AuthRequest *const auth = data;
  const char *username = NULL;
  ssize_t len = 0;
  char buf[RFC1413_BUFSIZE + 1];

  assert(auth->fd == F);
  assert(auth->client);
  assert(auth->client->connection);

  if (F->read_handler == NULL && (len = recv(auth->fd->fd, buf, sizeof(buf) - 1, 0)) > 0)
  {
    buf[len] = '\0';
    username = auth_check_ident_reply(buf);
  }

  fd_close(auth->fd);
  auth->fd = NULL;
  auth->ident_pending = false;

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

/**
 * @brief Handles the result of comm_connect_tcp() for ident server connection.
 *
 * This callback function is invoked by the I/O multiplexer when the attempt
 * to connect to the ident server is complete. If the connection fails, it
 * closes the authentication socket, reports the failure, and marks the
 * authentication attempt as unsuccessful. If the connection succeeds, it
 * sends an ident query to the server with the port numbers and sets up the
 * read callback to handle the server's response. This function is a
 * one-shot operation, meaning it is designed to be executed only once per
 * authentication attempt. Any error during the process is considered a
 * failure in the authentication attempt. The one-shot nature of this
 * operation is not an issue here because the socket has a write buffer
 * large enough to store the entire ident query message, ensuring that the
 * message is sent in its entirety in a single attempt.
 *
 * @param F The socket/fd representing the authentication connection.
 * @param error The result of the connection attempt.
 * @param data The AuthRequest struct representing the authentication request.
 */
static void
auth_connect_callback(fde_t *F, int error, void *data)
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

  assert(auth->fd == F);
  assert(auth->client);
  assert(auth->client->connection);

  if (error != COMM_OK)
  {
    auth_error(auth);
    return;
  }

  if (getsockname(auth->client->connection->fd->fd, (struct sockaddr *)&us, &ulen) ||
      getpeername(auth->client->connection->fd->fd, (struct sockaddr *)&them, &tlen))
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

  if (send(F->fd, authbuf, len, 0) != len)
  {
    auth_error(auth);
    return;
  }

  comm_setselect(F, COMM_SELECT_READ, auth_read_reply, auth, 4);
}

/**
 * @brief Initiates the authentication process for a client by querying the Ident server.
 *
 * This function is responsible for starting the authentication process for a client
 * by initiating a query to the Ident server. It opens a socket of the same type as
 * the client socket, binds it to the local address of the client, and establishes a
 * connection to the Ident server. Once the connection is established, it sends a query
 * to the server containing port information, and sets up a callback function to handle
 * the server's response. If the connection or any subsequent phase of the identification
 * process fails, the authentication process is aborted, and the client is assigned an
 * "unknown" username.
 *
 * @param auth The AuthRequest structure containing information about the client
 *             and the authentication process.
 */
static void
auth_start_query(struct AuthRequest *auth)
{
  struct irc_ssaddr localaddr;
  socklen_t locallen = sizeof(struct irc_ssaddr);
  struct sockaddr_in6 *v6;

  assert(auth->client);
  assert(auth->client->connection);

  /* Open a socket of the same type as the client socket */
  int fd = comm_socket(auth->client->ip.ss.ss_family, SOCK_STREAM, 0);
  if (fd == -1)
  {
    report_error(L_ALL, "creating auth stream socket %s:%s",
                 client_get_name(auth->client, SHOW_IP), errno);
    ++ServerStats.is_abad;
    return;
  }

  auth->fd = fd_open(fd, true, "ident");
  auth->ident_pending = true;

  auth_sendheader(auth->client, REPORT_DO_ID);

  /*
   * Get the local address of the client and bind to that to
   * make the auth request.
   */
  memset(&localaddr, 0, locallen);
  getsockname(auth->client->connection->fd->fd, (struct sockaddr *)&localaddr, &locallen);

  remove_ipv6_mapping(&localaddr);
  v6 = (struct sockaddr_in6 *)&localaddr;
  v6->sin6_port = htons(0);

  comm_connect_tcp(auth->fd, &auth->client->ip, RFC1413_PORTNUM, &localaddr,
                   auth_connect_callback, auth, 4);
}

/**
 * @brief Initiates the authentication process for a client.
 *
 * This function starts the authentication process for a client. It involves
 * DNS lookup and ident server query to determine the client's hostname and
 * identity. The client is notified about the ongoing DNS lookup and ident
 * checking through notice messages. If authentication is not disabled, the
 * function initiates the ident server query. Flags and timestamps are set,
 * and packet reading from the client is started once authenticated. If
 * successful, the FINISHED_AUTH flag is added to the client. In case of
 * failure, error notices are sent, and appropriate flags are marked on the
 * client.
 *
 * @param client The client to authenticate.
 */
void
auth_start(struct Client *client)
{
  struct AuthRequest *auth = auth_make(client);

  assert(client);
  assert(client->connection);

  auth_sendheader(client, REPORT_DO_DNS);

  auth->dns_pending = true;

  if (ConfigGeneral.disable_auth == 0)
    auth_start_query(auth);

  gethost_byaddr(auth_dns_callback, auth, &client->ip);
}

/**
 * @brief Deletes the AuthRequest structure and associated resources.
 *
 * This function is responsible for cleaning up the AuthRequest structure
 * and freeing associated resources. If the AuthRequest has an associated
 * file descriptor, it is closed. Ident queries and DNS lookups are canceled,
 * and related flags are updated. The function ensures the proper cleanup of
 * memory and state related to the authentication process.
 *
 * @param auth The AuthRequest structure to delete.
 */
void
auth_delete(struct AuthRequest *auth)
{
  assert(auth->client);
  assert(auth->client->connection);

  if (auth->fd)
  {
    fd_close(auth->fd);
    auth->fd = NULL;
  }

  auth->ident_pending = false;

  delete_resolver_queries(auth);
  auth->dns_pending = false;

  auth_free(auth);
}
