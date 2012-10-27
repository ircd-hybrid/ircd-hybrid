/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_names.c: Shows the users who are online.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *
 *  $Id$
 */

#include "stdinc.h"
#include "tools.h"
#include "handlers.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "common.h"   /* bleah */
#include "hash.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "s_conf.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"


static void names_all_visible_channels(struct Client *);
static void names_non_public_non_secret(struct Client *);

static void m_names(struct Client *, struct Client *, int, char *[]);
static void ms_names(struct Client *, struct Client *, int, char *[]);

struct Message names_msgtab = {
  "NAMES", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_names, ms_names, m_ignore, m_names, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&names_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&names_msgtab);
}

const char *_version = "$Revision$";
#endif

/************************************************************************
 * m_names() - Added by Jto 27 Apr 1989
 ************************************************************************/

/*
** m_names
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
m_names(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{ 
  struct Channel *chptr = NULL;
  char *s;
  char *para = parc > 1 ? parv[1] : NULL;

  if (!EmptyString(para))
  {
    while (*para == ',')
      ++para;

    if ((s = strchr(para, ',')) != NULL)
      *s = '\0';

    if (*para == '\0')
      return;

    if ((chptr = hash_find_channel(para)) != NULL)
      channel_member_names(source_p, chptr, 1);
    else
      sendto_one(source_p, form_str(RPL_ENDOFNAMES),
                 me.name, source_p->name, para);
  }
  else
  {
    names_all_visible_channels(source_p);
    names_non_public_non_secret(source_p);
    sendto_one(source_p, form_str(RPL_ENDOFNAMES),
               me.name, source_p->name, "*");
  }
}

/* names_all_visible_channels()
 *
 * inputs       - pointer to client struct requesting names
 * output       - none
 * side effects - lists all visible channels whee!
 */
static void
names_all_visible_channels(struct Client *source_p)
{
  dlink_node *ptr;
  struct Channel *chptr;

  /* 
   * First, do all visible channels (public and the one user self is)
   */
  DLINK_FOREACH(ptr, global_channel_list.head)
  {
    chptr = ptr->data;

    /* Find users on same channel (defined by chptr) */
    channel_member_names(source_p, chptr, 0);
  }
}

/* names_non_public_non_secret()
 *
 * inputs       - pointer to client struct requesting names
 * output       - none
 * side effects - lists all non public non secret channels
 */
static void
names_non_public_non_secret(struct Client *source_p)
{
  int mlen, tlen, cur_len;
  int reply_to_send = NO;
  int shown_already;
  dlink_node *gc2ptr, *lp;
  struct Client *c2ptr;
  struct Channel *ch3ptr = NULL;
  char buf[IRCD_BUFSIZE];
  char *t;

  mlen = ircsprintf(buf,form_str(RPL_NAMREPLY),
                    me.name, source_p->name, "*", "*");
  cur_len = mlen;
  t = buf + mlen;

  /* Second, do all non-public, non-secret channels in one big sweep */
  DLINK_FOREACH(gc2ptr, global_client_list.head)
  {
    c2ptr = gc2ptr->data;

    if (!IsClient(c2ptr) || IsInvisible(c2ptr))
      continue;

    shown_already = NO;

    /* We already know the user is not +i. If they are on no common
     * channels with source_p, they have not been shown yet. */
    DLINK_FOREACH(lp, c2ptr->channel.head)
    {
      ch3ptr = ((struct Membership *) lp->data)->chptr;

      if (IsMember(source_p, ch3ptr))
      {
        shown_already = YES;
        break;
      }
    }

    if (shown_already)
      continue;

    tlen = strlen(c2ptr->name);
    if (cur_len + tlen + 1 > IRCD_BUFSIZE - 2)
    {
      sendto_one(source_p, "%s", buf);
      cur_len = mlen;
      t = buf + mlen;
    }

    strcpy(t, c2ptr->name);
    t += tlen;

    *t++ = ' ';
    *t = 0;

    cur_len += tlen + 1;

    reply_to_send = YES;
  }

  if (reply_to_send)
    sendto_one(source_p, "%s", buf);
}

static void
ms_names(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  /* If its running as a hub, and linked with lazy links
   * then allow leaf to use normal client m_names()
   * other wise, ignore it.
   */
  if (ServerInfo.hub)
  {
    if (!IsCapable(client_p->from, CAP_LL))
      return;
  }

  if (IsClient(source_p))
    m_names(client_p, source_p, parc, parv);
}
