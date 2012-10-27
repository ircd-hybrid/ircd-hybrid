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
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 * 	This product includes software developed by the University of
 * 	California, Berkeley and its contributors.
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
 * Code modified specifically for ircd use from the following orginal files
 * in bind ...
 *
 * res_comp.c
 * ns_name.c
 * ns_netint.c
 * res_init.c
 * 
 * - Dianora
 */

#include "stdinc.h"
#include "ircd_defs.h"
#include "irc_res.h"
#include "irc_reslib.h"
#include "fileio.h"
#include "irc_string.h"

#define NS_TYPE_ELT             0x40 /* EDNS0 extended label type */
#define DNS_LABELTYPE_BITSTRING 0x41
#define MAXLINE 128

/* $Id$ */

struct irc_ssaddr irc_nsaddr_list[IRCD_MAXNS];
int irc_nscount = 0;

static const char digitvalue[256] = {
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*16*/
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*32*/
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*48*/
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1, /*64*/
  -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*80*/
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*96*/
  -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*112*/
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*128*/
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*256*/
};

static int parse_resvconf(void);
static void add_nameserver(char *arg);

static const char digits[] = "0123456789";
static int labellen(const unsigned char *lp);
static int special(int ch);
static int printable(int ch);
static int irc_decode_bitstring(const unsigned char **cpp, char *dn, const char *eom);
static int irc_ns_name_compress(const char *src, unsigned char *dst, size_t dstsiz,
    const unsigned char **dnptrs, const unsigned char **lastdnptr);
static int irc_dn_find(const unsigned char *, const unsigned char *, const unsigned char * const *,
                       const unsigned char * const *);
static int irc_encode_bitsring(const char **, const char *, unsigned char **, unsigned char **, 
                               const unsigned char *);
static int irc_ns_name_uncompress(const unsigned char *, const unsigned char *,
                                  const unsigned char *, char *, size_t);
static int irc_ns_name_unpack(const unsigned char *, const unsigned char *,
                              const unsigned char *, unsigned char *,
                              size_t);
static int irc_ns_name_ntop(const unsigned char *, char *, size_t);
static int irc_ns_name_skip(const unsigned char **, const unsigned char *);
static int mklower(int ch);
  
int
irc_res_init(void)
{
  irc_nscount = 0;
  memset(irc_nsaddr_list, 0, sizeof(irc_nsaddr_list));

  return parse_resvconf();
}

/* parse_resvconf()
 *
 * inputs - NONE
 * output - -1 if failure 0 if success
 * side effects - fills in irc_nsaddr_list
 */
static int
parse_resvconf(void)
{
  char *p;
  char *opt;
  char *arg;
  char input[MAXLINE];
  FBFILE *file;

  /* XXX "/etc/resolv.conf" should be from a define in config.h perhaps
   * for cygwin support etc. this hardcodes it to unix for now -db
   */
  if ((file = fbopen("/etc/resolv.conf", "r")) == NULL)
    return -1;

  while (fbgets(input, sizeof(input), file) != NULL)
  {
    /* blow away any newline */
    if ((p = strpbrk(input, "\r\n")) != NULL)
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

    if ((p = strpbrk(arg, " \t")) != NULL)
      *p = '\0';  /* take the first word */

    if (irccmp(opt, "nameserver") == 0)
      add_nameserver(arg);
  }

  fbclose(file);
  return 0;
}

/* add_nameserver()
 *
 * input        - either an IPV4 address in dotted quad
 *                or an IPV6 address in : format
 * output       - NONE
 * side effects - entry in irc_nsaddr_list is filled in as needed
 */
static void
add_nameserver(char *arg)
{
  struct addrinfo hints, *res;
  /* Done max number of nameservers? */
  if ((irc_nscount) >= IRCD_MAXNS)
    return;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family   = PF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(arg, "domain", &hints, &res))
    return;

  if (res == NULL)
    return;

  memcpy(&irc_nsaddr_list[irc_nscount].ss, res->ai_addr, res->ai_addrlen);
  irc_nsaddr_list[irc_nscount].ss_len = res->ai_addrlen;
  irc_nscount++;
  freeaddrinfo(res);
}

