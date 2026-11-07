/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file misc.h
 * @brief Header file for miscellaneous functions.
 */

#ifndef INCLUDED_misc_h
#define INCLUDED_misc_h
#include <stdint.h>

extern const char *date(uintmax_t);
extern const char *date_iso8601(uintmax_t);
extern const char *date_iso8601_usec(uintmax_t);
extern const char *date_ctime(uintmax_t);
extern const char *time_format_duration(uintmax_t);
#endif  /* INCLUDED_misc_h */
