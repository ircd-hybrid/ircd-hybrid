/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module.c
 * @brief Module ownership, validation, and lifecycle management.
 */

#include "config.h"

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "io.h"
#include "io_string.h"
#include "list.h"
#include "memory.h"
#include "module.h"
#include "module_internal.h"
#include "module_loader.h"

struct module_manager
{
  list_t modules;
  module_config_t *config;
  uint32_t application_abi_version;
  void *application_context;
  bool busy;
  bool shutdown_started;
};

struct module_failure
{
  enum module_error_code code;
  enum module_error_code cause;
  char message[MODULE_ERROR_MESSAGE_CAPACITY];
  char cleanup_message[MODULE_ERROR_MESSAGE_CAPACITY];
};

struct module
{
  list_node_t node;
  struct module_manager *manager;
  char name[MODULE_NAME_CAPACITY];
  module_loader_handle_t handle;
  module_exit_fn exit_handler;
  module_flags_t intrinsic_flags;
  module_flags_t policy_flags;
  enum module_state state;
  struct module_failure failure;
};

struct module_candidate
{
  module_loader_handle_t handle;
  module_flags_t intrinsic_flags;
  module_init_fn init_handler;
  module_exit_fn exit_handler;
};

_Static_assert(sizeof(struct module_descriptor) <= UINT32_MAX,
               "Module descriptor size must fit in uint32_t");

void
_module_error_clear(struct module_error_info *error)
{
  if (error)
    *error = (struct module_error_info){ 0 };
}

enum module_error_code
_module_error_set(struct module_error_info *error, enum module_error_code code,
                  const char *module_name, const char *format, ...)
{
  assert(code != MODULE_SUCCESS);
  assert(format);

  if (error)
  {
    *error = (struct module_error_info){ .code = code };
    snprintf(error->module_name, sizeof(error->module_name), "%.*s",
             MODULE_NAME_CAPACITY - 1, string_or_empty(module_name));

    va_list args;
    va_start(args, format);
    vsnprintf(error->message, sizeof(error->message), format, args);
    va_end(args);
  }

  return code;
}

#ifndef NDEBUG
/* Transitional states are valid inside native callbacks, but not at operation boundaries. */
static bool
_module_is_stable(const struct module *module)
{
  assert(module);
  assert(module->manager);
  assert(module_name_is_valid(module->name));
  assert((module->intrinsic_flags & ~MODULE_FLAG_VALID_MASK) == 0);
  assert((module->policy_flags & ~MODULE_FLAG_VALID_MASK) == 0);

  switch (module->state)
  {
    case MODULE_STATE_ACTIVE:
      return module->handle != NULL && module->failure.code == MODULE_SUCCESS;
    case MODULE_STATE_FAILED:
      return module->handle == NULL && module->exit_handler == NULL && module->failure.code != MODULE_SUCCESS;
    case MODULE_STATE_BROKEN:
      return module->handle != NULL && module->exit_handler == NULL && module->failure.code == MODULE_ERR_CLOSE_FAILED;
    default:
      return false;
  }
}

static bool
_module_manager_is_stable(const struct module_manager *manager)
{
  assert(manager);
  assert(manager->config);
  assert(manager->application_abi_version != 0);

  list_node_t *node;
  LIST_FOREACH(node, manager->modules.head)
  {
    const struct module *const module = node->data;
    if (!_module_is_stable(module) || module->manager != manager)
      return false;

    if (manager->shutdown_started && module->state != MODULE_STATE_BROKEN)
      return false;
  }

  return true;
}
#endif

static enum module_error_code
_module_manager_operation_begin(struct module_manager *manager, struct module_error_info *error)
{
  if (manager == NULL)
    return _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Module manager is required");
  if (manager->busy)
    return _module_error_set(error, MODULE_ERR_BUSY, NULL, "Module manager is busy");

  assert(_module_manager_is_stable(manager));

  manager->busy = true;
  return MODULE_SUCCESS;
}

static enum module_error_code
_module_manager_operation_end(struct module_manager *manager, enum module_error_code code)
{
  assert(manager);
  assert(manager->busy);
  assert(_module_manager_is_stable(manager));

  manager->busy = false;
  return code;
}

