/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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

/*! \file id.h
 * \brief Contains functions pertaining to SID/UID generation.
 * \version $Id$
 */

#ifndef INCLUDED_id_h
#define INCLUDED_id_h

enum
{
  IRC_MAXSID  = 3,
  IRC_MAXUID  = 6,
  TOTALSIDUID = IRC_MAXSID + IRC_MAXUID
};

extern int valid_sid(const char *);
extern void init_uid(void);
extern const char *uid_get(void);
extern void generate_sid(void);
#endif