/*
 * Expand compressed domain name 'comp_dn' to full domain name.
 * 'msg' is a pointer to the begining of the message,
 * 'eomorig' points to the first location after the message,
 * 'exp_dn' is a pointer to a buffer of size 'length' for the result.
 * Return size of compressed name or -1 if there was an error.
 */
int
irc_dn_expand(const unsigned char *msg, const unsigned char *eom,
              const unsigned char *src, char *dst, int dstsiz)
{
  int n = irc_ns_name_uncompress(msg, eom, src, dst, (size_t)dstsiz);

  if (n > 0 && dst[0] == '.')
    dst[0] = '\0';
  return(n);
} /*2*/

/*
 * irc_ns_name_uncompress(msg, eom, src, dst, dstsiz)
 *	Expand compressed domain name to presentation format.
 * return:
 *	Number of bytes read out of `src', or -1 (with errno set).
 * note:
 *	Root domain returns as "." not "".
 */
static int
irc_ns_name_uncompress(const unsigned char *msg, const unsigned char *eom,
                       const unsigned char *src, char *dst, size_t dstsiz)
{
  unsigned char tmp[NS_MAXCDNAME];
  int n;

  if ((n = irc_ns_name_unpack(msg, eom, src, tmp, sizeof tmp)) == -1)
    return(-1);
  if (irc_ns_name_ntop(tmp, dst, dstsiz) == -1)
    return(-1);
  return(n);
} /*2*/

/*
 * irc_ns_name_unpack(msg, eom, src, dst, dstsiz)
 *	Unpack a domain name from a message, source may be compressed.
 * return:
 *	-1 if it fails, or consumed octets if it succeeds.
 */
static int
irc_ns_name_unpack(const unsigned char *msg, const unsigned char *eom,
                   const unsigned char *src, unsigned char *dst,
                   size_t dstsiz)
{
	const unsigned char *srcp, *dstlim;
	unsigned char *dstp;
	int n, len, checked, l;

	len = -1;
	checked = 0;
	dstp = dst;
	srcp = src;
	dstlim = dst + dstsiz;
	if (srcp < msg || srcp >= eom) {
		errno = EMSGSIZE;
		return (-1);
	}
	/* Fetch next label in domain name. */
	while ((n = *srcp++) != 0) {
		/* Check for indirection. */
		switch (n & NS_CMPRSFLGS) {
		case 0:
		case NS_TYPE_ELT:
			/* Limit checks. */
			if ((l = labellen(srcp - 1)) < 0) {
				errno = EMSGSIZE;
				return(-1);
			}
			if (dstp + l + 1 >= dstlim || srcp + l >= eom) {
				errno = EMSGSIZE;
				return (-1);
			}
			checked += l + 1;
			*dstp++ = n;
			memcpy(dstp, srcp, l);
			dstp += l;
			srcp += l;
			break;

		case NS_CMPRSFLGS:
			if (srcp >= eom) {
				errno = EMSGSIZE;
				return (-1);
			}
			if (len < 0)
				len = srcp - src + 1;
			srcp = msg + (((n & 0x3f) << 8) | (*srcp & 0xff));
			if (srcp < msg || srcp >= eom) {  /* Out of range. */
				errno = EMSGSIZE;
				return (-1);
			}
			checked += 2;
			/*
			 * Check for loops in the compressed name;
			 * if we've looked at the whole message,
			 * there must be a loop.
			 */
			if (checked >= eom - msg) {
				errno = EMSGSIZE;
				return (-1);
			}
			break;

		default:
			errno = EMSGSIZE;
			return (-1);			/* flag error */
		}
	}
	*dstp = '\0';
	if (len < 0)
		len = srcp - src;
	return (len);
} /*2*/

/*
 * irc_ns_name_ntop(src, dst, dstsiz)
 *	Convert an encoded domain name to printable ascii as per RFC1035.
 * return:
 *	Number of bytes written to buffer, or -1 (with errno set)
 * notes:
 *	The root is returned as "."
 *	All other domains are returned in non absolute form
 */
