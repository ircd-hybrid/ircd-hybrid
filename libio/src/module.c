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
#include "memory.h"
#include "module.h"

static char module_last_error[MODULE_ERROR_BUFFER_SIZE];

static list_t module_config_list;

static list_t module_list;

static char *module_base_path;

const list_t *
module_get_list(void)
{
  return &module_list;
}

void
module_set_base_path(const char *path)
{
  fprintf(stderr, "module_set_base_path(%s)", path);
  io_free(module_base_path);
  module_base_path = io_strdup(path);
}

static void
module_set_error(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  vsnprintf(module_last_error, sizeof(module_last_error), format, args);
  va_end(args);
}

void
module_init(void)
{
  if (lt_dlinit())
  {
    module_set_error("Couldn't initialize the libltdl run time dynamic link library: %s",
                     lt_dlerror());
    exit(EXIT_FAILURE);
  }
}

void
module_cleanup(void)
{
  lt_dlexit();
}

const char *
module_get_error(void)
{
  return module_last_error;
}

const char *
module_get_attributes(const struct Module *module)
{
  static char attributes[16];

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
    struct Module *module = node->data;
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
    struct ModuleConfig *config = node->data;
    if (strcmp(config->name, name) == 0)
      return config;
  }

  return NULL;
}

bool
module_unload(const char *name, bool warn)
{
  struct Module *module = module_find(name);
  if (module == NULL)
  {
    module_set_error("Module %s is not loaded", name);
    return false;
  }

  if (module->exit_handler)
    module->exit_handler();

  list_remove(&module->node, &module_list);
  io_free(module->name);

  if (lt_dlclose(module->handle))
  {
    module_set_error("Error closing module %s: %s", name, lt_dlerror());
    return false;
  }

  return true;
}

bool
module_load(const char *name, bool warn, bool startup)
{
  if (*name == '/')
  {
    module_set_error("Invalid module path %s: Absolute paths are not allowed", name);
    return false;
  }

  if (module_valid_suffix(name) == false)
  {
    module_set_error("Invalid module name %s: Expected file suffix '.la'", name);
    return false;
  }

  if (module_config_find(name) == NULL)
  {
    module_set_error("Module %s is not configured to be loaded", name);
    return false;
  }

  if (module_find(name))
  {
    module_set_error("Module %s is already loaded", name);
    return false;
  }

  char path[IO_PATH_MAX];
  if (module_base_path)
    snprintf(path, sizeof(path), "%s/%s", module_base_path, name);
  else
  {
     module_set_error("Module base path is not set");
     return false;
  }

  if (strstr(path, "../") || strstr(path, "/.."))
  {
    module_set_error("Module path %s contains illegal directory traversal", path);
    return false;
  }

  struct stat sb;
  if (stat(path, &sb) != 0)
  {
    module_set_error("Error loading module %s: %s", path, strerror(errno));
    return false;
  }

  if (!S_ISREG(sb.st_mode))
  {
    module_set_error("Error loading module %s: Not a regular file", path);
    return false;
  }

  lt_dlhandle handle = lt_dlopen(path);
  if (handle == NULL)
  {
    module_set_error("Error loading module %s: %s", name, lt_dlerror());
    return false;
  }

  struct Module *const module = lt_dlsym(handle, "module_entry");
  if (module == NULL)
  {
    module_set_error("Error loading module %s: %s", name, lt_dlerror());
    lt_dlclose(handle);
    return false;
  }

  module->handle = handle;
  module->name = io_strdup(name);
  list_add(module, &module->node, &module_list);

  if (module->init_handler)
    module->init_handler();

  return true;
}

void
module_add_config(const char *name, bool resident, bool core)
{
  struct ModuleConfig *config = io_calloc(sizeof(*config));
  config->name = io_strdup(name);
  config->resident = resident;
  config->core = core;
  list_add(config, &config->node, &module_config_list);
}

void
module_clear_config(void)
{
  while (module_config_list.head)
  {
    struct ModuleConfig *config = module_config_list.head->data;
    list_remove(&config->node, &module_config_list);
    io_free(config->name);
    io_free(config);
  }
}

void
module_load_all(bool warn, bool startup)
{
  list_node_t *node;
  LIST_FOREACH(node, module_config_list.head)
  {
    struct ModuleConfig *config = node->data;
    if (module_load(config->name, warn, startup) == 0 && startup)
    {
      fprintf(stderr, "Error loading module %s from: %s during startup: %s\n",
              config->name, module_base_path, module_last_error);
      exit(EXIT_FAILURE);
    }
    fprintf(stderr, "Loading module %s from: %s\n",
              config->name, module_base_path);
  }
}

bool
module_reload_all(unsigned int *unloaded_count, unsigned int *loaded_count, bool warn, bool startup)
{
  bool success = true;

  list_node_t *node, *node_next;
  LIST_FOREACH_SAFE(node, node_next, module_list.head)
  {
    const struct Module *const module = node->data;
    if (module->resident == false && module_unload(module->name, warn))
      ++(*unloaded_count);
    else
      success = false;
  }

  LIST_FOREACH(node, module_config_list.head)
  {
    const struct ModuleConfig *const config = node->data;
    if (module_load(config->name, warn, startup) == 0)
    {
      if (startup && config->core)
      {
        fprintf(stderr, "Error reloading core module %s: %s\n",
                config->name, module_last_error);
        exit(EXIT_FAILURE);
      }

      success = false;
    }
    else
      ++(*loaded_count);
  }

  return success;
}
