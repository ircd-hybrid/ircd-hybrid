/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  send.h: A header for the message sending functions.
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

#ifndef INCLUDED_send_h
#define INCLUDED_send_h

#include "fdlist.h"

#define ALL_MEMBERS  0
#define NON_CHANOPS  1
#define ONLY_CHANOPS_VOICED  2
#define ONLY_CHANOPS 3
#define ONLY_SERVERS 4 /* for channel_mode.c */

#define L_ALL   0
#define L_OPER  1
#define L_ADMIN 2

#define SEND_NOTICE 1
#define SEND_GLOBAL 2
#define SEND_LOCOPS 3

#define NOCAPS          0               /* no caps */
#define NOFLAGS         0               /* no flags */

/* used when sending to #mask or $mask */
#define MATCH_SERVER  1
#define MATCH_HOST    2


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
extern void sendto_channel_butone(struct Client *, struct Client *,
                                  struct Channel *, unsigned int,
                                  const char *, ...) AFP(5,6);
extern void sendto_common_channels_local(struct Client *, int, unsigned int,
                                         const char *, ...) AFP(4,5);
extern void sendto_channel_local(int, int, struct Channel *,
                                 const char *, ...) AFP(4,5);
extern void sendto_channel_local_butone(struct Client *, int, unsigned int, struct Channel *,
                                        const char *, ...) AFP(5,6);
extern void sendto_channel_remote(struct Client *, struct Client *, int,
                                  const unsigned int, const unsigned int,
                                  struct Channel *, const char *, ...) AFP(7,8);
extern void sendto_server(struct Client *,
                          const unsigned int,
                          const unsigned int, const char *, ...) AFP(4,5);
extern void sendto_match_butone(struct Client *, struct Client *, 
                                char *, int, const char *, ...) AFP(5,6);
extern void sendto_match_servs(struct Client *, const char *, int,
                               const char *, ...) AFP(4,5);
extern void sendto_realops_flags(unsigned int, int, int,
                                 const char *, ...) AFP(4,5);
extern void sendto_wallops_flags(unsigned int, struct Client *,
                                 const char *, ...) AFP(3,4);
extern void ts_warn(const char *, ...) AFP(1,2);

extern void sendto_anywhere(struct Client *, struct Client *, 
                            const char *, ...) AFP(3,4);
extern void kill_client(struct Client *, struct Client *,
                        const char *, ... ) AFP(3,4);
extern void kill_client_ll_serv_butone(struct Client *, struct Client *,
                                       const char *, ...) AFP(3,4);
#endif /* INCLUDED_send_h */
