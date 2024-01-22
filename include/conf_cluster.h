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

/*! \file conf_cluster.h
 * \brief Implements cluster {} block configuration management.
 */

#ifndef INCLUDED_conf_cluster_h
#define INCLUDED_conf_cluster_h

enum
{
  CLUSTER_KLINE   = 1 << 0,
  CLUSTER_UNKLINE = 1 << 1,
  CLUSTER_XLINE   = 1 << 2,
  CLUSTER_UNXLINE = 1 << 3,
  CLUSTER_RESV    = 1 << 4,
  CLUSTER_UNRESV  = 1 << 5,
  CLUSTER_LOCOPS  = 1 << 6,
  CLUSTER_DLINE   = 1 << 7,
  CLUSTER_UNDLINE = 1 << 8,
  CLUSTER_REHASH  = 1 << 9,
  CLUSTER_ALL     = UINT_MAX
};

struct ClusterItem
{
  dlink_node node;
  char *server;
  unsigned int type;
};

extern const dlink_list *cluster_get_list(void);
extern void cluster_clear(void);
extern struct ClusterItem *cluster_make(void);
extern void cluster_distribute(const void *, const char *, unsigned int, unsigned int, const char *, ...);
#endif  /* INCLUDED_conf_cluster_h */
