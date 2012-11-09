/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file
 * \brief Configuration managment for class{} blocks
 * \version $Id$
 */


#ifndef INCLUDED_conf_class_h
#define INCLUDED_conf_class_h

struct ClassItem
{
  char *name;
  dlink_node node;
  dlink_list list_ipv4;         /* base of per cidr ipv4 client link list */
  dlink_list list_ipv6;         /* base of per cidr ipv6 client link list */
  unsigned int ref_count;
  unsigned int max_sendq;
  unsigned int max_recvq;
  unsigned int con_freq;
  unsigned int ping_freq;
  unsigned int max_total;
  unsigned int max_local;
  unsigned int max_global;
  unsigned int max_ident;
  unsigned int max_perip;
  unsigned int cidr_bitlen_ipv4;
  unsigned int cidr_bitlen_ipv6;
  unsigned int number_per_cidr;
  unsigned int active;
};

/* address of default class conf */
extern struct ClassItem *class_default;

extern struct ClassItem *class_make(void);
extern const dlink_list *class_get_list(void);
extern void class_free(struct ClassItem *);
extern void class_init(void);
extern const char *get_client_class(const dlink_list *const);
extern unsigned int get_client_ping(const dlink_list *const);
extern unsigned int get_sendq(const dlink_list *const);
extern unsigned int get_recvq(const dlink_list *const);
extern struct ClassItem *class_find(const char *, int);
extern void class_mark_for_deletion(void);
extern void class_delete_marked(void);
extern void destroy_cidr_class(struct ClassItem *);
extern int cidr_limit_reached(int, struct irc_ssaddr *, struct ClassItem *);
extern void remove_from_cidr_check(struct irc_ssaddr *, struct ClassItem *);
extern void rebuild_cidr_list(struct ClassItem *);
#endif
