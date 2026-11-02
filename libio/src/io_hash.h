/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef INCLUDED_io_hash_h
#define INCLUDED_io_hash_h
#include <stdint.h>

extern uint32_t io_hash_mix32(uint32_t);
extern uint64_t io_hash_mix64(uint64_t);
extern uintptr_t io_hash_pointer(const void *);
#endif  /* INCLUDED_io_hash_h */
