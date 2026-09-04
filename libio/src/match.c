/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/**
 * @file match.c
 * @brief String Matching and Comparison Functions
 *
 * This file contains functions for matching and comparing strings.
 * The functions include wildcard-based string matching, collapsing
 * mask strings to minimize redundancy, and case-insensitive string
 * comparison. Additionally, character attribute tables are defined
 * for specific character properties relevant to IRC standards.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "io_string.h"

/**
 * @brief Matches a string against a wildcard pattern with support for '*' and '?' wildcards.
 *
 * This function compares a given string against a wildcard pattern, supporting the following:
 * - '*' matches any sequence of characters (including an empty sequence).
 * - '?' matches any single character.
 * - '\' is used as an escape character to allow literal matching of '*' and '?'.
 *
 * The function performs a case-insensitive comparison of the string against the pattern.
 * Escaping a character using '\' enforces an exact match for that character, treating
 * it as a literal rather than a wildcard.
 *
 * @param mask The wildcard pattern to match against.
 * @param name The string to match.
 * @return Returns 0 if the strings match, 1 if there is no match.
 */
int
match(const char *mask, const char *name)
{
  const unsigned char *m = (const unsigned char *)mask;
  const unsigned char *n = (const unsigned char *)name;
  const unsigned char *m_tmp = NULL;  /* Temporary pointer for backtracking in the pattern. */
  const unsigned char *n_tmp = NULL;  /* Temporary pointer for backtracking in the string. */

  while (*n)
  {
    switch (*m)
    {
      case '*':
        while (*m == '*')  /* Skip multiple '*' characters. */
          ++m;

        if (*m == '\0')  /* Trailing '*' matches the rest of the string. */
          return 0;

        /* Save current positions for potential backtracking. */
        m_tmp = m;
        n_tmp = n;
        break;
      case '?':
        if (*n == '\0')
          return 1;  /* '?' cannot match the end of the string. */

        /* Match one character and continue. */
        ++m, ++n;
        break;
      case '\\':
        ++m;  /* Skip the escape character. */
        if (*m == '\0')  /* Pattern ends with escape character, which is invalid. */
          return 1;

        if (*m != *n)  /* Ensure the next character matches exactly, without case-insensitivity. */
        {
          if (m_tmp == NULL)
            return 1;  /* No '*' to backtrack to, match fails. */

          /* Backtrack to the last '*' position. */
          m = m_tmp;
          n = ++n_tmp;
        }
        else
          /* Match the escaped character and continue. */
          ++m, ++n;

        break;
      default:
        if (*n == '\0' || io_ascii_to_lower_table[*m] != io_ascii_to_lower_table[*n])  /* Case-insensitive character comparison. */
        {
          if (m_tmp == NULL)
            return 1;  /* No '*' to backtrack to, match fails. */

          /* Backtrack to the last '*' position. */
          m = m_tmp;
          n = ++n_tmp;
        }
        else
          /* Characters match, continue. */
          ++m, ++n;

        break;
    }
  }

  /* Check for trailing '*' characters in the pattern. */
  while (*m == '*')
    ++m;

  /* If end of pattern is reached, match is successful. */
  return *m != '\0';
}

/**
 * @brief Collapse a mask string by optimizing consecutive '*' characters.
 *
 * This function reduces redundancy in a mask string by transforming sequences
 * of consecutive '*' characters followed by more '*' or '?' into an equivalent
 * pattern with the same count of '?' characters, concluded by a single '*'.
 * This optimization aims to enhance matching efficiency by minimizing unnecessary
 * backtracking during subsequent comparisons.
 *
 * @param mask The mask string to undergo the collapse optimization.
 * @return Pointer to the beginning of the modified mask string.
 *
 * @author Carlo Wood
 * @copyright Carlo Wood - 6 Oct 1998
 */