static enum module_error_code
_module_manager_mutation_begin(struct module_manager *manager, struct module_error_info *error)
{
  const enum module_error_code code = _module_manager_operation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (manager->shutdown_started)
    return _module_manager_operation_end(manager,
      _module_error_set(error, MODULE_ERR_SHUTDOWN_STARTED, NULL, "Module manager has started shutdown"));

  return MODULE_SUCCESS;
}

static struct module *
_module_find(const struct module_manager *manager, const char *name)
{
  assert(manager);
  assert(name);

  list_node_t *node;
  LIST_FOREACH(node, manager->modules.head)
  {
    struct module *const module = node->data;
    if (strcmp(module->name, name) == 0)
      return module;
  }

  return NULL;
}

static enum module_error_code
_module_lookup(struct module_manager *manager, const char *name,
               struct module **module_out, struct module_error_info *error)
{
  assert(manager);
  assert(manager->busy);
  assert(module_out);

  if (!module_name_is_valid(name))
    return _module_error_set(error, MODULE_ERR_INVALID_NAME, name, "Invalid module name");

  *module_out = _module_find(manager, name);
  if (*module_out == NULL)
    return _module_error_set(error, MODULE_ERR_NOT_FOUND, name, "Module is not managed");

  return MODULE_SUCCESS;
}

static void
_module_failure_store(struct module *module, const struct module_error_info *error)
{
  assert(module);
  assert(error);
  assert(module->state == MODULE_STATE_FAILED || module->state == MODULE_STATE_BROKEN);
  assert(error->code != MODULE_SUCCESS);

  module->failure.code = error->code;
  module->failure.cause = error->cause;
  memcpy(module->failure.message, error->message, sizeof(module->failure.message));
  memcpy(module->failure.cleanup_message, error->cleanup_message, sizeof(module->failure.cleanup_message));
}

static enum module_error_code
_module_quarantine_error(const struct module *module, struct module_error_info *error)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);
  assert(module->state == MODULE_STATE_BROKEN);
  assert(_module_is_stable(module));

  if (error)
  {
    (void)module_get_failure(module, error);
    error->cause = error->code;
    error->code = MODULE_ERR_BROKEN;
  }

  return MODULE_ERR_BROKEN;
}

static void
_module_remove(struct module *module)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);
  assert(module->state == MODULE_STATE_FAILED || module->state == MODULE_STATE_UNLOADING);
  assert(module->handle == NULL);
  assert(module->exit_handler == NULL);

  list_remove(&module->node, &module->manager->modules);
  io_free(module);
}

static bool
_module_is_deactivation_protected(const struct module *module)
{
  assert(module);
  return module->state == MODULE_STATE_ACTIVE &&
         (module_get_effective_flags(module) & MODULE_FLAG_NO_DEACTIVATE) != 0;
}

static enum module_error_code
_module_path_build(const struct module_manager *manager, const char *name,
                   char *path, size_t path_size, struct module_error_info *error)
{
  assert(manager);
  assert(manager->config);
  assert(manager->busy);
  assert(name);
  assert(path);
  assert(path_size > 0);

  const char *const base_path = module_config_get_base_path(manager->config);
  if (base_path == NULL)
    return _module_error_set(error, MODULE_ERR_BASE_PATH_NOT_SET, name, "Module base path is not set");

  const size_t base_path_length = strlen(base_path);
  assert(base_path_length > 0);

  const int required_length = snprintf(path, path_size, "%s%s%s.so", base_path,
                                       base_path[base_path_length - 1] == '/' ? "" : "/", name);
  if (required_length < 0)
    return _module_error_set(error, MODULE_ERR_INVALID_PATH, name, "Failed to construct the module path");
  if ((size_t)required_length >= path_size)
    return _module_error_set(error, MODULE_ERR_PATH_TOO_LONG, name, "Module path is too long");

  return MODULE_SUCCESS;
}

