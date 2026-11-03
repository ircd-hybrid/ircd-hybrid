/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "cap.h"
#include "client.h"
#include "ircd_hook.h"
#include "send.h"

enum
{
  /* Leave room for a continued ACK containing a negative capability name. */
  CAP_NAME_LENGTH_MAX = IRCD_BUFSIZE - 2 -
                       (1 + HOSTLEN + sizeof(" CAP ") - 1 + HOSTLEN + sizeof(" ACK * :-") - 1)
};

static list_t cap_list;
static void **cap_array;
static size_t cap_array_size;
static bool cap_array_stale;

static bool
_cap_name_is_valid(const char *name)
{
  if (string_is_empty(name) || *name == '-' || strlen(name) > CAP_NAME_LENGTH_MAX)
    return false;

  for (const unsigned char *p = (const unsigned char *)name; *p; ++p)
    if (*p <= ' ' || *p == 0x7f || *p == '=')
      return false;

  return true;
}

static bool
_cap_value_is_valid(const char *value)
{
  if (value == NULL)
    return true;

  for (const unsigned char *p = (const unsigned char *)value; *p; ++p)
    if (*p <= ' ' || *p == 0x7f)
      return false;

  return true;
}

static bool
_cap_value_fits(const struct Client *client, const struct Cap *cap)
{
  const char *const prefix = client_get_id_or_name(&me, client);
  const char *destination = client_get_id_or_name(client, client);
  if (string_is_empty(destination))
    destination = "*";

  const size_t overhead = 1 + strlen(prefix) + sizeof(" CAP ") - 1 + strlen(destination) +
                          sizeof(" NEW :") - 1 + cap->name_len + 1;
  return overhead <= IRCD_BUFSIZE - 2 && cap->value_len <= IRCD_BUFSIZE - 2 - overhead;
}

static void
_cap_notify_clients(void *const clients[], size_t count, const struct Cap *cap, bool removed)
{
  for (size_t i = 0; i < count; ++i)
  {
    struct Client *const client = clients[i];
    if (client_is_dead(client) || (!client_is_unknown(client) && !client_is_local_user(client)))
      continue;

    if (client_has_cap(client, CAP_CAP_NOTIFY))
    {
      if (!removed && cap->value && client_has_flag(client, FLAGS_CAP302) && _cap_value_fits(client, cap))
        sendto_one_command(client, &me, "CAP", "NEW :%s=%s", cap->name, cap->value);
      else
        sendto_one_command(client, &me, "CAP", "%s :%s", removed ? "DEL" : "NEW", cap->name);
    }

    if (removed)
      cap_client_set(client, client->connection->cap_flags & ~cap->flag);
  }
}

static void
_cap_notify(struct Cap *cap, bool removed)
{
  /* A change notification must not recursively mutate its own capability. */
  assert(!cap->notifying);
  cap->notifying = true;

  /* Exit hooks can detach other clients; their destruction is deferred. */
  const size_t unknown_count = list_length(&unknown_list);
  const size_t local_count = list_length(&local_client_list);
  void **const unknown_clients = list_to_array(&unknown_list);
  void **const local_clients = list_to_array(&local_client_list);

  _cap_notify_clients(unknown_clients, unknown_count, cap, removed);
  _cap_notify_clients(local_clients, local_count, cap, removed);
  io_free(unknown_clients);
  io_free(local_clients);
  cap->notifying = false;
}

static void
_cap_update(struct Cap *cap, const char *value, bool available)
{
  const bool value_changed = (cap->value == NULL) != (value == NULL) ||
                             (cap->value && value && strcmp(cap->value, value) != 0);
  const bool was_available = cap->available;
  if (!value_changed && was_available == available)
    return;

  /* Idempotent refreshes are safe while a change is being announced. */
  assert(!cap->notifying);

  if (value_changed)
  {
    char *const replacement = value ? io_strdup(value) : NULL;
    io_free(cap->value);
    cap->value = replacement;
    cap->value_len = replacement ? strlen(replacement) : 0;
  }

  cap->available = available;
  if (available)
    _cap_notify(cap, false);
  else if (was_available)
    _cap_notify(cap, true);
}

