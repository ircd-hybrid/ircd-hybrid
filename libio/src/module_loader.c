/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module_loader.c
 * @brief Native dynamic module loading and symbol resolution.
 */

#include "config.h"

#include <dlfcn.h>
#include <stddef.h>
#include <string.h>

#include "io_string.h"
#include "module_loader.h"

static void
_module_loader_clear_error(struct module_loader_error *error)
{
  if (error)
    error->message[0] = '\0';
}

static void
_module_loader_set_error(struct module_loader_error *error, const char *message)
{
  if (error)
    strlcpy(error->message, message, sizeof(error->message));
}

static void
_module_loader_set_dlerror(struct module_loader_error *error, const char *fallback)
{
  const char *const message = dlerror();
  _module_loader_set_error(error, string_is_empty(message) ? fallback : message);
}

module_loader_result_t
module_loader_open(const char *path, module_loader_handle_t *handle,
                   struct module_loader_error *error)
{
  _module_loader_clear_error(error);

  if (handle == NULL || string_is_empty(path))
  {
    _module_loader_set_error(error, "A nonempty path and a handle output slot are required");
    return MODULE_LOADER_INVALID_ARGUMENT;
  }

  if (*handle != NULL)
  {
    _module_loader_set_error(error, "The handle output slot must be initialized to NULL");
    return MODULE_LOADER_INVALID_ARGUMENT;
  }

  (void)dlerror();

  const module_loader_handle_t opened_handle = dlopen(path, RTLD_NOW | RTLD_LOCAL);
  if (opened_handle == NULL)
  {
    _module_loader_set_dlerror(error, "dlopen() failed without an error message");
    return MODULE_LOADER_OPEN_FAILED;
  }

  *handle = opened_handle;
  return MODULE_LOADER_OK;
}

module_loader_result_t
module_loader_symbol(module_loader_handle_t handle, const char *name,
                     void **symbol, struct module_loader_error *error)
{
  _module_loader_clear_error(error);

  if (symbol == NULL)
  {
    _module_loader_set_error(error, "A symbol output slot is required");
    return MODULE_LOADER_INVALID_ARGUMENT;
  }

  *symbol = NULL;

  if (handle == NULL || string_is_empty(name))
  {
    _module_loader_set_error(error, "An open handle and a nonempty symbol name are required");
    return MODULE_LOADER_INVALID_ARGUMENT;
  }

  (void)dlerror();

  void *const address = dlsym(handle, name);

  const char *const message = dlerror();
  if (message)
  {
    _module_loader_set_error(error, string_is_empty(message) ? "dlsym() failed without an error message" : message);
    return MODULE_LOADER_SYMBOL_FAILED;
  }

  *symbol = address;
  return MODULE_LOADER_OK;
}

module_loader_result_t
module_loader_close(module_loader_handle_t *handle, struct module_loader_error *error)
{
  _module_loader_clear_error(error);

  if (handle == NULL || *handle == NULL)
  {
    _module_loader_set_error(error, "A handle slot owning an open reference is required");
    return MODULE_LOADER_INVALID_ARGUMENT;
  }

  (void)dlerror();

  if (dlclose(*handle))
  {
    _module_loader_set_dlerror(error, "dlclose() failed without an error message");
    return MODULE_LOADER_CLOSE_FAILED;
  }

  *handle = NULL;
  return MODULE_LOADER_OK;
}
