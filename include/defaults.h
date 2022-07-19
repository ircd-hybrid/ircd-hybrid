/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file defaults.h
 * \brief The ircd defaults header for values and paths.
 */

#ifndef INCLUDED_defaults_h
#define INCLUDED_defaults_h

/* Here are some default paths. Most except DPATH are
 * configurable at runtime. */

/*
 * Directory paths and filenames for UNIX systems.
 * PREFIX is set using ./configure --prefix, see INSTALL.
 * The other defaults should be fine.
 *
 * NOTE: CHANGING THESE WILL NOT ALTER THE DIRECTORY THAT FILES WILL
 *       BE INSTALLED TO.  IF YOU CHANGE THESE, DO NOT USE MAKE INSTALL,
 *       BUT COPY THE FILES MANUALLY TO WHERE YOU WANT THEM.
 *
 * PREFIX = prefix for all directories
 * DPATH       = root directory of installation
 * BINPATH     = directory for binary files
 * ETCPATH     = directory for configuration files
 * LOGPATH     = directory for logfiles
 * MODPATH     = directory for modules
 * AUTOMODPATH = directory for autoloaded modules
 */

/* dirs */
#define DPATH        PREFIX
#define BINPATH      PREFIX "/bin/"
#define MODPATH      LIBDIR "/" PACKAGE "/modules/"
#define HPATH        DATADIR "/" PACKAGE "/help"
#define AUTOMODPATH  MODPATH "/autoload/"
#define ETCPATH      SYSCONFDIR
#define LIBPATH      LOCALSTATEDIR "/lib"
#define LOGPATH      LOCALSTATEDIR "/log"
#define RUNPATH      LOCALSTATEDIR "/run"

/* files */
#define SPATH     BINPATH "/ircd"  /* ircd executable */
#define CPATH     ETCPATH "/ircd.conf"  /* ircd.conf file */
#define KPATH     LIBPATH "/kline.db"  /* kline file */
#define RESVPATH  LIBPATH "/resv.db"  /* resv file */
#define DLPATH    LIBPATH "/dline.db"  /* dline file */
#define XPATH     LIBPATH "/xline.db"  /* xline file */
#define MPATH     ETCPATH "/ircd.motd"  /* MOTD file */
#define LPATH     LOGPATH "/ircd.log"  /* ircd logfile */
#define PPATH     RUNPATH "/ircd.pid"  /* pid file */

/*
 * This file is included to supply default values for things which
 * are now configurable at runtime.
 */

#define HYBRID_SOMAXCONN 25
#define MAX_TDKLINE_TIME  (24*60*360)

/* tests show that about 7 fds are not registered by fdlist.c, these
 * include std* descriptors + some others (by OpenSSL etc.). Note this is
 * intentionally too high, we don't want to eat fds up to the last one */
#define LEAKED_FDS       10
/* how many (privileged) clients can exceed max_clients */
#define MAX_BUFFER       60

#define MAXCLIENTS_MAX   (hard_fdlimit - LEAKED_FDS - MAX_BUFFER)
#define MAXCLIENTS_MIN   32

/* class {} default values */
#define DEFAULT_SENDQ 9000000           /* default max SendQ */
#define DEFAULT_RECVQ 2560           /* default max RecvQ */
#define PORTNUM 6667                    /* default outgoing portnum */
#define DEFAULT_PINGFREQUENCY    120    /* Default ping frequency */
#define DEFAULT_CONNECTFREQUENCY 600    /* Default connect frequency */
#define CLIENT_FLOOD_MAX     8000
#define CLIENT_FLOOD_MIN     512

/* ConfigServerInfo default values */
#define NETWORK_NAME_DEFAULT "2600net"  /* default for network_name */
#define NETWORK_DESCRIPTION_DEFAULT "2600net IRC Network"  /* default for network_description */

/* General defaults */
#define LINKS_DELAY_DEFAULT  300

#define MAX_TARGETS_DEFAULT 4           /* default for max_targets */

#define CONNECTTIMEOUT  30      /* Recommended value: 30 */

#define MIN_JOIN_LEAVE_TIME  60
#define MAX_JOIN_LEAVE_COUNT  25
#define OPER_SPAM_COUNTDOWN   5
#define JOIN_LEAVE_COUNT_EXPIRE_TIME 120

#define MIN_SPAM_NUM 5
#define MIN_SPAM_TIME 60
#endif  /* INCLUDED_defaults_h */
