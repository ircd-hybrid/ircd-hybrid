/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2022 ircd-hybrid development team
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
#include "client.h"
#include "modules.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "ircd.h"
#include "parse.h"


static void dump_map(struct Client *client,
                     struct Client *server,
                     unsigned int prompt_length)
{
  dlink_node *node;
  static char prompt[64];
  char buf[IRCD_BUFSIZE];
  char *p = prompt + prompt_length;
  unsigned int cnt = 0;

  *p = '\0';

  if (prompt_length > 60)
    sendto_one_numeric(client, &me, RPL_MAPMORE, prompt, server->name);
  else
  {
    unsigned int bufpos = snprintf(buf, sizeof(buf), "%s", server->name);

    if (HasUMode(client, UMODE_OPER))
      bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, "[%s]", server->id);

    buf[bufpos++] = ' ';

    for (int dashes = 50 - bufpos - prompt_length; dashes > 0; --dashes)
      buf[bufpos++] = '-';

    buf[bufpos++] = ' ';
    buf[bufpos++] = '|';

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, " Users: %5d (%1.2f%%)",
                       dlink_list_length(&server->serv->client_list), 100 *
                       (float)dlink_list_length(&server->serv->client_list) /
                       (float)dlink_list_length(&global_client_list));
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

  DLINK_FOREACH(node, server->serv->server_list.head)
  {
    struct Client *target_p = node->data;

    if (IsHidden(target_p))
      if (!HasUMode(client, UMODE_OPER))
        continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    ++cnt;
  }

  DLINK_FOREACH(node, server->serv->server_list.head)
  {
    struct Client *target_p = node->data;

    if (IsHidden(target_p))
      if (!HasUMode(client, UMODE_OPER))
        continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    if (--cnt == 0)
      *p = '`';
    dump_map(client, target_p, prompt_length + 2);
  }

  if (prompt_length)
    *(p - 1) = '-';
}

/*! \brief Sends a network topology map and notifies irc-operators
 *         about the MAP request
 *
 * \param source_p Pointer to client to report to
 */
static void
do_map(struct Client *source_p)
{
  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE,
                       "MAP requested by %s (%s@%s) [%s]",
                       source_p->name, source_p->username,
                       source_p->host, source_p->servptr->name);
  dump_map(source_p, &me, 0);
}

/*! \brief MAP command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
m_map(struct Client *source_p, int parc, char *parv[])
{
  static uintmax_t last_used = 0;

  if (ConfigServerHide.flatten_links)
  {
    m_not_oper(source_p, parc, parv);
    return;
  }

  if ((last_used + ConfigGeneral.pace_wait) > event_base->time.sec_monotonic)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "MAP");
    return;
  }

  last_used = event_base->time.sec_monotonic;

  do_map(source_p);
  sendto_one_numeric(source_p, &me, RPL_MAPEND);
}

/*! \brief MAP command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 */
static void
mo_map(struct Client *source_p, int parc, char *parv[])
{
  do_map(source_p);
  sendto_one_numeric(source_p, &me, RPL_MAPEND);
}

static struct Message map_msgtab =
{
  .cmd = "MAP",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_map },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = mo_map }
};

static void
module_init(void)
{
  mod_add_cmd(&map_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&map_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
