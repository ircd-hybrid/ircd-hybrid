/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_version.c: Shows ircd version information.
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
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "s_user.h"
#include "send.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"

static char *confopts(struct Client *);
static void m_version(struct Client *, struct Client *, int, char *[]);
static void ms_version(struct Client *, struct Client *, int, char *[]);
static void mo_version(struct Client *, struct Client *, int, char *[]);

/* Option string. */
static const char serveropts[] = {
  ' ',
  'T',
  'S',
#ifdef TS_CURRENT
  '0' + TS_CURRENT,
#endif
/* ONLY do TS */
/* ALWAYS do TS_WARNINGS */
  'o',
  'w',
  '\0'
};

struct Message version_msgtab = {
  "VERSION", 0, 0, 0, 0, MFLG_SLOW, 0,
  { m_unregistered, m_version, ms_version, m_ignore, mo_version, m_ignore }
};

void
_modinit(void)
{
  mod_add_cmd(&version_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&version_msgtab);
}

const char *_version = "$Revision$";

/*
 * m_version - VERSION command handler
 *      parv[0] = sender prefix
 *      parv[1] = remote server
 */
static void
m_version(struct Client *client_p, struct Client *source_p,
          int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p, form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  if (!ConfigFileEntry.disable_remote)
    if (hunt_server(client_p, source_p, ":%s VERSION :%s",
                    1, parc, parv) != HUNTED_ISME)
      return;

  sendto_one(source_p, form_str(RPL_VERSION),
             me.name, source_p->name, ircd_version, serno,
             me.name, confopts(source_p), serveropts);
  show_isupport(source_p);
}

/*
 * mo_version - VERSION command handler
 *      parv[0] = sender prefix
 *      parv[1] = remote server
 */
static void
mo_version(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  
  if (hunt_server(client_p, source_p, ":%s VERSION :%s", 
		  1, parc, parv) != HUNTED_ISME)
    return;

  sendto_one(source_p, form_str(RPL_VERSION), me.name, parv[0], ircd_version, 
  	     serno, me.name, confopts(source_p), serveropts);

  show_isupport(source_p);
}

/*
 * ms_version - VERSION command handler
 *      parv[0] = sender prefix
 *      parv[1] = remote server
 */
static void
ms_version(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  if (hunt_server(client_p, source_p, ":%s VERSION :%s", 
                  1, parc, parv) == HUNTED_ISME)
  {
    sendto_one(source_p, form_str(RPL_VERSION),
               ID_or_name(&me, client_p),
               ID_or_name(source_p, client_p),
               ircd_version, serno,
               me.name, confopts(source_p), serveropts);
    show_isupport(source_p);
  }
}

/* confopts()
 *
 * input  - client pointer
 * output - ircd.conf option string
 * side effects - none
 */
static char *
confopts(struct Client *source_p)
{
  static char result[12];
  char *p = result;

  if (ConfigChannel.use_except)
    *p++ = 'e';
  if (ConfigFileEntry.glines)
    *p++ = 'G';
  *p++ = 'g';

  /* might wanna hide this :P */
  if (ServerInfo.hub && 
      (!ConfigFileEntry.disable_remote || IsOper(source_p)))
  {
    *p++ = 'H';
  }

  if (ConfigChannel.use_invex)
    *p++ = 'I';
  if (ConfigChannel.use_knock)
    *p++ = 'K';
  *p++ = 'M';

  if (ConfigFileEntry.ignore_bogus_ts)
    *p++ = 'T';
#ifdef USE_SYSLOG
  *p++ = 'Y';
#endif
#ifdef HAVE_LIBZ
  *p++ = 'Z';
#endif
  *p++ = '6';

  *p = '\0';

  return result;
}
