/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file res.c
 * \brief ircd resolver functions
 * \version $Id$
 */

/*
 * A rewrite of Darren Reed's original res.c As there is nothing
 * left of Darren's original code, this is now licensed by the hybrid group.
 * (Well, some of the function names are the same, and bits of the structs..)
 * You can use it where it is useful, free even. Buy us a beer and stuff.
 *
 * The authors takes no responsibility for any damage or loss
 * of property which results from the use of this software.
 *
 * July 1999 - Rewrote a bunch of stuff here. Change hostent builder code,
 *     added callbacks and reference counting of returned hostents.
 *     --Bleep (Thomas Helvey <tomh@inxpress.net>)
 *
 * This was all needlessly complicated for irc. Simplified. No more hostent
 * All we really care about is the IP -> hostname mappings. That's all.
 *
 * Apr 28, 2003 --cryogen and Dianora
 */

#include "stdinc.h"
#include "list.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "rng_mt.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "misc.h"
#include "res.h"
#include "reslib.h"
#include "memory.h"
#include "conf.h"
#include "hostmask.h"

#if (CHAR_BIT != 8)
#error this code needs to be able to address individual octets
#endif

static void res_readreply(fde_t *, void *);

#define MAXPACKET      1024  /**< rfc says 512 but we expand names so ... */

/*
 * RFC 1104/1105 wasn't very helpful about what these fields
 * should be named, so for now, we'll just name them this way.
 * We probably should look at what named calls them or something.
 */
#define TYPE_SIZE         (size_t)2
#define CLASS_SIZE        (size_t)2
#define TTL_SIZE          (size_t)4
#define RDLENGTH_SIZE     (size_t)2
#define ANSWER_FIXED_SIZE (TYPE_SIZE + CLASS_SIZE + TTL_SIZE + RDLENGTH_SIZE)

struct reslist
{
  dlink_node node;                           /**< Doubly linked list node. */
  unsigned int id;                           /**< Request ID (from request header). */
  char type;                                 /**< Current request type. */
  char retries;                              /**< Retry counter */
  unsigned int sends;                        /**< Number of sends (>1 means resent). */
  uintmax_t sentat;                          /**< Timestamp we last sent this request. */
  uintmax_t timeout;                         /**< When this request times out. */
  struct irc_ssaddr addr;                    /**< Address for this request. */
  char name[RFC1035_MAX_DOMAIN_LENGTH + 1];  /**< Hostname for this request. */
  size_t namelength;                         /**< Actual hostname length. */
  dns_callback_fnc callback;                 /**< Callback function on completion. */
  void *callback_ctx;                        /**< Context pointer for callback. */
};

static fde_t *ResolverFileDescriptor;
static dlink_list request_list;


/*
 * rem_request - remove a request from the list.
 * This must also free any memory that has been allocated for
 * temporary storage of DNS results.
 */
static void
rem_request(struct reslist *request)
{
  dlinkDelete(&request->node, &request_list);
  xfree(request);
}

/*
 * make_request - Create a DNS request record for the server.
 */
static struct reslist *
make_request(dns_callback_fnc callback, void *ctx)
{
  struct reslist *request = xcalloc(sizeof(*request));

  request->sentat = event_base->time.sec_monotonic;
  request->retries = 2;
  request->timeout = 4;  /* Start at 4 and exponential inc. */
  request->callback = callback;
  request->callback_ctx = ctx;

  dlinkAdd(request, &request->node, &request_list);
  return request;
}

/*
 * int
 * res_ourserver(inp)
 *      looks up "inp" in reslib_nsaddr_list[]
 * returns:
 *      0  : not found
 *      >0 : found
 * author:
 *      paul vixie, 29may94
 *      revised for ircd, cryogen(stu) may03
 */
static bool
res_ourserver(const struct irc_ssaddr *inp)
{
  for (unsigned int i = 0; i < reslib_nscount; ++i)
    if (address_compare(inp, &reslib_nsaddr_list[i], true, true, 0) == true)
      return true;

  return false;
}

/*
 * start_resolver - do everything we need to read the resolv.conf file
 * and initialize the resolver file descriptor if needed
 */
static void
start_resolver(void)
{
  reslib_res_init();

  if (ResolverFileDescriptor == NULL)
  {
    int fd = comm_socket(reslib_nsaddr_list[0].ss.ss_family, SOCK_DGRAM, 0);
    if (fd == -1)
      return;

    ResolverFileDescriptor = fd_open(fd, true, "UDP resolver socket");

    /* At the moment, the resolver FD data is global .. */
    comm_setselect(ResolverFileDescriptor, COMM_SELECT_READ, res_readreply, NULL, 0);
  }
}

