/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2012-2024 ircd-hybrid development team
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
 * @file conf_service.h
 * @brief Implements service {} block configuration management.
 *
 * This file defines structures and functions related to the configuration
 * management of service {} blocks. It provides a set of functions to
 * create, retrieve, and clear service configurations.
 */

#ifndef INCLUDED_conf_service_h
#define INCLUDED_conf_service_h

/**
 * @struct ServiceItem
 * @brief Represents a service configuration item.
 *
 * This structure is used to store information related to a service configuration.
 */
struct ServiceItem
{
  list_node_t node;  /**< Node for linking in the service list. */
  char *name;  /**< Name of the service. */
};

extern void service_clear(void);
extern struct ServiceItem *service_make(void);
extern const list_t *service_get_list(void);
extern const struct ServiceItem *service_find(const char *, int (*)(const char *, const char *));
#endif  /* INCLUDED_conf_service_h */
