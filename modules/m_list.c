/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_list.c: List channel given or all channels.
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
#include "hash.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "list.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "s_user.h"

static void m_list(struct Client *, struct Client *, int, char **);
static void ms_list(struct Client *, struct Client *, int, char **);
static void mo_list(struct Client *, struct Client *, int, char **);

struct Message list_msgtab = {
  "LIST", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_list, ms_list, m_ignore, mo_list, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&list_msgtab);
  add_isupport("ELIST", "CMNTU", -1);
  add_isupport("SAFELIST", NULL, -1);
}

void
_moddeinit(void)
{
  mod_del_cmd(&list_msgtab);
  delete_isupport("ELIST");
  delete_isupport("SAFELIST");
}

const char *_version = "$Revision$";
#endif

static int
has_wildcards(const char *s)
{
  char c;

  while ((c = *s++))
    if (IsMWildChar(c))
      return 1;

  return 0;
}

static void
do_list(struct Client *source_p, int parc, char *parv[])
{
  struct ListTask *lt;
  int no_masked_channels;

  if (MyConnect(source_p))
  {
    if (source_p->localClient->list_task != NULL)
    {
      free_list_task(source_p->localClient->list_task, source_p);
      sendto_one(source_p, form_str(RPL_LISTEND), me.name, source_p->name);
      return;
    }
  }

  lt = (struct ListTask *) MyMalloc(sizeof(struct ListTask));
  lt->users_max = UINT_MAX;
  lt->created_max = UINT_MAX;
  lt->topicts_max = UINT_MAX;
  if (MyConnect(source_p))
    source_p->localClient->list_task = lt;
  no_masked_channels = 1;

  if (parc > 1)
  {
    char *opt, *save;
    dlink_list *list;
    int i, errors = 0;

    for (opt = strtoken(&save, parv[1], ","); opt != NULL;
         opt = strtoken(&save, NULL, ","))
      switch (*opt)
      {
        case '<': if ((i = atoi(opt + 1)) > 0)
		    lt->users_max = (unsigned int) i - 1;
                  else
		    errors = 1;
		  break;
        case '>': if ((i = atoi(opt + 1)) >= 0)
		    lt->users_min = (unsigned int) i + 1;
		  else
		    errors = 1;
		  break;
        case '-': break;
        case 'C':
	case 'c': switch (*++opt)
	          {
		    case '<': if ((i = atoi(opt + 1)) >= 0)
		                lt->created_max = (unsigned int) (CurrentTime
				                  - 60 * i);
			      else
			        errors = 1;
			      break;
		    case '>': if ((i = atoi(opt + 1)) >= 0)
		                lt->created_min = (unsigned int) (CurrentTime
				                  - 60 * i);
			      else
			        errors = 1;
			      break;
		    default: errors = 1;
		  }
		  break;
	case 'T':
	case 't': switch (*++opt)
	          {
		    case '<': if ((i = atoi(opt + 1)) >= 0)
		                lt->topicts_min = (unsigned int) (CurrentTime
				                  - 60 * i);
			      else
			        errors = 1;
			      break;
		    case '>': if ((i = atoi(opt + 1)) >= 0)
		                lt->topicts_max = (unsigned int) (CurrentTime
				                  - 60 * i);
			      else
			        errors = 1;
			      break;
		    default: errors = 1;
		  }
		  break;
        default: if (*opt == '!')
	         {
		   list = &lt->hide_mask;
		   opt++;
		 }
		 else list = &lt->show_mask;

		 if (has_wildcards(opt + !!IsChanPrefix(*opt)))
		 {
		   if (list == &lt->show_mask)
		     no_masked_channels = 0;
		 }
		 else if (!IsChanPrefix(*opt))
		   errors = 1;
		 if (!errors)
		 {
                   char *s;
		   DupString(s, opt);
		   dlinkAdd(s, make_dlink_node(), list);
		 }
      }
    if (errors)
    {
      free_list_task(lt, source_p);
      sendto_one(source_p, form_str(ERR_LISTSYNTAX),
                 MyConnect(source_p) ? me.name : ID(&me),
                 MyConnect(source_p) ? source_p->name : ID(source_p));
      return;
    }
  }


  if (MyConnect(source_p))
    dlinkAdd(source_p, make_dlink_node(), &listing_client_list);
  sendto_one(source_p, form_str(RPL_LISTSTART),
             MyConnect(source_p) ? me.name : ID(&me),
             MyConnect(source_p) ? source_p->name : ID(source_p));
  safe_list_channels(source_p, lt, no_masked_channels &&
                     lt->show_mask.head != NULL, !MyConnect(source_p));
}

/*
** m_list
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
m_list(struct Client *client_p, struct Client *source_p, 
       int parc, char *parv[])
{
  static time_t last_used = 0;

  /* If not a LazyLink connection, see if its still paced */
  /* If we're forwarding this to uplinks.. it should be paced due to the
   * traffic involved in /list.. -- fl_ */
  if (((last_used + ConfigFileEntry.pace_wait) > CurrentTime))
  {
    sendto_one(source_p,form_str(RPL_LOAD2HI),me.name,parv[0]);
    return;
  }
  else
    last_used = CurrentTime;

  /* If its a LazyLinks connection, let uplink handle the list */
  if (uplink && IsCapable(uplink, CAP_LL))
  {
    if (parc < 2)
      sendto_one(uplink, ":%s LIST", source_p->name);
    else
      sendto_one(uplink, ":%s LIST %s", source_p->name, parv[1]);
    return;
  }

  do_list(source_p, parc, parv);
}

/*
** mo_list
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
mo_list(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  /* If its a LazyLinks connection, let uplink handle the list
   * even for opers!
   */

  if (uplink && IsCapable(uplink, CAP_LL))
  {
    if (parc < 2)
      sendto_one(uplink, ":%s LIST", source_p->name);
    else
      sendto_one(uplink, ":%s LIST %s", source_p->name, parv[1]);
    return;
  }

  do_list(source_p, parc, parv);
}

/*
** ms_list
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
ms_list(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  /* Only allow remote list if LazyLink request */
  if (ServerInfo.hub)
  {
    if (!IsCapable(client_p->from, CAP_LL) && !MyConnect(source_p))
      return;

    do_list(source_p, parc, parv);
  }
}
