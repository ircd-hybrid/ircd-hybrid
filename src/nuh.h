/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

#ifndef INCLUDED_nuh_h
#define INCLUDED_nuh_h
#include <stddef.h>

/**
 * @struct nuh_split
 * @brief Represents the parsed components of an IRC `nick!user@host` mask.
 *
 * The nuh_split structure is used to store the components of an IRC mask
 * after parsing. It contains pointers to the nickname, username, and hostname,
 * as well as the sizes of the respective buffers.
 */
struct nuh_split
{
  char *nuhmask;  /**< The input IRC mask string to be parsed (e.g., "nick!user@host"). */
  char *nickptr;  /**< Pointer to the buffer for storing the parsed nickname. */
  char *userptr;  /**< Pointer to the buffer for storing the parsed username. */
  char *hostptr;  /**< Pointer to the buffer for storing the parsed hostname. */

  size_t nicksize;  /**< Size of the buffer for the nickname. */
  size_t usersize;  /**< Size of the buffer for the username. */
  size_t hostsize;  /**< Size of the buffer for the hostname. */
};

extern void nuh_split(struct nuh_split *const);
#endif  /* INCLUDED_nuh_h */
