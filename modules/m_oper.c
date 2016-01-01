/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2016 ircd-hybrid development team
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
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "conf.h"
#include "log.h"
#include "user.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"


/*! \brief Blindly opers up given source_p, using conf info.
 *         All checks on passwords have already been done.
 * \param source_p Pointer to given client to oper
 */
static void
oper_up(struct Client *source_p)
{
  const unsigned int old = source_p->umodes;
  const struct MaskItem *const conf = source_p->connection->confs.head->data;

  ++Count.oper;
  SetOper(source_p);

  if (conf->modes)
    AddUMode(source_p, conf->modes);
  else if (ConfigGeneral.oper_umodes)
    AddUMode(source_p, ConfigGeneral.oper_umodes);

  if (!(old & UMODE_INVISIBLE) && HasUMode(source_p, UMODE_INVISIBLE))
    ++Count.invisi;
  else if ((old & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
    --Count.invisi;

  assert(dlinkFind(&oper_list, source_p) == NULL);
  dlinkAdd(source_p, make_dlink_node(), &oper_list);

  AddOFlag(source_p, conf->port);

  if (HasOFlag(source_p, OPER_FLAG_ADMIN))
    AddUMode(source_p, UMODE_ADMIN);

  if (!EmptyString(conf->whois))
  {
    client_attach_svstag(source_p, RPL_WHOISOPERATOR, "+", conf->whois);
    sendto_server(source_p, 0, 0, ":%s SVSTAG %s %ju %u + :%s",
                  me.id, source_p->id, source_p->tsinfo,
                  RPL_WHOISOPERATOR, conf->whois);
  }

  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE, "%s is now an operator",
                       get_oper_name(source_p));
  sendto_server(NULL, 0, 0, ":%s GLOBOPS :%s is now an operator",
                me.id, get_oper_name(source_p));
  send_umode_out(source_p, old);
  sendto_one_numeric(source_p, &me, RPL_YOUREOPER);
}

/*! \brief Notices all opers of the failed oper attempt if enabled
 *
 * \param source_p Client doing /oper ...
 * \param name     The nick they tried to oper as
 * \param reason   The reason why they have failed
 */
static void
failed_oper_notice(struct Client *source_p, const char *name,
                   const char *reason)
{
  if (ConfigGeneral.failed_oper_notice)
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Failed OPER attempt as %s by %s (%s@%s) - %s",
                         name, source_p->name, source_p->username,
                         source_p->host, reason);

  ilog(LOG_TYPE_OPER, "Failed OPER attempt as %s by %s (%s@%s) - %s",
       name, source_p->name, source_p->username,
       source_p->host, reason);
}

/*! \brief OPER command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = oper name
 *      - parv[2] = oper password
 */
static int
m_oper(struct Client *source_p, int parc, char *parv[])
{
  struct MaskItem *conf = NULL;
  const char *const opername = parv[1];
  const char *const password = parv[2];

  if (EmptyString(password))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "OPER");
    return 0;
  }

  /* end the grace period */
  if (!IsFloodDone(source_p))
    flood_endgrace(source_p);

  if ((conf = find_exact_name_conf(CONF_OPER, source_p, opername, NULL, NULL)) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
    conf = find_exact_name_conf(CONF_OPER, NULL, opername, NULL, NULL);
    failed_oper_notice(source_p, opername, (conf != NULL) ?
                       "host mismatch" : "no operator {} block");
    return 0;
  }

  if (IsConfSSL(conf) && !HasUMode(source_p, UMODE_SSL))
  {
    sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
    failed_oper_notice(source_p, opername, "requires SSL/TLS");
    return 0;
  }

  if (!EmptyString(conf->certfp))
  {
    if (EmptyString(source_p->certfp) || strcasecmp(source_p->certfp, conf->certfp))
    {
      sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
      failed_oper_notice(source_p, opername, "client certificate fingerprint mismatch");
      return 0;
    }
  }

  if (match_conf_password(password, conf))
  {
    if (attach_conf(source_p, conf))
    {
      sendto_one_notice(source_p, &me, ":Can't attach conf!");
      failed_oper_notice(source_p, opername, "can't attach conf!");
      return 0;
    }

    oper_up(source_p);

    ilog(LOG_TYPE_OPER, "OPER %s by %s!%s@%s", opername, source_p->name,
         source_p->username, source_p->host);
  }
  else
  {
    sendto_one_numeric(source_p, &me, ERR_PASSWDMISMATCH);
    failed_oper_notice(source_p, opername, "password mismatch");
  }

  return 0;
}

/*! \brief OPER command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = oper name
 *      - parv[2] = oper password
 */
static int
mo_oper(struct Client *source_p, int parc, char *parv[])
{
  sendto_one_numeric(source_p, &me, RPL_YOUREOPER);
  return 0;
}

static struct Message oper_msgtab =
{
  .cmd = "OPER",
  .args_min = 3,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_oper,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_oper
};

static void
module_init(void)
{
  mod_add_cmd(&oper_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&oper_msgtab);
}

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
