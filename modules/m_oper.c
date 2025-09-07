/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2025 ircd-hybrid development team
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

/*! \file m_oper.c
 * \brief Includes required functions for processing the OPER command.
 */

#include "stdinc.h"
#include "io_string.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"
#include "client.h"
#include "client_svstag.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "user_mode.h"
#include "send.h"
#include "parse.h"

/*! \brief Blindly opers up given client, using conf info.
 *         All checks on passwords have already been done.
 * \param client Pointer to given client to oper
 * \param conf operator {} configuration record
 */
static void
oper_up(struct Client *client, const struct OperItem *oper)
{
  client_set_class(client, oper->klass, CLIENT_CLASS_OPER);

  assert(client->connection->oper_name == NULL);
  io_free(client->connection->oper_name);
  client->connection->oper_name = io_strdup(oper->name);

  AddOFlag(client, oper->oper_privs);

  uint64_t mode_flags_old = client->umodes;
  uint64_t mode_flags_add = UMODE_OPER | UMODE_ADMIN;

  if (oper->modes)
    mode_flags_add |= user_mode_string_to_flags(oper->modes);
  else if (ConfigGeneral.oper_umodes)
    mode_flags_add |= user_mode_string_to_flags(ConfigGeneral.oper_umodes);

  user_mode_set_flag_exec(client, mode_flags_add, USER_MODE_SOURCE_REGULAR);
  user_mode_send(client, mode_flags_old, USER_MODE_SEND_CLIENT | USER_MODE_SEND_SERVER);

  sendto_one_numeric(client, &me, RPL_YOUREOPER);

  if (!string_is_empty(oper->whois_text))
  {
    svstag_attach(&client->svstag_list, RPL_WHOISOPERATOR, "+", oper->whois_text);
    sendto_servers(NULL, 0, 0, ":%s SVSTAG %s 0 %u + :%s",
                   me.id, client->id, RPL_WHOISOPERATOR, oper->whois_text);
  }

  log_write(LOG_TYPE_OPER, "OPER %s by %s",
            oper->name, client_get_name(client, HIDE_IP));

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s is now an operator",
                 client_get_oper_name(client));
  sendto_servers(NULL, 0, 0, ":%s GLOBOPS :%s is now an operator",
                 me.id, client_get_oper_name(client));
}

/*! \brief Notices all opers of the failed oper attempt if enabled
 *
 * \param source Client doing /oper ...
 * \param name     The nick they tried to oper as
 * \param reason   The reason why they have failed
 */
static void
failed_oper_notice(struct Client *client, const char *name, oper_auth_result_t result)
{
  const char *reason = oper_auth_result_to_string(result);

  if (ConfigGeneral.failed_oper_notice)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Failed OPER attempt as [%s] by %s (%s)",
                   name, client_get_name(client, HIDE_IP), reason);

  log_write(LOG_TYPE_OPER, "Failed OPER attempt as [%s] by %s (%s)",
            name, client_get_name(client, HIDE_IP), reason);
}

/*! \brief OPER command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = oper name
 *      - parv[2] = oper password
 */
static void
m_oper(struct Client *source, int parc, char *parv[])
{
  const char *const opername = parv[1];
  const char *const password = parv[2];

  struct OperItem *oper = NULL;
  oper_auth_result_t result = oper_authenticate(source, opername, password, &oper);
  if (result == OPER_AUTH_SUCCESS)
  {
    assert(oper);

    oper_up(source, oper);
    return;
  }

  failed_oper_notice(source, opername, result);

  switch (result)
  {
    case OPER_AUTH_FAIL_PASSWORD:
      sendto_one_numeric(source, &me, ERR_PASSWDMISMATCH);
      break;
    default:
      sendto_one_numeric(source, &me, ERR_NOOPERHOST);
      break;
  }
}

/*! \brief OPER command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = oper name
 *      - parv[2] = oper password
 */
static void
mo_oper(struct Client *source, int parc, char *parv[])
{
  sendto_one_numeric(source, &me, RPL_YOUREOPER);
}

static struct Command command_table =
{
  .name = "OPER",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_oper, .args_min = 3, .end_grace_period = true },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_oper, .args_min = 3, .end_grace_period = true }
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
