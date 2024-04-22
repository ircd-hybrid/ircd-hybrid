/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2024 ircd-hybrid development team
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

/*! \file hostmask.c
 * \brief Code to efficiently find IP & hostmask based configs.
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "address.h"
#include "irc_string.h"
#include "ircd.h"


#define DigitParse(ch) do { \
                       if (ch >= '0' && ch <= '9') \
                         ch = ch - '0'; \
                       else if (ch >= 'A' && ch <= 'F') \
                         ch = ch - 'A' + 10; \
                       else if (ch >= 'a' && ch <= 'f') \
                         ch = ch - 'a' + 10; \
                       } while (false);

/* int try_parse_v6_netmask(const char *, struct io_addr *, int *);
 * Input: A possible IPV6 address as a string.
 * Output: An integer describing whether it is an IPV6 or hostmask,
 *         an address(if it is IPV6), a bitlength(if it is IPV6).
 * Side effects: None
 * Comments: Called from parse_netmask
 */
static int
try_parse_v6_netmask(const char *text, struct io_addr *addr, int *b)
{
  char c;
  int d[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  int dp = 0;
  int nyble = 4;
  int finsert = -1;
  int bits = 128;
  int deficit = 0;
  uint16_t dc[8];
  struct sockaddr_in6 *const v6 = (struct sockaddr_in6 *)addr;

  for (const char *p = text; (c = *p); ++p)
  {
    if (IsXDigit(c))
    {
      if (nyble == 0)
        return HM_HOST;
      DigitParse(c);
      d[dp] |= c << (4 * --nyble);
    }
    else if (c == ':')
    {
      if (p > text && *(p - 1) == ':')
      {
        if (finsert >= 0)
          return HM_HOST;
        finsert = dp;
      }
      else
      {
        /*
         * If there were less than 4 hex digits, e.g. :ABC: shift right
         * so we don't interpret it as ABC0 -A1kmm
         */
        d[dp] = d[dp] >> 4 * nyble;
        nyble = 4;

        if (++dp >= 8)
          return HM_HOST;
      }
    }
    else if (c == '*')
    {
      /* * must be last, and * is ambiguous if there is a ::... -A1kmm */
      if (finsert >= 0 || *(p + 1) || dp == 0 || *(p - 1) != ':')
        return HM_HOST;
      bits = dp * 16;
    }
    else if (c == '/')
    {
      char *after;

      bits = strtoul(p + 1, &after, 10);

      if (bits < 0 || bits > 128 || *after)
        return HM_HOST;
      /* 16 bits for each hextet, plus 4 for each parsed nyble */
      if (bits > dp * 16 + (4 - nyble) * 4 && !(finsert >= 0))
        return HM_HOST;
      break;
    }
    else
      return HM_HOST;
  }

  d[dp] = d[dp] >> 4 * nyble;

  if (c == 0)
    ++dp;
  if (finsert < 0 && bits == 0)
    bits = dp * 16;

  /* How many words are missing? -A1kmm */
  deficit = bits / 16 + ((bits % 16) ? 1 : 0) - dp;

  /* Now fill in the gaps(from ::) in the copied table... -A1kmm */
  for (dp = 0, nyble = 0; dp < 8; ++dp)
  {
    if (nyble == finsert && deficit)
    {
      dc[dp] = 0;
      deficit--;
    }
    else
      dc[dp] = d[nyble++];
  }

  /* Set unused bits to 0... -A1kmm */
  if (bits < 128 && (bits % 16 != 0))
    dc[bits / 16] &= ~((1 << (15 - bits % 16)) - 1);
  for (dp = bits / 16 + (bits % 16 ? 1 : 0); dp < 8; ++dp)
    dc[dp] = 0;

  /* And assign... -A1kmm */
  if (addr)
  {
    v6->sin6_family = AF_INET6;

    for (dp = 0; dp < 8; ++dp)
      /* The cast is a kludge to make netbsd work. */
      ((uint16_t *)&v6->sin6_addr)[dp] = htons(dc[dp]);
  }

  if (b)
    *b = bits;
  return HM_IPV6;
}

/* int try_parse_v4_netmask(const char *, struct io_addr *, int *);
 * Input: A possible IPV4 address as a string.
 * Output: An integer describing whether it is an IPV4 or hostmask,
 *         an address(if it is IPV4), a bitlength(if it is IPV4).
 * Side effects: None
 * Comments: Called from parse_netmask
 */
static int
try_parse_v4_netmask(const char *text, struct io_addr *addr, int *b)
{
  const char *digits[4];
  uint8_t addb[4];
  int n = 0, bits = 0;
  char c;
  struct sockaddr_in *const v4 = (struct sockaddr_in *)addr;

  digits[n++] = text;

  for (const char *p = text; (c = *p); ++p)
  {
    if (c >= '0' && c <= '9')   /* empty */
      ;
    else if (c == '.')
    {
      if (n >= 4)
        return HM_HOST;

      digits[n++] = p + 1;
    }
    else if (c == '*')
    {
      if (*(p + 1) || n == 1 || *(p - 1) != '.')
        return HM_HOST;

      bits = (n - 1) * 8;
      break;
    }
    else if (c == '/')
    {
      char *after;
      bits = strtoul(p + 1, &after, 10);

      if (bits < 0 || *after)
        return HM_HOST;
      if (bits > n * 8)
        return HM_HOST;

      break;
    }
    else
      return HM_HOST;
  }

  if (n < 4 && bits == 0)
    bits = n * 8;
  if (bits)
    while (n < 4)
      digits[n++] = "0";

  for (n = 0; n < 4; ++n)
    addb[n] = strtoul(digits[n], NULL, 10);

  if (bits == 0)
    bits = 32;

  /* Set unused bits to 0... -A1kmm */
  if (bits < 32 && bits % 8)
    addb[bits / 8] &= ~((1 << (8 - bits % 8)) - 1);
  for (n = bits / 8 + (bits % 8 ? 1 : 0); n < 4; ++n)
    addb[n] = 0;
  if (addr)
  {
    v4->sin_family = AF_INET;
    v4->sin_addr.s_addr =
      htonl((unsigned int)addb[0] << 24 |
            (unsigned int)addb[1] << 16 |
            (unsigned int)addb[2] <<  8 |
            (unsigned int)addb[3]);
  }

  if (b)
    *b = bits;
  return HM_IPV4;
}

/* int parse_netmask(const char *, struct io_addr *, int *);
 * Input: A hostmask, or an IPV4/6 address.
 * Output: An integer describing whether it is an IPV4, IPV6 address or a
 *         hostmask, an address(if it is an IP mask),
 *         a bitlength(if it is IP mask).
 * Side effects: None
 */
int
parse_netmask(const char *text, struct io_addr *addr, int *b)
{
  if (addr)
    memset(addr, 0, sizeof(*addr));

  if (strchr(text, '.'))
    return try_parse_v4_netmask(text, addr, b);
  if (strchr(text, ':'))
    return try_parse_v6_netmask(text, addr, b);

  return HM_HOST;
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
void
address_mask(struct io_addr *addr, int bits)
{
  if (addr->ss.ss_family != AF_INET6)
  {
    /* Calculate the IPv4 mask based on the prefix length. */
    const int mask = ~((1 << (32 - bits)) - 1);
    struct sockaddr_in *const v4_base_ip = (struct sockaddr_in *)addr;

    /* Apply the mask to the network portion of the IPv4 address. */
    v4_base_ip->sin_addr.s_addr = htonl(ntohl(v4_base_ip->sin_addr.s_addr) & mask);
  }
  else
  {
    /* Calculate the number of full octets and remaining bits. */
    const unsigned int n = bits / 8;
    const unsigned int m = bits % 8;

    /* Calculate the IPv6 mask based on the remaining bits. */
    const int mask = ~((1 << (8 - m)) - 1);
    struct sockaddr_in6 *const v6_base_ip = (struct sockaddr_in6 *)addr;

    /* Apply the mask to the specified octet in the IPv6 address. */
    v6_base_ip->sin6_addr.s6_addr[n] = v6_base_ip->sin6_addr.s6_addr[n] & mask;

    /* Set the remaining octets to zero. */
    for (unsigned int i = n + 1; i < 16; ++i)
      v6_base_ip->sin6_addr.s6_addr[i] = 0;
  }
}

/**
 * @brief Compare two network addresses for equality or matching.
 *
 * This function compares two network addresses for equality or matching based on
 * specified criteria such as exact match, port match, and subnet match.
 *
 * @param p1    Pointer to the first network address (struct io_addr).
 * @param p2    Pointer to the second network address (struct io_addr).
 * @param exact If true, performs an exact address match (ignores bits parameter).
 * @param port  If true, compares port numbers for equality.
 * @param bits  Number of bits to consider for subnet matching (ignored if exact is true).
 *
 * @return True if addresses match based on the specified criteria, false otherwise.
 */
bool
address_compare(const void *p1, const void *p2, bool exact, bool port, int bits)
{
  const struct io_addr *const addr = p1;
  const struct io_addr *const mask = p2;

  /* Check if address families are the same */
  if (addr->ss.ss_family != mask->ss.ss_family)
    return false;

  if (addr->ss.ss_family == AF_INET)
  {
    const struct sockaddr_in *const sin1 = (const struct sockaddr_in *)addr;
    const struct sockaddr_in *const sin2 = (const struct sockaddr_in *)mask;

    /* Compare port numbers if required */
    if (port && (sin1->sin_port != sin2->sin_port))
      return false;
    if (exact)
      return sin1->sin_addr.s_addr == sin2->sin_addr.s_addr;
    return match_ipv4(addr, mask, bits);
  }
  else if (addr->ss.ss_family == AF_INET6)
  {
    const struct sockaddr_in6 *const sin1 = (const struct sockaddr_in6 *)addr;
    const struct sockaddr_in6 *const sin2 = (const struct sockaddr_in6 *)mask;

    if (port && (sin1->sin6_port != sin2->sin6_port))
      return false;

    if (exact)
      return memcmp(sin1->sin6_addr.s6_addr,
                    sin2->sin6_addr.s6_addr, sizeof(struct in6_addr)) == 0;
    return match_ipv6(addr, mask, bits);
  }

  return false;  /* Invalid address family */
}

/* The address matching stuff... */
/* int match_ipv6(struct io_addr *, struct io_addr *, int)
 * Input: An IP address, an IP mask, the number of bits in the mask.
 * Output: if match, -1 else 0
 * Side effects: None
 */
bool
match_ipv6(const struct io_addr *addr, const struct io_addr *mask, int bits)
{
  int i, m, n = bits / 8;
  const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)addr;
  const struct sockaddr_in6 *const v6mask = (const struct sockaddr_in6 *)mask;

  for (i = 0; i < n; ++i)
    if (v6->sin6_addr.s6_addr[i] != v6mask->sin6_addr.s6_addr[i])
      return false;

  if ((m = bits % 8) == 0)
    return true;
  if ((v6->sin6_addr.s6_addr[n] & ~((1 << (8 - m)) - 1)) ==
      v6mask->sin6_addr.s6_addr[n])
    return true;
  return false;
}

/* int match_ipv4(struct io_addr *, struct io_addr *, int)
 * Input: An IP address, an IP mask, the number of bits in the mask.
 * Output: if match, -1 else 0
 * Side Effects: None
 */
bool
match_ipv4(const struct io_addr *addr, const struct io_addr *mask, int bits)
{
  const struct sockaddr_in *const v4 = (const struct sockaddr_in *)addr;
  const struct sockaddr_in *const v4mask = (const struct sockaddr_in *)mask;

  if ((ntohl(v4->sin_addr.s_addr) & ~((1 << (32 - bits)) - 1)) ==
      ntohl(v4mask->sin_addr.s_addr))
    return true;
  return false;
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
    const struct sockaddr_in *const v4 = (const struct sockaddr_in *)addr;
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
  const struct sockaddr_in6 *const v6 = (const struct sockaddr_in6 *)addr;

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
    h = (h << 4) - (h + ToLower(*p));

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
    if (IsMWildChar(*p))
      return hash_text(hp);
    else if (*p == '.')
      hp = p + 1;
  return hash_text(text);
}
