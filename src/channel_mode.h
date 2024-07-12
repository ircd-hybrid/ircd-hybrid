/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file channel_mode.h
 * \brief Includes channel mode related definitions and structures.
 */

#ifndef INCLUDED_channel_mode_h
#define INCLUDED_channel_mode_h


enum { CMEMBER_STATUS_FLAGS_LEN = 5 };

enum { MODEBUFLEN = 200 };

/** Maximum mode changes allowed per client, per server is different */
enum { MAXMODEPARAMS = 6 };

enum
{
  MODE_NONE,
  MODE_DEL,
  MODE_ADD
};

enum
{
  CHACCESS_NOTONCHAN = -1,
  CHACCESS_PEON,
  CHACCESS_VOICE,
  CHACCESS_HALFOP,
  CHACCESS_OP,
  CHACCESS_ADMIN,
  CHACCESS_OWNER,
  CHACCESS_REMOTE
};

enum mode_class
{
  /* A = modes that take a parameter, and add or remove nicks
   *     or addresses to a list, such as +bIe for the ban,
   *     invite, and exception lists.
   */
  MODE_CLASS_A,

  /* B = modes that change channel settings, but which take
   *     a parameter when they are set and unset, such as
   *     +k key, and -k key.
   */
  MODE_CLASS_B,

  /* C = modes that change channel settings, but which take
   *     a parameter only when they are set, such as +l N,
   *     and -l.
   */
  MODE_CLASS_C,

  /* D = modes that change channel settings, such as +imnpst
   *     and take no parameters.
   */
  MODE_CLASS_D
};

/** Channel related flags */
enum
{
  CHFL_CHANOWNER    = 1 <<  0,  /**< Channel owner (~) */
  CHFL_CHANADMIN    = 1 <<  1,  /**< Channel admin (&) */
  CHFL_CHANOP       = 1 <<  2,  /**< Channel operator (@) */
  CHFL_HALFOP       = 1 <<  3,  /**< Channel half-op (%) */
  CHFL_VOICE        = 1 <<  4,  /**< Channel voice (+) */
  CHFL_BAN          = 1 <<  5,  /* ban channel flag */
  CHFL_EXCEPTION    = 1 <<  6,  /* exception to ban channel flag */
  CHFL_INVEX        = 1 <<  7,
  /* Cache flags for silence on ban */
  CHFL_BAN_CHECKED  = 1 <<  8,
  CHFL_BAN_SILENCED = 1 <<  9,
};

/** Channel mode flags */
enum
{
  MODE_PRIVATE      = 1 <<  0,  /**< */
  MODE_SECRET       = 1 <<  1,  /**< Channel does not show up on NAMES or LIST */
  MODE_MODERATED    = 1 <<  2,  /**< Users without +v or higher cannot send text to the channel */
  MODE_TOPICLIMIT   = 1 <<  3,  /**< Only chanops or higher can change the topic */
  MODE_INVITEONLY   = 1 <<  4,  /**< Only invited users may join this channel */
  MODE_NOPRIVMSGS   = 1 <<  5,  /**< Users must be in the channel to send text to it */
  MODE_SECUREONLY   = 1 <<  6,  /**< Prevents anyone who isn't connected via TLS from joining the channel */
  MODE_OPERONLY     = 1 <<  7,  /**< Prevents anyone who hasn't obtained IRC operator status from joining the channel */
  MODE_REGISTERED   = 1 <<  8,  /**< Channel has been registered with ChanServ */
  MODE_REGONLY      = 1 <<  9,  /**< Only registered clients may join a channel with that mode set */
  MODE_NOCTRL       = 1 << 10,  /**< Prevents users from sending messages containing control codes to the channel */
  MODE_MODREG       = 1 << 11,  /**< Unregistered/unidentified clients cannot send text to the channel */
  MODE_NOCTCP       = 1 << 12,  /**< Clients cannot send CTCP messages to the channel */
  MODE_NONOTICE     = 1 << 13,  /**< Clients cannot send NOTICE to the channel */
  MODE_EXTLIMIT     = 1 << 14,  /**< Channel can make use of the extended ban list limit */
  MODE_NONICKCHANGE = 1 << 15,  /**< User is prevented from changing their nick while in this channel */
  MODE_NOKNOCK      = 1 << 16,  /**< Clients may not use KNOCK on this channel */
  MODE_NOKICK       = 1 << 17,  /**< Clients may not use KICK on this channel */
  MODE_ISSECURE     = 1 << 18,
  MODE_NOINVITE     = 1 << 19,  /**< Clients may not use INVITE on this channel */
};

#define HasCMode(x, y) ((x)->mode.mode &   (y))
#define AddCMode(x, y) ((x)->mode.mode |=  (y))
#define DelCMode(x, y) ((x)->mode.mode &= ~(y))

/* name invisible */
#define PubChannel(x)           (((x)->mode.mode & (MODE_PRIVATE | MODE_SECRET)) == 0)

struct ChModeChange
{
  char letter;
  const char *arg;
  const char *id;
  unsigned int dir;
};

struct chan_mode
{
  unsigned char letter;
  unsigned char prefix;
  unsigned int mode;
  unsigned int flag;
  enum mode_class class;
  bool only_opers;
  bool only_servers;
  int required_rank;
  int rank;
  void (*func)(struct Client *,
               struct Channel *, int, int *, char *[], int *,
               int, int, const char, const struct chan_mode *);
};

extern const struct chan_mode *cmode_map[];
extern const struct chan_mode  cmode_tab[];
extern const struct chan_mode  cflag_tab[];
extern char cmode_rpl04[][256];
extern char cmode_class[][256];

extern void channel_mode_init(void);
extern void channel_mode_set(struct Client *, struct Channel *, int, char *[]);
extern void clear_ban_cache_list(list_t *);
extern const char *add_id(struct Client *, struct Channel *, const char *, list_t *, unsigned int);
#endif  /* INCLUDED_channel_mode_h */
