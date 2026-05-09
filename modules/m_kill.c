/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2026 ircd-hybrid development team
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

#include "io_string.h"
#include "list.h"
#include "log.h"
#include "module.h"
#include "stdinc.h"
#include "client.h"
#include "conf.h"
#include "conf_oper.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"
#include "server.h"
#include "user_mode.h"
#include "whowas.h"

/*! \brief KILL command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
mo_kill(struct Client *source, int parc, char *parv[])
{
  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
  {
    /*
     * If the user has recently changed nick, automatically
     * rewrite the KILL for this new nickname--this keeps
     * servers in synch when nick change and kill collide
     */
    target = whowas_get_history(parv[1], ConfigGeneral.kill_chase_time_limit);
    if (target == NULL)
    {
      sendto_one_numeric(source, &me, ERR_NOSUCHNICK, parv[1]);
      return;
    }

    sendto_one_notice(source, &me, ":KILL changed from %s to %s",
                      parv[1], target->name);
  }

  assert(IsClient(target));
  if (!client_is_local(target) && !client_has_oper_flag(source, OPER_FLAG_KILL_REMOTE))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kill:remote");
    return;
  }

  if (client_is_local(target) && !client_has_oper_flag(source, OPER_FLAG_KILL))
  {
    sendto_one_numeric(source, &me, ERR_NOPRIVS, "kill");
    return;
  }

  const char *const reason = string_default(parv[2], CONF_NOREASON);
  if (client_is_local(target))
    sendto_one(target, ":%s!%s@%s KILL %s :%.*s",
               source->name, source->username, source->host, target->name, REASONLEN, reason);

  /*
   * Do not change the format of this message. There's no point in changing messages
   * that have been around for ever, for no reason..
   */
  sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                 "Received KILL message for %s!%s@%s[%s]. From %s Path: %s (%.*s)",
                 target->name, target->username, target->host,
                 target->uplink->name, source->name, me.name, REASONLEN, reason);

  log_write(LOG_TYPE_KILL, "KILL From %s For %s Path %s (%.*s)",
            source->name, target->name, me.name, REASONLEN, reason);

  /*
   * And pass on the message to other servers. Note, that if KILL was changed,
   * the message has to be sent to all links, also back.
   */
  if (!client_is_local(target))
  {
    sendto_servers(source, 0, 0, ":%s KILL %s :%s!%s!%s!%s (%.*s)",
                   source->id, target->id, me.name, source->host,
                   source->username, source->name, REASONLEN, reason);

    /*
     * Set FLAGS_KILLED. This prevents client_exit() from sending
     * the unnecessary QUIT for this. (This flag should never be
     * set in any other place)
     */
    client_set_flag(target, FLAGS_KILLED);
  }

  client_exit_fmt(target, "Killed (%s (%.*s))", source->name, REASONLEN, reason);
}

static const char *
_kill_source_name_for_target(const struct Client *source, const struct Client *target)
{
  if (client_is_oper(target))
    return source->name;

  return client_get_visible_server_name(source);
}

static const char *
_kill_source_name_for_exit_reason(const struct Client *source)
{
  if (IsServer(source) || client_is_me(source))
    return client_get_visible_server_name(source);

  return source->name;
}

/*! \brief KILL command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
ms_kill(struct Client *source, int parc, char *parv[])
{
  char def_reason[] = CONF_NOREASON;

  struct Client *const target = find_person(source, parv[1]);
  if (target == NULL)
    return;
  assert(IsClient(target));

  char *reason = strchr(parv[2], ' ');
  if (reason)
    *reason++ = '\0';
  else
    reason = def_reason;

  if (client_is_local(target))
  {
    if (IsClient(source))
      sendto_one(target, ":%s!%s@%s KILL %s :%s",
                 source->name, source->username, source->host, target->name, reason);
    else
      sendto_one(target, ":%s KILL %s :%s",
                 _kill_source_name_for_target(source, target), target->name, reason);
  }

  /*
   * Be warned, this message must be From %s, or it confuses clients
   * so don't change it to From: or the case or anything! -- fl -- db
   */
  /*
   * Path must contain at least 2 !'s, or bitchx falsely declares it
   * local --fl
   */
  if (IsClient(source))  /* Send it normally */
    sendto_clients(UMODE_SERVNOTICE, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Received KILL message for %s!%s@%s[%s]. From %s Path: %s!%s!%s!%s %s",
                   target->name, target->username, target->host,
                   target->uplink->name, source->name,
                   source->uplink->name, source->host, source->username, source->name, reason);
  else
    sendto_clients(UMODE_SKILL, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE,
                   "Received KILL message for %s!%s@%s[%s]. From %s %s",
                   target->name, target->username, target->host,
                   target->uplink->name, source->name, reason);

  log_write(LOG_TYPE_KILL, "KILL From %s For %s Path %s %s",
            source->name, target->name, source->name, reason);

  sendto_servers(source, 0, 0, ":%s KILL %s :%s %s",
                 source->id, target->id, parv[2], reason);

  client_set_flag(target, FLAGS_KILLED);
  /* Reason comes supplied with its own ()'s */
  client_exit_fmt(target, "Killed (%s %s)",
                  _kill_source_name_for_exit_reason(source), reason);
}

static struct Command command_table =
{
  .name = "KILL",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_not_oper },
  .handlers[SERVER_HANDLER] = { .handler = ms_kill, .args_min = 3 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_kill, .args_min = 2 }
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
  .core = true
};