static enum module_error_code
_module_descriptor_validate(const struct module *module,
                            const struct module_descriptor *descriptor,
                            struct module_error_info *error)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);

  if (descriptor == NULL)
    return _module_error_set(error, MODULE_ERR_INVALID_DESCRIPTOR, module->name,
                             "Module descriptor is NULL");

  if (descriptor->abi_version != MODULE_DESCRIPTOR_ABI_VERSION)
    return _module_error_set(error, MODULE_ERR_DESCRIPTOR_ABI_MISMATCH, module->name,
                             "Module descriptor ABI version mismatch (expected %" PRIu32 ", got %" PRIu32 ")",
                             MODULE_DESCRIPTOR_ABI_VERSION, descriptor->abi_version);

  if (descriptor->descriptor_size < MODULE_DESCRIPTOR_V1_MIN_SIZE)
    return _module_error_set(error, MODULE_ERR_INVALID_DESCRIPTOR, module->name,
                             "Module descriptor is too small (minimum %" PRIu32 " bytes, got %" PRIu32 ")",
                             MODULE_DESCRIPTOR_V1_MIN_SIZE, descriptor->descriptor_size);

  if (descriptor->application_abi_version != module->manager->application_abi_version)
    return _module_error_set(error, MODULE_ERR_APPLICATION_ABI_MISMATCH, module->name,
                             "Module application ABI version mismatch (expected %" PRIu32 ", got %" PRIu32 ")",
                             module->manager->application_abi_version, descriptor->application_abi_version);

  if (!module_name_is_valid(descriptor->name))
    return _module_error_set(error, MODULE_ERR_INVALID_DESCRIPTOR, module->name,
                             "Module descriptor has an invalid name");

  if (strcmp(descriptor->name, module->name) != 0)
    return _module_error_set(error, MODULE_ERR_NAME_MISMATCH, module->name,
                             "Module descriptor name mismatch (expected '%s', got '%s')",
                             module->name, descriptor->name);

  if (descriptor->flags & ~MODULE_FLAG_VALID_MASK)
    return _module_error_set(error, MODULE_ERR_INVALID_DESCRIPTOR, module->name,
                             "Module descriptor contains unknown flags (0x%08" PRIx32 ")",
                             descriptor->flags & ~MODULE_FLAG_VALID_MASK);

  if (descriptor->exit_handler && descriptor->init_handler == NULL)
    return _module_error_set(error, MODULE_ERR_INVALID_DESCRIPTOR, module->name,
                             "Module exit handler requires an initialization handler");

  return MODULE_SUCCESS;
}

static enum module_error_code
_module_candidate_discard(struct module *module, struct module_candidate *candidate,
                          struct module_error_info *error)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);
  assert(module->state == MODULE_STATE_LOADING || module->state == MODULE_STATE_RELOADING);
  assert(module->handle == NULL);
  assert(module->exit_handler == NULL);
  assert(candidate);
  assert(candidate->handle);
  assert(error);
  assert(error->code != MODULE_SUCCESS);

  const enum module_error_code cause = error->code;

  struct module_loader_error cleanup_error;
  if (module_loader_close(&candidate->handle, &cleanup_error) == MODULE_LOADER_OK)
  {
    assert(candidate->handle == NULL);

    module->state = MODULE_STATE_FAILED;
    return cause;
  }

  assert(candidate->handle);

  module->handle = candidate->handle;
  candidate->handle = NULL;
  module->state = MODULE_STATE_BROKEN;

  error->code = MODULE_ERR_CLOSE_FAILED;
  error->cause = cause;
  strlcpy(error->cleanup_message, cleanup_error.message, sizeof(error->cleanup_message));

  return MODULE_ERR_CLOSE_FAILED;
}

