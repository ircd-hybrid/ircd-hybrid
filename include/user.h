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

/*! \file user.h
 * \brief A header for the user functions.
 * \version $Id$
 */

#ifndef INCLUDED_user_h
#define INCLUDED_user_h

struct Client;

struct user_modes
{
  unsigned char c;
  unsigned int flag;
};

extern const struct user_modes *umode_map[];
extern const struct user_modes  umode_tab[];

extern void user_modes_init(void);
extern void send_umode(struct Client *, struct Client *,
                       unsigned int, char *);
extern void send_umode_out(struct Client *, unsigned int);
extern void show_lusers(struct Client *);
extern void show_isupport(struct Client *);
extern void user_oper_up(struct Client *);

extern void register_local_user(struct Client *);
extern void register_remote_user(struct Client *);
extern int valid_hostname(const char *);
extern int valid_username(const char *, const int);
extern int valid_nickname(const char *, const int);
extern void add_isupport(const char *, const char *, int);
extern void delete_isupport(const char *);
extern void init_isupport(void);
extern void rebuild_isupport_message_line(void);
extern void user_set_hostmask(struct Client *, const char *, const int);
#endif
