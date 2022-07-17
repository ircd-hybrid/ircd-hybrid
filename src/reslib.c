/*
 * Copyright (c) 1985, 1993
 *    The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Portions Copyright (c) 1993 by Digital Equipment Corporation.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies, and that
 * the name of Digital Equipment Corporation not be used in advertising or
 * publicity pertaining to distribution of the document or software without
 * specific, written prior permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

/*
 * Portions Copyright (c) 1996-1999 by Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

/* Original copyright ISC as above.
 *
 * The following functions were extracted from glibc's resolver
 * implementation. All functions (except for res_mkquery, which
 * has been heavily modified for use in ircd-hybrid), remain
 * unmodified.
 *
 * dn_expand() - dn_expand.c
 * dn_find() - ns_name_pack.c
 * dn_skipname() - dn_skipname.c
 * mklower() - ns_name_pack.c
 * ns_get16 - ns_netint.c
 * ns_get32() - ns_netint.c
 * ns_name_compress() - ns_name_compress.c
 * ns_name_ntop() - ns_name_ntop.c
 * ns_name_pack() - ns_name_pack.c
 * ns_name_pton() - ns_name_pton.c
 * ns_name_skip() - ns_name_skip.c
 * ns_name_uncompress() - ns_name_uncompress.c
 * ns_name_unpack() - ns_name_unpack.c
 * printable() - ns_name_ntop.c
 * res_mkquery() - res_mkquery.c
 * special() - ns_name_ntop.c
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "res.h"
#include "reslib.h"
#include "irc_string.h"

#define MAXLINE 128

struct irc_ssaddr irc_nsaddr_list[RESLIB_MAXNS];
unsigned int irc_nscount = 0;

static bool special(int);
static bool printable(int);
static int irc_ns_name_compress(const char *, unsigned char *, size_t, const unsigned char **, const unsigned char **);
static int irc_dn_find(const unsigned char *, const unsigned char *, const unsigned char **, const unsigned char **);
static int irc_ns_name_uncompress(const unsigned char *, const unsigned char *, const unsigned char *, char *, size_t);
static int irc_ns_name_unpack(const unsigned char *, const unsigned char *, const unsigned char *, unsigned char *, size_t);
static int irc_ns_name_ntop(const unsigned char *, char *, size_t);
static int irc_ns_name_skip(const unsigned char **, const unsigned char *);
static int mklower(int);


/* add_nameserver()
 *
 * input        - either an IPV4 address in dotted quad
 *                or an IPV6 address in : format
 * output       - NONE
 * side effects - entry in irc_nsaddr_list is filled in as needed
 */
static void
add_nameserver(const char *arg)
{
  struct addrinfo hints, *res;

  /* Done max number of nameservers? */
  if (irc_nscount >= RESLIB_MAXNS)
    return;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = PF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(arg, "domain", &hints, &res))
    return;

  memcpy(&irc_nsaddr_list[irc_nscount].ss, res->ai_addr, res->ai_addrlen);
  irc_nsaddr_list[irc_nscount++].ss_len = res->ai_addrlen;
  freeaddrinfo(res);
}

/* parse_resvconf()
 *
 * inputs - NONE
 * output - -1 if failure 0 if success
 * side effects - fills in irc_nsaddr_list
 */
static void
parse_resvconf(void)
{
  char *p;
  char *opt;
  char *arg;
  char input[MAXLINE];
  FILE *file;

  /* XXX "/etc/resolv.conf" should be from a define in config.h perhaps
   * for cygwin support etc. this hardcodes it to unix for now -db
   */
  if ((file = fopen("/etc/resolv.conf", "r")) == NULL)
    return;

  while (fgets(input, sizeof(input), file))
  {
    /* blow away any newline */
    if ((p = strpbrk(input, "\r\n")))
      *p = '\0';

    p = input;

    /* skip until something thats not a space is seen */
    while (IsSpace(*p))
      ++p;

    /* if at this point, have a '\0' then continue */
    if (*p == '\0')
      continue;

    /* Ignore comment lines immediately */
    if (*p == ';' || *p == '#')
      continue;

    /* skip until a space is found */
    opt = p;
    while (!IsSpace(*p) && *p)
      ++p;

    if (*p == '\0')
      continue;  /* no arguments?.. ignore this line */

    /* blow away the space character */
    *p++ = '\0';

    /* skip these spaces that are before the argument */
    while (IsSpace(*p))
      ++p;

    /* Now arg should be right where p is pointing */
    arg = p;

    if ((p = strpbrk(arg, " \t")))
      *p = '\0';  /* take the first word */

    if (!strcasecmp(opt, "nameserver"))
      add_nameserver(arg);
  }

  fclose(file);
}

