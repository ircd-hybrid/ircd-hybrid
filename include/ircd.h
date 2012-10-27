/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd.h: A header for the ircd startup routines.
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

#ifndef INCLUDED_ircd_h
#define INCLUDED_ircd_h

#include "ircd_defs.h"
#include "config.h"
#include "memory.h"
#include "list.h"

struct Client;

struct SetOptions
{
  int autoconn;      /* autoconn enabled for all servers? */
  int idletime;
  int floodcount;    /* Number of messages in 1 second    */
  /* XXX for join flood catching - Dianora */
  int joinfloodtime;
  int joinfloodcount;
  /* XXX */
  int rejecttime;
  int ident_timeout; /* timeout for identd lookups        */
  int spam_num;
  int spam_time;
};

/*
 * statistics structures
 */
struct ServerStatistics
{
  uint64_t        is_cbs;  /* bytes sent to clients */
  uint64_t        is_cbr;  /* bytes received from clients */
  uint64_t        is_sbs;  /* bytes sent to servers */
  uint64_t        is_sbr;  /* bytes received from servers */

  time_t          is_cti;  /* time spent connected by clients */
  time_t          is_sti;  /* time spent connected by servers */

  unsigned int    is_cl;   /* number of client connections */
  unsigned int    is_sv;   /* number of server connections */
  unsigned int    is_ni;   /* connection but no idea who it was */
  unsigned int    is_ac;   /* connections accepted */
  unsigned int    is_ref;  /* accepts refused */
  unsigned int    is_unco; /* unknown commands */
  unsigned int    is_wrdi; /* command going in wrong direction */
  unsigned int    is_unpf; /* unknown prefix */
  unsigned int    is_empt; /* empty message */
  unsigned int    is_num;  /* numeric message */
  unsigned int    is_kill; /* number of kills generated on collisions */
  unsigned int    is_asuc; /* successful auth requests */
  unsigned int    is_abad; /* bad auth requests */
};

extern struct ServerStatistics ServerStats;


struct Counter
{
  uint64_t totalrestartcount; /* Total client count ever */
  unsigned int myserver;      /* my servers          */
  unsigned int oper;          /* Opers               */
  unsigned int local;         /* Local Clients       */
  unsigned int total;         /* total clients       */
  unsigned int invisi;        /* invisible clients   */
  unsigned int max_loc;       /* MAX local clients   */
  unsigned int max_tot;       /* MAX global clients  */
  unsigned int max_loc_con;   /* MAX local connection count (clients + server) */
  unsigned int max_loc_cli;   /* XXX This is redundant - Max local client count */
};

extern struct SetOptions GlobalSetOptions; /* defined in ircd.c */

struct ServerState_t
{
  int foreground;
};

extern struct ServerState_t server_state;

extern char **myargv;
extern char ircd_platform[PLATFORMLEN];
extern char *get_ircd_platform(char *);
extern const char *infotext[];
extern const char *serno;
extern const char *ircd_version;
extern const char *logFileName;
extern const char *pidFileName;
extern int dorehash;
extern int doremotd;
extern struct Counter Count;
extern struct timeval SystemTime;
#define CurrentTime SystemTime.tv_sec
extern int default_server_capabs;
#ifdef HAVE_LIBCRYPTO
extern int bio_spare_fd;
#endif /* HAVE_LIBCRYPTO */

extern unsigned int splitmode;
extern unsigned int splitchecking;
extern unsigned int split_users;
extern unsigned int split_servers;

extern dlink_list unknown_list;       /* unknown clients ON this server only        */
extern dlink_list local_client_list;  /* local clients only ON this server          */
extern dlink_list serv_list;          /* local servers to this server ONLY          */
extern dlink_list global_serv_list;   /* global servers on the network              */
extern dlink_list oper_list;          /* our opers, duplicated in local_client_list */
extern int rehashed_klines;
extern void set_time(void);
#endif
