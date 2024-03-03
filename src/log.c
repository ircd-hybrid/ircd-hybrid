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

/**
 * @file log.c
 * @brief Implements a versatile logging system with support for multiple log types and rotation capabilities.
 *
 * This module offers a robust logging infrastructure designed for integration into IRC servers and similar applications.
 * It provides flexibility through various log types, file rotation mechanisms, and configurable logging behaviors.
 */

#include "stdinc.h"
#include "list.h"
#include "log.h"
#include "conf.h"
#include "misc.h"
#include "memory.h"

/**
 * @def TRUNCATED_STRING
 * @brief A string indicating that log message content has been truncated.
 *
 * If a log message exceeds the maximum allowed length, it is truncated,
 * and this string is appended to indicate the truncation.
 */
#define TRUNCATED_STRING "[...truncated]"

/**
 * @def LOG_MAX_LENGTH
 * @brief Maximum length allowed for a log message, excluding null-terminator.
 *
 * This constant defines the maximum length a log message can have before
 * it gets truncated. Log messages exceeding this length will be truncated
 * with the TRUNCATED_STRING appended.
 */
enum { LOG_MAX_LENGTH = 512 };

/**
 * @def LOG_ROTATION_ATTEMPTS
 * @brief Maximum number of attempts to find a new file name during log rotation.
 *
 * During log rotation, a new file name is generated by appending a number to
 * the original file name. This constant represents the maximum number of attempts
 * to find an available file name in case of clashes.
 */
enum { LOG_ROTATION_ATTEMPTS = 1000 };

/**
 * @def LOG_ROTATION_ATTEMPTS
 * @brief Maximum number of attempts to find a new file name during log rotation.
 *
 * During log rotation, a new file name is generated by appending a number to
 * the original file name. This constant represents the maximum number of attempts
 * to find an available file name in case of clashes.
 */
static dlink_list log_list;

/**
 * @brief Initializes the logging system with a specific log type, file name, maximum file size, flush behavior, and log level.
 *
 * This function creates and initializes a new log, setting its attributes, opening the log file, and adding it to the log list.
 * In case of failure, it prints an error message and exits if it's the main log; otherwise, it returns NULL.
 *
 * @param type The type of the log entry.
 * @param main Flag indicating if it's the primary log.
 * @param max_file_size Maximum size for the log file.
 * @param file_name Name of the log file.
 * @return A pointer to the initialized Log structure.
 */
struct Log *
log_add(enum log_type type, bool main, size_t max_file_size, const char *file_name)
{
  struct Log *log = xcalloc(sizeof(*log));
  log->type = type;
  log->file_name = xstrdup(file_name);
  log->max_file_size = max_file_size;
  log->main = main;
  log->flush_immediately = true;
  log->time_provider = date_iso8601_usec;
  log->file = fopen(file_name, "a");
  dlinkAdd(log, &log->node, &log_list);

  if (log->file == NULL)
  {
    if (log->main)
    {
      perror("fopen");
      exit(EXIT_FAILURE);
    }

    log_destroy(log);
    return NULL;
  }

  /* Set owner-only read and write permissions. */
  chmod(log->file_name, S_IRUSR | S_IWUSR);
  return log;
}

/**
 * @brief Rotates log files, handling file renaming and creating a new log file.
 *
 * This function performs log rotation, renaming the current log file and creating a new one.
 * It checks for available filenames, handles file permissions, and reports success or failure.
 *
 * @param log The Log structure to rotate.
 * @return True if rotation succeeds, false otherwise.
 */
