/*
 * SPDX-FileCopyrightText: 1997 Jukka Santala (Donwulff)
 * SPDX-FileCopyrightText: 2005-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file address_parse.c
 * \brief Functions for parsing IPv4 and IPv6 address prefixes.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "address.h"
#include "io_parse.h"
#include "io_string.h"

_Static_assert(CHAR_BIT == 8, "address parsing requires 8-bit bytes");

enum
{
  ADDRESS_IPV6_MAX_PREFIX_LENGTH = sizeof(struct in6_addr) * CHAR_BIT,
  ADDRESS_IPV6_HEXTET_BITS = 16,
  ADDRESS_IPV6_HEXTET_COUNT = ADDRESS_IPV6_MAX_PREFIX_LENGTH / ADDRESS_IPV6_HEXTET_BITS
};

static bool
_address_parse_ipv4_octet(const char *text, size_t text_length, unsigned char *octet_out)
{
  assert(text);
  assert(octet_out);

  if (text_length == 0 || text_length > 3)
    return false;

  unsigned int value = 0;

  for (size_t i = 0; i < text_length; ++i)
  {
    if (!io_ascii_is_digit(text[i]))
      return false;

    value = value * 10U + (unsigned int)(text[i] - '0');
    if (value > UCHAR_MAX)
      return false;
  }

  *octet_out = (unsigned char)value;
  return true;
}

static bool
_address_parse_ipv4_prefix(const char *text, struct io_addr *addr_out, unsigned int *prefix_length_out)
{
  assert(text);
  assert(addr_out);
  assert(prefix_length_out);

  unsigned char address_bytes[sizeof(struct in_addr)] = { 0 };
  size_t octet_count = 0;
  unsigned int prefix_length;
  const char *cursor = text;

  while (true)
  {
    if (octet_count >= sizeof(address_bytes))
      return false;

    const char *octet_end = cursor;
    while (io_ascii_is_digit(*octet_end))
      ++octet_end;

    if (!_address_parse_ipv4_octet(cursor, (size_t)(octet_end - cursor), &address_bytes[octet_count]))
      return false;

    ++octet_count;
    const unsigned int explicit_prefix_length = (unsigned int)(octet_count * CHAR_BIT);

    if (*octet_end == '\0')
    {
      if (octet_count < 2)
        return false;

      prefix_length = explicit_prefix_length;
      break;
    }

    if (*octet_end == '/')
    {
      if (octet_count < 2)
        return false;

      if (io_parse_uint_range(octet_end + 1, 0,
                              explicit_prefix_length, &prefix_length) != IO_PARSE_OK)
        return false;

      break;
    }

    if (*octet_end != '.')
      return false;

    cursor = octet_end + 1;
    if (*cursor == '*')
    {
      if (cursor[1] != '\0' || octet_count >= sizeof(address_bytes))
        return false;

      prefix_length = explicit_prefix_length;
      break;
    }
  }

  struct io_addr addr;
  if (!address_from_bytes(&addr, AF_INET, address_bytes, sizeof(address_bytes)))
    return false;

  *addr_out = addr;
  *prefix_length_out = prefix_length;
  return true;
}

static bool
_address_parse_ipv6_wildcard(const char *text, const char *wildcard, struct io_addr *addr_out,
                             unsigned int *prefix_length_out)
{
  assert(text);
  assert(wildcard);
  assert(*wildcard == '*');
  assert(addr_out);
  assert(prefix_length_out);

  /*
   * Wildcard notation consists of one to seven explicit hextets
   * followed by ":*".
   */
  if (wildcard == text || wildcard[1] != '\0')
    return false;

  if (wildcard[-1] != ':' || text[0] == ':' || strstr(text, "::") || strchr(text, '/'))
    return false;

  size_t hextet_count = 0;

  for (const char *p = text; p < wildcard; ++p)
  {
    if (*p == ':')
      ++hextet_count;
  }

  if (hextet_count >= ADDRESS_IPV6_HEXTET_COUNT)
    return false;

  /*
   * Replace the wildcard with IPv6 zero compression and let the
   * regular address parser validate the explicit hextets.
   */
  char address_buffer[INET6_ADDRSTRLEN];

  const size_t wildcard_offset = (size_t)(wildcard - text);
  if (wildcard_offset > sizeof(address_buffer) - 2)
    return false;

  memcpy(address_buffer, text, wildcard_offset);
  address_buffer[wildcard_offset] = ':';
  address_buffer[wildcard_offset + 1] = '\0';

  struct io_addr addr;
  if (!address_from_string(address_buffer, &addr) || !address_is_ipv6(&addr))
    return false;

  *addr_out = addr;
  *prefix_length_out = (unsigned int)(hextet_count * ADDRESS_IPV6_HEXTET_BITS);
  return true;
}

static bool
_address_parse_ipv6_prefix(const char *text, struct io_addr *addr_out, unsigned int *prefix_length_out)
{
  const char *const wildcard = strchr(text, '*');
  if (wildcard)
    return _address_parse_ipv6_wildcard(text, wildcard, addr_out, prefix_length_out);

  char address_buffer[INET6_ADDRSTRLEN];
  const char *address_text = text;
  const char *const prefix_separator = strchr(text, '/');
  unsigned int prefix_length = ADDRESS_IPV6_MAX_PREFIX_LENGTH;

  if (prefix_separator)
  {
    const size_t address_text_length = (size_t)(prefix_separator - text);
    if (address_text_length == 0 || address_text_length >= sizeof(address_buffer))
      return false;

    memcpy(address_buffer, text, address_text_length);
    address_buffer[address_text_length] = '\0';
    address_text = address_buffer;

    if (io_parse_uint_range(prefix_separator + 1, 0,
                            ADDRESS_IPV6_MAX_PREFIX_LENGTH,
                            &prefix_length) != IO_PARSE_OK)
      return false;
  }

  struct io_addr addr;
  if (!address_from_string(address_text, &addr) || !address_is_ipv6(&addr))
    return false;

  *addr_out = addr;
  *prefix_length_out = prefix_length;
  return true;
}

bool
address_parse_prefix(const char *text, struct io_addr *addr_out, unsigned int *prefix_length_out)
{
  struct io_addr addr;
  unsigned int prefix_length;

  if (strchr(text, ':'))
  {
    if (!_address_parse_ipv6_prefix(text, &addr, &prefix_length))
      return false;
  }
  else if (strchr(text, '.'))
  {
    if (!_address_parse_ipv4_prefix(text, &addr, &prefix_length))
      return false;
  }
  else
    return false;

  if (!address_mask(&addr, prefix_length))
    return false;

  if (addr_out)
    *addr_out = addr;
  if (prefix_length_out)
    *prefix_length_out = prefix_length;

  return true;
}