static enum module_error_code
_module_activate_native(struct module *module, const char *path, struct module_error_info *error)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);
  assert(!module->manager->shutdown_started);
  assert(module->state == MODULE_STATE_LOADING || module->state == MODULE_STATE_RELOADING);
  assert(!string_is_empty(path));
  assert(error);
  assert(module->handle == NULL);
  assert(module->exit_handler == NULL);

  struct module_candidate candidate = { 0 };
  struct module_loader_error loader_error;
  if (module_loader_open(path, &candidate.handle, &loader_error) != MODULE_LOADER_OK)
  {
    assert(candidate.handle == NULL);

    module->state = MODULE_STATE_FAILED;
    return _module_error_set(error, MODULE_ERR_OPEN_FAILED, module->name, "%s", loader_error.message);
  }

  assert(candidate.handle);

  void *symbol = NULL;
  if (module_loader_symbol(candidate.handle, MODULE_DESCRIPTOR_SYMBOL, &symbol, &loader_error) != MODULE_LOADER_OK)
  {
    _module_error_set(error, MODULE_ERR_DESCRIPTOR_LOOKUP_FAILED, module->name, "%s", loader_error.message);
    return _module_candidate_discard(module, &candidate, error);
  }

  const struct module_descriptor *const descriptor = symbol;
  const enum module_error_code code = _module_descriptor_validate(module, descriptor, error);
  if (code != MODULE_SUCCESS)
    return _module_candidate_discard(module, &candidate, error);

  candidate.intrinsic_flags = descriptor->flags;
  candidate.init_handler = descriptor->init_handler;
  candidate.exit_handler = descriptor->exit_handler;

  /* Retain accepted restrictions until a new activation succeeds. */
  module->intrinsic_flags |= candidate.intrinsic_flags;

  char init_error_message[MODULE_ERROR_MESSAGE_CAPACITY] = "";
  if (candidate.init_handler &&
      !candidate.init_handler(module->manager->application_context, init_error_message, sizeof(init_error_message)))
  {
    init_error_message[sizeof(init_error_message) - 1] = '\0';
    _module_error_set(error, MODULE_ERR_INIT_FAILED, module->name, "%s",
                      string_is_empty(init_error_message) ? "Module initialization failed" : init_error_message);
    return _module_candidate_discard(module, &candidate, error);
  }

  module->handle = candidate.handle;
  candidate.handle = NULL;
  module->exit_handler = candidate.exit_handler;
  module->intrinsic_flags = candidate.intrinsic_flags;
  module->state = MODULE_STATE_ACTIVE;

  return MODULE_SUCCESS;
}

static enum module_error_code
_module_activate(struct module *module, const char *path, struct module_error_info *error)
{
  struct module_error_info activation_error = { 0 };
  const enum module_error_code code = _module_activate_native(module, path, &activation_error);

  if (code == MODULE_SUCCESS)
    module->failure = (struct module_failure){ 0 };
  else
    _module_failure_store(module, &activation_error);

  assert(code == activation_error.code);
  assert(_module_is_stable(module));

  if (error)
    *error = activation_error;

  return code;
}

static enum module_error_code
_module_deactivate(struct module *module, struct module_error_info *error)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);
  assert(module->state == MODULE_STATE_RELOADING || module->state == MODULE_STATE_UNLOADING);
  assert(module->handle);

  const module_exit_fn exit_handler = module->exit_handler;
  module->exit_handler = NULL;

  if (exit_handler)
    exit_handler(module->manager->application_context);

  struct module_loader_error loader_error;
  if (module_loader_close(&module->handle, &loader_error) != MODULE_LOADER_OK)
  {
    module->state = MODULE_STATE_BROKEN;

    struct module_error_info close_error;
    const enum module_error_code code =
      _module_error_set(&close_error, MODULE_ERR_CLOSE_FAILED, module->name, "%s", loader_error.message);
    _module_failure_store(module, &close_error);

    assert(_module_is_stable(module));

    if (error)
      *error = close_error;
    return code;
  }

  assert(module->handle == NULL);
  assert(module->exit_handler == NULL);

  return MODULE_SUCCESS;
}

static enum module_error_code
_module_load(struct module_manager *manager, const char *name, struct module_error_info *error)
{
  assert(manager);
  assert(manager->busy);
  assert(!manager->shutdown_started);

  if (!module_name_is_valid(name))
    return _module_error_set(error, MODULE_ERR_INVALID_NAME, name, "Invalid module name");

  const struct module_config_entry *const entry = module_config_find(manager->config, name);
  if (entry == NULL)
    return _module_error_set(error, MODULE_ERR_NOT_CONFIGURED, name, "Module is not configured");

  if (_module_find(manager, name))
    return _module_error_set(error, MODULE_ERR_ALREADY_MANAGED, name, "Module is already managed");

  if (list_length(&manager->modules) == UINT_MAX)
    return _module_error_set(error, MODULE_ERR_CAPACITY_REACHED, name, "Module manager record limit reached");

  char path[IO_PATH_MAX];
  enum module_error_code code = _module_path_build(manager, name, path, sizeof(path), error);
  if (code != MODULE_SUCCESS)
    return code;

  struct module *const module = io_calloc(sizeof(*module));
  module->manager = manager;
  module->policy_flags = entry->policy_flags;
  module->state = MODULE_STATE_LOADING;
  strlcpy(module->name, name, sizeof(module->name));

  list_add_tail(module, &module->node, &manager->modules);

  code = _module_activate(module, path, error);
  if (code != MODULE_SUCCESS && module->state != MODULE_STATE_BROKEN)
    _module_remove(module);

  return code;
}

