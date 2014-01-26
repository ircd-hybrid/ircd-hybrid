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


/*
 * m_mode - MODE command handler
 * parv[0] - sender
 * parv[1] - channel
 */
static int
m_mode(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;
  char modebuf[MODEBUFLEN];
  char parabuf[MODEBUFLEN];

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "MODE");
    return 0;
  }

  /* Now, try to find the channel in question */
  if (!IsChanPrefix(*parv[1]))
  {
    /* if here, it has to be a non-channel name */
    set_user_mode(client_p, source_p, parc, parv);
    return 0;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               ID_or_name(&me, source_p),
               ID_or_name(source_p, source_p),
               parv[1]);
    return 0;
  }

  /* Now known the channel exists */
  if (parc < 3)
  {
    channel_modes(chptr, source_p, modebuf, parabuf);
    sendto_one(source_p, form_str(RPL_CHANNELMODEIS),
               me.name, source_p->name, chptr->chname, modebuf, parabuf);
    sendto_one(source_p, form_str(RPL_CREATIONTIME),
               me.name, source_p->name, chptr->chname, chptr->channelts);
    return 0;
  }

  /*
   * bounce all modes from people we deop on sjoin
   * servers have always gotten away with murder,
   * including telnet servers *g* - Dianora
   */
  if (IsServer(source_p) || HasFlag(source_p, FLAGS_SERVICE))
    set_channel_mode(client_p, source_p, chptr, NULL, parc - 2, parv + 2);
  else
  {
    member = find_channel_link(source_p, chptr);

    if (!has_member_flags(member, CHFL_DEOPPED))
    {
      /* Finish the flood grace period... */
      if (MyClient(source_p) && !IsFloodDone(source_p))
        if (!((parc == 3) && (parv[2][0] == 'b') && (parv[2][1] == '\0')))
          flood_endgrace(source_p);

      set_channel_mode(client_p, source_p, chptr, member, parc - 2, parv + 2);
    }
  }

  return 0;
}

/*
 * ms_tmode()
 *
 * inputs	- parv[0] = UID
 *		  parv[1] = TS
 *		  parv[2] = channel name
 *		  parv[3] = modestring
 */
static int
ms_tmode(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               ID_or_name(&me, client_p), ID_or_name(source_p, client_p), parv[2]);
    return 0;
  }

  if (atol(parv[1]) > chptr->channelts)
    return 0;

  if (IsServer(source_p) || HasFlag(source_p, FLAGS_SERVICE))
    set_channel_mode(client_p, source_p, chptr, NULL, parc - 3, parv + 3);
  else
  {
    member = find_channel_link(source_p, chptr);

    /* XXX are we sure we just want to bail here? */
    if (has_member_flags(member, CHFL_DEOPPED))
      return 0;

    set_channel_mode(client_p, source_p, chptr, member, parc - 3, parv + 3);
  }

  return 0;
}

/*
 * ms_bmask()
 *
 * inputs	- parv[0] = SID
 *		  parv[1] = TS
 *		  parv[2] = channel name
 *		  parv[3] = type of ban to add ('b' 'I' or 'e')
 *		  parv[4] = space delimited list of masks to add
 * outputs	- none
 * side effects	- propagates unchanged bmask line to CAP_TS6 servers,
 *		  sends plain modes to the others.  nothing is sent
 *		  to the server the issuing server is connected through
 */
static int
ms_bmask(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  char modebuf[IRCD_BUFSIZE];
  char parabuf[IRCD_BUFSIZE];
  char banbuf[IRCD_BUFSIZE];
  struct Channel *chptr;
  char *s, *t, *mbuf, *pbuf;
  long mode_type;
  int mlen, tlen;
  int modecount = 0;
  int needcap = NOCAPS;

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
      needcap = CAP_EX;
      break;

    case 'I':
      mode_type = CHFL_INVEX;
      needcap = CAP_IE;
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
        sendto_server(client_p, needcap, CAP_TS6,
                      "%s %s", modebuf, parabuf);

        mbuf = modebuf + mlen;
        pbuf = parabuf;
        modecount = 0;
      }

      *mbuf++ = parv[3][0];
      pbuf += sprintf(pbuf, "%s ", s);
      modecount++;
    }

    s = t;
  } while (s != NULL);

  if (modecount)
  {
    *mbuf = *(pbuf - 1) = '\0';
    sendto_channel_local(ALL_MEMBERS, 0, chptr, "%s %s", modebuf, parabuf);
    sendto_server(client_p, needcap, CAP_TS6,
                  "%s %s", modebuf, parabuf);
  }

  /* assumption here is that since the server sent BMASK, they are TS6, so they have an ID */
  sendto_server(client_p, CAP_TS6|needcap, NOCAPS, ":%s BMASK %lu %s %s :%s",
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
