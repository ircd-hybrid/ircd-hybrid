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
 * @file io_getopt.c
 * @brief Command-line option parsing utility, avoiding getopt_long().
 *
 * This file provides functionality for parsing command-line options using a custom
 * approach, avoiding the use of getopt_long(), which is a GNU extension. It offers a
 * simple interface for specifying valid options along with their types and descriptions.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>

#include "memory.h"
#include "io_getopt.h"

/**
 * @brief Display usage information for the program.
 *
 * Displays the program's usage information, including valid options and their descriptions,
 * based on the provided io_getopt structure.
 *
 * @param name The name of the program.
 * @param opts An array of io_getopt structures representing valid command-line options.
 */
static noreturn void
io_getopt_usage(const char *name, const struct io_getopt *opts)
{
  fprintf(stderr, "Usage: %s [options]\n", name);
  fprintf(stderr, "Where valid options are:\n");

  for (; opts->opt; ++opts)
    if (opts->short_opt)
      fprintf(stderr, "\t-%c, --%-10s %-20s%s\n", opts->short_opt, opts->opt,
              (opts->argtype == BOOLEAN || opts->argtype == USAGE) ? "" :
              opts->argtype == INTEGER ? "<number>" : "<string>",
              opts->desc);
    else
      fprintf(stderr, "\t--%-10s %-20s%s\n", opts->opt,
              (opts->argtype == BOOLEAN || opts->argtype == USAGE) ? "" :
              opts->argtype == INTEGER ? "<number>" : "<string>",
              opts->desc);

  exit(EXIT_FAILURE);
}

/**
 * @brief Handle a command-line option.
 *
 * This function processes a single command-line option based on its type and updates the
 * corresponding variable as specified by the option.
 *
 * @param argc Pointer to the argument count.
 * @param argv Pointer to the argument vector.
 * @param opts An array of io_getopt structures representing valid command-line options.
 * @param index The index of the current option in the opts array.
 * @param progname The name of the program.
 */
static void
handle_option(int *argc, char ***argv, struct io_getopt *opts, unsigned int index, const char *progname)
{
  switch (opts[index].argtype)
  {
    case BOOLEAN:
      *((bool *)opts[index].argloc) = true;
      break;
    case INTEGER:
      if (*argc < 2)
      {
        fprintf(stderr, "Error: option '%s' requires an argument\n", (*argv)[0]);
        io_getopt_usage(progname, opts);
      }

      *((int *)opts[index].argloc) = atoi((*argv)[1]);
      (*argc)--;
      (*argv)++;
      break;
    case STRING:
      if (*argc < 2)
      {
        fprintf(stderr, "Error: option '%s' requires an argument\n", (*argv)[0]);
        io_getopt_usage(progname, opts);
      }

      *((char **)opts[index].argloc) = io_strdup((*argv)[1]);
      (*argc)--;
      (*argv)++;
      break;
    case USAGE:
      /* Print usage information and exit. */
      io_getopt_usage(progname, opts);
    default:
      /* Internal error, should never reach here. */
      fprintf(stderr, "Error: internal error in handle_option() at %s:%d\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
  }
}

/**
 * @brief Parse command-line arguments.
 *
 * This function parses command-line arguments based on the provided options and
 * updates the corresponding variables as specified by the options.
 *
 * @param argc Pointer to the argument count.
 * @param argv Pointer to the argument vector.
 * @param opts An array of io_getopt structures representing valid command-line options.
 */
void
io_getopt(int *argc, char ***argv, struct io_getopt *opts)
{
  const char *progname = (*argv)[0];

  while (true)
  {
    bool found = false;
    bool long_option = false;
    const char *opt;

    (*argc)--;
    (*argv)++;

    /* Break the loop if no more arguments. */
    if (*argc < 1)
      break;

    /* Check if the argument is an option (starts with '-'). */
    if ((*argv)[0][0] != '-')
      break;

    /* Determine if it's a long option or short option. */
    if ((*argv)[0][1] == '-')
    {
      opt = &(*argv)[0][2];
      long_option = true;
    }
    else
      opt = &(*argv)[0][1];

    for (unsigned int i = 0; opts[i].opt; ++i)
    {
      if ((long_option && strcmp(opts[i].opt, opt) == 0) ||
          (long_option == false && opts[i].short_opt == opt[0]))
      {
        found = true;
        handle_option(argc, argv, opts, i, progname);
        break;
      }
    }

    if (found == false)
    {
      fprintf(stderr, "Error: unknown argument '%s'\n", (*argv)[0]);
      io_getopt_usage(progname, opts);
    }
  }
}
