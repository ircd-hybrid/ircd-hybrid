/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_misc.h: A header for the miscellaneous functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#ifndef INCLUDED_s_misc_h
#define INCLUDED_s_misc_h

extern char *date(time_t);
extern const char *smalldate(time_t);
#ifdef HAVE_LIBCRYPTO
extern char *ssl_get_cipher(const SSL *);
#endif

/* Just blindly define our own MIN/MAX macro */

#define IRCD_MAX(a, b)  ((a) > (b) ? (a) : (b))
#define IRCD_MIN(a, b)  ((a) < (b) ? (a) : (b))

#define _1MEG     (1024.0f)
#define _1GIG     (1024.0f*1024.0f)
#define _1TER     (1024.0f*1024.0f*1024.0f)
#define _GMKs(x)  (((x) > _1TER) ? "Terabytes" : (((x) > _1GIG) ? "Gigabytes" :\
                  (((x) > _1MEG) ? "Megabytes" : "Kilobytes")))
#define _GMKv(x)  (((x) > _1TER) ? (float)((x)/_1TER) : (((x) > _1GIG) ? \
                   (float)((x)/_1GIG) : (((x) > _1MEG) ? (float)((x)/_1MEG) : \
		   (float)(x))))
#endif
