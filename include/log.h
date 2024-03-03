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
 * @file log.h
 * @brief Defines the logging system for ircd-hybrid.
 *
 * This file contains declarations and documentation for the logging
 * system used in the ircd-hybrid Internet Relay Chat Daemon. It includes
 * constants, structures, and functions related to logging messages,
 * log file rotation, and managing log entries.
 */

#ifndef INCLUDED_log_h
#define INCLUDED_log_h

/**
 * @enum log_type
 * @brief Enumerates different log types for classifying log entries.
 */
enum log_type
{
  LOG_TYPE_IRCD,  /**< IRC daemon-related log entries (main log). */
  LOG_TYPE_KILL,  /**< Log entries related to KILL events. */
  LOG_TYPE_KLINE,  /**< Log entries related to KLINE events. */
  LOG_TYPE_DLINE,  /**< Log entries related to DLINE events. */
  LOG_TYPE_XLINE,  /**< Log entries related to XLINE events. */
  LOG_TYPE_RESV,  /**< Log entries related to RESV events. */
  LOG_TYPE_OPER,  /**< Log entries related to operator actions. */
  LOG_TYPE_USER,  /**< Log entries related to general user actions. */
  LOG_TYPE_DEBUG,  /**< Log entries for debugging information. */
};

/**
 * @struct Log
 * @brief Represents a log structure, holding information about log configuration.
 *
 * The Log structure includes details such as the log type, file name,
 * associated file pointer, maximum file size, whether it is the main log,
 * flush behavior, and a time provider function. This structure is part of
 * a doubly linked list of loggers (log_list).
 */
struct Log
{
  dlink_node node;  /**< Doubly linked list node for log management. */
  enum log_type type;  /**< Type categorizing the log entries. */
  char *file_name;  /**< File name associated with the log. */
  FILE *file;  /**< File pointer for the log file. */
  size_t max_file_size;  /**< Maximum size allowed for the log file. */
  bool main;  /**< Indicates if the log is the main log. */
  bool flush_immediately;  /**< Flag to flush log entries immediately. */
  const char *(*time_provider)(uintmax_t);  /**< Time provider function for log timestamp. */
};

extern struct Log *log_add(enum log_type, bool, size_t, const char *);
extern void log_clear(void);
extern void log_write(enum log_type, const char *, ...) AFP(2,3);
#endif  /* INCLUDED_log_h */
