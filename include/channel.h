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

/*! \file channel.h
 * \brief Responsible for managing channels, members, bans and topics
 * \version $Id$
 */

#ifndef INCLUDED_channel_h
#define INCLUDED_channel_h

#include "ircd_defs.h"        /* KEYLEN, CHANNELLEN */

/* channel visible */
#define ShowChannel(v,c)        (PubChannel(c) || IsMember((v),(c)))

#define IsMember(who, chan) ((find_channel_link(who, chan)) ? 1 : 0)
#define AddMemberFlag(x, y) ((x)->flags |=  (y))
#define DelMemberFlag(x, y) ((x)->flags &= ~(y))

enum
{
  MSG_FLOOD_NOTICED  = 0x00000001U,
  JOIN_FLOOD_NOTICED = 0x00000002U
};

#define SetFloodNoticed(x)   ((x)->flags |= MSG_FLOOD_NOTICED)
#define IsSetFloodNoticed(x) ((x)->flags & MSG_FLOOD_NOTICED)
#define ClearFloodNoticed(x) ((x)->flags &= ~MSG_FLOOD_NOTICED)

#define SetJoinFloodNoticed(x)   ((x)->flags |= JOIN_FLOOD_NOTICED)
#define IsSetJoinFloodNoticed(x) ((x)->flags & JOIN_FLOOD_NOTICED)
#define ClearJoinFloodNoticed(x) ((x)->flags &= ~JOIN_FLOOD_NOTICED)

struct Client;

/*! \brief Mode structure for channels */
struct Mode
{
  unsigned int mode;   /**< simple modes */
  unsigned int limit;  /**< +l userlimit */
  char key[KEYLEN + 1];    /**< +k key */
};

/*! \brief Channel structure */
struct Channel
{
  dlink_node node;

  struct Channel *hnextch;
  struct Mode mode;

  char topic[TOPICLEN + 1];
  char topic_info[USERHOST_REPLYLEN];

  time_t creationtime;
  time_t topic_time;
  time_t last_knock;  /**< Don't allow knock to flood */
  time_t last_join_time;
  time_t first_received_message_time; /*!< channel flood control */
  unsigned int flags;
  int received_number_of_privmsgs;

  dlink_list locmembers;  /*!< local members are here too */
  dlink_list members;
  dlink_list invites;
  dlink_list banlist;
  dlink_list exceptlist;
  dlink_list invexlist;

  float number_joined;

  char name[CHANNELLEN + 1];
};

/*! \brief Membership structure */
struct Membership
{
  dlink_node locchannode;  /**< link to chptr->locmembers */
  dlink_node channode;     /**< link to chptr->members    */
  dlink_node usernode;     /**< link to source_p->channel */
  struct Channel *chptr;   /**< Channel pointer */
  struct Client *client_p; /**< Client pointer */
  unsigned int flags;      /**< user/channel flags, e.g. CHFL_CHANOP */
};

/*! \brief Ban structure. Used for b/e/I n!u\@h masks */
struct Ban
{
  dlink_node node;
  char name[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  char who[NICKLEN + USERLEN + HOSTLEN + 3];
  size_t len;
  time_t when;
  struct irc_ssaddr addr;
  int bits;
  int type;
};

extern dlink_list channel_list;

extern int channel_check_name(const char *, const int);
extern int can_send(struct Channel *, struct Client *, struct Membership *, const char *);
extern int is_banned(const struct Channel *, const struct Client *);
extern int can_join(struct Client *, const struct Channel *, const char *);
extern int has_member_flags(const struct Membership *, const unsigned int);

extern void channel_do_join(struct Client *, char *, char *);
extern void channel_do_join_0(struct Client *);
extern void channel_do_part(struct Client *, char *, const char *);
extern void remove_ban(struct Ban *, dlink_list *);
extern void channel_init(void);
extern void add_user_to_channel(struct Channel *, struct Client *, unsigned int, int);
extern void remove_user_from_channel(struct Membership *);
extern void channel_member_names(struct Client *, struct Channel *, int);
extern void add_invite(struct Channel *, struct Client *);
extern void del_invite(struct Channel *, struct Client *);
extern void clear_invites_channel(struct Channel *);
extern void clear_invites_client(struct Client *);
extern void channel_send_modes(struct Client *, struct Channel *);
extern void channel_modes(struct Channel *, struct Client *, char *, char *);
extern void check_spambot_warning(struct Client *, const char *);
extern void channel_free(struct Channel *);
extern void channel_set_topic(struct Channel *, const char *, const char *, time_t, int);

extern const char *get_member_status(const struct Membership *, const int);

extern struct Channel *channel_make(const char *);
extern struct Membership *find_channel_link(struct Client *, struct Channel *);
#endif