/*
 * restart_resolver - reread resolv.conf, reopen socket
 */
void
restart_resolver(void)
{
  if (ResolverFileDescriptor)
  {
    fd_close(ResolverFileDescriptor);
    ResolverFileDescriptor = NULL;
  }

  start_resolver();
}

/*
 * delete_resolver_queries - cleanup outstanding queries
 * for which there no longer exist clients or conf lines.
 */
void
delete_resolver_queries(const void *vptr)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, request_list.head)
  {
    struct reslist *request = node->data;

    if (request->callback_ctx == vptr)
      rem_request(request);
  }
}

/*
 * send_res_msg - sends msg to all nameservers found in the "_res" structure.
 * This should reflect /etc/resolv.conf. We will get responses
 * which arent needed but is easier than checking to see if nameserver
 * isn't present. Returns number of messages successfully sent to
 * nameservers or -1 if no successful sends.
 */
static void
send_res_msg(const unsigned char *msg, int len, unsigned int rcount)
{
  unsigned int max_queries = IRCD_MIN(reslib_nscount, rcount);

  /* RES_PRIMARY option is not implemented
   * if (res.options & RES_PRIMARY || 0 == max_queries)
   */
  if (max_queries == 0)
    max_queries = 1;

  for (unsigned int i = 0; i < max_queries; ++i)
    sendto(ResolverFileDescriptor->fd, msg, len, 0,
           (struct sockaddr *)&reslib_nsaddr_list[i], reslib_nsaddr_list[i].ss_len);
}

/*
 * find_id - find a dns request id (id is determined by dn_mkquery)
 */
static struct reslist *
find_id(unsigned int id)
{
  dlink_node *node;

  DLINK_FOREACH(node, request_list.head)
  {
    struct reslist *request = node->data;

    if (request->id == id)
      return request;
  }

  return NULL;
}

/*
 * query_name - generate a query based on class, type and name.
 */
static void
query_name(const char *name, int query_class, int type, struct reslist *request)
{
  unsigned char buf[MAXPACKET];

  memset(buf, 0, sizeof(buf));

  int request_len = reslib_res_mkquery(name, query_class, type, buf, sizeof(buf));
  if (request_len > 0)
  {
    HEADER *header = (HEADER *)buf;

    /*
     * Generate an unique id.
     * NOTE: we don't have to worry about converting this to and from
     * network byte order, the nameserver does not interpret this value
     * and returns it unchanged.
     */
    do
      header->id = (header->id + genrand_int32()) & 0xFFFF;
    while (find_id(header->id));

    request->id = header->id;
    ++request->sends;

    send_res_msg(buf, request_len, request->sends);
  }
}

/*
 * do_query_name - nameserver lookup name
 */
static void
do_query_name(dns_callback_fnc callback, void *ctx, const char *name,
              struct reslist *request, int type)
{
  char host_name[RFC1035_MAX_DOMAIN_LENGTH + 1];

  strlcpy(host_name, name, sizeof(host_name));

  if (request == NULL)
  {
    request = make_request(callback, ctx);
    request->type = type;
    request->namelength = strlcpy(request->name, host_name, sizeof(request->name));
  }

  request->type = type;
  query_name(host_name, C_IN, type, request);
}

/*
 * do_query_number - Use this to do reverse IP# lookups.
 */
static void
do_query_number(dns_callback_fnc callback, void *ctx,
                const struct irc_ssaddr *addr,
                struct reslist *request)
{
  char ipbuf[128] = "";

