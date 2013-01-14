/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  defaults.h: The ircd defaults header for values and paths.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
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
 * MSGPATH     = directory for language files
 * ETCPATH     = directory for configuration files
 * LOGPATH     = directory for logfiles
 * MODPATH     = directory for modules
 * AUTOMODPATH = directory for autoloaded modules
 */

/* dirs */
#define DPATH       PREFIX                                                     
#define SBINPATH    PREFIX "/sbin/"
#define BINPATH     PREFIX "/bin/"
#define	MSGPATH		  DATADIR "/" PACKAGE "/messages"
#define MODPATH		  LIBDIR "/" PACKAGE "/modules/"
#define HPATH		    DATADIR "/" PACKAGE "/help/opers"
#define UHPATH		  DATADIR "/" PACKAGE "/help/users"
#define AUTOMODPATH	MODPATH "/autoload/"
#define ETCPATH     SYSCONFDIR
#define	LOGPATH		  LOCALSTATEDIR "/log"
#define RUNPATH           LOCALSTATEDIR "/run"

/* files */
#define SPATH   SBINPATH "/ircd"                /* ircd executable */
#define CPATH   ETCPATH "/ircd.conf"            /* ircd.conf file */
#define KPATH   ETCPATH "/kline.db"           /* kline file */
#define RESVPATH ETCPATH "/resv.db" /* resv file */
#define DLPATH  ETCPATH "/dline.db"           /* dline file */
#define XPATH   ETCPATH "/xline.db"           /* xline file */
#define GPATH  ETCPATH "/gline.db"           /* gline file */
#define MPATH   ETCPATH "/ircd.motd"            /* MOTD file */
#define LPATH   LOGPATH "/ircd.log"             /* ircd logfile */
#define PPATH   RUNPATH "/ircd.pid"             /* pid file */
#define LIPATH  ETCPATH "/links.txt"            /* cached links file */

/*
 * This file is included to supply default values for things which
 * are now configurable at runtime.
 */

#define HYBRID_SOMAXCONN 25
#define MAX_TDKLINE_TIME	(24*60*360)

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

#define WATCHSIZE_MIN 1
#define WATCHSIZE_DEFAULT 32
#define TS_MAX_DELTA_MIN      10        /* min value for ts_max_delta */
#define TS_MAX_DELTA_DEFAULT  600       /* default for ts_max_delta */
#define TS_WARN_DELTA_MIN     10        /* min value for ts_warn_delta */
#define TS_WARN_DELTA_DEFAULT 30        /* default for ts_warn_delta */

/* ServerInfo default values */
#define NETWORK_NAME_DEFAULT "EFnet"             /* default for network_name */
#define NETWORK_DESC_DEFAULT "Eris Free Network" /* default for network_desc */
#define SERVICE_NAME_DEFAULT "service.someserver"

#define GLINE_REQUEST_EXPIRE_DEFAULT 600

/* General defaults */
#define MAXIMUM_LINKS_DEFAULT 0         /* default for maximum_links */

#define LINKS_DELAY_DEFAULT  300

#define MAX_TARGETS_DEFAULT 4           /* default for max_targets */

#define INIT_LOG_LEVEL L_NOTICE         /* default for log_level */

#define CONNECTTIMEOUT  30      /* Recommended value: 30 */
#define IDENT_TIMEOUT 10

#define MIN_JOIN_LEAVE_TIME  60
#define MAX_JOIN_LEAVE_COUNT  25
#define OPER_SPAM_COUNTDOWN   5 
#define JOIN_LEAVE_COUNT_EXPIRE_TIME 120

#define MIN_SPAM_NUM 5
#define MIN_SPAM_TIME 60

#endif /* INCLUDED_defaults_h */
