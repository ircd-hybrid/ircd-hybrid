/*
 * SPDX-FileCopyrightText: 2001-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file io_getopt.h
 * @brief Header for the lightweight command-line option parser avoiding getopt_long().
 *
 * This header provides structures and functions for parsing command-line options in a simple way,
 * avoiding the use of getopt_long() as it is a GNU extension.
 */

#ifndef INCLUDED_io_getopt_h
#define INCLUDED_io_getopt_h

/**
 * @struct io_getopt
 * @brief Structure representing a command-line option.
 *
 * This structure contains information about a command-line option, including its
 * long name, short name, the location to store the argument (if any), the type of the argument,
 * and a description for usage and help printing.
 */
struct io_getopt
{
  const char *opt;  /**< Long option name. */
  char short_opt;  /**< Short option name (single letter). */
  void *argloc;  /**< Location to store the argument. */
  enum { INTEGER, BOOLEAN, STRING, USAGE } argtype;  /**< Type of the argument. */
  const char *desc;  /**< Description of the argument, usage for printing help. */
};

extern void io_getopt(int *, char ***, struct io_getopt *);
#endif  /* INCLUDED_io_getopt_h */
