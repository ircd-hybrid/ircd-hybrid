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

/*! \file hostmask.h
 * \brief A header for the hostmask code.
 */

#ifndef INCLUDED_address_h
#define INCLUDED_address_h

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
  socklen_t ss_len;  /**< Length of the sockaddr_storage. */
};

extern uint32_t hash_ipv4(const struct io_addr *, int);
extern uint32_t hash_ipv6(const struct io_addr *, int);
extern uint32_t hash_text(const char *);
extern uint32_t get_mask_hash(const char *);
extern int parse_netmask(const char *, struct io_addr *, int *);
extern void address_strip_ipv4(struct io_addr *);
extern void address_mask(struct io_addr *, int);
extern bool address_compare(const void *, const void *, bool, bool, int);
extern bool match_ipv6(const struct io_addr *, const struct io_addr *, int);
extern bool match_ipv4(const struct io_addr *, const struct io_addr *, int);
#endif  /* INCLUDED_address_h */
