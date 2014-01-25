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

/*! \file irc_res.c
 * \brief ircd resolver functions
 * \version $Id$
 */

/*
 * A rewrite of Darren Reeds original res.c As there is nothing
 * left of Darrens original code, this is now licensed by the hybrid group.
 * (Well, some of the function names are the same, and bits of the structs..)
 * You can use it where it is useful, free even. Buy us a beer and stuff.
 *
 * The authors takes no responsibility for any damage or loss
 * of property which results from the use of this software.
 *
 * $Id$
 *
 * July 1999 - Rewrote a bunch of stuff here. Change hostent builder code,
 *     added callbacks and reference counting of returned hostents.
 *     --Bleep (Thomas Helvey <tomh@inxpress.net>)
 *
 * This was all needlessly complicated for irc. Simplified. No more hostent
 * All we really care about is the IP -> hostname mappings. Thats all.
 *
 * Apr 28, 2003 --cryogen and Dianora
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "event.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "rng_mt.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "log.h"
#include "s_misc.h"
#include "send.h"
#include "memory.h"
#include "mempool.h"
#include "irc_res.h"
#include "irc_reslib.h"

#if (CHAR_BIT != 8)
#error this code needs to be able to address individual octets
#endif

static PF res_readreply;

#define MAXPACKET      1024  /* rfc sez 512 but we expand names so ... */
#define RES_MAXALIASES 35    /* maximum aliases allowed */
#define RES_MAXADDRS   35    /* maximum addresses allowed */
#define AR_TTL         600   /* TTL in seconds for dns cache entries */

/* RFC 1104/1105 wasn't very helpful about what these fields
 * should be named, so for now, we'll just name them this way.
 * we probably should look at what named calls them or something.
 */
#define TYPE_SIZE         (size_t)2
#define CLASS_SIZE        (size_t)2
#define TTL_SIZE          (size_t)4
#define RDLENGTH_SIZE     (size_t)2
#define ANSWER_FIXED_SIZE (TYPE_SIZE + CLASS_SIZE + TTL_SIZE + RDLENGTH_SIZE)

typedef enum
{
  REQ_IDLE,  /* We're doing not much at all */
  REQ_PTR,   /* Looking up a PTR */
  REQ_A,     /* Looking up an A, possibly because AAAA failed */
#ifdef IPV6
  REQ_AAAA,  /* Looking up an AAAA */
#endif
  REQ_CNAME  /* We got a CNAME in response, we better get a real answer next */
} request_state;

struct reslist
{
  dlink_node node;
  int id;
  int sent;                /* number of requests sent */
  request_state state;     /* State the resolver machine is in */
  time_t ttl;
  char type;
  char retries;            /* retry counter */
  char sends;              /* number of sends (>1 means resent) */
  char resend;             /* send flag. 0 == dont resend */
  time_t sentat;
  time_t timeout;
  struct irc_ssaddr addr;
  char *name;
  dns_callback_fnc callback;
  void *callback_ctx;
};

static fde_t ResolverFileDescriptor;
static dlink_list request_list = { NULL, NULL, 0 };
static mp_pool_t *dns_pool = NULL;

static void rem_request(struct reslist *);
static struct reslist *make_request(dns_callback_fnc, void *);
static void do_query_name(dns_callback_fnc, void *,
                          const char *, struct reslist *, int);
static void do_query_number(dns_callback_fnc, void *,
                            const struct irc_ssaddr *,
                            struct reslist *);
static void query_name(const char *, int, int, struct reslist *);
static int send_res_msg(const char *, int, int);
static void resend_query(struct reslist *);
static int proc_answer(struct reslist *, HEADER *, char *, char *);
static struct reslist *find_id(int);


/*
 * int
 * res_ourserver(inp)
 *      looks up "inp" in irc_nsaddr_list[]
 * returns:
 *      0  : not found
 *      >0 : found
 * author:
 *      paul vixie, 29may94
 *      revised for ircd, cryogen(stu) may03
 */