static int
irc_ns_name_ntop(const unsigned char *src, char *dst, size_t dstsiz)
{
	const unsigned char *cp;
	char *dn, *eom;
	unsigned char c;
	unsigned int n;
	int l;

	cp = src;
	dn = dst;
	eom = dst + dstsiz;

	while ((n = *cp++) != 0) {
		if ((n & NS_CMPRSFLGS) == NS_CMPRSFLGS) {
			/* Some kind of compression pointer. */
			errno = EMSGSIZE;
			return (-1);
		}
		if (dn != dst) {
			if (dn >= eom) {
				errno = EMSGSIZE;
				return (-1);
			}
			*dn++ = '.';
		}
		if ((l = labellen((cp - 1))) < 0) {
			errno = EMSGSIZE; /* XXX */
			return(-1);
		}
		if (dn + l >= eom) {
			errno = EMSGSIZE;
			return (-1);
		}
		if ((n & NS_CMPRSFLGS) == NS_TYPE_ELT) {
			int m;

			if (n != DNS_LABELTYPE_BITSTRING) {
				/* XXX: labellen should reject this case */
				errno = EINVAL;
				return(-1);
			}
			if ((m = irc_decode_bitstring(&cp, dn, eom)) < 0)
			{
				errno = EMSGSIZE;
				return(-1);
			}
			dn += m; 
			continue;
		}
		for ((void)NULL; l > 0; l--) {
			c = *cp++;
			if (special(c)) {
				if (dn + 1 >= eom) {
					errno = EMSGSIZE;
					return (-1);
				}
				*dn++ = '\\';
				*dn++ = (char)c;
			} else if (!printable(c)) {
				if (dn + 3 >= eom) {
					errno = EMSGSIZE;
					return (-1);
				}
				*dn++ = '\\';
				*dn++ = digits[c / 100];
				*dn++ = digits[(c % 100) / 10];
				*dn++ = digits[c % 10];
			} else {
				if (dn >= eom) {
					errno = EMSGSIZE;
					return (-1);
				}
				*dn++ = (char)c;
			}
		}
	}
	if (dn == dst) {
		if (dn >= eom) {
			errno = EMSGSIZE;
			return (-1);
		}
		*dn++ = '.';
	}
	if (dn >= eom) {
		errno = EMSGSIZE;
		return (-1);
	}
	*dn++ = '\0';
	return (dn - dst);
} /*2*/

/*
 * Skip over a compressed domain name. Return the size or -1.
 */
int
irc_dn_skipname(const unsigned char *ptr, const unsigned char *eom) {
  const unsigned char *saveptr = ptr;

  if (irc_ns_name_skip(&ptr, eom) == -1)
    return(-1);
  return(ptr - saveptr);
} /*2*/

/*
 * ns_name_skip(ptrptr, eom)
 *	Advance *ptrptr to skip over the compressed name it points at.
 * return:
 *	0 on success, -1 (with errno set) on failure.
 */
static int
irc_ns_name_skip(const unsigned char **ptrptr, const unsigned char *eom)
{
  const unsigned char *cp;
  unsigned int n;
  int l;

  cp = *ptrptr;

  while (cp < eom && (n = *cp++) != 0)
  {
    /* Check for indirection. */
    switch (n & NS_CMPRSFLGS)
    {
      case 0: /* normal case, n == len */
        cp += n;
        continue;
      case NS_TYPE_ELT: /* EDNS0 extended label */
        if ((l = labellen(cp - 1)) < 0)
        {
          errno = EMSGSIZE; /* XXX */
          return(-1);
        }

        cp += l;
        continue;
      case NS_CMPRSFLGS: /* indirection */
        cp++;
        break;
      default: /* illegal type */
        errno = EMSGSIZE;
        return(-1);
    }

    break;
  }

  if (cp > eom)
  {
    errno = EMSGSIZE;
    return (-1);
  }

  *ptrptr = cp;
  return(0);
} /*2*/

unsigned int
irc_ns_get16(const unsigned char *src)
{
  unsigned int dst;

  IRC_NS_GET16(dst, src);
  return(dst);
}

unsigned long
irc_ns_get32(const unsigned char *src)
{
  unsigned long dst;

  IRC_NS_GET32(dst, src);
  return(dst);
}

