/*
 * SPDX-FileCopyrightText: 1997-2026 ircd-hybrid development team
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

/*! \file m_bmask.c
 * \brief Includes required functions for processing the BMASK command.
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "io_string.h"
#include "list.h"
#include "module.h"

#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "parse.h"
#include "send.h"

/*! \brief BMASK command handler
 *
 * \param source Pointer to allocated Client struct from which the message
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
ms_bmask(struct Client *source, int parc, char *parv[])
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

  struct Channel *channel = channel_find(parv[2]);
  if (channel == NULL)
    return;

  /* Their TS is higher, drop it. */
  if (strtoumax(parv[1], NULL, 10) > channel->creation_time)
    return;

  switch (*parv[3])
  {
    case 'b':
      type = CHFL_BAN;
      list = &channel->ban_list;
      break;
    case 'e':
      type = CHFL_EXCEPTION;
      list = &channel->exception_list;
      break;
    case 'I':
      type = CHFL_INVEX;
      list = &channel->invite_exception_list;
      break;
    default:
      return;
  }

  strlcpy(banbuf, parv[4], sizeof(banbuf));
  s = banbuf;

  mlen = snprintf(modebuf, sizeof(modebuf), ":%s MODE %s +",
                  client_get_visible_server_name(source), channel->name);
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

    if (tlen && *s != ':' && (mask = add_id(source, channel, s, list, type)))
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

  sendto_servers(source, 0, 0, ":%s BMASK %ju %s %s :%s",
                 source->id, channel->creation_time, channel->name, parv[3], parv[4]);
}

static struct Command command_table =
{
  .name = "BMASK",
  .handlers[COMMAND_HANDLER_UNREGISTERED] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_USER] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_SERVER] = { .handler = ms_bmask, .args_min = 5 },
  .handlers[COMMAND_HANDLER_ENCAP] = { .handler = command_handler_ignore },
  .handlers[COMMAND_HANDLER_OPER] = { .handler = command_handler_ignore }
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
