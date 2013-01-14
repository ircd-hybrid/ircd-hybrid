/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  log.c: Logger functions.
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

#include "log.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "s_misc.h"


static struct {
  char path[HYB_PATH_MAX + 1];
  size_t size;
  FILE *file;
} log_type_table[LOG_TYPE_LAST];


int
log_add_file(enum log_type type, size_t size, const char *path)
{
  if (log_type_table[type].file)
    fclose(log_type_table[type].file);

  strlcpy(log_type_table[type].path, path, sizeof(log_type_table[type].path));
  log_type_table[type].size = size;

  return (log_type_table[type].file = fopen(path, "a")) != NULL;
}

void
log_close_all(void)
{
  unsigned int type = 0;

  while (++type < LOG_TYPE_LAST)
  {
    if (log_type_table[type].file == NULL)
      continue;

    fclose(log_type_table[type].file);
    log_type_table[type].file = NULL;
  }
}

static int
log_exceed_size(unsigned int type)
{
  struct stat sb;

  if (!log_type_table[type].size)
    return 0;

  if (stat(log_type_table[type].path, &sb) < 0)
    return -1;

  return (size_t)sb.st_size > log_type_table[type].size;
}

static void 
log_write(enum log_type type, const char *message)
{
  char buf[IRCD_BUFSIZE];

  strftime(buf, sizeof(buf), "[%FT%H:%M:%S%z]", localtime(&CurrentTime));

  fprintf(log_type_table[type].file, "%s %s\n", buf, message);
  fflush(log_type_table[type].file);
}

void
ilog(enum log_type type, const char *fmt, ...)
{
  char buf[LOG_BUFSIZE];
  va_list args;

  if (!log_type_table[type].file || !ConfigLoggingEntry.use_logging)
    return;

  va_start(args, fmt);
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);

  log_write(type, buf);

  if (log_exceed_size(type) <= 0)
    return;

  snprintf(buf, sizeof(buf), "Rotating logfile %s",
           log_type_table[type].path);
  log_write(type, buf);

  fclose(log_type_table[type].file);
  log_type_table[type].file = NULL;

  snprintf(buf, sizeof(buf), "%s.old", log_type_table[type].path);
  unlink(buf);
  rename(log_type_table[type].path, buf);

  log_add_file(type, log_type_table[type].size, log_type_table[type].path);
}
