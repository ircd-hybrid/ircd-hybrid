/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file hostmask.c
 * \brief Code to efficiently find IP & hostmask based configs.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "address.h"
#include "io_string.h"

_Static_assert(CHAR_BIT == 8, "address handling requires 8-bit bytes");

bool
address_equal(const struct io_addr *lhs, const struct io_addr *rhs)
{
  if (address_get_family(lhs) != address_get_family(rhs))
    return false;

  const unsigned char *lhs_bytes;
  const unsigned char *rhs_bytes;
  size_t lhs_length;
  size_t rhs_length;

  if (!address_get_bytes(lhs, &lhs_bytes, &lhs_length) ||
      !address_get_bytes(rhs, &rhs_bytes, &rhs_length))
    return false;

  if (lhs_length != rhs_length)
    return false;

  return memcmp(lhs_bytes, rhs_bytes, lhs_length) == 0;
}

bool
address_equal_with_port(const struct io_addr *lhs, const struct io_addr *rhs)
{
  return address_equal(lhs, rhs) && address_get_port(lhs) == address_get_port(rhs);
}

bool
address_match_prefix(const struct io_addr *lhs, const struct io_addr *rhs, unsigned int bitlen)
{
  if (address_get_family(lhs) != address_get_family(rhs))
    return false;

  const unsigned char *lhs_bytes;
  const unsigned char *rhs_bytes;
  size_t lhs_length;
  size_t rhs_length;

  if (!address_get_bytes(lhs, &lhs_bytes, &lhs_length) ||
      !address_get_bytes(rhs, &rhs_bytes, &rhs_length))
    return false;

  if (lhs_length != rhs_length || bitlen > lhs_length * CHAR_BIT)
    return false;

  const size_t full_bytes = bitlen / CHAR_BIT;
  if (full_bytes && memcmp(lhs_bytes, rhs_bytes, full_bytes))
    return false;

  const unsigned int remaining_bits = bitlen % CHAR_BIT;
  if (remaining_bits == 0)
    return true;

  const unsigned char mask =
    (unsigned char)(UCHAR_MAX << (CHAR_BIT - remaining_bits));
  return (lhs_bytes[full_bytes] & mask) == (rhs_bytes[full_bytes] & mask);
}

/**
 * @brief Strips IPv4 mapping from an IPv6 address if present.
 *
 * This function removes the IPv4 mapping from an IPv6 address if it is present,
 * effectively converting an IPv6-mapped IPv4 address to a standard IPv4 address.
 *
 * @param addr Pointer to the io_addr structure representing the IP address.
 */
void
address_unmap_ipv4(struct io_addr *addr)
{
  if (addr == NULL || !address_is_ipv4_mapped(addr))
    return;

  const struct sockaddr_in6 *const ipv6 = (const struct sockaddr_in6 *)&addr->ss;

  struct in_addr ipv4_address;
  memcpy(&ipv4_address, &ipv6->sin6_addr.s6_addr[12], sizeof(ipv4_address));

  const uint16_t port = address_get_port(addr);

  struct io_addr ipv4;
  if (!address_from_bytes(&ipv4, AF_INET, &ipv4_address, sizeof(ipv4_address)))
  {
    assert(false);
    return;
  }

  if (!address_set_port(&ipv4, port))
  {
    assert(false);
    return;
  }

  *addr = ipv4;
}

/**
 * @brief Masks the address based on the specified number of bits.
 *
 * This function masks the given IP address based on the specified number of bits,
 * effectively setting to zero the bits beyond the specified prefix length.
 *
 * @param addr Pointer to the io_addr structure representing the IP address.
 * @param bits The number of bits to preserve in the address (prefix length).
 *
 * @note The function handles both IPv4 and IPv6 addresses.
 * For IPv4, the mask is applied to the network portion of the address.
 * For IPv6, the mask is applied to the specified number of octets,
 * and the remaining octets are set to zero.
 */