static enum module_error_code
_module_reload(struct module *module, struct module_error_info *error)
{
  assert(module);
  assert(module->manager);
  assert(module->manager->busy);
  assert(!module->manager->shutdown_started);
  assert(_module_is_stable(module));

  if (module->state == MODULE_STATE_BROKEN)
    return _module_quarantine_error(module, error);

  if (module_config_find(module->manager->config, module->name) == NULL)
    return _module_error_set(error, MODULE_ERR_NOT_CONFIGURED, module->name, "Module is not configured");

  assert(module->state == MODULE_STATE_ACTIVE || module->state == MODULE_STATE_FAILED);

  if (_module_is_deactivation_protected(module))
    return _module_error_set(error, MODULE_ERR_DEACTIVATION_PROTECTED, module->name,
                             "Active module deactivation is protected");

  char path[IO_PATH_MAX];
  const enum module_error_code path_code =
    _module_path_build(module->manager, module->name, path, sizeof(path), error);
  if (path_code != MODULE_SUCCESS)
    return path_code;

  const bool was_active = module->state == MODULE_STATE_ACTIVE;
  module->state = MODULE_STATE_RELOADING;

  if (was_active)
  {
    const enum module_error_code code = _module_deactivate(module, error);
    if (code != MODULE_SUCCESS)
      return code;
  }

  return _module_activate(module, path, error);
}

module_manager_t *
module_manager_create(const struct module_manager_options *options, struct module_error_info *error)
{
  _module_error_clear(error);

  if (options == NULL)
  {
    _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Module manager options are required");
    return NULL;
  }

  if (options->application_abi_version == 0)
  {
    _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Application ABI version must be nonzero");
    return NULL;
  }

  struct module_manager *const manager = io_calloc(sizeof(*manager));
  manager->config = module_config_create();

  const enum module_error_code code = _module_config_acquire(manager->config, error);
  assert(code == MODULE_SUCCESS);
  (void)code;

  manager->application_abi_version = options->application_abi_version;
  manager->application_context = options->application_context;

  assert(_module_manager_is_stable(manager));

  return manager;
}

enum module_error_code
module_manager_shutdown(module_manager_t *manager, module_report_fn report, void *report_context,
                        struct module_error_info *error)
{
  _module_error_clear(error);

  enum module_error_code code = _module_manager_operation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  manager->shutdown_started = true;

  list_node_t *node = manager->modules.tail;
  while (node)
  {
    struct module *const module = node->data;
    node = node->prev;

    char name[MODULE_NAME_CAPACITY];
    strlcpy(name, module->name, sizeof(name));

    struct module_error_info entry_error = { 0 };

    enum module_error_code entry_code = MODULE_SUCCESS;
    if (module->state == MODULE_STATE_BROKEN)
      entry_code = _module_quarantine_error(module, &entry_error);
    else
    {
      assert(module->state == MODULE_STATE_ACTIVE || module->state == MODULE_STATE_FAILED);

      if (module->state == MODULE_STATE_ACTIVE)
      {
        module->state = MODULE_STATE_UNLOADING;
        entry_code = _module_deactivate(module, &entry_error);
      }

      if (entry_code == MODULE_SUCCESS)
        _module_remove(module);
    }

    if (entry_code != MODULE_SUCCESS && code == MODULE_SUCCESS)
    {
      code = entry_code;
      if (error)
        *error = entry_error;
    }

    if (report)
      report(name, entry_code == MODULE_SUCCESS ? MODULE_REPORT_SUCCESS : MODULE_REPORT_FAILED,
             entry_code == MODULE_SUCCESS ? NULL : &entry_error, report_context);
  }

  return _module_manager_operation_end(manager, code);
}

