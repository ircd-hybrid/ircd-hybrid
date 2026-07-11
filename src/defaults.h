/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
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
 */

/* dirs */
#define DPATH        PREFIX
#define BINPATH      PREFIX "/bin/"
#define HPATH        DATADIR "/" PACKAGE "/help"
#define ETCPATH      SYSCONFDIR
#define LIBPATH      LOCALSTATEDIR "/lib"
#define LOGPATH      LOCALSTATEDIR "/log"
#define RUNPATH      LOCALSTATEDIR "/run"

/* files */
#define SPATH     BINPATH "/ircd"  /* ircd executable */
#define CPATH     ETCPATH "/ircd.conf"  /* ircd.conf file */
#define KPATH     LIBPATH "/kline.json"  /* kline file */
#define RESVPATH  LIBPATH "/resv.json"  /* resv file */
#define DLPATH    LIBPATH "/dline.json"  /* dline file */
#define XPATH     LIBPATH "/xline.json"  /* xline file */
#define LPATH     LOGPATH "/ircd.log"  /* ircd logfile */
#define PPATH     RUNPATH "/ircd.pid"  /* pid file */

/* tests show that about 7 fds are not registered by fdlist.c, these
 * include std* descriptors + some others (by OpenSSL etc.). Note this is
 * intentionally too high, we don't want to eat fds up to the last one */
#define LEAKED_FDS       10
/* how many (privileged) clients can exceed max_clients */
#define MAX_BUFFER       60

#define MAXCLIENTS_MAX   (hard_fdlimit - LEAKED_FDS - MAX_BUFFER)
#define MAXCLIENTS_MIN   32

/* class {} default values */
#define CLIENT_FLOOD_MIN     512

/* ConfigServerInfo default values */
#define NETWORK_NAME_DEFAULT "2600net"  /* default for network_name */
#define NETWORK_DESCRIPTION_DEFAULT "2600net IRC Network"  /* default for network_description */

/* General defaults */
#define CONNECTTIMEOUT  30      /* Recommended value: 30 */

#define MIN_JOIN_LEAVE_TIME  60
#define MAX_JOIN_LEAVE_COUNT  25
#define OPER_SPAM_COUNTDOWN   5
#define JOIN_LEAVE_COUNT_EXPIRE_TIME 120

#define MIN_SPAM_NUM 5
#define MIN_SPAM_TIME 60
#endif  /* INCLUDED_defaults_h */
