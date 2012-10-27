/************************************************************************
 *   IRC - Internet Relay Chat, src/match.c
 *   Copyright (C) 1990 Jarkko Oikarinen
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id$
 *
 */

#include "stdinc.h"
#include "irc_string.h"
#include "client.h"
#include "ircd.h"

/* Fix "statement not reached" warnings on Sun WorkShop C */
#ifdef __SUNPRO_C
#   pragma error_messages(off, E_STATEMENT_NOT_REACHED)
#endif

/* match()
 * 
 *  Compare if a given string (name) matches the given
 *  mask (which can contain wild cards: '*' - match any
 *  number of chars, '?' - match any single character.
 *
 *      return  1, if match
 *              0, if no match
 *
 *  Originally by Douglas A Lewis (dalewis@acsu.buffalo.edu)
 */
int
match(const char *mask, const char *name)
{
  const unsigned char* m = (const unsigned char *) mask;
  const unsigned char* n = (const unsigned char *) name;
  const unsigned char* ma = NULL;
  const unsigned char* na = (const unsigned char *) name;

  assert(mask != NULL);
  assert(name != NULL);

  while (1)
  {
    if (*m == '*')
    {
      /*
       * XXX - shouldn't need to spin here, the mask should have been
       * collapsed before match is called
       */
      while (*m == '*')
        m++;
      ma = m;
      na = n;
    }

    if (!*m)
    {
      if (!*n)
        return 1;
      if (!ma)
        return 0;
      for (m--; (m > (const unsigned char*) mask) && (*m == '?'); m--)
        ;
      if (*m == '*')
        return 1;
      m = ma;
      n = ++na;
    }
    else if (!*n)
    {
      /*
       * XXX - shouldn't need to spin here, the mask should have been
       * collapsed before match is called
       */
      while (*m == '*')
        m++;
      return (*m == 0);
    }

    if (ToLower(*m) != ToLower(*n) && *m != '?' && (*m != '#' || !IsDigit(*n)))
    {
      if (!ma)
        return 0;
      m = ma;
      n = ++na;
    }
    else
      m++, n++;
  }

  return 0;
}

/* match_esc()
 *
 * The match() function with support for escaping characters such
 * as '*' and '?'
 */
int
match_esc(const char *mask, const char *name)
{
  const unsigned char *m = (const unsigned char *) mask;
  const unsigned char *n = (const unsigned char *) name;
  const unsigned char *ma = NULL;
  const unsigned char *na = (const unsigned char *) name;

  assert(mask != NULL);
  assert(name != NULL);

  while (1)
  {
    if (*m == '*')
    {
      /*
       * XXX - shouldn't need to spin here, the mask should have been
       * collapsed before match is called
       */
      while (*m == '*')
        m++;
      ma = m;
      na = n;
    }

    if (!*m)
    {
      if (!*n)
        return 1;
      if (!ma)
        return 0;
      for (m--; (m > (const unsigned char*) mask) && (*m == '?'); m--)
        ;
      if (*m == '*')
        return 1;
      m = ma;
      n = ++na;
    }
    else if (!*n)
    {
      /*
       * XXX - shouldn't need to spin here, the mask should have been
       * collapsed before match is called
       */
      while (*m == '*')
        m++;
      return (*m == 0);
    }

    if (*m != '?' && (*m != '#' || IsDigit(*n)))
    {
      if (*m == '\\')
	if (!*++m)
	  return 0;
      if (ToLower(*m) != ToLower(*n))
      {
        if (!ma)
          return 0;
        m = ma;
        n = ++na;
      }
      else
        m++, n++;
    }
    else
      m++, n++;
  }

  return 0;
}

/* match_chan()
 *
 * The match_esc() function doing channel prefix auto-escape,
 * ie. mask: #blah*blah is seen like \#blah*blah
 */
int
match_chan(const char *mask, const char *name)
{
  if (*mask == '#')
  {
    if (*name != '#')
      return 0;
    ++name, ++mask;
  }

  return match_esc(mask, name);
}

