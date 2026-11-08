/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban.c
 * \brief Implements extended channel bans.
 */

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "io.h"
#include "io_string.h"

#include "channel.h"
#include "channel_mode.h"
#include "extban.h"
#include "isupport.h"

enum { EXTBAN_CAPACITY = 52 };

static const char extban_prefix_char = '$';

static const struct Extban *extban_table[EXTBAN_CAPACITY];
static uint64_t known_matching_mask, known_acting_mask;
static uint64_t case_sensitive_parameter_mask;

uint64_t EXTBAN_JOIN;
uint64_t EXTBAN_KNOCK;
uint64_t EXTBAN_MUTE;
uint64_t EXTBAN_NICK;

static int
_extban_letter_to_index(unsigned char letter)
{
  if (letter >= 'A' && letter <= 'Z')
    return letter - 'A';
  if (letter >= 'a' && letter <= 'z')
    return letter - 'a' + 26;

  return -1;
}

static unsigned char
_extban_index_to_letter(int index)
{
  assert(index >= 0 && index < EXTBAN_CAPACITY);
  return index < 26 ? 'A' + index : 'a' + index - 26;
}

static uint64_t
_extban_letter_to_flag(unsigned char letter)
{
  const int index = _extban_letter_to_index(letter);
  return index < 0 ? 0 : UINT64_C(1) << index;
}

static int
_extban_flag_to_index(uint64_t flag)
{
  if (flag == 0 || (flag & (flag - 1)))
    return -1;

  int index = 0;

  while (flag > 1)
  {
    flag >>= 1;
    ++index;
  }

  return index < EXTBAN_CAPACITY ? index : -1;
}

static bool
_extban_flags_are_valid(uint64_t flags)
{
  const uint64_t matching_flags = flags & known_matching_mask;
  const uint64_t acting_flags = flags & known_acting_mask;

  return (flags & ~(known_matching_mask | known_acting_mask)) == 0 &&
         (matching_flags & (matching_flags - 1)) == 0 && (acting_flags & (acting_flags - 1)) == 0;
}

static void
_extban_invalidate_ban_caches(void)
{
  list_node_t *node;

  LIST_FOREACH(node, channel_get_list()->head)
  {
    struct Channel *const channel = node->data;
    clear_ban_cache_list(&channel->local_member_list);
  }
}

static void
_extban_update_isupport(void)
{
  char value[EXTBAN_CAPACITY + sizeof("$,")];
  size_t length = 0;

  value[length++] = extban_prefix_char;
  value[length++] = ',';

  for (size_t entry_index = 0; entry_index < EXTBAN_CAPACITY; ++entry_index)
    if (extban_table[entry_index])
      value[length++] = extban_table[entry_index]->letter;

  if (length == 2)
  {
    isupport_delete("EXTBAN");
    return;
  }

  value[length] = '\0';
  const isupport_result_t result = isupport_add("EXTBAN", "%s", value);
  assert(result == ISUPPORT_SUCCESS);
  (void)result;
}

extban_result_t
extban_register(const struct Extban *extban)
{
  if (extban == NULL)
    return EXTBAN_INVALID_ARGUMENT;

  const int index = _extban_letter_to_index(extban->letter);
  const uint32_t allowed_list_types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX;
  if (index < 0 ||
      (extban->kind != EXTBAN_KIND_MATCHING && extban->kind != EXTBAN_KIND_ACTING) ||
      extban->list_types == 0 || (extban->list_types & ~allowed_list_types) ||
      (extban->kind == EXTBAN_KIND_MATCHING && extban->matches == NULL) ||
      (extban->kind == EXTBAN_KIND_ACTING && (extban->matches != NULL || extban->parameter_case_sensitive)))
    return EXTBAN_INVALID_ARGUMENT;

  if (extban_table[index])
    return EXTBAN_ALREADY_REGISTERED;

  const uint64_t flag = UINT64_C(1) << index;
  const uint64_t incompatible_mask = extban->kind == EXTBAN_KIND_MATCHING ? known_acting_mask : known_matching_mask;
  if (flag & incompatible_mask)
    return EXTBAN_KIND_CONFLICT;

  if (extban->flag_binding)
    for (size_t entry_index = 0; entry_index < EXTBAN_CAPACITY; ++entry_index)
      if (extban_table[entry_index] &&
          extban_table[entry_index]->flag_binding == extban->flag_binding)
        return EXTBAN_INVALID_ARGUMENT;

  extban_table[index] = extban;

  if (extban->kind == EXTBAN_KIND_MATCHING)
    known_matching_mask |= flag;
  else
    known_acting_mask |= flag;

  if (extban->parameter_case_sensitive)
    case_sensitive_parameter_mask |= flag;
  else
    case_sensitive_parameter_mask &= ~flag;

  if (extban->flag_binding)
    *extban->flag_binding = flag;

  _extban_invalidate_ban_caches();
  _extban_update_isupport();
  return EXTBAN_SUCCESS;
}

extban_result_t
extban_unregister(const struct Extban *extban)
{
  if (extban == NULL)
    return EXTBAN_INVALID_ARGUMENT;

  const int index = _extban_letter_to_index(extban->letter);
  if (index < 0)
    return EXTBAN_INVALID_ARGUMENT;

  if (extban_table[index] != extban)
    return EXTBAN_NOT_FOUND;

  extban_table[index] = NULL;
  if (extban->flag_binding)
    *extban->flag_binding = 0;

  _extban_invalidate_ban_caches();
  _extban_update_isupport();
  return EXTBAN_SUCCESS;
}

const struct Extban *
extban_find_by_letter(unsigned char letter)
{
  const int index = _extban_letter_to_index(letter);
  return index < 0 ? NULL : extban_table[index];
}

