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

/*! \file irc_string.c
 * \brief IRC string functions.
 */

#include "config.h"
#include "stdinc.h"
#include "irc_string.h"


bool
has_wildcards(const char *str)
{
  const unsigned char *p = (const unsigned char *)str;

  for (; *p; ++p)
  {
    if (*p == '\\')
    {
      if (*++p == '\0')
        return false;
    }
    else if (IsMWildChar(*p))
      return true;
  }

  return false;
}

const char *
stripws(char *txt)
{
  while (*txt == '\t' || *txt == ' ')
    ++txt;

  char *tmp = txt + strlen(txt) - 1;
  while (tmp >= txt && (*tmp == '\t' || *tmp == ' '))
    --tmp;

  *(tmp + 1) = '\0';

  return txt;
}

/** Fill a vector of tokens from a delimited input list.
 * Empty tokens (when \a token occurs at the start or end of \a list,
 * or when \a token occurs adjacent to itself) are ignored.  When
 * \a size tokens have been written to \a vector, the rest of the
 * string is ignored.
 * \param names Input buffer.
 * \param token Delimiter used to split \a list.
 * \param vector Output vector.
 * \param size Maximum number of elements to put in \a vector.
 * \return Number of elements written to \a vector.
 */
unsigned int
token_vector(char *names, char token, char *vector[], unsigned int size)
{
  unsigned int count = 0;
  char *start = names;

  assert(names);
  assert(vector);
  assert(size > 1);

  vector[count++] = start;

  for (char *end = strchr(start, token); end;
             end = strchr(start, token))
  {
    *end++ = '\0';
    start = end;

    if (*start)
    {
      vector[count++] = start;

      if (count < size)
        continue;
    }

    break;
  }

  return count;
}

/* libio_basename()
 *
 * input	- i.e. "/usr/local/ircd/modules/m_whois.so"
 * output	- i.e. "m_whois.so"
 * side effects - this will be overwritten on subsequent calls
 */
const char *
libio_basename(const char *path)
{
  const char *s;

  if ((s = strrchr(path, '/')) == NULL)
    s = path;
  else
    s++;

  return s;
}

/*    $OpenBSD: strlcat.c,v 1.18 2016/10/16 17:37:39 dtucker Exp $    */
/*    $OpenBSD: strlcpy.c,v 1.15 2016/10/16 17:37:39 dtucker Exp $    */
/*
 * Copyright (c) 1998, 2015 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef HAVE_STRLCAT
/*
 * Appends src to string dst of size dsize (unlike strncat, dsize is the
 * full size of dst, not space left).  At most dsize-1 characters
 * will be copied.  Always NUL terminates (unless dsize <= strlen(dst)).
 * Returns strlen(src) + MIN(dsize, strlen(initial dst)).
 * If retval >= dsize, truncation occurred.
 */
size_t
strlcat(char *dst, const char *src, size_t dsize)
{
  const char *odst = dst;
  const char *osrc = src;
  size_t n = dsize;
  size_t dlen;

  /* Find the end of dst and adjust bytes left but don't go past end. */
  while (n-- != 0 && *dst != '\0')
    dst++;

  dlen = dst - odst;
  n = dsize - dlen;

  if (n-- == 0)
    return dlen + strlen(src);

  while (*src != '\0')
  {
    if (n != 0)
    {
      *dst++ = *src;
      n--;
    }

    src++;
  }

  *dst = '\0';

  return dlen + (src - osrc);  /* count does not include NUL */
}
#endif

#ifndef HAVE_STRLCPY
/*
 * Copy string src to buffer dst of size dsize.  At most dsize-1
 * chars will be copied.  Always NUL terminates (unless dsize == 0).
 * Returns strlen(src); if retval >= dsize, truncation occurred.
 */
size_t
strlcpy(char *dst, const char *src, size_t dsize)
{
  const char *osrc = src;
  size_t nleft = dsize;

  /* Copy as many bytes as will fit. */
  if (nleft != 0)
  {
    while (--nleft != 0)
    {
      if ((*dst++ = *src++) == '\0')
        break;
    }
  }

  /* Not enough room in dst, add NUL and traverse rest of src. */
  if (nleft == 0)
  {
    if (dsize != 0)
      *dst = '\0';  /* NUL-terminate dst */

    while (*src++)
      ;
  }

  return src - osrc - 1;  /* count does not include NUL */
}
#endif
