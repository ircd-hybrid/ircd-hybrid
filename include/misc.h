/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file misc.h
 * \brief A header for the miscellaneous functions.
 * \version $Id$
 */

#ifndef INCLUDED_misc_h
#define INCLUDED_misc_h

/* Just blindly define our own MIN/MAX macro */
#define IRCD_MAX(a, b)  ((a) > (b) ? (a) : (b))
#define IRCD_MIN(a, b)  ((a) < (b) ? (a) : (b))

#define _1MEG     (1024.0f)
#define _1GIG     (1024.0f*1024.0f)
#define _1TER     (1024.0f*1024.0f*1024.0f)
#define _GMKs(x)  (((x) > _1TER) ? "Tebibytes" : (((x) > _1GIG) ? "Gibibytes" :\
                  (((x) > _1MEG) ? "Mebibytes" : "Kibibytes")))
#define _GMKv(x)  (((x) > _1TER) ? (float)((x)/_1TER) : (((x) > _1GIG) ? \
                   (float)((x)/_1GIG) : (((x) > _1MEG) ? (float)((x)/_1MEG) : \
                   (float)(x))))

extern const char *date(uintmax_t);
extern const char *date_iso8601(uintmax_t);
extern const char *date_ctime(uintmax_t);
extern const char *time_dissect(uintmax_t);
extern void binary_to_hex(const unsigned char *, char *, unsigned int);
#endif  /* INCLUDED_misc_h */
