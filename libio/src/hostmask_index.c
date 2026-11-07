/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file hostmask_index.c
 * @brief Indexed matching of wildcard hostname masks.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "hostmask_index.h"
#include "io_string.h"
#include "memory.h"

enum
{
  HOSTMASK_INDEX_BUCKET_COUNT = 4096
};

_Static_assert(HOSTMASK_INDEX_BUCKET_COUNT > 0 &&
               (HOSTMASK_INDEX_BUCKET_COUNT & (HOSTMASK_INDEX_BUCKET_COUNT - 1)) == 0,
               "HOSTMASK_INDEX_BUCKET_COUNT must be a non-zero power of two");

static const uint64_t hostmask_hash_offset_basis = UINT64_C(14695981039346656037);
static const uint64_t hostmask_hash_prime = UINT64_C(1099511628211);

struct hostmask_index
{
  struct hostmask_index_entry *buckets[HOSTMASK_INDEX_BUCKET_COUNT];
  struct hostmask_index_entry *fallback;
  size_t count;

#ifndef NDEBUG
  size_t iteration_depth;
#endif
};

struct hostmask_index_entry
{
  struct hostmask_index_entry *next;
  struct hostmask_index_entry **previous_link;
  struct hostmask_index *index;
  void *data;
  uint64_t suffix_hash;
  size_t suffix_length;
  char mask[];
};

struct hostmask_index_suffix
{
  const char *text;
  size_t length;
};

static void
_hostmask_index_assert_not_iterating(const struct hostmask_index *index)
{
  assert(index);

#ifndef NDEBUG
  assert(index->iteration_depth == 0);
#else
  (void)index;
#endif
}

static void
_hostmask_index_entry_link(struct hostmask_index_entry **head, struct hostmask_index_entry *entry)
{
  assert(head);
  assert(entry);
  assert(entry->index);
  assert(entry->next == NULL);
  assert(entry->previous_link == NULL);

  if (*head)
  {
    assert((*head)->index == entry->index);
    assert((*head)->previous_link == head);
  }

  entry->next = *head;
  entry->previous_link = head;

  if (entry->next)
    entry->next->previous_link = &entry->next;

  *head = entry;
}

static void
_hostmask_index_entry_unlink(struct hostmask_index_entry *entry)
{
  assert(entry);
  assert(entry->index);
  assert(entry->previous_link);
  assert(*entry->previous_link == entry);

  if (entry->next)
  {
    assert(entry->next != entry);
    assert(entry->next->index == entry->index);
    assert(entry->next->previous_link == &entry->next);
  }

  struct hostmask_index_entry *const next = entry->next;
  struct hostmask_index_entry **const previous_link = entry->previous_link;

  *previous_link = next;
  if (next)
    next->previous_link = previous_link;

#ifndef NDEBUG
  entry->next = NULL;
  entry->previous_link = NULL;
#endif
}

static size_t
_hostmask_index_find_last_wildcard_offset(const char *mask, size_t mask_length)
{
  assert(mask);

  size_t wildcard_offset = SIZE_MAX;

  for (size_t i = 0; i < mask_length; ++i)
  {
    if (mask[i] == '\\')
    {
      if (i + 1 < mask_length)
        ++i;

      continue;
    }

    if (mask[i] == '*' || mask[i] == '?')
      wildcard_offset = i;
  }

  return wildcard_offset;
}

static bool
_hostmask_index_find_literal_suffix(const char *mask, size_t mask_length, struct hostmask_index_suffix *suffix)
{
  assert(mask);
  assert(suffix);

  if (mask_length == 0)
    return false;

  size_t suffix_offset = 0;
  const size_t wildcard_offset = _hostmask_index_find_last_wildcard_offset(mask, mask_length);

  /*
   * Lookups enumerate hostname suffixes only at label boundaries. After the
   * final wildcard, use the first complete following label as the longest
   * suffix that can be indexed without excluding a valid match.
   */
  if (wildcard_offset != SIZE_MAX)
  {
    const char *const label_separator =
      memchr(mask + wildcard_offset + 1, '.', mask_length - wildcard_offset - 1);
    if (label_separator == NULL)
      return false;

    suffix_offset = (size_t)(label_separator - mask) + 1;
    if (suffix_offset == mask_length)
      return false;
  }

  /*
   * match() compares escaped characters byte-exactly. A suffix containing
   * escape syntax therefore cannot use the case-folded hash safely.
   */
  if (memchr(mask + suffix_offset, '\\', mask_length - suffix_offset))
    return false;

  suffix->text = mask + suffix_offset;
  suffix->length = mask_length - suffix_offset;

  return suffix->length != 0;
}

