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

/*! \file m_kill.c
 * \brief Includes required functions for processing the KILL command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "server.h"
#include "conf.h"
#include "send.h"
#include "whowas.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


/*! \brief KILL command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = kill victim
 *      - parv[2] = reason
 */
static void
mo_kill(struct Client *source_p, int parc, char *parv[])
{
  char def_reason[] = CONF_NOREASON;

  char *reason = parv[2];  /* Either defined or NULL (parc >= 2!!) */
  if (!EmptyString(reason))
  {
    if (strlen(reason) > REASONLEN)
      reason[REASONLEN] = '\0';
  }
  else
    reason = def_reason;

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
  {
    /*
     * If the user has recently changed nick, automatically
     * rewrite the KILL for this new nickname--this keeps
     * servers in synch when nick change and kill collide
     */
    target_p = whowas_get_history(parv[1], ConfigGeneral.kill_chase_time_limit);
    if (target_p == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, parv[1]);
      return;
    }

    sendto_one_notice(source_p, &me, ":KILL changed from %s to %s",
                      parv[1], target_p->name);
  }

  if (!MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_KILL_REMOTE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "kill:remote");
    return;
  }

  if (MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_KILL))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "kill");
    return;
  }

  if (IsServer(target_p) || IsMe(target_p))
  {
    sendto_one_numeric(source_p, &me, ERR_CANTKILLSERVER);
    return;
  }

  if (MyConnect(target_p))
    sendto_one(target_p, ":%s!%s@%s KILL %s :%s",
               source_p->name, source_p->username, source_p->host,
               target_p->name, reason);

  /*
   * Do not change the format of this message. There's no point in changing messages
   * that have been around for ever, for no reason..
   */
  sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                       "Received KILL message for %s!%s@%s[%s]. From %s Path: %s (%s)",
                       target_p->name, target_p->username, target_p->host,
                       target_p->servptr->name,
                       source_p->name, me.name, reason);

  ilog(LOG_TYPE_KILL, "KILL From %s For %s Path %s (%s)",
       source_p->name, target_p->name, me.name, reason);

  /*
   * And pass on the message to other servers. Note, that if KILL was changed,
   * the message has to be sent to all links, also back.
   */
  if (!MyConnect(target_p))
  {
    sendto_server(source_p, 0, 0, ":%s KILL %s :%s!%s!%s!%s (%s)",
                  source_p->id, target_p->id, me.name, source_p->host,
                  source_p->username, source_p->name, reason);

    /*
     * Set FLAGS_KILLED. This prevents exit_client() from sending
     * the unnecessary QUIT for this. (This flag should never be
     * set in any other place)
     */
    AddFlag(target_p, FLAGS_KILLED);
  }

  char buf[IRCD_BUFSIZE];
  snprintf(buf, sizeof(buf), "Killed (%s (%s))", source_p->name, reason);

  exit_client(target_p, buf);
}

/*! \brief KILL command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = kill victim
 *      - parv[2] = kill path and reason
 */
static void
ms_kill(struct Client *source_p, int parc, char *parv[])
{
  char def_reason[] = CONF_NOREASON;

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
    return;

  char *reason = strchr(parv[2], ' ');
  if (reason)
    *reason++ = '\0';
  else
    reason = def_reason;

  if (IsServer(target_p) || IsMe(target_p))
  {
    sendto_one_numeric(source_p, &me, ERR_CANTKILLSERVER);
    return;
  }

  if (MyConnect(target_p))
  {
    if (IsServer(source_p))
    {
      /* Don't send clients kills from a hidden server */
      if ((IsHidden(source_p) || ConfigServerHide.hide_servers) && !HasUMode(target_p, UMODE_OPER))
        sendto_one(target_p, ":%s KILL %s :%s",
                   me.name, target_p->name, reason);
      else
        sendto_one(target_p, ":%s KILL %s :%s",
                   source_p->name, target_p->name, reason);
    }
    else
      sendto_one(target_p, ":%s!%s@%s KILL %s :%s",
                 source_p->name, source_p->username, source_p->host,
                 target_p->name, reason);
  }

  /*
   * Be warned, this message must be From %s, or it confuses clients
   * so don't change it to From: or the case or anything! -- fl -- db
   */
  /*
   * Path must contain at least 2 !'s, or bitchx falsely declares it
   * local --fl
   */
  if (IsClient(source_p))  /* Send it normally */
    sendto_realops_flags(UMODE_SERVNOTICE, L_ALL, SEND_NOTICE,
                         "Received KILL message for %s!%s@%s[%s]. From %s Path: %s!%s!%s!%s %s",
                         target_p->name, target_p->username, target_p->host,
                         target_p->servptr->name,
                         source_p->name,
                         source_p->servptr->name, source_p->host, source_p->username,
                         source_p->name, reason);
  else
    sendto_realops_flags(UMODE_SKILL, L_ALL, SEND_NOTICE,
                         "Received KILL message for %s!%s@%s[%s]. From %s %s",
                         target_p->name, target_p->username, target_p->host,
                         target_p->servptr->name,
                         source_p->name, reason);

  ilog(LOG_TYPE_KILL, "KILL From %s For %s Path %s %s",
       source_p->name, target_p->name, source_p->name, reason);

  sendto_server(source_p, 0, 0, ":%s KILL %s :%s %s",
                source_p->id, target_p->id, parv[2], reason);
  AddFlag(target_p, FLAGS_KILLED);

  /* Reason comes supplied with its own ()'s */
  char buf[IRCD_BUFSIZE];
  if (IsServer(source_p) && (IsHidden(source_p) || ConfigServerHide.hide_servers))
    snprintf(buf, sizeof(buf), "Killed (%s %s)", me.name, reason);
  else
    snprintf(buf, sizeof(buf), "Killed (%s %s)", source_p->name, reason);

  exit_client(target_p, buf);
}


static struct Message kill_msgtab =
{
  .cmd = "KILL",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_kill, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_kill, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&kill_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&kill_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
