/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file resolver.c
 * \brief ircd resolver functions
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

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "address.h"
#include "comm.h"
#include "fdlist.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "resolver.h"
#include "resolver_config.h"
#include "reslib.h"
#include "rng_mt.h"

_Static_assert(CHAR_BIT == 8, "DNS resolver requires 8-bit bytes");

struct resolver_socket
{
  int family;
  const char *description;
  fde_t *fde;
};

static void _resolver_read_reply(fde_t *, void *);

enum
{
  RESOLVER_MAX_ATTEMPTS = 2
};

#define RESOLVER_MESSAGE_BUFFER_SIZE 1024

#define DNS_RR_TYPE_SIZE          ((size_t)2)
#define DNS_RR_CLASS_SIZE         ((size_t)2)
#define DNS_RR_TTL_SIZE           ((size_t)4)
#define DNS_RR_RDLENGTH_SIZE      ((size_t)2)
#define DNS_RR_FIXED_FIELDS_SIZE \
  (DNS_RR_TYPE_SIZE +            \
   DNS_RR_CLASS_SIZE +           \
   DNS_RR_TTL_SIZE +             \
   DNS_RR_RDLENGTH_SIZE)

struct resolver_request
{
  list_node_t node;
  unsigned int id;
  unsigned int type;
  unsigned int attempt_count;
  uintmax_t last_sent_at;
  uintmax_t timeout;
  struct io_addr addr;
  char name[RFC1035_MAX_DOMAIN_LENGTH + 1];
  size_t name_length;
  resolver_callback_fnc callback;
  void *callback_ctx;
};

static struct resolver_socket resolver_sockets[] =
{
  { .family = AF_INET, .description = "IPv4 UDP resolver socket" },
  { .family = AF_INET6, .description = "IPv6 UDP resolver socket" }
};

static struct resolver_config resolver_config;
static list_t request_list;

static const struct resolver_socket *
_resolver_socket_find_by_family(int family)
{
  for (size_t i = 0; i < IO_ARRAY_LENGTH(resolver_sockets); ++i)
    if (resolver_sockets[i].family == family)
      return &resolver_sockets[i];

  return NULL;
}

static bool
_resolver_socket_open(struct resolver_socket *socket)
{
  assert(socket);

  if (socket->fde)
    return true;

  socket->fde = comm_socket_create(socket->family, SOCK_DGRAM, 0, socket->description);
  if (socket->fde == NULL)
    return false;

  comm_setselect(socket->fde, COMM_SELECT_READ, _resolver_read_reply, socket);
  return true;
}

static void
_resolver_socket_close(struct resolver_socket *socket)
{
  if (socket->fde == NULL)
    return;

  comm_socket_close(socket->fde);
  socket->fde = NULL;
}

static bool
_resolver_socket_reconfigure(const struct resolver_config *config)
{
  assert(config);
  assert(config->nameserver_count > 0);
  assert(config->nameserver_count <= IO_ARRAY_LENGTH(config->nameservers));

  bool opened[IO_ARRAY_LENGTH(resolver_sockets)] = { false };
  for (size_t i = 0; i < IO_ARRAY_LENGTH(resolver_sockets); ++i)
  {
    struct resolver_socket *const socket = &resolver_sockets[i];
    if (!resolver_config_has_family(config, socket->family) || socket->fde)
      continue;

    if (!_resolver_socket_open(socket))
    {
      for (size_t j = 0; j < IO_ARRAY_LENGTH(resolver_sockets); ++j)
      {
        if (opened[j])
          _resolver_socket_close(&resolver_sockets[j]);
      }

      return false;
    }

    opened[i] = true;
  }

  for (size_t i = 0; i < IO_ARRAY_LENGTH(resolver_sockets); ++i)
  {
    struct resolver_socket *const socket = &resolver_sockets[i];
    if (!resolver_config_has_family(config, socket->family))
      _resolver_socket_close(socket);
  }

  return true;
}

static bool
_resolver_source_is_configured_nameserver(const struct resolver_socket *socket, const struct io_addr *source)
{
  assert(socket);
  assert(source);

  if (address_get_family(source) != socket->family)
    return false;

  return resolver_config_contains_nameserver(&resolver_config, source);
}

static void
_resolver_request_destroy(struct resolver_request *request)
{
  list_remove(&request->node, &request_list);
  io_free(request);
}

