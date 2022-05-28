/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2016 plexus development team
 *  Copyright (c) 2019-2022 ircd-hybrid development team
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

/*! \file extban.c
 * \brief Implements extended channel bans.
 * \version $Id$
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "list.h"
#include "irc_string.h"
#include "user.h"
#include "isupport.h"
#include "extban.h"


static dlink_list extban_list;
static unsigned int matching_mask, acting_mask;


static unsigned int
extban_find_mask(void)
{
  dlink_node *node;
  unsigned int used = 0;
  unsigned int i;

  DLINK_FOREACH(node, extban_list.head)
  {
    const struct Extban *extban = node->data;
    used |= extban->flag;
  }

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
  extban_add(&extban_mute);
  extban_add(&extban_nick);
  extban_add(&extban_operclass);
  extban_add(&extban_server);
  extban_add(&extban_tlsinfo);
  extban_add(&extban_usermode);

  const char *ptr = extban_get_isupport();
  if (ptr)
    isupport_add("EXTBAN", ptr, -1);
}

void
extban_add(struct Extban *extban)
{
  unsigned int mask = extban_find_mask();

  if (mask == 0)
    return;

  extban->flag = mask;
  dlinkAdd(extban, &extban->node, &extban_list);

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

  dlinkDelete(&extban->node, &extban_list);

  matching_mask &= ~extban->flag;
  acting_mask &= ~extban->flag;
}

struct Extban *
extban_find(unsigned char c)
{
  dlink_node *node;

  DLINK_FOREACH(node, extban_list.head)
  {
    struct Extban *extban = node->data;

    if (extban->character == c)
      return extban;
  }

  return NULL;
}

struct Extban *
extban_find_flag(unsigned int flag)
{
  dlink_node *node;

  DLINK_FOREACH(node, extban_list.head)
  {
    struct Extban *extban = node->data;

    if (extban->flag == flag)
      return extban;
  }

  return NULL;
}

enum extban_type
extban_parse(const char *mask, unsigned int *input_extbans, unsigned int *offset)
{
  *input_extbans = 0;
  *offset = 0;

  if (*mask == '$' && IsAlpha(*(mask + 1)) && *(mask + 2) == ':')
  {
    struct Extban *extban = extban_find(*(mask + 1));
    if (extban == NULL)
      return EXTBAN_INVALID;

    *input_extbans |= extban->flag;
    *offset += 3;
    mask += 3;

    /* Matching extbans take a special parameter, so stop reading */
    if (extban->type == EXTBAN_MATCHING)
      return EXTBAN_MATCHING;

    if (IsAlpha(*mask) && *(mask + 1) == ':')
    {
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
      mask += 2;

      return EXTBAN_MATCHING;
    }

    return EXTBAN_ACTING;
  }

  return EXTBAN_NONE;
}

size_t
extban_format(unsigned int e, char *buf)
{
  dlink_node *node;
  size_t written = 0;

  DLINK_FOREACH(node, extban_list.head)
  {
    struct Extban *extban = node->data;

    if (extban->type != EXTBAN_ACTING)
      continue;

    if (extban->flag & e)
    {
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
  }

  DLINK_FOREACH(node, extban_list.head)
  {
    struct Extban *extban = node->data;

    if (extban->type != EXTBAN_MATCHING)
      continue;

    if (extban->flag & e)
    {
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
  }

  return written;
}

unsigned int
extban_matching_mask(void)
{
  return matching_mask;
}

unsigned int
extban_acting_mask(void)
{
  return acting_mask;
}

const char *
extban_get_isupport(void)
{
  dlink_node *node;
  char extban_chars[256] = { 0 };
  static char buf[sizeof(extban_chars) + 3 /* +3 = $,\0 */ ];

  if (dlink_list_length(&extban_list) == 0)
    return NULL;

  DLINK_FOREACH(node, extban_list.head)
  {
    struct Extban *extban = node->data;
    extban_chars[extban->character] = extban->character;
  }

  char *p = buf + strlcpy(buf, "$,", sizeof(buf));

  for (unsigned int i = 0; i < 256; ++i)
    if (extban_chars[i])
      *p++ = extban_chars[i];
  *p = '\0';

  return buf;
}

