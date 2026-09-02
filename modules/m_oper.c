/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_oper.c
 * \brief Includes required functions for processing the OPER command.
 */

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "io_string.h"
#include "list.h"
#include "log.h"
#include "memory.h"
#include "module.h"

#include "client.h"
#include "client_format.h"
#include "client_svstag.h"
#include "conf.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "user_mode.h"
#include "send.h"

/*! \brief Blindly opers up given client, using conf info.
 *         All checks on passwords have already been done.
 * \param client Pointer to given client to oper
 * \param conf operator {} configuration record
 */
static void
_oper_commit(struct Client *client, const struct OperItem *oper)
{
  client_set_class(client, oper->klass, CLIENT_CLASS_OPER);

  assert(client->connection->oper_auth_name == NULL);
  io_free(client->connection->oper_auth_name);
  client->connection->oper_auth_name = io_strdup(oper->name);

  client_set_oper_flag(client, oper->oper_privs);

  uint64_t mode_flags_old = client->user_mode_flags;
  uint64_t mode_flags_add = UMODE_OPER | UMODE_ADMIN;

  if (oper->modes)
    mode_flags_add |= user_mode_string_to_flags(oper->modes);
  else if (ConfigGeneral.oper_umodes)
    mode_flags_add |= user_mode_string_to_flags(ConfigGeneral.oper_umodes);

  user_mode_set_flag_exec(client, mode_flags_add, USER_MODE_SOURCE_REGULAR);
  user_mode_send(client, mode_flags_old, USER_MODE_SEND_USER | USER_MODE_SEND_SERVER);

  sendto_one_numeric(client, &me, RPL_YOUREOPER);

  if (!string_is_empty(oper->whois_text) && svstag_attach(&client->svstag_list, oper->whois_text))
    sendto_servers(NULL, 0, 0, ":%s SVSTAG %s 0 %u + :%s",
                   me.id, client->id, RPL_WHOISOPERATOR, oper->whois_text);

  client_format_name_buffer_t client_name_buffer;
  client_format_oper_name_buffer_t oper_name_buffer;
  const char *const client_name = client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer);
  const char *const oper_name = client_format_oper_name(client, &oper_name_buffer);

  log_write(LOG_TYPE_OPER, "OPER %s by %s",
            oper->name, client_name);

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s is now an operator",
                 oper_name);
  sendto_servers(NULL, 0, 0, ":%s GLOBOPS :%s is now an operator",
                 me.id, oper_name);
}

/*! \brief Notices all opers of the failed oper attempt if enabled
 *
 * \param source Client doing /oper ...
 * \param name     The nick they tried to oper as
 * \param reason   The reason why they have failed
 */
static void
_oper_report_failed_attempt(struct Client *client, const char *name, oper_auth_result_t result)
{
  const char *const reason = oper_auth_result_to_string(result);

  client_format_name_buffer_t client_name_buffer;
  const char *const client_name = client_format_name(client, CLIENT_FORMAT_NAME_PUBLIC, &client_name_buffer);

  if (ConfigGeneral.failed_oper_notice)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Failed OPER attempt as [%s] by %s (%s)",
                   name, client_name, reason);

  log_write(LOG_TYPE_OPER, "Failed OPER attempt as [%s] by %s (%s)",
            name, client_name, reason);
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
m_oper(struct Client *source, size_t parc, char *parv[])
{
  const char *const opername = parv[1];
  const char *const password = parv[2];

  const struct OperItem *oper = NULL;
  oper_auth_result_t result = oper_authenticate(source, opername, password, &oper);
  if (result == OPER_AUTH_SUCCESS)
  {
    assert(oper);

    _oper_commit(source, oper);
    return;
  }

  _oper_report_failed_attempt(source, opername, result);

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
mo_oper(struct Client *source, size_t parc, char *parv[])
{
  sendto_one_numeric(source, &me, RPL_YOUREOPER);
}

static struct Command command_table =
{
  .name = "OPER",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = m_oper, .args_min = 3, .end_grace_period = true },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_oper, .args_min = 3, .end_grace_period = true }
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