static int
res_ourserver(const struct irc_ssaddr *inp)
{
#ifdef IPV6
  const struct sockaddr_in6 *v6;
  const struct sockaddr_in6 *v6in = (const struct sockaddr_in6 *)inp;
#endif
  const struct sockaddr_in *v4;
  const struct sockaddr_in *v4in = (const struct sockaddr_in *)inp;
  int ns;

  for (ns = 0; ns < irc_nscount; ++ns)
  {
    const struct irc_ssaddr *srv = &irc_nsaddr_list[ns];
#ifdef IPV6
    v6 = (const struct sockaddr_in6 *)srv;
#endif
    v4 = (const struct sockaddr_in *)srv;

    /* could probably just memcmp(srv, inp, srv.ss_len) here
     * but we'll air on the side of caution - stu
     *
     */
    switch (srv->ss.ss_family)
    {
#ifdef IPV6
      case AF_INET6:
        if (srv->ss.ss_family == inp->ss.ss_family)
          if (v6->sin6_port == v6in->sin6_port)
            if (!memcmp(&v6->sin6_addr.s6_addr, &v6in->sin6_addr.s6_addr,
                        sizeof(struct in6_addr)))
              return 1;
        break;
#endif
      case AF_INET:
        if (srv->ss.ss_family == inp->ss.ss_family)
          if (v4->sin_port == v4in->sin_port)
            if (v4->sin_addr.s_addr == v4in->sin_addr.s_addr)
              return 1;
        break;
      default:
        break;
    }
  }

  return 0;
}

/*
 * timeout_query_list - Remove queries from the list which have been
 * there too long without being resolved.
 */
static time_t
timeout_query_list(time_t now)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct reslist *request;
  time_t next_time = 0;
  time_t timeout   = 0;

  DLINK_FOREACH_SAFE(ptr, next_ptr, request_list.head)
  {
    request = ptr->data;
    timeout = request->sentat + request->timeout;

    if (now >= timeout)
    {
      if (--request->retries <= 0)
      {
        (*request->callback)(request->callback_ctx, NULL, NULL);
        rem_request(request);
        continue;
      }
      else
      {
        request->sentat = now;
        request->timeout += request->timeout;
        resend_query(request);
      }
    }

    if ((next_time == 0) || timeout < next_time)
      next_time = timeout;
  }

  return (next_time > now) ? next_time : (now + AR_TTL);
}

/*
 * timeout_resolver - check request list
 */
static void
timeout_resolver(void *notused)
{
  timeout_query_list(CurrentTime);
}

/*
 * start_resolver - do everything we need to read the resolv.conf file
 * and initialize the resolver file descriptor if needed
 */
static void
start_resolver(void)
{
  irc_res_init();

  if (!ResolverFileDescriptor.flags.open)
  {
    if (comm_open(&ResolverFileDescriptor, irc_nsaddr_list[0].ss.ss_family,
                  SOCK_DGRAM, 0, "Resolver socket") == -1)
      return;

    /* At the moment, the resolver FD data is global .. */
    comm_setselect(&ResolverFileDescriptor, COMM_SELECT_READ,
        res_readreply, NULL, 0);
    eventAdd("timeout_resolver", timeout_resolver, NULL, 1);
  }
}

/*
 * init_resolver - initialize resolver and resolver library
 */
void
init_resolver(void)
{
  dns_pool = mp_pool_new(sizeof(struct reslist), MP_CHUNK_SIZE_DNS);
  memset(&ResolverFileDescriptor, 0, sizeof(fde_t));
  start_resolver();
}

/*
 * restart_resolver - reread resolv.conf, reopen socket
 */
void
restart_resolver(void)
{
  fd_close(&ResolverFileDescriptor);
  eventDelete(timeout_resolver, NULL); /* -ddosen */
  start_resolver();
}

/*
 * rem_request - remove a request from the list.
 * This must also free any memory that has been allocated for
 * temporary storage of DNS results.
 */
static void
rem_request(struct reslist *request)
{
  dlinkDelete(&request->node, &request_list);

  MyFree(request->name);
  mp_pool_release(request);
}

/*
 * make_request - Create a DNS request record for the server.
 */
static struct reslist *
make_request(dns_callback_fnc callback, void *ctx)
{
  struct reslist *request = mp_pool_get(dns_pool);

  memset(request, 0, sizeof(*request));
  request->sentat       = CurrentTime;
  request->retries      = 3;
  request->resend       = 1;
  request->timeout      = 4;    /* start at 4 and exponential inc. */
  request->state        = REQ_IDLE;
  request->callback     = callback;
  request->callback_ctx = ctx;

  dlinkAdd(request, &request->node, &request_list);
  return request;
}

/*
 * delete_resolver_queries - cleanup outstanding queries
 * for which there no longer exist clients or conf lines.
 */
void
delete_resolver_queries(const void *vptr)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;

  DLINK_FOREACH_SAFE(ptr, next_ptr, request_list.head)
  {
    struct reslist *request = ptr->data;

    if (request->callback_ctx == vptr)
      rem_request(request);
  }
}

