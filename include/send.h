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

/*! \file send.h
 * \brief A header for the message sending functions.
 * \version $Id$
 */

#ifndef INCLUDED_send_h
#define INCLUDED_send_h

#include "fdlist.h"
#include "numeric.h"

enum { NOCAPS = 0 };

enum
{
  ALL_MEMBERS         = 0,
  NON_CHANOPS         = 1,
  ONLY_CHANOPS_VOICED = 2,
  ONLY_CHANOPS        = 3,
  ONLY_SERVERS        = 4
};

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

/* used when sending to #mask or $mask */
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
extern void sendq_unblocked(fde_t *, struct Client *);
extern void send_queued_write(struct Client *);
extern void send_queued_all(void);
extern void sendto_one(struct Client *, const char *, ...) AFP(2,3);
extern void sendto_one_numeric(struct Client *, struct Client *, enum irc_numerics, ...);
extern void sendto_one_notice(struct Client *, struct Client *, const char *, ...);
extern void sendto_channel_butone(struct Client *, struct Client *,
                                  struct Channel *, unsigned int,
                                  const char *, ...) AFP(5,6);
extern void sendto_common_channels_local(struct Client *, int, unsigned int,
                                         const char *, ...) AFP(4,5);
extern void sendto_channel_local(unsigned int, int, struct Channel *,
                                 const char *, ...) AFP(4,5);
extern void sendto_channel_local_butone(struct Client *, unsigned int, unsigned int, struct Channel *,
                                        const char *, ...) AFP(5,6);
extern void sendto_server(struct Client *,
                          const unsigned int,
                          const unsigned int, const char *, ...) AFP(4,5);
extern void sendto_match_butone(struct Client *, struct Client *,
                                char *, int, const char *, ...) AFP(5,6);
extern void sendto_match_servs(struct Client *, const char *, unsigned int,
                               const char *, ...) AFP(4,5);
extern void sendto_realops_flags(unsigned int, int, int,
                                 const char *, ...) AFP(4,5);
extern void sendto_wallops_flags(unsigned int, struct Client *,
                                 const char *, ...) AFP(3,4);
extern void sendto_realops_flags_ratelimited(const char *, ...) AFP(1,2);

extern void sendto_anywhere(struct Client *, struct Client *,
                            const char *,
                            const char *, ...) AFP(4,5);
extern void kill_client(struct Client *, struct Client *,
                        const char *, ... ) AFP(3,4);
extern void kill_client_serv_butone(struct Client *, struct Client *,
                                    const char *, ...) AFP(3,4);
#endif /* INCLUDED_send_h */
