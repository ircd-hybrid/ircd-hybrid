/*	inet_misc.h - Supplemental structs, functions,		*
 *	and definitions required to build ircd on some		*
 *	exotic platforms.					*
 *								*
 *	$Id$							*
 *
 * Copyright (c) 1980, 1983, 1988, 1993
 *      The Regents of the University of California.  All rights reserved.
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
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
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
 *
 * -
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
 * -
 * --Copyright--
 */

#ifndef INCLUDED_inet_misc_h
#define INCLUDED_inet_misc_h

#include "stdinc.h"

#ifndef AI_PASSIVE
#define AI_PASSIVE      0x00000001 /* get address to use bind() */
#endif /* AI_PASSIVE */

#ifndef AI_NUMERICHOST
#define AI_NUMERICHOST  0x00000004 /* prevent name resolution */
#endif /* AI_NUMERICHOST */

#ifndef EAI_FAIL
#define EAI_FAIL         4      /* non-recoverable failure in name resolution */
#endif /* EAI_FAIL */

#ifndef EAI_FAMILY
#define EAI_FAMILY       5      /* ai_family not supported */
#endif /* EAI_FAMILY */

#ifndef EAI_MEMORY
#define EAI_MEMORY       6      /* memory allocation failure */
#endif /* EAI_MEMORY */

#ifndef EAI_NONAME
#define EAI_NONAME       8      /* hostname nor servname provided, or not known */
#endif /* EAI_NONAME */

#ifndef EAI_SYSTEM
#define EAI_SYSTEM      11      /* system error returned in errno */
#endif /* EAI_SYSTEM */

#ifndef NI_NUMERICHOST
#define NI_NUMERICHOST	0x00000002
#endif /* NI_NUMERICHOST */

#ifndef NI_NAMEREQD
#define NI_NAMEREQD     0x00000004
#endif /* NI_NAMEREQD */

#ifndef NI_NUMERICSERV
#define NI_NUMERICSERV  0x00000008
#endif /* NI_NUMERICSERV */

#ifndef NI_DGRAM
#define NI_DGRAM        0x00000010
#endif /* NI_DGRAM */

#ifndef INADDR_NONE
#define INADDR_NONE ((unsigned int) 0xffffffff)
#endif /* INADDR_NONE */

#ifndef HAVE_STRUCT_SOCKADDR_STORAGE
#ifdef SOCKADDR_IN_HAS_LEN /* BSD style sockaddr_storage for BSD style
			      sockaddr_in */
struct sockaddr_storage {
	unsigned char ss_len;
	sa_family_t ss_family;
	char __ss_pad1[((sizeof(int64_t)) - sizeof(unsigned char) -
			sizeof(sa_family_t) )];
	int64_t __ss_align;
	char __ss_pad2[(128 - sizeof(unsigned char) - sizeof(sa_family_t) -
			((sizeof(int64_t)) - sizeof(unsigned char) -
			 sizeof(sa_family_t)) - (sizeof(int64_t)))];
};
#else /* Linux style for everything else (for now) */
struct sockaddr_storage
{
	sa_family_t ss_family;
	uint32_t __ss_align;
	char __ss_padding[(128 - (2 * sizeof (uint32_t)))];
};
#endif /* SOCKADDR_IN_HAS_LEN */
#endif /* HAVE_STRUCT_SOCKADDR_STORAGE */

#ifndef HAVE_STRUCT_ADDRINFO
struct addrinfo {
	int ai_flags;
	int ai_family;
	int ai_socktype;
	int ai_protocol;
	size_t ai_addrlen;
	char *ai_canonname;
	struct sockaddr *ai_addr;
	struct addrinfo *ai_next;
};
#endif /* HAVE_STRUCT_ADDRINFO */

#ifdef NO_IN6ADDR_ANY
extern const struct in6_addr in6addr_any;
#endif

#ifdef NO_INET_NTOP
const char * inet_ntop(int af, const void *src, char *dst, size_t size);
#endif /* NO_INET_NTOP */

#ifdef NO_INET_PTON
int inet_pton(int af, const char *src, void *dst);
#endif /* NO_INET_PTON */

#ifdef NO_INET_ATON
int inet_aton(const char *cp, struct in_addr * addr);
#endif /* NO_INET_ATON */

#endif /* INCLUDED_inet_misc_h */
