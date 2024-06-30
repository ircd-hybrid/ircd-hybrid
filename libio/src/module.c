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

/**
 * @file module.c
 * @brief Implements the module management functions.
 *
 * This file contains the implementation of functions for managing modules, including
 * initialization, loading, unloading, and configuration handling. It provides the
 * necessary functionality to dynamically manage modules within the application.
 */

#include "ltdl.h"
#include "stdinc.h"
#include "io.h"
#include "irc_string.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"

/**
 * @var module_last_error
 * @brief Buffer for storing the last error message.
 *
 * This buffer stores the last error message encountered during module operations.
 * It provides detailed information about the most recent error for debugging and logging purposes.
 */
static char module_last_error[MODULE_ERROR_BUFFER_SIZE];

/**
 * @var module_config_list
 * @brief List of module configurations.
 *
 * This variable maintains a doubly linked list of all module configurations.
 * Each element in the list is a ModuleConfig structure representing a specific module configuration.
 */
static list_t module_config_list;

/**
 * @var module_list
 * @brief List of loaded modules.
 *
 * This variable maintains a doubly linked list of all loaded modules.
 * Each element in the list is a Module structure representing a specific loaded module.
 */
static list_t module_list;

/**
 * @var module_base_path
 * @brief Base path for module files.
 *
 * This variable stores the base path for resolving module file paths during loading operations.
 * The base path can be set to customize where the application looks for module files.
 */
static char *module_base_path;

/**
 * @var module_load_callback
 * @brief Callback for module load events.
 *
 * This function pointer stores the callback function that will be called when a module is loaded.
 * The callback can be used to perform additional actions or logging when a module is loaded.
 */
static void (*module_load_callback)(const char *, const void *, void *);

/**
 * @var module_unload_callback
 * @brief Callback for module unload events.
 *
 * This function pointer stores the callback function that will be called when a module is unloaded.
 * The callback can be used to perform additional actions or logging when a module is unloaded.
 */
static void (*module_unload_callback)(const char *, const void *, void *);

/**
 * @var module_error_strings
 * @brief Array of error message strings corresponding to module_error_code values.
 *
 * This array stores human-readable error messages for each error code defined in module_error_code.
 * It is used to format detailed error messages for debugging and logging purposes.
 */
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

/**
 * @brief Retrieves the list of loaded modules.
 *
 * This function returns a pointer to the list of loaded modules. The list is used
 * to manage and iterate over all modules that are currently loaded in the application.
 *
 * @return Pointer to the list of loaded modules.
 */
const list_t *
module_get_list(void)
{
  return &module_list;
}

/**
 * @brief Retrieves the list of module configurations.
 *
 * This function returns a pointer to the list of module configurations. The list is used
 * to manage and iterate over all module configurations that are defined in the application.
 *
 * @return Pointer to the list of module configurations.
 */
const list_t *
module_config_get_list(void)
{
  return &module_config_list;
}

/**
 * @brief Sets the base path for module files.
 *
 * This function sets the base path for module files, freeing any previously set path.
 * The base path is used as a prefix for resolving module file paths during loading operations.
 *
 * @param path Path to set as the base path.
 */
void
module_set_base_path(const char *path)
{
  io_free(module_base_path);
  module_base_path = io_strdup(path);
}

/**
 * @brief Sets the last error message for module operations.
 *
 * This function sets the last error message using a formatted string. It is used internally
 * to provide detailed error messages for module operations that encounter issues.
 *
 * @param code Error code indicating the type of error.
 * @param ... Additional arguments for formatting the error message.
 */
static void
module_set_error(enum module_error_code code, ...)
{
  va_list args;
  va_start(args, code);
  vsnprintf(module_last_error, sizeof(module_last_error), module_error_strings[code], args);
  va_end(args);
}

/**
 * @brief Sets the callback function for module load events.
 *
 * This function sets the callback function that will be called when a module is loaded.
 * The callback function can be used to perform additional actions or logging when a module is loaded.
 *
 * @param callback Function pointer to the load callback.
 */
void
module_set_load_callback(void (*callback)(const char *name, const void *handle, void *user_data))
{
  module_load_callback = callback;
}

/**
 * @brief Sets the callback function for module unload events.
 *
 * This function sets the callback function that will be called when a module is unloaded.
 * The callback function can be used to perform additional actions or logging when a module is unloaded.
 *
 * @param callback Function pointer to the unload callback.
 */
void
module_set_unload_callback(void (*callback)(const char *name, const void *handle, void *user_data))
{
  module_unload_callback = callback;
}

/**
 * @brief Initializes the module management system.
 *
 * This function initializes the libltdl dynamic link library, setting up the environment for
 * loading and unloading modules. It must be called before any modules can be loaded or managed.
 *
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
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

/**
 * @brief Cleans up the module management system.
 *
 * This function shuts down the libltdl dynamic link library, cleaning up resources used
 * for module management. It should be called when the application is shutting down to ensure
 * that all resources are properly released.
 *
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
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

/**
 * @brief Retrieves the last error message.
 *
 * This function returns the last error message set during module operations. It can be used
 * to obtain detailed information about the most recent error that occurred.
 *
 * @return Pointer to the last error message.
 */
