/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_svinfo.c
 * \brief Includes required functions for processing the SVINFO command.
 */

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "io_parse.h"
#include "io_time.h"
#include "log.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"
#include "server.h"

static void _svinfo_report_link_status(struct Client *, bool, const char *, ...) IO_AFP(3, 4);
static void
_svinfo_report_link_status(struct Client *link, bool write_log, const char *status_format, ...)
{
  char status[IRCD_BUFSIZE];

  va_list args;
  va_start(args, status_format);
  vsnprintf(status, sizeof(status), status_format, args);
  va_end(args);

  client_format_name_buffer_t admin_name_buffer;
  client_format_name_buffer_t oper_name_buffer;

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_ADMIN, SEND_TYPE_NOTICE, "Link %s %s",
                 client_format_name(link, CLIENT_FORMAT_NAME_ADMIN, &admin_name_buffer), status);
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER, SEND_TYPE_NOTICE, "Link %s %s",
                 client_format_name(link, CLIENT_FORMAT_NAME_OPER, &oper_name_buffer), status);

  if (write_log)
  {
    client_format_name_buffer_t log_name_buffer;
    log_write(LOG_TYPE_IRCD, "Link %s %s",
              client_format_name(link, CLIENT_FORMAT_NAME_LOG, &log_name_buffer), status);
  }
}

/*! \brief SVINFO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = TS_CURRENT for the server
 *      - parv[2] = TS_MINIMUM for the server
 *      - parv[3] = unused
 *      - parv[4] = server's idea of UTC time
 */
static void
ms_svinfo(struct Client *source, size_t parc, char *parv[])
{
  if (!client_is_local_server(source))
    return;

  uintmax_t current_version;
  uintmax_t minimum_version;
  if (io_parse_uintmax(parv[1], &current_version) != IO_PARSE_OK ||
      io_parse_uintmax(parv[2], &minimum_version) != IO_PARSE_OK)
  {
    _svinfo_report_link_status(source, true, "dropped, malformed TS protocol version");
    client_exit(source, "Malformed TS protocol version");
    return;
  }

  if (minimum_version > current_version)
  {
    _svinfo_report_link_status(source, true,
                               "dropped, invalid TS protocol version range (current=%ju, minimum=%ju)",
                               current_version, minimum_version);

    client_exit(source, "Invalid TS protocol version range");
    return;
  }

  if (current_version < SERVER_TS_PROTOCOL_MINIMUM ||
      minimum_version > SERVER_TS_PROTOCOL_CURRENT)
  {
    _svinfo_report_link_status(source, true,
                               "dropped, incompatible TS protocol version (current=%ju, minimum=%ju)",
                               current_version, minimum_version);

    client_exit(source, "Incompatible TS protocol version");
    return;
  }

  uintmax_t remote_ts;
  if (io_parse_uintmax(parv[4], &remote_ts) != IO_PARSE_OK)
  {
    _svinfo_report_link_status(source, true, "dropped, malformed timestamp");
    client_exit(source, "Malformed timestamp");
    return;
  }

  io_time_update_cache();

  const uintmax_t local_ts = io_time_get(IO_TIME_REALTIME_SEC);
  const uintmax_t abs_delta_ts = (remote_ts > local_ts) ? (remote_ts - local_ts) : (local_ts - remote_ts);

  if (abs_delta_ts > ConfigGeneral.ts_max_delta)
  {
    _svinfo_report_link_status(source, true,
                               "dropped, excessive TS delta (my TS=%ju, their TS=%ju, delta=%ju)",
                               local_ts, remote_ts, abs_delta_ts);

    client_exit(source, "Excessive TS delta");
    return;
  }

  if (abs_delta_ts > ConfigGeneral.ts_warn_delta)
    _svinfo_report_link_status(source, false,
                               "notable TS delta (my TS=%ju, their TS=%ju, delta=%ju)",
                               local_ts, remote_ts, abs_delta_ts);
}

static struct Command command_table =
{
  .name = "SVINFO",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_svinfo, .args_min = 5 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
};

static void
init_handler(void)
{
  command_add(&command_table);
}

static void
exit_handler(void)
{
  command_del(&command_table);
}

struct Module module_entry =
{
  .init_handler = init_handler,
  .exit_handler = exit_handler,
};