enum module_error_code
module_manager_destroy(module_manager_t **manager_slot, struct module_error_info *error)
{
  _module_error_clear(error);

  if (manager_slot == NULL)
    return _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Module manager ownership slot is required");

  struct module_manager *const manager = *manager_slot;
  if (manager == NULL)
    return MODULE_SUCCESS;

  const enum module_error_code code = _module_manager_operation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (!list_is_empty(&manager->modules))
    return _module_manager_operation_end(manager,
      _module_error_set(error, MODULE_ERR_NOT_EMPTY, NULL, "Module manager is not empty"));

  _module_config_destroy_owned(manager->config);
  io_free(manager);
  *manager_slot = NULL;

  return MODULE_SUCCESS;
}

enum module_error_code
module_manager_replace_config(module_manager_t *manager, module_config_t **config_slot,
                              struct module_error_info *error)
{
  _module_error_clear(error);

  enum module_error_code code = _module_manager_mutation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (config_slot == NULL)
    return _module_manager_operation_end(manager,
      _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Module configuration ownership slot is required"));

  code = _module_config_acquire(*config_slot, error);
  if (code != MODULE_SUCCESS)
    return _module_manager_operation_end(manager, code);

  module_config_t *const previous = manager->config;
  manager->config = *config_slot;
  *config_slot = NULL;

  list_node_t *node;
  LIST_FOREACH(node, manager->modules.head)
  {
    struct module *const module = node->data;
    const struct module_config_entry *const entry = module_config_find(manager->config, module->name);
    module->policy_flags = entry ? entry->policy_flags : 0;
  }

  _module_config_destroy_owned(previous);

  return _module_manager_operation_end(manager, MODULE_SUCCESS);
}

enum module_error_code
module_manager_activate_configured(module_manager_t *manager, struct module_activation_result *result,
                                   module_report_fn report, void *report_context, struct module_error_info *error)
{
  _module_error_clear(error);

  if (result)
    *result = (struct module_activation_result){ 0 };

  enum module_error_code code = _module_manager_mutation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  for (size_t i = 0; i < module_config_count(manager->config); ++i)
  {
    const struct module_config_entry *const entry = module_config_get(manager->config, i);
    struct module *const module = _module_find(manager, entry->name);

    if (module && module->state == MODULE_STATE_ACTIVE)
    {
      if (result)
        ++result->skipped;

      if (report)
        report(entry->name, MODULE_REPORT_SKIPPED, NULL, report_context);

      continue;
    }

    struct module_error_info entry_error = { 0 };
    enum module_error_code entry_code;

    if (module && module->state == MODULE_STATE_BROKEN)
      entry_code = _module_quarantine_error(module, &entry_error);
    else
      entry_code = module ? _module_reload(module, &entry_error) : _module_load(manager, entry->name, &entry_error);

    if (result)
    {
      if (entry_code == MODULE_SUCCESS)
        ++result->activated;
      else
        ++result->failed;
    }

    if (entry_code != MODULE_SUCCESS && code == MODULE_SUCCESS)
    {
      code = entry_code;
      if (error)
        *error = entry_error;
    }

    if (report)
      report(entry->name, entry_code == MODULE_SUCCESS ? MODULE_REPORT_SUCCESS : MODULE_REPORT_FAILED,
             entry_code == MODULE_SUCCESS ? NULL : &entry_error, report_context);
  }

  return _module_manager_operation_end(manager, code);
}

enum module_error_code
module_manager_load(module_manager_t *manager, const char *name, struct module_error_info *error)
{
  _module_error_clear(error);

  const enum module_error_code code = _module_manager_mutation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  return _module_manager_operation_end(manager, _module_load(manager, name, error));
}

enum module_error_code
module_manager_unload(module_manager_t *manager, const char *name, struct module_error_info *error)
{
  _module_error_clear(error);

  enum module_error_code code = _module_manager_mutation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  struct module *module = NULL;
  code = _module_lookup(manager, name, &module, error);
  if (code != MODULE_SUCCESS)
    return _module_manager_operation_end(manager, code);

  if (module->state == MODULE_STATE_BROKEN)
    return _module_manager_operation_end(manager, _module_quarantine_error(module, error));

  if (module_get_effective_flags(module) & MODULE_FLAG_NO_REMOVE)
    return _module_manager_operation_end(manager,
      _module_error_set(error, MODULE_ERR_REMOVAL_PROTECTED, module->name, "Module removal is protected"));

  if (_module_is_deactivation_protected(module))
    return _module_manager_operation_end(manager,
      _module_error_set(error, MODULE_ERR_DEACTIVATION_PROTECTED, module->name,
                        "Active module deactivation is protected"));

  assert(module->state == MODULE_STATE_ACTIVE || module->state == MODULE_STATE_FAILED);

  if (module->state == MODULE_STATE_ACTIVE)
  {
    module->state = MODULE_STATE_UNLOADING;
    code = _module_deactivate(module, error);
  }

  if (code == MODULE_SUCCESS)
    _module_remove(module);

  return _module_manager_operation_end(manager, code);
}

enum module_error_code
module_manager_reload(module_manager_t *manager, const char *name, struct module_error_info *error)
{
  _module_error_clear(error);

  enum module_error_code code = _module_manager_mutation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  struct module *module = NULL;
  code = _module_lookup(manager, name, &module, error);
  if (code == MODULE_SUCCESS)
    code = _module_reload(module, error);

  return _module_manager_operation_end(manager, code);
}

enum module_error_code
module_manager_reload_all(module_manager_t *manager, struct module_reload_all_result *result,
                          module_report_fn report, void *report_context, struct module_error_info *error)
{
  _module_error_clear(error);

  if (result)
    *result = (struct module_reload_all_result){ 0 };

  enum module_error_code code = _module_manager_mutation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  list_node_t *node;
  LIST_FOREACH(node, manager->modules.head)
  {
    struct module *const module = node->data;
    if (module_config_find(manager->config, module->name) == NULL || _module_is_deactivation_protected(module))
    {
      if (result)
        ++result->skipped;

      if (report)
        report(module->name, MODULE_REPORT_SKIPPED, NULL, report_context);

      continue;
    }

    struct module_error_info reload_error = { 0 };
    code = _module_reload(module, &reload_error);

    if (code == MODULE_SUCCESS && result)
      ++result->reloaded;

    if (report)
      report(module->name, code == MODULE_SUCCESS ? MODULE_REPORT_SUCCESS : MODULE_REPORT_FAILED,
             code == MODULE_SUCCESS ? NULL : &reload_error, report_context);

    if (code != MODULE_SUCCESS)
    {
      if (error)
        *error = reload_error;

      break;
    }
  }

  return _module_manager_operation_end(manager, code);
}

const module_config_t *
module_manager_get_config(const module_manager_t *manager)
{
  return manager ? manager->config : NULL;
}

const module_t *
module_manager_find(const module_manager_t *manager, const char *name)
{
  if (manager == NULL || !module_name_is_valid(name))
    return NULL;

  return _module_find(manager, name);
}

size_t
module_manager_count(const module_manager_t *manager)
{
  return manager ? list_length(&manager->modules) : 0;
}

enum module_error_code
module_manager_foreach(module_manager_t *manager, module_foreach_fn callback, void *context,
                       struct module_error_info *error)
{
  _module_error_clear(error);

