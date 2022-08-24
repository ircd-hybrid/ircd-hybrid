/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999 Bahamut development team.
 *  Copyright (c) 2011-2022 ircd-hybrid development team
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
#include "modules.h"
#include "irc_string.h"
#include "user.h"
#include "conf.h"


/*! \brief SVSMODE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
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
ms_svsmode(struct Client *source_p, int parc, char *parv[])
{
  const char *const modes = parv[3];
  const struct user_modes *tab = NULL;
  int what = MODE_ADD;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return;

  struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
    return;

  uintmax_t ts = strtoumax(parv[2], NULL, 10);
  if (ts && (ts != target_p->tsinfo))
    return;

  const unsigned int setmodes = target_p->umodes;

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
        if (what == MODE_DEL && HasUMode(target_p, UMODE_OPER))
        {
          ClearOper(target_p);
          --Count.oper;

          if (MyConnect(target_p))
          {
            svstag_detach(&target_p->svstags, RPL_WHOISOPERATOR);
            conf_detach(target_p, CONF_OPER);

            ClrOFlag(target_p);
            DelUMode(target_p, ConfigGeneral.oper_only_umodes);

            dlink_node *node = dlinkFindDelete(&oper_list, target_p);
            if (node)
              free_dlink_node(node);
          }
        }

        break;

      case 'i':
        if (what == MODE_ADD && !HasUMode(target_p, UMODE_INVISIBLE))
        {
          AddUMode(target_p, UMODE_INVISIBLE);
          ++Count.invisi;
        }
        else if (what == MODE_DEL && HasUMode(target_p, UMODE_INVISIBLE))
        {
          DelUMode(target_p, UMODE_INVISIBLE);
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
            AddUMode(target_p, tab->flag);
          else
            DelUMode(target_p, tab->flag);
        }

        break;
    }
  }

  sendto_server(source_p, 0, 0, ":%s SVSMODE %s %ju %s",
                source_p->id,
                target_p->id, target_p->tsinfo, modes);

  if (MyConnect(target_p) && (setmodes != target_p->umodes))
  {
    char buf[UMODE_MAX_STR] = "";

    send_umode(target_p, true, setmodes, buf);
  }
}

static struct Message svsmode_msgtab =
{
  .cmd = "SVSMODE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_svsmode, .args_min = 4 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&svsmode_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&svsmode_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
