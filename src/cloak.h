/*
 * MIT License
 *
 * Copyright (c) 2019 Shivaram Lingamneni
 * Copyright (c) 2024-2024 ircd-hybrid development team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file cloak.h
 * @brief Declarations for hostname cloaking.
 *
 * Contains function declarations for configuring and utilizing the hostname cloaking module.
 */

#ifndef INCLUDED_cloak_h
#define INCLUDED_cloak_h

#include "ircd_defs.h"

extern void cloak_set_enabled(void);
extern void cloak_set_disabled(void);
extern void cloak_set_cidr_len_ipv4(int);
extern void cloak_set_cidr_len_ipv6(int);
extern void cloak_set_num_bits(int);
extern void cloak_set_secret(const char *);
extern void cloak_set_suffix(const char *);
extern void cloak_initialize(void);
extern const char *cloak_compute(const struct irc_ssaddr *);
#endif  /* INCLUDED_cloak_h */
