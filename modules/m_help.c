/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2014 ircd-hybrid development team
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

/*! \file m_help.c
 * \brief Includes required functions for processing the HELP command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"

#define HELPLEN 400


static void
sendhelpfile(struct Client *source_p, const char *path, const char *topic)
{
  FILE *file = NULL;
  char line[HELPLEN] = { '\0' };

  if ((file = fopen(path, "r")) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  if (fgets(line, sizeof(line), file) == NULL)
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    fclose(file);
    return;
  }

  line[strlen(line) - 1] = '\0';
  sendto_one_numeric(source_p, &me, RPL_HELPSTART, topic, line);

  while (fgets(line, sizeof(line), file))
  {
    line[strlen(line) - 1] = '\0';

    sendto_one_numeric(source_p, &me, RPL_HELPTXT, topic, line);
  }

  fclose(file);
  sendto_one_numeric(source_p, &me, RPL_ENDOFHELP, topic);
}

static void
do_help(struct Client *source_p, char *topic)
{
  char *p = topic;
  char h_index[] = "index";
  char path[HYB_PATH_MAX + 1];
  struct stat sb;

  if (EmptyString(topic))
    topic = h_index;
  else
    for (; *p; ++p)
      *p = ToLower(*p);

  if (strpbrk(topic, "/\\"))
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  if (strlen(HPATH) + strlen(topic) + 1 > HYB_PATH_MAX)
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  snprintf(path, sizeof(path), "%s/%s", HPATH, topic);

  if (stat(path, &sb) < 0)
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  if (!S_ISREG(sb.st_mode))
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  sendhelpfile(source_p, path, topic);
}

/*! \brief HELP command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = help topic
 */
static int
m_help(struct Client *source_p, int parc, char *parv[])
{
  static time_t last_used = 0;

  if ((last_used + ConfigFileEntry.pace_wait_simple) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI);
    return 0;
  }

  last_used = CurrentTime;

  do_help(source_p, parv[1]);
  return 0;
}

/*! \brief HELP command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = help topic
 */
static int
mo_help(struct Client *source_p, int parc, char *parv[])
{
  do_help(source_p, parv[1]);
  return 0;
}

static struct Message help_msgtab =
{
  "HELP", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_help, m_ignore, m_ignore, mo_help, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&help_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&help_msgtab);
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
