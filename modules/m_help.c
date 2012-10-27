/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_help.c: Provides help information to a user/operator.
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
#include "ircd_handler.h"
#include "msg.h"
#include "numeric.h"
#include "send.h"
#include "s_conf.h"
#include "s_log.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"

#define HELPLEN 400

static void m_help(struct Client *, struct Client *, int, char *[]);
static void mo_help(struct Client *, struct Client *, int, char *[]);
static void mo_uhelp(struct Client *, struct Client *, int, char *[]);
static void dohelp(struct Client *, const char *, char *);
static void sendhelpfile(struct Client *, const char *, const char *);

struct Message help_msgtab = {
  "HELP", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_help, m_ignore, m_ignore, mo_help, m_ignore}
};

struct Message uhelp_msgtab = {
  "UHELP", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_help, m_ignore, m_ignore, mo_uhelp, m_ignore}
};

void
_modinit(void)
{
  mod_add_cmd(&help_msgtab);
  mod_add_cmd(&uhelp_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&help_msgtab);
  mod_del_cmd(&uhelp_msgtab);
}

const char *_version = "$Revision$";

/*
 * m_help - HELP message handler
 *      parv[0] = sender prefix
 */
static void
m_help(struct Client *client_p, struct Client *source_p,
       int parc, char *parv[])
{
  static time_t last_used = 0;

  /* HELP is always local */
  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    /* safe enough to give this on a local connect only */
    sendto_one(source_p,form_str(RPL_LOAD2HI),
               me.name, source_p->name);
    return;
  }

  last_used = CurrentTime;

  dohelp(source_p, UHPATH, parv[1]);
}

/*
 * mo_help - HELP message handler
 *      parv[0] = sender prefix
 */
static void
mo_help(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  dohelp(source_p, HPATH, parv[1]);
}

/*
 * mo_uhelp - HELP message handler
 * This is used so that opers can view the user help file without deopering
 *      parv[0] = sender prefix
 */
static void
mo_uhelp(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  dohelp(source_p, UHPATH, parv[1]);
}

static void
dohelp(struct Client *source_p, const char *hpath, char *topic)
{
  char h_index[] = "index";
  char path[PATH_MAX + 1];
  struct stat sb;
  int i;

  if (topic != NULL)
  {
    if (*topic == '\0')
      topic = h_index;
    else
    {
      /* convert to lower case */
      for (i = 0; topic[i] != '\0'; ++i)
        topic[i] = ToLower(topic[i]);
    }
  }
  else
    topic = h_index;    /* list available help topics */

  if (strpbrk(topic, "/\\"))
  {
    sendto_one(source_p, form_str(ERR_HELPNOTFOUND),
               me.name, source_p->name, topic);
    return;
  }

  if (strlen(hpath) + strlen(topic) + 1 > PATH_MAX)
  {
    sendto_one(source_p, form_str(ERR_HELPNOTFOUND),
               me.name, source_p->name, topic);
    return;
  }

  snprintf(path, sizeof(path), "%s/%s", hpath, topic);

  if (stat(path, &sb) < 0)
  {
    sendto_one(source_p, form_str(ERR_HELPNOTFOUND),
               me.name, source_p->name, topic);
    return;
  }

  if (!S_ISREG(sb.st_mode))
  {
    sendto_one(source_p, form_str(ERR_HELPNOTFOUND),
               me.name, source_p->name, topic);
    return;
  }

  sendhelpfile(source_p, path, topic);
}

static void 
sendhelpfile(struct Client *source_p, const char *path, const char *topic)
{
  FBFILE *file;
  char line[HELPLEN];
  char started = 0;
  int type;

  if ((file = fbopen(path, "r")) == NULL)
  {
    sendto_one(source_p, form_str(ERR_HELPNOTFOUND),
               me.name, source_p->name, topic);
    return;
  }

  if (fbgets(line, sizeof(line), file) == NULL)
  {
    sendto_one(source_p, form_str(ERR_HELPNOTFOUND),
               me.name, source_p->name, topic);
    return;
  }

  else if (line[0] != '#')
  {
    line[strlen(line) - 1] = '\0';	  
    sendto_one(source_p, form_str(RPL_HELPSTART),
             me.name, source_p->name, topic, line);
    started = 1;
  }

  while (fbgets(line, sizeof(line), file))
  {
    line[strlen(line) - 1] = '\0';
    if (line[0] != '#')
    {
      if (!started)
      {
        type = RPL_HELPSTART;
        started = 1;
      }
      else
        type = RPL_HELPTXT;
      
      sendto_one(source_p, form_str(RPL_HELPTXT),
                 me.name, source_p->name, topic, line);
    }
  }

  fbclose(file);
  sendto_one(source_p, form_str(RPL_HELPTXT),
             me.name, source_p->name, topic, "");
  sendto_one(source_p, form_str(RPL_ENDOFHELP),
             me.name, source_p->name, topic);
}
