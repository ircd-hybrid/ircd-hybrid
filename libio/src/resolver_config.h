/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file resolver_config.h
 * @brief DNS resolver configuration interfaces.
 */

#ifndef INCLUDED_resolver_config_h
#define INCLUDED_resolver_config_h
#include <stdbool.h>
#include <stddef.h>

#include "address.h"


enum
{
  RESOLVER_CONFIG_NAMESERVER_CAPACITY = 8
};

struct resolver_config
{
  struct io_addr nameservers[RESOLVER_CONFIG_NAMESERVER_CAPACITY];
  size_t nameserver_count;
};

extern bool resolver_config_equal(const struct resolver_config *, const struct resolver_config *);
extern bool resolver_config_load(struct resolver_config *);
extern bool resolver_config_has_family(const struct resolver_config *, int);
extern bool resolver_config_contains_nameserver(const struct resolver_config *, const struct io_addr *);
#endif  /* INCLUDED_resolver_config_h */
