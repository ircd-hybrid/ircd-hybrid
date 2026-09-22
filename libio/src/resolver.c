/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file resolver.c
 * @brief Asynchronous DNS resolver implementation.
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
#include "dns.h"
#include "fdlist.h"
#include "io_string.h"
#include "io_time.h"
#include "list.h"
#include "memory.h"
#include "resolver.h"
#include "resolver_config.h"
#include "rng_mt.h"

enum
{
  RESOLVER_UDP_MESSAGE_CAPACITY = 1024,
  RESOLVER_INITIAL_TIMEOUT = 4,
  RESOLVER_MAX_ROUNDS = 2,
};

enum resolver_nameserver_state
{
  RESOLVER_NAMESERVER_STATE_UNQUERIED = 0,
  RESOLVER_NAMESERVER_STATE_QUERIED,
  RESOLVER_NAMESERVER_STATE_FAILED
};

struct resolver_socket
{
  int family;
  const char *description;
  fde_t *fde;
};

struct resolver_request
{
  list_node_t node;
  uint16_t transaction_id;
  uint16_t query_type;
  size_t nameserver_index;
  unsigned int round_index;
  uint64_t config_generation;
  enum resolver_nameserver_state nameserver_states[RESOLVER_CONFIG_NAMESERVER_CAPACITY];
  uintmax_t last_sent_at;
  uintmax_t timeout_interval;
  struct io_addr addr;
  char name[DNS_NAME_TEXT_CAPACITY];
  size_t name_length;
  resolver_callback_fn callback;
  void *callback_ctx;
};

static struct resolver_socket resolver_sockets[] =
{
  { .family = AF_INET, .description = "IPv4 UDP resolver socket" },
  { .family = AF_INET6, .description = "IPv6 UDP resolver socket" }
};

static struct resolver_config resolver_config;
static uint64_t resolver_config_generation;
static list_t request_list;

static void _resolver_read_reply(fde_t *, void *);

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
_resolver_send_packet(const unsigned char *packet, size_t packet_length, size_t nameserver_index)
{
  assert(packet);
  assert(packet_length > 0);
  assert(resolver_config.nameserver_count > 0);
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));
  assert(nameserver_index < resolver_config.nameserver_count);

  const struct io_addr *const nameserver = &resolver_config.nameservers[nameserver_index];
  const struct resolver_socket *const socket =
    _resolver_socket_find_by_family(address_get_family(nameserver));
  if (socket == NULL || socket->fde == NULL)
    return false;

  ssize_t bytes_sent;
  do
    bytes_sent = sendto(socket->fde->fd, packet, packet_length, 0,
                        (const struct sockaddr *)&nameserver->ss,
                        address_get_sockaddr_length(nameserver));
  while (bytes_sent == -1 && errno == EINTR);

  return bytes_sent >= 0 && (size_t)bytes_sent == packet_length;
}

static bool
_resolver_nameserver_find_index_by_source(const struct resolver_socket *socket, const struct io_addr *source,
                                          size_t *nameserver_index)
{
  assert(socket);
  assert(source);
  assert(nameserver_index);
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));

  if (address_get_family(source) != socket->family)
    return false;

  for (size_t i = 0; i < resolver_config.nameserver_count; ++i)
  {
    if (!address_equal_with_port(source, &resolver_config.nameservers[i]))
      continue;

    *nameserver_index = i;
    return true;
  }

  return false;
}

static struct resolver_request *
_resolver_request_create(resolver_callback_fn callback, void *callback_ctx)
{
  assert(callback);

  struct resolver_request *const request = io_calloc(sizeof(*request));
  request->callback = callback;
  request->callback_ctx = callback_ctx;

  return request;
}

static void
_resolver_request_destroy(struct resolver_request *request)
{
  list_remove(&request->node, &request_list);
  io_free(request);
}

static struct resolver_request *
_resolver_request_find_by_transaction_id(uint16_t transaction_id)
{
  list_node_t *node;

  LIST_FOREACH(node, request_list.head)
  {
    struct resolver_request *const request = node->data;
    if (request->transaction_id == transaction_id)
      return request;
  }

  return NULL;
}

