/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2024 ircd-hybrid development team
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
 * @file ircd_getopt.h
 * @brief Header for the lightweight command-line option parser avoiding getopt_long().
 *
 * This header provides structures and functions for parsing command-line options in a simple way,
 * avoiding the use of getopt_long() as it is a GNU extension.
 */

#ifndef INCLUDED_ircd_getopt_h
#define INCLUDED_ircd_getopt_h

/**
 * @struct lgetopt
 * @brief Structure representing a command-line option.
 *
 * This structure contains information about a command-line option, including its
 * name, the location to store the argument (if any), the type of the argument,
 * and a description for usage and help printing.
 */
struct lgetopt
{
  const char *opt;  /**< Name of the argument. */
  void *argloc;  /**< Location to store the argument to it (-option argument). */
  enum { INTEGER, BOOLEAN, STRING, USAGE } argtype;  /**< Type of the argument. */
  const char *desc;  /**< Description of the argument, usage for printing help. */
};

extern void parseargs(int *, char ***, struct lgetopt *);
#endif /* INCLUDED_ircd_getopt_h */