void
irc_res_init(void)
{
  irc_nscount = 0;
  memset(irc_nsaddr_list, 0, sizeof(irc_nsaddr_list));

  parse_resvconf();

  if (irc_nscount == 0)
    add_nameserver("127.0.0.1");
}

/* Expand compressed domain name COMP_DN to full domain name.  MSG is
   a pointer to the beginning of the message, EOMORIG points to the
   first location after the message, EXP_DN is a pointer to a buffer
   of size LENGTH for the result.  Returns size of compressed name or
   -1 if there was an error.  */
int
irc_dn_expand(const unsigned char *msg, const unsigned char *eom,
              const unsigned char *src, char *dst, int dstsiz)
{
  int n = irc_ns_name_uncompress(msg, eom, src, dst, (size_t)dstsiz);

  if (n > 0 && dst[0] == '.')
    dst[0] = '\0';
  return n;
}

/* Expand compressed domain name to presentation format.  Returns the
   number of bytes read out of `src', or -1 (with errno set).  The
   root domain is returned as ".", not "".  */
static int
irc_ns_name_uncompress(const unsigned char *msg, const unsigned char *eom,
                       const unsigned char *src, char *dst, size_t dstsiz)
{
  unsigned char tmp[NS_MAXCDNAME];
  int n = irc_ns_name_unpack(msg, eom, src, tmp, sizeof tmp);

  if (n < 0)
    return -1;
  if (irc_ns_name_ntop(tmp, dst, dstsiz) < 0)
    return -1;
  return n;
}

/* Unpack a domain name from a message, source may be compressed.
   Returns -1 if it fails, or consumed octets if it succeeds.  */
static int
irc_ns_name_unpack(const unsigned char *msg, const unsigned char *eom,
                   const unsigned char *src, unsigned char *dst,
                   size_t dstsiz)
{
  const unsigned char *srcp, *dstlim;
  unsigned char *dstp;
  int n, len, checked;

  len = -1;
  checked = 0;
  dstp = dst;
  srcp = src;
  dstlim = dst + dstsiz;

  if (srcp < msg || srcp >= eom)
  {
    errno = EMSGSIZE;
    return -1;
  }

  /* Fetch next label in domain name.  */
  while ((n = *srcp++) != 0)
  {
    /* Check for indirection.  */
    switch (n & NS_CMPRSFLGS)
    {
      case 0:
        /* Limit checks.  */
        if (n >= 64)
        {
          errno = EMSGSIZE;
          return -1;
        }

        /* NB: n + 1 and >= to cover the *dstp = '\0' assignment
           below.  */
        if (n + 1 >= dstlim - dstp || n >= eom - srcp)
        {
          errno = EMSGSIZE;
          return -1;
        }

        checked += n + 1;
        *dstp++ = n;
        memcpy(dstp, srcp, n);
        dstp += n;
        srcp += n;
        break;

      case NS_CMPRSFLGS:
        if (srcp >= eom)
        {
          errno = EMSGSIZE;
          return -1;
        }

        if (len < 0)
          len = srcp - src + 1;

        {
          int target = ((n & 0x3f) << 8) | *srcp;
          if (target >= eom - msg)
          {
            /* Out of range.  */
            errno = EMSGSIZE;
            return -1;
          }

          srcp = msg + target;
        }

        checked += 2;

        /* Check for loops in the compressed name; if we've looked
           at the whole message, there must be a loop.  */
        if (checked >= eom - msg)
        {
          errno = EMSGSIZE;
          return -1;
        }

        break;

      default:
        errno = EMSGSIZE;
        return -1;
    }
  }

  *dstp = '\0';

  if (len < 0)
    len = srcp - src;

  return len;
}

/* Converts an uncompressed, encoded domain name to printable ASCII as
   per RFC1035.  Returns the number of bytes written to buffer, or -1
   (with errno set).  The root is returned as "."  All other domains
   are returned in non absolute form.  */
