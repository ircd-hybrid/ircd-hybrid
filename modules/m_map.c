/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2024 ircd-hybrid development team
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

/*! \file m_map.c
 * \brief Includes required functions for processing the MAP command.
 */

#include "stdinc.h"
#include "io_time.h"
#include "client.h"
#include "module.h"
#include "numeric.h"
#include "send.h"
#include "user_mode.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"


static void
dump_map_flat(struct Client *client)
{
  unsigned int count = 0;

  list_node_t *node;
  LIST_FOREACH(node, global_server_list.head)
  {
    const struct Client *const server = node->data;

    if (IsHidden(server))
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    if (HasFlag(server, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    ++count;
  }

  unsigned int current_server = 0;
  LIST_FOREACH_PREV(node, global_server_list.tail)
  {
    const struct Client *const server = node->data;

    if (IsHidden(server))
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    if (HasFlag(server, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    char buf[IRCD_BUFSIZE];
    unsigned int bufpos = snprintf(buf, sizeof(buf), "%s", server->name);

    buf[bufpos++] = ' ';
    unsigned int dashes = 50 - bufpos;

    if (current_server)
      dashes -= 2;

    for (; dashes > 0; --dashes)
      buf[bufpos++] = '-';

    buf[bufpos++] = ' ';
    buf[bufpos++] = '|';

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, " Users: %5d (%1.2f%%)",
                       list_length(&server->serv->client_list), 100 *
                       (float)list_length(&server->serv->client_list) /
                       (float)list_length(&global_client_list));

    if (current_server == 0)
      sendto_one_numeric(client, &me, RPL_MAP, "", buf);
    else if (current_server == count - 1)
      sendto_one_numeric(client, &me, RPL_MAP, "`-", buf);
    else
      sendto_one_numeric(client, &me, RPL_MAP, "|-", buf);

    ++current_server;
  }
}

static void
dump_map(struct Client *client, const struct Client *server, unsigned int prompt_length)
{
  static char prompt[64];
  char *p = prompt + prompt_length;

  *p = '\0';

  if (prompt_length > 60)
    sendto_one_numeric(client, &me, RPL_MAPMORE, prompt, server->name);
  else
  {
    char buf[IRCD_BUFSIZE];
    unsigned int bufpos = snprintf(buf, sizeof(buf), "%s", server->name);

    if (user_mode_has_flag(client, UMODE_OPER))
      bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, "[%s]", server->id);

    buf[bufpos++] = ' ';

    for (int dashes = 50 - bufpos - prompt_length; dashes > 0; --dashes)
      buf[bufpos++] = '-';

    buf[bufpos++] = ' ';
    buf[bufpos++] = '|';

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, " Users: %5d (%1.2f%%)",
                       list_length(&server->serv->client_list), 100 *
                       (float)list_length(&server->serv->client_list) /
                       (float)list_length(&global_client_list));
    sendto_one_numeric(client, &me, RPL_MAP, prompt, buf);
  }

  if (prompt_length)
  {
    *(p - 1) = ' ';

    if (*(p - 2) == '`')
      *(p - 2) = ' ';
  }

  if (prompt_length > 60)
    return;
  strcpy(p, "|-");

  unsigned int count = 0;
  list_node_t *node;
  LIST_FOREACH(node, server->serv->server_list.head)
  {
    const struct Client *target = node->data;

    if (IsHidden(target))
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    if (HasFlag(target, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    ++count;
  }

  LIST_FOREACH(node, server->serv->server_list.head)
  {
    const struct Client *target = node->data;

    if (IsHidden(target))
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    if (HasFlag(target, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (user_mode_has_flag(client, UMODE_OPER) == false)
        continue;

    if (--count == 0)
      *p = '`';
    dump_map(client, target, prompt_length + 2);
  }

  if (prompt_length)
    *(p - 1) = '-';
}

/*! \brief Sends a network topology map and notifies irc-operators
 *         about the MAP request
 *
 * \param source Pointer to client to report to
 */
static void
do_map(struct Client *source)
{
  sendto_clients(UMODE_SPY, SEND_RECIPIENT_OPER_ALL, SEND_TYPE_NOTICE, "MAP requested by %s (%s@%s) [%s]",
                 source->name, source->username, source->host, source->servptr->name);

  if (ConfigServerHide.flatten_links && user_mode_has_flag(source, UMODE_OPER) == false)
    dump_map_flat(source);
  else
    dump_map(source, &me, 0);
}

/*! \brief MAP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
m_map(struct Client *source, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait) > io_time_get(IO_TIME_MONOTONIC_SEC))
  {
    sendto_one_numeric(source, &me, RPL_LOAD2HI, "MAP");
    return;
  }

  last_used = io_time_get(IO_TIME_MONOTONIC_SEC);

  do_map(source);
  sendto_one_numeric(source, &me, RPL_MAPEND);
}

/*! \brief MAP command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_map(struct Client *source, int parc, char *parv[])
{
  do_map(source);
  sendto_one_numeric(source, &me, RPL_MAPEND);
}

static struct Command command_table =
{
  .name = "MAP",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_map },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_map }
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
