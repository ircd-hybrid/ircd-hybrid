/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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

/*! \file m_mode.c
 * \brief Includes required functions for processing the MODE/TMODE/BMASK command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_user.h"
#include "conf.h"
#include "s_serv.h"
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
  unsigned int flag, setflags;
  char buf[IRCD_BUFSIZE] = "";
  struct Client *target_p = NULL;
  int what = MODE_ADD, badflag = 0;

  assert(!(parc < 2));

  if ((target_p = find_person(source_p, parv[1])) == NULL)
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
    char *m = buf;
    *m++ = '+';

    for (unsigned int i = 0; i < 128; ++i)
      if (HasUMode(source_p, user_modes[i]))
        *m++ = (char)i;
    *m = '\0';

    sendto_one_numeric(source_p, &me, RPL_UMODEIS, buf);
    return;
  }

  /* find flags already set for user */
  setflags = source_p->umodes;

  /* parse mode change string(s) */
  for (char **p = &parv[2]; p && *p; ++p)
  {
    for (const char *m = *p; *m; ++m)
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
            Count.oper--;

            if (MyConnect(source_p))
            {
              dlink_node *ptr = NULL;

              detach_conf(source_p, CONF_OPER);
              ClrOFlag(source_p);
              DelUMode(source_p, ConfigFileEntry.oper_only_umodes);

              if ((ptr = dlinkFindDelete(&oper_list, source_p)))
                free_dlink_node(ptr);
            }
          }

          break;

        case 'S':  /* Only servers may set +S in a burst */
        case 'W':  /* Only servers may set +W in a burst */
        case 'r':  /* Only services may set +r */
        case 'x':  /* Only services may set +x */
          break;

        default:
          if ((flag = user_modes[(unsigned char)*m]))
          {
            if (MyConnect(source_p) && !HasUMode(source_p, UMODE_OPER) &&
                (ConfigFileEntry.oper_only_umodes & flag))
              badflag = 1;
            else
            {
              if (what == MODE_ADD)
                AddUMode(source_p, flag);
              else
                DelUMode(source_p, flag);
            }
          }
          else if (MyConnect(source_p))
            badflag = 1;

          break;
      }
    }
  }

  if (badflag)
    sendto_one_numeric(source_p, &me, ERR_UMODEUNKNOWNFLAG);

  if (MyConnect(source_p) && HasUMode(source_p, UMODE_ADMIN) &&
      !HasOFlag(source_p, OPER_FLAG_ADMIN))
  {
    sendto_one_notice(source_p, &me, ":*** You have no admin flag;");
    DelUMode(source_p, UMODE_ADMIN);
  }

  if (!(setflags & UMODE_INVISIBLE) && HasUMode(source_p, UMODE_INVISIBLE))
    ++Count.invisi;
  if ((setflags & UMODE_INVISIBLE) && !HasUMode(source_p, UMODE_INVISIBLE))
    --Count.invisi;

  /*
   * compare new flags with old flags and send string which
   * will cause servers to update correctly.
   */
  send_umode_out(source_p, source_p, setflags);
}

/*
 * m_mode - MODE command handler
 * parv[0] - command
 * parv[1] - channel
 */
static int
m_mode(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;
  char modebuf[MODEBUFLEN];
  char parabuf[MODEBUFLEN];

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "MODE");
    return 0;
  }

  /* Now, try to find the channel in question */
  if (!IsChanPrefix(*parv[1]))
  {
    /* if here, it has to be a non-channel name */
    set_user_mode(source_p, parc, parv);
    return 0;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[1]);
    return 0;
  }

  /* Now known the channel exists */
  if (parc < 3)
  {
    channel_modes(chptr, source_p, modebuf, parabuf);
    sendto_one_numeric(source_p, &me, RPL_CHANNELMODEIS, chptr->chname, modebuf, parabuf);
    sendto_one_numeric(source_p, &me, RPL_CREATIONTIME, chptr->chname, chptr->channelts);
    return 0;
  }

  /*
   * bounce all modes from people we deop on sjoin
   * servers have always gotten away with murder,
   * including telnet servers *g* - Dianora
   */
  if (IsServer(source_p) || HasFlag(source_p, FLAGS_SERVICE))
    set_channel_mode(source_p, chptr, NULL, parc - 2, parv + 2);
  else
  {
    member = find_channel_link(source_p, chptr);

    if (!has_member_flags(member, CHFL_DEOPPED))
    {
      /* Finish the flood grace period... */
      if (MyClient(source_p) && !IsFloodDone(source_p))
        if (!((parc == 3) && (parv[2][0] == 'b') && (parv[2][1] == '\0')))
          flood_endgrace(source_p);

      set_channel_mode(source_p, chptr, member, parc - 2, parv + 2);
    }
  }

  return 0;
}

