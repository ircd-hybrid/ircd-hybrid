/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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
 * @file io_hex.c
 * @brief Implements hexadecimal encoding helpers.
 */

#include <stdint.h>

#include "io_hex.h"

/**
 * @brief Converts bytes to an uppercase hexadecimal string.
 *
 * Converts @p bytes_len bytes from @p bytes into a NUL-terminated uppercase
 * hexadecimal string stored in @p hex. The output buffer must be at least
 * (bytes_len * 2) + 1 bytes long. The input and output buffers must not
 * overlap.
 *
 * If the function returns false and @p hex is non-NULL with nonzero size,
 * @p hex is left as an empty string.
 *
 * @param bytes Input byte buffer. May be NULL only when @p bytes_len is 0.
 * @param bytes_len Number of input bytes.
 * @param hex Output buffer for the hexadecimal string.
 * @param hex_size Size of the output buffer.
 * @return true on success, false on invalid arguments or insufficient output space.
 */
bool
io_bytes_to_hex(const unsigned char *bytes, size_t bytes_len, char *hex, size_t hex_size)
{
  static const char hex_digits[] = "0123456789ABCDEF";

  if (hex == NULL || hex_size == 0)
    return false;

  hex[0] = '\0';

  if (bytes == NULL && bytes_len > 0)
    return false;

  if (bytes_len > (SIZE_MAX - 1) / 2)
    return false;

  const size_t required_hex_size = (bytes_len * 2) + 1;
  if (hex_size < required_hex_size)
    return false;

  char *out = hex;
  for (size_t i = 0; i < bytes_len; ++i)
  {
    const unsigned char byte = bytes[i];
    *out++ = hex_digits[byte >> 4];
    *out++ = hex_digits[byte & 0x0F];
  }

  *out = '\0';
  return true;
}
