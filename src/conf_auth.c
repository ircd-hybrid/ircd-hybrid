/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file conf_auth.c
 * @brief Ordered client authorization configuration and matching.
 */

#include "config.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#ifdef HAVE_CRYPT_H
#include <crypt.h>
#endif

#include "address.h"
#include "io_string.h"
#include "list.h"
#include "log.h"
#include "memory.h"

#include "client.h"
#include "conf_auth.h"
#include "conf_class.h"
#include "conf_kill.h"
#include "ipcache.h"
#include "ircd_defs.h"
#include "send.h"
#include "user.h"

#define CONF_AUTH_FLAGS_ALL \
  (CONF_AUTH_FLAG_NO_TILDE | \
   CONF_AUTH_FLAG_REQUIRE_IDENT | \
   CONF_AUTH_FLAG_EXEMPT_KLINE | \
   CONF_AUTH_FLAG_EXEMPT_LIMITS | \
   CONF_AUTH_FLAG_CAN_FLOOD | \
   CONF_AUTH_FLAG_ENCRYPTED_PASSWORD | \
   CONF_AUTH_FLAG_EXEMPT_RESV | \
   CONF_AUTH_FLAG_WEBIRC | \
   CONF_AUTH_FLAG_EXEMPT_XLINE | \
   CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH)

struct conf_auth_address_rule
{
  struct conf_auth_rule rule;
  struct io_addr network;
  unsigned int prefix_length;
};

struct conf_auth_registry
{
  list_t items;
  bool initialized;
};

static struct conf_auth_registry conf_auth_registry;

static bool
_conf_auth_is_initialized(void)
{
  return conf_auth_registry.initialized;
}

static void
_conf_auth_assert_initialized(void)
{
  const bool initialized = _conf_auth_is_initialized();
  assert(initialized);

  assert((conf_auth_registry.items.head == NULL) ==
         (conf_auth_registry.items.tail == NULL));
  assert((conf_auth_registry.items.head == NULL) ==
         (list_length(&conf_auth_registry.items) == 0));
}

static bool
_conf_auth_flags_are_valid(unsigned int flags)
{
  return (flags & ~CONF_AUTH_FLAGS_ALL) == 0;
}

static void
_conf_auth_assert_valid(const struct conf_auth *auth)
{
  assert(auth);
  assert(auth->node.data == auth);
  assert(auth->klass);
  assert(_conf_auth_flags_are_valid(auth->flags));
  assert(auth->password == NULL || !string_is_empty(auth->password));
  assert(auth->spoof == NULL || hostname_is_valid(auth->spoof));
  assert(!list_is_empty(&auth->rules));
  assert((auth->rules.head == NULL) == (auth->rules.tail == NULL));
}

static void
_conf_auth_rule_assert_valid(const struct conf_auth_rule *rule)
{

  assert(rule);
  assert(rule->node.data == rule);
  assert(!string_is_empty(rule->user));
  assert(!string_is_empty(rule->host));
  assert(rule->selector_type == CONF_AUTH_SELECTOR_ADDRESS ||
         rule->selector_type == CONF_AUTH_SELECTOR_HOSTMASK);

#ifndef NDEBUG
  if (rule->selector_type == CONF_AUTH_SELECTOR_ADDRESS)
  {
    const struct conf_auth_address_rule *const address_rule = (const struct conf_auth_address_rule *)rule;
    assert((address_is_ipv4(&address_rule->network) && address_rule->prefix_length <= 32) ||
           (address_is_ipv6(&address_rule->network) && address_rule->prefix_length <= 128));
  }
#endif
}

static bool
_conf_auth_spec_is_valid(const struct conf_auth_spec *spec)
{
  if (spec == NULL || string_is_empty(spec->user) ||
      string_is_empty(spec->host) || !_conf_auth_flags_are_valid(spec->flags))
    return false;

  if (!string_is_empty(spec->spoof) && !hostname_is_valid(spec->spoof))
    return false;

  return true;
}