static inline uint64_t
_hostmask_hash_update(uint64_t hash_state, unsigned char byte)
{
  hash_state ^= io_ascii_to_lower_table[byte];
  hash_state *= hostmask_hash_prime;

  return hash_state;
}

static inline uint64_t
_hostmask_hash_finalize(uint64_t hash_state, size_t length)
{
  hash_state ^= (uint64_t)length * UINT64_C(0x9e3779b97f4a7c15);
  hash_state ^= hash_state >> 33;
  hash_state *= UINT64_C(0xff51afd7ed558ccd);
  hash_state ^= hash_state >> 33;
  hash_state *= UINT64_C(0xc4ceb9fe1a85ec53);
  hash_state ^= hash_state >> 33;

  return hash_state;
}

static uint64_t
_hostmask_hash_suffix(const char *suffix, size_t suffix_length)
{
  assert(suffix);
  assert(suffix_length > 0);

  uint64_t hash_state = hostmask_hash_offset_basis;

  for (size_t i = suffix_length; i != 0; )
  {
    --i;
    hash_state = _hostmask_hash_update(hash_state, (unsigned char)suffix[i]);
  }

  return _hostmask_hash_finalize(hash_state, suffix_length);
}

static inline size_t
_hostmask_index_bucket_index(uint64_t hash)
{
  return (size_t)(hash & (HOSTMASK_INDEX_BUCKET_COUNT - 1));
}

static bool
_hostmask_index_foreach_suffix_match(const struct hostmask_index *index, const char *hostname, size_t hostname_length,
                                     hostmask_index_foreach_fn callback, void *callback_ctx)
{
  assert(index);
  assert(hostname);
  assert(callback);

  uint64_t hash_state = hostmask_hash_offset_basis;
  const char *const hostname_end = hostname + hostname_length;
  const char *cursor = hostname_end;

  while (cursor != hostname)
  {
    --cursor;
    hash_state = _hostmask_hash_update(hash_state, (unsigned char)*cursor);

    /*
     * Candidate suffixes begin either at the start of the hostname or
     * immediately after a dot.
     */
    if (cursor != hostname && cursor[-1] != '.')
      continue;

    const size_t hostname_suffix_length = (size_t)(hostname_end - cursor);
    const uint64_t hostname_suffix_hash = _hostmask_hash_finalize(hash_state, hostname_suffix_length);
    const size_t bucket_index = _hostmask_index_bucket_index(hostname_suffix_hash);

    for (const struct hostmask_index_entry *entry = index->buckets[bucket_index]; entry; entry = entry->next)
    {
      assert(entry->index == index);
      assert(entry->previous_link);
      assert(*entry->previous_link == entry);
      assert(entry->suffix_length > 0);

      if (entry->suffix_hash != hostname_suffix_hash || entry->suffix_length != hostname_suffix_length)
        continue;

      if (match(entry->mask, hostname))
        continue;

      if (!callback(entry, callback_ctx))
        return false;
    }
  }

  return true;
}

static bool
_hostmask_index_foreach_fallback_match(const struct hostmask_index *index, const char *hostname,
                                       hostmask_index_foreach_fn callback, void *callback_ctx)
{
  assert(index);
  assert(hostname);
  assert(callback);

  for (const struct hostmask_index_entry *entry = index->fallback; entry; entry = entry->next)
  {
    assert(entry->index == index);
    assert(entry->previous_link);
    assert(*entry->previous_link == entry);
    assert(entry->suffix_length == 0);

    if (match(entry->mask, hostname))
      continue;

    if (!callback(entry, callback_ctx))
      return false;
  }

  return true;
}

