/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_kill.c
 * \brief Includes required functions for processing the KILL command.
 */

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "io_string.h"
#include "log.h"
#include "module.h"

#include "client.h"
#include "client_find.h"
#include "conf.h"
#include "conf_oper.h"
#include "ircd.h"
#include "numeric.h"
#include "parse.h"
#include "send.h"

static const struct Client *
_kill_source_for_target(const struct Client *source, const struct Client *target)
{
  if (client_is_user(source))
    return source;

  if (client_is_oper(target))
    return source;

  return client_get_visible_server(source);
}

static void
_kill_send_to_target(const struct Client *source, struct Client *target, const char *reason)
{
  assert(source);
  assert(client_is_user(source) || client_is_server(source));
  assert(client_is_local_user(target));
  assert(reason);

  const struct Client *const visible_source =
    _kill_source_for_target(source, target);
  sendto_one_command(target, visible_source, "KILL", ":%.*s", REASONLEN, reason);
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
 *      - parv[2] = reason
 */
static void
mo_kill(struct Client *source, int parc, char *parv[])
{
  bool from_history = false;

  const char *const target_name = parv[1];
  struct Client *const target = client_find_user_with_history(source, target_name, &from_history);
  if (target == NULL)
  {
    sendto_one_numeric(source, &me, ERR_NOSUCHNICK, target_name);
    return;
  }

  if (from_history)
    sendto_one_notice(source, &me, ":KILL changed from %s to %s",
                      target_name, target->name);

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

  const char *const reason = string_or_default(parv[2], CONF_NOREASON);
  if (client_is_local(target))
    _kill_send_to_target(source, target, reason);

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
_kill_source_name_for_exit_reason(const struct Client *source)
{
  if (client_is_server(source) || client_is_me(source))
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

  struct Client *const target = client_find_user(source, parv[1]);
  if (target == NULL)
    return;

  char *reason = strchr(parv[2], ' ');
  if (reason)
    *reason++ = '\0';
  else
    reason = def_reason;

  if (client_is_local(target))
    _kill_send_to_target(source, target, reason);

  /*
   * Be warned, this message must be From %s, or it confuses clients
   * so don't change it to From: or the case or anything! -- fl -- db
   */
  /*
   * Path must contain at least 2 !'s, or bitchx falsely declares it
   * local --fl
   */
  if (client_is_user(source))  /* Send it normally */
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
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_reject_not_registered },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_reject_not_oper },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_kill, .args_min = 3 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = mo_kill, .args_min = 2 }
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
