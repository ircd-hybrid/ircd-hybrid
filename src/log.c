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

/*! \file log.c
 * \brief Logger functions.
 */

#include "stdinc.h"
#include "log.h"
#include "conf.h"
#include "misc.h"
#include "memory.h"


static struct LogFile log_type_table[LOG_TYPE_LAST];


void
log_set_file(enum log_type type, size_t size, const char *path)
{
  struct LogFile *log = &log_type_table[type];

  if (log->path)
    xfree(log->path);

  log->path = xstrdup(path);
  log->size = size;

  if (type == LOG_TYPE_IRCD)
    log->file = fopen(log->path, "a");
}

void
log_free(struct LogFile *log)
{
  xfree(log->path);
  log->path = NULL;
}

void
log_reopen(struct LogFile *log)
{
  if (log->file)
  {
    fclose(log->file);
    log->file = NULL;
  }

  if (log->path)
    log->file = fopen(log->path, "a");
}

void
log_iterate(void (*func)(struct LogFile *))
{
  /* type = 1 to skip LOG_TYPE_IRCD */
  for (unsigned int type = 1; type < LOG_TYPE_LAST; ++type)
    func(&log_type_table[type]);
}

static bool
log_exceed_size(struct LogFile *log)
{
  struct stat sb;

  if (log->size == 0)
    return false;

  if (stat(log->path, &sb) < 0)
    return false;

  return (size_t)sb.st_size > log->size;
}

static void
log_write(struct LogFile *log, const char *message)
{
  fprintf(log->file, "[%s] %s\n", date_iso8601(0), message);
  fflush(log->file);
}

void
ilog(enum log_type type, const char *fmt, ...)
{
  struct LogFile *log = &log_type_table[type];
  char buf[LOG_BUFSIZE] = "";
  va_list args;

  if (log->file == NULL || ConfigLog.use_logging == 0)
    return;

  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);

  log_write(log, buf);

  if (log_exceed_size(log) == false)
    return;

  snprintf(buf, sizeof(buf), "Rotating logfile %s", log->path);
  log_write(log, buf);

  fclose(log->file);
  log->file = NULL;

  snprintf(buf, sizeof(buf), "%s.old", log->path);
  unlink(buf);
  rename(log->path, buf);

  log->file = fopen(log->path, "a");
}