static struct conf_auth_rule *
_conf_auth_rule_create(const char *user, const char *host)
{
  assert(!string_is_empty(user));
  assert(!string_is_empty(host));

  if (string_is_empty(user) || string_is_empty(host))
    return NULL;

  struct io_addr network;
  unsigned int prefix_length;

  struct conf_auth_rule *rule;
  if (address_parse_prefix(host, &network, &prefix_length))
  {
    if (!address_mask(&network, prefix_length))
      return NULL;

    struct conf_auth_address_rule *const address_rule = io_calloc(sizeof(*address_rule));
    address_rule->network = network;
    address_rule->prefix_length = prefix_length;
    address_rule->rule.selector_type = CONF_AUTH_SELECTOR_ADDRESS;
    rule = &address_rule->rule;
  }
  else
  {
    rule = io_calloc(sizeof(*rule));
    rule->selector_type = CONF_AUTH_SELECTOR_HOSTMASK;
  }

  rule->user = io_strdup(user);
  rule->host = io_strdup(host);
  return rule;
}

static void
_conf_auth_rule_destroy(struct conf_auth *auth, struct conf_auth_rule *rule)
{
  assert(auth);
  _conf_auth_rule_assert_valid(rule);

  list_remove(&rule->node, &auth->rules);

  io_free(rule->user);
  io_free(rule->host);
  io_free(rule);
}

static void
_conf_auth_assign_class(struct conf_auth *auth, const char *class_name, const char *user, const char *host)
{
  assert(auth);
  assert(auth->klass == NULL);
  assert(!string_is_empty(user));
  assert(!string_is_empty(host));
  assert(class_default);

  if (!string_is_empty(class_name))
    auth->klass = class_find(class_name, true);

  if (auth->klass)
    return;

  auth->klass = class_default;

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE,
                 "Warning: Class '%s' not found for auth block [%s@%s]. Defaulting to class '%s'.",
                 string_or_default(class_name, "<not specified>"), user, host, auth->klass->name);
  log_write(LOG_TYPE_IRCD,
            "Class '%s' not found for auth block [%s@%s]. Defaulting to class '%s'.",
            string_or_default(class_name, "<not specified>"), user, host, auth->klass->name);
}

static bool
_conf_auth_rule_matches(const struct conf_auth_rule *rule,
                        const char *hostname, const struct io_addr *address, const char *username)
{
  _conf_auth_rule_assert_valid(rule);
  assert(!string_is_empty(username));

  if (match(rule->user, username))
    return false;

  switch (rule->selector_type)
  {
    case CONF_AUTH_SELECTOR_ADDRESS:
    {
      if (address == NULL)
        return false;

      const struct conf_auth_address_rule *const address_rule = (const struct conf_auth_address_rule *)rule;
      return address_match_prefix(address, &address_rule->network, address_rule->prefix_length);
    }

    case CONF_AUTH_SELECTOR_HOSTMASK:
      return !string_is_empty(hostname) && match(rule->host, hostname) == 0;
  }

  assert(!"invalid auth selector type");
  return false;
}

static bool
_conf_auth_matches(const struct conf_auth *auth, const char *hostname,
                   const struct io_addr *address, const char *username)
{
  _conf_auth_assert_valid(auth);

  list_node_t *node;
  LIST_FOREACH(node, auth->rules.head)
  {
    const struct conf_auth_rule *const rule = node->data;
    assert(&rule->node == node);

    if (_conf_auth_rule_matches(rule, hostname, address, username))
      return true;
  }

  return false;
}

static bool
_conf_auth_password_matches(const struct conf_auth *auth, const char *password)
{
  _conf_auth_assert_valid(auth);

  if (string_is_empty(auth->password))
    return true;

  if (string_is_empty(password))
    return false;

  const char *candidate;
  if (auth->flags & CONF_AUTH_FLAG_ENCRYPTED_PASSWORD)
    candidate = crypt(password, auth->password);
  else
    candidate = password;

  return candidate && strcmp(candidate, auth->password) == 0;
}

static void
_conf_auth_password_free(char **password_ptr)
{
  assert(password_ptr);

  char *const password = *password_ptr;
  if (password == NULL)
    return;

  volatile unsigned char *cursor = (volatile unsigned char *)password;
  for (size_t length = strlen(password); length; --length)
    *cursor++ = 0;

  io_free(password);
  *password_ptr = NULL;
}

static void
_conf_auth_destroy(struct conf_auth *auth)
{
  assert(auth);
  _conf_auth_assert_initialized();
  _conf_auth_assert_valid(auth);

  while (auth->rules.head)
    _conf_auth_rule_destroy(auth, auth->rules.head->data);

  list_remove(&auth->node, &conf_auth_registry.items);

  auth->klass = NULL;
  _conf_auth_password_free(&auth->password);
  io_free(auth->spoof);
  io_free(auth);
}

