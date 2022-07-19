/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2022 ircd-hybrid development team
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

/*! \file getopt.c
 * \brief Uses getopt to fetch the command line options.
 */

#include "stdinc.h"
#include "ircd_getopt.h"
#include "memory.h"

#define OPTCHAR '-'


static void
usage(const char *name, const struct lgetopt *opts)
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

void
parseargs(int *argc, char ***argv, struct lgetopt *opts)
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
      if (strcmp(opts[i].opt, opt) == 0)
      {
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
              usage((*argv)[0], opts);
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
              usage(progname, opts);
            }

            *((char **)opts[i].argloc) = xstrdup((*argv)[1]);
            (*argc)--;
            (*argv)++;
            break;

          case USAGE:
            usage(progname, opts);
            /* NOTREACHED */

          default:
            fprintf(stderr, "Error: internal error in parseargs() at %s:%d\n",
                    __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
      }
    }

    if (found == false)
    {
      fprintf(stderr, "Error: unknown argument '%c%s'\n",
              OPTCHAR, opt);
      usage(progname, opts);
    }
  }
}
