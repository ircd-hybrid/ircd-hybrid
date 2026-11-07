/*
 * SPDX-FileCopyrightText: 2026-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_parse_h
#define INCLUDED_io_parse_h
#include <stdbool.h>
#include <stdint.h>

typedef enum
{
  IO_PARSE_OK = 0,
  IO_PARSE_EMPTY,
  IO_PARSE_INVALID,
  IO_PARSE_RANGE,
} io_parse_status_t;

extern io_parse_status_t io_parse_bool(const char *, bool *);
extern io_parse_status_t io_parse_uint(const char *, unsigned int *);
extern io_parse_status_t io_parse_uint32(const char *, uint32_t *);
extern io_parse_status_t io_parse_uint32_range(const char *, uint32_t, uint32_t, uint32_t *);
extern io_parse_status_t io_parse_uint_range(const char *, unsigned int, unsigned int, unsigned int *);
extern io_parse_status_t io_parse_uintmax(const char *, uintmax_t *);
extern io_parse_status_t io_parse_uintmax_range(const char *, uintmax_t, uintmax_t, uintmax_t *);
#endif  /* INCLUDED_io_parse_h */