const char *
module_get_error(void)
{
  return module_last_error;
}

/**
 * @brief Retrieves the attributes of a module.
 *
 * This function returns a string representation of the attributes (core, resident)
 * of the specified module. The attributes indicate special properties of the module.
 *
 * @param module Pointer to the module structure.
 * @return String representation of the module's attributes.
 */
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

/**
 * @brief Validates the suffix of a module file.
 *
 * This function checks if the specified module name has the expected file suffix.
 * It ensures that only files with the correct suffix are processed as modules.
 *
 * @param name Name of the module file.
 * @return true if the suffix is valid, false otherwise.
 */
static bool
module_valid_suffix(const char *name)
{
  const char *const suffix = strrchr(name, '.');
  if (suffix && strcmp(suffix, ".la") == 0)
    return true;

  return false;
}

/**
 * @brief Finds a loaded module by name.
 *
 * This function searches the list of loaded modules for a module with the specified name.
 * It returns a pointer to the Module structure if found, or NULL if no such module is loaded.
 *
 * @param name Name of the module to find.
 * @return Pointer to the Module structure if found, NULL otherwise.
 */
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

/**
 * @brief Finds a module configuration by name.
 *
 * This function searches the list of module configurations for a configuration with the specified name.
 * It returns a pointer to the ModuleConfig structure if found, or NULL if no such configuration exists.
 *
 * @param name Name of the module configuration to find.
 * @return Pointer to the ModuleConfig structure if found, NULL otherwise.
 */
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

/**
 * @brief Compares two modules by name.
 *
 * This function compares the names of two modules for sorting purposes.
 * It is used to maintain a sorted list of modules based on their names.
 *
 * @param a_ Pointer to the first module.
 * @param b_ Pointer to the second module.
 * @return Comparison result for sorting.
 */
static int
module_cmp(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct Module *)a_)->name;
  const char *const b = ((const struct Module *)b_)->name;
  return strcmp(a, b);
}

/**
 * @brief Compares two module configurations by name.
 *
 * This function compares the names of two module configurations for sorting purposes.
 * It is used to maintain a sorted list of module configurations based on their names.
 *
 * @param a_ Pointer to the first module configuration.
 * @param b_ Pointer to the second module configuration.
 * @return Comparison result for sorting.
 */
static int
module_config_cmp(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct ModuleConfig *)a_)->name;
  const char *const b = ((const struct ModuleConfig *)b_)->name;
  return strcmp(a, b);
}

/**
 * @brief Unloads a module by name.
 *
 * This function unloads the specified module, invoking its exit handler and
 * removing it from the list of loaded modules. It ensures that resources associated
 * with the module are properly released and that the module is safely removed.
 *
 * @param name Name of the module to unload.
 * @param reload Whether to allow reloading of the module.
 * @param user_data User data to pass to the unload callback.
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
enum module_error_code
module_unload(const char *name, bool reload, void *user_data)
{
  /* Ensure the module name has a valid suffix. */
  if (module_valid_suffix(name) == false)
  {
    module_set_error(MODULE_ERR_INVALID_SUFFIX, name);
    return MODULE_ERR_INVALID_SUFFIX;
  }

  /* Find the module to unload. */
  struct Module *const module = module_find(name);
  if (module == NULL)
  {
    module_set_error(MODULE_ERR_NOT_FOUND, name);
    return MODULE_ERR_NOT_FOUND;
  }

  /* Core modules cannot be unloaded unless reloaded. */
  if (reload == false && module->core)
  {
    module_set_error(MODULE_ERR_CORE_UNLOAD, name);
    return MODULE_ERR_CORE_UNLOAD;
  }

  /* Resident modules cannot be unloaded. */
  if (module->resident)
  {
    module_set_error(MODULE_ERR_RESIDENT_UNLOAD, name);
    return MODULE_ERR_RESIDENT_UNLOAD;
  }

  /* Call the module's exit handler, if defined. */
  if (module->exit_handler)
    module->exit_handler();

  list_remove(&module->node, &module_list);
  io_free(module->name);

  /*
   * Store the module handle before closing it.
   * This is necessary because the handle is required for the unload callback,
   * and once the handle is closed, it may no longer be valid or accessible.
   */
  const lt_dlhandle handle = module->handle;

  /* Close the module handle. */
  if (lt_dlclose(module->handle))
  {
    module_set_error(MODULE_ERR_CLOSE_FAILED, name, lt_dlerror());
    return MODULE_ERR_CLOSE_FAILED;
  }

  /* Invoke the unload callback, if defined. */
  if (module_unload_callback)
    module_unload_callback(name, handle, user_data);

  log_write(LOG_TYPE_IRCD, "Module %s [handle: %p] unloaded", name, handle);
  return MODULE_SUCCESS;
}

