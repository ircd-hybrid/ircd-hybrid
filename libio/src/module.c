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
  const char *basename = io_basename(name);

  list_node_t *node;
  LIST_FOREACH(node, module_list.head)
  {
    struct Module *module = node->data;
    if (strcmp(module->name, basename) == 0)
      return module;
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
module_load(const char *path, bool warn, bool startup)
{
  const char *const name = io_basename(path);
  char full_path[IO_PATH_MAX];

  if (module_base_path)
  {
    snprintf(full_path, sizeof(full_path), "%s/%s", module_base_path, path);
    path = full_path;
  }

  if (module_find(name))
  {
    module_set_error("Module %s is already loaded", name);
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
module_add_config(const char *path, bool resident, bool core)
{
  if (!module_valid_suffix(path))
    return;

  struct ModuleConfig *config = io_calloc(sizeof(*config));
  config->path = io_strdup(path);
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
    io_free(config->path);
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
    if (module_load(config->path, warn, startup) == 0 && startup)
    {
      fprintf(stderr, "Error loading module %s from: %s during startup: %s\n",
              config->path, module_base_path, module_last_error);
      exit(EXIT_FAILURE);
    }
    fprintf(stderr, "Loading module %s from: %s\n",
              config->path, module_base_path);
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
    if (module_load(config->path, warn, startup) == 0)
    {
      if (startup && config->core)
      {
        fprintf(stderr, "Error reloading core module %s: %s\n",
                config->path, module_last_error);
        exit(EXIT_FAILURE);
      }

      success = false;
    }
    else
      ++(*loaded_count);
  }

  return success;
}
