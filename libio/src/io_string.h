/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2026 ircd-hybrid development team
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

/**
 * @file io_string.h
 * @brief Header file for IRC string functions and character attributes.
 *
 * This header file provides essential definitions, macros, and enumerations
 * for IRC string manipulation and character classification. It encompasses
 * character attribute flags, classification macros, and utility functions.
 */

#ifndef INCLUDED_io_string_h
#define INCLUDED_io_string_h
#include <stdbool.h>
#include <stddef.h>

#include "config.h"  /**< Autotools-generated HAVE_STRLCPY & HAVE_STRLCAT. */

/**
 * @brief Enumeration of character attributes used for classification.
 *
 * This enum defines various character classes for classification,
 * utilized by the provided character classification macros.
 */
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
#define IsAlpha(c)      (CharAttrs[(unsigned char)(c)] & ALPHA_C)
#define IsSpace(c)      (CharAttrs[(unsigned char)(c)] & SPACE_C)
#define IsLower(c)      (IsAlpha((c)) && ((unsigned char)(c) > 0x5f))
#define IsUpper(c)      (IsAlpha((c)) && ((unsigned char)(c) < 0x60))
#define IsDigit(c)      (CharAttrs[(unsigned char)(c)] & DIGIT_C)
#define IsXDigit(c)     (IsDigit(c) || ('a' <= (c) && (c) <= 'f') || ('A' <= (c) && (c) <= 'F'))
#define IsAlNum(c) (CharAttrs[(unsigned char)(c)] & (DIGIT_C | ALPHA_C))
#define IsEol(c) (CharAttrs[(unsigned char)(c)] & EOL_C)

extern const unsigned char ToLowerTab[];  /*!< Lookup table for converting characters to lowercase. */
#define ToLower(c) (ToLowerTab[(unsigned char)(c)]) /*!< Converts a character to lowercase using the lookup table. */

extern const unsigned char ToUpperTab[];  /*!< Lookup table for converting characters to uppercase. */
#define ToUpper(c) (ToUpperTab[(unsigned char)(c)])  /*!< Converts a character to uppercase using the lookup table. */

extern const unsigned int CharAttrs[];

extern const char *io_basename(const char *);
extern const char *stripws(char *);
extern bool has_wildcards(const char *);
extern int match(const char *, const char *);
extern unsigned int token_vector(char *, char, char *[], unsigned int);
extern char *collapse(char *);
extern int io_strcasecmp(const char *, const char *);
extern int io_strncasecmp(const char *, const char *, size_t);
#ifndef HAVE_STRLCPY
extern size_t strlcpy(char *, const char *, size_t);
#endif
#ifndef HAVE_STRLCAT
extern size_t strlcat(char *, const char *, size_t);
#endif

/**
 * @brief Returns a default string if the provided string is NULL or empty.
 *
 * This function checks if the provided string is non-NULL and not empty.
 * If it is, the function returns the original string; otherwise, it returns
 * the provided default string.
 *
 * @param str Pointer to the string to check.
 * @param default_str The default string to return if `str` is NULL or empty.
 * @return The original string if non-NULL and not empty, or the default string.
 */
static inline const char *
string_default(const char *str, const char *default_str)
{
  return (str && *str != '\0') ? str : default_str;
}

/**
 * @brief Checks if a string is empty.
 *
 * This function returns `true` if the provided string pointer is NULL or if the string's
 * first character is the null terminator (`'\0'`), indicating an empty string.
 *
 * @param str Pointer to the string to check.
 * @return `true` if the string is empty or NULL; `false` otherwise.
 */
static inline bool
string_is_empty(const char *str)
{
  return !str || *str == '\0';
}

/**
 * @brief Returns a non-NULL string.
 *
 * This function returns the provided string if it is non-NULL; otherwise, it returns
 * an empty string ("").
 *
 * @param str Pointer to the string to check.
 * @return The original string if non-NULL, or an empty string ("") if NULL.
 */
static inline const char *
string_or_empty(const char *str)
{
  return str ? str : "";
}
#endif  /* INCLUDED_io_string_h */