/*
 * send_res_msg - sends msg to all nameservers found in the "_res" structure.
 * This should reflect /etc/resolv.conf. We will get responses
 * which arent needed but is easier than checking to see if nameserver
 * isnt present. Returns number of messages successfully sent to
 * nameservers or -1 if no successful sends.
 */
static int
send_res_msg(const char *msg, int len, int rcount)
{
  int i;
  int sent = 0;
  int max_queries = IRCD_MIN(irc_nscount, rcount);

  /* RES_PRIMARY option is not implemented
   * if (res.options & RES_PRIMARY || 0 == max_queries)
   */
  if (max_queries == 0)
    max_queries = 1;

  for (i = 0; i < max_queries; i++)
  {
    if (sendto(ResolverFileDescriptor.fd, msg, len, 0,
        (struct sockaddr*)&(irc_nsaddr_list[i]),
        irc_nsaddr_list[i].ss_len) == len)
      ++sent;
  }

  return sent;
}

/*
 * find_id - find a dns request id (id is determined by dn_mkquery)
 */
static struct reslist *
find_id(int id)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, request_list.head)
  {
    struct reslist *request = ptr->data;

    if (request->id == id)
      return request;
  }

  return NULL;
}

/*
 * gethost_byname_type - get host address from name
 *
 */
void
gethost_byname_type(dns_callback_fnc callback, void *ctx, const char *name, int type)
{
  assert(name != NULL);
  do_query_name(callback, ctx, name, NULL, type);
}

/*
 * gethost_byname - wrapper for _type - send T_AAAA first if IPV6 supported
 */
void
gethost_byname(dns_callback_fnc callback, void *ctx, const char *name)
{
#ifdef IPV6
  gethost_byname_type(callback, ctx, name, T_AAAA);
#else
  gethost_byname_type(callback, ctx, name, T_A);
#endif
}

/*
 * gethost_byaddr - get host name from address
 */
void
gethost_byaddr(dns_callback_fnc callback, void *ctx, const struct irc_ssaddr *addr)
{
  do_query_number(callback, ctx, addr, NULL);
}

/*
 * do_query_name - nameserver lookup name
 */
static void
do_query_name(dns_callback_fnc callback, void *ctx, const char *name,
              struct reslist *request, int type)
{
  char host_name[HOSTLEN + 1];

  strlcpy(host_name, name, sizeof(host_name));

  if (request == NULL)
  {
    request       = make_request(callback, ctx);
    request->name = MyMalloc(strlen(host_name) + 1);
    request->type = type;
    strcpy(request->name, host_name);
#ifdef IPV6
    if (type != T_A)
      request->state = REQ_AAAA;
    else
#endif
    request->state = REQ_A;
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
  char ipbuf[128];
  const unsigned char *cp;

  if (addr->ss.ss_family == AF_INET)
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *)addr;
    cp = (const unsigned char *)&v4->sin_addr.s_addr;

    snprintf(ipbuf, sizeof(ipbuf), "%u.%u.%u.%u.in-addr.arpa.",
             (unsigned int)(cp[3]), (unsigned int)(cp[2]),
             (unsigned int)(cp[1]), (unsigned int)(cp[0]));
  }
#ifdef IPV6
  else if (addr->ss.ss_family == AF_INET6)
  {
    const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)addr;
    cp = (const unsigned char *)&v6->sin6_addr.s6_addr;

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
#endif
  if (request == NULL)
  {
    request       = make_request(callback, ctx);
    request->type = T_PTR;
    memcpy(&request->addr, addr, sizeof(struct irc_ssaddr));
    request->name = MyMalloc(HOSTLEN + 1);
  }

  query_name(ipbuf, C_IN, T_PTR, request);
}

/*
 * query_name - generate a query based on class, type and name.
 */
static void
query_name(const char *name, int query_class, int type,
           struct reslist *request)
{
  char buf[MAXPACKET];
  int request_len = 0;

  memset(buf, 0, sizeof(buf));

  if ((request_len = irc_res_mkquery(name, query_class, type,
      (unsigned char *)buf, sizeof(buf))) > 0)
  {
    HEADER *header = (HEADER *)buf;

    /*
     * generate an unique id
     * NOTE: we don't have to worry about converting this to and from
     * network byte order, the nameserver does not interpret this value
     * and returns it unchanged
     */
    do
      header->id = (header->id + genrand_int32()) & 0xffff;
    while (find_id(header->id));

    request->id = header->id;
    ++request->sends;

    request->sent += send_res_msg(buf, request_len, request->sends);
  }
}

