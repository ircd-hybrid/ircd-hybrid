/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file channel.h
 * \brief Responsible for managing channels, bans and topics
 */

#ifndef INCLUDED_channel_h
#define INCLUDED_channel_h

#include "ircd_defs.h"        /* KEYLEN, CHANNELLEN */
#include "extban.h"
#include "address.h"

/**
 * @enum channel_send_perm_t
 * @brief Enum for representing the send permission of a client in a channel.
 *
 * This enum lists the possible permissions indicating whether a client can send messages to a channel,
 * including their level of permission.
 */
typedef enum
{
  CHANNEL_SEND_PERM_FORBIDDEN,  /**< Client cannot send messages to the channel. */
  CHANNEL_SEND_PERM_STANDARD,  /**< Client can send messages to the channel but is not an operator. */
  CHANNEL_SEND_PERM_ELEVATED,  /**< Client can send messages to the channel as an operator, half-operator, or voiced. */
} channel_send_perm_t;

struct Client;

/** Mode structure for channels */
struct ChannelMode
{
  uint32_t flags;  /**< Simple modes */
  uint32_t member_limit;  /**< +l userlimit */
  char key[KEYLEN + 1];  /**< +k key */
};

/** Channel structure */
struct Channel
{
  list_node_t node;  /**< List node; linked into channel_list */
  struct Channel *hash_next;  /**< Pointer to the next Channel with the same hash value */
  char name[CHANNELLEN + 1];  /**< Unique name of the channel */
  size_t name_len;  /**< Cached string length of Channel::name */
  struct ChannelMode mode;
  char *mode_lock;
  char *topic;
  char *topic_setter;
  uintmax_t creation_time;  /**< Time the channel has been created; real time */
  uintmax_t topic_time;  /**< Modification time of the topic; real time */
  uintmax_t mode_lock_time;  /**< Real time; this gets set by services only */
  uintmax_t last_knock_time;  /**< Don't allow knock to flood; monotonic time */
  uintmax_t last_invite_time;  /**< Last time an INVITE to this channel has been issued; monotonic time */
  uintmax_t last_join_time;  /**< Last time a user has joined the channel; monotonic time */
  uintmax_t first_received_message_time;  /**< Channel flood control; monotonic time */
  uint32_t received_privmsg_count;
  float number_joined;
  bool sent_join_flood_notice;  /**< Indicates whether a server notice about a join flood event has been sent to IRC operators. */
  bool sent_message_flood_notice;  /**< Indicates whether a server notice about a message flood event has been sent to IRC operators. */
  list_t local_member_list;  /**< List of local members on this channel */
  list_t member_list;  /**< List of members on this channel */
  list_t invite_list;  /**< List of invites on this channel */
  list_t ban_list;  /**< List of bans on this channel */
  list_t exception_list;  /**< List of ban exceptions on this channel */
  list_t invite_exception_list;  /**< List of invite exceptions on this channel */
};

enum { BANSTRLEN = 200 }; /* XXX */

/** Ban structure. Used for b/e/I n!u\@h masks */
struct Ban
{
  list_node_t node;
  uint32_t extban;
  char banstr[BANSTRLEN];
  char name[NICKLEN + 1];
  char user[USERLEN + 1];
  char host[HOSTLEN + 1];
  char who[NICKLEN + USERLEN + HOSTLEN + 3];
  size_t banstr_len;  /**< Cached string length of Ban::banstr */
  uintmax_t when;  /**< Time this ban has been set; real time */
  struct io_addr addr;
  int bits;
  int type;
};

extern void channel_destroy(struct Channel *);
extern void channel_flood_record_join(struct Channel *, const struct Client *);
extern void channel_join(struct Client *, const char *, const char *);
extern void channel_join_list(struct Client *, char *, char *);
extern void channel_part(struct Client *, const char *, const char *);
extern void channel_part_list(struct Client *, char *, const char *);
extern void channel_send_namereply(struct Client *, struct Channel *);
extern void channel_send_state(struct Client *, const struct Channel *);
extern void channel_set_mode_lock(struct Client *, struct Channel *, const char *);
extern void channel_set_topic(struct Channel *, const char *, const char *, uintmax_t, bool);
extern void remove_ban(struct Ban *, list_t *);
extern bool channel_is_valid_name(const char *, bool);
extern bool find_bmask(struct Client *, struct Channel*, const list_t *, struct Extban *);
extern bool is_banned(struct Channel *, struct Client *, struct Extban *);
extern channel_send_perm_t channel_send_qualifies(struct Channel *, struct Client *, struct ChannelMember *, unsigned int, const char *, bool, const char **);
extern struct Channel *channel_create(const char *);
extern struct Channel *channel_find(const char *);
extern const list_t *channel_get_list(void);
extern const char *channel_modes(const struct Channel *, const struct Client *, bool);

static inline bool
channel_is_empty(const struct Channel *channel)
{
  assert(channel);
  return list_is_empty(&channel->member_list);
}

static inline bool
channel_has_key(const struct Channel *channel)
{
  assert(channel);
  return channel->mode.key[0] != '\0';
}

static inline bool
channel_has_member_limit(const struct Channel *channel)
{
  assert(channel);
  return channel->mode.member_limit != 0;
}
#endif  /* INCLUDED_channel_h */