static int
irc_ns_name_ntop(const unsigned char *src, char *dst, size_t dstsiz)
{
  const unsigned char *cp;
  char *dn, *eom;
  unsigned char c;
  int l;

  cp = src;
  dn = dst;
  eom = dst + dstsiz;

  while ((l = *cp++) != 0)
  {
    if (l >= 64)
    {
      /* Some kind of compression pointer.  */
      errno = EMSGSIZE;
      return -1;
    }

    if (dn != dst)
    {
      if (dn >= eom)
      {
        errno = EMSGSIZE;
        return -1;
      }

      *dn++ = '.';
    }

    for (; l > 0; l--)
    {
      c = *cp++;

      if (special(c))
      {
        if (eom - dn < 2)
        {
          errno = EMSGSIZE;
          return -1;
        }

        *dn++ = '\\';
        *dn++ = c;
      }
      else if (!printable(c))
      {
        if (eom - dn < 4)
        {
          errno = EMSGSIZE;
          return -1;
        }

        *dn++ = '\\';
        *dn++ = '0' + (c / 100);
        *dn++ = '0' + ((c % 100) / 10);
        *dn++ = '0' + (c % 10);
      }
      else
      {
        if (eom - dn < 2)
        {
          errno = EMSGSIZE;
          return -1;
        }

        *dn++ = c;
      }
    }
  }

  if (dn == dst)
  {
    if (dn >= eom)
    {
      errno = EMSGSIZE;
      return -1;
    }

    *dn++ = '.';
  }

  if (dn >= eom)
  {
    errno = EMSGSIZE;
    return -1;
  }

  *dn++ = '\0';
  return dn - dst;
}

/* Skips over a compressed domain name. Returns the size or -1.  */
int
irc_dn_skipname(const unsigned char *ptr, const unsigned char *eom)
{
  const unsigned char *saveptr = ptr;

  if (irc_ns_name_skip(&ptr, eom) < 0)
    return -1;
  return ptr - saveptr;
}

/* Advances *PTRPTR to skip over the compressed name it points at.
   Returns 0 on success, -1 (with errno set) on failure.  */
static int
irc_ns_name_skip(const unsigned char **ptrptr, const unsigned char *eom)
{
  const unsigned char *cp;
  unsigned int n;

  cp = *ptrptr;

  while (cp < eom)
  {
    n = *cp++;

    if (n == 0)
    {
      /* End of domain name without indirection.  */
      *ptrptr = cp;
      return 0;
    }

    /* Check for indirection.  */
    switch (n & NS_CMPRSFLGS)
    {
      case 0:  /* Normal case, n == len.  */
        if (eom - cp < n)
          goto malformed;

        cp += n;
        break;
      case NS_CMPRSFLGS:  /* Indirection.  */
        if (cp == eom)
          /* No room for second indirection byte.  */
          goto malformed;
        *ptrptr = cp + 1;
        return 0;
      default:  /* Illegal type.  */
        goto malformed;
    }
  }

malformed:
  errno = EMSGSIZE;
  return -1;
}

unsigned int
irc_ns_get16(const unsigned char *src)
{
  unsigned int dst;

  IRC_NS_GET16(dst, src);
  return dst;
}

unsigned long
irc_ns_get32(const unsigned char *src)
{
  unsigned long dst;

  IRC_NS_GET32(dst, src);
  return dst;
}

/* Thinking in noninternationalized US-ASCII (per the DNS spec), is
   this character special ("in need of quoting")?  */
static inline bool
special(int ch)
{
  switch (ch)
  {
    case '"':
    case '.':
    case ';':
    case '\\':
    case '(':
    case ')':
      /* Special modifiers in zone files.  */
    case '@':
    case '$':
      return true;
    default:
      return false;
  }
}

/* Thinking in noninternationalized US-ASCII (per the DNS spec), is
   this character visible and not a space when printed?  */
static inline bool
printable(int ch)
{
  return ch > 0x20 && ch < 0x7f;
}

/* Converts an ASCII string into an encoded domain name as per
   RFC1035.  Returns -1 if it fails, 1 if string was fully qualified,
   0 is string was not fully qualified.  Enforces label and domain
   length limits.  */