static void
resend_query(struct reslist *request)
{
  if (request->resend == 0)
    return;

  switch (request->type)
  {
    case T_PTR:
      do_query_number(NULL, NULL, &request->addr, request);
      break;
    case T_A:
      do_query_name(NULL, NULL, request->name, request, request->type);
      break;
#ifdef IPV6
    case T_AAAA:
      /* didnt work, try A */
      if (request->state == REQ_AAAA)
        do_query_name(NULL, NULL, request->name, request, T_A);
#endif
    default:
      break;
  }
}

/*
 * proc_answer - process name server reply
 */
static int
proc_answer(struct reslist *request, HEADER *header, char *buf, char *eob)
{
  char hostbuf[HOSTLEN + 100]; /* working buffer */
  unsigned char *current;      /* current position in buf */
  int query_class;             /* answer class */
  int type;                    /* answer type */
  int n;                       /* temp count */
  int rd_length;
  struct sockaddr_in *v4;      /* conversion */
#ifdef IPV6
  struct sockaddr_in6 *v6;
#endif
  current = (unsigned char *)buf + sizeof(HEADER);

  for (; header->qdcount > 0; --header->qdcount)
  {
    if ((n = irc_dn_skipname(current, (unsigned char *)eob)) < 0)
      break;

    current += (size_t)n + QFIXEDSZ;
  }

  /*
   * process each answer sent to us blech.
   */
  while (header->ancount > 0 && (char *)current < eob)
  {
    header->ancount--;

    n = irc_dn_expand((unsigned char *)buf, (unsigned char *)eob, current,
        hostbuf, sizeof(hostbuf));

    if (n < 0 /* broken message */ || n == 0 /* no more answers left */)
      return 0;

    hostbuf[HOSTLEN] = '\0';

    /* With Address arithmetic you have to be very anal
     * this code was not working on alpha due to that
     * (spotted by rodder/jailbird/dianora)
     */
    current += (size_t) n;

    if (!(((char *)current + ANSWER_FIXED_SIZE) < eob))
      break;

    type = irc_ns_get16(current);
    current += TYPE_SIZE;

    query_class = irc_ns_get16(current);
    current += CLASS_SIZE;

    request->ttl = irc_ns_get32(current);
    current += TTL_SIZE;

    rd_length = irc_ns_get16(current);
    current += RDLENGTH_SIZE;

    /*
     * Wait to set request->type until we verify this structure
     */
    switch (type)
    {
      case T_A:
        if (request->type != T_A)
          return 0;

        /*
         * check for invalid rd_length or too many addresses
         */
        if (rd_length != sizeof(struct in_addr))
          return 0;

        v4 = (struct sockaddr_in *)&request->addr;
        request->addr.ss_len = sizeof(struct sockaddr_in);
        v4->sin_family = AF_INET;
        memcpy(&v4->sin_addr, current, sizeof(struct in_addr));
        return 1;
        break;
#ifdef IPV6
      case T_AAAA:
        if (request->type != T_AAAA)
          return 0;

        if (rd_length != sizeof(struct in6_addr))
          return 0;

        request->addr.ss_len = sizeof(struct sockaddr_in6);
        v6 = (struct sockaddr_in6 *)&request->addr;
        v6->sin6_family = AF_INET6;
        memcpy(&v6->sin6_addr, current, sizeof(struct in6_addr));
        return 1;
        break;
#endif
      case T_PTR:
        if (request->type != T_PTR)
          return 0;

        n = irc_dn_expand((unsigned char *)buf, (unsigned char *)eob,
            current, hostbuf, sizeof(hostbuf));
        if (n < 0 /* broken message */ || n == 0 /* no more answers left */)
          return 0;

        strlcpy(request->name, hostbuf, HOSTLEN + 1);
        return 1;
        break;
      case T_CNAME: /* first check we already havent started looking
                       into a cname */
        if (request->type != T_PTR)
          return 0;

        if (request->state == REQ_CNAME)
        {
          n = irc_dn_expand((unsigned char *)buf, (unsigned char *)eob,
                            current, hostbuf, sizeof(hostbuf));

          if (n < 0)
            return 0;
          return 1;
        }

        request->state = REQ_CNAME;
        current += rd_length;
        break;

      default:
        /* XXX I'd rather just throw away the entire bogus thing
         * but its possible its just a broken nameserver with still
         * valid answers. But lets do some rudimentary logging for now...
         */
        ilog(LOG_TYPE_IRCD, "irc_res.c bogus type %d", type);
        break;
    }
  }

  return 1;
}

