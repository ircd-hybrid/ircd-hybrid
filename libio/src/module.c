/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2024 ircd-hybrid development team
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

#include "ltdl.h"
#include "stdinc.h"
#include "io.h"
#include "irc_string.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"

static char module_last_error[MODULE_ERROR_BUFFER_SIZE];

static list_t module_config_list;

static list_t module_list;

static char *module_base_path;

static void (*module_load_callback)(const char *, const void *, void *);
static void (*module_unload_callback)(const char *, const void *, void *);

static const char *const module_error_strings[MODULE_ERR_COUNT] =
{
  [MODULE_SUCCESS] = "Operation completed successfully",
  [MODULE_ERR_INIT_FAILED] = "Failed to initialize the libltdl dynamic link library: %s",
  [MODULE_ERR_SHUTDOWN_FAILED] = "Failed to shut down the libltdl dynamic link library: %s",
  [MODULE_ERR_LOAD_FAILED] = "Failed to load module %s: %s",
  [MODULE_ERR_INVALID_PATH] = "Invalid module path: %s",
  [MODULE_ERR_INVALID_SUFFIX] = "Invalid module name %s: Expected file suffix '.la'",
  [MODULE_ERR_NOT_FOUND] = "Module not loaded: %s",
  [MODULE_ERR_ALREADY_LOADED] = "Module already loaded: %s",
  [MODULE_ERR_NOT_CONFIGURED] = "Module not configured to be loaded: %s",
  [MODULE_ERR_ILLEGAL_TRAVERSAL] = "Illegal directory traversal in path: %s",
  [MODULE_ERR_INVALID_FILE] = "Invalid file for module %s: %s",
  [MODULE_ERR_CLOSE_FAILED] = "Failed to close module %s: %s",
  [MODULE_ERR_CONFIG_EXISTS] = "Module configuration already exists: %s",
  [MODULE_ERR_CORE_UNLOAD] = "Core module cannot be unloaded: %s",
  [MODULE_ERR_RESIDENT_UNLOAD] = "Resident module cannot be unloaded: %s"
};

const list_t *
module_get_list(void)
{
  return &module_list;
}

const list_t *
module_config_get_list(void)
{
  return &module_config_list;
}

void
module_set_base_path(const char *path)
{
  io_free(module_base_path);
  module_base_path = io_strdup(path);
}

static void
module_set_error(enum module_error_code code, ...)
{
  va_list args;
  va_start(args, code);
  vsnprintf(module_last_error, sizeof(module_last_error), module_error_strings[code], args);
  va_end(args);
}

void
module_set_load_callback(void (*callback)(const char *name, const void *handle, void *user_data))
{
  module_load_callback = callback;
}

void
module_set_unload_callback(void (*callback)(const char *name, const void *handle, void *user_data))
{
  module_unload_callback = callback;
}

enum module_error_code
module_init(void)
{
  if (lt_dlinit())
  {
    module_set_error(MODULE_ERR_INIT_FAILED, lt_dlerror());
    return MODULE_ERR_INIT_FAILED;
  }

  return MODULE_SUCCESS;
}

enum module_error_code
module_cleanup(void)
{
  if (lt_dlexit())
  {
    module_set_error(MODULE_ERR_SHUTDOWN_FAILED, lt_dlerror());
    return MODULE_ERR_SHUTDOWN_FAILED;
  }

  return MODULE_SUCCESS;
}

const char *
module_get_error(void)
{
  return module_last_error;
}

const char *
module_get_attributes(const struct Module *module)
{
  static char attributes[18];

  if (module->core || module->resident)
    snprintf(attributes, sizeof(attributes), "(%s%s%s)",
             module->core ? "core" : "",
             (module->core && module->resident) ? ", " : "", module->resident ? "resident" : "");
  else
    attributes[0] = '\0';

  return attributes;
}

static bool
module_valid_suffix(const char *name)
{
  const char *const suffix = strrchr(name, '.');
  if (suffix && strcmp(suffix, ".la") == 0)
    return true;

  return false;
}

struct Module *
module_find(const char *name)
{
  list_node_t *node;
  LIST_FOREACH(node, module_list.head)
  {
    struct Module *const module = node->data;
    if (strcmp(module->name, name) == 0)
      return module;
  }

  return NULL;
}

struct ModuleConfig *
module_config_find(const char *name)
{
  list_node_t *node;
  LIST_FOREACH(node, module_config_list.head)
  {
    struct ModuleConfig *const config = node->data;
    if (strcmp(config->name, name) == 0)
      return config;
  }

  return NULL;
}

static int
module_cmp(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct Module *)a_)->name;
  const char *const b = ((const struct Module *)b_)->name;
  return strcmp(a, b);
}

static int
module_config_cmp(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct ModuleConfig *)a_)->name;
  const char *const b = ((const struct ModuleConfig *)b_)->name;
  return strcmp(a, b);
}

enum module_error_code
module_unload(const char *name, bool reload, void *user_data)
{
  if (module_valid_suffix(name) == false)
  {
    module_set_error(MODULE_ERR_INVALID_SUFFIX, name);
    return MODULE_ERR_INVALID_SUFFIX;
  }

  struct Module *const module = module_find(name);
  if (module == NULL)
  {
    module_set_error(MODULE_ERR_NOT_FOUND, name);
    return MODULE_ERR_NOT_FOUND;
  }

  if (reload == false && module->core)
  {
    module_set_error(MODULE_ERR_CORE_UNLOAD, name);
    return MODULE_ERR_CORE_UNLOAD;
  }

  if (module->resident)
  {
    module_set_error(MODULE_ERR_RESIDENT_UNLOAD, name);
    return MODULE_ERR_RESIDENT_UNLOAD;
  }

  if (module->exit_handler)
    module->exit_handler();

  list_remove(&module->node, &module_list);
  io_free(module->name);

  const lt_dlhandle handle = module->handle;
  if (lt_dlclose(module->handle))
  {
    module_set_error(MODULE_ERR_CLOSE_FAILED, name, lt_dlerror());
    return MODULE_ERR_CLOSE_FAILED;
  }

  if (module_unload_callback)
    module_unload_callback(name, handle, user_data);

  log_write(LOG_TYPE_IRCD, "Module %s [handle: %p] unloaded", name, handle);
  return MODULE_SUCCESS;
}