const struct Extban *
extban_find_by_flag(uint64_t flag)
{
  const int index = _extban_flag_to_index(flag);
  return index < 0 ? NULL : extban_table[index];
}

bool
extban_validate_local(uint64_t flags, uint32_t list_type, const char *parameter)
{
  if (flags == 0 || !_extban_flags_are_valid(flags) || string_is_empty(parameter) ||
      (list_type != CHFL_BAN && list_type != CHFL_EXCEPTION && list_type != CHFL_INVEX))
    return false;

  const uint64_t component_flags[] = { flags & known_acting_mask, flags & known_matching_mask };

  for (size_t entry_index = 0; entry_index < IO_ARRAY_LENGTH(component_flags); ++entry_index)
  {
    if (component_flags[entry_index] == 0)
      continue;

    const struct Extban *const extban = extban_find_by_flag(component_flags[entry_index]);
    if (extban == NULL || !(extban->list_types & list_type) ||
        (extban->validate_parameter && !extban->validate_parameter(parameter)))
      return false;
  }

  return true;
}

extban_parse_result_t
extban_parse(const char *mask)
{
  if (mask == NULL)
    return (extban_parse_result_t){ .status = EXTBAN_PARSE_INVALID_SYNTAX };
  if (mask[0] != extban_prefix_char)
    return (extban_parse_result_t){ .status = EXTBAN_PARSE_NOT_EXTBAN };
  if (!io_ascii_is_alpha(mask[1]) || mask[2] != ':' || mask[3] == '\0')
    return (extban_parse_result_t){ .status = EXTBAN_PARSE_INVALID_SYNTAX };

  const char *const parameter = mask + 3;
  for (const char *cursor = parameter; *cursor; ++cursor)
    if (io_ascii_is_space(*cursor))
      return (extban_parse_result_t){ .status = EXTBAN_PARSE_INVALID_SYNTAX };

  const struct Extban *extban = extban_find_by_letter(mask[1]);
  if (extban == NULL)
    return (extban_parse_result_t){ .status = EXTBAN_PARSE_UNSUPPORTED };

  uint64_t flags = _extban_letter_to_flag(extban->letter);
  size_t parameter_offset = 3;

  if (extban->kind == EXTBAN_KIND_ACTING)
  {
    if (parameter[0] == extban_prefix_char)
      return (extban_parse_result_t){ .status = EXTBAN_PARSE_INVALID_SYNTAX };

    if (io_ascii_is_alpha(parameter[0]) && parameter[1] == ':')
    {
      if (parameter[2] == '\0')
        return (extban_parse_result_t){ .status = EXTBAN_PARSE_INVALID_SYNTAX };

      extban = extban_find_by_letter(parameter[0]);
      if (extban == NULL)
        return (extban_parse_result_t){ .status = EXTBAN_PARSE_UNSUPPORTED };
      if (extban->kind != EXTBAN_KIND_MATCHING)
        return (extban_parse_result_t){ .status = EXTBAN_PARSE_INVALID_SYNTAX };

      flags |= _extban_letter_to_flag(extban->letter);
      parameter_offset += 2;
    }
  }

  return (extban_parse_result_t)
  {
    .status = EXTBAN_PARSE_SUCCESS,
    .flags = flags,
    .parameter_offset = parameter_offset
  };
}

extban_result_t
extban_format_prefix(uint64_t flags, char *buffer, size_t capacity, size_t *length_out)
{
  if (length_out)
    *length_out = 0;
  if (buffer == NULL)
    return EXTBAN_INVALID_ARGUMENT;
  if (capacity)
    buffer[0] = '\0';
  if (!_extban_flags_are_valid(flags))
    return EXTBAN_INVALID_FLAGS;

  const uint64_t component_flags[] = { flags & known_acting_mask, flags & known_matching_mask };
  const size_t required_length = (flags != 0) + 2 * ((component_flags[0] != 0) + (component_flags[1] != 0));

  if (capacity <= required_length)
    return EXTBAN_BUFFER_TOO_SMALL;

  size_t length = 0;
  for (size_t entry_index = 0; entry_index < IO_ARRAY_LENGTH(component_flags); ++entry_index)
  {
    if (component_flags[entry_index] == 0)
      continue;

    if (length == 0)
      buffer[length++] = extban_prefix_char;

    buffer[length++] = _extban_index_to_letter(_extban_flag_to_index(component_flags[entry_index]));
    buffer[length++] = ':';
  }

  buffer[length] = '\0';
  if (length_out)
    *length_out = length;

  return EXTBAN_SUCCESS;
}

bool
extban_parameters_equal(uint64_t flags, const char *lhs, const char *rhs)
{
  if (flags == 0 || !_extban_flags_are_valid(flags) || lhs == NULL || rhs == NULL)
    return false;

  if (flags & case_sensitive_parameter_mask)
    return strcmp(lhs, rhs) == 0;

  return io_strcasecmp(lhs, rhs) == 0;
}

uint64_t
extban_known_matching_mask(void)
{
  return known_matching_mask;
}

uint64_t
extban_known_acting_mask(void)
{
  return known_acting_mask;
}

const char *
extban_result_to_string(extban_result_t result)
{
  switch (result)
  {
    case EXTBAN_SUCCESS:
      return "Success";
    case EXTBAN_ALREADY_REGISTERED:
      return "Letter already registered";
    case EXTBAN_NOT_FOUND:
      return "Definition not registered";
    case EXTBAN_INVALID_ARGUMENT:
      return "Invalid argument";
    case EXTBAN_KIND_CONFLICT:
      return "Letter already assigned to another extban kind";
    case EXTBAN_INVALID_FLAGS:
      return "Invalid flag combination";
    case EXTBAN_BUFFER_TOO_SMALL:
      return "Buffer too small";
  }

  return "Unknown error";
}
