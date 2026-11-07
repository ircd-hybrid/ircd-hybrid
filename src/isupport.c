/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file isupport.c
 * @brief Implementation of IRC ISUPPORT messages (RPL_ISUPPORT) in ircd-hybrid.
 *
 * The ISUPPORT mechanism provides a means for IRC servers to communicate their
 * capabilities and configuration settings to clients at registration and when
 * these features change. This file contains functions and structures necessary for
 * handling and managing ISUPPORT messages within the ircd-hybrid server.
 */

#include <assert.h>
#include <limits.h>
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

struct IsupportLineBuilder
{
  list_t *lines;
  size_t limit;
  size_t length;
  unsigned int token_count;
  char buffer[IRCD_BUFSIZE];
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
 * @brief Published ISUPPORT response lines.
 *
 * The cache remains unchanged while an update batch is open. It is rebuilt once
 * when the outermost batch commits an actual change to the advertised tokens.
 */
static list_t isupport_list_lines;

static struct
{
  list_t baseline;
  unsigned int depth;
  bool has_baseline;
} isupport_notify_batch;

static bool
_isupport_values_equal(const char *lhs, const char *rhs)
{
  return lhs == rhs || (lhs && rhs && strcmp(lhs, rhs) == 0);
}

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
_isupport_clear_lines(list_t *lines)
{
  list_node_t *node;

  while ((node = list_pop_head(lines)))
  {
    assert(node->data);

    io_free(node->data);
    list_free_node(node);
  }
}

static void
_isupport_line_flush(struct IsupportLineBuilder *builder)
{
  if (builder->token_count == 0)
    return;

  list_add_tail(io_strdup(builder->buffer), list_make_node(), builder->lines);
  builder->length = 0;
  builder->token_count = 0;
}

static void
_isupport_line_append(struct IsupportLineBuilder *builder, const char *name, const char *value)
{
  const size_t name_length = strlen(name);
  const size_t value_length = value ? strlen(value) : 0;
  const size_t token_length = name_length + (value ? value_length + 1 : 0);

  assert(builder->limit > 0 && builder->limit < sizeof(builder->buffer));
  assert(name_length > 0 && token_length <= builder->limit);

  if (builder->token_count && (builder->token_count == ISUPPORT_TOKENS_PER_LINE ||
                               token_length >= builder->limit - builder->length))
    _isupport_line_flush(builder);

  if (builder->token_count)
    builder->buffer[builder->length++] = ' ';

  memcpy(builder->buffer + builder->length, name, name_length);
  builder->length += name_length;

  if (value)
  {
    builder->buffer[builder->length++] = '=';
    memcpy(builder->buffer + builder->length, value, value_length);
    builder->length += value_length;
  }

  builder->buffer[builder->length] = '\0';
  ++builder->token_count;
}

static void
_isupport_build_lines(size_t line_limit)
{
  struct IsupportLineBuilder builder = { .lines = &isupport_list_lines, .limit = line_limit };
  _isupport_clear_lines(&isupport_list_lines);

  list_node_t *node;
  LIST_FOREACH(node, isupport_list.head)
  {
    const struct Isupport *const support = node->data;
    _isupport_line_append(&builder, support->name, support->value);
  }

  _isupport_line_flush(&builder);
}

static void
_isupport_line_append_negation(struct IsupportLineBuilder *builder, const char *name)
{
  char token[ISUPPORT_NAME_LENGTH_MAX + sizeof("-")];

  token[0] = '-';
  memcpy(token + 1, name, strlen(name) + 1);
  _isupport_line_append(builder, token, NULL);
}

static void
_isupport_notify_build_lines(const list_t *before, list_t *lines, size_t line_limit)
{
  struct IsupportLineBuilder builder = { .lines = lines, .limit = line_limit };
  const list_node_t *old_node = before->head;
  const list_node_t *new_node = isupport_list.head;

  /* Both lists are sorted by name, so each entry is visited once. */
  while (old_node && new_node)
  {
    const struct Isupport *const old = old_node->data;
    const struct Isupport *const current = new_node->data;

    const int comparison = io_strcasecmp(old->name, current->name);
    if (comparison < 0)
    {
      _isupport_line_append_negation(&builder, old->name);
      old_node = old_node->next;
    }
    else if (comparison > 0)
    {
      _isupport_line_append(&builder, current->name, current->value);
      new_node = new_node->next;
    }
    else
    {
      if (!_isupport_values_equal(old->value, current->value))
        _isupport_line_append(&builder, current->name, current->value);

      old_node = old_node->next;
      new_node = new_node->next;
    }
  }

  for (; old_node; old_node = old_node->next)
  {
    const struct Isupport *const old = old_node->data;
    _isupport_line_append_negation(&builder, old->name);
  }

  for (; new_node; new_node = new_node->next)
  {
    const struct Isupport *const current = new_node->data;
    _isupport_line_append(&builder, current->name, current->value);
  }

  _isupport_line_flush(&builder);
}

static void
_isupport_send_lines(struct Client *client, const list_t *lines)
{
  list_node_t *node;

  LIST_FOREACH(node, lines->head)
  {
    const char *const string = node->data;
    sendto_one_numeric(client, &me, RPL_ISUPPORT, string);
  }
}

static void
_isupport_notify_publish(const list_t *lines)
{
  list_node_t *node;

  LIST_FOREACH(node, local_client_list.head)
  {
    struct Client *const client = node->data;
    _isupport_send_lines(client, lines);
  }
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

  return support;
}

/**
 * @brief Destroys an ISUPPORT option.
 *
 * Deallocates an ISUPPORT option which has already been unlinked.
 *
 * @param support A pointer to the Isupport structure to destroy.
 */
static void
_isupport_destroy(struct Isupport *support)
{
  io_free(support->name);
  io_free(support->value);
  io_free(support);
}

static void
_isupport_snapshot_capture(list_t *snapshot)
{
  assert(list_is_empty(snapshot));

  list_node_t *node;
  LIST_FOREACH(node, isupport_list.head)
  {
    const struct Isupport *const support = node->data;

    struct Isupport *const copy = _isupport_create(support->name, support->value);
    list_add_tail(copy, &copy->node, snapshot);
  }
}

static void
_isupport_snapshot_clear(list_t *snapshot)
{
  list_node_t *node;

  while ((node = list_pop_head(snapshot)))
    _isupport_destroy(node->data);
}

static void
_isupport_notify_capture_baseline(void)
{
  assert(isupport_notify_batch.depth > 0);

  /* Before the first mutation, the registry still matches the published state. */
  if (!isupport_notify_batch.has_baseline)
  {
    _isupport_snapshot_capture(&isupport_notify_batch.baseline);
    isupport_notify_batch.has_baseline = true;
  }
}

void
isupport_notify_batch_begin(void)
{
  assert(isupport_notify_batch.depth < UINT_MAX);
  ++isupport_notify_batch.depth;
}

void
isupport_notify_batch_end(void)
{
  assert(isupport_notify_batch.depth > 0);

  if (--isupport_notify_batch.depth || !isupport_notify_batch.has_baseline)
    return;

  list_t lines = { 0 };
  const size_t line_limit = _isupport_line_limit();
  assert(line_limit > 0);

  if (line_limit)
    _isupport_notify_build_lines(&isupport_notify_batch.baseline, &lines, line_limit);

  _isupport_snapshot_clear(&isupport_notify_batch.baseline);
  isupport_notify_batch.has_baseline = false;

  if (!list_is_empty(&lines))
  {
    _isupport_build_lines(line_limit);
    _isupport_notify_publish(&lines);
  }

  _isupport_clear_lines(&lines);
}

/**
 * @brief Adds or updates an ISUPPORT option.
 *
 * Validates the name, formatted value and complete token length before changing
 * the registry. Failed updates preserve both the previous entry and output.
 * Accepted changes are published when the outermost update batch ends.
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
  const char *const value = value_length ? encoded_value : NULL;
  if (support && _isupport_values_equal(support->value, value))
    return ISUPPORT_SUCCESS;

  isupport_notify_batch_begin();
  _isupport_notify_capture_baseline();

  if (support)
  {
    char *const copy = value ? io_strdup(value) : NULL;

    io_free(support->value);
    support->value = copy;
  }
  else
  {
    struct Isupport *const entry = _isupport_create(name, value);
    list_add_sorted(entry, &entry->node, &isupport_list, _isupport_cmp);
  }

  isupport_notify_batch_end();
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
 * Deletes an ISUPPORT option with the specified name. The published response
 * and connected clients are updated when the outermost batch ends.
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

  isupport_notify_batch_begin();
  _isupport_notify_capture_baseline();
  list_remove(&support->node, &isupport_list);
  _isupport_destroy(support);

  isupport_notify_batch_end();
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
  _isupport_send_lines(client, &isupport_list_lines);
}
