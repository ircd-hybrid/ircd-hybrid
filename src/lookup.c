/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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

#include <assert.h>
#include <stddef.h>

#include "address.h"
#include "comm.h"
#include "ident.h"
#include "io_string.h"
#include "io_time.h"
#include "memory.h"
#include "res.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "lookup.h"
#include "packet.h"
#include "send.h"

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
  LOOKUP_IDENT_FAIL
} lookup_report_type_t;

static const char *const lookup_report_headers[] =
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
lookup_check_complete(struct LookupRequest *lookup)
{
  /* Do not proceed if other asynchronous lookups are still in flight. */
  if (lookup->dns_pending || lookup->ident_pending)
    return;

  struct Client *client = lookup->client;
  client->connection->lookup = NULL;
  io_free(lookup);

  /* The pre-registration phase is complete; update the client's state and timers. */
  client->connection->last_receive_time = \
  client->connection->created_monotonic = io_time_get(IO_TIME_MONOTONIC_SEC);
  client->connection->created_real = io_time_get(IO_TIME_REALTIME_SEC);

  /* Start the registration timer; the client must now send NICK/USER. */
  client_reset_activity_timeout(client);

  /* Hand the connection over to the main packet reader to begin processing IRC protocol commands. */
  read_packet(client->connection->fd, client);
}

static bool
lookup_verify_hostname(const char *hostname)
{
  const char *p = hostname;
  assert(p);

  if (string_is_empty(p) || *p == '.' || *p == ':')
    return false;

  for (; *p; ++p)
    if (!IsHostChar(*p))
      return false;

  return true;
}

static void
lookup_dns_callback(void *vptr, const struct io_addr *addr, const char *name, size_t name_length)
{
  struct LookupRequest *lookup = vptr;
  lookup->dns_pending = false;

  if (name_length == 0)
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_DNS_FAIL]);
  else if (name_length > HOSTLEN)
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_DNS_TOO_LONG]);
  else if (address_match(addr, &lookup->client->addr, true, false, 0) == false)
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_DNS_IP_MISMATCH]);
  else if (lookup_verify_hostname(name) == false)
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_DNS_INVALID]);
  else
  {
    strlcpy(lookup->client->host, name, sizeof(lookup->client->host));
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_DNS_SUCCESS]);
  }

  lookup_check_complete(lookup);
}

static void
lookup_ident_callback(void *user_data, const char *username)
{
  struct LookupRequest *lookup = user_data;

  ident_delete(lookup->ident_request);

  lookup->ident_request = NULL;
  lookup->ident_pending = false;

  if (string_is_empty(username))
  {
    ++ServerStats.is_abad;
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_IDENT_FAIL]);
  }
  else
  {
    strlcpy(lookup->client->username, username, sizeof(lookup->client->username));
    client_set_flag(lookup->client, FLAGS_GOTID);

    ++ServerStats.is_asuc;
    sendto_one_notice(lookup->client, &me, "%s", lookup_report_headers[LOOKUP_IDENT_SUCCESS]);
  }

  lookup_check_complete(lookup);
}

void
lookup_delete(struct LookupRequest *lookup)
{
  if (lookup->ident_request)
  {
    lookup->ident_request->callback = NULL;
    lookup->ident_request->user_data = NULL;

    ident_delete(lookup->ident_request);
    lookup->ident_request = NULL;
  }

  delete_resolver_queries(lookup);
  io_free(lookup);
}

void
lookup_start(struct Client *client)
{
  struct LookupRequest *lookup = io_calloc(sizeof(*lookup));
  lookup->client = client;
  client->connection->lookup = lookup;

  if (ConfigGeneral.disable_dns == 0)
  {
    sendto_one_notice(client, &me, "%s", lookup_report_headers[LOOKUP_DNS_START]);
    lookup->dns_pending = true;
    gethost_byaddr(lookup_dns_callback, lookup, &client->addr);
  }

  if (ConfigGeneral.disable_ident == 0)
  {
    sendto_one_notice(client, &me, "%s", lookup_report_headers[LOOKUP_IDENT_START]);

    const uintmax_t timeout_ms = ConfigGeneral.ident_timeout * 1000ULL;
    lookup->ident_request =
      ident_start(&client->addr, client->connection->fd->fd, lookup_ident_callback, lookup, timeout_ms);
    if (lookup->ident_request)
      lookup->ident_pending = true;
    else
    {
      ++ServerStats.is_abad;
      sendto_one_notice(client, &me, "%s", lookup_report_headers[LOOKUP_IDENT_FAIL]);
    }
  }

  lookup_check_complete(lookup);
}
