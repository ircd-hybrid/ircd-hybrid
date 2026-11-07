/*
 * SPDX-FileCopyrightText: 2012-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
extern const struct ServiceItem *service_find(const char *);
#endif  /* INCLUDED_conf_service_h */
