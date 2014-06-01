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

/*! \file m_ison.c
 * \brief Includes required functions for processing the ISON command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*! \brief ISON command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = space-separated list of nicknames
 */
static int
m_ison(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char *nick;
  char *p = NULL;
  char *current_insert_point = NULL;
  char buf[IRCD_BUFSIZE];
  int len;
  int done = 0;

  len = snprintf(buf, sizeof(buf), numeric_form(RPL_ISON), me.name, source_p->name);
  current_insert_point = buf + len;

  /*
   * rfc1459 is ambigious about how to handle ISON
   * this should handle both interpretations.
   */
  for (int i = 1; i < parc; ++i)
  {
    for (nick = strtoken(&p, parv[i], " "); nick;
         nick = strtoken(&p,    NULL, " "))
    {
      if ((target_p = find_person(source_p, nick)))
      {
        len = strlen(target_p->name);

        if ((current_insert_point + (len + 5)) < (buf + sizeof(buf)))
        {
          memcpy(current_insert_point, target_p->name, len);
          current_insert_point += len;
          *current_insert_point++ = ' ';
        }
        else
        {
          done = 1;
          break;
        }
      }
    }

    if (done)
      break;
  }

  /*
   *  current_insert_point--;
   *  Do NOT take out the trailing space, it breaks ircII
   *  --Rodder
   */
  *current_insert_point  = '\0';

  sendto_one(source_p, "%s", buf);
  return 0;
}

static struct Message ison_msgtab =
{
  "ISON", 0, 0, 2, 1, MFLG_SLOW, 0,
  { m_unregistered, m_ison, m_ignore, m_ignore, m_ison, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&ison_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&ison_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
