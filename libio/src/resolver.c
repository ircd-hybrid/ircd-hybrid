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
#include <string.h>
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
  RESOLVER_MAX_PENDING_REQUESTS = 4096
};

_Static_assert(RESOLVER_MAX_PENDING_REQUESTS <= UINT16_MAX + 1U,
               "resolver request limit exceeds transaction ID space");

enum resolver_nameserver_state
{
  RESOLVER_NAMESERVER_STATE_UNQUERIED = 0,
  RESOLVER_NAMESERVER_STATE_QUERIED,
  RESOLVER_NAMESERVER_STATE_FAILED
};

enum resolver_response_result
{
  RESOLVER_RESPONSE_RESULT_MATCH,
  RESOLVER_RESPONSE_RESULT_NO_MATCH,
  RESOLVER_RESPONSE_RESULT_MALFORMED
};

enum resolver_completion_type
{
  RESOLVER_COMPLETION_TYPE_NAME,
  RESOLVER_COMPLETION_TYPE_ADDRESSES
};

union resolver_callback
{
  resolver_lookup_addr_callback_fn lookup_addr;
  resolver_lookup_name_callback_fn lookup_name;
};

union resolver_result_data
{
  struct
  {
    char value[DNS_NAME_TEXT_CAPACITY];
    size_t length;
  } name;

  struct
  {
    struct io_addr *items;
    size_t count;
  } addresses;
};

struct resolver_completion
{
  enum resolver_completion_type type;
  void *callback_ctx;
  union resolver_callback callback;
  union resolver_result_data result;
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
  char query_name[DNS_NAME_TEXT_CAPACITY];
  size_t query_name_length;

  union resolver_callback callback;
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
static struct resolver_request *requests_by_transaction_id[UINT16_MAX + 1U];
static size_t request_count;

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
_resolver_request_create(void *callback_ctx)
{
  assert(request_count <= RESOLVER_MAX_PENDING_REQUESTS);

  if (request_count == RESOLVER_MAX_PENDING_REQUESTS)
    return NULL;

  struct resolver_request *const request = io_calloc(sizeof(*request));
  request->callback_ctx = callback_ctx;
  return request;
}

static void
_resolver_request_publish(struct resolver_request *request)
{
  assert(request);
  assert(request_count < RESOLVER_MAX_PENDING_REQUESTS);
  assert(requests_by_transaction_id[request->transaction_id] == NULL);

  requests_by_transaction_id[request->transaction_id] = request;
  list_add(request, &request->node, &request_list);
  ++request_count;
}

static void
_resolver_request_destroy(struct resolver_request *request)
{
  assert(request);
  assert(request_count > 0);
  assert(requests_by_transaction_id[request->transaction_id] == request);

  requests_by_transaction_id[request->transaction_id] = NULL;
  list_remove(&request->node, &request_list);
  --request_count;
  io_free(request);
}

static void
_resolver_request_finalize_failure(struct resolver_request *request, struct resolver_completion *completion)
{
  assert(request);
  assert(completion);

  completion->callback_ctx = request->callback_ctx;

  switch (request->query_type)
  {
    case DNS_TYPE_PTR:
      assert(request->callback.lookup_addr);
      completion->type = RESOLVER_COMPLETION_TYPE_NAME;
      completion->callback.lookup_addr = request->callback.lookup_addr;
      completion->result.name.value[0] = '\0';
      completion->result.name.length = 0;
      break;

    case DNS_TYPE_A:
    case DNS_TYPE_AAAA:
      assert(request->callback.lookup_name);
      completion->type = RESOLVER_COMPLETION_TYPE_ADDRESSES;
      completion->callback.lookup_name = request->callback.lookup_name;
      completion->result.addresses.items = NULL;
      completion->result.addresses.count = 0;
      break;

    default:
      assert(!"unsupported resolver query type");
  }

  _resolver_request_destroy(request);
}

static void
_resolver_request_finalize_name(struct resolver_request *request, struct resolver_completion *completion,
                                const char *name, size_t name_length)
{
  assert(request);
  assert(completion);
  assert(request->query_type == DNS_TYPE_PTR);
  assert(request->callback.lookup_addr);
  assert(name_length > 0);
  assert(name_length < sizeof(completion->result.name.value));
  assert(name[name_length] == '\0');

  completion->type = RESOLVER_COMPLETION_TYPE_NAME;
  completion->callback_ctx = request->callback_ctx;
  completion->callback.lookup_addr = request->callback.lookup_addr;
  memcpy(completion->result.name.value, name, name_length + 1);
  completion->result.name.length = name_length;

  _resolver_request_destroy(request);
}

static void
_resolver_request_finalize_addresses(struct resolver_request *request, struct resolver_completion *completion,
                                     struct io_addr *addresses, size_t address_count)
{
  assert(request);
  assert(completion);
  assert(request->query_type == DNS_TYPE_A || request->query_type == DNS_TYPE_AAAA);
  assert(request->callback.lookup_name);
  assert(addresses);
  assert(address_count > 0);

