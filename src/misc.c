/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2019 ircd-hybrid development team
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

/*! \file s_misc.c
 * \brief Yet another miscellaneous functions file.
 * \version $Id$
 */

#include "stdinc.h"
#include "misc.h"
#include "irc_string.h"
#include "ircd.h"


const char *
date(uintmax_t lclock)
{
  static char buf[80];
  static uintmax_t lclock_last;

  if (lclock == 0)
    lclock = event_base->time.sec_real;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
    strftime(buf, sizeof(buf), "%A %B %-e %Y -- %T %z", localtime((time_t *)&lclock));
  }

  return buf;
}

const char *
date_iso8601(uintmax_t lclock)
{
  static char buf[MAX_DATE_STRING];
  static uintmax_t lclock_last;

  if (lclock == 0)
    lclock = event_base->time.sec_real;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
    strftime(buf, sizeof(buf), "%FT%T%z", localtime((time_t *)&lclock));
  }

  return buf;
}

/*
 * myctime - This is like standard ctime()-function, but it zaps away
 *   the newline from the end of that string. Also, it takes
 *   the time value as parameter, instead of pointer to it.
 *   Note that it is necessary to copy the string to alternate
 *   buffer (who knows how ctime() implements it, maybe it statically
 *   has newline there and never 'refreshes' it -- zapping that
 *   might break things in other places...)
 *
 *
 * Thu Nov 24 18:22:48 1986
 */
const char *
date_ctime(uintmax_t lclock)
{
  static char buf[MAX_DATE_STRING];
  static uintmax_t lclock_last;

  if (lclock == 0)
    lclock = event_base->time.sec_real;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;  /* Cache value to avoid repetitive strftime() calls. */
    strftime(buf, sizeof(buf), "%a %b %-e %T %Y", localtime((time_t *)&lclock));
  }

  return buf;
}

const char *
time_dissect(uintmax_t duration)
{
  static char buf[32];  /* 32 = sizeof("9999999999999999 days, 23:59:59") */
  unsigned int days = 0, hours = 0, minutes = 0, seconds = 0;

  while (duration >= 60 * 60 * 24)
  {
    duration -= 60 * 60 * 24;
    ++days;
  }

  while (duration >= 60 * 60)
  {
    duration -= 60 * 60;
    ++hours;
  }

  while (duration >= 60)
  {
    duration -= 60;
    ++minutes;
  }

  seconds = duration;

  snprintf(buf, sizeof(buf), "%u day%s, %02u:%02u:%02u",
           days, days == 1 ? "" : "s", hours, minutes, seconds);
  return buf;
}

void
binary_to_hex(const unsigned char *bin, char *hex, unsigned int length)
{
  static const char trans[] = "0123456789ABCDEF";

  for (const unsigned char *const end = bin + length; bin < end; ++bin)
  {
    *hex++ = trans[*bin >>  4];
    *hex++ = trans[*bin & 0xf];
  }

  *hex = '\0';
}

bool
address_compare(const void *p1,
                const void *p2, bool port)
{
  const struct irc_ssaddr *const addr1 = p1;
  const struct irc_ssaddr *const addr2 = p2;

  if (addr1->ss.ss_family != addr2->ss.ss_family)
    return false;

  if (addr1->ss.ss_family == AF_INET)
  {
    const struct sockaddr_in *const sin1 = (const struct sockaddr_in *)addr1;
    const struct sockaddr_in *const sin2 = (const struct sockaddr_in *)addr2;

    if (port == true && (sin1->sin_port != sin2->sin_port))
      return false;

    return sin1->sin_addr.s_addr == sin2->sin_addr.s_addr;
  }
  else if (addr1->ss.ss_family == AF_INET6)
  {
    const struct sockaddr_in6 *const sin1 = (const struct sockaddr_in6 *)addr1;
    const struct sockaddr_in6 *const sin2 = (const struct sockaddr_in6 *)addr2;

    if (port == true && (sin1->sin6_port != sin2->sin6_port))
      return false;

    return memcmp(sin1->sin6_addr.s6_addr,
                  sin2->sin6_addr.s6_addr, sizeof(struct in6_addr)) == 0;
  }

  return false;
}