static void
_conf_auth_set_failure(enum conf_auth_result *result_out, const char **failure_reason_out,
                       enum conf_auth_result result, const char *failure_reason)
{
  assert(result_out);
  assert(failure_reason_out);
  assert(result != CONF_AUTH_SUCCESS);
  assert(!string_is_empty(failure_reason));

  *result_out = result;
  *failure_reason_out = failure_reason;
}

static bool
_conf_auth_admit_to_class(struct ClassItem *klass, struct Client *client,
                          bool exempt_limits, enum conf_auth_result *result_out,
                          const char **failure_reason_out)
{
  assert(klass);
  assert(client);
  assert(!client_has_flag(client, FLAGS_IPHASH));

  struct ip_entry *const ipcache = ipcache_record_find_or_add(&client->addr);
  ++ipcache->count_local;
  client_set_flag(client, FLAGS_IPHASH);

  if (exempt_limits)
  {
    class_ip_limit_add(klass, &client->addr, CLASS_IP_LIMIT_ACCOUNT_ONLY);
    return true;
  }

  if (klass->max_total && klass->ref_count >= klass->max_total)
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_CLASS_TOTAL_LIMIT,
                           "connection class full: total limit reached");
    return false;
  }

  if (klass->max_perip_local && ipcache->count_local > klass->max_perip_local)
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_CLASS_LOCAL_IP_LIMIT,
                           "connection class full: local per-IP limit reached");
    return false;
  }

  if (klass->max_perip_global &&
      ipcache->count_local + ipcache->count_remote > klass->max_perip_global)
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_CLASS_GLOBAL_IP_LIMIT,
                           "connection class full: global per-IP limit reached");
    return false;
  }

  if (class_ip_limit_add(klass, &client->addr, CLASS_IP_LIMIT_ENFORCE))
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_CLASS_CIDR_LIMIT,
                           "connection class full: CIDR subnet limit reached");
    return false;
  }

  return true;
}

void
conf_auth_init(void)
{
  assert(!_conf_auth_is_initialized());
  assert(conf_auth_registry.items.head == NULL);
  assert(conf_auth_registry.items.tail == NULL);

  list_init(&conf_auth_registry.items);
  conf_auth_registry.initialized = true;

  _conf_auth_assert_initialized();
}

struct conf_auth *
conf_auth_add(const struct conf_auth_spec *spec)
{
  _conf_auth_assert_initialized();

  if (!_conf_auth_spec_is_valid(spec))
    return NULL;

  struct conf_auth_rule *const rule = _conf_auth_rule_create(spec->user, spec->host);
  if (rule == NULL)
    return NULL;

  struct conf_auth *const auth = io_calloc(sizeof(*auth));
  list_init(&auth->rules);

  if (!string_is_empty(spec->password))
    auth->password = io_strdup(spec->password);
  if (!string_is_empty(spec->spoof))
    auth->spoof = io_strdup(spec->spoof);

  auth->flags = spec->flags;
  _conf_auth_assign_class(auth, spec->class_name, spec->user, spec->host);

  list_add_tail(rule, &rule->node, &auth->rules);
  list_add_tail(auth, &auth->node, &conf_auth_registry.items);

  _conf_auth_assert_initialized();
  return auth;
}

bool
conf_auth_add_rule(struct conf_auth *auth, const char *user, const char *host)
{
  _conf_auth_assert_initialized();
  assert(auth);
  assert(!string_is_empty(user));
  assert(!string_is_empty(host));

  if (auth == NULL || auth->node.data != auth || string_is_empty(user) || string_is_empty(host))
    return false;

  _conf_auth_assert_valid(auth);

  struct conf_auth_rule *const rule = _conf_auth_rule_create(user, host);
  if (rule == NULL)
    return false;

  list_add_tail(rule, &rule->node, &auth->rules);

  _conf_auth_assert_initialized();
  return true;
}