static struct resolver_request *
_resolver_request_create(resolver_callback_fnc callback, void *callback_ctx)
{
  struct resolver_request *const request = io_calloc(sizeof(*request));
  request->last_sent_at = io_time_get(IO_TIME_MONOTONIC_SEC);
  request->timeout = 4;
  request->callback = callback;
  request->callback_ctx = callback_ctx;
  list_add(request, &request->node, &request_list);

  return request;
}

size_t
resolver_nameserver_count(void)
{
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));
  return resolver_config.nameserver_count;
}

bool
resolver_nameserver_get(size_t index, struct io_addr *nameserver)
{
  assert(nameserver);
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));

  if (index >= resolver_config.nameserver_count)
    return false;

  address_copy(nameserver, &resolver_config.nameservers[index]);
  return true;
}

bool
resolver_reload(void)
{
  struct resolver_config candidate;

  if (!resolver_config_load(&candidate))
    return false;

  if (!_resolver_socket_reconfigure(&candidate))
    return false;

  resolver_config = candidate;
  return true;
}

void
resolver_cancel_by_context(const void *callback_ctx)
{
  list_node_t *node, *node_next;

  LIST_FOREACH_SAFE(node, node_next, request_list.head)
  {
    struct resolver_request *const request = node->data;
    if (request->callback_ctx == callback_ctx)
      _resolver_request_destroy(request);
  }
}

static void
_resolver_send_packet(const unsigned char *msg, size_t packet_length, unsigned int max_nameservers)
{
  assert(msg);
  assert(packet_length > 0);
  assert(max_nameservers > 0);
  assert(resolver_config.nameserver_count > 0);
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));

  unsigned int nameservers_sent = 0;

  for (size_t i = 0; i < resolver_config.nameserver_count && nameservers_sent < max_nameservers; ++i)
  {
    const struct io_addr *const nameserver = &resolver_config.nameservers[i];

    const struct resolver_socket *const socket =
      _resolver_socket_find_by_family(address_get_family(nameserver));
    if (socket == NULL || socket->fde == NULL)
      continue;

    ssize_t bytes_sent;
    do
      bytes_sent = sendto(socket->fde->fd, msg, packet_length, 0,
                          (const struct sockaddr *)&nameserver->ss,
                          address_get_sockaddr_length(nameserver));
    while (bytes_sent == -1 && errno == EINTR);

    if (bytes_sent >= 0 && (size_t)bytes_sent == packet_length)
      ++nameservers_sent;
  }
}

static struct resolver_request *
_resolver_request_find_by_id(unsigned int transaction_id)
{
  list_node_t *node;

  LIST_FOREACH(node, request_list.head)
  {
    struct resolver_request *const request = node->data;
    if (request->id == transaction_id)
      return request;
  }

  return NULL;
}

static void
_resolver_query_send(const char *name, int query_class, int type, struct resolver_request *request)
{
  assert(request);
  assert(request->attempt_count < RESOLVER_MAX_ATTEMPTS);

  ++request->attempt_count;

  unsigned char packet[RESOLVER_MESSAGE_BUFFER_SIZE];

  const int packet_length = reslib_res_mkquery(name, query_class, type, packet, sizeof(packet));
  if (packet_length > 0)
  {
    HEADER *const header = (HEADER *)packet;

    /*
     * Generate an unique id.
     * NOTE: we don't have to worry about converting this to and from
     * network byte order, the nameserver does not interpret this value
     * and returns it unchanged.
     */
    do
      header->id = (header->id + genrand_int32()) & 0xFFFF;
    while (_resolver_request_find_by_id(header->id));

    request->id = header->id;

    _resolver_send_packet(packet, (size_t)packet_length, request->attempt_count);
  }
}

static void
_resolver_query_name(resolver_callback_fnc callback, void *callback_ctx, const char *name,
                     struct resolver_request *request, int type)
{
  char host_name[RFC1035_MAX_DOMAIN_LENGTH + 1];

  strlcpy(host_name, name, sizeof(host_name));

  if (request == NULL)
  {
    request = _resolver_request_create(callback, callback_ctx);
    request->type = type;
    request->name_length = strlcpy(request->name, host_name, sizeof(request->name));
  }

  request->type = type;
  _resolver_query_send(host_name, C_IN, type, request);
}

static void
_resolver_query_addr(resolver_callback_fnc callback, void *callback_ctx, const struct io_addr *addr,
                     struct resolver_request *request)
{
  assert(addr);
  assert(address_is_ipv4(addr) || address_is_ipv6(addr));

  char reverse_name[ADDRESS_REVERSE_NAME_BUFSIZE];
  if (!address_to_reverse_name(addr, reverse_name, sizeof(reverse_name)))
    return;

