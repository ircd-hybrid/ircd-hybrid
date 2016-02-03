/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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
 * \version $Id$
 */

#ifndef INCLUDED_conf_cluster_h
#define INCLUDED_conf_cluster_h
#include "stdinc.h"
#include "client.h"

enum
{
  CLUSTER_KLINE   = 0x00000001U,
  CLUSTER_UNKLINE = 0x00000002U,
  CLUSTER_XLINE   = 0x00000004U,
  CLUSTER_UNXLINE = 0x00000008U,
  CLUSTER_RESV    = 0x00000010U,
  CLUSTER_UNRESV  = 0x00000020U,
  CLUSTER_LOCOPS  = 0x00000040U,
  CLUSTER_DLINE   = 0x00000080U,
  CLUSTER_UNDLINE = 0x00000100U,
  CLUSTER_REHASH  = 0x00000200U,
  CLUSTER_ALL     = 0xFFFFFFFFU
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
extern void cluster_distribute(void *, const char *, unsigned int, unsigned int, const char *, ...);
#endif
