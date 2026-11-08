/*
 * SPDX-FileCopyrightText: 2015-2016 plexus development team
 * SPDX-FileCopyrightText: 2019-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file extban.h
 * \brief Implements extended channel bans.
 */

#ifndef INCLUDED_extban_h
#define INCLUDED_extban_h
#include <stddef.h>
#include <stdint.h>

struct Ban;
struct Channel;
struct Client;

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

typedef enum
{
  EXTBAN_SUCCESS = 0,
  EXTBAN_ALREADY_REGISTERED,
  EXTBAN_NOT_FOUND,
  EXTBAN_INVALID_ARGUMENT,
  EXTBAN_TYPE_CONFLICT
} extban_result_t;

struct Extban
{
  unsigned char character;
  enum extban_type type;
  int (*is_valid)(const char *);
  enum extban_match (*matches)(struct Client *, struct Channel *, struct Ban *);
  uint32_t types;  /* CHFL_BAN/EXCEPTION/INVEX */
  uint64_t *flag_out;
};

extern uint64_t EXTBAN_JOIN;
extern uint64_t EXTBAN_KNOCK;
extern uint64_t EXTBAN_MUTE;
extern uint64_t EXTBAN_NICK;

extern extban_result_t extban_register(const struct Extban *);
extern extban_result_t extban_unregister(const struct Extban *);
extern enum extban_type extban_parse(const char *, uint64_t *, size_t *);
extern size_t extban_format(uint64_t, char *);
extern uint64_t extban_matching_mask(void);
extern uint64_t extban_acting_mask(void);
extern const struct Extban *extban_find(unsigned char);
extern const struct Extban *extban_find_flag(uint64_t);
extern const char *extban_result_to_string(extban_result_t);
#endif  /* INCLUDED_extban_h */