/* collapse()
 *
 * collapses a string containing multiple *'s.
 */
char *
collapse(char *pattern)
{
  char *p = pattern, *po = pattern;
  char c;

  if (p == NULL)
    return NULL;
 
  while ((c = *p++))
  {
    if (c != '*')
      *po++ = c;
    else if (*p != '*')
      *po++ = '*';
  }

  *po = 0;

  return pattern;
}

/* collapse_esc()
 *
 * The collapse() function with support for escaping characters
 */
char *
collapse_esc(char *pattern)
{
  char *p = pattern, *po = pattern;
  char c;

  if (p == NULL)
    return NULL;

  while ((c = *p++))
  {
    if (c != '*')
    {
      *po++ = c;
      if (c == '\\' && *p)
        *po++ = *p++;
    }
    else if (*p != '*')
      *po++ = '*';
  }

  *po = 0;

  return pattern;
}

/*
 * irccmp - case insensitive comparison of two 0 terminated strings.
 *
 *      returns  0, if s1 equal to s2
 *               1, if not
 */
int
irccmp(const char *s1, const char *s2)
{
  const unsigned char *str1 = (const unsigned char *) s1;
  const unsigned char *str2 = (const unsigned char *) s2;

  assert(s1 != NULL);
  assert(s2 != NULL);
  
  while (ToUpper(*str1) == ToUpper(*str2))
  {
    if (*str1 == '\0')
      return 0;
    str1++;
    str2++;
  }

  return 1;
}

int
ircncmp(const char* s1, const char *s2, size_t n)
{
  const unsigned char *str1 = (const unsigned char *) s1;
  const unsigned char *str2 = (const unsigned char *) s2;
  int res;

  assert(s1 != NULL);
  assert(s2 != NULL);

  while ((res = ToUpper(*str1) - ToUpper(*str2)) == 0)
  {
    str1++, str2++, n--;
    if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
      return 0;
  }
  return res;
}

const unsigned char ToLowerTab[] = { 
  0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa,
  0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14,
  0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f,
  ' ', '!', '"', '#', '$', '%', '&', 0x27, '(', ')',
  '*', '+', ',', '-', '.', '/',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  ':', ';', '<', '=', '>', '?',
  '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
  '_',
  '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
  0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
  0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99,
  0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
  0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
  0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
  0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9,
  0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
  0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
  0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};

const unsigned char ToUpperTab[] = { 
  0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa,
  0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14,
  0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
  0x1e, 0x1f,
  ' ', '!', '"', '#', '$', '%', '&', 0x27, '(', ')',
  '*', '+', ',', '-', '.', '/',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  ':', ';', '<', '=', '>', '?',
  '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
  'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^',
  0x5f,
  '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
  'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^',
  0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
  0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99,
  0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
  0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
  0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9,
  0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
  0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9,
  0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
  0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
  0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff 
};

/*
 * CharAttrs table
 *
 * NOTE: RFC 1459 sez: anything but a ^G, comma, or space is allowed
 * for channel names
 */