void
irc_ns_put16(unsigned int src, unsigned char *dst)
{
  IRC_NS_PUT16(src, dst);
}

void
irc_ns_put32(unsigned long src, unsigned char *dst)
{
  IRC_NS_PUT32(src, dst);
}

/* From ns_name.c */

/*
 * special(ch)
 *      Thinking in noninternationalized USASCII (per the DNS spec),
 *      is this characted special ("in need of quoting") ?
 * return:
 *      boolean.
 */
static int
special(int ch)
{
  switch (ch)
  {
    case 0x22: /* '"'  */
    case 0x2E: /* '.'  */
    case 0x3B: /* ';'  */
    case 0x5C: /* '\\' */
    case 0x28: /* '('  */
    case 0x29: /* ')'  */
    /* Special modifiers in zone files. */
    case 0x40: /* '@'  */
    case 0x24: /* '$'  */
      return(1);
    default:
      return(0);
  }
} /*2*/

static int
labellen(const unsigned char *lp)
{                               
  int bitlen;
  unsigned char l = *lp;

  if ((l & NS_CMPRSFLGS) == NS_CMPRSFLGS)
  {
    /* should be avoided by the caller */
    return(-1);
  }

  if ((l & NS_CMPRSFLGS) == NS_TYPE_ELT)
  {
    if (l == DNS_LABELTYPE_BITSTRING)
    {
      if ((bitlen = *(lp + 1)) == 0)
        bitlen = 256;
      return((bitlen + 7 ) / 8 + 1);
    }

    return(-1); /* unknwon ELT */
  }

  return(l);
} /*2*/


/*
 * printable(ch)
 *      Thinking in noninternationalized USASCII (per the DNS spec),
 *      is this character visible and not a space when printed ?
 * return:
 *      boolean.
 */
static int
printable(int ch)
{
  return(ch > 0x20 && ch < 0x7f);
} /*2*/

static int
irc_decode_bitstring(const unsigned char **cpp, char *dn, const char *eom)
{
        const unsigned char *cp = *cpp;
        char *beg = dn, tc;
        int b, blen, plen;

        if ((blen = (*cp & 0xff)) == 0)
                blen = 256;
        plen = (blen + 3) / 4;
        plen += sizeof("\\[x/]") + (blen > 99 ? 3 : (blen > 9) ? 2 : 1);
        if (dn + plen >= eom)
                return(-1);

        cp++;
        dn += sprintf(dn, "\\[x");
        for (b = blen; b > 7; b -= 8, cp++)
                dn += sprintf(dn, "%02x", *cp & 0xff);
        if (b > 4) {
                tc = *cp++;
                dn += sprintf(dn, "%02x", tc & (0xff << (8 - b)));
        } else if (b > 0) {
                tc = *cp++;
               dn += sprintf(dn, "%1x",
                               ((tc >> 4) & 0x0f) & (0x0f << (4 - b)));
        }
        dn += sprintf(dn, "/%d]", blen);

        *cpp = cp;
        return(dn - beg);
} /*2*/

/*
 * irc_ns_name_pton(src, dst, dstsiz)
 *  Convert a ascii string into an encoded domain name as per RFC1035.
 * return:
 *  -1 if it fails
 *  1 if string was fully qualified
 *  0 is string was not fully qualified
 * notes:
 *  Enforces label and domain length limits.
 */