static bool
log_rotate(struct Log *log)
{
  char new_file_name[PATH_MAX];
  unsigned int attempt = 0;

  /* Attempt to find an available filename for rotation. */
  do
  {
    /* If it's the first attempt, append ".old" to the file name. */
    if (attempt == 0)
      snprintf(new_file_name, sizeof(new_file_name), "%s.old", log->file_name);
    else
      /* If subsequent attempts, append ".old." with attempt number. */
      snprintf(new_file_name, sizeof(new_file_name), "%s.old.%u", log->file_name, attempt);

    if (access(new_file_name, F_OK) == -1)
      break;
  } while (++attempt < LOG_ROTATION_ATTEMPTS);

  /* If LOG_ROTATION_ATTEMPTS is reached without finding a new file name, return false. */
  if (attempt == LOG_ROTATION_ATTEMPTS)
    return false;  /* Rotation failed. */

  /* Rename the current log file. */
  if (rename(log->file_name, new_file_name))
    return false;  /* Rotation failed. */

  /* Create a new log file. */
  FILE *new_file = fopen(log->file_name, "a");
  if (new_file == NULL)
    return false;  /* Rotation failed. */

  fprintf(log->file, "[%s] Log file rotated. Exceeded maximum size: %zu bytes.\n",
          log->time_provider(0), log->max_file_size);

  /* Close the old log file. */
  fclose(log->file);
  log->file = new_file;

  /* Set owner-only read and write permissions. */
  chmod(log->file_name, S_IRUSR | S_IWUSR);
  return true;  /* Rotation succeeded. */
}

/**
 * @brief Checks whether log rotation is due based on specific conditions.
 *
 * This function determines whether log rotation is necessary by evaluating
 * certain conditions, such as exceeding a predefined maximum file size.
 * If the log meets the conditions for rotation, it returns true; otherwise, it returns false.
 *
 * @param log The Log structure for which to check if rotation is due.
 * @return True if log rotation is due, false otherwise.
 */
static bool
log_rotate_due(struct Log *log)
{
  if (log->max_file_size == 0)
    return false;

  struct stat sb;
  if (stat(log->file_name, &sb) < 0)
    return false;

  return (size_t)sb.st_size > log->max_file_size;
}

/**
 * @brief Writes a log entry with a variable argument list to the appropriate log file.
 *
 * This function writes a log entry to the appropriate log file based on the log type.
 * It performs log rotation if needed and flushes immediately based on the log's configuration.
 *
 * @param type The type of the log entry.
 * @param format The format string for the log entry.
 * @param ... Variable argument list for the log entry.
 */
void
log_write(enum log_type type, const char *format, ...)
{
  if (ConfigLog.use_logging == 0)
    return;

  dlink_node *node;
  DLINK_FOREACH(node, log_list.head)
  {
    struct Log *log = node->data;

    /* Check if the log entry type matches the log's log type. */
    if (log->type == type)
    {
      char buffer[LOG_MAX_LENGTH + 1];  /* +1 for the null terminator ('\0'). */

      va_list args;
      va_start(args, format);
      size_t length = vsnprintf(buffer, sizeof(buffer), format, args);
      va_end(args);

      /* Check if log message was truncated. */
      if (length >= sizeof(buffer))
        snprintf(buffer + LOG_MAX_LENGTH - sizeof(TRUNCATED_STRING), sizeof(TRUNCATED_STRING), TRUNCATED_STRING);

      /* Check if log file exceeds the maximum size, rotate if needed. */
      if (log->main == false && log_rotate_due(log))
        log_rotate(log);

      /* Write log entry to the file. */
      fprintf(log->file, "[%s] %s\n", log->time_provider(0), buffer);

      /* Optionally flush immediately based on the configuration. */
      if (log->flush_immediately)
        fflush(log->file);

      return;
    }
  }
}

/**
 * @brief Closes, deinitializes, and frees a log.
 *
 * This function removes a log from the log list, closes the associated file, and frees memory.
 *
 * @param log The Log structure to destroy.
 */
void
log_destroy(struct Log *log)
{
  dlinkDelete(&log->node, &log_list);

  if (log->file)
    fclose(log->file);

  xfree(log->file_name);
  xfree(log);
}

/**
 * @brief Closes, deinitializes, and frees all logs except the main log.
 *
 * This function iterates through the log list, destroying all logs except the main log.
 */
void
log_clear(void)
{
  dlink_node *node, *node_next;

  DLINK_FOREACH_SAFE(node, node_next, log_list.head)
  {
    struct Log *log = log_list.head->data;

    if (log->main == false)
      log_destroy(log);
  }
}
