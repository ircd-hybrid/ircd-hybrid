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

/*! \file send.h
 * \brief A header for the message sending functions.
 */

#ifndef INCLUDED_send_h
#define INCLUDED_send_h

#include "io.h"
#include "fdlist.h"
#include "numeric.h"

/**
 * @enum send_recipient
 * @brief Enum for representing the recipients of sending notices.
 *
 * This enum lists the possible recipients for sending notices using the sendto_clients function.
 * Each recipient specifies a different group of clients or operators who should receive the notice.
 */
typedef enum
{
  SEND_RECIPIENT_OPER_ALL,  /**< Send to all operators, regardless of their administrator status. */
  SEND_RECIPIENT_OPER,  /**< Send to regular operators only (excluding administrators). */
  SEND_RECIPIENT_ADMIN,  /**< Send to administrators only. */
  SEND_RECIPIENT_CLIENT,  /**< Send to all connected clients. */
} send_recipient;

/**
 * @enum send_type
 * @brief Enum for representing the types of notices to be sent.
 *
 * This enum lists the possible types of notices that can be sent using the sendto_clients function.
 * Each type specifies a different scope or category of the notice, which is used as a prefix in the message.
 */
typedef enum
{
  SEND_TYPE_NOTICE,  /**< A general notice message. Prefix: "Notice". */
  SEND_TYPE_GLOBAL,  /**< A global notice message. Prefix: "Global". */
  SEND_TYPE_LOCOPS,  /**< A notice message sent to local operators. Prefix: "LocOps". */
} send_type;

/*
 * struct decls
 */
struct Channel;
struct Client;

/* send.c prototypes */
extern void sendq_unblocked(fde_t *, void *);
extern void send_queued_write(struct Client *);
extern void sendto_one(struct Client *, const char *, ...) IO_AFP(2,3);
extern void sendto_one_numeric(struct Client *, const struct Client *, enum irc_numerics, ...);
extern void sendto_one_notice(struct Client *, const struct Client *, const char *, ...) IO_AFP(3,4);
extern void sendto_channel_butone(struct Client *, const struct Client *, struct Channel *, int, const char *, ...) IO_AFP(5,6);
extern void sendto_common_channels_local(struct Client *, bool, unsigned int, unsigned int, const char *, ...) IO_AFP(5,6);
extern void sendto_channel_local(const struct Client *, struct Channel *, int, unsigned int, unsigned int, const char *, ...) IO_AFP(6,7);
extern void sendto_servers(const struct Client *, const unsigned int, const unsigned int, const char *, ...) IO_AFP(4,5);
extern void sendto_match_butone(const struct Client *, const struct Client *, const char *, bool, const char *, ...) IO_AFP(5,6);
extern void sendto_match_servs(const struct Client *, const char *, unsigned int, const char *, ...) IO_AFP(4,5);
extern void sendto_clients(unsigned int, send_recipient, send_type, const char *, ...) IO_AFP(4,5);
extern void sendto_wallops_flags(unsigned int, const struct Client *, const char *, ...) IO_AFP(3,4);
extern void sendto_clients_ratelimited(uintmax_t *, const char *, ...) IO_AFP(2,3);
extern void sendto_anywhere(struct Client *, const struct Client *, const char *, const char *, ...) IO_AFP(4,5);
#endif  /* INCLUDED_send_h */