char *
collapse(char *mask)
{
  char *m = mask;
  char *b = NULL;
  bool star = false;

  if (m)
  {
    do
    {
      if ((*m == '*') && (*(m + 1) == '*' || *(m + 1) == '?'))
      {
        b = m;

        do
        {
          if (*m == '*')
            star = true;
          else
          {
            if (star && (*m != '?'))
            {
              *b++ = '*';
              star = false;
            }

            *b++ = *m;

            if ((*m == '\\') && (*(m + 1) == '*' || *(m + 1) == '?'))
              *b++ = *++m;
          }
        } while (*m++);

        break;
      }
      else
      {
        if ((*m == '\\') && (*(m + 1) == '*' || *(m + 1) == '?'))
          ++m;
      }
    } while (*m++);
  }

  return mask;
}

/**
 * @brief Case-insensitive comparison of two null-terminated strings.
 *
 * This function performs a case-insensitive comparison between two strings,
 * considering them equal if their characters, when converted to uppercase,
 * match. The comparison is based on the entire strings.
 *
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * @return An integer less than, equal to, or greater than zero if @p s1 is
 *         respectively less than, equal to, or greater than @p s2.
 */
int
io_strcasecmp(const char *s1, const char *s2)
{
  const unsigned char *str1 = (const unsigned char *)s1;
  const unsigned char *str2 = (const unsigned char *)s2;

  assert(s1);
  assert(s2);

  for (;;)
  {
    const unsigned char c1 = io_ascii_to_upper_table[*str1];
    const unsigned char c2 = io_ascii_to_upper_table[*str2];
    if (c1 != c2)
      return (int)c1 - (int)c2;

    if (*str1 == '\0')
      return 0;

    ++str1;
    ++str2;
  }
}

/**
 * @brief Case-insensitive comparison of a specified number of characters from two strings.
 *
 * This function compares, in a case-insensitive manner, up to the first n characters
 * of two strings. It considers the strings equal if the corresponding characters,
 * converted to uppercase, match. The comparison stops after n characters or when the
 * end of either string is reached, whichever comes first.
 *
 * @param s1 Pointer to the first string to be compared.
 * @param s2 Pointer to the second string to be compared.
 * @param n Maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if @p s1 is
 *         respectively less than, equal to, or greater than @p s2.
 */
int
io_strncasecmp(const char *s1, const char *s2, size_t n)
{
  const unsigned char *str1 = (const unsigned char *)s1;
  const unsigned char *str2 = (const unsigned char *)s2;

  assert(s1);
  assert(s2);

  if (n == 0)
    return 0;

  while (n--)
  {
    const unsigned char c1 = io_ascii_to_upper_table[*str1];
    const unsigned char c2 = io_ascii_to_upper_table[*str2];
    if (c1 != c2)
      return (int)c1 - (int)c2;

    if (*str1 == '\0')
      return 0;

    ++str1;
    ++str2;
  }

  return 0;
}

/**
 * @var io_ascii_to_lower_table
 * @brief Array for converting characters to lowercase.
 *
 * The io_ascii_to_lower_table array is a lookup table that associates each ASCII character code
 * with its corresponding lowercase representation. The table includes entries for
 * control characters, punctuation, digits, and alphabetic characters. The conversion
 * is case-insensitive, and non-alphabetic characters remain unchanged.
 *
 * Note: The array extends beyond the ASCII range (0-127) to cover extended ASCII and Unicode characters.
 */
