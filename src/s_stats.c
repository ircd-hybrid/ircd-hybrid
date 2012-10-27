/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_stats.c: Statistics related functions
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
#include "s_stats.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_bsd.h"
#include "send.h"
#include "memory.h"

/* stats stuff */
static struct ServerStatistics ircst;
struct ServerStatistics *ServerStats = &ircst;

void
init_stats(void)
{
  memset(&ircst, 0, sizeof(ircst));
}

/* tstats()
 *
 * inputs	- client to report to
 * output	- NONE
 * side effects	-
 */
void
tstats(struct Client *source_p)
{
  const struct Client *target_p = NULL;
  struct ServerStatistics *sp;
  struct ServerStatistics tmp;
  dlink_node *ptr;

  sp = &tmp;
  memcpy(sp, ServerStats, sizeof(struct ServerStatistics));

  /*
   * must use the += operator. is_sv is not the number of currently
   * active server connections. Note the incrementation in
   * s_bsd.c:close_connection.
   */
  sp->is_sv += dlink_list_length(&serv_list);

  DLINK_FOREACH(ptr, serv_list.head)
  {
    target_p = ptr->data;

    sp->is_sbs += target_p->localClient->send.bytes;
    sp->is_sbr += target_p->localClient->recv.bytes;
    sp->is_sti += CurrentTime - target_p->firsttime;
  }

  sp->is_cl += dlink_list_length(&local_client_list);

  DLINK_FOREACH(ptr, local_client_list.head)
  {
    target_p = ptr->data;

    sp->is_cbs += target_p->localClient->send.bytes;
    sp->is_cbr += target_p->localClient->recv.bytes;
    sp->is_cti += CurrentTime - target_p->firsttime;
  }

  sp->is_ni += dlink_list_length(&unknown_list);

  sendto_one(source_p, ":%s %d %s T :accepts %u refused %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_ac, sp->is_ref);
  sendto_one(source_p, ":%s %d %s T :unknown commands %u prefixes %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_unco, sp->is_unpf);
  sendto_one(source_p, ":%s %d %s T :nick collisions %u unknown closes %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_kill, sp->is_ni);
  sendto_one(source_p, ":%s %d %s T :wrong direction %u empty %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_wrdi, sp->is_empt);
  sendto_one(source_p, ":%s %d %s T :numerics seen %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_num);
  sendto_one(source_p, ":%s %d %s T :auth successes %u fails %u",
             me.name, RPL_STATSDEBUG, source_p->name, sp->is_asuc, sp->is_abad);
  sendto_one(source_p, ":%s %d %s T :Client Server",
             me.name, RPL_STATSDEBUG, source_p->name);

  sendto_one(source_p, ":%s %d %s T :connected %u %u",
             me.name, RPL_STATSDEBUG, source_p->name, 
	     (unsigned int)sp->is_cl,
             (unsigned int)sp->is_sv);
  sendto_one(source_p, ":%s %d %s T :bytes sent %llu %llu",
             me.name, RPL_STATSDEBUG, source_p->name,
             sp->is_cbs, sp->is_sbs);
  sendto_one(source_p, ":%s %d %s T :bytes recv %llu %llu",
             me.name, RPL_STATSDEBUG, source_p->name,
             sp->is_cbr, sp->is_sbr);
  sendto_one(source_p, ":%s %d %s T :time connected %u %u",
             me.name, RPL_STATSDEBUG, source_p->name,
             (unsigned int)sp->is_cti,
	     (unsigned int)sp->is_sti);
}
