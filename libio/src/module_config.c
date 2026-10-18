/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module_config.c
 * @brief Owned module configuration drafts and immutable manager snapshots.
 */

#include "config.h"

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

#include "io.h"
#include "io_string.h"
#include "memory.h"
#include "module.h"
#include "module_internal.h"

struct module_config
{
  struct module_config_entry *entries;
  size_t count;
  size_t capacity;
  char *base_path;
  bool manager_owned;
};

#ifndef NDEBUG
static bool
_module_config_is_valid(const struct module_config *config)
{
  assert(config);

  const size_t size_limit = SIZE_MAX / sizeof(*config->entries);
  const size_t capacity_limit = size_limit < UINT_MAX ? size_limit : UINT_MAX;

  if (config->count > config->capacity)
    return false;

  if ((config->entries == NULL) != (config->capacity == 0))
    return false;

  if (config->capacity > capacity_limit)
    return false;

  if (config->base_path &&
      (string_is_empty(config->base_path) || strlen(config->base_path) >= IO_PATH_MAX))
    return false;

  /* Drafts may be incomplete; manager-owned snapshots must be ready for use. */
  return !config->manager_owned || config->count == 0 || config->base_path != NULL;
}

static bool
_module_config_entries_are_valid(const struct module_config *config)
{
  assert(config);

  for (size_t i = 0; i < config->count; ++i)
  {
    const struct module_config_entry *const entry = &config->entries[i];
    if (!module_name_is_valid(entry->name) || (entry->policy_flags & ~MODULE_FLAG_VALID_MASK))
      return false;
  }

  return true;
}
#endif

static enum module_error_code
_module_config_mutation_validate(const struct module_config *config, struct module_error_info *error)
{
  if (config == NULL)
    return _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Module configuration is required");

  assert(_module_config_is_valid(config));

  if (config->manager_owned)
    return _module_error_set(error, MODULE_ERR_CONFIG_OWNED, NULL, "Module configuration belongs to a manager");

  return MODULE_SUCCESS;
}

static void
_module_config_free(struct module_config *config)
{
  assert(config);
  assert(_module_config_is_valid(config));

  io_free(config->entries);
  io_free(config->base_path);
  io_free(config);
}

enum module_error_code
_module_config_acquire(module_config_t *config, struct module_error_info *error)
{
  const enum module_error_code code = _module_config_mutation_validate(config, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (config->count && config->base_path == NULL)
    return _module_error_set(error, MODULE_ERR_BASE_PATH_NOT_SET, NULL,
                             "Module base path is required for a nonempty configuration");

  assert(_module_config_entries_are_valid(config));

  config->manager_owned = true;

  assert(_module_config_is_valid(config));

  return MODULE_SUCCESS;
}

void
_module_config_destroy_owned(module_config_t *config)
{
  assert(config);
  assert(config->manager_owned);

  _module_config_free(config);
}

module_config_t *
module_config_create(void)
{
  return io_calloc(sizeof(struct module_config));
}

enum module_error_code
module_config_destroy(module_config_t **config_slot, struct module_error_info *error)
{
  _module_error_clear(error);

  if (config_slot == NULL)
    return _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Module configuration ownership slot is required");

  if (*config_slot == NULL)
    return MODULE_SUCCESS;

  const enum module_error_code code = _module_config_mutation_validate(*config_slot, error);
  if (code != MODULE_SUCCESS)
    return code;

  _module_config_free(*config_slot);
  *config_slot = NULL;

  return MODULE_SUCCESS;
}

enum module_error_code
module_config_set_base_path(module_config_t *config, const char *base_path, struct module_error_info *error)
{
  _module_error_clear(error);

  const enum module_error_code code = _module_config_mutation_validate(config, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (string_is_empty(base_path))
    return _module_error_set(error, MODULE_ERR_INVALID_PATH, NULL, "Module base path must be nonempty");

  size_t length = 0;
  while (length < IO_PATH_MAX && base_path[length])
    ++length;

  if (length == IO_PATH_MAX)
    return _module_error_set(error, MODULE_ERR_PATH_TOO_LONG, NULL, "Module base path is too long");

  char *const copy = io_strdup(base_path);
  io_free(config->base_path);
  config->base_path = copy;

  assert(_module_config_is_valid(config));

  return MODULE_SUCCESS;
}

enum module_error_code
module_config_add(module_config_t *config, const char *name, module_flags_t policy_flags,
                  struct module_error_info *error)
{
  _module_error_clear(error);

  const enum module_error_code code = _module_config_mutation_validate(config, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (!module_name_is_valid(name))
    return _module_error_set(error, MODULE_ERR_INVALID_NAME, name, "Invalid module name");

  if (policy_flags & ~MODULE_FLAG_VALID_MASK)
    return _module_error_set(error, MODULE_ERR_INVALID_POLICY, name,
                             "Module policy contains unknown flags (0x%08" PRIx32 ")",
                             policy_flags & ~MODULE_FLAG_VALID_MASK);

  if (module_config_find(config, name))
    return _module_error_set(error, MODULE_ERR_ALREADY_CONFIGURED, name, "Module is already configured");

  const size_t size_limit = SIZE_MAX / sizeof(*config->entries);
  const size_t capacity_limit = size_limit < UINT_MAX ? size_limit : UINT_MAX;

  if (config->count == capacity_limit)
    return _module_error_set(error, MODULE_ERR_CAPACITY_REACHED, name, "Module configuration entry limit reached");

  char name_copy[MODULE_NAME_CAPACITY];
  strlcpy(name_copy, name, sizeof(name_copy));

  if (config->count == config->capacity)
  {
    const size_t capacity = config->capacity == 0 ? (capacity_limit < 8 ? capacity_limit : 8) :
      (config->capacity > capacity_limit / 2 ? capacity_limit : config->capacity * 2);

    assert(capacity > config->capacity);
    assert(capacity <= capacity_limit);

    struct module_config_entry *const entries = io_calloc(capacity * sizeof(*entries));

    if (config->count)
      memcpy(entries, config->entries, config->count * sizeof(*entries));

    io_free(config->entries);
    config->entries = entries;
    config->capacity = capacity;
  }

  assert(config->count < config->capacity);

  struct module_config_entry *const entry = &config->entries[config->count++];
  strlcpy(entry->name, name_copy, sizeof(entry->name));
  entry->policy_flags = policy_flags;

  assert(_module_config_is_valid(config));

  return MODULE_SUCCESS;
}

const char *
module_config_get_base_path(const module_config_t *config)
{
  return config ? config->base_path : NULL;
}

size_t
module_config_count(const module_config_t *config)
{
  return config ? config->count : 0;
}

const struct module_config_entry *
module_config_get(const module_config_t *config, size_t index)
{
  return config && index < config->count ? &config->entries[index] : NULL;
}

const struct module_config_entry *
module_config_find(const module_config_t *config, const char *name)
{
  if (config == NULL || !module_name_is_valid(name))
    return NULL;

  for (size_t i = 0; i < config->count; ++i)
    if (strcmp(config->entries[i].name, name) == 0)
      return &config->entries[i];

  return NULL;
}