void
cap_client_set(struct Client *client, uint32_t flags)
{
  assert(client);
  assert(client_is_local(client));

  const uint32_t previous = client->connection->cap_flags;
  if (flags == previous)
    return;

  client->connection->cap_flags = flags;

  hook_dispatch(ircd_hook_cap_change, &(ircd_hook_cap_change_ctx)
  {
    .client = client,
    .added = flags & ~previous,
    .removed = previous & ~flags
  });
}

const list_t *
cap_get_list(void)
{
  return &cap_list;
}

static int
_cap_compare_direct(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct Cap *)a_)->name;
  const char *const b = ((const struct Cap *)b_)->name;
  return strcmp(a, b);
}

static int
_cap_compare_name(const void *const name_, const void *const entry_)
{
  const char *const name = name_;
  const struct Cap *const cap = *(void *const *)entry_;
  return strcmp(name, cap->name);
}

cap_result_t
cap_register(const struct CapConfig *config, struct Cap **cap_out)
{
  assert(config);
  assert(cap_out);
  assert(*cap_out == NULL);

  if (!_cap_name_is_valid(config->name))
    return CAP_INVALID_NAME;
  if (config->flag == 0 || (config->flag & (config->flag - 1)))
    return CAP_INVALID_FLAG;
  if (!_cap_value_is_valid(config->value))
    return CAP_INVALID_VALUE;
  if (cap_find(config->name))
    return CAP_ALREADY_REGISTERED;

  list_node_t *node;
  LIST_FOREACH(node, cap_list.head)
  {
    const struct Cap *const cap = node->data;
    if (cap->flag == config->flag)
      return CAP_FLAG_CONFLICT;
  }

  struct Cap *const cap = io_calloc(sizeof(*cap));
  cap->flag = config->flag;
  cap->name = io_strdup(config->name);
  cap->name_len = strlen(config->name);
  list_add_sorted(cap, &cap->node, &cap_list, _cap_compare_direct);

  cap_array_stale = true;
  *cap_out = cap;
  _cap_update(cap, config->value, config->available);

  return CAP_SUCCESS;
}

cap_result_t
cap_update(struct Cap *cap, const char *value, bool available)
{
  assert(cap);
  assert(cap_find(cap->name) == cap);

  if (!_cap_value_is_valid(value))
    return CAP_INVALID_VALUE;

  _cap_update(cap, value, available);
  return CAP_SUCCESS;
}

void
cap_unregister(struct Cap **cap_ptr)
{
  assert(cap_ptr);

  struct Cap *const cap = *cap_ptr;
  if (cap == NULL)
    return;

  assert(cap_find(cap->name) == cap);
  assert(!cap->notifying);

  /* Keep the name and flag reserved until all DEL notifications have completed. */
  _cap_update(cap, NULL, false);
  list_remove(&cap->node, &cap_list);
  cap_array_stale = true;
  *cap_ptr = NULL;

  io_free(cap->name);
  io_free(cap->value);
  io_free(cap);
}

static void
_cap_array_update(void)
{
  cap_array_stale = false;

  io_free(cap_array);
  cap_array = NULL;
  cap_array_size = 0;

  if (list_is_empty(&cap_list))
    return;

  cap_array = list_to_array(&cap_list);
  cap_array_size = list_length(&cap_list);
}

const struct Cap *
cap_find(const char *name)
{
  if (cap_array_stale)
    _cap_array_update();

  if (cap_array_size == 0)
    return NULL;

  void **cap = bsearch(name, cap_array, cap_array_size, sizeof(*cap_array), _cap_compare_name);

  return cap ? *cap : NULL;
}