static bool
_resolver_transaction_id_generate(uint16_t *transaction_id)
{
  assert(transaction_id);

  const uint16_t first = (uint16_t)genrand_int32();

  for (uint32_t offset = 0; offset <= UINT16_MAX; ++offset)
  {
    const uint16_t candidate = (uint16_t)(first + offset);
    if (_resolver_request_find_by_transaction_id(candidate) == NULL)
    {
      *transaction_id = candidate;
      return true;
    }
  }

  return false;
}

static uint16_t
_resolver_query_type_from_family(int family)
{
  switch (family)
  {
    case AF_INET:
      return DNS_TYPE_A;
    case AF_INET6:
      return DNS_TYPE_AAAA;
    default:
      assert(!"unsupported address family");
      return 0;
  }
}

static bool
_resolver_request_submit(struct resolver_request *request, const char *name,
                         size_t start_index, unsigned int round_index, uintmax_t timeout_interval)
{
  assert(request);
  assert(name);
  assert(request->query_type == DNS_TYPE_A ||
         request->query_type == DNS_TYPE_AAAA ||
         request->query_type == DNS_TYPE_PTR);
  assert(resolver_config.nameserver_count > 0);
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));
  assert(start_index < resolver_config.nameserver_count);
  assert(round_index < RESOLVER_MAX_ROUNDS);
  assert(timeout_interval >= RESOLVER_INITIAL_TIMEOUT);

  const struct dns_query query =
  {
    .name = name,
    .transaction_id = request->transaction_id,
    .type = request->query_type,
    .class = DNS_CLASS_IN,
    .recursion_desired = true
  };

  unsigned char packet[DNS_QUERY_WIRE_MAX_LENGTH];
  size_t packet_length;
  if (!dns_query_encode(&query, packet, sizeof(packet), &packet_length))
    return false;

  for (size_t i = start_index; i < resolver_config.nameserver_count; ++i)
  {
    if (request->nameserver_states[i] == RESOLVER_NAMESERVER_STATE_FAILED ||
        !_resolver_send_packet(packet, packet_length, i))
      continue;

    request->nameserver_index = i;
    request->nameserver_states[i] = RESOLVER_NAMESERVER_STATE_QUERIED;
    request->round_index = round_index;
    request->config_generation = resolver_config_generation;
    request->last_sent_at = io_time_get(IO_TIME_MONOTONIC_SEC);
    request->timeout_interval = timeout_interval;
    return true;
  }

  return false;
}

static bool
_resolver_request_start(struct resolver_request *request, const char *name)
{
  assert(request);
  assert(name);

  if (!_resolver_transaction_id_generate(&request->transaction_id) ||
      !_resolver_request_submit(request, name, 0, 0, RESOLVER_INITIAL_TIMEOUT))
  {
    io_free(request);
    return false;
  }

  list_add(request, &request->node, &request_list);
  return true;
}

static bool
_resolver_query_name(resolver_callback_fn callback, void *callback_ctx, const char *name, uint16_t query_type)
{
  assert(callback);
  assert(name);
  assert(query_type == DNS_TYPE_A || query_type == DNS_TYPE_AAAA);

  struct resolver_request *const request = _resolver_request_create(callback, callback_ctx);
  request->query_type = query_type;
  request->name_length = strlcpy(request->name, name, sizeof(request->name));

  if (request->name_length >= sizeof(request->name))
  {
    io_free(request);
    return false;
  }

  return _resolver_request_start(request, request->name);
}

static bool
_resolver_query_addr(resolver_callback_fn callback, void *callback_ctx, const struct io_addr *addr)
{
  assert(callback);
  assert(addr);
  assert(address_is_ipv4(addr) || address_is_ipv6(addr));

  char reverse_name[ADDRESS_REVERSE_NAME_BUFSIZE];
  if (!address_to_reverse_name(addr, reverse_name, sizeof(reverse_name)))
    return false;

  struct resolver_request *const request = _resolver_request_create(callback, callback_ctx);
  request->query_type = DNS_TYPE_PTR;
  address_copy(&request->addr, addr);

  return _resolver_request_start(request, reverse_name);
}

