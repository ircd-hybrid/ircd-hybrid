/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file isupport.c
 * @brief Implementation of IRC ISUPPORT messages (RPL_ISUPPORT) in ircd-hybrid.
 *
 * The ISUPPORT mechanism provides a means for IRC servers to communicate their
 * capabilities and configuration settings to clients during the connection
 * establishment phase. This file contains functions and structures necessary for
 * handling and managing ISUPPORT messages within the ircd-hybrid server.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "memory.h"

#include "client.h"
#include "ircd_defs.h"
#include "isupport.h"
#include "numeric.h"
#include "send.h"

/**
 * @brief Limits for ISUPPORT response lines and token names.
 */
enum
{
  ISUPPORT_TOKENS_PER_LINE = 13,
  ISUPPORT_NAME_LENGTH_MAX = 20
};

/**
 * @struct Isupport
 * @brief Structure representing an IRC ISUPPORT option.
 *
 * This structure stores an ISUPPORT name and its optional value.
 */
struct Isupport
{
  list_node_t node;  /**< Node for linking Isupport structures in a list. */
  char *name;  /**< Name of the ISUPPORT option. */
  char *value;  /**< Encoded value, or NULL for a valueless token. */
};

/**
 * @var isupport_list
 * @brief List containing Isupport structures representing active ISUPPORT options.
 *
 * The isupport_list is a linked list that stores Isupport structures, each representing
 * a unique ISUPPORT option in the ircd-hybrid server. This list serves as the central
 * repository for managing and organizing ISUPPORT options. Various operations, such as
 * addition, deletion, and retrieval, are performed on this list to maintain and update
 * ISUPPORT options dynamically.
 */
static list_t isupport_list;

/**
 * @var isupport_list_lines
 * @brief List containing formatted ISUPPORT strings for transmission.
 *
 * The isupport_list_lines is a linked list that stores formatted ISUPPORT strings, each
 * representing a line of ISUPPORT information suitable for sending to clients. These
 * strings are constructed based on the options stored in the isupport_list. The list is
 * updated and rebuilt as needed to reflect the current set of supported features and
 * configurations.
 */
static list_t isupport_list_lines;

static bool
_isupport_name_is_valid(const char *name)
{
  if (string_is_empty(name))
    return false;

  size_t length = 0;
  for (const unsigned char *p = (const unsigned char *)name; *p; ++p)
    if (++length > ISUPPORT_NAME_LENGTH_MAX ||
        !(io_ascii_is_upper(*p) || io_ascii_is_digit(*p)))
      return false;

  return true;
}

static isupport_result_t
_isupport_encode_value(const char *value, size_t length, char *buffer,
                       size_t buffer_size, size_t *encoded_length)
{
  size_t written = 0;

  assert(buffer_size > 0);

  for (size_t i = 0; i < length; ++i)
  {
    const unsigned char ch = (unsigned char)value[i];
    if (ch < ' ' || ch > '~')
      return ISUPPORT_INVALID_VALUE;

    const bool escaped = ch == ' ' || ch == '\\';
    const size_t encoded_size = escaped ? 4 : 1;
    if (encoded_size >= buffer_size - written)
      return ISUPPORT_TOO_LONG;

    if (escaped)
      memcpy(buffer + written, ch == ' ' ? "\\x20" : "\\x5C", encoded_size);
    else
      buffer[written] = (char)ch;

    written += encoded_size;
  }

  buffer[written] = '\0';
  *encoded_length = written;
  return ISUPPORT_SUCCESS;
}

static size_t
_isupport_line_limit(void)
{
  const size_t overhead = HOSTLEN + NICKLEN + sizeof(": 005  \r\n") - 1;
  const int suffix_length = snprintf(NULL, 0, numeric_form(RPL_ISUPPORT), "");

  if (overhead >= IRCD_BUFSIZE || suffix_length < 0 ||
      (size_t)suffix_length >= IRCD_BUFSIZE - overhead)
    return 0;

  return IRCD_BUFSIZE - overhead - (size_t)suffix_length;
}

