/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_log.c: Logger functions.
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

#include "stdinc.h"

#ifdef USE_SYSLOG
# ifdef HAVE_SYS_SYSLOG_H
#  include <sys/syslog.h>
# else
#  ifdef HAVE_SYSLOG_H
#   include <syslog.h>
#  endif
# endif
#endif

#include "client.h"	/* Needed for struct Client */
#include "common.h"
#include "s_log.h"
#include "fileio.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "s_misc.h"
#include "event.h"	/* Needed for EVH etc. */
#include "s_conf.h"
#include "memory.h"

/* some older syslogs would overflow at 2024 */
#define LOG_BUFSIZE 2000

static FBFILE *logFile;
static int logLevel = INIT_LOG_LEVEL;

#ifndef SYSLOG_USERS
static EVH user_log_resync;
static FBFILE *user_log_fb = NULL;
#endif


#ifdef USE_SYSLOG
static const int sysLogLevel[] =
{
  LOG_CRIT,
  LOG_ERR,
  LOG_WARNING,
  LOG_NOTICE,
  LOG_INFO,
  LOG_INFO,
  LOG_INFO
};
#endif

static const char *logLevelToString[] =
{
  "L_CRIT",
  "L_ERROR",
  "L_WARN",
  "L_NOTICE",
  "L_TRACE",
  "L_INFO",
  "L_DEBUG"
};

/*
 * open_log - open ircd logging file
 * returns true (1) if successful, false (0) otherwise
 */
static int 
open_log(const char *filename)
{
  logFile = fbopen(filename, "a");

  if (logFile == NULL)
  {
#ifdef USE_SYSLOG
    syslog(LOG_ERR, "Unable to open log file: %s: %s",
           filename, strerror(errno));
#endif
    return (0);
  }

  return (1);
}

static void 
write_log(const char *message)
{
  char buf[LOG_BUFSIZE];
  size_t nbytes = 0;

  if (logFile == NULL)
    return;

  nbytes = snprintf(buf, sizeof(buf), "[%s] %s\n",
                    smalldate(CurrentTime), message);

  fbputs(buf, logFile, nbytes);
}
   
void
ilog(const int priority, const char *fmt, ...)
{
  char buf[LOG_BUFSIZE];
  va_list args;

  assert(priority > -1);

  if (fmt == NULL)
    return;

  if (priority > logLevel)
    return;

  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);

#ifdef USE_SYSLOG  
  if (priority <= L_DEBUG)
    syslog(sysLogLevel[priority], "%s", buf);
#endif
  if (ConfigLoggingEntry.use_logging)
    write_log(buf);
}
  
void
init_log(const char *filename)
{
  open_log(filename);
#ifdef USE_SYSLOG
  openlog("ircd", LOG_PID | LOG_NDELAY, LOG_FACILITY);
#endif
#ifndef SYSLOG_USERS
  eventAddIsh("user_log_resync", user_log_resync, NULL, 60);
#endif
}

void
reopen_log(const char *filename)
{
  if (logFile != NULL)
    fbclose(logFile);
  open_log(filename);
}

void
set_log_level(const int level)
{
  if (L_ERROR < level && level <= L_DEBUG)
    logLevel = level;
}

int
get_log_level(void)
{
  return(logLevel);
}

const char *
get_log_level_as_string(int level)
{
  if (level > L_DEBUG)
    level = L_DEBUG;
  else if (level < L_ERROR)
    level = L_ERROR;

  return(logLevelToString[level]);
}

/* log_user_exit()
 *
 * inputs	- pointer to connecting client
 * output	- NONE
 * side effects - Current exiting client is logged to
 *		  either SYSLOG or to file.
 */