/*
 * res_readreply - read a dns reply from the nameserver and process it.
 */
static void
res_readreply(fde_t *fd, void *data)
{
  char buf[sizeof(HEADER) + MAXPACKET]
	/* Sparc and alpha need 16bit-alignment for accessing header->id
	 * (which is uint16_t). Because of the header = (HEADER*) buf;
	 * lateron, this is neeeded. --FaUl
	 */
#if defined(__sparc__) || defined(__alpha__)
	  __attribute__((aligned (16)))
#endif
	  ;
  HEADER *header;
  struct reslist *request = NULL;
  int rc;
  socklen_t len = sizeof(struct irc_ssaddr);
  struct irc_ssaddr lsin;

  rc = recvfrom(fd->fd, buf, sizeof(buf), 0, (struct sockaddr *)&lsin, &len);

  /* Re-schedule a read *after* recvfrom, or we'll be registering
   * interest where it'll instantly be ready for read :-) -- adrian
   */
  comm_setselect(fd, COMM_SELECT_READ, res_readreply, NULL, 0);

  /* Better to cast the sizeof instead of rc */
  if (rc <= (int)(sizeof(HEADER)))
    return;

  /*
   * convert DNS reply reader from Network byte order to CPU byte order.
   */
  header = (HEADER *)buf;
  header->ancount = ntohs(header->ancount);
  header->qdcount = ntohs(header->qdcount);
  header->nscount = ntohs(header->nscount);
  header->arcount = ntohs(header->arcount);

  /*
   * check against possibly fake replies
   */
  if (!res_ourserver(&lsin))
    return;

  /*
   * response for an id which we have already received an answer for
   * just ignore this response.
   */
  if (!(request = find_id(header->id)))
    return;

  if ((header->rcode != NO_ERRORS) || (header->ancount == 0))
  {
    if (header->rcode == SERVFAIL || header->rcode == NXDOMAIN)
    {
      /*
       * If a bad error was returned, stop here and don't
       * send any more (no retries granted).
       */
      (*request->callback)(request->callback_ctx, NULL, NULL);
      rem_request(request);
    }
#ifdef IPV6
    else
    {
      /*
       * If we havent already tried this, and we're looking up AAAA, try A
       * now
       */
      if (request->state == REQ_AAAA && request->type == T_AAAA)
      {
        request->timeout += 4;
        resend_query(request);
      }
    }
#endif

    return;
  }

  /*
   * If this fails there was an error decoding the received packet,
   * try it again and hope it works the next time.
   */
  if (proc_answer(request, header, buf, buf + rc))
  {
    if (request->type == T_PTR)
    {
      if (request->name == NULL)
      {
        /*
         * got a PTR response with no name, something bogus is happening
         * don't bother trying again, the client address doesn't resolve
         */
        (*request->callback)(request->callback_ctx, NULL, NULL);
        rem_request(request);
        return;
      }

      /*
       * Lookup the 'authoritative' name that we were given for the
       * ip#.
       *
       */
#ifdef IPV6
      if (request->addr.ss.ss_family == AF_INET6)
        gethost_byname_type(request->callback, request->callback_ctx, request->name, T_AAAA);
      else
#endif
      gethost_byname_type(request->callback, request->callback_ctx, request->name, T_A);
      rem_request(request);
    }
    else
    {
      /*
       * got a name and address response, client resolved
       */
      (*request->callback)(request->callback_ctx, &request->addr, request->name);
      rem_request(request);
    }
  }
  else if (!request->sent)
  {
    /* XXX - we got a response for a query we didn't send with a valid id?
     * this should never happen, bail here and leave the client unresolved
     */
    assert(0);

    /* XXX don't leak it */
    rem_request(request);
  }
}

void
report_dns_servers(struct Client *source_p)
{
  int i;
  char ipaddr[HOSTIPLEN + 1];

  for (i = 0; i < irc_nscount; i++)
  {
    getnameinfo((struct sockaddr *)&(irc_nsaddr_list[i]),
                irc_nsaddr_list[i].ss_len, ipaddr,
                sizeof(ipaddr), NULL, 0, NI_NUMERICHOST);
    sendto_one(source_p, form_str(RPL_STATSALINE),
               me.name, source_p->name, ipaddr);
  }
}
