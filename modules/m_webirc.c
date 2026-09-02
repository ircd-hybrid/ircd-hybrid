/*
 * SPDX-FileCopyrightText: 2012-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_webirc.c
 * \brief Includes required functions for processing the WEBIRC command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "address.h"
#include "io_string.h"
#include "module.h"

#include "client.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"
#include "user.h"
#include "user_mode.h"

/*! \brief WEBIRC command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = password
 *      - parv[2] = fake username (we ignore this)
 *      - parv[3] = fake hostname
 *      - parv[4] = fake ip
 */
static void
mr_webirc(struct Client *source, size_t parc, char *parv[])
{
  const char *const pass = parv[1];
  const char *const host = parv[3];
  const char *const addr = parv[4];

  assert(client_is_local(source));

  if (!valid_hostname(host))
  {
    client_exit(source, "Invalid WebIRC hostname");
    return;
  }

  const struct MaskItem *conf =
    find_address_conf(source->host, client_has_flag(source, FLAGS_GOTID) ?
                      source->username : "webirc", &source->addr, pass);
  if (conf == NULL)
    return;

  if (!IsConfClient(conf))
    return;  /* It's a CONF_KLINE */

  if (!IsConfWebIRC(conf))
  {
    client_exit(source, "Not a WebIRC auth block");
    return;
  }

  if (string_is_empty(conf->passwd))
  {
    client_exit(source, "WebIRC auth blocks must have a password");
    return;
  }

  if (!conf_match_password(pass, conf))
  {
    client_exit(source, "Invalid WebIRC password");
    return;
  }

  if (!address_from_string(addr, &source->addr))
  {
    client_exit(source, "Invalid WebIRC IP address");
    return;
  }

  strlcpy(source->sockhost, addr, sizeof(source->sockhost));

  if (source->sockhost[0] == ':')
  {
    memmove(source->sockhost + 1, source->sockhost, sizeof(source->sockhost) - 1);
    source->sockhost[0] = '0';
  }

  strlcpy(source->host, host, sizeof(source->host));
  strlcpy(source->realhost, host, sizeof(source->realhost));

  /* Check dlines now, k-lines will be checked on registration */
  conf = find_dline_conf(&source->addr);
  if (conf)
  {
    if (conf->type == CONF_DLINE)
    {
      client_exit(source, "D-lined");
      return;
    }
  }

  user_mode_set_flag(source, UMODE_WEBIRC);
  sendto_one_notice(source, &me, ":WebIRC host/IP set to %s %s", host, addr);
}

static struct Command command_table =
{
  .name = "WEBIRC",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = mr_webirc, .args_min = 5 },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_already_registered },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_reject_already_registered }
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
