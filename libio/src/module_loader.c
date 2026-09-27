/*
 * SPDX-FileCopyrightText: 2000-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file module_loader.c
 * @brief Native dynamic module loading and symbol resolution.
 */

#include <assert.h>
#include <dlfcn.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "module_loader.h"

enum
{
  MODULE_LOADER_ERROR_CAPACITY = 512
};

static char module_loader_last_error[MODULE_LOADER_ERROR_CAPACITY];
static const char module_loader_suffix[] = ".so";

static void
_module_loader_clear_error(void)
{
  module_loader_last_error[0] = '\0';
}

static void
_module_loader_set_error(const char *error)
{
  assert(error);
  snprintf(module_loader_last_error, sizeof(module_loader_last_error), "%s", error);
}

static void
_module_loader_set_dlerror(const char *fallback)
{
  assert(fallback);

  const char *const error = dlerror();
  _module_loader_set_error(error ? error : fallback);
}

bool
module_loader_build_path(char *path, size_t path_size, const char *directory, const char *name)
{
  assert(path);
  assert(path_size);
  assert(directory);
  assert(name);

  _module_loader_clear_error();

  const int length = snprintf(path, path_size, "%s/%s%s", directory, name, module_loader_suffix);
  if (length < 0)
  {
    _module_loader_set_error("Failed to construct module path");
    return false;
  }

  if ((size_t)length >= path_size)
  {
    _module_loader_set_error("Module path exceeds the maximum supported length");
    return false;
  }

  return true;
}

module_loader_handle_t
module_loader_open(const char *path)
{
  assert(path);

  _module_loader_clear_error();

  dlerror();

  module_loader_handle_t handle = dlopen(path, RTLD_LAZY);
  if (handle == NULL)
    _module_loader_set_dlerror("dlopen() failed without an error message");

  return handle;
}

bool
module_loader_symbol(module_loader_handle_t handle, const char *name, void **symbol)
{
  assert(handle);
  assert(name);
  assert(symbol);

  *symbol = NULL;

  _module_loader_clear_error();

  dlerror();

  void *const address = dlsym(handle, name);

  const char *const error = dlerror();
  if (error)
  {
    _module_loader_set_error(error);
    return false;
  }

  if (address == NULL)
  {
    _module_loader_set_error("Dynamic loader returned a null symbol address");
    return false;
  }

  *symbol = address;
  return true;
}

bool
module_loader_close(module_loader_handle_t handle)
{
  assert(handle);

  _module_loader_clear_error();

  dlerror();

  if (dlclose(handle))
  {
    _module_loader_set_dlerror("dlclose() failed without an error message");
    return false;
  }

  return true;
}

const char *
module_loader_get_error(void)
{
  return module_loader_last_error;
}
