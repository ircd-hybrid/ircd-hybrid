#ifndef INCLUDED_ircd_snprintf_h
#define INCLUDED_ircd_snprintf_h
/*
 * IRC - Internet Relay Chat, include/ircd_snprintf.h
 * Copyright (C) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
/** @file
 * @brief IRC-specific printf() clone interface.
 * @version $Id$
 */
#ifndef INCLUDED_sys_types_h
#include <sys/types.h>
#define INCLUDED_sys_types_h
#endif
#ifndef INCLUDED_stdarg_h
#include <stdarg.h>
#define INCLUDED_stdarg_h
#endif

struct Client;

/** structure passed as argument for %v conversion */
struct VarData
{
  size_t        vd_chars;     /**< number of characters inserted */
  size_t        vd_overflow;  /**< number of characters that couldn't be */
  const char   *vd_format;    /**< format string */
  va_list       vd_args;      /**< arguments for %v */
};

extern int xsnprintf(struct Client *, char *, size_t, const char *, ...);
extern int xvsnprintf(struct Client *, char *, size_t, const char *, va_list);

/** @fn int xsnprintf(struct Client *dest, char *buf, size_t
                          buf_len, const char *format, ...)
**
**   These functions are intended to be a complete replacement for
** sprintf and sprintf_irc.  They are a (nearly) complete
** reimplementation, and of course they're snprintf clones, making it
** more difficult for accidental buffer overflows to crop up.
**
**   First off, what's missing?  These functions support all ANSI C
** conversion specifiers and selected ones from ISO 9x, with the
** exception of all floating-point conversions.  The floating-point
** conversions are tricky, and will likely be dependent on the
** representation of a floating-point number on a particular
** architecture.  While that representation is likely to conform to
** some standard, it is not currently used in ircu, so seemed like a
** good thing to omit, given the difficulty of implementing it.
**
**   There are two more things missing from this implementation that
** would be required by ANSI; the first is support for multibyte
** character strings, and the second is support for locales, neither
** of which have any relevance for ircu, so again omission seemed to
** be a good policy.  Additionally, %#x always causes '0x' (or '0X')
** to be printed, even if the number is zero.
**
**   These functions also have some extensions not seen in a
** standards-compliant implementation; technically, the ISO 9x
** extensions fall into this category, for instance.  The ISO 9x
** extensions supported are type extensions--%ju, %tu, and %zu, for
** instance; %qu and %hhu are also supported.  The extensions added
** for use in ircu are %Tu, which takes a time_t, and the new %C
** conversion, which inserts either a numeric or a nick, dependant on
** the &lt;dest> parameter.  The GNU %m extension, which inserts the
** strerror() string corresponding to the current value of errno, is
** also supported, as is a special %v extension, which essentially
** does a recursive call to ircd_snprintf.
**
**   The following description is descended from the Linux manpage for
** the printf family of functions.
**
**   The format string is composed of zero or more directives:
** ordinary characters (not %), which are copied unchanged to the
** output stream; and conversion specifications, each of which results
** in fetching zero or more subsequent arguments.  Each conversion
** specification is introduced by the character %.  The arguments must
** correspond properly (after type promotion) with the conversion
** specifier.  After the %, the following appear in sequence:
**
** <ul><li>Zero or more of the following flags:<dl>
**
** <dt>#</dt>
**      <dd>specifying that the value should be converted to an
**	"alternate form."  For c, d, i, n, p, s, and u conversions,
**	this option has no effect.  For o conversions, the precision
**	of the number is increased to force the first character of the
**	output string to a zero (except if a zero value is printed
**	with an explicit precision of zero).  For x and X conversions,
**	the string '0x' (or '0X' for X conversions) is prepended to
**	it.  For e, E, f, g, and G conversions, the result will always
**	contain a decimal point, even if no digits follow it
**	(normally, a decimal point appears in the results of those
**	conversions only if a digit follows).  For g and G
**	conversions, trailing zeros are not removed from the result as
**	they would otherwise be.  For C conversions, if the
**	destination is local and the origin is a user, the
**	nick!user\@host form is used.</dd>
**
** <dt>0</dt>
**      <dd> specifying zero padding.  For all conversions except n, the
**	converted value is padded on the left with zeros rather than
**	blanks.  If a precision is given with a numeric conversion (d,
**	i, o, u, i, x, and X), the 0 flag is ignored.</dd>
**
** <dt>-</dt>
**      <dd>(a negative field width flag) indicates the converted value is
**	to be left adjusted on the field boundary.  Except for n
**	conversions, the converted value is padded on the right with
**	blanks, rather than on the left with blanks or zeros.  A -
**	overrides a 0 if both are given.</dd>
**
** <dt>' ' (a space)</dt>
**      <dd>specifying that a blank should be left before a
**	positive number produced by a signed conversion (d, e, E, f,
**	g, G, or i).</dd>
**
** <dt>+</dt>
**      <dd>specifying that a sign always be placed before a number
**	produced by a signed conversion.  A + overrides a space if
**	both are used.</dd>
**
** <dt>:</dt>
**      <dd>specifying that a struct Client name should be preceded by a
**	':' character if the destination is a user.</dd>
** </dl></li>
**
** <li>An optional decimal digit string specifying a minimum field
**   width.  If the converted value has fewer characters than the
**   field width, it will be padded with spaces on the left (or right,
**   if the left-adjustment flag has been given) to fill out the field
**   width.</li>
**
** <li>An optional precision, in the form of a period (`.') followed by
**   an optional digit string.  If  the digit string is omitted, the
**   precision is taken as zero.  This gives the minimum number of
**   digits to appear for d, i, o, u, x, and X conversions, the number
**   of digits to appear after the decimal-point for e, E, and f
**   conversions, the maximum number of significant digits for g and G
**   conversions, or the maximum number of characters to be printed
**   from a string for s conversions.</li>
**
** <li>The optional character h, specifying that a following d, i, o, u,
**   x, or X conversion corresponds to a short int or unsigned short
**   int argument, or that a following n conversion corresponds to a
**   pointer to a short int argument.  If the h character is given
**   again, char is used instead of short int.</li>
**
** <li>The optional character l (ell) specifying that a following d, i,
**   o, u, x, or X conversion applies to a pointer to a long int or
**   unsigned long int argument, or that a following n conversion
**   corresponds to a pointer to a long int argument.</li>
**
** <li>The character L specifying that a following e, E, f, g, or G
**   conversion corresponds to a long double argument, or a following
**   d, i, o, u, x, or X conversion corresponds to a long long
**   argument.  Note that long long is not specified in ANSI C and
**   therefore not portable to all architectures.</li>
**
** <li>The optional character q.  This is equivalent to L.</li>
**
** <li>A j character specifying that the following integer (d, i, o, u,
**   x, or X) conversion corresponds to an intmax_t argument.</li>
**
** <li>A t character specifying that the following integer (d, i, o, u,
**   x, or X) conversion corresponds to a ptrdiff_t argument.</li>
**
** <li>A z character specifying that the following integer (d, i, o, u,
**   x, or X) conversion corresponds to a size_t argument.</li>
**
** <li>A T character specifying that the following integer (d, i, o, u,
**   x, or X) conversion corresponds to a time_t argument.</li>
**
** <li>A character that specifies the type of conversion to be applied.</li>
** </ul>
**
**   A field width or precision, or both, may be indicated by an
** asterisk `*' instead of a digit string.  In this case, an int
** argument supplies the field width or precision.  A negative field
** width is treated as a left adjustment flag followed by a positive
** field width; a negative precision is treated as though it were
** missing.
**
** The conversion specifiers and their meanings are:
**
** <dl>
** <dt>diouxX</dt>
**		<dd>The int (or appropriate variant) argument is converted
**		to signed decimal (d and i), unsigned octal (o),
**		unsigned decimal (u), or unsigned hexadecimal (x and
**		X) notation.  The letters abcdef are used for x
**		conversions; the letters ABCDEF are used for X
**		conversions.  The precision, if any, gives the minimum
**		number of digits that must appear; if the converted
**		value requires fewer digits, it is padded on the left
**		with zeros.</dd>
**
** <dt>eE [NOT IMPLEMENTED]</dt>
**		<dd>The double argument is rounded and
**		converted in the style [-]d.dddedd where there is one
**		digit before the decimal-point character and the
**		number of digits after it is equal to the precision;
**		if the precision is missing, it is taken as 6; if the
**		precision is zero, no decimal-point character appears.
**		An E conversion uses the letter E (rather than e) to
**		introduce the exponent.  The exponent always contains
**		at least two digits; if the value is zero, the
**		exponent is 00.</dd>
**
** <dt>f [NOT IMPLEMENTED]</dt>
**		<dd>The double argument is rounded and
**		converted to  decimal notation in the style
**		[-]ddd.ddd, where the number of digits after the
**		decimal-point character is equal to the precision
**		specification.  If the precision is missing, it is
**		taken as 6; if the precision is explicitly zero, no
**		decimal-point character appears.  If a decimal point
**		appears, at least one digit appears before it.</dd>
**
** <dt>g [NOT IMPLEMENTED]</dt>
**		<dd>The double argument is converted in
**		style f or e (or E for G conversions).  The precision
**		specifies the number of significant digits.  If the
**		precision is missing, 6 digits are given; if the
**		precision is zero, it is treated as 1.  Style e is
**		used if the exponent from its conversion is less than
**		-4 or greater than or equal to the precision.
**		Trailing zeros are removed from the fractional part of
**		the result; a decimal point appears only if it is
**		followed by at least one digit.</dd>
**
** <dt>c</dt>
**		<dd>The int argument is converted to an unsigned char, and
**		the resulting character is written.</dd>
**
** <dt>s</dt>
**		<dd>The "char *" argument is expected to be a pointer to
**		an array of character type (pointer to a string).
**		Characters from the array are written up to (but not
**		including) a terminating NUL character; if a precision
**		is specified, no more than the number specified are
**		written.  If a precision is given, no null character
**		need be present; if the precision is not specified, or
**		is greater than the size of the array, the array must
**		contain a terminating NUL character.</dd>
**
** <dt>p</dt>
**		<dd>The "void *" pointer argument is printed in
**		hexadecimal (as if by %#x or %#lx).</dd>
**
** <dt>n</dt>
**		<dd>The number of characters written so far is stored into
**		the integer indicated by the ``int *'' (or variant)
**		pointer argument.  No argument is converted.</dd>
**
** <dt>m</dt>
**		<dd>The error message associated with the current value of
**		errno is printed as if by %s.</dd>
**
** <dt>C</dt>
**		<dd>The client argument identifier is printed under the
**		control of the &lt;dest> argument; if &lt;dest> is NULL or
**		is a user, the client's name (nickname or server name)
**		is printed; otherwise, the client's network numeric is
**		printed.</dd>
**
** <dt>H</dt>
**		<dd>The channel argument identifier (channel name) is
**		printed.</dd>
**
** <dt>v</dt>
**		<dd>The argument given must be a pointer to a struct
**		VarData with vd_format and vd_args must be initialized
**		appropriately.  On return, vd_chars will contain the
**		number of characters added to the buffer, and
**		vd_overflow will contain the number of characters that
**		could not be added due to buffer overflow or due to a
**		precision.</dd>
**
** <dt>%<dt>
**		<dd>A `%' is written.  No argument is converted.  The
**		complete conversion specification is `%%'.</dd>
** </dl>
**
**   In no case does a non-existent or small field width cause
** truncation of a field; if the result of a conversion is wider than
** the field width, the field is expanded to contain the conversion
** result.
**
** @param[in] dest Client receiving of message.
** @param[out] buf Output buffer for formatted message.
** @param[in] buf_len Number of bytes that can be written to \a buf.
** @param[in] format Format string for message.
** @return Number of bytes that would be written to \a buf without truncation.
*/

#endif /* INCLUDED_ircd_snprintf_h */