static int
irc_ns_name_pton(const char *src, unsigned char *dst, size_t dstsiz)
{
  unsigned char *label, *bp, *eom;
  char *cp;
  int c, n, escaped, e = 0;

  escaped = 0;
  bp = dst;
  eom = dst + dstsiz;
  label = bp++;


  while ((c = *src++) != 0) {
    if (escaped) {
      if (c == '[') { /* start a bit string label */
        if ((cp = strchr(src, ']')) == NULL) {
          errno = EINVAL; /* ??? */
          return(-1);
        }
        if ((e = irc_encode_bitsring(&src,
               cp + 2,
               &label,
               &bp,
               eom))
            != 0) {
          errno = e;
          return(-1);
        }
        escaped = 0;
        label = bp++;
        if ((c = *src++) == 0)
          goto done;
        else if (c != '.') {
          errno = EINVAL;
          return(-1);
        }
        continue;
      }
      else if ((cp = strchr(digits, c)) != NULL) {
        n = (cp - digits) * 100;
        if ((c = *src++) == 0 ||
            (cp = strchr(digits, c)) == NULL) {
          errno = EMSGSIZE;
          return (-1);
        }
        n += (cp - digits) * 10;
        if ((c = *src++) == 0 ||
            (cp = strchr(digits, c)) == NULL) {
          errno = EMSGSIZE;
          return (-1);
        }
        n += (cp - digits);
        if (n > 255) {
          errno = EMSGSIZE;
          return (-1);
        }
        c = n;
      }
      escaped = 0;
    } else if (c == '\\') {
      escaped = 1;
      continue;
    } else if (c == '.') {
      c = (bp - label - 1);
      if ((c & NS_CMPRSFLGS) != 0) {  /* Label too big. */
        errno = EMSGSIZE;
        return (-1);
      }
      if (label >= eom) {
        errno = EMSGSIZE;
        return (-1);
      }
      *label = c;
      /* Fully qualified ? */
      if (*src == '\0') {
        if (c != 0) {
          if (bp >= eom) {
            errno = EMSGSIZE;
            return (-1);
          }
          *bp++ = '\0';
        }
        if ((bp - dst) > NS_MAXCDNAME) {
          errno = EMSGSIZE;
          return (-1);
        }
        return (1);
      }
      if (c == 0 || *src == '.') {
        errno = EMSGSIZE;
        return (-1);
      }
      label = bp++;
      continue;
    }
    if (bp >= eom) {
      errno = EMSGSIZE;
      return (-1);
    }
    *bp++ = (unsigned char)c;
  }
  c = (bp - label - 1);
  if ((c & NS_CMPRSFLGS) != 0) {    /* Label too big. */
    errno = EMSGSIZE;
    return (-1);
  }
  done:
  if (label >= eom) {
    errno = EMSGSIZE;
    return (-1);
  }
  *label = c;
  if (c != 0) {
    if (bp >= eom) {
      errno = EMSGSIZE;
      return (-1);
    }
    *bp++ = 0;
  }

  if ((bp - dst) > NS_MAXCDNAME)
  { /* src too big */
    errno = EMSGSIZE;
    return (-1);
  }

  return (0);
} /*2*/

/*
 * irc_ns_name_pack(src, dst, dstsiz, dnptrs, lastdnptr)
 *  Pack domain name 'domain' into 'comp_dn'.
 * return:
 *  Size of the compressed name, or -1.
 * notes:
 *  'dnptrs' is an array of pointers to previous compressed names.
 *  dnptrs[0] is a pointer to the beginning of the message. The array
 *  ends with NULL.
 *  'lastdnptr' is a pointer to the end of the array pointed to
 *  by 'dnptrs'.
 * Side effects:
 *  The list of pointers in dnptrs is updated for labels inserted into
 *  the message as we compress the name.  If 'dnptr' is NULL, we don't
 *  try to compress names. If 'lastdnptr' is NULL, we don't update the
 *  list.
 */
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
  if (dnptrs != NULL) {
    if ((msg = *dnptrs++) != NULL) {
      for (cpp = dnptrs; *cpp != NULL; cpp++)
        (void)NULL;
      lpp = cpp;  /* end of list to search */
    }
  } else
    msg = NULL;

  /* make sure the domain we are about to add is legal */
  l = 0;
  do {
    int l0;

    n = *srcp;
    if ((n & NS_CMPRSFLGS) == NS_CMPRSFLGS) {
      errno = EMSGSIZE;
      return (-1);
    }
    if ((l0 = labellen(srcp)) < 0) {
      errno = EINVAL;
      return(-1);
    }
    l += l0 + 1;
    if (l > NS_MAXCDNAME) {
      errno = EMSGSIZE;
      return (-1);
    }
    srcp += l0 + 1;
  } while (n != 0);

  /* from here on we need to reset compression pointer array on error */
  srcp = src;
  do {
    /* Look to see if we can use pointers. */
    n = *srcp;
    if (n != 0 && msg != NULL) {
      l = irc_dn_find(srcp, msg, (const unsigned char * const *)dnptrs,
            (const unsigned char * const *)lpp);
      if (l >= 0) {
        if (dstp + 1 >= eob) {
          goto cleanup;
        }
        *dstp++ = (l >> 8) | NS_CMPRSFLGS;
        *dstp++ = l % 256;
        return (dstp - dst);
      }
      /* Not found, save it. */
      if (lastdnptr != NULL && cpp < lastdnptr - 1 &&
          (dstp - msg) < 0x4000 && first) {
        *cpp++ = dstp;
        *cpp = NULL;
        first = 0;
      }
    }
    /* copy label to buffer */
    if ((n & NS_CMPRSFLGS) == NS_CMPRSFLGS) {
      /* Should not happen. */
      goto cleanup;
    }
    n = labellen(srcp);
    if (dstp + 1 + n >= eob) {
      goto cleanup;
    }
    memcpy(dstp, srcp, n + 1);
    srcp += n + 1;
    dstp += n + 1;
  } while (n != 0);

  if (dstp > eob) {
cleanup:
    if (msg != NULL)
      *lpp = NULL;
    errno = EMSGSIZE;
    return (-1);
  }
  return(dstp - dst);
} /*2*/