static bool
_resolver_request_retry(struct resolver_request *request)
{
  assert(request);
  assert(request->round_index < RESOLVER_MAX_ROUNDS);
  assert(resolver_config.nameserver_count > 0);
  assert(resolver_config.nameserver_count <= IO_ARRAY_LENGTH(resolver_config.nameservers));

  size_t next_nameserver_index;
  unsigned int round_index = request->round_index;
  uintmax_t timeout_interval = request->timeout_interval;

  if (request->config_generation != resolver_config_generation ||
      request->nameserver_index >= resolver_config.nameserver_count)
  {
    for (size_t i = 0; i < IO_ARRAY_LENGTH(request->nameserver_states); ++i)
      request->nameserver_states[i] = RESOLVER_NAMESERVER_STATE_UNQUERIED;

    next_nameserver_index = 0;
  }
  else if (request->nameserver_index + 1 < resolver_config.nameserver_count)
  {
    next_nameserver_index = request->nameserver_index + 1;
  }
  else if (++round_index < RESOLVER_MAX_ROUNDS)
  {
    next_nameserver_index = 0;
    timeout_interval *= 2;
  }
  else
    return false;

  char reverse_name[ADDRESS_REVERSE_NAME_BUFSIZE];
  const char *name;

  switch (request->query_type)
  {
    case DNS_TYPE_PTR:
      if (!address_to_reverse_name(&request->addr, reverse_name, sizeof(reverse_name)))
        return false;

      name = reverse_name;
      break;

    case DNS_TYPE_A:
    case DNS_TYPE_AAAA:
      name = request->name;
      break;

    default:
      assert(!"unsupported resolver query type");
      return false;
  }

  while (round_index < RESOLVER_MAX_ROUNDS)
  {
    if (_resolver_request_submit(request, name, next_nameserver_index, round_index, timeout_interval))
      return true;

    if (++round_index >= RESOLVER_MAX_ROUNDS)
      break;

    next_nameserver_index = 0;
    timeout_interval *= 2;
  }

  return false;
}

static void
_resolver_request_mark_nameserver_failed(struct resolver_request *request, size_t nameserver_index)
{
  assert(request);
  assert(request->config_generation == resolver_config_generation);
  assert(nameserver_index < resolver_config.nameserver_count);
  assert(request->nameserver_states[nameserver_index] != RESOLVER_NAMESERVER_STATE_UNQUERIED);

  request->nameserver_states[nameserver_index] = RESOLVER_NAMESERVER_STATE_FAILED;
}

static bool
_resolver_response_code_is_nameserver_failure(uint16_t response_code)
{
  return response_code != DNS_RESPONSE_CODE_NOERROR &&
         response_code != DNS_RESPONSE_CODE_NXDOMAIN;
}

