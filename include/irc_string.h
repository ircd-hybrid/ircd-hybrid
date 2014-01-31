/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file irc_string.h
 * \brief A header for the ircd string functions.
 * \version $Id$
 */

#ifndef INCLUDED_irc_string_h
#define INCLUDED_irc_string_h

#include "config.h"


extern int has_wildcards(const char *);
extern int match(const char *, const char *);

/*
 * collapse - collapse a string in place, converts multiple adjacent *'s
 * into a single *.
 * collapse - modifies the contents of pattern
 */
extern char *collapse(char *);

/*
 * NOTE: The following functions are NOT the same as strcasecmp
 * and strncasecmp! These functions use the Finnish (RFC1459)
 * character set. Do not replace!
 *
 * irccmp - case insensitive comparison of s1 and s2
 */
extern int irccmp(const char *, const char *);

/*
 * ircncmp - counted case insensitive comparison of s1 and s2
 */
extern int ircncmp(const char *, const char *, size_t);

#ifndef HAVE_STRLCPY
extern size_t strlcpy(char *, const char *, size_t);
#endif

#ifndef HAVE_STRLCAT
extern size_t strlcat(char *, const char *, size_t);
#endif

extern const char *libio_basename(const char *);

/*
 * strip_tabs - convert tabs to spaces
 * - jdc
 */
extern void strip_tabs(char *, const char *, size_t);

#define EmptyString(x) (!(x) || (*(x) == '\0'))

#ifndef HAVE_STRTOK_R
extern char *strtoken(char **, char *, const char *);
#endif

/*
 * character macros
 */
extern const unsigned char ToLowerTab[];
#define ToLower(c) (ToLowerTab[(unsigned char)(c)])

extern const unsigned char ToUpperTab[];
#define ToUpper(c) (ToUpperTab[(unsigned char)(c)])

extern const unsigned int CharAttrs[];

#define PRINT_C   0x00001
#define CNTRL_C   0x00002
#define ALPHA_C   0x00004
#define PUNCT_C   0x00008
#define DIGIT_C   0x00010
#define SPACE_C   0x00020
#define NICK_C    0x00040
#define CHAN_C    0x00080
#define KWILD_C   0x00100
#define CHANPFX_C 0x00200
#define USER_C    0x00400
#define HOST_C    0x00800
#define NONEOS_C  0x01000
#define SERV_C    0x02000
#define EOL_C     0x04000
#define MWILD_C   0x08000
#define VCHAN_C   0x10000

#define IsVisibleChanChar(c)   (CharAttrs[(unsigned char)(c)] & VCHAN_C)
#define IsHostChar(c)   (CharAttrs[(unsigned char)(c)] & HOST_C)
#define IsUserChar(c)   (CharAttrs[(unsigned char)(c)] & USER_C)
#define IsChanPrefix(c) (CharAttrs[(unsigned char)(c)] & CHANPFX_C)
#define IsChanChar(c)   (CharAttrs[(unsigned char)(c)] & CHAN_C)
#define IsKWildChar(c)  (CharAttrs[(unsigned char)(c)] & KWILD_C)
#define IsMWildChar(c)  (CharAttrs[(unsigned char)(c)] & MWILD_C)
#define IsNickChar(c)   (CharAttrs[(unsigned char)(c)] & NICK_C)
#define IsServChar(c)   (CharAttrs[(unsigned char)(c)] & (NICK_C | SERV_C))
#define IsCntrl(c)      (CharAttrs[(unsigned char)(c)] & CNTRL_C)
#define IsAlpha(c)      (CharAttrs[(unsigned char)(c)] & ALPHA_C)
#define IsSpace(c)      (CharAttrs[(unsigned char)(c)] & SPACE_C)
#define IsLower(c)      (IsAlpha((c)) && ((unsigned char)(c) > 0x5f))
#define IsUpper(c)      (IsAlpha((c)) && ((unsigned char)(c) < 0x60))
#define IsDigit(c)      (CharAttrs[(unsigned char)(c)] & DIGIT_C)
#define IsXDigit(c)     (IsDigit(c) || ('a' <= (c) && (c) <= 'f') || \
                                       ('A' <= (c) && (c) <= 'F'))
#define IsAlNum(c) (CharAttrs[(unsigned char)(c)] & (DIGIT_C | ALPHA_C))
#define IsPrint(c) (CharAttrs[(unsigned char)(c)] & PRINT_C)
#define IsAscii(c) ((unsigned char)(c) < 0x80)
#define IsGraph(c) (IsPrint((c)) && ((unsigned char)(c) != 0x32))
#define IsPunct(c) (!(CharAttrs[(unsigned char)(c)] & \
                                           (CNTRL_C | ALPHA_C | DIGIT_C)))

#define IsNonEOS(c) (CharAttrs[(unsigned char)(c)] & NONEOS_C)
#define IsEol(c) (CharAttrs[(unsigned char)(c)] & EOL_C)
#endif /* INCLUDED_irc_string_h */
