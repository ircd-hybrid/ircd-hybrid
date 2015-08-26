/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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


static const char *const months[] =
{
  "January",   "February", "March",    "April",
  "May",       "June",     "July",     "August",
  "September", "October",  "November", "December"
};

static const char *const weekdays[] =
{
  "Sunday",   "Monday", "Tuesday", "Wednesday",
  "Thursday", "Friday", "Saturday"
};

const char *
date(time_t lclock)
{
  static char buf[80], plus;
  static time_t lclock_last;
  struct tm *lt, *gm;
  struct tm gmbuf;
  int minswest;

  if (!lclock)
    lclock = CurrentTime;

  if (lclock_last == lclock)
    return buf;

  lclock_last = lclock;
  gm = gmtime(&lclock);
  memcpy(&gmbuf, gm, sizeof(gmbuf));
  gm = &gmbuf;
  lt = localtime(&lclock);

  /*
   * There is unfortunately no clean portable way to extract time zone
   * offset information, so do ugly things.
   */
  minswest = (gm->tm_hour - lt->tm_hour) * 60 + (gm->tm_min - lt->tm_min);

  if (lt->tm_yday != gm->tm_yday)
  {
    if ((lt->tm_yday > gm->tm_yday && lt->tm_year == gm->tm_year) ||
        (lt->tm_yday < gm->tm_yday && lt->tm_year != gm->tm_year))
      minswest -= 24 * 60;
    else
      minswest += 24 * 60;
  }

  plus = (minswest > 0) ? '-' : '+';
  if (minswest < 0)
    minswest = -minswest;

  snprintf(buf, sizeof(buf), "%s %s %d %d -- %02u:%02u:%02u %c%02u:%02u",
           weekdays[lt->tm_wday], months[lt->tm_mon], lt->tm_mday,
           lt->tm_year + 1900, lt->tm_hour, lt->tm_min, lt->tm_sec,
           plus, minswest/60, minswest%60);
  return buf;
}

const char *
date_iso8601(time_t lclock)
{
  static char buf[MAX_DATE_STRING];
  static time_t lclock_last;

  if (!lclock)
    lclock = CurrentTime;

  if (lclock_last != lclock)
  {
    lclock_last = lclock;
    strftime(buf, sizeof(buf), "%FT%H:%M:%S%z", localtime(&lclock));
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
myctime(time_t lclock)
{
  static char buf[MAX_DATE_STRING];
  static time_t lclock_last;
  char *p;

  if (!lclock)
    lclock = CurrentTime;

  if (lclock_last == lclock)
    return buf;

  lclock_last = lclock;
  strlcpy(buf, ctime(&lclock), sizeof(buf));

  if ((p = strchr(buf, '\n')))
    *p = '\0';
  return buf;
}

#ifdef HAVE_LIBCRYPTO
const char *
ssl_get_cipher(const SSL *ssl)
{
  static char buffer[IRCD_BUFSIZE];
  int bits = 0;

  SSL_CIPHER_get_bits(SSL_get_current_cipher(ssl), &bits);

  snprintf(buffer, sizeof(buffer), "%s-%s-%d", SSL_get_version(ssl),
           SSL_get_cipher(ssl), bits);
  return buffer;
}
#endif