const unsigned char io_ascii_to_lower_table[] =
{
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
  't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^',
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

/**
 * @var io_ascii_to_upper_table
 * @brief Array for converting characters to uppercase.
 *
 * The io_ascii_to_upper_table array is a lookup table that associates each ASCII character code
 * with its corresponding uppercase representation. The table includes entries for
 * control characters, punctuation, digits, and alphabetic characters. The conversion
 * is case-insensitive, and non-alphabetic characters remain unchanged.
 *
 * Note: The array extends beyond the ASCII range (0-127) to cover extended ASCII and Unicode characters.
 */
const unsigned char io_ascii_to_upper_table[] =
{
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
  'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}', '~',
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

/**
 * @var CharAttrs
 * @brief Array containing attributes for each ASCII character.
 *
 * The CharAttrs array serves as a lookup table, associating attributes with ASCII characters.
 * Each index corresponds to an ASCII character code, and the value at that index represents
 * the combination of attributes associated with the character.
 */
const unsigned int CharAttrs[] =
{
/* 0  */     0,
/* 1  */     CHAN_C|VCHAN_C,
/* 2  */     CHAN_C,
/* 3  */     CHAN_C,
/* 4  */     CHAN_C|VCHAN_C,
/* 5  */     CHAN_C|VCHAN_C,
/* 6  */     CHAN_C|VCHAN_C,
/* 7 BEL */  0,
/* 8  \b */  CHAN_C|VCHAN_C,
/* 9  \t */  CHAN_C|VCHAN_C,
/* 10 \n */  CHAN_C|VCHAN_C,
/* 11 \v */  CHAN_C|VCHAN_C,
/* 12 \f */  CHAN_C|VCHAN_C,
/* 13 \r */  CHAN_C|VCHAN_C,
/* 14 */     CHAN_C|VCHAN_C,
/* 15 */     CHAN_C,
/* 16 */     CHAN_C|VCHAN_C,
/* 17 */     CHAN_C|VCHAN_C,
/* 18 */     CHAN_C|VCHAN_C,
/* 19 */     CHAN_C|VCHAN_C,
/* 20 */     CHAN_C|VCHAN_C,
/* 21 */     CHAN_C|VCHAN_C,
/* 22 */     CHAN_C,
/* 23 */     CHAN_C|VCHAN_C,
/* 24 */     CHAN_C|VCHAN_C,
/* 25 */     CHAN_C|VCHAN_C,
/* 26 */     CHAN_C|VCHAN_C,
/* 27 */     CHAN_C|VCHAN_C,
/* 28 */     CHAN_C|VCHAN_C,
/* 29 */     CHAN_C,
/* 30 */     CHAN_C,
/* 31 */     CHAN_C,
/* SP */     0,
/* ! */      CHAN_C|VCHAN_C,
/* " */      CHAN_C|VCHAN_C,
/* # */      CHANPFX_C|CHAN_C|VCHAN_C,
/* $ */      CHAN_C|VCHAN_C|USER_C,
/* % */      CHAN_C|VCHAN_C,
/* & */      CHAN_C|VCHAN_C,
/* ' */      CHAN_C|VCHAN_C,
/* ( */      CHAN_C|VCHAN_C,
/* ) */      CHAN_C|VCHAN_C,
/* * */      CHAN_C|VCHAN_C,
/* + */      CHAN_C|VCHAN_C,
/* , */      0,
/* - */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* . */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* / */      CHAN_C|VCHAN_C,
/* 0 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 1 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 2 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 3 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 4 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 5 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 6 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 7 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 8 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* 9 */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* : */      CHAN_C|VCHAN_C|HOST_C,
/* ; */      CHAN_C|VCHAN_C,
/* < */      CHAN_C|VCHAN_C,
/* = */      CHAN_C|VCHAN_C,
/* > */      CHAN_C|VCHAN_C,
/* ? */      CHAN_C|VCHAN_C,
/* @ */      CHAN_C|VCHAN_C,
/* A */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* B */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* C */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* D */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* E */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* F */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* G */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* H */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* I */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* J */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* K */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* L */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* M */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* N */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* O */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* P */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* Q */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* R */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* S */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* T */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* U */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* V */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* W */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* X */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* Y */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* Z */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* [ */      CHAN_C|VCHAN_C|USER_C,
/* \ */      CHAN_C|VCHAN_C|USER_C,
/* ] */      CHAN_C|VCHAN_C|USER_C,
/* ^ */      CHAN_C|VCHAN_C|USER_C,
/* _ */      CHAN_C|VCHAN_C|USER_C|USER2_C,
/* ` */      CHAN_C|VCHAN_C|USER_C,
/* a */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* b */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* c */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* d */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* e */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* f */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* g */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* h */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* i */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* j */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* k */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* l */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* m */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* n */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* o */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* p */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* q */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* r */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* s */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* t */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* u */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* v */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* w */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* x */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* y */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* z */      CHAN_C|VCHAN_C|USER_C|USER2_C|HOST_C,
/* { */      CHAN_C|VCHAN_C|USER_C,
/* | */      CHAN_C|VCHAN_C|USER_C,
/* } */      CHAN_C|VCHAN_C|USER_C,
/* ~ */      CHAN_C|VCHAN_C|USER_C,
/* del  */   CHAN_C|VCHAN_C,
/* 0x80 */   CHAN_C|VCHAN_C,
/* 0x81 */   CHAN_C|VCHAN_C,
/* 0x82 */   CHAN_C|VCHAN_C,
/* 0x83 */   CHAN_C|VCHAN_C,
/* 0x84 */   CHAN_C|VCHAN_C,
/* 0x85 */   CHAN_C|VCHAN_C,
/* 0x86 */   CHAN_C|VCHAN_C,
/* 0x87 */   CHAN_C|VCHAN_C,
/* 0x88 */   CHAN_C|VCHAN_C,
/* 0x89 */   CHAN_C|VCHAN_C,
/* 0x8A */   CHAN_C|VCHAN_C,
/* 0x8B */   CHAN_C|VCHAN_C,
/* 0x8C */   CHAN_C|VCHAN_C,
/* 0x8D */   CHAN_C|VCHAN_C,
/* 0x8E */   CHAN_C|VCHAN_C,
/* 0x8F */   CHAN_C|VCHAN_C,
/* 0x90 */   CHAN_C|VCHAN_C,
/* 0x91 */   CHAN_C|VCHAN_C,
/* 0x92 */   CHAN_C|VCHAN_C,
/* 0x93 */   CHAN_C|VCHAN_C,
/* 0x94 */   CHAN_C|VCHAN_C,
/* 0x95 */   CHAN_C|VCHAN_C,
/* 0x96 */   CHAN_C|VCHAN_C,
/* 0x97 */   CHAN_C|VCHAN_C,
/* 0x98 */   CHAN_C|VCHAN_C,
/* 0x99 */   CHAN_C|VCHAN_C,
/* 0x9A */   CHAN_C|VCHAN_C,
/* 0x9B */   CHAN_C|VCHAN_C,
/* 0x9C */   CHAN_C|VCHAN_C,
/* 0x9D */   CHAN_C|VCHAN_C,
/* 0x9E */   CHAN_C|VCHAN_C,
/* 0x9F */   CHAN_C|VCHAN_C,
/* 0xA0 */   CHAN_C,
/* 0xA1 */   CHAN_C|VCHAN_C,
/* 0xA2 */   CHAN_C|VCHAN_C,
/* 0xA3 */   CHAN_C|VCHAN_C,
/* 0xA4 */   CHAN_C|VCHAN_C,
/* 0xA5 */   CHAN_C|VCHAN_C,
/* 0xA6 */   CHAN_C|VCHAN_C,
/* 0xA7 */   CHAN_C|VCHAN_C,
/* 0xA8 */   CHAN_C|VCHAN_C,
/* 0xA9 */   CHAN_C|VCHAN_C,
/* 0xAA */   CHAN_C|VCHAN_C,
/* 0xAB */   CHAN_C|VCHAN_C,
/* 0xAC */   CHAN_C|VCHAN_C,
/* 0xAD */   CHAN_C|VCHAN_C,
/* 0xAE */   CHAN_C|VCHAN_C,
/* 0xAF */   CHAN_C|VCHAN_C,
/* 0xB0 */   CHAN_C|VCHAN_C,
/* 0xB1 */   CHAN_C|VCHAN_C,
/* 0xB2 */   CHAN_C|VCHAN_C,
/* 0xB3 */   CHAN_C|VCHAN_C,
/* 0xB4 */   CHAN_C|VCHAN_C,
/* 0xB5 */   CHAN_C|VCHAN_C,
/* 0xB6 */   CHAN_C|VCHAN_C,
/* 0xB7 */   CHAN_C|VCHAN_C,
/* 0xB8 */   CHAN_C|VCHAN_C,
/* 0xB9 */   CHAN_C|VCHAN_C,
/* 0xBA */   CHAN_C|VCHAN_C,
/* 0xBB */   CHAN_C|VCHAN_C,
/* 0xBC */   CHAN_C|VCHAN_C,
/* 0xBD */   CHAN_C|VCHAN_C,
/* 0xBE */   CHAN_C|VCHAN_C,
/* 0xBF */   CHAN_C|VCHAN_C,
/* 0xC0 */   CHAN_C|VCHAN_C,
/* 0xC1 */   CHAN_C|VCHAN_C,
/* 0xC2 */   CHAN_C|VCHAN_C,
/* 0xC3 */   CHAN_C|VCHAN_C,
/* 0xC4 */   CHAN_C|VCHAN_C,
/* 0xC5 */   CHAN_C|VCHAN_C,
/* 0xC6 */   CHAN_C|VCHAN_C,
/* 0xC7 */   CHAN_C|VCHAN_C,
/* 0xC8 */   CHAN_C|VCHAN_C,
/* 0xC9 */   CHAN_C|VCHAN_C,
/* 0xCA */   CHAN_C|VCHAN_C,
/* 0xCB */   CHAN_C|VCHAN_C,
/* 0xCC */   CHAN_C|VCHAN_C,
/* 0xCD */   CHAN_C|VCHAN_C,
/* 0xCE */   CHAN_C|VCHAN_C,
/* 0xCF */   CHAN_C|VCHAN_C,
/* 0xD0 */   CHAN_C|VCHAN_C,
/* 0xD1 */   CHAN_C|VCHAN_C,
/* 0xD2 */   CHAN_C|VCHAN_C,
/* 0xD3 */   CHAN_C|VCHAN_C,
/* 0xD4 */   CHAN_C|VCHAN_C,
/* 0xD5 */   CHAN_C|VCHAN_C,
/* 0xD6 */   CHAN_C|VCHAN_C,
/* 0xD7 */   CHAN_C|VCHAN_C,
/* 0xD8 */   CHAN_C|VCHAN_C,
/* 0xD9 */   CHAN_C|VCHAN_C,
/* 0xDA */   CHAN_C|VCHAN_C,
/* 0xDB */   CHAN_C|VCHAN_C,
/* 0xDC */   CHAN_C|VCHAN_C,
/* 0xDD */   CHAN_C|VCHAN_C,
/* 0xDE */   CHAN_C|VCHAN_C,
/* 0xDF */   CHAN_C|VCHAN_C,
/* 0xE0 */   CHAN_C|VCHAN_C,
/* 0xE1 */   CHAN_C|VCHAN_C,
/* 0xE2 */   CHAN_C|VCHAN_C,
/* 0xE3 */   CHAN_C|VCHAN_C,
/* 0xE4 */   CHAN_C|VCHAN_C,
/* 0xE5 */   CHAN_C|VCHAN_C,
/* 0xE6 */   CHAN_C|VCHAN_C,
/* 0xE7 */   CHAN_C|VCHAN_C,
/* 0xE8 */   CHAN_C|VCHAN_C,
/* 0xE9 */   CHAN_C|VCHAN_C,
/* 0xEA */   CHAN_C|VCHAN_C,
/* 0xEB */   CHAN_C|VCHAN_C,
/* 0xEC */   CHAN_C|VCHAN_C,
/* 0xED */   CHAN_C|VCHAN_C,
/* 0xEE */   CHAN_C|VCHAN_C,
/* 0xEF */   CHAN_C|VCHAN_C,
/* 0xF0 */   CHAN_C|VCHAN_C,
/* 0xF1 */   CHAN_C|VCHAN_C,
/* 0xF2 */   CHAN_C|VCHAN_C,
/* 0xF3 */   CHAN_C|VCHAN_C,
/* 0xF4 */   CHAN_C|VCHAN_C,
/* 0xF5 */   CHAN_C|VCHAN_C,
/* 0xF6 */   CHAN_C|VCHAN_C,
/* 0xF7 */   CHAN_C|VCHAN_C,
/* 0xF8 */   CHAN_C|VCHAN_C,
/* 0xF9 */   CHAN_C|VCHAN_C,
/* 0xFA */   CHAN_C|VCHAN_C,
/* 0xFB */   CHAN_C|VCHAN_C,
/* 0xFC */   CHAN_C|VCHAN_C,
/* 0xFD */   CHAN_C|VCHAN_C,
/* 0xFE */   CHAN_C|VCHAN_C,
/* 0xFF */   CHAN_C|VCHAN_C
};
