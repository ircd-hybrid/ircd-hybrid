/*
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <limits.h>
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
  CAP_COUNT_MAX = sizeof(uint32_t) * CHAR_BIT,
  /* Leave room for a continued ACK containing a negative capability name. */
  CAP_NAME_LENGTH_MAX = IRCD_BUFSIZE - 2 -
                       (1 + HOSTLEN + sizeof(" CAP ") - 1 + HOSTLEN + sizeof(" ACK * :-") - 1)
};

static list_t cap_registry;
static void **cap_name_index;
static size_t cap_name_index_count;
static bool cap_name_index_stale;

struct CapSnapshotEntry
{
  char *name;
  char *value;
  size_t name_len;
  size_t value_len;
  uint32_t flag;
};

struct CapSnapshot
{
  struct CapSnapshotEntry entries[CAP_COUNT_MAX];
  size_t entry_count;
};

struct CapNotifyPlan
{
  struct CapSnapshot before;
  struct CapSnapshot after;
  uint32_t del_flags;
  uint32_t new_flags;
};

static struct CapNotifyBatch
{
  struct CapSnapshot baseline;
  const struct CapNotifyPlan *active_plan;
  uint32_t withdrawn_flags;
  unsigned int depth;
  bool has_baseline;
} cap_notify_batch;

enum cap_notify_subcommand
{
  CAP_NOTIFY_DEL,
  CAP_NOTIFY_NEW
};

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
_cap_value_equal(const char *lhs, const char *rhs)
{
  return lhs == rhs || (lhs && rhs && strcmp(lhs, rhs) == 0);
}

static void
_cap_snapshot_capture(struct CapSnapshot *snapshot)
{
  assert(snapshot->entry_count == 0);

  list_node_t *node;
  LIST_FOREACH(node, cap_registry.head)
  {
    const struct Cap *const cap = node->data;
    if (!cap->available)
      continue;

    assert(snapshot->entry_count < CAP_COUNT_MAX);
    struct CapSnapshotEntry *const entry = &snapshot->entries[snapshot->entry_count++];
    entry->name = io_strdup(cap->name);
    entry->value = cap->value ? io_strdup(cap->value) : NULL;
    entry->name_len = cap->name_len;
    entry->value_len = cap->value_len;
    entry->flag = cap->flag;
  }
}

static void
_cap_snapshot_clear(struct CapSnapshot *snapshot)
{
  for (size_t i = 0; i < snapshot->entry_count; ++i)
  {
    io_free(snapshot->entries[i].name);
    io_free(snapshot->entries[i].value);
  }

  snapshot->entry_count = 0;
}

static const struct CapSnapshotEntry *
_cap_snapshot_find_by_flag(const struct CapSnapshot *snapshot, uint32_t flag)
{
  for (size_t i = 0; i < snapshot->entry_count; ++i)
    if (snapshot->entries[i].flag == flag)
      return &snapshot->entries[i];

  return NULL;
}

static bool
_cap_snapshot_has_flag_conflict(const struct CapSnapshot *snapshot, uint32_t flag, const char *name)
{
  const struct CapSnapshotEntry *const entry = _cap_snapshot_find_by_flag(snapshot, flag);
  return entry && strcmp(entry->name, name) != 0;
}

static bool
_cap_has_reserved_flag_conflict(uint32_t flag, const char *name)
{
  if (_cap_snapshot_has_flag_conflict(&cap_notify_batch.baseline, flag, name))
    return true;

  return cap_notify_batch.active_plan &&
         (_cap_snapshot_has_flag_conflict(&cap_notify_batch.active_plan->before, flag, name) ||
          _cap_snapshot_has_flag_conflict(&cap_notify_batch.active_plan->after, flag, name));
}

static void
_cap_notify_plan_prepare(struct CapNotifyPlan *plan, uint32_t withdrawn_flags)
{
  for (size_t i = 0; i < plan->before.entry_count; ++i)
  {
    const struct CapSnapshotEntry *const before_entry = &plan->before.entries[i];
    const struct CapSnapshotEntry *const after_entry = _cap_snapshot_find_by_flag(&plan->after, before_entry->flag);
    if ((withdrawn_flags & before_entry->flag) || after_entry == NULL ||
        strcmp(before_entry->name, after_entry->name) != 0)
      plan->del_flags |= before_entry->flag;
  }

  for (size_t i = 0; i < plan->after.entry_count; ++i)
  {
    const struct CapSnapshotEntry *const after_entry = &plan->after.entries[i];
    const struct CapSnapshotEntry *const before_entry = _cap_snapshot_find_by_flag(&plan->before, after_entry->flag);
    if ((plan->del_flags & after_entry->flag) || before_entry == NULL ||
        strcmp(before_entry->name, after_entry->name) != 0 ||
        !_cap_value_equal(before_entry->value, after_entry->value))
      plan->new_flags |= after_entry->flag;
  }
}