/**
 * @brief Clears the list of lines used for RPL_ISUPPORT messages.
 *
 * This function removes all stored lines in preparation for rebuilding
 * the RPL_ISUPPORT response. It iterates through the list of lines,
 * deallocates memory, and frees the associated data.
 */
static void
_isupport_clear_lines(void)
{
  list_node_t *node;

  while ((node = list_pop_head(&isupport_list_lines)))
  {
    assert(node->data);

    io_free(node->data);
    list_free_node(node);
  }
}

/**
 * @brief Constructs formatted lines for ISUPPORT messages.
 *
 * This function constructs formatted lines for ISUPPORT messages based on the ISUPPORT
 * options stored in the isupport_list. Each line represents a set of ISUPPORT options,
 * and the resulting lines are stored in isupport_list_lines.
 */
static void
_isupport_build_lines(size_t line_limit)
{
  char line[IRCD_BUFSIZE];
  size_t line_length = 0;
  unsigned int token_count = 0;

  assert(line_limit > 0 && line_limit < sizeof(line));

  _isupport_clear_lines();

  list_node_t *node;
  LIST_FOREACH(node, isupport_list.head)
  {
    const struct Isupport *const support = node->data;

    const size_t name_length = strlen(support->name);
    const size_t value_length = support->value ? strlen(support->value) : 0;
    const size_t token_length = name_length + (support->value ? value_length + 1 : 0);

    assert(name_length > 0 && token_length <= line_limit);

    if (token_count && (token_count == ISUPPORT_TOKENS_PER_LINE ||
                        token_length >= line_limit - line_length))
    {
      list_add_tail(io_strdup(line), list_make_node(), &isupport_list_lines);
      line_length = 0;
      token_count = 0;
    }

    if (token_count)
      line[line_length++] = ' ';

    memcpy(line + line_length, support->name, name_length);
    line_length += name_length;

    if (support->value)
    {
      line[line_length++] = '=';
      memcpy(line + line_length, support->value, value_length);
      line_length += value_length;
    }

    line[line_length] = '\0';
    ++token_count;
  }

  if (token_count)
    list_add_tail(io_strdup(line), list_make_node(), &isupport_list_lines);
}

/**
 * @brief Finds an ISUPPORT option by name.
 *
 * Searches the list of ISUPPORT options for an option with the specified name.
 *
 * @param name The name of the ISUPPORT option to find.
 * @return A pointer to the Isupport structure if found, otherwise NULL.
 */
static struct Isupport *
_isupport_find(const char *name)
{
  list_node_t *node;

  LIST_FOREACH(node, isupport_list.head)
  {
    struct Isupport *const support = node->data;
    if (io_strcasecmp(support->name, name) == 0)
      return support;
  }

  return NULL;
}

static int
_isupport_cmp(const void *const a_, const void *const b_)
{
  const char *const a = ((const struct Isupport *)a_)->name;
  const char *const b = ((const struct Isupport *)b_)->name;
  return io_strcasecmp(a, b);
}

/**
 * @brief Creates a new ISUPPORT option.
 *
 * Creates a new ISUPPORT option with the specified name and optional value.
 *
 * @param name The name of the ISUPPORT option.
 * @param value The optional value associated with the ISUPPORT option.
 * @return A pointer to the newly created Isupport structure.
 */
static struct Isupport *
_isupport_create(const char *name, const char *value)
{
  struct Isupport *const support = io_calloc(sizeof(*support));
  support->name = io_strdup(name);
  support->value = value ? io_strdup(value) : NULL;

  list_add_sorted(support, &support->node, &isupport_list, _isupport_cmp);
  return support;
}

/**
 * @brief Destroys an ISUPPORT option.
 *
 * Removes an ISUPPORT option from the list and deallocates its memory.
 *
 * @param support A pointer to the Isupport structure to destroy.
 */