static int
irc_ns_name_pton(const char *src, unsigned char *dst, size_t dstsiz)
{
  unsigned char *label, *bp, *eom;
  int c, n, escaped;

  escaped = 0;
  bp = dst;
  eom = dst + dstsiz;
  label = bp++;

  while ((c = *src++) != 0)
  {
    if (escaped)
    {
      if ('0' <= c && c <= '9')
      {
        n = (c - '0') * 100;

        if ((c = *src++) == 0 || c < '0' || c > '9')
        {
           errno = EMSGSIZE;
          return -1;
        }

        n += (c - '0') * 10;

        if ((c = *src++) == 0 || c < '0' || c > '9')
        {
          errno = EMSGSIZE;
          return -1;
        }

        n += c - '0';

        if (n > 255)
        {
          errno = EMSGSIZE;
          return -1;
        }

        c = n;
      }

      escaped = 0;
    }
    else if (c == '\\')
    {
      escaped = 1;
      continue;
    }
    else if (c == '.')
    {
      c = (bp - label - 1);

      if ((c & NS_CMPRSFLGS) != 0)  /* Label too big.  */
      {
        errno = EMSGSIZE;
        return -1;
      }

      if (label >= eom)
      {
        errno = EMSGSIZE;
        return -1;
      }

      *label = c;

      /* Fully qualified ? */
      if (*src == '\0')
      {
        if (c != 0)
        {
          if (bp >= eom)
          {
            errno = EMSGSIZE;
            return -1;
          }

          *bp++ = '\0';
        }

        if ((bp - dst) > NS_MAXCDNAME)
        {
          errno = EMSGSIZE;
          return -1;
        }

        return 1;
      }

      if (c == 0 || *src == '.')
      {
        errno = EMSGSIZE;
        return -1;
      }

      label = bp++;
      continue;
    }

    if (bp >= eom)
    {
      errno = EMSGSIZE;
      return -1;
    }

    *bp++ = (unsigned char)c;
  }

  if (escaped)  /* Trailing backslash.  */
  {
    errno = EMSGSIZE;
    return -1;
  }

  c = (bp - label - 1);

  if ((c & NS_CMPRSFLGS) != 0)  /* Label too big.  */
  {
    errno = EMSGSIZE;
    return -1;
  }

  if (label >= eom)
  {
    errno = EMSGSIZE;
    return -1;
  }

  *label = c;

  if (c != 0)
  {
    if (bp >= eom)
    {
      errno = EMSGSIZE;
      return -1;
    }

    *bp++ = 0;
  }

  if ((bp - dst) > NS_MAXCDNAME)  /* src too big.  */
  {
    errno = EMSGSIZE;
    return -1;
  }

  return 0;
}

/* Packs domain name SRC into DST.  Returns size of the compressed
   name, or -1.

   DNPTRS is an array of pointers to previous compressed names.
   DNPTRS[0] is a pointer to the beginning of the message. The array
   ends with NULL.  LASTDNPTR is a pointer to the end of the array
   pointed to by 'dnptrs'.

   The list of pointers in DNPTRS is updated for labels inserted into
   the message as we compress the name.  If DNPTRS is NULL, we don't
   try to compress names. If LASTDNPTR is NULL, we don't update the
   list.  */
static int
irc_ns_name_pack(const unsigned char *src, unsigned char *dst, int dstsiz,
                 const unsigned char **dnptrs, const unsigned char **lastdnptr)
{
  unsigned char *dstp;
  const unsigned char **cpp, **lpp, *eob, *msg;
  const unsigned char *srcp;
  int n, l, first = 1;

  srcp = src;
  dstp = dst;
  eob = dstp + dstsiz;
  lpp = cpp = NULL;

  if (dnptrs != NULL)
  {
    if ((msg = *dnptrs++) != NULL)
    {
      for (cpp = dnptrs; *cpp != NULL; cpp++)
        ;

      lpp = cpp;  /* End of list to search.  */
    }
  }
  else
    msg = NULL;

  /* Make sure the domain we are about to add is legal.  */
  l = 0;

  do
  {
    n = *srcp;

    if (n >= 64)
    {
      errno = EMSGSIZE;
      return -1;
    }

    l += n + 1;

    if (l > NS_MAXCDNAME)
    {
      errno = EMSGSIZE;
      return -1;
    }

    srcp += n + 1;
  } while (n != 0);

  /* from here on we need to reset compression pointer array on error */
  srcp = src;
  do
  {
    /* Look to see if we can use pointers.  */
    n = *srcp;

    if (n != 0 && msg != NULL)
    {
      l = irc_dn_find(srcp, msg, dnptrs, lpp);
      if (l >= 0)
      {
        if (eob - dstp <= 1)
          goto cleanup;

        *dstp++ = (l >> 8) | NS_CMPRSFLGS;
        *dstp++ = l % 256;
        return dstp - dst;
      }

      /* Not found, save it.  */
      if (lastdnptr != NULL && cpp < lastdnptr - 1 && (dstp - msg) < 0x4000 && first)
      {
        *cpp++ = dstp;
        *cpp = NULL;
        first = 0;
      }
    }

    /* Copy label to buffer.  */
    if (n >= 64)
      /* Should not happen.  */
      goto cleanup;

    if (n + 1 > eob - dstp)
      goto cleanup;

    memcpy(dstp, srcp, n + 1);
    srcp += n + 1;
    dstp += n + 1;
  } while (n != 0);

  if (dstp > eob)
  {
cleanup:
    if (msg != NULL)
      *lpp = NULL;

    errno = EMSGSIZE;
    return -1;
  }

  return dstp - dst;
}

