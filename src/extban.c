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

#include "io.h"
#include "io_string.h"

#include "channel.h"
#include "channel_mode.h"
#include "extban.h"
#include "isupport.h"

enum { EXTBAN_CAPACITY = 52 };

static const char extban_prefix_char = '$';

struct extban_slot
{
  const struct Extban *definition;
  enum extban_type type;
};

static struct extban_slot extban_table[EXTBAN_CAPACITY];
static uint64_t matching_mask, acting_mask;

uint64_t EXTBAN_JOIN;
uint64_t EXTBAN_KNOCK;
uint64_t EXTBAN_MUTE;
uint64_t EXTBAN_NICK;

static int
_extban_char_to_index(unsigned char character)
{
  if (character >= 'A' && character <= 'Z')
    return character - 'A';
  if (character >= 'a' && character <= 'z')
    return character - 'a' + 26;

  return -1;
}

static unsigned char
_extban_index_to_char(size_t index)
{
  assert(index < EXTBAN_CAPACITY);
  return index < 26 ? 'A' + index : 'a' + index - 26;
}

static uint64_t
_extban_char_to_flag(unsigned char character)
{
  const int index = _extban_char_to_index(character);
  return index < 0 ? 0 : UINT64_C(1) << index;
}

static void
_extban_invalidate_ban_caches(void)
{
  list_node_t *node;

  LIST_FOREACH(node, channel_get_list()->head)
  {
    struct Channel *const channel = node->data;
    clear_ban_cache_list(&channel->member_list);
  }
}

static void
_extban_update_isupport(void)
{
  char value[EXTBAN_CAPACITY + sizeof("$,")];
  size_t length = 0;

  value[length++] = extban_prefix_char;
  value[length++] = ',';

  for (size_t i = 0; i < EXTBAN_CAPACITY; ++i)
    if (extban_table[i].definition)
      value[length++] = extban_table[i].definition->character;

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

  const int index = _extban_char_to_index(extban->character);
  const uint32_t allowed_types = CHFL_BAN | CHFL_EXCEPTION | CHFL_INVEX;
  if (index < 0 ||
      (extban->type != EXTBAN_MATCHING && extban->type != EXTBAN_ACTING) ||
      extban->types == 0 || (extban->types & ~allowed_types) ||
      (extban->type == EXTBAN_MATCHING && extban->matches == NULL) ||
      (extban->type == EXTBAN_ACTING && extban->matches != NULL))
    return EXTBAN_INVALID_ARGUMENT;

  struct extban_slot *const slot = &extban_table[index];
  if (slot->definition)
    return EXTBAN_ALREADY_REGISTERED;
  if (slot->type != EXTBAN_NONE && slot->type != extban->type)
    return EXTBAN_TYPE_CONFLICT;

  if (extban->flag_out)
    for (size_t i = 0; i < EXTBAN_CAPACITY; ++i)
      if (extban_table[i].definition && extban_table[i].definition->flag_out == extban->flag_out)
        return EXTBAN_INVALID_ARGUMENT;

  const uint64_t flag = UINT64_C(1) << index;
  slot->definition = extban;
  slot->type = extban->type;

  if (extban->type == EXTBAN_MATCHING)
    matching_mask |= flag;
  else
    acting_mask |= flag;

  if (extban->flag_out)
    *extban->flag_out = flag;

  _extban_invalidate_ban_caches();
  _extban_update_isupport();
  return EXTBAN_SUCCESS;
}

extban_result_t
extban_unregister(const struct Extban *extban)
{
  if (extban == NULL)
    return EXTBAN_INVALID_ARGUMENT;

  const int index = _extban_char_to_index(extban->character);
  if (index < 0)
    return EXTBAN_INVALID_ARGUMENT;

  struct extban_slot *const slot = &extban_table[index];
  if (slot->definition != extban)
    return EXTBAN_NOT_FOUND;

  slot->definition = NULL;
  if (extban->flag_out)
    *extban->flag_out = 0;

  _extban_invalidate_ban_caches();
  _extban_update_isupport();
  return EXTBAN_SUCCESS;
}

const struct Extban *
extban_find(unsigned char character)
{
  const int index = _extban_char_to_index(character);
  return index < 0 ? NULL : extban_table[index].definition;
}

const struct Extban *
extban_find_flag(uint64_t flag)
{
  if (flag == 0 || (flag & (flag - 1)))
    return NULL;

  size_t index = 0;

  while (flag > 1)
  {
    flag >>= 1;
    ++index;
  }

  return index < EXTBAN_CAPACITY ? extban_table[index].definition : NULL;
}

enum extban_type
extban_parse(const char *mask, uint64_t *input_extbans, size_t *offset)
{
  *input_extbans = *offset = 0;

  if (!(mask[0] == extban_prefix_char && io_ascii_is_alpha(mask[1]) && mask[2] == ':'))
    return EXTBAN_NONE;

  const struct Extban *extban = extban_find(*(mask + 1));
  if (extban == NULL)
    return EXTBAN_INVALID;

  *input_extbans |= _extban_char_to_flag(extban->character);
  *offset += 3;
  mask += 3;

  /* Matching extbans take a special parameter, so stop reading */
  if (extban->type == EXTBAN_MATCHING)
    return EXTBAN_MATCHING;

  if (!(io_ascii_is_alpha(mask[0]) && mask[1] == ':'))
    return EXTBAN_ACTING;

  extban = extban_find(mask[0]);
  if (extban == NULL)
    return EXTBAN_INVALID;

  /* Two acting extbans make no sense */
  if (extban->type == EXTBAN_ACTING)
    return EXTBAN_INVALID;

  /* Check parameter */
  if (extban->is_valid && extban->is_valid(mask) == EXTBAN_INVALID)
    return EXTBAN_INVALID;

  *input_extbans |= _extban_char_to_flag(extban->character);
  *offset += 2;
  return EXTBAN_MATCHING;
}

size_t
extban_format(uint64_t flags, char *buffer)
{
  static const enum extban_type types[] = { EXTBAN_ACTING, EXTBAN_MATCHING };
  size_t written = 0;

  for (size_t type = 0; type < IO_ARRAY_LENGTH(types); ++type)
  {
    for (size_t i = 0; i < EXTBAN_CAPACITY; ++i)
    {
      if (extban_table[i].type != types[type] || !(flags & (UINT64_C(1) << i)))
        continue;

      if (written == 0)
        buffer[written++] = extban_prefix_char;

      buffer[written++] = _extban_index_to_char(i);
      buffer[written++] = ':';
      break;
    }
  }

  return written;
}

uint64_t
extban_matching_mask(void)
{
  return matching_mask;
}

uint64_t
extban_acting_mask(void)
{
  return acting_mask;
}

const char *
extban_result_to_string(extban_result_t result)
{
  switch (result)
  {
    case EXTBAN_SUCCESS:
      return "Success";
    case EXTBAN_ALREADY_REGISTERED:
      return "Character already registered";
    case EXTBAN_NOT_FOUND:
      return "Definition not registered";
    case EXTBAN_INVALID_ARGUMENT:
      return "Invalid definition";
    case EXTBAN_TYPE_CONFLICT:
      return "Character already assigned to another extban type";
  }

  return "Unknown error";
}
