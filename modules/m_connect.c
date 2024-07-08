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

/*! \file m_connect.c
 * \brief Includes required functions for processing the CONNECT command.
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "hash.h"
#include "module.h"


static void
do_connect(struct Client *source, const char *name)
{
  assert(IsClient(source));

  /*
   * Try to find the name. If it fails, notify and bail.
   */
  struct MaskItem *conf = connect_find(name, match);
  if (conf == NULL)
  {
    sendto_one_notice(source, &me, ":Connect: Server %s not listed in configuration file", name);
    return;
  }

  const struct Client *target = hash_find_server(conf->name);
  if (target)
  {
    sendto_one_notice(source, &me, ":Connect: Server %s already exists from %s",
                      target->name, target->from->name);
    return;
  }

  if (find_servconn_in_progress(conf->name))
  {
    sendto_one_notice(source, &me, ":Connect: a connection to %s is already in progress",
                      conf->name);
    return;
  }

  /* Notify all operators about connect requests. */
  static const char *const type[] = { "Remote", "Local" };
  const char *const type_p = type[MyConnect(source) != 0];

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_GLOBAL, "from %s: %s CONNECT %s %u from %s",
                       me.name, type_p, name, conf->port, get_oper_name(source));
  sendto_server(NULL, 0, 0, ":%s GLOBOPS :%s CONNECT %s %u from %s",
                me.id, type_p, name, conf->port, get_oper_name(source));

  log_write(LOG_TYPE_IRCD, "%s CONNECT %s %u from %s",
            type_p, name, conf->port, get_oper_name(source));

  /*
   * At this point we should be calling connect_server with a valid
   * connect{} block and a valid port in the connect{} block.
   */
  if (server_connect(conf, source) == false)
    sendto_one_notice(source, &me, ":*** Couldn't connect to %s.%u",
                      conf->name, conf->port);
  else if (MyConnect(source) &&
           (ConfigServerHide.hide_server_ips == 0 && HasUMode(source, UMODE_ADMIN)))
    sendto_one_notice(source, &me, ":*** Connecting to %s[%s].%u",
                      conf->name, conf->host, conf->port);
  else
    sendto_one_notice(source, &me, ":*** Connecting to %s.%u",
                      conf->name, conf->port);

  /*
   * Client is either connecting with all the data it needs or has been
   * destroyed.
   */
}

/*! \brief CONNECT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = unused/ignored
 *      - parv[3] = nickname/servername
 */
static void
mo_connect(struct Client *source, int parc, char *parv[])
{
  if (!EmptyString(parv[3]))
  {
    if (!HasOFlag(source, OPER_FLAG_CONNECT_REMOTE))
    {
      sendto_one_numeric(source, &me, ERR_NOPRIVS, "connect:remote");
      return;
    }

    if (server_hunt(source, ":%s CONNECT %s %s :%s", 3, parv)->ret != HUNTED_ISME)
      return;
  }

  if (!HasOFlag(source, OPER_FLAG_CONNECT))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "connect");
    return;
  }

  const char *const name = parv[1];
  do_connect(source, name);
}

/*! \brief CONNECT command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server
 *      - parv[2] = unused/ignored
 *      - parv[3] = nickname/servername
 */
static void
ms_connect(struct Client *source, int parc, char *parv[])
{
  if (server_hunt(source, ":%s CONNECT %s %s :%s", 3, parv)->ret != HUNTED_ISME)
    return;

  const char *const name = parv[1];
  do_connect(source, name);
}

static struct Command command_table =
{
  .name = "CONNECT",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_connect, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_connect, .args_min = 2 }
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