static bool
_resolver_process_answer(struct resolver_request *request, struct dns_reader *reader,
                         const struct dns_header *header)
{
  assert(request);
  assert(reader);
  assert(header);

  for (uint16_t i = 0; i < header->question_count; ++i)
  {
    struct dns_question question;
    if (!dns_reader_read_question(reader, &question))
      return false;
  }

  for (uint16_t i = 0; i < header->answer_count; ++i)
  {
    struct dns_record record;
    if (!dns_reader_read_record(reader, &record))
      return false;

    if (record.class != DNS_CLASS_IN)
      continue;

    switch (record.type)
    {
      case DNS_TYPE_A:
      case DNS_TYPE_AAAA:
      {
        if (request->query_type != record.type)
          continue;

        const int family = record.type == DNS_TYPE_A ? AF_INET : AF_INET6;
        const unsigned char *const rdata = reader->packet.data + record.rdata.offset;

        return address_from_bytes(&request->addr, family, rdata, record.rdata.length);
      }

      case DNS_TYPE_PTR:
        if (request->query_type != record.type)
          continue;

        return dns_name_decode(&reader->packet, record.rdata,
                               request->name, sizeof(request->name), &request->name_length);

      case DNS_TYPE_CNAME:
      {
        char cname[DNS_NAME_TEXT_CAPACITY];
        size_t cname_length;

        if (!dns_name_decode(&reader->packet, record.rdata, cname, sizeof(cname), &cname_length))
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

  unsigned char packet[RESOLVER_UDP_MESSAGE_CAPACITY];

  while (true)
  {
    struct io_addr source = { 0 };
    socklen_t source_length = sizeof(source.ss);

    ssize_t bytes_received;
    do
      bytes_received = recvfrom(fde->fd, packet, sizeof(packet), 0,
                                (struct sockaddr *)&source.ss, &source_length);
    while (bytes_received == -1 && errno == EINTR);

    if (bytes_received == -1)
      break;

    const size_t packet_length = (size_t)bytes_received;
    if (packet_length < DNS_HEADER_WIRE_SIZE)
      continue;

    size_t source_nameserver_index;
    if (!_resolver_nameserver_find_index_by_source(socket, &source, &source_nameserver_index))
      continue;

    struct dns_reader reader;
    dns_reader_init(&reader, packet, packet_length);

    struct dns_header header;
    if (!dns_reader_read_header(&reader, &header) ||
        !dns_header_is_response(&header) || dns_header_get_opcode(&header) != DNS_OPCODE_QUERY)
      continue;

    struct resolver_request *const request =
      _resolver_request_find_by_transaction_id(header.transaction_id);
    if (request == NULL)
      continue;

    const bool source_nameserver_was_queried =
      request->config_generation == resolver_config_generation &&
      request->nameserver_states[source_nameserver_index] != RESOLVER_NAMESERVER_STATE_UNQUERIED;
    const bool source_nameserver_is_current =
      source_nameserver_was_queried && source_nameserver_index == request->nameserver_index;

    const uint16_t response_code = dns_header_get_response_code(&header);
    if (dns_header_is_truncated(&header) ||
        _resolver_response_code_is_nameserver_failure(response_code))
    {
      if (!source_nameserver_was_queried)
        continue;

      _resolver_request_mark_nameserver_failed(request, source_nameserver_index);

      if (!source_nameserver_is_current || _resolver_request_retry(request))
        continue;

      request->callback(request->callback_ctx, NULL, NULL, 0);
      _resolver_request_destroy(request);
      continue;
    }

    if (response_code != DNS_RESPONSE_CODE_NOERROR || header.answer_count == 0)
    {
      request->callback(request->callback_ctx, NULL, NULL, 0);
      _resolver_request_destroy(request);
      continue;
    }

    if (!_resolver_process_answer(request, &reader, &header))
    {
      if (!source_nameserver_is_current)
        continue;

      if (_resolver_request_retry(request))
        continue;

      request->callback(request->callback_ctx, NULL, NULL, 0);
      _resolver_request_destroy(request);
      continue;
    }

    if (request->query_type == DNS_TYPE_PTR)
    {
      if (request->name_length == 0)
      {
        request->callback(request->callback_ctx, NULL, NULL, 0);
        _resolver_request_destroy(request);
        continue;
      }

      resolver_callback_fn callback = request->callback;
      void *const callback_ctx = request->callback_ctx;
      const bool submitted =
        resolver_lookup_name(callback, callback_ctx, request->name, address_get_family(&request->addr));

      _resolver_request_destroy(request);

      if (!submitted)
        callback(callback_ctx, NULL, NULL, 0);
    }
    else
    {
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
    assert(request->round_index < RESOLVER_MAX_ROUNDS);

    const uintmax_t deadline = request->last_sent_at + request->timeout_interval;
    if (now < deadline)
      continue;

    if (!_resolver_request_retry(request))
    {
      request->callback(request->callback_ctx, NULL, NULL, 0);
      _resolver_request_destroy(request);
    }
  }
}

static bool
_resolver_config_update(void)
{
  struct resolver_config candidate;

  if (!resolver_config_load(&candidate))
    return false;

  if (!_resolver_socket_reconfigure(&candidate))
    return false;

  resolver_config = candidate;
  ++resolver_config_generation;
  return true;
}

bool
resolver_init(event_manager_t manager)
{
  if (!_resolver_config_update())
    return false;

  event_handle_t event_resolver_timeout =
    event_create(manager, "_resolver_process_timeouts", _resolver_process_timeouts, 1000, false, NULL, NULL);
  event_set_priority(event_resolver_timeout, 1);
  event_schedule(event_resolver_timeout);
  return true;
}

bool
resolver_reload(void)
{
  return _resolver_config_update();
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
resolver_lookup_name(resolver_callback_fn callback, void *callback_ctx, const char *name, int family)
{
  assert(callback);
  assert(name);
  assert(family == AF_INET || family == AF_INET6);

  const uint16_t query_type = _resolver_query_type_from_family(family);
  return _resolver_query_name(callback, callback_ctx, name, query_type);
}

bool
resolver_lookup_addr(resolver_callback_fn callback, void *callback_ctx, const struct io_addr *addr)
{
  assert(callback);
  assert(addr);
  assert(address_is_ipv4(addr) || address_is_ipv6(addr));

  return _resolver_query_addr(callback, callback_ctx, addr);
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