  completion->type = RESOLVER_COMPLETION_TYPE_ADDRESSES;
  completion->callback_ctx = request->callback_ctx;
  completion->callback.lookup_name = request->callback.lookup_name;
  completion->result.addresses.items = addresses;
  completion->result.addresses.count = address_count;

  _resolver_request_destroy(request);
}

static struct resolver_request *
_resolver_request_find_by_transaction_id(uint16_t transaction_id)
{
  return requests_by_transaction_id[transaction_id];
}

static bool
_resolver_transaction_id_generate(uint16_t *transaction_id)
{
  assert(transaction_id);
  assert(request_count < RESOLVER_MAX_PENDING_REQUESTS);

  const uint16_t first = (uint16_t)genrand_int32();

  for (size_t offset = 0; offset <= request_count; ++offset)
  {
    const uint16_t candidate = (uint16_t)(first + offset);
    if (_resolver_request_find_by_transaction_id(candidate))
      continue;

    *transaction_id = candidate;
    return true;
  }

  assert(!"resolver transaction ID registry is inconsistent");
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
_resolver_request_submit(struct resolver_request *request,
                         size_t start_index, unsigned int round_index, uintmax_t timeout_interval)
{
  assert(request);
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
    .name = request->query_name,
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
_resolver_request_set_query_name(struct resolver_request *request, const char *name)
{
  assert(request);
  assert(name);

  request->query_name_length = strlcpy(request->query_name, name, sizeof(request->query_name));
  return request->query_name_length < sizeof(request->query_name);
}

static bool
_resolver_request_start(struct resolver_request *request)
{
  assert(request);
  assert(request->query_name_length < sizeof(request->query_name));
  assert(request->query_name[request->query_name_length] == '\0');

  if (!_resolver_transaction_id_generate(&request->transaction_id) ||
      !_resolver_request_submit(request, 0, 0, RESOLVER_INITIAL_TIMEOUT))
  {
    io_free(request);
    return false;
  }

  _resolver_request_publish(request);
  return true;
}

static bool
_resolver_query_name(resolver_lookup_name_callback_fn callback, void *callback_ctx,
                     const char *name, uint16_t query_type)
{
  assert(callback);
  assert(name);
  assert(query_type == DNS_TYPE_A || query_type == DNS_TYPE_AAAA);

  struct resolver_request *const request = _resolver_request_create(callback_ctx);
  if (request == NULL)
    return false;

  request->query_type = query_type;
  request->callback.lookup_name = callback;

  if (!_resolver_request_set_query_name(request, name))
  {
    io_free(request);
    return false;
  }

  return _resolver_request_start(request);
}

static bool
_resolver_query_addr(resolver_lookup_addr_callback_fn callback, void *callback_ctx, const struct io_addr *addr)
{
  assert(callback);
  assert(addr);
  assert(address_is_ipv4(addr) || address_is_ipv6(addr));

  char reverse_name[ADDRESS_REVERSE_NAME_BUFSIZE];
  if (!address_to_reverse_name(addr, reverse_name, sizeof(reverse_name)))
    return false;

  struct resolver_request *const request = _resolver_request_create(callback_ctx);
  if (request == NULL)
    return false;

  request->query_type = DNS_TYPE_PTR;
  request->callback.lookup_addr = callback;

  if (!_resolver_request_set_query_name(request, reverse_name))
  {
    io_free(request);
    return false;
  }

  return _resolver_request_start(request);
}

static bool
_resolver_request_retry(struct resolver_request *request)
{
  assert(request);
  assert(request->round_index < RESOLVER_MAX_ROUNDS);
  assert(request->query_name_length < sizeof(request->query_name));
  assert(request->query_name[request->query_name_length] == '\0');
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

  while (round_index < RESOLVER_MAX_ROUNDS)
  {
    if (_resolver_request_submit(request, next_nameserver_index, round_index, timeout_interval))
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
_resolver_question_matches_request(const struct resolver_request *request,
                                   const struct dns_message_view *packet,
                                   const struct dns_question *question)
{
  assert(request);
  assert(packet);
  assert(question);
  assert(request->query_type == DNS_TYPE_A ||
         request->query_type == DNS_TYPE_AAAA ||
         request->query_type == DNS_TYPE_PTR);
  assert(request->query_name_length < sizeof(request->query_name));
  assert(request->query_name[request->query_name_length] == '\0');

  return question->type == request->query_type &&
         question->class == DNS_CLASS_IN &&
         dns_name_equal_text(packet, question->name, request->query_name);
}

static bool
_resolver_validate_response_records(const struct resolver_request *request,
                                    struct dns_reader *reader,
                                    const struct dns_header *header)
{
  assert(request);
  assert(reader);
  assert(header);

  for (uint16_t i = 0; i < header->answer_count; ++i)
  {
    struct dns_record record;
    if (!dns_reader_read_record(reader, &record))
      return false;

    if (record.class != DNS_CLASS_IN)
      continue;

    if (record.type == DNS_TYPE_CNAME)
    {
      char name[DNS_NAME_TEXT_CAPACITY];
      size_t name_length;

      if (!dns_name_decode(&reader->packet, record.rdata, name, sizeof(name), &name_length))
        return false;
      continue;
    }

    if (record.type != request->query_type)
      continue;

    switch (request->query_type)
    {
      case DNS_TYPE_A:
      case DNS_TYPE_AAAA:
      {
        const int family = request->query_type == DNS_TYPE_A ? AF_INET : AF_INET6;
        const unsigned char *const rdata = reader->packet.data + record.rdata.offset;
        struct io_addr addr;

        if (!address_from_bytes(&addr, family, rdata, record.rdata.length))
          return false;
        break;
      }

      case DNS_TYPE_PTR:
      {
        char name[DNS_NAME_TEXT_CAPACITY];
        size_t name_length;

        if (!dns_name_decode(&reader->packet, record.rdata, name, sizeof(name), &name_length))
          return false;
        break;
      }

      default:
        assert(!"unsupported resolver query type");
        return false;
    }
  }

  const size_t remaining_record_count =
    (size_t)header->authority_count + (size_t)header->additional_count;

  for (size_t i = 0; i < remaining_record_count; ++i)
  {
    struct dns_record record;
    if (!dns_reader_read_record(reader, &record))
      return false;
  }

  return reader->offset == reader->packet.length;
}

static bool
_resolver_follow_cname_chain(const struct resolver_request *request,
                             const struct dns_reader *answers,
                             const struct dns_header *header,
                             char *terminal_name, size_t terminal_name_capacity)
{
  assert(request);
  assert(answers);
  assert(header);
  assert(terminal_name);
  assert(terminal_name_capacity > 0);

  char current_name[DNS_NAME_TEXT_CAPACITY];
  memcpy(current_name, request->query_name, request->query_name_length + 1);

  for (size_t hop = 0; hop <= header->answer_count; ++hop)
  {
    struct dns_reader reader = *answers;
    char cname_target[DNS_NAME_TEXT_CAPACITY];
    size_t cname_target_length = 0;
    bool cname_found = false;
    bool terminal_record_found = false;

    for (uint16_t i = 0; i < header->answer_count; ++i)
    {
      struct dns_record record;
      if (!dns_reader_read_record(&reader, &record))
        return false;

      if (record.class != DNS_CLASS_IN ||
          !dns_name_equal_text(&reader.packet, record.name, current_name))
        continue;

      if (record.type == request->query_type)
        terminal_record_found = true;

      if (record.type != DNS_TYPE_CNAME)
        continue;

      char target[DNS_NAME_TEXT_CAPACITY];
      size_t target_length;
      if (!dns_name_decode(&reader.packet, record.rdata, target, sizeof(target), &target_length))
        return false;

      if (!cname_found)
      {
        memcpy(cname_target, target, target_length + 1);
        cname_target_length = target_length;
        cname_found = true;
      }
      else if (!dns_name_equal_text(&reader.packet, record.rdata, cname_target))
        return false;
    }

    if (!cname_found)
    {
      const size_t length = strlen(current_name);
      if (length >= terminal_name_capacity)
        return false;

      memcpy(terminal_name, current_name, length + 1);
      return true;
    }

    if (terminal_record_found || hop == header->answer_count)
      return false;

    memcpy(current_name, cname_target, cname_target_length + 1);
  }

  assert(!"unreachable CNAME-chain state");
  return false;
}

static enum resolver_response_result
_resolver_collect_addresses(const struct resolver_request *request,
                            const struct dns_reader *answers,
                            const struct dns_header *header,
                            const char *terminal_name,
                            struct io_addr **addresses_out, size_t *address_count_out)
{
  assert(request);
  assert(answers);
  assert(header);
  assert(terminal_name);
  assert(addresses_out);
  assert(address_count_out);
  assert(request->query_type == DNS_TYPE_A || request->query_type == DNS_TYPE_AAAA);

  size_t matching_record_count = 0;
  struct dns_reader reader = *answers;

  for (uint16_t i = 0; i < header->answer_count; ++i)
  {
    struct dns_record record;
    if (!dns_reader_read_record(&reader, &record))
      return RESOLVER_RESPONSE_RESULT_MALFORMED;

    if (record.class == DNS_CLASS_IN && record.type == request->query_type &&
        dns_name_equal_text(&reader.packet, record.name, terminal_name))
      ++matching_record_count;
  }

  if (matching_record_count == 0)
    return RESOLVER_RESPONSE_RESULT_NO_MATCH;

  struct io_addr *const addresses = io_calloc(matching_record_count * sizeof(*addresses));
  size_t address_count = 0;
  reader = *answers;

  for (uint16_t i = 0; i < header->answer_count; ++i)
  {
    struct dns_record record;
    if (!dns_reader_read_record(&reader, &record))
    {
      io_free(addresses);
      return RESOLVER_RESPONSE_RESULT_MALFORMED;
    }

    if (record.class != DNS_CLASS_IN || record.type != request->query_type ||
        !dns_name_equal_text(&reader.packet, record.name, terminal_name))
      continue;

    const int family = request->query_type == DNS_TYPE_A ? AF_INET : AF_INET6;
    const unsigned char *const rdata = reader.packet.data + record.rdata.offset;
    struct io_addr address;

    if (!address_from_bytes(&address, family, rdata, record.rdata.length))
    {
      io_free(addresses);
      return RESOLVER_RESPONSE_RESULT_MALFORMED;
    }

    bool duplicate = false;
    for (size_t j = 0; j < address_count; ++j)
    {
      if (address_equal(&addresses[j], &address))
      {
        duplicate = true;
        break;
      }
    }

    if (!duplicate)
      address_copy(&addresses[address_count++], &address);
  }

  assert(address_count > 0);
  *addresses_out = addresses;
  *address_count_out = address_count;
  return RESOLVER_RESPONSE_RESULT_MATCH;
}

static enum resolver_response_result
_resolver_find_ptr_name(const struct resolver_request *request,
                        const struct dns_reader *answers,
                        const struct dns_header *header,
                        const char *terminal_name,
                        char *name, size_t name_capacity, size_t *name_length)
{
  assert(request);
  assert(answers);
  assert(header);
  assert(terminal_name);
  assert(name);
  assert(name_capacity > 0);
  assert(name_length);
  assert(request->query_type == DNS_TYPE_PTR);

  struct dns_reader reader = *answers;

  for (uint16_t i = 0; i < header->answer_count; ++i)
  {
    struct dns_record record;
    if (!dns_reader_read_record(&reader, &record))
      return RESOLVER_RESPONSE_RESULT_MALFORMED;

    if (record.class != DNS_CLASS_IN || record.type != DNS_TYPE_PTR ||
        !dns_name_equal_text(&reader.packet, record.name, terminal_name))
      continue;

    size_t decoded_length;
    if (!dns_name_decode(&reader.packet, record.rdata, name, name_capacity, &decoded_length))
      return RESOLVER_RESPONSE_RESULT_MALFORMED;

    if (decoded_length == 0)
      continue;

    *name_length = decoded_length;
    return RESOLVER_RESPONSE_RESULT_MATCH;
  }

  return RESOLVER_RESPONSE_RESULT_NO_MATCH;
}

static enum resolver_response_result
_resolver_process_response(const struct resolver_request *request, struct dns_reader *reader,
                           const struct dns_header *header, union resolver_result_data *result_data)
{
  assert(request);
  assert(reader);
  assert(header);
  assert(result_data);
  assert(request->query_type == DNS_TYPE_A ||
         request->query_type == DNS_TYPE_AAAA ||
         request->query_type == DNS_TYPE_PTR);

  const uint16_t response_code = dns_header_get_response_code(header);
  assert(response_code == DNS_RESPONSE_CODE_NOERROR ||
         response_code == DNS_RESPONSE_CODE_NXDOMAIN);
  assert(header->question_count == 1);

  const struct dns_reader answers = *reader;
  if (!_resolver_validate_response_records(request, reader, header))
    return RESOLVER_RESPONSE_RESULT_MALFORMED;

  char terminal_name[DNS_NAME_TEXT_CAPACITY];
  if (!_resolver_follow_cname_chain(request, &answers, header, terminal_name, sizeof(terminal_name)))
    return RESOLVER_RESPONSE_RESULT_MALFORMED;

  if (response_code != DNS_RESPONSE_CODE_NOERROR)
    return RESOLVER_RESPONSE_RESULT_NO_MATCH;

  switch (request->query_type)
  {
    case DNS_TYPE_PTR:
    {
      char name[DNS_NAME_TEXT_CAPACITY];
      size_t name_length;
      const enum resolver_response_result result =
        _resolver_find_ptr_name(request, &answers, header, terminal_name, name, sizeof(name), &name_length);
      if (result != RESOLVER_RESPONSE_RESULT_MATCH)
        return result;

      result_data->name.length = name_length;
      memcpy(result_data->name.value, name, name_length + 1);
      return RESOLVER_RESPONSE_RESULT_MATCH;
    }

    case DNS_TYPE_A:
    case DNS_TYPE_AAAA:
      return _resolver_collect_addresses(request, &answers, header, terminal_name,
                                         &result_data->addresses.items,
                                         &result_data->addresses.count);

    default:
      assert(!"unsupported resolver query type");
      return RESOLVER_RESPONSE_RESULT_MALFORMED;
  }
}

static void
_resolver_completion_dispatch(const struct resolver_completion *completion)
{
  assert(completion);

  switch (completion->type)
  {
    case RESOLVER_COMPLETION_TYPE_NAME:
      assert(completion->callback.lookup_addr);
      assert(completion->result.name.length < sizeof(completion->result.name.value));
      assert(completion->result.name.value[completion->result.name.length] == '\0');

      if (completion->result.name.length == 0)
        completion->callback.lookup_addr(completion->callback_ctx, NULL, 0);
      else
        completion->callback.lookup_addr(completion->callback_ctx, completion->result.name.value,
                                         completion->result.name.length);
      return;

    case RESOLVER_COMPLETION_TYPE_ADDRESSES:
      assert(completion->callback.lookup_name);

      if (completion->result.addresses.count == 0)
      {
        assert(completion->result.addresses.items == NULL);
        completion->callback.lookup_name(completion->callback_ctx, NULL, 0);
        return;
      }

      assert(completion->result.addresses.items);
      completion->callback.lookup_name(completion->callback_ctx,
                                       completion->result.addresses.items,
                                       completion->result.addresses.count);
      io_free(completion->result.addresses.items);
      return;
  }

  assert(!"invalid resolver completion type");
}

static bool
_resolver_process_packet(const struct resolver_socket *socket,
                         const unsigned char *packet, size_t packet_length,
                         const struct io_addr *source,
                         struct resolver_completion *completion)
{
  assert(socket);
  assert(packet);
  assert(source);
  assert(completion);

  if (packet_length < DNS_HEADER_WIRE_SIZE)
    return false;

  size_t source_nameserver_index;
  if (!_resolver_nameserver_find_index_by_source(socket, source, &source_nameserver_index))
    return false;

  struct dns_reader reader;
  dns_reader_init(&reader, packet, packet_length);

  struct dns_header header;
  if (!dns_reader_read_header(&reader, &header) ||
      !dns_header_is_response(&header) || dns_header_get_opcode(&header) != DNS_OPCODE_QUERY)
    return false;

  struct resolver_request *const request =
    _resolver_request_find_by_transaction_id(header.transaction_id);
  if (request == NULL)
    return false;

  if (request->config_generation != resolver_config_generation ||
      request->nameserver_states[source_nameserver_index] == RESOLVER_NAMESERVER_STATE_UNQUERIED)
    return false;

  if (header.question_count != 1)
    return false;

  struct dns_question question;
  if (!dns_reader_read_question(&reader, &question) ||
      !_resolver_question_matches_request(request, &reader.packet, &question))
    return false;

  const bool source_nameserver_is_current = source_nameserver_index == request->nameserver_index;

  const uint16_t response_code = dns_header_get_response_code(&header);
  if (dns_header_is_truncated(&header) ||
      _resolver_response_code_is_nameserver_failure(response_code))
  {
    _resolver_request_mark_nameserver_failed(request, source_nameserver_index);

    if (!source_nameserver_is_current || _resolver_request_retry(request))
      return false;

    _resolver_request_finalize_failure(request, completion);
    return true;
  }

  union resolver_result_data result_data = { 0 };
  switch (_resolver_process_response(request, &reader, &header, &result_data))
  {
    case RESOLVER_RESPONSE_RESULT_MATCH:
      break;

    case RESOLVER_RESPONSE_RESULT_NO_MATCH:
      _resolver_request_finalize_failure(request, completion);
      return true;

    case RESOLVER_RESPONSE_RESULT_MALFORMED:
      _resolver_request_mark_nameserver_failed(request, source_nameserver_index);

      if (!source_nameserver_is_current || _resolver_request_retry(request))
        return false;

      _resolver_request_finalize_failure(request, completion);
      return true;
  }

  switch (request->query_type)
  {
    case DNS_TYPE_PTR:
      _resolver_request_finalize_name(request, completion,
                                      result_data.name.value,
                                      result_data.name.length);
      return true;

    case DNS_TYPE_A:
    case DNS_TYPE_AAAA:
      _resolver_request_finalize_addresses(request, completion,
                                           result_data.addresses.items,
                                           result_data.addresses.count);
      return true;

    default:
      assert(!"unsupported resolver query type");
      return false;
  }
}

static void
_resolver_read_reply(fde_t *fde, void *data)
{
  struct resolver_socket *const socket = data;
  assert(socket);
  assert(socket->fde == fde);

  unsigned char packet[RESOLVER_UDP_MESSAGE_CAPACITY];
  struct resolver_completion completion;
  bool completed = false;

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

    completed = _resolver_process_packet(socket, packet, (size_t)bytes_received, &source, &completion);
    if (completed)
      break;
  }

  comm_setselect(fde, COMM_SELECT_READ, _resolver_read_reply, socket);

  if (completed)
    _resolver_completion_dispatch(&completion);
}

static void
_resolver_process_timeouts(void *unused)
{
  (void)unused;

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);

  for (size_t i = 0; i < IO_ARRAY_LENGTH(requests_by_transaction_id); ++i)
  {
    struct resolver_request *const request = requests_by_transaction_id[i];
    if (request == NULL)
      continue;

    assert(request->transaction_id == (uint16_t)i);
    assert(request->round_index < RESOLVER_MAX_ROUNDS);

    if (now < request->last_sent_at ||
        now - request->last_sent_at < request->timeout_interval)
      continue;

    if (_resolver_request_retry(request))
      continue;

    struct resolver_completion completion;
    _resolver_request_finalize_failure(request, &completion);
    _resolver_completion_dispatch(&completion);
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
resolver_lookup_name(resolver_lookup_name_callback_fn callback, void *callback_ctx, const char *name, int family)
{
  assert(callback);
  assert(name);
  assert(family == AF_INET || family == AF_INET6);

  const uint16_t query_type = _resolver_query_type_from_family(family);
  return _resolver_query_name(callback, callback_ctx, name, query_type);
}

bool
resolver_lookup_addr(resolver_lookup_addr_callback_fn callback, void *callback_ctx, const struct io_addr *addr)
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
