/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2024 ircd-hybrid development team
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

/*! \file irc_string.h
 * \brief A header for the ircd string functions.
 */

#ifndef INCLUDED_irc_string_h
#define INCLUDED_irc_string_h

#include "config.h"


extern bool has_wildcards(const char *);
extern int match(const char *, const char *);

extern unsigned int token_vector(char *, char, char *[], unsigned int);

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

extern const char *stripws(char *);

#define EmptyString(x) (!(x) || (*(x) == '\0'))

/*
 * character macros
 */
extern const unsigned char ToLowerTab[];
#define ToLower(c) (ToLowerTab[(unsigned char)(c)])

extern const unsigned char ToUpperTab[];
#define ToUpper(c) (ToUpperTab[(unsigned char)(c)])

extern const unsigned int CharAttrs[];

enum
{
  PRINT_C   = 1 <<  0,
  CNTRL_C   = 1 <<  1,
  ALPHA_C   = 1 <<  2,
  PUNCT_C   = 1 <<  3,
  DIGIT_C   = 1 <<  4,
  SPACE_C   = 1 <<  5,
  NICK_C    = 1 <<  6,
  CHAN_C    = 1 <<  7,
  KWILD_C   = 1 <<  8,
  CHANPFX_C = 1 <<  9,
  USER_C    = 1 << 10,
  HOST_C    = 1 << 11,
  NONEOS_C  = 1 << 12,
  SERV_C    = 1 << 13,
  EOL_C     = 1 << 14,
  MWILD_C   = 1 << 15,
  VCHAN_C   = 1 << 16,
  USER2_C   = 1 << 17,
};

#define IsVisibleChanChar(c)   (CharAttrs[(unsigned char)(c)] & VCHAN_C)
#define IsHostChar(c)   (CharAttrs[(unsigned char)(c)] & HOST_C)
#define IsUserChar(c)   (CharAttrs[(unsigned char)(c)] & USER_C)
#define IsUser2Char(c)  (CharAttrs[(unsigned char)(c)] & USER2_C)
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
#endif  /* INCLUDED_irc_string_h */