  if (request == NULL)
  {
    request = _resolver_request_create(callback, callback_ctx);
    request->type = T_PTR;
    address_copy(&request->addr, addr);
  }

  _resolver_query_send(reverse_name, C_IN, T_PTR, request);
}

static int
_resolver_query_type_from_family(int family)
{
  switch (family)
  {
    case AF_INET:
      return T_A;
    case AF_INET6:
      return T_AAAA;
    default:
      assert(!"unsupported address family");
      return 0;
  }
}

void
resolver_lookup_name(resolver_callback_fnc callback, void *callback_ctx, const char *name, int family)
{
  assert(callback);
  assert(name);
  assert(family == AF_INET || family == AF_INET6);

  const int query_type = _resolver_query_type_from_family(family);
  _resolver_query_name(callback, callback_ctx, name, NULL, query_type);
}

void
resolver_lookup_addr(resolver_callback_fnc callback, void *callback_ctx, const struct io_addr *addr)
{
  _resolver_query_addr(callback, callback_ctx, addr, NULL);
}

static void
_resolver_query_resend(struct resolver_request *request)
{
  switch (request->type)
  {
    case T_PTR:
      _resolver_query_addr(NULL, NULL, &request->addr, request);
      break;
    case T_A:
    case T_AAAA:
      _resolver_query_name(NULL, NULL, request->name, request, request->type);
      break;
    default:
      break;
  }
}

static bool
_resolver_packet_has_bytes(const unsigned char *cursor, const unsigned char *end, size_t length)
{
  assert(cursor);
  assert(end);

  if (cursor > end)
    return false;

  return length <= (size_t)(end - cursor);
}

static bool
_resolver_packet_skip_name(const unsigned char **cursor, const unsigned char *end)
{
  assert(cursor);
  assert(*cursor);
  assert(end);

  const int length = reslib_dn_skipname(*cursor, end);
  if (length <= 0 || !_resolver_packet_has_bytes(*cursor, end, (size_t)length))
    return false;

  *cursor += (size_t)length;
  return true;
}

static bool
_resolver_process_answer(struct resolver_request *request, const HEADER *header,
                         const unsigned char *packet, const unsigned char *packet_end)
{
  assert(request);
  assert(header);
  assert(packet);
  assert(packet_end);
  assert(packet <= packet_end);

  if (!_resolver_packet_has_bytes(packet, packet_end, HFIXEDSZ))
    return false;

  const unsigned char *cursor = packet + HFIXEDSZ;
  char hostname[sizeof(request->name)];

  for (unsigned int i = 0; i < header->qdcount; ++i)
  {
    if (!_resolver_packet_skip_name(&cursor, packet_end) ||
        !_resolver_packet_has_bytes(cursor, packet_end, QFIXEDSZ))
      return false;

    cursor += QFIXEDSZ;
  }

  for (unsigned int i = 0; i < header->ancount; ++i)
  {
    if (!_resolver_packet_skip_name(&cursor, packet_end) ||
        !_resolver_packet_has_bytes(cursor, packet_end, DNS_RR_FIXED_FIELDS_SIZE))
      return false;

    const uint16_t rr_type = reslib_ns_get16(cursor);
    cursor += DNS_RR_TYPE_SIZE;
    const uint16_t rr_class = reslib_ns_get16(cursor);
    cursor += DNS_RR_CLASS_SIZE;
    cursor += DNS_RR_TTL_SIZE;
    const uint16_t rdata_length = reslib_ns_get16(cursor);
    cursor += DNS_RR_RDLENGTH_SIZE;

    if (!_resolver_packet_has_bytes(cursor, packet_end, rdata_length))
      return false;

    const unsigned char *const rdata = cursor;
    const unsigned char *const rdata_end = rdata + rdata_length;
    cursor = rdata_end;

    if (rr_class != C_IN)
      continue;

    switch (rr_type)
    {
      case T_A:
      case T_AAAA:
        if (request->type != rr_type)
          continue;

        return address_from_bytes(&request->addr, rr_type == T_A ? AF_INET : AF_INET6, rdata, rdata_length);

      case T_PTR:
      {
        if (request->type != rr_type)
          continue;

        const int encoded_length = reslib_dn_skipname(rdata, rdata_end);
        if (encoded_length <= 0 || (size_t)encoded_length != rdata_length)
          return false;

        const int expanded_length =
          reslib_dn_expand(packet, packet_end, rdata, hostname, (int)sizeof(hostname));

        if (expanded_length != encoded_length)
          return false;

        request->name_length = strlcpy(request->name, hostname, sizeof(request->name));
        assert(request->name_length < sizeof(request->name));
        return true;
      }

      case T_CNAME:
      {
        const int encoded_length = reslib_dn_skipname(rdata, rdata_end);
        if (encoded_length <= 0 || (size_t)encoded_length != rdata_length)
          return false;

        continue;
      }

      default:
        continue;
    }
  }

  return false;
}

