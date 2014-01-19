/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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

/*! \file rsa.h
 * \brief A header for the RSA functions.
 * \version $Id$
 */

#ifndef INCLUDED_rsa_h
#define INCLUDED_rsa_h

#include "config.h"

#ifdef HAVE_LIBCRYPTO
extern void report_crypto_errors(void);
extern int generate_challenge(char **, char **, RSA *);
extern int get_randomness(unsigned char *, int);
#endif
#endif /* INCLUDED_rsa_h */