void
log_user_exit(struct Client *source_p)
{
  time_t on_for = CurrentTime - source_p->firsttime;
#ifdef SYSLOG_USERS
  if (IsClient(source_p))
  {
    ilog(L_INFO, "%s (%3u:%02u:%02u): %s!%s@%s %llu/%llu",
         myctime(source_p->firsttime), (unsigned int)(on_for / 3600),
         (unsigned int)((on_for % 3600)/60), (unsigned int)(on_for % 60),
         source_p->name, source_p->username, source_p->host,
         source_p->localClient->send.bytes>>10,
         source_p->localClient->recv.bytes>>10);
    }
#else
  {
    char linebuf[BUFSIZ];

    /*
     * This conditional makes the logfile active only after
     * it's been created - thus logging can be turned off by
     * removing the file.
     * -Taner
     */
    if (IsClient(source_p))
    {
      if (user_log_fb == NULL)
      {
	if ((ConfigLoggingEntry.userlog[0] != '\0') && 
	   (user_log_fb = fbopen(ConfigLoggingEntry.userlog, "r")) != NULL)
	{
	  fbclose(user_log_fb);
	  user_log_fb = fbopen(ConfigLoggingEntry.userlog, "a");
	}
      }

      if (user_log_fb != NULL)
      {
        size_t nbytes = ircsprintf(linebuf,
		   "%s (%3u:%02u:%02u): %s!%s@%s %llu/%llu\n",
		   myctime(source_p->firsttime),
		   (unsigned int)(on_for / 3600),
		   (unsigned int)((on_for % 3600)/60),
		   (unsigned int)(on_for % 60),
		   source_p->name, source_p->username, source_p->host,
		   source_p->localClient->send.bytes>>10,
		   source_p->localClient->recv.bytes>>10);
	fbputs(linebuf, user_log_fb, nbytes);
      }
    }
  }
#endif
}

#ifndef SYSLOG_USERS
/* user_log_resync()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects	-
 */
static void
user_log_resync(void *notused)
{
  if (user_log_fb != NULL)
  {
    fbclose(user_log_fb);
    user_log_fb = NULL;
  }
}
#endif

/* log_oper_action()
 *
 * inputs	- type of oper log entry
 *		- pointer to oper
 *              - const char *pattern == format string
 *		- var args for format string
 * output	- none
 * side effects - corresponding log is written to, if its present.
 *
 * rewritten sept 5 2005 - Dianora
 */
void
log_oper_action(int log_type, const struct Client *source_p, 
		const char *pattern, ...)
{
  va_list args;
  char linebuf[IRCD_BUFSIZE];
  FBFILE *log_fb;
  char *logfile;
  const char *log_message;
  size_t nbytes;
  size_t n_preamble;
  char *p;

  switch(log_type)
  {
  case LOG_OPER_TYPE:
    logfile = ConfigLoggingEntry.operlog;
    log_message = "OPER";
    break;
  case LOG_FAILED_OPER_TYPE:
    logfile = ConfigLoggingEntry.failed_operlog;
    log_message = "FAILED OPER";
    break;
  case LOG_KLINE_TYPE:
    logfile = ConfigLoggingEntry.klinelog;
    log_message = "KLINE";
    break;
  case LOG_RKLINE_TYPE:
    logfile = ConfigLoggingEntry.klinelog;
    log_message = "RKLINE";
    break;
  case LOG_DLINE_TYPE:
    logfile = ConfigLoggingEntry.klinelog;
    log_message = "DLINE";
    break;
  case LOG_TEMP_DLINE_TYPE:
    logfile = ConfigLoggingEntry.klinelog;
    log_message = "TEMP DLINE";
    break;
  case LOG_TEMP_KLINE_TYPE:
    logfile = ConfigLoggingEntry.klinelog;
    log_message = "TEMP KLINE";
    break;
  case LOG_GLINE_TYPE:
    logfile = ConfigLoggingEntry.glinelog;
    log_message = "GLINE";
    break;
  case LOG_KILL_TYPE:
    logfile = ConfigLoggingEntry.killlog;
    log_message = "KILL";
    break;
  case LOG_IOERR_TYPE:
    logfile = ConfigLoggingEntry.ioerrlog;
    log_message = "IO ERR";
    break;
  default:
    return;
  }

  if (*logfile == '\0')
    return;

  p = linebuf;
  if (source_p != NULL)
  {
    n_preamble = ircsprintf(linebuf, "%s %s by (%s!%s@%s) :",
			    myctime(CurrentTime), log_message,
			    source_p->name, source_p->username, source_p->host);

  }
  else
  {
    n_preamble = ircsprintf(linebuf, "%s %s :",
			    myctime(CurrentTime), log_message);
  }

  p += n_preamble;

  if ((log_fb = fbopen(logfile, "r")) != NULL)
  {
    fbclose(log_fb);
    log_fb = fbopen(logfile, "a");
    if (log_fb == NULL)
      return;
    va_start(args, pattern);
    /* XXX add check for IRCD_BUFSIZE-(n_preamble+1) < 0 ? -db */
    nbytes = vsnprintf(p, IRCD_BUFSIZE-(n_preamble+1), pattern, args);
    nbytes += n_preamble;
    va_end(args);
    fbputs(linebuf, log_fb, nbytes);
    fbclose(log_fb);
  }
}
