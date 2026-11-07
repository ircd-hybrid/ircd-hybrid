/*
 * SPDX-FileCopyrightText: 2026-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <string.h>

#include "io_parse.h"

static bool
_io_parse_is_decimal_digit(unsigned char ch)
{
  return ch >= '0' && ch <= '9';
}

io_parse_status_t
io_parse_uintmax(const char *text, uintmax_t *value_out)
{
  return io_parse_uintmax_range(text, 0, UINTMAX_MAX, value_out);
}

io_parse_status_t
io_parse_uintmax_range(const char *text, uintmax_t min, uintmax_t max, uintmax_t *value_out)
{
  assert(value_out);
  assert(min <= max);

  if (value_out == NULL)
    return IO_PARSE_INVALID;
  if (text == NULL)
    return IO_PARSE_INVALID;
  if (min > max)
    return IO_PARSE_RANGE;
  if (*text == '\0')
    return IO_PARSE_EMPTY;

  const uintmax_t max_div_10 = max / 10U;
  const uintmax_t max_mod_10 = max % 10U;

  uintmax_t value = 0;
  bool out_of_range = false;

  for (const char *p = text; *p; ++p)
  {
    const unsigned char ch = (unsigned char)*p;
    if (!_io_parse_is_decimal_digit(ch))
      return IO_PARSE_INVALID;

    if (out_of_range)
      continue;

    const uintmax_t digit = (uintmax_t)(ch - '0');
    if (value > max_div_10 || (value == max_div_10 && digit > max_mod_10))
    {
      out_of_range = true;
      continue;
    }

    value = value * 10U + digit;
  }

  if (out_of_range || value < min)
    return IO_PARSE_RANGE;

  *value_out = value;
  return IO_PARSE_OK;
}

io_parse_status_t
io_parse_uint(const char *text, unsigned int *value_out)
{
  return io_parse_uint_range(text, 0, UINT_MAX, value_out);
}

io_parse_status_t
io_parse_uint_range(const char *text, unsigned int min, unsigned int max, unsigned int *value_out)
{
  assert(value_out);
  assert(min <= max);

  if (value_out == NULL)
    return IO_PARSE_INVALID;
  if (min > max)
    return IO_PARSE_RANGE;

  uintmax_t value;
  const io_parse_status_t status = io_parse_uintmax_range(text, min, max, &value);
  if (status != IO_PARSE_OK)
    return status;

  *value_out = (unsigned int)value;
  return IO_PARSE_OK;
}

io_parse_status_t
io_parse_uint32(const char *text, uint32_t *value_out)
{
  return io_parse_uint32_range(text, 0, UINT32_MAX, value_out);
}

io_parse_status_t
io_parse_uint32_range(const char *text, uint32_t min, uint32_t max, uint32_t *value_out)
{
  assert(value_out);
  assert(min <= max);

  if (value_out == NULL)
    return IO_PARSE_INVALID;
  if (min > max)
    return IO_PARSE_RANGE;

  uintmax_t value;
  const io_parse_status_t status = io_parse_uintmax_range(text, min, max, &value);
  if (status != IO_PARSE_OK)
    return status;

  *value_out = (uint32_t)value;
  return IO_PARSE_OK;
}

io_parse_status_t
io_parse_bool(const char *text, bool *value_out)
{
  assert(value_out);

  if (value_out == NULL)
    return IO_PARSE_INVALID;
  if (text == NULL)
    return IO_PARSE_INVALID;
  if (*text == '\0')
    return IO_PARSE_EMPTY;

  if (strcmp(text, "true") == 0)
  {
    *value_out = true;
    return IO_PARSE_OK;
  }

  if (strcmp(text, "false") == 0)
  {
    *value_out = false;
    return IO_PARSE_OK;
  }

  return IO_PARSE_INVALID;
}
