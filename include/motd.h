/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 2000 Kevin L. Mitchell <klmitch@mit.edu>
 *  Copyright (C) 2013 by the Hybrid Development Team.
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

/*! \file motd.h
 * \brief Message-of-the-day manipulation implementation.
 * \version $Id$
 */

#ifndef INCLUDED_motd_h
#define INCLUDED_motd_h
struct Client;

/** Type of MOTD. */
enum MotdType
{
    MOTD_UNIVERSAL, /**< MOTD for all users */
    MOTD_HOSTMASK,  /**< MOTD selected by hostmask */
    MOTD_IPMASK,    /**< MOTD selected by IP mask */
    MOTD_CLASS      /**< MOTD selected by connection class */
};

/** Entry for a single Message Of The Day (MOTD). */
struct Motd
{
  dlink_node         node; /**< Next MOTD in the linked list. */
  enum MotdType      type;     /**< Type of MOTD. */
  char              *hostmask; /**< Hostmask if type==MOTD_HOSTMASK,
                                       class name if type==MOTD_CLASS,
                                       text IP mask if type==MOTD_IPMASK. */
  struct irc_ssaddr  address;  /**< Address if type==MOTD_IPMASK. */
  int                addrbits; /**< Number of bits checked in Motd::address. */
  char              *path;     /**< Pathname of MOTD file. */
  int                maxcount; /**< Number of lines for MOTD. */
  struct MotdCache  *cache;    /**< MOTD cache entry. */
};

/** Length of one MOTD line(80 chars + '\\0'). */
#define MOTD_LINESIZE   81
/** Maximum number of lines for MOTD */
#define MOTD_MAXLINES   100


/** Cache entry for the contents of a MOTD file. */
struct MotdCache
{
  dlink_node  node;     /**< Next MotdCache in list. */
  int         ref;      /**< Number of references to this entry. */
  char       *path;     /**< Pathname of file. */
  int         maxcount; /**< Number of lines allocated for message. */
  struct tm   modtime;  /**< Last modification time from file. */
  int         count;    /**< Actual number of lines used in message. */
  char        motd[1][MOTD_LINESIZE]; /**< Message body. */
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

/* This is called to report T-lines */
extern void motd_report(struct Client *);
extern void motd_memory_count(struct Client *);

#endif