/**
 * @brief Loads a module by name.
 *
 * This function loads the specified module, invoking its initialization handler and
 * adding it to the list of loaded modules. It ensures that the module is properly
 * initialized and that its resources are ready for use.
 *
 * If manual loading is enabled (indicated by the `manual` parameter), the function
 * performs additional checks and validations to ensure the safety and correctness
 * of loading the module. Manual loading typically involves user-initiated module
 * loads, which may include loading modules from non-standard paths.
 *
 * @param name Name of the module to load.
 * @param manual Whether the load is manual.
 * @param user_data User data to pass to the load callback.
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
enum module_error_code
module_load(const char *name, bool manual, void *user_data)
{
  /* Ensure manual loads do not use absolute paths. */
  if (manual && *name == '/')
  {
    module_set_error(MODULE_ERR_INVALID_PATH, name);
    return MODULE_ERR_INVALID_PATH;
  }

  /* Ensure the module name has a valid suffix if it's a manual load. */
  if (manual && module_valid_suffix(name) == false)
  {
    module_set_error(MODULE_ERR_INVALID_SUFFIX, name);
    return MODULE_ERR_INVALID_SUFFIX;
  }

  /* Ensure the module is configured before loading. */
  if (module_config_find(name) == NULL)
  {
    module_set_error(MODULE_ERR_NOT_CONFIGURED, name);
    return MODULE_ERR_NOT_CONFIGURED;
  }

  /* Check if the module is already loaded. */
  if (module_find(name))
  {
    module_set_error(MODULE_ERR_ALREADY_LOADED, name);
    return MODULE_ERR_ALREADY_LOADED;
  }

  /* Resolve the module path. */
  char path[IO_PATH_MAX];
  if (module_base_path)
    snprintf(path, sizeof(path), "%s/%s", module_base_path, name);
  else
  {
    module_set_error(MODULE_ERR_INVALID_PATH, "Base path is not set");
    return MODULE_ERR_INVALID_PATH;
  }

  /* Prevent illegal directory traversal. */
  if (strstr(path, "../") || strstr(path, "/.."))
  {
    module_set_error(MODULE_ERR_ILLEGAL_TRAVERSAL, path);
    return MODULE_ERR_ILLEGAL_TRAVERSAL;
  }

  /* Validate the module file. */
  struct stat sb;
  if (stat(path, &sb))
  {
    /* stat() failed, likely because the file does not exist or is inaccessible. */
    module_set_error(MODULE_ERR_INVALID_FILE, name, strerror(errno));
    return MODULE_ERR_INVALID_FILE;
  }

  if (!S_ISREG(sb.st_mode))
  {
    /* The path exists, but it's not a regular file (e.g., it could be a directory). */
    module_set_error(MODULE_ERR_INVALID_FILE, name, "Not a regular file");
    return MODULE_ERR_INVALID_FILE;
  }

  /* Attempt to load the module. */
  lt_dlhandle handle = lt_dlopen(path);
  if (handle == NULL)
  {
    module_set_error(MODULE_ERR_LOAD_FAILED, name, lt_dlerror());
    return MODULE_ERR_LOAD_FAILED;
  }

  /* Retrieve the module entry point. */
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

  /* Call the module's initialization handler, if present. */
  if (module->init_handler)
    module->init_handler();

  /* Invoke the load callback, if defined. */
  if (module_load_callback)
    module_load_callback(name, handle, user_data);

  log_write(LOG_TYPE_IRCD, "Module %s [handle: %p] loaded", name, handle);
  return MODULE_SUCCESS;
}

/**
 * @brief Adds a new module configuration.
 *
 * This function adds a new configuration for a module, specifying its name
 * and attributes (resident, core). The configuration is stored in the module
 * configuration list and can be used to control module loading behavior.
 *
 * @param name Name of the module.
 * @param resident Whether the module is resident.
 * @param core Whether the module is core.
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
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

/**
 * @brief Clears all module configurations.
 *
 * This function removes all module configurations from the list,
 * freeing their associated memory. It ensures that no stale configurations
 * remain in the system, allowing for fresh configuration.
 */
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

/**
 * @brief Loads all configured modules.
 *
 * This function loads all modules that have been configured, incrementing the
 * loaded count for each successful load. It ensures that all necessary modules
 * are loaded and ready for use.
 *
 * @param loaded_count Pointer to an unsigned int to store the count of loaded modules.
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
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
      /*
       * If loading the module failed for reasons other than the module being already loaded,
       * update the return code to the specific error and log the failure.
       * This ensures we log only significant errors and not just already loaded modules.
       */
      code = tmp;
      log_write(LOG_TYPE_IRCD, "Failed to load module %s: %s",
                config->name, module_get_error());
    }
  }

  return code;
}

/**
 * @brief Unloads all non-resident modules.
 *
 * This function unloads all non-resident modules, incrementing the unloaded
 * count for each successful unload. It ensures that only resident modules remain
 * loaded, freeing up resources used by other modules.
 *
 * @param unloaded_count Pointer to an unsigned int to store the count of unloaded modules.
 * @return MODULE_SUCCESS on success, or an appropriate error code on failure.
 */
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
