/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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

/*! \file send.h
 * \brief A header for the message sending functions.
 * \version $Id$
 */

#ifndef INCLUDED_send_h
#define INCLUDED_send_h

#include "fdlist.h"
#include "numeric.h"

enum
{
  L_ALL   = 0,
  L_OPER  = 1,
  L_ADMIN = 2
};

enum
{
  SEND_NOTICE = 1,
  SEND_GLOBAL = 2,
  SEND_LOCOPS = 3
};

/* Used when sending to $#mask or $$mask */
enum
{
  MATCH_SERVER = 1,
  MATCH_HOST   = 2
};

/*
 * struct decls
 */
struct Channel;
struct Client;

/* send.c prototypes */
extern void sendq_unblocked(fde_t *, void *);
extern void send_queued_write(struct Client *);
extern void send_queued_all(void);
extern void sendto_one(struct Client *, const char *, ...) AFP(2,3);
extern void sendto_one_numeric(struct Client *, const struct Client *, enum irc_numerics, ...);
extern void sendto_one_notice(struct Client *, const struct Client *, const char *, ...) AFP(3,4);
extern void sendto_channel_butone(struct Client *, const struct Client *,
                                  struct Channel *, unsigned int,
                                  const char *, ...) AFP(5,6);
extern void sendto_common_channels_local(struct Client *, int, unsigned int, unsigned int,
                                         const char *, ...) AFP(5,6);
extern void sendto_channel_local(const struct Client *, struct Channel *, unsigned int,
                                 unsigned int, unsigned int, const char *, ...)  AFP(6,7);
extern void sendto_server(const struct Client *, const unsigned int,
                          const unsigned int, const char *, ...) AFP(4,5);
extern void sendto_match_butone(const struct Client *, const struct Client *,
                                const char *, int, const char *, ...) AFP(5,6);
extern void sendto_match_servs(const struct Client *, const char *, unsigned int,
                               const char *, ...) AFP(4,5);
extern void sendto_realops_flags(unsigned int, int, int,
                                 const char *, ...) AFP(4,5);
extern void sendto_wallops_flags(unsigned int, const struct Client *,
                                 const char *, ...) AFP(3,4);
extern void sendto_realops_flags_ratelimited(uintmax_t *, const char *, ...) AFP(2,3);

extern void sendto_anywhere(struct Client *, const struct Client *,
                            const char *,
                            const char *, ...) AFP(4,5);
#endif /* INCLUDED_send_h */
