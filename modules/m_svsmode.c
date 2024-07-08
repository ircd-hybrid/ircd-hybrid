/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999 Bahamut development team.
 *  Copyright (c) 2011-2024 ircd-hybrid development team
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

/*! \file m_svsmode.c
 * \brief Includes required functions for processing the SVSMODE command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "client_svstag.h"
#include "ircd.h"
#include "send.h"
#include "channel.h"
#include "channel_mode.h"
#include "parse.h"
#include "module.h"
#include "user.h"
#include "conf.h"


/*! \brief SVSMODE command handler
 *
 * \param source Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname
 *      - parv[2] = TS
 *      - parv[3] = modes to be added or removed
 */
static void
ms_svsmode(struct Client *source, int parc, char *parv[])
{
  const char *const modes = parv[3];
  const struct user_modes *tab = NULL;
  int what = MODE_ADD;

  if (!HasFlag(source, FLAGS_SERVICE) && !IsServer(source))
    return;

  struct Client *target = find_person(source, parv[1]);
  if (target == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target->tsinfo))
    return;

  const unsigned int oldmodes = target->umodes;

  for (const char *m = modes; *m; ++m)
  {
    switch (*m)
    {
      case '+':
        what = MODE_ADD;
        break;
      case '-':
        what = MODE_DEL;
        break;

      case 'o':
        if (what == MODE_DEL && HasUMode(target, UMODE_OPER))
        {
          ClearOper(target);
          --Count.oper;

          if (MyConnect(target))
          {
            svstag_detach(&target->svstags, RPL_WHOISOPERATOR);
            conf_detach(target, CONF_OPER);

            ClrOFlag(target);
            DelUMode(target, ConfigGeneral.oper_only_umodes);

            list_node_t *node = list_find_remove(&oper_list, target);
            if (node)
              list_free_node(node);
          }
        }

        break;

      case 'i':
        if (what == MODE_ADD && !HasUMode(target, UMODE_INVISIBLE))
        {
          AddUMode(target, UMODE_INVISIBLE);
          ++Count.invisi;
        }
        else if (what == MODE_DEL && HasUMode(target, UMODE_INVISIBLE))
        {
          DelUMode(target, UMODE_INVISIBLE);
          --Count.invisi;
        }

        break;

      case 'z':
      case 'S':  /* Only servers may set +S in a burst */
      case 'W':  /* Only servers may set +W in a burst */
        break;

      default:
        if ((tab = umode_map[(unsigned char)*m]))
        {
          if (what == MODE_ADD)
            AddUMode(target, tab->flag);
          else
            DelUMode(target, tab->flag);
        }

        break;
    }
  }

  sendto_servers(source, 0, 0, ":%s SVSMODE %s %ju %s",
                source->id, target->id, target->tsinfo, modes);

  if (MyConnect(target))
    send_umode(target, oldmodes, true, false);
}

static struct Command command_table =
{
  .name = "SVSMODE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svsmode, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
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