static void
_cap_notify_send_list(struct Client *client, const struct CapSnapshot *snapshot,
                      uint32_t selected_flags, enum cap_notify_subcommand subcommand)
{
  if (selected_flags == 0)
    return;

  const char *const subcommand_name = subcommand == CAP_NOTIFY_DEL ? "DEL" : "NEW";
  const bool include_values = subcommand == CAP_NOTIFY_NEW && client_has_flag(client, FLAGS_CAP302);
  const char *const prefix = client_get_id_or_name(&me, client);
  const char *destination = client_get_id_or_name(client, client);

  if (string_is_empty(destination))
    destination = "*";

  const size_t header_length = 1 + strlen(prefix) + sizeof(" CAP ") - 1 + strlen(destination) +
                               1 + strlen(subcommand_name) + sizeof(" :") - 1;
  assert(header_length < IRCD_BUFSIZE - 2);
  if (header_length >= IRCD_BUFSIZE - 2)
    return;

  const size_t caplist_limit = IRCD_BUFSIZE - 2 - header_length;
  char caplist[IRCD_BUFSIZE];
  size_t caplist_length = 0;

  for (size_t i = 0; i < snapshot->entry_count; ++i)
  {
    const struct CapSnapshotEntry *const entry = &snapshot->entries[i];
    if (!(selected_flags & entry->flag))
      continue;

    assert(entry->name_len <= caplist_limit);
    const bool include_value = include_values && entry->value && entry->name_len < caplist_limit &&
                               entry->value_len <= caplist_limit - entry->name_len - 1;
    const size_t entry_length = entry->name_len + (include_value ? 1 + entry->value_len : 0);

    if (caplist_length && caplist_length + 1 + entry_length > caplist_limit)
    {
      caplist[caplist_length] = '\0';
      sendto_one_command(client, &me, "CAP", "%s :%s", subcommand_name, caplist);
      caplist_length = 0;
    }

    if (caplist_length)
      caplist[caplist_length++] = ' ';

    memcpy(caplist + caplist_length, entry->name, entry->name_len);
    caplist_length += entry->name_len;

    if (include_value)
    {
      caplist[caplist_length++] = '=';
      memcpy(caplist + caplist_length, entry->value, entry->value_len);
      caplist_length += entry->value_len;
    }
  }

  if (caplist_length)
  {
    caplist[caplist_length] = '\0';
    sendto_one_command(client, &me, "CAP", "%s :%s", subcommand_name, caplist);
  }
}

static void
_cap_notify_clients(void *const clients[], size_t client_count, const struct CapNotifyPlan *plan)
{
  for (size_t i = 0; i < client_count; ++i)
  {
    struct Client *const client = clients[i];
    if (client_is_dead(client) || (!client_is_unknown(client) && !client_is_local_user(client)))
      continue;

    if (client_has_cap(client, CAP_CAP_NOTIFY))
      _cap_notify_send_list(client, &plan->before, plan->del_flags, CAP_NOTIFY_DEL);

    cap_client_set_flags(client, client->connection->cap_flags & ~plan->del_flags);

    if (!client_is_dead(client) && client_has_cap(client, CAP_CAP_NOTIFY))
      _cap_notify_send_list(client, &plan->after, plan->new_flags, CAP_NOTIFY_NEW);
  }
}

static void
_cap_notify_publish(const struct CapNotifyPlan *plan)
{
  if (plan->del_flags == 0 && plan->new_flags == 0)
    return;

  /* Exit hooks can detach other clients; their destruction is deferred. */
  const size_t unknown_client_count = list_length(&unknown_list);
  const size_t local_client_count = list_length(&local_client_list);
  void **const unknown_clients = list_to_array(&unknown_list);
  void **const local_clients = list_to_array(&local_client_list);

  _cap_notify_clients(unknown_clients, unknown_client_count, plan);
  _cap_notify_clients(local_clients, local_client_count, plan);

  io_free(unknown_clients);
  io_free(local_clients);
}

/* Only the outermost scope publishes notifications; hooks may queue a later round. */
void
cap_notify_batch_begin(void)
{
  assert(cap_notify_batch.depth < UINT_MAX);

  if (!cap_notify_batch.has_baseline)
  {
    _cap_snapshot_capture(&cap_notify_batch.baseline);
    cap_notify_batch.has_baseline = true;
  }

  ++cap_notify_batch.depth;
}

