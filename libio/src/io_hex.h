/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file io_hex.h
 * @brief Declarations for hexadecimal encoding helpers.
 */

#ifndef INCLUDED_io_hex_h
#define INCLUDED_io_hex_h
#include <stdbool.h>
#include <stddef.h>

extern bool io_bytes_to_hex(const unsigned char *, size_t, char *, size_t);
#endif  /* INCLUDED_io_hex_h */