  if (addr->ss.ss_family == AF_INET)
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *)addr;
    const unsigned char *cp = (const unsigned char *)&v4->sin_addr.s_addr;

    snprintf(ipbuf, sizeof(ipbuf), "%u.%u.%u.%u.in-addr.arpa.",
             (unsigned int)(cp[3]), (unsigned int)(cp[2]),
             (unsigned int)(cp[1]), (unsigned int)(cp[0]));
  }
  else if (addr->ss.ss_family == AF_INET6)
  {
    const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)addr;
    const unsigned char *cp = (const unsigned char *)&v6->sin6_addr.s6_addr;

    snprintf(ipbuf, sizeof(ipbuf),
             "%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x."
             "%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.%x.ip6.arpa.",
             (unsigned int)(cp[15] & 0xf), (unsigned int)(cp[15] >> 4),
             (unsigned int)(cp[14] & 0xf), (unsigned int)(cp[14] >> 4),
             (unsigned int)(cp[13] & 0xf), (unsigned int)(cp[13] >> 4),
             (unsigned int)(cp[12] & 0xf), (unsigned int)(cp[12] >> 4),
             (unsigned int)(cp[11] & 0xf), (unsigned int)(cp[11] >> 4),
             (unsigned int)(cp[10] & 0xf), (unsigned int)(cp[10] >> 4),
             (unsigned int)(cp[9] & 0xf), (unsigned int)(cp[9] >> 4),
             (unsigned int)(cp[8] & 0xf), (unsigned int)(cp[8] >> 4),
             (unsigned int)(cp[7] & 0xf), (unsigned int)(cp[7] >> 4),
             (unsigned int)(cp[6] & 0xf), (unsigned int)(cp[6] >> 4),
             (unsigned int)(cp[5] & 0xf), (unsigned int)(cp[5] >> 4),
             (unsigned int)(cp[4] & 0xf), (unsigned int)(cp[4] >> 4),
             (unsigned int)(cp[3] & 0xf), (unsigned int)(cp[3] >> 4),
             (unsigned int)(cp[2] & 0xf), (unsigned int)(cp[2] >> 4),
             (unsigned int)(cp[1] & 0xf), (unsigned int)(cp[1] >> 4),
             (unsigned int)(cp[0] & 0xf), (unsigned int)(cp[0] >> 4));
  }

  if (request == NULL)
  {
    request = make_request(callback, ctx);
    request->type = T_PTR;
    request->addr = *addr;
  }

  query_name(ipbuf, C_IN, T_PTR, request);
}

/*
 * gethost_byname_type - get host address from name
 *
 */
void
gethost_byname_type(dns_callback_fnc callback, void *ctx, const char *name, int type)
{
  assert(name);
  do_query_name(callback, ctx, name, NULL, type);
}

/*
 * gethost_byaddr - get host name from address
 */
void
gethost_byaddr(dns_callback_fnc callback, void *ctx, const struct irc_ssaddr *addr)
{
  do_query_number(callback, ctx, addr, NULL);
}

static void
resend_query(struct reslist *request)
{
  switch (request->type)
  {
    case T_PTR:
      do_query_number(NULL, NULL, &request->addr, request);
      break;
    case T_A:
    case T_AAAA:
      do_query_name(NULL, NULL, request->name, request, request->type);
      break;
    default:
      break;
  }
}

/*
 * proc_answer - process name server reply
 */
static bool
proc_answer(struct reslist *request, HEADER *header, unsigned char *buf, unsigned char *eob)
{
  char hostbuf[RFC1035_MAX_DOMAIN_LENGTH + 100]; /* working buffer */
  unsigned char *current = buf + sizeof(HEADER); /* current position in buf */
  unsigned int type = 0;       /* answer type */
  unsigned int rd_length = 0;
  struct sockaddr_in *v4;      /* conversion */
  struct sockaddr_in6 *v6;

  for (; header->qdcount > 0; --header->qdcount)
  {
    int n = reslib_dn_skipname(current, eob);
    if (n < 0)
      break;

    current += (size_t)n + QFIXEDSZ;
  }

  /*
   * Process each answer sent to us blech.
   */
  while (header->ancount > 0 && current < eob)
  {
    --header->ancount;

    int n = reslib_dn_expand(buf, eob, current, hostbuf, sizeof(hostbuf));
    if (n < 0  /* Broken message */ || n == 0  /* No more answers left */)
      return false;

    hostbuf[RFC1035_MAX_DOMAIN_LENGTH] = '\0';

    /*
     * With Address arithmetic you have to be very anal
     * this code was not working on alpha due to that
     * (spotted by rodder/jailbird/dianora)
     */
    current += (size_t)n;

    if (!((current + ANSWER_FIXED_SIZE) < eob))
      break;

    type = reslib_ns_get16(current);
    current += TYPE_SIZE;
    current += CLASS_SIZE;
    current += TTL_SIZE;
    rd_length = reslib_ns_get16(current);
    current += RDLENGTH_SIZE;

    /*
     * Wait to set request->type until we verify this structure
     */
    switch (type)
    {
      case T_A:
        if (request->type != T_A)
          return false;

        /*
         * Check for invalid rd_length or too many addresses
         */
        if (rd_length != sizeof(struct in_addr))
          return false;

        request->addr.ss_len = sizeof(struct sockaddr_in);
        v4 = (struct sockaddr_in *)&request->addr;
        v4->sin_family = AF_INET;
        memcpy(&v4->sin_addr, current, sizeof(struct in_addr));
        return true;
        break;

      case T_AAAA:
        if (request->type != T_AAAA)
          return false;

        if (rd_length != sizeof(struct in6_addr))
          return false;

        request->addr.ss_len = sizeof(struct sockaddr_in6);
        v6 = (struct sockaddr_in6 *)&request->addr;
        v6->sin6_family = AF_INET6;
        memcpy(&v6->sin6_addr, current, sizeof(struct in6_addr));
        return true;
        break;

      case T_PTR:
        if (request->type != T_PTR)
          return false;

        n = reslib_dn_expand(buf, eob, current, hostbuf, sizeof(hostbuf));
        if (n < 0  /* Broken message */ || n == 0  /* No more answers left */)
          return false;

        request->namelength = strlcpy(request->name, hostbuf, sizeof(request->name));
        return true;
        break;

      case T_CNAME:
        current += rd_length;
        break;

      default:
        return false;
        break;
    }
  }

  return false;
}

