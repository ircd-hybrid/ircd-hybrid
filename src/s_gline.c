/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_gline.c: GLine global ban functions.
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
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "conf.h"
#include "hostmask.h"
#include "s_misc.h"
#include "send.h"
#include "s_serv.h"
#include "s_gline.h"
#include "event.h"
#include "memory.h"

dlink_list pending_glines[GLINE_PENDING_ADD_TYPE + 1] = { { NULL, NULL, 0 },
                                                          { NULL, NULL, 0 } };

static void expire_pending_glines(struct gline_pending *);


struct MaskItem *
find_is_glined(const char *host, const char *user)
{
  struct irc_ssaddr iphost, *piphost = NULL;
  struct MaskItem *conf = NULL;
  int t = 0;
  int aftype = 0;

  if ((t = parse_netmask(host, &iphost, NULL)) != HM_HOST)
  {
#ifdef IPV6
    if (t == HM_IPV6)
      aftype = AF_INET6;
    else
#endif
      aftype = AF_INET;
    piphost = &iphost;
  }
  else
    piphost = NULL;

  conf = find_conf_by_address(host, piphost, CONF_GLINE, aftype, user, NULL, 0);
  return conf;
}

/* cleanup_glines()
 *
 * inputs	- NONE
 * output	- NONE
 * side effects - expire gline lists
 *                This is an event started off in ircd.c
 */
void
cleanup_glines(void *unused)
{
  expire_pending_glines(unused);
}

/* expire_pending_glines()
 *
 * inputs       - NONE
 * output       - NONE
 * side effects -
 *
 * Go through the pending gline list, expire any that haven't had
 * enough "votes" in the time period allowed
 */
static void
expire_pending_glines(struct gline_pending *in)
{
  dlink_node *ptr = NULL, *next_ptr = NULL;
  unsigned int idx = 0;

  for (; idx < GLINE_PENDING_ADD_TYPE + 1; ++idx)
  {
    DLINK_FOREACH_SAFE(ptr, next_ptr, pending_glines[idx].head)
    {
      struct gline_pending *glp_ptr = ptr->data;

      if ((glp_ptr->last_gline_time + ConfigFileEntry.gline_request_time) <= CurrentTime ||
          glp_ptr == in)
      {
        dlinkDelete(&glp_ptr->node, &pending_glines[idx]);
        MyFree(glp_ptr);
      }
    }
  }
}