void
cap_notify_batch_end(void)
{
  assert(cap_notify_batch.depth);

  if (--cap_notify_batch.depth || cap_notify_batch.active_plan)
    return;

  while (cap_notify_batch.has_baseline && cap_notify_batch.depth == 0)
  {
    struct CapNotifyPlan plan = { .before = cap_notify_batch.baseline };
    cap_notify_batch.baseline = (struct CapSnapshot){ 0 };

    _cap_snapshot_capture(&plan.after);
    _cap_notify_plan_prepare(&plan, cap_notify_batch.withdrawn_flags);
    cap_notify_batch.withdrawn_flags = 0;
    cap_notify_batch.has_baseline = false;
    cap_notify_batch.active_plan = &plan;
    _cap_notify_publish(&plan);
    cap_notify_batch.active_plan = NULL;
    _cap_snapshot_clear(&plan.before);
    _cap_snapshot_clear(&plan.after);
  }
}

static void
_cap_update(struct Cap *cap, const char *value, bool available)
{
  const bool value_changed = !_cap_value_equal(cap->value, value);
  const bool was_available = cap->available;

  if (!value_changed && was_available == available)
    return;

  cap_notify_batch_begin();

  if (was_available && !available)
    cap_notify_batch.withdrawn_flags |= cap->flag;

  if (value_changed)
  {
    char *const replacement = value ? io_strdup(value) : NULL;

    io_free(cap->value);
    cap->value = replacement;
    cap->value_len = replacement ? strlen(replacement) : 0;
  }

  cap->available = available;
  cap_notify_batch_end();
}

void
cap_client_set_flags(struct Client *client, uint32_t new_flags)
{
  assert(client);
  assert(client_is_local(client));

  const uint32_t previous_flags = client->connection->cap_flags;
  if (new_flags == previous_flags)
    return;

  client->connection->cap_flags = new_flags;

  hook_dispatch(ircd_hook_cap_change, &(ircd_hook_cap_change_ctx)
  {
    .client = client,
    .added = new_flags & ~previous_flags,
    .removed = previous_flags & ~new_flags
  });
}

const list_t *
cap_get_list(void)
{
  return &cap_registry;
}

static int
_cap_compare_names(const void *const lhs, const void *const rhs)
{
  const char *const lhs_name = ((const struct Cap *)lhs)->name;
  const char *const rhs_name = ((const struct Cap *)rhs)->name;
  return strcmp(lhs_name, rhs_name);
}

static int
_cap_compare_name_key(const void *const name_key, const void *const index_entry)
{
  const char *const name = name_key;
  const struct Cap *const cap = *(void *const *)index_entry;
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
  LIST_FOREACH(node, cap_registry.head)
  {
    const struct Cap *const cap = node->data;
    if (cap->flag == config->flag)
      return CAP_FLAG_CONFLICT;
  }

  if (_cap_has_reserved_flag_conflict(config->flag, config->name))
    return CAP_FLAG_CONFLICT;

  struct Cap *const cap = io_calloc(sizeof(*cap));
  cap->flag = config->flag;
  cap->name = io_strdup(config->name);
  cap->name_len = strlen(config->name);
  list_add_sorted(cap, &cap->node, &cap_registry, _cap_compare_names);

  cap_name_index_stale = true;
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

  /* Snapshots reserve advertised flags until every client has seen DEL. */
  cap_notify_batch_begin();
  _cap_update(cap, NULL, false);
  list_remove(&cap->node, &cap_registry);
  cap_name_index_stale = true;
  *cap_ptr = NULL;

  io_free(cap->name);
  io_free(cap->value);
  io_free(cap);
  cap_notify_batch_end();
}

static void
_cap_name_index_rebuild(void)
{
  cap_name_index_stale = false;

  io_free(cap_name_index);
  cap_name_index = NULL;
  cap_name_index_count = 0;

  if (list_is_empty(&cap_registry))
    return;

  cap_name_index = list_to_array(&cap_registry);
  cap_name_index_count = list_length(&cap_registry);
}

const struct Cap *
cap_find(const char *name)
{
  if (cap_name_index_stale)
    _cap_name_index_rebuild();

  if (cap_name_index_count == 0)
    return NULL;

  void **match = bsearch(name, cap_name_index, cap_name_index_count, sizeof(*cap_name_index), _cap_compare_name_key);

  return match ? *match : NULL;
}
