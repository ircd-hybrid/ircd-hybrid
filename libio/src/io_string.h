/*
 * SPDX-FileCopyrightText: 1999-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
  NICK_C    = 1 <<  6,
  CHAN_C    = 1 <<  7,
  KWILD_C   = 1 <<  8,
  CHANPFX_C = 1 <<  9,
  USER_C    = 1 << 10,
  HOST_C    = 1 << 11,
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

extern const unsigned char io_ascii_to_lower_table[256];  /*!< Lookup table for converting characters to lowercase. */
extern const unsigned char io_ascii_to_upper_table[256];  /*!< Lookup table for converting characters to uppercase. */

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

static inline bool
io_ascii_is_space(unsigned char ch)
{
  return ch == ' '  ||
         ch == '\t' ||
         ch == '\n' ||
         ch == '\v' ||
         ch == '\f' ||
         ch == '\r';
}

static inline unsigned char
io_ascii_to_lower(unsigned char c)
{
  return io_ascii_to_lower_table[c];
}

static inline unsigned char
io_ascii_to_upper(unsigned char c)
{
  return io_ascii_to_upper_table[c];
}

static inline bool
io_ascii_is_alpha(unsigned char ch)
{
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

static inline bool
io_ascii_is_upper(unsigned char ch)
{
  return ch >= 'A' && ch <= 'Z';
}

static inline bool
io_ascii_is_digit(unsigned char ch)
{
  return ch >= '0' && ch <= '9';
}

static inline bool
io_ascii_is_xdigit(unsigned char ch)
{
  return io_ascii_is_digit(ch) || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f');
}

static inline bool
io_ascii_is_alnum(unsigned char ch)
{
  return io_ascii_is_alpha(ch) || io_ascii_is_digit(ch);
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
string_or_default(const char *str, const char *default_str)
{
  return (str && *str != '\0') ? str : default_str;
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
