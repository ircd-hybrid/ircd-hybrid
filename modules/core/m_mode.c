/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2022 ircd-hybrid development team
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

/*! \file m_mode.c
 * \brief Includes required functions for processing the MODE command.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "client_svstag.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "user.h"
#include "conf.h"
#include "server.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "packet.h"


/* set_user_mode()
 *
 * added 15/10/91 By Darren Reed.
 * parv[0] - command
 * parv[1] - username to change mode for
 * parv[2] - modes to change
 */
static void
set_user_mode(struct Client *source_p, const int parc, char *parv[])
{
  const struct user_modes *tab = NULL;
  const unsigned int setmodes = source_p->umodes;
  bool badmode = false;
  int what = MODE_ADD;

  const struct Client *target_p = find_person(source_p, parv[1]);
  if (target_p == NULL)
  {
    if (MyConnect(source_p))
      sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  if (source_p != target_p)
  {
     sendto_one_numeric(source_p, &me, ERR_USERSDONTMATCH);
     return;
  }

  if (parc < 3)
  {
    sendto_one_numeric(source_p, &me, RPL_UMODEIS,
                       user_get_mode_str(source_p->umodes));
    return;
  }

  /* Parse user mode change string */
  for (const char *m = parv[2]; *m; ++m)
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
        if (what == MODE_ADD)
        {
          if (!MyConnect(source_p) && !HasUMode(source_p, UMODE_OPER))
          {
            ++Count.oper;
            SetOper(source_p);
          }
        }
        else
        {
          if (!HasUMode(source_p, UMODE_OPER))
            break;

          ClearOper(source_p);
          --Count.oper;

          if (MyConnect(source_p))
          {
            svstag_detach(&source_p->svstags, RPL_WHOISOPERATOR);
            conf_detach(source_p, CONF_OPER);

            ClrOFlag(source_p);
            DelUMode(source_p, ConfigGeneral.oper_only_umodes);

            dlink_node *node = dlinkFindDelete(&oper_list, source_p);
            if (node)
              free_dlink_node(node);
          }
        }

        break;

      case 'S':  /* Only servers may set +S in a burst */
      case 'W':  /* Only servers may set +W in a burst */
      case 'r':  /* Only services may set +r */
        break;

      default:
        if ((tab = umode_map[(unsigned char)*m]))
        {
          if (MyConnect(source_p) && !HasUMode(source_p, UMODE_OPER) &&
              (ConfigGeneral.oper_only_umodes & tab->flag))
            badmode = true;
          else
          {
            if (what == MODE_ADD)
              AddUMode(source_p, tab->flag);
            else
              DelUMode(source_p, tab->flag);
          }
        }
        else if (MyConnect(source_p))
          badmode = true;

        break;
    }
  }

  if (badmode == true)
    sendto_one_numeric(source_p, &me, ERR_UMODEUNKNOWNFLAG);

  if (MyConnect(source_p) && HasUMode(source_p, UMODE_ADMIN) &&
      !HasOFlag(source_p, OPER_FLAG_ADMIN))
  {
    sendto_one_notice(source_p, &me, ":*** You have no admin flag;");
    DelUMode(source_p, UMODE_ADMIN);
  }

  if (!(setmodes & UMODE_INVISIBLE) && HasUMode(source_p, UMODE_INVISIBLE))
    ++Count.invisi;
  else if ((setmodes & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
    --Count.invisi;

  /*
   * Compare new modes with old modes and send string which will cause
   * servers to update correctly.
   */
  send_umode_out(source_p, setmodes);
}

/*! \brief MODE command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = channel or nick name
 *      - parv[2] = modes to be added or removed
 */
static void
m_mode(struct Client *source_p, int parc, char *parv[])
{
  /* Now, try to find the channel in question */
  if (!IsChanPrefix(*parv[1]))
  {
    /* If here, it has to be a non-channel name */
    set_user_mode(source_p, parc, parv);
    return;
  }

  struct Channel *channel = hash_find_channel(parv[1]);
  if (channel == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return;
  }

  /* Now known the channel exists */
  if (parc < 3)
  {
    sendto_one_numeric(source_p, &me, RPL_CHANNELMODEIS, channel->name,
                       channel_modes(channel, source_p, true));
    sendto_one_numeric(source_p, &me, RPL_CREATIONTIME, channel->name, channel->creation_time);
    return;
  }

  channel_mode_set(source_p, channel, parc - 2, parv + 2);
}

static struct Message mode_msgtab =
{
  .cmd = "MODE",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_unregistered },
  .handlers[CLIENT_HANDLER] = { .handler = m_mode, .args_min = 2 },
  .handlers[SERVER_HANDLER] = { .handler = m_mode, .args_min = 2 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_mode, .args_min = 2 }
};

static void
module_init(void)
{
  mod_add_cmd(&mode_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&mode_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
