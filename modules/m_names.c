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
#include "list.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "s_serv.h"
#include "parse.h"
#include "modules.h"


/* names_all_visible_channels()
 *
 * inputs       - pointer to client struct requesting names
 * output       - none
 * side effects - lists all visible channels whee!
 */
static void
names_all_visible_channels(struct Client *source_p)
{
  dlink_node *ptr = NULL;

  /* 
   * First, do all visible channels (public and the one user self is)
   */
  DLINK_FOREACH(ptr, global_channel_list.head)
    /* Find users on same channel (defined by chptr) */
    channel_member_names(source_p, ptr->data, 0);
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
  int reply_to_send = 0;
  int shown_already;
  dlink_node *gc2ptr, *lp;
  struct Client *c2ptr;
  struct Channel *ch3ptr = NULL;
  char buf[IRCD_BUFSIZE];
  char *t;

  mlen = snprintf(buf, sizeof(buf), RPL_NAMREPLY,
                  me.name, source_p->name, "*", "*");
  cur_len = mlen;
  t = buf + mlen;

  /* Second, do all non-public, non-secret channels in one big sweep */
  DLINK_FOREACH(gc2ptr, global_client_list.head)
  {
    c2ptr = gc2ptr->data;

    if (!IsClient(c2ptr) || HasUMode(c2ptr, UMODE_INVISIBLE))
      continue;

    shown_already = 0;

    /* We already know the user is not +i. If they are on no common
     * channels with source_p, they have not been shown yet. */
    DLINK_FOREACH(lp, c2ptr->channel.head)
    {
      ch3ptr = ((struct Membership *) lp->data)->chptr;

      if (IsMember(source_p, ch3ptr))
      {
        shown_already = 1;
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

    reply_to_send = 1;
  }

  if (reply_to_send)
    sendto_one(source_p, "%s", buf);
}

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
      sendto_one(source_p, RPL_ENDOFNAMES,
                 me.name, source_p->name, para);
  }
  else
  {
    names_all_visible_channels(source_p);
    names_non_public_non_secret(source_p);
    sendto_one(source_p, RPL_ENDOFNAMES,
               me.name, source_p->name, "*");
  }
}

static struct Message names_msgtab = {
  "NAMES", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_names, m_ignore, m_ignore, m_names, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&names_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&names_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
