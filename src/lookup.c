/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "address.h"
#include "comm.h"
#include "ident.h"
#include "io_string.h"
#include "io_time.h"
#include "memory.h"
#include "resolver.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "lookup.h"
#include "packet.h"
#include "send.h"
#include "user.h"

enum lookup_report_type
{
  LOOKUP_REPORT_DNS_START,
  LOOKUP_REPORT_DNS_SUCCESS,
  LOOKUP_REPORT_DNS_FAIL,
  LOOKUP_REPORT_DNS_IP_MISMATCH,
  LOOKUP_REPORT_DNS_TOO_LONG,
  LOOKUP_REPORT_DNS_INVALID,
  LOOKUP_REPORT_IDENT_START,
  LOOKUP_REPORT_IDENT_SUCCESS,
  LOOKUP_REPORT_IDENT_FAIL,
  LOOKUP_REPORT_COUNT
};

struct LookupRequest
{
  struct Client *client;
  bool dns_pending;
  bool ident_pending;
};

static const char *const lookup_report_messages[LOOKUP_REPORT_COUNT] =
{
  [LOOKUP_REPORT_DNS_START] = ":*** Looking up your hostname",
  [LOOKUP_REPORT_DNS_SUCCESS] = ":*** Found your hostname",
  [LOOKUP_REPORT_DNS_FAIL] = ":*** Couldn't look up your hostname",
  [LOOKUP_REPORT_DNS_IP_MISMATCH] = ":*** Your forward and reverse DNS do not match, ignoring hostname",
  [LOOKUP_REPORT_DNS_TOO_LONG] = ":*** Your hostname is too long, ignoring hostname",
  [LOOKUP_REPORT_DNS_INVALID] = ":*** Your hostname contains illegal characters, ignoring hostname",
  [LOOKUP_REPORT_IDENT_START] = ":*** Checking Ident",
  [LOOKUP_REPORT_IDENT_SUCCESS] = ":*** Got Ident response",
  [LOOKUP_REPORT_IDENT_FAIL] = ":*** No Ident response"
};

static void
_lookup_assert_attached(const struct LookupRequest *lookup)
{
  assert(lookup);
  assert(lookup->client);
  assert(lookup->client->connection);
  assert(lookup->client->connection->lookup_request == lookup);
}

static void
_lookup_report(const struct LookupRequest *lookup, enum lookup_report_type type)
{
  _lookup_assert_attached(lookup);
  assert((unsigned int)type < (unsigned int)LOOKUP_REPORT_COUNT);
  assert(lookup_report_messages[type]);

  sendto_one_notice(lookup->client, &me, "%s", lookup_report_messages[type]);
}

static void
_lookup_complete_if_ready(struct LookupRequest *lookup)
{
  _lookup_assert_attached(lookup);

  if (lookup->dns_pending || lookup->ident_pending)
    return;

  struct Client *const client = lookup->client;
  client->connection->lookup_request = NULL;
  io_free(lookup);

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  client->connection->last_receive_time = now;
  client->connection->created_monotonic = now;
  client->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);

  /* Start the registration timer; the client must now send NICK/USER. */
  client_update_activity_timeout(client);

  /* Hand the connection over to the main packet reader to begin processing IRC protocol commands. */
  read_packet(client->connection->fde, client);
}

static enum lookup_report_type
_lookup_dns_process_result(struct LookupRequest *lookup, const struct io_addr *addr,
                           const char *name, size_t name_length)
{
  _lookup_assert_attached(lookup);

  if (addr == NULL || name == NULL || name_length == 0)
    return LOOKUP_REPORT_DNS_FAIL;

  if (name_length > HOSTLEN)
    return LOOKUP_REPORT_DNS_TOO_LONG;

  if (!address_equal(addr, &lookup->client->addr))
    return LOOKUP_REPORT_DNS_IP_MISMATCH;

  if (!hostname_is_valid(name))
    return LOOKUP_REPORT_DNS_INVALID;

  strlcpy(lookup->client->host, name, sizeof(lookup->client->host));
  return LOOKUP_REPORT_DNS_SUCCESS;
}

static void
_lookup_dns_callback(void *callback_ctx, const struct io_addr *addr, const char *name, size_t name_length)
{
  struct LookupRequest *const lookup = callback_ctx;
  _lookup_assert_attached(lookup);
  assert(lookup->dns_pending);

  lookup->dns_pending = false;

  const enum lookup_report_type report = _lookup_dns_process_result(lookup, addr, name, name_length);
  _lookup_report(lookup, report);

  _lookup_complete_if_ready(lookup);
}

static void
_lookup_ident_callback(void *callback_ctx, const char *username)
{
  struct LookupRequest *const lookup = callback_ctx;
  _lookup_assert_attached(lookup);
  assert(lookup->ident_pending);

  lookup->ident_pending = false;

  enum lookup_report_type report = LOOKUP_REPORT_IDENT_FAIL;
  if (!string_is_empty(username))
  {
    strlcpy(lookup->client->username, username, sizeof(lookup->client->username));
    client_set_flag(lookup->client, FLAGS_GOTID);
    report = LOOKUP_REPORT_IDENT_SUCCESS;
  }

  _lookup_report(lookup, report);
  _lookup_complete_if_ready(lookup);
}

static void
_lookup_dns_start(struct LookupRequest *lookup)
{
  _lookup_assert_attached(lookup);
  assert(!lookup->dns_pending);

  _lookup_report(lookup, LOOKUP_REPORT_DNS_START);

  if (resolver_lookup_addr(_lookup_dns_callback, lookup, &lookup->client->addr))
  {
    lookup->dns_pending = true;
    return;
  }

  _lookup_report(lookup, LOOKUP_REPORT_DNS_FAIL);
}

static void
_lookup_ident_start(struct LookupRequest *lookup)
{
  _lookup_assert_attached(lookup);
  assert(!lookup->ident_pending);

  _lookup_report(lookup, LOOKUP_REPORT_IDENT_START);

  const uintmax_t timeout_ms = ConfigGeneral.ident_timeout * 1000ULL;
  if (ident_start(_lookup_ident_callback, lookup, lookup->client->connection->fde->fd, timeout_ms))
  {
    lookup->ident_pending = true;
    return;
  }

  _lookup_report(lookup, LOOKUP_REPORT_IDENT_FAIL);
}

void
lookup_delete(struct LookupRequest *lookup)
{
  _lookup_assert_attached(lookup);

  ident_cancel_by_context(lookup);
  resolver_cancel_by_context(lookup);

  io_free(lookup);
}

void
lookup_start(struct Client *client)
{
  assert(client);
  assert(client->connection);
  assert(client->connection->lookup_request == NULL);

  struct LookupRequest *const lookup = io_calloc(sizeof(*lookup));
  lookup->client = client;
  client->connection->lookup_request = lookup;

  if (ConfigGeneral.disable_dns == 0)
    _lookup_dns_start(lookup);

  if (ConfigGeneral.disable_ident == 0)
    _lookup_ident_start(lookup);

  _lookup_complete_if_ready(lookup);
}