static int
irc_ns_name_compress(const char *src, unsigned char *dst, size_t dstsiz,
                     const unsigned char **dnptrs, const unsigned char **lastdnptr)
{
  unsigned char tmp[NS_MAXCDNAME];

  if (irc_ns_name_pton(src, tmp, sizeof tmp) == -1)
    return(-1);
  return(irc_ns_name_pack(tmp, dst, dstsiz, dnptrs, lastdnptr));
}

static int
irc_encode_bitsring(const char **bp, const char *end, unsigned char **labelp,
                    unsigned char **dst, const unsigned char *eom)
{
  int afterslash = 0;
  const char *cp = *bp;
  unsigned char *tp;
  char c;
  const char *beg_blen;
  char *end_blen = NULL;
  int value = 0, count = 0, tbcount = 0, blen = 0;

  beg_blen = end_blen = NULL;

  /* a bitstring must contain at least 2 characters */
  if (end - cp < 2)
    return(EINVAL);

  /* XXX: currently, only hex strings are supported */
  if (*cp++ != 'x')
    return(EINVAL);
  if (!isxdigit((*cp) & 0xff)) /* reject '\[x/BLEN]' */
    return(EINVAL);

  for (tp = *dst + 1; cp < end && tp < eom; cp++) {
    switch((c = *cp)) {
    case ']': /* end of the bitstring */
      if (afterslash) {
        if (beg_blen == NULL)
          return(EINVAL);
        blen = (int)strtol(beg_blen, &end_blen, 10);
        if (*end_blen != ']')
          return(EINVAL);
      }
      if (count)
        *tp++ = ((value << 4) & 0xff);
      cp++; /* skip ']' */
      goto done;
    case '/':
      afterslash = 1;
      break;
    default:
      if (afterslash) {
        if (!isdigit(c&0xff))
          return(EINVAL);
        if (beg_blen == NULL) {

          if (c == '0') {
            /* blen never begings with 0 */
            return(EINVAL);
          }
          beg_blen = cp;
        }
      } else {
        if (!isxdigit(c&0xff))
          return(EINVAL);
        value <<= 4;
        value += digitvalue[(int)c];
        count += 4;
        tbcount += 4;
        if (tbcount > 256)
          return(EINVAL);
        if (count == 8) {
          *tp++ = value;
          count = 0;
        }
      }
      break;
    }
  }
  done:
  if (cp >= end || tp >= eom)
    return(EMSGSIZE);

  /*
   * bit length validation:
   * If a <length> is present, the number of digits in the <bit-data>
   * MUST be just sufficient to contain the number of bits specified
   * by the <length>. If there are insignificant bits in a final
   * hexadecimal or octal digit, they MUST be zero.
   * RFC 2673, Section 3.2.
   */
  if (blen > 0) {
    int traillen;

    if (((blen + 3) & ~3) != tbcount)
      return(EINVAL);
    traillen = tbcount - blen; /* between 0 and 3 */
    if (((value << (8 - traillen)) & 0xff) != 0)
      return(EINVAL);
  }
  else
    blen = tbcount;
  if (blen == 256)
    blen = 0;

  /* encode the type and the significant bit fields */
  **labelp = DNS_LABELTYPE_BITSTRING;
  **dst = blen;

  *bp = cp;
  *dst = tp;

  return(0);
} /*2*/

