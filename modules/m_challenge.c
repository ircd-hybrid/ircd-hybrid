/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2015 ircd-hybrid development team
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

/*! \file m_challenge.c
 * \brief Includes required functions for processing the CHALLENGE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "modules.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "rsa.h"
#include "parse.h"
#include "irc_string.h"
#include "log.h"
#include "user.h"
#include "memory.h"


#ifdef HAVE_LIBCRYPTO
/*! \brief Notices all opers of the failed challenge attempt if enabled
 *
 * \param source_p Client doing /challenge ...
 * \param name     The nick they tried to oper as
 * \param reason   The reason why they have failed
 */
static void
failed_challenge_notice(struct Client *source_p, const char *name,
                        const char *reason)
{
  if (ConfigGeneral.failed_oper_notice)
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Failed CHALLENGE attempt as %s "
                         "by %s (%s@%s) - %s", name, source_p->name,
                         source_p->username, source_p->host, reason);

  ilog(LOG_TYPE_OPER, "Failed CHALLENGE attempt as %s "
       "by %s (%s@%s) - %s", name, source_p->name,
       source_p->username, source_p->host, reason);
}

/*! \brief CHALLENGE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = operator to challenge for, or +response
 */
static int
m_challenge(struct Client *source_p, int parc, char *parv[])
{
  char *challenge = NULL;
  struct MaskItem *conf = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "CHALLENGE");
    return 0;
  }

  if (*parv[1] == '+')
  {
    /* Ignore it if we aren't expecting this... -A1kmm */
    if (source_p->connection->challenge_response == NULL)
      return 0;

    if (irccmp(source_p->connection->challenge_response, ++parv[1]))
    {
      sendto_one_numeric(source_p, &me, ERR_PASSWDMISMATCH);
      failed_challenge_notice(source_p, source_p->connection->challenge_operator,
                              "challenge failed");
      return 0;
    }

    conf = find_exact_name_conf(CONF_OPER, source_p,
                                source_p->connection->challenge_operator, NULL, NULL);
    if (conf == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
      conf = find_exact_name_conf(CONF_OPER, NULL, source_p->connection->challenge_operator, NULL, NULL);
      failed_challenge_notice(source_p, source_p->connection->challenge_operator, (conf != NULL) ?
                              "host mismatch" : "no operator {} block");
      return 0;
    }

    if (attach_conf(source_p, conf))
    {
      sendto_one_notice(source_p, &me, ":Can't attach conf!");
      failed_challenge_notice(source_p, conf->name, "can't attach conf!");
      return 0;
    }

    oper_up(source_p);

    ilog(LOG_TYPE_OPER, "CHALLENGE %s by %s!%s@%s",
         source_p->connection->challenge_operator,
         source_p->name, source_p->username,
         source_p->host);

    MyFree(source_p->connection->challenge_response);
    MyFree(source_p->connection->challenge_operator);
    source_p->connection->challenge_response = NULL;
    source_p->connection->challenge_operator = NULL;
    return 0;
  }

  MyFree(source_p->connection->challenge_response);
  MyFree(source_p->connection->challenge_operator);
  source_p->connection->challenge_response = NULL;
  source_p->connection->challenge_operator = NULL;

  conf = find_exact_name_conf(CONF_OPER, source_p, parv[1], NULL, NULL);

  if (!conf)
  {
    sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
    conf = find_exact_name_conf(CONF_OPER, NULL, parv[1], NULL, NULL);
    failed_challenge_notice(source_p, parv[1], (conf != NULL)
                            ? "host mismatch" : "no operator {} block");
    return 0;
  }

  if (conf->rsa_public_key == NULL)
  {
    sendto_one_notice(source_p, &me, ":I'm sorry, PK authentication "
                      "is not enabled for your operator {} block.");
    return 0;
  }

  if (IsConfSSL(conf) && !HasUMode(source_p, UMODE_SSL))
  {
    sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
    failed_challenge_notice(source_p, conf->name, "requires SSL/TLS");
    return 0;
  }

  if (!EmptyString(conf->certfp))
  {
    if (EmptyString(source_p->certfp) || strcasecmp(source_p->certfp, conf->certfp))
    {
      sendto_one_numeric(source_p, &me, ERR_NOOPERHOST);
      failed_challenge_notice(source_p, conf->name, "client certificate fingerprint mismatch");
      return 0;
    }
  }

  if (!generate_challenge(&challenge, &source_p->connection->challenge_response,
                          conf->rsa_public_key))
  {
    sendto_one_numeric(source_p, &me, RPL_RSACHALLENGE, challenge);
    source_p->connection->challenge_operator = xstrdup(conf->name);
  }

  MyFree(challenge);
  return 0;
}

/*! \brief CHALLENGE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = operator to challenge for, or +response
 */
static int
mo_challenge(struct Client *source_p, int parc, char *parv[])
{
  sendto_one_numeric(source_p, &me, RPL_YOUREOPER);
  return 0;
}

static struct Message challenge_msgtab =
{
  .cmd = "CHALLENGE",
  .args_min = 2,
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_challenge,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_challenge
};

static void
module_init(void)
{
  mod_add_cmd(&challenge_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&challenge_msgtab);
}

#else

static void
module_init(void)
{
}

static void
module_exit(void)
{
}
#endif

struct module module_entry =
{
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