static void
_resolver_read_reply(fde_t *fde, void *data)
{
  struct resolver_socket *const socket = data;
  assert(socket);
  assert(socket->fde == fde);

  unsigned char packet[sizeof(HEADER) + RESOLVER_MESSAGE_BUFFER_SIZE];

  while (true)
  {
    struct io_addr addr = { 0 };
    socklen_t len = sizeof(addr.ss);

    ssize_t rc = recvfrom(fde->fd, packet, sizeof(packet), 0, (struct sockaddr *)&addr.ss, &len);
    if (rc == -1)
      break;

    if (rc <= (ssize_t)sizeof(HEADER))
      continue;

    /* Ignore replies from unconfigured sources. */
    if (!_resolver_source_is_configured_nameserver(socket, &addr))
      continue;

    /*
     * Convert DNS reply reader from Network byte order to CPU byte order.
     */
    HEADER *const header = (HEADER *)packet;
    header->ancount = ntohs(header->ancount);
    header->qdcount = ntohs(header->qdcount);
    header->nscount = ntohs(header->nscount);
    header->arcount = ntohs(header->arcount);

    /*
     * Response for an id which we have already received an answer for
     * just ignore this response.
     */
    struct resolver_request *const request = _resolver_request_find_by_id(header->id);
    if (request == NULL)
      continue;

    if (header->rcode != NO_ERRORS || header->ancount == 0)
    {
      /*
       * If a bad error was returned, stop here and don't send
       * any more (no retries_remaining granted).
       */
      request->callback(request->callback_ctx, NULL, NULL, 0);
      _resolver_request_destroy(request);
      continue;
    }

    /*
     * If this fails there was an error decoding the received packet.
     * We only give it one shot. If it fails, just leave the client
     * unresolved.
     */
    if (!_resolver_process_answer(request, header, packet, packet + rc))
    {
      request->callback(request->callback_ctx, NULL, NULL, 0);
      _resolver_request_destroy(request);
      continue;
    }

    if (request->type == T_PTR)
    {
      if (request->name_length == 0)
      {
        /*
         * Got a PTR response with no name, something bogus is happening
         * don't bother trying again, the client address doesn't resolve
         */
        request->callback(request->callback_ctx, NULL, NULL, 0);
        _resolver_request_destroy(request);
        continue;
      }

      /*
       * Lookup the 'authoritative' name that we were given for the ip#.
       */
      resolver_lookup_name(request->callback, request->callback_ctx,
                           request->name, address_get_family(&request->addr));
      _resolver_request_destroy(request);
    }
    else
    {
      /*
       * Got a name and address response, client resolved
       */
      request->callback(request->callback_ctx, &request->addr, request->name, request->name_length);
      _resolver_request_destroy(request);
    }
  }

  comm_setselect(fde, COMM_SELECT_READ, _resolver_read_reply, socket);
}

static void
_resolver_process_timeouts(void *unused)
{
  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, request_list.head)
  {
    struct resolver_request *const request = node->data;
    assert(request->attempt_count > 0);
    assert(request->attempt_count <= RESOLVER_MAX_ATTEMPTS);

    const uintmax_t timeout = request->last_sent_at + request->timeout;
    if (now >= timeout)
    {
      if (request->attempt_count >= RESOLVER_MAX_ATTEMPTS)
      {
        request->callback(request->callback_ctx, NULL, NULL, 0);
        _resolver_request_destroy(request);
      }
      else
      {
        request->last_sent_at = now;
        request->timeout += request->timeout;
        _resolver_query_resend(request);
      }
    }
  }
}

bool
resolver_init(event_manager_t manager)
{
  struct resolver_config candidate;

  if (!resolver_config_load(&candidate))
    return false;

  if (!_resolver_socket_reconfigure(&candidate))
    return false;

  resolver_config = candidate;

  event_handle_t event_resolver_timeout =
    event_create(manager, "_resolver_process_timeouts", _resolver_process_timeouts, 1000, false, NULL, NULL);
  event_set_priority(event_resolver_timeout, 1);
  event_schedule(event_resolver_timeout);
  return true;
}