  const enum module_error_code code = _module_manager_operation_begin(manager, error);
  if (code != MODULE_SUCCESS)
    return code;

  if (callback == NULL)
    return _module_manager_operation_end(manager,
      _module_error_set(error, MODULE_ERR_INVALID_ARGUMENT, NULL, "Enumeration callback is required"));

  list_node_t *node;
  LIST_FOREACH(node, manager->modules.head)
    callback(node->data, context);

  return _module_manager_operation_end(manager, MODULE_SUCCESS);
}

const char *
module_get_name(const module_t *module)
{
  assert(module);
  return module->name;
}

enum module_state
module_get_state(const module_t *module)
{
  assert(module);
  return module->state;
}

module_flags_t
module_get_intrinsic_flags(const module_t *module)
{
  assert(module);
  return module->intrinsic_flags;
}

module_flags_t
module_get_policy_flags(const module_t *module)
{
  assert(module);
  return module->policy_flags;
}

module_flags_t
module_get_effective_flags(const module_t *module)
{
  assert(module);
  return module->intrinsic_flags | module->policy_flags;
}

bool
module_get_failure(const module_t *module, struct module_error_info *error)
{
  assert(module);
  assert(error);

  _module_error_clear(error);

  if (module->state != MODULE_STATE_FAILED && module->state != MODULE_STATE_BROKEN)
    return false;

  assert(module->failure.code != MODULE_SUCCESS);

  error->code = module->failure.code;
  error->cause = module->failure.cause;
  memcpy(error->module_name, module->name, sizeof(error->module_name));
  memcpy(error->message, module->failure.message, sizeof(error->message));
  memcpy(error->cleanup_message, module->failure.cleanup_message, sizeof(error->cleanup_message));

  return true;
}

const char *
module_flags_to_string(module_flags_t flags)
{
  switch (flags)
  {
    case 0: return "none";
    case MODULE_FLAG_NO_REMOVE: return "no_remove";
    case MODULE_FLAG_NO_DEACTIVATE: return "no_deactivate";
    case MODULE_FLAG_NO_REMOVE | MODULE_FLAG_NO_DEACTIVATE: return "no_remove,no_deactivate";
  }

  return "unknown";
}

bool
module_name_is_valid(const char *name)
{
  if (string_is_empty(name))
    return false;

  const unsigned char first_char = (unsigned char)name[0];
  if (!io_ascii_is_alpha(first_char))
    return false;

  for (size_t i = 1; i < MODULE_NAME_CAPACITY; ++i)
  {
    const unsigned char ch = (unsigned char)name[i];
    if (ch == '\0')
      return true;
    if (!io_ascii_is_alnum(ch) && ch != '_' && ch != '-')
      return false;
  }

  return false;
}

const char *
module_state_to_string(enum module_state state)
{
  switch (state)
  {
    case MODULE_STATE_LOADING: return "loading";
    case MODULE_STATE_ACTIVE: return "active";
    case MODULE_STATE_RELOADING: return "reloading";
    case MODULE_STATE_UNLOADING: return "unloading";
    case MODULE_STATE_FAILED: return "failed";
    case MODULE_STATE_BROKEN: return "broken";
  }

  return "unknown";
}

const char *
module_strerror(enum module_error_code code)
{
  switch (code)
  {
    case MODULE_SUCCESS: return "Success";
    case MODULE_ERR_INVALID_ARGUMENT: return "Invalid argument";
    case MODULE_ERR_BUSY: return "Module manager is busy";
    case MODULE_ERR_SHUTDOWN_STARTED: return "Module manager has started shutdown";
    case MODULE_ERR_CAPACITY_REACHED: return "Module capacity limit reached";
    case MODULE_ERR_INVALID_NAME: return "Invalid module name";
    case MODULE_ERR_INVALID_POLICY: return "Invalid module policy flags";
    case MODULE_ERR_INVALID_PATH: return "Invalid module path";
    case MODULE_ERR_BASE_PATH_NOT_SET: return "Module base path is not set";
    case MODULE_ERR_PATH_TOO_LONG: return "Module path is too long";
    case MODULE_ERR_NOT_FOUND: return "Module is not managed";
    case MODULE_ERR_ALREADY_MANAGED: return "Module is already managed";
    case MODULE_ERR_NOT_EMPTY: return "Module manager is not empty";
    case MODULE_ERR_REMOVAL_PROTECTED: return "Module removal is protected";
    case MODULE_ERR_DEACTIVATION_PROTECTED: return "Active module deactivation is protected";
    case MODULE_ERR_OPEN_FAILED: return "Native module open failed";
    case MODULE_ERR_DESCRIPTOR_LOOKUP_FAILED: return "Module descriptor symbol lookup failed";
    case MODULE_ERR_DESCRIPTOR_ABI_MISMATCH: return "Module descriptor ABI version mismatch";
    case MODULE_ERR_APPLICATION_ABI_MISMATCH: return "Module application ABI version mismatch";
    case MODULE_ERR_NAME_MISMATCH: return "Module descriptor name mismatch";
    case MODULE_ERR_INVALID_DESCRIPTOR: return "Invalid module descriptor";
    case MODULE_ERR_INIT_FAILED: return "Module initialization failed";
    case MODULE_ERR_CLOSE_FAILED: return "Native module close failed";
    case MODULE_ERR_BROKEN: return "Module is quarantined";
    case MODULE_ERR_ALREADY_CONFIGURED: return "Module is already configured";
    case MODULE_ERR_CONFIG_OWNED: return "Module configuration belongs to a manager";
    case MODULE_ERR_NOT_CONFIGURED: return "Module is not configured";
  }

  return "Unknown module error";
}