static void
_isupport_destroy(struct Isupport *support)
{
  list_remove(&support->node, &isupport_list);
  io_free(support->name);
  io_free(support->value);
  io_free(support);
}

/**
 * @brief Adds or updates an ISUPPORT option.
 *
 * Validates the name, formatted value and complete token length before changing
 * the registry. Failed updates preserve both the previous entry and output.
 *
 * @param name The name of the ISUPPORT option.
 * @param format Format for the optional value, or NULL for a valueless token.
 * @return ISUPPORT_SUCCESS or the reason the update was rejected.
 */
isupport_result_t
isupport_add(const char *name, const char *format, ...)
{
  if (!_isupport_name_is_valid(name))
    return ISUPPORT_INVALID_NAME;

  char encoded_value[IRCD_BUFSIZE];
  size_t value_length = 0;

  if (format)
  {
    char formatted_value[IRCD_BUFSIZE];
    va_list args;

    va_start(args, format);
    const int length = vsnprintf(formatted_value, sizeof(formatted_value), format, args);
    va_end(args);

    if (length < 0)
      return ISUPPORT_FORMAT_ERROR;
    if ((size_t)length >= sizeof(formatted_value))
      return ISUPPORT_TOO_LONG;

    const isupport_result_t result =
      _isupport_encode_value(formatted_value, (size_t)length, encoded_value, sizeof(encoded_value), &value_length);
    if (result != ISUPPORT_SUCCESS)
      return result;
  }

  const size_t line_limit = _isupport_line_limit();
  if (line_limit == 0)
    return ISUPPORT_FORMAT_ERROR;

  const size_t token_length = strlen(name) + (value_length ? value_length + 1 : 0);
  if (token_length > line_limit)
    return ISUPPORT_TOO_LONG;

  struct Isupport *const support = _isupport_find(name);
  if (support)
  {
    char *const value = value_length ? io_strdup(encoded_value) : NULL;
    io_free(support->value);
    support->value = value;
  }
  else
    _isupport_create(name, value_length ? encoded_value : NULL);

  _isupport_build_lines(line_limit);
  return ISUPPORT_SUCCESS;
}

const char *
isupport_result_to_string(isupport_result_t result)
{
  switch (result)
  {
    case ISUPPORT_SUCCESS:       return "Success";
    case ISUPPORT_INVALID_NAME:  return "Invalid token name";
    case ISUPPORT_INVALID_VALUE: return "Invalid token value";
    case ISUPPORT_FORMAT_ERROR:  return "Formatting failed";
    case ISUPPORT_TOO_LONG:      return "Token exceeds the ISUPPORT line limit";
  }

  return "Unknown ISUPPORT result";
}

/**
 * @brief Deletes an ISUPPORT option.
 *
 * Deletes an ISUPPORT option with the specified name. After deletion,
 * the ISUPPORT lines are rebuilt.
 *
 * @param name The name of the ISUPPORT option to delete.
 */
void
isupport_delete(const char *name)
{
  if (string_is_empty(name))
    return;

  struct Isupport *const support = _isupport_find(name);
  if (support == NULL)
    return;

  const size_t line_limit = _isupport_line_limit();
  assert(line_limit > 0);
  if (line_limit == 0)
    return;

  _isupport_destroy(support);

  _isupport_build_lines(line_limit);
}

/**
 * @brief Displays ISUPPORT information to a client.
 *
 * Sends formatted ISUPPORT messages to a client to inform them about the
 * server's supported features and settings.
 *
 * @param client A pointer to the Client structure.
 */
void
isupport_show(struct Client *client)
{
  list_node_t *node;

  LIST_FOREACH(node, isupport_list_lines.head)
  {
    const char *const string = node->data;
    sendto_one_numeric(client, &me, RPL_ISUPPORT, string);
  }
}
