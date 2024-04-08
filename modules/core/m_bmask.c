/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2024 ircd-hybrid development team
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

/*! \file m_bmask.c
 * \brief Includes required functions for processing the BMASK command.
 */

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief BMASK command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = timestamp
 *      - parv[2] = channel name
 *      - parv[3] = type of ban to add ('b' 'I' or 'e')
 *      - parv[4] = space delimited list of masks to add
 */
static void
ms_bmask(struct Client *source_p, int parc, char *parv[])
{
  char modebuf[IRCD_BUFSIZE];
  char parabuf[IRCD_BUFSIZE];
  char banbuf[IRCD_BUFSIZE];
  const char *mask;
  char *s, *t, *mbuf, *pbuf;
  list_t *list = NULL;
  size_t mlen = 0, tlen = 0;
  int modecount = 0;
  unsigned int type = 0;

  struct Channel *channel = hash_find_channel(parv[2]);
  if (channel == NULL)
    return;

  /* Their TS is higher, drop it. */
  if (strtoumax(parv[1], NULL, 10) > channel->creation_time)
    return;

  switch (*parv[3])
  {
    case 'b':
      type = CHFL_BAN;
      list = &channel->banlist;
      break;
    case 'e':
      type = CHFL_EXCEPTION;
      list = &channel->exceptlist;
      break;
    case 'I':
      type = CHFL_INVEX;
      list = &channel->invexlist;
      break;
    default:
      return;
  }

  strlcpy(banbuf, parv[4], sizeof(banbuf));
  s = banbuf;

  mlen = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s +",
                  (IsHidden(source_p) || ConfigServerHide.hide_servers) ? me.name : source_p->name,
                  channel->name);
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

    if (tlen && *s != ':' && (mask = add_id(source_p, channel, s, list, type)))
    {
      /* add_id can modify the actual ban mask */
      tlen = strlen(mask);

      /* this new one wont fit.. */
      if (mbuf - modebuf + 2 + pbuf - parabuf + tlen > sizeof(modebuf) - 2 ||
          modecount >= MAXMODEPARAMS)
      {
        *mbuf = '\0';

        sendto_channel_local(NULL, channel, 0, 0, 0, "%s %s", modebuf, parabuf);
        mbuf = modebuf + mlen;
        pbuf = parabuf;
        modecount = 0;
      }

      *mbuf++ = *parv[3];
      pbuf += snprintf(pbuf, sizeof(parabuf) - (pbuf - parabuf), pbuf != parabuf ? " %s" : "%s", mask);
      ++modecount;
    }

    s = t;
  } while (s);

  if (modecount)
  {
    *mbuf = '\0';
    sendto_channel_local(NULL, channel, 0, 0, 0, "%s %s", modebuf, parabuf);
  }

  sendto_server(source_p, 0, 0, ":%s BMASK %ju %s %s :%s",
                source_p->id, channel->creation_time, channel->name, parv[3], parv[4]);
}

static struct Command bmask_msgtab =
{
  .name = "BMASK",
  .handlers[UNREGISTERED_HANDLER] = { .handler = m_ignore },
  .handlers[CLIENT_HANDLER] = { .handler = m_ignore },
  .handlers[SERVER_HANDLER] = { .handler = ms_bmask, .args_min = 5 },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_ignore }
};

static void
module_init(void)
{
  command_add(&bmask_msgtab);
}

static void
module_exit(void)
{
  command_del(&bmask_msgtab);
}

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
  .is_core = true
};
