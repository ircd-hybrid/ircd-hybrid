/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2014 ircd-hybrid development team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 */

/*! \file m_map.c
 * \brief Includes required functions for processing the MAP command.
 * \version $Id$
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
  dlink_node *ptr = NULL;
  struct Client *target_p = NULL;
  static char prompt[64];
  static char buf[IRCD_BUFSIZE];
  char *p = prompt + prompt_length;
  unsigned int cnt = 0;
  unsigned int bufpos = 0;

  *p = '\0';

  if (prompt_length > 60)
    sendto_one_numeric(client, &me, RPL_MAPMORE, prompt, server->name);
  else
  {
    int dashes;

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, "%s", server->name);

    if (HasUMode(client, UMODE_OPER) && server->id[0])
      bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, "[%s]", server->id);

    buf[bufpos++] = ' ';
    dashes = 50 - bufpos - prompt_length;
    for (; dashes > 0; --dashes)
      buf[bufpos++] = '-';
    buf[bufpos++] = ' ';
    buf[bufpos++] = '|';

    bufpos += snprintf(buf + bufpos, sizeof(buf) - bufpos, " Users %5d (%1.2f%%)",
                       dlink_list_length(&server->serv->client_list), 100 *
                       (float)dlink_list_length(&server->serv->client_list) /
                       (float)Count.total);
    sendto_one_numeric(client, &me, RPL_MAP, prompt, buf);
  }

  if (prompt_length > 0)
  {
    *(p - 1) = ' ';

    if (*(p - 2) == '`')
      *(p - 2) = ' ';
  }

  if (prompt_length > 60)
    return;
  strcpy(p, "|-");

  DLINK_FOREACH(ptr, server->serv->server_list.head)
  {
    target_p = ptr->data;

    if (IsHidden(target_p) && !HasUMode(client, UMODE_OPER))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    ++cnt;
  }

  DLINK_FOREACH(ptr, server->serv->server_list.head)
  {
    target_p = ptr->data;

    if (IsHidden(target_p) && !HasUMode(client, UMODE_OPER))
      continue;

    if (HasFlag(target_p, FLAGS_SERVICE) && ConfigServerHide.hide_services)
      if (!HasUMode(client, UMODE_OPER))
        continue;

    if (--cnt == 0)
      *p = '`';
    dump_map(client, target_p, prompt_length + 2);
  }

  if (prompt_length > 0)
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
static int
m_map(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  if (ConfigServerHide.flatten_links)
    return m_not_oper(source_p, parc, parv);

  if ((last_used + ConfigFileEntry.pace_wait) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI);
    return 0;
  }

  last_used = CurrentTime;

  do_map(source_p);
  sendto_one_numeric(source_p, &me, RPL_MAPEND);
  return 0;
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
static int
mo_map(struct Client *source_p, int parc, char *parv[])
{
  do_map(source_p);
  sendto_one_numeric(source_p, &me, RPL_MAPEND);
  return 0;
}

static struct Message map_msgtab =
{
  "MAP", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_map, m_ignore, m_ignore, mo_map, m_ignore }
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
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
