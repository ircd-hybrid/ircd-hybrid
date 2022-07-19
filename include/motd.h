/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (c) 2013-2022 ircd-hybrid development team
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

/*! \file motd.h
 * \brief Message-of-the-day manipulation implementation.
 */

#ifndef INCLUDED_motd_h
#define INCLUDED_motd_h

/** Type of MOTD. */
enum MotdType
{
  MOTD_UNIVERSAL, /**< MOTD for all users */
  MOTD_HOSTMASK,  /**< MOTD selected by hostmask */
  MOTD_IPMASKV4,  /**< MOTD selected by IPv4 mask */
  MOTD_IPMASKV6,  /**< MOTD selected by IPv6 mask */
  MOTD_CLASS      /**< MOTD selected by connection class */
};

/** Length of one MOTD line(320 chars + '\\0'). */
enum { MOTD_LINESIZE = 321 };
/** Maximum number of lines for MOTD */
enum { MOTD_MAXLINES = 100 };

/** Entry for a single Message Of The Day (MOTD). */
struct Motd
{
  dlink_node node;  /**< Next MOTD in the linked list. */
  enum MotdType type;  /**< Type of MOTD. */
  char *path;  /**< Pathname of MOTD file. */
  char *mask;  /**< Hostmask if type==MOTD_HOSTMASK,
                    class name if type==MOTD_CLASS,
                    text IP mask if type==MOTD_IPMASK. */
  struct irc_ssaddr address;  /**< Address if type==MOTD_IPMASK. */
  int addrbits;  /**< Number of bits checked in Motd::address. */
  unsigned int maxcount;  /**< Number of lines for MOTD. */
  struct MotdCache *cache;  /**< MOTD cache entry. */
};

/** Cache entry for the contents of a MOTD file. */
struct MotdCache
{
  dlink_node node;  /**< Next MotdCache in list. */
  char *path;  /**< Pathname of file. */
  unsigned int ref;  /**< Number of references to this entry. */
  unsigned int maxcount;  /**< Number of lines allocated for message. */
  unsigned int count;  /**< Actual number of lines used in message. */
  uintmax_t modtime;  /**< Last modification time from file. */
  char motd[][MOTD_LINESIZE];  /**< Message body. */
};

/* motd_send sends a MOTD off to a user */
extern void motd_send(struct Client *);

/* motd_signon sends a MOTD off to a newly-registered user */
extern void motd_signon(struct Client *);

/* motd_recache causes all the MOTD caches to be cleared */
extern void motd_recache(void);

/* motd_init initializes the MOTD routines, including reading the
 * ircd.motd and remote.motd files into cache
 */
extern void motd_init(void);

/* This routine adds a MOTD */
extern void motd_add(const char *, const char *);

/* This routine clears the list of MOTDs */
extern void motd_clear(void);

/* This is called to report motd {} blocks */
extern void motd_report(struct Client *, int, char *[]);
extern void motd_memory_count(struct Client *);
#endif  /* INCLUDED_motd_h */
