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

/*! \file channel_mode.h
 * \brief Includes channel mode related definitions and structures.
 * \version $Id$
 */

#ifndef INCLUDED_channel_mode_h
#define INCLUDED_channel_mode_h

#include "ircd_defs.h"        /* buffer sizes */

#define MODEBUFLEN    200

/* Maximum mode changes allowed per client, per server is different */
#define MAXMODEPARAMS 4

/* can_send results */
#define CAN_SEND_NO	0
#define CAN_SEND_NONOP  -1
#define CAN_SEND_OPV	-2


/* Channel related flags */
#define CHFL_CHANOP     0x0001 /* Channel operator   */
#define CHFL_HALFOP     0x0002 /* Channel half op    */
#define CHFL_VOICE      0x0004 /* the power to speak */
#define CHFL_DEOPPED    0x0008 /* deopped by us, modes need to be bounced */
#define CHFL_BAN        0x0010 /* ban channel flag */
#define CHFL_EXCEPTION  0x0020 /* exception to ban channel flag */
#define CHFL_INVEX      0x0040

/* channel modes ONLY */
#define MODE_PRIVATE    0x0001
#define MODE_SECRET     0x0002
#define MODE_MODERATED  0x0004
#define MODE_TOPICLIMIT 0x0008
#define MODE_INVITEONLY 0x0010
#define MODE_NOPRIVMSGS 0x0020
#define MODE_SSLONLY    0x0040
#define MODE_OPERONLY   0x0080
#define MODE_REGISTERED 0x0100 /* Channel has been registered with ChanServ */
#define MODE_REGONLY    0x0200
#define MODE_NOCTRL     0x0400
#define MODE_MODREG     0x0800

/* cache flags for silence on ban */
#define CHFL_BAN_CHECKED  0x0080
#define CHFL_BAN_SILENCED 0x0100

#define MODE_QUERY  0
#define MODE_ADD    1
#define MODE_DEL   -1

#define CHACCESS_NOTONCHAN  -1
#define CHACCESS_PEON       0
#define CHACCESS_HALFOP     1
#define CHACCESS_CHANOP     2

/* name invisible */
#define SecretChannel(x)        (((x)->mode.mode & MODE_SECRET))
#define PubChannel(x)           (!SecretChannel(x))
/* knock is forbidden, halfops can't kick/deop other halfops.
 * +pi means paranoid and will generate notices on each invite */
#define PrivateChannel(x)       (((x)->mode.mode & MODE_PRIVATE))

struct ChModeChange
{
  char letter;
  const char *arg;
  const char *id;
  int dir;
  unsigned int caps;
  unsigned int nocaps;
  int mems;
  struct Client *client;
};

struct ChCapCombo
{
  int count;
  unsigned int cap_yes;
  unsigned int cap_no;
};

struct mode_letter
{
  const unsigned int mode;
  const unsigned char letter;
};

extern const struct mode_letter chan_modes[];
extern int add_id(struct Client *, struct Channel *, char *, int);
extern void set_channel_mode(struct Client *, struct Client *, struct Channel *,
                             struct Membership *, int, char **, char *);
extern void clear_ban_cache(struct Channel *);
extern void clear_ban_cache_client(struct Client *);
extern void init_chcap_usage_counts(void);
extern void set_chcap_usage_counts(struct Client *);
extern void unset_chcap_usage_counts(struct Client *);
#endif /* INCLUDED_channel_mode_h */