/*
 * dn_find(domain, msg, dnptrs, lastdnptr)
 *  Search for the counted-label name in an array of compressed names.
 * return:
 *  offset from msg if found, or -1.
 * notes:
 *  dnptrs is the pointer to the first name on the list,
 *  not the pointer to the start of the message.
 */
static int
irc_dn_find(const unsigned char *domain, const unsigned char *msg,
            const unsigned char * const *dnptrs,
            const unsigned char * const *lastdnptr)
{
  const unsigned char *dn, *cp, *sp;
  const unsigned char * const *cpp;
  unsigned int n;

  for (cpp = dnptrs; cpp < lastdnptr; cpp++)
  {
    sp = *cpp;
    /*
     * terminate search on:
     * root label
     * compression pointer
     * unusable offset
     */
    while (*sp != 0 && (*sp & NS_CMPRSFLGS) == 0 &&
           (sp - msg) < 0x4000) {
      dn = domain;
      cp = sp;
      while ((n = *cp++) != 0) {
        /*
         * check for indirection
         */
        switch (n & NS_CMPRSFLGS) {
        case 0:   /* normal case, n == len */
          n = labellen(cp - 1); /* XXX */

          if (n != *dn++)
            goto next;

          for ((void)NULL; n > 0; n--)
            if (mklower(*dn++) !=
                mklower(*cp++))
              goto next;
          /* Is next root for both ? */
          if (*dn == '\0' && *cp == '\0')
            return (sp - msg);
          if (*dn)
            continue;
          goto next;
        case NS_CMPRSFLGS:  /* indirection */
          cp = msg + (((n & 0x3f) << 8) | *cp);
          break;

        default:  /* illegal type */
          errno = EMSGSIZE;
          return (-1);
        }
      }
 next: ;
      sp += *sp + 1;
    }
  }
  errno = ENOENT;
  return (-1);
} /*2*/

/*
 *  *  Thinking in noninternationalized USASCII (per the DNS spec),
 *   *  convert this character to lower case if it's upper case.
 *    */
static int
mklower(int ch) 
{
  if (ch >= 0x41 && ch <= 0x5A)
    return(ch + 0x20);

  return(ch);
} /*2*/

/* From resolv/mkquery.c */

/*
 * Form all types of queries.
 * Returns the size of the result or -1.
 */
int
irc_res_mkquery(
	     const char *dname,		/* domain name */
	     int class, int type,	/* class and type of query */
	     unsigned char *buf,		/* buffer to put query */
	     int buflen)		/* size of buffer */
{
	HEADER *hp;
	unsigned char *cp;
	int n;
	const unsigned char *dnptrs[20], **dpp, **lastdnptr;

	/*
	 * Initialize header fields.
	 */
	if ((buf == NULL) || (buflen < HFIXEDSZ))
		return (-1);
	memset(buf, 0, HFIXEDSZ);
	hp = (HEADER *) buf;

	hp->id = 0;
	hp->opcode = QUERY;
	hp->rd = 1;		/* recurse */
	hp->rcode = NO_ERRORS;
	cp = buf + HFIXEDSZ;
	buflen -= HFIXEDSZ;
	dpp = dnptrs;
	*dpp++ = buf;
	*dpp++ = NULL;
	lastdnptr = dnptrs + sizeof dnptrs / sizeof dnptrs[0];

	if ((buflen -= QFIXEDSZ) < 0)
	  return (-1);
	if ((n = irc_ns_name_compress(dname, cp, buflen, dnptrs,
                                                         lastdnptr)) < 0)
	  return (-1);

	cp += n;
	buflen -= n;
	IRC_NS_PUT16(type, cp);
	IRC_NS_PUT16(class, cp);
	hp->qdcount = htons(1);

	return (cp - buf);
}
