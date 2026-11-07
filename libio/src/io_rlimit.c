/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file io_rlimit.c
 * @brief Implements functions for managing resource limits, specifically core file size and the number of open files.
 *
 * This file contains the implementation of functions for setting and retrieving resource limits to control
 * the maximum core file size and the maximum number of open files for the process.
 */

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#include "io_rlimit.h"

/**
 * @brief Sets the core file size limit to the maximum allowed value.
 *
 * This function retrieves the current core file size limit and sets the soft limit
 * (rlim_cur) to the hard limit (rlim_max), allowing the largest possible core files.
 */
void
io_rlimit_set_max_core(void)
{
  struct rlimit rlim;

  if (getrlimit(RLIMIT_CORE, &rlim) == 0)
  {
    rlim.rlim_cur = rlim.rlim_max;
    setrlimit(RLIMIT_CORE, &rlim);
  }
}

/**
 * @brief Sets the maximum number of open files to the highest allowed value.
 *
 * This function retrieves the current limit on the number of open files and sets the soft limit
 * (rlim_cur) to the hard limit (rlim_max). It also adjusts the hard limit if it exceeds certain
 * platform-specific values.
 */
void
io_rlimit_set_max_nofile(void)
{
  struct rlimit rlim;

  if (getrlimit(RLIMIT_NOFILE, &rlim))
  {
    fprintf(stderr, "getrlimit: couldn't get maximum number of file descriptors: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }

#ifdef __APPLE__
  if (rlim.rlim_max > OPEN_MAX)
    rlim.rlim_max = OPEN_MAX;
#endif
  if (rlim.rlim_max > 0xFFFF)
    rlim.rlim_max = 0xFFFF;
  rlim.rlim_cur = rlim.rlim_max;

  if (setrlimit(RLIMIT_NOFILE, &rlim))
  {
    fprintf(stderr, "setrlimit: couldn't set maximum number of file descriptors: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Retrieves the current limit on the number of open files.
 *
 * This function retrieves the current soft limit (rlim_cur) on the number of open files for the process.
 *
 * @return size_t The current soft limit on the number of open files.
 */
size_t
io_rlimit_get_cur_nofile(void)
{
  struct rlimit rlim;

  if (getrlimit(RLIMIT_NOFILE, &rlim))
  {
    fprintf(stderr, "getrlimit: couldn't get maximum number of file descriptors: %s\n",
            strerror(errno));
    exit(EXIT_FAILURE);
  }

  return (size_t)rlim.rlim_cur;
}
