/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stddef.h>

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

typedef enum
{
  LOOKUP_DNS_START,
  LOOKUP_DNS_SUCCESS,
  LOOKUP_DNS_FAIL,
  LOOKUP_DNS_IP_MISMATCH,
  LOOKUP_DNS_TOO_LONG,
  LOOKUP_DNS_INVALID,
  LOOKUP_IDENT_START,
  LOOKUP_IDENT_SUCCESS,
  LOOKUP_IDENT_FAIL,
  LOOKUP_REPORT_COUNT
} lookup_report_type_t;

static const char *const lookup_report_headers[LOOKUP_REPORT_COUNT] =
{
  [LOOKUP_DNS_START] = ":*** Looking up your hostname",
  [LOOKUP_DNS_SUCCESS] = ":*** Found your hostname",
  [LOOKUP_DNS_FAIL] = ":*** Couldn't look up your hostname",
  [LOOKUP_DNS_IP_MISMATCH] = ":*** Your forward and reverse DNS do not match, ignoring hostname",
  [LOOKUP_DNS_TOO_LONG] = ":*** Your hostname is too long, ignoring hostname",
  [LOOKUP_DNS_INVALID] = ":*** Your hostname contains illegal characters, ignoring hostname",
  [LOOKUP_IDENT_START] = ":*** Checking Ident",
  [LOOKUP_IDENT_SUCCESS] = ":*** Got Ident response",
  [LOOKUP_IDENT_FAIL] = ":*** No Ident response"
};

static void
_lookup_report(const struct LookupRequest *lookup, lookup_report_type_t type)
{
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));
  assert((unsigned int)type < LOOKUP_REPORT_COUNT);
  assert(lookup_report_headers[type]);

  sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[type]);
}

static void
_lookup_check_complete(struct LookupRequest *lookup)
{
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));
  assert(lookup->client->connection->lookup_request == lookup);

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

static void
_lookup_dns_callback(void *data, const struct io_addr *addr, const char *name, size_t name_length)
{
  struct LookupRequest *const lookup = data;
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));
  assert(lookup->client->connection->lookup_request == lookup);
  assert(lookup->dns_pending);

  lookup->dns_pending = false;

  lookup_report_type_t report = LOOKUP_DNS_FAIL;

  if (addr == NULL || name == NULL)
  {
    assert(addr == NULL && name == NULL && name_length == 0);
    report = LOOKUP_DNS_FAIL;
  }
  else if (name_length == 0)
    report = LOOKUP_DNS_FAIL;
  else if (name_length > HOSTLEN)
    report = LOOKUP_DNS_TOO_LONG;
  else if (!address_equal(addr, &lookup->client->addr))
    report = LOOKUP_DNS_IP_MISMATCH;
  else if (!hostname_is_valid(name))
    report = LOOKUP_DNS_INVALID;
  else
  {
    strlcpy(lookup->client->host, name, sizeof(lookup->client->host));
    report = LOOKUP_DNS_SUCCESS;
  }

  _lookup_report(lookup, report);
  _lookup_check_complete(lookup);
}

static void
_lookup_ident_callback(void *data, const char *username)
{
  struct LookupRequest *const lookup = data;
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));
  assert(lookup->client->connection->lookup_request == lookup);
  assert(lookup->ident_request);
  assert(lookup->ident_pending);

  ident_request_t *const ident_request = lookup->ident_request;
  lookup->ident_request = NULL;
  lookup->ident_pending = false;
  ident_delete(ident_request);

  lookup_report_type_t report = LOOKUP_IDENT_FAIL;

  if (!string_is_empty(username))
  {
    strlcpy(lookup->client->username, username, sizeof(lookup->client->username));
    client_set_flag(lookup->client, FLAGS_GOTID);
    report = LOOKUP_IDENT_SUCCESS;
  }

  _lookup_report(lookup, report);
  _lookup_check_complete(lookup);
}

static void
_lookup_dns_start(struct LookupRequest *lookup)
{
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));
  assert(!lookup->dns_pending);

  _lookup_report(lookup, LOOKUP_DNS_START);

  if (resolver_lookup_addr(_lookup_dns_callback, lookup, &lookup->client->addr))
  {
    lookup->dns_pending = true;
    return;
  }

  _lookup_report(lookup, LOOKUP_DNS_FAIL);
}

static void
_lookup_ident_start(struct LookupRequest *lookup)
{
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));
  assert(lookup->ident_request == NULL);
  assert(!lookup->ident_pending);

  _lookup_report(lookup, LOOKUP_IDENT_START);

  const uintmax_t timeout_ms = ConfigGeneral.ident_timeout * 1000ULL;
  lookup->ident_request =
    ident_start(&lookup->client->addr, lookup->client->connection->fde->fd,
                _lookup_ident_callback, lookup, timeout_ms);

  if (lookup->ident_request)
  {
    lookup->ident_pending = true;
    return;
  }

  _lookup_report(lookup, LOOKUP_IDENT_FAIL);
}

void
lookup_delete(struct LookupRequest *lookup)
{
  assert(lookup);
  assert(lookup->client && client_is_local(lookup->client));

  if (lookup->ident_request)
  {
    ident_request_t *const ident_request = lookup->ident_request;
    lookup->ident_request = NULL;
    lookup->ident_pending = false;

    ident_request->callback = NULL;
    ident_request->user_data = NULL;
    ident_delete(ident_request);
  }

  resolver_cancel_by_context(lookup);
  io_free(lookup);
}

void
lookup_start(struct Client *client)
{
  assert(client && client_is_local(client));
  assert(client->connection->lookup_request == NULL);

  struct LookupRequest *const lookup = io_calloc(sizeof(*lookup));
  lookup->client = client;
  client->connection->lookup_request = lookup;

  if (ConfigGeneral.disable_dns == 0)
    _lookup_dns_start(lookup);

  if (ConfigGeneral.disable_ident == 0)
    _lookup_ident_start(lookup);

  _lookup_check_complete(lookup);
}
