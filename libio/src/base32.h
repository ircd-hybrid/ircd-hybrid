/**
 * base32 (de)coder implementation as specified by RFC4648.
 *
 * Copyright (c) 2010 Adrien Kunysz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **/

#ifndef INCLUDED_base32_h
#define INCLUDED_base32_h

#include <stddef.h>  /* size_t */
#include <stdbool.h>

/**
 * Returns the length of the output buffer required to encode len bytes of
 * data into base32. This is a macro to allow users to define buffer size at
 * compilation time.
 */
#define BASE32_LEN(len)  (((len) / 5) * 8 + ((len) % 5 ? 8 : 0))

/**
 * Returns the length of the output buffer required to decode a base32 string
 * of len characters. Please note that len must be a multiple of 8 as per
 * definition of a base32 string. This is a macro to allow users to define
 * buffer size at compilation time.
 */
#define UNBASE32_LEN(len)  (((len) / 8) * 5)

/**
 * @def BASE32_FLAGS
 * @brief Enumerates configuration flags for Base32 encoding and decoding.
 *
 * This enumeration defines flags that can be used to configure the behavior of Base32 encoding and decoding.
 * Flags can be combined using bitwise OR operations to enable multiple options simultaneously.
 */
typedef enum
{
  /**
   * @def BASE32_NO_PADDING
   * @brief Disables padding in Base32 encoding.
   *
   * When this flag is set, padding characters ('=') are not added to the end of encoded Base32 strings.
   * By default, padding is enabled in Base32 encoding.
   */
  BASE32_NO_PADDING = 1 << 0,

  /**
   * @def BASE32_LOWER_CASE
   * @brief Specifies the use of lower-case characters in Base32 encoding.
   *
   * When this flag is set, lower-case characters ('a' to 'z') are used in the Base32 encoding table.
   * By default, upper-case characters ('A' to 'Z') are used.
   */
  BASE32_LOWER_CASE = 1 << 1,
} base32_flags_t;

/**
 * @brief Configuration options for Base32 encoding and decoding.
 *
 * This structure defines configuration options for Base32 encoding and decoding.
 * Users can specify options such as padding behavior and character case.
 */
typedef struct
{
  bool no_padding;  /**< Specifies whether padding is disabled in Base32 encoding. Default is false. */
  bool lower_case;  /**< Specifies whether lower-case characters are used in Base32 encoding. Default is false. */
} base32_config_t;

/**
 * @brief Context structure for Base32 encoding and decoding.
 *
 * This structure holds the context for Base32 encoding and decoding operations.
 * It includes a base32_config structure for configuration options and a pointer
 * to the Base32 encoding table.
 */
typedef struct
{
  base32_config_t config;  /**< Configuration options for Base32 encoding and decoding. */
  const unsigned char *base32_table;  /**< Pointer to the Base32 encoding table. */
} base32_context_t;

extern void base32_init(base32_context_t *);
extern void base32_set_config(base32_context_t *, base32_flags_t);

/**
 * Encode the data pointed to by plain into base32 and store the
 * result at the address pointed to by coded. The "coded" argument
 * must point to a location that has enough available space
 * to store the whole coded string. The resulting string will only
 * contain characters from the [A-Z2-7=] set. The "len" arguments
 * define how many bytes will be read from the "plain" buffer.
 **/
extern void base32_encode(base32_context_t *, const unsigned char *, size_t, unsigned char *);

/**
 * Decode the null terminated string pointed to by coded and write
 * the decoded data into the location pointed to by plain. The
 * "plain" argument must point to a location that has enough available
 * space to store the whole decoded string.
 * Returns the length of the decoded string. This may be less than
 * expected due to padding. If an invalid base32 character is found
 * in the coded string, decoding will stop at that point.
 **/
extern size_t base32_decode(base32_context_t *, const unsigned char *, unsigned char *);
#endif  /* INCLUDED_base32_h */
