/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2015-2016 plexus development team
 *  Copyright (c) 2019-2026 ircd-hybrid development team
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

/*! \file extban.h
 * \brief Implements extended channel bans.
 */

#ifndef INCLUDED_extban_h
#define INCLUDED_extban_h
#include <stddef.h>
#include <stdint.h>

#include "list.h"

struct Channel;
struct Client;
struct Ban;
struct ChannelMember;

#define EXTBAN_MASK UINT32_MAX  /* All possible mask values */

enum extban_type
{
  EXTBAN_NONE,
  EXTBAN_INVALID  = 1 << 0,
  EXTBAN_MATCHING = 1 << 1,
  EXTBAN_ACTING   = 1 << 2
};

enum extban_match
{
  EXTBAN_NO_MATCH,
  EXTBAN_MATCH
};

struct Extban
{
  list_node_t node;
  unsigned char character;
  enum extban_type type;
  int (*is_valid)(const char *);
  enum extban_match (*matches)(struct Client *, struct Channel *, struct Ban *);
  uint32_t types;  /* CHFL_BAN/EXCEPTION/INVEX */
  uint32_t flag;
};

extern struct Extban extban_account;
extern struct Extban extban_channel;
extern struct Extban extban_fingerprint;
extern struct Extban extban_gecos;
extern struct Extban extban_join;
extern struct Extban extban_knock;
extern struct Extban extban_mute;
extern struct Extban extban_nick;
extern struct Extban extban_operclass;
extern struct Extban extban_server;
extern struct Extban extban_tlsinfo;
extern struct Extban extban_usermode;

extern void extban_init(void);
extern void extban_add(struct Extban *);
extern void extban_del(struct Extban *);
extern enum extban_type extban_parse(const char *, uint32_t *, size_t *);
extern size_t extban_format(uint32_t, char *);
extern uint32_t extban_matching_mask(void);
extern uint32_t extban_acting_mask(void);
extern struct Extban *extban_find(unsigned char);
extern struct Extban *extban_find_flag(uint32_t);
extern const char *extban_get_isupport(void);
#endif  /* INCLUDED_extban_h */
