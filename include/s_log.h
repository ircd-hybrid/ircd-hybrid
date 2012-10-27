/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_log.h: A header for the logger functions.
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

#ifndef INCLUDED_s_log_h
#define INCLUDED_s_log_h

struct Client;

#define L_CRIT   0
#define L_ERROR  1
#define L_WARN   2
#define L_NOTICE 3
#define L_TRACE  4
#define L_INFO   5
#define L_DEBUG  6

extern void init_log(const char *);
extern void reopen_log(const char *);
extern void set_log_level(const int);
extern int get_log_level(void);
#ifdef __GNUC__
extern void ilog(const int, const char *, ...) __attribute__((format(printf, 2, 3)));
#else
extern void ilog(const int, const char *, ...);
#endif
extern const char *get_log_level_as_string(int);
extern void log_user_exit(struct Client *);
extern void log_oper_action(int type, const struct Client *, const char *, ...);

enum {
  LOG_OPER_TYPE,
  LOG_FAILED_OPER_TYPE,
  LOG_KLINE_TYPE,
  LOG_RKLINE_TYPE,
  LOG_TEMP_KLINE_TYPE,
  LOG_DLINE_TYPE,
  LOG_TEMP_DLINE_TYPE,
  LOG_GLINE_TYPE,
  LOG_KILL_TYPE,
  LOG_OPERSPY_TYPE,
  LOG_IOERR_TYPE
};

#endif /* INCLUDED_s_log_h */
