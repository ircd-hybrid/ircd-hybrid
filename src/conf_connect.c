/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#include "io_string.h"
#include "log.h"
#include "memory.h"
#include "res.h"
#include "reslib.h"

#include "client.h"
#include "conf_connect.h"
#include "conf_class.h"
#include "send.h"

static list_t connect_items;

void
connect_assign_class(struct ConnectItem *connect, const char *class_name)
{
  assert(connect->klass == NULL);

  if (!string_is_empty(class_name))
    connect->klass = class_find(class_name, true);

  if (connect->klass == NULL)
  {
    connect->klass = class_default;

    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Warning: Class '%s' not found for connect block '%s'. Defaulting to class '%s'.",
                   string_default(class_name, "<not specified>"), connect->name, connect->klass->name);
    log_write(LOG_TYPE_IRCD, "Class '%s' not found for connect block '%s'. Defaulting to class '%s'.",
              string_default(class_name, "<not specified>"), connect->name, connect->klass->name);
  }
}

void
connect_mark_all_inactive(void)
{
  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    connect->active = false;
  }
}

void
connect_sweep_inactive(void)
{
  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    if (connect->active == false && connect->ref_count == 0)
      connect_destroy(connect);
  }
}

struct ConnectItem *
connect_create(void)
{
  struct ConnectItem *const connect = io_calloc(sizeof(*connect));
  connect->active = true;
  connect->address_family = AF_INET;

  list_add(connect, &connect->node, &connect_items);
  return connect;
}

void
connect_destroy(struct ConnectItem *connect)
{
  assert(connect);
  assert(connect->ref_count == 0);

  list_remove(&connect->node, &connect_items);

  if (connect->dns_pending)
    delete_resolver_queries(connect);

  if (connect->accept_password)
    memset(connect->accept_password, 0, strlen(connect->accept_password));
  if (connect->send_password)
    memset(connect->send_password, 0, strlen(connect->send_password));

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, connect->hub_masks.head)
  {
    io_free(node->data);
    list_remove(node, &connect->hub_masks);
    list_free_node(node);
  }

  LIST_FOREACH_SAFE(node, node_next, connect->leaf_masks.head)
  {
    io_free(node->data);
    list_remove(node, &connect->leaf_masks);
    list_free_node(node);
  }

  connect->klass = NULL;

  io_free(connect->name);
  io_free(connect->host);
  io_free(connect->accept_password);
  io_free(connect->send_password);
  io_free(connect->tls_cert_fingerprint);
  io_free(connect->cipher_list);
  io_free(connect);
}

static void
_connect_dns_callback(void *vptr, const struct io_addr *addr, const char *name, size_t name_length)
{
  struct ConnectItem *const connect = vptr;
  assert(connect);
  assert(connect->dns_pending);

  connect->dns_pending = false;

  if (addr)
  {
    address_copy(&connect->remote_addr, addr);
    connect->dns_failed = false;
  }
  else
    connect->dns_failed = true;
}

void
connect_dns_lookup(struct ConnectItem *connect)
{
  assert(connect);
  assert(connect->address_family == AF_INET || connect->address_family == AF_INET6);
  assert(!string_is_empty(connect->host));

  if (address_from_string(connect->host, &connect->remote_addr))
  {
    connect->dns_pending = false;
    connect->dns_failed = false;
    return;
  }

  /*
   * By this point connect->host possibly is not a numerical network address. Do a nameserver
   * lookup of the connect host. If the connect entry is currently doing a ns lookup do nothing.
   */
  if (connect->dns_pending)
    return;

  connect->dns_pending = true;
  connect->dns_failed = false;

  const int query_type = (connect->address_family == AF_INET) ? T_A : T_AAAA;
  gethost_byname_type(_connect_dns_callback, connect, connect->host, query_type);
}

struct ConnectItem *
connect_find(const char *name, bool active)
{
  assert(!string_is_empty(name));

  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    if (match(name, connect->name))
      continue;

    if (active && connect->active == false)
      continue;

    return connect;
  }

  return NULL;
}

static bool
_connect_match_password(const struct ConnectItem *connect, const char *password)
{
  if (string_is_empty(password) || string_is_empty(connect->accept_password))
    return false;

  const char *encr;
  if (connect->flags & CONNECT_FLAG_ENCRYPTED_PASSWORD)
    encr = crypt(password, connect->accept_password);
  else
    encr = password;

  return encr && strcmp(encr, connect->accept_password) == 0;
}

connect_auth_result_t
connect_authenticate_server(const char *server_name, const struct Client *client, struct ConnectItem **connect_out)
{
  assert(!string_is_empty(server_name));
  assert(client && client_is_local(client));
  assert(connect_out);

  *connect_out = NULL;
  connect_auth_result_t result = CONNECT_AUTH_FAIL_NAME;

  list_node_t *node;
  LIST_FOREACH(node, connect_items.head)
  {
    struct ConnectItem *const connect = node->data;
    if (connect->active == false)
      continue;

    if (io_strcasecmp(server_name, connect->name))
      continue;

    if (io_strcasecmp(connect->host, client->host) && io_strcasecmp(connect->host, client->sockhost))
    {
      if (result < CONNECT_AUTH_FAIL_HOST)
        result = CONNECT_AUTH_FAIL_HOST;
      continue;
    }

    if ((connect->flags & CONNECT_FLAG_USE_TLS) && !client_has_flag(client, FLAGS_TLS_ACTIVE))
    {
      if (result < CONNECT_AUTH_FAIL_TLS)
        result = CONNECT_AUTH_FAIL_TLS;
      continue;
    }

    if (!string_is_empty(connect->tls_cert_fingerprint) &&
        (string_is_empty(client->tls_certfp) || io_strcasecmp(client->tls_certfp, connect->tls_cert_fingerprint)))
    {
      if (result < CONNECT_AUTH_FAIL_CERTFP)
        result = CONNECT_AUTH_FAIL_CERTFP;
      continue;
    }

    if (!_connect_match_password(connect, client->connection->password))
    {
      if (result < CONNECT_AUTH_FAIL_PASSWORD)
        result = CONNECT_AUTH_FAIL_PASSWORD;
      continue;
    }

    *connect_out = connect;
    return CONNECT_AUTH_SUCCESS;
  }

  return result;
}

list_t *
connect_get_list(void)
{
  return &connect_items;
}

void
connect_incref(struct ConnectItem *connect)
{
  if (connect == NULL)
    return;

  connect->ref_count++;
}

void
connect_decref(struct ConnectItem *connect)
{
  if (connect == NULL)
    return;

  assert(connect->ref_count > 0);
  connect->ref_count--;

  if (connect->ref_count == 0 && connect->active == false)
    connect_destroy(connect);
}

const char *
connect_auth_result_to_string(connect_auth_result_t result)
{
  switch (result)
  {
    case CONNECT_AUTH_SUCCESS:        return "Success";
    case CONNECT_AUTH_FAIL_NAME:      return "No configured connect block";
    case CONNECT_AUTH_FAIL_HOST:      return "Connecting host does not match configured host";
    case CONNECT_AUTH_FAIL_PASSWORD:  return "Invalid password";
    case CONNECT_AUTH_FAIL_TLS:       return "TLS connection required";
    case CONNECT_AUTH_FAIL_CERTFP:    return "Invalid TLS certificate fingerprint";
  }

  return "Unknown authentication result";
}