bool
address_mask(struct io_addr *addr, unsigned int bitlen)
{
  unsigned char *bytes;
  size_t byte_length;

  if (address_is_ipv4(addr))
  {
    struct sockaddr_in *const v4 = (struct sockaddr_in *)&addr->ss;
    bytes = (unsigned char *)&v4->sin_addr;
    byte_length = sizeof(v4->sin_addr);
  }
  else if (address_is_ipv6(addr))
  {
    struct sockaddr_in6 *const v6 = (struct sockaddr_in6 *)&addr->ss;
    bytes = (unsigned char *)&v6->sin6_addr;
    byte_length = sizeof(v6->sin6_addr);
  }
  else
    return false;

  if (bitlen > byte_length * CHAR_BIT)
    return false;

  size_t byte_index = bitlen / CHAR_BIT;
  const unsigned int remaining_bits = bitlen % CHAR_BIT;
  if (remaining_bits)
  {
    const unsigned char mask =
      (unsigned char)(UCHAR_MAX << (CHAR_BIT - remaining_bits));
    bytes[byte_index++] &= mask;
  }

  if (byte_index < byte_length)
    memset(bytes + byte_index, 0, byte_length - byte_index);

  return true;
}

/* unsigned long hash_ipv4(struct io_addr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
uint32_t
hash_ipv4(const struct io_addr *addr, int bits)
{
  if (bits)
  {
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *)&addr->ss;
    uint32_t av = ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1);

    return (av ^ (av >> 12) ^ (av >> 24)) & (ADDRESS_HASHSIZE - 1);
  }

  return 0;
}

/* unsigned long hash_ipv6(struct io_addr*)
 * Input: An IP address.
 * Output: A hash value of the IP address.
 * Side effects: None
 */
uint32_t
hash_ipv6(const struct io_addr *addr, int bits)
{
  uint32_t v = 0, n;
  const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)&addr->ss;

  for (n = 0; n < 16; ++n)
  {
    if (bits >= 8)
    {
      v ^= v6->sin6_addr.s6_addr[n];
      bits -= 8;
    }
    else if (bits)
    {
      v ^= v6->sin6_addr.s6_addr[n] & ~((1 << (8 - bits)) - 1);
      return v & (ADDRESS_HASHSIZE - 1);
    }
    else
      return v & (ADDRESS_HASHSIZE - 1);
  }

  return v & (ADDRESS_HASHSIZE - 1);
}

/* int hash_text(const char *start)
 * Input: The start of the text to hash.
 * Output: The hash of the string between 1 and (TH_MAX-1)
 * Side-effects: None.
 */
uint32_t
hash_text(const char *start)
{
  uint32_t h = 0;

  for (const char *p = start; *p; ++p)
    h = (h << 4) - (h + io_ascii_to_lower(*p));

  return h & (ADDRESS_HASHSIZE - 1);
}

/* unsigned long get_hash_mask(const char *)
 * Input: The text to hash.
 * Output: The hash of the string right of the first '.' past the last
 *         wildcard in the string.
 * Side-effects: None.
 */
uint32_t
get_mask_hash(const char *text)
{
  const char *hp = "", *p;

  for (p = text + strlen(text) - 1; p >= text; --p)
    if (*p == '*' || *p == '?')
      return hash_text(hp);
    else if (*p == '.')
      hp = p + 1;
  return hash_text(text);
}

bool
address_from_string(const char *str, struct io_addr *addr_out)
{
  struct io_addr addr = { 0 };

  struct sockaddr_in *const v4 = (struct sockaddr_in *)&addr.ss;
  if (inet_pton(AF_INET, str, &v4->sin_addr) == 1)
  {
    v4->sin_family = AF_INET;
    *addr_out = addr;
    return true;
  }

  struct sockaddr_in6 *const v6 = (struct sockaddr_in6 *)&addr.ss;
  if (inet_pton(AF_INET6, str, &v6->sin6_addr) == 1)
  {
    v6->sin6_family = AF_INET6;
    *addr_out = addr;
    return true;
  }

  return false;
}

bool
address_to_string(const struct io_addr *addr, char *buf, size_t buflen)
{
  if (address_is_ipv4(addr))
  {
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *)&addr->ss;
    if (inet_ntop(AF_INET, &v4->sin_addr, buf, buflen))
      return true;
  }

  if (address_is_ipv6(addr))
  {
    const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)&addr->ss;
    if (inet_ntop(AF_INET6, &v6->sin6_addr, buf, buflen))
      return true;
  }

  return false;
}

