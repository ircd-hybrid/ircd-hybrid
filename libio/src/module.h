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
 * @file module.h
 * @brief Defines the interface for managing modules in the application.
 *
 * This file contains definitions for handling module initialization, loading, unloading,
 * and configuration within the application. It provides structures, enums, and function
 * prototypes necessary for module management.
 */

#ifndef INCLUDED_module_h
#define INCLUDED_module_h

#include "list.h"

/**
 * @def MODULE_ERROR_BUFFER_SIZE
 * @brief Buffer size for storing error messages.
 *
 * This constant defines the size of the buffer used for storing error messages
 * encountered during module operations. It ensures that error messages are properly
 * bounded and do not overflow.
 */
#define MODULE_ERROR_BUFFER_SIZE 256

/**
 * @enum module_error_code
 * @brief Enum for representing error codes for module operations.
 *
 * This enum lists possible error codes returned by module operations such as initialization,
 * loading, and unloading. Each code provides a specific reason for a failure or success state.
 */
enum module_error_code
{
  MODULE_SUCCESS = 0,  /**< Operation completed successfully. */
  MODULE_ERR_INIT_FAILED,  /**< Failed to initialize module system. */
  MODULE_ERR_SHUTDOWN_FAILED,  /**< Failed to shut down module system. */
  MODULE_ERR_LOAD_FAILED,  /**< Failed to load module. */
  MODULE_ERR_INVALID_PATH,  /**< Invalid module path specified. */
  MODULE_ERR_INVALID_SUFFIX,  /**< Invalid module file suffix. */
  MODULE_ERR_NOT_FOUND,  /**< Module not found. */
  MODULE_ERR_ALREADY_LOADED,  /**< Module already loaded. */
  MODULE_ERR_NOT_CONFIGURED,  /**< Module not configured to be loaded. */
  MODULE_ERR_ILLEGAL_TRAVERSAL,  /**< Illegal directory traversal in module path. */
  MODULE_ERR_INVALID_FILE,  /**< Invalid module file specified. */
  MODULE_ERR_CLOSE_FAILED,  /**< Failed to close module. */
  MODULE_ERR_CONFIG_EXISTS,  /**< Module configuration already exists. */
  MODULE_ERR_CORE_UNLOAD,  /**< Core module cannot be unloaded. */
  MODULE_ERR_RESIDENT_UNLOAD,  /**< Resident module cannot be unloaded. */
  MODULE_ERR_COUNT  /**< Number of error codes defined. */
};

/**
 * @enum module_attributes
 * @brief Enum for representing module attributes.
 *
 * This enum defines attributes that can be assigned to modules, such as resident and core.
 * Attributes determine the behavior and restrictions on module unloading and reloading.
 */
enum module_attributes
{
  MODULE_RESIDENT = 1 << 0,  /**< Indicates that the module is resident and cannot be unloaded. */
  MODULE_CORE     = 1 << 1,  /**< Indicates that the module is core and essential for functionality. */
};

/**
 * @struct Module
 * @brief Represents a module in the application.
 *
 * The Module structure holds information about a loaded module, including its name,
 * handle, initialization and exit handlers, and attributes. This structure is used
 * to manage and interact with modules throughout their lifecycle.
 */
struct Module
{
  list_node_t node;  /**< Doubly-linked list node for managing modules in a list. */
  char *name;  /**< Name of the module. */
  void *handle;  /**< Handle to the loaded module. */
  void (*init_handler)(void);  /**< Initialization function for the module. */
  void (*exit_handler)(void);  /**< Exit function for the module. */
  bool resident;  /**< Indicates if the module is resident and cannot be unloaded. */
  bool core;  /**< Indicates if the module is core and essential for functionality. */
};

/**
 * @struct ModuleConfig
 * @brief Represents the configuration for a module.
 *
 * The ModuleConfig structure holds information about the configuration of a module,
 * including its name and attributes. This structure is used to configure modules
 * before they are loaded.
 */
struct ModuleConfig
{
  list_node_t node;  /**< Doubly-linked list node for managing module configurations in a list. */
  char *name;  /**< Name of the module configuration. */
  bool resident;  /**< Indicates if the module is resident and cannot be unloaded. */
  bool core;  /**< Indicates if the module is core and essential for functionality. */
};

extern void module_set_base_path(const char *);
extern void module_config_clear(void);
extern void module_set_load_callback(void (*)(const char *, const void *, void *));
extern void module_set_unload_callback(void (*)(const char *, const void *, void *));
extern enum module_error_code module_init(void);
extern enum module_error_code module_cleanup(void);
extern enum module_error_code module_load(const char *, bool, void *);
extern enum module_error_code module_unload(const char *, bool, void *);
extern enum module_error_code module_config_add(const char *, bool, bool);
extern enum module_error_code module_unload_all(unsigned int *);
extern enum module_error_code module_load_all(unsigned int *);
extern struct Module *module_find(const char *);
extern struct ModuleConfig *module_config_find(const char *);
extern const list_t *module_get_list(void);
extern const list_t *module_config_get_list(void);
extern const char *module_get_error(void);
extern const char *module_get_attributes(const struct Module *);
#endif  /* INCLUDED_module_h */
