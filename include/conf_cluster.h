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
 * @file conf_cluster.h
 * @brief Implements cluster {} block management for sharing IRC commands between servers.
 */

#ifndef INCLUDED_conf_cluster_h
#define INCLUDED_conf_cluster_h

/**
 * @brief Configuration options for clustering.
 * @details Defines constants representing different configuration options
 * for clustering. Each option corresponds to a specific type of IRC command
 * that can be shared among clustered servers.
 */
enum
{
  CLUSTER_KLINE   = 1 << 0, /*!< Share KLINE commands */
  CLUSTER_UNKLINE = 1 << 1, /*!< Share UNKLINE commands */
  CLUSTER_XLINE   = 1 << 2, /*!< Share XLINE commands */
  CLUSTER_UNXLINE = 1 << 3, /*!< Share UNXLINE commands */
  CLUSTER_RESV    = 1 << 4, /*!< Share RESV commands */
  CLUSTER_UNRESV  = 1 << 5, /*!< Share UNRESV commands */
  CLUSTER_LOCOPS  = 1 << 6, /*!< Share LOCOPS commands */
  CLUSTER_DLINE   = 1 << 7, /*!< Share DLINE commands */
  CLUSTER_UNDLINE = 1 << 8, /*!< Share UNDLINE commands */
  CLUSTER_REHASH  = 1 << 9, /*!< Share REHASH commands */
  CLUSTER_ALL     = UINT_MAX /*!< Share all supported commands (default) */
};

extern const dlink_list *cluster_get_list(void);
extern void cluster_clear(void);
extern struct ClusterItem *cluster_make(void);
extern void cluster_distribute(const void *, const char *, unsigned int, unsigned int, const char *, ...);
#endif  /* INCLUDED_conf_cluster_h */
