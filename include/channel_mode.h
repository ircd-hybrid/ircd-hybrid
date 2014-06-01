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

#define MODEBUFLEN    200

/* Maximum mode changes allowed per client, per server is different */
#define MAXMODEPARAMS 4

enum
{
  MODE_QUERY =  0,
  MODE_ADD   =  1,
  MODE_DEL   = -1
};

enum
{
  CHACCESS_NOTONCHAN = -1,
  CHACCESS_PEON      =  0,
  CHACCESS_HALFOP    =  1,
  CHACCESS_CHANOP    =  2
};

/* can_send results */
enum
{
  CAN_SEND_NO    =  0,
  CAN_SEND_NONOP = -1,
  CAN_SEND_OPV   = -2
};


/* Channel related flags */
#define CHFL_CHANOP     0x0001 /* Channel operator   */
#define CHFL_HALFOP     0x0002 /* Channel half op    */
#define CHFL_VOICE      0x0004 /* the power to speak */
#define CHFL_BAN        0x0008 /* ban channel flag */
#define CHFL_EXCEPTION  0x0010 /* exception to ban channel flag */
#define CHFL_INVEX      0x0020

/* channel modes ONLY */
#define MODE_PRIVATE    0x0001  /**< */
#define MODE_SECRET     0x0002  /**< Channel does not show up on NAMES or LIST */
#define MODE_MODERATED  0x0004  /**< Users without +v/h/o cannot send text to the channel */
#define MODE_TOPICLIMIT 0x0008  /**< Only chanops can change the topic */
#define MODE_INVITEONLY 0x0010  /**< Only invited usersmay join this channel */
#define MODE_NOPRIVMSGS 0x0020  /**< Users must be in the channel to send text to it */
#define MODE_SSLONLY    0x0040  /**< Prevents anyone who isn't connected via SSL/TLS from joining the channel */
#define MODE_OPERONLY   0x0080  /**< Prevents anyone who hasn't obtained IRC operator status from joining the channel */
#define MODE_REGISTERED 0x0100  /**< Channel has been registered with ChanServ */
#define MODE_REGONLY    0x0200  /**< Only registered clients may join a channel with that mode set */
#define MODE_NOCTRL     0x0400  /**< Prevents users from sending messages containing control codes to the channel */
#define MODE_MODREG     0x0800  /**< Unregistered/unidentified clients cannot send text to the channel */

/* cache flags for silence on ban */
#define CHFL_BAN_CHECKED  0x0080
#define CHFL_BAN_SILENCED 0x0100

/* name invisible */
#define SecretChannel(x)        (((x)->mode.mode & MODE_SECRET))
#define PubChannel(x)           (((x)->mode.mode & (MODE_PRIVATE | MODE_SECRET)) == 0)
/* knock is forbidden, halfops can't kick/deop other halfops. */
#define PrivateChannel(x)       (((x)->mode.mode & MODE_PRIVATE))

struct ChannelMode
{
  void (*func)(struct Client *,
               struct Channel *, int, int *, char **,
               int *, int, int, char, unsigned int);
  unsigned int d;
};

struct ChModeChange
{
  char letter;
  const char *arg;
  const char *id;
  int dir;
  int mems;
};

struct mode_letter
{
  const unsigned int mode;
  const unsigned char letter;
};

extern const struct mode_letter chan_modes[];
extern struct ChannelMode ModeTable[];

extern int add_id(struct Client *, struct Channel *, char *, unsigned int);
extern void set_channel_mode(struct Client *, struct Channel *,
                             struct Membership *, int, char **);
extern void clear_ban_cache(struct Channel *);
extern void clear_ban_cache_client(struct Client *);
#endif /* INCLUDED_channel_mode_h */