static void
_hostmask_index_clear_chain(struct hostmask_index *index, struct hostmask_index_entry **head)
{
  assert(index);
  assert(head);

  while (*head)
  {
    struct hostmask_index_entry *const entry = *head;

    assert(entry->index == index);
    assert(entry->previous_link == head);
    assert(index->count > 0);

    _hostmask_index_entry_unlink(entry);
    --index->count;
    io_free(entry);
  }
}

hostmask_index_t *
hostmask_index_create(void)
{
  struct hostmask_index *const index = io_calloc(sizeof(*index));
  return index;
}

void
hostmask_index_destroy(hostmask_index_t *index)
{
  if (index == NULL)
    return;

  _hostmask_index_assert_not_iterating(index);

  for (size_t i = 0; i < HOSTMASK_INDEX_BUCKET_COUNT; ++i)
    _hostmask_index_clear_chain(index, &index->buckets[i]);

  _hostmask_index_clear_chain(index, &index->fallback);

  assert(index->count == 0);

  io_free(index);
}

hostmask_index_entry_t *
hostmask_index_add(hostmask_index_t *index, const char *mask, void *data)
{
  assert(index);
  assert(mask);

  _hostmask_index_assert_not_iterating(index);

  if (index->count == SIZE_MAX)
    return NULL;

  const size_t mask_length = strlen(mask);
  if (mask_length > SIZE_MAX - sizeof(struct hostmask_index_entry) - 1)
    return NULL;

  struct hostmask_index_suffix suffix;
  const bool has_suffix = _hostmask_index_find_literal_suffix(mask, mask_length, &suffix);

  uint64_t suffix_hash = 0;
  struct hostmask_index_entry **chain_head;

  if (has_suffix)
  {
    suffix_hash = _hostmask_hash_suffix(suffix.text, suffix.length);
    chain_head = &index->buckets[_hostmask_index_bucket_index(suffix_hash)];
  }
  else
    chain_head = &index->fallback;

  struct hostmask_index_entry *const entry = io_calloc(sizeof(*entry) + mask_length + 1);
  entry->index = index;
  entry->data = data;

  if (has_suffix)
  {
    entry->suffix_hash = suffix_hash;
    entry->suffix_length = suffix.length;
  }

  memcpy(entry->mask, mask, mask_length + 1);

  _hostmask_index_entry_link(chain_head, entry);
  ++index->count;

  return entry;
}

void *
hostmask_index_remove(hostmask_index_entry_t *entry)
{
  assert(entry);
  assert(entry->index);

  struct hostmask_index *const index = entry->index;

  _hostmask_index_assert_not_iterating(index);
  assert(index->count > 0);

  void *const data = entry->data;

  _hostmask_index_entry_unlink(entry);
  --index->count;
  io_free(entry);

  return data;
}

bool
hostmask_index_foreach_match(hostmask_index_t *index, const char *hostname,
                             hostmask_index_foreach_fn callback, void *callback_ctx)
{
  assert(index);
  assert(hostname);
  assert(callback);

#ifndef NDEBUG
  assert(index->iteration_depth < SIZE_MAX);
  ++index->iteration_depth;
#endif

  bool completed =
    _hostmask_index_foreach_suffix_match(index, hostname, strlen(hostname), callback, callback_ctx);
  if (completed)
    completed = _hostmask_index_foreach_fallback_match(index, hostname, callback, callback_ctx);

#ifndef NDEBUG
  assert(index->iteration_depth > 0);
  --index->iteration_depth;
#endif

  return completed;
}

const char *
hostmask_index_entry_get_mask(const hostmask_index_entry_t *entry)
{
  assert(entry);
  return entry->mask;
}

void *
hostmask_index_entry_get_data(const hostmask_index_entry_t *entry)
{
  assert(entry);
  return entry->data;
}

size_t
hostmask_index_count(const hostmask_index_t *index)
{
  assert(index);
  return index->count;
}
