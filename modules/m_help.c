/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1999-2016 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
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


enum { HELPLEN = 400 };

static void
sendhelpfile(struct Client *source_p, const char *path, const char *topic)
{
  FILE *file = NULL;
  char *p = NULL;
  char line[HELPLEN] = "";

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

  if ((p = strpbrk(line, "\r\n")))
    *p = '\0';

  sendto_one_numeric(source_p, &me, RPL_HELPSTART, topic, line);

  while (fgets(line, sizeof(line), file))
  {
    if ((p = strpbrk(line, "\r\n")))
      *p = '\0';

    sendto_one_numeric(source_p, &me, RPL_HELPTXT, topic, line);
  }

  fclose(file);
  sendto_one_numeric(source_p, &me, RPL_ENDOFHELP, topic);
}

static void
do_help(struct Client *source_p, char *topic)
{
  char h_index[] = "index";
  struct stat sb;

  if (EmptyString(topic))
    topic = h_index;
  else
    for (char *p = topic; *p; ++p)
      *p = ToLower(*p);

  if (strpbrk(topic, "/\\"))
  {
    sendto_one_numeric(source_p, &me, ERR_HELPNOTFOUND, topic);
    return;
  }

  char path[sizeof(HPATH) + strlen(topic) + 1];  /* +1 for / */
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
  static uintmax_t last_used = 0;

  if ((last_used + ConfigGeneral.pace_wait_simple) > CurrentTime)
  {
    sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "HELP");
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
  .cmd = "HELP",
  .args_max = MAXPARA,
  .handlers[UNREGISTERED_HANDLER] = m_unregistered,
  .handlers[CLIENT_HANDLER] = m_help,
  .handlers[SERVER_HANDLER] = m_ignore,
  .handlers[ENCAP_HANDLER] = m_ignore,
  .handlers[OPER_HANDLER] = mo_help
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
  .version = "$Revision$",
  .modinit = module_init,
  .modexit = module_exit,
};