/* Compresses a domain name into wire format, using compression pointers.
   Returns the number of bytes consumed in DST or -1 (with errno set).

   DNPTRS is an array of pointers to previous compressed names.
   DNPTRS[0] is a pointer to the beginning of the message.

   The list ends with NULL.  LASTDNPTR is a pointer to the end of the
   array pointed to by DNPTRS.  Side effect is to update the list of
   pointers for labels inserted into the message as we compress the
   name.  If DNPTRS is NULL, we don't try to compress names.  If
   LASTDNPTR * is NULL, we don't update the list.  */
static int
irc_ns_name_compress(const char *src, unsigned char *dst, size_t dstsiz,
                     const unsigned char **dnptrs, const unsigned char **lastdnptr)
{
  unsigned char tmp[NS_MAXCDNAME];

  if (irc_ns_name_pton(src, tmp, sizeof tmp) < 0)
    return -1;
  return irc_ns_name_pack(tmp, dst, dstsiz, dnptrs, lastdnptr);
}

/* Search for the counted-label name in an array of compressed names.
   Returns the offset from MSG if found, or -1.

   DNPTRS is the pointer to the first name on the list, not the
   pointer to the start of the message.  */
static int
irc_dn_find(const unsigned char *domain, const unsigned char *msg,
            const unsigned char **dnptrs,
            const unsigned char **lastdnptr)
{
  const unsigned char *dn, *cp, *sp;
  const unsigned char **cpp;
  unsigned int n;

  for (cpp = dnptrs; cpp < lastdnptr; cpp++)
  {
    sp = *cpp;

    /* Terminate search on: root label, compression pointer, unusable
       offset.  */
    while (*sp != 0 && (*sp & NS_CMPRSFLGS) == 0 && (sp - msg) < 0x4000)
    {
      dn = domain;
      cp = sp;

      while ((n = *cp++) != 0)
      {
        /* Check for indirection.  */
        switch (n & NS_CMPRSFLGS)
        {
          case 0:  /* Normal case, n == len.  */
            if (n != *dn++)
              goto next;

            for (; n > 0; n--)
              if (mklower(*dn++) != mklower(*cp++))
                goto next;

            /* Is next root for both?  */
            if (*dn == '\0' && *cp == '\0')
              return sp - msg;

            if (*dn)
              continue;
            goto next;

          case NS_CMPRSFLGS:  /* Indirection.  */
            cp = msg + (((n & 0x3f) << 8) | *cp);
            break;
          default:  /* Illegal type.  */
            errno = EMSGSIZE;
            return -1;
        }
      }
next: ;
      sp += *sp + 1;
    }
  }

  errno = ENOENT;
  return -1;
}

/* Thinking in noninternationalized USASCII (per the DNS spec),
   convert this character to lower case if it's upper case.  */
static int
mklower(int ch)
{
  if (ch >= 'A' && ch <= 'Z')
    return ch - 'A' + 'a';
  return ch;
}

/* Form all types of queries.  Returns the size of the result or -1 on
   error.

   DNAME is the domain.  CLASS and TYPE are the DNS query
   class and type.  BUF must point to the out buffer of BUFLEN bytes. */
int
irc_res_mkquery(const char *dname, int class, int type, unsigned char *buf, int buflen)
{
  HEADER *hp;
  unsigned char *cp;
  int n;
  const unsigned char *dnptrs[20], **dpp, **lastdnptr;

  if (class < 0 || class > 65535 || type < 0 || type > 65535)
    return -1;

  /* Initialize header fields.  */
  if ((buf == NULL) || (buflen < HFIXEDSZ))
    return -1;

  memset(buf, 0, HFIXEDSZ);
  hp = (HEADER *)buf;

  hp->id = 0;
  hp->opcode = QUERY;  /* standard query */
  hp->rd = 1;  /* recursion desired */
  hp->rcode = NO_ERRORS;
  cp = buf + HFIXEDSZ;
  buflen -= HFIXEDSZ;
  dpp = dnptrs;
  *dpp++ = buf;
  *dpp++ = NULL;
  lastdnptr = dnptrs + sizeof dnptrs / sizeof dnptrs[0];

  if ((buflen -= QFIXEDSZ) < 0)
    return -1;

  n = irc_ns_name_compress(dname, cp, buflen, dnptrs, lastdnptr);
  if (n < 0)
    return -1;

  cp += n;
  buflen -= n;
  IRC_NS_PUT16(type, cp);
  IRC_NS_PUT16(class, cp);
  hp->qdcount = htons(1);

  return cp - buf;
}
