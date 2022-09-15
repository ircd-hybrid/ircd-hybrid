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

/*! \file extban.h
 * \brief Implements extended channel bans.
 */

#ifndef INCLUDED_extban_h
#define INCLUDED_extban_h

struct Channel;
struct Client;
struct Ban;
struct ChannelMember;

enum
{
  /* All possible mask values */
  EXTBAN_MASK = 0xFFFFFFFF
};

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
  unsigned char character;
  enum extban_type type;
  int (*is_valid)(const char *);
  enum extban_match (*matches)(struct Client *, struct Channel *, struct Ban *);
  unsigned int types;  /* CHFL_BAN/EXCEPTION/INVEX */
  unsigned int flag;
  dlink_node node;
};

extern void extban_init(void);
extern void extban_add(struct Extban *);
extern void extban_del(struct Extban *);
extern struct Extban *extban_find(unsigned char);
extern struct Extban *extban_find_flag(unsigned int);
extern enum extban_type extban_parse(const char *, unsigned int *, unsigned int *);
extern size_t extban_format(unsigned int, char *);
extern unsigned int extban_matching_mask(void);
extern unsigned int extban_acting_mask(void);
extern const char *extban_get_isupport(void);

extern struct Extban extban_account;
extern struct Extban extban_channel;
extern struct Extban extban_fingerprint;
extern struct Extban extban_gecos;
extern struct Extban extban_invite;
extern struct Extban extban_join;
extern struct Extban extban_kick;
extern struct Extban extban_knock;
extern struct Extban extban_mute;
extern struct Extban extban_nick;
extern struct Extban extban_operclass;
extern struct Extban extban_server;
extern struct Extban extban_tlsinfo;
extern struct Extban extban_usermode;
#endif  /* INCLUDED_extban_h */
