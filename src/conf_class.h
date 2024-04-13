/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/**
 * @file conf_class.h
 * @brief Configuration management for class {} blocks.
 *
 * This file defines structures and functions related to the configuration
 * management of class {} blocks in the IRC daemon.
 */

#ifndef INCLUDED_conf_class_h
#define INCLUDED_conf_class_h

/**
 * @brief Flags for controlling class behavior.
 */
enum
{
  CLASS_FLAGS_FAKE_IDLE            = 1 << 0,  /**< Flag indicating fake idle is enabled. */
  CLASS_FLAGS_RANDOM_IDLE          = 1 << 1,  /**< Flag indicating random idle is enabled. */
  CLASS_FLAGS_HIDE_IDLE_FROM_OPERS = 1 << 2,  /**< Flag indicating idle is hidden from operators. */
};

/**
 * @struct ClassItem
 * @brief Structure representing a class configuration.
 *
 * This structure contains information about a class configuration,
 * including its name, flags, and various settings such as send/receive
 * queue sizes, idle time limits, and IP address limits.
 */
struct ClassItem
{
  char *name;  /**< Name of the class. */
  list_node_t node;  /**< List node for linking into class_list. */
  bool active;  /**< Indicates if the class is active. */
  void *ip_tree_v6;  /**< Pointer to IPv6 patricia_tree_t item. */
  void *ip_tree_v4;  /**< Pointer to IPv4 patricia_tree_t item. */
  unsigned int ref_count;  /**< Reference count for the class. */
  unsigned int max_sendq;  /**< Maximum send queue size for clients in this class. */
  unsigned int max_recvq;  /**< Maximum receive queue size for clients in this class. */
  unsigned int con_freq;  /**< Connection frequency for servers in this class. */
  unsigned int ping_freq;  /**< Ping frequency for clients in this class. */
  unsigned int max_total;  /**< Maximum total number of clients in this class. */
  unsigned int max_perip_local;  /**< Maximum number of local clients per IP in this class. */
  unsigned int max_perip_global;  /**< Maximum number of global clients per IP in this class. */
  unsigned int min_idle;  /**< Minimum idle time shown in WHOIS for clients in this class. */
  unsigned int max_idle;  /**< Maximum idle time shown in WHOIS for clients in this class. */
  unsigned int max_channels;  /**< Maximum number of channels clients in this class can join. */
  unsigned int cidr_bitlen_ipv4;  /**< CIDR bit length for IPv4 subnets. */
  unsigned int cidr_bitlen_ipv6;  /**< CIDR bit length for IPv6 subnets. */
  unsigned int number_per_cidr;  /**< Maximum number of clients allowed per CIDR subnet. */
  unsigned int flags;  /**< Bitwise flags indicating class configuration options. */
};

/**
 * @brief Pointer to the default class configuration.
 */
extern struct ClassItem *class_default;

extern struct ClassItem *class_make(void);
extern const struct ClassItem *class_get_ptr(const list_t *const);
extern const list_t *class_get_list(void);
extern void class_free(struct ClassItem *const);
extern void class_init(void);
extern const char *class_get_name(const list_t *const);
extern unsigned int class_get_ping_freq(const list_t *const);
extern unsigned int class_get_sendq(const list_t *const);
extern unsigned int class_get_recvq(const list_t *const);
extern struct ClassItem *class_find(const char *, bool);
extern void class_mark_for_deletion(void);
extern void class_delete_marked(void);
extern bool class_ip_limit_add(struct ClassItem *, void *, bool);
extern bool class_ip_limit_remove(struct ClassItem *, void *);
extern void class_ip_limit_rebuild(struct ClassItem *);
#endif  /* INCLUDED_conf_class_h */
