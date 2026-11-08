/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_info.c
 * \brief Includes required functions for processing the INFO command.
 */

#include <stddef.h>
#include <stdint.h>

#include "io_time.h"
#include "misc.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "ircd_module.h"
#include "ircd_hook.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "tls.h"

static const char *const info_text_lines[] =
{
  "ircd-hybrid --",
  "Based on the original code written by Jarkko Oikarinen",
  "Copyright (c) 1988-1991 University of Oulu, Computing Center",
  "Copyright (c) 1997-2026 ircd-hybrid development team",
  "",
  "This program is free software; you can redistribute it and/or",
  "modify it under the terms of the GNU General Public License as",
  "published by the Free Software Foundation; either version 2, or",
  "(at your option) any later version.",
  "",
  "",
  "The core team as of this major release:",
  "",
  "Dianora, Diane Bruce <db@db.net>",
  "Michael, Michael Wobst <michael@wobst.fr>",
  "Rodder, Jon Lusky <lusky@blown.net>",
  "Wohali, Joan Touzet <joant@ieee.org>",
  "",
  "The following people have contributed blood, sweat, and/or code to",
  "recent releases of ircd-hybrid, in nick alphabetical order:",
  "",
  "A1kmm, Andrew Miller <a1kmm@mware.virtualave.net>",
  "Adam, Adam <Adam@anope.org>",
  "Adrian Chadd <adrian@creative.net.au>",
  "adx, Piotr Nizynski <nizynski@sysplex.pl>",
  "AndroSyn, Aaron Sethman <androsyn@ratbox.org>",
  "bane, Dragan Dosen <bane@idolnet.org>",
  "billy-jon, William Bierman III <bill@thebiermans.org>",
  "bysin, Ben Kittridge <bkittridge@cfl.rr.com>",
  "cosine, Patrick Alken <wnder@uwns.underworld.net>",
  "cryogen, Stuart Walsh <stu@ipng.org.uk>",
  "David-T, David Taylor <davidt@yadt.co.uk>",
  "Dom, Dominic Hargreaves <dom@earth.li>",
  "Fawkes, Christoph Ostermeier <fawkes@phat-net.de>",
  "fgeek, Henri Salo <henri@nerv.fi>",
  "fl, Lee Hardy <lee@leeh.co.uk>",
  "Garion, Joost Vunderink <garion@efnet.nl>",
  "Habeeb, David Supuran <habeeb@cfl.rr.com>",
  "Hwy101, W. Campbell <wcampbel@botbay.net>",
  "jmallett, Juli Mallett <jmallett@FreeBSD.org>",
  "joshk, Joshua Kwan <joshk@triplehelix.org>",
  "jv, Jakub Vlasek <jv@pilsedu.cz>",
  "k9, Jeremy Chadwick <ircd@jdc.parodius.com>",
  "kire, Erik Small <smalle@hawaii.edu>",
  "knight, Alan LeVee <alan.levee@prometheus-designs.net>",
  "kre, Dinko Korunic <kreator@fly.srk.fer.hr>",
  "madmax, Paul Lomax <madmax@efnet.org>",
  "metalrock, Jack Low <xxjack12xx@gmail.com>",
  "r0d3nt, Andrew Strutt <andrew.strutt@gmail.com>",
  "Riedel, Dennis Vink <dennis@drvink.com>",
  "scuzzy, David Todd <scuzzy@aniverse.net>",
  "spookey, David Colburn <spookey@spookey.org>",
  "TimeMr14C, Yusuf Iskenderoglu <uhc0@stud.uni-karlsruhe.de>",
  "toot, Toby Verrall <to7@antipope.fsnet.co.uk>",
  "vx0, Mark Miller <mark@oc768.net>",
  "wiz, Jason Dambrosio <jason@wiz.cx>",
  "Xride, S\xC3\xB8ren Straarup <xride@x12.dk>",
  "zb^3, Alfred Perlstein <alfred@freebsd.org>",
  "",
  NULL
};

static void
_info_send_tls_library(struct Client *client)
{
  const tls_library_info_t info = tls_library_get_info();
  sendto_one_numeric(client, &me, RPL_INFO | SND_EXPLICIT,
                     ":TLS library: %s; runtime: %s; compile-time: %s",
                     info.name, info.runtime_version, info.compile_version);
}

static void
_info_send_online_since(struct Client *client)
{
  sendto_one_numeric(client, &me, RPL_INFO | SND_EXPLICIT, ":On-line since %s",
                     date(me.connection->created_real));
}

static void
_info_process_request(struct Client *client)
{
  hook_dispatch(ircd_hook_spy_request, &(ircd_hook_spy_request_ctx){
    .source = client,
    .command = "INFO"
  });

  for (const char *const *line_ptr = info_text_lines; *line_ptr; ++line_ptr)
  {
    const char *const line = **line_ptr ? *line_ptr : " ";
    sendto_one_numeric(client, &me, RPL_INFO, line);
  }

  if (client_is_oper(client) && tls_is_configured())
    _info_send_tls_library(client);

  _info_send_online_since(client);

  sendto_one_numeric(client, &me, RPL_ENDOFINFO);
}

/*! \brief INFO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
m_info(struct Client *source, size_t parc, char *parv[])
{
  static uintmax_t last_used = 0;

  const uintmax_t now = io_time_get(IO_TIME_MONOTONIC_SEC);
  if (now - last_used < ConfigGeneral.pace_wait)
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "INFO");
    return;
  }

  last_used = now;

  if (ConfigServerHide.disable_remote_commands == 0)
    if (server_route_command(source, ":%s INFO :%s", 1, parv)->result != SERVER_ROUTE_ISME)
      return;

  _info_process_request(source);
}

/*! \brief INFO command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/servername
 */
static void
ms_info(struct Client *source, size_t parc, char *parv[])
{
  if (server_route_command(source, ":%s INFO :%s", 1, parv)->result != SERVER_ROUTE_ISME)
    return;

  _info_process_request(source);
}

static struct Command command_table =
{
  .name = "INFO",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_info },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_info },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = ms_info }
};

static bool
init_handler(void *context, char *error_message, size_t error_message_size)
{
  return ircd_module_register_commands(&command_table, 1, error_message, error_message_size);
}

static void
exit_handler(void *context)
{
  command_del(&command_table);
}

const struct module_descriptor module_entry_v1 =
{
  .abi_version = MODULE_DESCRIPTOR_ABI_VERSION,
  .descriptor_size = sizeof(struct module_descriptor),
  .application_abi_version = IRCD_MODULE_ABI_VERSION,
  .name = "m_info",
  .init_handler = init_handler,
  .exit_handler = exit_handler
};