/*
 * res_readreply - read a dns reply from the nameserver and process it.
 */
static void
res_readreply(fde_t *F, void *data)
{
  unsigned char buf[sizeof(HEADER) + MAXPACKET];
  ssize_t rc;
  socklen_t len = sizeof(struct irc_ssaddr);
  struct irc_ssaddr lsin;

  while ((rc = recvfrom(F->fd, buf, sizeof(buf), 0, (struct sockaddr *)&lsin, &len)) != -1)
  {
    if (rc <= (ssize_t)sizeof(HEADER))
      continue;

    /*
     * Check against possibly fake replies
     */
    if (res_ourserver(&lsin) == false)
      continue;

    /*
     * Convert DNS reply reader from Network byte order to CPU byte order.
     */
    HEADER *header = (HEADER *)buf;
    header->ancount = ntohs(header->ancount);
    header->qdcount = ntohs(header->qdcount);
    header->nscount = ntohs(header->nscount);
    header->arcount = ntohs(header->arcount);

    /*
     * Response for an id which we have already received an answer for
     * just ignore this response.
     */
    struct reslist *request = find_id(header->id);
    if (request == NULL)
      continue;

    if (header->rcode != NO_ERRORS || header->ancount == 0)
    {
      /*
       * If a bad error was returned, stop here and don't send
       * any more (no retries granted).
       */
      (*request->callback)(request->callback_ctx, NULL, NULL, 0);
      rem_request(request);
      continue;
    }

    /*
     * If this fails there was an error decoding the received packet.
     * We only give it one shot. If it fails, just leave the client
     * unresolved.
     */
    if (proc_answer(request, header, buf, buf + rc) == false)
    {
      (*request->callback)(request->callback_ctx, NULL, NULL, 0);
      rem_request(request);
      continue;
    }

    if (request->type == T_PTR)
    {
      if (request->namelength == 0)
      {
        /*
         * Got a PTR response with no name, something bogus is happening
         * don't bother trying again, the client address doesn't resolve
         */
        (*request->callback)(request->callback_ctx, NULL, NULL, 0);
        rem_request(request);
        continue;
      }

      /*
       * Lookup the 'authoritative' name that we were given for the ip#.
       */
      if (request->addr.ss.ss_family == AF_INET6)
        gethost_byname_type(request->callback, request->callback_ctx, request->name, T_AAAA);
      else
        gethost_byname_type(request->callback, request->callback_ctx, request->name, T_A);

      rem_request(request);
    }
    else
    {
      /*
       * Got a name and address response, client resolved
       */
      (*request->callback)(request->callback_ctx, &request->addr, request->name, request->namelength);
      rem_request(request);
    }
  }

  comm_setselect(F, COMM_SELECT_READ, res_readreply, NULL, 0);
}

/*
 * timeout_query_list - Remove queries from the list which have been
 * there too long without being resolved.
 */
static void
resolver_timeout(void *unused)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, request_list.head)
  {
    struct reslist *request = node->data;
    uintmax_t timeout = request->sentat + request->timeout;

    if (event_base->time.sec_monotonic >= timeout)
    {
      if (--request->retries <= 0)
      {
        (*request->callback)(request->callback_ctx, NULL, NULL, 0);
        rem_request(request);
      }
      else
      {
        request->sentat = event_base->time.sec_monotonic;
        request->timeout += request->timeout;
        resend_query(request);
      }
    }
  }
}

/*
 * resolver_init - initialize resolver and resolver library
 */
void
resolver_init(void)
{
  static struct event resolver_timeout_event =
  {
    .name = "resolver_timeout",
    .handler = resolver_timeout,
    .when = 1
  };

  start_resolver();
  event_add(&resolver_timeout_event, NULL);
}