const unsigned int CharAttrs[] = {
/* 0  */     CNTRL_C,
/* 1  */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 2  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 3  */     CNTRL_C|CHAN_C|NONEOS_C,
/* 4  */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 5  */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 6  */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 7 BEL */  CNTRL_C|NONEOS_C,
/* 8  \b */  CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 9  \t */  CNTRL_C|SPACE_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 10 \n */  CNTRL_C|SPACE_C|CHAN_C|VCHAN_C|NONEOS_C|EOL_C,
/* 11 \v */  CNTRL_C|SPACE_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 12 \f */  CNTRL_C|SPACE_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 13 \r */  CNTRL_C|SPACE_C|CHAN_C|VCHAN_C|NONEOS_C|EOL_C,
/* 14 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 15 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 16 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 17 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 18 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 19 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 20 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 21 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 22 */     CNTRL_C|CHAN_C|NONEOS_C,
/* 23 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 24 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 25 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 26 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 27 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 28 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 29 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 30 */     CNTRL_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 31 */     CNTRL_C|CHAN_C|NONEOS_C,
/* SP */     PRINT_C|SPACE_C,
/* ! */      PRINT_C|KWILD_C|CHAN_C|VCHAN_C|NONEOS_C,
/* " */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* # */      PRINT_C|KWILD_C|MWILD_C|CHANPFX_C|CHAN_C|VCHAN_C|NONEOS_C,
/* $ */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* % */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* & */      PRINT_C|CHANPFX_C|CHAN_C|VCHAN_C|NONEOS_C,
/* ' */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* ( */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* ) */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* * */      PRINT_C|KWILD_C|MWILD_C|CHAN_C|VCHAN_C|NONEOS_C|SERV_C,
/* + */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* , */      PRINT_C|NONEOS_C,
/* - */      PRINT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* . */      PRINT_C|KWILD_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C|SERV_C,
/* / */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* 0 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 1 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 2 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 3 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 4 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 5 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 6 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 7 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 8 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* 9 */      PRINT_C|DIGIT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* : */      PRINT_C|KWILD_C|CHAN_C|VCHAN_C|NONEOS_C|HOST_C,
/* ; */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* < */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* = */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* > */      PRINT_C|CHAN_C|VCHAN_C|NONEOS_C,
/* ? */      PRINT_C|KWILD_C|MWILD_C|CHAN_C|VCHAN_C|NONEOS_C,
/* @ */      PRINT_C|KWILD_C|CHAN_C|VCHAN_C|NONEOS_C,
/* A */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* B */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* C */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* D */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* E */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* F */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* G */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* H */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* I */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* J */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* K */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* L */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* M */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* N */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* O */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* P */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* Q */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* R */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* S */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* T */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* U */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* V */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* W */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* X */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* Y */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* Z */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* [ */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* \ */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* ] */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* ^ */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* _ */      PRINT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* ` */      PRINT_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* a */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* b */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* c */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* d */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* e */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* f */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* g */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* h */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* i */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* j */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* k */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* l */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* m */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* n */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* o */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* p */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* q */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* r */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* s */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* t */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* u */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* v */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* w */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* x */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* y */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* z */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C|HOST_C,
/* { */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* | */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* } */      PRINT_C|ALPHA_C|NICK_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* ~ */      PRINT_C|ALPHA_C|CHAN_C|VCHAN_C|NONEOS_C|USER_C,
/* del  */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x80 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x81 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x82 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x83 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x84 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x85 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x86 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x87 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x88 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x89 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x8A */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x8B */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x8C */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x8D */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x8E */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x8F */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x90 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x91 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x92 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x93 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x94 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x95 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x96 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x97 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x98 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x99 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x9A */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x9B */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x9C */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x9D */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x9E */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0x9F */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA0 */   CHAN_C|NONEOS_C,
/* 0xA1 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA2 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA3 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA4 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA5 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA6 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA7 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA8 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xA9 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xAA */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xAB */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xAC */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xAD */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xAE */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xAF */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB0 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB1 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB2 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB3 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB4 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB5 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB6 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB7 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB8 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xB9 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xBA */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xBB */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xBC */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xBD */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xBE */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xBF */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC0 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC1 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC2 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC3 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC4 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC5 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC6 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC7 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC8 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xC9 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xCA */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xCB */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xCC */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xCD */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xCE */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xCF */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD0 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD1 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD2 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD3 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD4 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD5 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD6 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD7 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD8 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xD9 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xDA */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xDB */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xDC */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xDD */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xDE */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xDF */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE0 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE1 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE2 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE3 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE4 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE5 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE6 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE7 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE8 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xE9 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xEA */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xEB */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xEC */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xED */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xEE */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xEF */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF0 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF1 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF2 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF3 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF4 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF5 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF6 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF7 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF8 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xF9 */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xFA */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xFB */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xFC */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xFD */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xFE */   CHAN_C|VCHAN_C|NONEOS_C,
/* 0xFF */   CHAN_C|VCHAN_C|NONEOS_C
};
