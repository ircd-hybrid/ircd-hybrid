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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct Ban;
struct Channel;
struct Client;

enum
{
  EXTBAN_PREFIX_LENGTH_MAX = 5,
  EXTBAN_PREFIX_BUFFER_SIZE = EXTBAN_PREFIX_LENGTH_MAX + 1
};

typedef enum
{
  EXTBAN_KIND_MATCHING = 1,
  EXTBAN_KIND_ACTING
} extban_kind_t;

typedef enum
{
  EXTBAN_PARSE_NOT_EXTBAN,
  EXTBAN_PARSE_SUCCESS,
  EXTBAN_PARSE_UNSUPPORTED,
  EXTBAN_PARSE_INVALID_SYNTAX
} extban_parse_status_t;

typedef struct
{
  extban_parse_status_t status;
  uint64_t flags;
  size_t parameter_offset;
} extban_parse_result_t;

typedef enum
{
  EXTBAN_SUCCESS = 0,
  EXTBAN_ALREADY_REGISTERED,
  EXTBAN_NOT_FOUND,
  EXTBAN_INVALID_ARGUMENT,
  EXTBAN_KIND_CONFLICT,
  EXTBAN_INVALID_FLAGS,
  EXTBAN_BUFFER_TOO_SMALL
} extban_result_t;

struct Extban
{
  unsigned char letter;
  extban_kind_t kind;
  bool parameter_case_sensitive;
  bool (*validate_parameter)(const char *);
  bool (*matches)(const struct Client *, const struct Channel *, const struct Ban *);
  uint32_t list_types;  /* CHFL_BAN/EXCEPTION/INVEX */
  uint64_t *flag_binding;
};

extern uint64_t EXTBAN_JOIN;
extern uint64_t EXTBAN_KNOCK;
extern uint64_t EXTBAN_MUTE;
extern uint64_t EXTBAN_NICK;

extern bool extban_parameters_equal(uint64_t, const char *, const char *);
extern bool extban_validate_local(uint64_t, uint32_t, const char *);
extern uint64_t extban_known_acting_mask(void);
extern uint64_t extban_known_matching_mask(void);
extern extban_parse_result_t extban_parse(const char *);
extern extban_result_t extban_format_prefix(uint64_t, char *, size_t, size_t *);
extern extban_result_t extban_register(const struct Extban *);
extern extban_result_t extban_unregister(const struct Extban *);
extern const char *extban_result_to_string(extban_result_t);
extern const struct Extban *extban_find_by_flag(uint64_t);
extern const struct Extban *extban_find_by_letter(unsigned char);
#endif  /* INCLUDED_extban_h */
