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

/*! \file server.h
 * \brief A header for the server functions.
 * \version $Id$
 */

#ifndef INCLUDED_server_h
#define INCLUDED_server_h

struct Client;
struct MaskItem;

/*
 * Number of seconds to wait after server starts up, before
 * starting try_connections()
 * TOO SOON and you can nick collide like crazy.
 */
enum { STARTUP_CONNECTIONS_TIME = 60 };

/*
 * Return values for hunt_server()
 */
enum
{
  HUNTED_NOSUCH  = -1,  /**< If the hunted server is not found */
  HUNTED_ISME    =  0,  /**< If this server should execute the command */
  HUNTED_PASS    =  1   /**< If message passed onwards successfully */
};


/* Capabilities */
struct Capability
{
  dlink_node node;
  char *name;  /**< Name of capability */
  unsigned int cap;  /**< Mask value */
};

enum
{
  CAPAB_QS      = 0x00000001U,  /* Can handle quit storm removal */
  CAPAB_EX      = 0x00000002U,  /* Can do channel +e exemptions */
  CAPAB_IE      = 0x00000004U,  /* Can do invite exceptions */
  CAPAB_EOB     = 0x00000008U,  /* Can do EOB message */
  CAPAB_KLN     = 0x00000010U,  /* Can do KLINE message */
  CAPAB_KNOCK   = 0x00000020U,  /* Supports KNOCK */
  CAPAB_UNKLN   = 0x00000040U,  /* Can do UNKLINE message */
  CAPAB_CLUSTER = 0x00000080U,  /* Supports server clustering */
  CAPAB_ENCAP   = 0x00000100U,  /* Supports ENCAP message */
  CAPAB_HOPS    = 0x00000200U,  /* Supports HALFOPS */
  CAPAB_TBURST  = 0x00000400U,  /* Supports TBURST */
  CAPAB_SVS     = 0x00000800U,  /* Supports services */
  CAPAB_DLN     = 0x00001000U,  /* Can do DLINE message */
  CAPAB_UNDLN   = 0x00002000U,  /* Can do UNDLINE message */
  CAPAB_CHW     = 0x00004000U   /* Can do channel wall @# */
};

/*
 * Capability macros.
 */
#define IsCapable(x, cap)       ((x)->connection->caps &   (cap))
#define SetCapable(x, cap)      ((x)->connection->caps |=  (cap))
#define ClearCap(x, cap)        ((x)->connection->caps &= ~(cap))

extern int valid_servname(const char *);
extern int check_server(const char *, struct Client *);
extern int hunt_server(struct Client *, const char *, const int, const int, char *[]);
extern void add_capability(const char *, unsigned int);
extern void delete_capability(const char *);
extern unsigned int find_capability(const char *);
extern void send_capabilities(struct Client *);
extern void write_links_file(void *);
extern void read_links_file(void);
extern const char *show_capabilities(const struct Client *);
extern void try_connections(void *);
extern int serv_connect(struct MaskItem *, struct Client *);
extern struct Client *find_servconn_in_progress(const char *);
extern struct Server *make_server(struct Client *);
#endif  /* INCLUDED_server_h */
