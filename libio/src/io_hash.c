/*
 * SPDX-FileCopyrightText: 2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "io_hash.h"

_Static_assert(UINTPTR_MAX == UINT32_MAX || UINTPTR_MAX == UINT64_MAX,
               "io_hash_pointer requires a 32-bit or 64-bit uintptr_t");

uint32_t
io_hash_mix32(uint32_t value)
{
  value ^= value >> 16;
  value *= UINT32_C(0x85ebca6b);
  value ^= value >> 13;
  value *= UINT32_C(0xc2b2ae35);
  value ^= value >> 16;

  return value;
}

uint64_t
io_hash_mix64(uint64_t value)
{
  value ^= value >> 33;
  value *= UINT64_C(0xff51afd7ed558ccd);
  value ^= value >> 33;
  value *= UINT64_C(0xc4ceb9fe1a85ec53);
  value ^= value >> 33;

  return value;
}

uintptr_t
io_hash_pointer(const void *pointer)
{
#if UINTPTR_MAX == UINT64_MAX
  return io_hash_mix64((uintptr_t)pointer);
#else
  return io_hash_mix32((uintptr_t)pointer);
#endif
}

