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

/*! \file m_rehash.c
 * \brief Includes required functions for processing the REHASH command.
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "res.h"
#include "conf.h"
#include "conf_shared.h"
#include "log.h"
#include "send.h"
#include "parse.h"
#include "module.h"
#include "motd.h"


/*! \brief REHASH CONF handler
 *         Attempts to reload server's configuration file(s)
 * \param source Pointer to client issuing the command
 */
static void
rehash_conf(struct Client *source)
{
  sendto_one_numeric(source, &me, RPL_REHASHING, "CONF");
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                       "%s is rehashing configuration file(s)",
                       get_oper_name(source));
  log_write(LOG_TYPE_IRCD, "REHASH CONF from %s",
            get_oper_name(source));
  conf_rehash(false);
}

/*! \brief REHASH MOTD handler
 *         Attempts to recache server's MOTD file(s)
 * \param source Pointer to client issuing the command
 */
static void
rehash_motd(struct Client *source)
{
  sendto_one_numeric(source, &me, RPL_REHASHING, "MOTD");
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                       "%s is forcing re-reading of MOTD files",
                       get_oper_name(source));
  log_write(LOG_TYPE_IRCD, "REHASH MOTD from %s",
            get_oper_name(source));
  motd_recache();
}

/*! \brief REHASH DNS handler
 *         Attempts to restart server's resolver
 * \param source Pointer to client issuing the command
 */
static void
rehash_dns(struct Client *source)
{
  sendto_one_numeric(source, &me, RPL_REHASHING, "DNS");
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                       "%s is rehashing DNS",
                       get_oper_name(source));
  log_write(LOG_TYPE_IRCD, "REHASH DNS from %s",
            get_oper_name(source));
  restart_resolver();
}

struct RehashStruct
{
  const char *const option;
  void (*const handler)(struct Client *);
};

static const struct RehashStruct rehash_cmd_table[] =
{
  { .option = "CONF", .handler = rehash_conf },
  { .option = "MOTD", .handler = rehash_motd },
  { .option = "DNS", .handler = rehash_dns },
  { .option = NULL }
};

/*! \brief REHASH command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = option [CONF, DNS, MOTD]
 * or for remote REHASH:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = option [CONF, DNS, MOTD]
 */
static void
mo_rehash(struct Client *source, int parc, char *parv[])
{
  const char *option = NULL;
  const char *server = NULL;

  if (!EmptyString(parv[2]))
  {
    if (!HasOFlag(source, OPER_FLAG_REHASH_REMOTE))
    {
      sendto_one_numeric(source, &me, ERR_NOPRIVS, "rehash:remote");
      return;
    }

    server = parv[1];
    option = parv[2];
  }
  else
  {
    if (!HasOFlag(source, OPER_FLAG_REHASH))
    {
      sendto_one_numeric(source, &me, ERR_NOPRIVS, "rehash");
      return;
    }

    option = parv[1];
  }

  for (const struct RehashStruct *tab = rehash_cmd_table; tab->handler; ++tab)
  {
    if (irccmp(tab->option, option))
      continue;

    if (!EmptyString(server))
      sendto_match_servs(source, server, 0, "REHASH %s %s", server, option);

    if (EmptyString(server) || match(server, me.name) == 0)
      tab->handler(source);

    return;
  }

  sendto_one_notice(source, &me, ":%s is not a valid option. "
                    "Choose from CONF, DNS, MOTD",
                    option);
}

/*! \brief REHASH command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = target server mask
 *      - parv[2] = option [CONF, DNS, MOTD]
 */
static void
ms_rehash(struct Client *source, int parc, char *parv[])
{
  const char *const option = parv[2];
  const char *const server = parv[1];

  sendto_match_servs(source, server, 0, "REHASH %s %s", server, option);

  if (match(server, me.name))
    return;

  if (!shared_find(SHARED_REHASH, source->servptr->name,
                   source->username, source->host))
    return;

  for (const struct RehashStruct *tab = rehash_cmd_table; tab->handler; ++tab)
  {
    if (irccmp(tab->option, option))
      continue;

    tab->handler(source);
    return;
  }
}

static struct Command command_table =
{
  .name = "REHASH",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_rehash, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_rehash, .args_min = 2 }
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
