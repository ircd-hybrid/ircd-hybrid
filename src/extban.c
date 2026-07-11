/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban.c
 * \brief Implements extended channel bans.
 */

#include <string.h>

#include "io_string.h"
#include "client.h"
#include "extban.h"
#include "isupport.h"

static list_t extban_list;
static uint32_t matching_mask, acting_mask;

static uint32_t
_extban_find_mask(void)
{
  uint32_t used = 0;

  list_node_t *node;
  LIST_FOREACH(node, extban_list.head)
  {
    const struct Extban *const extban = node->data;
    used |= extban->flag;
  }

  uint32_t i;
  for (i = 1; (i < EXTBAN_MASK) && (used & i); i <<= 1)
    ;

  return i;
}

void
extban_init(void)
{
  extban_add(&extban_account);
  extban_add(&extban_channel);
  extban_add(&extban_fingerprint);
  extban_add(&extban_gecos);
  extban_add(&extban_join);
  extban_add(&extban_knock);
  extban_add(&extban_mute);
  extban_add(&extban_nick);
  extban_add(&extban_operclass);
  extban_add(&extban_server);
  extban_add(&extban_tlsinfo);
  extban_add(&extban_usermode);

  const char *ptr = extban_get_isupport();
  if (ptr)
    isupport_add("EXTBAN", "%s", ptr);
}

void
extban_add(struct Extban *extban)
{
  const uint32_t mask = _extban_find_mask();
  if (mask == 0)
    return;

  extban->flag = mask;
  list_add(extban, &extban->node, &extban_list);

  if (extban->type & EXTBAN_MATCHING)
    matching_mask |= mask;
  if (extban->type & EXTBAN_ACTING)
    acting_mask |= mask;
}

void
extban_del(struct Extban *extban)
{
  if (extban->flag == 0)
    return;

  list_remove(&extban->node, &extban_list);

  matching_mask &= ~extban->flag;
  acting_mask &= ~extban->flag;
}

struct Extban *
extban_find(unsigned char c)
{
  list_node_t *node;

  LIST_FOREACH(node, extban_list.head)
  {
    struct Extban *const extban = node->data;
    if (extban->character == c)
      return extban;
  }

  return NULL;
}

struct Extban *
extban_find_flag(uint32_t flag)
{
  list_node_t *node;

  LIST_FOREACH(node, extban_list.head)
  {
    struct Extban *const extban = node->data;
    if (extban->flag == flag)
      return extban;
  }

  return NULL;
}

enum extban_type
extban_parse(const char *mask, uint32_t *input_extbans, size_t *offset)
{
  *input_extbans = *offset = 0;

  if (!(*mask == '$' && IsAlpha(*(mask + 1)) && *(mask + 2) == ':'))
    return EXTBAN_NONE;

  const struct Extban *extban = extban_find(*(mask + 1));
  if (extban == NULL)
    return EXTBAN_INVALID;

  *input_extbans |= extban->flag;
  *offset += 3;
  mask += 3;

  /* Matching extbans take a special parameter, so stop reading */
  if (extban->type == EXTBAN_MATCHING)
    return EXTBAN_MATCHING;

  if (!(IsAlpha(*mask) && *(mask + 1) == ':'))
    return EXTBAN_ACTING;

  extban = extban_find(*mask);
  if (extban == NULL)
    return EXTBAN_INVALID;

  /* Two acting extbans make no sense */
  if (extban->type == EXTBAN_ACTING)
    return EXTBAN_INVALID;

  /* Check parameter */
  if (extban->is_valid && extban->is_valid(mask) == EXTBAN_INVALID)
    return EXTBAN_INVALID;

  *input_extbans |= extban->flag;
  *offset += 2;
  return EXTBAN_MATCHING;
}

size_t
extban_format(uint32_t e, char *buf)
{
  size_t written = 0;

  list_node_t *node;
  LIST_FOREACH(node, extban_list.head)
  {
    const struct Extban *const extban = node->data;
    if (extban->type != EXTBAN_ACTING || !(extban->flag & e))
      continue;

    if (written == 0)
    {
      written++;
      *buf++ = '$';
    }

    *buf++ = extban->character;
    *buf++ = ':';
    written += 2;

    break;
  }

  LIST_FOREACH(node, extban_list.head)
  {
    const struct Extban *const extban = node->data;
    if (extban->type != EXTBAN_MATCHING || !(extban->flag & e))
      continue;

    if (written == 0)
    {
      written++;
      *buf++ = '$';
    }

    *buf++ = extban->character;
    *buf++ = ':';
    written += 2;

    break;
  }

  return written;
}

uint32_t
extban_matching_mask(void)
{
  return matching_mask;
}

uint32_t
extban_acting_mask(void)
{
  return acting_mask;
}

const char *
extban_get_isupport(void)
{
  char extban_chars[256] = { 0 };
  static char buf[sizeof(extban_chars) + 3 /* +3 = $,\0 */ ];

  if (list_is_empty(&extban_list))
    return NULL;

  list_node_t *node;
  LIST_FOREACH(node, extban_list.head)
  {
    const struct Extban *const extban = node->data;
    extban_chars[extban->character] = extban->character;
  }

  char *p = buf + strlcpy(buf, "$,", sizeof(buf));

  for (size_t i = 0; i < sizeof(extban_chars); ++i)
    if (extban_chars[i])
      *p++ = extban_chars[i];
  *p = '\0';

  return buf;
}

