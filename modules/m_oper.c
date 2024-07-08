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

/*! \file m_oper.c
 * \brief Includes required functions for processing the OPER command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "module.h"


/*! \brief Blindly opers up given source, using conf info.
 *         All checks on passwords have already been done.
 * \param source Pointer to given client to oper
 * \param conf operator {} configuration record
 */
static void
oper_up(struct Client *source, const struct MaskItem *conf)
{
  const unsigned int oldmodes = source->umodes;

  ++Count.oper;
  SetOper(source);

  if (conf->modes)
    AddUMode(source, conf->modes);
  else if (ConfigGeneral.oper_umodes)
    AddUMode(source, ConfigGeneral.oper_umodes);

  if (!(oldmodes & UMODE_INVISIBLE) && HasUMode(source, UMODE_INVISIBLE))
    ++Count.invisi;

  assert(list_find(&oper_list, source) == NULL);
  list_add(source, list_make_node(), &oper_list);

  AddOFlag(source, conf->port);

  if (HasOFlag(source, OPER_FLAG_ADMIN))
    AddUMode(source, UMODE_ADMIN);

  if (!EmptyString(conf->whois))
  {
    svstag_attach(&source->svstags, RPL_WHOISOPERATOR, "+", conf->whois);
    sendto_servers(NULL, 0, 0, ":%s SVSTAG %s %ju %u + :%s",
                  me.id, source->id, source->tsinfo, RPL_WHOISOPERATOR, conf->whois);
  }

  log_write(LOG_TYPE_OPER, "OPER %s by %s",
            conf->name, client_get_name(source, HIDE_IP));

  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "%s is now an operator",
                       get_oper_name(source));
  sendto_servers(NULL, 0, 0, ":%s GLOBOPS :%s is now an operator",
                me.id, get_oper_name(source));

  send_umode(source, oldmodes, true, true);
  sendto_one_numeric(source, &me, RPL_YOUREOPER);
}

/*! \brief Notices all opers of the failed oper attempt if enabled
 *
 * \param source Client doing /oper ...
 * \param name     The nick they tried to oper as
 * \param reason   The reason why they have failed
 */
static void
failed_oper_notice(struct Client *source, enum irc_numerics numeric,
                   const char *name, const char *reason)
{
  if (numeric)
    sendto_one_numeric(source, &me, numeric);

  if (ConfigGeneral.failed_oper_notice)
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                         "Failed OPER attempt as %s by %s - %s",
                         name, client_get_name(source, HIDE_IP), reason);

  log_write(LOG_TYPE_OPER, "Failed OPER attempt as %s by %s - %s",
            name, client_get_name(source, HIDE_IP), reason);
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

  struct MaskItem *conf = operator_find(source, opername);
  if (conf == NULL)
  {
    conf = operator_find(NULL, opername);
    failed_oper_notice(source, ERR_NOOPERHOST, opername, conf ? "host mismatch" : "no operator {} block");
    return;
  }

  if (IsConfTLS(conf) && !HasUMode(source, UMODE_SECURE))
  {
    failed_oper_notice(source, ERR_NOOPERHOST, opername, "requires TLS");
    return;
  }

  if (!EmptyString(conf->certfp))
  {
    if (EmptyString(source->tls_certfp) || strcasecmp(source->tls_certfp, conf->certfp))
    {
      failed_oper_notice(source, ERR_NOOPERHOST, opername, "client certificate fingerprint mismatch");
      return;
    }
  }

  if (match_conf_password(password, conf) == false)
  {
    failed_oper_notice(source, ERR_PASSWDMISMATCH, opername, "password mismatch");
    return;
  }

  if (conf_attach(source, conf))
  {
    sendto_one_notice(source, &me, ":Can't attach conf!");
    failed_oper_notice(source, 0, opername, "can't attach conf!");
    return;
  }

  oper_up(source, conf);
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