enum module_error_code
module_load(const char *name, bool manual, void *user_data)
{
  if (manual && *name == '/')
  {
    module_set_error(MODULE_ERR_INVALID_PATH, name);
    return MODULE_ERR_INVALID_PATH;
  }

  if (manual && module_valid_suffix(name) == false)
  {
    module_set_error(MODULE_ERR_INVALID_SUFFIX, name);
    return MODULE_ERR_INVALID_SUFFIX;
  }

  if (module_config_find(name) == NULL)
  {
    module_set_error(MODULE_ERR_NOT_CONFIGURED, name);
    return MODULE_ERR_NOT_CONFIGURED;
  }

  if (module_find(name))
  {
    module_set_error(MODULE_ERR_ALREADY_LOADED, name);
    return MODULE_ERR_ALREADY_LOADED;
  }

  char path[IO_PATH_MAX];
  if (module_base_path)
    snprintf(path, sizeof(path), "%s/%s", module_base_path, name);
  else
  {
    module_set_error(MODULE_ERR_INVALID_PATH, "Base path is not set");
    return MODULE_ERR_INVALID_PATH;
  }

  if (strstr(path, "../") || strstr(path, "/.."))
  {
    module_set_error(MODULE_ERR_ILLEGAL_TRAVERSAL, path);
    return MODULE_ERR_ILLEGAL_TRAVERSAL;
  }

  struct stat sb;
  if (stat(path, &sb))
  {
    module_set_error(MODULE_ERR_INVALID_FILE, name, strerror(errno));
    return MODULE_ERR_INVALID_FILE;
  }

  if (!S_ISREG(sb.st_mode))
  {
    module_set_error(MODULE_ERR_INVALID_FILE, name, "Not a regular file");
    return MODULE_ERR_INVALID_FILE;
  }

  lt_dlhandle handle = lt_dlopen(path);
  if (handle == NULL)
  {
    module_set_error(MODULE_ERR_LOAD_FAILED, name, lt_dlerror());
    return MODULE_ERR_LOAD_FAILED;
  }

  struct Module *const module = lt_dlsym(handle, "module_entry");
  if (module == NULL)
  {
    module_set_error(MODULE_ERR_LOAD_FAILED, name, lt_dlerror());
    lt_dlclose(handle);
    return MODULE_ERR_LOAD_FAILED;
  }

  module->handle = handle;
  module->name = io_strdup(name);

  list_add_sorted(module, &module->node, &module_list, module_cmp);

  if (module->init_handler)
    module->init_handler();

  if (module_load_callback)
    module_load_callback(name, handle, user_data);

  log_write(LOG_TYPE_IRCD, "Module %s [handle: %p] loaded", name, handle);
  return MODULE_SUCCESS;
}

enum module_error_code
module_config_add(const char *name, bool resident, bool core)
{
  if (module_config_find(name))
  {
    module_set_error(MODULE_ERR_CONFIG_EXISTS, name);
    return MODULE_ERR_CONFIG_EXISTS;
  }

  if (module_valid_suffix(name) == false)
  {
    module_set_error(MODULE_ERR_INVALID_SUFFIX, name);
    return MODULE_ERR_INVALID_SUFFIX;
  }

  struct ModuleConfig *const config = io_calloc(sizeof(*config));
  config->name = io_strdup(name);
  config->resident = resident;
  config->core = core;
  list_add_sorted(config, &config->node, &module_config_list, module_config_cmp);

  return MODULE_SUCCESS;
}

void
module_config_clear(void)
{
  while (module_config_list.head)
  {
    struct ModuleConfig *const config = module_config_list.head->data;
    list_remove(&config->node, &module_config_list);
    io_free(config->name);
    io_free(config);
  }
}

enum module_error_code
module_load_all(unsigned int *loaded_count)
{
  enum module_error_code code = MODULE_SUCCESS;

  list_node_t *node;
  LIST_FOREACH(node, module_config_list.head)
  {
    struct ModuleConfig *const config = node->data;

    enum module_error_code tmp = module_load(config->name, false, NULL);
    if (tmp == MODULE_SUCCESS)
    {
      if (loaded_count)
        ++(*loaded_count);
    }
    else if (tmp != MODULE_ERR_ALREADY_LOADED)
    {
      code = tmp;
      log_write(LOG_TYPE_IRCD, "Failed to load module %s: %s",
                config->name, module_get_error());
    }
  }

  return code;
}

enum module_error_code
module_unload_all(unsigned int *unloaded_count)
{
  enum module_error_code code = MODULE_SUCCESS;

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, module_list.head)
  {
    struct Module *const module = node->data;

    if (module->resident)
      continue;

    enum module_error_code tmp = module_unload(module->name, true, NULL);
    if (tmp == MODULE_SUCCESS)
    {
      if (unloaded_count)
        ++(*unloaded_count);
    }
    else
      code = tmp;
  }

  return code;
}
