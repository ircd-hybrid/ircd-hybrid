/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2026 ircd-hybrid development team
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

/*! \file hostmask.h
 * \brief A header for the hostmask code.
 */

#ifndef INCLUDED_address_h
#define INCLUDED_address_h

#include <assert.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdint.h>

enum hostmask_type
{
  HM_HOST,
  HM_IPV4,
  HM_IPV6
};

enum { ADDRESS_HASHSIZE = 0x1000 }; /* XXX */

/**
 * @struct io_addr
 * @brief Structure to handle sockaddr_storage with compatibility for different implementations.
 *
 * This structure provides a consistent interface for sockaddr_storage with compatibility
 * for different implementations that may or may not include the ss_len member.
 */
struct io_addr
{
  struct sockaddr_storage ss;  /**< Underlying sockaddr_storage structure. */
};

extern void address_strip_ipv4(struct io_addr *);
extern void address_mask(struct io_addr *, int);
extern bool address_from_bytes(struct io_addr *, int, const void *, size_t);
extern bool address_from_string(const char *, struct io_addr *);
extern bool address_to_string(const struct io_addr *, char *, size_t);
extern bool address_match(const struct io_addr *, const struct io_addr *, bool, bool, int);
extern bool address_match_ipv6(const struct io_addr *, const struct io_addr *, int);
extern bool address_match_ipv4(const struct io_addr *, const struct io_addr *, int);
extern int address_parse_netmask(const char *, struct io_addr *, int *);
extern uint32_t hash_ipv4(const struct io_addr *, int);
extern uint32_t hash_ipv6(const struct io_addr *, int);
extern uint32_t hash_text(const char *);
extern uint32_t get_mask_hash(const char *);

static inline bool
address_is_ipv4(const struct io_addr *addr)
{
  return addr->ss.ss_family == AF_INET;
}

static inline bool
address_is_ipv6(const struct io_addr *addr)
{
  return addr->ss.ss_family == AF_INET6;
}

static inline bool
address_is_ipv4_mapped(const struct io_addr *addr)
{
  if (address_is_ipv6(addr) == false)
    return false;

  const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)&addr->ss;
  return IN6_IS_ADDR_V4MAPPED(&v6->sin6_addr);
}

static inline bool
address_is_unspecified(const struct io_addr *addr)
{
  if (address_is_ipv4(addr))
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *)&addr->ss;
    return v4->sin_addr.s_addr == INADDR_ANY;
  }
  else if (address_is_ipv6(addr))
  {
    const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)&addr->ss;
    return IN6_IS_ADDR_UNSPECIFIED(&v6->sin6_addr);
  }

  return false;
}

static inline bool
address_is_specific(const struct io_addr *addr)
{
  return (address_is_ipv4(addr) || address_is_ipv6(addr)) && address_is_unspecified(addr) == false;
}

static inline int
address_get_family(const struct io_addr *addr)
{
  return addr->ss.ss_family;
}

static inline uint16_t
address_get_port(const struct io_addr *addr)
{
  if (address_is_ipv4(addr))
  {
    const struct sockaddr_in *v4 = (const struct sockaddr_in *)&addr->ss;
    return ntohs(v4->sin_port);
  }
  else if (address_is_ipv6(addr))
  {
    const struct sockaddr_in6 *v6 = (const struct sockaddr_in6 *)&addr->ss;
    return ntohs(v6->sin6_port);
  }

  return 0;
}

static inline bool
address_set_port(struct io_addr *addr, uint16_t port)
{
  if (address_is_ipv4(addr))
  {
    struct sockaddr_in *v4 = (struct sockaddr_in *)&addr->ss;
    v4->sin_port = htons(port);
    return true;
  }
  else if (address_is_ipv6(addr))
  {
    struct sockaddr_in6 *v6 = (struct sockaddr_in6 *)&addr->ss;
    v6->sin6_port = htons(port);
    return true;
  }

  return false;
}

static inline socklen_t
address_length(const struct io_addr *addr)
{
  if (address_is_ipv4(addr))
    return sizeof(struct sockaddr_in);
  if (address_is_ipv6(addr))
    return sizeof(struct sockaddr_in6);

  return 0;
}

static inline void
address_clear(struct io_addr *addr)
{
  if (addr)
    memset(addr, 0, sizeof(*addr));
}

static inline void
address_copy(struct io_addr *dst, const struct io_addr *src)
{
  assert(dst);
  assert(src);

  *dst = *src;
}
#endif  /* INCLUDED_address_h */
