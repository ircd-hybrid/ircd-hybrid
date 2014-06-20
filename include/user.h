/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file user.h
 * \brief A header for the user functions.
 * \version $Id$
 */

#ifndef INCLUDED_user_h
#define INCLUDED_user_h

#define IRC_MAXSID 3
#define IRC_MAXUID 6
#define TOTALSIDUID (IRC_MAXSID + IRC_MAXUID)

struct Client;

extern const unsigned int user_modes[];

extern void assemble_umode_buffer(void);
extern void send_umode(struct Client *, struct Client *,
                       unsigned int, char *);
extern void send_umode_out(struct Client *, struct Client *, unsigned int);
extern void show_lusers(struct Client *);
extern void show_isupport(struct Client *);
extern void oper_up(struct Client *);

extern void register_local_user(struct Client *);
extern void register_remote_user(struct Client *,
                                 const char *, const char *,
                                 const char *);
extern void init_uid(void);
extern int valid_sid(const char *);
extern int valid_hostname(const char *);
extern int valid_username(const char *, const int);
extern int valid_nickname(const char *, const int);
extern void add_isupport(const char *, const char *, int);
extern void delete_isupport(const char *);
extern void init_isupport(void);
extern void rebuild_isupport_message_line(void);
extern void user_set_hostmask(struct Client *, const char *, const int);
#endif
