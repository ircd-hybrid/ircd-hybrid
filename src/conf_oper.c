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

#include "io_string.h"
#include "memory.h"
#include "stdinc.h"
#include "client.h"
#include "conf_class.h"
#include "conf_oper.h"
#include "send.h"
#include "user_mode.h"

static list_t operator_items;

static bool
oper_match_password(const struct OperItem *oper, const char *password)
{
  if (string_is_empty(password) || string_is_empty(oper->password))
    return false;

  const char *encr;
  if (oper->flags & OPER_CONF_FLAG_ENCRYPTED_PASSWORD)
    encr = crypt(password, oper->password);
  else
    encr = password;

  return encr && strcmp(encr, oper->password) == 0;
}

void
oper_free_all(void)
{
  list_node_t *node, *next;
  LIST_FOREACH_SAFE(node, next, operator_items.head)
  {
    struct OperItem *const oper = node->data;
    oper_free(oper);
  }
}

struct OperItem *
oper_create(void)
{
  struct OperItem *const oper = io_calloc(sizeof(*oper));
  list_add(oper, &oper->node, &operator_items);

  return oper;
}

void
oper_free(struct OperItem *oper)
{
  list_remove(&oper->node, &operator_items);

  if (oper->password)
    memset(oper->password, 0, strlen(oper->password));

  oper->class = NULL;

  io_free(oper->name);
  io_free(oper->user);
  io_free(oper->host);
  io_free(oper->password);
  io_free(oper->tls_cert_fingerprint);
  io_free(oper->whois_text);
  io_free(oper->modes);
  io_free(oper);
}

void
oper_assign_class(struct OperItem *oper, const char *class_name)
{
  assert(oper);

  if (!string_is_empty(class_name))
    oper->class = class_find(class_name, true);

  if (oper->class == NULL)
  {
    oper->class = class_default;
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                   "Warning: Class '%s' not found for operator block '%s'. Defaulting to class '%s'.",
                   string_default(class_name, "<not specified>"), oper->name, oper->class->name);
  }
}

oper_auth_result_t
oper_authenticate(const struct Client *client, const char *oper_name, const char *password, struct OperItem **oper_out)
{
  assert(oper_out);

  *oper_out = NULL;
  oper_auth_result_t result = OPER_AUTH_FAIL_NAME;

  list_node_t *node;
  LIST_FOREACH(node, operator_items.head)
  {
    struct OperItem *const oper = node->data;
    if (irccmp(oper->name, oper_name))
      continue;

    bool host_match = false;
    if (match(oper->user, client->username) == 0)
    {
      switch (oper->htype)
      {
        case HM_HOST:
          host_match = (match(oper->host, client->realhost) == 0 ||
                        match(oper->host, client->sockhost) == 0 || match(oper->host, client->host) == 0);
          break;
        case HM_IPV4:
        case HM_IPV6:
          host_match = address_match(&client->addr, &oper->addr, false, false, oper->bits);
          break;
      }
    }

    if (host_match == false)
    {
      if (result < OPER_AUTH_FAIL_HOST)
        result = OPER_AUTH_FAIL_HOST;
      continue;
    }

    if ((oper->flags & OPER_CONF_FLAG_REQUIRE_TLS) && !user_mode_has_flag(client, UMODE_SECURE))
    {
      if (result < OPER_AUTH_FAIL_TLS)
        result = OPER_AUTH_FAIL_TLS;
      continue;
    }

    if (!string_is_empty(oper->tls_cert_fingerprint) &&
        (string_is_empty(client->tls_certfp) || strcasecmp(client->tls_certfp, oper->tls_cert_fingerprint)))
    {
      if (result < OPER_AUTH_FAIL_CERTFP)
        result = OPER_AUTH_FAIL_CERTFP;
      continue;
    }

    if (oper_match_password(oper, password) == false)
    {
      if (result < OPER_AUTH_FAIL_PASSWORD)
        result = OPER_AUTH_FAIL_PASSWORD;
      continue;
    }

    *oper_out = oper;
    return OPER_AUTH_SUCCESS;
  }

  return result;
}

const char *
oper_auth_result_to_string(oper_auth_result_t result)
{
  switch (result)
  {
    case OPER_AUTH_SUCCESS:          return "Success";
    case OPER_AUTH_FAIL_NAME:        return "No configured operator block";
    case OPER_AUTH_FAIL_HOST:        return "Host/ident/IP mismatch";
    case OPER_AUTH_FAIL_PASSWORD:    return "Invalid password";
    case OPER_AUTH_FAIL_TLS:         return "TLS connection required";
    case OPER_AUTH_FAIL_CERTFP:      return "Invalid TLS certificate fingerprint";
    case OPER_AUTH_FAIL_CLASS_FULL:  return "Operator class limit reached";
  }

  return "Unknown authentication result";
}

list_t *
oper_get_list(void)
{
  return &operator_items;
}
