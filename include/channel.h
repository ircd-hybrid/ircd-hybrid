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

/*! \file channel.h
 * \brief Responsible for managing channels, members, bans and topics
 */

#ifndef INCLUDED_channel_h
#define INCLUDED_channel_h

#include "ircd_defs.h"        /* KEYLEN, CHANNELLEN */
#include "extban.h"

#define AddMemberFlag(x, y) ((x)->flags |=  (y))
#define DelMemberFlag(x, y) ((x)->flags &= ~(y))

enum
{
  CAN_SEND_NO,
  CAN_SEND_NONOP,
  CAN_SEND_OPV
};

struct Client;

/** Mode structure for channels */
struct Mode
{
  unsigned int mode;  /**< Simple modes */
  unsigned int limit;  /**< +l userlimit */
  char key[KEYLEN + 1];  /**< +k key */
};

/** Channel structure */
struct Channel
{
  list_node_t node;  /**< List node; linked into channel_list */

  struct Channel *hnextch;  /**< Pointer to the next Channel with the same hash value */
  struct Mode mode;

  char topic[TOPICLEN + 1];
  char topic_info[NICKLEN + USERLEN + HOSTLEN + 3];

  uintmax_t creation_time;  /**< Time the channel has been created; real time */
  uintmax_t topic_time;  /**< Modification time of the topic; real time */
  uintmax_t mode_lock_time;  /**< Real time; this gets set by services only */
  uintmax_t last_knock_time;  /**< Don't allow knock to flood; monotonic time */
  uintmax_t last_invite_time;  /**< Last time an INVITE to this channel has been issued; monotonic time */
  uintmax_t last_join_time;  /**< Last time a user has joined the channel; monotonic time */
  uintmax_t first_received_message_time;  /**< Channel flood control; monotonic time */
  unsigned int received_number_of_privmsgs;

  bool sent_join_flood_notice;  /**< Indicates whether a server notice about a join flood event has been sent to IRC operators. */
  bool sent_message_flood_notice;  /**< Indicates whether a server notice about a message flood event has been sent to IRC operators. */

  list_t members_local;  /**< List of local members on this channel */
  list_t members;  /**< List of members on this channel */
  list_t invites;  /**< List of invites on this channel */
  list_t banlist;  /**< List of bans on this channel */
  list_t exceptlist;  /**< List of ban exceptions on this channel */
  list_t invexlist;  /**< List of invite exceptions on this channel */

  float number_joined;

  char *mode_lock;
  char name[CHANNELLEN + 1];  /**< Unique name of the channel */
  size_t name_len;  /**< Cached string length of Channel::name */
};

/** ChannelMember structure */
struct ChannelMember
{
  list_node_t locchannode;  /**< link to channel->members_local */
  list_node_t channode;  /**< link to channel->members */
  list_node_t usernode;  /**< link to client->channel */
  struct Channel *channel;  /**< Channel pointer */
  struct Client *client;  /**< Client pointer */
  unsigned int flags;  /**< user/channel flags, e.g. CHFL_CHANOP */
};

enum { BANSTRLEN = 200 }; /* XXX */

/** Ban structure. Used for b/e/I n!u\@h masks */
struct Ban
{
  list_node_t node;
  unsigned int extban;
  char banstr[BANSTRLEN];
  char name[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  char who[NICKLEN + USERLEN + HOSTLEN + 3];
  size_t banstr_len;  /**< Cached string length of Ban::banstr */
  uintmax_t when;  /**< Time this ban has been set; real time */
  struct irc_ssaddr addr;
  int bits;
  int type;
};

extern const list_t *channel_get_list(void);
extern bool channel_check_name(const char *, bool);
extern int can_send(struct Channel *, struct Client *, struct ChannelMember *, const char *, bool, const char **);
extern bool is_banned(struct Channel *, struct Client *, struct Extban *);
extern bool find_bmask(struct Client *, struct Channel*, const list_t *, struct Extban *);
extern bool member_has_flags(const struct ChannelMember *, const unsigned int);

extern void channel_join_list(struct Client *, char *, char *);
extern void channel_part_list(struct Client *, char *, const char *);
extern void remove_ban(struct Ban *, list_t *);
extern void channel_add_user(struct Channel *, struct Client *, unsigned int, bool);
extern void channel_remove_user(struct ChannelMember *);
extern void channel_demote_members(struct Channel *, const struct Client *);
extern void channel_send_namereply(struct Client *, struct Channel *);
extern void channel_send_modes(struct Client *, const struct Channel *);
extern const char *channel_modes(const struct Channel *, const struct Client *, bool);
extern void channel_free(struct Channel *);
extern void channel_set_mode_lock(struct Client *, struct Channel *, const char *);
extern void channel_set_topic(struct Channel *, const char *, const char *, uintmax_t, bool);

extern const char *member_get_prefix(const struct ChannelMember *, bool);
extern size_t member_get_prefix_len(const struct ChannelMember *, bool);
extern int member_highest_rank(const struct ChannelMember *);
extern int channel_prefix_to_rank(const char);
extern const char *channel_rank_to_prefix(const int);
extern unsigned int channel_prefix_to_flag(const char);

extern struct Channel *channel_make(const char *);
extern struct ChannelMember *member_find_link(const struct Client *, const struct Channel *);
#endif  /* INCLUDED_channel_h */
