/*
 * SPDX-FileCopyrightText: 1997-2024 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