/*
 * ms_tmode()
 *
 * inputs	- parv[0] = command
 *		  parv[1] = TS
 *		  parv[2] = channel name
 *		  parv[3] = modestring
 */
static int
ms_tmode(struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_NOSUCHCHANNEL, parv[2]);
    return 0;
  }

  if (atol(parv[1]) > chptr->channelts)
    return 0;

  if (IsServer(source_p) || HasFlag(source_p, FLAGS_SERVICE))
    set_channel_mode(source_p, chptr, NULL, parc - 3, parv + 3);
  else
  {
    member = find_channel_link(source_p, chptr);

    /* XXX are we sure we just want to bail here? */
    if (has_member_flags(member, CHFL_DEOPPED))
      return 0;

    set_channel_mode(source_p, chptr, member, parc - 3, parv + 3);
  }

  return 0;
}

/*
 * ms_bmask()
 *
 * inputs	- parv[0] = command
 *		  parv[1] = TS
 *		  parv[2] = channel name
 *		  parv[3] = type of ban to add ('b' 'I' or 'e')
 *		  parv[4] = space delimited list of masks to add
 * outputs	- none
 * side effects	- propagates unchanged bmask line to servers
 */
static int
ms_bmask(struct Client *source_p, int parc, char *parv[])
{
  char modebuf[IRCD_BUFSIZE];
  char parabuf[IRCD_BUFSIZE];
  char banbuf[IRCD_BUFSIZE];
  struct Channel *chptr;
  char *s, *t, *mbuf, *pbuf;
  unsigned int mode_type = 0;
  int mlen, tlen;
  int modecount = 0;

  if ((chptr = hash_find_channel(parv[2])) == NULL)
    return 0;

  /* TS is higher, drop it. */
  if (atol(parv[1]) > chptr->channelts)
    return 0;

  switch (*parv[3])
  {
    case 'b':
      mode_type = CHFL_BAN;
      break;

    case 'e':
      mode_type = CHFL_EXCEPTION;
      break;

    case 'I':
      mode_type = CHFL_INVEX;
      break;

    /* maybe we should just blindly propagate this? */
    default:
      return 0;
  }

  parabuf[0] = '\0';
  s = banbuf;
  strlcpy(s, parv[4], sizeof(banbuf));

  /* only need to construct one buffer, for non-ts6 servers */
  mlen = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s +",
                  (IsHidden(source_p) || ConfigServerHide.hide_servers) ? me.name : source_p->name,
                  chptr->chname);
  mbuf = modebuf + mlen;
  pbuf = parabuf;

  do
  {
    if ((t = strchr(s, ' ')))
      *t++ = '\0';
    tlen = strlen(s);

    /* I don't even want to begin parsing this.. */
    if (tlen > MODEBUFLEN)
      break;

    if (tlen && *s != ':' && add_id(source_p, chptr, s, mode_type))
    {
      /* this new one wont fit.. */
      if (mbuf - modebuf + 2 + pbuf - parabuf + tlen > IRCD_BUFSIZE - 2 ||
          modecount >= MAXMODEPARAMS)
      {
        *mbuf = '\0';
        *(pbuf - 1) = '\0';

        sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s",
                             modebuf, parabuf);
        mbuf = modebuf + mlen;
        pbuf = parabuf;
        modecount = 0;
      }

      *mbuf++ = parv[3][0];
      pbuf += sprintf(pbuf, "%s ", s);
      modecount++;
    }

    s = t;
  } while (s);

  if (modecount)
  {
    *mbuf = *(pbuf - 1) = '\0';
    sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s", modebuf, parabuf);
  }

  sendto_server(source_p, NOCAPS, NOCAPS, ":%s BMASK %lu %s %s :%s",
                source_p->id, (unsigned long)chptr->channelts, chptr->chname,
                parv[3], parv[4]);
  return 0;
}

static struct Message mode_msgtab =
{
  "MODE", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_mode, m_mode, m_ignore, m_mode, m_ignore }
};

static struct Message tmode_msgtab =
{
  "TMODE", 0, 0, 4, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_tmode, m_ignore, m_ignore, m_ignore }
};

static struct Message bmask_msgtab =
{
  "BMASK", 0, 0, 5, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_ignore, ms_bmask, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&mode_msgtab);
  mod_add_cmd(&tmode_msgtab);
  mod_add_cmd(&bmask_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&mode_msgtab);
  mod_del_cmd(&tmode_msgtab);
  mod_del_cmd(&bmask_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
