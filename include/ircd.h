/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2019 ircd-hybrid development team
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

/*! \file ircd.h
 * \brief A header for the ircd startup routines.
 * \version $Id$
 */


#ifndef INCLUDED_ircd_h
#define INCLUDED_ircd_h

#include "ircd_defs.h"
#include "config.h"


struct SetOptions
{
  bool autoconn;      /* autoconn enabled for all servers? */
  unsigned int maxclients;
  unsigned int floodcount;  /* Number of messages in 'floodtime' seconds */
  unsigned int floodtime;
  unsigned int joinfloodtime;
  unsigned int joinfloodcount;
  unsigned int spam_num;
  unsigned int spam_time;
};

/*
 * statistics structures
 */
struct ServerStatistics
{
  uintmax_t        is_cbs;  /* bytes sent to clients */
  uintmax_t        is_cbr;  /* bytes received from clients */
  uintmax_t        is_sbs;  /* bytes sent to servers */
  uintmax_t        is_sbr;  /* bytes received from servers */

  uintmax_t        is_cti;  /* time spent connected by clients */
  uintmax_t        is_sti;  /* time spent connected by servers */

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

struct Counter
{
  uintmax_t totalrestartcount; /* Total client count ever */
  unsigned int oper;          /* Opers               */
  unsigned int invisi;        /* invisible clients   */
  unsigned int max_loc;       /* MAX local clients   */
  unsigned int max_tot;       /* MAX global clients  */
  unsigned int max_loc_con;   /* MAX local connection count (clients + server) */
};

struct ServerState_t
{
  bool foreground;
};

struct ServerTime
{
  uintmax_t tv_sec, tv_nsec;
};


extern char **myargv;
extern const char *logFileName;
extern const char *pidFileName;
extern bool dorehash;
extern bool doremotd;
extern struct Counter Count;
extern struct ServerStatistics ServerStats;
extern struct SetOptions GlobalSetOptions;
extern struct ServerState_t server_state;
extern struct event event_write_links_file;
extern struct ServerTime SystemTime;
#define CurrentTime SystemTime.tv_sec

extern void set_time(void);
#endif
