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

#include <stdnoreturn.h>
#include "stdinc.h"
#include "io_getopt.h"
#include "memory.h"

/**
 * @var OPTCHAR
 * @brief Character used to denote command-line options.
 *
 * This variable defines the character used to denote command-line options. In this
 * context, options are command-line arguments preceded by a specific character,
 * typically a hyphen (-).
 */
static const unsigned char OPTCHAR = '-';

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
    fprintf(stderr, "\t%c%-10s %-20s%s\n", OPTCHAR, opts->opt,
            (opts->argtype == BOOLEAN || opts->argtype == USAGE) ? "" :
            opts->argtype == INTEGER ? "<number>" : "<string>",
            opts->desc);

  exit(EXIT_FAILURE);
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

  /* Loop through each argument */
  while (true)
  {
    bool found = false;
    const char *opt = NULL;

    (*argc)--;
    (*argv)++;

    if (*argc < 1 || (*argv)[0][0] != OPTCHAR)
      return;

    opt = &(*argv)[0][1];

    /* Search through our argument list, and see if it matches */
    for (unsigned int i = 0; opts[i].opt; ++i)
    {
      if (strcmp(opts[i].opt, opt))
        continue;

      /* Found our argument */
      found = true;

      switch (opts[i].argtype)
      {
        case BOOLEAN:
          *((bool *)opts[i].argloc) = true;
          break;

        case INTEGER:
          if (*argc < 2)
          {
            fprintf(stderr, "Error: option '%c%s' requires an argument\n",
                    OPTCHAR, opts[i].opt);
            io_getopt_usage((*argv)[0], opts);
          }

          *((int *)opts[i].argloc) = atoi((*argv)[1]);
          (*argc)--;
          (*argv)++;
          break;

        case STRING:
          if (*argc < 2)
          {
            fprintf(stderr, "Error: option '%c%s' requires an argument\n",
                    OPTCHAR, opts[i].opt);
            io_getopt_usage(progname, opts);
          }

          *((char **)opts[i].argloc) = io_strdup((*argv)[1]);
          (*argc)--;
          (*argv)++;
          break;

        case USAGE:
          io_getopt_usage(progname, opts);
          /* NOTREACHED */

        default:
          fprintf(stderr, "Error: internal error in io_getopt() at %s:%d\n",
                  __FILE__, __LINE__);
          exit(EXIT_FAILURE);
      }
    }

    if (found == false)
    {
      fprintf(stderr, "Error: unknown argument '%c%s'\n",
              OPTCHAR, opt);
      io_getopt_usage(progname, opts);
    }
  }
}
