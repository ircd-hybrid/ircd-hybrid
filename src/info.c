/**
 * @file info.c
 * @brief Implements dynamic registration, unregistration, and updating of info entries.
 *
 * This file contains the implementation of an API for dynamically registering and unregistering
 * info entries. The API supports various output types including string, unsigned integer,
 * signed integer, boolean, float, double, and char.
 * This implementation is used for showing the configuration in /INFO requests.
 */

#include "stdinc.h"
#include "memory.h"
#include "send.h"
#include "client.h"
#include "info.h"

/**
 * @brief List to hold dynamically registered info entries.
 *
 * This variable represents a doubly-linked list that stores dynamically registered info
 * entries. Each node in the list corresponds to a specific info entry containing
 * configuration details that can be displayed in response to /INFO requests.
 */
static list_t info_list;

/**
 * @brief Registers a new info entry.
 *
 * This function registers a new info entry with the specified name, output type, value, and description.
 * If an entry with the same name is already registered, it returns an error code.
 *
 * @param name The name of the info entry.
 * @param output_type The output type of the info entry.
 * @param option The pointer to the value of the info entry.
 * @param description The description of the info entry.
 * @return An error code indicating the result of the operation.
 */
info_result_t
info_register(const char *name, info_output_type_t output_type, const void *option, const char *description)
{
  if (info_find(name))
    return INFO_ALREADY_REGISTERED;

  struct InfoEntry *info = io_calloc(sizeof(*info));
  info->name = strdup(name);
  info->output_type = output_type;
  info->option = option;
  info->description = strdup(description);
  list_add_tail(info, &info->node, &info_list);

  return INFO_SUCCESS;
}

/**
 * @brief Unregisters an existing info entry.
 *
 * This function unregisters an existing info entry with the specified name.
 * If the entry is not found, it returns an error code.
 *
 * @param name The name of the info entry to be unregistered.
 * @return An error code indicating the result of the operation.
 */
info_result_t
info_unregister(const char *name)
{
  struct InfoEntry *info = info_find(name);
  if (info == NULL)
    return INFO_NOT_FOUND;

  list_remove(&info->node, &info_list);

  /* Temporarily disable the warning for casting away const qualifiers. */
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"

  /* Freeing memory allocated for const char pointers. */
  io_free(info->name);
  io_free(info->description);

  /* Re-enable the discarded qualifiers warning. */
  #pragma GCC diagnostic pop

  io_free(info);

  return INFO_SUCCESS;
}

/**
 * @brief Registers an array of info entries.
 *
 * This function registers an entire array of info entries to the info API.
 *
 * @param entries The array of InfoEntry structures to be registered.
 * @param elements The number of elements in the entries array.
 */
void
info_register_array(const struct InfoEntry *entries, size_t elements)
{
  for (size_t i = 0; i < elements; ++i)
  {
    const struct InfoEntry *const tmp = &entries[i];
    info_register(tmp->name, tmp->output_type, tmp->option, tmp->description);
  }
}

/**
 * @brief Unregisters an array of info entries.
 *
 * This function unregisters an entire array of info entries from the info API.
 *
 * @param entries The array of InfoEntry structures to be unregistered.
 * @param elements The number of elements in the entries array.
 */
void
info_unregister_array(const struct InfoEntry *entries, size_t elements)
{
  for (size_t i = 0; i < elements; ++i)
  {
    const struct InfoEntry *const tmp = &entries[i];
    info_unregister(tmp->name);
  }
}

/**
 * @brief Finds an info entry.
 *
 * This function looks up an info entry by its name. If found, it returns a pointer to the info structure.
 *
 * @param name The name of the info entry.
 * @return A pointer to the InfoEntry structure or NULL if not found.
 */
struct InfoEntry *
info_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, info_list.head)
  {
    struct InfoEntry *info = node->data;
    if (strcasecmp(info->name, name) == 0)
      return info;
  }

  return NULL;
}

/**
 * @brief Sends configuration options to the client.
 *
 * This function iterates over all registered info entries and formats their values
 * according to their specified output types. The formatted information is then sent
 * to the specified client. Supported output types include strings, unsigned integers,
 * signed integers, booleans, floats, doubles, and characters.
 *
 * The function ensures that each value is correctly formatted based on its type before
 * sending it to the client. It handles the following output types:
 * - INFO_OUTPUT_STRING: Dereferences a string pointer to obtain the value.
 * - INFO_OUTPUT_STRING_LITERAL: Uses the string literal value directly.
 * - INFO_OUTPUT_UNSIGNED_INT: Formats the value as an unsigned integer.
 * - INFO_OUTPUT_INT: Formats the value as a signed integer.
 * - INFO_OUTPUT_BOOLEAN: Formats the value as "YES" or "NO".
 * - INFO_OUTPUT_FLOAT: Formats the value as a floating-point number.
 * - INFO_OUTPUT_DOUBLE: Formats the value as a double-precision floating-point number.
 * - INFO_OUTPUT_CHAR: Formats the value as a single character.
 *
 * @param client The client to send the configuration options to.
 */
void
info_send(struct Client *client)
{
  char buf[32];
  const char *value = NULL;

  list_node_t *node;
  LIST_FOREACH(node, info_list.head)
  {
    const struct InfoEntry *const info = node->data;
    switch (info->output_type)
    {
      case INFO_OUTPUT_STRING:
        value = (info->option && *((const char *const *)info->option)) ? *((const char *const *)info->option) : "NONE";
        break;
      case INFO_OUTPUT_STRING_LITERAL:
        value = info->option ? (const char *const)info->option : "NONE";
        break;
      case INFO_OUTPUT_INT:
        snprintf(buf, sizeof(buf), "%d", *((const int *const)info->option));
        value = buf;
        break;
      case INFO_OUTPUT_UNSIGNED_INT:
        snprintf(buf, sizeof(buf), "%u", *((const unsigned int *const)info->option));
        value = buf;
        break;
      case INFO_OUTPUT_BOOLEAN:
        value = (info->option && *((const unsigned int *const)info->option)) ? "YES" : "NO";
        break;
      case INFO_OUTPUT_FLOAT:
        snprintf(buf, sizeof(buf), "%f", *((const float *const)info->option));
        value = buf;
        break;
      case INFO_OUTPUT_DOUBLE:
        snprintf(buf, sizeof(buf), "%lf", *((const double *const)info->option));
        value = buf;
        break;
      case INFO_OUTPUT_CHAR:
        snprintf(buf, sizeof(buf), "%c", *((const char *const)info->option));
        value = buf;
        break;
    }

    sendto_one_numeric(client, &me, RPL_INFO | SND_EXPLICIT, ":%-30s %-5s [%s]",
                       info->name, value, info->description);
  }
}
