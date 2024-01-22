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

/*! \file
 * \brief Configuration managment for class{} blocks
 */


#ifndef INCLUDED_conf_class_h
#define INCLUDED_conf_class_h

enum
{
  CLASS_FLAGS_FAKE_IDLE            = 1 << 0,
  CLASS_FLAGS_RANDOM_IDLE          = 1 << 1,
  CLASS_FLAGS_HIDE_IDLE_FROM_OPERS = 1 << 2
};

struct ClassItem
{
  char *name;
  dlink_node node;
  bool active;
  void *ip_tree_v6;  /**< Pointer to 'patricia_tree_t' item */
  void *ip_tree_v4;  /**< Pointer to 'patricia_tree_t' item */
  unsigned int ref_count;
  unsigned int max_sendq;
  unsigned int max_recvq;
  unsigned int con_freq;
  unsigned int ping_freq;
  unsigned int max_total;
  unsigned int max_perip_local;
  unsigned int max_perip_global;
  unsigned int min_idle;
  unsigned int max_idle;
  unsigned int max_channels;
  unsigned int cidr_bitlen_ipv4;
  unsigned int cidr_bitlen_ipv6;
  unsigned int number_per_cidr;
  unsigned int flags;
};

/* address of default class conf */
extern struct ClassItem *class_default;

extern struct ClassItem *class_make(void);
extern const struct ClassItem *class_get_ptr(const dlink_list *const);
extern const dlink_list *class_get_list(void);
extern void class_free(struct ClassItem *const);
extern void class_init(void);
extern const char *class_get_name(const dlink_list *const);
extern unsigned int class_get_ping_freq(const dlink_list *const);
extern unsigned int class_get_sendq(const dlink_list *const);
extern unsigned int class_get_recvq(const dlink_list *const);
extern struct ClassItem *class_find(const char *, bool);
extern void class_mark_for_deletion(void);
extern void class_delete_marked(void);
extern bool class_ip_limit_add(struct ClassItem *, void *, bool);
extern bool class_ip_limit_remove(struct ClassItem *, void *);
extern void class_ip_limit_rebuild(struct ClassItem *);
#endif  /* INCLUDED_conf_class_h */