enum conf_auth_lookup_result
conf_auth_find(const char *hostname, const struct io_addr *address,
               const char *username, const char *password, const struct conf_auth **auth_out)
{
  _conf_auth_assert_initialized();
  assert(!string_is_empty(hostname) || address);
  assert(!string_is_empty(username));
  assert(auth_out);

  if (auth_out == NULL)
    return CONF_AUTH_LOOKUP_NONE;

  *auth_out = NULL;

  if ((string_is_empty(hostname) && address == NULL) || string_is_empty(username))
    return CONF_AUTH_LOOKUP_NONE;

  list_node_t *node;
  LIST_FOREACH(node, conf_auth_registry.items.head)
  {
    const struct conf_auth *const auth = node->data;
    assert(&auth->node == node);

    if (!_conf_auth_matches(auth, hostname, address, username))
      continue;

    if (_conf_auth_password_matches(auth, password))
    {
      *auth_out = auth;
      return CONF_AUTH_LOOKUP_MATCH;
    }

    if (auth->flags & CONF_AUTH_FLAG_REJECT_PASSWORD_MISMATCH)
    {
      *auth_out = auth;
      return CONF_AUTH_LOOKUP_PASSWORD_MISMATCH;
    }
  }

  return CONF_AUTH_LOOKUP_NONE;
}

const struct conf_auth *
conf_auth_authorize_client(struct Client *client, enum conf_auth_result *result_out,
                           const char **failure_reason_out)
{
  _conf_auth_assert_initialized();
  assert(client);
  assert(client == NULL || client_is_local(client));
  assert(result_out);
  assert(failure_reason_out);

  if (client == NULL || result_out == NULL || failure_reason_out == NULL)
    return NULL;

  *result_out = CONF_AUTH_SUCCESS;
  *failure_reason_out = NULL;

  char username[USERLEN + 1] = "~";

  if (client_has_flag(client, FLAGS_GOTID))
    strlcpy(username, client->username, sizeof(username));
  else
    strlcpy(username + 1, client->username, sizeof(username) - 1);

  const struct conf_auth *auth = NULL;
  const enum conf_auth_lookup_result lookup_result =
    conf_auth_find(client->host, &client->addr, username, client->connection->password, &auth);

  if (lookup_result == CONF_AUTH_LOOKUP_NONE)
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_NO_BLOCK, "no matching auth block");
    return NULL;
  }

  assert(auth);

  if ((auth->flags & CONF_AUTH_FLAG_EXEMPT_KLINE) == 0)
  {
    const struct conf_kill *const kill = conf_kill_find(&client->addr, username, client->host);
    if (kill)
    {
      _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_KLINE_MATCH,
                             string_or_default(kill->reason, "K-lined"));
      return NULL;
    }
  }

  if ((auth->flags & CONF_AUTH_FLAG_REQUIRE_IDENT) && !client_has_flag(client, FLAGS_GOTID))
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_IDENT_REQUIRED, "ident required");
    return NULL;
  }

  if (lookup_result == CONF_AUTH_LOOKUP_PASSWORD_MISMATCH)
  {
    _conf_auth_set_failure(result_out, failure_reason_out, CONF_AUTH_PASSWORD_MISMATCH, "password mismatch");
    return NULL;
  }

  assert(lookup_result == CONF_AUTH_LOOKUP_MATCH);

  if (!client_has_flag(client, FLAGS_GOTID) && (auth->flags & CONF_AUTH_FLAG_NO_TILDE) == 0)
    strlcpy(client->username, username, sizeof(client->username));

  strlcpy(client->realhost, client->host, sizeof(client->realhost));

  if (!string_is_empty(auth->spoof))
  {
    strlcpy(client->host, auth->spoof, sizeof(client->host));
    client_set_flag(client, FLAGS_SPOOF);
  }

  if (!_conf_auth_admit_to_class(auth->klass, client, (auth->flags & CONF_AUTH_FLAG_EXEMPT_LIMITS) != 0,
        result_out, failure_reason_out))
    return NULL;

  client_set_class(client, auth->klass, CLIENT_CLASS_BASE);

  _conf_auth_password_free(&client->connection->password);
  return auth;
}

const list_t *
conf_auth_get_list(void)
{
  _conf_auth_assert_initialized();
  return &conf_auth_registry.items;
}

void
conf_auth_clear(void)
{
  _conf_auth_assert_initialized();

  while (conf_auth_registry.items.head)
    _conf_auth_destroy(conf_auth_registry.items.head->data);

  _conf_auth_assert_initialized();
}
