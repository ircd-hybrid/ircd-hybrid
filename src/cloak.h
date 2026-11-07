/*
 * SPDX-FileCopyrightText: 2019 Shivaram Lingamneni
 * SPDX-FileCopyrightText: 2024-2026 ircd-hybrid development team
 * SPDX-License-Identifier: MIT
 */

/**
 * @file cloak.h
 * @brief Declarations for hostname cloaking.
 *
 * Contains function declarations for configuring and utilizing the hostname cloaking module.
 */

#ifndef INCLUDED_cloak_h
#define INCLUDED_cloak_h
#include "address.h"

extern void cloak_init(void);
extern void cloak_set_cidr_len_ipv4(int);
extern void cloak_set_cidr_len_ipv6(int);
extern void cloak_set_disabled(void);
extern void cloak_set_enabled(void);
extern void cloak_set_num_bits(int);
extern void cloak_set_secret(const char *);
extern void cloak_set_suffix(const char *);
extern const char *cloak_compute(const struct io_addr *);
#endif  /* INCLUDED_cloak_h */
