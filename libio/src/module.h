/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module.h
 * @brief Explicit module ownership, policy, and lifecycle management.
 */

#ifndef INCLUDED_module_h
#define INCLUDED_module_h
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MODULE_DESCRIPTOR_ABI_VERSION UINT32_C(1)
#define MODULE_DESCRIPTOR_SYMBOL "module_entry_v1"
#define MODULE_ERROR_MESSAGE_CAPACITY 512
#define MODULE_NAME_CAPACITY 64

typedef struct module module_t;
typedef struct module_config module_config_t;
typedef struct module_manager module_manager_t;
typedef uint32_t module_flags_t;

enum module_flag
{
  MODULE_FLAG_NO_REMOVE     = UINT32_C(1) << 0,
  MODULE_FLAG_NO_DEACTIVATE = UINT32_C(1) << 1
};

#define MODULE_FLAG_VALID_MASK ((module_flags_t)(MODULE_FLAG_NO_REMOVE | MODULE_FLAG_NO_DEACTIVATE))

enum module_state
{
  MODULE_STATE_LOADING,
  MODULE_STATE_ACTIVE,
  MODULE_STATE_RELOADING,
  MODULE_STATE_UNLOADING,
  MODULE_STATE_FAILED,
  MODULE_STATE_BROKEN
};

enum module_error_code
{
  MODULE_SUCCESS = 0,
  MODULE_ERR_INVALID_ARGUMENT,
  MODULE_ERR_BUSY,
  MODULE_ERR_SHUTDOWN_STARTED,
  MODULE_ERR_CAPACITY_REACHED,
  MODULE_ERR_INVALID_NAME,
  MODULE_ERR_INVALID_POLICY,
  MODULE_ERR_INVALID_PATH,
  MODULE_ERR_BASE_PATH_NOT_SET,
  MODULE_ERR_PATH_TOO_LONG,
  MODULE_ERR_NOT_FOUND,
  MODULE_ERR_ALREADY_MANAGED,
  MODULE_ERR_NOT_EMPTY,
  MODULE_ERR_REMOVAL_PROTECTED,
  MODULE_ERR_DEACTIVATION_PROTECTED,
  MODULE_ERR_OPEN_FAILED,
  MODULE_ERR_DESCRIPTOR_LOOKUP_FAILED,
  MODULE_ERR_DESCRIPTOR_ABI_MISMATCH,
  MODULE_ERR_APPLICATION_ABI_MISMATCH,
  MODULE_ERR_NAME_MISMATCH,
  MODULE_ERR_INVALID_DESCRIPTOR,
  MODULE_ERR_INIT_FAILED,
  MODULE_ERR_CLOSE_FAILED,
  MODULE_ERR_BROKEN,
  MODULE_ERR_ALREADY_CONFIGURED,
  MODULE_ERR_CONFIG_OWNED,
  MODULE_ERR_NOT_CONFIGURED
};

enum module_report_outcome
{
  MODULE_REPORT_SUCCESS,
  MODULE_REPORT_SKIPPED,
  MODULE_REPORT_FAILED
};

struct module_error_info
{
  enum module_error_code code;
  enum module_error_code cause;
  char module_name[MODULE_NAME_CAPACITY];
  char message[MODULE_ERROR_MESSAGE_CAPACITY];
  char cleanup_message[MODULE_ERROR_MESSAGE_CAPACITY];
};

typedef void (*module_exit_fn)(void *);
typedef void (*module_foreach_fn)(const module_t *, void *);
typedef void (*module_report_fn)(const char *, enum module_report_outcome, const struct module_error_info *, void *);
typedef bool (*module_init_fn)(void *, char *, size_t);

struct module_descriptor
{
  uint32_t abi_version;
  uint32_t descriptor_size;
  uint32_t application_abi_version;
  const char *name;
  module_flags_t flags;
  module_init_fn init_handler;
  module_exit_fn exit_handler;
};

#define MODULE_DESCRIPTOR_V1_MIN_SIZE \
  ((uint32_t)(offsetof(struct module_descriptor, exit_handler) + \
              sizeof(((struct module_descriptor *)0)->exit_handler)))

struct module_config_entry
{
  char name[MODULE_NAME_CAPACITY];
  module_flags_t policy_flags;
};

struct module_manager_options
{
  uint32_t application_abi_version;
  void *application_context;
};

struct module_activation_result
{
  size_t activated;
  size_t skipped;
  size_t failed;
};

struct module_reload_all_result
{
  size_t reloaded;
  size_t skipped;
};

extern bool module_get_failure(const module_t *, struct module_error_info *);
extern bool module_name_is_valid(const char *);
extern enum module_error_code module_config_add(module_config_t *, const char *, module_flags_t, struct module_error_info *);
extern enum module_error_code module_config_destroy(module_config_t **, struct module_error_info *);
extern enum module_error_code module_config_set_base_path(module_config_t *, const char *, struct module_error_info *);
extern enum module_error_code module_manager_activate_configured(module_manager_t *, struct module_activation_result *, module_report_fn, void *, struct module_error_info *);
extern enum module_error_code module_manager_destroy(module_manager_t **, struct module_error_info *);
extern enum module_error_code module_manager_foreach(module_manager_t *, module_foreach_fn, void *, struct module_error_info *);
extern enum module_error_code module_manager_load(module_manager_t *, const char *, struct module_error_info *);
extern enum module_error_code module_manager_reload(module_manager_t *, const char *, struct module_error_info *);
extern enum module_error_code module_manager_reload_all(module_manager_t *, struct module_reload_all_result *, module_report_fn, void *, struct module_error_info *);
extern enum module_error_code module_manager_replace_config(module_manager_t *, module_config_t **, struct module_error_info *);
extern enum module_error_code module_manager_shutdown(module_manager_t *, module_report_fn, void *, struct module_error_info *);
extern enum module_error_code module_manager_unload(module_manager_t *, const char *, struct module_error_info *);
extern enum module_state module_get_state(const module_t *);
extern module_config_t *module_config_create(void);
extern module_flags_t module_get_effective_flags(const module_t *);
extern module_flags_t module_get_intrinsic_flags(const module_t *);
extern module_flags_t module_get_policy_flags(const module_t *);
extern module_manager_t *module_manager_create(const struct module_manager_options *, struct module_error_info *);
extern size_t module_config_count(const module_config_t *);
extern size_t module_manager_count(const module_manager_t *);
extern const char *module_config_get_base_path(const module_config_t *);
extern const char *module_flags_to_string(module_flags_t);
extern const char *module_get_name(const module_t *);
extern const char *module_state_to_string(enum module_state);
extern const char *module_strerror(enum module_error_code);
extern const module_config_t *module_manager_get_config(const module_manager_t *);
extern const module_t *module_manager_find(const module_manager_t *, const char *);
extern const struct module_config_entry *module_config_find(const module_config_t *, const char *);
extern const struct module_config_entry *module_config_get(const module_config_t *, size_t);
#endif  /* INCLUDED_module_h */