bool
address_from_bytes(struct io_addr *addr_out, int family, const void *bytes, size_t len)
{
  struct io_addr addr = { 0 };

  if (family == AF_INET && len == sizeof(struct in_addr))
  {
    struct sockaddr_in *const v4 = (struct sockaddr_in *)&addr.ss;
    v4->sin_family = AF_INET;
    memcpy(&v4->sin_addr, bytes, sizeof(v4->sin_addr));

    *addr_out = addr;
    return true;
  }

  if (family == AF_INET6 && len == sizeof(struct in6_addr))
  {
    struct sockaddr_in6 *const v6 = (struct sockaddr_in6 *)&addr.ss;
    v6->sin6_family = AF_INET6;
    memcpy(&v6->sin6_addr, bytes, sizeof(v6->sin6_addr));

    *addr_out = addr;
    return true;
  }

  return false;
}

bool
address_to_bytes(const struct io_addr *addr, void *bytes, size_t len)
{
  const unsigned char *address_bytes;
  size_t address_length;

  if (!address_get_bytes(addr, &address_bytes, &address_length) || len != address_length)
    return false;

  memcpy(bytes, address_bytes, address_length);
  return true;
}

bool
address_get_bytes(const struct io_addr *addr, const unsigned char **bytes_out, size_t *len_out)
{
  if (address_is_ipv4(addr))
  {
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *)&addr->ss;
    *bytes_out = (const unsigned char *)&v4->sin_addr;
    *len_out = sizeof(v4->sin_addr);
    return true;
  }

  if (address_is_ipv6(addr))
  {
    const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)&addr->ss;
    *bytes_out = (const unsigned char *)&v6->sin6_addr;
    *len_out = sizeof(v6->sin6_addr);
    return true;
  }

  *bytes_out = NULL;
  *len_out = 0;
  return false;
}

static char *
_address_append_decimal_octet(char *out, unsigned char octet)
{
  static const char digits[] = "0123456789";

  if (octet >= 100)
  {
    *out++ = digits[octet / 100];
    *out++ = digits[(octet / 10) % 10];
  }
  else if (octet >= 10)
    *out++ = digits[octet / 10];

  *out++ = digits[octet % 10];
  return out;
}

_Static_assert(ADDRESS_REVERSE_NAME_BUFSIZE == sizeof(struct in6_addr) * 4 + sizeof("ip6.arpa."),
  "ADDRESS_REVERSE_NAME_BUFSIZE is incorrect");

bool
address_to_reverse_name(const struct io_addr *addr, char *buffer, size_t buffer_size)
{
  const unsigned char *bytes;
  size_t length;

  if (!address_get_bytes(addr, &bytes, &length))
    return false;

  char reverse_name[ADDRESS_REVERSE_NAME_BUFSIZE];
  char *out = reverse_name;

  if (address_is_ipv4(addr))
  {
    if (length != sizeof(struct in_addr))
      return false;

    for (size_t i = length; i-- > 0;)
    {
      out = _address_append_decimal_octet(out, bytes[i]);
      *out++ = '.';
    }

    static const char suffix[] = "in-addr.arpa.";
    memcpy(out, suffix, sizeof(suffix));
    out += sizeof(suffix) - 1;
  }
  else if (address_is_ipv6(addr))
  {
    if (length != sizeof(struct in6_addr))
      return false;

    static const char digits[] = "0123456789abcdef";

    for (size_t i = length; i-- > 0;)
    {
      const unsigned char octet = bytes[i];
      *out++ = digits[octet & 0x0f];
      *out++ = '.';
      *out++ = digits[octet >> 4];
      *out++ = '.';
    }

    static const char suffix[] = "ip6.arpa.";
    memcpy(out, suffix, sizeof(suffix));
    out += sizeof(suffix) - 1;
  }
  else
    return false;

  const size_t required_size = (size_t)(out - reverse_name) + 1;
  assert(required_size <= sizeof(reverse_name));
  assert(*out == '\0');

  if (buffer_size < required_size)
    return false;

  memcpy(buffer, reverse_name, required_size);
  return true;
}
